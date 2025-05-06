# Simple Restaurant Reservation Chatbot

def greet():
    print("Hello! Welcome to Sunny Restaurant's Reservation Bot.")
    print("I'm here to help you book a table. Type 'exit' to quit.")

def process_reservation(name, num_people, time):
    # Simulate availability: max 10 people per time slot
    max_capacity = 10
    if num_people > max_capacity:
        print(f"Sorry, {name}, we can't accommodate {num_people} people at {time}.")
        print("We have a maximum capacity of 10 per slot.")
        print("Would you like to book for fewer people or another time? (Type 'yes' or 'no')")
        return False
    else:
        print(f"Reservation confirmed for {name}!")
        print(f"Details: {num_people} people at {time}.")
        print("Thank you for choosing Sunny Restaurant!")
        return True

def main():
    greet()
    while True:
        print("\nHow can I assist you? (Type 'book' to make a reservation or 'exit' to quit)")
        user_input = input().lower()

        if user_input == 'exit':
            print("Goodbye! Have a great day!")
            break
        elif user_input == 'book':
            print("Great! Let's make a reservation.")
            print("Please enter your name:")
            name = input()
            print("How many people in your party?")
            num_people = input()
            # Basic validation
            if not num_people.isdigit() or int(num_people) <= 0:
                print("Invalid number of people. Please try again.")
                continue
            num_people = int(num_people)
            print("What time would you like to book? (e.g., 7PM)")
            time = input()

            # Process the reservation
            success = process_reservation(name, num_people, time)
            if not success:
                retry = input().lower()
                if retry != 'yes':
                    print("Okay, let me know if you want to try again later!")
        else:
            print("Sorry, I didn't understand. Please type 'book' or 'exit'.")

if __name__ == "__main__":
    main()