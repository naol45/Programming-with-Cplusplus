// added libraries for the program
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Declared variables
    int combatLevel = 0;
    int slayerLevel = 0;
    char slayerMaster = 'A';
    int slayerM = 0;

    // User input for combat level
    cout << "Combat Level: ";
    cin >> combatLevel;

    // Error handling and validate combat level
    if (cin.fail()) {
        cout << "Error: Invalid number" << endl;
    } else if (combatLevel < 3) {
        cout << "Error: Minimum combat level is 3" << endl;
    } else if (combatLevel > 126) {
        cout << "Error: Maximum combat level is 126" << endl;
    } else {

        // User input for slayer level
        cout << "\nSlayer Level: ";
        cin >> slayerLevel;

        // Error handling and validate slayer level
        if (cin.fail()) {
            cout << "Error: Invalid number" << endl;
        } else if (slayerLevel < 1) {
            cout << "Error: Minimum slayer level is 1" << endl;
        } else if (slayerLevel > 99) {
            cout << "Error: Maximum slayer level is 99" << endl;
        } else {

            // User input for slayer master
            cout << "\n(T/t)urael\n(D/d)uradel\n(K/k)onar\nSelection: ";
            cin >> slayerMaster;
            slayerMaster = toupper(slayerMaster);

            

            // Error handling
            if (slayerMaster == 'T' || slayerMaster == 'D' || slayerMaster == 'K') {
                // Variable assignment for switch condtionals
                if (slayerMaster == 'T') {
                    slayerM = 1;
                } else if (slayerMaster == 'D') {
                    slayerM = 2;
                } else if (slayerMaster == 'K') {
                    slayerM = 3;
                }
                // Choice handling
                switch (slayerM) {

                    // T
                    case 1:
                         // Header
                        cout << setw(10) << left << "\nMonster";
                        cout << setw(13) << right << "Probability";
                        cout << setw(15) << right << "Max Assigned" <<endl;

                        // line separter output
                        cout << setfill('-') << setw(37) << "" <<endl;

                        //Kalphite output
                        cout << setfill(' ') << setw(9) << left << "Kalphite";
                        cout << setw(13) << right << "74%";
                        cout << setw(15) << right << "15" <<endl;

                        //Ankou output
                        cout << setw(9) << left << "Ankou";
                        cout << setw(13) << right << "24%";
                        cout << setw(15) << right << "25" <<endl;

                        //Dragon output
                        cout << setw(9) << left << "Dragon";
                        cout << setw(13) << right << "0%";
                        cout << setw(15) << right << "0" <<endl;

                        //Boss output
                        cout << setw(9) << left << "Boss";
                        cout << setw(13) << right << "2%";
                        cout << setw(15) << right << "1" <<endl;

                    break;

                    // D
                    case 2:
                        if (combatLevel < 100 || slayerLevel < 50) {
                            cout << "Error: Must have combat level 100 and slayer level 50 to visit Duradel" << endl;
                        } else if (combatLevel >= 100 && slayerLevel < 75){

                            cout << "Kill counts halved because of slayer level" << endl;
                            // Header
                            cout << setw(10) << left << "\nMonster";
                            cout << setw(13) << right << "Probability";
                            cout << setw(15) << right << "Max Assigned" <<endl;

                            // line separter output
                            cout << setfill('-') << setw(37) << "" <<endl;

                            //Kalphite output
                            cout << setfill(' ') << setw(9) << left << "Kalphite";
                            cout << setw(13) << right << "30%";
                            cout << setw(15) << right << "60" <<endl;

                            //Ankou output
                            cout << setw(9) << left << "Ankou";
                            cout << setw(13) << right << "50%";
                            cout << setw(15) << right << "125" <<endl;

                            //Dragon output
                            cout << setw(9) << left << "Dragon";
                            cout << setw(13) << right << "0%";
                            cout << setw(15) << right << "0" <<endl;

                            //Boss output
                            cout << setw(9) << left << "Boss";
                            cout << setw(13) << right << "20%";
                            cout << setw(15) << right << "2" <<endl;
                        } else {
                            // Header
                            cout << setw(10) << left << "\nMonster";
                            cout << setw(13) << right << "Probability";
                            cout << setw(15) << right << "Max Assigned" <<endl;

                            // line separter output
                            cout << setfill('-') << setw(37) << "" <<endl;

                            //Kalphite output
                            cout << setfill(' ') << setw(9) << left << "Kalphite";
                            cout << setw(13) << right << "30%";
                            cout << setw(15) << right << "120" <<endl;

                            //Ankou output
                            cout << setw(9) << left << "Ankou";
                            cout << setw(13) << right << "50%";
                            cout << setw(15) << right << "250" <<endl;

                            //Dragon output
                            cout << setw(9) << left << "Dragon";
                            cout << setw(13) << right << "0%";
                            cout << setw(15) << right << "0" <<endl;

                            //Boss output
                            cout << setw(9) << left << "Boss";
                            cout << setw(13) << right << "20%";
                            cout << setw(15) << right << "5" <<endl;
                        }
                    break;

                    // K
                    case 3:
                        if (combatLevel < 75) {
                            cout << "Error: Must have combat level 75 to visit Konar" << endl;
                        } else {
                            // Header
                            cout << setw(10) << left << "\nMonster";
                            cout << setw(13) << right << "Probability";
                            cout << setw(15) << right << "Max Assigned" <<endl;

                            // line separter output
                            cout << setfill('-') << setw(37) << "" <<endl;

                            //Kalphite output
                            cout << setfill(' ') << setw(9) << left << "Kalphite";
                            cout << setw(13) << right << "25%";
                            cout << setw(15) << right << "30" <<endl;

                            //Ankou output
                            cout << setw(9) << left << "Ankou";
                            cout << setw(13) << right << "35%";
                            cout << setw(15) << right << "100" <<endl;

                            //Dragon output
                            cout << setw(9) << left << "Dragon";
                            cout << setw(13) << right << "20%";
                            cout << setw(15) << right << "100" <<endl;

                            //Boss output
                            cout << setw(9) << left << "Boss";
                            cout << setw(13) << right << "20%";
                            cout << setw(15) << right << "2" <<endl;
                        }
                    break;
                    
                }
            } else {
                cout << "Error: Invalid slayer master selection" << endl;
            }

        }

    }

    
    
    return 0;
}