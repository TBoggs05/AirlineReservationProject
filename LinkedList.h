#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include<iostream>
#include<string>

struct Node {
	//passenger data for each passenger Node
	std::string firstName;
	std::string lastName;
	std::string address;
	int passengerID;
	long reservationNum;
	std::string phoneNum;
	int seatNum;
	std::string menuPref;
	Node* next;
	//constructor that sets next to NULL by default, and everything else to blank or -1.
	Node() {
		next = NULL;
		firstName = lastName = address = phoneNum = menuPref = " ";
		reservationNum = -1;
		passengerID = seatNum = -1;
	}
	//public functions to streamline Linked List operations.
	/*
	* simply sets data as passed.
	@RETURNS VOID
	*/
	void setData(std::string first, std::string last, std::string addr, int passID, long resNum, std::string pNum, int sNum, std::string mPref, Node* n) {
		firstName = first;
		lastName = last;
		address = addr;
		passengerID = passID;
		reservationNum = resNum;
		phoneNum = pNum;
		seatNum = sNum;
		menuPref = mPref;
		next = n;
	}
	void setMenu(std::string mPref) {
		menuPref = mPref;
	}
	void setSeat(int sNum) {
		seatNum = sNum;
	}
	/*
	-checks for alphabetical order.
	-uses built in compare function, which uses ASCII Values.
	-returns 1 if objects lastName is EARLIER in the alphabet than the compared Node's lastName.
	-returns 0 otherwise
	-If both lastnames are equal, we compare firstNames.
	@RETURNS BOOL
	*/
	bool compareLastName(Node* other) {
		//if lastNames are equal, check firstNames.
		if (this->lastName == other->lastName) {
			//other firstName comes earlier in the alphabet than this firstName
			if (this->firstName > other->firstName) {
				return 1;
			}
			//vice versa
			else {
				return 0;
			}
		}
		//other lastName comes earlier in the alphabet than this lastName
		if (this->lastName > other->lastName) {
			return 1;
		}
		//vice versa
		else {
			return 0;
		}
	}

};


class LinkedList
{
private:
	int count;//# of nodes
	Node* head;//first node. (linear linked list)
public:
	LinkedList();//initializes linked list
	~LinkedList();//frees memory used by linkedList
	LinkedList(LinkedList*);//initialize a linked list with another linkedList.
	void LinkedList_copy(Node*);//copy a linked list to our linked list, overwriting our data.
	bool insert_node(Node*);//inserts node alphabetically using Node's compareLastName() function
	bool delete_node(long);//deletes a node after finding it based on ID
	void print_list();//prints each node's data
	int list_size();//returns count
	void change_Food(long);// changes food option;
	void change_Seat(long); //changes seat number; 
	int search_node(long);//searches for a node based on ID
	
	int search_node_seat(int);
	
	bool Is_ID_taken(long); // checks the avaliability of ID
	bool Is_Seat_taken(int); // cheks the avaliability of seat number
	Node* getHead() { return head; }//inline function to return head(only useful for copy function)

};

#endif
