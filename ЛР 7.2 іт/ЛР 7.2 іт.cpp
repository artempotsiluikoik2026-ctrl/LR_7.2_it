//ЛР 7.2 іт

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int SumMinEvenCols(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int S = SumMinEvenCols(a, k, n);
    cout << "S = " << S << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumMinEvenCols(int** a, const int k, const int n)
{
    int S = 0;
    int min;
    for (int j = 0; j < n; j++)
        if ((j + 1) % 2 == 0)
        {
            min = a[0][j];
            for (int i = 1; i < k; i++)
                if (a[i][j] < min)
                    min = a[i][j];
            S += min;
        }
    return S;
}