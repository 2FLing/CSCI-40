//MingkuanPang
//This program can caculate factorials
// n! = (n-1)! x n and the greatest common factor
//of two numbers.
#include <iostream>
#include<string>
#include"bignumber.h"
using namespace std;
void bigNumber::readBig()//ReadBig will read a number as a string,
					   //It then converts each element of the string to an integer and stores it in an integer array.
					   //Finally, it reverses the elements of the array so that the ones digit is in element zero,ement 1, the hundreds digit is in element 2, etc.
{
	string number;
	char temp;
	int digit, pos = 0;
	for (digit = 0; digit <= MAX_DIGITS - 1; digit++)
		num[digit] = 0;
	cin >> number;
	digit = number.length() - 1;
	while (digit != (number.length() - 1) / 2)
	{
		temp = number.at(digit);
		number.at(digit) = number.at(pos);
		number.at(pos) = temp;
		digit--;
		pos++;
	}
	for (digit = 0; digit <= number.length() - 1; digit++)
		num[digit] = int(number.at(digit) - '0');

}



void bigNumber::printBig()//PrintBig uses a while loop to skip leading zeros and then uses a for loop to print the number.
{
	int digit = MAX_DIGITS - 1;
	while (num[digit] == 0 and digit != 0)
		digit--;
	for (digit; digit >= 0; digit--)
		cout << num[digit];
	cout << endl;
}
bigNumber bigNumber::addBig(bigNumber number)//AddBig adds the corresponding digits of the first two arrays and stores the answer in the third.
												//In a second loop, it performs the carry operation.
{
	int digit, my_sum, mover = 0, temp = 0, num2_num_size, start, digit2;
	bigNumber number2;
	for (digit = 0; digit <= MAX_DIGITS - 1; digit++)
		number2.num[digit] = 0;
	for (start = 0; start <= MAX_DIGITS - 1; start++)
	{
		my_sum = num[start] + number.num[start] + mover;
		if (my_sum >= 10)
		{
			mover = my_sum / 10;
			my_sum = my_sum % 10;
		}
		else
			mover = 0;
		number2.num[start] = my_sum;
	}

	return number2;
}