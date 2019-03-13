#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
using namespace std;
char *My_sort(char*,int length);
int main()
{
	ifstream input_file;
	ofstream output_file;
	char names[100],*new_name;
	int index = 0, length;
	input_file.open("names.txt");
	if (!input_file.is_open())
	{
		cout << "Error!\n";
		return 1;
	}
	while (!input_file.eof())
		input_file.getline(names, 100);
	input_file.close();
	while (names[index] >= 'a'&&names[index] <= 'z' || names[index] >= 'A'&&names[index] <= 'Z' || names[index] == ' ')
	{
		index++;
	}
	length = index;
	new_name=My_sort(names, length);
	for (index = 0; index <= length; index++)
	{
		names[index] = *new_name;
		new_name++;
	}
	output_file.open("new_name.txt");
	for (index = 0; index <= length; index++)
	{
		output_file<<names[index];
	}
	output_file.close();
	system("pause");
	return 0;
}

char *My_sort(char* names, int length)
{
	int index = 0, position[10], index_position = 0;
	int current_index,temp,min,temp_index,min_index,name_index=0,new_name_index=0,position_length;
	position[index_position] = index;
	char new_name[100];
	while (index <= length - 1)
	{
		index++;
		if (names[index] == ' ')
			position[++index_position] =++index;
	}
	position_length = index_position;
	for (current_index = 0; current_index <= index_position - 1; current_index++)
	{
		min = names[position[current_index]];
		min_index = current_index;
		for (temp_index = current_index; temp_index <= index_position; temp_index++)
		{
			if (names[position[temp_index]] < min)
			{
				min = names[position[temp_index]];
				min_index = temp_index;
			}
		}
		temp = position[current_index];
		position[current_index] = position[min_index];
		position[min_index] = temp;
	}
	index_position = 0;
	while (index_position <= position_length)
	{
		name_index = position[index_position++];
		while (names[name_index] != ' '&&name_index<=length)
		{
			new_name[new_name_index++]= names[name_index++];
		}
		if(name_index<=length)
			new_name[new_name_index++] = names[name_index];
	}
	return new_name;
}