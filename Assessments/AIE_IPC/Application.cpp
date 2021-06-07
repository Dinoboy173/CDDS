

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