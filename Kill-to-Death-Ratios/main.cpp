// included requited libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Declared varible
    int userInput = 0;
    const int arraySize = 10;
    int killArray[arraySize];
    int deathArray[arraySize];
    int kSum = 0;
    int dSum = 0;
    int kAverage = 0;
    int dAverage = 0;
    int newKill = 0;
    int newDeath = 0;
    char cont = ' ';
    int c = 0;

    // prompt to the user to enter input
    cout << "K/D File 1/2/3? ";
    cin >> userInput;

    // error handling for input
    while (cin.fail() || userInput < 1 || userInput > 3) {
    cout << "Error: invalid selection" << endl;

    cin.clear();
    cin.ignore(100, '\n');

    cout << "K/D File 1/2/3? ";
    cin >> userInput;
    }

    // input file stream for kill file
    string kFileName = "kills" + to_string(userInput) + ".txt";
    ifstream killInput;
    killInput.open(kFileName);
    
    // input file stream for death file
    string dFileName = "deaths" + to_string(userInput) + ".txt";
    ifstream deathInput;
    deathInput.open(dFileName);

    // loop to record file data to array
    while(c < arraySize && (killInput >> killArray[c])){
        deathInput >> deathArray[c];
        c++;
        if (c == arraySize) {
            cout << "\nArray full\n";
            break;
        }
    }

    killInput.close();
    deathInput.close();

    // for loop to add sum of all inputs in the arrays
    for(int i = 0; i < c;) {
        kSum = kSum + killArray[i];
        dSum = dSum + deathArray[i];
        i++;
    }

    // Average calculation
    if (c == 0) {
        kAverage = kSum / 1;
        dAverage = dSum / 1;
    }else {
        kAverage = kSum / c;
        dAverage = dSum / c;
    }
    

    // output file averages
    cout << "\nFile Average k/d: " << kAverage<< " : " << dAverage << endl;

    // conditional to check if array is already full
    if (c < arraySize){
         // promted users for a new kill and new death
        cout << "\nNew kill: ";
        cin >> newKill;
        cout << "New death: ";
        cin >> newDeath;

        // updating the Arrays
        killArray[c] = newKill;
        deathArray[c] = newDeath;
        c++;
        
        // calculating the new average
        kSum = 0;
        dSum = 0;
        for(int i = 0; i < c;) {
            kSum = kSum + killArray[i];
            dSum = dSum + deathArray[i];
            i++;
        }

        // new Average calculation
        kAverage = kSum / c;
        dAverage = dSum / c;


        // new output file averages
        cout << "\nAverage k/d: " << kAverage<< " : " << dAverage << endl;

        // prompt for user to continue or stop
        cout << "\n(c)ontinue (any other key to quit)? ";
        cin >> cont;

        // conditional to check if user wants to continue
        while (cont == 'c' && c < arraySize){
            // promted users for a new kill and new death
            cout << "\nNew kill: ";
            cin >> newKill;
            cout << "New death: ";
            cin >> newDeath;

            // updating the Arrays
            killArray[c] = newKill;
            deathArray[c] = newDeath;
            c++;
            
            // calculating the new average
            kSum = 0;
            dSum = 0;
            for(int i = 0; i < c;) {
                kSum = kSum + killArray[i];
                dSum = dSum + deathArray[i];
                i++;
            }

            // new Average calculation
            kAverage = kSum / c;
            dAverage = dSum / c;

            // new output file averages
            cout << "\nAverage k/d: " << kAverage<< " : " << dAverage << endl;

            // check if array is full
            if (c >= arraySize) {
                cout << "\nArray full\n";
                break;
            }

            // prompt for user to continue or stop
            cout << "\n(c)ontinue (any other key to quit)? ";
            cin >> cont;
        }

    }

    // output file stream for kill file
    ofstream killOutput;
    killOutput.open(kFileName);
    
    // output file stream for death file
    ofstream deathOutput;
    deathOutput.open(dFileName);

    // write arrays to output files
    for(int i = 0; i < c; i++) {
        killOutput << killArray[i] << endl;
        deathOutput << deathArray[i] << endl;
    }

    killOutput.close();
    deathOutput.close();
   
    
    return 0;
}