//MingkuanPang
//This program can read names from a file
// and sort the names and write into a new file.
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;
void sort_names(string);
void order_name(string[], int);
int get_size(string[]);
const int MAX_LENGTH = 256;
int main()
{
	sort_names("names.txt");
	return 0;
}

void sort_names(string name)//This function can write names into a new file in sorted sizes order.
{
	string buffer[MAX_LENGTH];
	int  index = 0, pos, size;
	ifstream names;
	ofstream new_names;
	names.open(name);
	if (not names.is_open())
	{
		cout << "error!" << endl;
		exit(1);
	}
	while ((not names.eof()) and buffer->length() <= MAX_LENGTH - 1)
	{
		names >> buffer[index];
		index++;
	}
	names.close();
	size = get_size(buffer);
	order_name(buffer, size);
	new_names.open("new_names.txt");
	for (pos = 0; pos <= size; pos++)
	{
		new_names << buffer[pos];
		new_names << " ";
	}
	new_names.close();
}
void order_name(string names[MAX_LENGTH], int size)
//Order the factors in a string array by the increasing length of the factors.
{
	int index, pos;
	string temp;
	for (index = size - 1; index >= 0; index--)
		for (pos = 0; pos <= index; pos++)
		{
			if (names[pos].length() > names[pos + 1].length())
			{
				temp = names[pos];
				names[pos] = names[pos + 1];
				names[pos + 1] = temp;
			}
		}
}
int get_size(string names[MAX_LENGTH])//Judge the effective size of a string array.
{
	int size, index = 0;
	while (not names[index].empty())
	{
		index++;
	}
	size = index - 1;
	return size;
}