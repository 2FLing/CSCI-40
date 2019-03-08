//MingkuanPang
//This program will test three functions capable of reading, adding, 
//and printing 100-digit numbers.
#include <iostream>
#include<string>
using namespace std;
// Do not change these function prototypes:
void readBig(int[]);
void printBig(int[]);
void addBig(int[], int[], int[]);

// This constant should be 100 when the program is finished.
const int MAX_DIGITS = 100;

//There should be no changes made to the main program when you turn it in.
int main()
{
	// Declare the three numbers, the first, second and the sum:
	int num1[MAX_DIGITS], num2[MAX_DIGITS], sum[MAX_DIGITS];
	bool done = false;
	char response;
	while (not done)
	{
		cout << "Please enter a number up to " << MAX_DIGITS << " digits: ";
		readBig(num1);
		cout << "Please enter a number up to " << MAX_DIGITS << " digits: ";
		readBig(num2);
		addBig(num1, num2, sum);
		printBig(num1);
		cout << "\n+\n";
		printBig(num2);
		cout << "\n=\n";
		printBig(sum);
		cout << "\n";
		cout << "test again?";
		cin >> response;
		cin.ignore(900, '\n');
		done = toupper(response) != 'Y';
	}
	system("pause");
	return 0;
}
void readBig(int num[])//ReadBig will read a number as a string,
					   //It then converts each element of the string to an integer and stores it in an integer array.
					   //Finally, it reverses the elements of the array so that the ones digit is in element zero,ement 1, the hundreds digit is in element 2, etc.
{
	string number;
	char temp;
	int digit,pos;
	for (digit = 0; digit <= MAX_DIGITS - 1; digit++)
		num[digit] = 0;
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



void printBig(int num[])//PrintBig uses a while loop to skip leading zeros and then uses a for loop to print the number.
{
	int digit = MAX_DIGITS-1;
	while (num[digit] == 0)
		digit--;
	for (digit; digit >= 0; digit--)
		cout << num[digit];
	cout << endl;
}
//1238
//5675
void addBig(int num1[], int num2[], int num3[])//AddBig adds the corresponding digits of the first two arrays and stores the answer in the third.
												//In a second loop, it performs the carry operation.
{
	int digit,my_sum,mover=0,temp,num3_size;
	for (digit = 0; digit <= MAX_DIGITS - 1; digit++)
		num3[digit] = 0;
	for (digit = 0; digit <= MAX_DIGITS-1; digit++)
	{
		my_sum = num1[digit] + num2[digit]+mover;
		if (my_sum >= 10)
		{
			mover = my_sum / 10;
			my_sum = my_sum % 10;
		}
		else
			mover = 0;
		num3[digit] = my_sum;
	}
	num3_size = digit;
	for (digit; digit >= 0; digit--)
	{
		temp = num3[digit];
		num3[digit] = num3[num3_size - digit];
		num3[num3_size - digit] = temp;
		if (temp == num3_size / 2)
			break;
	}

}
