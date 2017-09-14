#include <iostream>
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

int main()
{
	while (true) {

	std::cout << "input a value: ";

	std::cin >> val; //input a value to test

	std::cout << "Sum of " << val  << " = "<< sum(val) << std::endl; //the sum of the value

	if (prime(val) == true) {								//is the value a prime number
		std::cout << val << " Is a prime" << std::endl;
	}
	else {
		std::cout << val << " Is not a prime" << std::endl;
	}

	std::cout << std::fixed << "The " << val << ". fibonachi nr is: " << fibo(val) << std::endl;
}
}
