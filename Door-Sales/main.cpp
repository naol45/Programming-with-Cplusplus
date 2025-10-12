#include <iostream>

using namespace std;

int main() {

    // Declared variables for the constant values
    float BUNDLE_SIZE = 100;
    float MARKUP = 0.75;

    // Declared variables for the input from the user
    float input_bundle_qty = 0;
    float input_bundle_cost = 0;
    
    // User interaction to request the values
    cout << "How many door bundles are needed? ";
    cin >> input_bundle_qty;

    cout << "How much does each bundle cost? $";
    cin >> input_bundle_cost;

    // Declared variables for the calculated values
    float total_doors_purchased = BUNDLE_SIZE * input_bundle_qty;
    float single_door_cost = input_bundle_cost / BUNDLE_SIZE;
    float total_cost = input_bundle_cost * input_bundle_qty;
    float single_door_sale_price = single_door_cost + (single_door_cost * MARKUP);
    float total_sale_price = single_door_sale_price * total_doors_purchased;
    float single_door_profit = single_door_sale_price - single_door_cost;
    float total_profit = single_door_profit * total_doors_purchased; 

    // Display the calculated values
    cout << "\nBundle Quantity: " << input_bundle_qty <<endl;
    cout << "Bundle Cost: $" << input_bundle_cost <<endl;
    cout << "Total Doors Purchased: " << total_doors_purchased <<endl;
    cout << "Single Door Cost: $" << single_door_cost <<endl;
    cout << "Total Cost: $" << total_cost <<endl;
    cout << "Single Door Sale Price: $" << single_door_sale_price <<endl;
    cout << "Total Sale Price: $" << total_sale_price <<endl;
    cout << "Single Door Profit: $" << single_door_profit <<endl;
    cout << "Total Profit: $" << total_profit <<endl;

    return 0;
}