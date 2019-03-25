﻿#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
using namespace std;
class scene
{
public:
	string name;
	string long_description;
	string short_description;
	string long_description_after_got;
	string short_description_after_got;
	string stuff_can_cut_name;
	string place_can_give_stuff_1_name;
	string place_can_give_stuff_2_name;
	string entrance_1_name;
	string entrance_2_name;
	string entrance_3_name;
	string special_1_name;
	string stuff_can_cut_description;
	string entrance_1_look_description_1;
	string entrance_1_look_description_2;
	string entrance_1_description;
	string entrance_1_description_2;
	string stuff_can_cut_look_description_1;
	string stuff_can_cut_look_description_2;
	string stuff_can_cut_description_2;
	string entrance_2_description;
	string entrance_2_description_2;
	string special_1_description;
	string entrance_3_description;
	string place_can_give_stuff_1_description_1;
	string place_can_give_stuff_1_description_2;
	string hint;
	string stuff_can_be_used_1;
	string stuff_1_get_info;
	vector<string> stuff_can_cut;
	vector<string>stuff_can_give;
	vector<string>stuff_can_get;
	vector<string>stuff_can_eat;
	int max_x;
	int min_x;
	int max_y;
	int min_y;
	int stuff_can_cut_x;
	int stuff_can_cut_y;
	int entrance_1_x;
	int entrance_1_y;
	int entrance_2_x;
	int entrance_2_y;
	int entrance_3_x;
	int entrance_3_y;
	int place_can_give_stuff_1_x;
	int place_can_give_stuff_1_y;
	int place_can_give_stuff_2_x;
	int place_can_give_stuff_2_y;
	int bed_x;
	int bed_y;
	int table_x;
	int table_y;
};
class player
{
public:
	map<string, int> inventory;
	string action;
	string object;
	string command[31] = { "north","south","west","east","board","enter","take","give","search","look","eat","cut","climb","drop","up","down","unlock","sail","open","quit","inventory","setting","save","load" ,"hint","help","get out","hide","display","start"," " };
	string location = "up";
	int set = 1;
	int load = 0;
	int x = 4;
	int y = -3;
	int x_last_time = 4;
	int y_last_time = -3;
	int banana_amount = 1;
	int knife_amount = 1;
	int island_times = 0;
	int hide = 0;
	int upper_deck_times = 0;
	int capitains_quarters_times = 0;
	int in_n_out = 0;
	bool if_gorilla_run = 0;
	bool if_over = false;
};
player island(player, scene);
player upper_deck(player, scene, int);
player load_game(player);
int save_game(player);
void action_seprate(string&, string&,string);
player take_action(player,scene);
scene set_scene(player);
player if_over(player, scene);
player init_inventory(player);
void help();
player setting(player);
string To_lower(string);
bool if_has_object(string);
bool if_can_get(player, scene, string stuff="nothing");
bool if_can_cut(player, scene, string stuff="nothing");
bool if_can_give(player, scene,string stuff="nothing");
bool if_can_eat(player, scene,string food="nothing");
int if_closer(player, scene);
player so_bad_so_sad(player);
player re_take_action(player, scene);
int main()
{
	int success = 0;
	player player1;
	scene place;
	player1 = init_inventory(player1);
	while (success == 0)
	{
		place = set_scene(player1);	
		if (place.name == "island")
			player1 = island(player1, place);
		else if (place.name == "upper deck")
			player1 = upper_deck(player1, place,success);
	}

	system("pause");
	return 0;
}
player take_action(player player1,scene place)
{
	bool save = false;
	bool load = false;
	string action = "char";
	string actions;
	string objects;
	string extra_action="none";
	cout << "What are you gonna do?\n";
	getline(cin, action);
	action = To_lower(action);
	action_seprate(actions, objects, action);
	system("cls");
	if (actions == "setting")
	{
		player1.action = actions;
		player1.object = objects;
		if (objects == "game" or objects == "none")
		{
			player1 = setting(player1);
			if (player1.action == "setting fail")
			{
				player1.action = "none";
				cout << "Fail to setting keys!" << endl;
			}
		}
		else
		{
			player1.object = objects;
			player1 = so_bad_so_sad(player1);
		}
	}
	else if (actions == "go" or actions=="north" or actions=="south" or actions=="west" or actions=="east" or action==player1.command[0] or action==player1.command[1] or action == player1.command[2] or action == player1.command[3])
	{
		if (actions == "go" and objects == "none")
		{
			cout << "Which direction you want to go?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			objects = extra_action;
		}
		if ((objects == "north" and actions == "go") or action == player1.command[0] or (actions == "north" and objects == "none"))
		{
			cout << "You are going north" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.x += 1;
			player1.action = "move";
		}
		else if ((objects == "south" and actions == "go") or action == player1.command[1] or (actions == "south" and objects == "none"))
		{
			cout << "You are going south" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.x -= 1;
			player1.action = "move";
		}
		else if ((objects == "west" and actions == "go") or (actions == "west" and objects == "none") or action == player1.command[2])
		{
			cout << "You are going west" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.y += 1;
			player1.action = "move";
		}
		else if ((objects == "east" and actions == "go") or (actions == "east" and objects == "none") or action == player1.command[3])
		{
			cout << "You are going east" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.y -= 1;
			player1.action = "move";
		}
		else
			{
				player1.action = actions;
				player1.object = objects;
				player1 = so_bad_so_sad(player1);
			}
	}
	else if (actions == "look" or action == player1.command[9])
	{
		if (objects == "none")
		{
			player1.action = "look";
			player1.object = objects;
		}
		else
		{
			player1.action = "look";
			player1.object = objects;
		}
	}
	else if (actions == "search" or action == player1.command[8])
	{
		player1.action = "search";
		player1.object = objects;
	}
	else if (actions == "take" or action == player1.command[6])
	{
		player1.object = objects;
		player1.action = actions;
		if (objects == "none")
		{
			cout << "What are you gonna take?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			player1.object = extra_action;
			if (if_can_get(player1, place, extra_action))
				player1.action = "get";
		}
		else if (if_can_get(player1, place))
		{
			player1.action = "get";
			player1.object = objects;
		}
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "enter" or action == player1.command[5])
	{
		if (objects == "none")
			player1.action = "enter";
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "eat"  or action == player1.command[10])
	{
		player1.object = objects;
		if (objects == "none")
		{
			cout << "What you are gonna eat?" << endl;
			getline(cin,extra_action);
			extra_action = To_lower(extra_action);
			if (if_can_eat(player1, place, extra_action) and player1.inventory[extra_action] != 0)
			{
				player1.action = "eat";
				player1.object = objects;
				player1.inventory[extra_action]--;
				cout << "After you eat " << extra_action << " your stomach feels better" << endl;
			}
			else
			{
				player1.action = "none";
				cout<<"You don`t have "<<extra_action<<" to eat!"<<endl;
			}
		}
		else
		{
			if (if_can_eat(player1, place))
			{
				player1.action = "eat";
				player1.object = objects;
				player1.inventory[objects]--;
				cout << "After you eat " << objects << " your stomach feels better" << endl;
			}
			else
			{
				cout << "You don`t have " << objects<< " to eat!" << endl;
				player1.action = "none";
			}
		}
	}
	else if (actions == "inventory" or action == player1.command[20])
	{
		player1.action = "inventory";
		player1.object = objects;
		if (objects == "none")
		{
			map<string, int>::iterator it;
			for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
				cout << it->first << ": " << it->second << endl;
		}
		else
			player1 = so_bad_so_sad(player1);

	}
	else if (actions == "start" or action == player1.command[30])
	{
		player1.object = objects;
		if (objects == "none")
		{
			cout << "What are you gonna start?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			if (extra_action == "ship" or extra_action == "the ship")
			{
				player1.action = "start";
			}
			else
				player1.action = "none";
		}
		else if (objects == "ship" or objects == "the ship")
			player1.action = "start";
		else
			player1=so_bad_so_sad(player1);
	}
	else if (actions == "hint" or action == player1.command[24])
	{
		player1.action = "hint";
		player1.object = objects;
		if (objects == "none")
			cout << place.hint;
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "save" or action == player1.command[22])
	{
		player1.action = "save";
		player1.object = objects;
		save = save_game(player1);
		if (objects == "game" or objects == "none")
		{
			if (save)
				cout << "Save successfully!" << endl;
			else
				cout << "Save fail!" << endl;
		}
		else
			player1=so_bad_so_sad(player1);
	}
	else if (actions == "load" or action == player1.command[23])
	{
		player1.action = "load";
		player1.object = objects;
		if (objects == "game" or objects == "none")
		{
			player1 = load_game(player1);
			load = true;
		}
		else
			player1=so_bad_so_sad(player1);
	}
	else if (actions == "cut" or action == player1.command[11])
	{
		if (player1.inventory["knife"] == 0)
		{
			cout << "You need a knife to cut!" << endl;
			player1.action = "none";
		}
		else if (objects == "none")
		{
			cout << "What are you gonna cut?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			if (if_can_cut(player1, place, extra_action))
				player1.action = "cut";
		}
		else
		{
			player1.object = objects;
			if (if_can_cut(player1, place))
				player1.action = "cut";
			else
			{
				player1.action = actions;
				player1 = so_bad_so_sad(player1);
				player1.object = "none";
			}
		}
	}
	else if (actions == "help" or action == player1.command[25])
	{
		player1.action = "help";
		if (objects == "none")
			help();
		else
		{
			player1.object = objects;
			player1 = so_bad_so_sad(player1);
		}
	}
	else if (actions == "quit" or action == player1.command[19])
	{
		player1.action = "quit";
		player1.object = objects;
		if (objects == "none" or objects=="game")
			exit(0);
		else
			player1=so_bad_so_sad(player1);
	}
	else if (actions == "get" or action == player1.command[2])
	{
		player1.object = objects;
		if (objects == "out")
		{
			player1.action = "get out";
		}
		if (objects == "none")
		{
			cout << "What are you gonna get?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			player1.object = extra_action;
			if (if_can_get(player1, place, extra_action))
			{
				player1.action = "get";
				player1.object = objects;
			}
		}
		else if (if_can_get(player1, place))
		{
			player1.action = "get";
			player1.object = objects;
		}
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "give" or action == player1.command[7])
	{
		player1.object = objects;
		if (objects == "none")
		{
			cout << "What you wanna give?" << endl;
			getline(cin, extra_action);
			if (if_can_give(player1, place, extra_action))
			{
				player1.action = "give";
				player1.object = extra_action;
			}
			else
			{
				player1.action = "none";
			}
		}
		else
		{
			if (if_can_give(player1, place))
				player1.action = "give";
			else
			{
				player1.action = "none";
			}
		}
	}
	else if (actions == "hide" or action == player1.command[27])
	{
		player1.action = "hide";
		if (objects == "none")
			player1.hide = 1;
		else if (objects == "extra information")
			player1.hide = 1;
		else
		{
			player1.object = objects;
			player1 = so_bad_so_sad(player1);
		}
	}
	else if (actions == "display" or action == player1.command[28])
	{
		player1.action = "display";
		if (objects == "none")
			player1.hide = 0;
		else if (objects == "extra information")
			player1.hide = 0;
		else
		{
			player1.object = objects;
			player1 = so_bad_so_sad(player1);
		}
	}
	else
		cout << "You can`t do that bro!" << endl;
	if (player1.hide == 0 and player1.action=="move")
	{
		cout << "***********************************************************************************************" << endl;
		cout << "Extra information: " << endl;
		cout << "Your current coordinate is:  x: " << player1.x << " y: " << player1.y << endl;
		if_closer(player1, place);
		cout << "(You can enter hide to hide the extra information and enter display to see the extra information again)" << endl;
		cout << "***********************************************************************************************" << endl;
	}
	return player1;
}
player if_over(player player1, scene place)
{
	if (player1.load != 1)
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
	}
	else
		player1.load = 0;
	return player1;
}
scene set_scene(player player1)
{
	scene place;
	if (player1.y >= -6)
	{
		place.name = "island";
		place.stuff_can_cut.push_back("banana");
		place.stuff_can_eat.push_back("banana");
		place.stuff_can_get.push_back("banana");
		place.long_description = "The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore.\nstuff you can get: banana";
		place.short_description = "So many banana trees!\nstuff you can get: banana";
		place.long_description_after_got = "The island is forested with banana trees. Most of the bananas are green.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore.";
		place.short_description_after_got = "So many banana trees!";
		place.stuff_can_cut_name = "tree";
		place.entrance_1_name = "gangplank";
		place.stuff_can_cut_description = "You are standing in front of a ripe banana tree, you can take a look to see what is on the tree";
		place.entrance_1_description = "You found a gangplank! You wanna enter the ship?";
		place.stuff_can_cut_look_description_1 = "There is one branch of repe bananas on the tree.";
		place.stuff_can_cut_look_description_2 = "There is nothing on the tree....";
		place.stuff_can_cut_description_2 = "You are standing in front of a ripe banana tree! But....there is nothing on the tree....";
		place.hint = "There is a ripe banana tree around here, you can get ripe banana on this tree, try to find it!";
		place.stuff_can_be_used_1 = "knife";
		place.stuff_can_get.push_back("banana");
		place.stuff_1_get_info = "You got a tempting banana!";
		place.max_x = 5;
		place.min_x = -5;
		place.max_y = 5;
		place.min_y = -6;
		place.stuff_can_cut_x = 3;
		place.stuff_can_cut_y= 2;
		place.entrance_1_x = 2;
		place.entrance_1_y = -5;
	}
	else if (player1.y <= -7 and player1.location == "up")
	{
		place.name = "upper deck";
		place.stuff_can_eat.push_back("banana");
		place.stuff_can_give.push_back("banana");
		place.stuff_can_give.push_back("treasure");
		place.stuff_can_get.push_back("knife");
		place.long_description = "The top deck has a wheel at the north end of the ship, and the south end of the ship has a ladder down to the lower deck.\nstuff you can get: knife";
		place.long_description_after_got = "The top deck has a wheel at the north end of the ship, and the south end of the ship has a ladder down to the lower deck.";
		place.short_description_after_got = "It is upper deck";
		place.short_description = "It is upper deck\nstuff you can get: knife";
		place.entrance_1_name = "capain`s quarters";
		place.entrance_2_name = "ladder";
		place.place_can_give_stuff_1_name = "Ship`s Wheel";
		place.special_1_name = "gorilla";
		place.entrance_3_name = "gangplank";
		place.entrance_1_description = "There is a bed and a table in this room.(There is a knife on the table.)";
		place.entrance_1_description_2 = "There is a bed and a table in this room.";
		place.entrance_2_description = "There is a ladder, do you want to go down?";
		place.place_can_give_stuff_1_description_1 = "There is a large gorilla by the ship`s wheel. The gorilla is hostile. You can`t approach the wheel.\n";
		place.place_can_give_stuff_1_description_2 = "You are at the wheel.";
		place.entrance_1_look_description_1 = "There are a bed and a table in this room. Em.... there is something on the table";
		place.entrance_1_look_description_2 = "There are a bed and a table in this room.";
		place.entrance_3_description = "You found a gangplank! You wanna leave the ship?";
		place.hint = "What monkey like to eat?";
		place.stuff_can_be_used_1 = "key";
		place.stuff_can_get.push_back("knife");
		place.stuff_can_get.push_back("treasure");
		place.stuff_1_get_info = "You got a sharp knife!";
		place.max_x = 7;
		place.min_x = -4;
		place.max_y = -7;
		place.min_y = -12;
		place.entrance_1_x = -1;
		place.entrance_2_x = 2;
		place.entrance_2_y = -10;
		place.place_can_give_stuff_1_x = 5;
		place.place_can_give_stuff_1_y = -11;
		place.place_can_give_stuff_2_x = 2;
		place.place_can_give_stuff_2_y = -7;
		place.entrance_3_x = 2;
		place.entrance_3_y = -9;
		place.table_x = -3;
		place.table_y = -8;
		place.bed_x = -3;
		place.bed_y = -11;
	}
	return place;
}

