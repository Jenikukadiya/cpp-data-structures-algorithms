#include <stdio.h>

struct process
{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int tat;
    int wt;
};

// Standard Queue Functions
void enqueue(int queue[], int *rear, int value)
{
    queue[++(*rear)] = value;
}

int dequeue(int queue[], int *front)
{
    return queue[(*front)++];
}

void print(struct process p[], int n)
{
    printf("\n------- Round Robin Scheduling -------\n");
    printf("P_ID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].tat, p[i].wt);
    }
}

int main()
{
    int n, tq, completed = 0, current_time = 0;
    int front = 0, rear = -1;
    int queue[1000]; // Larger size to handle re-entries
    int visited[20] = {0}; // To track if process is already in queue

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter AT and BT for Process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
    }

    // Initial push: find the first process(es) to arrive
    // We sort of "wait" until the first process arrives if current_time < min arrival
    int min_arrival = p[0].arrival;
    for(int i=1; i<n; i++)
        if(p[i].arrival < min_arrival) min_arrival = p[i].arrival;
              current_time = min_arrival;

    for (int i = 0; i < n; i++)
    {
        if (p[i].arrival <= current_time)
        {
            enqueue(queue, &rear, i);
            visited[i] = 1;
        }
    }

    while (completed < n)
    {
        if (front > rear)
        { // Queue is empty but processes remain (CPU Idle)
            current_time++;
            for (int i = 0; i < n; i++)
            {
                if (p[i].arrival <= current_time && !visited[i])
                {
                    enqueue(queue, &rear, i);
                    visited[i] = 1;
                }
            }
            continue;
        }

        int index = dequeue(queue, &front);

        // Process execution
        if (p[index].remaining > tq)
        {
            p[index].remaining -= tq;
            current_time += tq;
        }
        else
        {
            current_time += p[index].remaining;
            p[index].remaining = 0;
            completed++;
            p[index].completion = current_time;
            p[index].tat = p[index].completion - p[index].arrival;
            p[index].wt = p[index].tat - p[index].burst;
        }

        // Check for new arrivals while the current process was running
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !visited[i] && p[i].remaining > 0) {
                enqueue(queue, &rear, i);
                visited[i] = 1;
            }
        }

        // If the current process isn't finished, put it back at the end of the queue
        if (p[index].remaining > 0) {
            enqueue(queue, &rear, index);
        }
    }

    print(p, n);
    return 0;
}
