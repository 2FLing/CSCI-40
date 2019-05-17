//MingkuanPang
//This function can sort 10 pairs
//of cartesian coordinates by
//increasing x-values,decreasing y-values
//and increasing distance from the origin.
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
const int num_pairs = 10;
struct coordinates
{
	double x;
	double y;
	double distance;
};
enum type
{
	x,
	y,
	distances
};
int read_pairs(coordinates[]);
void sort_pairs(coordinates[], type coordinate_type, int);
void print_pairs(coordinates[], type coordinate_type, int);
int main()
{
	type coordinate_type;
	int size;
	coordinates coordinate[num_pairs];
	size = read_pairs(coordinate);
	for (coordinate_type = x; coordinate_type <= distances; coordinate_type = type(coordinate_type + 1))
	{
		sort_pairs(coordinate, coordinate_type, size);
		print_pairs(coordinate, coordinate_type, size);
	}
	return 0;
}
int read_pairs(coordinates coordinate[])
{
	ifstream file;
	char space;
	int index = 0;
	file.open("points.txt");
	if (!file.is_open())
	{
		cout << "Error!\n" << endl;
	}
	else
	{
		while (not file.eof() and index < num_pairs)
		{
			file >> coordinate[index].x;
			file >> coordinate[index].y;
			coordinate[index].distance = sqrt(coordinate[index].x * coordinate[index].x +
				coordinate[index].y * coordinate[index].y);
			index++;

		}
		file.close();
	}
	return index;
}
void sort_pairs(coordinates coordinate[num_pairs], type  coordinate_type, int size)
{
	int next, last, length = size - 2;
	coordinates temp;
	bool out_of_order;
	for (last = 0; last <= length; last++)
		for (next = 0; next <= length - last; next++)
		{
			switch (coordinate_type)
			{
			case x:
				out_of_order = coordinate[next + 1].x < coordinate[next].x;
				break;
			case y:
				out_of_order = coordinate[next + 1].y > coordinate[next].y;
				break;
			case distances:
				out_of_order = coordinate[next + 1].distance < coordinate[next].distance;
				break;
			default:
				break;
			}
			if (out_of_order)
			{

				temp = coordinate[next];
				coordinate[next] = coordinate[next + 1];
				coordinate[next + 1] = temp;
			}
		}
}
void print_pairs(coordinates coordinate[num_pairs], type  coordinate_type, int size)
{
	int index;
	switch (coordinate_type)
	{
	case x:
		cout << "Order by increasing x-values:" << endl;
		break;
	case y:
		cout << "Order by decreasing y-values:" << endl;
		break;
	case distances:
		cout << "Order by increasing distance from the origin:" << endl;
		break;
	default:
		break;
	}
	for (index = 0; index <= size - 1; index++)
	{
		cout << "x:" << coordinate[index].x << "  " << "y:" <<
			coordinate[index].y << "  " << "distance:"
			<< coordinate[index].distance << endl;
	}
}
