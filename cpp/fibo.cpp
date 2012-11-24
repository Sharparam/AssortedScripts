#include <iostream>
#include <string>
#include <sstream>

#define LIMIT 1000

typedef unsigned long ULONG;

double fibos[LIMIT];
int current = 0;

void fibonacci(double a, double b)
{
	if (current + 1 > LIMIT)
		return;
	fibos[current] = a;
	current++;
	// std::cout << a << std::endl;
	double tmp = a;
	a = b;
	b += tmp;
	fibonacci(a, b);
}

int getNum()
{
	std::string input = "";
	int result = 0;
	while (result <= 0 || result > 1000)
	{
		std::cout << "Enter a valid number (1-1000): ";
		getline(std::cin, input);
		std::stringstream stream(input);
		stream >> result;
	}
	return result;
}

int main()
{
	fibonacci(0.0, 1.0);
	std::cout << "Generated " << LIMIT << " fibonacci numbers" << std::endl;
	
	while (true)
	{
		int index = getNum();
		std::cout << "Fibonacci number #" << index << " is " << fibos[index - 1] << std::endl;
	}

	return 0;
}
