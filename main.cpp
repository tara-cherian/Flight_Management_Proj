#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

#include "main.h"
using namespace std;

const string flightInfo = "flight_info.txt";

void pressReturnToContinue() {
    cin.clear();
    cin.get();
}

void display_header() {
    cout << "Version: 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced by: Salem, Tara, Asher" << endl;
    cout << "Year: 2023" << endl;
    cout << "\n<<<Press Return to Continue>>>" << endl;
}

void populate_flight_from_file(Flight &flight) {
    flight.readDataFromFile(flightInfo);
}

int menu() {
    int choice;
    cout << "\nPlease select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passengers Information" << endl;
    cout << "3. Add a New Passenger" << endl;
    cout << "4. Remove an Existing Passenger" << endl;
    cout << "5. Save data" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
    cin >> choice;
    return choice;
}

int main() {
    display_header();

    Flight flight;
    Airline airline;
    populate_flight_from_file(flight);
    airline.addFlight(flight);

    int choice;
    do {
        cout << "<<<Press Return to Continue>>>" << endl;
        pressReturnToContinue();

        choice = menu();
        do{
            pressReturnToContinue();

        }while(false);
       
        switch (choice) {

            case 1:{
                flight.displaySeatMap();
                break;
            }
            case 2: {
                flight.displayPassengerInformation();
                break;
            }
            case 3: {
                string fName, lName, phone,id;
                int row;
                char seat;
                bool validInput = false;
                cout << "Enter the passenger's first name: ";
                cin >> fName;
                cout << "Enter the passenger's last name: ";
                cin >> lName;
                cout << "Enter the passenger's phone number: ";
                cin >> phone;
                cout << "Enter the passenger's ID: ";
                cin >> id;
                while (!validInput) {
                    cout << "Enter the passenger's desired row: ";
                    string rowInput;
                    cin >> rowInput;

                    validInput = true;
                    for (char c : rowInput) {
                        if (!isdigit(c)) {
                            validInput = false;
                            cout << "Please enter a valid integer for the row: ";
                            break;
                        }
                    }

                    if (validInput) {
                        row = stoi(rowInput);
                        break; 
                    }

                    cin.clear(); 
                }
                cout << "Enter the passenger's desired seat (A-F): ";
                cin >> seat;
                flight.addPassenger(fName, lName, phone, id , row, seat);
                break;
            }
            case 4: {
                string id;
                cout << "Enter the ID of the passenger to be removed: ";
                cin >> id;
                flight.removePassenger(id);
                break;
            }
            case 5: {
                char YorN;
                cout << "Do you want to save the data in the ""flight_info.txt""? Please answer <Y or N> ";
                cin >> YorN;
                if(YorN == 'Y'){
                    flight.saveDataToFile(flightInfo);
                } else if(YorN != 'N') {
                    cout <<"Invalid Choice"<<endl;
                }
                pressReturnToContinue();
                break;
            }
            case 6: {
                cout << "Program terminated." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                pressReturnToContinue();

                break;
        }

    } while (choice != 6);
    return 0;
}
