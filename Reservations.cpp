#include "Reservations.h"
#include "LinkedList.h"

/*
Default Constructor
Creates an instance for LinkedList                             DONE
*/
Reservation::Reservation()
{
	LinkedList obj1;
}

/*
Display's users menu options                                   DONE
*/
char Reservation::menu()
{
	/*  This is the menu for the user. The menu displays the choices the user has.
	The user will enter a character, and that character will be returned to be used
	in the start function of the reservation class.*/
	{
		string choice;

		cout << "\n\t\tMenu\n";
		cout << "\t 1\tEnter a reservation\n";
		cout << "\t 2\tCancel a reservation\n";
		cout << "\t 3\tPrint a passenger list\n";
		cout << "\t 4\tSearch for a passenger\n";
		cout << "\t 5\tChange Reservation Seat\n";
		cout << "\t 6\tChange Reservation Food\n";
		cout << "\t 0\tEXIT\n";

		cout << "\nEnter your choice: ";
		cin >> choice;	// user input


		return choice[0];	// returns user input
	}

}
/*
Starts the progam and prompts for options                      DONE
Loops if asked to do so.
*/
void Reservation::start()
{
	/* once this function is called, a loop will be created that allows the user to input how they want the list to be manipulated.
	Functions include insert, remove, print,search, changeSeat, and changeFood. If user enters '0', then the loop will terminate.*/
	{
		bool done = false;	// done boolean
		do {
			char choice = menu(); //get the choice from the user
			switch (choice)
				/*this switch compares the choice entered
				  by the user to determine which function to call.*/
			{
			case '1': insert(); break;
			case '2': remove(); break;
			case '3': print(); break;
			case '4': search(); break;
			case '5': changeSeat(); break;
			case '6': changeFood(); break;
			case '0': done = true; break;
			default: cout << "INVALID, please enter one of the options from our menu" << endl;
			}
		} while (!done); // if done, then quit, else continue

		cout << "\nThank you for using my simulation." << endl;

	}
}

/*
 Search through Reservation class for specific passenger         DONE
*/
void Reservation::search()
{
	// Declares the variable ID
	long ID;

	// checks if there are any passengers in list
	if (obj1.list_size() != 0) {

		// if there are, prompts user for passenger ID
		cout << "\nPlease enter the Passenger's ID that you're looking for: ";
		cin >> ID;

			// checks to see if search_node returns an integer 1
			// stating that there was a match
			if (obj1.search_node(ID) >= 1) {
				long position = obj1.search_node(ID);

				// if matched then output confirmation
				cout << "\nPassenger with ID number: " << ID << " was found at position: " << position << endl;


			}
			else {
				//if match not found then output results
				cout << "\nPassenger with ID number: " << ID << " was NOT found." << endl;
			}
	}
	else {
		// There were no passengers to search for
		cout << "\nThere are currently no passengers with reservations, please make a reservation first" << endl;
	}
}

/*
Inserts a new passenger into the Reservation by collecting
information that was prompted in the menu					   DONE
*/
void Reservation::insert()
{
	// declares variables needed to insert into node
	std::string firstName, lastName, address, phoneNum, menuPref;
	int passengerID, seatNum;
	long reservationNum;

	// prompts the user for information about passenger
	std::cout << "\nEnter passenger details:\n";
	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "Last Name: ";
	std::cin >> lastName;
	std::cout << "Address: ";
	std::cin.ignore();
	std::getline(cin, address);

	std::cout << "Passenger ID: ";
	std::cin >> passengerID;
	if (obj1.Is_ID_taken(passengerID) == true) {

	    while(obj1.Is_ID_taken(passengerID) == true){
		    std::cout << "\noops! That passenger ID is already taken, please enter an original ID. \nPassenger ID: ";
		    std::cin >> passengerID;
	    }
	}
	
	std::cout << "Reservation Number: ";
	std::cin >> reservationNum;
	std::cout << "Phone Number: ";
	std::cin >> phoneNum;
	std::cout << "Seat Number: ";
	std::cin >> seatNum;
	if (obj1.Is_Seat_taken(seatNum) == true) {
        std:: cout << "here\n";
	    while(obj1.Is_Seat_taken(seatNum) == true){
		    std::cout << "\noops! This seat is already taken, please enter a new seat number. \nSeat Number: ";
		    std::cin >> seatNum;
	    }
	}	
	std::cout << "Menu Preference: ";
	std::cin >> menuPref;

	// Create a new Node with passenger data
	Node* newNode = new Node();
	newNode->setData(firstName, lastName, address, passengerID, reservationNum, phoneNum, seatNum, menuPref, nullptr);

	// Insert the new passenger into the linked list
	bool inserted = obj1.insert_node(newNode);
	if (inserted) {
		// passenger status: INSERTED
		cout << "\nPassenger successfully added!\n";
	}
	else {
		// passenger status: NOT INSERTED
		cout << "\nPassenger was not added.\n";
	}


}

/*
Allowes user to remove a passenger from the Reservation        DONE
*/
void Reservation::remove()
{
	// Declared the variable needed
	long ID;

	// Prompts the user for the passengers ID
	if (obj1.list_size() != 0) {
		cout << "\nPlease enter the ID of the reservation you'd like to cancel: ";
		cin >> ID;

		// If the passenger was succesfully removed then...
		bool del = obj1.delete_node(ID);
		if (del) {
			// passenger status: REMOVED
			cout << "\nPassenger sucessfully removed!";
		}
		else {
			// passenger status: NOT REMOVED
			cout << "\nPassenger was not removed!";
		}
	}
	else {
		cout << "There are currently no reservations to cancel." << endl;
	}

}

/*
Prints information from all the passengers                     DONE
*/
void Reservation::print()
{
	obj1.print_list();
}

/*
Allowes the user to change their food option
*/
void Reservation::changeFood()
{
	long ID;
	string newPref;

	cout << "\nPlease enter your Passenger ID: ";
	cin >> ID;

	obj1.change_Food(ID);


}

/*
* Prompts the user to change their seat on airplane
*/
void Reservation::changeSeat()
{
	long ID;
	int newSeatNum;

	cout << "\nPlease enter your Passenger ID: ";
	cin >> ID;

	obj1.change_Seat(ID);
}
/*

*/


void Reservation::copyDatabase()
{
}
