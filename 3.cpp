#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

void input(int*, int, int);
void output(int*, int*, int, int, int);

int main()
{
    setlocale(LC_ALL, "");
    int n = 0, m = 0;
    cout << "������� ���-�� ����� ������� �: ";
    cin >> n;
    cout << "������� ���-�� �������� ������� �: ";
    cin >> m;
    int A[50], B[50];

    input(A, n, m);

    int column = 0, c = 0;
    for(int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if(A[i*m+j] > 0)
            {
                column = column + 1;
            }
            else
            {
                column = 0;
                i = 0;
                break;
            }
        }
        if(column == n)
        {
            B[c] = j;
            c++;
            column = 0;
        }
        int first_column = B[0], last_column = B[c-1], temp;
        for(int i = 0; i < n; i++)
        {
            temp = A[i*m+first_column];
            A[i*m+first_column] = A[i*m+last_column];
            A[i*m+last_column] = temp;
        }
    }

    output(A, B, n, m, c);

    return 0;
}

void input(int* A, int n, int m)
{
    cout <<"������� �������� " << n << "x" <<  m << " ����������� ������� �: " << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << i + 1 << " ������ " << j + 1 << " ������� = ";
            cin >> A[i*m+j];
        }
    }
    cout << "�������� �������: ";
    cout << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout << A[i*m+j] << ' ';
        }
        cout << endl;
    }
}

void output(int* A, int* B, int n, int m, int c)
{

    if(c == 0)
    {
        cout << "�������� ������� - �� ����������.";
        cout << endl;
        exit(0);
    }
    else if(c == 1)
    {
        cout << "������ 1 ������������� �������, ��� ����� �� ������ ������� = " << B[0];
    }
    else
    {
        cout << "��������� �������: ";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << A[i * m + j] << ' ';
            }
            cout << endl;
        }
        cout << "������ ������������� ��������: ";
        for(int i = 0; i < c; i++)
        {
            cout << B[i] + 1 << ' ';
        }
    }
}
