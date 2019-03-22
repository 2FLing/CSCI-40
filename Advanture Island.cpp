#include<iostream>
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
	string special_1_name;
	string special_2_name;
	string special_3_name;
	string special_4_name;
	string special_5_name;
	string special_1_description;
	string special_description_1;
	string special_2_description;
	string special_1_look_description_1;
	string special_1_look_description_2;
	string special_1_description_2;
	string special_3_description;
	string special_3_description_2;
	string special_4_description;
	string special_5_description;
	string hint;
	string stuff_can_be_used_1;
	string stuff_can_get_1;
	string stuff_1_get_info;
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
	int special_5_x;
	int special_5_y;
<<<<<<< HEAD
	int bed_x;
	int bed_y;
	int table_x;
	int table_y;
=======
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
};
class player
{
public:
	map<string, int> inventory;
	string action;
	string command[30] = { "north","south","west","east","board","enter","take","give","search","look","eat","cut","climb","drop","up","down","unlock","sail","open","quit","inventory","setting","save","load" ,"hint","help","get out","hide","display"," " };
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
<<<<<<< HEAD
	int in_n_out = 0;
=======
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
	bool if_gorilla_run = 0;
	bool if_over = false;
	bool long_or_short = 0;
};
player engine(player, scene);
player island(player, scene);
player upper_deck(player, scene, int);
player load_game(player);
int save_game(player);
string take_action(player);
player behave(player, string, scene);
scene set_scene(player);
player if_over(player, scene);
player init_inventory(player);
void help();
player setting(player);
string To_lower(string);
vector<string> give_stuff(string);
int action_give(string, player);
int if_closer(player, scene);
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
			player1 = upper_deck(player1, place, success);

	}

	system("pause");
	return 0;
}
string take_action(player player1)
{
	string action = "char";
	string behavior = "none";
	int give;
	cout << "What are you gonna do?\n";
	if (action != "char")
	{
		cin.ignore(999);
		cin.get();
	}
	getline(cin, action);
	action = To_lower(action);

	if (action == "setting")
		behavior = "setting";
	else if (action == "go north" or action == "north" or action == player1.command[0])
		behavior = "north";
	else if (action == "go south" or action == "south" or action == player1.command[1])
		behavior = "south";
	else if (action == "go west" or action == "west" or action == player1.command[2])
		behavior = "west";
	else if (action == "go east" or action == "east" or action == player1.command[3])
		behavior = "east";
	else if (action == "look" or action == player1.command[9])
		behavior = "look";
	else if (action == "search" or action == player1.command[8])
		behavior = "search";
	else if (action == "take" or action == "take it" or action == player1.command[6])
		behavior = "take";
	else if (action == "enter" or action == player1.command[5])
		behavior = "enter";
	else if (action == "eat" or action == "eat something" or action == player1.command[10])
		behavior = "eat";
	else if (action == "inventory" or action == player1.command[20])
		behavior = "inventory";
	else if (action == "hint" or action == "h" or action == player1.command[24])
		behavior = "hint";
	else if (action == "save game" or action == "save" or action == player1.command[22])
		behavior = "save";
	else if (action == "load game" or action == "load" or action == player1.command[23])
		behavior = "load";
	else if (action == "cut" or action == player1.command[11])
		behavior = "cut";
	else if (action == "help" or action == player1.command[25])
		behavior = "help";
	else if (action == "quit" or action == player1.command[19])
		behavior = "quit";
	else if (action == "get out" or action == player1.command[2])
		behavior = "get out";
	else if (give = action_give(action, player1) == 1)
		behavior = action;
	else if (action == "hide" or action == player1.command[27])
		behavior = "hide";
	else if (action == "display" or action == player1.command[28])
		behavior = "display";
	system("cls");
	return behavior;
}
player behave(player player1, string behavior)
{
	int give;
	vector<string>give_something;
	if (behavior == "north")
	{
		cout << "You are going north" << endl;
		player1.x_last_time = player1.x;
		player1.y_last_time = player1.y;
		player1.x += 1;
		player1.action = "go north";
	}
	else if (behavior == "south")
	{
		cout << "You are going south" << endl;
		player1.x_last_time = player1.x;
		player1.y_last_time = player1.y;
		player1.x -= 1;
		player1.action = "go south";
	}
	else if (behavior == "west")
	{
		cout << "You are going west" << endl;
		player1.x_last_time = player1.x;
		player1.y_last_time = player1.y;
		player1.y += 1;
		player1.action = "go west";
	}
	else if (behavior == "east")
	{
		cout << "You are going east" << endl;
		player1.x_last_time = player1.x;
		player1.y_last_time = player1.y;
		player1.y -= 1;
		player1.action = "go east";
	}
	else if (behavior == "look")
	{
		player1.action = "look";
	}
	else if (behavior == "take" or behavior == "take it")
	{
		player1.action = "take";
	}
	else if (behavior == "enter" or behavior == "go in")
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
	else if (behavior == "get out")
	{
		player1.action = "get out";
	}
	else if (give = action_give(behavior, player1) == 1)
	{
		player1.action = "give";
		give_something = give_stuff(behavior);
		player1.action.append(" ");
		player1.action.append(give_something[1]);
	}
	else if (behavior == "hide")
	{
		player1.action = "hide";
	}
	else if (behavior == "display")
	{
		player1.action = "display";
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
	if (player1.y >= -6)
	{
		place.name = "island";
		place.long_description = "The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore.\nstuff you can get: banana";
		place.short_description = "So many banana trees!\nstuff you can get: banana";
		place.long_description_after_got = "The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore.";
		place.short_description_after_got = "So many banana trees!";
		place.special_1_name = "tree";
		place.special_2_name = "gangplank";
		place.special_1_description = "You are standing in front of a ripe banana tree, you can take a look to see what is on the tree";
		place.special_2_description = "You found a gangplank! You wanna enter the ship?";
		place.special_1_look_description_1 = "There is one branch of repe bananas on the tree.";
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
	else if (player1.y <= -7 and player1.location == "up")
	{
		place.name = "upper deck";
		place.long_description = "The top deck has a wheel at the north end of the ship, and the south end of the ship has a ladder down to the lower deck.\nstuff you can get: knife";
<<<<<<< HEAD
		place.long_description_after_got = "The top deck has a wheel at the north end of the ship, and the south end of the ship has a ladder down to the lower deck.";
		place.short_description_after_got = "It is upper deck";
=======
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
		place.short_description = "It is upper deck\nstuff you can get: knife";
		place.special_1_name = "capain`s quarters";
		place.special_2_name = "ladder";
		place.special_3_name = "Ship`s Wheel";
		place.special_4_name = "gorilla";
		place.special_5_name = "gangplank";
		place.special_1_description = "There is a bed and a table in this room.(There is a knife on the table.)";
		place.special_1_description_2 = "There is a bed and a table in this room.";
		place.special_2_description = "There is a ladder, do you want to go down?";
		place.special_3_description = "There is a large gorilla by the ship`s wheel. The gorilla is hostile. You can`t approach the wheel.\n";
		place.special_3_description_2 = "You are at the wheel.";
		place.special_1_look_description_1 = "There are a bed and a table in this room. Em.... there is something on the table";
		place.special_1_look_description_2 = "There are a bed and a table in this room.";
		place.special_5_description = "You found a gangplank! You wanna leave the ship?";
		place.hint = "The Gorilla is fierce, you gonna come up some ideas to drive it away";
		place.stuff_can_be_used_1 = "key";
		place.stuff_can_get_1 = "knife";
		place.stuff_1_get_info = "You got a sharp knife!";
		place.max_x = 7;
		place.min_x = -4;
		place.max_y = -7;
		place.min_y = -12;
		place.special_1_x = -1;
		place.special_2_x = 2;
		place.special_2_y = -10;
		place.special_3_x = 5;
		place.special_3_y = -12;
		place.special_5_x = 2;
		place.special_5_y = -7;
<<<<<<< HEAD
		place.table_x = -3;
		place.table_y = -8;
		place.bed_x = -3;
		place.bed_y - 11;
=======
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
	}
	return place;
}

player init_inventory(player player1)
{

	player1.inventory["knife"] = 0;
	player1.inventory["bananas"] = 0;
	player1.inventory["tresure"] = 0;
	player1.inventory["door"] = 0;
	player1.inventory["trunk"] = 0;
	player1.inventory["parrot"] = 0;
	player1.inventory["key"] = 0;
	return player1;
}
player setting(player player1)
{
	string change, *new_command;
	int traversal = 0, index;
	int number;
	bool repeat = true;

	new_command = player1.command;
	cout << "There are commands in this game." << endl;
	for (index = 0; index <= 28; index++)
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
<<<<<<< HEAD
		game_file << "hide: " << endl;
		game_file << player1.hide << endl;
=======
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
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
<<<<<<< HEAD
	string loaction, inventory, banana_amount, knife_amount, player_location, player_x_last_time, setting, *set, hide;
=======
	string loaction, inventory, banana_amount, knife_amount, player_location, player_x_last_time, setting, *set;
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
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
<<<<<<< HEAD
		game_file >> hide;
		game_file >> player1.hide;
=======
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
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

player engine(player player1, scene place)
{

	bool save = false;
	bool load = false;
<<<<<<< HEAD
=======
	int *stuff_1_max;

>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
	if (player1.action == "eat")
	{
		if (player1.inventory["bananas"] == 0)
			cout << "You have nothing to eat." << endl;
		else
<<<<<<< HEAD
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
	else if (player1.action == "hide")
	{
		player1.hide = 1;
	}
	else if (player1.action == "display")
	{
		player1.hide = 0;
	}
	else if (player1.action == "look")
	{
		if (place.name == "island")
		{
			if (player1.banana_amount == 1)
				cout << place.long_description << endl;
			else
				cout << place.long_description_after_got << endl;
		}
		else if (place.name == "upper deck")
		{
			if (player1.knife_amount == 1)
				cout << place.long_description << endl;
			else
				cout << place.long_description_after_got << endl;
		}
	}
	if (player1.hide == 0)
	{
		cout << "***********************************************************************************************" << endl;
		cout << "Extra information: " << endl;
		cout << "Your current coordinate is:  x: " << player1.x << " y: " << player1.y << endl;
		if_closer(player1, place);
		cout << "(You can enter hide to hide the extra information and enter display to see the extra information again)" << endl;
		cout << "***********************************************************************************************" << endl;
	}
	player1.load = 0;
	return player1;
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
		if (player1.x != place.special_1_x or player1.y != place.special_1_y)
		{
			if (abs(player1.x - place.special_1_x) < abs(player1.x_last_time - place.special_1_x) or abs(player1.y - place.special_1_y) < abs(player1.y_last_time - place.special_1_y))
				cout << "You are getting closer to the ripe banana tree!" << endl;
			else
				cout << "You are getting away the ripe banana tree!" << endl;
		}
		if (player1.x != place.special_2_x or player1.y != place.special_2_y)
		{
			if (abs(player1.x - place.special_2_x) < abs(player1.x_last_time - place.special_2_x) or abs(player1.y - place.special_2_y) < abs(player1.y_last_time - place.special_2_y))
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
		if (player1.x <= place.special_1_x)
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
		else if (player1.x > place.special_1_x)
		{
			if (abs(player1.x - place.special_1_x) < abs(player1.x_last_time - place.special_1_x) or abs(player1.y - place.special_1_y) < abs(player1.y_last_time - place.special_1_y))
				cout << "You are getting closer to the capain`s quarters!" << endl;
			else
				cout << "You are getting away the capain`s quarters!" << endl;
		}
		if (player1.x != place.special_2_x or player1.y != place.special_2_y)
		{
			if (abs(player1.x - place.special_2_x) < abs(player1.x_last_time - place.special_2_x) or abs(player1.y - place.special_2_y) < abs(player1.y_last_time - place.special_2_y))
				cout << "You are getting closer to the ladder!" << endl;
			else
				cout << "You are getting away the ladder!" << endl;
		}
		if (player1.x != place.special_3_x or player1.y != place.special_3_y)
		{
			if (abs(player1.x - place.special_3_x) < abs(player1.x_last_time - place.special_3_x) or abs(player1.y - place.special_3_y) < abs(player1.y_last_time - place.special_3_y))
				cout << "You are getting closer to the ship`s wheel!" << endl;
			else
				cout << "You are getting away the ship`s wheel!" << endl;
		}
		if (player1.x != place.special_5_x or player1.y != place.special_5_y)
		{
			if (abs(player1.x - place.special_5_x) < abs(player1.x_last_time - place.special_5_x) or abs(player1.y - place.special_5_y) < abs(player1.y_last_time - place.special_5_y))
				cout << "You are getting closer to the gangplank!" << endl;
			else
				cout << "You are getting away the gangplank!" << endl;
		}

	}
	return 0;
}
player island(player player1, scene place)
{

	string behavior = "none";
	if (player1.x == place.special_1_x and player1.y == place.special_1_y)
	{
		if (player1.banana_amount != 0)
		{
			cout << place.special_1_description << endl;
		}
		else if (player1.banana_amount == 0)
		{
			cout << place.special_1_description_2 << endl;
		}
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		while (player1.action == "cut")
		{
			cout << "You can`t cut the " << place.special_1_name << "!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
		}
		while (player1.action == "look")
		{
			if (player1.banana_amount != 0)
			{
				cout << place.special_1_look_description_1 << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
			}
			else
			{
				cout << place.special_1_look_description_2 << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
			}
		}
		if (player1.action == "take")
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
				cout << place.special_1_look_description_2 << endl;
			}
		}
	}
	else if (player1.x == place.special_2_x and player1.y == place.special_2_y)
	{
		cout << place.special_2_description << endl;
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		player1 = if_over(player1, place);
		while (player1.if_over == true)
		{
			cout << "You go too far go back!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			player1 = if_over(player1, place);
		}
		if (player1.action == "enter")
		{
			player1.in_n_out = 0;
			player1.y -= 3;
			player1.island_times += 1;
		}
		else if (player1.action == "look")
			cout << place.special_2_description << endl;
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
	}
	if (behavior == "none")
	{
		behavior = take_action(player1);
		while (behavior == "none")
		{
			cout << "You can`t do that bro" << endl;
			behavior = take_action(player1);
		}

		player1 = behave(player1, behavior);
		player1 = if_over(player1, place);
		while (player1.if_over == true)
		{
			cout << "You go too far go back!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			player1 = if_over(player1, place);
		}
	}
	player1 = engine(player1, place);
	return player1;
}
player upper_deck(player player1, scene place, int success)
{
	vector<string> give;
	string behavior = "none";
	int *if_success = &success;
	cout << "\n\n\n\n\n";
	if (player1.x <= place.special_1_x)
	{
		if (player1.knife_amount != 0)
		{
			cout << place.special_1_description << endl;

		}
		else if (player1.knife_amount == 0)
		{
			cout << place.special_1_description_2 << endl;
		}
		if (player1.x == place.table_x and player1.y == place.table_y)
		{
			if (player1.knife_amount != 0)
			{
				cout << "You see there is a shinning knife on the table!" << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
				while (behavior == "none")
				{
					cout << "You can`t do that bro" << endl;
					behavior = take_action(player1);
				}
				if (player1.action == "take")
				{
					player1.knife_amount -= 1;
					player1.inventory[place.stuff_can_get_1] += 1;
					cout << place.stuff_1_get_info << endl;
				}
			}
			else
				cout << "You see a table!" << endl;
		}
		else
		{
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			while (player1.action == "look")
			{
				if (player1.knife_amount != 0)
				{
					cout << place.special_1_look_description_1 << endl;
					behavior = take_action(player1);
					player1 = behave(player1, behavior);
				}
				else
				{
					cout << place.special_1_look_description_2 << endl;
					behavior = take_action(player1);
					player1 = behave(player1, behavior);
				}
			}
		}
	}

	else if (player1.x == place.special_2_x and player1.y == place.special_2_y)
	{
		cout << place.special_2_description << endl;
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		if (player1.action == "down")
			player1.location = "down";
	}
	else if (player1.x == place.special_3_x and player1.y == place.special_3_y)
	{
		if (player1.if_gorilla_run == 0)
		{
			cout << place.special_3_description;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			if (player1.action.substr(0, player1.action.find(" ")) == "give")
			{
				if (player1.inventory[player1.action.substr(player1.action.find(" ") + 1)] == 0)
				{
					cout << "You don`t have " << player1.action.substr(player1.action.find(" ") + 1) << "to give!!!" << endl;
				}
				else if (player1.action == "give banana")
				{
					player1.inventory["banana"] -= 1;
					player1.if_gorilla_run = 1;
					cout << "The gorilla rush to the forest and disapear" << endl;
				}
				else
				{

					cout << "Gorilla does not want " << player1.action.substr(player1.action.find(" ") + 1) << "!!!" << endl;;
				}
			}
		}
		else
		{
			if (player1.inventory[place.stuff_can_be_used_1] != 0)
			{
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
				if (player1.action == "start")
				{
					*if_success = 1;
					cout << "You finally success to sail away!" << endl;
				}
			}
			else
				cout << "You need a " << place.stuff_can_be_used_1 << " to start this ship!" << endl;
		}
	}
	else if (player1.x == place.special_5_x and player1.y == place.special_5_y)
	{
		cout << place.special_5_description << endl;
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		player1 = if_over(player1, place);
		while (player1.if_over == true)
		{
			cout << "You go too far go back!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			player1 = if_over(player1, place);
		}
		if (player1.action == "get out")
=======
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
		{
			cout << "You have got out of the ship!" << endl;
			player1.y += 3;
			player1.upper_deck_times += 1;
		}
	}
<<<<<<< HEAD
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
	}
	if (behavior == "none")
	{
		behavior = take_action(player1);
		while (behavior == "none")
		{
			cout << "You can`t do that bro" << endl;
			behavior = take_action(player1);
		}

		player1 = behave(player1, behavior);
		player1 = if_over(player1, place);
		while (player1.if_over == true)
		{
			cout << "You go too far go back!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			player1 = if_over(player1, place);
		}
	}
	player1 = engine(player1, place);
=======
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
		cout << place.long_description << endl;
	}
	cout << "x: " << player1.x << " y: " << player1.y << endl;
	if_closer(player1, place);
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
	return player1;
}
vector<string> give_stuff(string word)
{
	vector<string>give;
	int pos;
	pos = word.find(" ");
	give.push_back(word.substr(0, pos));
	pos++;
	give.push_back(word.substr(pos));
	return give;
}
int action_give(string word, player player1)
{
<<<<<<< HEAD
	int pos;
	string temp;
	int give;
	pos = word.find(" ");
	temp = word.substr(0, pos);
	if (temp == "give" or temp == player1.command[7])
		give = 1;
	else
		give = 0;
	return give;
}
=======
	int close = 0;
	if (place.name == "island")
	{
		if (player1.x == place.special_1_x and player1.y == place.special_1_y)
			;
		else if (abs(player1.x - place.special_1_x) <= abs(player1.x_last_time - place.special_1_x) and abs(player1.y - place.special_1_y) <= abs(player1.y_last_time - place.special_1_y))
			cout << "You are getting closer to the ripe banana tree!" << endl;
		else
			cout << "You are getting away the ripe banana tree!" << endl;
		if (player1.x == place.special_2_x and player1.y == place.special_2_y)
			;
		else if (abs(player1.x - place.special_2_x) <= abs(player1.x_last_time - place.special_2_x) and abs(player1.y - place.special_2_y) <= abs(player1.y_last_time - place.special_2_y))
			cout << "You are getting closer to the gangplank!" << endl;
		else
			cout << "You are getting away the gangplank!" << endl;
	}
	return 0;
}
player island(player player1, scene place)
{

	string behavior = "none";
	int stuff_1_max;
	stuff_1_max = player1.banana_amount;

	if (player1.x == place.special_1_x and player1.y == place.special_1_y)
	{
		stuff_1_max = player1.banana_amount;
		if (player1.banana_amount != 0)
		{
			cout << place.special_1_description << endl;
		}
		else if (player1.banana_amount == 0)
		{
			cout << place.special_1_description_2 << endl;
		}
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		while (player1.action == "cut")
		{
			cout << "You can`t cut the " << place.special_1_name << "!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
		}
		while (player1.action == "look")
		{
			if (player1.banana_amount != 0)
			{
				cout << place.special_1_look_description_1 << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
			}
			else
			{
				cout << place.special_1_look_description_2 << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
			}
		}
		if (player1.action == "take")
		{
			if (player1.inventory[place.stuff_can_be_used_1] != 0 and stuff_1_max != 0)
			{
				stuff_1_max -= 1;
				player1.inventory["bananas"] += 1;
				cout << place.stuff_1_get_info << endl;
			}
			else if (player1.inventory[place.stuff_can_be_used_1] == 0)
			{
				cout << "Sorry, you need a " << place.stuff_can_be_used_1 << " to get the banana." << endl;
			}
			else if (stuff_1_max == 0)
			{
				cout << place.special_1_look_description_2 << endl;
			}
		}
	}
	else if (player1.x == place.special_2_x and player1.y == place.special_2_y)
	{
		cout << place.special_2_description << endl;
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		if (player1.action == "enter")
		{
			player1.y -= 3;
			player1.long_or_short = 0;
			player1.island_times += 1;
		}
		else if (player1.action == "look")
			cout << place.special_2_description << endl;
	}
	else
	{
		if (player1.island_times == 0 and player1.long_or_short != 1)
		{
			cout << place.long_description << endl;
			player1.long_or_short = 1;
		}
		else if (player1.long_or_short != 1)
		{
			player1.long_or_short = 1;
			if (player1.banana_amount != 0)
				cout << place.short_description << endl;
			else
				cout << place.short_description_after_got << endl;
		}
	}
	if (behavior == "none")
	{
		behavior = take_action(player1);
		while (behavior == "none")
		{
			cout << "You can`t do that bro" << endl;
			behavior = take_action(player1);
		}

		player1 = behave(player1, behavior);
		player1 = if_over(player1, place);
		while (player1.if_over == true)
		{
			cout << "You go too far go back!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			player1 = if_over(player1, place);
		}
	}
	player1 = engine(player1, place);
	return player1;
}
player upper_deck(player player1, scene place, int success)
{

	bool *gorilla_run;
	string behavior = "none";
	int stuff_1_max;
	int *if_success = &success;
	stuff_1_max = player1.knife_amount;
	if (player1.x <= place.special_1_x)
	{
		stuff_1_max = player1.knife_amount;
		if (player1.knife_amount != 0)
		{
			cout << place.special_1_description << endl;

		}
		else if (player1.knife_amount == 0)
		{
			cout << place.special_1_description_2 << endl;
		}
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		while (player1.action == "look")
		{
			if (player1.knife_amount != 0)
			{
				cout << place.special_1_look_description_1 << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
			}
			else
			{
				cout << place.special_1_look_description_2 << endl;
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
			}
		}
		if (player1.action == "take")
		{
			if (stuff_1_max != 0)
			{
				stuff_1_max -= 1;
				player1.inventory[place.stuff_can_get_1] += 1;
				cout << place.stuff_1_get_info << endl;
			}
		}
	}

	else if (player1.x == place.special_2_x and player1.y == place.special_2_y)
	{
		cout << place.special_2_description << endl;
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		if (player1.action == "down")
			player1.location = "down";
	}
	else if (player1.x == place.special_3_x and player1.y == place.special_3_y)
	{
		if (player1.if_gorilla_run == 0)
		{
			cout << place.special_3_description;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			if (player1.action == "give")
			{
				player1.inventory["banana"] -= 1;
				gorilla_run = &player1.if_gorilla_run;
				*gorilla_run = 1;
				cout << "The gorilla rush to the forest and disapear" << endl;
			}
		}
		else
		{
			if (player1.inventory[place.stuff_can_be_used_1] != 0)
			{
				behavior = take_action(player1);
				player1 = behave(player1, behavior);
				if (player1.action == "start")
				{
					*if_success = 1;
					cout << "You finally success to sail away!" << endl;
				}
			}
			else
				cout << "You need a " << place.stuff_can_be_used_1 << " to start this ship!" << endl;
		}
	}
	else if (player1.x == place.special_5_x and player1.y == place.special_5_y)
	{
		cout << place.special_5_description << endl;
		behavior = take_action(player1);
		player1 = behave(player1, behavior);
		if (player1.action == "get out")
		{
			player1.y += 3;
			player1.upper_deck_times += 1;
		}
	}
	else
	{
		if (player1.upper_deck_times == 0 and player1.long_or_short != 1)
		{
			cout << place.long_description << endl;
			player1.long_or_short = 1;
		}
		else if (player1.long_or_short != 1)
		{
			player1.long_or_short = 1;
			if (player1.knife_amount != 0)
				cout << place.short_description << endl;
			else
				cout << place.short_description_after_got << endl;
		}
	}
	if (behavior == "none")
	{
		behavior = take_action(player1);
		while (behavior == "none")
		{
			cout << "You can`t do that bro" << endl;
			behavior = take_action(player1);
		}

		player1 = behave(player1, behavior);
		player1 = if_over(player1, place);
		while (player1.if_over == true)
		{
			cout << "You go too far go back!" << endl;
			behavior = take_action(player1);
			player1 = behave(player1, behavior);
			player1 = if_over(player1, place);
		}
	}
	player1 = engine(player1, place);
	return player1;
}
>>>>>>> fa3d218d9dbccbc869dc4287e1c1692a6a6668aa
