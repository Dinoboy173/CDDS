#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>

struct MyData
{
	int i;
	float f;
	char c;
	bool b;
	double d;
};

class Application
{

public:
	Application();
	virtual ~Application();

	virtual void Run() = 0;

	void MapMemory();
	void UnmapMemory();
	void OpenAndCreateFile();

protected:
	bool m_shouldClose = false;
	bool m_isCreated = false;

	HANDLE m_fileHandle;
	MyData* m_data;

	const wchar_t m_mySharedMemory[15] = L"MySharedMemory";
private:
};