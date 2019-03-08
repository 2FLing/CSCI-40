//MingkuanPang
// This program accepts ten sets of four grades,and it will print the
//weighted average of each set, and prints the unweighted
//average of each test.
#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{
	const int students = 10;
	double grade, weighted_grade, unweighted_grade, test1_grade = 0, test2_grade = 0, test3_grade = 0, test4_grade = 0;
	for (int student = 1; student <= students; ++student)
	{
		double sum = 0;
		cout << "Please enter the grade of 1th test for student" << student << ":";
		cin >> grade;
		sum += grade * 0.1;
		test1_grade += grade;
		cout << "Please enter the grade of 2th test for student" << student << ":";
		cin >> grade;
		sum += grade * 0.25;
		test2_grade += grade;
		cout << "Please enter the grade of 3th test for student" << student << ":";
		cin >> grade;
		sum += grade * 0.30;
		test3_grade += grade;
		cout << "Please enter the grade of 4th test for student" << student << ":";
		cin >> grade;
		sum += grade * 0.35;
		test4_grade += grade;
		cout << "The weighted average grade for student "<<student<<" is: " << sum << endl;
	}
	cout << "The unweighted average grade for test1 is:" << test1_grade / students << endl;
	cout << "The unweighted average grade for test2 is:" << test2_grade / students << endl;
	cout << "The unweighted average grade for test3 is:" << test3_grade / students << endl;
	cout << "The unweighted average grade for test4 is:" << test4_grade / students << endl;
	
	return 0;
}




