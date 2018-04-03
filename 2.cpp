#include <iostream>
#include <clocale>
#include <cstdio>
#include <climits>

using std::cout;
using std::cin;
using std::endl;

void input(int*, int);
void output(int*, int);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int n = 3, k = 0, min = 0, temp;
    cout << "¬ведите количество элементов массива: ";
    cin >> n;
    int array[50];
    cout << "¬ведите число \"k\": ";
    cin >> k;

    input(array, n);

    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(array[j] < array[min] && array[j] > k && array[min] > k)
            {
                min = j;
            }
            else continue;
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }


    output(array, n);

    return 0;
}

void input(int* array,int n) // вводим исходный массив
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> array[i];
    }
}

void output(int* array, int n) // выводим изменЄнный массив
{
    cout << endl;
    cout << "»зменЄнный массив: ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "b[" << i + 1 << "] = " << array[i];
        cout << endl;
    }
}
