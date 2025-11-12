// included nececcary libraries
#include <iostream>
#include <fstream>

using namespace std;

//  functions
// open file function

void openFile(ifstream &file, string prompt) {
    string fileName = "";
    bool first = true;
    do{
        file.clear();
        if (!first){
            cout << "Error: Invalid filename\n";
        }
        cout << prompt;
        cin >> fileName;
        file.open(fileName);
        first = false;
    } while(!file.is_open());
}

// inventory reading
void readInventory(string names[], int quantities[], int &readCnt) {
    // defined parsing variables
    string oneLine = "";
    int index = 0;
    string name = "";
    int quantity = 0;
    // opeaning file
    ifstream inventory;
    openFile(inventory, "Inventory File: ");
    //reading file
    getline(inventory, oneLine);
    getline(inventory, oneLine);
    while (!oneLine.empty()){
        if (oneLine.empty()) {
            continue; 
        }
        index = oneLine.find(",");
        name = oneLine.substr(0, index);
        quantity = stoi(oneLine.substr(index + 1));

        names[readCnt] = name;
        quantities[readCnt] = quantity;

        readCnt = readCnt + 1;
        getline(inventory, oneLine);

    }
    inventory.close();
}

// displaing inventory
void displayInventory(string names[], int quantities[], int readCnt) {
    int i = 0;
    cout << "Inventory:\n";
    while (i < readCnt){
        cout << "  " << i + 1 << ") " << names[i] << ": " << quantities[i] <<endl;
        i += 1;
    }
}

// creat poitions
void createPotions(string names[], int quantities[], int &inventorySize){
    // opeaning file
    ifstream poitionFile;
    openFile(poitionFile, "Potions File: ");

    // finding the index of potion base
    int pbIndex = inventorySize + 1;
    int i = 0;
    while(i < inventorySize){
        if (names[i] == "potion base"){
            pbIndex = i;
            break;
        }
        i += 1;
    }
    // reading the open file
    // initializing variables
    string poitionType = "";
    int poitionQty = 0;
    string reqMix = "";
    int cost = 0;

    while (poitionFile >> poitionType >> poitionQty){
        // print out the quantity and type
        cout << poitionQty << " " << poitionType << " potions requested\n";

        // rules
        if (poitionType == "attack"){
            reqMix = "eye of newt";
            cost = 2;
        } else if (poitionType == "strength"){
            reqMix = "limpwurt root";
            cost = 1;
        } else if (poitionType == "defense"){
            reqMix = "white berries";
            cost = 10;
        }

        // check if there are enought potion base for one
        if ((quantities[pbIndex] < 1) || pbIndex == inventorySize + 1){
            cout << "Error: Not enough potion base to make " << poitionType << " potions\n";
            continue;
        }

        // finding the index of the required mixin
        int index = 0;
        while(index < inventorySize){
            if (names[index] == reqMix){
                break;
            }
            index += 1;
        }

        // check if there are enought mix in qty for one
        if (quantities[index] < cost || names[index] != reqMix){
            cout << "Error: Not enough " << reqMix << " to make " << poitionType << " potions\n";
            continue;
        }

        // check for all
        // check if there are enought potion base
        if ((quantities[pbIndex] < poitionQty)){
            cout << "Limited by " << quantities[pbIndex] << " base potions\n";
        }

        // check if there are enought mix in qty
        if (quantities[index] < (cost * poitionQty)){
            cout << "Limited by " << quantities[index] << " " << reqMix << endl;
        }

        // difining the mixer limit
        int mixLimit = quantities[index] / cost;

        //defining the general limit
        int limit = 0;
        if (mixLimit >= quantities[pbIndex]){
            limit = quantities[pbIndex];
        } else {
            limit = mixLimit;
        }

        // checking if we need to go over the limit
        if (limit > poitionQty){
            limit = poitionQty;
        }

        // updating inventory
        quantities[pbIndex] = quantities[pbIndex] - limit;
        quantities[index] = quantities[index] - (cost * limit);
        // if an inventory already exists
        bool Exists = false;
        int c = 0;

        while (c < inventorySize) {
            if (names[c] == poitionType) {
                quantities[c] = quantities[c] + limit;
                Exists = true; 
                break; 
            }
            c += 1; 
        }

        if (Exists == false && inventorySize < 10) {
            names[inventorySize] = poitionType;
            quantities[inventorySize] = limit;
            inventorySize += 1; 
        }

        // print
        cout << "Mixing "<< limit << " "<< poitionType << " potions\n";
        // display
        displayInventory(names, quantities, inventorySize);

    }

}


int main() {
    // creating variables
    string names[10];
    int quantities[10];
    int readCnt = 0;

    // calling functions
    readInventory(names, quantities, readCnt);
    displayInventory(names, quantities, readCnt);
    createPotions(names, quantities, readCnt);

    return 0;
}

