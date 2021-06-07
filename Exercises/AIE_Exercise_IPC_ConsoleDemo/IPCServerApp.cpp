#include "IPCServerApp.h"

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

IPCServerApp::IPCServerApp()
{
    OpenAndCreateFile();

    MapMemory();
}

IPCServerApp::~IPCServerApp()
{
    UnmapMemory();
}

void IPCServerApp::Run()
{
    while (!m_shouldClose)
    {
        Server();
    }
}

void IPCServerApp::RandomValues()
{ 
    srand(time(NULL));

    myData.i = rand() % 100 + 1;
    myData.f = rand() % 10000 / 100.0f;
    myData.c = rand() % 94 + 32;
    myData.b = rand() % 2;
    myData.d = rand() % 10000 / 100.0;
}

int IPCServerApp::Server()
{
    // write to the memory block
    *m_data = myData;

    // wait for a keypress to close
    if (_getch() == 27)
        m_shouldClose = true;
     else
         RandomValues();

    return 0;
}
