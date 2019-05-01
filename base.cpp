//MingkuanPang
//This function can print 1-23 on base 3
#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
void print_base(int,int);
string convert_to_base(int,int);
int main()
{
	print_base(3, 23);
	return 0;
}
void print_base(int base, int term)
{
	int number=1;
	while (number <= term)
	{
		cout << "number " << number << " on base " << base << " is:" << convert_to_base(number, base)<<endl;
		number++;
	}
}
string convert_to_base(int number,int base)//Below ten.
{
	int  temp_num;
	string num_after_convert,temp_string;
	char letter = 'A';
	if (number > INT_MAX)
	{
		cout << "The number is too big" << endl;
	}
	else
	{
		while (number >=1)
		{
			temp_num = number % base;
			if (temp_num >= 10)
			{
				letter = 'A';
				temp_num -= 10;
				letter += temp_num;
				temp_string = letter;
				num_after_convert.append(temp_string);
			}
			else
				num_after_convert.append(to_string(temp_num));
			if (number == 1)
				number = 0;
			number /= base;
		}
		reverse(num_after_convert.begin(), num_after_convert.end());
	}
	return num_after_convert;
}