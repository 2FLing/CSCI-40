//MingkuanPang
//This program can read names from a file
// and sort the names and write into a new file.
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;
int sizes(char[], int[]);
int sort_size(int[], int);
void sort_names(string);
const int MAX_LENGTH = 256;
int main()
{
	ifstream input_file;
	sort_names("names.txt");
	return 0;
}
int sizes(char names[], int size[])//This function can judge the size of each names
{
	int index, word_length = 0, size_index = 0, *size_pointer, size_length = 0;
	size_pointer = size;
	for (index = 0; index <= strlen(names) - 1; index++)
	{
		if (names[index] != ' ')
		{
			word_length++;
		}
		if (names[index] == ' ' or index == strlen(names) - 1)
		{
			*size_pointer++ = word_length;
			size_length++;
			word_length = 0;
		}
	}
	++size_pointer = NULL;
	return size_length;
}
void sort_names(string name)//This function can write names into a new file in sorted sizes order.
{
	char buffer[MAX_LENGTH] = "none";
	int size[MAX_LENGTH], pos[MAX_LENGTH];
	int length = 0, index = 0, size_length, pos_index = 0, size_index = 0, name_length = 0;
	char *new_name;
	ifstream names;
	ofstream new_names;
	names.open(name);
	if (!names.is_open())
	{
		cout << "error!" << endl;
		exit(1);
	}
	while ((!names.eof()) and strlen(buffer) <= MAX_LENGTH - 1)
	{
		names.getline(buffer, MAX_LENGTH);
	}
	names.close();
	size_length = sizes(buffer, size);
	size_length = sort_size(size, size_length);
	for (size_index = 0; size_index <= size_length - 1; size_index++)
	{
		length = 0;
		for (index = 0; index <= strlen(buffer) - 1; index++)
		{
			if (buffer[index] != ' ')
			{
				length++;
			}
			if (buffer[index] == ' ' or index == strlen(buffer) - 1)
			{
				name_length = length;
				length = 0;
				if (name_length == size[size_index] and pos_index <= MAX_LENGTH - 1)
				{
					if (index == strlen(buffer) - 1)
						pos[pos_index] = index - name_length + 1;
					else
						pos[pos_index] = index - name_length;
					pos_index++;
					name_length = 0;
				}
			}
		}
	}
	new_names.open("new_names.txt");
	for (index = 0; index <= pos_index - 1; index++)
	{
		size_index = pos[index];
		while (buffer[size_index] != ' ' and size_index <= strlen(buffer) - 1)
		{
			new_names << buffer[size_index];
			size_index++;
		}
		new_names << " ";
	}
	new_names.close();
}
int sort_size(int size[], int size_length)//This funtion can sort the sizes of names.
{
	int index_1, temp, index_2, new_size[MAX_LENGTH], size_value;
	for (index_1 = 0; index_1 <= size_length - 1; index_1++)
		for (index_2 = index_1 + 1; index_2 <= size_length - 1; index_2++)
		{
			if (size[index_2] > size[index_1])
			{
				temp = size[index_1];
				size[index_1] = size[index_2];
				size[index_2] = temp;
			}
		}
	new_size[0] = size[0];
	size_value = new_size[0];
	index_2 = 1;
	for (index_1 = 0; index_1 <= size_length - 1; index_1++)
	{
		if (index_1 <= MAX_LENGTH - 1)
		{
			if (size[index_1] != size_value)
			{
				new_size[index_2++] = size[index_1];
				size_value = size[index_1];
			}
		}
	}
	for (index_1 = 0; index_1 <= index_2; index_1++)
		size[index_1] = new_size[index_1];

	return index_2;
}
