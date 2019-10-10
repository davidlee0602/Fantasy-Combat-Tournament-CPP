/*********************************************************************
** Program name: Team.hpp
** Author: David Lee
** Date: 05/25/2019
** Description: Team class header file that controls game flow in the fantasy team combat project.
 * The Team class has three data members that contains team1, team2 and the loserContainer.
 * The Team class implements stack data structure(LIFO) for the loserContainer.
 * The Team class implements queue data structure(FIFO) for the team fight.
 * All lists implements a single linked list.
 * The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container.
*********************************************************************/

#ifndef TEAM_HPP
#define TEAM_HPP
#include "Node.hpp"

class Team {
private:
    Node* team1; //single linked list for team1
    Node* team2; //single linked list for team2
    Node* loserContainer; //single linked list for loserContainer
public:
    Team(); //nullptr initialize
    ~Team(); // destructor
    void add(Node*& team, string name, int type); //adds character to back of team list
    void loserRemove(Node*& team, Node*& loserContainer); //removes the loser of the team fight and moves to loserContainer
    void printLoser(Node*& loserContainer); //prints loserContainer in a LIFO manner
    void moveBack(Node*& team); //moves winner to the back of team
    void fight(Node*& team1, Node*& team2); //head of team1 and team2 fights
    int inputValidation(string message, int min, int max); //input validation that takes in integers only
    void menu(); //menu function that controls program flow
    void resetLoserContainer(Node*& loserContainer); //de-allocates loserContainer
    void resetTeam(Node*& team1, Node*& team2); //de-allocates team1 and team2
    void recovery(Node*& team); //recovery function for winner in team fight

};


#endif
