#include "IPCClientApp.h"

#include <windows.h>
#include <iostream>
#include <conio.h>

IPCClientApp::IPCClientApp()
{
	OpenAndCreateFile();

	MapMemory();
}

IPCClientApp::~IPCClientApp()
{
	UnmapMemory();
}

void IPCClientApp::Run()
{
	while (!m_shouldClose)
	{
		Client();
	}
}

int IPCClientApp::Client()
{
	system("CLS");

	// write out what is in the memory block
	std::cout << "MyData = { ";
	std::cout << m_data->i << ", ";
	std::cout << m_data->f << ", ";
	std::cout << m_data->c << ", ";
	std::cout << m_data->b << ", ";
	std::cout << m_data->d;
	std::cout << " };" << std::endl;

	// wait for a keypress to close

	if (_getch() == 27)
		m_shouldClose = true;
	else

	return 0;
}