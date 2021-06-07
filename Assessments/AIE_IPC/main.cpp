
#include "EntityEditorApp.h"
#include "EntityDisplayApp.h"

#include <string>
#include <iostream>
#include <functional>

int PromptInt(const std::string& message, std::function<bool(int value)> validatorFn)
{
	while (true)
	{
		try
		{
			std::cout << message;
			std::string input;
			std::getline(std::cin, input);
			auto result = std::stoi(input);
			if (validatorFn(result))
				return result;
			else
				throw "Failed Validation";
		}
		catch (...)
		{
			std::cout << "Invalid Input!" << std::endl;
		}
	}
}

int main(int argc, char** argv)
{

	std::cout << "1. Run Display" << std::endl;
	std::cout << "2. Run Editor" << std::endl;
	int prompt = PromptInt("Run: ", [](int val) { 
		return val == 1 || val == 2;
	});

	Application* app = nullptr;

	if (prompt == 1) app = new EntityDisplayApp(800, 450);
	if (prompt == 2) app = new EntityEditorApp(800, 450);

	app->Run();

	delete app;

	return 0;
}