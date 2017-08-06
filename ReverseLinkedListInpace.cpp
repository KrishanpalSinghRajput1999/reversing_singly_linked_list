//============================================================================
// Name        : ReverseLinkedListInpace.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;
/*
 * Singlely Linked list
 *
 * |1|->|2|->|3|->|4|->|5|
 * First Element is preserved in a variable called "head" and last node points no other Element (NULL)
 *
 *
 * head -> |1|->|2|->|3|->|4|->|5|-> NULL
 *
 * 1) Sinlgely linked list is a collection of Elements where each element is linked to next element along with its data.
 * 2) So each element contains two parts one Data of its own and two Pointer to next element of its own kind (another node)
 * 3) As each element contains reference (pointer) to next element of its own kind, definition (structure) of Element is recursive
 *    As shown in struct Node; As struct Node contains self reference to next element- these are also called self referencing structures.
 * 2) We need to preserve the address of the first node to traverse (read/visit) the list in a singly list, say head..
 *    first element is called head element and its reference is stored in a variable named "head"
 *
 *    Reversed List
 *
 *    NULL <- |5|<-|4|<-|3|<-|2|<-|1|<- reversehead
 *
 */

//Definition of Node

struct Node {
	int key;
	struct Node *next;
};

/*  Building Linked list
 *
 *  1)  We keeep head node fixed throughout building of list pointing to first node |1|
 *  2)  current Node keeps reference to currently building node
 *  3) previous Node keeps reference to previous built node
 *         -------
 *   head =  |1|->
 *           -------
 *
 *   First Iteration of for Loop (previous and head point same noade
 *           -------
 *    previous = head =  |1|->|
 *           -------
 * ===========================================
 *   Second iteration
 *
 *   |1|->|2|->
 *    ^     ^
 *    |     |
 *  Pre  Current
 * ==========================================================
 * Third iteration
 * |1|->|2|->|3|->|4|->|5|->NULL
 *       ^    ^
 *       |    |
 *      Prev Current (node)
 *
 *      1. We keeep head fixed throughout building of list pointing to first node |1|
 */

Node* buildList() {
	Node *head, *current, *previous;

	head = new Node();
	head->key = 1;
	head->next=NULL;
	current = head;

	for (int i = 2; i < 5; i++) {
		previous = current;
		current = new Node();
		current->key = i;
		previous->next = current;
		previous = current;

	}
	previous->next = NULL;
	return head;

}
Node* reverselist(Node* list) {

	Node *currentnode, *previousnode, *nextnode;

	previousnode = list;

	//previous -> current -> next

	currentnode = previousnode->next;
	previousnode->next = NULL; //new tail

	while (currentnode) {
		nextnode = currentnode->next;
		currentnode->next = previousnode;
		previousnode = currentnode;
		currentnode=nextnode;
	}
	return previousnode;

}
void printList(Node* list){
	while (list) {
			cout << list->key << endl;
			list = list->next;
		}

}

int main(void) {

	Node* head = buildList(); //Build singly linked list ***  head -> |1|->|2|->|3|->|4|->|5|->NULL
	cout << "print original list " << endl;
	printList(head);

	////////////////////// REVERSE ===============

	Node* reversehead = reverselist(head);  //Reverse the list *** reversehead ->  |5|->|4|->|3|->|2|->|1|->NULL
	cout << " Print Reversed list " << endl;
	printList(reversehead);


	return EXIT_SUCCESS;
}
