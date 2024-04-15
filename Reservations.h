#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <iostream>
#include <fstream>	// to open database file
#include <cstdlib>
#include "LinkedList.h" // LinkedList class
using namespace std;

class Reservation
{
public:
	Reservation();
	// constructor initializes data to database
	char menu();
	//reservation system menu  
	void start();
	// starts user input
	void search();
	// allows user to display specific passenger info
	void insert();
	// allows user to make a new passenger reservation
	void remove();
	// allows user to cancel a reservation
	void print();
	// prints list of all passengers
	void changeFood();
	// user can change food preference of passenger
	void changeSeat();
	// user can change seat of passenger if available
	void copyDatabase();
	// linked_list is initialized to database
	void produceReport();
	//produces a report of food choices and total passengers signed up.
private:
	LinkedList obj1;
	// declare an object of the linked list class
	int ID;
	// stores id for search functions		
};

#endif
