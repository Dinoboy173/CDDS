#pragma once

#include "Application.h"

#include <iostream>
#include <windows.h>
#include <conio.h>

class IPCServerApp : public Application
{
public:

	IPCServerApp();
	virtual ~IPCServerApp();

	virtual void Run();
	virtual void RandomValues();
	virtual int Server();

protected:
	MyData myData;

	
private:
};