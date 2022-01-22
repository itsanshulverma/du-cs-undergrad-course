/**
 * Write a program to implement first-fit, best-fit and 
 * worst-fit allocation strategies.
 * 
 */

#include <cstring>
#include <iostream>
#define MAX_SIZE 100

using namespace std;

void worstFit(int blockSize[], int m,
              int processSize[], int n)
{
  int allocation[n];

  for (int i = 0; i < n; i++)
    allocation[i] = -1;

  for (int i = 0; i < n; i++)
  {
    int wstIdx = -1;
    for (int j = 0; j < m; j++)
    {
      if (blockSize[j] >= processSize[i])
      {
        if (wstIdx == -1)
          wstIdx = j;
        else if (blockSize[wstIdx] < blockSize[j])
          wstIdx = j;
      }
    }

    if (wstIdx != -1)
    {
      allocation[i] = wstIdx;
      blockSize[wstIdx] -= processSize[i];
    }
  }

  cout << "\nWorst-Fit Allocation Strategy\n";
  cout << "=========================================\n";
  cout << "Process No.\tProcess Size\tBlock No.\n";
  cout << "=========================================\n";
  for (int i = 0; i < n; i++)
  {
    cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
    if (allocation[i] != -1)
      cout << allocation[i] + 1;
    else
      cout << "Not Allocated";
    cout << endl;
  }
}

int main()
{
  int holes, processes;
  int holeSizes[MAX_SIZE], processSizes[MAX_SIZE];

  cout << "\nEnter Number of Holes: ";
  cin >> holes;
  cout << "Enter Number of Processes: ";
  cin >> processes;

  for (int i = 0; i < holes; i++)
  {
    cout << "Enter Size of Hole " << (i + 1) << ": ";
    cin >> holeSizes[i];
  }

  for (int i = 0; i < processes; i++)
  {
    cout << "Enter Size of Process " << (i + 1) << ": ";
    cin >> processSizes[i];
  }

  worstFit(holeSizes, holes, processSizes, processes);

  cout << endl;
  return 0;
}
