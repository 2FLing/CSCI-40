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
#include<ctime>
using namespace std;
const int COMMAND_LENGTH = 39;
class monster
{
public:
	int x = 0;
	int y = 0;
	double health = 50;
	double attack = 5;
};
class equipment
{
public:
	string name = "none";
	int attack = 0;
	int defence = 0;
};
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
	string entrance_1_description_3;
	string entrance_1_short_description;
	string entrance_1_short_description_2;
	string entrance_1_short_description_3;
	string entrance_1_description_after_got;
	string entrance_1_description_after_got_2;
	string entrance_1_short_description_after_got;
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
	string shop_long_description;
	string shop_short_description;
	string stuff_1_get_info;
	map<string, string>stuff_can_cut;
	map<string, string>stuff_can_give;
	map<string, string>stuff_can_get;
	vector<string>stuff_can_eat;
	map<string, int>items;
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
	int bed_x;
	int shop_x;
	int shop_y;
	int question_x;
	int question_y;
	map<string, equipment>equips;
};
class player
{
public:
	map<string, int> inventory;
	map<string, string>drop_stuff;
	map<string, string>equipments;
	string time = "8:00";
	string action;
	string object;
	string command[COMMAND_LENGTH] = { "north","south","west","east","board","enter","take","give","search",
		"look","eat","cut","climb","drop","up","down","unlock","sail","open","quit","inventory",
		"setting","save","load" ,"hint","help","get","hide","display","pick","lie","attack","run away",
		"equip","state","light","unequip","sell","null" };
	string oringin_command[COMMAND_LENGTH] = { "north","south","west","east","board","enter","take","give","search",
		"look","eat","cut","climb","drop","up","down","unlock","sail","open","quit","inventory",
		"setting","save","load" ,"hint","help","get","hide","display","pick","lie","attack","run away",
		"equip","state","light","unequip","sell","null" };
	string location = "island";
	string room = "none";
	string last_room = "none";
	string weapon = "punch";
	double health = 100;
	double attack = 5;
	double defence = 0;
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
	int gangplank_times = 0;
	int shop_times;
	int question_times;
	int hide = 0;
	int upper_deck_times = 0;
	int if_gorilla_run = 0;
	int parrot = 0;
	int hostile = 0;
	int prison = 0;
	int get = 0;
	int up_or_down = 1;
	bool if_over = false;
	bool time_begin = true;
	bool fighting = false;
	bool with_light = false;
	int cur_time = 0;
	int start_time = 0;
	int time_spent = 0;
	int day = 0;
	double gold = 0;
	int timer = 0;
	int num_item1;
	int num_item2;
	int num_item3;
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
player init_player(player);
void help(player);
void welcome();
void extra_info(player, scene);
void boundary(player, scene);
void item_description(string);
player setting(player);
string To_lower(string);
string To_lower_2(string);
string coordinate_to_string(player);
bool if_has_object(string);
bool if_can_get(player, scene);
bool if_can_cut(player, scene);
bool if_can_give(player, scene);
bool if_can_eat(player, scene);
bool if_can_drop(player);
bool if_can_pick(player);
int if_has(player, scene, string);
int location(player, scene);
player so_bad_so_sad(player);
player pick_it_up(player, scene);
string re_name(player, string);
string recover_name(string);
string pig_latin(string);
string sentence_to_pig_latin(string);
void get_sentence(string, vector<string>&, vector<string>&);
player drop_it(player);
int get_number(string);
bool has_mark(string);
player game_time(player);
player fight(player, scene);
string ask_for_objects(string, string);
int main()
{
	bool success = false;
	player player1;
	scene place;
	string word;
	player1 = init_player(player1);
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
		extra_info(player1, place);
	}
	cout << "Good job!!!" << endl;
	cout << "Game Over" << endl;
	return 0;
}
player take_action(player player1, scene place)
//This function can transfer the command from player to the action of the character in the game.
{
	bool save = false;
	bool load = false;
	time_t now;
	string action;
	string actions, eat_enter;
	string objects;
	string drop_coordinate;
	int index;
	player1.if_over = false;
	player1.action = "none";
	player1.object = "none";
	if (player1.with_light == true and player1.timer >= 20)
	{
		cout << "---------------------" << endl;
		cout << "The torch went out." << endl;
		cout << "---------------------" << endl;
		player1.with_light = false;
		player1.inventory["stem"]--;
		player1.timer = 0;
	}
	if (player1.room == "shop")
	{
		cout << "-----------------------------------------------------------------" << endl;
		cout << "Which are you gonna buy?(enter the number in front of the item)" << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
	else
	{
		cout << "------------------------" << endl;
		cout << "What are you gonna do?" << endl;
		cout << "------------------------" << endl;
	}
	action = getchar();
	while (action == "\n")
	{
		cout << "------------" << endl;
		cout << "Enter fail" << endl;
		cout << "------------------------" << endl;
		cout << "What are you gonna do?" << endl;
		cout << "------------------------" << endl;
		action = getchar();
	}
	eat_enter = action;
	getline(cin, action);
	action = eat_enter + action;
	action = To_lower(action);
	player1 = game_time(player1);
	action_seprate(actions, objects, action);
	for (index = 0; index <= COMMAND_LENGTH - 2; index++)
		if (actions == player1.command[index])
		{
			actions = player1.oringin_command[index];
		}
	if (player1.fighting == true)
	{
		if (actions == "attack")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none" or objects == "ghost" and player1.fighting == true)
				player1.action = "attack";
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "run")
		{
			player1.object = objects;
			player1.action = actions;
			if ((objects == "away" or objects == "none") and player1.fighting == true)
				player1.action = "run away";
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "quit")
		{
			player1.action = "quit";
			player1.object = objects;
			if (objects == "none" or objects == "game")
				exit(0);
			else
				player1 = so_bad_so_sad(player1);
		}
		else
		{
			cout << "-------------------------------------------------------------------" << endl;
			cout << "You have to defeat the ghost first,then you can do what you want." << endl;
			cout << "-------------------------------------------------------------------" << endl;
			player1.action = "none";
		}
	}
	else {
		if (action == "leave")
			action = "get out";
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
					cout << "-----------------------" << endl;
					cout << "Fail to setting keys!" << endl;
					cout << "-----------------------" << endl;
				}
			}
			else
			{
				player1.object = objects;
				player1 = so_bad_so_sad(player1);
			}
		}
		else if (actions == "go" or action == "n" or action == "s" or action == "w" or action == "e" or actions == "north"
			or actions == "south" or actions == "west" or actions == "east")
		{
			if (player1.fighting == false) {
				if (player1.up_or_down == 0)
					player1.action = "can`t go";
				else
				{
					if (actions == "go" and objects == "none")
					{
						cout << "---------------------------------" << endl;
						cout << "|Which direction you want to go?|" << endl;
						cout << "---------------------------------" << endl;
						getline(cin, objects);
						objects = To_lower(objects);
					}
					if ((objects == "north" and actions == "go" or action == "n")
						or (actions == "north" and objects == "none"))
					{
						player1.x_last_time = player1.x;
						player1.y_last_time = player1.y;
						player1.x += 1;
						player1 = if_over(player1, place);
						if (!player1.if_over)
						{
							player1.action = "move";
							player1.object = "north";
							if (player1.location == "up")
							{
								if (player1.x > place.entrance_4_x and player1.y == place.entrance_4_y and player1.if_gorilla_run != 1)
								{
									cout << "-------------------------------------------" << endl;
									cout << "|The gorilla is there, you can`t approach!|" << endl;
									cout << "-------------------------------------------" << endl;
									player1.x -= 1;
								}
							}
							else
							{
								cout << "----------------------" << endl;
								cout << "|You are going north.|" << endl;
								cout << "----------------------" << endl;
							}
						}
						else if (player1.if_over)
						{
							cout << "-------------------------" << endl;
							cout << "|You go too far go back!|" << endl;
							cout << "-------------------------" << endl;
							player1.x -= 1;
							player1.action = "none";
						}

					}
					else if ((objects == "south" and actions == "go" or action == "s")
						or (actions == "south" and objects == "none"))
					{
						player1.x_last_time = player1.x;
						player1.y_last_time = player1.y;
						player1.x -= 1;
						player1 = if_over(player1, place);
						if (player1.if_over)
						{
							cout << "-------------------------" << endl;
							cout << "|You go too far go back!|" << endl;
							cout << "-------------------------" << endl;
							player1.x += 1;
							player1.action = "none";
						}
						else if (!player1.if_over)
						{
							player1.action = "move";
							player1.object = "south";
							cout << "----------------------" << endl;
							cout << "|You are going south.|" << endl;
							cout << "----------------------" << endl;
						}
					}
					else if ((objects == "west" and actions == "go" or action == "w")
						or (actions == "west" and objects == "none"))
					{
						player1.x_last_time = player1.x;
						player1.y_last_time = player1.y;
						player1.y += 1;
						player1 = if_over(player1, place);
						if (player1.location == "up" and player1.x == place.entrance_3_x and player1.y == place.entrance_3_y + 1
							and player1.hostile == 0)
						{
							cout << "-----------------------------------------------" << endl;
							cout << "|The hostile native is here, you can`t go out!|" << endl;
							cout << "-----------------------------------------------" << endl;
							player1.y -= 1;
							player1.action = "none";
						}
						else if (player1.location == "up" and player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
						{
							player1.action = "move";
							player1.object = "west";
							cout << "You are going west" << endl;
						}
						else
						{
							if (player1.if_over)
							{
								cout << "You go too far go back!" << endl;
								player1.y -= 1;
								player1.action = "none";
							}
							else if (!player1.if_over)
							{
								player1.action = "move";
								player1.object = "west";
								cout << "---------------------" << endl;
								cout << "|You are going west.|" << endl;
								cout << "---------------------" << endl;
							}
						}

					}
					else if ((objects == "east" and actions == "go" or action == "e")
						or (actions == "east" and objects == "none") or action == player1.command[3])
					{

						player1.x_last_time = player1.x;
						player1.y_last_time = player1.y;
						player1.y -= 1;
						player1 = if_over(player1, place);

						if (player1.if_over)
						{
							cout << "-------------------------" << endl;
							cout << "|You go too far go back!|" << endl;
							cout << "-------------------------" << endl;
							player1.y += 1;
							player1.action = "none";
						}
						else if (!player1.if_over)
						{
							player1.action = "move";
							player1.object = "east";
							cout << "---------------------" << endl;
							cout << "|You are going east.|" << endl;
							cout << "---------------------" << endl;
						}
						else
						{
							player1.action = actions;
							player1.object = objects;
							player1 = so_bad_so_sad(player1);
						}
					}
				}
				if (objects == "up" and actions == "go" and (player1.room == "ladder" or player1.up_or_down == 0))
				{
					player1.action = "up";
				}
				else if (objects == "down" and actions == "go" and (player1.room == "ladder" or player1.up_or_down == 1))
				{
					player1.action = "down";
				}
			}
			else
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "|You can`t move until you run away or defeat the ghost!|" << endl;
				cout << "--------------------------------------------------------" << endl;
				player1.action = "none";
			}
		}
		else if (actions == "look")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none" or objects == "around")
			{
				player1.action = "look";
				player1 = look_hint_and_search(player1, place);
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "search")
		{
			player1.action = "search";
			if (objects == "none" or objects == "it")
				player1 = look_hint_and_search(player1, place);

			else
				player1.object = objects;
		}
		else if (actions == "take")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
				if (if_can_get(player1, place))
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
		else if (actions == "enter")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
				player1.action = "enter";
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "eat")
		{
			player1.object = objects;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
				if (if_can_eat(player1, place) and player1.inventory[objects] != 0)
				{
					player1.action = "eat";
					player1.object = objects;
					player1.inventory[objects]--;
					cout << "-----------------------------------------------------------" << endl;
					cout << "After you eat " << objects << " your stomach feels better" << endl;
					cout << "-----------------------------------------------------------" << endl;
				}
				else
				{
					cout << "------------------------------------" << endl;
					cout << "You don`t have " << objects << "!!!" << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else
			{
				if (if_can_eat(player1, place))
				{
					player1.action = "eat";
					player1.object = objects;
					player1.inventory[objects]--;
					cout << "-----------------------------------------------------------" << endl;
					cout << "After you eat " << objects << " your stomach feels better" << endl;
					cout << "-----------------------------------------------------------" << endl;
				}
				else
				{
					cout << "------------------------------------" << endl;
					cout << "You can`t eat " << objects << "!!!" << endl;
					cout << "------------------------------------" << endl;
				}
			}
		}
		else if (actions == "inventory")
		{
			player1.action = "inventory";
			player1.object = objects;
			if (objects == "none")
			{
				if (player1.inventory.size() == 0)
					cout << "You are currently carring nothing" << endl;
				else
				{
					map<string, int>::iterator it;
					cout << "----------------------------" << endl;
					for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
						cout << it->first << ": " << it->second << endl;
				}
				cout << "gold:" << player1.gold << endl;
				cout << "----------------------------" << endl;
			}
			else
				player1 = so_bad_so_sad(player1);

		}
		else if (actions == "board" or actions == "sail")
		{
			player1.action = "board";
			player1.object = objects;
			if (objects == "none")
			{

				player1.action = "board";

			}
			else if (objects == "ship" or objects == "the ship")
			{
				player1.action = "board";
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "hint")
		{
			player1.action = "hint";
			player1.object = objects;
			if (objects == "none")
				player1 = look_hint_and_search(player1, place);
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "save")
		{
			player1.action = "save";
			player1.object = objects;
			save = save_game(player1);
			if (objects == "game" or objects == "none")
			{
				if (save)
				{
					cout << "--------------------" << endl;
					cout << "Save successfully!" << endl;
					cout << "--------------------" << endl;
				}
				else
				{
					cout << "------------" << endl;
					cout << "Save fail!" << endl;
					cout << "------------" << endl;
				}
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "load")
		{
			player1.action = "load";
			player1.object = objects;
			if (objects == "game" or objects == "none")
			{
				player1 = load_game(player1);
				player1.in_n_out = 0;
				load = true;
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "cut")
		{
			if (player1.inventory["knife"] == 0)
			{
				cout << "--------------------------" << endl;
				cout << "You need a knife to cut!" << endl;
				cout << "--------------------------" << endl;
				player1.action = "none";
			}
			else if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
				player1.action = actions;
				if (if_can_cut(player1, place))
					player1.action = "cut";
				else
				{
					cout << "-------------------------------------------------------" << endl;
					cout << "Cut cut cut, your skill of cutting is getting better." << endl;
					cout << "-------------------------------------------------------" << endl;
				}
			}
			else if (objects == "it")
			{
				if (player1.room == "banana tree")
				{
					player1.action = "cut";
					player1.object = objects;
				}
				else
				{
					cout << "-------------------------------------------------------" << endl;
					cout << "Cut cut cut, your skill of cutting is getting better." << endl;
					cout << "-------------------------------------------------------" << endl;
				}
			}
			else
			{
				player1.action = actions;
				player1.object = objects;
				if (if_can_cut(player1, place))
				{
					player1.action = "cut";
					player1.object = objects;
				}
				else
				{
					cout << "-------------------------------------------------------" << endl;
					cout << "Cut cut cut, your skill of cutting is getting better." << endl;
					cout << "-------------------------------------------------------" << endl;
				}
			}
		}
		else if (actions == "help")
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
		else if (actions == "quit")
		{
			player1.action = "quit";
			player1.object = objects;
			if (objects == "none" or objects == "game")
				exit(0);
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "get")
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
					objects = ask_for_objects(actions, objects);
					player1.object = objects;
					if (if_can_get(player1, place))
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
			}
		}
		else if (actions == "give")
		{
			player1.object = objects;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
				if (if_can_give(player1, place))
				{
					player1.action = "give";
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
		else if (actions == "hide")
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
		else if (actions == "display")
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
		else if (actions == "drop")
		{
			player1.action = actions;
			player1.object = objects;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
				if (if_can_drop(player1))
				{
					player1.object = objects;
					player1 = drop_it(player1);
				}
				else
				{
					cout << "-------------------------------------------" << endl;
					cout << "You don`t have " << objects << " to drop!" << endl;
					cout << "-------------------------------------------" << endl;
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
					cout << "-------------------------------------------" << endl;
					cout << "You don`t have " << objects << " to drop!" << endl;
					cout << "-------------------------------------------" << endl;
				}
			}
		}
		else if (actions == "pick" or actions == "lift")
		{
			int pos;
			if (objects == "up")
				objects = "none";
			else
			{
				pos = objects.find(" ");
				if (pos >= 0 and pos <= objects.length() - 1)
					objects = objects.substr(pos + 1);
				player1.object = objects;
			}
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
				if (if_can_pick(player1))
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
				{
					player1.action = "pick";
				}
				else
				{
					player1.action = "none";
					player1.object = "none";
				}
			}

		}
		else if (actions == "up" or action == "u")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none" and (player1.room == "ladder" or player1.room == "brig"))
				player1.action = "up";
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "down" or action == "d")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none" and (player1.room == "ladder" or player1.up_or_down == 1))
				player1.action = "down";
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "unlock" or actions == "open")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
			}
			if (player1.inventory["key"] == 0)
			{
				cout << "---------------------------" << endl;
				cout << "You need a key to unlock!" << endl;
				cout << "---------------------------" << endl;
			}
			else if (objects == "brig" and player1.room == "brig")
				player1.action = "unlock";
			else if (objects != "none" and player1.room == "brig")
			{
				cout << "---------------------------------------" << endl;
				cout << "This is a brig not a " << objects << endl;
				cout << "---------------------------------------" << endl;
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "lie")
		{
			player1.object = objects;
			player1.action = actions;
			if ((objects == "none" or objects == "on bed" or objects == "on the bed") and player1.location == "up" and player1.x == place.bed_x)
				player1.action = "lie";
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "attack")
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Attack attack attack....The demage you deal is:0" << endl;
			cout << "--------------------------------------------------" << endl;
			player1.action = "none";
		}
		else if (actions == "run")
		{
			if (objects == "away")
			{
				cout << "--------------------------------------------------" << endl;
				cout << "You can only run away when you are in the battle" << endl;
				cout << "--------------------------------------------------" << endl;
				player1.action = "none";
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "equip")
		{
			int has;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
			}
			if (objects == "chainmail")
				objects = "chain mail";
			if (objects == "treasure")
			{
				cout << "---------------------------" << endl;
				cout << "You can`t equip treasure!" << endl;
				cout << "---------------------------" << endl;
			}
			else if (objects != "none")
			{
				has = if_has(player1, place, objects);
				if (has == 1)
				{
					map<string, equipment>::iterator it;
					for (it = place.equips.begin(); it != place.equips.end(); it++)
						if (it->second.name == objects)
						{
							player1.attack += it->second.attack;
							player1.defence += it->second.defence;
							if (it->second.attack > 0)
							{
								player1.equipments["weapon"] = objects;
							}
							else if (it->second.defence > 0)
							{
								if (objects == "chainmail helmet")
									player1.equipments["head"] = objects;
								else if (objects == "chain mail")
									player1.equipments["body"] = objects;
								else if (objects == "leggings")
									player1.equipments["legs"] = objects;
								else if (objects == "chainmail boots")
									player1.equipments["feet"] = objects;
							}
							else
							{
								player1.equipments["trinket"] = objects;
							}
							cout << "-----------------------------------------" << endl;
							cout << objects << " equiped!" << endl;
							cout << "Current attack is: " << player1.attack << endl;
							cout << "Current attack is: " << player1.defence << endl;
							cout << "-----------------------------------------" << endl;
						}
				}
				else if (has == 0)
				{
					cout << "-------------------------------------------------------" << endl;
					cout << "You have to get " << objects << " before you equip it!" << endl;
					cout << "-------------------------------------------------------" << endl;
				}
				else if (has == -1)
				{
					cout << "-------------------------------------------------------" << endl;
					cout << "" << objects << " equiped!" << " wait....what is " << objects << "?" << endl;
					cout << "-------------------------------------------------------" << endl;
				}
			}
			else
			{
				player1.object = objects;
				player1 = so_bad_so_sad(player1);
			}
		}
		else if (actions == "state")
		{
			if (objects == "none")
			{
				cout << "Player states:" << endl;
				cout << "Health:" << player1.health << endl;
				cout << "Attack:" << player1.attack << endl;
				cout << "Weapon currently equip:" << player1.equipments["weapon"] << "" << endl;
				cout << "Head currently equip:" << player1.equipments["head"] << "" << endl;
				cout << "Body currently equip:" << player1.equipments["body"] << "" << endl;
				cout << "Legs currently equip:" << player1.equipments["legs"] << "" << endl;
				cout << "Feet currently equip:" << player1.equipments["feet"] << "" << endl;
				cout << "Trinket currently equip:" << player1.equipments["trinket"] << "" << endl;
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (actions == "light")
		{
			if (objects == "none" or objects == "stem")
			{
				if (player1.with_light == false)
				{
					cout << "-----------------------------------------------------------------------" << endl;
					cout << "You`ve light the stem,a faint glow of fire gave off a trace of warmth." << endl;
					cout << "-----------------------------------------------------------------------" << endl;
					player1.with_light = true;
					player1.timer = 0;
				}
				else
				{
					cout << "------------------------------------" << endl;
					cout << "You are already holding the torch!" << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else
				player1 = so_bad_so_sad(player1);
		}
		else if (player1.room == "shop")
		{
			if (actions == "1")
				player1.action = "1";
			else if (actions == "2")
				player1.action = "2";
			else if (actions == "3")
				player1.action = "3";
			else if (actions == "sell")
			{
				bool wearing = false;
				map<string, string>::iterator it;
				if (objects == "none")
				{
					objects = ask_for_objects(actions, objects);
					player1.object = objects;
				}
				if (objects == "chainmail")
					objects = "chain mail";
				if (player1.inventory[objects] == 0)
				{
					cout << "---------------------------------------" << endl;
					cout << "You don`t have " << objects << " !!!" << endl;
					cout << "---------------------------------------" << endl;
					player1.inventory.erase(objects);
				}
				else if (player1.inventory[objects] == 1)
				{
					for (it = player1.equipments.begin(); it != player1.equipments.end(); it++)
					{
						if (it->second == objects)
						{
							wearing = true;
							cout << "---------------------------------------" << endl;
							cout << "You have to unequip " << objects << " first." << endl;
							cout << "---------------------------------------" << endl;
						}
					}
					if (!wearing)
					{
						player1.gold += place.items[objects] * 0.25;
						player1.inventory.erase(objects);
						cout << "---------------------------------------" << endl;
						cout << "You sold the " << objects << " to the shop!" << endl;
						cout << "---------------------------------------" << endl;
					}
				}
				else
				{
					player1.gold += place.items[objects] * 0.25;
					player1.inventory[objects]--;
					cout << "---------------------------------------" << endl;
					cout << "You sold the " << objects << " to the shop!" << endl;
					cout << "---------------------------------------" << endl;
				}
			}
			else if (actions == "unequip")
			{
				map<string, string>::iterator it;
				map<string, equipment>::iterator equip;
				bool wearing = false;
				if (objects == "none")
				{
					cout << "What are you gonna unequip?" << endl;
					getline(cin, objects);
					objects = To_lower(objects);
				}
				if (objects == "chainmail")
					objects = "chain mail";
				for (it = player1.equipments.begin(); it != player1.equipments.end(); it++)
				{
					if (it->second == objects and (objects != "none" or objects != "punch"))
					{
						it->second = "none";
						for (equip = place.equips.begin(); equip != place.equips.end(); equip++)
							if (equip->second.name == objects)
							{
								player1.attack -= equip->second.attack;
								player1.defence -= equip->second.defence;
							}
						wearing = true;
						cout << "------------------------------" << endl;
						cout << "You have uniquiped the " << objects << endl;
						cout << "current attack is:" << player1.attack << endl;
						cout << "current defence is:" << player1.defence << endl;
						cout << "------------------------------" << endl;
					}
				}
				if (!wearing)
					cout << "You are not wearing " << objects << " currently" << endl;
			}
		}
		else if (actions == "unequip")
		{
			map<string, string>::iterator it;
			map<string, equipment>::iterator equip;
			bool wearing = false;
			if (objects == "none")
			{
				cout << "What are you gonna unequip?" << endl;
				getline(cin, objects);
				objects = To_lower(objects);
			}
			for (it = player1.equipments.begin(); it != player1.equipments.end(); it++)
			{
				if (it->second == objects and (objects != "none" or objects != "punch"))
				{
					it->second = "none";
					for (equip = place.equips.begin(); equip != place.equips.end(); equip++)
						if (equip->second.name == objects)
						{
							player1.attack -= equip->second.attack;
							player1.defence -= equip->second.defence;
						}
					wearing = true;
					cout << "------------------------------" << endl;
					cout << "You have uniquiped the " << objects << endl;
					cout << "current attack is:" << player1.attack << endl;
					cout << "current defence is:" << player1.defence << endl;
					cout << "------------------------------" << endl;
				}
			}
			if (!wearing)
				cout << "You are not wearing " << objects << " currently" << endl;
		}
		else if (actions == "sell")
		{
			cout << "You can only sell in the shop!" << endl;
		}
		else
		{
			cout << "------------------------" << endl;
			cout << "|You can`t do that bro!|" << endl;
			cout << "------------------------" << endl;
		}
	}
	return player1;
}
player if_over(player player1, scene place)
//This function can determind if the player is over the boundaries of the map.
{

	if (player1.x < place.min_x)
	{
		if (player1.location == "island" and player1.x == 3
			and player1.y == -3 and player1.hostile == 1)
		{
			player1.if_over = false;
		}
		else
			player1.if_over = true;
	}
	else if (player1.x > place.max_x)

	{
		if (player1.location == "up")
		{
			if (player1.x == place.entrance_4_x + 1 and
				player1.y == place.entrance_4_y and player1.if_gorilla_run == 0)
				player1.if_over = false;
			else
				player1.if_over = true;
		}
		else if (player1.location == "island" and player1.x == 5
			and player1.y == -3 and player1.hostile == 1)
			player1.if_over = false;
		else
			player1.if_over = true;
	}
	else if (player1.y > place.max_y)
	{
		if (player1.location == "up" and player1.x == place.entrance_3_x
			and (player1.y == place.entrance_3_y or player1.y == place.entrance_3_y + 1))
			player1.if_over = false;
		else
			player1.if_over = true;

	}
	else if (player1.y < place.min_y)
	{
		if (player1.location == "island" and player1.x == place.entrance_3_x
			and player1.y == place.entrance_3_y - 1)
			player1.if_over = false;
		else
			player1.if_over = true;
	}
	return player1;
}
scene set_scene(player player1, scene place)//This function can set up the map according to the coordinate of the player.
{
	if (player1.y >= -4)
	{
		place.name = "island";
		place.long_description = "You are in a island.The island is forested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore.\nEnter \"help\" for help";
		place.short_description = "You are currently in the island, there are so many banana trees!";
		place.stuff_can_cut_name = "tree";
		place.entrance_3_name = "gangplank";
		place.stuff_can_cut_description = "You are standing in front of a ripe banana tree, you can take a look to see what is on the tree.\nstuff you can get:banana.";
		place.entrance_3_description = "You are at the gangplank! You wanna enter the ship?";
		place.stuff_can_cut_look_description_1 = "There is one branch of repe bananas on the tree.";
		place.stuff_can_cut_look_description_2 = "There is nothing on the tree....";
		place.stuff_can_cut_description_2 = "You are standing in front of a ripe banana tree! But....there is nothing on the tree you can reach....";
		place.shop_long_description = "You`ve enter the hostile`s shop.They have many different amazing stuff for sell\nThese items in this shop will updated in a period time.";
		place.shop_short_description = "You`ve enter the hostile`s shop";
		place.stuff_1_get_info = "You got a tempting banana!";
		place.max_x = 4;
		place.min_x = 4;
		place.max_y = -2;
		place.min_y = -4;
		place.stuff_can_cut_x = 4;
		place.stuff_can_cut_y = -2;
		place.entrance_3_x = 4;
		place.entrance_3_y = -4;
		place.shop_x = 3;
		place.shop_y = -3;
		place.question_x = 5;
		place.question_y = -3;
	}
	else if (player1.y <= -9 and player1.location == "up")
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
		place.entrance_1_description_2 = "You are in the captain`s quarter. There is a bed and a table in this room.\nstuff you can get: key";
		place.entrance_1_description_3 = "You are in the captain`s quarter. There is a bed and a table in this room.\nstuff you can get: key,knife";
		place.entrance_1_description_after_got_2 = "You are in the captain`s quarter. There is a bed and a table in this room.";
		place.entrance_1_short_description = "You are in the captsin`s quarter.\nstuff you can get: knife";
		place.entrance_1_short_description_2 = "You are in the captsin`s quarter.\nstuff you can get: knife,key";
		place.entrance_1_short_description_3 = "You are in the captsin`s quarter.\nstuff you can get: key";
		place.entrance_1_short_description_after_got = "You are in the captain`s quarter";
		place.entrance_2_description = "There is a ladder, do you want to go down?";
		place.entrance_4_description = "You are at eage of the ship`s wheel.There is a large gorilla by the ship`s wheel. The gorilla is hostile. You can`t approach the wheel.\n";
		place.entrance_4_description_2 = "You are at ship`s wheel. There is a gorilla right there.";
		place.entrance_4_short_description = "You are at the wheel.";
		place.entrance_3_description = "You are at the gangplank! You wanna leave the ship?";
		place.stuff_1_get_info = "You got a sharp knife!";
		place.max_x = 4;
		place.min_x = 0;
		place.max_y = -10;
		place.min_y = -10;
		place.entrance_1_x = 1;
		place.entrance_1_y = -10;
		place.bed_x = 0;
		place.entrance_2_x = 2;
		place.entrance_2_y = -10;
		place.entrance_4_x = 4;
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
		place.entrance_1_description = "You`ve entered the cargo hold. There are barrels, a pile of tools, and a trunk.\n You are standing in front of a trunk.\nstuff can get:stem";
		place.entrance_1_short_description = "You`ve entered the cargo hold. You are standing in front of a trunk\nstuff can get:stem";
		place.entrance_2_description = "There is a ladder, do you want to go up or down?";
		place.entrance_3_description = "You are at brig.In this room there is a prisoner in a locked cell.\nHe says,\"Jack,I`m so glad you`re alive. The captain locked me up for cheating at cards, which is the only reason the islanders didn`t capture me.\nThey killed everyone else.\nNow I guess we`re the only two left, which makes you captain since you were first mate.\nGo find the keys to unlock this door, and we can sail out of here.\"";
		place.entrance_3_short_description = "You are at brig, that man is watching you.";
		place.entrance_3_short_description_after = "You are at the brig.";
		place.entrance_4_description = "This is galley. It is mostly empty, but in a shadowy corner you see a parrot sitting on a perch.";
		place.entrance_4_short_description = "You are in the galley";
		place.stuff_1_get_info = "You got the treasure!";
		place.max_x = 2;
		place.min_x = 2;
		place.max_y = -9;
		place.min_y = -11;
		place.entrance_1_x = 2;
		place.entrance_1_y = -9;
		place.entrance_2_x = 2;
		place.entrance_2_y = -10;
		place.entrance_4_x = 2;
		place.entrance_4_y = -11;
	}
	return place;
}

player init_player(player player1)//This function can initialize the inventory of the player.
									 //Usually the amounts of the stuff that player carrying are all zeros.
{

	player1.equipments["weapon"] = "none";
	player1.equipments["head"] = "none";
	player1.equipments["body"] = "none";
	player1.equipments["legs"] = "none";
	player1.equipments["feet"] = "none";
	player1.equipments["trinket"] = "none";
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
		case 29:cout << index + 1 << ". " << "To" << " pick something---" << player1.command[index] << endl; break;
		case 30:cout << index + 1 << ". " << "To" << " lie---" << player1.command[index] << endl; break;
		case 31:cout << index + 1 << ". " << "To" << " attack---" << player1.command[index] << endl; break;
		case 32:cout << index + 1 << ". " << "To" << " run away---" << player1.command[index] << endl; break;
		case 33:cout << index + 1 << ". " << "To" << " equip equipment---" << player1.command[index] << endl; break;
		case 34:cout << index + 1 << ". " << "To" << " check character`s state---" << player1.command[index] << endl; break;
		case 35:cout << index + 1 << ". " << "To" << " light the stem---" << player1.command[index] << endl; break;
		case 36:cout << index + 1 << ". " << "To" << " unequip equipment---" << player1.command[index] << endl; break;
		case 37:cout << index + 1 << ". " << "To" << " sell stuff---" << player1.command[index] << endl; break;
			break;
		}

	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "|Enter the front number to choose which one you want to change|" << endl;
	cout << "---------------------------------------------------------------" << endl;
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
		cout << "-----------------------------------" << endl;
		cout << "|What word you want to change for?|" << endl;
		cout << "-----------------------------------" << endl;
		getline(cin, change);
		change = To_lower(change);
		while (repeat)
		{
			for (traversal = 0; traversal <= index; traversal++)
				if (player1.command[traversal] == change)
				{
					cout << "-------------------------------------------------------------" << endl;
					cout << "|This key is already used in command, please use aother key.|" << endl;
					cout << "-------------------------------------------------------------" << endl;
					getline(cin, change);
					change = To_lower(change);
					traversal = 0;
				}
			repeat = false;
		}
		player1.command[number - 1] = change;
		cout << "-------" << endl;
		cout << "|done!|" << endl;
		cout << "-------" << endl;
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
	map<string, string>::iterator equip;
	string temp;
	size_t pos;
	int success = 1, index;
	game_file.open("Advanture Island.txt");
	if (!game_file.is_open())
	{
		cout << "--------" << endl;
		cout << "|Error!|" << endl;
		cout << "--------" << endl;
		success = 0;
	}
	else
	{
		game_file << "location:" << endl;
		game_file << player1.x << " " << player1.y << "\n";
		game_file << "health:" << endl;
		game_file << player1.health << endl;
		game_file << "attack:" << endl;
		game_file << player1.attack << endl;
		game_file << "defence:" << endl;
		game_file << player1.defence << endl;
		game_file << "time:" << endl;
		game_file << player1.time << endl;
		game_file << "day:" << endl;
		game_file << player1.day << endl;
		game_file << "time_spent:" << endl;
		game_file << player1.time_spent << endl;
		game_file << "fighting" << endl;
		game_file << player1.fighting << endl;
		game_file << "weapon:" << endl;
		game_file << player1.weapon << endl;
		game_file << "gold:" << endl;
		game_file << player1.gold << endl;
		game_file << "with_light:" << endl;
		game_file << player1.with_light << endl;
		game_file << "Inventory:" << endl;
		for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
		{
			pos = it->first.find(" ");
			if (pos > 0 and pos < it->first.length())
			{
				temp = it->first.substr(0, pos);
				temp.append("_");
				temp += it->first.substr(pos + 1, it->first.length());
				game_file << temp << endl;
			}
			else
				game_file << it->first << endl;
			game_file << it->second << endl;
		}
		game_file << "Inventory_end" << endl;
		for (equip = player1.equipments.begin(); equip != player1.equipments.end(); equip++)
		{
			pos = equip->second.find(" ");
			if (pos > 0 and pos < equip->second.length())
			{
				temp = equip->second.substr(0, pos);
				temp.append("_");
				temp += equip->second.substr(pos + 1, equip->second.length());
				equip->second = temp;
			}
			game_file << equip->second << endl;
		}
		game_file << "up_or_down:" << endl;
		game_file << player1.up_or_down << endl;
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
		game_file << "player_gangplank_times:" << endl;
		game_file << player1.gangplank_times << endl;
		game_file << "player_shop_times:" << endl;
		game_file << player1.shop_times << endl;
		game_file << "player_question_times:" << endl;
		game_file << player1.question_times << endl;
		game_file << "item1" << endl;
		game_file << player1.num_item1 << endl;
		game_file << "item2" << endl;
		game_file << player1.num_item2 << endl;
		game_file << "item3" << endl;
		game_file << player1.num_item3 << endl;
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
	map<string, string>::iterator equip;
	map<string, string>::iterator it;
	string loaction, inventory, banana_amount, knife_amount, player_location,
		player_x_last_time, setting, hide, drop_stuff;
	string plaer_y_last_time, player_island_times, player_upper_deck_times,
		player_capitains_quarters_times, player_lower_deck_times;
	string player_cargo_hold_times, player_brig_times, player_galley_times, treasure_amount;
	string gorilla, parrot, hostile, key, prison, get, up_or_down, health, attack, money, time, day;
	string time_spent, fighting, weapon, gold, gangplank, light, shop, question, item1, item2, item3;
	string  defence, temp = " ", inventory_name;
	int index, inventory_quantity;
	size_t pos;
	game_file.open("Advanture Island.txt");
	if (!game_file.is_open())
	{
		cout << "--------------------" << endl;
		cout << "|Fail loading game!|" << endl;
		cout << "--------------------" << endl;
	}
	else
	{
		game_file >> loaction;
		game_file >> player1.x >> player1.y;
		game_file >> health;
		game_file >> player1.health;
		game_file >> attack;
		game_file >> player1.attack;
		game_file >> defence;
		game_file >> player1.defence;
		game_file >> time;
		game_file >> player1.time;
		game_file >> day;
		game_file >> player1.day;
		game_file >> time_spent;
		game_file >> player1.time_spent;
		game_file >> fighting;
		game_file >> player1.fighting;
		game_file >> weapon;
		game_file >> player1.weapon;
		game_file >> gold;
		game_file >> player1.gold;
		game_file >> light;
		game_file >> player1.with_light;
		game_file >> inventory;
		while (temp != "Inventory_end")
		{
			game_file >> temp;
			if (temp != "Inventory_end")
			{
				pos = temp.find("_");
				if (pos > 0 and pos < temp.length())
				{
					inventory_name = temp.substr(0, pos);
					inventory_name.append(" ");
					inventory_name += temp.substr(pos + 1, temp.length());
				}
				else
					inventory_name = temp;
				game_file >> inventory_quantity;
				player1.inventory[inventory_name] = inventory_quantity;
			}
		}
		for (equip = player1.equipments.begin(); equip != player1.equipments.end(); equip++)
		{
			game_file >> equip->second;
			pos = equip->second.find("_");
			if (pos > 0 and pos < equip->second.length())
			{
				temp = equip->second.substr(0, pos);
				temp.append(" ");
				temp += equip->second.substr(pos + 1, equip->second.length());
				equip->second = temp;
			}
		}
		game_file >> up_or_down;
		game_file >> player1.up_or_down;
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
		game_file >> gangplank;
		game_file >> player1.gangplank_times;
		game_file >> shop;
		game_file >> player1.shop_times;
		game_file >> question;
		game_file >> player1.question_times;
		game_file >> item1;
		game_file >> player1.num_item1;
		game_file >> item2;
		game_file >> player1.num_item2;
		game_file >> item3;
		game_file >> player1.num_item3;
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
		cout << "------------------------" << endl;
		cout << "|Load game successfully|" << endl;
		cout << "------------------------" << endl;
	}
	player1.load = 1;
	game_file.close();
	return player1;
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
	if (player1.location == "island" and player1.load == 0)
	{
		if (player1.x == place.stuff_can_cut_x and player1.y == place.stuff_can_cut_y)
			cout << "You currently at ripe banana tree." << endl;
		else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
			cout << "You currently at gangplank." << endl;
		else if (player1.x == place.shop_x and player1.y == place.shop_y)
			cout << "You currently at hostile`s shop." << endl;
		else if (player1.x == place.question_x and player1.y == place.question_y)
			cout << "You currently at questions room." << endl;
		else
			cout << "You currently at island." << endl;

	}
	else if (player1.location == "up" and player1.load == 0)
	{
		if (player1.x <= place.entrance_1_x and player1.y == place.entrance_1_y)
		{
			if (player1.x == place.bed_x)
				cout << "You are currently at the bed of captain`s quaters." << endl;
			else
				cout << "You are currently at the table of captain`s quaters." << endl;
		}
		else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
			cout << "You are currently at ladder." << endl;
		else if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
			cout << "You are currently at ship`s wheel." << endl;
		else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
			cout << "You are currently at gangplank." << endl;
		else
			cout << "You are currently at upper deck." << endl;


	}
	else if (player1.location == "down" and player1.load == 0)
	{
		if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
			cout << "You currently in front of the trunk in cargo hold." << endl;
		else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
			cout << "You are currently at ladder." << endl;
		else if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
			cout << "You are currently at galley" << endl;
		else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
			cout << "You are currently at brig." << endl;
		else
			cout << "You are currently ar lower deck." << endl;

		if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
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
					player1.inventory["banana"] ++;
					place.stuff_can_get.erase("banana");
					cout << place.stuff_1_get_info << endl;
				}
				else if (player1.action == "get")
				{
					cout << "-------------------------------------" << endl;
					cout << "You need a knife to get the banana!" << endl;
					cout << "-------------------------------------" << endl;
				}
			}
			else if (player1.banana_amount == 0)
			{
				cout << "-----------------------------" << endl;
				cout << "You already got the banana!" << endl;
				cout << "-----------------------------" << endl;
			}
		}
	}
	else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
	{
		player1.room = "gangplank";
		cout << place.entrance_3_description << endl;
		player1 = take_action(player1, place);
		if (player1.action == "enter" or player1.action == "move" and player1.object == "east")
		{
			player1.location = "up";
			player1.x = 3;
			player1.y = -10;
		}
	}
	else if (player1.x == place.shop_x and player1.y == place.shop_y and player1.hostile == 1)
	{
		int  index = 0, item_num = 1;
		string item1, item2, item3;
		map<string, int>::iterator item = place.items.begin();
		player1.room = "shop";
		player1 = add_times(player1);
		if (player1.in_n_out == 0 and player1.shop_times == 1)
		{
			srand((unsigned)time(NULL));
			player1.num_item1 = rand() % (place.items.size());
			player1.num_item2 = rand() % (place.items.size());
			while (player1.num_item2 == player1.num_item1)
				player1.num_item2 = rand() % (place.items.size());
			player1.num_item3 = rand() % (place.items.size());
			while (player1.num_item3 == player1.num_item1 or player1.num_item3 == player1.num_item2)
			{
				player1.num_item3 = rand() % (place.items.size());
				cout << player1.num_item3 << endl;
			}
			cout << place.shop_long_description << endl;
			player1.in_n_out = 1;
		}
		else if (player1.in_n_out == 0 and player1.shop_times > 1)
		{
			srand((unsigned)time(NULL));
			player1.num_item1 = rand() % (place.items.size());
			player1.num_item2 = rand() % (place.items.size());
			while (player1.num_item2 == player1.num_item1)
				player1.num_item2 = rand() % (place.items.size());
			player1.num_item3 = rand() % (place.items.size());
			while (player1.num_item3 == player1.num_item1 or player1.num_item3 == player1.num_item2)
				player1.num_item3 = rand() % (place.items.size());
			cout << place.shop_short_description << endl;
			player1.in_n_out = 1;
		}
		cout << "Here are the items for this time!" << endl;
		while (item != place.items.end())
		{
			if (index == player1.num_item1 or index == player1.num_item2 or index == player1.num_item3)
			{
				cout << item_num << "." << item->first << "-------" << item->second << endl;
				item_description(item->first);
				if (item_num == 1)
					item1 = item->first;
				else if (item_num == 2)
					item2 = item->first;
				else if (item_num == 3)
					item3 = item->first;
				item_num++;
			}
			item++;
			index++;
		}
		player1 = take_action(player1, place);
		if (player1.action == "1")
		{
			if (player1.gold >= place.items[item1])
			{
				cout << "Got " << item1 << "!!!" << endl;
				player1.gold -= place.items[item1];
				player1.inventory[item1]++;
			}
			else
			{
				cout << "---------------------" << endl;
				cout << "You need more money" << endl;
				cout << "---------------------" << endl;
			}
		}
		else if (player1.action == "2")
		{
			if (player1.gold >= place.items[item2])
			{
				cout << "Got " << item2 << "!!!" << endl;
				player1.gold -= place.items[item2];
				player1.inventory[item2]++;
			}
			else
			{
				cout << "---------------------" << endl;
				cout << "You need more money" << endl;
				cout << "---------------------" << endl;
			}
		}
		else if (player1.action == "3")
		{
			if (player1.gold >= place.items[item3])
			{
				cout << "Got " << item3 << "!!!" << endl;
				player1.gold -= place.items[item3];
				player1.inventory[item3]++;
			}
			else
			{
				cout << "---------------------" << endl;
				cout << "You need more money" << endl;
				cout << "---------------------" << endl;
			}
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
			if (player1.hostile == 1)
				cout << "The hostile natives establish a shop and a mysterious hut\n" <<
				"The shop is on the south of island and the hut is on the north of island." << endl;
		}
		player1 = take_action(player1, place);
	}
	return player1;
}
player upper_deck(player player1, scene place, bool& success)//This function can set up the map "upper deck" in the game.
{
	vector<string> give;
	player1 = pick_it_up(player1, place);
	if (!player1.with_light)
		player1 = fight(player1, place);
	if (player1.x <= place.entrance_1_x and player1.y == place.entrance_1_y)
	{
		player1.room = "captain`s quarters";
		player1 = add_times(player1);
		if (player1.captain_quarters_times == 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			if (player1.parrot == 0)
				cout << place.entrance_1_description << endl;
			else
				cout << place.entrance_1_description_3 << endl;
		}
		else if (player1.captain_quarters_times > 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			if (player1.parrot == 0)
			{
				if (player1.knife_amount == 0)
					cout << place.entrance_1_short_description_after_got << endl;
				else
					cout << place.entrance_1_short_description << endl;
			}
			else
			{
				if (player1.knife_amount == 0)
				{
					if (player1.key_amount != 0)
						cout << place.entrance_1_short_description_3 << endl;
					else
						cout << place.entrance_1_short_description_after_got << endl;
				}
				else
				{
					if (player1.key_amount != 0)
						cout << place.entrance_1_short_description_2 << endl;
					else
						cout << place.entrance_1_short_description << endl;
				}
			}
		}
		if (player1.x == place.bed_x)
		{
			cout << "You see a soft comfortable bed in front of you, you can lying on the bed to restore your health." << endl;
			player1 = take_action(player1, place);

			if (player1.action == "lie")
			{
				player1.health = 100;
				player1.time = "8:00";
				cout << "--------------------------------------------------------" << endl;
				cout << "One night passed away. You feel you are full of vigor." << endl;
				cout << "--------------------------------------------------------" << endl;
			}
		}
		else if (player1.x != place.bed_x)
		{
			if (player1.parrot == 0)
			{
				if (player1.knife_amount != 0)
				{
					cout << "You see there is a shinning knife on the table!" << endl;
					player1 = take_action(player1, place);
					if (player1.action == "get" and player1.object == "knife")
					{
						player1.knife_amount -= 1;
						player1.inventory["knife"] ++;
						place.stuff_can_get.erase("knife");
						cout << place.stuff_1_get_info << endl;
						player1 = take_action(player1, place);
					}
				}
				else
				{
					cout << "You are standing in front of a table." << endl;
					player1 = take_action(player1, place);
				}
			}
			else if (player1.parrot == 1 and player1.key_amount != 0)
			{
				if (player1.knife_amount == 0)
				{
					cout << "You are standing in front of a table, and you see the key is under the table!" << endl;
					player1 = take_action(player1, place);
					if (player1.action == "get" and player1.object == "key")
					{
						cout << "You got the key!" << endl;
						player1.inventory["key"]++;
						player1.key_amount--;
						place.stuff_can_get.erase("key");
					}
				}
				else
				{
					cout << "You are standing in front of a table, and you see the knife is on the table and key is under the table!" << endl;
					player1 = take_action(player1, place);
					if (player1.action == "get" and player1.object == "knife")
					{
						player1.knife_amount -= 1;
						player1.inventory["knife"] ++;
						place.stuff_can_get.erase("knife");
						cout << place.stuff_1_get_info << endl;
					}
					if (player1.action == "get" and player1.object == "key")
					{
						cout << "You got the key!" << endl;
						player1.inventory["key"]++;
						player1.key_amount--;
						place.stuff_can_get.erase("key");
					}
				}
			}
			else if (player1.parrot == 1 and player1.key_amount == 0)
			{

				if (player1.knife_amount != 0)
				{
					cout << "You see there is a shinning knife on the table!" << endl;
					player1 = take_action(player1, place);
					if (player1.action == "get" and player1.object == "knife")
					{
						player1.knife_amount -= 1;
						player1.inventory["knife"] ++;
						place.stuff_can_get.erase("knife");
						cout << place.stuff_1_get_info << endl;
						player1 = take_action(player1, place);
					}
				}
				else
				{
					cout << "You are standing in front of a table." << endl;
					player1 = take_action(player1, place);
				}
			}
		}
	}
	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		player1.room = "ladder";
		if (player1.last_room != "captain`s quarters" or player1.last_room != "ship`s wheel")
		{
			player1.in_n_out = 0;
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
			player1.last_room = "ladder";
		}
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
			if (player1.action == "give" and player1.object == "banana" or
				player1.object == "banana to gorilla")
			{
				player1.inventory["banana"] --;
				place.stuff_can_give.erase("banana");
				player1.if_gorilla_run = 1;
				cout << "The gorilla rush to the forest and disapear!" << endl;
			}
			while (player1.action == "move" and player1.object == "north")
			{
				player1 = take_action(player1, place);
			}
		}
		if (player1.if_gorilla_run != 0)
		{
			cout << place.entrance_4_short_description << endl;
			player1 = take_action(player1, place);
			if (player1.action == "board")
			{
				if (player1.prison != 0)
				{
					success = true;
					cout << "You finally success to sail away!" << endl;
				}
				else
					cout << "You need that guy in the brig to help you board this ship!" << endl;
			}
		}
	}
	else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
	{
		player1.room = "gangplank";
		player1 = add_times(player1);
		if (player1.hostile == 0)
		{
			if (player1.in_n_out == 0 and player1.gangplank_times == 1)
			{
				cout << "There are hostile natives that appear outside the ship after the player boards\n" <<
					"They will not allow anyone off the ship until you give the treasure to them." << endl;
				player1.in_n_out = 1;
			}
			else if (player1.in_n_out == 0 and player1.gangplank_times != 1)
			{
				cout << "There are hostile natives outside want the treasure!" << endl;
				player1.in_n_out = 1;
			}
			player1 = take_action(player1, place);
			if (player1.action == "give")
			{
				place.stuff_can_give.erase("treasure");
				player1.inventory.erase("treasure");
				player1.hostile = 1;
				cout << "The hostile native finally leave." << endl;
			}
		}
		else
		{
			if (player1.in_n_out == 0)
				cout << place.entrance_3_description << endl;
			player1 = take_action(player1, place);
			if (player1.action == "get out" or (player1.action == "move" and player1.object == "west"))
			{
				cout << "You have got out of the ship!" << endl;
				player1.location = "island";
				player1.x = 4;
				player1.y = -3;
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
	}
	return player1;
}
player lower_deck(player player1, scene place)//This function can set up the map "lower deck" in the game.
{
	player1 = pick_it_up(player1, place);
	if (!player1.with_light)
		player1 = fight(player1, place);
	if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
	{
		player1.room = "cargo hold";
		player1 = add_times(player1);
		int get_stem;
		if (player1.in_n_out == 0 and player1.cargo_hold_times == 1)
		{
			cout << place.entrance_1_description << endl;
			player1.in_n_out = 1;
		}
		else if (player1.in_n_out == 0 and player1.cargo_hold_times != 1)
		{
			if (player1.get == 1)
				cout << place.entrance_1_short_description << "and a treasure is hiding behind the trunck." << endl;
			else
				cout << place.entrance_1_short_description << endl;
			player1.in_n_out = 1;
		}
		player1 = take_action(player1, place);
		if (player1.action == "get")
		{
			if (player1.treasure_amount != 0 and player1.get == 1)
			{
				cout << "-----------------------" << endl;
				cout << "|You got the treasure!|" << endl;
				cout << "-----------------------" << endl;
				player1.get = 0;
				player1.inventory["treasure"]++;
				player1.treasure_amount--;
				place.stuff_can_get.erase("treaure");
			}
			else if (player1.get == 0 and player1.treasure_amount != 0)
			{
				cout << "----------------------------" << endl;
				cout << "|You got nothing from here.|" << endl;
				cout << "----------------------------" << endl;
			}
			else
			{
				cout << "------------------------------" << endl;
				cout << "|You aready got the treasure!|" << endl;
				cout << "------------------------------" << endl;
			}
		}
		else if (player1.action == "cut")
		{
			if (player1.object == "trunk")
			{
				cout << "-----------------" << endl;
				cout << "|You got a stem!|" << endl;
				cout << "-----------------" << endl;
				player1.inventory["stem"]++;
			}
		}

	}

	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		if (player1.up_or_down != 0)
		{
			player1.room = "ladder";
			if (player1.last_room != "brig" and player1.last_room != "galley"
				and player1.last_room != "cargo hold" and player1.last_room != "lower deck")
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
				player1.room = "ladder";
			}
			cout << place.entrance_2_description << endl;
			player1.last_room = "ladder";
			player1 = take_action(player1, place);
			if (player1.action == "up")
			{
				player1.location = "up";
				player1.lower_times++;
				player1.in_n_out = 0;
				player1.x = 2;
				player1.y = -10;
			}
			if (player1.action == "down")
			{
				player1.up_or_down = 0;
			}
		}
		else if (player1.up_or_down == 0)
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
				else
					cout << place.entrance_3_short_description_after << endl;
				player1.in_n_out = 1;
			}
			player1 = take_action(player1, place);
			while (player1.action == "can`t go")
			{
				cout << "-----------------------------------" << endl;
				cout << "|You have to leave the brig first.|" << endl;
				cout << "-----------------------------------" << endl;
				player1 = take_action(player1, place);
			}
			if (player1.action == "unlock" and player1.prison == 0)
			{
				cout << "--------------------------------------------" << endl;
				cout << "|You finally free that poor guy. Hell yeah!|" << endl;
				cout << "--------------------------------------------" << endl;
				player1.inventory["key"]--;
				player1.prison = 1;
				player1.in_n_out = 1;
			}
			else if (player1.action == "up")
				player1.up_or_down = 1;
		}
	}

	else if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
	{
		string words;
		int get_out = player1.parrot;
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
		}
	}
	else
	{
		player1 = take_action(player1, place);
	}
	return player1;
}
void action_seprate(string & actions, string & objects, string action)
//This function can separate the command in two parts
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
bool if_has_object(string action)
//This function can determind if the command has object.
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
//This function can prompt the player when they input the bad command.
{
	if (player1.object != "none")
	{
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "|So bad so sad, you can`t " << player1.action << " " << player1.object << " right now!|" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
	}
	else
	{
		cout << "--------------------------------------------------------------" << endl;
		cout << "|So bad so sad, you can`t " << player1.action << " right now!|" << endl;
		cout << "--------------------------------------------------------------" << endl;
	}
	player1.action = "none";
	return player1;
}
bool if_can_get(player player1, scene place)
//This function can determind if the player can get
// something in the game.
{
	bool get = false;
	map<string, string>::iterator it;
	string coordinate;
	coordinate = coordinate_to_string(player1);

	for (it = place.stuff_can_get.begin(); it != place.stuff_can_get.end(); it++)
	{
		if (it->first == player1.object and it->second == coordinate)
			get = true;
	}
	if (!get)
	{
		cout << "----------------------------------------------------------" << endl;
		cout << "|Sorry, you can`t get " << player1.object << " right here|" << endl;
		cout << "----------------------------------------------------------" << endl;
	}
	return get;
}
bool if_can_cut(player player1, scene place)
//This function can determind if the player can cut
// something in the game.
{
	bool cut = false;
	map<string, string>::iterator it;
	string coordinate;
	coordinate = coordinate_to_string(player1);


	for (it = place.stuff_can_cut.begin(); it != place.stuff_can_cut.end(); it++)
	{
		if (player1.object == it->first and it->second == coordinate)
			cut = true;
	}
	if (!cut)
	{
		cout << "--------------------------------------" << endl;
		cout << "|" << player1.object << " is not here!|" << endl;
		cout << "--------------------------------------" << endl;
	}
	return cut;
}
bool if_can_give(player player1, scene place)
//This function can determind if the player can give
// something in the game.
{
	bool give = false, equal = false;
	map<string, string>::iterator it;
	string coordinate;
	coordinate = coordinate_to_string(player1);
	for (it = place.stuff_can_give.begin(); it != place.stuff_can_give.end(); it++)
	{
		if (player1.object == it->first)
		{
			equal = true;
			if (player1.inventory[player1.object] != 0 and it->second == coordinate)
				give = true;
			else if (player1.inventory[player1.object] != 0 and it->second != coordinate)
			{
				cout << "-------------------------------" << endl;
				cout << "|You can`t do that right here!|" << endl;
				cout << "-------------------------------" << endl;
			}
			else
			{
				cout << "---------------------------------" << endl;
				cout << "|You don`t have " << player1.object << " to give!|" << endl;
				cout << "---------------------------------" << endl;
			}
		}
	}
	if (!equal)
	{
		cout << "--------------------------------------" << endl;
		cout << "|You don`t have " << player1.object << " to give!|" << endl;
		cout << "--------------------------------------" << endl;
	}
	return give;
}
bool if_can_eat(player player1, scene place)
//This function can determind if the player can eat
// something in the game.
{
	bool eat = false;
	vector<string>::iterator it;

	for (it = place.stuff_can_eat.begin(); it != place.stuff_can_eat.end(); it++)
	{
		if (player1.object == *it and player1.inventory[player1.object] != 0)
			eat = true;
	}

	return eat;
}
bool if_can_pick(player player1)
//This function can determind if the player can pick
// something in the game.
{
	map<string, string>::iterator it;
	bool pick = false;
	string name, coordinate;
	coordinate = coordinate_to_string(player1);
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
	{
		cout << "---------------------------" << endl;
		cout << "|" << player1.object << " is not here!|" << endl;
		cout << "---------------------------" << endl;
	}

	return pick;
}
bool if_can_drop(player player1)
//This function can determind if the player can drop
// something in the game.
{
	bool drop = false;
	map<string, int>::iterator it;
	for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
		if (it->first == player1.object and it->second != 0)
			drop = true;

	return drop;
}
string coordinate_to_string(player player1)
//This function can convert the coordinate of the player to a string.
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
player pick_it_up(player player1, scene place)
//This function can let player pick up the stuff he dropped.
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
				cout << "--------------------------" << endl;
				cout << "|You got the " << origin_name << " back!|" << endl;
				cout << "--------------------------" << endl;
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
//This function can rename the stuff that the player dropped
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
string recover_name(string name)
//This function can recover the name of the stuff
//that the player dropped.
{
	int pos;
	pos = name.find(" ");
	name = name.substr(0, pos);
	return name;
}
player drop_it(player player1)
//This function can let player drop stuff in the game.
{
	map<string, string>::iterator it;
	string name, drop_coordinate;
	bool duplicate = false;
	player1.inventory.erase(player1.object);
	drop_coordinate = coordinate_to_string(player1);
	for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
	{
		name = it->first;
		name = recover_name(name);
		if (name == player1.object)
		{
			name = it->first;
			cout << "-----------------------------------------------------" << endl;
			cout << "|You drop a " << player1.object << "\nPlease protect the environment!|" << endl;
			cout << "-----------------------------------------------------" << endl;
			name = re_name(player1, name);
			player1.drop_stuff[name] = drop_coordinate;
			duplicate = true;
		}
	}
	if (duplicate == false)
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "|You drop a " << player1.object << "\nPlease protect the environment!|" << endl;
		cout << "-----------------------------------------------------" << endl;
		player1.object.append(" ");
		player1.object.append("1");
		player1.drop_stuff[player1.object] = drop_coordinate;
	}
	return player1;
}
int get_number(string name)
//This function can get the number in the name of the stuff that player dropped
//like the 1 in banana 1.
{
	int pos, number;
	pos = name.find(" ");
	name = name.substr(pos + 1);
	number = stoi(name);
	return number;
}
string sentence_to_pig_latin(string sentence)
//This function can convert the words in a sentence to pig-latin.
{
	string new_sentence;
	vector<string>marks;
	vector<string>word;
	string hello;
	int index;
	bool bingo = false;
	int marks_index = 0, word_index = 0;
	if (has_mark(sentence))
	{
		get_sentence(sentence, marks, word);
		for (index = 0; index <= word.size() - 1; index++)
		{
			hello = To_lower_2(word[index]);
			if (hello == "hello" or hello == "polly" or hello == "cracker")
			{
				new_sentence = "hello";
				bingo = true;
			}
		}
		if (!bingo)
		{
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
		}
	}
	else
	{
		if (sentence == "hello" or sentence == "polly" or sentence == "cracker")
			new_sentence = "hello";
		else
			new_sentence = pig_latin(sentence);
	}
	return new_sentence;
}
string pig_latin(string word)
//This function can convert a single word to pig-latin.
{
	string first_letter;
	first_letter = word.at(0);
	first_letter.append("ay");
	word = word.substr(1);
	word.append(first_letter);
	return word;
}
void get_sentence(string sentence, vector<string> & marks, vector<string> & word)//This cuntion can separate a sentence into marks and words.
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
player add_times(player player1)
//This function can count how many times that player has been to the map.
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
	else if (player1.room == "gangplank" and player1.gangplank_times == 0)
	{
		player1.gangplank_times++;
		player1.in_n_out = 0;
		player1.last_room = "gangplank";
	}
	else if (player1.room == "shop" and player1.shop_times == 0)
	{
		player1.shop_times++;
		player1.in_n_out = 0;
		player1.last_room = "shop";
	}
	else if (player1.room == "question" and player1.question_times == 0)
	{
		player1.question_times++;
		player1.in_n_out = 0;
		player1.last_room = "question";
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
			else if (player1.room == "gangplank")
			{
				player1.gangplank_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "shop")
			{
				player1.shop_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "question")
			{
				player1.question_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
		}
	}
	return player1;
}
player look_hint_and_search(player player1, scene place)
//This function can prompt the player when the player
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
					{
						cout << "---------------------------------------------------------------" << endl;
						cout << "|Need knife to cut? Don`t forget there is a ship to your east.|" << endl;
						cout << "---------------------------------------------------------------" << endl;
					}
					else
					{
						cout << "----------------- " << endl;
						cout << "|Cut cut cut!!!!|" << endl;
						cout << "----------------- " << endl;
					}
				}
			}
			else
			{
				if (player1.action == "look")
					cout << place.stuff_can_cut_look_description_2 << endl;
				else if (player1.action == "hint")
				{
					cout << "-----------------------------" << endl;
					cout << "|You already got the banana!|" << endl;
					cout << "-----------------------------" << endl;
				}
			}
		}
		else if (player1.room == "gangplank")
		{
			if (player1.action == "look")
				cout << place.entrance_3_description << endl;
			else if (player1.action == "hint")
			{
				cout << "--------------------------------------------" << endl;
				cout << "|To go in or not go in, that is a question.|" << endl;
				cout << "--------------------------------------------" << endl;
			}
			else if (player1.action == "search")
			{
				cout << "--------------------" << endl;
				cout << "|No new discoveries|" << endl;
				cout << "--------------------" << endl;
			}
		}
		else
		{
			if (player1.action == "look")
				cout << place.long_description << endl;

			else if (player1.action == "hint")
			{
				if (player1.banana_amount == 1)
				{
					cout << "--------------------" << endl;
					cout << "|Go get the banana!|" << endl;
					cout << "--------------------" << endl;
				}
				else
				{
					cout << "-----------------------------------" << endl;
					cout << "|There is nothing I can prompt you|" << endl;
					cout << "-----------------------------------" << endl;
				}
			}
			else if (player1.action == "search")
			{
				cout << "--------------------" << endl;
				cout << "|No new discoveries|" << endl;
				cout << "--------------------" << endl;
			}
		}

	}
	else if (place.name == "upper deck")
	{
		if (player1.room == "captain`s quarters")
		{
			if (player1.parrot == 0)
			{
				if (player1.action == "look")
				{
					if (player1.knife_amount == 1)
						cout << place.entrance_1_description << endl;
					else
						cout << place.entrance_1_description_after_got << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "----------------------------" << endl;
					cout << "|Get the knife and go away.|" << endl;
					cout << "----------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					if (player1.knife_amount != 0)
					{
						cout << "-------------------------------------" << endl;
						cout << "|You found nothing except the knife.|" << endl;
						cout << "-------------------------------------" << endl;
					}
					else
					{
						cout << "-------------------------------" << endl;
						cout << "|here is nothing on the table.|" << endl;
						cout << "-------------------------------" << endl;
					}
				}

			}
			else
			{
				if (player1.action == "look")
				{
					if (player1.knife_amount == 1)
						cout << place.entrance_1_description_3 << endl;
					else
						cout << place.entrance_1_description_2 << endl;
				}
				else if (player1.action == "hint")
				{
					if (player1.knife_amount == 1)
					{
						cout << "------------------------------------" << endl;
						cout << "|Get the knife and key and go away.|" << endl;
						cout << "------------------------------------" << endl;
					}
					else
					{
						cout << "--------------------------" << endl;
						cout << "|Get the key and go away.|" << endl;
						cout << "--------------------------" << endl;
					}
				}
				else if (player1.action == "search")
				{
					if (player1.knife_amount != 0)
					{
						cout << "-----------------------------------------" << endl;
						cout << "|You the key and the knife on the table.|" << endl;
						cout << "-----------------------------------------" << endl;
					}
					else
					{
						cout << "---------------------------------" << endl;
						cout << "|You found the key on the table.|" << endl;
						cout << "---------------------------------" << endl;
					}
				}
			}
		}
		else if (player1.room == "ladder")
		{
			if (player1.action == "look")
				cout << place.long_description << endl;
			else if (player1.action == "hint")
			{
				cout << "------------------------------------------------" << endl;
				cout << "|To go down or not go down, that is a question.|" << endl;
				cout << "------------------------------------------------" << endl;
			}
			else if (player1.action == "search")
			{
				cout << "------------------------------------" << endl;
				cout << "|You found nothing with this ladder|" << endl;
				cout << "------------------------------------" << endl;
			}
		}
		else if (player1.room == "ship`s wheel")
		{
			if (player1.if_gorilla_run == 0)
			{
				if (player1.action == "look")
				{
					cout << "----------------------------------------------------------------------------------------------" << endl;
					cout << "|You take a sneak look at the gorilla. It's so big and frightening that you hide back quickly|" << endl;
					cout << "----------------------------------------------------------------------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "----------------------------------------" << endl;
					cout << "|Think about what gorilla likes to eat?|" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "----------------------------------------------------" << endl;
					cout << "|You can`t do any search when the gorilla is there!|" << endl;
					cout << "----------------------------------------------------" << endl;
				}
			}
			else
			{
				if (player1.action == "look")
					cout << place.entrance_4_description_2 << endl;
				else if (player1.action == "hint")
				{
					cout << "------------------------------------------------" << endl;
					cout << "|You need a sailor to help you sail this ship.|" << endl;
					cout << "------------------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "---------------------" << endl;
					cout << "|No new discoveries.|" << endl;
					cout << "---------------------" << endl;
				}
			}
		}
		else if (player1.room == "gangplank")
		{
			if (player1.hostile == 0)
			{
				if (player1.action == "look")
					cout << "There are hostile natives that appear outside the ship after the player boards\n" <<
					"They will not allow anyone off the ship until you give the treasure to them." << endl;
				else if (player1.action == "hint")
				{
					cout << "--------------------------------------------" << endl;
					cout << "|Why you wait? Just give them the treasure.|" << endl;
					cout << "--------------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "|No new discoveries|" << endl;
					cout << "--------------------" << endl;
				}
			}
			else
			{
				if (player1.action == "look")
					cout << place.entrance_3_description << endl;
				else if (player1.action == "hint")
				{
					cout << "---------------------------------------------" << endl;
					cout << "|To go in or not go out, that is a question.|" << endl;
					cout << "---------------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "|No new discoveries|" << endl;
					cout << "--------------------" << endl;
				}
			}
		}
		else
		{
			if (player1.action == "look")
				cout << place.long_description << endl;
			else if (player1.action == "hint")
			{
				if (player1.if_gorilla_run == 1)
				{
					cout << "------------------------------------" << endl;
					cout << "|Kick the gorilla out of this ship!|" << endl;
					cout << "------------------------------------" << endl;
				}
				else
				{
					cout << "------------------------------------" << endl;
					cout << "|There is nothing I can prompt you.|" << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else if (player1.action == "search")
			{
				cout << "--------------------" << endl;
				cout << "|No new discoveries|" << endl;
				cout << "--------------------" << endl;
			}
		}
	}
	else if (place.name == "lower deck")
	{
		if (player1.room == "cargo hold")
		{
			if (player1.treasure_amount == 1)
			{
				if (player1.action == "look")
				{
					cout << "-----------------------------------------" << endl;
					cout << "|It doesn't look like an ordinary trunk.|" << endl;
					cout << "-----------------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "----------------------------------" << endl;
					cout << "|Maybe there is something inside?|" << endl;
					cout << "----------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					if (player1.get == 0)
					{
						cout << "----------------------------------------" << endl;
						cout << "|You found the treasure in the trunk!!!|" << endl;
						cout << "----------------------------------------" << endl;
						player1.get = 1;
					}
					else
					{
						cout << "--------------------" << endl;
						cout << "|No new discoveries|" << endl;
						cout << "--------------------" << endl;
					}
				}
			}
			else
			{
				if (player1.action == "look")
				{
					cout << "-------------------------------" << endl;
					cout << "|The trunk has many many stmes|" << endl;
					cout << "-------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					if (player1.hostile == 0 and player1.inventory["treasure"] != 0)
					{
						cout << "----------------------------------------------" << endl;
						cout << "|Now, these hostile should be happy to leave.|" << endl;
						cout << "----------------------------------------------" << endl;
					}
					else
					{
						cout << "------------------------------------" << endl;
						cout << "|There is nothing I can prompt you.|" << endl;
						cout << "------------------------------------" << endl;
					}
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "|No new discoveries|" << endl;
					cout << "--------------------" << endl;
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
				{
					cout << "--------------------" << endl;
					cout << "|No new discoveries|" << endl;
					cout << "--------------------" << endl;
				}
			}
			else
			{
				if (player1.action == "look")
				{
					cout << "-----------------------------------------------------------------------------------------------------------" << endl;
					cout << "|You can see from the broken cage and its surroundings how much the poor man who had been inside suffered.|" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "------------------------------------" << endl;
					cout << "|There is nothing I can prompt you.|" << endl;
					cout << "------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "|No new discoveries|" << endl;
					cout << "--------------------" << endl;
				}
			}
		}
		else if (player1.room == "ladder")
		{
			if (player1.action == "look")
				cout << place.long_description << endl;
			else if (player1.action == "hint")
			{
				cout << "--------------------------------------------" << endl;
				cout << "|To go up or not go up, that is a question.|" << endl;
				cout << "--------------------------------------------" << endl;
			}
			else if (player1.action == "search")
			{
				cout << "--------------------" << endl;
				cout << "|No new discoveries|" << endl;
				cout << "--------------------" << endl;
			}
		}
		else if (player1.room == "galley")
		{
			if (player1.parrot == 0)
			{
				if (player1.action == "look")
					cout << place.entrance_4_description << endl;
				else if (player1.action == "hint")
				{
					cout << "------------------------------------" << endl;
					cout << "1.Try to be polite to the parrot.\n2.Think about what parrot likes to eat.\n3.It`s name is Polly" << endl;
					cout << "------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "|No new discoveries|" << endl;
					cout << "--------------------" << endl;
				}
			}
			else
			{
				if (player1.action == "look")
				{
					cout << "------------------------------------------------------------------------------------------------------------" << endl;
					cout << "|The parrot looks like it wants to play the Pig-Latin game with you. You're so scared that want to go away.|" << endl;
					cout << "------------------------------------------------------------------------------------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "------------------------------------" << endl;
					cout << "|There is nothing I can prompt you.|" << endl;
					cout << "------------------------------------" << endl;
				}
				else if (player1.action == "search") {
					cout << "--------------------" << endl;
					cout << "|No new discoveries|" << endl;
					cout << "--------------------" << endl;
				}
			}
		}
		else
		{
			if (player1.action == "look")
				cout << place.long_description << endl;
			else if (player1.action == "hint")
			{
				if (player1.parrot == 0 and player1.treasure_amount == 1)
				{
					cout << "-----------------------------------------------------" << endl;
					cout << "|Go find the key and free that man and the treasure!|" << endl;
					cout << "-----------------------------------------------------" << endl;
				}
				else if (player1.parrot == 0)
				{
					cout << "------------------------------------" << endl;
					cout << "|Go find the key and free that man!|" << endl;
					cout << "------------------------------------" << endl;
				}
				else if (player1.treasure_amount == 1)
				{
					cout << "-----------------------" << endl;
					cout << "|Go find the treasure!|" << endl;
					cout << "-----------------------" << endl;
				}
			}
			else if (player1.action == "search")
			{
				cout << "--------------------" << endl;
				cout << "|No new discoveries|" << endl;
				cout << "--------------------" << endl;
			}
		}
	}
	return player1;
}
scene init_scene(scene place)
//This function can initialize the coordinate of special stuff that 
// the player can do something with like drop or cut.
{
	equipment stem, sword, chainmail_helmet, chain_mail, leggings, chainmail_boots, banana, key, cross, pendant;
	stem.name = "stem";
	stem.attack = 1;
	stem.defence = 0;
	sword.name = "sword";
	sword.attack = 6;
	sword.defence = 0;
	chainmail_helmet.name = "chainmail helmet";
	chainmail_helmet.attack = 0;
	chainmail_helmet.defence = 1;
	chain_mail.name = "chain mail";
	chain_mail.attack = 0;
	chain_mail.defence = 2;
	leggings.name = "leggings";
	leggings.attack = 0;
	leggings.defence = 1;
	chainmail_boots.name = "chainmail boots";
	chainmail_boots.attack = 0;
	chainmail_boots.defence = 1;
	banana.name = "banana";
	banana.attack = 1;
	banana.defence = 0;
	key.name = "key";
	key.attack = 1;
	key.defence = 0;
	cross.name = "cross";
	cross.attack = 0;
	cross.defence = 0;
	pendant.name = "pendant";
	pendant.attack = 0;
	pendant.defence = 0;
	place.stuff_can_get["treasure"] = "2 -9 0";
	place.stuff_can_give["banana"] = "4 -10 1";
	place.stuff_can_give["treasure"] = "3 -9 1";
	place.stuff_can_get["knife"] = "1 -10 1";
	place.stuff_can_cut["banana"] = "4 -2 2";
	place.stuff_can_cut["trunk"] = "2 -9 0";
	place.stuff_can_get["banana"] = "4 -2 2";
	place.stuff_can_get["key"] = "1 -10 1";
	place.stuff_can_eat.push_back("banana");
	place.items["stem"] = 15;
	place.items["health potion"] = 40;
	place.items["sword"] = 80;
	place.items["chainmail helmet"] = 80;
	place.items["chain mail"] = 120;
	place.items["leggings"] = 80;
	place.items["pendant"] = 65;
	place.items["cross"] = 300;
	place.items["chainmail boots"] = 80;
	place.equips["stem"] = stem;
	place.equips["sword"] = sword;
	place.equips["chainmail_helmet"] = chainmail_helmet;
	place.equips["chain_mail"] = chain_mail;
	place.equips["leggings"] = leggings;
	place.equips["chainmail_boots"] = chainmail_boots;
	place.equips["banana"] = banana;
	place.equips["key"] = key;
	place.equips["cross"] = cross;
	place.equips["pendant"] = pendant;
	return place;
}
bool has_mark(string sentence)
//This function can determind if a sentence has marks.
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
string To_lower_2(string words)
//This function can convert the words in sentence to lower case,
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
void help(player player1)
//This function can print helping information for the player.
{
	int index;
	cout << "About battle in this game:\n" << endl;
	cout << "Once you are in a battle, you can only do either attack or run away, and quit the game."
		<< "Fight until someone dies." << endl;
	cout << "************************************************************************************************************" << endl;
	cout << "About commands in this game:\n" << endl;
	cout << "The commands in this game is made up by one or two words, normally a verb fllowed by a noun." << endl;
	cout << "You can change the keys for command by enter \"setting\"." << endl;
	cout << "Here are the keys for command:" << endl;
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
		case 29:cout << index + 1 << ". " << "To" << " pick something---" << player1.command[index] << endl; break;
		case 30:cout << index + 1 << ". " << "To" << " lie---" << player1.command[index] << endl; break;
		case 31:cout << index + 1 << ". " << "To" << " attack---" << player1.command[index] << endl; break;
		case 32:cout << index + 1 << ". " << "To" << " run away---" << player1.command[index] << endl; break;
		case 33:cout << index + 1 << ". " << "To" << " equip equipment---" << player1.command[index] << endl; break;
		case 34:cout << index + 1 << ". " << "To" << " check character`s state---" << player1.command[index] << endl; break;
		case 35:cout << index + 1 << ". " << "To" << " light the stem---" << player1.command[index] << endl; break;
		case 36:cout << index + 1 << ". " << "To" << " unequip equipment---" << player1.command[index] << endl; break;
		case 37:cout << index + 1 << ". " << "To" << " sell stuff---" << player1.command[index] << endl; break;
			break;
		}
	}
}
void welcome()
//This function can print welcome words to the player.
{
	cout << "You wake up on an island with no memory of how you got there.You need to overcome a"
		<< "series of obstacles in order to be able to to board a pirate ship and sail it to civilization." << endl;
}
void boundary(player player1, scene place)
//This function can prompt player when he get to the boundary of the map.
{
	if (player1.x == place.min_x and player1.x == place.max_x)
		cout << "You are right at the boundary, you can`t go south or north" << endl;
	else if (player1.y == place.min_y and player1.y == place.max_x)
		cout << "You are right at the boundray, you can`t go west or east" << endl;
	else if (player1.x == place.min_x and player1.y == place.max_y)
	{
		cout << "You are right at the boundary, you can`t go south or west" << endl;
	}
	else if (player1.x == place.max_x and player1.y == place.max_y)
	{
		cout << "You are right at the boundary, you can`t go north or west" << endl;
	}
	else if (player1.x == place.min_x and player1.y == place.min_y)
	{
		if (player1.location == "island")
			cout << "You are right at the boundary, you can`t go south" << endl;
		else
			cout << "You are right at the boundary, you can`t go south or east" << endl;
	}
	else if (player1.x == place.max_x and player1.y == place.min_y)
	{
		cout << "You are right at the boundary, you can`t go north or east" << endl;
	}
	else if (player1.x == place.max_x)
	{
		cout << "You are right at the boundary,you can`t go north" << endl;
	}
	else if (player1.x == place.min_x)
	{
		cout << "You are right at the boundary,you can`t go south" << endl;
	}
	else if (player1.y == place.max_y)
	{
		if (player1.location != "down")
		{
			if (player1.x != place.entrance_3_x or player1.y != place.entrance_3_y)
			{
				cout << "You are right at the boundary,you can`t go west" << endl;
			}
		}
		else if (player1.location == "down")
		{
			cout << "You right at the boundary,you can`t go west" << endl;
		}
	}
	else if (player1.y == place.min_y)
	{
		if (player1.location != "down")
		{
			if (player1.x != place.entrance_3_x or player1.y != place.entrance_3_y)
			{
				cout << "You are right at the boundary, you can`t go east" << endl;
			}
		}
		else if (player1.location == "down")
		{
			cout << "You can`t go east" << endl;
		}
	}
}
player game_time(player player1)
{
	time_t now;
	struct tm ltm;
	int hour, min, sec, time_spent = 0, pos;
	int p_hour, p_min;
	string p_time;
	if (player1.time_begin == true)
	{
		now = time(0);
		localtime_s(&ltm, &now);
		min = ltm.tm_min;
		sec = ltm.tm_sec;
		player1.start_time = min * 60 + sec;
	}
	else
	{
		now = time(0);
		localtime_s(&ltm, &now);
		min = ltm.tm_min;
		sec = ltm.tm_sec;
		player1.cur_time = min * 60 + sec;
	}
	if (player1.cur_time != 0)
		time_spent = player1.cur_time - player1.start_time;
	if (time_spent == 0 and player1.time_begin == false)
		time_spent += 1;
	if (time_spent != 0)
	{
		min = time_spent * 5;
		hour = min / 60;
		min %= 60;
		pos = player1.time.find(":");
		p_hour = stoi(player1.time.substr(0, pos++)) + hour;
		p_min = stoi(player1.time.substr(pos, player1.time.length() - pos)) + min;
		if (p_min >= 60)
		{
			p_hour += 1;
			p_min -= 60;
		}
		if (p_hour >= 24)
		{
			p_hour -= 24;
			player1.day++;
		}
		if (p_min < 10)
			p_time = to_string(p_hour) + ":0" + to_string(p_min);
		else
			p_time = to_string(p_hour) + ":" + to_string(p_min);
		player1.time = p_time;
		player1.start_time = player1.cur_time;
		player1.time_spent += time_spent;
		player1.timer += time_spent;
	}
	if (player1.time_begin == true)
		player1.time_begin = false;
	return player1;
}
void extra_info(player player1, scene place)
{
	if (player1.hide == 0 and player1.action == "move" or player1.action == "display"
		or player1.action == "save" or player1.action == "up" or player1.action == "down")
	{
		cout << "***********************************************************************************************" << endl;
		cout << "Time:" << player1.time << endl;
		cout << "Extra information: " << endl;
		location(player1, place);
		boundary(player1, place);
		cout << "(You can enter hide to hide the extra information and enter display to see the extra information again)" << endl;
		cout << "***********************************************************************************************" << endl;
	}
}
player fight(player player1, scene place)
{
	monster ghost;
	int pos, hour, min, cur_time, run;
	pos = player1.time.find(":");
	hour = stoi(player1.time.substr(0, pos++));
	min = stoi(player1.time.substr(pos, player1.time.length() - pos));
	cur_time = hour * 60 + min;
	if (cur_time >= 1080)
	{
		srand((unsigned)time(NULL));
		ghost.x = rand() % (player1.x + 1) + player1.x;
		ghost.y = rand() % (player1.y + 1) + player1.y;
		if (ghost.x == player1.x and ghost.y == player1.y)
		{
			cout << "You have encouter a ghost!" << endl;
			player1.fighting = true;
			while (ghost.health != 0 and player1.fighting == true)
			{
				player1 = take_action(player1, place);
				if (player1.action == "attack")
				{
					ghost.health -= player1.attack;
					player1.health = player1.health - (ghost.attack - player1.defence * 0.5);
					if (player1.weapon == "knife")
					{
						cout << "ultimate skill:shadow of knife!!! ";
						cout << "Enimy health minus " << player1.attack << endl;
					}
					else if (player1.weapon == "stem")
					{
						cout << "ultimate skill:stem tornado!!! ";
						cout << "Enimy health minus " << player1.attack << endl;
					}
					else if (player1.weapon == "key")
					{
						cout << "ultimate skill:key attack!!! ";
						cout << "Enimy health minus " << player1.attack << endl;
					}
					else if (player1.weapon == "banana")
					{
						cout << "ultimate skill:super banana drill!!! ";
						cout << "Enimy health minus " << player1.attack << endl;
					}
					else if (player1.weapon == "punch")
					{
						cout << "ultimate skill:punch storm!!! ";
						cout << "Enimy health minus " << player1.attack << endl;
					}
					cout << "Your health remind: " << player1.health << endl;
					cout << "Ghost health remind: " << ghost.health << endl;
					if (ghost.health <= 0)
					{
						player1.gold += 20;
						cout << "Victory!!!You have defeated the ghost!" << endl;
						cout << "Gold add 20" << endl;
						player1.fighting = false;
					}
				}
				else if (player1.action == "run away")
				{
					srand((unsigned)time(NULL));
					run = rand() % 4;
					if (run == 0)
					{
						cout << "successfully run away!" << endl;
						player1.fighting = false;
					}
					else
					{
						player1.health = player1.health - (ghost.attack - player1.defence * 0.5);
						cout << "fail to run away....health remind: " << player1.health << ". keep fighting!" << endl;
					}
				}
				if (player1.health <= 0)
				{
					cout << "Victory and defeated are the common things of men,please start over again :)" << endl;
					exit(0);
				}
			}
		}
	}
	return player1;
}
int if_has(player player1, scene place, string stuff)
{
	map<string, equipment>::iterator it;
	map<string, string>::iterator player_equip;
	int has = 0, what_is_it = 0;
	for (player_equip = player1.equipments.begin(); player_equip != player1.equipments.end(); player_equip++)
	{
		if (player_equip->second == stuff)
		{
			cout << "You already equiped " << stuff << "!!!" << endl;
			has = 2;
		}
	}
	if (has == 0)
	{
		for (it = place.equips.begin(); it != place.equips.end(); it++)
		{
			if (it->second.name == stuff)
			{
				what_is_it = 1;
				if (player1.inventory[it->second.name] != 0)
					has = 1;
			}
		}

		if (what_is_it == 0)
			has = -1;
	}
	return has;
}
void item_description(string item)
{
	if (item == "health potion")
		cout << "health potion:One health potion can restore 40 health" << endl;
	else if (item == "sword")
		cout << "sword:Add 6 attack if equiped" << endl;
	else if (item == "chainmailhelmet")
		cout << "chainmailhelmet:Add 1 defence if equiped" << endl;
	else if (item == "chain mail")
		cout << "chain mail:Add 2 defence if equiped" << endl;
	else if (item == "leggings")
		cout << "leggings:Add 1 defence if equiped" << endl;
	else if (item == "chainmail boots")
		cout << "chainmail boots:Add 1 defence if equiped" << endl;
	else if (item == "pendant")
		cout << "pendant:There will be chance to get two stems when you wear pendant" << endl;
	else if (item == "cross")
		cout << "cross:Attack will be double when attack a ghost." << endl;
}
string ask_for_objects(string actions, string objects)
{
	if (objects == "none")
	{
		cout << "--------------------------" << endl;
		cout << "What are you gonna " << actions << endl;
		cout << "--------------------------" << endl;
		getline(cin, objects);
		objects = To_lower(objects);
	}
	return objects;
}