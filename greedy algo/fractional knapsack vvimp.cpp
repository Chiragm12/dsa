// here the data is given like [(100,20),(90,10)] where first is weight, and second is capactiy.


#include <bitsstdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

// Custom comparator: sort by decreasing value/weight ratio
bool comp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to return the maximum total value in the knapsack
double fractionalKnapsack(int W, vector<Item>& arr, int n) {
    // Sort items based on value/weight ratio
    sort(arr.begin(), arr.end(), comp);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            totalValue += arr[i].value;
            W -= arr[i].weight;
        } else {
            // Take the fractional part
            totalValue += (double)arr[i].value * ((double)W / arr[i].weight);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

// Driver code
int main() {
    int W = 50; // Capacity of knapsack
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int n = items.size();

    double maxVal = fractionalKnapsack(W, items, n);
    cout << "Maximum value in Knapsack = " << maxVal << endl;

    return 0;
}



// if they give in seperate arrays then combine thme like this


class Solution {
public:
    // Define item structure
    struct Item {
        int value, weight;
    };

    // Comparator to sort by decreasing value/weight ratio
    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);
        
        // Combine value and weight into a single struct
        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }

        // Sort based on value/weight ratio
        sort(items.begin(), items.end(), comp);

        double total = 0.0;

        for (int i = 0; i < n; i++) {
            if (capacity >= items[i].weight) {
                total += items[i].value;
                capacity -= items[i].weight;
            } else {
                total += (double)items[i].value * ((double)capacity / items[i].weight);
                break;
            }
        }

        return total;
    }
};
