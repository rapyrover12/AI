#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char input[100];

    cout << "Welcome to EasyHelp Customer Service Bot!\n";
    cout << "You can ask about store hours, location, delivery, returns, and more.\n";
    cout << "Type 'exit' to end the chat.\n";

    while (true) {
        cout << "\nYou: ";
        cin.getline(input, 100);

        if (strcmp(input, "exit") == 0) {
            cout << "Bot: Thank you for chatting with us! Goodbye!\n";
            break;
        }
        else if (strcmp(input, "What are your store hours?") == 0) {
            cout << "Bot: We are open from 9 AM to 9 PM, Monday to Sunday.";
        }
        else if (strcmp(input, "Do you offer home delivery?") == 0) {
            cout << "Bot: Yes, we offer free home delivery for orders above Rs. 500.";
        }
        else if (strcmp(input, "Where is your store located?") == 0) {
            cout << "Bot: Our store is located near Main Market, City Center, next to ABC Mall.";
        }
        else if (strcmp(input, "What is your return policy?") == 0) {
            cout << "Bot: You can return products within 7 days with the original bill.";
        }
        else if (strcmp(input, "Do you accept digital payments?") == 0) {
            cout << "Bot: Yes, we accept UPI, debit/credit cards, and net banking.";
        }
        else if (strcmp(input, "Do you have cash on delivery?") == 0) {
            cout << "Bot: Yes, cash on delivery is available for orders below Rs. 2000.";
        }
        else if (strcmp(input, "How can I contact customer support?") == 0) {
            cout << "Bot: You can call us at 1800-123-456 or email help@easyhelp.com.";
        }
        else if (strcmp(input, "Are there any current offers?") == 0) {
            cout << "Bot: Yes! Get 10% off on your first online order using code WELCOME10.";
        }
        else {
            cout << "Bot: Sorry, I didn't understand that. Please ask something else.";
        }
    }

    return 0;
}
