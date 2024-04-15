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

		cout << "\n---------------------MENU-----------------------\n";
		cout << "\t 1\tEnter a reservation\n";
		cout << "\t 2\tCancel a reservation\n";
		cout << "\t 3\tPrint a passenger list\n";
		cout << "\t 4\tSearch for a passenger\n";
		cout << "\t 5\tChange Reservation Seat\n";
		cout << "\t 6\tChange Reservation Food\n";
		cout << "\t 7\tProduce Food+Passenger Report\n";
		cout << "\t 8\tCopy List Content to TextFile\n";
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
			case '7': produceReport(); break;
			case '8': copyDatabase(); break;
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
	//CONVERTS IMPORTANT SORTING STRINGS TO ALL LOWERCASE FOR CONVENIENCE!!
	for(int i = 0; i < menuPref.size(); i++){
		menuPref[i] = tolower(menuPref[i]);
	}
	for(int i = 0; i < lastName.size(); i++){
		lastName[i] = tolower(lastName[i]);
	}
	for(int i = 0; i < firstName.size(); i++){
		firstName[i] = tolower(firstName[i]);
	}
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

	//obj1.change_Food(ID);
	Node* curr = obj1.getHead();
	std::string new_menuPref;
	while(curr != NULL && curr->passengerID != ID){
		curr = curr->next;
	}
	if(curr == NULL){
		std::cout << "\nPassenger NOT found\n";
	}
	else if (curr->passengerID == ID) {
		std::cout << "\nEnter new menu preference: ";
		std::cin >> new_menuPref;
		for(int i = 0; i < new_menuPref.size(); i++){
		new_menuPref[i] = tolower(new_menuPref[i]);
	}
		curr->setMenu(new_menuPref);
		std::cout << "\n Menu preference CHANGED!\n";
	}
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
	//obj1.change_Seat(ID);
	Node* curr = obj1.getHead();
	int newSeat;

	while(curr != NULL && curr->passengerID != ID){
		curr = curr->next;
	}
	if(curr == NULL){
		std::cout << "\nPassenger NOT found\n";
	}
	else if (curr->passengerID == ID) {
		std::cout << "Enter new seat number: ";
		std::cin >> newSeat;
		

		Node* temp = obj1.getHead();
		bool taken = false;
		while(temp != NULL){
			if(newSeat == temp->seatNum)
				taken = true;
			temp = temp->next;
		}


		if (!taken) {
			curr->setSeat(newSeat);
			std::cout << "\nSeat CHANGED!\n";
		}
		else {
			std::cout << "\nSeat is already taken, or is already the current seat!\n";
		}
	}
}
/*
-COPY DATABASE FUNCTION
-does a print of the linked list, but to a text file instead of to output.
*/
void Reservation::copyDatabase()
{
	std::fstream stream;
	stream.open("reservation_database.txt", fstream::out);
	//if it didnt actually open, return.
	if(!stream.is_open()){
		std::cout<<"writing to text file failed. Try again."<<std::endl;
		return;
	}
	//if it did open, write to text document.
	else{
		if (obj1.list_size() == 0) {
		stream << "NO RESERVATIONS!\n";
		stream.close();
		return;
	}
	Node* temp = obj1.getHead();
	while (temp != NULL)
	{
		stream << "--------------------------------------------------------------------\n";
		stream << "PASSENGER: " << temp->firstName << " " << temp->lastName << "\n";
		stream << "ADDRESS: " << temp->address << "\n";
		stream << "Passenger_ID: " << temp->passengerID << "\n";
		stream << "RESERVATION_NUMBER: " << temp->reservationNum << "\n";
		stream << "PHONE_NUMBER: " << temp->phoneNum << "\n";
		stream << "SEAT_NUMBER: " << temp->seatNum << "\n";
		stream << "MENU_PREFERENCE: " << temp->menuPref << "\n";
		temp = temp->next;
	}
	stream << "\n";
	stream << "total passengers: "<<obj1.list_size();
	stream << "--------------------------------------------------------------------\n";
	stream << "\n";


	std::cout<<"Database File has been created in this directory!"<<std::endl;
	stream.close();
	return;
	}
}
/*
produces a report, including total passengers and food preferences.
*/
void Reservation::produceReport()
{
	std::cout<<"REPORT:";
	std::cout<<"Total passengers on plane: "<<obj1.list_size()<<std::endl;
	std::cout<<"Food preferences:"<<std::endl;
	int numBeef = 0;
	int numChicken = 0;
	int numFish = 0;
	int numVegetables = 0;
	int numOthers = 0;
	Node* temp = obj1.getHead();
	while(temp != NULL){
		if(temp->menuPref == "beef"){
			numBeef++;
		}
		else if(temp->menuPref == "chicken"){
			numChicken++;
		}
		else if(temp->menuPref == "fish"){
			numFish++;
		}
		else if(temp->menuPref == "vegetables"){
			numVegetables++;
		}
		else{
			numOthers++;
		}
		temp = temp->next;
	}
	std::cout<<"Beef: "<<numBeef<<std::endl;
	std::cout<<"Chicken: "<<numChicken<<std::endl;
	std::cout<<"Fish: "<<numFish<<std::endl;
	std::cout<<"Vegetables: "<<numVegetables<<std::endl;
	std::cout<<"Other: "<<numOthers<<std::endl;
}