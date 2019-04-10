//MingkuanPang
//This program can caculate the sum
//of two numbers.Each number can be 
// up to 100 digits.
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
	int digit, pos;
	for (digit = 0; digit <= MAX_DIGITS - 1; digit++)
		num[digit] = 0;
	cout << "Please enter a BIG number:" << endl;
	cin >> number;
	for (digit = number.length() - 1; digit >= 0; digit--)
	{
		temp = number.at(digit);
		pos = number.length() - 1 - digit;
		number.at(digit) = number.at(pos);
		number.at(number.length() - (digit + 1)) = temp;
		if (digit == number.length() / 2)
			break;
	}
	for (digit = 0; digit <= number.length() - 1; digit++)
		num[digit] = int(number.at(digit) - '0');

}



void bigNumber::printBig()//PrintBig uses a while loop to skip leading zeros and then uses a for loop to print the number.
{
	int digit = MAX_DIGITS - 1;
	while (num[digit] == 0)
		digit--;
	for (digit; digit >= 0; digit--)
		cout << num[digit];
	cout << endl;
}
//1238
//5675
bigNumber bigNumber::addBig(bigNumber number)//AddBig adds the corresponding digits of the first two arrays and stores the answer in the third.
												//In a second loop, it performs the carry operation.
{
	int digit, my_sum, mover = 0, temp, num2_num_size,start,digit2;
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
	num2_num_size = digit;
	for (digit2=digit; digit2 >= 0; digit2--)
	{
		temp = number2.num[digit2];
		number2.num[digit2] = number2.num[num2_num_size - digit2];
		number2.num[num2_num_size - digit2] = temp;
		if (temp == num2_num_size / 2)
			break;
	}
	
	return number2;
}

