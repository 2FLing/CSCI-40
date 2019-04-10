//MingkuanPang
//This program can caculate factorials
// n! = (n-1)! x n and the greatest common factor
//of two numbers.
#include<iostream>
using namespace std;
int factorial(int);
int gcf(int, int);
int main()
{
	int times,number1,number2,result1,result2;
	cout << "How many times of factorial do you want to see?" << endl;
	cin >> times;
	cout << "What numbers greatest common factor do you want to see?" << endl;
	cin >> number1>>number2;
	result1=factorial(times);
	result2 = gcf(number1, number2);
	cout << "The result of " << times << " times of factorial is: " << result1 << endl;
	cout << "The greatest common factor of " << number1 << " and " << number2 << " is: " << result2 << endl;
	return 0;
}
//This function can caculate the factorial base on the times
//taht the user input.
int factorial(int times)
{
	if (times == 0)
		times = 1;
	else
		times=factorial(times - 1)*times;
	return times;
}
//This function can caculate the greatest common factor of two numbers.
int gcf(int number1, int number2)
{
	int temp;
	if (number2 != 0)
	{
		temp = number2;
		number2 = number1 % number2;
		number1 = temp;
		gcf(number1, number2);
	}
	else
		return number1;
}
