#include "Application.h"

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

Application::Application(int screenWidth, int screenHeight, const char* windowTitle) :
	m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_windowTitle(windowTitle)
{

}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);
	Startup();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
	Shutdown();
	CloseWindow();
}

void Application::MapMemory()
{
	// map the memory from the shared block to a pointer we can manipulate
	
	m_data = (Entity*)MapViewOfFile(m_fileHandle,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		sizeof(Entity) * ENTITY_COUNT);

	if (m_data == nullptr)
	{
		std::cout << "Could not map view of file: " << GetLastError() << std::endl;

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
			sizeof(Entity) * ENTITY_COUNT, // size of the memory block, 
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

