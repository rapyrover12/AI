#include <iostream>
using namespace std;

// Maximum number of jobs and time slots
#define MAX_N 100

// Structure for a job
struct Job {
    char id;    // Job ID (e.g., 'A', 'B')
    int dead;   // Deadline (e.g., 2 means by time 2)
    int profit; // Profit (e.g., 50)
};

// Bubble sort jobs by profit (descending)
void sortJobs(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                // Swap jobs
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

// Greedy Job Scheduling
void jobScheduling(Job jobs[], int n) {
    // Find maximum deadline to set time slots
    int maxDead = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].dead > maxDead) {
            maxDead = jobs[i].dead;
        }
    }

    // Array to store scheduled jobs (slot[i] = job ID or '\0' if empty)
    char slot[MAX_N] = {'\0'};
    int totalProfit = 0;

    // Process jobs in descending profit order
    sortJobs(jobs, n);

    // Schedule each job
    for (int i = 0; i < n; i++) {
        // Find latest free slot before deadline
        for (int j = jobs[i].dead - 1; j >= 0; j--) {
            if (slot[j] == '\0') { // Slot is free
                slot[j] = jobs[i].id; // Assign job
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print scheduled jobs
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDead; i++) {
        if (slot[i] != '\0') {
            cout << slot[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    Job jobs[MAX_N];

    // Input number of jobs
    cout << "Enter number of jobs: ";
    cin >> n;

    // Input jobs (ID, deadline, profit)
    cout << "Enter jobs (ID deadline profit, e.g., A 2 50):\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].dead >> jobs[i].profit;
    }

    // Run job scheduling
    jobScheduling(jobs, n);

    return 0;
}