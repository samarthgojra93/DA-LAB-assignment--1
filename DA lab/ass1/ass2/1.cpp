#include <iostream>
using namespace std;

void activitySelection(int start[], int finish[], int n) {
    // 1. Manual Selection Sort to sort by finish times
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (finish[j] < finish[min_idx]) {
                min_idx = j;
            }
        }
        // Swap finish times
        int tempFinish = finish[min_idx];
        finish[min_idx] = finish[i];
        finish[i] = tempFinish;

        // Swap start times to keep them synchronized
        int tempStart = start[min_idx];
        start[min_idx] = start[i];
        start[i] = tempStart;
    }

    // 2. Greedy Selection
    cout << "Selected activities: ";
    
    // The first activity (earliest finish) is always selected
    int i = 0;
    cout << "(" << start[i] << ", " << finish[i] << ")";
    int count = 1;

    // 3. Compare remaining activities
    for (int j = 1; j < n; j++) {
        // If this activity has a start time >= finish time of previous activity
        if (start[j] >= finish[i]) {
            cout << ", (" << start[j] << ", " << finish[j] << ")";
            i = j; // Move the pointer to the latest selected activity
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count << endl;
}

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    activitySelection(start, finish, n);

    return 0;
}