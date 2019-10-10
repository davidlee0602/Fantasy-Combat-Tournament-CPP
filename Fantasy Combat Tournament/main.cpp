/*********************************************************************
** Program name: main.cpp
** Author: David Lee
** Date: 05/25/2019
** Description: main file that acts as the entry point to the fantasy team combat project.
 * It is a game from project 3 to run a tournament between 2 teams of fighters.
 * This game is a one-user-two-player game, so one user should be able to play setup fighters for both teams.
 * The tournament finishes when one of the team does not have any more fighters to fight.
 * When the game ends, it should print the result of the game, and allow user to have the choice to display the contents of the loser pile.
 * The Team class implements stack data structure(LIFO) for the loserContainer.
 * The Team class implements queue data structure(FIFO) for the team fight.
 * All lists implements a single linked list.
 * The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container.
*********************************************************************/

#include "Team.hpp"

int main(){
    Team team; //initialize team object
    team.menu(); //invokes game entry and menu
}