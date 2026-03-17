// this is code for project 1
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
using namespace std;

// using this later 
enum menuChoice {
    ADD = 1,
    SUBTRACT = 2,
    DISPLAY = 3,
    GIVEUP = 4,
    EXIT = 5
};

int main() {
    srand(time(0));  // // not sure if this goes here. this is for rand number

    string username;
    bool isValid;
    int playerPoints = 100;
    int num1, num2, input;
    bool displayed = false;  //to check for displayed
    bool exitGame = false;   // to stop the game
    menuChoice choice;// to declare choice

    // this is the intro screen of the game
    cout << "+-------------------------------------------------+" << endl;
    cout << "|         Computer Science and Engineering        |" << endl;
    cout << "|         CSCE 1030 - Computer Science I          |" << endl;
    cout << "|Somtochukwu Anyanwu soa0083@my.unt.edu           |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    // end of intro
	// asking user and seeing if its valid or not
    while (true) {
        cout << "Enter your name: ";
        getline(cin, username);
        isValid = true;

        for (char c : username) {
            if (!isalpha(c) && !isspace(c)) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Your name can only have alphabets or spaces. Enter again." << endl;
            continue;
        }

        // Capitalize name correctly
        bool newWord = true;
        for (int i = 0; i < username.length(); i++) {
            if (isspace(username[i])) {
                newWord = true;
            } else if (newWord) {
                username[i] = toupper(username[i]);
                newWord = false;
            } else {
                username[i] = tolower(username[i]);
            }
        }

        cout << "Welcome " << username << "!" << endl;
        break;
    }

    
    while (playerPoints >= 0 && !exitGame) {
        // Generate two random numbers, ensuring num1 < num2
        do {
            num1 = rand() % 51 + 100;  // Random number between 100-150
            num2 = rand() % 51 + 100;
        } while (num1 >= num2);

        cout << "Your two random numbers have been generated." << endl;

        do {
            // Menu display
            cout << "ADD(1)" << endl;
            cout << "SUBTRACT(2)" << endl;
            cout << "DISPLAY(3)" << endl;
            cout << "GIVEUP(4)" << endl;
            cout << "EXIT(5)" << endl;

            cout << "Enter your number (1-5): ";
            cin >> input;

            choice = static_cast<menuChoice>(input);

            switch (choice) {
                case ADD: {
                    int guess;
                    cout << "Guess the sum of two random numbers: ";
                    cin >> guess;

                    int sumofnum = num1 + num2;
                    if (abs(sumofnum - guess) < 5) {
                        playerPoints += 5;
                        cout << "Correct! Current points: " << playerPoints << endl;
                    } else {
                        playerPoints -= 1;
                        cout << "WRONG! Current points: " << playerPoints << endl;
                    }

                    // End game if points fall below zero
                    if (playerPoints < 0) {
                        cout << "Game over! Your points fell below zero." << endl;
                        exitGame = true;
                    }
                    break;
                }

                case SUBTRACT: {
                    int guess;
                    cout << "Guess the difference between two random numbers: ";
                    cin >> guess;

                    int differenceofnum = num2 - num1;
                    if (abs(differenceofnum - guess) < 5) {
                        playerPoints += 5;
                        cout << "Correct! Current points: " << playerPoints << endl;
                    } else {
                        playerPoints -= 1;
                        cout << "WRONG! Current points: " << playerPoints << endl;
                    }

                    if (playerPoints < 0) {
                        cout << "Game over! Your points fell below zero." << endl;
                        exitGame = true;
                    }
                    break;
                }

                case DISPLAY:
                    if (!displayed) {
                        cout << "First number: " << num1 << endl;
                        playerPoints -= 3;
                        displayed = true;

                        if (playerPoints < 0) {
                            cout << "Game over! Your points fell below zero." << endl;
                            exitGame = true;
                        }
                    } else {
                        cout << "Error: You have already displayed the number." << endl;
                    }
                    break;

                case GIVEUP:
                    cout << "The numbers were " << num1 << " and " << num2 << "." << endl;
                    char playAgain;
                    cout << "Do you want to play again? (Y/N): ";
                    cin >> playAgain;

                    if (tolower(playAgain) != 'y') {
                        cout << "Goodbye, " << username << ". Your final points: " << playerPoints << endl;
                        exitGame = true;
                    } else {
                        displayed = false;  // Reset display flag for new round
                    }
                    break;

                case EXIT:
                    cout << "You have quit the game. Final points: " << playerPoints << endl;
                    exitGame = true;  // Exit game
                    break;

                default:
                    cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                    break;
            }

        } while (choice != GIVEUP && choice != EXIT && playerPoints >= 0 && !exitGame);// will continue until user says otherwise
	/* having an issue with 'choice' being declared. for some reason it doesn't 
	   identify with the 'mainChoice choice' */
    }

    if (playerPoints < 0) {
        cout << "Game over! Your points fell below zero." << endl;
    }

    return 0;
}
