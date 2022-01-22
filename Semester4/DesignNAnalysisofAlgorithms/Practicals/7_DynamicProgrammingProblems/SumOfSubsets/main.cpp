/*
  Written by Anshul Verma (19/78065) for University of Delhi
  Lab Work for Design and Analysis of Algorithms
*/

#include <iostream>
#include <string>
using namespace std;

int SubsetSum(int set[], int n, int W)
{
  // Array M[0 . . . n, 0 . . . W]
  int M[n + 1][W + 1];

  string subset[n];

  // Initialize M[0, w]= 0 
  // for each w = 0, 1, . . . , W
  for(int w = 0; w <= W; w++)
    M[0][w] = 0;

  // For i = 1, 2, . . . , n
  for(int i = 1; i <= n; i++)
    // For w = 0, . . . , W
    for(int w = 0; w <= W; w++)
      if (w < set[i-1])
      {
        M[i][w] = M[i-1][w];
        subset[i - 1] = "" + set[i-1];
      }
      else
      {
        subset[i-1] = "" + set[i-1];
        M[i][w] = max(
          M[i - 1][w], 
          (set[i - 1] + M[i - 1][w - set[i - 1]])
        );
      }

  //--- Printing the array M
  cout << "Final Iteration of algorithm:\n      ";
  for(int w = 0; w <= W; w++)
    cout << w << " ";
  cout << "\n  ------------------\n";
  for(int i = 0; i <= n; i++)
  {
    if (i == 0) cout << "  0 | ";
    else cout << "  " << set[i - 1] << " | ";
    for(int j = 0; j <= W; j++)
      cout << M[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  
  // Return M[n, W]
  return M[n][W];
}

/*
  Driver Code
*/
int main()
{
  int n, W;
  cout << "\nEnter the number of elements in set: ";
  cin >> n;
  int set[n];
  cout << "Enter the set elements: ";
  for(int i = 0; i < n; i++)
    cin >> set[i];
  cout << "Enter the sum: ";
  cin >> W;
  cout << endl;
  cout << SubsetSum(set, n, W) << " is the optimum solution value.\n";

  cout << endl;
  return 0;
}