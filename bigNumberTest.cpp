
//MingkuanPang
#include"bignumber.h"
#include<iostream>
using namespace std;
int main()
{
	bigNumber num1, num2, sum;

	bool done = false;
	char response;
	while (not done)
	{
		cout << "Please enter a number up to " << MAX_DIGITS << " digits: " << endl;
		num1.readBig();
		cout << "Please enter a number up to " << MAX_DIGITS << " digits: " << endl;
		num2.readBig();
		sum = num1.addBig(num2);
		num1.printBig();
		cout << "\n+\n";
		num2.printBig();
		cout << "\n=\n";
		sum.printBig();
		cout << "\n";
		cout << "test again?" << endl;
		cin >> response;
		cin.ignore(900, '\n');
		done = toupper(response) != 'Y';
	}
	return 0;
}
