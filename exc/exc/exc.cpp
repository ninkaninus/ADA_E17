// exc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <sstream>
#include <stack>

int val;

int sum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return n + sum(n - 1);
	}
}

bool prime(int n)
{
	if (n % 2 != 0) {
		return true;
	}
	else {
		return false;
	}

}

double fibo(int n)
{
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}

bool matchingBrackets(std::string text)
{
	std::stack<int> bracket;
	for (unsigned int i = 0; i < text.size(); i++)
	{
		if (text.at(i) == '(' || text.at(i) == ')')
		{
			bracket.push(text.at(i));
		}
	}
	int left = 0;
	int right = 0;
	for (unsigned int i = bracket.size(); i > 0; i--)
	{
		if (bracket.top() == '(')
		{
			left++;
		}
		if (bracket.top() == ')')
		{
			right++;
		}
		bracket.pop();
	}
	if (left == right)
	{
		return true;
		while (bracket.empty() == false)
		{
			bracket.pop();
		}
	}
	else
	{
		return false;
		while (bracket.empty() == false)
		{
			bracket.pop();
		}
	}
}

// exc 1
int exc1()
{
	std::cout << "input a value: ";
	std::cin >> val; //input a value to test
	std::cout << "Sum of " << val << " = " << sum(val) << std::endl; //the sum of the value
	if (prime(val) == true) {								//is the value a prime number
		std::cout << val << " Is a prime" << std::endl;
	}
	else {
		std::cout << val << " Is not a prime" << std::endl;
	}
	std::cout << std::fixed << "The " << val << ". fibonachi nr is: " << fibo(val) << std::endl;
	return 0;
}


//exc 2
int exc2()
{
	std::string test;
	std::cout << "Write ( or )" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, test);
	bool testbool = matchingBrackets(test);
	if (testbool == true)
	{
		std::cout << "There is an equal amout" << std::endl;
	}
	else
	{
		std::cout << "There is not an equal amout" << std::endl;
	}
	return 0;
}

int  main()
{
	std::cout << "Choose the number of the exc" << std::endl;
	std::cout << "Exc 1 = 1" << std::endl;
	std::cout << "Exc 2 = 2" << std::endl;
	std::cin >> val;
	switch (val)
	{
	case 1: exc1();
		break;
	case 2: exc1();
		break;
	default:
		break;
	}

}
