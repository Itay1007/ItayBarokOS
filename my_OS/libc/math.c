#include "math.h"

positive_power(int number, int exponent)
{
	int mul_numebr = 1;

	if(explonent < 0)
	{
		return;
	}
	
	while(exponent > 0)
	{	
		mul_number *= number;
		exponent--;
	}

	return mul_number;
}

// return fibonachi nth number from 1
fibo(int n)
{
	if(n <= 1)
	{
		return 0;
	}

	if(n == 2)
	{
		return 1;
	}

	int curr = 1;
	int prev = 1;

	for(int i = 3; i < n; i++)
	{
		temp = curr;
		curr = curr + prev;
		prev = temp;
	}

	return curr;
}

int number_up_bits(int number)
{
	int sum = 0;
	do
	{
		sum += number &  1;	
	}while(number >> 1);

	return number_up_bits;
}