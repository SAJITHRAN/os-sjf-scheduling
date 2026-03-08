#include <stdio.h>

struct Process {
    char pid[10];
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int finished;
};

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[20];

    for(int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time and Burst Time: ");
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].finished = 0;
    }

    int completed = 0;
    int currentTime = 0;

    while(completed < n) {

        int shortest = -1;

        for(int i = 0; i < n; i++) {

            if(p[i].finished == 0 && p[i].at <= currentTime) {

                if(shortest == -1 || p[i].bt < p[shortest].bt) {
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            currentTime++;
            continue;
        }

        currentTime += p[shortest].bt;

        p[shortest].ct = currentTime;
        p[shortest].tat = p[shortest].ct - p[shortest].at;
        p[shortest].wt = p[shortest].tat - p[shortest].bt;

        p[shortest].finished = 1;
        completed++;
    }

    float totalWT = 0;
    float totalTAT = 0;

    printf("\nWaiting Time:\n");

    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
        totalWT += p[i].wt;
    }

    printf("\nTurnaround Time:\n");

    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
        totalTAT += p[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);

    return 0;
}