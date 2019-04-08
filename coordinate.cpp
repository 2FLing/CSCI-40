lude<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int pairs = 10;
struct coordinates
{
	int x;
	int y;
	double distance;
};
void read_pairs(coordinates*);
enum
{
	x_incresing = 0,
	y_decresing = 1,
	distance = 2
};
int main()
{
	coordinates coordinate[pairs];
	read_pairs(coordinate);
	
	return 0;
}
void read_pairs(coordinates coordinate[])
{
	ifstream file;
	int index = 0,coo_index=0;
	string buffer;
	file.open("points.txt");
	if (!file.is_open())
	{
		cout << "Error!\n"<<endl;
		exit(1);
	}
	while (!file.eof())
	{
		getline(file, buffer);
	}
	while (index <= buffer.length() - 1)
	{
		if (!isdigit(buffer.at(index)))
			index++;
		else
		{
			coordinate[coo_index].x=buffer.at(index) - '0';
			index++;
			while (!isdigit(buffer.at(index)))
				index++;
			coordinate[coo_index].y = buffer.at(index) - '0';
			coordinate[coo_index].distance = sqrt(coordinate[coo_index].x*coordinate[coo_index].x
				+ coordinate[coo_index].y*coordinate[coo_index].y);
			coo_index++;
			index++;
		}
	}
}
