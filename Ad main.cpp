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
		place = set_scene(player1);
		if (place.name == "island"&&player1.y > -6)
		{
			player1 = island(player1, place);
		}
	}

	system("pause");
	return 0;
}
string take_action(player player1)// This function can determind the the command for the character in the game base on what the player input.
{
	
	return behavior;
}
player behave(player player1, string behavior, scene place)// This function can make the character to do something according to the command it given.
{
	
	return player1;
}
player if_over(player player1, scene place)//This function can determind if the character is over max coordinate of the map.
{

	return player1;
}
scene set_scene(player player1)//This function can initialize the different map in this game
{
	
	return place;
}
player island(player player1, scene place)//This function is represent the map of island in this game. Characters can do different things in each different map.
{

	return player1;
}
player init_inventory(player player1)// This function can initialize the amount of suff the character carrys, usually they are all zeros.
{

	return player1;
}
player setting(player player1)//This function is used to set different keys for the command of this game
{
	
	return player1;
}
int save_game(player player1)//	This function is used to save the game.
	
	return success;
}
player load_game(player player1)//This funtion is used to load the game.
{
	
	return player1;
}
void help()//This function is used to print help in the game.
{

}

player engine(player player1, scene place)//This funtion is used to run the game in different map.
{
	return player1;
}
string word_to_Piglatin(string word)//This funtion is used to translate the words to Pig Latin
{
	return Piglatin;
}