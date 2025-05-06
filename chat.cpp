//  Develop an elementary chatbot for any suitable customer interaction application
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to generate bot responses based on user input
string generateResponse(const string &userInput)
{
    // Simple logic for generating responses
    if (userInput == "hello")
    {
        return "Hi there! How can I assist you today?";
    }
    else if (userInput == "how are you?")
    {
        return "I'm just a program, but thanks for asking!";
    }
    else if (userInput == "bye")
    {
        return "Goodbye! Have a great day!";
    }
    else
    {
        return "Sorry, I didn't understand that. Can you please rephrase?";
    }
}

int main()
{
    string userInput;

    cout << "Welcome! How can I assist you today?" << endl;
    cout << "You can start typing your questions or messages." << endl;
    cout << "Type 'bye' to exit the chat." << endl;

    // Main interaction loop
    while (true)
    {
        cout << "You: ";
        getline(cin, userInput);

        // Convert user input to lowercase for easier processing
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        // Check for exit command
        if (userInput == "bye")
        {
            cout << "Bot: Goodbye! Have a great day!" << endl;
            break;
        }

        // Generate and output bot response
        cout << "Bot: " << generateResponse(userInput) << endl;
    }

    return 0;
}
