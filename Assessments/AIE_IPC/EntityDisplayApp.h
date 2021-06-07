#pragma once
#include <vector>
#include "Application.h"
#include "Entity.h"

class EntityDisplayApp : public Application
{
public:

	EntityDisplayApp(int screenWidth, int screenHeight);
	virtual ~EntityDisplayApp();

	virtual void Startup();
	virtual void Shutdown();

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	// an array of an unknown number of entities
	std::vector<Entity> m_entities;
};

