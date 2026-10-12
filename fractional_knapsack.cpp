#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight;
    int value;
};

double fractional_knapsack (int max, vector<Item>& items, vector<double>& fractions, vector<bool>& used) {
    
    if(max <= 0) {
        return 0.0;
    }

    double max_density = 0;
    int best_index = -1;


    //Iterate over it once to find the max density
    for (int i = 0; i < items.size(); i++ ) {
        if(used[i] == 1) continue;
        double curr_density = items[i].value / items[i].weight;
        if(curr_density > max_density) {
            max_density = curr_density;
            best_index = i;
        }
    }

    if (best_index == -1)
        return 0;

    used[best_index] = 1;

    if (items[best_index].weight <= max) {
        fractions[best_index] = 1.0;
        return items[best_index].value + fractional_knapsack(max - items[best_index].weight, items, fractions, used);
    }
    else {
        fractions[best_index] = max / items[best_index].weight;
        return items[best_index].value * fractions[best_index];
    }
}

int main() {
    vector<Item> items = { {5, 10}, {8, 8} };   // example input
    int capacity = 10;

    vector<double> fractions(items.size(), 0.0);
    vector<bool> used(items.size(), false);

    double total = fractional_knapsack(capacity, items, fractions, used);

    cout << "Max total value: " << total << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << "Item " << i << " fraction: " << fractions[i] << endl;
    }
    return 0;
}