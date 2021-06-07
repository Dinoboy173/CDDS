#include "Application.h"

Application::Application()
{

}

Application::~Application()
{

}

void Application::MapMemory()
{
	// map the memory from the shared block to a pointer we can manipulate
	m_data = (MyData*)MapViewOfFile(m_fileHandle,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		sizeof(MyData));


	if (m_data == nullptr)
	{
		std::cout << "Could not map view of file: " <<
			GetLastError() << std::endl;

		CloseHandle(m_fileHandle);
		return;
	}
}

void Application::UnmapMemory()
{
	// unmap the memory block since we're done with it
	UnmapViewOfFile(m_data);

	// close the shared file
	CloseHandle(m_fileHandle);
}

void Application::OpenAndCreateFile()
{
	if (!m_isCreated)
	{
		// open a named shared memory block
		m_fileHandle = CreateFileMapping(
			INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
			nullptr, // optional security attributes
			PAGE_READWRITE, // read/write access control
			0,
			sizeof(MyData), // size of the memory block, 
			m_mySharedMemory);

		if (m_fileHandle == nullptr)
		{
			std::cout << "Could not create file mapping object: " <<
				GetLastError() << std::endl;
		}

		m_isCreated = true;
	}
	else
	{
		// gain access to a named shared memory block that already exists
		m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_mySharedMemory);

		if (m_fileHandle == nullptr)
		{
			std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
			return;
		}
	}
}