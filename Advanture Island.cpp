#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<typeinfo>
#include<fstream>
using namespace std;
class scene
{
public:
	string name;
	string long_description;
	string short_description;
	string special_1_name;
	string special_2_name;
	string special_1_description;
	string special_description_1;
	string special_2_description;
	string special_1_look_description_1;
	string special_1_look_description_2;
	string special_1_description_2;
	string hint;
	string stuff_can_be_used_1;
	string stuff_can_get_1;
	string stuff_1_get_info;
	int max_stuff_1_can_get_amount;
	int max_x;
	int min_x;
	int max_y;
	int min_y;
	int special_1_x = 3;
	int special_1_y = 0;
	int special_2_x = 2;
	int special_2_y = -5;
};
class player
{
public:
	map<string, int> inventory;
	string action;
	string command[27] = { "north","south","west","east","board","enter","take","give","search","look","eat","cut","climb","drop","up","down","unlock","sail","open","quit","inventory","setting","save","load" ,"hint","help"," " };
	string location = "up";
	int set = 1;
	int x = 4;
	int y = -3;
	int banana_amount = 1;
	int island_times = 0;
	bool if_over = false;
};
player engine(player, scene);
player load_game(player);
int save_game(player);
player island(player, scene);
player upper(player, scene);
string take_action(player);
player behave(player, string, scene);
scene set_scene(player);
player if_over(player, scene);
player init_inventory(player);
void help();
player setting(player);
string word_to_Piglatin(string);
int main()
{
	bool success = false, first_time = true, over = true;
	player player1;
	scene place;
	player1 = init_inventory(player1);
	while (!success)
	{
		if (player1.y > -6)
		{
			place = set_scene(player1);
			player1 = island(player1, place);
		}
		else if (player1.location == "up"&&player1.y <= -6)
		{
			place = set_scene(player1);
			player1 = upper(player1, place);
		}
	}

	system("pause");
	return 0;
}
string take_action(player player1)
{
	string action = "char";
	string behavior = "none";
	cout << "What are you gonna do?\n";
	if (action != "char")
	{
		cin.ignore(999);
		cin.get();
	}
	getline(cin, action);
	transform(action.begin(), action.end(), action.begin(), tolower);
	if (action == "setting")
		behavior = "setting";
	else if (action == "go north" || action == "north" || action == player1.command[0])
		behavior = "north";
	else if (action == "go south" || action == "south" || action == player1.command[1])
		behavior = "south";
	else if (action == "go west" || action == "west" || action == player1.command[2])
		behavior = "west";
	else if (action == "go east" || action == "east" || action == player1.command[3])
		behavior = "east";
	else if (action == "look" || action == player1.command[9])
		behavior = "look";
	else if (action == "search" || action == player1.command[8])
		behavior = "search";
	else if (action == "take" || action == "take it" || action == player1.command[6])
		behavior = "take";
	else if (action == "enter" || action == player1.command[5])
		behavior = "enter";
	else if (action == "eat" || action == "eat something" || action == player1.command[10])
		behavior = "eat";
	else if (action == "inventory" || action == player1.command[20])
		behavior = "inventory";
	else if (action == "hint" || action == "h" || action == player1.command[24])
		behavior = "hint";
	else if (action == "save game" || action == "save" || action == player1.command[22])
		behavior = "save";
	else if (action == "load game" || action == "load" || action == player1.command[23])
		behavior = "load";
	else if (action == "cut" || action == player1.command[11])
		behavior = "cut";
	else if (action == "help" || action == player1.command[25])
		behavior = "help";
	else if (action == "quit" || action == player1.command[19])
		behavior = "quit";
	return behavior;
}
player behave(player player1, string behavior, scene place)
{
	if (behavior == "north")
	{
		player1.x += 1;
		player1.action = "go north";
	}
	else if (behavior == "south")
	{
		player1.x -= 1;
		player1.action = "go south";
	}
	else if (behavior == "west")
	{
		player1.y += 1;
		player1.action = "go west";
	}
	else if (behavior == "east")
	{
		player1.y -= 1;
		player1.action = "go east";
	}
	else if (behavior == "look")
	{
		player1.action = "look";
	}
	else if (behavior == "take" || behavior == "take it")
	{
		player1.action = "take";
	}
	else if (behavior == "enter" || behavior == "go in")
	{
		player1.action = "enter";
	}
	else if (behavior == "eat")
	{
		player1.action = "eat";
	}
	else if (behavior == "inventory")
	{
		player1.action = "inventory";
	}
	else if (behavior == "hint")
	{
		player1.action = "hint";
	}

	else if (behavior == "save")
	{
		player1.action = "save";
	}
	else if (behavior == "load")
	{
		player1.action = "load";
	}
	else if (behavior == "cut")
	{
		player1.action = "cut";
	}
	else if (behavior == "help")
	{
		player1.action = "help";
	}
	else if (behavior == "quit")
	{
		player1.action = "quit";
	}
	else if (behavior == "setting")
	{
		player1 = setting(player1);
	}
	return player1;
}
player if_over(player player1, scene place)
{
	if (player1.x < place.min_x)
	{
		player1.x += 1;
		player1.if_over = true;
	}
	else if (player1.x > place.max_x)
	{
		player1.x -= 1;
		player1.if_over = true;
	}
	else if (player1.y > place.max_y)
	{
		player1.y -= 1;
		player1.if_over = true;
	}
	else if (player1.y < place.min_y)
	{
		player1.y += 1;
		player1.if_over = true;
	}
	else
		player1.if_over = false;
	return player1;
}
scene set_scene(player player1)//当切换场景的时候记得要把上一个场景的次数加一
{
	scene place;
	if (player1.y > -6)
	{
		place.name = "island";
		place.long_description = "The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore\n";
		place.short_description = "So many banana trees!\n";
		place.special_1_name = "tree";
		place.special_2_name = "gangplank";
		place.special_1_description = "You are standing in front of a ripe banana tree, you can take a look to see what is on the tree\n";
		place.special_2_description = "You found a gangplank! You wanna enter?\n";
		place.special_1_look_description_1 = "There is a branch of repe bananas on the tree.";
		place.special_1_look_description_2 = "There is nothing on the tree....";
		place.special_1_description_2 = "You are standing in front of a ripe banana tree! But....there is nothing on the tree....";
		place.hint = "There is a ripe banana tree around here, you can get ripe banana on this tree, try to find it!";
		place.stuff_can_be_used_1 = "knife";
		place.stuff_can_get_1 = "banana";
		place.stuff_1_get_info = "You got a tempting banana!";
		place.max_x = 5;
		place.min_x = -5;
		place.max_y = 5;
		place.min_y = -6;
		place.special_1_x = 3;
		place.special_1_y = 0;
		place.special_2_x = 2;
		place.special_2_y = -5;
	}
	else if (player1.location == "up"&&player1.y <= -6)
	{

	}
	return place;
}
player island(player player1, scene place)
{

	player1 = engine(player1, place);
	return player1;
}
player init_inventory(player player1)
{

	player1.inventory["knife"] = 0;
	player1.inventory["bananas"] = 0;
	player1.inventory["tresure"] = 0;
	player1.inventory["door"] = 0;
	player1.inventory["trunk"] = 0;
	player1.inventory["parrot"] = 0;
	player1.inventory["keys"] = 0;
	return player1;
}
player setting(player player1)//输入字母的时候会出现两次 you can`t do that bro!
{
	string change, *new_command;
	int traversal = 0, index;
	int number;
	bool repeat = true;

	new_command = player1.command;
	cout << "There are commands in this game." << endl;
	for (index = 0; index <= 25; index++)
	{

		switch (index)
		{
		default:
		case 0:cout << index + 1 << ". " << "Go " << "north---" << player1.command[index] << endl; break;
		case 1:cout << index + 1 << ". " << "Go " << "south---" << player1.command[index] << endl; break;
		case 2:cout << index + 1 << ". " << "Go " << "west---" << player1.command[index] << endl; break;
		case 3:cout << index + 1 << ". " << "Go " << "east---" << player1.command[index] << endl; break;
		case 4:cout << index + 1 << ". " << "To " << "board---" << player1.command[index] << endl; break;
		case 5:cout << index + 1 << ". " << "To " << "enter---" << player1.command[index] << endl; break;
		case 6:cout << index + 1 << ". " << "To " << "take---" << player1.command[index] << endl; break;
		case 7:cout << index + 1 << ". " << "To " << "give---" << player1.command[index] << endl; break;
		case 8:cout << index + 1 << ". " << "To " << "search---" << player1.command[index] << endl; break;
		case 9:cout << index + 1 << ". " << "To" << "look---" << player1.command[index] << endl; break;
		case 10:cout << index + 1 << ". " << "To " << "eat---" << player1.command[index] << endl; break;
		case 11:cout << index + 1 << ". " << "To " << "cut---" << player1.command[index] << endl; break;
		case 12:cout << index + 1 << ". " << "To " << "climb---" << player1.command[index] << endl; break;
		case 13:cout << index + 1 << ". " << "To " << "drop---" << player1.command[index] << endl; break;
		case 14:cout << index + 1 << ". " << "Go " << "up---" << player1.command[index] << endl; break;
		case 15:cout << index + 1 << ". " << "Go " << "down---" << player1.command[index] << endl; break;
		case 16:cout << index + 1 << ". " << "To " << "unlock---" << player1.command[index] << endl; break;
		case 17:cout << index + 1 << ". " << "To " << "sail---" << player1.command[index] << endl; break;
		case 18:cout << index + 1 << ". " << "To " << "open---" << player1.command[index] << endl; break;
		case 19:cout << index + 1 << ". " << "To " << "quit---" << player1.command[index] << endl; break;
		case 20:cout << index + 1 << ". " << "Check " << "inventory---" << player1.command[index] << endl; break;
		case 21:cout << index + 1 << ". " << "To " << "setting---" << player1.command[index] << endl; break;
		case 22:cout << index + 1 << ". " << "To " << "save---" << player1.command[index] << endl; break;
		case 23:cout << index + 1 << ". " << "To " << "load--" << player1.command[index] << endl; break;
		case 24:cout << index + 1 << ". " << "To see " << "hint---" << player1.command[index] << endl; break;
		case 25:cout << index + 1 << ". " << "To see " << "help---" << player1.command[index] << endl; break;
			break;
		}
	}
	cout << "Enter the front number to choose which one you want to change" << endl;
	cin >> number;
	if (cin.fail())
	{
		player1.action = "setting fail";
		cin.clear();
		cin.get();
		number = 0;
		player1.set = 0;
	}
	else
	{
		cin.clear();
		cin.get();
	}
	if (number > 0 && number <= index - 1)
	{

		cout << "What word you want to change for?" << endl;
		getline(cin, change);
		transform(change.begin(), change.end(), change.begin(), tolower);
		while (repeat)
		{
			for (traversal = 0; traversal <= index - 1; traversal++)
				if (player1.command[traversal] == change)
				{
					cout << "This key is already used in command, please use aother key." << endl;
					getline(cin, change);
					transform(change.begin(), change.end(), change.begin(), tolower);
					traversal = 0;
				}
			repeat = false;
		}
		for (index = 0; index < number - 1; index++)
			new_command++;
		*new_command = change;
		cout << "done!" << endl;
		index = number + 1;
	}
	else
	{
		player1.action = "setting fail";
		player1.set = 0;
	}
	return player1;
}
int save_game(player player1)//设置也要保存下来
{
	ofstream game_file;
	map<string, int>::iterator it;
	int success = 1;
	string *set;
	game_file.open("Advanture Island.txt");
	if (!game_file.is_open())
	{
		cout << "Error!" << endl;
		success = 0;
	}
	else
	{
		game_file << "location:" << endl;
		game_file << player1.x << " " << player1.y << "\n";
		game_file << "Inventory:" << endl;
		for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
		{
			game_file << it->second << "\n";
		}
		game_file << "banana_amount: " << endl;
		game_file << player1.banana_amount << endl;
		game_file << "setting:" << endl;
		for (set = player1.command; *set != " "; set++)
			game_file << *set << endl;
		game_file.close();
	}
	return success;
}
player load_game(player player1)
{
	ifstream game_file;
	map<string, int>::iterator it;
	string loaction, inventory, banana_amount, setting, *set;
	game_file.open("Advanture Island.txt");
	if (!game_file.is_open())
		cout << "Fail loading game!" << endl;
	else
	{
		game_file >> loaction;
		game_file >> player1.x >> player1.y;
		game_file >> inventory;
		for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
		{
			game_file >> it->second;
		}
		game_file >> banana_amount;
		game_file >> player1.banana_amount;
		game_file >> setting;
		for (set = player1.command; *set != " "; set++)
		{
			game_file >> *set;
		}
		cout << "Load game successfully" << endl;
	}
	game_file.close();
	return player1;
}
void help()
{
	cout << "Sorry, there is nothing I can help you...." << endl;
}

