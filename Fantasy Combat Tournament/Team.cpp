/*********************************************************************
** Program name: Team.cpp
** Author: David Lee
** Date: 05/25/2019
** Description: Team class implementation file that controls game flow in the fantasy team combat project.
 * The Team class has three data members that contains team1, team2 and the loserContainer.
 * The Team class implements stack data structure(LIFO) for the loserContainer.
 * The Team class implements queue data structure(FIFO) for the team fight.
 * All lists implements a single linked list.
 * The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container.
*********************************************************************/

#include "Team.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

Team::Team(): team1(nullptr), team2(nullptr), loserContainer(nullptr){ //constructor for Team class

}

Team::~Team(){ //destructor
    cout << "Team object deleted" << endl;
}

void Team::add(Node*& team, string name, int type){ //adds character to back of team list
    Character* tempChar = nullptr;
    switch(type){ //user picks the type of character to put in their lineup
        case 1:
            tempChar = new Vampire();
            break;
        case 2:
            tempChar = new Barbarian();
            break;
        case 3:
            tempChar = new BlueMen();
            break;
        case 4:
            tempChar = new Medusa();
            break;
        case 5:
            tempChar = new HarryPotter();
            break;
        default:
            break;
    }

    if(team == nullptr){ //no character in team
        team = new Node(tempChar, name, nullptr);
    }else{ //adds to next in team lineup
        Node* tempTeam = team;
        while(tempTeam->getNext() != nullptr){
            tempTeam = tempTeam->getNext();
        }
        tempTeam->setNext(new Node(tempChar, name, nullptr));

    }
}

void Team::loserRemove(Node*& team, Node*& loserContainer){ //removes the loser of the team fight and moves to loserContainer
    Node* loser = loserContainer;
    loserContainer = team;
    if(loserContainer->getNext() != nullptr){
        team = team->getNext();
        loserContainer->setNext(loser);
    }else{
        team = nullptr;
        loserContainer->setNext(loser);
    }
}

void Team::printLoser(Node*& loserContainer){ //prints loserContainer in a LIFO manner
    Node* printLoser = loserContainer;
    cout << "Your loser list(LIFO): ";
    while(printLoser != nullptr){
        cout << printLoser->getName() << " ";

        printLoser = printLoser->getNext();
    }
    cout << endl;
}

void Team::resetLoserContainer(Node*& loserContainer){ //de-allocates loserContainer
    Node* garbage = nullptr;
    while(loserContainer != nullptr){
        garbage = loserContainer;
        delete garbage->getChar(); //added 05192019
        loserContainer = loserContainer->getNext();
        delete garbage;
    }
}

void Team::moveBack(Node*& team){ //moves winner to the back of team
    Node* tempWinner = team;

    if(tempWinner->getNext() != nullptr){
    while(tempWinner->getNext() != nullptr){
        tempWinner = tempWinner->getNext();
    }
        tempWinner->setNext(team);
        team = team->getNext();

        tempWinner = tempWinner->getNext();
        tempWinner->setNext(nullptr);
    }
}

void Team::resetTeam(Node*& team1, Node*& team2){ //de-allocates team1 and team2
    Node* garbage = nullptr;
    while(team1 != nullptr){
        garbage = team1;
        delete garbage->getChar(); //added 05192019
        team1 = team1->getNext();
        delete garbage;
    }

    while(team2 != nullptr){
        garbage = team2;
        delete garbage->getChar(); //added 05192019
        team2 = team2->getNext();
        delete garbage;
    }

}

void Team::recovery(Node*& team){ //recovery function for winner in team fight
    int damageTaken = 0;
    double recoverRange = (rand() % 10 + 1); //range between 1 - 10 for recovery
    int recoverAmount = 0;
    if(team->getChar()->getType() == "Vampire"){
        damageTaken = 18 - (team->getChar()->getStrengthPoints()); //total damage taken amount
        recoverAmount = recoverRange * damageTaken / 10;
        cout << "Strength recovery amount: " << recoverAmount  << endl;
        team->getChar()->setStrengthPoints(recoverAmount + team->getChar()->getStrengthPoints());
    }else if(team->getChar()->getType() == "Barbarian"){
        damageTaken = 12 - (team->getChar()->getStrengthPoints()); //total damage taken amount
        recoverAmount = recoverRange * damageTaken / 10;
        cout << "Strength recovery amount: " << recoverAmount  << endl;
        team->getChar()->setStrengthPoints(recoverAmount + team->getChar()->getStrengthPoints());
    }else if(team->getChar()->getType() == "BlueMen"){
        damageTaken = 12 - (team->getChar()->getStrengthPoints()); //total damage taken amount
        recoverAmount = recoverRange * damageTaken / 10;
        cout << "Strength recovery amount: " << recoverAmount  << endl;
        team->getChar()->setStrengthPoints(recoverAmount + team->getChar()->getStrengthPoints());
    }else if(team->getChar()->getType() == "Medusa"){
        damageTaken = 8 - (team->getChar()->getStrengthPoints()); //total damage taken amount
        recoverAmount = recoverRange * damageTaken / 10;
        cout << "Strength recovery amount: " << recoverAmount  << endl;
        team->getChar()->setStrengthPoints(recoverAmount + team->getChar()->getStrengthPoints());
    }else if(team->getChar()->getType() == "HarryPotter"){
        if(team->getChar()->getStrengthPoints() > 10){
            damageTaken = 20 - (team->getChar()->getStrengthPoints()); //total damage taken amount (considers Hogwarts Revive)
            recoverAmount = recoverRange * damageTaken / 10;
            cout << "Strength recovery amount: " << recoverAmount  << endl;
            team->getChar()->setStrengthPoints(recoverAmount + team->getChar()->getStrengthPoints());
        }else{
            damageTaken = 10 - (team->getChar()->getStrengthPoints()); //total damage taken amount
            recoverAmount = recoverRange * damageTaken / 10;
            cout << "Strength recovery amount: " << recoverAmount  << endl;
            team->getChar()->setStrengthPoints(recoverAmount + team->getChar()->getStrengthPoints());
        }
    }else{
        cout << "Type Error" << endl;
    }

}

