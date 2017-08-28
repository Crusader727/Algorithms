/*2_4. Скользящий максимум.

Дан массив натуральных чисел A[0..n), n не превосходит 10^8. Так же задан размер некотрого окна

(последовательно расположенных элементов массива) в этом массиве k, k<=n. Требуется для

каждого положения окна (от 0 и до n-k) вывести значение максимума в окне. Скорость работы O(n

log n), память O(k).*/


#include <iostream>
template <class T>
class MyHeap
{
    public:
    /*void SiftUp(T& arr, int i)
    {
        while(i > 0)
        {
            int parent = (i - 1) / 2;
            if(arr[i]) <= arr[parent])
                return;
            std::swap(arr[i], arr[parent]);
            index = parent;
        }
    }
    void Add(T& arr, T element)
    {
        arr.push_back(element);
        SiftUp(arr, arr.Size() - 1);
    }*/
    private:
    std::vector<T> arr;
    void SiftDown(int i)
    {
        int left = 2 * i + 1;
        int rught = 2 * i + 2;
        //search bigger son
        int largest = i;
        if(left < arr.size() && arr[i] < arr[left])
            largest = left;
        if(right < arr.size() && arr[largest] < arr[right])
            largest = right;
        //if we got bigger son push to root
        if(largest != i)
        {
            std::swap(arr[i], arr[largest]);
            SiftDown(largest);
        }
    }
    void BuildHeap(int i)
    {
        for(int i = arr.size() / 2 - 1; i >= 0; i--)
        {
            SiftDown(i);
        }
    }
};
int main()
{
    int size = 0;
    int k = 0;
    std::cin >> size;
    std::vector<int> arr;
    int buf;
    for(int i = 0; i < size; i++)
    {
        std::cin >> buf;
        arr.push_back(buf);
    }
    std::cin >> k;

    return 0;
}