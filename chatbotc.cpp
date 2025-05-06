#include <iostream>
#include <cstring>
using namespace std;

// Maximum string length
#define MAX_STR 50

// Function to greet the user
void greet() {
    cout << "Hello! Welcome to Sunny Restaurant's Reservation Bot." << endl;
    cout << "I'm here to help you book a table. Type 'exit' to quit." << endl;
}

// Function to check if a string is a valid positive number
bool isValidNumber(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    int num = atoi(str);
    return num > 0;
}

// Function to process a reservation
bool processReservation(char* name, int numPeople, char* time) {
    const int maxCapacity = 10;
    if (numPeople > maxCapacity) {
        cout << "Sorry, " << name << ", we can't accommodate " << numPeople << " people at " << time << "." << endl;
        cout << "We have a maximum capacity of 10 per slot." << endl;
        cout << "Would you like to book for fewer people or another time? (Type 'yes' or 'no'): ";
        return false;
    } else {
        cout << "Reservation confirmed for " << name << "!" << endl;
        cout << "Details: " << numPeople << " people at " << time << "." << endl;
        cout << "Thank you for choosing Sunny Restaurant!" << endl;
        return true;
    }
}
12
int main() {
    char input[MAX_STR], name[MAX_STR], time[MAX_STR], numPeopleStr[MAX_STR];
    char retry[MAX_STR];

    greet();
    while (true) {
        cout << "\nHow can I assist you? (Type 'book' to make a reservation or 'exit' to quit): ";
        cin >> input;

        // Convert input to lowercase (manual)
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                input[i] = input[i] + 32;
            }
        }

        if (strcmp(input, "exit") == 0) {
            cout << "Goodbye! Have a great day!" << endl;
            break;
        } else if (strcmp(input, "book") == 0) {
            cout << "Great! Let's make a reservation." << endl;
            cout << "Please enter your name: ";
            cin.ignore(1, '\n'); // Clear newline
            cin.getline(name, MAX_STR);

            cout << "How many people in your party? ";
            cin >> numPeopleStr;

            // Validate number of people
            if (!isValidNumber(numPeopleStr)) {
                cout << "Invalid number of people. Please try again." << endl;
                continue;
            }
            int numPeople = atoi(numPeopleStr);

            cout << "What time would you like to book? (e.g., 7PM): ";
            cin.ignore(1, '\n');
            cin.getline(time, MAX_STR);

            // Process reservation
            bool success = processReservation(name, numPeople, time);
            if (!success) {
                cin >> retry;
                // Convert retry to lowercase
                for (int i = 0; retry[i] != '\0'; i++) {
                    if (retry[i] >= 'A' && retry[i] <= 'Z') {
                        retry[i] = retry[i] + 32;
                    }
                }
                if (strcmp(retry, "yes") != 0) {
                    cout << "Okay, let me know if you want to try again later!" << endl;
                }
            }
        } else {
            cout << "Sorry, I didn't understand. Please type 'book' or 'exit'." << endl;
        }
    }

    return 0;
}