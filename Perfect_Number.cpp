//MingkuanPang
//This fucntion can tell What
//numbers below 5000 are perfect ? What odd numbers
//below 5000 are abundant ? What are the relative
//proportions of deficient, abundant, and perfect numbers ?
#include <stdio.h>
#include<iostream>
using namespace std;
int NUMBER = 5000;
bool if_perfect(int);
bool if_deficient(int);
bool if_abundant(int);
bool if_odd(int);
int my_sum(int);
int main()
{
	double num_perfect = 0, num_deficient = 0, num_abundant = 0;
	int num_in_NUMBER;
	cout << "The perfect numbers in 5000 are: ";
	for (num_in_NUMBER = 1; num_in_NUMBER <= NUMBER; num_in_NUMBER++)
	{
		if (if_perfect(num_in_NUMBER))
		{
			cout << num_in_NUMBER << " ";
			num_perfect++;
		}
		else
			if (if_deficient(num_in_NUMBER))
				num_deficient++;
			else
				if (if_abundant(num_in_NUMBER))
					num_abundant++;
	}
	cout << endl;
	cout << "These odd numbers below 5000 are abundant: ";
	for (num_in_NUMBER = 1; num_in_NUMBER <= NUMBER - 1; num_in_NUMBER++)
		if (if_abundant(num_in_NUMBER) and if_odd(num_in_NUMBER))
			cout << num_in_NUMBER << " ";
	cout << endl;
	cout << "The percentage of perfect number in 5000 is :" << num_perfect / NUMBER * 100 << "%" << endl;
	cout << "The percentage of deficient number in 5000 is :" << num_deficient / NUMBER * 100 << "%" << endl;
	cout << "The percentage of abandant number in 5000 is :" << num_abundant / NUMBER * 100 << "%" << endl;
	return 0;
}
int my_sum(int factor)//This function can cacaulate the sum of all divisor in a number
{
	int num_in_factor, sum = 0;
	for (num_in_factor = 1; num_in_factor <= factor - 1; ++num_in_factor)
		if (factor%num_in_factor == 0)
			sum += num_in_factor;
	return sum;
}
bool if_perfect(int factor)//This function can determind if a number is a perfect number
{
	int sum;
	bool real;
	sum = my_sum(factor);
	if (sum == factor)
		real=1;
	else
		real=0;
	return real;
}
bool if_deficient(int factor)//This function can determind if a number is a deficient number
{
	int sum;
	bool real;
	sum = my_sum(factor);
	if (sum < factor)
		real=1;
	else
		real=0;
	return real;
}
bool if_abundant(int factor)//This function can determind if a number is a abundant number
{
	int sum;
	bool real;
	sum = my_sum(factor);
	if (sum > factor)
		real=1;
	else
		real=0;
	return real;
}
bool if_odd(int factor)//This function can determind if a number is an odd number
{
	bool real;
	if (factor % 2 == 1)
		real=1;
	else
		real=0;
	return real;
}



