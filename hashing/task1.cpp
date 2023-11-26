#include <iostream>

using namespace std;

class LinearProbing
{
private:
    int i;
    int table_size;
    int array[INT16_MAX] = {0};
    float lf;

public:
    LinearProbing(int n) : table_size(n), i(0), lf(0) {}
    void insert(int value)
    {
        for (int i = 0; i < 6; i++)
        {
            int index = (value + i) % table_size;
            if (!array[index])
            {
                array[index] = value;
                lf++;
                cout << "Inserted : Index-" << index << " (L.F=" << lf / table_size << ")" << endl;
                return;
            }
            else
            {
                cout << "Collision: Index-" << index << endl;
            }
        }
        cout << "Input Abandoned" << endl;
    }
};

class QuadraticProbing
{
private:
    int i;
    int table_size;
    int array[INT16_MAX] = {0};
    float lf;

public:
    QuadraticProbing(int n) : table_size(n), i(0), lf(0) {}
    void insert(int value)
    {
        for (int i = 0; i < 6; i++)
        {
            int index = (value + i * i) % table_size;
            if (!array[index])
            {
                array[index] = value;
                lf++;
                cout << "Inserted : Index-" << index << " (L.F = " << lf / table_size << ")" << endl;
                return;
            }
            else
            {
                cout << "Collision: Index-" << index << endl;
            }
        }
        cout << "Input Abandoned" << endl;
    }
};

class DoubleProbing
{
private:
    int i;
    int table_size;
    int array[INT16_MAX] = {0};
    float lf;

public:
    DoubleProbing(int n) : table_size(n), i(0), lf(0) {}
    void insert(int value)
    {
        for (int i = 0; i < 6; i++)
        {
            int index = i == 0 ? value % table_size : (value + i * (7 - value % 7)) % table_size;
            if (!array[index])
            {
                array[index] = value;
                lf++;
                cout << "Inserted : Index-" << index << " (L.F = " << lf / table_size << ")" << endl;
                return;
            }
            else
            {
                cout << "Collision: Index-" << index << endl;
            }
        }
        cout << "Input Abandoned" << endl;
    }
};

void LinearHashing()
{
    int t_size, n;
    cin >> t_size >> n;
    LinearProbing htable(t_size);
    while (n--)
    {
        int k;
        cin >> k;
        htable.insert(k);
    }
}

void QuadraticHashing()
{
    int t_size, n;
    cin >> t_size >> n;
    QuadraticProbing htable(t_size);
    while (n--)
    {
        int k;
        cin >> k;
        htable.insert(k);
    }
}

void DoubleHashing()
{
    int t_size, n;
    cin >> t_size >> n;
    DoubleProbing htable(t_size);
    while (n--)
    {
        int k;
        cin >> k;
        htable.insert(k);
    }
}

int main()
{
    int hash_type;
    cin >> hash_type;
    if (hash_type == 1)
    {
        LinearHashing();
    }
    else if (hash_type == 2)
    {
        QuadraticHashing();
    }
    else if (hash_type == 3)
    {
        DoubleHashing();
    }
}