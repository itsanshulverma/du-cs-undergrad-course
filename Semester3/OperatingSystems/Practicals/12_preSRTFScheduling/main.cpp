/*
	7. Write a program to implement FCFS scheduling algorithm.

	Author: Anshul Verma
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Process {
	int pID;
	int arrivalTime;
	int burstTime;
	int completionTime;
	int waitingTime;
	int turnAroundTime;
};

void swapProcess(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortAccArrivalTime(struct Process *p, int n)
{
    for(int i=0; i < n-1; ++i)
    {
        if(p[i].arrivalTime > p[i+1].arrivalTime)
        {
            swapProcess(&p[i], &p[i+1]);
        }
    }
    return;
}

void sortAccPID(struct Process *p, int n)
{
    for(int i=0; i < n-1; ++i)
    {
        if(p[i].pID > p[i+1].pID)
        {
            swapProcess(&p[i], &p[i+1]);
        }
    }
    return;
}

void calcCompletionTime(struct Process *p, int n)
{
	int remainingTime[n];
	for(int i=0; i < n; ++i)
		remainingTime[i] = p[i].burstTime;
    int minIndex, time=0, count=0;

	for(time=0; count!=n; time++)
	{	
		minIndex = 0;
		for(int i = 0; i < n; ++i)
			if(p[i].arrivalTime <= time && remainingTime[i] < remainingTime[minIndex] && remainingTime[i] > 0)
				minIndex = i;
		
		if(remainingTime[minIndex] <= 0)
			continue;
		
		remainingTime[minIndex]--;

		if(remainingTime[minIndex] == 0)
		{
			count++;
			p[minIndex].completionTime = time + 1;
		}
	}
	return;
}

void calcTurnAroundTime(struct Process *p, int n)
{
	for(int i=0; i<n; ++i)
  	{
    	p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
  	}
  	return;
}

void calcWaitingTime(struct Process *p, int n)
{
  	for(int i=0; i<n; ++i)
  	{
    	p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
  	}
  	return;
}

void printAvgTime(struct Process *p, int n)
{
    sortAccArrivalTime(p, n);
	calcCompletionTime(p, n);
	calcTurnAroundTime(p, n);
	calcWaitingTime(p, n);
    sortAccPID(p, n);

	// double end;
  	// int smallest, count = 0;
  	// double totalWaitingTime = 0.0;
  	// double totalTurnAroundTime = 0.0;
  	// struct 	Process temp[n + 1];

	// for (int i = 0; i < n; i++)
    // temp[i] = p[i];

  	// smallest = n + 1;
  	// temp[smallest].burstTime = 999;
  	// for (double time = 0; count != n; time++) {
    // 	for (int i = 0; i < n; i++) {
    // 		if (p[i].arrivalTime <= time &&
    //       	p[i].burstTime < temp[smallest].burstTime &&
    //       	p[i].burstTime > 0) {
    //     	smallest = i;
    //   		}
    // 	}
    // 	temp[smallest].burstTime--;
    // 	if (temp[smallest].burstTime == 0) {
    //   		count++;
    //   		end = time + 1;
    //   		p[count].waitingTime +=
    //       end - p[smallest].arrivalTime - temp[smallest].burstTime;
    //   		p[count].turnAroundTime += end - p[smallest].arrivalTime;
    // 	}
  	// }

  	// Printing Process Info
	cout << " SRTF CPU Scheduling" << endl;
	cout << " ------------------------------" << endl;
  	cout << "\n process -> { arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime }\n";
  	for (int i=0; i<n; ++i)
  	{
   		cout << " P" << p[i].pID << "      -> { " << p[i].arrivalTime << " , " << p[i].burstTime << " , " << p[i].completionTime << " , " << p[i].turnAroundTime << " , " << p[i].waitingTime << " }\n";
  	}

  	// Calculating sum of waitingTime and turnAroundTime
  	int sumW = 0.0;
  	int sumT = 0.0;
  	for (int i=0; i<n; ++i)
  	{
    		sumW += p[i].waitingTime;
    		sumT += p[i].turnAroundTime;
  	}

  	// Printing average waitingTime and turnAroundTime
  	cout << "\n Average Waiting Time: " << sumW/n;
  	cout << "\n Average Turn Around Time: " << sumT/n << endl;

  	return;
}

int main()
{
	int n;

	cout << "\n Enter number of Processes: ";
	cin >> n;
	cout << endl;
	
	struct Process p[n];
	for(int i=0; i<n; ++i)
	{
		p[i].pID = i+1;
		cout << " Enter Arrival Time of Process " << i+1 << ": ";
		cin >> p[i].arrivalTime;
		cout << " Enter Burst Time of Process " << i+1 << ": ";
		cin >> p[i].burstTime;
		cout << endl;
	}
	
	printAvgTime(p, n);
	cout << endl;

	return 0;
}
