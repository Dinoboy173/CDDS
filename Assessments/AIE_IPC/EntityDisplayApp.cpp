#include "EntityDisplayApp.h"
#include "raylib.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) :
	Application(screenWidth, screenHeight, "Display App")
{

}

EntityDisplayApp::~EntityDisplayApp()
{

}

void EntityDisplayApp::Startup()
{
	
}

void EntityDisplayApp::Shutdown()
{

}

void EntityDisplayApp::Update(float deltaTime)
{

}

void EntityDisplayApp::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {

		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}