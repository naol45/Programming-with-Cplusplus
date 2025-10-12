// CS 135 - Dr. Choi In class template 

#include <iostream> 

using namespace std;


int main(){


// variables used
// Boolean - alive variables
    bool scarletRevive = false;        // boolean flag for whether or not the unicorn is alive
    bool sunshineRevive = false;
    bool oceanRevive = false; 
    bool forestRevive = false;
    bool stardustRevive = false; 

    int revivedCount = 0;              // counter for number of revived unicorns
    // scarlet = 1, sunshine = 2, ocean = 3, forest = 4, stardust = 5
    int unicornID = 0;  

    while(revivedCount < 5){
        
        // print menu
        cout << "Frozen Unicorns to Revive:" << endl;
        if (scarletRevive == false) {
            cout << "\n1. Scarlet Comet is still frozen" << endl; 
        }
        if (sunshineRevive == false) {
            cout << "2. Sunshine Speedster is still frozen" << endl; 
        }
        if (oceanRevive == false) {
            cout << "3. Ocean Dreamer is still frozen" << endl; 
        }
        if (forestRevive == false) {
            cout << "4. Forest Whisperer is still frozen" << endl; 
        }
        if (stardustRevive == false){
            cout << "5. Stardust Knight is still frozen" << endl; 
        }

        // get user input with validation
        cout << "Select the Unicorn Number that you want revive now:" << endl; 
        cin >> unicornID; 
        bool badInput = true; 

        while (badInput){
            if (cin.fail()){
                cout << "Invalid input. Please enter a number between 1 and 5.\n" << endl; 
                cin.clear(); 
                cin.ignore(1000, '\n');
                cout << "\nFrozen Unicorns to Revive:" << endl;
                if (scarletRevive == false) {
                    cout << "\n1. Scarlet Comet is still frozen" << endl; 
                }
                if (sunshineRevive == false) {
                    cout << "2. Sunshine Speedster is still frozen" << endl; 
                }
                if (oceanRevive == false) {
                    cout << "3. Ocean Dreamer is still frozen" << endl; 
                }
                if (forestRevive == false) {
                    cout << "4. Forest Whisperer is still frozen" << endl; 
                }
                if (stardustRevive == false){
                    cout << "5. Stardust Knight is still frozen" << endl; 
                }

                cout << "Select the Unicorn Number that you want revive now:" << endl; 
                cin >> unicornID;
            }
            else if (unicornID < 1 || unicornID > 5) {
                cout << "There is no such unicorn" << endl;
                cout << "\nFrozen Unicorns to Revive:" << endl;
                if (scarletRevive == false) {
                    cout << "\n1. Scarlet Comet is still frozen" << endl; 
                }
                if (sunshineRevive == false) {
                    cout << "2. Sunshine Speedster is still frozen" << endl; 
                }
                if (oceanRevive == false) {
                    cout << "3. Ocean Dreamer is still frozen" << endl; 
                }
                if (forestRevive == false) {
                    cout << "4. Forest Whisperer is still frozen" << endl; 
                }
                if (stardustRevive == false){
                    cout << "5. Stardust Knight is still frozen" << endl; 
                }

                cout << "Select the Unicorn Number that you want revive now:" << endl; 
                cin >> unicornID;
            }
            else {
                // check if unicorn is already revived
                switch(unicornID){
                    case 1: 
                        if (scarletRevive){
                            cout << "This unicorn is already revived" << endl;
                            cout << "Select the Unicorn Number that you want revive now:" << endl; 
                            cin >> unicornID;
                        }
                        else 
                            badInput = false; 
                        break; 
                    case 2: 
                        if (sunshineRevive){
                            cout << "This unicorn is already revived" << endl;
                            cout << "Select the Unicorn Number that you want revive now:" << endl; 
                            cin >> unicornID;
                        }
                        else 
                            badInput = false; 
                        break;
                    case 3: 
                        if (oceanRevive){
                            cout << "This unicorn is already revived" << endl;
                            cout << "Select the Unicorn Number that you want revive now:" << endl; 
                            cin >> unicornID;
                        }
                        else 
                            badInput = false; 
                        break;
                    case 4: 
                        if (forestRevive){
                            cout << "This unicorn is already revived" << endl;
                            cout << "Select the Unicorn Number that you want revive now:" << endl; 
                            cin >> unicornID;
                        }
                        else 
                            badInput = false; 
                        break;
                    case 5: 
                        if (stardustRevive){
                            cout << "This unicorn is already revived" << endl;
                            cout << "Select the Unicorn Number that you want revive now:" << endl; 
                            cin >> unicornID;
                        }
                        else 
                            badInput = false; 
                        break;
                } // end of switch statement
            }
        } // end of while statement for bad input

        // Rainbow waterfall part of the code
        {
            // reinitialize variables for color needs
            int needV = 0; 
            int needI = 0; 
            int needB = 0;
            int needG = 0;
            int needY = 0; 
            int needO = 0;
            int needR = 0; 
            
            // set up the unicorn needs
            switch(unicornID){
                case 1: 
                    needV = 0;
                    needI = 0;
                    needB = 3;
                    needG = 0;
                    needY = 2;
                    needO = 0; 
                    needR = 7; 
                    cout << "\nThe colors needed to revive this unicorn are: Red=7 drops, Blue=3 drops, Yellow=2 drops\n" << endl;
                    break; 
                case 2:
                    needV = 0;
                    needI = 0;
                    needB = 0;
                    needG = 3;
                    needY = 8;
                    needO = 2; 
                    needR = 0; 
                    cout << "\nThe colors needed to revive this unicorn are: Yellow=8 drops, Green=3 drops, Orange=2 drops\n" << endl;
                    break;
                case 3:
                    needV = 2;
                    needI = 4;
                    needB = 6;
                    needG = 0;
                    needY = 0;
                    needO = 0; 
                    needR = 0; 
                    cout << "\nThe colors needed to revive this unicorn are: Blue=6 drops, Indigo=4 drops, Violet=2 drops\n" << endl;
                    break;
                case 4:
                    needV = 0;
                    needI = 0;
                    needB = 0;
                    needG = 5;
                    needY = 0;
                    needO = 3; 
                    needR = 2; 
                    cout << "\nThe colors needed to revive this unicorn are: Green=5 drops, Red=2 drops, Orange=3 drops\n" << endl;
                    break;
                case 5:
                    needV = 7;
                    needI = 3;
                    needB = 0;
                    needG = 0;
                    needY = 3;
                    needO = 0; 
                    needR = 0; 
                    cout << "\nThe colors needed to revive this unicorn are: Violet=7 drops, Indigo=3 drops, Yellow=3 drops\n" << endl;
                    break;
            }// end of switch for needColor
            
            // initialize collection variables
            int collectV = 0; 
            int collectI = 0;
            int collectB = 0;
            int collectG = 0;
            int collectY = 0;
            int collectO = 0;
            int collectR = 0;
            
            long drops = 1; 
            bool allColorNeeds = false; 
            
            // nested while loop for collecting drops
            while (!allColorNeeds){
                // calculate current color
                long windowIndex = (drops-1)/7; 
                int colorIndex = (windowIndex % 7);
                
                // print drop number and color
                cout << "Drop:" << drops << "|| The current waterfall drop is: ";
                if (colorIndex == 0) cout << "violet" << endl;
                else if (colorIndex == 1) cout << "indigo" << endl;
                else if (colorIndex == 2) cout << "blue" << endl;
                else if (colorIndex == 3) cout << "green" << endl;
                else if (colorIndex == 4) cout << "yellow" << endl;
                else if (colorIndex == 5) cout << "orange" << endl;
                else if (colorIndex == 6) cout << "red" << endl;
                
                bool obnoxiousUnicorn = false;
                
                // check if a revived unicorn drinks the drop
                if (scarletRevive && colorIndex == 6 && drops % 2 == 0) {
                    cout << "Scarlet Comet drinks this red drop" << endl;
                    obnoxiousUnicorn = true;
                }
                else if (sunshineRevive && colorIndex == 4 && drops % 2 == 0) {
                    cout << "Sunshine Speedster drinks this yellow drop" << endl;
                    obnoxiousUnicorn = true;
                }
                else if (oceanRevive && colorIndex == 2 && drops % 2 == 0) {
                    cout << "Ocean Dreamer drinks this blue drop" << endl;
                    obnoxiousUnicorn = true;
                }
                else if (forestRevive && colorIndex == 3 && drops % 2 == 0) {
                    cout << "Forest Whisperer drinks this green drop" << endl;
                    obnoxiousUnicorn = true;
                }
                else if (stardustRevive && colorIndex == 0 && drops % 2 == 0) {
                    cout << "Stardust Knight drinks this violet drop" << endl;
                    obnoxiousUnicorn = true;
                }
                
                // if not drunk, check if we need to collect it
                if (!obnoxiousUnicorn) {
                    if (colorIndex == 0 && collectV < needV) {
                        collectV++; 
                        cout << "Drop:" << drops << "|| You collect this violet drop\n" << endl;
                    }
                    else if (colorIndex == 1 && collectI < needI) {
                        collectI++; 
                        cout << "Drop:" << drops << "|| You collect this indigo drop\n" << endl;
                    }
                    else if (colorIndex == 2 && collectB < needB) {
                        collectB++; 
                        cout << "Drop:" << drops << "|| You collect this blue drop\n" << endl;
                    }
                    else if (colorIndex == 3 && collectG < needG) {
                        collectG++; 
                        cout << "Drop:" << drops << "|| You collect this green drop\n" << endl;
                    }
                    else if (colorIndex == 4 && collectY < needY) {
                        collectY++; 
                        cout << "Drop:" << drops << "|| You collect this yellow drop\n" << endl;
                    }
                    else if (colorIndex == 5 && collectO < needO) {
                        collectO++; 
                        cout << "Drop:" << drops << "|| You collect this orange drop\n" << endl;
                    }
                    else if (colorIndex == 6 && collectR < needR) {
                        collectR++; 
                        cout << "Drop:" << drops << "|| You collect this red drop\n" << endl;
                    }
                }
                
                // check if all colors are collected
                if (needV == collectV && needI == collectI && needB == collectB && 
                    needG == collectG && needY == collectY && needO == collectO && 
                    needR == collectR) {
                    allColorNeeds = true; 
                }
                
                drops++;
            } // end of revive for singular unicorn
            
            // revive the unicorn
            drops--; // adjust because we incremented one extra time
            cout << "The total time taken to revive ";
            
            switch(unicornID) {
                case 1:
                    scarletRevive = true;
                    cout << "Scarlet Comet is:" << drops << " minutes." << endl;
                    cout << "\nThe Scarlet Comet unicorn is revived!!!" << endl;
                    break;
                case 2:
                    sunshineRevive = true;
                    cout << "Sunshine Speedster is:" << drops << " minutes." << endl;
                    cout << "\nThe Sunshine Speedster unicorn is revived!!!" << endl;
                    break;
                case 3:
                    oceanRevive = true;
                    cout << "Ocean Dreamer is:" << drops << " minutes." << endl;
                    cout << "\nThe Ocean Dreamer unicorn is revived!!!" << endl;
                    break;
                case 4:
                    forestRevive = true;
                    cout << "Forest Whisperer is:" << drops << " minutes." << endl;
                    cout << "\nThe Forest Whisperer unicorn is revived!!!" << endl;
                    break;
                case 5:
                    stardustRevive = true;
                    cout << "Stardust Knight is:" << drops << " minutes." << endl;
                    cout << "\nThe Stardust Knight unicorn is revived!!!" << endl;
                    break;
            }
            
            revivedCount++;
            
        } // end of while block

    } // end of main while loop
    
    // Final rainbow pattern
    cout << "\n\n The 5 powerful unicorns are revived and now they can create the magic rainbow:" << endl;
    

    // print RYBGV
    cout << "\nRYBGV" << endl;
    cout << "   RYBGV" << endl;
    cout << "      RYBGV" << endl;
    cout << "      RYBGV" << endl;
    cout << "   RYBGV" << endl;
    cout << "RYBGV" << endl;
    cout << "\n\n\n" << endl;

    return 0; 
}