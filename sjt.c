#include <stdio.h>
#include <string.h>

struct Process {
	char pid[10];
	int at, bt, ct, wt, tat;
	int finished;
};

int main() {

	int n;
	scanf("%d",&n);

	struct Process proc[100];

	for(int i=0; i<n; i++) {
		scanf("%s %d %d",proc[i].pid,&proc[i].at,&proc[i].bt);
		proc[i].finished=0;
	}

	int currentTime=0, doneCount=0;

	while(doneCount<n) {

		int index=-1;
		int minBT=9999;

		for(int i=0; i<n; i++) {
			if(proc[i].finished==0 && proc[i].at<=currentTime) {
				if(proc[i].bt<minBT) {
					minBT=proc[i].bt;
					index=i;
				}
			}
		}

		if(index==-1) {
			currentTime++;
		}
		else {
			currentTime+=proc[index].bt;

			proc[index].ct=currentTime;
			proc[index].tat=proc[index].ct-proc[index].at;
			proc[index].wt=proc[index].tat-proc[index].bt;

			proc[index].finished=1;
			doneCount++;
		}
	}

	float totalWT=0,totalTAT=0;

	printf("Waiting Time:\n");
	for(int i=0; i<n; i++) {
		printf("%s %d\n",proc[i].pid,proc[i].wt);
		totalWT+=proc[i].wt;
	}

	printf("Turnaround Time:\n");
	for(int i=0; i<n; i++) {
		printf("%s %d\n",proc[i].pid,proc[i].tat);
		totalTAT+=proc[i].tat;
	}

	printf("Average Waiting Time: %.2f\n",totalWT/n);
	printf("Average Turnaround Time: %.2f\n",totalTAT/n);

	return 0;
}

