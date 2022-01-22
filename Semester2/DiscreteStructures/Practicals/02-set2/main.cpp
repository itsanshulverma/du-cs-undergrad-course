#include <iostream>

using namespace std;

class Set
{
public:
    int elements[100];
    int size = 0;

    Set();
    void input();
    void print();
    bool subset_of(Set);
    Set union_with(Set);
    Set intersection_with(Set);
    Set complement(Set);
    Set difference(Set);
    Set difference_sym(Set);
    void cartesian_prod(Set);

private:
    void addElement(int);
    bool has(int i);
};

Set::Set()
{
}
void Set::input()
{
    int itrCount;
    cout << "\nEnter the size of set : ";
    cin >> itrCount;
    cout << "Enter the elements of set : ";
    for (int i = 0; i < itrCount; i++)
    {
        int e;
        cin >> e;
        this->addElement(e);
    }
    cout << endl;
}
bool Set::has(int n)
{
    for (int i = 0; i < size; i++)
    {
        if (n == elements[i])
        {
            return true;
            break;
        }
    }
    return false;
}
void Set::addElement(int n)
{
    if (!has(n))
    {
        elements[size] = n;
        ++size;
    }
}
bool Set::subset_of(Set set)
{
    int count = 0;
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < set.size; j++)
        {
            if (this->elements[i] == set.elements[j])
            {
                count++;
                break;
            }
        }
    }
    if (count == size)
        return true;
    else
        return false;
}
Set Set::union_with(Set set)
{
    Set temp;
    for (int i = 0; i < size; i++)
    {
        temp.addElement(elements[i]);
    }
    for (int i = 0; i < set.size; i++)
    {
        temp.addElement(set.elements[i]);
    }
    return temp;
}
Set Set::intersection_with(Set set)
{
    Set temp;
    for (int i = 0; i < size; i++)
    {
        if (set.has(elements[i]))
            temp.addElement(elements[i]);
    }
    return temp;
}
Set Set::complement(Set uni_set)
{
    Set temp;
    for (int i = 0; i < uni_set.size; i++)
    {
        if (!has(uni_set.elements[i]))
            temp.addElement(uni_set.elements[i]);
    }
    return temp;
}
Set Set::difference(Set set)
{
    Set temp;
    for (int i = 0; i < size; i++)
    {
        if (!set.has(elements[i]))
            temp.addElement(elements[i]);
    }
    return temp;
}
Set Set::difference_sym(Set set)
{
    Set unionSet = union_with(set);
    Set intrSet = intersection_with(set);
    return unionSet.difference(intrSet);
}
void Set::cartesian_prod(Set set)
{
    cout << endl
         << "{ ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < set.size; j++)
        {
            cout << "{" << elements[i] << "," << set.elements[j] << "} ";
        }
    }
    cout << "}" << endl
         << endl
         << endl;
}

void Set::print()
{
    cout << "{";
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            cout << elements[i];
        else
            cout << "," << elements[i];
    }
    cout << "} ";
}

int main()
{
    Set setA = Set();
    setA.input();
    cout << "--> Set A : ";
    setA.print();
    Set setB = Set();
    setB.input();
    cout << "--> Set B : ";
    setB.print();

    if (setA.subset_of(setB))
        cout << "\n\n--> Set A is a subset of Set B.\n";
    else
        cout << "\n\n--> Set A is not a subset of Set B.\n";

    cout << endl
         << "--> Set A union Set B : ";
    setA.union_with(setB).print();

    cout << "\n\n--> Set A intersection Set B : ";
    setA.intersection_with(setB).print();

    cout << "\n\n--> Let Universal Set be ";
    Set universalSet = setA.union_with(setB);
    universalSet.print();
    cout << endl
         << "--> Complement of Set A (A') : ";
    setA.complement(universalSet).print();
    cout << endl
         << "--> Complement of Set B (B') : ";
    setB.complement(universalSet).print();

    cout << "\n\n--> Set A difference Set B : ";
    setA.difference(setB).print();

    cout << "\n\n--> Set A symmetric difference Set B : ";
    setA.difference_sym(setB).print();

    cout << "\n\n--> Cartesian product of Set A and Set B : ";
    setA.cartesian_prod(setB);

    return 0;
}