// added libraries for the program
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declared variables for the inputs
    int combatStyle = 0;
    string weapon;
    string spell;
    // Requested combat style input from the user
    cout << "Choose a style (1=Melee -or- 2=Magic): ";
    cin >> combatStyle;

    // Conditional to check if the number is valid
    if (combatStyle == 1 || combatStyle == 2){

        //conditional request based on combat style choice
        switch(combatStyle) {

            // case for melee choice
            case 1:

                cout << "\nChoose a weapon (dagger or scimitar): ";
                cin >> weapon;

                // conditional to check if weapon is valid
                if (weapon == "dagger" || weapon == "scimitar") {
                    
                    if (weapon == "dagger") {
                        cout << "\nThe dagger weapon  causes " << 10 * 1.3 <<  " damage with bonus 1.3.\n";
                    } else {
                        cout << "\nThe scimitar weapon  causes " << 10 * 2.7 <<  " damage with bonus 2.7.\n";
                    }

                } else {
                    cout << "Error: Invalid weapon\n";
                }

                break;

            //case for majic choice
            case 2:

                cout << "\nChoose a spell (bolt or blast): ";
                cin >> spell;

                // conditional to check if spell is valid
                if (spell == "bolt" || spell == "blast") {

                    if (spell == "blast") {
                        cout << "\nThe blast spell  causes " << 10 * 3 <<  " damage with bonus 3.\n";
                    } else {
                        cout << "\nThe bolt spell  causes " << 10 * 1.9 <<  " damage with bonus 1.9.\n";
                    }

                } else {

                    cout << "Error: Invalid spell\n";

                }

                break;
        }

    } else if (cin.fail()) {
        // invalid input
        cout << "Error: Invalid number\n";

    } else {
        cout << "Error: Invalid selection\n";
    }



    return 0;
}