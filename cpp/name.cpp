#include <iostream>
#include <string>

int main()
{
	// Skriv ut ett meddelande
	std::cout << "What's your name? ";

	// Skapa en tom sträng
	std::string input = "";

	// Läs in data från standard input
	getline(std::cin, input);

	// Skriv ut "Hello," följt av det som användaren skrev
	std::cout << "Hello, " << input << std::endl;

	return 0;
}

