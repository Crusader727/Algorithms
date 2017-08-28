/*Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков

пирамиду.

Формат входных данных:

На вход подается количество кубиков N.

Формат выходных данных:

Вывести число различных пирамид из N кубиков.

6_1.​ Высокая пирамида. ​Каждый вышележащий слой пирамиды должен быть не больше нижележащего.

N ≤ 200.*/

#include<iostream>

long long calc(long long** mas, int n, int k) 
{
    if (k > n) 
    {
        k = n;
    }
    return mas[n][k];
}

long long getNumOfPir(int n)
{
    long long** mas = new long long*[n + 1];
    for (int i = 0; i < n + 1; i++) 
    {
        mas[i] = new long long[n + 1];
    }
    mas[0][0] = 1;
    for(int i = 0; i < n + 1 ; i++) 
    {
        for(int j = 1; j < i + 1; j++)
         {
             mas[i][j] = calc(mas, i, j - 1) + calc(mas, i - j, j);
        }
    }
    long long result = mas[n][n];
    for(int i = 0; i < n+1; i++)
    {
        delete[] mas[i];
    }
    for(int i = 0; i < n + 1 ; i++) 
    {
        for(int j = 1; j < i + 1; j++)
         {
             std::cout << mas[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    delete[] mas;
    return result;
}

int main() 
{
    int n;
    std::cin >> n;
    long long result = getNumOfPir(n);
    std::cout << result;
    return 0;
} 
