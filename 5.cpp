#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_CTYPE, "RUS");

    char intermediate[20], compare, Y = 'Y', y = 'y';
    int n = 1, mal, flag = 0, cmp_y = y, cmp_Y = Y, cmp;
    struct TV
    {
        char name[20];
        int time[2];
        int duration;
    };

    TV array[n];
    for(size_t i = 0; i < n; i++)
    {
        cout << "�������� ������������ = ";
        //cin.getline(array[i].name, 20);
        //cin.get(array[i].name, q).get();
        cin >> array[i].name;
        cout << "����� ������ � ����(����) = ";
        cin >> array[i].time[0];
        cout << "����� ������ � ����(������) = ";
        cin >> array[i].time[1];
        cout << "����������������� � ������� = ";
        cin >> array[i].duration;
        cout << endl;
    }

    for(int i = 0; i < n - 1; i++)
        {
            mal = i;
            for(int j = i + 1; j < n; j++)
            {
                if(array[j].time[0] < array[mal].time[0])
                {
                    mal = j;
                }
                if(array[j].time[0] == array[mal].time[0])
                {
                    if(array[j].time[1] < array[mal].time[1])
                    {
                        mal = j;
                    }
                }

            }
            TV temp = array[i];
            array[i] = array[mal];
            array[mal] = temp;
        }
    cout << "��������������� �� ������� ������ ������ ��������: ";
    cout << endl << endl;
    for(size_t i = 0; i < n; i++)
    {
        cout << "�������� ������������ = ";
        cout << array[i].name;
        cout << endl;
        cout << "����� ������ � ����(����) = ";
        cout << array[i].time[0];
        cout << endl;
        cout << "����� ������ � ����(������) = ";
        cout << array[i].time[1];
        cout << endl;
        cout << "����������������� � ������� = ";
        cout << array[i].duration;
        cout << endl;
    }

    while(true)
    {
        cout << endl;
        cout << "������� �������� ������������: ";
        cin >> intermediate;
        cout << endl;
        for(size_t i = 0; i < n; i++)
        {
            if(!strcmp(array[i].name, intermediate))
            {
                cout << "����� ������ � ����(����) = ";
                cout << array[i].time[0];
                cout << endl;
                cout << "����� ������ � ����(������) = ";
                cout << array[i].time[1];
                cout << endl;
                cout << "����������������� � ������� = ";
                cout << array[i].duration;
                cout << endl;
                flag = 1;
                i = 0;
                break;
            }
            else continue;
        }
        if(flag == 1 )
        {
            flag = 0;
            cout << "������ ����� ������ ��� ����� ������������?(Y/N): ";
            cin >> compare;
            cmp = compare;
            if(cmp == cmp_y || cmp == cmp_Y) continue;
            else break;
        }
        else if(flag == 0)
        {
            cout << "����� ������������ ���. ���������� �����(Y/N): ";
            cin >> compare;
            cmp = compare;
            if(cmp == cmp_y || cmp == cmp_Y) continue;
            else break;
        }
    }
    cout << endl;
    cout << "��������� ���������!";

    return 0;
}