player engine(player player1, scene place)
{

	bool save = false;
	bool load = false;
	string behavior;
	int *stuff_1_max;
	stuff_1_max = &place.max_stuff_1_can_get_amount;
	*stuff_1_max = player1.banana_amount;
	if (place.name == "island"&&player1.x == place.special_1_x&&player1.y == place.special_1_y)
	{
		if (player1.banana_amount != 0)
		{
			cout << place.special_1_description;
		}
		else if (player1.banana_amount == 0)
		{
			cout << place.special_1_description_2 << endl;
		}
	}

	else if (player1.x == place.special_2_x&&player1.y == place.special_2_y)
	{
		cout << place.special_2_description;
	}
	else
	{
		if (player1.island_times == 0)
		{
			cout << place.long_description << endl;
			player1.island_times += 1;
		}
		else if (player1.action != "look")
			cout << place.short_description << endl;
	}
	behavior = take_action(player1);
	while (behavior == "none")
	{
		cout << "You can`t do that bro" << endl;
		behavior = take_action(player1);
	}
	player1 = behave(player1, behavior, place);
	player1 = if_over(player1, place);
	while (player1.if_over == true)
	{
		cout << "You go too far go back!" << endl;
		behavior = take_action(player1);
		player1 = behave(player1, behavior, place);
		player1 = if_over(player1, place);
	}
	if (place.name == "island")
	{
		if (player1.x == place.special_1_x&&player1.y == place.special_1_y)
		{
			while (player1.action == "cut")
			{
				cout << "You can`t cut the " << place.special_1_name << "!" << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior, place);
			}
			while (player1.action == "look")
			{
				if (player1.banana_amount != 0)
				{
					cout << place.special_1_look_description_1 << endl;
					behavior = take_action(player1);
					player1 = behave(player1, behavior, place);
				}
				else
				{
					cout << place.special_1_look_description_2 << endl;
					behavior = take_action(player1);
					player1 = behave(player1, behavior, place);
				}
			}
			if (player1.action == "take")
			{
				if (player1.inventory[place.stuff_can_be_used_1] != 0 && *stuff_1_max != 0)
				{
					*stuff_1_max -= 1;
					if (place.name == "island")
					{
						player1.inventory["bananas"] += 1;
					}
					cout << place.stuff_1_get_info << endl;
				}
				else if (player1.inventory[place.stuff_can_be_used_1] == 0)
				{
					cout << "Sorry, you need a " << place.stuff_can_be_used_1 << " to get the banana.\n";
				}
				else if (*stuff_1_max == 0)
				{
					cout << place.special_1_look_description_2 << endl;
				}
			}
			else;
		}
		else if (player1.x == place.special_2_x&&player1.y == place.special_2_y)
		{
			if (player1.action == "enter")
				player1.y -= 1;
		}
	}
	if (player1.action == "eat")
	{
		if (player1.inventory["bananas"] == 0)
			cout << "You have nothing to eat." << endl;
		else
		{
			cout << "Your stomach feels better." << endl;
			player1.inventory["bananas"] -= 1;
		}
	}
	else if (player1.action == "inventory")
	{
		map<string, int>::iterator it;
		for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
			cout << it->first << ": " << it->second << endl;
	}
	else if (player1.action == "hint")
		cout << place.hint << endl;
	else if (player1.action == "save")
	{
		save = save_game(player1);
		if (save)
			cout << "Save successfully!" << endl;
		else
			cout << "Save fail!" << endl;
	}
	else if (player1.action == "load")
	{
		player1 = load_game(player1);
		load = true;
	}
	else if (player1.action == "help")
	{
		help();
	}
	else if (player1.action == "setting fail")
	{
		cin.get();
	}
	else if (player1.action == "quit")
	{
		exit(1);
	}
	else if (player1.action == "look")
	{
		if (player1.x == place.special_1_x&&player1.y == place.special_1_y)
			cout << place.special_1_look_description_1 << endl;
		else if (player1.x == place.special_2_x&&player1.y == place.special_2_y)\
			cout << place.special_2_description << endl;
		else
			cout << place.long_description << endl;
	}
	cout << "x: " << player1.x << " y: " << player1.y << endl;
	if (place.name == "island"&&load == false)
	{
		player1.banana_amount = *stuff_1_max;
	}
	return player1;
}
player upper(player player1)
{

}