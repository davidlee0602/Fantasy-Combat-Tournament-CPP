/*********************************************************************
** Program name: Node.cpp
** Author: David Lee
** Date: 05/25/2019
** Description: Node class implementation file that contains the accessor and mutator member functions.
 *              The Node class has data members;
 *              next, a pointer to the next Node object.
 *              character, a pointer to the character object.
 *              name, string value storing the character name.
 *              The Node class also has a constructor that takes in the character pointer,
 *              name of character and a pointer to the next Node object.
*********************************************************************/

#include "Node.hpp"
#include <ctime>
#include <random>

Node::Node() : next(nullptr), character(nullptr), name(""){ //constructor

}

Node::Node(Character* character, string name, Node* next){ //constructor with parameters
    this->character = character;
    this->name = name;
    this->next = next;
    srand(time(0));
}

Node::~Node(){ //destructor

}

Node* Node::getNext(){ //accessor to next node object
    return next;
}

void Node::setNext(Node* next){ //mutator that sets next node object
    this->next = next;
}

string Node::getName(){ //accessor to character name stored in node object
    return name;
}

Character* Node::getChar(){ //accessor to character object stored in node object
    return character;
}