void Team::fight(Node*& team1, Node*& team2){ //head of team1 and team2 fights
    int round = 0;
    int team1score = 0;
    int team2score = 0;
    while(team1 != nullptr && team2 != nullptr){
        cout << "Round: #"<< ++round << endl;
        cout << "Team 1's[ " << team1->getChar()->getType() << " Name: " << team1->getName()
             << "] vs. " << "Team 2's: [" << team2->getChar()->getType() << " Name: " << team2->getName() << "]" << endl;
        while(team1->getChar()->getStrengthPoints() > 0 && team2->getChar()->getStrengthPoints() > 0){
            if(team1->getChar()->getStrengthPoints() > 0){ //player1 always attacks first
                int player1Attack = team1->getChar()->attack();
                team2->getChar()->defend(player1Attack);
            }
            if(team2->getChar()->getStrengthPoints() > 0){
                int player2Attack = team2->getChar()->attack();
                team1->getChar()->defend(player2Attack);
            }
        }
        if (team1->getChar()->getStrengthPoints() > team2->getChar()->getStrengthPoints()){ //round result
            cout << team1->getChar()->getType() << ": " << team1->getName() << " WINS with Strength Points: " << team1->getChar()->getStrengthPoints() << endl;
            recovery(team1);
            cout << team1->getChar()->getType() << ": " << team1->getName() << " recovers to Strength Points: " << team1->getChar()->getStrengthPoints() << endl;
            moveBack(team1);
            loserRemove(team2, loserContainer);
            team1score += 2; //winning team gains 2 points
            team2score -= 1; //losing team loses 1 point

        }
        else{
            cout << team2->getChar()->getType() << ": " << team2->getName() << " WINS with Strength Points: " << team2->getChar()->getStrengthPoints() << endl;
            recovery(team2);
            cout << team2->getChar()->getType() << ": " << team2->getName() << " recovers to Strength Points: " << team2->getChar()->getStrengthPoints() << endl;
            moveBack(team2);
            loserRemove(team1, loserContainer);
            team2score += 2; //winning team gains 2 points
            team1score -= 1; //losing team loses 1 point

        }
    } //results
    cout << "***************" << endl;
    cout << "Result:" << endl;
    cout << "Team 1 score: " << team1score << endl;
    cout << "Team 2 score: " << team2score << endl;

    if(team1score > team2score){
        cout << "***************" << endl;
        cout << "Team 1 WINS!!!!" << endl;
        cout << "***************" << endl;
    }else if(team2score > team1score){
        cout << "***************" << endl;
        cout << "Team 2 WINS!!!!" << endl;
        cout << "***************" << endl;
    }else{
        cout << "***************" << endl;
        cout << "Both teams TIE!" << endl;
        cout << "***************" << endl;
    }
}

int Team::inputValidation(string message, int min, int max){ //input validation to accept integers only
    double input;
    bool repeatEntry = true;
    char errorTest;
    string inputLine;
    while (repeatEntry == true) {
        cout << message << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> input)) {
            cout << "Input was not a number. Please try again." << endl;
        } else if ((input < min) || (input > max)) {
            cout << "Input out of range. Please try again." << endl;
        } else if (input - static_cast<int>(input) != 0) {
            cout << "Input with decimals and not an integer. Please try again." << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters. Please try again." << endl;
        } else {
            repeatEntry = false;
            input = input;
            cout << "Input accepted." << endl;
        }
    }
    return input;
}

void Team::menu() { //driver function for the fantasy combat game
    bool menuRun = true;
    while (menuRun) {
        int userInput = inputValidation("Welcome to Team Fantasy Combat Game. Press 1 for to START. Press 2 for END.", 1, 2);
        if (userInput == 1) { //ask if user wants to play
            int teamSize = inputValidation("Please enter the size of each team. Specify between 1 and 10", 1, 10); //ask for size of team
            for (int i = 0; i < teamSize; i++) {
                int team1Type = inputValidation(
                        "Add for team 1. \n[1]Vampire, [2]Barbarian, [3]Blue Men, [4]Medusa, [5]Harry Potter", 1, 5);
                cout << "Please enter character name." << endl; //specify character type and name to add to team
                string charName;
                getline(cin, charName);
                add(team1, charName, team1Type);

            }

            for (int i = 0; i < teamSize; i++) {
                int team2Type = inputValidation(
                        "Add for team 2. \n[1]Vampire, [2]Barbarian, [3]Blue Men, [4]Medusa, [5]Harry Potter", 1, 5);
                cout << "Please enter character name." << endl; //specify character type and name to add to team
                string charName;
                getline(cin, charName);
                add(team2, charName, team2Type);
            }

            cout << "Team has been set for both teams. Let's battle!" << endl;
            fight(team1, team2); //team1 and team2 fights
            int printLoserInput = inputValidation(
                    "Would you like to print the list of losers? Press 1 for YES, Press 2 for NO", 1, 2);
            if (printLoserInput == 1) {
                printLoser(loserContainer);
            }
            resetLoserContainer(loserContainer);
            resetTeam(team1, team2);
        } else {
            menuRun = false;
            cout << "Program ended. Thank you." << endl;
        }
    }
}