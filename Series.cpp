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
	double a,r,sum_1,sum_2;
	cout << "Please enter your a: ";
	cin >> a;
	cout << "Please enter your r: ";
	cin >> r;
	sum_1=Sum_Series(a, r);
	sum_2=Series_Sum(a,r);
	cout.setf(ios::fixed);
	cout.precision(10);
	cout <<"The sum by caculated is: "<<sum_1<<endl;
	cout <<"The sum by formula is: "<<sum_2<<endl;
	return 0;
}

double Sum_Series(double a, double r)//This function can caculate a sum of a series of numbers.
{
	double sum_1=0,sum_2;
	sum_2 = Series_Sum(a, r);
	while (1)
	{
		sum_1 += a;
		a *= r;
		if (if_equal(sum_1,sum_2))
			break;
	}
	return sum_1;
}
double Series_Sum(double a, double r)//This function can caculate a sum of a series of numbers by formula.
{
	double sum;
	sum = a / (1 - r);
	return sum;
}
bool if_equal(double sum_1, double sum_2)// This function can judge if two numbers are equal.
{
	if(fabs(sum_1-sum_2)<fabs(sum_1*pow(10,-7)))
		return true;
	else
		return false;
}
