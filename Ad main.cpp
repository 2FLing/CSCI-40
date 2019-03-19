#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class scene
{
public:
	
};
class player
{
public:
	
};
player engine(player, scene, int);
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
string To_pig_latin(string)
int main()
{
	bool success = false;
	player player1;
	scene place;
	player1 = init_inventory(player1);
	while (!success)
	{
		place = set_scene(player1);
		player1 = engine(player1, place, success);
	}

	system("pause");
	return 0;
}
string take_action(player player1)//This funtion can convert the command the given by user to the action of the character in the game.
{
	return behavior;
}
player behave(player player1, string behavior)//This function can make the character to act what it suppose to act.
{
	
	return player1;
}
player if_over(player player1, scene place)//This function can judge if the player go over the map.
{

	return player1;
}
scene set_scene(player player1)//This function can set up the map according to the coordinate of the character
{
	
	return place;
}

player init_inventory(player player1)//This function can initialize the amount of the stuff the character has at beginning, usually they are all zeros.
{

	return player1;
}
player setting(player player1)//This function can set up the key what player input to a command in this game.
{
	return player1;
}
int save_game(player player1)//This function can save the game into a file.
{

	return success;
}
player load_game(player player1)//This function can load the game from a file.
{
}
void help()
{
}

player engine(player player1, scene place, int success)//This function can make the game run!
{

	return player1;
}
string To_lower(string words)//This function can convert a string to lower case.
{
	return words;
}
string To_pig_latin(string words)//This function can convert words to Pig latin.
{
	return words;
}