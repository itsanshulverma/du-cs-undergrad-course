#include <iostream>
using namespace std;

class Relation
{
public:
    int matrix[100][100] = {0};
    int size, matrix_size;

    void input();
    void print_matrix();
    bool isReflexive();
    bool isSymmetric();
    bool isAntisymmetric();
    bool isTransitive();
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

bool Relation::isReflexive()
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

    return flag;
}
bool Relation::isSymmetric()
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
    return flag;
}
bool Relation::isAntisymmetric()
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
    return !flag;
}
bool Relation::isTransitive()
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
    return flag;
}

int main()
{
    Relation rel = Relation();
    rel.input();
    rel.print_matrix();

    if (rel.isReflexive() && rel.isSymmetric() && rel.isTransitive())
        cout << "\n\n--> The given relation is equivalence relation.\n";
    else if (rel.isReflexive() && rel.isAntisymmetric() && rel.isTransitive())
        cout << "\n\n--> The given relation is a partially ordered relation(poset).\n";
    else
        cout << "\n\n--> The given relation is neither a equivalence relation nor a poset.\n";

    return 0;
}