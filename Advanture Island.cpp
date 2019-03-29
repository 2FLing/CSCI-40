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
	string stuff_can_cut_name;
	string place_can_give_stuff_1_name;
	string place_can_give_stuff_2_name;
	string entrance_1_name;
	string entrance_2_name;
	string entrance_3_name;
	string entrance_4_name;
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
	int entrance_4_x;
	int entrance_4_y;
	int place_can_give_stuff_1_x;
	int place_can_give_stuff_1_y;
	int place_can_give_stuff_2_x;
	int place_can_give_stuff_2_y;
	int place_can_use_stuff_1_x;
	int place_can_use_stuff_1_y;
	int bed_x;
	int bed_y;
	int table_x;
	int table_y;
	int barrel_x;
	int barrel_y;
	int trunk_x;
	int trunk_y;
	int tool_x;
	int tool_y;

};
class player
{
public:
	map<string, int> inventory;
	map<string, string>drop_stuff;
	string action;
	string object;
	string command[33] = { "north","south","west","east","board","enter","take","give","search","look","eat","cut","climb","drop","up","down","unlock","sail","open","quit","inventory","setting","save","load" ,"hint","help","get out","hide","display","start","drop","pick","null" };
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
	int lower_times = 0;
	int captain_quarts_times = 0;
	int ship_wheel_times = 0;
	int cargo_hold_times = 0;
	int brig_times = 0;
	int galley_times = 0;
	int hide = 0;
	int upper_deck_times = 0;
	int capitains_quarters_times = 0;
	int in_n_out = 0;
	bool if_gorilla_run = 0;
	bool if_over = false;
};
player island(player, scene);
player upper_deck(player, scene, int);
player lower_deck(player, scene);
player load_game(player);
int save_game(player);
void action_seprate(string&, string&, string);
player take_action(player, scene);
scene set_scene(player);
player if_over(player, scene);
player init_inventory(player);
void help();
player setting(player);
string To_lower(string);
string coordinate_to_string(player);
bool if_has_object(string);
bool if_can_get(player, scene, string stuff = "nothing");
bool if_can_cut(player, scene, string stuff = "nothing");
bool if_can_give(player, scene, string stuff = "nothing");
bool if_can_eat(player, scene, string food = "nothing");
bool if_can_drop(player, string stuff = "nothing");
bool if_can_pick(player, string stuff = "nothing");
int if_closer(player, scene);
player so_bad_so_sad(player);
player re_take_action(player, scene);
player pick_it_up(player, scene);
string re_name(player, string);
string recover_name(string);
string pig_latin(string);
string sentence_to_pig_latin(string);
void get_sentence(string, vector<string>&, vector<string>&);
player drop_it(player);
int get_number(string);
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
player take_action(player player1, scene place)
{
	bool save = false;
	bool load = false;
	string action = "char";
	string actions;
	string objects;
	string extra_action = "none";
	string drop_coordinate;
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
	else if (actions == "go" or actions == "north" or actions == "south" or actions == "west" or actions == "east" or action == player1.command[0] or action == player1.command[1] or action == player1.command[2] or action == player1.command[3])
	{
		if (actions == "go" and objects == "none")
		{
			cout << "\n\n\n\n";
			cout << "Which direction you want to go?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			objects = extra_action;
		}
		if ((objects == "north" and actions == "go") or action == player1.command[0] or (actions == "north" and objects == "none"))
		{
			cout << "\n\n\n\n";
			cout << "You are going north" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.x += 1;
			player1.action = "move";
		}
		else if ((objects == "south" and actions == "go") or action == player1.command[1] or (actions == "south" and objects == "none"))
		{
			cout << "\n\n\n\n";
			cout << "You are going south" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.x -= 1;
			player1.action = "move";
		}
		else if ((objects == "west" and actions == "go") or (actions == "west" and objects == "none") or action == player1.command[2])
		{
			cout << "\n\n\n\n";
			cout << "You are going west" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.y += 1;
			player1.action = "move";
		}
		else if ((objects == "east" and actions == "go") or (actions == "east" and objects == "none") or action == player1.command[3])
		{
			cout << "\n\n\n\n";
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
			cout << "\n\n\n\n";
			cout << "What are you gonna take?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			player1.object = extra_action;
			if (if_can_get(player1, place, extra_action))
				player1.action = "get";
		}
		else if (objects == "it")
		{
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
	else if (actions == "eat" or action == player1.command[10])
	{
		player1.object = objects;
		if (objects == "none")
		{
			cout << "\n\n\n\n";
			cout << "What you are gonna eat?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			if (if_can_eat(player1, place, extra_action) and player1.inventory[extra_action] != 0)
			{
				player1.action = "eat";
				player1.object = objects;
				player1.inventory[extra_action]--;
				cout << "\n\n\n\n";
				cout << "After you eat " << extra_action << " your stomach feels better" << endl;
			}
			else
			{
				player1.action = "none";
				cout << "\n\n\n\n";
				cout << "You don`t have " << extra_action << " to eat!" << endl;
			}
		}
		else
		{
			if (if_can_eat(player1, place))
			{
				player1.action = "eat";
				player1.object = objects;
				player1.inventory[objects]--;
				cout << "\n\n\n\n";
				cout << "After you eat " << objects << " your stomach feels better" << endl;
			}
			else
			{
				cout << "\n\n\n\n";
				cout << "You don`t have " << objects << " to eat!" << endl;
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
			cout << "\n\n\n\n";
			map<string, int>::iterator it;
			for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
				cout << it->first << ": " << it->second << endl;
		}
		else
			player1 = so_bad_so_sad(player1);

	}
	else if (actions == "start" or action == player1.command[29])
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
			player1 = so_bad_so_sad(player1);
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
			{
				cout << "\n\n\n\n";
				cout << "Save successfully!" << endl;
			}
			else
			{
				cout << "\n\n\n\n";
				cout << "Save fail!" << endl;
			}
		}
		else
			player1 = so_bad_so_sad(player1);
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
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "cut" or action == player1.command[11])
	{
		if (player1.inventory["knife"] == 0)
		{
			cout << "\n\n\n\n";
			cout << "You need a knife to cut!" << endl;
			player1.action = "none";
		}
		else if (objects == "none")
		{
			cout << "\n\n\n\n";
			cout << "What are you gonna cut?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			if (if_can_cut(player1, place, extra_action))
				player1.action = "cut";
		}
		else if (objects == "it")
		{
			player1.action = actions;
			player1.object = objects;
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
		if (objects == "none" or objects == "game")
			exit(0);
		else
			player1 = so_bad_so_sad(player1);
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
			cout << "\n\n\n\n";
			cout << "What are you gonna get?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			player1.object = extra_action;
			if (if_can_get(player1, place, extra_action))
			{
				player1.action = "get";
			}
		}
		else if (objects == "it")
		{
			player1.action = actions;
			player1.object = objects;
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
			cout << "\n\n\n\n";
			cout << "What you wanna give?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
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
	else if (actions == "drop" or action == player1.command[30])
	{
		player1.action = actions;
		player1.object = objects;
		if (objects == "none")
		{
			cout << "What are you gonna drop?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			if (if_can_drop(player1, extra_action))
			{
				player1.object = extra_action;
				player1 = drop_it(player1);
			}
			else
			{
				player1.action = "none";
				cout << "You don`t have " << extra_action << " to drop!" << endl;
			}
		}
		else
		{
			if (if_can_drop(player1))
			{
				player1 = drop_it(player1);
			}

			else
			{
				player1.action = "none";
				cout << "You don`t have " << objects << " to drop!" << endl;
			}
		}
	}
	else if (actions == "pick" or action == player1.command[31])
	{
		player1.object = objects;
		if (objects == "none")
		{
			cout << "What are you gonna pick?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			if (if_can_pick(player1, extra_action))
			{
				player1.action = "pick";
				player1.object = objects;
			}
			else
			{
				player1.action = "none";
				player1.object = "none";
			}
		}
		else if (objects == "it up" or objects == "it")
		{
			player1.action = "pick";
			player1.object = "none";
		}
		else
		{
			if (if_can_pick(player1))
				player1.action = "pick";
			else
			{
				player1.action = "none";
				player1.object = "none";
			}
		}

	}
	else
	{
		cout << "\n\n\n\n";
		cout << "You can`t do that bro!" << endl;
	}
	if (player1.hide == 0 and player1.action == "move" or player1.action == "load" or player1.action == "display" or player1.action == "save")
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
		place.min_y = -5;
		place.stuff_can_cut_x = 3;
		place.stuff_can_cut_y = 2;
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
		place.entrance_1_description = "There is a bed and a table in this room.";
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
	else if (player1.y <= -7 and player1.location == "down")
	{
		place.name = "lower deck";
		place.stuff_can_eat.push_back("banana");
<<<<<<< HEAD
		place.stuff_can_get.push_back("treasure");
		place.long_description = "The deck below is dimly lit, and smells musty. You can make out three doors.\n One is to the east, one is to the west, and one is a trapdoor below you.\nstuff you can get: treasure.";
		place.long_description_after_got = "The deck below is dimly lit, and smells musty. You can make out three doors.\n One is to the east, one is to the west, and one is a trapdoor below you.";
		place.short_description_after_got = "It is lower deck";
		place.short_description = "It is lower deck\nstuff you can get: knife";
		place.entrance_1_name = "cargo hold";
		place.entrance_2_name = "ladder";
		place.entrance_3_name = "brig";
		place.entrance_4_name = "galley";
		place.entrance_1_description = "You`ve entered the cargo hold. Ther are barrels, a pile of tools, and a trunk.";
		place.entrance_2_description = "There is a ladder, do you want to go down?";
		place.entrance_1_look_description_1 = "There are barrels, a pile of tools, and a trunk.";
		place.entrance_3_description = "In this room there is a prisoner in a locked cell.\nHe says,\"Jack,I`m so glad you`re alive. The captain locked me up for cheating at cards, which is the only reason the islanders didn`t capture me.\nThey killed everyone else.\nNow I guess we`re the only two left, which makes you captain since you were first mate.\n Go find the keys to unlock this door, and we can sail out of here.\"";
		place.hint = "Why there is trunk in the ship?";
		place.stuff_can_be_used_1 = "key";
		place.stuff_can_get.push_back("treasure");
		place.stuff_1_get_info = "You got the treasure!";
=======
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
>>>>>>> 282998a41bd2b66dad36f09e3c3f08e25032ae19
		place.max_x = 7;
		place.min_x = -4;
		place.max_y = -7;
		place.min_y = -12;
		place.entrance_1_x = -1;
<<<<<<< HEAD
		place.entrance_1_y = -9;
		place.entrance_2_x = 2;
		place.entrance_2_y = -10;
		place.entrance_3_x = 0;
		place.entrance_3_y = -11;
		place.entrance_4_x = 2;
		place.entrance_4_y = -10;
		place.place_can_use_stuff_1_x = 0;
		place.place_can_give_stuff_1_y = -11;
		place.barrel_x = -2;
		place.barrel_y = -8;
		place.tool_x = 1;
		place.tool_y = -7;
		place.trunk_x = 3;
		place.trunk_y = -7;
=======
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
>>>>>>> 282998a41bd2b66dad36f09e3c3f08e25032ae19
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
	string change, *new_command, eat_trash;
	int traversal = 0, index;
	int number;
	bool repeat = true;

	new_command = player1.command;
	cout << "There are commands in this game." << endl;
	for (index = 0; index <= 31; index++)
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
		case 30:cout << index + 1 << ". " << "To" << " drop something---" << player1.command[index] << endl; break;
		case 31:cout << index + 1 << ". " << "To" << " pick something---" << player1.command[index] << endl; break;
			break;
		}

	}
	cout << "Enter the front number to choose which one you want to change" << endl;
	cin >> number;
	if (cin.fail() or cin.bad())
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
	if (number > 0 and number <= index)
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
int save_game(player player1)//写一个东西存 drop stuff 
{
	ofstream game_file;
	map<string, int>::iterator it;
	map<string, string>::iterator drop_stuff;
	int success = 1;
	string *set;
	game_file.open("Advanture Island.txt");
	if (!game_file.is_open())
	{
		cout << "\n\n\n\n";
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
		for (set = player1.command; *set != "null"; set++)
			game_file << *set << endl;
		game_file << "drop_stuff:" << endl;
		for (drop_stuff = player1.drop_stuff.begin(); drop_stuff != player1.drop_stuff.end(); drop_stuff++)
		{
			game_file << drop_stuff->first << endl;
			game_file << drop_stuff->second << endl;
		}
		game_file.close();
		++set = NULL;
	}
	return success;
}
player load_game(player player1)
{
	ifstream game_file;
	map<string, int>::iterator it;
	string loaction, inventory, banana_amount, knife_amount, player_location, player_x_last_time, setting, *set, hide, drop_stuff;
	string plaer_y_last_time, player_island_times, player_upper_deck_times, player_capitains_quarters_times;
	game_file.open("Advanture Island.txt");
	if (!game_file.is_open())
	{
		cout << "\n\n\n\n";
		cout << "Fail loading game!" << endl;
	}
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
		game_file.seekg(2, ios::cur);
		for (set = player1.command; *set != "null"; set++)
			getline(game_file, *set);
		player1.load = 1;
		game_file >> drop_stuff;
		game_file.seekg(2, ios::cur);
		while (!game_file.eof())
		{
			getline(game_file, drop_stuff);
			getline(game_file, player1.drop_stuff[drop_stuff]);
		}
		cout << "\n\n\n\n";
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
	player1 = pick_it_up(player1, place);

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
		while (player1.action == "look" and (player1.object == "banana tree" or player1.object == "none"))
		{
			if (player1.banana_amount != 0)
			{
				cout << place.stuff_can_cut_look_description_1 << endl;
				player1 = take_action(player1, place);
			}
			else
			{
				cout << place.stuff_can_cut_look_description_2 << endl;
				player1 = take_action(player1, place);
			}
		}
		if ((player1.action == "get" or player1.action == "cut") and (player1.object == "banana" or player1.object == "it"))
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
	player1 = pick_it_up(player1, place);
	if (player1.x <= place.entrance_1_x)
	{
		if (player1.x == place.table_x and player1.y == place.table_y)
		{
			if (player1.knife_amount != 0)
			{
				cout << "You see there is a shinning knife on the table!" << endl;
				player1 = take_action(player1, place);
				player1 = re_take_action(player1, place);
				if (player1.action == "get" and player1.object == "knife")
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
				else if (player1.action == "get")
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
		player1 = take_action(player1, place);
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
player lower_deck(player player1, scene place)
{
	player1 = pick_it_up(player1, place);
	if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
	{
		cout << place.entrance_1_description << endl;
		player1 = take_action(player1, place);
	}

	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		cout << place.entrance_2_description << endl;
		player1 = take_action(player1, place);
		if (player1.action == "down")
			player1.location = "down";
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
	return player1;
}
void action_seprate(string &actions, string &objects, string action)
{
	int pos;
	bool has_object;
	has_object = if_has_object(action);
	if (has_object)
	{
		pos = action.find(" ");
		actions = action.substr(0, pos);
		pos++;
		objects = action.substr(pos);
	}
	else
	{
		actions = action;
		objects = "none";
	}
}
bool if_has_object(string action)
{
	int has = false, action_index;
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
	cout << "\n\n\n\n";
	cout << "So bad so sad, you can`t " << player1.action << " " << player1.object << " right now!" << endl;
	player1.action = "none";
	return player1;
}
bool if_can_get(player player1, scene place, string stuff)
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
	else if (stuff != "nothing")
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
bool if_can_cut(player player1, scene place, string stuff)
{
	bool cut = false;
	vector<string>::iterator it;

	if (stuff == "nothing")
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
	bool give = false, equal = false;
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
		if (equal == false)
			cout << "You don`t have " << player1.object << " to give!" << endl;
	}
	else
	{
		for (it = place.stuff_can_give.begin(); it != place.stuff_can_give.end(); it++)
		{
			if (stuff == *it)
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
bool if_can_eat(player player1, scene place, string food)
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
bool if_can_pick(player player1, string stuff)
{
	map<string, string>::iterator it;
	bool pick = false;
	string name;
	if (stuff == "nothing")
	{
		for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
		{
			name = recover_name(it->first);
			if (name == player1.object)
			{
				pick = true;
			}
		}
		if (pick == false)
			cout << player1.object << " is not here!" << endl;
	}
	else
	{
		for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
		{
			name = recover_name(it->first);
			if (name == stuff)
				pick = true;
		}
		if (pick == false)
			cout << stuff << " is not here!" << endl;
	}
	return pick;
}
player re_take_action(player player1, scene place)
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
bool if_can_drop(player player1, string stuff)
{
	bool drop = false;
	map<string, int>::iterator it;
	if (stuff == "nothing")
	{
		for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
			if (it->first == player1.object and it->second != 0)
				drop = true;
	}
	else
	{
		for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
			if (it->first == stuff and it->second != 0)
				drop = true;
	}
	return drop;
}
string coordinate_to_string(player player1)
{
	string coordinate, up_or_down;
	if (player1.location == "up")
		up_or_down = "1";
	else
		up_or_down = "0";
	coordinate = to_string(player1.x);
	coordinate.append(" ");
	coordinate.append(to_string(player1.y));
	coordinate.append(" ");
	coordinate.append(up_or_down);
	return coordinate;
}
player pick_it_up(player player1, scene place)
{
	string coordinate, name, origin_name;
	map<string, string>::iterator it;
	coordinate = coordinate_to_string(player1);
	bool got_back = false;
	it = player1.drop_stuff.begin();
	while (!got_back and it != player1.drop_stuff.end())
	{
		if (coordinate == it->second)
		{
			origin_name = recover_name(it->first);
			name = it->first;
			if (player1.action == "pick" and (player1.object == "none" or player1.object == origin_name))
			{
				cout << "You got the " << origin_name << " back!" << endl;
				player1.inventory[origin_name]++;
				player1.drop_stuff.erase(name);
				got_back = true;
			}
			if (!got_back)
			{
				cout << "You see the " << origin_name << " you throwed away is lying on the ground" << endl;
				got_back = true;
			}
		}
		else
			it++;
	}
	return player1;
}
string re_name(player player1, string stuff)
{
	int times, pos, number = 0, max = 0;
	map<string, string>::iterator it;
	for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
	{
		max = get_number(it->first);
		if (max > number)
			number = max;
	}
	pos = stuff.find(" ");
	stuff = stuff.substr(0, pos);
	number += 1;
	stuff.append(" ");
	stuff.append(to_string(number));
	return stuff;
}
string recover_name(string name)
{
	int index, pos;
	bool has_space = false;
	for (index = 0; index <= name.length() - 1; index++)
		if (name.at(index) == ' ')
			has_space = true;
	if (has_space)
	{
		pos = name.find(" ");
		name = name.substr(0, pos);
	}
	return name;
}
player drop_it(player player1)
{
	map<string, string>::iterator it;
	string name, drop_coordinate;
	bool duplicate = false;
	player1.inventory[player1.object]--;
	drop_coordinate = coordinate_to_string(player1);
	for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
	{
		if (duplicate == false)
		{
			name = it->first;
			name = recover_name(name);
			if (name == player1.object)
			{
				name = it->first;
				cout << "You drop a " << player1.object << "!\nPlease protect the environment!" << endl;
				name = re_name(player1, name);
				player1.drop_stuff[name] = drop_coordinate;
				duplicate = true;
			}
		}

	}
	if (duplicate == false)
	{
		cout << "You drop a " << player1.object << "!\nPlease protect the environment!" << endl;
		player1.object.append(" ");
		player1.object.append("1");
		player1.drop_stuff[player1.object] = drop_coordinate;
	}
	return player1;
}
int get_number(string name)
{
	int pos, number;
	pos = name.find(" ");
	name = name.substr(pos + 1);
	number = stoi(name);
	return number;
}
string sentence_to_pig_latin(string sentence)
{
	string new_sentence;
	vector<string>marks;
	vector<string>word;
	int marks_index = 0, word_index = 0;
	get_sentence(sentence, marks, word);
	if (size(marks) > size(word))
	{
		while (marks_index <= size(marks) - 1)
		{
			new_sentence.append(marks[marks_index]);
			marks_index++;
			if (word_index <= size(word) - 1)
			{
				word[word_index] = pig_latin(word[word_index]);
				new_sentence.append(word[word_index]);
				word_index++;
			}
		}
	}
	else
	{
		while (word_index <= size(word) - 1)
		{
			word[word_index] = pig_latin(word[word_index]);
			new_sentence.append(word[word_index]);
			word_index++;
			if (marks_index <= size(marks) - 1)
			{
				new_sentence.append(marks[marks_index]);
				marks_index++;
			}
		}
	}
	return new_sentence;
}
string pig_latin(string word)
{
	string first_letter;
	first_letter = word.at(0);
	first_letter.append("ay");
	word = word.substr(1);
	word.append(first_letter);
	return word;
}
void get_sentence(string sentence, vector<string>&marks, vector<string>&word)
{
	int index = 0;
	string mark = " ", temp_mark, words = " ", temp_word;
	while (index <= sentence.length() - 1)
	{
		if ((sentence.at(index) >= 'a' and sentence.at(index) <= 'z') or (sentence.at(index) >= 'A' and sentence.at(index) <= 'Z') and index < sentence.length() - 1)
		{
			if (mark.length() != 1)
			{
				mark = mark.substr(1);
				marks.push_back(mark);
			}
			temp_word = sentence.at(index);
			words.append(temp_word);
			if (index == sentence.length() - 1)
			{
				words = words.substr(1);
				word.push_back(words);
			}
			index++;
			mark = " ";
		}
		else if (index <= sentence.length() - 1)
		{
			temp_mark = sentence.at(index);
			mark.append(temp_mark);
			if (index == sentence.length() - 1)
			{
				mark = mark.substr(1);
				marks.push_back(mark);
			}
			if (words.length() != 1)
			{
				words = words.substr(1);
				word.push_back(words);
			}
			index++;
			words = " ";
		}
	}
}