player init_inventory(player player1)
{

	player1.inventory["knife"] = 0;
	player1.inventory["banana"] = 0;
	player1.inventory["tresure"] = 0;
	player1.inventory["door"] = 0;
	player1.inventory["trunk"] = 0;
	player1.inventory["parrot"] = 0;
	player1.inventory["key"] = 0;
	return player1;
}
player setting(player player1)
{
	string change, *new_command,eat_trash;
	int traversal = 0, index;
	int number;
	bool repeat = true;

	new_command = player1.command;
	cout << "There are commands in this game." << endl;
	for (index = 0; index <= 29; index++)
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
		case 26:cout << index + 1 << ". " << "To" << " get out---" << player1.command[index] << endl; break;
		case 27:cout << index + 1 << ". " << "To" << " hide extra information---" << player1.command[index] << endl; break;
		case 28:cout << index + 1 << ". " << "To" << " display extra information---" << player1.command[index] << endl; break;
		case 29:cout << index + 1 << ". " << "To" << " start something---" << player1.command[index] << endl; break;
			break;
		}

	}
	cout << "Enter the front number to choose which one you want to change" << endl;
	cin >> number;
	if (cin.fail()or cin.bad())
	{
		player1.action = "setting fail";
		cin.clear();
		cin.sync();
		number = 0;
		player1.set = 0;
		getline(cin, eat_trash);
	}
	else
	{
		cin.clear();
		cin.get();
	}
	if (number > 0 and number <= index - 1)
	{

		cout << "What word you want to change for?" << endl;
		getline(cin, change);
		change = To_lower(change);
		while (repeat)
		{
			for (traversal = 0; traversal <= index; traversal++)
				if (player1.command[traversal] == change)
				{
					cout << "This key is already used in command, please use aother key." << endl;
					getline(cin, change);
					change = To_lower(change);
					traversal = 0;
				}
			repeat = false;
		}
		for (index = 0; index < number - 1; index++)
			new_command++;
		*new_command = change;
		cout << "done!" << endl;
		index = number + 1;
		++new_command = NULL;
	}
	else
	{
		player1.action = "setting fail";
		player1.set = 0;
	}
	return player1;
}
int save_game(player player1)
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
		game_file << "knife_amount: " << endl;
		game_file << player1.knife_amount << endl;
		game_file << "player_location: " << endl;
		game_file << player1.location << endl;
		game_file << "player_x_last_time: " << endl;
		game_file << player1.x_last_time << endl;
		game_file << "player_y_last_time: " << endl;
		game_file << player1.y_last_time << endl;
		game_file << "player_island_times: " << endl;
		game_file << player1.island_times << endl;
		game_file << "player_upper_deck_times: " << endl;
		game_file << player1.upper_deck_times << endl;
		game_file << "player_capitains_quarters_times: " << endl;
		game_file << player1.capitains_quarters_times << endl;
		game_file << "hide: " << endl;
		game_file << player1.hide << endl;
		game_file << "setting:" << endl;
		for (set = player1.command; *set != " "; set++)
			game_file << *set << endl;
		game_file.close();
		++set = NULL;
	}
	return success;
}
player load_game(player player1)
{
	ifstream game_file;
	map<string, int>::iterator it;
	string loaction, inventory, banana_amount, knife_amount, player_location, player_x_last_time, setting, *set, hide;
	string plaer_y_last_time, player_island_times, player_upper_deck_times, player_capitains_quarters_times;
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
		game_file >> knife_amount;
		game_file >> player1.knife_amount;
		game_file >> player_location;
		game_file >> player1.location;
		game_file >> player_x_last_time;
		game_file >> player1.x_last_time;
		game_file >> plaer_y_last_time;
		game_file >> player1.y_last_time;
		game_file >> player_island_times;
		game_file >> player1.island_times;
		game_file >> player_upper_deck_times;
		game_file >> player1.upper_deck_times;
		game_file >> player_capitains_quarters_times;
		game_file >> player1.capitains_quarters_times;
		game_file >> hide;
		game_file >> player1.hide;
		game_file >> setting;
		for (set = player1.command; *set != " "; set++)
		{
			game_file >> *set;
		}
		player1.load = 1;
		cout << "Load game successfully" << endl;
		++set = NULL;
	}
	game_file.close();
	return player1;
}
void help()
{
	cout << "Sorry, there is nothing I can help you...." << endl;
}


