/*********************************************************************
** Program name: Node.hpp
** Author: David Lee
** Date: 05/25/2019
** Description: Node class header file that contains the accessor and mutator member functions.
 *              The Node class has data members;
 *              next, a pointer to the next Node object.
 *              character, a pointer to the character object.
 *              name, string value storing the character name.
 *              The Node class also has a constructor that takes in the character pointer,
 *              name of character and a pointer to the next Node object.
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP
#include "Character.hpp"

class Node {
private:
    Node* next; //pointer to next node object
    Character* character; //stores character object
    string name; //stores string name
public:
    Node(); //constructor
    Node(Character* character, string name, Node* next); //constructor with parameters
    ~Node(); //destructor
    Node* getNext(); //returns pointer to next Node object
    void setNext(Node* next); //set pointer to next Node object
    string getName(); //accessor to character name
    Character* getChar(); //accessor to character object
};


#endif
