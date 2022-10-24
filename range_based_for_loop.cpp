#include <iostream>
#include <array>
using namespace std;

int main()
{
    // int arr[10];
    array<int, 10> arr;

    for (int i = 1; i <= 10; i++)
        arr[i - 1] = i;

    // basically a for each loop!
    // great for situations when we wanna do something
    // for each element in an array/iterable
    for (int element : arr)
        cout << element << " ";
}