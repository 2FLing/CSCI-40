//MingkuanPang
//This is the header for bigNumber.
#ifndef bignumber_h
#define bignumber_h
const int MAX_DIGITS=100;
class bigNumber
{
public:
	void readBig();
	void printBig();
	bigNumber addBig(bigNumber);
private:
	int num[MAX_DIGITS];
};
#endif // !bignumber.h



