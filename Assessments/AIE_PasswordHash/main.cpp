
#include "Appplication.h"
#include <iostream>

int main(int argc, char** argv)
{
	try
	{
		Application app;
		app.Run();
	}
	catch (NotAuthorisedException& ex)
	{
		std::cout << "You do not have permision to run this program" << std::endl;
		std::cout << "Exiting" << std::endl;
	}
	
	return 0;
}