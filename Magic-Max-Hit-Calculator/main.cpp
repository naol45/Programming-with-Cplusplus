// added libraries for the program
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    // Defined variables for all numbers
    int majicLevel = 0;
    int majicBonus = 0;
    int fireBoltBD = 12;
    int fireBlastBD = 16;
    int fireWaveBD = 20;
    int boltMaxHit = 0;
    int blastMaxHit = 0;
    int waveMaxHit = 0;

    // promt for the user to input the values
    cout << "Enter your Magic level: ";
    cin >> majicLevel;

    cout << "Enter your Magic bonus: ";
    cin >> majicBonus;

    // calculations
    boltMaxHit = (fireBoltBD * (1 + (majicLevel/100.0)) * sqrt(1 + (majicBonus/100.0)));
    blastMaxHit = (fireBlastBD * (1 + (majicLevel/100.0)) * sqrt(1 + (majicBonus/100.0)));
    waveMaxHit = (fireWaveBD * (1 + (majicLevel/100.0)) * sqrt(1 + (majicBonus/100.0)));
    
    // Header
    cout << setw(14) << left << "\nSpell";
    cout << setw(11) << left << "BaseDmg";
    cout << setw(8) << left << "Level";
    cout << setw(5) << right << "Bonus";
    cout << setw(9) << right << "MaxHit" <<endl;

    // line separter output
    cout << setfill('-') << setw(46) << "" <<endl;

    //Fire bolt output
    cout << setfill(' ') << setw(13) << left << "Fire Bolt";
    cout << setw(11) << left << fireBoltBD;
    cout << setw(8) << left << majicLevel;
    cout << setw(5) << right << majicBonus;
    cout << setw(9) << right << boltMaxHit <<endl;

    //Fire blast output
    cout << setw(13) << left << "Fire Blast";
    cout << setw(11) << left << fireBlastBD;
    cout << setw(8) << left << majicLevel;
    cout << setw(5) << right << majicBonus;
    cout << setw(9) << right << blastMaxHit <<endl;

    //Fire wave output
    cout << setw(13) << left << "Fire Wave";
    cout << setw(11) << left << fireWaveBD;
    cout << setw(8) << left << majicLevel;
    cout << setw(5) << right << majicBonus;
    cout << setw(9) << right << waveMaxHit <<endl;
    

    return 0;
}