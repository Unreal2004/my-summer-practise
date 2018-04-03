#include <iostream>
#include <clocale>
#include <climits>

using std::cout;
using std::cin;
using std::endl;

int creating(int*, int*, int, int, int);
int find_max_elem(int*, int);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int n = 100;
    cout << "Введите размерность матрицы(вектора): ";
    cin >> n;
    int max_element, min_index = 0, l = 0;
    int *X = new int [n];
    int *Y = new int [n];
    for(int i = 0; i < n; i++)
    {
        cout << "x[" << i+1 << "] = ";
        cin >> X[i];
    }

    cout << "Массив X: ";
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << X[i] << ' ';
    }

    max_element = find_max_elem(X,n);
    cout << endl;
    cout << "Номер максимального элемента массива Х = " << max_element + 1;
    cout << endl << endl;

    l = creating(X,Y,n,l,min_index);

    cout << "Массив Y: ";
    cout << endl;
    for(int i = 0; i < l; i++)
    {
        cout << Y[i] << ' ';
    }

    max_element = find_max_elem(Y,l);
    cout << endl;
    cout << "Номер максимального элемента массива Y = " << max_element + 1;
    cout << endl;

    delete [] X;
    delete [] Y;

    return 0;
}

int creating(int* X, int* Y, int n, int l, int min_index)
{
    int min_elem = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(min_elem > X[i])
        {
            min_elem = X[i];
            min_index = i;
        }
    }
    for(int end = n-1; end >= 0; end--)
    {
        if(X[end] == X[min_index])
        {
            continue;
        }
        Y[l] = X[end];
        l++;
    }


    return l;
}

int find_max_elem(int* A, int n)
{
    int max_elem = INT_MIN, max_x;
    for(int i = 0; i < n; i++)
    {
        if(max_elem < A[i])
        {
            max_elem = A[i];
            max_x = i;
        }
    }

    return max_x;
}
