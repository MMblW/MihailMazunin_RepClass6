#include <iostream>
#include "List_3.h"

using namespace std;

int main()
{
    system("chcp 1251");

    List example(10);

    Iterator a = example.first();
    for (int i = 0; i < 10; i++)
    {
        cout << example[i] << " ";
    }
    cout << endl;

    int index = 3;
    a + index;
    cout << *a << endl;
    cout << endl;
}