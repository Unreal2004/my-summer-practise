#include <iostream>
#include <clocale>

using std::cout;
using std::cin;
using std::endl;

void input(int*, int);
int maximal_element(int*, int);
void output(int*, int);

int main()
{
    setlocale(LC_CTYPE, "RUS");

    int n = 3,k = 0, max_element;
    cout << "¬ведите количество элементов массива: ";
    cin >> n;
    int array[9];
    cout << "¬ведите число \"k\": ";
    cin >> k;
    input(array, n);
    max_element = maximal_element(array, n);
    int changed_array[9],repeat = 1, c = 0; // c=счЄтщик элементов дл€ changed_array , repeat=количество повторений числа
    for(size_t i = 1; i < n; i++)
    {
        while(array[i-1] == array[i])
        {
            repeat++;
            i=i+1;
        }
        if(repeat < k && repeat > 1)
        {
            changed_array[c] = max_element;
            c=c+1;
            repeat = 1;
            continue;
        }
        if(repeat >= k)
        {
            while(array[i-2] == array[i-1])
            {
                repeat = repeat - 1;
                i=i-1;
            }
            while(array[i-1] == array[i])
            {
                changed_array[c] = array[i-1];
                c++;
                if(array[i] != array[i+1])
                {
                    changed_array[c] = array[i];
                    c++;
                }
                i=i+1;
            }
            continue;
        }
        changed_array[c] = array[i-1];
        c++;
    }
    if(array[n-1] != array[n-2])
    {
        changed_array[c] = array[n-1];
        c=c+1;
    }
    else
    {
        if(repeat < k && repeat > 1)
        {
            changed_array[c] = max_element;
            c=c+1;
        }
    }
    output(changed_array, c);

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

int maximal_element(int* array, int n) // находим максимальный элемент
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void output(int* changed_array, int c) // выводим изменЄнный массив
{
    cout << endl;
    cout << "»зменЄнный массив: ";
    cout << endl;
    for (int i = 0; i < c; i++)
    {
        cout << "b[" << i + 1 << "] = " << changed_array[i];
        cout << endl;
    }
}
