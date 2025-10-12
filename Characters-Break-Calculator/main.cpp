// included neccecary libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // defined all variables
    string inputFile;
    ifstream iFile;
    ofstream oFile;
    string character;
    int breaktime = 0;
    int downtime = 0;
    int delaytime = 0;
    int backin = 0;
    int lineNumber = 1;

    // first user input
    cout << "Character Break File: ";
    cin >> inputFile;
    iFile.open(inputFile);
    
    // Error handling
    while (!iFile.is_open()) {
        cout << "Error: Invalid filename\n";
        cout << "Character Break File: ";
        cin >> inputFile;
        iFile.open(inputFile);
    }
    
    // opened an outfile to contain all the outputs
    oFile.open("howLongTilCharacter.txt");

    // A way of diregarding the header
    string header;
    getline(iFile, header);

    // a loop to go over all the inputs, compute them and output on the output file
    while (iFile >> character) {
        // line counter
        lineNumber++;
        
        if (iFile >> breaktime >> downtime >> delaytime) {
            if (breaktime < 0 || downtime < 0 || delaytime < 0) {
                cout << "Error: Invalid number detected on line " << lineNumber << endl;
            } else {
                backin = (breaktime - downtime) + delaytime;
                oFile << character << " will be back in " << backin << " minutes" << endl;
            }
        } else {
            cout << "Error: Invalid number detected on line " << lineNumber << endl;
            iFile.clear(); 
            string junk;
            getline(iFile, junk);
        }
    }

    // closed out all open files
    iFile.close();
    oFile.close();

    return 0;
}