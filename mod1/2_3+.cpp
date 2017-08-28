/*2_3. ​Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество
 
 таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
 
 n, m ≤ 100000.*/


#include <iostream>


int calc(int* mass1, size_t n, int* mass2, size_t m, int k)
{
    int result = 0;
    int j = m-1;
    int i = 0;
    int buff = 0;
    while(j!= -1 && i != n)
    {
        buff = mass1[i] + mass2[j];
        if(buff == k)
        {
            result++;
            j--;
            i++;
        }
        if(buff < k)
            i++;
        if(buff > k)
            j--;
    }
    return result;

}

int main()
{
    int n, m, k;
    //creating first arr with length n
    std::cin >> n;
    int* mass1 = new int[n];
    for(int i = 0; i < n; ++i)
        std::cin >> mass1[i];
    //creating second arr with length m
    std::cin >> m;
    int* mass2 = new int[m];
    for(int i = 0; i < m; ++i)
        std::cin >> mass2[i];
    std::cin >> k;
    std::cout << calc(mass1, n, mass2, m, k) << std::endl;
    //delete[] mass1;
    //delete[] mass2;
    return 0;
}
