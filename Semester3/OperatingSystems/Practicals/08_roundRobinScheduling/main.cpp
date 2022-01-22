/*
	7. Write a program to implement FCFS scheduling algorithm.

	Author: Anshul Verma
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Process {
	int pID;
	float arrivalTime;
	float burstTime;
	float waitingTime;
	float turnAroundTime;
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

void calcWaitingTime(struct Process *p, int n, float quantum)
{
	float *remainingTime = new float[n];
	for(int i=0; i<n; ++i)
		remainingTime[i] = p[i].burstTime;

	float temp = 0;
	
	while(true)
	{
		int flag = 1;
		for(int i=0; i<n; ++i)
		{
			if (remainingTime[i] > 0)
			{
				flag = 0;
				if (remainingTime[i] > quantum)
				{
					temp += quantum;
					remainingTime[i] -= quantum;
				}
				else
				{
					temp += remainingTime[i];
					p[i].waitingTime += temp - p[i].arrivalTime - p[i].burstTime;
					remainingTime[i] = 0;	
				}
			}
  		}
		if (flag ==1) break;
  	}
	return;
}

void calcTurnAroundTime(struct Process *p, int n)
{
	for(int i=0; i<n; ++i)
  	{
    		p[i].turnAroundTime = p[i].waitingTime + p[i].burstTime - p[i].arrivalTime;
  	}
  	return;
}


void printAvgTime(struct Process *p, int n, int quantum)
{
	sortAccArrivalTime(p, n);
	calcWaitingTime(p, n, quantum);
	calcTurnAroundTime(p, n);
	sortAccPID(p, n);

  	// Printing Process Info
	cout << " Round Robin CPU Scheduling" << endl;
	cout << " ------------------------------" << endl;
  	cout << "\n process -> { arrivalTime, burstTime, turnAroundTime, waitingTime }\n";
  	for (int i=0; i<n; ++i)
  	{
   		cout << " P" << p[i].pID << "      -> { " << p[i].arrivalTime << " , " << p[i].burstTime << " , " << p[i].turnAroundTime << " , " << p[i].waitingTime << " }\n";
  	}

  	// Calculating sum of waitingTime and turnAroundTime
  	float sumW = 0.0;
  	float sumT = 0.0;
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
	float quantum;

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

	cout << " Enter quantum time: ";
	cin >> quantum;
	cout << endl;
	
	printAvgTime(p, n, quantum);
	cout << endl;

	return 0;
}
