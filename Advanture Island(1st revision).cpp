//Group2
//MingkuanPang
//Juan
//Karnvir
//Matthew Jones
//CSCI-40 group project Advanture Island game.
//use "-std=c++11" to compile"
//*******************************************************
//This is the source code for Advanture Island game     *
//In this game the player`s goal is to sail the ship    *
//in order to escape from the Island. Player has to     *
//get the stuff he needs in differen rooms and defeated *
// the final boss before he sail the ship successfully. *
//*******************************************************
#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<ctime>
#pragma warning(disable:4996)  
using namespace std;
const int COMMAND_LENGTH = 40;
class monster
{
public:
	string name;
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
	string attribute;
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
	map<string, equipment>equips;
	map<string, string>questions;
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
	int hut_x;
	int hut_y;
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
	string command[COMMAND_LENGTH] = { "north","south","west","east","board","enter","take",
		"give","search","look","eat","cut","climb","drop","up","down","unlock","sail","open",
		"quit","inventory","setting","save","load" ,"hint","help","get","hide","display",
		"pick","lie","attack","run",
		"equip","state","light","unequip","sell","use","null" };
	string oringin_command[COMMAND_LENGTH] = { "north","south","west","east","board","enter",
		"take","give","search","look","eat","cut","climb","drop","up","down","unlock","sail",
		"open","quit","inventory","setting","save","load" ,"hint","help","get","hide","display",
		"pick","lie","attack","run","equip","state","light","unequip","sell","use","null" };
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
	int shop_times = 0;
	int hut_times = 0;
	int ladder_times = 0;
	int hide = 0;
	int upper_deck_times = 0;
	int ship_times = 0;
	int get = 0;
	int up_or_down = 1;
	bool gorilla_run = false;
	bool parrot = false;
	bool hostile = true;
	bool save_prison = false;
	bool over = false;
	bool time_begin = true;
	bool fighting = false;
	bool with_light = false;
	bool answering = false;
	bool bandit = false;
	bool bandit_warning = false;
	bool battle_warning = true;
	bool quit = false;
	int cur_time = 0;
	int start_time = 0;
	int time_spent = 0;
	int day = 0;
	double gold = 0;
	int timer = 0;
	int num_item1 = 0;
	int num_item2 = 0;
	int num_item3 = 0;
	int last_question_index = 100;
	int hut_score = 0;
	int last_hut_score = 0;
	int wrong_times = 0;
	int correct_row = 0;
	int money_made = 0;
	int money_spend = 0;
	int kill = 0;
	double final_score = 500;
};
void island(player&, scene);
void upper_deck(player&, scene, bool&);
void lower_deck(player&, scene);
void load_game(player&);
void add_times(player&);
void look_hint_and_search(player&, scene);
int save_game(player);
void action_seprate(string&, string&, string);
void take_action(player&, scene);
scene set_scene(player, scene);
scene init_scene(scene);
void over(player&, scene);
void init_player(player&);
void help(player);
void welcome();
void extra_info(player, scene);
void boundary(player, scene);
void item_description(string);
void discard_stuff(player&, string);
void setting(player&);
string To_lower(string);
string To_lower_2(string);
string coordinate_to_string(player);
bool has_object(string);
bool can_get(player, scene);
bool can_cut(player, scene);
bool can_give(player, scene);
bool can_eat(player, scene);
bool can_drop(player);
bool can_pick(player);
bool carrying(player, string);
int has_equipment(player, scene, string);
int location(player, scene);
void so_bad_so_sad(player&);
string re_name(player, string);
string recover_name(string);
string pig_latin(string);
string sentence_to_pig_latin(string);
void get_sentence(string, vector<string>&, vector<string>&);
void drop_it(player&);
int get_number(string);
bool has_mark(string);
bool match(string guess, string answer);
void game_time(player&);
void fight(player&, scene, monster);
string ask_for_objects(string, string);
void data_statistics(player);
int main()
{
	bool success = false;
	player player1;
	scene place;
	string word;
	init_player(player1);
	place = init_scene(place);
	welcome();
	while (!success and !player1.quit)
	{
		place = set_scene(player1, place);
		if (place.name == "island")
<<<<<<< HEAD
		{
			island(player1, place);
		}
=======
			island(player1, place);
>>>>>>> 5978291d167b403e8110fac99db6168fb2d21983
		else if (place.name == "upper deck")
			upper_deck(player1, place, success);
		else
			lower_deck(player1, place);
		extra_info(player1, place);
	}
	if (success)
	{
		cout << "Good job!!!" << endl;
		data_statistics(player1);
		cout << "Game Over" << endl;
	}
	return 0;
}
void take_action(player & player1, scene place)
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
	string coordinate, name, origin_name;
	map<string, string>::iterator it;
	map<string, equipment>::iterator equip;
	coordinate = coordinate_to_string(player1);
	bool got_back = false;
	player1.over = false;
	player1.action = "none";
	player1.object = "none";
	if (player1.with_light and player1.timer >= 20)
	{
		cout << "---------------------" << endl;
		cout << "The torch went out." << endl;
		cout << "---------------------" << endl;
		player1.with_light = false;
		discard_stuff(player1, "stem");
		player1.timer = 0;
	}
	for (it = player1.equipments.begin(); it != player1.equipments.end(); it++)
	{
		if (it->second != "none")
		{
			if (carrying(player1, it->second) == false)
			{
				cout << "-------------------------------------" << endl;
				cout << "You currently no more equip " << it->second << endl;
				for (equip = place.equips.begin(); equip != place.equips.end(); equip++)
					if (equip->second.name == it->second)
					{
						player1.attack -= equip->second.attack;
						player1.defence -= equip->second.defence;
						player1.equipments[equip->second.attribute] = "none";
					}
				cout << "current attack is:" << player1.attack << endl;
				cout << "current defence is:" << player1.defence << endl;
				cout << "-------------------------------------" << endl;
			}
		}
	}
	for (it = player1.drop_stuff.begin(); it != player1.drop_stuff.end(); it++)
		if (coordinate == it->second and got_back == false)
		{
			origin_name = recover_name(it->first);
			cout << "You see the " << origin_name <<
				" you throwed away is lying on the ground" << endl;
			got_back = true;//Only for break the loop.
		}
	if (player1.room == "shop")
	{
		cout << "-----------------------------------------------------------------" << endl;
		cout << "Which are you going to buy?(enter the number in front of the item)" << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
	else if (player1.answering)
	{
		cout << "--------------------------" << endl;
		cout << "What are you going to answer?" << endl;
		cout << "--------------------------" << endl;
	}
	else
	{
		cout << "------------------------" << endl;
		cout << "What are you going to do?" << endl;
		cout << "------------------------" << endl;
	}
	action = getchar();
	while (action == "\n")
	{
		cout << "------------" << endl;
		cout << "Enter fail" << endl;
		cout << "------------------------" << endl;
		cout << "What are you going to do?" << endl;
		cout << "------------------------" << endl;
		action = getchar();
	}
	eat_enter = action;
	getline(cin, action);
	action = eat_enter + action;
	action = To_lower(action);
	if (!player1.fighting)
		game_time(player1);
	action_seprate(actions, objects, action);
	for (index = 0; index <= COMMAND_LENGTH - 2; index++)
		if (actions == player1.command[index])
		{
			actions = player1.oringin_command[index];
		}
	if (player1.fighting)
	{
		if (actions == "attack")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none" or objects == "ghost" and player1.fighting)
				player1.action = "attack";
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "run")
		{
			player1.object = objects;
			player1.action = actions;
			if ((objects == "away" or objects == "none") and player1.fighting)
				player1.action = "run away";
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "quit")
		{
			player1.action = "quit";
			player1.object = objects;
			if (objects == "none" or objects == "game")
				player1.quit = true;
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "use")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
			}
			if (player1.object == "health potion"
				and carrying(player1, player1.object))
			{
				player1.health += 40;
				discard_stuff(player1, objects);
				if (player1.health > 100)
					player1.health = 100;
				cout << "Health restore 40" << endl;
				cout << "current health:" << player1.health << endl;
			}
			else
				so_bad_so_sad(player1);
		}
		else
		{
			cout << "-------------------------------------------------------------------" << endl;
			cout << "You have to get out of the battle first,then you can do what you want." << endl;
			cout << "-------------------------------------------------------------------" << endl;
			player1.action = "none";
		}
	}
	else if (player1.fighting == false and player1.answering == false)
	{

		if (actions == "setting")
		{
			player1.action = actions;
			player1.object = objects;
			if (objects == "game" or objects == "none")
			{
				setting(player1);
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
				so_bad_so_sad(player1);
			}
		}
		else if (actions == "go" or action == "n" or action == "s" or
			action == "w" or action == "e" or actions == "north"
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
						cout << "Which direction you want to go?" << endl;
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
						over(player1, place);
						if (!player1.over)
						{
							player1.action = "move";
							player1.object = "north";
							if (player1.location == "up")
							{
								if (player1.x > place.entrance_4_x
									and player1.y == place.entrance_4_y
									and player1.gorilla_run != true)
								{
									cout << "-------------------------------------------" << endl;
									cout << "The gorilla is there, you can`t approach!" << endl;
									cout << "-------------------------------------------" << endl;
									player1.x -= 1;
								}
							}
							else
							{
								cout << "----------------------" << endl;
								cout << "You are going north." << endl;
								cout << "----------------------" << endl;
							}
						}
						else if (player1.over)
						{
							cout << "-------------------------" << endl;
							cout << "You go too far go back!" << endl;
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
						over(player1, place);
						if (player1.over)
						{
							cout << "-------------------------" << endl;
							cout << "You go too far go back!" << endl;
							cout << "-------------------------" << endl;
							player1.x += 1;
							player1.action = "none";
						}
						else if (!player1.over)
						{
							player1.action = "move";
							player1.object = "south";
							cout << "----------------------" << endl;
							cout << "You are going south." << endl;
							cout << "----------------------" << endl;
						}
					}
					else if ((objects == "west" and actions == "go" or action == "w")
						or (actions == "west" and objects == "none"))
					{
						player1.x_last_time = player1.x;
						player1.y_last_time = player1.y;
						player1.y += 1;
						over(player1, place);
						if (player1.location == "up"
							and player1.x == place.entrance_3_x
							and player1.y == place.entrance_3_y + 1
							and player1.hostile)
						{
							cout << "-----------------------------------------------" << endl;
							cout << "The hostile native is here, you can`t go out!" << endl;
							cout << "-----------------------------------------------" << endl;
							player1.y -= 2;
							player1.action = "none";
						}
						else if (player1.location == "up"
							and player1.x == place.entrance_3_x
							and player1.y == place.entrance_3_y)
						{
							player1.action = "move";
							player1.object = "west";
							cout << "You are going west" << endl;
						}
						else
						{
							if (player1.over)
							{
								cout << "You go too far go back!" << endl;
								player1.y -= 1;
								player1.action = "none";
							}
							else if (!player1.over)
							{
								player1.action = "move";
								player1.object = "west";
								cout << "---------------------" << endl;
								cout << "You are going west." << endl;
								cout << "---------------------" << endl;
							}
						}

					}
					else if ((objects == "east" and actions == "go" or action == "e")
						or (actions == "east" and objects == "none")
						or action == player1.command[3])
					{

						player1.x_last_time = player1.x;
						player1.y_last_time = player1.y;
						player1.y -= 1;
						over(player1, place);

						if (player1.over)
						{
							cout << "-------------------------" << endl;
							cout << "You go too far go back!" << endl;
							cout << "-------------------------" << endl;
							player1.y += 1;
							player1.action = "none";
						}
						else if (!player1.over)
						{
							player1.action = "move";
							player1.object = "east";
							cout << "---------------------" << endl;
							cout << "You are going east." << endl;
							cout << "---------------------" << endl;
						}
						else
						{
							player1.action = actions;
							player1.object = objects;
							so_bad_so_sad(player1);
						}
					}
				}
				if (objects == "up" and actions == "go"
					and (player1.room == "ladder" or player1.up_or_down == 0))
				{
					player1.action = "up";
				}
				else if (objects == "down"
					and actions == "go"
					and (player1.room == "ladder" or player1.up_or_down == 1))
				{
					player1.action = "down";
				}
			}
			else
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "You can`t move until you run away or defeat the ghost!" << endl;
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
				look_hint_and_search(player1, place);
			}
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "search")
		{
			player1.action = "search";
			look_hint_and_search(player1, place);
			player1.object = objects;
		}
		else if (actions == "fight")
		{
			player1.action = "fight";
			player1.object = objects;
			if (objects == "none")
				player1.action = "fight";
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "take")
		{
			if (objects == "bananas")
				objects = "banana";
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				if (objects == "bananas")
					objects = "banana";
				player1.object = objects;
				if (can_get(player1, place))
					player1.action = "get";
			}

			else if (objects == "it")
			{
				player1.action = "get";
			}
			else if (can_get(player1, place))
			{
				player1.action = "get";
				player1.object = objects;
			}
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "enter")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
				player1.action = "enter";
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "use")
		{
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
			}
			if (player1.object == "health potion"
				and carrying(player1, player1.object))
			{
				player1.health += 40;
				discard_stuff(player1, objects);
				if (player1.health > 100)
					player1.health = 100;
				cout << "Health restore 40" << endl;
				cout << "current health:" << player1.health << endl;
			}
			else
				so_bad_so_sad(player1);
		}

		else if (actions == "eat")
		{
			player1.object = objects;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
			}
			if (can_eat(player1, place) and carrying(player1, objects))
			{
				player1.action = "eat";
				player1.object = objects;
				discard_stuff(player1, objects);
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
				so_bad_so_sad(player1);

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
				so_bad_so_sad(player1);
		}
		else if (actions == "hint")
		{
			player1.action = "hint";
			player1.object = objects;
			if (objects == "none")
				look_hint_and_search(player1, place);
			else
				so_bad_so_sad(player1);
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
				so_bad_so_sad(player1);
		}
		else if (actions == "load")
		{
			player1.action = "load";
			player1.object = objects;
			if (objects == "game" or objects == "none")
			{
				load_game(player1);
				player1.in_n_out = 0;
				load = true;
			}
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "cut")
		{
			if (!carrying(player1, "knife"))
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
				if (objects == "bananas")
					objects = "banana";
				if (can_cut(player1, place))
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
				if (objects == "bananas")
					objects = "banana";
				if (can_cut(player1, place))
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
				so_bad_so_sad(player1);
			}
		}
		else if (actions == "quit")
		{
			player1.action = "quit";
			player1.object = objects;
			if (objects == "none" or objects == "game")
				exit(0);
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "get")
		{
			if (objects == "bananas")
				objects = "banana";
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
					if (objects == "bananas")
						objects = "banana";
					if (can_get(player1, place))
					{
						player1.action = "get";
					}
				}
				else if (objects == "it")
				{
					player1.action = actions;
					player1.object = objects;
				}
				else if (can_get(player1, place))
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
				if (can_give(player1, place))
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
				if (can_give(player1, place))
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
				so_bad_so_sad(player1);
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
				so_bad_so_sad(player1);
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
				if (can_drop(player1))
				{
					player1.object = objects;
					drop_it(player1);
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
				if (can_drop(player1))
				{
					drop_it(player1);
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
				if (can_pick(player1))
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
				if (can_pick(player1))
				{
					player1.action = "pick";
				}
				else
				{
					player1.action = "none";
					player1.object = "none";
				}
			}
			if (player1.action == "pick")
			{
				it = player1.drop_stuff.begin();
				got_back = false;
				while (got_back != true and it != player1.drop_stuff.end())
				{
					if (coordinate == it->second)
					{
						origin_name = recover_name(it->first);
						name = it->first;
						cout << "--------------------------" << endl;
						cout << "You got the " << origin_name << " back!" << endl;
						cout << "--------------------------" << endl;
						player1.inventory[origin_name]++;
						player1.drop_stuff.erase(name);
						got_back = true;//Only for break the loop.
					}
					else
						it++;
				}
			}
		}
		else if (actions == "up" or action == "u" or actions == "climb")
		{
			player1.object = objects;
			player1.action = "up";
			if (objects == "none" and (player1.room == "ladder" or player1.room == "brig"))
			{
				if (player1.location == "up")
				{
					cout << "You can`t go up anymore!" << endl;
					player1.action = "none";
				}
				else
					player1.action = "up";
			}
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "down" or action == "d")
		{
			player1.object = objects;
			player1.action = "down";
			if (objects == "none" and (player1.room == "ladder" and player1.up_or_down == 1))
			{
				player1.action = "down";
			}
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "open")
		{
			if (objects == "cell")
				objects = "door";
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
			}
			if (!carrying(player1, "key") and player1.action == "open")
			{
				cout << "---------------------------" << endl;
				cout << "You can`t open "<<objects<<" for now!" << endl;
				cout << "---------------------------" << endl;
			}
			else if ((objects == "brig" or objects == "door") and player1.room == "brig")
				player1.action = "unlock";
			else if (objects != "none" and player1.room == "brig")
			{
				cout << "---------------------------------------" << endl;
				cout << "This is door not a " << objects << endl;
				cout << "---------------------------------------" << endl;
			}
			else if (player1.room == "cargo hold" and player1.object == "trunk")
			{
				if (player1.treasure_amount == 1)
				{
					cout << "----------------------------------------" << endl;
					cout << "You found the treasure in the trunk!!!" << endl;
					cout << "----------------------------------------" << endl;
					player1.get = 1;
				}
				else
					cout << "You have opened the trunk, it is empty!!!" << endl;
			}
		}
		else if (actions == "unlock")
		{
			if (objects == "cell" or objects == "brig")
				objects = "door";
			player1.object = objects;
			player1.action = actions;
			if (objects == "none")
			{
				objects = ask_for_objects(actions, objects);
				player1.object = objects;
			}
			if (!carrying(player1, "key") and player1.action == "unlock")
			{
				cout << "---------------------------" << endl;
				cout << "You need a key to unlock!" << endl;
				cout << "---------------------------" << endl;
			}
			else if ((objects == "brig" or objects == "door") and player1.room == "brig")
				player1.action = "unlock";
			else if (objects != "none" and player1.room == "brig")
			{
				cout << "---------------------------------------" << endl;
				cout << "This is door not a " << objects << endl;
				cout << "---------------------------------------" << endl;
			}
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "lie")
		{
			player1.object = objects;
			player1.action = actions;
			if ((objects == "none" or objects == "on bed" or objects == "on the bed")
				and player1.location == "up" and player1.x == place.bed_x)
				player1.action = "lie";
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "attack")
		{
			cout << "--------------------------------------------------" << endl;
			cout << "You can only attack when you are in the battle" << endl;
			cout << "--------------------------------------------------" << endl;
			player1.action = "none";
		}
		else if (actions == "run")
		{
			player1.action = actions;
			player1.object = objects;
			if (objects == "away" or objects == "none")
			{
				cout << "--------------------------------------------------" << endl;
				cout << "You can only run away when you are in the battle" << endl;
				cout << "--------------------------------------------------" << endl;
				player1.action = "none";
			}
			else
				so_bad_so_sad(player1);
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
<<<<<<< HEAD
				enum stuff { have_stuff = 1, not_have_stuff = 0,stuff_not_in_the_game=-1 };
				has = has_equipment(player1, place, objects);
				if (has == have_stuff)
=======
				has = has_equipment(player1, place, objects);
				if (has == 1)
>>>>>>> 5978291d167b403e8110fac99db6168fb2d21983
				{
					map<string, equipment>::iterator it;
					for (it = place.equips.begin(); it != place.equips.end(); it++)
						if (it->second.name == objects)
						{
							if (player1.equipments[it->second.attribute] == "none")
							{
								player1.attack += it->second.attack;
								player1.defence += it->second.defence;
								player1.equipments[it->second.attribute] = it->second.name;
								if (it->second.attribute == "weapon")
									player1.weapon = it->second.name;
								cout << "-----------------------------------------" << endl;
								cout << objects << " equiped!" << endl;
								cout << "Current attack is: " << player1.attack << endl;
								cout << "Current defence is: " << player1.defence << endl;
								cout << "-----------------------------------------" << endl;
							}
							else
								cout << "You have to unequip " << player1.equipments[it->second.attribute]
								<< " first!" << endl;
						}
				}
				else if (has == not_have_stuff)
				{
					cout << "-------------------------------------------------------" << endl;
					cout << "You have to get " << objects << " before you equip it!" << endl;
					cout << "-------------------------------------------------------" << endl;
				}
				else if (has ==stuff_not_in_the_game)
				{
					cout << "-------------------------------------------------------" << endl;
					cout << "" << objects << " equiped!" << " wait....what is "
						<< objects << "?" << endl;
					cout << "-------------------------------------------------------" << endl;
				}
			}
			else
			{
				player1.object = objects;
				so_bad_so_sad(player1);
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
				so_bad_so_sad(player1);
		}
		else if (actions == "light")
		{
			if (objects == "none" or objects == "stem")
			{
				if (player1.with_light == false)
				{
<<<<<<< HEAD
					if (carrying(player1, "stem"))
					{
						cout << "-----------------------------------------------------------------------" << endl;
						cout << "You`ve light the stem,a faint glow of"
							<< " fire gave off a trace of warmth." << endl;
						cout << "-----------------------------------------------------------------------" << endl;
						player1.with_light = true;
						player1.timer = 0;
					}
					else
					{
						cout << "The first step of lighting a stem is: get a stem." << endl;
					}
=======
					cout << "-----------------------------------------------------------------------" << endl;
					cout << "You`ve light the stem,a faint glow of"
						<< " fire gave off a trace of warmth." << endl;
					cout << "-----------------------------------------------------------------------" << endl;
					player1.with_light = true;
					player1.timer = 0;
>>>>>>> 5978291d167b403e8110fac99db6168fb2d21983
				}
				else
				{
					cout << "------------------------------------" << endl;
					cout << "You are already holding the torch!" << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else
				so_bad_so_sad(player1);
		}
		else if (actions == "unequip")
		{
			map<string, string>::iterator it;
			map<string, equipment>::iterator equip;
			bool wearing = false;
			if (objects == "none")
			{
				cout << "What are you going to unequip?" << endl;
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
				if (!carrying(player1, objects))
				{
					cout << "---------------------------------------" << endl;
					cout << "You don`t have " << objects << " !!!" << endl;
					cout << "---------------------------------------" << endl;
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
					discard_stuff(player1, objects);
					cout << "---------------------------------------" << endl;
					cout << "You sold the " << objects << " to the shop!" << endl;
					cout << "---------------------------------------" << endl;
				}
			}
		}
		else if (actions == "sell")
		{
			cout << "You can only sell in the shop!" << endl;
		}
		else if (actions == "yes" and objects == "none" and player1.room == "hut")
			player1.action = "yes";
		else if (actions == "no" and objects == "none" and player1.room == "hut")
			player1.action = "no";
		else
		{
			cout << "------------------------" << endl;
			cout << "You can`t do that bro!" << endl;
			cout << "------------------------" << endl;
		}
	}
	if (player1.answering)
	{
		if (actions == "leave" and objects == "none")
			player1.action = "leave";
		else
		{
			if (objects == "none")
				player1.action = actions;
			else
			{
				actions = actions.append(" ");
				player1.action = actions + objects;
			}
		}
	}
}
void over(player & player1, scene place)
//This function can determind if the player is over the boundaries of the map.
{

	if (player1.x < place.min_x)
	{
		if (player1.location == "island" and player1.x == 3
			and player1.y == -3 and player1.hostile == false)
		{
			player1.over = false;
		}
		else
			player1.over = true;
	}
	else if (player1.x > place.max_x)

	{
		if (player1.location == "up")
		{
			if (player1.x == place.entrance_4_x + 1 and
				player1.y == place.entrance_4_y and player1.gorilla_run == false)
				player1.over = false;
			else
				player1.over = true;
		}
		else if (player1.location == "island" and player1.x == 5
			and player1.y == -3 and player1.hostile == false)
			player1.over = false;
		else
			player1.over = true;
	}
	else if (player1.y > place.max_y)
	{
		if (player1.location == "up" and player1.x == place.entrance_3_x
			and (player1.y == place.entrance_3_y or player1.y == place.entrance_3_y + 1))
			player1.over = false;
		else
			player1.over = true;

	}
	else if (player1.y < place.min_y)
	{
		if (player1.location == "island" and player1.x == place.entrance_3_x
			and player1.y == place.entrance_3_y - 1)
			player1.over = false;
		else
			player1.over = true;
	}
}
scene set_scene(player player1, scene place)//This function can set up the map according to the coordinate of the player.
{
	if (player1.y >= -4)
	{
		place.name = "island";
		place.long_description = "You are in a island.The island isforested with banana trees. Most of the bananas are green, but one tree to your west might have ripe bananas.\nThere are ominous drums in the background.There is a ship to your east with a gangplank to the shore.\nEnter \"help\" for help";
		place.short_description = "You are currently in the island, there are so many banana trees!";
		place.stuff_can_cut_name = "tree";
		place.entrance_3_name = "gangplank";
		place.stuff_can_cut_description = "You are standing in front of a ripe banana tree, you can take a look to see what is on the tree.\nstuff you can get:banana.";
		place.entrance_3_description = "You are at the gangplank! You can enter the ship.";
		place.stuff_can_cut_look_description_1 = "There is one branch of repe bananas on the tree that you can reach.";
		place.stuff_can_cut_look_description_2 = "There is nothing on the tree....";
		place.stuff_can_cut_description_2 = "You are standing in front of a ripe banana tree! But....there is nothing on the tree you can reach....";
		place.shop_long_description = "You`ve enter the native`s shop.They have many different amazing stuff for sell\nThese items in this shop will updated in a period time.";
		place.shop_short_description = "You`ve enter the native`s shop";
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
		place.hut_x = 5;
		place.hut_y = -3;
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
		place.entrance_1_description = "You are in the captain`s quarters. There is a bed and a table in this room.\nstuff you can get: knife";
		place.entrance_1_description_after_got = "You are in the captain`s quarters. There is a bed and a table in this room.";
		place.entrance_1_description_2 = "You are in the captain`s quarters. There is a bed and a table in this room.\nstuff you can get: key";
		place.entrance_1_description_3 = "You are in the captain`s quarters. There is a bed and a table in this room.\nstuff you can get: key,knife";
		place.entrance_1_description_after_got_2 = "You are in the captain`s quarters. There is a bed and a table in this room.";
		place.entrance_1_short_description = "You are in the captsin`s quarters.\nstuff you can get: knife";
		place.entrance_1_short_description_2 = "You are in the captsin`s quarters.\nstuff you can get: knife,key";
		place.entrance_1_short_description_3 = "You are in the captsin`s quarters.\nstuff you can get: key";
		place.entrance_1_short_description_after_got = "You are in the captain`s quarters";
		place.entrance_2_description = "There is a ladder, you can go down";
		place.entrance_4_description = "You are at edge of the ship`s wheel.There is a large gorilla by the ship`s wheel. The gorilla is hostile. You can`t approach the wheel.\n";
		place.entrance_4_short_description = "You are at the wheel.";
		place.entrance_3_description = "You are at the gangplank! You can leave the ship";
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
		place.entrance_1_description = "You`ve entered the cargo hold. There are barrels, a pile of tools, and a trunk.\nYou are standing in front of a trunk.";
		place.entrance_1_short_description = "You`ve entered the cargo hold. You are standing in front of a trunk";
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

void init_player(player & player1)//This function can initialize the inventory of the player.
									 //Usually the amounts of the stuff that player carrying are all zeros.
{

	player1.equipments["weapon"] = "none";
	player1.equipments["head"] = "none";
	player1.equipments["body"] = "none";
	player1.equipments["legs"] = "none";
	player1.equipments["feet"] = "none";
	player1.equipments["trinket"] = "none";
}
void setting(player & player1)//This function can let the player set up the command keys in the game to what they want.
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
		case 0:cout << index + 1 << ". " << "Go " << "north---" << player1.command[index] << endl;
			break;
		case 1:cout << index + 1 << ". " << "Go " << "south---" << player1.command[index] << endl;
			break;
		case 2:cout << index + 1 << ". " << "Go " << "west---" << player1.command[index] << endl;
			break;
		case 3:cout << index + 1 << ". " << "Go " << "east---" << player1.command[index] << endl;
			break;
		case 4:cout << index + 1 << ". " << "To " << "board---" << player1.command[index] << endl;
			break;
		case 5:cout << index + 1 << ". " << "To " << "enter---" << player1.command[index] << endl;
			break;
		case 6:cout << index + 1 << ". " << "To " << "take---" << player1.command[index] << endl;
			break;
		case 7:cout << index + 1 << ". " << "To " << "give---" << player1.command[index] << endl;
			break;
		case 8:cout << index + 1 << ". " << "To " << "search---" << player1.command[index] << endl;
			break;
		case 9:cout << index + 1 << ". " << "To " << "look---" << player1.command[index] << endl;
			break;
		case 10:cout << index + 1 << ". " << "To " << "eat---" << player1.command[index] << endl;
			break;
		case 11:cout << index + 1 << ". " << "To " << "cut---" << player1.command[index] << endl;
			break;
		case 12:cout << index + 1 << ". " << "To " << "climb---" << player1.command[index] << endl;
			break;
		case 13:cout << index + 1 << ". " << "To " << "drop---" << player1.command[index] << endl;
			break;
		case 14:cout << index + 1 << ". " << "Go " << "up---" << player1.command[index] << endl;
			break;
		case 15:cout << index + 1 << ". " << "Go " << "down---" << player1.command[index] << endl;
			break;
		case 16:cout << index + 1 << ". " << "To " << "unlock---" << player1.command[index] << endl;
			break;
		case 17:cout << index + 1 << ". " << "To " << "sail---" << player1.command[index] << endl;
			break;
		case 18:cout << index + 1 << ". " << "To " << "open---" << player1.command[index] << endl;
			break;
		case 19:cout << index + 1 << ". " << "To " << "quit---" << player1.command[index] << endl;
			break;
		case 20:cout << index + 1 << ". " << "Check " << "inventory---" << player1.command[index]
			<< endl; break;
		case 21:cout << index + 1 << ". " << "To " << "setting---" << player1.command[index]
			<< endl; break;
		case 22:cout << index + 1 << ". " << "To " << "save---" << player1.command[index] << endl;
			break;
		case 23:cout << index + 1 << ". " << "To " << "load--" << player1.command[index] << endl;
			break;
		case 24:cout << index + 1 << ". " << "To see " << "hint---" << player1.command[index]
			<< endl; break;
		case 25:cout << index + 1 << ". " << "To see " << "help---" << player1.command[index]
			<< endl; break;
		case 26:cout << index + 1 << ". " << "To" << " get something---" << player1.command[index]
			<< endl; break;
		case 27:cout << index + 1 << ". " << "To" << " hide extra information---" <<
			player1.command[index] << endl; break;
		case 28:cout << index + 1 << ". " << "To" << " display extra information---"
			<< player1.command[index] << endl; break;
		case 29:cout << index + 1 << ". " << "To" << " pick something---"
			<< player1.command[index] << endl; break;
		case 30:cout << index + 1 << ". " << "To" << " lie---"
			<< player1.command[index] << endl; break;
		case 31:cout << index + 1 << ". " << "To" << " attack---"
			<< player1.command[index] << endl; break;
		case 32:cout << index + 1 << ". " << "To" << " run away---"
			<< player1.command[index] << endl; break;
		case 33:cout << index + 1 << ". " << "To" << " equip equipment---"
			<< player1.command[index] << endl; break;
		case 34:cout << index + 1 << ". " << "To" << " check character`s state---"
			<< player1.command[index] << endl; break;
		case 35:cout << index + 1 << ". " << "To" << " light the stem---"
			<< player1.command[index] << endl; break;
		case 36:cout << index + 1 << ". " << "To" << " unequip equipment---"
			<< player1.command[index] << endl; break;
		case 37:cout << index + 1 << ". " << "To" << " sell stuff---"
			<< player1.command[index] << endl; break;
		case 38:cout << index + 1 << ". " << "To" << " use stuff---"
			<< player1.command[index] << endl; break;
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
		cout << "done!" << endl;
		cout << "-------" << endl;
	}
	else
	{
		player1.action = "setting fail";
		player1.set = 0;
	}
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
		game_file << "queston_index:" << endl;
		game_file << player1.last_question_index << endl;
		game_file << "hut_score:" << endl;
		game_file << player1.last_hut_score << endl;
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
		game_file << player1.gorilla_run << endl;
		game_file << "player1_get:" << endl;
		game_file << player1.get << endl;
		game_file << "bandit" << endl;
		game_file << player1.bandit << endl;
		game_file << "bandit_warning:" << endl;
		game_file << player1.bandit_warning << endl;
		game_file << "prison:" << endl;
		game_file << player1.save_prison << endl;
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
		game_file << "player_ship_times:" << endl;
		game_file << player1.ship_times << endl;
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
		game_file << "player_hut_times:" << endl;
		game_file << player1.hut_times << endl;
		game_file << "player_ladder_times:" << endl;
		game_file << player1.ladder_times << endl;
		game_file << "item1" << endl;
		game_file << player1.num_item1 << endl;
		game_file << "item2" << endl;
		game_file << player1.num_item2 << endl;
		game_file << "item3" << endl;
		game_file << player1.num_item3 << endl;
		game_file << "money_made:" << endl;
		game_file << player1.money_made << endl;
		game_file << "money_spend:" << endl;
		game_file << player1.money_spend << endl;
		game_file << "kill:" << endl;
		game_file << player1.kill << endl;
		game_file << "hide: " << endl;
		game_file << player1.hide << endl;
		game_file << "final_score:" << endl;
		game_file << player1.final_score << endl;
		game_file << "setting:" << endl;
		for (index = 0; index <= COMMAND_LENGTH - 1; index++)
			game_file << player1.command[index] << endl;
		game_file << "drop_stuff:" << endl;
		for (drop_stuff = player1.drop_stuff.begin();
			drop_stuff != player1.drop_stuff.end(); drop_stuff++)
		{
			game_file << drop_stuff->first << endl;
			game_file << drop_stuff->second << endl;
		}
		game_file << "ending";
		game_file.close();
	}
	return success;
}
void load_game(player & player1)//This function can load the game from a file.
{
	ifstream game_file;
	map<string, string>::iterator equip;
	map<string, string>::iterator it;
	string loaction, inventory, banana_amount, knife_amount, player_location,
		player_x_last_time, setting, hide, drop_stuff, coordinate;
	string plaer_y_last_time, player_island_times, player_upper_deck_times,
		player_capitains_quarters_times, player_lower_deck_times;
	string player_cargo_hold_times, player_brig_times, player_galley_times, treasure_amount;
	string gorilla, parrot, hostile, key, prison, get, up_or_down, health, attack, money, time, day;
	string time_spent, fighting, weapon, gold, gangplank, light, shop, hut, item1, item2, item3;
	string  defence, temp = " ", inventory_name, hut_score, question, ship, bandit, warning;
	string made, spend, kill, ladder, final_score;
	int index, inventory_quantity;
	size_t pos;
	player1.drop_stuff.erase(player1.drop_stuff.begin(), player1.drop_stuff.end());
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
		game_file >> question;
		game_file >> player1.last_question_index;
		game_file >> hut_score;
		game_file >> player1.last_hut_score;
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
		game_file >> player1.gorilla_run;
		game_file >> get;
		game_file >> player1.get;
		game_file >> bandit;
		game_file >> player1.bandit;
		game_file >> warning;
		game_file >> player1.bandit_warning;
		game_file >> prison;
		game_file >> player1.save_prison;
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
		game_file >> ship;
		game_file >> player1.ship_times;
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
		game_file >> hut;
		game_file >> player1.hut_times;
		game_file >> ladder;
		game_file >> player1.ladder_times;
		game_file >> item1;
		game_file >> player1.num_item1;
		game_file >> item2;
		game_file >> player1.num_item2;
		game_file >> item3;
		game_file >> player1.num_item3;
		game_file >> made;
		game_file >> player1.money_made;
		game_file >> spend;
		game_file >> player1.money_spend;
		game_file >> kill;
		game_file >> player1.kill;
		game_file >> hide;
		game_file >> player1.hide;
		game_file >> final_score;
		game_file >> player1.final_score;
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
			if (drop_stuff != "ending")
			{
				getline(game_file, coordinate);
				player1.drop_stuff[drop_stuff] = coordinate;
			}
		}
		cout << "------------------------" << endl;
		cout << "Load game successfully" << endl;
		cout << "------------------------" << endl;
	}

	player1.load = 1;
	game_file.close();
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
int location(player player1, scene place)
//This function can determind if the player is getting closer or away
// to a room in the game.
{
	int close = 0;
	if (player1.location == "island")
	{
		if (player1.x == place.stuff_can_cut_x and player1.y == place.stuff_can_cut_y)
			cout << "You currently at ripe banana tree." << endl;
		else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
			cout << "You currently at gangplank." << endl;
		else if (player1.x == place.shop_x and player1.y == place.shop_y)
			cout << "You currently at native`s shop." << endl;
		else if (player1.x == place.hut_x and player1.y == place.hut_y)
			cout << "You currently at mysterious hut." << endl;
		else
			cout << "You currently at island." << endl;

	}
	else if (player1.location == "up")
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
	else if (player1.location == "down")
	{
		enum position{up=1,down=0};
		if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
			cout << "You currently in front of the trunk in cargo hold." << endl;
		else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
		{
			if (player1.up_or_down == up)
				cout << "You are currently at ladder." << endl;
			else
				cout << "You are currently at brig" << endl;
		}
		else if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
			cout << "You are currently at galley" << endl;
		else
			cout << "You are currently ar lower deck." << endl;

		if (player1.x == place.entrance_4_x and player1.y == place.entrance_4_y)
			cout << "You are currently at the brig" << endl;
	}
	return 0;
}
void island(player & player1, scene place)//This function can set up the map "island" in the game.
{
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
		take_action(player1, place);
		if (player1.action == "get" or player1.action == "cut")
		{
			if (player1.banana_amount != 0)
			{
				if (carrying(player1, "knife"))
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
		take_action(player1, place);
		if (player1.action == "enter" or player1.action == "move" and player1.object == "east")
		{
			player1.location = "up";
			player1.x = 3;
			player1.y = -10;
		}
	}
	else if (player1.x == place.shop_x and player1.y == place.shop_y and player1.hostile == false)
	{
		int  index = 0, item_num = 1;
		string item1, item2, item3;
		vector<string>item_names;
		map<string, int>::iterator item = place.items.begin();
		player1.room = "shop";
		add_times(player1);
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
			while (player1.num_item3 == player1.num_item1
				or player1.num_item3 == player1.num_item2)
				player1.num_item3 = rand() % (place.items.size());
			cout << place.shop_short_description << endl;
			player1.in_n_out = 1;
		}
		cout << "Here are the items for this time!" << endl;
		while (item != place.items.end())
		{
			if (index == player1.num_item1
				or index == player1.num_item2 or index == player1.num_item3)
			{
				cout << item_num << "." << item->first << "-------" << item->second << endl;
				item_description(item->first);
				item_names.push_back(item->first);
				item_num++;
			}
			item++;
			index++;
		}
		take_action(player1, place);
		if (player1.action >= "1" and player1.action <= "3")
		{
			item_num = stoi(player1.action) - 1;
			if (player1.gold >= place.items[item_names[item_num]])
			{
				cout << "Got " << item_names[item_num] << "!!!" << endl;
				player1.gold -= place.items[item_names[item_num]];
				player1.money_spend += place.items[item_names[item_num]];
				player1.inventory[item_names[item_num]]++;
			}
			else
			{
				cout << "---------------------" << endl;
				cout << "You need more money" << endl;
				cout << "---------------------" << endl;
			}
		}
	}
	else if (player1.x == place.hut_x and player1.y == place.hut_y and player1.hostile == false)
	{
		player1.room = "hut";
		add_times(player1);
		int question_index, index = 0;
		bool repeat = false;
		string bootlick = "";
		map<string, string>::iterator question = place.questions.begin();
		vector<int>index_for_questions_asked;
		vector<int>::iterator it;
		if (player1.in_n_out == 0 and player1.hut_times == 1)
		{
			cout << "The owner of this hut is an old man who is the most intelligent person" <<
				"in these native people.\n" <<
				"He has been looking for a warrior who is as wise as him.\n" <<
				"If you can answer his questions correctly and get his appreciation,"
				<< " he will give you a generous reward.\n" <<
				"Do you want to accept his challenge?" << endl;
			player1.in_n_out = 1;
		}
		else if (player1.in_n_out == 0 and player1.hut_times > 1)
		{
			cout << "You have entered the mysterious hut." << endl;
			if (player1.last_hut_score <= 1)
				cout << "Do you want to accept the challenge?" << endl;
			else
				cout << "I remember you got " << player1.last_hut_score
				<< " questions last time, that was awesome!" <<
				"Do you want to try again?" << endl;
			player1.in_n_out = 1;
		}
		if (player1.answering == false)
			take_action(player1, place);
		if (player1.action == "yes" and player1.answering == false)
			player1.answering = true;
		else if (player1.action == "no" and player1.answering == false)
		{
			cout << "\"Ok...go to do what you want to do...\" the wise old man walked away disappointed." << endl;
			cout << "\"But....I will be back if you answer yes!:)\" he suddenly turn his head back and says." << endl;
		}
		if (player1.answering)
		{
			srand((unsigned)time(NULL));
			question_index = rand() % 99;
			for (it = index_for_questions_asked.begin(); it != index_for_questions_asked.end(); it++)
				if (*it == question_index)
					repeat = true;
			while ((question_index == player1.last_question_index) and repeat)
			{
				srand((unsigned)time(NULL));
				question_index = rand() % 99;
			}
			index_for_questions_asked.push_back(question_index);
			player1.last_question_index = question_index;
			while (question != place.questions.end() and index != question_index)
			{

				index++;
				question++;

			}

			cout << question->first << "(Enter \"leave\" to leave)" << endl;
			take_action(player1, place);
			if (player1.action == "leave")
			{
				cout << "Challenge over. You score this time is: " << player1.hut_score << endl;
				cout << "Do you want to try again?" << endl;
				player1.last_hut_score = player1.hut_score;
				player1.hut_score = 0;
				player1.correct_row = 0;
				player1.wrong_times = 0;
				player1.answering = false;
			}
			else
			{
				if (match(player1.action, question->second))
				{
					player1.hut_score++;
					player1.correct_row++;
					player1.final_score += 1;
					if (player1.correct_row == 3)
						bootlick = "You are excellent!";
					else if (player1.correct_row == 6)
						bootlick = "You are domanating!";
					else if (player1.correct_row == 9)
						bootlick = "You are unstoppable!";
					else if (player1.correct_row == 12)
						bootlick = "You are wicked sick!";
					else if (player1.correct_row == 20)
						bootlick = "You are legendary!";
					else if (player1.correct_row >= 35)
						bootlick = "I believe you are the most smartest man that I have seen!";
					cout << "Correct!!! " << bootlick << endl;
					if (player1.hut_score == 6)
					{
						cout << "Good job! The wise old man decide" <<
							" to give you 80 golds!" << endl;
						player1.gold += 80;
						player1.money_made += 80;
					}
					else if (player1.hut_score == 15)
					{
						cout << "Good job! The wise old man decide" <<
							" to give you ten stems!" << endl;
						player1.inventory["health posion"] += 10;
					}
					else if (player1.hut_score == 20)
					{
						cout << "Good job! The The wise old man decide" <<
							" to give you a pendent!" << endl;
						player1.inventory["pendent"]++;
					}
					else if (player1.hut_score == 25)
					{
						cout << "Good job! The wise old man decide" <<
							" to give you a chainmail helmet!" << endl;
						player1.inventory["chainmail helmet"]++;
					}
					else if (player1.hut_score == 30)
					{
						cout << "Good job! The wise old man decide" <<
							" to give you a sword!" << endl;
						player1.inventory["sword"]++;
					}
					else if (player1.hut_score == 35)
					{
						cout << "Good job! The wise old man decide" <<
							" to give you a pair of leggings!" << endl;
						player1.inventory["leggings"]++;
					}
					else if (player1.hut_score == 40)
					{
						cout << "Good job! The wise old man decide" <<
							" to give you a pair of chainmail boots!" << endl;
						player1.inventory["chainmail boots"]++;
					}
					else if (player1.hut_score == 50)
					{
						cout << "Good job! The wise old man decide"
							<< " to give you a chain mail!" << endl;
						player1.inventory["chain mail"]++;
					}
					else if (player1.hut_score == 65)
					{
						cout << "Good job! The wise old man decide" <<
							" to give you a cross!" << endl;
						player1.inventory["cross"]++;
					}
				}
				else
				{
					cout << "wrong answer" << endl;
					cout << "The correct answer is: " << question->second << endl;
					player1.wrong_times++;
					if (player1.wrong_times == 3)
					{
						cout << "Challenge over. You score this time is: "
							<< player1.hut_score << endl;
						player1.last_hut_score = player1.hut_score;
						player1.hut_score = 0;
						player1.correct_row = 0;
						player1.wrong_times = 0;
						player1.answering = false;
						player1.in_n_out = 0;
					}
				}
			}
		}
	}
	else
	{
		player1.room = "island";
		add_times(player1);
		if (player1.island_times == 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.long_description << endl;
		}
		else if (player1.island_times > 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			cout << place.short_description << endl;
			if (player1.hostile == false)
				cout << "The natives establish a shop and a mysterious hut\n" <<
				"The shop is on the south of island and the hut is on the north of island." << endl;
		}
		take_action(player1, place);
	}
}
void upper_deck(player & player1, scene place, bool& success)
//This function can set up the map "upper deck" in the game.
{
	vector<string> give;
	int pos, hour, min, cur_time;
	monster ghost;
	pos = player1.time.find(":");
	hour = stoi(player1.time.substr(0, pos++));
	min = stoi(player1.time.substr(pos, player1.time.length() - pos));
	cur_time = hour * 60 + min;
	if (cur_time >= 1080 or cur_time <= 360)
	{
		if (!player1.with_light)
		{
			srand((unsigned)time(NULL));
			ghost.x = rand() % 3 + player1.x;
<<<<<<< HEAD
			ghost.y =player1.y;
=======
			ghost.y = rand() % 2 + player1.y;
>>>>>>> 5978291d167b403e8110fac99db6168fb2d21983
			if (ghost.x == player1.x and ghost.y == player1.y)
			{
				cout << "You have encouter a ghost!" << endl;
				ghost.name = "ghost";
				fight(player1, place, ghost);
			}
		}
	}
	if (player1.x <= place.entrance_1_x and player1.y == place.entrance_1_y)
	{
		player1.room = "captain`s quarters";
		add_times(player1);
		if (player1.captain_quarters_times == 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			if (player1.parrot == false)
				cout << place.entrance_1_description << endl;
			else
				cout << place.entrance_1_description_3 << endl;
		}
		else if (player1.captain_quarters_times > 1 and player1.in_n_out == 0)
		{
			player1.in_n_out = 1;
			if (player1.parrot == false)
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
			cout << "You see a soft comfortable bed in front of you," <<
				" you can lying on the bed to restore your health." << endl;
			take_action(player1, place);

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
			if (player1.parrot == false)
			{
				if (player1.knife_amount != 0)
				{
					cout << "You see there is a shinning knife on the table!" << endl;
					take_action(player1, place);
					if (player1.action == "get" and player1.object == "knife")
					{
						player1.knife_amount -= 1;
						player1.inventory["knife"] ++;
						place.stuff_can_get.erase("knife");
						cout << place.stuff_1_get_info << endl;
						take_action(player1, place);
					}
				}
				else
				{
					cout << "You are standing in front of a table." << endl;
					take_action(player1, place);
				}
			}
			else if (player1.parrot and player1.key_amount != 0)
			{
				if (player1.knife_amount == 0)
				{
					cout << "You are standing in front of a table," <<
						" and you see the key is under the table!" << endl;
					take_action(player1, place);
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
					cout << "You are standing in front of a table, " <<
						"and you see the knife is on the table and key is under the table!" << endl;
					take_action(player1, place);
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
			else if (player1.parrot and player1.key_amount == 0)
			{

				if (player1.knife_amount != 0)
				{
					cout << "You see there is a shinning knife on the table!" << endl;
					take_action(player1, place);
					if (player1.action == "get" and player1.object == "knife")
					{
						player1.knife_amount -= 1;
						player1.inventory["knife"] ++;
						place.stuff_can_get.erase("knife");
						cout << place.stuff_1_get_info << endl;
						take_action(player1, place);
					}
				}
				else
				{
					cout << "You are standing in front of a table." << endl;
					take_action(player1, place);
				}
			}
		}
	}
	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		player1.room = "ladder";
		player1.ladder_times++;
		if (player1.last_room != "ship`s wheel" 
			and player1.last_room != "captain`s quarters"
			and player1.last_room != "upper deck")
			cout << "This is upper deck." << endl;
		cout << place.entrance_2_description << endl;
		take_action(player1, place);
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
		add_times(player1);
		if (player1.gorilla_run == 0)
		{
			if (player1.in_n_out == 0)
			{
				cout << place.entrance_4_description;
				player1.in_n_out = 1;
			}
			take_action(player1, place);
			if (player1.action == "give" and player1.object == "banana" or
				player1.object == "banana to gorilla")
			{
				discard_stuff(player1, "banana");
				place.stuff_can_give.erase("banana");
				player1.gorilla_run = 1;
				cout << "The gorilla rush to the forest and disapear!" << endl;
				player1.in_n_out = 0;
			}
			if (player1.action == "board")
				cout << "The gorilla is there, you can`t sail the ship!" << endl;
			while (player1.action == "move" and player1.object == "north")
			{
				take_action(player1, place);
			}
		}
		else if (player1.gorilla_run != 0)
		{
			if (player1.bandit)
			{
				monster bully;
				bully.name = "bully";
				bully.x = player1.x;
				bully.y = player1.y;
				bully.attack = 20;
				bully.health = 150;
				if (player1.bandit_warning and player1.gorilla_run)
				{
					cout << "---------------------------------------------------------------" << endl;
					cout << "\"Hahahahahaha!!!!Now the ship is mine!!!!\"" << endl;
					cout << "What bad luck! There is a bully in the natives who has tracked you"
						<< "for a long time wants this ship!" << endl;
					cout << "The good thing is he doesn`t know how to start it..." << endl;
					cout << "we batter consider some ways of kicking him out of this ship." << endl;
					player1.bandit_warning = false;
				}
				if (player1.in_n_out == 0)
				{
					cout << "-----------------------------------------------------" << endl;
					cout << "In front of the bully, you suddenly fell you are full" << endl;
					cout << "of confident and courage, you come forward and try to " << endl;
					cout << "convinced the bully to leave this ship. However it seems" << endl;
					cout << "like he still insists on taking this ship and he slapped you on the right cheek." << endl;
					player1.health -= 10;
					cout << "Your health remainding:" << player1.health << endl;
					player1.in_n_out = 1;
				}
				cout << "-----------------------------------------------------" << endl;
				cout << "Enter \"fight\" to fight with the bully!" << endl;
				take_action(player1, place);
				if (player1.action == "fight")
					fight(player1, place, bully);
			}
			else
			{
				if (player1.in_n_out == 0)
				{
					cout << place.entrance_4_short_description << endl;
					player1.in_n_out = 1;
				}

				take_action(player1, place);
				if (player1.action == "board")
				{

					if (player1.save_prison != false)
					{
						success = true;
						cout << "You finally success to sail away!" << endl;
					}
					else
						cout << "You need that guy in the brig to help you board this ship!" << endl;

				}
			}
		}
	}
	else if (player1.x == place.entrance_3_x and player1.y == place.entrance_3_y)
	{
		player1.room = "gangplank";
		add_times(player1);
		if (player1.hostile)
		{
			if (player1.in_n_out == 0 and player1.gangplank_times == 1)
			{
				cout << "There are hostile natives that appear outside" <<
					" the ship after the player boards\n" <<
					"They will not allow anyone off the ship" <<
					" until you give the treasure to them." << endl;
				player1.in_n_out = 1;
			}
			else if (player1.in_n_out == 0 and player1.gangplank_times != 1)
			{
				cout << "There are hostile natives outside want the treasure!" << endl;
				player1.in_n_out = 1;
			}
			take_action(player1, place);
			if (player1.action == "give")
			{
				place.stuff_can_give.erase("treasure");
				player1.inventory.erase("treasure");
				player1.hostile = false;
				player1.bandit = true;
				player1.bandit_warning = true;
				cout << "The hostile native finally leave." << endl;
			}
		}
		else
		{
			if (player1.in_n_out == 0)
				cout << place.entrance_3_description << endl;
			take_action(player1, place);
			if (player1.action == "get out" or
				(player1.action == "move" and player1.object == "west"))
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
		add_times(player1);
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
		take_action(player1, place);
	}
}
void lower_deck(player & player1, scene place)
//This function can set up the map "lower deck" in the game.
{
	int pos, hour, min, cur_time;
	monster ghost;
	pos = player1.time.find(":");
	hour = stoi(player1.time.substr(0, pos++));
	min = stoi(player1.time.substr(pos, player1.time.length() - pos));
	cur_time = hour * 60 + min;
	if (cur_time >= 1080 and cur_time <= 360)
	{
		if (!player1.with_light)
		{
			srand((unsigned)time(NULL));
			ghost.x = rand() % 3 + player1.x;
<<<<<<< HEAD
			ghost.y =player1.y;
=======
			ghost.y = rand() % 2 + player1.y;
>>>>>>> 5978291d167b403e8110fac99db6168fb2d21983
			if (ghost.x == player1.x and ghost.y == player1.y)
			{
				cout << "You have encouter a ghost!" << endl;
				ghost.name = "ghost";
				fight(player1, place, ghost);
			}
		}
	}
	if (player1.x == place.entrance_1_x and player1.y == place.entrance_1_y)
	{
		player1.room = "cargo hold";
		add_times(player1);
		int get_stem;
		if (player1.in_n_out == 0 and player1.cargo_hold_times == 1)
		{
			cout << place.entrance_1_description << "\nstuff can get:stem" << endl;
			player1.in_n_out = 1;
		}
		else if (player1.in_n_out == 0 and player1.cargo_hold_times != 1)
		{
			if (player1.get == 1)
				cout << place.entrance_1_short_description
				<< "\nstuff can get:stem and treasure" << endl;
			else
				cout << place.entrance_1_short_description
				<< "\nstuff can get:stem" << endl;;
			player1.in_n_out = 1;
		}
		take_action(player1, place);
		if (player1.action == "get" or player1.action == "cut")
		{
			if (player1.action == "get" and player1.object == "treasure")
			{
				if (player1.object == "treasure")
				{
					if (player1.treasure_amount != 0)
					{
						if (player1.get == 1)
						{
							cout << "-----------------------" << endl;
							cout << "You got the treasure!" << endl;
							cout << "-----------------------" << endl;
							player1.get = 0;
							player1.inventory["treasure"]++;
							player1.treasure_amount--;
							place.stuff_can_get.erase("treaure");
						}
						else if (player1.get == 0)
						{
							cout << "--------------------------------------------------" << endl;
							cout << "You don`t see any treasure here, at least...so far" << endl;
							cout << "--------------------------------------------------" << endl;
						}
					}
					else if (player1.treasure_amount == 0)
					{
						cout << "------------------------------" << endl;
						cout << "You already got the treasure!" << endl;
						cout << "------------------------------" << endl;
					}
				}
			}
			else if (player1.object == "stem")
			{
				if (carrying(player1, "knife"))
				{
					if (player1.equipments["trinket"] == "pandent")
					{
						int got_two;
						srand((unsigned)time(NULL));
						got_two = rand() % 5;
						if (got_two == 0)
						{
							cout << "-----------------" << endl;
							cout << "You got two stems!" << endl;
							cout << "-----------------" << endl;
							player1.inventory["stem"] += 2;
						}
						else
						{
							cout << "-----------------" << endl;
							cout << "You got a stem!" << endl;
							cout << "-----------------" << endl;
							player1.inventory["stem"]++;
						}
					}
					else
					{
						cout << "-----------------" << endl;
						cout << "You got a stem!" << endl;
						cout << "-----------------" << endl;
						player1.inventory["stem"]++;
					}
				}
				else
				{
					cout << "----------------------------------" << endl;
					cout << "You need a knife to get the stem!" << endl;
					cout << "----------------------------------" << endl;
				}
			}
		}
	}

	else if (player1.x == place.entrance_2_x and player1.y == place.entrance_2_y)
	{
		enum position{up=1,down=0};
		if (player1.up_or_down ==up)
		{
			player1.room = "ladder";
			player1.ladder_times++;
			if (player1.last_room != "brig" and player1.last_room != "galley"
				and player1.last_room != "cargo hold" and player1.last_room != "lower deck")
			{
				player1.room = "lower deck";
				add_times(player1);
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
			take_action(player1, place);
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
		else if (player1.up_or_down == down)
		{
			player1.room = "brig";
			add_times(player1);
			if (player1.brig_times == 1 and player1.in_n_out == 0)
			{
				cout << place.entrance_3_description << endl;
				player1.in_n_out = 1;
			}
			else if (player1.brig_times != 1 and player1.in_n_out == 0)
			{
				if (player1.save_prison == false)
					cout << place.entrance_3_short_description << endl;
				else
					cout << place.entrance_3_short_description_after << endl;
				player1.in_n_out = 1;
			}
			take_action(player1, place);
			while (player1.action == "can`t go")
			{
				cout << "-----------------------------------" << endl;
				cout << "You have to leave the brig first." << endl;
				cout << "-----------------------------------" << endl;
				take_action(player1, place);
			}
			if (player1.action == "unlock" and player1.save_prison == false)
			{
				cout << "--------------------------------------------" << endl;
				cout << "You finally free that poor guy. Hell yeah!" << endl;
				cout << "--------------------------------------------" << endl;
				discard_stuff(player1, "key");
				player1.save_prison = true;
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
		add_times(player1);
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
		while (get_out == 0)
		{
			cout << "What are you going to do?" << endl;
			getline(cin, words);
			words = sentence_to_pig_latin(words);
			if (words == "hello")
			{
				player1.parrot = true;
				get_out = 1;
				cout << "The parrot says: \"The key is in the captain`s quarters!\"" << endl;
			}
			else
				cout << "The parrot repeat your words:\"" << words << "\"" << endl;
		}
		if (get_out == 1)
		{
			take_action(player1, place);
		}
	}
	else
	{
		take_action(player1, place);
	}
}
void action_seprate(string & actions, string & objects, string action)
//This function can separate the command in two parts
// one is the action and one is object.
{
	int pos;
	bool object;
	object = has_object(action);
	if (object)
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
bool has_object(string action)
//This function can determind if the command has object.
{
	bool has = false;
	int action_index;
	if (action.length() - 1 >= 0)
	{
		for (action_index = 0; action_index <= action.length() - 1; action_index++)
			if (action.at(action_index) == ' ' and action_index != action.length() - 1)
				has = true;
	}
	return has;
}
void so_bad_so_sad(player & player1)
//This function can prompt the player when they input the bad command.
{
	if (player1.object != "none")
	{
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "So bad so sad, you can`t " << player1.action << " "
			<< player1.object << " right now!" << endl;
		cout << "---------------------------------------------------------------------------" << endl;
	}
	else
	{
		cout << "--------------------------------------------------------------" << endl;
		cout << "So bad so sad, you can`t " << player1.action << " right now!" << endl;
		cout << "--------------------------------------------------------------" << endl;
	}
	player1.action = "none";
}
bool can_get(player player1, scene place)
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
		cout << "Sorry, you can`t get " << player1.object << " right here" << endl;
		cout << "----------------------------------------------------------" << endl;
	}
	return get;
}
bool can_cut(player player1, scene place)
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
		cout << "" << player1.object << " is not here!" << endl;
		cout << "--------------------------------------" << endl;
	}
	return cut;
}
bool can_give(player player1, scene place)
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
			if (carrying(player1, player1.object) != false and it->second == coordinate)
				give = true;
			else if (carrying(player1, player1.object) != false and it->second != coordinate)
			{
				cout << "-------------------------------" << endl;
				cout << "You can`t do that right here!" << endl;
				cout << "-------------------------------" << endl;
			}
			else
			{
				cout << "---------------------------------" << endl;
				cout << "You don`t have " << player1.object << " to give!" << endl;
				cout << "---------------------------------" << endl;
			}
		}
	}
	if (!equal)
	{
		cout << "--------------------------------------" << endl;
		cout << "You don`t have " << player1.object << " to give!" << endl;
		cout << "--------------------------------------" << endl;
	}
	return give;
}
bool can_eat(player player1, scene place)
//This function can determind if the player can eat
// something in the game.
{
	bool eat = false;
	vector<string>::iterator it;

	for (it = place.stuff_can_eat.begin(); it != place.stuff_can_eat.end(); it++)
	{
		if (player1.object == *it and carrying(player1, player1.object) != false)
			eat = true;
	}

	return eat;
}
bool can_pick(player player1)
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
		cout << "" << player1.object << " is not here!" << endl;
		cout << "---------------------------" << endl;
	}

	return pick;
}
bool can_drop(player player1)
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
	pos = stuff.length() - 2;
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
	pos = name.length() - 2;
	name = name.substr(0, pos);
	return name;
}
void drop_it(player & player1)
//This function can let player drop stuff in the game.
{
	map<string, string>::iterator it;
	string name, drop_coordinate;
	bool duplicate = false;
	discard_stuff(player1, player1.object);
	drop_coordinate = coordinate_to_string(player1);
	if (!player1.drop_stuff.empty())
	{
		it = player1.drop_stuff.begin();
		while (it != player1.drop_stuff.end() and duplicate != true)
		{
			name = it->first;
			name = recover_name(name);
			if (name == player1.object)
			{
				name = it->first;
				cout << "-----------------------------------------------------" << endl;
				cout << "You drop a " << player1.object << "\nPlease protect the environment!" << endl;
				cout << "-----------------------------------------------------" << endl;
				name = re_name(player1, name);
				player1.drop_stuff[name] = drop_coordinate;
				duplicate = true;
			}
			else
				it++;
		}
	}
	if (duplicate == false)
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "You drop a " << player1.object << "\nPlease protect the environment!" << endl;
		cout << "-----------------------------------------------------" << endl;
		player1.object.append(" ");
		player1.object.append("1");
		player1.drop_stuff[player1.object] = drop_coordinate;
	}
}
int get_number(string name)
//This function can get the number in the name of the stuff that player dropped
//like the 1 in banana 1.
{
	int pos, number;
	string num;
	pos = name.length() - 1;
	num = name.at(pos);
	number = stoi(num);
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
	string first_part, second_part;
	int pos = 0;
	bool got_volve = false;
	while (pos != word.length() - 1 and !got_volve)
	{
		if (word.at(pos) == 'a' or word.at(pos) == 'e' or
			word.at(pos) == 'i' or word.at(pos) == 'o'
			or word.at(pos) == 'u')
			got_volve = true;
		else
			pos++;
	}
	if (pos == 0)
		word.append("way");
	else
	{
		first_part = word.substr(0, pos);
		second_part = word.substr(pos, word.length() - pos);
		first_part += "ay";
		word = second_part + first_part;
	}
	return word;
}
void get_sentence(string sentence, vector<string> & marks, vector<string> & word)
//This cuntion can separate a sentence into marks and words.
{
	int index = 0;
	string mark = " ", temp_mark, words = " ", temp_word;
	while (index <= sentence.length() - 1)
	{
		if ((sentence.at(index) >= 'a' and sentence.at(index) <= 'z')
			or (sentence.at(index) >= 'A' and sentence.at(index) <= 'Z')
			and index < sentence.length() - 1)
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
void add_times(player & player1)
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
	else if (player1.room == "hut" and player1.hut_times == 0)
	{
		player1.hut_times++;
		player1.in_n_out = 0;
		player1.last_room = "hut";
	}
	else if (player1.room == "ship`s wheel" and player1.ship_times == 0)
	{
		player1.ship_times++;
		player1.in_n_out = 0;
		player1.last_room = "ship`s wheel";
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
			else if (player1.room == "hut")
			{
				player1.hut_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
			else if (player1.room == "ship`s wheel")
			{
				player1.ship_times++;
				player1.in_n_out = 0;
				player1.last_room = player1.room;
			}
		}
	}
}
void look_hint_and_search(player & player1, scene place)
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
					if (!carrying(player1, "knife"))
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
			if (player1.action == "hint")
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
			if (player1.parrot == false)
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
					cout << "Get the knife and go away." << endl;
					cout << "----------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					if (player1.knife_amount != 0)
					{
						cout << "-------------------------------------" << endl;
						cout << "You found nothing except the knife." << endl;
						cout << "-------------------------------------" << endl;
					}
					else
					{
						cout << "-------------------------------" << endl;
						cout << "here is nothing on the table." << endl;
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
						cout << "Get the knife and key and go away." << endl;
						cout << "------------------------------------" << endl;
					}
					else
					{
						cout << "--------------------------" << endl;
						cout << "Get the key and go away." << endl;
						cout << "--------------------------" << endl;
					}
				}
				else if (player1.action == "search")
				{
					if (player1.knife_amount != 0)
					{
						cout << "-----------------------------------------" << endl;
						cout << "You the key and the knife on the table." << endl;
						cout << "-----------------------------------------" << endl;
					}
					else
					{
						cout << "---------------------------------" << endl;
						cout << "You found the key on the table." << endl;
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
				cout << "To go down or not go down, that is a question." << endl;
				cout << "------------------------------------------------" << endl;
			}
			else if (player1.action == "search")
			{
				cout << "------------------------------------" << endl;
				cout << "You found nothing with this ladder" << endl;
				cout << "------------------------------------" << endl;
			}
		}
		else if (player1.room == "ship`s wheel")
		{
			if (player1.gorilla_run == 0)
			{
				if (player1.action == "look")
				{
					cout << "------------------------------------------------------------------------" << endl;
					cout << place.entrance_4_description;
					cout << "You take a sneak look at the gorilla." <<
						" It's so big and frightening that you hide back quickly" << endl;
					cout << "------------------------------------------------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "----------------------------------------" << endl;
					cout << "Think about what gorilla likes to eat?" << endl;
					cout << "----------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "----------------------------------------------------" << endl;
					cout << "You can`t do any search when the gorilla is there!" << endl;
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
					cout << "You need a sailor to help you sail this ship." << endl;
					cout << "------------------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "---------------------" << endl;
					cout << "No new discoveries." << endl;
					cout << "---------------------" << endl;
				}
			}
		}
		else if (player1.room == "gangplank")
		{
			if (player1.hostile)
			{
				if (player1.action == "look")
				{
					cout << "There are hostile natives that appear outside the ship after"
						<< " the player boards";
					cout << "They will not allow anyone off the ship until you give the treasure to you." << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "--------------------------------------------" << endl;
					cout << "Why you wait? Just give them the treasure." << endl;
					cout << "--------------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "No new discoveries" << endl;
					cout << "--------------------" << endl;
				}
			}
			else
			{
				if (player1.action == "hint")
				{
					cout << "---------------------------------------------" << endl;
					cout << "To go in or not go out, that is a question." << endl;
					cout << "---------------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "No new discoveries" << endl;
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
				if (player1.gorilla_run == 1)
				{
					cout << "------------------------------------" << endl;
					cout << "Kick the gorilla out of this ship!" << endl;
					cout << "------------------------------------" << endl;
				}
				else
				{
					cout << "------------------------------------" << endl;
					cout << "There is nothing I can prompt you." << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else if (player1.action == "search")
			{
				cout << "--------------------" << endl;
				cout << "No new discoveries" << endl;
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
					if (player1.get == 1)
					{
						cout << "-----------------------------------------" << endl;
						cout << place.entrance_1_description << endl;
						cout << "stuff can get:stem,treasure" << endl;
						cout << "-----------------------------------------" << endl;
					}
					else
					{
						cout << "-----------------------------------------" << endl;
						cout << place.entrance_1_description << endl;
						cout << "stuff can get:stem" << endl;
						cout << "-----------------------------------------" << endl;
					}
				}
				else if (player1.action == "hint")
				{
					cout << "----------------------------------" << endl;
					cout << "Maybe there is something inside?" << endl;
					cout << "----------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					if (player1.get == 0)
					{
						cout << "----------------------------------------" << endl;
						cout << "You found the treasure in the trunk!!!" << endl;
						cout << "----------------------------------------" << endl;
						player1.get = 1;
					}
					else
					{
						cout << "--------------------" << endl;
						cout << "No new discoveries" << endl;
						cout << "--------------------" << endl;
					}
				}
			}
			else
			{
				if (player1.action == "look")
				{
					cout << "-----------------------------------------" << endl;
					cout << place.entrance_1_description << endl;
					cout << "stuff can get:stem" << endl;
					cout << "-----------------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					if (player1.hostile and carrying(player1, "treasure"))
					{
						cout << "----------------------------------------------" << endl;
						cout << "Now, these hostile should be happy to leave." << endl;
						cout << "----------------------------------------------" << endl;
					}
					else
					{
						cout << "------------------------------------" << endl;
						cout << "There is nothing I can prompt you." << endl;
						cout << "------------------------------------" << endl;
					}
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "No new discoveries" << endl;
					cout << "--------------------" << endl;
				}
			}
		}
		else if (player1.room == "brig")
		{
			if (player1.save_prison == false)
			{
				if (player1.action == "look")
					cout << place.entrance_3_description << endl;
				else if (player1.action == "hint")
					cout << "The other one who can speak on this ship" <<
					" may know where the key is." << endl;
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "No new discoveries" << endl;
					cout << "--------------------" << endl;
				}
			}
			else
			{
				if (player1.action == "look")
				{
					cout << "-----------------------------------------------------------------------------------------------------------" << endl;
					cout << "You can see from the broken cage and its surroundings how much the poor man who had been inside suffered." << endl;
					cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				}
				else if (player1.action == "hint")
				{
					cout << "------------------------------------" << endl;
					cout << "There is nothing I can prompt you." << endl;
					cout << "------------------------------------" << endl;
				}
				else if (player1.action == "search")
				{
					cout << "--------------------" << endl;
					cout << "No new discoveries" << endl;
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
				cout << "To go up or not go up, that is a question." << endl;
				cout << "--------------------------------------------" << endl;
			}
			else if (player1.action == "search")
			{
				cout << "--------------------" << endl;
				cout << "No new discoveries" << endl;
				cout << "--------------------" << endl;
			}
		}
		else if (player1.room == "galley")
		{
			if (player1.parrot == false)
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
					cout << place.entrance_4_description << endl;
					cout << "------------------------------------------------------------------------------------------------------------" << endl;
					cout << "The parrot looks like it wants to play the Pig-Latin game with you. You're so scared that want to go away." << endl;
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
				if (player1.parrot == false and player1.treasure_amount == 1)
				{
					cout << "-----------------------------------------------------" << endl;
					cout << "|Go find the key and free that man and the treasure!|" << endl;
					cout << "-----------------------------------------------------" << endl;
				}
				else if (player1.parrot == false)
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
}
scene init_scene(scene place)
//This function can initialize the coordinate of special stuff that 
// the player can do something with like drop or cut.
{
	equipment stem, sword, chainmail_helmet, chain_mail,
		leggings, chainmail_boots, banana, key, cross, pendant, knife;
	stem.name = "stem";
	stem.attack = 1;
	stem.defence = 0;
	stem.attribute = "weapon";
	knife.name = "knife";
	knife.attack = 3;
	knife.defence = 0;
	knife.attribute = "weapon";
	sword.name = "sword";
	sword.attack = 6;
	sword.defence = 0;
	sword.attribute = "weapon";
	chainmail_helmet.name = "chainmail helmet";
	chainmail_helmet.attack = 0;
	chainmail_helmet.defence = 1;
	chainmail_helmet.attribute = "head";
	chain_mail.name = "chain mail";
	chain_mail.attack = 0;
	chain_mail.defence = 2;
	chain_mail.attribute = "body";
	leggings.name = "leggings";
	leggings.attack = 0;
	leggings.defence = 1;
	leggings.attribute = "legs";
	chainmail_boots.name = "chainmail boots";
	chainmail_boots.attack = 0;
	chainmail_boots.defence = 1;
	chainmail_boots.attribute = "feet";
	banana.name = "banana";
	banana.attack = 1;
	banana.defence = 0;
	banana.attribute = "weapon";
	key.name = "key";
	key.attack = 1;
	key.defence = 0;
	key.attribute = "weapon";
	cross.name = "cross";
	cross.attack = 0;
	cross.defence = 0;
	cross.attribute = "trinket";
	pendant.name = "pendant";
	pendant.attack = 0;
	pendant.defence = 0;
	pendant.attribute = "trinket";
	place.stuff_can_get["treasure"] = "2 -9 0";
	place.stuff_can_get["stem"] = "2 -9 0";
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
	place.equips["knife"] = knife;
	place.questions["Who invented the telephone?"] = "bell";
	place.questions["Which nail grows fastest?"] = "middle nail";
	place.questions["What number of temperature does water boil at?"] = "100";
	place.questions["Who discovered penicillin?"] = "fleming";
	place.questions["What Spanish artist said he would eat his wife when she died?"] = "dali";
	place.questions["Who wrote Julius Caesar, Macbeth and Hamlet?"] = "shakespeare";
	place.questions["Who wrote Lazarillo de Tormes?"] = "anonymous";
	place.questions["What did the crocodile swallow in Peter Pan? "] = "alarm clock";
	place.questions["Where was Lope de Vega born?"] = "madrid";
	place.questions["Who did Lady Diana Spencer marry?"] = "prince charles";
	place.questions["Where is Mulhacen?"] = "granada spain";
	place.questions["How many states are there in the United States of America?"] = "50";
	place.questions["Which river passes through Madrid?"] = "manzanares";
	place.questions[" Which German city is famous for the perfume it produces?"] = "cologne";
	place.questions["Who did Prince Rainier of Monaco marry? "] = "grace kelly";
	place.questions["What year did the Spanish Civil War end?"] = "1939";
	place.questions["When did the First World War start?"] = "1914";
	place.questions["What did Joseph Priesley discover in 1774?"] = "oxygen";
	place.questions["Where is the smallest bone in the body?"] = "ear";
	place.questions["Which is the only mammal that can`t jump?"] = "elephant";
	place.questions["What does the roman numeral C represent?"] = "100";
	place.questions["What colour is a panda? "] = "black and white";
	place.questions["What nationality was Chopin?"] = "polish";
	place.questions["What`s the best known artificial international language?"] = "esperanto";
	place.questions["Who lived at 221B, Baker Street, London?"] = "sherlock holmes";
	place.questions["Who cut Van Gogh’s ear? "] = "himself";
	place.questions["Where did Salvador Dali live? "] = "figueras";
	place.questions["Who painted the Mona Lisa?"] = "da vinci";
	place.questions["How many dots are there on two dice?"] = "42";
	place.questions["What horoscope sign has a crab?"] = "cancer";
	place.questions["In which shop can you buy books in England?"] = "bookshop";
	place.questions["Where does the British Prime Minister live? "] = "10, downing street";
	place.questions["How long is the compulsory military service in England?"] = "it doesn’t exist";
	place.questions["When did the Second World War end?"] = "1945";
	place.questions["What are the first three words of the bible?"] = "in the beginning";
	place.questions["How many children has Queen Elizabeth the Second got?"] = "4";
	place.questions["What`s the real name of Siddartha Gautama?"] = "buddha";
	place.questions["What`s the name of the famous big clock in London?"] = "big ben";
	place.questions["Where was Christopher Columbus born?"] = "ggenoa";
	place.questions["When did the American Civil War end? "] = "1865";
	place.questions["What did the 7 dwarves do for a job? "] = "miners";
	place.questions["Who painted the Sistine Chapel?"] = "michelangelo";
	place.questions["Who wrote La Colmena?"] = "cela";
	place.questions["Name a famous detective who smoked a pipe and played the violin."] = "sherlock holmes";
	place.questions["Who said E=mc2 "] = "einstein";
	place.questions["Which planet is nearest the sun? "] = "mercury";
	place.questions["Where are the Dolomites?"] = "italy";
	place.questions["What`s the capital of Kenya?"] = "nairobi";
	place.questions["Which is the largest ocean?"] = "pacific";
	place.questions["What`s the capital of Honduras?"] = "tegucigarpa";
	place.questions["What`s the capital of Ethiopia?"] = "addis ababa";
	place.questions["How many squares are there on a chess board?"] = "64";
	place.questions["How many prongs are there on a fork? "] = "4";
	place.questions["Which color starts first in chess? "] = "white";
	place.questions["How many events are there in the decathlon?"] = "10";
	place.questions[" What do you use to take a cork out of a bottle?"] = "corkscrew";
	place.questions["What language has the most words?"] = "english";
	place.questions["What`s the name of the main airport in Madrid?"] = "barajas";
	place.questions["What money do they use in Japan?"] = "yen";
	place.questions[" What year did Paquirri die?"] = "1984 or 1985";
	place.questions["Who said, “I think, therefore I am”?"] = "descartes";
	place.questions["Who wrote the Ugly Duckling?"] = "hans christian andersen";
	place.questions["Where was El Greco born?"] = "greece";
	place.questions["What`s the Hungarian word for pepper?"] = "paprika";
	place.questions["Which painter did the group Mecano write a song about?"] = "dali";
	place.questions["Who sang, \"I`m dreaming of a white Christmas\"?"] = "bing crosby";
	place.questions["Name of the two main actors in “The Sting”."] = "paul newman and robert redford";
	place.questions["What year did Elvis Presley die?"] = "1977";
	place.questions[" What film star who was in 9« weeks is now a boxer?"] = "mickey rourke";
	place.questions["Where was Marco Polo’s home town?"] = "venice";
	place.questions["Which Italian leader was terribly afraid of the evil eye?"] = "mussolini";
	place.questions["What country gave Florida to the USA in 1891?"] = "spain";
	place.questions["Who gave his name to the month of July?"] = "julius caesar";
	place.questions["Who wrote the Satanic Verses?"] = "salman rushdie";
	place.questions["What was the first theatre play in Spain?"] = "la celestina";
	place.questions["What`s the most important book in the Moslem religion?"] = "koran";
	place.questions["When was Elvis` first ever concert?"] = "1954";
	place.questions["Who sang \"My Way\"?"] = "frank sinatra";
	place.questions["Who as the main actor in “Cocktail”?"] = "tom cruise";
	place.questions["Who was the main actor in Superman 2?"] = "christopher reeve";
	place.questions["Who did Madonna marry?"] = "sean penn";
	place.questions["What did the Montgolfier brothers invent?"] = "the balloon";
	place.questions["Who is the president of Iraq between 1979 to 2003?"] = "sadam hussein";
	place.questions["What type of elephant has got the biggest ears?"] = "african";
	place.questions["Who invented the electric light bulb?"] = "thomas edison";
	place.questions["What`s the smallest type of tree in the world?"] = "dwarf willow salix herbacea";
	place.questions["Who invented television?"] = "john logie baird";
	place.questions["What activity other than jumping are kangaroos good at?"] = "boxing";
	place.questions["What`s the capital of Ecuador? "] = "quito";
	place.questions["What colours make purple?"] = "red and blue";
	place.questions["What`s the hardest rock?"] = "diamond";
	place.questions["How much does a litre of water weigh?"] = "1kg";
	place.questions["When was President Kennedy killed?"] = "1963";
	place.questions["What stopped in London at 3.45 on August 5th, 1975? "] = "big ben";
	place.questions["What nationality was Marco Polo?"] = "italian";
	place.questions["Who won a gold medal for Spain in cycling in the 1992 Olympics?"] = "jose manuel moreno";
	place.questions["Who is the tallest basketball player in the world?"] = "manute boll";
	place.questions["Where does the American president live?"] = "the white house";
	place.questions["What is the first letter on a typewriter?"] = "q";
	place.questions["Which river goes through London?"] = "thames";
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
	cout << "Once you are in a battle, you can only" <<
		" do either attack or run away, and quit the game."
		<< "Fight until someone dies." << endl;
	cout << "************************************************************************************************************" << endl;
	cout << "About commands in this game:\n" << endl;
	cout << "The commands in this game is made up by" <<
		" one or two words, normally a verb fllowed by a noun." << endl;
	cout << "You can change the keys for command by enter \"setting\"." << endl;
	cout << "Here are the keys for command:" << endl;
	for (index = 0; index <= COMMAND_LENGTH - 2; index++)
	{

		switch (index)
		{
		default:
		case 0:cout << index + 1 << ". " << "Go " << "north---" << player1.command[index] << endl;
			break;
		case 1:cout << index + 1 << ". " << "Go " << "south---" << player1.command[index] << endl;
			break;
		case 2:cout << index + 1 << ". " << "Go " << "west---" << player1.command[index] << endl;
			break;
		case 3:cout << index + 1 << ". " << "Go " << "east---" << player1.command[index] << endl;
			break;
		case 4:cout << index + 1 << ". " << "To " << "board---" << player1.command[index] << endl;
			break;
		case 5:cout << index + 1 << ". " << "To " << "enter---" << player1.command[index] << endl;
			break;
		case 6:cout << index + 1 << ". " << "To " << "take---" << player1.command[index] << endl;
			break;
		case 7:cout << index + 1 << ". " << "To " << "give---" << player1.command[index] << endl;
			break;
		case 8:cout << index + 1 << ". " << "To " << "search---" << player1.command[index] << endl;
			break;
		case 9:cout << index + 1 << ". " << "To " << "look---" << player1.command[index] << endl;
			break;
		case 10:cout << index + 1 << ". " << "To " << "eat---" << player1.command[index] << endl;
			break;
		case 11:cout << index + 1 << ". " << "To " << "cut---" << player1.command[index] << endl;
			break;
		case 12:cout << index + 1 << ". " << "To " << "climb---" << player1.command[index] << endl;
			break;
		case 13:cout << index + 1 << ". " << "To " << "drop---" << player1.command[index] << endl;
			break;
		case 14:cout << index + 1 << ". " << "Go " << "up---" << player1.command[index] << endl;
			break;
		case 15:cout << index + 1 << ". " << "Go " << "down---" << player1.command[index] << endl;
			break;
		case 16:cout << index + 1 << ". " << "To " << "unlock---" << player1.command[index] << endl;
			break;
		case 17:cout << index + 1 << ". " << "To " << "sail---" << player1.command[index] << endl;
			break;
		case 18:cout << index + 1 << ". " << "To " << "open---" << player1.command[index] << endl;
			break;
		case 19:cout << index + 1 << ". " << "To " << "quit---" << player1.command[index] << endl;
			break;
		case 20:cout << index + 1 << ". " << "Check " << "inventory---" << player1.command[index]
			<< endl; break;
		case 21:cout << index + 1 << ". " << "To " << "setting---" << player1.command[index]
			<< endl; break;
		case 22:cout << index + 1 << ". " << "To " << "save---" << player1.command[index] << endl;
			break;
		case 23:cout << index + 1 << ". " << "To " << "load--" << player1.command[index] << endl;
			break;
		case 24:cout << index + 1 << ". " << "To see " << "hint---" << player1.command[index]
			<< endl; break;
		case 25:cout << index + 1 << ". " << "To see " << "help---" << player1.command[index]
			<< endl; break;
		case 26:cout << index + 1 << ". " << "To" << " get something---" << player1.command[index]
			<< endl; break;
		case 27:cout << index + 1 << ". " << "To" << " hide extra information---" <<
			player1.command[index] << endl; break;
		case 28:cout << index + 1 << ". " << "To" << " display extra information---"
			<< player1.command[index] << endl; break;
		case 29:cout << index + 1 << ". " << "To" << " pick something---"
			<< player1.command[index] << endl; break;
		case 30:cout << index + 1 << ". " << "To" << " lie---"
			<< player1.command[index] << endl; break;
		case 31:cout << index + 1 << ". " << "To" << " attack---"
			<< player1.command[index] << endl; break;
		case 32:cout << index + 1 << ". " << "To" << " run away---"
			<< player1.command[index] << endl; break;
		case 33:cout << index + 1 << ". " << "To" << " equip equipment---"
			<< player1.command[index] << endl; break;
		case 34:cout << index + 1 << ". " << "To" << " check character`s state---"
			<< player1.command[index] << endl; break;
		case 35:cout << index + 1 << ". " << "To" << " light the stem---"
			<< player1.command[index] << endl; break;
		case 36:cout << index + 1 << ". " << "To" << " unequip equipment---"
			<< player1.command[index] << endl; break;
		case 37:cout << index + 1 << ". " << "To" << " sell stuff---"
			<< player1.command[index] << endl; break;
		case 38:cout << index + 1 << ". " << "To" << " use stuff---"
			<< player1.command[index] << endl; break;
			break;
		}
	}
}
void welcome()
//This function can print welcome words to the player.
{
	cout << "You wake up on an island with no memory of how" <<
		" you got there.You need to overcome a"
		<< "series of obstacles in order to be able to to " <<
		" a pirate ship and sail it to civilization." << endl;
}
void boundary(player player1, scene place)
//This function can prompt player when he get to the boundary of the map.
{
	if (player1.x == place.min_x and player1.x == place.max_x)
	{
		if (player1.location == "island" and player1.hostile == false)
			;
		else
			cout << "You are right at the boundary, you can`t go south or north" << endl;
	}
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
void game_time(player & player1)
//This function can caculate the time in this game.
//The time in this game begins at 8:00 o`clock.
{
	time_t now;
	struct tm ltm;
	int hour, min, sec, time_spent = 0, pos;
	int p_hour, p_min;
	string p_time;
	if (player1.time_begin)
	{
		now = time(0);
		ltm = *localtime(&now);
		min = ltm.tm_min;
		sec = ltm.tm_sec;
		player1.start_time = min * 60 + sec;
	}
	else
	{
		now = time(0);
		ltm = *localtime(&now);
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
}
void extra_info(player player1, scene place)
//This function can telling the player the time right now
// the location he is at and remind the player when he
//is right at the boundary.
{
	if (player1.hide == 0 and (player1.action == "move" or player1.action == "display"
		or player1.action == "save" or player1.action == "up" or player1.action == "down"))
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
void fight(player & player1, scene place, monster ghost)
//This function can let player battle with monster
//in this game.
{
	int  run, dodge;
	player1.fighting = true;
	if (player1.battle_warning)
	{
		cout << "You have entered a battle, your opponent is "
			<< ghost.name << ", very dangerous! Be careful!" << endl;
		player1.battle_warning = false;
	}
	if (player1.equipments["trinket"] == "cross")
		player1.attack *= 2;
	while (ghost.health != 0 and player1.fighting)
	{
		take_action(player1, place);
		if (player1.action == "attack")
		{
			ghost.health -= player1.attack;
			if (ghost.health <= 0)
				ghost.health = 0;
			if (player1.equipments["trinket"] == "pendant")
			{
				srand((unsigned)time(NULL));
				dodge = rand() % 10;
				if (dodge == 0)
				{
					cout << "Dodge! You dodge an attack from ghost." << endl;
					player1.health -= 0;
				}
				else
					player1.health = player1.health - (ghost.attack - player1.defence * 0.5);
			}
			else
				player1.health = player1.health - (ghost.attack - player1.defence * 0.5);
			if (player1.weapon == "knife")
			{
				cout << "ultimate skill:shadow of knife!!! ";
				cout << "Enimy health minus: " << player1.attack << endl;
			}
			else if (player1.weapon == "stem")
			{
				cout << "ultimate skill:stem tornado!!! ";
				cout << "Enimy health minus: " << player1.attack << endl;
			}
			else if (player1.weapon == "key")
			{
				cout << "ultimate skill:key attack!!! ";
				cout << "Enimy health minus: " << player1.attack << endl;
			}
			else if (player1.weapon == "banana")
			{
				cout << "ultimate skill:super banana drill!!! ";
				cout << "Enimy health minus: " << player1.attack << endl;
			}
			else if (player1.weapon == "punch")
			{
				cout << "ultimate skill:punch storm!!! ";
				cout << "Enimy health minus: " << player1.attack << endl;
			}
			else if (player1.weapon == "sword")
			{
				cout << "ultimate skill:X-Scissor!!! ";
				cout << "Enimy health minus: " << player1.attack << endl;
			}
			cout << "Your health remaining: " << player1.health << endl;
			cout << "Ghost health remaining: " << ghost.health << endl;
			if (ghost.health <= 0)
			{
				player1.gold += 20;
				player1.money_made += 20;
				player1.kill += 1;
				player1.final_score += 1;
				cout << "Victory!!!You have defeated the " << ghost.name << "!!!" << endl;
				cout << "Gold add 20" << endl;
				player1.fighting = false;
				player1.battle_warning = true;
				if (ghost.name == "bully")
					player1.bandit = false;
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
				player1.battle_warning = true;
			}
			else
			{
				if (player1.equipments["trinket"] == "pendant")
				{
					srand((unsigned)time(NULL));
					dodge = rand() % 10;
					if (dodge == 0)
					{
						cout << "Dodge! You dodge an attack from ghost." << endl;
						player1.health -= 0;
					}
					else
						player1.health = player1.health - (ghost.attack - player1.defence * 0.5);
				}
				else
					player1.health = player1.health - (ghost.attack - player1.defence * 0.5);
				if (player1.health > 0)
					cout << "fail to run away....health remind: " << player1.health << ". keep fighting!" << endl;
			}
		}
		if (player1.health <= 0)
		{
			cout << "You die" << endl;
			cout << "Victory and defeated are the common things of men,please start over again :)" << endl;
			exit(0);
		}
	}
}
int has_equipment(player player1, scene place, string stuff)
//This function can determind if the player has that equipment
// that he wants to wear.
{
	map<string, equipment>::iterator it;
	map<string, string>::iterator player_equip;
	enum object{have_stuff=2,not_have_but_in_the_game=1,not_have_not_in_the_game=-1};
	enum in_or_out{stuff_in_the_game=1,stuff_not_in_the_game=0};
	int has = 0, what_is_it = 0;
	for (player_equip = player1.equipments.begin(); player_equip != player1.equipments.end(); player_equip++)
	{
		if (player_equip->second == stuff)
		{
			cout << "You already equiped " << stuff << "!!!" << endl;
			has = have_stuff;
		}
	}
	if (has == 0)
	{
		for (it = place.equips.begin(); it != place.equips.end(); it++)
		{
			if (it->second.name == stuff)
			{
<<<<<<< HEAD
				what_is_it = stuff_in_the_game;
				if (carrying(player1, stuff) != false)
					has = not_have_but_in_the_game;
=======
				what_is_it = 1;
				if (carrying(player1, stuff) != false)
					has = 1;
>>>>>>> 5978291d167b403e8110fac99db6168fb2d21983
			}
		}

		if (what_is_it == stuff_not_in_the_game)
			has = not_have_not_in_the_game;
	}
	return has;
}
void item_description(string item)
//Descript the items in this game.
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
		cout << "pendant:There will be chance to get two stems and dodge"
		<< "an attack in battle when you wear pendant" << endl;
	else if (item == "cross")
		cout << "cross:God be with you.Attack will be double when attacking." << endl;
}
string ask_for_objects(string actions, string objects)
//Ask player for the objects  if needed when player input a command
//withou object.
{
	if (objects == "none")
	{
		cout << "--------------------------" << endl;
		cout << "What are you going to " << actions << endl;
		cout << "--------------------------" << endl;
		getline(cin, objects);
		objects = To_lower(objects);
	}
	return objects;
}
bool carrying(player player1, string stuff)
//Determind if the player`s inventory has something.
{
	bool carrying = false;
	map<string, int>::iterator it;
	for (it = player1.inventory.begin(); it != player1.inventory.end(); it++)
		if (it->first == stuff)
			carrying = true;
	return carrying;
}
void discard_stuff(player & player1, string stuff)
{
	player1.inventory[stuff]--;
	if (player1.inventory[stuff] <= 0)
		player1.inventory.erase(stuff);
}
bool match(string guess, string answer)
//This function can convert a single word to pig-latin.
{
	vector<string>words_in_answer;
	vector<string>words_in_guess;
	string word, temp;
	bool match = false;
	int answer_index = 0, guess_index = 0, combo = 0, counter = 0, length;
	while (answer_index < answer.length())
	{
		temp = answer.at(answer_index);
		if (temp != " ")
			word.append(temp);
		if (temp == " " or answer_index == answer.length() - 1)
		{
			words_in_answer.push_back(word);
			word.clear();
		}
		answer_index++;
	}
	word.clear();
	while (guess_index < guess.length())
	{
		temp = guess.at(guess_index);
		if (temp != " ")
		{
			word.append(temp);
		}
		if (temp == " " or guess_index == guess.length() - 1)
		{
			words_in_guess.push_back(word);
			word.clear();
		}
		guess_index++;
	}
	if (words_in_answer.size() < words_in_guess.size())
		length = words_in_answer.size();
	else
		length = words_in_guess.size();
	for (answer_index = 0; answer_index <= words_in_answer.size() - 1; answer_index++)
		for (guess_index = 0; guess_index <= words_in_guess.size() - 1; guess_index++)
		{
			if (words_in_answer[answer_index] == words_in_guess[guess_index])
				combo++;
		}
	if (combo == length)
		match = true;
	return match;
}
void data_statistics(player player1)
{
	map<string, int>times;
	map<string, string>scene_description;
	map<string, int>::iterator it;
	int max = 0, second, min;
	bool breaker = false;
	min = player1.time_spent / 60;
	second = player1.time_spent % 60;
	player1.final_score += (20000 / player1.time_spent);
	times["gangplank"] = player1.gangplank_times;
	times["ladder"] = player1.ladder_times;
	times["island"] = player1.island_times;
	times["mysterious hut"] = player1.hut_times;
	times["native shop"] = player1.shop_times;
	times["captain quarters"] = player1.captain_quarters_times;
	times["ship`s wheel"] = player1.ship_times;
	times["cargo hold"] = player1.cargo_hold_times;
	times["brig"] = player1.brig_times;
	times["galley"] = player1.galley_times;
	scene_description["gangplank"] = "You must been hesitating to board or disembark for many times.";
	scene_description["ladder"] = "Success is a ladder. People with their hands in their pockets can't climb it.\nNo doubt, you are a successful man";
	scene_description["island"] = "Do you like the hut or shop? Or....bananas?";
	scene_description["mysterious hut"] = "It seems that you like to play with the wise old man very much.";
	scene_description["native shop"] = "What a rich man are you!";
	scene_description["captain quarters"] = "You must miss the soft bed in captain`s quarters.";
	scene_description["ship`s wheel"] = "Seems like you had fun with the bully.";
	scene_description["cargo hold"] = "Do you still remember the warmth of the torch?";
	scene_description["brig"] = "Haha, now he's your man.";
	scene_description["galley"] = "pig-Latin game must be fun!";
	for (it = times.begin(); it != times.end(); it++)
	{
		if (it->second > max)
			max = it->second;
	}
	cout << "---------------------------------------------------------" << endl;
	cout << "Hey! Take a look on your footprints in the game!" << endl;
	cout << "You have spend " << min << " minutes and " << second << " seconds in this game" << endl;
	it = times.begin();
	while (it != times.end() and !breaker)
	{
		if (it->second == max)
		{
			cout << "Your favorite"
				<< "place to go is:" << it->first
				<< ", you have been there " << it->second << " times" << endl;
			cout << scene_description[it->first] << endl;
			breaker = true;//Only for break the loop.
		}
		else
			it++;
	}
	cout << "In this game you have defeated " << player1.kill << " enemies." << endl;
	cout << "The total money you made is:" << player1.money_made << endl;
	cout << "And you have spent " << player1.money_spend << " golds." << endl;
	cout << "Welcome back anytime, my warrior." << endl;
	cout << "---------------------------------------------------------" << endl;
<<<<<<< HEAD
}
=======
}
>>>>>>> 5978291d167b403e8110fac99db6168fb2d21983
