#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class scene
{
public:
	string name;
	string long_description;
	string short_description;
	int times = 0;
	int max_x;
	int min_x;
	int max_y;
	int min_y;
	int special_1_x;
	int special_1_y;
	int special_2_x;
	int special_2_y;
	int special_3_x;
	int special_3_y;
	int special_4_x;
	int special_4_y;
};
class player
{
public:
	map<string, int> inventory;
	int x=0;
	int y=0;
};
void engine();
int load_game();
int save_game();
string take_action();
player behave(string,scene);
scene set_scene(player);
bool if_over(player,scene);
int main()
{
	bool success = false,first_time=true,over=true;
	string behavior;
	player player1;
	scene place;
	if (first_time)
		cout << "You have just awakened on a strange island with a terrible headache.You can't remember anything "
		<< "about yourself or where you are." << endl;
	else
		cout << "Welcome back! Survivor!" << endl;
	while (!success)
	{
		place=set_scene(player1);
		behavior = take_action();
		while (over = if_over(player1, place))
			behavior = take_action();
		player1=behave(behavior, place);
		cout << endl;
		cout << "x:" << player1.x << " " << "y: " << player1.y << endl;
	}

	system("pause");
	return 0;
}
int load_game()
{
	return false;
}
int save_game()
{
	return 1;
}
string take_action()
{
	string action;
	cout << "What are you gonna do?\n";
	getline(cin, action);
	string behavior="You can`t do that bro";
	cout << action;
	transform(action.begin(), action.end(), action.begin(), tolower);
	if (action == "go north" || action == "north")
		behavior = "north";
	else if (action == "go south" || action == "south")
		behavior = "south";
	else if (action == "go west" || action == "west")
		behavior = "west";
	else if (action == "go east" || action == "east")
		behavior = "east";
	return behavior;
}
player behave(string behavior,scene place)
{
	player player1;
	if (behavior == "north"&&player1.x < 5)
	{
		player1.x += 1;
		if (place.times == 1)
			cout << place.long_description<<endl;
		else
			cout << place.short_description<<endl;
	}
	else if (behavior == "south"&&player1.x>-5)
		player1.x -= 1;
	else if (behavior == "west"&&player1.y>-12)
		player1.y -= 1;
	else if (behavior == "east"&&player1.y<5)
		player1.y += 1;
	return player1;
}
bool if_over(player player1,scene place)
{
	bool over = false;
	if (player1.x < place.min_x)
	{
		cout << "You go too far go back!" << endl;
		over = true;
	}
	else if (player1.x > place.max_x)
		{
			cout << "You go too far go back!" << endl;
			over = true;
		}
	else if (player1.y > place.max_y)
		{
			cout << "You go too far go back!" << endl;
			over = true;
		}
	else if (player1.y < place.min_y)
		{
			cout << "You go too far go back!" << endl;
			over = true;
		}
	return over;
}
scene set_scene(player player1)
{
	scene place;
	if (player1.y >= -6)
	{
		place.name = "island";
		place.long_description = "The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore";
		place.short_description = "So many banana trees!";
		place.times+=1;
		place.max_x = 5;
		place.min_x = -5;
		place.max_y = 5;
		place.min_y = -6;
		place.special_1_x = 5;
		place.special_1_y = 0;
	}
	return place;
}
