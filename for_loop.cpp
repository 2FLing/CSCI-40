//MingkuanPang
// This program can print odd_num between 3-43, print every third letter staring with "B"
//print 1-20 in one column right next to the other column with number 20-1
//and Print every other character in the computer's character set by using for loop.
#include<iostream>
#include <stdio.h>
using namespace std;
void odd_num();
void third_letters();
void numbers();
void other_letters();
int main()
{
	odd_num();
	third_letters();
	numbers();
	other_letters();
	return 0;
}
void odd_num()//This function can print even_num between 3-43
{
	int number;
	for (number = 4; number <= 43; number += 2)
		cout << number << " ";
	cout << endl;
}
void third_letters()//This function can print every third letter staring with "B"
{
	char letter = 'B';
	for (letter = 'B'; letter <= 'Z'; letter += 3)
		cout << letter << " ";
	cout << endl;
}
void numbers()//This function can print 1-20 in one column right next to the other column with number 20-1
{
	int number1;
	for (number1 = 1; number1 <= 20; number1++)
		cout << number1 << ' '<<21-number1<<endl;
}
void other_letters()//This function can print other letters in the computer character set
{
	char letter1 = 32;
	for (letter1 = 32; letter1 <= 126; ++letter1)
		cout << letter1 << " ";
	cout << endl;
}




