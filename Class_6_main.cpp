#include <iostream>
using namespace std;

class Iterator
{
    friend class List;
private:
    int* elem;
public:
    Iterator()
    {
        elem = 0;
    }
    Iterator(const Iterator& it)
    {
        elem = it.elem;
    }
    bool operator == (Iterator& it)
    {
        return elem == it.elem;
    }
    bool operator != (Iterator& it)
    {
        return elem != it.elem;
    }
    void operator + (int n)
    {
        elem += n;
    }
    void operator - (int n)
    {
        elem -= n;
    }
    int& operator *()
    {
        return *elem;
    }
    void Show()
    {
        cout << *elem << endl;
    }
};

class List
{
private:
    int size;
    int* data;
    Iterator beg;
    Iterator end;
public:
    List(int a, int* arr[])
    {
        size = a;
        data = *arr;
        beg.elem = &data[0];
        end.elem = &data[size - 1];
    }
    List(List& a)
    {
        size = a.size;
        data = a.data;
        beg = a.beg;
        end = a.end;
    }
    ~List()
    {
        // No dynamic
    }
    int& operator [](int index)
    {
        return data[index];
    }
    int operator ()()
    {
        return size;
    }
    int Multiply(List b, int i)
    {
        return data[i] * b.data[i];
    }
    void Forward(Iterator& it, int n)
    {
        it + n;
    }
    void Backward(Iterator& it, int n)
    {
        it - n;
    }
    Iterator First()
    {
        return beg;
    }
    Iterator Last()
    {
        return end;
    }
    void Show(Iterator& it)
    {
        int a = *it;
        cout << data[a] << endl;
    }
};
int main()
{
    system("chcp 1251");

    int* arr = new int[10];
    List example(10, &arr);
    for (int i = 1; i <= 10; i++)
    {
        arr[i - 1] = i;
    }

    Iterator a = example.First();
    a.Show();

    a = example.Last();
    a.Show();

    example.Backward(a, 8);
    example.Show(a);

    int* arr2 = new int[10];
    List example2(10, &arr2);
    for (int i = 3; i <= 12; i++)
    {
        arr2[i - 3] = i;
    }

    cout << example.Multiply(example2, 3) << endl;
}