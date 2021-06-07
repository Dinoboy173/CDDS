#pragma once

#include "Application.h"

#include <windows.h>
#include <iostream>
#include <conio.h>

class IPCClientApp : public Application
{
public:

	IPCClientApp();
	virtual ~IPCClientApp();

	virtual void Run();
	virtual int Client();

protected:
private:
};