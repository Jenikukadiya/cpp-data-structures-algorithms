#include <stdio.h>

int main() {
    int n, at[10], bt[10], ct[10], tat[10], wt[10], p[10];
    double total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        p[i] = i + 1; // Assigning Process IDs
        printf("Process %d - AT: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d - BT: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Bubble Sort: Sorting processes based on Arrival Time (AT)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap Arrival Time
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap Process ID
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculation Logic
    int current_time = 0;
    for(int i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
        }
        current_time += bt[i];
        ct[i] = current_time;
    }

    // Display Results
    printf("\nP_ID  \tAT  \tBT  \tCT  \tTAT  \tWT  \n");
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    printf("  P%d  \t%d   \t%d    \t%d   \t%d    \t%d  \n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
