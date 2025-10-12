// added libraries for the program
#include <iostream>

using namespace std;

int main() {

    //Defined variables
    int playerHealth = 10;
    int monsterHealth = 10;
    int userInput = 0;
    int turn = 1;

    // Game system handling
    do {

        // Health level output
        cout << "Player Health: " << playerHealth << endl;
        cout << "Monster Health: " << monsterHealth << endl;

        // Condtional to handle user input
        do {

            cout << "\n1-Stab -or- 2-Slash: ";
            cin >> userInput;
            if (cin.fail() || (userInput != 1 && userInput != 2)) {
                cout << "Error: Invalid selection";
            }
            cin.clear();
            cin.ignore(1000, '\n');

        } while (cin.fail() || (userInput != 1 && userInput != 2));

        // condtional to determine turn and compute the results
        if (turn % 2 == 0) {
            //conditional to determine user method of attack
            if (userInput == 1){

                playerHealth = playerHealth - 2;
                monsterHealth = monsterHealth - 2;
                cout << "\nYou stab the monster causing 2 damage" << endl;
                cout << "The monster shoots a fire ball at you causing 2 damage" << endl << endl;

            } else {
                playerHealth = playerHealth - 2;
                monsterHealth = monsterHealth - 3;
                cout << "\nYou slash the monster causing 3 damage" << endl;
                cout << "The monster shoots a fire ball at you causing 2 damage" << endl << endl;
            }
        } else {
            cout << "\nThe monster blocks your attack" << endl << endl;
        }
        turn = turn + 1;

        // condtional to determine who won
        if (playerHealth <= 0 && monsterHealth > 0){
            cout << "The monster killed you" << endl;
        } else if (monsterHealth <= 0 && playerHealth > 0){
            cout << "You killed the monster" << endl;
        } else if (playerHealth <= 0 && monsterHealth <= 0 ){
            cout << "The player and monster killed eachother" << endl;
        }
    } while (playerHealth > 0 && monsterHealth > 0);

    return 0;
}