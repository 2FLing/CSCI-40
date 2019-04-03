//Group2
//MingkuanPang
//Juan
//Karnvir
//Matthew Jones
//CSCI-40 group project Advanture Island game.
//use "-std=c++11" to compile"
#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
using namespace std;
const int COMMAND_LENGTH = 32;
class scene
{
public:
	string name;
	string long_description;
	string short_description;
	string stuff_can_cut_name;
	string entrance_1_name;
	string entrance_2_name;
	string entrance_3_name;
	string entrance_4_name;
	string special_1_name;
	string stuff_can_cut_description;
	string entrance_1_description;
	string entrance_1_description_2;
	string entrance_1_short_description;
	string entrance_1_description_after_got;
	string entrance_1_short_description_after_got;
	string entrance_1_short_description_2;
	string stuff_can_cut_look_description_1;
	string stuff_can_cut_look_description_2;
	string stuff_can_cut_description_2;
	string entrance_2_description;
	string entrance_2_description_2;
	string entrance_2_short_description;
	string entrance_2_short_description_2;
	string special_1_description;
	string entrance_3_description;
	string entrance_3_short_description;
	string entrance_3_short_description_after;
	string entrance_4_description;
	string entrance_4_description_2;
	string entrance_4_short_description;
	string stuff_1_get_info;
	map<string, string>stuff_can_cut;
	map<string, string>stuff_can_give;
	map<string, string>stuff_can_get;
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
};
class player
{
public:
	map<string, int> inventory;
	map<string, string>drop_stuff;
	string action;
	string object;
	string command[32] = { "north","south","west","east","board","enter","take","give","search","look","eat","cut","climb","drop","up","down","unlock","sail","open","quit","inventory","setting","save","load" ,"hint","help","get","hide","display","start","pick","null" };
	string location = "island";
	string room = "none";
	string last_room = "none";
	int in_n_out = 0;
	int set = 1;
	int load = 0;
	int x = 4;
	int y = -3;
	int x_last_time = 4;
	int y_last_time = -3;
	int banana_amount = 1;
	int treasure_amount = 1;
	int key_amount = 1;
	int knife_amount = 1;
	int island_times = 0;
	int lower_times = 0;
	int captain_quarters_times = 0;
	int cargo_hold_times = 0;
	int brig_times = 0;
	int galley_times = 0;
	int hide = 0;
	int upper_deck_times = 0;
	int if_gorilla_run = 0;
	int parrot = 0;
	int hostile = 0;
	int prison = 0;
	int get = 0;
	bool if_over = false;
};
player island(player, scene);
player upper_deck(player, scene, bool&);
player lower_deck(player, scene);
player load_game(player);
player add_times(player);
player look_hint_and_search(player, scene);
int save_game(player);
void action_seprate(string&, string&, string);
player take_action(player, scene);
scene set_scene(player, scene);
scene init_scene(scene);
player if_over(player, scene);
player init_inventory(player);
void help(player);
void welcome();
void extra_info(player, scene);
player setting(player);
string To_lower(string);
string To_lower_2(string);
string coordinate_to_string(player);
bool if_has_object(string);
bool if_can_get(player, scene, string stuff = "nothing");
bool if_can_cut(player, scene, string stuff = "nothing");
bool if_can_give(player, scene, string stuff = "nothing");
bool if_can_eat(player, scene, string food = "nothing");
bool if_can_drop(player, string stuff = "nothing");
bool if_can_pick(player, string stuff = "nothing");
int location(player, scene);
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
bool has_mark(string);
int main()
{
	bool success = false;
	player player1;
	scene place;
	string word;
	player1 = init_inventory(player1);
	place = init_scene(place);
	welcome();
	while (!success)
	{
		place = set_scene(player1, place);
		if (place.name == "island")
			player1 = island(player1, place);
		else if (place.name == "upper deck")
			player1 = upper_deck(player1, place, success);
		else
			player1 = lower_deck(player1, place);
	}
	cout << "Game Over" << endl;
	return 0;
}
player take_action(player player1, scene place)//This function can transfer the command from player to the action of the character in the game.
{
	bool save = false;
	bool load = false;
	string action = "char";
	string actions, eat_enter;
	string objects;
	string extra_action = "none";
	string drop_coordinate;
	cout << "What are you gonna do?" << endl;
	action = getchar();
	while (action == "\n")
	{
		cout << "Enter fail" << endl;
		cout << "What are you gonna do?" << endl;
		action = getchar();
	}
	eat_enter = action;
	getline(cin, action);
	action = eat_enter + action;
	action = To_lower(action);
	if (action == "leave")
		action = "get out";
	action_seprate(actions, objects, action);
	if (actions == "setting" or action == player1.command[21])
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
			player1.object = "north";
		}
		else if ((objects == "south" and actions == "go") or action == player1.command[1] or (actions == "south" and objects == "none"))
		{
			cout << "You are going south" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.x -= 1;
			player1.action = "move";
			player1.object = "south";
		}
		else if ((objects == "west" and actions == "go") or (actions == "west" and objects == "none") or action == player1.command[2])
		{
			cout << "You are going west" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.y += 1;
			player1.action = "move";
			player1.object = "west";
		}
		else if ((objects == "east" and actions == "go") or (actions == "east" and objects == "none") or action == player1.command[3])
		{
			cout << "You are going east" << endl;
			player1.x_last_time = player1.x;
			player1.y_last_time = player1.y;
			player1.y -= 1;
			player1.action = "move";
			player1.object = "east";
		}
		else if (objects == "up" and actions == "go" and player1.room == "ladder")
		{
			player1.action = "up";
		}
		else if (objects == "down" and actions == "go" and player1.room == "ladder")
		{
			player1.action = "down";
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
		if (objects == "none" or objects == "around")
		{
			player1.action = "look";
			player1 = look_hint_and_search(player1, place);
		}
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "search" or action == player1.command[8])
	{
		player1.action = "search";
		if (objects == "none" or objects == "it")
			player1 = look_hint_and_search(player1, place);

		else
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
			cout << "What you are gonna eat?" << endl;
			getline(cin, extra_action);
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
				cout << "After you eat " << objects << " your stomach feels better" << endl;
			}
			else
			{
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
			map<string, int>::iterator it;
			for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
				cout << it->first << ": " << it->second << endl;
		}
		else
			player1 = so_bad_so_sad(player1);

	}
	else if (actions == "start" or action == player1.command[29])
	{
		player1.action = "start";
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
		{
			player1.action = "start";
			player1.object = "ship";
		}
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "hint" or action == player1.command[24])
	{
		player1.action = "hint";
		player1.object = objects;
		if (objects == "none")
			player1 = look_hint_and_search(player1, place);
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
				cout << "Save successfully!" << endl;
			}
			else
			{
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
			cout << "You need a knife to cut!" << endl;
			player1.action = "none";
		}
		else if (objects == "none")
		{
			cout << "What are you gonna cut?" << endl;
			getline(cin, extra_action);
			extra_action = To_lower(extra_action);
			player1.action = actions;
			player1.object = extra_action;
			if (if_can_cut(player1, place, extra_action))
				player1.action = "cut";
		}
		else if (objects == "it")
		{
			if (player1.room == "banana tree")
				player1.action = "cut";
			else
				cout << "Cut cut cut, your skill of cutting is getting better." << endl;
		}
		else
		{
			player1.action = actions;
			player1.object = objects;
			if (if_can_cut(player1, place))
				player1.action = "cut";
			else
				cout << "Cut cut cut, your skill of cutting is getting better." << endl;
		}
	}
	else if (actions == "help" or action == player1.command[25])
	{
		player1.action = "help";
		if (objects == "none")
			help(player1);
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
	else if (actions == "get" or action == player1.command[26])
	{
		player1.object = objects;
		if (objects == "out")
		{
			player1.action = "get out";
			player1.object = "none";
		}
		else
		{
			if (objects == "none")
			{
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
				cout << "You can`t get the " << objects << " right here!" << endl;
		}
	}
	else if (actions == "give" or action == player1.command[7])
	{
		player1.object = objects;
		if (objects == "none")
		{
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
	else if (actions == "drop" or action == player1.command[13])
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
	else if (actions == "pick" or action == player1.command[30])
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
	else if (actions == "up" or action == player1.command[14])
	{
		if (objects == "none" and player1.room == "ladder")
			player1.action = "up";
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "down" or action == player1.command[15])
	{
		if (objects == "none" and player1.room == "ladder")
			player1.action = "down";
		else
			player1 = so_bad_so_sad(player1);
	}
	else if (actions == "unlock" or action == player1.command[16])
	{
		if (player1.inventory["key"] == 0)
			cout << "You need a key to unlock!" << endl;
		else if ((objects == "none" or objects == "brig") and player1.room == "brig")
			player1.action = "unlock";
		else if (objects != "none" and player1.room == "brig")
			cout << "This is a brig not a " << objects << endl;
		else
			player1 = so_bad_so_sad(player1);
	}
	else
	{
		cout << "You can`t do that bro!" << endl;
	}

	return player1;
}
player if_over(player player1, scene place)//This function can determind if the player is over the boundaries of the map.
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
scene set_scene(player player1, scene place)//This function can set up the map according to the coordinate of the player.
{
	if (player1.y >= -6)
	{
		place.name = "island";
		place.long_description = "You are in a island.The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore.\nEnter \"help\" for help";
		place.short_description = "You are currently in the island, there are so many banana trees!";
		place.stuff_can_cut_name = "tree";
		place.entrance_1_name = "gangplank";
		place.stuff_can_cut_description = "You are standing in front of a ripe banana tree, you can take a look to see what is on the tree.\nstuff you can get:banana.";
		place.entrance_1_description = "You found a gangplank! You wanna enter the ship?";
		place.stuff_can_cut_look_description_1 = "There is one branch of repe bananas on the tree.";
		place.stuff_can_cut_look_description_2 = "There is nothing on the tree....";
		place.stuff_can_cut_description_2 = "You are standing in front of a ripe banana tree! But....there is nothing on the tree you can reach....";
		place.stuff_1_get_info = "You got a tempting banana!";
		place.max_x = 5;
		place.min_x = -5;
		place.max_y = 5;
		place.min_y = -5;
		place.stuff_can_cut_x = 4;
		place.stuff_can_cut_y = -2;
		place.entrance_1_x = 4;
		place.entrance_1_y = -4;
	}
	else if (player1.y <= -7 and player1.location == "up")
	{
		place.name = "upper deck";
		place.long_description = "You are in the top deck of the ship.The top deck has a wheel at the north end of the ship, and the south end of the ship has a ladder down to the lower deck.";
		place.short_description = "You are in the upper deck.";
		place.entrance_1_name = "capain`s quarters";
		place.entrance_2_name = "ladder";
		place.entrance_4_name = "Ship`s Wheel";
		place.special_1_name = "gorilla";
		place.entrance_3_name = "gangplank";
		place.entrance_1_description = "You are in the captain`s quarter. There is a bed and a table in this room.\nstuff you can get: knife";
		place.entrance_1_description_after_got = "You are in the captain`s quarter. There is a bed and a table in this room.";
		place.entrance_1_short_description = "You are in the captsin`s quarter.\nstuff you can get: knife";
		place.entrance_1_short_description_after_got = "You are in the captain`s quarter";
		place.entrance_2_description = "There is a ladder, do you want to go down?";
		place.entrance_4_description = "You are at ship`s wheel.There is a large gorilla by the ship`s wheel. The gorilla is hostile. You can`t approach the wheel.\n";
		place.entrance_4_description_2 = "You are at ship`s wheel. There is a gorilla right there.";
		place.entrance_4_short_description = "You are at the wheel.";
		place.entrance_3_description = "You found a gangplank! You wanna leave the ship?";
		place.stuff_1_get_info = "You got a sharp knife!";
		place.max_x = 4;
		place.min_x = 0;
		place.max_y = -8;
		place.min_y = -11;
		place.entrance_1_x = 1;
		place.entrance_1_y = -10;
		place.entrance_2_x = 2;
		place.entrance_2_y = -10;
		place.entrance_4_x = 3;
		place.entrance_4_y = -10;
		place.entrance_3_x = 3;
		place.entrance_3_y = -9;
	}
	else if (player1.y <= -7 and player1.location == "down")
	{
		place.name = "lower deck";
		place.long_description = "You are in the lower deck of the ship.The deck below is dimly lit, and smells musty. You can make out three doors.\nOne is to the east, one is to the west, and one is a trapdoor below you.";
		place.short_description = "You are in the lower deck.";
		place.entrance_1_name = "cargo hold";
		place.entrance_2_name = "ladder";
		place.entrance_3_name = "brig";
		place.entrance_4_name = "galley";
		place.entrance_1_description = "You`ve entered the cargo hold. There are barrels, a pile of tools, and a trunk.";
		place.entrance_1_short_description = "You`ve entered the cargo hold.";
		place.entrance_2_description = "There is a ladder, do you want to go up?";
		place.entrance_3_description = "You are at brig.In this room there is a prisoner in a locked cell.\nHe says,\"Jack,I`m so glad you`re alive. The captain locked me up for cheating at cards, which is the only reason the islanders didn`t capture me.\nThey killed everyone else.\nNow I guess we`re the only two left, which makes you captain since you were first mate.\n Go find the keys to unlock this door, and we can sail out of here.\"";
		place.entrance_3_short_description = "You are at brig, that man is watching you.";
		place.entrance_3_short_description_after = "You are at the brig.";
		place.entrance_4_description = "This is galley. It is mostly empty, but in a shadowy corner you see a parrot sitting on a perch.";
		place.entrance_4_short_description = "You are in the galley";
		place.stuff_1_get_info = "You got the treasure!";
		place.max_x = 7;
		place.min_x = -10;
		place.max_y = -7;
		place.min_y = -20;
		place.entrance_1_x =2;
		place.entrance_1_y = -9;
		place.entrance_2_x = 2;
		place.entrance_2_y = -10;
		place.entrance_3_x = 1;
		place.entrance_3_y = -10;
		place.entrance_4_x = 2;
		place.entrance_4_y = -11;
		
	}
	return place;
}

player init_inventory(player player1)//This function can initialize the inventory of the player.
									 //Usually the amounts of the stuff that player carrying are all zeros.
{

	player1.inventory["knife"] = 0;
	player1.inventory["banana"] = 0;
	player1.inventory["treasure"] = 0;
	player1.inventory["trunk"] = 0;
	player1.inventory["key"] = 0;
	player1.inventory["stem"] = 0;
	return player1;
}
player setting(player player1)//This function can let the player set up the command keys in the game to what they want.
{
	string change, eat_trash;
	int traversal = 0, index;
	int number;
	bool repeat = true;

	cout << "There are commands in this game." << endl;
	for (index = 0; index <= COMMAND_LENGTH - 2; index++)
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
		case 9:cout << index + 1 << ". " << "To " << "look---" << player1.command[index] << endl; break;
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
		case 26:cout << index + 1 << ". " << "To" << " get something---" << player1.command[index] << endl; break;
		case 27:cout << index + 1 << ". " << "To" << " hide extra information---" << player1.command[index] << endl; break;
		case 28:cout << index + 1 << ". " << "To" << " display extra information---" << player1.command[index] << endl; break;
		case 29:cout << index + 1 << ". " << "To" << " start something---" << player1.command[index] << endl; break;
		case 30:cout << index + 1 << ". " << "To" << " pick something---" << player1.command[index] << endl; break;
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
		player1.command[number-1] = change;
		cout << "done!" << endl;
	}
	else
	{
		player1.action = "setting fail";
		player1.set = 0;
	}
	return player1;
}
int save_game(player player1)//This function can save the progress of the game into a file.
{
	ofstream game_file;
	map<string, int>::iterator it;
	map<string, string>::iterator drop_stuff;
	int success = 1, index;
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
		game_file << "banana_amount:" << endl;
		game_file << player1.banana_amount << endl;
		game_file << "knife_amount:" << endl;
		game_file << player1.knife_amount << endl;
		game_file << "treasure_amount:" << endl;
		game_file << player1.treasure_amount << endl;
		game_file << "key_amount:" << endl;
		game_file << player1.key_amount << endl;
		game_file << "player_location:" << endl;
		game_file << player1.location << endl;
		game_file << "if_the_gorilla_ran:" << endl;
		game_file << player1.if_gorilla_run << endl;
		game_file << "player1_get:" << endl;
		game_file << player1.get << endl;
		game_file << "prison:" << endl;
		game_file << player1.prison << endl;
		game_file << "parrot" << endl;
		game_file << player1.parrot << endl;
		game_file << "hostile" << endl;
		game_file << player1.hostile << endl;
		game_file << "player_x_last_time:" << endl;
		game_file << player1.x_last_time << endl;
		game_file << "player_y_last_time:" << endl;
		game_file << player1.y_last_time << endl;
		game_file << "player_island_times:" << endl;
		game_file << player1.island_times << endl;
		game_file << "player_upper_deck_times:" << endl;
		game_file << player1.upper_deck_times << endl;
		game_file << "player1_lower_deck_times:" << endl;
		game_file << player1.lower_times << endl;
		game_file << "player_capitains_quarters_times:" << endl;
		game_file << player1.captain_quarters_times << endl;
		game_file << "player_cargo_hold_times:" << endl;
		game_file << player1.cargo_hold_times << endl;
		game_file << "player_brig_times:" << endl;
		game_file << player1.brig_times << endl;
		game_file << "player_galley_times:" << endl;
		game_file << player1.galley_times << endl;
		game_file << "hide: " << endl;
		game_file << player1.hide << endl;
		game_file << "setting:" << endl;
		for (index = 0; index <= COMMAND_LENGTH - 1; index++)
			game_file << player1.command[index] << endl;
		game_file << "drop_stuff:" << endl;
		for (drop_stuff = player1.drop_stuff.begin(); drop_stuff != player1.drop_stuff.end(); drop_stuff++)
		{
			game_file << drop_stuff->first << endl;
			game_file << drop_stuff->second << endl;
		}
		game_file.close();
	}
	return success;
}
player load_game(player player1)//This function can load the game from a file.
{
	ifstream game_file;
	map<string, int>::iterator it;
	string loaction, inventory, banana_amount, knife_amount, player_location, player_x_last_time, setting, hide, drop_stuff;
	string plaer_y_last_time, player_island_times, player_upper_deck_times, player_capitains_quarters_times, player_lower_deck_times;
	string player_cargo_hold_times, player_brig_times, player_galley_times, treasure_amount;
	string gorilla, parrot, hostile, key, prison, get;
	int index;
	game_file.open("Advanture Island.txt");
	if (!game_file.is_open())
	{
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
		game_file >> treasure_amount;
		game_file >> player1.treasure_amount;
		game_file >> key;
		game_file >> player1.key_amount;
		game_file >> player_location;
		game_file >> player1.location;
		game_file >> gorilla;
		game_file >> player1.if_gorilla_run;
		game_file >> get;
		game_file >> player1.get;
		game_file >> prison;
		game_file >> player1.prison;
		game_file >> parrot;
		game_file >> player1.parrot;
		game_file >> hostile;
		game_file >> player1.hostile;
		game_file >> player_x_last_time;
		game_file >> player1.x_last_time;
		game_file >> plaer_y_last_time;
		game_file >> player1.y_last_time;
		game_file >> player_island_times;
		game_file >> player1.island_times;
		game_file >> player_upper_deck_times;
		game_file >> player1.upper_deck_times;
		game_file >> player_lower_deck_times;
		game_file >> player1.lower_times;
		game_file >> player_capitains_quarters_times;
		game_file >> player1.captain_quarters_times;
		game_file >> player_cargo_hold_times;
		game_file >> player1.cargo_hold_times;
		game_file >> player_brig_times;
		game_file >> player1.brig_times;
		game_file >> player_galley_times;
		game_file >> player1.galley_times;
		game_file >> hide;
		game_file >> player1.hide;
		game_file >> setting;
		game_file.seekg(2, ios::cur);
		for (index = 0; index <= COMMAND_LENGTH - 1; index++)
		{
			getline(game_file, player1.command[index]);
		}
		game_file >> drop_stuff;
		game_file.seekg(2, ios::cur);
		while (!game_file.eof())
		{
			getline(game_file, drop_stuff);
			getline(game_file, player1.drop_stuff[drop_stuff]);
		}
		cout << "Load game successfully" << endl;
	}
	player1.load = 1;
	game_file.close();
	return player1;
}
void help()
{
	cout << "Sorry, there is nothing I can help you...." << endl;
}


string To_lower(string words)//This function can convert a string to lower case.
							 // and skip "the" at the beginning of the string.
{
	string::iterator it;
	int index = 0;
	for (it = words.begin(); it != words.end(); it++)
	{
		*it = tolower(*it);
		words.at(index++) = *it;
	}
	if (words.substr(0, 3) == "the")
		words = words.substr(4);
	return words;
}
int location(player player1, scene place)//This function can determind if the player is getting closer or away
										  // to a room in the game.
{
	int close = 0;
	if (place.name == "island" and player1.load == 0)
	{
		if (player1.x == place.stuff_can_cut_x and player1.y == place.stuff_can_cut_y)
			cout << "You currently at ripe banana tree." << endl;
		else if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
			cout << "You currently at gangplank." << endl;
		else
			cout << "You currently at island." << endl;

	}
	else if (place.name == "upper deck" and player1.load == 0)
	{
		if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y )
			cout << "You are currently at captain`s quaters." << endl;
		else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
			cout << "You are currently at ladder." << endl;
		else if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
			cout << "You are currently at ship`s wheel." << endl;
		else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
			cout << "You are currently at gangplank." << endl;
		else
			cout << "You are currently at upper deck." << endl;


	}
	else if (place.name == "lower deck" and player1.load == 0)
	{
		if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
			cout << "You currently at cargo hold." << endl;
		else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
			cout << "You are currently at ladder." << endl;
		else if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
			cout << "You are currently at galley" << endl;
		else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
			cout << "You are currently at brig." << endl;
		else
			cout << "You are currently ar lower deck." << endl;

		if (player1.x == place.entrance_4_x  and player1.y == place.entrance_4_y)
			cout << "You are currently at the brig" << endl;
	}
	return 0;
}
player island(player player1, scene place)//This function can set up the map "island" in the game.
{
	player1 = pick_it_up(player1, place);
	if (player1.x == place.stuff_can_cut_x and player1.y == place.stuff_can_cut_y)
	{
		player1.room = "banana tree";
		if (player1.banana_amount != 0)
		{
			cout << place.stuff_can_cut_description << endl;
		}
		else if (player1.banana_amount == 0)
		{
			cout << place.stuff_can_cut_description_2 << endl;
		}
		player1 = take_action(player1, place);
		if (player1.action == "get" or player1.action == "cut")
		{
			if (player1.banana_amount != 0)
			{
				if (player1.inventory["knife"] != 0)
				{
					player1.banana_amount -= 1;
					player1.inventory["banana"] += 1;
					place.stuff_can_get.erase("banana");
					cout << place.stuff_1_get_info << endl;
				}
				else if (player1.action == "get")
					cout << "You need a knife to get the banana!" << endl;
			}
			else if (player1.banana_amount == 0)
			{
				cout << "You already got the banana!" << endl;
			}
		}
	}
	else if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
	{
		player1.room = "gangplank";
		cout << place.entrance_1_description << endl;
		player1 = take_action(player1, place);
		if (player1.action == "enter")
		{
			player1.location = "up";
			player1.x= 2;
			player1.y = -10;
		}
	}
	else
	{
		player1.room = "island";
		player1 = add_times(player1);
		if (player1.island_times == 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.long_description << endl;
		}
		else if (player1.island_times > 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.short_description << endl;
		}
		player1 = take_action(player1, place);
		player1 = re_take_action(player1, place);
	}
	extra_info(player1, place);
	return player1;
}
player upper_deck(player player1, scene place, bool &success)//This function can set up the map "upper deck" in the game.
{
	vector<string> give;
	player1 = pick_it_up(player1, place);
	if (player1.x == place.entrance_1_x and player1.x == place.entrance_1_y)
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
				place.stuff_can_get.erase("knife");
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
	
		if (player1.get == 0)
		{
			cout << "You are standing in front of a bed." << endl;
			player1 = take_action(player1, place);
		}
		else
		{
			cout << "You are standing in front of a bed, the key is under the bed!" << endl;
			player1 = take_action(player1, place);
			cout << player1.action << endl;
			if (player1.action == "get" and player1.object == "key")
			{
				cout << "You got the key!" << endl;
				player1.inventory["key"]++;
				player1.get = 0;
				place.stuff_can_get.erase("key");
			}
		}
		player1.room = "captain`s quarters";
		player1 = add_times(player1);
		if (player1.captain_quarters_times == 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.entrance_1_description << endl;
		}
		else if (player1.captain_quarters_times > 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			if (player1.knife_amount == 1)
				cout << place.entrance_1_short_description << endl;
			else
				cout << place.entrance_1_short_description_after_got << endl;
		}
		player1 = take_action(player1, place);
		player1 = re_take_action(player1, place);
	
	}

	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		player1.room = "ladder";
		cout << place.entrance_2_description << endl;
		player1 = take_action(player1, place);
		if (player1.action == "down")
		{
			player1.location = "down";
			player1.x = 2;
			player1.y = -10;
		}
	}
	else if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
	{
		player1.room = "ship`s wheel";
		if (player1.if_gorilla_run == 0)
		{
			cout << place.entrance_4_description;
			player1 = take_action(player1, place);
			if (player1.action == "give" and player1.object == "banana" or player1.object == "banana to gorilla")
			{
				player1.inventory["banana"] -= 1;
				place.stuff_can_give.erase("banana");
				player1.if_gorilla_run = 1;
				cout << "The gorilla rush to the forest and disapear!" << endl;
			}
			while (player1.action == "move" and player1.object == "north")
			{
				cout << "The gorilla is there, you can`t approach!" << endl;
				player1 = take_action(player1, place);
			}
		}
		else
		{
			cout << place.entrance_4_short_description << endl;
			player1 = take_action(player1, place);
			if (player1.action == "start" and player1.object == "ship")
			{
				if (player1.prison != 0)
				{
					success = true;
					cout << "You finally success to sail away!" << endl;
				}
				else
					cout << "You need that guy in the brig to help you start this ship!" << endl;
			}
		}
	}
	else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
	{
		player1.room = "gangplank";

		if (player1.hostile == 0)
		{
			cout << "There are hostile natives that appear outside the ship after the player boards\nThey will not allow anyone off the ship until you give the treasure to them." << endl;
			player1 = take_action(player1, place);
			player1 = re_take_action(player1, place);
			if (player1.action == "give")
			{
				place.stuff_can_give.erase("treasure");
				player1.inventory["treasure"]--;
				player1.hostile = 1;
				cout << "The hostile native finally leave." << endl;
			}
		}
		else
		{
			cout << place.entrance_3_description << endl;
			player1 = take_action(player1, place);
			player1 = re_take_action(player1, place);
			if (player1.action == "get out")
			{
				cout << "You have got out of the ship!" << endl;
				player1.location = "island";
				player1.y += 5;
			}
		}
	}
	else
	{
		player1.room = "upper deck";
		player1 = add_times(player1);
		if (player1.upper_deck_times == 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.long_description << endl;
		}
		else if (player1.upper_deck_times > 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.short_description << endl;
		}
		player1 = take_action(player1, place);
		player1 = re_take_action(player1, place);
	}
	extra_info(player1, place);
	return player1;
}
player lower_deck(player player1, scene place)//This function can set up the map "lower deck" in the game.
{
	player1 = pick_it_up(player1, place);
	if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
	{

			if (player1.get == 0)
			{
				cout << "You see a bunch of trunk." << endl;
				player1 = take_action(player1, place);
				player1 = re_take_action(player1, place);
			}
			else
			{
				cout << "You see a bunch of trunk and the treasure is hiding inside." << endl;
				player1 = take_action(player1, place);
				player1 = re_take_action(player1, place);
				if (player1.action == "get" and player1.get == 1)
				{
					cout << "You got the treasure!" << endl;
					player1.get = 0;
					player1.inventory["treasure"]++;
					player1.treasure_amount--;
					place.stuff_can_get.erase("treaure");
				}
			}
			player1.room = "cargo hold";
			player1 = add_times(player1);
			if (player1.in_n_out == 0 and player1.cargo_hold_times == 1)
			{
				cout << place.entrance_1_description << endl;
				player1.in_n_out = 1;
			}
			else if (player1.in_n_out == 0 and player1.cargo_hold_times != 1)
			{
				cout << place.entrance_1_short_description << endl;
				player1.in_n_out = 1;
			}
			player1 = take_action(player1, place);
			player1 = re_take_action(player1, place);
	}

	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		player1.room = "ladder";
		cout << place.entrance_2_description << endl;
		player1 = take_action(player1, place);
		if (player1.action == "up")
		{
			player1.location = "up";
			player1.lower_times++;
			player1.in_n_out = 0;
		}
	}

	else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
	{
		cout << "You are stand on the top of a brig, you wanna go down and see?" << endl;
		player1 = take_action(player1, place);
		if (player1.action == "down")
		{
			player1.room = "brig";
			player1 = add_times(player1);
			if (player1.brig_times == 1 and player1.in_n_out == 0)
			{
				cout << place.entrance_3_description << endl;
				player1.in_n_out = 1;
			}
			else if (player1.brig_times != 1 and player1.in_n_out == 0)
			{
				if (player1.prison == 0)
					cout << place.entrance_3_short_description << endl;
				else if (player1.prison == 0)
					cout << place.entrance_3_short_description << endl;
				else
					cout << place.entrance_3_short_description_after << endl;
				player1.in_n_out = 1;
			}
			player1 = take_action(player1, place);
			if (player1.action == "unlock" and player1.prison == 0)
			{
				cout << "You finally free that poor guy. Hell yeah!" << endl;
				player1.inventory["key"]--;
				player1.prison = 1;
				player1.in_n_out = 1;
			}
		}
	}
	else if (player1.x == place.entrance_4_x and player1.x == place.entrance_4_y)
	{
		string words;
		int get_out = player1.parrot;
			cout << "The parrot is watching you." << endl;
			while (get_out == 0)
			{
				cout << "What are you gonna do?" << endl;
				getline(cin, words);
				words = sentence_to_pig_latin(words);
				if (words == "hello")
				{
					player1.parrot = 1;
					get_out = 1;
					cout << "The parrot says: \"The key is in the captain`s quarters!\"" << endl;
				}
				else
					cout << "The parrot repeat your words:\"" << words << "\"" << endl;
			}
			if (get_out == 1)
			{
				player1 = take_action(player1, place);
				player1 = re_take_action(player1, place);
			}
			player1.room = "galley";
			player1 = add_times(player1);
			if (player1.galley_times == 1 and player1.in_n_out == 0)
			{
				cout << place.entrance_4_description << endl;
				player1.in_n_out = 1;
			}
			else if (player1.galley_times > 1 and player1.in_n_out == 0)
			{
				cout << place.entrance_4_short_description << endl;
				player1.in_n_out = 1;
			}
			player1 = take_action(player1, place);
			player1 = re_take_action(player1, place);
	}
	else
	{
		player1.room = "lower deck";
		player1 = add_times(player1);
		if (player1.lower_times == 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.long_description << endl;
		}
		else if (player1.lower_times > 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.short_description << endl;
		}
		player1 = take_action(player1, place);
		player1 = re_take_action(player1, place);
	}
	extra_info(player1, place);
	return player1;
}
void action_seprate(string &actions, string &objects, string action)//This function can separate the command in two parts.
																	// one is the action and one is object.
{
	int pos;
	bool has_object;
	has_object = if_has_object(action);
	if (has_object)
	{
		pos = action.find(" ");
		actions = action.substr(0, pos);
		pos++;
		if (actions == "go")
		{
			if (action.substr(pos, 2) == "to")
				pos += 3;
		}
		else if (action.substr(pos, 3) == "the")
			pos += 4;
		objects = action.substr(pos);
	}
	else
	{
		actions = action;
		objects = "none";
	}
}
bool if_has_object(string action)//This function can determind if the command has object.
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
player so_bad_so_sad(player player1)//This function can prompt the player when they input the bad command.
{
	cout << "So bad so sad, you can`t " << player1.action << " " << player1.object << " right now!" << endl;
	player1.action = "none";
	return player1;
}
bool if_can_get(player player1, scene place, string stuff)//This function can determind if the player can get
														  // something in the game.
{
	bool get = false;
	map<string, string>::iterator it;
	string coordinate;
	coordinate = coordinate_to_string(player1);
	if (stuff == "nothing")
	{
		for (it = place.stuff_can_get.begin(); it != place.stuff_can_get.end(); it++)
		{
			if (it->first == player1.object and it->second == coordinate)
				get = true;
		}
	}
	else if (stuff != "nothing")
	{
		for (it = place.stuff_can_get.begin(); it != place.stuff_can_get.end(); it++)
		{
			if (it->first == stuff and it->second == coordinate)
				get = true;
		}
	}
	else
		cout << "Sorry, you can`t get " << player1.object << " right here" << endl;
	return get;
}
bool if_can_cut(player player1, scene place, string stuff)//This function can determind if the player can cut
														  // something in the game.
{
	bool cut = false;
	map<string, string>::iterator it;
	string coordinate;
	coordinate = coordinate_to_string(player1);
	if (stuff == "nothing")
	{
		for (it = place.stuff_can_cut.begin(); it != place.stuff_can_cut.end(); it++)
		{
			if (player1.object == it->first and it->second == coordinate)
				cut = true;
		}
	}
	else
	{
		for (it = place.stuff_can_cut.begin(); it != place.stuff_can_cut.end(); it++)
		{
			if (stuff == it->first and it->second == coordinate)
				cut = true;
		}
	}
	return cut;
}
bool if_can_give(player player1, scene place, string stuff)//This function can determind if the player can give
														  // something in the game.
{
	bool give = false, equal = false;
	map<string, string>::iterator it;
	string coordinate;
	coordinate = coordinate_to_string(player1);
	if (stuff == "nothing")
	{
		for (it = place.stuff_can_give.begin(); it != place.stuff_can_give.end(); it++)
		{
			if (player1.object == it->first)
			{
				equal = true;
				if (player1.inventory[player1.object] != 0 and it->second == coordinate)
					give = true;
				else if (player1.inventory[player1.object] != 0 and it->second != coordinate)
					cout << "You can`t do that right here!" << endl;
				else
					cout << "You don`t have " << player1.object << " to give!" << endl;
			}
		}
		if (!equal)
			cout << "You don`t have " << player1.object << " to give!" << endl;
	}
	else
	{
		for (it = place.stuff_can_give.begin(); it != place.stuff_can_give.end(); it++)
		{
			if (stuff == it->first)
			{
				equal = true;
				if (player1.inventory[stuff] != 0 and coordinate == it->second)
					give = true;
				else if (player1.inventory[stuff] != 0 and coordinate != it->second)
					cout << "You can`t do that right here!" << endl;
				else
					cout << "You don`t have " << stuff << " to give!" << endl;
			}
		}
		if (equal == false)
			cout << "You don`t have " << stuff << " to give!" << endl;
	}

	return give;
}
bool if_can_eat(player player1, scene place, string food)//This function can determind if the player can eat
														  // something in the game.
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
bool if_can_pick(player player1, string stuff)//This function can determind if the player can pick
														  // something in the game.
{
	map<string, string>::iterator it;
	bool pick = false;
	string name, coordinate;
	coordinate = coordinate_to_string(player1);
	if (stuff == "nothing")
	{
		for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
		{
			if (player1.object == "it" or player1.object == "it up")
			{
				if (coordinate == it->second)
					pick = true;
			}
			else
			{
				name = recover_name(it->first);
				if (name == player1.object and coordinate == it->second)
				{
					pick = true;
				}
			}
		}
		if (!pick)
			cout << player1.object << " is not here!" << endl;
	}
	else
	{
		for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
		{
			if (stuff == "it")
			{
				if (coordinate == it->second)
					pick = true;
			}
			else
			{
				name = recover_name(it->first);
				if (name == stuff and coordinate == it->second)
					pick = true;
			}
		}
		if (!pick)
			cout << stuff << " is not here!" << endl;
	}
	return pick;
}
player re_take_action(player player1, scene place)//This function can retake the command again
												  // when the player over boundaries of the map incidently.
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
bool if_can_drop(player player1, string stuff)//This function can determind if the player can drop
														  // something in the game.
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
string coordinate_to_string(player player1)//This function can convert the coordinate of the player to a string.
{
	string coordinate, up_or_down;
	if (player1.location == "island")
		up_or_down = "2";
	else if (player1.location == "up")
		up_or_down = "1";
	else if (player1.location == "down")
		up_or_down = "0";
	coordinate = to_string(player1.x);
	coordinate.append(" ");
	coordinate.append(to_string(player1.y));
	coordinate.append(" ");
	coordinate.append(up_or_down);
	return coordinate;
}
player pick_it_up(player player1, scene place)//This function can let player pick up the stuff he dropped.
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
			if (player1.action == "pick")
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
string re_name(player player1, string stuff)//This function can rename the stuff that the player dropped
										   // in ordered by when the player dropped it.Such as banana 1, banana 2
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
string recover_name(string name)//This function can recover the name of the stuff
								//that the player dropped.
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
player drop_it(player player1)//This function can let player drop stuff in the game.
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
int get_number(string name)//This function can get the number in the name of the stuff that player dropped
						   //like the 1 in banana 1.
{
	int pos, number;
	pos = name.find(" ");
	name = name.substr(pos + 1);
	number = stoi(name);
	return number;
}
string sentence_to_pig_latin(string sentence)//This function can convert the words in a sentence to pig-latin.
{
	string new_sentence;
	vector<string>marks;
	vector<string>word;
	vector<string>::iterator it;
	bool bingo = false;
	int marks_index = 0, word_index = 0;
	if (has_mark(sentence))
	{
		get_sentence(sentence, marks, word);
		for (it = word.begin(); it != word.end(); it++)
		{
			new_sentence = To_lower_2(*it);
			if (new_sentence == "hello" or new_sentence == "polly" or new_sentence == "cracker")
			{
				new_sentence = "hello";
				bingo = true;
			}
		}
		if (!bingo)
		{
			if (marks.size() > word.size())
			{
				while (marks_index <= marks.size() - 1)
				{
					new_sentence.append(marks[marks_index]);
					marks_index++;
					if (word_index <= word.size() - 1)
					{
						word[word_index] = pig_latin(word[word_index]);
						new_sentence.append(word[word_index]);
						word_index++;
					}
				}
			}
			else
			{
				while (word_index <= word.size() - 1)
				{
					word[word_index] = pig_latin(word[word_index]);
					new_sentence.append(word[word_index]);
					word_index++;
					if (marks_index <= marks.size() - 1)
					{
						new_sentence.append(marks[marks_index]);
						marks_index++;
					}
				}
			}
		}
	}
	else
	{
		new_sentence = To_lower_2(sentence);
		if (new_sentence == "hello" or new_sentence == "polly" or new_sentence == "cracker")
			new_sentence = "hello";
		else
			new_sentence = pig_latin(sentence);
	}
	return new_sentence;
}
string pig_latin(string word)//This function can convert a single word to pig-latin.
{
	string first_letter;
	first_letter = word.at(0);
	first_letter.append("ay");
	word = word.substr(1);
	word.append(first_letter);
	return word;
}
void get_sentence(string sentence, vector<string>&marks, vector<string>&word)//This cuntion can separate a sentence into marks and words.
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
player add_times(player player1)//This function can count how many times that player has been to the map.
{
	if (player1.room == "island" and player1.island_times == 0)
	{
		player1.island_times++;
		player1.in_n_out = 0;
		player1.last_room = "island";
	}
	else if (player1.room == "upper deck" and player1.upper_deck_times == 0)
	{
		player1.upper_deck_times++;
		player1.in_n_out = 0;
		player1.last_room = "upper deck";
	}
	else if (player1.room == "lower deck" and player1.lower_times == 0)
	{
		player1.lower_times++;
		player1.in_n_out = 0;
		player1.last_room = "lower deck";
	}
	else if (player1.room == "captain`s quarters" and player1.captain_quarters_times == 0)
	{
		player1.captain_quarters_times++;
		player1.in_n_out = 0;
		player1.last_room = "captain`s quarters";
	}
	else if (player1.room == "cargo hold" and player1.cargo_hold_times == 0)
	{
		player1.cargo_hold_times++;
		player1.in_n_out = 0;
		player1.last_room = "cargo hold";
	}
	else if (player1.room == "brig" and player1.brig_times == 0)
	{
		player1.brig_times++;
		player1.in_n_out = 0;
		player1.last_room = "brig";
	}
	else if (player1.room == "galley" and player1.galley_times == 0)
	{
		player1.galley_times++;
		player1.in_n_out = 0;
		player1.last_room = "galley";
	}
	else
	{
		if (player1.room != player1.last_room)
		{
			if (player1.room == "island")
			{
				player1.island_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "upper deck")
			{
				player1.upper_deck_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "lower deck")
			{
				player1.lower_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "captain`s quarters")
			{
				player1.captain_quarters_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "cargo hold")
			{
				player1.cargo_hold_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "brig")
			{
				player1.brig_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "galley")
			{
				player1.galley_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
		}
	}
	return player1;
}
player look_hint_and_search(player player1, scene place)//This function can prompt the player when the player
														// enter "look","hint", and "search".
{
	if (place.name == "island")
	{
		if (player1.room == "banana tree")
		{
			if (player1.banana_amount != 0)
			{
				if (player1.action == "look")
					cout << place.stuff_can_cut_look_description_1 << endl;
				else if (player1.action == "hint")
				{
					if (player1.inventory["knife"] == 0)
						cout << "Need knife to cut? Don`t forget there is a ship to your east." << endl;
					else
						cout << "Cut cut cut!!!!" << endl;
				}
			}
			else
			{
				if (player1.action == "look")
					cout << place.stuff_can_cut_look_description_2 << endl;
				else if (player1.action == "hint")
					cout << "You already got the banana!" << endl;
			}
		}
		else if (player1.room == "gangplank")
		{
			if (player1.action == "look")
				cout << place.entrance_1_description << endl;
			else if (player1.action == "hint")
				cout << "To go in or not go in, that is a question." << endl;
		}
		else
		{
			if (player1.action == "look")
					cout << place.long_description << endl;
			else if (player1.action == "hint")
			{
				if (player1.banana_amount == 1)
					cout << "Go get the banana!" << endl;
				else
					cout << "There is nothing I can prompt you." << endl;
			}
			else if (player1.action == "search")
				cout << "No new discoveries" << endl;
		}

	}
	else if (place.name == "upper deck")
	{
		if (player1.room == "captain`s quarters")
		{
			if (player1.parrot == 0)
			{
				if (player1.action == "look")
					cout << place.entrance_1_description << endl;
				else if (player1.action == "hint")
					cout << "The captain used to live here, he might left something in this room." << endl;
				else if (player1.action == "search")
				{
					if (player1.knife_amount != 0)
						cout << "You found nothing except the knife." << endl;
					else
						cout << "There is nothing on the table." << endl;
				}
			}
			else
			{
				if (player1.action == "look")
					cout << "The bed looks dirty and hard, you can barely fall in sleep on it." << endl;
				else if (player1.action == "hint")
					cout << "Would you like take a try with lying on this bed?" << endl;
				else if (player1.action == "search")
				{
					if (player1.parrot == 0)
						cout << "You found nothing and got dust on your clothes...." << endl;
					else
					{
						if (player1.get == 0)
						{
							cout << "You found the key under the bed!" << endl;
							player1.get = 1;
						}
						else
							cout << "You found nothing and got dust on your clothes...." << endl;
					}

				}
			}
		}
		else if (player1.room == "ladder")
		{
			if (player1.action == "look")
				cout << "This is a ladder" << endl;
			else if (player1.action == "hint")
				cout << "To go down or not go down, that is a question." << endl;
			else if (player1.action == "search")
				cout << "You found nothing with this ladder" << endl;
		}
		else if (player1.room == "ship`s wheel")
		{
			if (player1.if_gorilla_run == 0)
			{
				if (player1.action == "look")
					cout << "You take a sneak look at the gorilla. It's so big and frightening that you hide quickly." << endl;
				else if (player1.action == "hint")
					cout << "Think about what gorilla likes to eat?" << endl;
				else if (player1.action == "search")
					cout << "You can`t do any search when the gorilla is there!" << endl;
			}
			else
			{
				if (player1.action == "look")
					cout << place.entrance_4_description_2 << endl;
				else if (player1.action == "hint")
					cout << "You need a sailor to help you start this ship." << endl;
				else if (player1.action == "search")
					cout << "No new discoveries." << endl;
			}
		}
		else
		{
			if (player1.action == "look")
				cout << place.long_description << endl;
			else if (player1.action == "hint")
			{
				if (player1.if_gorilla_run == 1)
					cout << "Kick the gorilla out of this ship!" << endl;
				else
					cout << "There is nothing I can prompt you." << endl;
			}
			else if (player1.action == "search")
				cout << "No new discoveries" << endl;
		}
	}
	else if (place.name == "lower deck")
	{
		if (player1.room == "cargo hold")
		{
				if (player1.treasure_amount == 1)
				{
					if (player1.action == "look")
						cout << "It doesn't seem like an ordinary trunk." << endl;
					else if (player1.action == "hint")
						cout << "Maybe there is something inside?" << endl;
					else if (player1.action == "search")
					{
						if (player1.get == 0)
						{
							cout << "You found the treasure in the trunk!!!" << endl;
							player1.get = 1;
						}
						else
							cout << "No new discoveries." << endl;
					}
				}
				else
				{
					if (player1.action == "look")
						cout << "This looks like an ordinary trunk" << endl;
					else if (player1.action == "hint")
					{
						if (player1.hostile == 0)
							cout << "Now, these hostile should be happy to leave." << endl;
						else
							cout << "There is nothing I can prompt you." << endl;
					}
					else if (player1.action == "search")
						cout << "No new discoveries." << endl;
				}
			}
		}
		else if (player1.room == "brig")
		{
			if (player1.prison == 0)
			{
				if (player1.action == "look")
					cout << place.entrance_3_description << endl;
				else if (player1.action == "hint")
					cout << "The other one who can speak on this ship may know where the key is." << endl;
				else if (player1.action == "search")
					cout << "No new discoveries." << endl;
			}
			else
			{
				if (player1.action == "look")
					cout << "You can see from the broken cage and its surroundings how much the poor man who had been inside suffered." << endl;
				else if (player1.action == "hint")
					cout << "There is nothing I can prompt you." << endl;
				else if (player1.action == "search")
					cout << "No new discoveries." << endl;
			}
		}
		else if (player1.room == "ladder")
		{
			if (player1.action == "look")
				cout << place.entrance_2_description << endl;
			else if (player1.action == "hint")
				cout << "To go up or not go up, that is a question." << endl;
			else if (player1.action == "search")
				cout << "No new discoveries." << endl;
		}
		else if (player1.room == "galley")
		{
			if (player1.parrot == 0)
			{
				if (player1.action == "look")
					cout << place.entrance_4_description << endl;
				else if (player1.action == "hint")
					cout << "1.Try to be polite to the parrot.\n2.Think about what parrot likes to eat.\n3.It`s name is Polly" << endl;
				else if (player1.action == "search")
					cout << "No new discoveries." << endl;
			}
			else
			{
				if (player1.action == "look")
					cout << "The parrot looks like it wants to play the Pig-Latin game with you. You're so scared that want to go away." << endl;
				else if (player1.action == "hint")
					cout << "There is nothing I can prompt you." << endl;
				else if (player1.action == "search")
					cout << "No new discoveries." << endl;
			}
		}
		else
		{
			if (player1.action == "look")
				cout << place.long_description << endl;
			else if (player1.action == "hint")
			{
				if (player1.parrot == 0 and player1.treasure_amount == 1)
					cout << "Go find the key and free that man and the treasure!" << endl;
				else if (player1.parrot == 0)
					cout << "Go find the key and free that man!" << endl;
				else if (player1.treasure_amount == 1)
					cout << "Go find the treasure!" << endl;
			}
			else if (player1.action == "search")
				cout << "No new discoveries." << endl;
		}
		return player1;
	}
scene init_scene(scene place)//This function can initialize the coordinate of special stuff that 
							 // the player can do something with like drop or cut.
{
	place.stuff_can_get["treasure"] = "1 -9 0";
	place.stuff_can_give["banana"] = "5 -11 1";
	place.stuff_can_give["treasure"] = "2 -9 1";
	place.stuff_can_get["knife"] = "-3 -12 1";
	place.stuff_can_cut["banana"] = "3 2 2";
	place.stuff_can_get["banana"] = "3 2 2";
	place.stuff_can_get["key"] = "-5 -10 1";
	place.stuff_can_eat.push_back("banana");
	return place;
}
void extra_info(player player1, scene place)//This function can prompt the player the location he is currently at.

{
	if (player1.hide == 0 and player1.action == "move" or player1.action == "display" or player1.action == "save")
	{


		cout << "***********************************************************************************************" << endl;
		cout << "Extra information: " << endl;
		location(player1, place);
		cout << "(You can enter hide to hide the extra information and enter display to see the extra information again)" << endl;
		cout << "***********************************************************************************************" << endl;
	}
}
bool has_mark(string sentence)//This function can determind if a sentence has marks.
{
	int index, pos = 0;
	bool real = true;
	for (index = 0; index <= sentence.length() - 1; index++)
	{
		if ((sentence.at(index) >= 'a' and sentence.at(index) <= 'z') or (sentence.at(index) >= 'A' and sentence.at(index) <= 'Z'))
			pos++;
	}
	if (pos == index)
		real = false;
	return real;
}
string To_lower_2(string words)//This function can convert the words in sentence to lower case,
							// it doesn`t skip "the" at the beginning of the word.
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
void help(player player1)//This function can print helping information for the player.
{
	int index;
	cout << "The commands in this game is made up by one or two words, normally a verb fllowed by a noun." << endl;
	cout << "You can change the keys for command by enter \"setting\"." << endl;
	cout << "Here are the keys for command:" << endl;
	for (index = 0; index <= COMMAND_LENGTH - 2; index++)
	{

		switch (index)
		{
		default:
		case 0:cout << index + 1 << ". " << "To go " << "north---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 1:cout << index + 1 << ". " << "To go " << "south---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 2:cout << index + 1 << ". " << "To go " << "west---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 3:cout << index + 1 << ". " << "To go " << "east---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 4:cout << index + 1 << ". " << "To " << "board---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 5:cout << index + 1 << ". " << "To " << "enter---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 6:cout << index + 1 << ". " << "To " << "take---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 7:cout << index + 1 << ". " << "To " << "give---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 8:cout << index + 1 << ". " << "To " << "search---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 9:cout << index + 1 << ". " << "To " << "look---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 10:cout << index + 1 << ". " << "To " << "eat---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 11:cout << index + 1 << ". " << "To " << "cut---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 12:cout << index + 1 << ". " << "To " << "climb---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 13:cout << index + 1 << ". " << "To " << "drop---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 14:cout << index + 1 << ". " << "Go " << "up---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 15:cout << index + 1 << ". " << "Go " << "down---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 16:cout << index + 1 << ". " << "To " << "unlock---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 17:cout << index + 1 << ". " << "To " << "sail---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 18:cout << index + 1 << ". " << "To " << "open---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 19:cout << index + 1 << ". " << "To " << "quit---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 20:cout << index + 1 << ". " << "Check " << "inventory---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 21:cout << index + 1 << ". " << "To " << "setting---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 22:cout << index + 1 << ". " << "To " << "save---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 23:cout << index + 1 << ". " << "To " << "load--" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 24:cout << index + 1 << ". " << "To see " << "hint---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 25:cout << index + 1 << ". " << "To see " << "help---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 26:cout << index + 1 << ". " << "To" << " get something---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 27:cout << index + 1 << ". " << "To" << " hide extra information---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 28:cout << index + 1 << ". " << "To" << " display extra information---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 29:cout << index + 1 << ". " << "To" << " start something---" << "enter \"" << player1.command[index] << "\"" << endl; break;
		case 30:cout << index + 1 << ". " << "To" << " pick something---" << "enter \"" << player1.command[index] << "\"" << endl; break;
			break;
		}
	}
}
void welcome()//This function can print welcome words to the player.
{
	cout << "You wake up on an island with no memory of how you got there.You need to overcome a"
		<< "series of obstacles in order to be able to to board a pirate ship and sail it to civilization." << endl;
}