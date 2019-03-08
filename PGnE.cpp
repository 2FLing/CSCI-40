//MingkuanPang
//This program can caculate electric bill or gas bill for a month base on the 
//quantities,baseline quantities,baseline price,and over baseline price the user input.
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
double price(double, double, double, double, double);
int main()
{
	double bill, start, end;
	cout << "Please enter the beginning meter readings for electric:";
	cin >> start;
	cout << "Please enter the ending meter readings for electric:";
	cin >> end;
	bill = price(start, end, 238.7, 0.094, 0.133);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << bill << endl;
	cout << "Please enter the beginning meter readings for gas:";
	cin >> start;
	cout << "Please enter the ending meter readings for  gas:";
	cin >> end;
	bill = price(start, end, 31, 0.504, 0.824);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << bill << endl;
	return 0;
}
double price(double start, double end, double baseline_quantities, double baseline_price, double over_baseline_price)//This function can print the result of the total bill for whatever gas or electric for a month.
{
	double  price, quantities, over_quantities;
	quantities = end - start;
	if (quantities <= baseline_quantities)
		price = quantities * baseline_price;
	else
	{
		over_quantities = quantities - baseline_quantities;
		price = (baseline_quantities*baseline_price) + over_quantities * over_baseline_price;
	}
	return price;
}




