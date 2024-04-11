//Trace Boggs and Juan Juarez
//Project #3: Airline Reservation Simulation
//CS2413 Data Structures
//April 17, 2024
//Instructor: Dr.Zhao
//This assignment is a simulation of an Airline reservation system, handling one flight.
//it utilizes a linked list to store passenger's and their data in Nodes, ordered alphabetically.
//then, a reservation class handles various functions from a main menu, including updating reservations, seating, food
//and printing a menu.
//5 total files: LinkedList.h, LinkedList.cpp, Reservation.h, Reservation.cpp, and main.cpp.
#include "LinkedList.h"

using namespace std;

int main()
{
    char condition[2];
    //dud is populated to test copy constructors.
    LinkedList* dud = new LinkedList();
    Node* x = new Node();
    Node* y = new Node();
    Node* z = new Node();
    dud->insert_node(x);
    dud->insert_node(y);
    dud->insert_node(z);
    LinkedList list(dud); //tests copy constructor, just initialize it normally to not test that!
    do {
        int input = 0;
        cout << "LINKED_LIST_TEST_MENU:" << endl;
        cout << "1-insert node. 2-delete node. 3-search for a node. 4-test copyfunction. 5-test copyconstructor. 6-printList. 7-listSize"<<endl;
        cin >> input;
        cin.ignore();
        if (input == 1) {
            Node* toInsert = new Node;
            cout << "enter first,last,addr,passID,resNum,phoneNum,seatNum,and menuPref in that order. "<<endl;
            getline(cin, toInsert->firstName);
            getline(cin, toInsert->lastName);
            getline(cin, toInsert->address);
            cin >> toInsert->passengerID;
            cin >> toInsert->reservationNum;
            cin.ignore();
            getline(cin, toInsert->phoneNum);
            cin >> toInsert->seatNum;
            cin.ignore();
            getline(cin, toInsert->menuPref);
            list.insert_node(toInsert);
            cout << "Node inserted!" << endl;
        }   
        else if (input == 2) {
            long ID;
            cout << "enter the passengerID of who you would like to Remove:" << endl;
                cin >> ID;
            list.delete_node(ID);

        }
        else if (input == 3) {
            long ID;
            cout << "enter the passengerID of the passenger you would like to find:" << endl;
            cin >> ID;
            int index = list.search_node(ID);
            if (index == -1) {
                std::cout << "NOT FOUND" << std::endl;
            }
            else {
                std::cout << "FOUND AT INDEX: " << index << std::endl;
            }

        }
        else if (input == 4) {
            std::cout << "overwriting list with dud..." << std::endl;
            list.LinkedList_copy(dud->getHead());

        }
        else if (input == 5) {
            std::cout << "THIS HAS TO BE TESTED IN SOURCE CODE BY MODIFYING CONSTRUCTOR!" << std::endl;
        }
        else if (input == 6) {
            list.print_list();
        }
        else if (input == 7) {
            std::cout << list.list_size() << std::endl;

        }
        else{
            cout << "WRONG" << endl;

        }
        cout << "go again?(y/n)" << endl;
        cin >> condition[0];
    } while (tolower(condition[0]) == 'y');
    cout << "exiting..." << endl;
    return 0;
}
