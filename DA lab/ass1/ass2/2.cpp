#include <iostream>
using namespace std;

// Function to find minimum platforms
int findPlatform(int arr[], int dep[], int n) {
    // 1. Sort Arrival times (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    // 2. Sort Departure times (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (dep[j] < dep[min_idx]) min_idx = j;
        int temp = dep[min_idx];
        dep[min_idx] = dep[i];
        dep[i] = temp;
    }

    // 3. Two-pointer approach to find max concurrent trains
    int platforms_needed = 0;
    int max_platforms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        // If a train arrives before (or at the same time as) a departure
        if (arr[i] <= dep[j]) {
            platforms_needed++;
            i++;
        }
        // If a train departs
        else {
            platforms_needed--;
            j++;
        }

        if (platforms_needed > max_platforms)
            max_platforms = platforms_needed;
    }

    return max_platforms;
}

int main() {
    int n = 5;
    // Times converted to minutes for easier calculation
    int AT[] = {900, 910, 920, 1100, 1120};
    int DT[] = {940, 1200, 950, 1130, 1140};

    cout << "Minimum Number of Platforms Required: " << findPlatform(AT, DT, n) << endl;

    return 0;
}