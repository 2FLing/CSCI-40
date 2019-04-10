//MingkuanPang
#include"bignumber.h"
int main()
{
	bigNumber num1, num2,sum;
	num1.readBig();
	num2.readBig();
	sum = num1.addBig(num2);
	sum.printBig();
	return 0;
}
