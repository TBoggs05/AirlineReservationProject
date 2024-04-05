#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
}

LinkedList::LinkedList(Linked_List* aList)
{
	if (aList->head = NULL) {
		this->head = NULL;
	}
	else {
		this->head = new Node;
		this->head->data = alist->head->data;
		this->head->next = NULL;
		Node* a_move = alist->head;
		Node* h_move = this->head;
		while (a_move->next != NULL) {
			a_move = a_move->next;
			h_move->next = new Node;
			h_move = h_move->next;
			h_move->data = a_move->data;
			h_move->next = NULL;
		}
	}
}

void LinkedList::LinkedList_copy(Node* another)
{
	if (another == NULL)
		head = NULL;
	else {
		head = new Node;
		head->data = another->data;
		Node* a_move = another;
		Node* h_move = head;

		while (a_move->next != NULL)//copy the rest if nay
		{
			a_move = a_move->next;
			h_move->next = new Node; //create a new node
			h_move = h_move->next; //move to the new node
			h_move->data = a_move->data;
			h_move->next = NULL;
		}

	}
}

bool LinkedList::insert_node(Node* n)
{
	if (head == NULL)
	{
		head = n;
		return true;
	}
	else if (head->data > n->data)
	{
		n->next = head;
		head = n;
	}
	else {
		Node* pre, * cur;
		pre = head;
		cur = head->next;
		while (cur != NULL && cur->data < n->data) //find the position
		{
			pre = cur;
			cur = cur->next;
		}
		n->next = cur;
		pre->next = n;

		return true;
	}
}


bool LinkedList::delete_node(Node* n)
{
	if (head == NULL)
	{
		return false;
	}
	else if (head->data == n->data)
	{
		Node* del;
		del = head;
		head = head->next;
		delete del;
	}
	else {
		Node* pre, * cur;
		pre = head;
		cur = head->next;
		while (cur != NULL && cur->data != n->data)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur != NULL)
		{
			pre->next = cur->next;
			return true;
		}
		else
			return false;
	}
}

void LinkedList::print_list()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int LinkedList::list_size()
{
	Node* temp = head;
	int cnt = 0;
	while (temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}
	return cnt;
}
int LinkedList::search_node(Node* n)
{
	int position = 1;
	if (head == NULL)
		return -1;
	else if (head->data == n->data)
		return 1;
	else {
		Node* temp = head->next;
		while (temp != NULL && temp->data != n->data)
		{
			position++;
			temp = temp->next;
		}
		if (temp != NULL)
			return position + 1;
		else
			return -1;
	}
}
