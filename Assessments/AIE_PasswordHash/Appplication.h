#pragma once

#include <functional>

struct NotAuthorisedException : public std::exception
{
	const char* what() const throw ()
	{
		return "Not Authorised";
	}
};

class Application
{
public:

	Application();
	~Application();

	void Run();

private:

	int m_authHash = 0;
	
	// This is the Basic Hash method from the lecture
	static unsigned int BasicHash(const char* data, unsigned int size);

	// TODO:
	// Implement your own hash method here - note: signature should match the above
	static unsigned int MyHash(const char* data, unsigned int size);
	
	// this method allows us to change which hash function is used.
	std::function<unsigned int(const char* data, unsigned int size)> hashFn =
		Application::MyHash;

private:

	// below methods used to help with loading/saving/prompting
	// for passwords using the hash function.
	void LoadPass();
	void SavePass(unsigned int hash);
	bool Authenticate();
	int PromptPassword(bool confirmPrompt);

};

