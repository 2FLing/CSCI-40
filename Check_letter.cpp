//MingkuanPang
//This program can add a check letter to an eight_digit number
#include <stdio.h>
#include<iostream>
using namespace std;
char check_letter(int);
int main()
{
    int num,front_num,back_num;
    char letter;
    cout<<"Please enter a 8 digits num:";
    cin>>num;
    letter=check_letter(num);
    cout<<"The original num is: "<<num<<endl;
    cout<<"The check letter is:"<<letter<<endl;
    return 0;
}
char check_letter(int num)//This function can get the check letter of an eight_digits number.
{
    int num_1,num_2,num_3,num_4,back_num,total;
    char c_total;
    num_1=num/1000000;
    num_2=num/10000%100;
    num_3=num/100%100;
    num_4=num%100;
    c_total=(num_1+num_2+num_3+num_4)%26+65;
    return c_total;
}




