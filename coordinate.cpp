#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int num_pairs = 10;
struct coordinates
{
	int x;
	int y;
	double distance;
};
enum type
{
	x,
	y,
	distances
};
void read_pairs(coordinates*);
void sort_pairs(coordinates*, type coordinate_type);
void print_pairs(coordinates*, type coordinate_type);
int main()
{
	type coordinate_type;
	coordinates coordinate[num_pairs];
	read_pairs(coordinate);
	for (coordinate_type = x; coordinate_type <= distances; coordinate_type = type(coordinate_type + 1))
	{
		sort_pairs(coordinate, coordinate_type);
		print_pairs(coordinate, coordinate_type);
	}
	return 0;
}
void read_pairs(coordinates coordinate[])
{
	ifstream file;
	int index = 0,add_space=0, new_index = 0, coo_index = 0,space_index=0,x_or_y=0;
	string buffer, new_buffer, temp;
	file.open("points.txt");
	if (!file.is_open())
	{
		cout << "Error!\n" << endl;
		exit(1);
	}
	while (!file.eof())
	{
		getline(file, buffer);
	}
	while (index <= buffer.length() - 1)
	{
		if (!isdigit(buffer.at(index)))
		{
			index++;
			if (add_space != 0)
			{
				new_buffer.append(" ");
				add_space = 0;
			}
		}
		else
		{
			temp = buffer.at(index);
			new_buffer.append(temp);
			index++;
			add_space = 1;
		}
	}
	if(new_buffer.at(new_buffer.length()-1)!=' ')
		new_buffer.append(" ");
	while (new_index <= new_buffer.length() - 1)
	{
		while (new_buffer.at(new_index) != ' ')
			new_index++;
		if (x_or_y == 0)
		{
			coordinate[coo_index].x = stoi(new_buffer.substr(space_index, new_index - space_index));
			new_index++;
			space_index = new_index;
			x_or_y = 1;
		}
		else
		{
			coordinate[coo_index].y = stoi(new_buffer.substr(space_index, new_index - space_index));
			coordinate[coo_index].distance = sqrt(coordinate[coo_index].x*coordinate[coo_index].x
				+ coordinate[coo_index].y*coordinate[coo_index].y);
			coo_index++;
			new_index++;
			space_index = new_index;
			x_or_y = 0;
		}
	}
	file.close();
}
void sort_pairs(coordinates coordinate[num_pairs],type  coordinate_type)
{
	int next, last,length=num_pairs-2;
	coordinates temp;
	bool out_of_order;
	for(last = 0; last <= length; last++)
		for(next = 0; next <= length-last; next++)
		{
			switch (coordinate_type)
			{
			case x:
				out_of_order = coordinate[next+1].x < coordinate[next].x;
				break;
			case y:
				out_of_order = coordinate[next+1].y > coordinate[next].y;
				break;
			case distances:
				out_of_order = coordinate[next+1].distance < coordinate[next].distance;
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
void print_pairs(coordinates coordinate[num_pairs], type  coordinate_type)
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
	for (index = 0; index <= num_pairs - 1; index++)
	{
		cout << "x:" << coordinate[index].x << "  " << "y:" <<
			coordinate[index].y << "  " << "distance:"
			<< coordinate[index].distance << endl;
	}
}
