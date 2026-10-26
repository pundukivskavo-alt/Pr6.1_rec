// Лабораторна робота № 6. Завдання 6.1 (рекурсивний спосіб). Варіант 20
// Масив x із 24 елементів цілого типу, діапазон значень (-17,...,53).
// Критерій: всі від'ємні, крім кратних 3.
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* x, const int size, const int Low, const int High, int i)
{
    x[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(x, size, Low, High, i + 1);
}

void Print(int* x, const int size, int i)
{
    cout << setw(4) << x[i];
    if (i < size - 1)
        Print(x, size, i + 1);
    else
        cout << endl;
}

// кількість елементів, що задовольняють критерію
int Count(int* x, const int size, int i)
{
    if (i < size)
    {
        if (x[i] < 0 && x[i] % 3 != 0)
            return 1 + Count(x, size, i + 1);
        else
            return Count(x, size, i + 1);
    }
    else
        return 0;
}

// сума елементів, що задовольняють критерію
int Sum(int* x, const int size, int i)
{
    if (i < size)
    {
        if (x[i] < 0 && x[i] % 3 != 0)
            return x[i] + Sum(x, size, i + 1);
        else
            return Sum(x, size, i + 1);
    }
    else
        return 0;
}

// заміна нулями елементів, що задовольняють критерію
void Zeroing(int* x, const int size, int i)
{
    if (x[i] < 0 && x[i] % 3 != 0)
        x[i] = 0;
    if (i < size - 1)
        Zeroing(x, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));   // ініціалізація генератора випадкових чисел

    const int n = 24;
    int x[n];

    int Low = -17;
    int High = 53;

    Create(x, n, Low, High, 0);
    Print(x, n, 0);

    cout << "count = " << Count(x, n, 0) << endl;
    cout << "sum   = " << Sum(x, n, 0) << endl;

    Zeroing(x, n, 0);
    Print(x, n, 0);

    return 0;
}


