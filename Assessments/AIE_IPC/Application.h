#pragma once

#include <iostream>
#include <raylib.h>
#include "FixWindows.h"
#include "Entity.h"
#include <time.h>
#include <random>

class Application
{
public:

	Application(int screenWidth, int screenHeight, const char *windowTitle);
	virtual ~Application();

	void Run();

	void MapMemory();
	void UnmapMemory();
	void OpenAndCreateFile();

	virtual void Startup() = 0;
	virtual void Shutdown() = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

protected:

	int m_screenWidth;
	int m_screenHeight;
	const char* m_windowTitle;
	
	bool m_isCreated = false;
	HANDLE m_fileHandle;
	enum { ENTITY_COUNT = 300 };
	Entity *m_data;
	Entity m_entities[ENTITY_COUNT];
	const wchar_t m_mySharedMemory[7] = L"Memory";

private:
};
