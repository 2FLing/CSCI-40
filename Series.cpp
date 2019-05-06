//MingkuanPang
//s. The program can read the first term (a) and the common ratio (r) for the
//series, then it will caculate the sum in two ways, if both sums agree with the formula to 7 significant
//digits. The sums will be printed.  
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
bool if_equal(double, double);
double Sum_Series(double, double);
double Series_Sum(double, double);
int main()
{
	double first_term, common_ration, sum_1, sum_2;
	cout << "Please enter the first term: ";
	cin >> first_term;
	cout << "Please enter your common ration: ";
	cin >> common_ration;
	sum_1 = Sum_Series(first_term, common_ration);
	sum_2 = Series_Sum(first_term, common_ration);
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << "The sum by caculated is: " << sum_1 << endl;
	cout << "The sum by formula is: " << sum_2 << endl;
	return 0;
}

double Sum_Series(double first_term, double common_ration)//This function can caculate a sum of a series of numbers.
{
	double sum_1 = 0, sum_2;
	if (common_ration < 1)
	{
		sum_2 = Series_Sum(first_term, common_ration);
		while (!if_equal(sum_1, sum_2))
		{
			sum_1 += first_term;
			first_term *= common_ration;
		}
	}
	return sum_1;
}
double Series_Sum(double first_term, double common_ration)//This function can caculate a sum of a series of numbers by formula.
{
	double sum=0;
	if (common_ration < 1)
		sum = first_term / (1 - common_ration);
	else
		cout << "The comman_ration must less then 1!" << endl;
	return sum;
}
bool if_equal(double sum_1, double sum_2)// This function can judge if two numbers are equal.
{
	bool equal = false;
	if (fabs(sum_1 - sum_2) < fabs(sum_1*(1e-7)))
		equal = true;
	return equal;
}


