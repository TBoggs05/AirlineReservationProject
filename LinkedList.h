#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include<string>
struct Node {
	std::string firstName;
	std::string lastName;
	std::string address;
	int passengerID;
	int reservationNum;
	int phoneNum;
	int seatNum;
	std::string menuPref;
	Node* next;
};

class LinkedList
{
private:
	int count;
	Node* head;
public:
	LinkedList();
	~LinkedList();
	LinkedList(Linked_List*);
	void LinkedList_copy(Node*);
	bool insert_node(Node*);
	bool delete_node(Node*);
	void print_list();
	int list_size();
	int search_node(Node* n);
};

#endif