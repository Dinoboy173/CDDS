#pragma once

#include "Application.h"
#include "Entity.h"

#include <vector>

class EntityEditorApp : public Application
{
public:
	EntityEditorApp(int screenWidth, int screenHeight);
	virtual ~EntityEditorApp();

	void Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();

protected:

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 10 };
	Entity m_entities[ENTITY_COUNT];
};