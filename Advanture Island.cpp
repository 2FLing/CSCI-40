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
	string special_1_description;
	string special_2_description;
	string special_3_description;
	string special_4_description;
	string look_description_1;
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
	string action;
	int x = 0;
	int y = 0;
};
void engine();
int load_game();
int save_game();
player island(player, scene);
string take_action();
player behave(player, string, scene);
scene set_scene(player);
bool if_over(player, scene);
int main()
{
	bool success = false, first_time = true, over = true;
	player player1;
	scene place;
	if (first_time)
	{
		cout << "You have just awakened on a strange island with a terrible headache.You can't remember anything "
			<< "about yourself or where you are." << endl;
		player1.inventory["knife"] = 0;
		player1.inventory["banana"] = 0;
	}
	else
		cout << "Welcome back! Survivor!" << endl;
	while (!success)
	{
		place = set_scene(player1);
		if (place.name == "island")
			player1 = island(player1, place);


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
	string behavior = "none";
	transform(action.begin(), action.end(), action.begin(), tolower);
	if (action == "go north" || action == "north")
		behavior = "north";
	else if (action == "go south" || action == "south")
		behavior = "south";
	else if (action == "go west" || action == "west")
		behavior = "west";
	else if (action == "go east" || action == "east")
		behavior = "east";
	else if (action == "look")
		behavior = "look";
	else if (action == "search")
		behavior = "search";
	else if (action == "take" || action == "take it")
		behavior = "take";
	else if (action == "enter")
		behavior = "enter";
	return behavior;
}
player behave(player player1, string behavior, scene place)
{
	player person;
	person = player1;
	if (behavior == "north"&&person.x < 5)
	{
		person.x += 1;
		person.action = "go north";
	}
	else if (behavior == "south"&&person.x > -5)
	{
		person.x -= 1;
		person.action = "go south";
	}
	else if (behavior == "west"&&person.y > -12)
	{
		person.y -= 1;
		person.action = "go west";
	}
	else if (behavior == "east"&&person.y < 5)
	{
		person.y += 1;
		person.action = "go east";
	}
	else if (behavior == "look")
	{
		person.action = "look";
	}
	else if (behavior == "take" || behavior == "take it")
	{
		person.action = "take";
	}
	return person;
}
bool if_over(player player1, scene place)
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
		place.long_description = "The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore\n";
		place.short_description = "So many banana trees!\n";
		place.special_1_description = "There is a ripe banana tree!\n";
		place.special_2_description = "You found a exit!\n";
		place.look_description_1 = "There are some repe bananas on the tree.\n";
		place.times += 1;
		place.max_x = 5;
		place.min_x = -5;
		place.max_y = 5;
		place.min_y = -6;
		place.special_1_x = 3;
		place.special_1_y = 0;
		place.special_2_x = 2;
		place.special_2_y = -5;
	}
	return place;
}
player island(player player1, scene place)
{
	string behavior;
	player person;
	bool over = true;
	person = player1;
	behavior = take_action();
	while (over = if_over(person, place))
		behavior = take_action();
	while (behavior == "none")
	{
		cout << "You can`t do that bro" << endl;
		behavior = take_action();
	}
	person = behave(person, behavior, place);
	if (person.action == "look"&&person.x != place.special_1_x&&person.x != place.special_2_x&&person.x != place.special_3_x&&person.x != place.special_4_x)
	{
		if (place.times == 1)
			cout << place.long_description;
		else
			cout << place.short_description;
	}
	else if (person.x == place.special_1_x&&person.y == place.special_1_y)
	{
		cout << place.special_1_description;
		behavior = take_action();
		person = behave(person, behavior, place);
		if (person.action == "look" || person.action == "search")
		{
			cout << place.look_description_1;
			behavior = take_action();
			person = behave(person, behavior, place);
			if (person.action == "take")
			{
				if (person.inventory["knife"] == 1)
					person.inventory["banana"] += 1;
				else
					cout << "Sorry, you need a knife to get the banana.\n";
			}
		}
		else if (person.action == "take")
		{
			if (person.inventory["knife"] == 1)
				person.inventory["banana"] += 1;
			else
				cout << "Sorry, you need a knife to get the banana.\n";
		}
	}
	else if (person.x == place.special_2_x&&person.y == place.special_2_y)
	{

	}
	else if (person.action == "go north" || person.action == "go south" || person.action == "go east" || person.action == "go west")
	{
		if (place.times == 1)
			cout << place.long_description << endl;
		else
			cout << place.short_description << endl;
	}
	cout << "x: " << person.x << " y: " << person.y << endl;
	return person;
}