string To_lower(string words)
{
	string::iterator it;
	int index = 0;
	for (it = words.begin(); it != words.end(); it++)
	{
		*it = tolower(*it);
		words.at(index++) = *it;
	}
	return words;
}
int if_closer(player player1, scene place)
{
	int close = 0;
	if (place.name == "island" and player1.load == 0)
	{
		if (player1.x != place.stuff_can_cut_x or player1.y != place.stuff_can_cut_y)
		{
			if (abs(player1.x - place.stuff_can_cut_x) < abs(player1.x_last_time - place.stuff_can_cut_x) or abs(player1.y - place.stuff_can_cut_y) < abs(player1.y_last_time - place.stuff_can_cut_y))
				cout << "You are getting closer to the ripe banana tree!" << endl;
			else
				cout << "You are getting away the ripe banana tree!" << endl;
		}
		if (player1.x != place.entrance_1_x or player1.y != place.entrance_1_y)
		{
			if (abs(player1.x - place.entrance_1_x) < abs(player1.x_last_time - place.entrance_1_x) or abs(player1.y - place.entrance_1_y) < abs(player1.y_last_time - place.entrance_1_y))
			{
				cout << "You are getting closer to the gangplank!" << endl;
			}
			else
			{
				cout << "You are getting away the gangplank!" << endl;
			}
		}
	}
	else if (place.name == "upper deck" and player1.load == 0)
	{
		if (player1.x <= place.entrance_1_x)
		{
			if (abs(player1.x - place.bed_x) < abs(player1.x_last_time - place.bed_x) or abs(player1.y - place.bed_y) < abs(player1.y_last_time - place.bed_y))
				cout << "You are getting closer to the bed" << endl;
			else
				cout << "You are getting away to the bed" << endl;
			if (abs(player1.x - place.table_x) < abs(player1.x_last_time - place.table_x) or abs(player1.y - place.table_y) < abs(player1.y_last_time - place.table_y))
				cout << "You are getting closer to the table" << endl;
			else
				cout << "You are getting away to the table" << endl;

		}
		else if (player1.x > place.entrance_1_x)
		{
			if (abs(player1.x - place.entrance_1_x) < abs(player1.x_last_time - place.entrance_1_x) or abs(player1.y - place.entrance_1_y) < abs(player1.y_last_time - place.entrance_1_y))
				cout << "You are getting closer to the capain`s quarters!" << endl;
			else
				cout << "You are getting away the capain`s quarters!" << endl;
		}
		if (player1.x != place.entrance_2_x or player1.y != place.entrance_2_y)
		{
			if (abs(player1.x - place.entrance_2_x) < abs(player1.x_last_time - place.entrance_2_x) or abs(player1.y - place.entrance_2_y) < abs(player1.y_last_time - place.entrance_2_y))
				cout << "You are getting closer to the ladder!" << endl;
			else
				cout << "You are getting away the ladder!" << endl;
		}
		if (player1.x != place.place_can_give_stuff_1_x or player1.y != place.place_can_give_stuff_1_y)
		{
			if (abs(player1.x - place.place_can_give_stuff_1_x) < abs(player1.x_last_time - place.place_can_give_stuff_1_x) or abs(player1.y - place.place_can_give_stuff_1_y) < abs(player1.y_last_time - place.place_can_give_stuff_1_y))
				cout << "You are getting closer to the ship`s wheel!" << endl;
			else
				cout << "You are getting away the ship`s wheel!" << endl;
		}
		if (player1.x != place.entrance_3_x or player1.y != place.entrance_3_y)
		{
			if (abs(player1.x - place.entrance_3_x) < abs(player1.x_last_time - place.entrance_3_x) or abs(player1.y - place.entrance_3_y) < abs(player1.y_last_time - place.entrance_3_y))
				cout << "You are getting closer to the gangplank!" << endl;
			else
				cout << "You are getting away the gangplank!" << endl;
		}

	}
	return 0;
}
player island(player player1, scene place)
{
	cout << "\n\n\n\n\n";
	if (player1.x == place.stuff_can_cut_x and player1.y == place.stuff_can_cut_y)
	{
		if (player1.banana_amount != 0)
		{
			cout << place.stuff_can_cut_description << endl;
		}
		else if (player1.banana_amount == 0)
		{
			cout << place.stuff_can_cut_description_2 << endl;
		}
		player1 = take_action(player1, place);
		while (player1.action == "look" and (player1.object=="banana tree" or player1.object=="none"))
		{
			if (player1.banana_amount != 0)
			{
				cout << place.stuff_can_cut_look_description_1 << endl;
				player1 = take_action(player1,place);
			}
			else
			{
				cout << place.stuff_can_cut_look_description_2 << endl;
				player1 = take_action(player1,place);
			}
		}
		if ((player1.action=="get" or player1.action=="cut") and player1.object=="banana")
		{
			if (player1.inventory[place.stuff_can_be_used_1] != 0 and player1.banana_amount != 0)
			{
				player1.banana_amount -= 1;
				player1.inventory["bananas"] += 1;
				cout << place.stuff_1_get_info << endl;
			}
			else if (player1.inventory[place.stuff_can_be_used_1] == 0)
			{
				cout << "Sorry, you need a " << place.stuff_can_be_used_1 << " to get the banana." << endl;
			}
			else if (player1.banana_amount == 0)
			{
				cout << place.stuff_can_cut_description_2 << endl;
			}
		}
	}
	else if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
	{
		cout << place.entrance_1_description << endl;
		player1 = take_action(player1, place);
		if (player1.action == "enter")
		{
			player1.in_n_out = 0;
			player1.y -= 3;
			player1.island_times += 1;
		}
	}
	else
	{
		if (player1.island_times == 0 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.long_description << endl;
		}
		else if (player1.island_times != 0 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			if (player1.banana_amount != 0)
				cout << place.short_description << endl;
			else
				cout << place.short_description_after_got << endl;
		}
		player1 = take_action(player1, place);
		player1 = re_take_action(player1, place);
		if (player1.action == "look" and (player1.object == "island" or player1.object == "none"))
		{
			if (player1.banana_amount != 0)
				cout << place.long_description << endl;
			else
				cout << place.long_description_after_got << endl;
		}
	}

	return player1;
}
player upper_deck(player player1, scene place, int success)
{
	vector<string> give;
	int *if_success = &success;
	if (player1.x <= place.entrance_1_x)
	{
		if (player1.x == place.table_x and player1.y == place.table_y)
		{
			if (player1.knife_amount != 0)
			{
				cout << "You see there is a shinning knife on the table!" << endl;
				player1 = take_action(player1, place);
				player1 = re_take_action(player1, place);
				if (player1.action == "get" and player1.object=="knife")
				{
					player1.knife_amount -= 1;
					player1.inventory["knife"] += 1;
					cout << place.stuff_1_get_info << endl;
				}
				else
				{
					cout << player1.object << " is not here!" << endl;
				}
			}
			else
			{
				cout << "You see a table!" << endl;
				player1 = take_action(player1, place);
				if (player1.action == "get" and player1.object == "knife")
				{
					cout << "You already took the knife!" << endl;
				}
				else if(player1.action == "get")
					cout << player1.object << " is not here!" << endl;
			}
		}
		else 
		{
			if (player1.knife_amount != 0)
			{
				cout << place.entrance_1_description << endl;

			}
			else if (player1.knife_amount == 0)
			{
				cout << place.entrance_1_description_2 << endl;
			}
			player1 = take_action(player1, place);
			player1 = re_take_action(player1, place);
		}

		if (player1.action == "look")
		{
			if (player1.knife_amount != 0)
			{
				cout << place.entrance_1_look_description_1 << endl;
			}
			else
			{
				cout << place.entrance_1_description_2 << endl;
			}
		}
	}

	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		cout << place.entrance_2_description << endl;
		player1 = take_action(player1,place);
		if (player1.action == "down")
			player1.location = "down";
	}
	else if (player1.x == place.place_can_give_stuff_1_x and player1.y == place.place_can_give_stuff_1_y)
	{
		if (player1.if_gorilla_run == 0)
		{
			cout << place.place_can_give_stuff_1_description_1;
			player1 = take_action(player1, place);
			if (player1.action == "give" and player1.object == "banana")
			{
				player1.inventory["banana"] -= 1;
				player1.if_gorilla_run = 1;
				cout << "The gorilla rush to the forest and disapear!" << endl;
			}
		}
		else
		{
			if (player1.inventory[place.stuff_can_be_used_1] != 0)
			{
				player1 = take_action(player1, place);
				if (player1.action == "start")
				{
					*if_success = 1;
					cout << "You finally success to sail away!" << endl;
				}
			}
			else
				cout << "The gorilla disapear but you still need a " << place.stuff_can_be_used_1 << " to start this ship!" << endl;
		}
	}
	else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
	{
		cout << place.entrance_3_description << endl;
		player1 = take_action(player1, place);
		player1 = re_take_action(player1, place);
		if (player1.action == "get out")
		{
			cout << "You have got out of the ship!" << endl;
			player1.y += 3;
			player1.upper_deck_times += 1;
		}
	}
	else
	{
		if (player1.upper_deck_times == 0 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.long_description << endl;
		}
		else if (player1.upper_deck_times != 0 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			if (player1.knife_amount != 0)
				cout << place.short_description << endl;
			else
				cout << place.short_description_after_got << endl;
		}
		player1 = take_action(player1, place);
		player1 = re_take_action(player1, place);
	}
	++if_success = NULL;
	return player1;
}
void action_seprate(string &actions, string &objects,string action)
{
	int pos;
	bool has_object;
	has_object = if_has_object(action);
	if (has_object)
	{
		pos = action.find(" ");
		actions = action.substr(0, pos);
		pos++;
		objects= action.substr(pos);
	}
	else
	{
		actions = action;
		objects = "none";
	}
}
bool if_has_object(string action)
{
	int has = false,action_index;
	if (action.length() - 1 >= 0)
	{
		for (action_index = 0; action_index <= action.length() - 1; action_index++)
			if (action.at(action_index) == ' ' and action_index != action.length() - 1)
				has = true;
	}
	return has;
}
player so_bad_so_sad(player player1)
{
	cout << "So bad so sad, you can`t " << player1.action << " " << player1.object <<" right now!"<< endl;
	player1.action = "none";
	return player1;
}
bool if_can_get(player player1, scene place,string stuff)
{
	bool get = false;
	vector<string>::iterator it;
	if (stuff == "nothing")
	{
		for (it = place.stuff_can_get.begin(); it != place.stuff_can_get.end(); it++)
		{
			if (*it == player1.object)
				get = true;
		}
	}
	else if(stuff!="nothing")
	{
		for (it = place.stuff_can_get.begin(); it != place.stuff_can_get.end(); it++)
		{
			if (*it == stuff)
				get = true;
		}
	}
	else
		cout << "Sorry, you can`t get " << player1.object << " right here" << endl;
	return get;
}
bool if_can_cut(player player1,scene place,string stuff)
{
	bool cut = false;
	vector<string>::iterator it;
	
	if(stuff=="nothing")
	{
		for (it = place.stuff_can_cut.begin(); it != place.stuff_can_cut.end(); it++)
		{
			if (player1.object == *it)
				cut = true;
		}
		if (cut == false)
			so_bad_so_sad(player1);
	}
	else
	{
		for (it = place.stuff_can_cut.begin(); it != place.stuff_can_cut.end(); it++)
		{
			if (stuff == *it)
				cut = true;
		}
		if (cut == false)
			so_bad_so_sad(player1);

	}
	return cut;
}
bool if_can_give(player player1, scene place, string stuff)
{
	bool give = false,equal=false;
	vector<string>::iterator it;
	if (stuff == "nothing")
	{
		for (it = place.stuff_can_give.begin(); it != place.stuff_can_give.end(); it++)
		{
			if (player1.object == *it)
			{
				equal = true;
				if (player1.inventory[player1.object] != 0)
					give = true;
				else
					cout << "You don`t have " << player1.object << " to give!" << endl;
			}
		}
		if(equal==false)
			cout << "You don`t have " << player1.object << " to give!" << endl;
	}
	else
	{
		for (it = place.stuff_can_give.begin(); it != place.stuff_can_give.end(); it++)
		{
			if (stuff== *it)
			{
				equal = true;
				if (player1.inventory[stuff] != 0)
					give = true;
				else
					cout << "You don`t have " << stuff << " to give!" << endl;
			}
		}
		if (equal == false)
			cout << "You don`t have " << stuff << " to give!" << endl;
	}

	return give;
}
bool if_can_eat(player player1, scene place,string food)
{
	bool eat = false;
	vector<string>::iterator it;
	if (food == "nothing")
	{
		for (it = place.stuff_can_eat.begin(); it != place.stuff_can_eat.end(); it++)
		{
			if (player1.object == *it and player1.inventory[player1.object] != 0)
				eat = true;
		}
	}
	else
	{
		for (it = place.stuff_can_eat.begin(); it != place.stuff_can_eat.end(); it++)
			if (food == *it)
				eat = true;
	}

	return eat;
}
player re_take_action(player player1,scene place)
{
	while (player1.action == "none")
	{
		player1 = take_action(player1, place);
	}
	player1 = if_over(player1, place);
	while (player1.if_over == true)
	{
		cout << "You go too far go back!" << endl;
		player1 = take_action(player1, place);
		player1 = if_over(player1, place);
	}
	return player1;
}