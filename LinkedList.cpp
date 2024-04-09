#include "LinkedList.h"

/*
Default Constructor:
-Sets our Head to NULL
*/
LinkedList::LinkedList()
{
	head = NULL;
	count = 0;
}
/*
-Destructor
-Frees Memory from each node in linked List
*/
LinkedList::~LinkedList()
{
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
/*
Copy Constructor:
-Creates a LinkedList, starting with an old List as a base.
-Just reuses the LinkedList_copy() function, starting with aList->head.
*/
LinkedList::LinkedList(LinkedList* aList)
{
	LinkedList_copy(aList->getHead());


}
/*
COPY FUNCTION
-Takes in a Node Pointer, which is assumed to be the head of a list.
-We copy that list to our current linkedList, overwriting existing data if there is any.
-TWO CASES EXIST:
-CASE 1: otherList is NULL, so we just copy NULL to head and thats it.
-Case 2: otherList is not NULL, so copy over all node Data using setData Node Function.
@Returns VOID
*/
void LinkedList::LinkedList_copy(Node* another)
{
	if (another == NULL) {
		head = NULL;
		count = 0;
	}
	else {
		head = new Node();
		head->setData(another->firstName, another->lastName, another->address, another->passengerID, another->reservationNum, another->phoneNum, another->seatNum, another->menuPref, another->next);
		count++;
		Node* a_move = another;
		Node* h_move = head;

		while (a_move->next != NULL)//copy the rest if any
		{
			a_move = a_move->next;
			h_move->next = new Node(); //create a new node
			h_move = h_move->next; //move to the new node
			h_move->setData(a_move->firstName, a_move->lastName, a_move->address, a_move->passengerID, a_move->reservationNum, a_move->phoneNum, a_move->seatNum, a_move->menuPref, a_move->next);
			count++;
			h_move->next = NULL;
		}

	}
}
/*
 INSERT NODE FUNCTION
-Function will insert a Node into the List based on Alphabetical Order
-If the list is empty, add to front. Otherwise, insert alphabetically.
@RETURNS BOOL (to show whether insertion was successful or not)
*/
bool LinkedList::insert_node(Node* n)
{
	//error catch case, returns false.
	if (n == NULL) {
		return false;
	}
	//list is empty, insert at head.
	if (head == NULL)
	{
		head = n;
		count++;
		return true;
	}
	//n's last name is earlier in the alphabet than heads lastname
	else if (head->compareLastName(n))
	{
		n->next = head;
		head = n;
		count++;
	}
	else {
		Node* pre, * cur;
		pre = head;
		cur = head->next;
		//go until lastName of N is later in the alphabet than pre
		while (cur != NULL && !(pre->compareLastName(n))) //find the position
		{
			pre = cur;
			cur = cur->next;
		}
		n->next = cur;
		pre->next = n;
		count++;
		return true;
	}
}
/*
DELETE NODE FUNCTION
-deletes the first instance of that node
-(in a case where there are more than one instances of n, it will only delete the first instance after head.)
-however, since every node has a unique ID, we can guarantee this will delete the intended node.
-assumes unique ID and an already alphabetically sorted list.
@RETURNS BOOL (to show whether deletion was successful or not)
*/
bool LinkedList::delete_node(long ID)
{
	//if list is null, nothing to delete
	if (head == NULL)
	{
		std::cout << "NOTHING TO DELETE!" << std::endl;
		return false;
	}
	//compares them by unique passenger ID's to avoid deleting people with same names.
	//this statement checks if the first node is the node to delete.
	else if (head->passengerID == ID)
	{
		count--;
		Node* del;
		del = head;
		head = head->next;
		delete del;
		return true;
	}
	/*
	gives us a pre and cur node pointer to work with
	they both move through the while loop until n is found via passengerID, or until the loop is out
	if not found, return false. else, pre->next = cur->next. then free cur.
	*/
	else {
		Node* pre, * cur;
		pre = head;
		cur = head->next;
		//loop until n is found
		while (cur != NULL && cur->passengerID != ID)
		{
			pre = cur;
			cur = cur->next;
		}
		//if n was found...
		if (cur != NULL)
		{
			std::cout << "deleted!" << std::endl;
			count--;
			pre->next = cur->next;
			delete cur; //free memory
			return true;
		}
		//n was not found..
		else {
			std::cout << "no such passenger exists!" << std::endl;
			return false;
		}
	}
}
/*
PRINT LIST FUNCTION
-loops through the entire list printing data for each Node(Passenger)
@RETURNS VOID
*/
void LinkedList::print_list()
{
	if (count == 0) {
		std::cout << "NO RESERVATIONS!" << std::endl;
		return;
	}
	Node* temp = head;
	while (temp != NULL)
	{
		std::cout << "--------------------------------------------------------------------\n";
		std::cout << "PASSENGER: " << temp->firstName << " " << temp->lastName<<std::endl;
		std::cout << "ADDRESS: " << temp->address << std::endl;
		std::cout << "ID: " << temp->passengerID << std::endl;
		std::cout << "RESERVATION_NUMBER: " << temp->reservationNum << std::endl;
		std::cout << "PHONE_NUMBER: " << temp->phoneNum << std::endl;
		std::cout << "SEAT_NUMBER: " << temp->seatNum << std::endl;
		std::cout << "MENU_PREFERENCE: " << temp->menuPref << std::endl;
		temp = temp->next;
	}
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << std::endl;
}
/*
LIST SIZE FUNCTION
-simply returns the count variable which is updated every time nodes are deleted/removed(including constructors)
@RETURNS INTEGER
*/
int LinkedList::list_size()
{
	return count;
}
/*
SEARCH FOR NODE FUNCTION
-searches through the linked list until the node with the proper passengerID is found
-assumes unique passengerID's for all passengers + list is already sorted alphabetically
-NOTE: this could be used in delete to clean up logic, but keeping separate for now in case changes have to be made.
*/
int LinkedList::search_node(long ID)
{
	int position = 1;
	//if list is empty, return -1(doesnt exist)
	if (head == NULL)
		return -1;
	//if head is the searched for node, return 1(head index)
	else if (head->passengerID == ID)
		return 1;
	//if it is after head, loop until end of list(node is null), and find n.
	//each loop, update position to represent the index of the node
	//when n is found or list is at end, terminate loop and return either position+1(index) or -1(not found)
	//just like in delete, we check for passenger ID since it is unique, and we assume the list is already sorted
	//alphabetically.
	else {
		Node* temp = head->next;
		while (temp != NULL && temp->passengerID != ID)
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
