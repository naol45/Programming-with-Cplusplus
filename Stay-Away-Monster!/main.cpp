#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;


int main () {
    // Declared variable for the players postion
    int playerX = 0;
    int playerY = 0;

    // Declared variable for the monssters postion
    int monsterX = 0;
    int monsterY = 0;

    // Requested the input data from the user
    cout << "Player x: ";
    cin >> playerX;

    cout << "Player y: ";
    cin >> playerY;

    cout << "\nMonster x: ";
    cin >> monsterX;

    cout << "Monster y: ";
    cin >> monsterY;

    cout << "\nDistances from Player to Monster:";


    // Decalred varables and computed the calculations
    int xDist = abs(playerX - monsterX);
    int yDist = abs(playerY - monsterY);
    float manDist = xDist + yDist;
    float eucDist = sqrt((xDist * xDist) + (yDist * yDist));

    // display the calculated values
    cout << "\nX-Axis:" << setfill('.') << setw(15) << right << xDist << endl;
    cout << setfill('-') << setw(xDist + 1) << left << "p" << "m" << endl;

    cout << "\nY-Axis:" << setfill('.') << setw(15) << right << yDist << endl;
    cout << setfill('-') << setw(yDist + 1) << left << "p" << "m" << endl;

    cout << "\nManhattan:" << setfill('.') << setw(12) << right << manDist << endl;
    cout << setfill('-') << setw(manDist + 1) << left << "p" << "m" << endl;

    cout << "\nEuclidean:" << setfill('.') << setw(12) << right << fixed << setprecision(2) <<  eucDist << endl;
    cout << setfill('-') << setw(eucDist + 1) << left << "p" << "m" << endl;

    


    return 0;
}