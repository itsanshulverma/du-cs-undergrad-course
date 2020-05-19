#include <iostream>

using namespace std;

class Relation
{
public:
    int elements[100][2];
    int matrix[100][100] = {0};
    int size;

    void input();
    void print();
    void extract_sets();
    void print_matrix();
    bool isReflexive();
    bool isSymmetric();
    bool isAsymmetric();
    bool isTransitive();

private:
    int *set1, *set2;
    int n1 = 0, n2 = 0;
    void arrayto_set(int *, int *);
};
void Relation::input()
{
    cout << endl
         << endl
         << "Enter the length of relation : ";
    cin >> size;
    cout << "Enter the elements of relation : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << " : ";
        int a, b;
        cin >> a >> b;
        elements[i][0] = a;
        elements[i][1] = b;
        matrix[a - 1][b - 1] = 1;
    }
}
void Relation::print()
{
    cout << endl
         << endl
         << "--> Given relation : {";
    for (int i = 0; i < size; i++)
    {
        cout << "( ";
        for (int j = 0; j < 2; j++)
        {
            cout << elements[i][j] << " ";
        }
        cout << ")";
    }
    cout << "}" << endl;
    ;
}
void Relation::arrayto_set(int *arr, int *n)
{
    if (*n == 0 || *n == 1)
        return;

    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < *n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                *n = *n - 1;
            }
        }
    }
}
void Relation::extract_sets()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0)
            {
                set1[n1] = elements[j][i];
                n1++;
                cout << "s1 e" << n1 << " : " << set1[n1];
            }
            else
            {
                set2[n2] = elements[j][i];
                n2++;
                cout << "s2 e" << n2 << " : " << set2[n2];
            }
        }
    }
    // arrayto_set(set1, &n1);
    // arrayto_set(set2, &n2);
    // print(set1, n1);
    // print(set2, n2);
}
void Relation::print_matrix()
{
    cout << endl
         << endl
         << "--> Matrix Representation : {";
    for (int i = 0; i < size; i++)
    {
        cout << endl
             << "   ";
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }
}

int main()
{
    Relation rel = Relation();
    rel.input();
    rel.print();
    rel.print_matrix();

    return 0;
}