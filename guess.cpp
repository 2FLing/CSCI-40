//MingkuanPang
// This program can read a letter, and
// it will try to guess the letter.After each
//guess, the user should tell this program whether its
//guess was too high or too low.With this information, the
//program should be able to guess the letter within five
//tries.
#include<iostream>
#include<stdio.h>
using namespace std;
char guess(int, int);
bool if_upper(char);
int main()
{
	char letter, guess_letter, size, answer;
	int max, min;
	cout << "Please enter a letter: ";
	letter = cin.get();
	cin.ignore(999, '\n');
	if (if_upper(letter))
	{
		min = 'A';
		max = 'Z';
	}
	else
	{
		min = 'a';
		max = 'z';
	}
	while (1)
	{
		guess_letter = guess(max, min);
		cout << "If it is " << guess_letter << " ?" << endl;
		answer = cin.get();
		cin.ignore(999, '\n');
		answer = toupper(answer);
		if (answer == 'Y')
		{
			cout << "Hey! I am better than you!" << endl;
			break;
		}
		else
		{
			cout << "Does it come before " << guess_letter << " or after?" << endl;
			size = cin.get();
			cin.ignore(999, '\n');
			size = toupper(size);
			if (size == 'B')
			{
				max = guess_letter - 1;
			}
			else
			{
				min = guess_letter + 1;
			}
		}

	}
	return 0;
}
char guess(int max, int min)//This function can return a guessing letter within the range between min to max.
{
	char guess_letter, size;
	guess_letter = (max + min) / 2;
	return guess_letter;
}
bool if_upper(char letter)//This function can judge if a letter is capital or not.
{
	bool real;
	if (letter >= 'A' and letter <= 'Z')
		real = 1;
	else
		real = 0;
	return real;
}



