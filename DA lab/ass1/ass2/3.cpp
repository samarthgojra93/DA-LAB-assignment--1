#include <iostream>
#include <iomanip> // For setting decimal precision

using namespace std;

void fractionalKnapsack(int n, int values[], int weights[], int W) {
    double ratio[n];
    int id[n];

    // Calculate ratios and store original indices
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)values[i] / weights[i];
        id[i] = i;
    }

    // Manual Selection Sort based on ratio (Descending)
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[max_idx]) {
                max_idx = j;
            }
        }
        // Swap ratios
        double tempRatio = ratio[max_idx];
        ratio[max_idx] = ratio[i];
        ratio[i] = tempRatio;

        // Swap IDs to keep track of corresponding values/weights
        int tempId = id[max_idx];
        id[max_idx] = id[i];
        id[i] = tempId;
    }

    double currentWeight = 0.0;
    double finalValue = 0.0;

    cout << "Items selected: " << endl;

    for (int i = 0; i < n; i++) {
        int idx = id[i];

        // If adding the whole item doesn't exceed capacity
        if (currentWeight + weights[idx] <= W) {
            currentWeight += weights[idx];
            finalValue += values[idx];
            cout << "- Full Item (Value: " << values[idx] << ", Weight: " << weights[idx] << ")" << endl;
        } 
        // If we can only take a fraction
        else {
            int remaining = W - currentWeight;
            finalValue += values[idx] * ((double)remaining / weights[idx]);
            cout << "- Fractional Item (Value taken: " << values[idx] * ((double)remaining / weights[idx]) 
                 << ", Weight taken: " << remaining << ")" << endl;
            break; // Knapsack is full
        }
    }

    cout << fixed << setprecision(2);
    cout << "Maximum value in Knapsack = " << finalValue << endl;
}

int main() {
    int n = 3;
    int values[] = {100, 60, 120};
    int weights[] = {20, 10, 40};
    int W = 50;

    fractionalKnapsack(n, values, weights, W);

    return 0;
}