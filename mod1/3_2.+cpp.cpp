/*3_2. ​Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива строго
 
 возрастают, а на интервале [m, n-1] строго убывают. Найти m за O(log m).
 
 2 ≤ n ≤ 10000.*/

#include <iostream>


int calc(int* mass, int end)
{
    int buf;
    int l = 0 , r = end;
    buf = 1;
    for (int i = 0; buf < end; i++)
    {
        if(mass[buf - 1] > mass[buf])
        {
            l = buf/2;
            r = buf;
            break;
        }
        buf *= 2;
    }

    int middle = (l + r) / 2;
    while (r - l > 1)
    {
        middle = (l + r) / 2;
        if(mass[middle - 1] > mass[middle])
        {
            r = middle;
        }
        else if(mass[middle-1] < mass[middle] && mass[middle] > mass[middle+1])
        {
            return middle;
        }
        else
        {
            l = middle;
        } 
    } 
    return l;
}
//  0 1 2 3 4 5 6 7 8 9
// -5 2 5 6 7 8 9 5 2 1
// 1 9
// 5 9
//
int main()
{
    int n;
    std::cin >> n;
    if(n <= 1)
    {
        std::cout << 0;
        return 0;
    }

    int* mass = new int[n];
    for(int i = 0; i < n; ++i)
        std::cin >> mass[i];
    std::cout << calc(mass, n);

    delete [] mass;
    return 0;
}
