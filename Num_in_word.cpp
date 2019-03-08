//MingkuanPang
//That program reads a
//whole number of up to nine digits and prints it in words.
#include<iostream>
#include<stdio.h>
using namespace std;
void Num_in_word(int);
int Brake_Apart(int, int&);
int Digits(int);
void unit(int, int);
int main()
{
	int number, index, new_num, digits, temp;
	cout << "Please enter a number:";
	cin >> number;
	temp = number;
	digits = Digits(number);
	cout << "In words this number is : ";
	for (index = 1; index <= digits; ++index)
	{
		new_num = Brake_Apart(number, temp);
		Num_in_word(new_num);
		if (new_num != 0)
			unit(digits, index);
	}
	cout << endl;
	return 0;
}
//1,000,003
int Brake_Apart(int number, int &temp)//This function can brake a number into three parts,million,thousand, and ten.
{                           //There could be without million and thousand.
	int new_number;
	if (temp >= 1000000)
	{
		new_number = temp / 1000000;
		temp = 1000;
		return new_number;
	}
	else
		if (temp < 1000000 and temp>999)
		{
			temp = number;
			new_number = temp % 1000000 / 1000;
			temp = 0;
			return new_number;
		}
		else
			{
				temp = number % 1000000 % 1000;
				new_number = temp;
				return new_number;

			}
}
void Num_in_word(int number)//This function can turn a number into words.
{
	int hundred = number / 100, ten = number % 100, one = 0;
	if (ten >= 20)
	{
		ten = number % 100 / 10;
		one = number % 100 % 10;
	}
	else
		if (ten < 10)
		{
			ten = 0;
			one = number % 10;
		}

	switch (hundred)
	{
	case 1:
		cout << "one hundred "; break;
	case 2:
		cout << "two hundred "; break;
	case 3:
		cout << "three hundred "; break;
	case 4:
		cout << "four hundred "; break;
	case 5:
		cout << "five hundred "; break;
	case 6:
		cout << "six hundred "; break;
	case 7:
		cout << "seven hundred "; break;
	case 8:
		cout << "eight hundred "; break;
	case 9:
		cout << "nine hundred "; break;
	default:
		break;
	}
	switch (ten)
	{
	case 1:
		cout << "ten "; break;
	case 2:
		cout << "twenty "; break;
	case 3:
		cout << "thirty "; break;
	case 4:
		cout << "forty "; break;
	case 5:
		cout << "fifty "; break;
	case 6:
		cout << "sixty "; break;
	case 7:
		cout << "seventy "; break;
	case 8:
		cout << "eighty "; break;
	case 9:
		cout << "ninety "; break;
	case 10:
		cout << "ten "; break;
	case 11:
		cout << "eleven "; break;
	case 12:
		cout << "twelve "; break;
	case 13:
		cout << "thirteen "; break;
	case 14:
		cout << "fourteen "; break;
	case 15:
		cout << "fifteen "; break;
	case 16:
		cout << "sixteen "; break;
	case 17:
		cout << "seventeen "; break;
	case 18:
		cout << "eighteen "; break;
	case 19:
		cout << "nineteen "; break;

	default:
		break;
	}
	switch (one)
	{
	case 1:
		cout << "one "; break;
	case 2:
		cout << "two "; break;
	case 3:
		cout << "three "; break;
	case 4:
		cout << "four "; break;
	case 5:
		cout << "five "; break;
	case 6:
		cout << "six "; break;
	case 7:
		cout << "seven "; break;
	case 8:
		cout << "eight "; break;
	case 9:
		cout << "nine "; break;
	default:
		break;
	}
}
int Digits(int number)//This number can judge how many digits does the number have.
{                   // Every one thousand is a digit.
	if (number >= 1000000)
		return 3;
	else
		if (number >= 1000)
			return 2;
		else
			return 1;
}
void unit(int digits, int index)//This funtion can add units at the end of every digit of number.
{                           // every one thousand is a digit.
	switch (digits)
	{
	case 3:
		switch (index)
		{
		case 1:cout << "million "; break;
		case 2:cout << "thousand "; break;
		default:
			break;
		}; break;
	case 2:
		switch (index)
		{
		case 1:cout << "thousand "; break;
		default:
			break;
		}; break;

	default:
		break;
	}
}



