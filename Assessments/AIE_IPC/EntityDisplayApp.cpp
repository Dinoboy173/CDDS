#include "EntityDisplayApp.h"
#include "raylib.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{
	OpenAndCreateFile();

	MapMemory();
}

EntityDisplayApp::~EntityDisplayApp()
{
	UnmapMemory();
}

void EntityDisplayApp::Startup()
{
	
}

void EntityDisplayApp::Shutdown()
{
	
}

void EntityDisplayApp::Update(float deltaTime)
{
	if (m_editorIsOpen)
	{
		m_entities.clear();

		for (int i = 0; i < ENTITY_COUNT; i++)
			m_entities.push_back(m_data[i]);
	}
}

void EntityDisplayApp::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	if (m_editorIsOpen)
	{
		for (auto& entity : m_entities)
		{
			DrawRectanglePro(
				Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
				Vector2{ entity.size / 2, entity.size / 2 }, // origin
				entity.rotation,
				Color{ entity.r, entity.g, entity.b, 255 });
		}
	}
	else
	{
		DrawText("Waiting For Editor", m_screenWidth/4, m_screenHeight/2, 40, RED);
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}