#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Player variables
    int player_health = 100;
    int player_wood = 0, player_stone = 0, player_iron = 0, player_apple = 0;
    int player_pickaxe = 0, player_sword = 0, player_cooked_apple = 0;

    // World resources
    int world_wood = 0, world_stone = 0, world_iron = 0, world_apple = 0;

    // Recipe variables
    int pickaxe_wood = 0, pickaxe_stone = 0;
    int sword_iron = 0, sword_wood = 0;
    int cooked_apple_apple = 0;

    // Load resources from resources.txt
    ifstream resourceFile("resources.txt");
    // check if file opened successfully
    if (!resourceFile) {
        cout << "Error: Cannot open resources.txt" << endl;
        return 0;
    }
    
    // getting resources from file
    string resourceName;
    int resourceQuant = 0;
    // loop to read all resource data
    while (resourceFile >> resourceName >> resourceQuant) {
        // assign resource quantities based on name
        if (resourceName == "wood") {
            world_wood = resourceQuant;
        } else if (resourceName == "stone") {
            world_stone = resourceQuant;
        } else if (resourceName == "iron") {
            world_iron = resourceQuant;
        } else if (resourceName == "apple") {
            world_apple = resourceQuant;
        }
    }
    
    resourceFile.close();
    
    // Load recipes from recipes.txt
    ifstream recipesFile("recipes.txt");
    // check if file opened successfully
    if (!recipesFile) {
        cout << "Error: Cannot open recipes.txt" << endl;
        return 0;
    }
    
    // Read crafting recipes from file
    string itemName;
    string recipeResource;
    int recipeQuant = 0;
    // loop to read all recipe data
    while (recipesFile >> itemName) {
        // process pickaxe recipe requirements
        if (itemName == "pickaxe") {
            recipesFile >> recipeResource >> recipeQuant;
            if (recipeResource == "wood") {
                pickaxe_wood = recipeQuant;
            }
            recipesFile >> recipeResource >> recipeQuant;
            if (recipeResource == "stone") {
                pickaxe_stone = recipeQuant;
            }
        // process sword recipe requirements
        } else if (itemName == "sword") {
            recipesFile >> recipeResource >> recipeQuant;
            if (recipeResource == "iron") {
                sword_iron = recipeQuant;
            }
            recipesFile >> recipeResource >> recipeQuant;
            if (recipeResource == "wood") {
                sword_wood = recipeQuant;
            }
        // process cooked apple recipe requirements
        } else if (itemName == "cooked_apple") {
            recipesFile >> recipeResource >> recipeQuant;
            if (recipeResource == "apple") {
                cooked_apple_apple = recipeQuant;
            }
        }
    }
    recipesFile.close();
    
    // while loop to check if game is still going
    bool gaming = true;
    // main game loop
    while (player_health > 0 && gaming) {
        // Display player status
        cout << "Player Status:" << endl;
        cout << "Health: " << player_health << endl;
        cout << "Inventory:" << endl;
        // display all player resources
        cout << "Wood: " << player_wood << endl;
        cout << "Stone: " << player_stone << endl;
        cout << "Iron: " << player_iron << endl;
        cout << "Apple: " << player_apple << endl;
        // display all player items
        cout << "Pickaxe: " << player_pickaxe << endl;
        cout << "Sword: " << player_sword << endl;
        cout << "Cooked Apple: " << player_cooked_apple << endl;
        cout << endl;
        
        // Display main menu
        cout << "Menu:" << endl;
        cout << "1. Mine resources" << endl;
        cout << "2. Craft item" << endl;
        cout << "3. Eat food" << endl;
        cout << "4. Quit and save" << endl;
                cout << "Enter choice (1-4): ";
                
                // get user input
                int choice = 0;
                cin >> choice;
        
        // switch statement to handle the user's choice
        // process user selection
        switch (choice) {
            // case for mining resources
            case 1: { 
                // get mining choice
                string mineChoice;
                cout << "Enter resource to mine (wood, stone, iron, apple): ";
                cin >> mineChoice;
                
                // check if resource is valid
                bool resourceExists = false;
                bool playerDied = false;
                while (!resourceExists) {
                    // check if wood is available and mine it
                    if (mineChoice == "wood" && world_wood > 0) {
                        player_wood++;
                        world_wood--;
                        player_health -= 5;
                        resourceExists = true;
                        cout << "Mined 1 wood. Health now: " << player_health << endl;
                    // check if stone is available and mine it
                    } else if (mineChoice == "stone" && world_stone > 0) {
                        player_stone++;
                        world_stone--;
                        player_health -= 5;
                        resourceExists = true;
                        cout << "Mined 1 stone. Health now: " << player_health << endl;
                    // check if iron is available and mine it
                    } else if (mineChoice == "iron" && world_iron > 0) {
                        player_iron++;
                        world_iron--;
                        player_health -= 5;
                        resourceExists = true;
                        cout << "Mined 1 iron. Health now: " << player_health << endl;
                    // check if apple is available and mine it
                    } else if (mineChoice == "apple" && world_apple > 0) {
                        player_apple++;
                        world_apple--;
                        player_health -= 5;
                        resourceExists = true;
                        cout << "Gathered 1 apple. Health now: " << player_health << endl;
                    } else {
                        cout << "Invalid resource or none available. Try again: ";
                        cin >> mineChoice;
                    }
                }
                
                // Checking if player died
                if (player_health <= 0) {
                    cout << "You died!" << endl;
                    playerDied = true;
                    break;
                }
                
                // Asking if player wants to mine again
                // only ask if first mining was successful
                if (resourceExists) {
                    char mineAgain = ' ';
                    do {
                        cout << "Mine again? (y/n): ";
                        cin >> mineAgain;
                        
                        if (mineAgain == 'y') {
                            cout << "Enter resource to mine: ";
                            cin >> mineChoice;
                            
                            resourceExists = false;
                            if (mineChoice == "wood" && world_wood > 0) {
                                player_wood++;
                                world_wood--;
                                player_health -= 5;
                                resourceExists = true;
                                cout << "Mined 1 wood. Health now: " << player_health << endl;
                            } else if (mineChoice == "stone" && world_stone > 0) {
                                player_stone++;
                                world_stone--;
                                player_health -= 5;
                                resourceExists = true;
                                cout << "Mined 1 stone. Health now: " << player_health << endl;
                            } else if (mineChoice == "iron" && world_iron > 0) {
                                player_iron++;
                                world_iron--;
                                player_health -= 5;
                                resourceExists = true;
                                cout << "Mined 1 iron. Health now: " << player_health << endl;
                            } else if (mineChoice == "apple" && world_apple > 0) {
                                player_apple++;
                                world_apple--;
                                player_health -= 5;
                                resourceExists = true;
                                cout << "Gathered 1 apple. Health now: " << player_health << endl;
                            } else {
                                cout << "Invalid resource or none available." << endl;
                            }
                            
                        } else if (mineAgain == 'n') {
                            break;
                        } else {
                            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                        }
                        
                        // check for death after each mining session
                        if (player_health <= 0) {
                            cout << "You died!" << endl;
                            playerDied = true;
                            break;
                        }
                    } while (true);
                }
                
                // save game if player died during mining
                if (playerDied) {
                    ofstream saveFile("save.txt");
                    if (saveFile) {
                        saveFile << "health " << player_health << endl;
                        saveFile << "wood " << player_wood << endl;
                        saveFile << "stone " << player_stone << endl;
                        saveFile << "iron " << player_iron << endl;
                        saveFile << "apple " << player_apple << endl;
                        saveFile << "pickaxe " << player_pickaxe << endl;
                        saveFile << "sword " << player_sword << endl;
                        saveFile << "cooked_apple " << player_cooked_apple << endl;
                        saveFile.close();
                    }
                    cout << "Game saved to save.txt." << endl;
                }
                break;
            }
            
            // case for crafting items
            case 2: { 
                // get crafting choice
                string craftItem;
                cout << "Enter item to craft (pickaxe, sword, cooked_apple): ";
                cin >> craftItem;
                
                // check if player can craft pickaxe
                if (craftItem == "pickaxe") {
                    if (player_wood >= pickaxe_wood && player_stone >= pickaxe_stone) {
                        player_wood -= pickaxe_wood;
                        player_stone -= pickaxe_stone;
                        player_pickaxe++;
                        cout << "Crafted 1 pickaxe." << endl;
                    } else {
                        cout << "Not enough resources for pickaxe." << endl;
                    }
                // check if player can craft sword
                } else if (craftItem == "sword") {
                    if (player_iron >= sword_iron && player_wood >= sword_wood) {
                        player_iron -= sword_iron;
                        player_wood -= sword_wood;
                        player_sword++;
                        cout << "Crafted 1 sword." << endl;
                    } else {
                        cout << "Not enough resources for sword." << endl;
                    }
                // check if player can craft cooked apple
                } else if (craftItem == "cooked_apple") {
                    if (player_apple >= cooked_apple_apple) {
                        player_apple -= cooked_apple_apple;
                        player_cooked_apple++;
                        cout << "Crafted 1 cooked_apple." << endl;
                    } else {
                        cout << "Not enough resources for cooked_apple." << endl;
                    }
                } else {
                    cout << "Invalid item name." << endl;
                }
                break;
            }
            
            // case for eating food
            case 3: { 
                // get food choice
                string food;
                cout << "Enter food to eat (apple, cooked_apple): ";
                cin >> food;
                
                // check if player can eat raw apple
                if (food == "apple") {
                    if (player_apple > 0) {
                        player_apple--;
                        player_health += 10;
                        // cap health at 100
                        if (player_health > 100) {
                            player_health = 100;
                        }
                        cout << "Ate 1 apple. Health now: " << player_health << endl;
                    } else {
                        cout << "No apples to eat." << endl;
                    }
                // check if player can eat cooked apple
                } else if (food == "cooked_apple") {
                    if (player_cooked_apple > 0) {
                        player_cooked_apple--;
                        player_health += 20;
                        // cap health at 100
                        if (player_health > 100) {
                            player_health = 100;
                        }
                        cout << "Ate 1 cooked_apple. Health now: " << player_health << endl;
                    } else {
                        cout << "No cooked apples to eat." << endl;
                    }
                } else {
                    cout << "Invalid food name." << endl;
                }
                break;
            }
            
            // case for quitting and saving
            case 4: { 
                // Save game to save.txt
                // create save file
                ofstream saveFile("save.txt");
                // write all player data to save file
                if (saveFile) {
                    saveFile << "health " << player_health << endl;
                    saveFile << "wood " << player_wood << endl;
                    saveFile << "stone " << player_stone << endl;
                    saveFile << "iron " << player_iron << endl;
                    saveFile << "apple " << player_apple << endl;
                    saveFile << "pickaxe " << player_pickaxe << endl;
                    saveFile << "sword " << player_sword << endl;
                    saveFile << "cooked_apple " << player_cooked_apple << endl;
                    saveFile.close();
                }
                cout << "Game saved to save.txt." << endl;
                cout << "Goodbye!" << endl;
                gaming = false;
                break;
            }
            
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    
    // If player died, save the game
    if (player_health <= 0) {
        ofstream saveFile("save.txt");

        // write final game state even after death
        if (saveFile) {
            saveFile << "health " << player_health << endl;
            saveFile << "wood " << player_wood << endl;
            saveFile << "stone " << player_stone << endl;
            saveFile << "iron " << player_iron << endl;
            saveFile << "apple " << player_apple << endl;
            saveFile << "pickaxe " << player_pickaxe << endl;
            saveFile << "sword " << player_sword << endl;
            saveFile << "cooked_apple " << player_cooked_apple << endl;
            saveFile.close();
        }
    }

    return 0;
}