#include <iostream>
using namespace std;

class Relation
{
public:
    int matrix[100][100] = {0};
    int size, matrix_size;

    void input();
    void print_matrix();
    void isReflexive();
    void isSymmetric();
    void isAntisymmetric();
    void isTransitive();
};
void Relation::input()
{
    int max = 0;
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
        matrix[a - 1][b - 1] = 1;
        if (a > max)
            max = a;
        else if (b > max)
            max = b;
    }
    matrix_size = max;
}

void Relation::print_matrix()
{
    cout << "\n--> Matrix Representation : \n";
    for (int i = 0; i < matrix_size; i++)
    {
        cout << endl
             << "    ";
        for (int j = 0; j < matrix_size; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }
}

void Relation::isReflexive()
{
    int flag = 0;
    for (int i = 0; i < matrix_size; i++)
    {
        if (matrix[i][i] == 1)
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
        cout << "--> Given relation is not reflexive\n";
    else
        cout << "--> Given relation is reflexive\n";
}
void Relation::isSymmetric()
{
    int flag = 0;
    for (int i = 0; i < matrix_size; i++)
        for (int j = 0; j < matrix_size; j++)
            if (matrix[i][j] == matrix[j][i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
    if (flag == 0)
        cout << "--> Given relation is not symmetric\n";
    else
        cout << "--> Given relation is symmetric\n";
}
void Relation::isAntisymmetric()
{
    int flag = 0;
    for (int i = 0; i < matrix_size; i++)
        for (int j = 0; j < matrix_size; j++)
            if ((matrix[i][j] || matrix[j][i] == 0) && i != j)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
    if (flag == 0)
        cout << "--> Given relation is antisymmetric\n";
    else
        cout << "--> Given relation is not antisymmetric\n";
}
void Relation::isTransitive()
{
    int flag = 1;
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            if (matrix[i][j] == 1)
            {
                for (int k = 0; k < size; k++)
                {
                    if (matrix[j][k] == 1 && matrix[i][k] != 1)
                    {
                        flag = 0;
                    }
                }
            }
        }
    }
    if (flag == 0)
        cout << "--> Given relation is not transitive\n";
    else
        cout << "--> Given relation is transitive\n";
}

int main()
{
    Relation rel = Relation();
    rel.input();
    rel.print_matrix();

    cout << endl
         << endl;
    rel.isReflexive();
    rel.isSymmetric();
    rel.isTransitive();
    rel.isAntisymmetric();

    return 0;
}