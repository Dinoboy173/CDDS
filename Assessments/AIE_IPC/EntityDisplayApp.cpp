#include "EntityDisplayApp.h"
#include "raylib.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{
	
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
	m_fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_mySharedMemory);
	MapMemory();

	if (m_fileHandle != nullptr)
	{
		m_entities.clear();

		for (int i = 0; i < ENTITY_COUNT; i++)
			m_entities.push_back(m_data[i]);
	}

	UnmapMemory();
}

void EntityDisplayApp::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	if (m_fileHandle == nullptr)
	{
		int textSize = 40;
		char text[] = "Waiting For Editor";

		DrawText(text, (GetScreenWidth() / 4), (GetScreenHeight() / 2) - textSize, textSize, RED);
	}
	else
	{
		// draw entities
		for (auto& entity : m_entities)
		{
			DrawRectanglePro(
				Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
				Vector2{ entity.size / 2, entity.size / 2 }, // origin
				entity.rotation,
				Color{ entity.r, entity.g, entity.b, 255 });
		}
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}