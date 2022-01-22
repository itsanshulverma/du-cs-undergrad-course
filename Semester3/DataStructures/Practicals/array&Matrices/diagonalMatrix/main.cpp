#include <iostream>
using namespace std;

/* Diagonal Matrix Class */
class DiagonalMatrix
{
	int *arr;
	int size;
	public:
	DiagonalMatrix(int x)
	{
		this->size = x;
		arr = new int[size];
	}
	~DiagonalMatrix()
	{
		delete[] arr;
	}

	/* To store an element 'n' at index (x, y): (input as 1-indexing) */
	void store(int x, int y, int n)
	{
		if (x > size || y > size)
		{
			cerr << "Err: Index out of bound.";
			exit(1);
		}
		if (x == y)
			arr[x-1] = n;
	}

	/* To retrive element at index (x, y): (input as 1-indexing) */
	int retrieve(int x, int y)
	{
		if (x > size || y > size)
		{
			cerr << "Err: Index out of bound.";
			exit(1);
			return -1;
		}
		else if (x == y)
			return arr[x-1];
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
		cerr << "Err: No. of rows and columns must be same in a Diagonal Matrix.";
		exit(1);
	}

	DiagonalMatrix diag(x);
	cout << "Enter the diagonal elements: ";
	for (int i = 1; i <= x; ++i)
	{
		int n;
		cin >> n;
		diag.store(i, i, n);
	}

	/* Show matrix */
	cout << "\nResultant Matrix:\n";
	diag.show();

	/* Retrieve elements */
	char ch;
	cout << "\nRetrive individual elements? (y/n): ";
	cin >> ch;
	while (ch == 'Y' || ch == 'y'){
		cout << "\nEnter the index of element to be retrieved: ";
		cin >> x >> y;
		cout << "--> " << diag.retrieve(x, y) << endl;

		cout << "More? (y/n): ";
		cin >> ch;
	}

	cout << endl;
  return 0;
}