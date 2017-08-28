/*1_4. Строки.

Напишите программу, печатающую набор строк в лексикографическом порядке.

Строки разделяются символом перевода строки '\n'. Если последний символ в потоке ввода '\n',

считать, что после него нет пустой строки. Максимальная длина строки 255 символов. Написать

свою функцию сравнения строк.*/


#include <iostream>
#include <string>
#include <vector>


bool myCmp(std::string& a, std::string& b)
{
    int size = a.size();
    if(a.size() > b.size())
        size = b.size();
    for(int i = 0; i < size; i++)
    {
        if(a[i] < b[i])
            return true;
        if(a[i] > b[i])
            return false;
    }
    if(size == b.size())
        return false;
    else
        return true;
    //return a < b;
}


template <class T>
void insertion_sort(T* arr, int size, bool(*cmpLess)(T&,T&))
{
    int j = 0;
    T tmp ;
    for(int i = 1; i < size; i++)
    {
       tmp = arr[i];
       for(j = i - 1; j >= 0 && cmpLess(tmp, arr[j]); j--) 
       {
           arr[j + 1] = arr[j]; 
       }
       arr[j + 1] = tmp;
    }
}
int main()
{
    int size = 0;
    std::cin >> size;
    std::string* arr = new std::string[size];
    for(int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    insertion_sort(arr,size,myCmp);
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    delete[] arr;
    return 0;
}