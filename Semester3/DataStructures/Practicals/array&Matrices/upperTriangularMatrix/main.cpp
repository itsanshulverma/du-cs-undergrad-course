#include <iostream>
using namespace std;

/* Upper Triangular Matrix Class */
class UpperTriagMatrix
{
	int *arr;
	int size;
	public:
	UpperTriagMatrix(int x)
	{
		this->size = x;
		arr = new int[size];
	}
	~UpperTriagMatrix()
	{
		delete[] arr;
	}

	/* To store an element 'n' at index (x, y): (input as 1-indexing) */
	void store(int x, int y, int n)
	{
		if (x < 1 || x > size || y < 1 || y > size)
		{
			cerr << "Err: Index out of bound.";
			exit(1);
		}
		if (x <= y)
    {
      int k = (y*(y-1)/2 + (x-1));
      arr[k] = n;
    }
	}

	/* To retrive element at index (x, y): (input as 1-indexing) */
	int retrieve(int x, int y)
	{
		if (x < 1 || x > size || y < 1 || y > size)
		{
			cerr << "Err: Index out of bound.";
			exit(1);
			return -1;
		}
		else if (x <= y)
		{
      int k = (y*(y-1)/2 + (x-1));
      return arr[k];
    }
		return 0;
	}

	/* To show all the elements of matrix */
	void show()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << "\n\t";
			for (int j = 0; j < size; ++j)
			{
				cout << retrieve(i+1, j+1) << "  ";
			}
		}
		cout << endl;
	}
};

int main()
{
	int x, y;

	/* Take input and store */
	cout << "\nEnter the no. of rows and columns: ";
	cin >> x >> y;
	if (x != y)
	{
		cerr << "Err: No. of rows and columns must be same.";
		exit(1);
	}

	UpperTriagMatrix upp(x);
	cout << "Enter the elements (by row): ";
	for (int i = 1; i <= x; ++i)
	{
		int n;
    for (int j = i; j <= x; ++j)
    {
      cin >> n;
		  upp.store(i, j, n);
    }
	}

	/* Show matrix */
	cout << "\nResultant Matrix:\n";
	upp.show();

	/* Retrieve elements */
	char ch;
	cout << "\nRetrive individual elements? (y/n): ";
	cin >> ch;
	while (ch == 'Y' || ch == 'y'){
		cout << "\nEnter the index of element to be retrieved: ";
		cin >> x >> y;
		cout << "--> " << upp.retrieve(x, y) << endl;

		cout << "More? (y/n): ";
		cin >> ch;
	}

	cout << endl;
  return 0;
}