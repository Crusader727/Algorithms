
#include <iostream>
#include <cmath>

struct point
{
    int x;
    int y;
    double angle;
};

void SetAngles(point* arr, int size)
{
    arr[0].angle = 0;
    for(int i = 1; i < size; i++)
    {
        arr[i].angle = (3 * (arr[i].x-arr[0].x))/(3 * sqrt((arr[i].y-arr[0].y)*(arr[i].y-arr[0].y)+(arr[i].x-arr[0].x)*(arr[i].x-arr[0].x)));
        if(arr[i].y < arr[0].y)
            arr[i].angle = 2 - arr[i].angle;
    }
}

bool myCmp(point& a, point& b)
{
    if(a.angle < b.angle )
        return true;
    if(a.angle == b.angle && a.x < b.x)
        return true;
    else
        return false;

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
    point* arr = new point[size];
    for(int i = 0; i < size; i++)
    {
        std::cin >> arr[i].x;
        std::cin >> arr[i].y;
    } 
    point min;
    for(int i = 1; i < size; i++)
    {
        if((arr[0].x > arr[i].x) || (arr[0].x == arr[i].x && arr[0].y > arr[i].y))
            {
                min.x = arr[0].x;
                min.y = arr[0].y;
                arr[0].x = arr[i].x;
                arr[0].y = arr[i].y;
                arr[i].x = min.x;
                arr[i].y = min.y;
            }
    }
    SetAngles(arr,size);
    
    insertion_sort(arr,size,myCmp);
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i].x << ' ' << arr[i].y << std::endl;
    }
    delete[] arr;
    return 0;
}