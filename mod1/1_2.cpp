/*1_2. ​Вывести разложение натурального числа n на простые множители. Простые множители должны быть
 
 упорядочены по возрастанию и разделены пробелами.
 
 2 ≤ n ≤ 106*/

#include <iostream>

void resize(int*& mass, int capasity)
{
    int* mass2 = new int[capasity * 2];
    for(int i = 0; i < capasity; i++)
        mass2[i] = mass[i];
    delete mass;
    mass = mass2;
   /*capasity *= 2;
    delete[] mass;
    mass = new int[capasity];
    for(int i = 0; i < capasity-1; i++)
        mass[i] = mass2[i];   */
}

int calc(int* values, int n, int capasity)
{
    int index = 0;
    int factor = 2;
    while(n > 1)
    {
        if(n % factor == 0)
        {
            n /= factor;
            if(index == capasity)
            {
                resize(values, capasity);
                capasity *= 2;
            }
            values[index]= factor;
            index++;
        }
        else
            factor++;
    }
    return index;
}

int main()
{
    int n;
    std::cin >> n;
    int* values = new int[1];
    int capasity = 1;
    int size = calc(values, n, capasity);
    for(int i = 0; i < size; i++)
     std::cout << values[i] << " ";
    //delete [] values; ОБОЖАЮ ТЕСТЫ ТП !!!!! ОНИ ОФИГЕННЫЕ!!!! ПРОСТО НЕТ СЛОВ!!!!!! Я В ШОКЕ!!!!!!
    return 0;
}




