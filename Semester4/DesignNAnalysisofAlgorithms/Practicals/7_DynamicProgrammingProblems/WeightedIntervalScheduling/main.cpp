#include <iostream>
#include <algorithm>
using namespace std;

int M[20];

// Job data structure
struct Job {
    int s, // Start Time
     f, // Finish Time
     w; //weight
};

// p(jobs[], j), for an interval j, is the largest index i < j 
// such that intervals i and j are disjoint i.e.
// i is the leftmost interval that ends before j begins.
int p(Job jobs[], int j)
{
  // finding the last job index whose finish time is less than or equal to the
  // given job's start time
  for(int i = j - 1; i >= 0; i--)
    if (jobs[i].f <= jobs[j].s) 
      return i;

  // return the negative index if no non-conflicting job is found
  return 0;
}

// Function to compare jobs used to sort them according to finish time
bool compareJob(Job j1, Job j2)
{
  return (j1.f < j2.f);
}

// Function to compute optimal value using memoization i.e.
// it returns value of optimal solution to the problem 
// consisting of job requests 1, 2, ..., j
int ComputeOpt(Job jobs[], int j)
{
  if (M[j] == -1)
  {
    M[j] = max(jobs[j].w + ComputeOpt(jobs, p(jobs, j)),
      ComputeOpt(jobs, j - 1));
    return M[j];
  }  
}

// Function to print optimal solution
void FindSolution(Job jobs[], int j)
{
  if (j == 0)
    cout << "";
  else if ((jobs[j].w + M[p(jobs, j)]) > M[j - 1])
  {
    cout << j << " ";
    FindSolution(jobs, p(jobs, j));
  }
  else
    FindSolution(jobs, j - 1);
}

// Main function to find the optimal solution
void weightedIntervalScheduling(Job jobs[], int n)
{

  for(int i = 0; i < n; i++)
  {
    cout << endl << p(jobs, i) << " ";
  }
  cout << endl;
  // Sort jobs according to finish time
  sort(jobs, jobs + n, compareJob);

  // Find value of optimal solution
  M[0] = 0;

  // for(int j = 1; j < n; j++)
  //   M[j] = max(jobs[j].w + M[p(jobs, j)], M[j - 1]);

  for (int i = 1; i < n; i++)
    {
        // find the index of the last non-conflicting job with the current job
        int index = p(jobs, i);
 
        // include the current job with its non-conflicting jobs
        int incl = jobs[i].w;
        if (index != -1) {
            incl += M[index];
        }
 
        // store the maximum profit by including or excluding the current job
        M[i] = max(incl, M[i-1]);
    }

  cout << M[n-1] << " is the optimal value.";

  // Find optimal solution
  cout << "\nOptimal Solution: ";
  // FindSolution(jobs, n);
}

/*
  Driver Code
*/
int main()
{
  int n;
  cout << "\nEnter the no of jobs: ";
  cin >> n;
  cout << "Enter the job details:\n";

  Job jobs[n];
  for(int i = 0; i < n; i++)
  {
    cout << "Starting time of Job " << i+1 << ": ";
    cin >> jobs[i].s;
    cout << "Finishing time of Job " << i+1 << ": ";
    cin >> jobs[i].f;
    cout << "Weight of Job " << i+1 << ": ";
    cin >> jobs[i].w;
    cout << endl;
  }

  weightedIntervalScheduling(jobs, n);

  return 0;
}