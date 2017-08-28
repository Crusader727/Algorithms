// Вариант 4_2
// Во всех задачах из следующего списка следует написать структуру данных, обрабатывающую команды
//         push* и pop*.
// Формат входных данных.
// В первой строке количество команд n. n ≤ 1000000.
// Каждая команда задаётся как 2 целых числа: a b.
//         a = 1 - push front
//         a = 2 - pop front
//         a = 3 - push back
//         a = 4 - pop back
//         Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
// Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
// Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры
//         данных, то ожидается “-1”.
// Формат выходных данных.
// Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не
// оправдалось, то напечатать NO.
// 4_2. ​Реализовать дек с динамическим зацикленным буфером.

#include <iostream>

class MyQ 
{
public:
    MyQ(int cap) :cap(cap), head(0), tail(0) 
    {
        arr = new int[cap];
    }
    ~MyQ()
    {
        delete[] arr;
    }
    void push_back(int value) 
    {
        arr[tail] = value;
        tail = (tail + 1) % cap;
        if (tail == head)
            recap();
    }
    void push_front(int value) 
    {
        if(head == 0)
            head = cap - 1;
        else 
            head --;
        arr[head] = value;
        if (tail == head)
            recap();
    }

    int pop_front() 
    {
        if (head == tail)
        {
            return -1;
        } 
        else
        {
            int res = arr[head];
            head = (head + 1) % cap;
            return res;
        }
    }
    int pop_back() 
    {
        if (head == tail)
        {
            return -1;
        } 
        else
        {
            if(tail == 0)
                tail = cap - 1;
            else
                tail --;
            int res = arr[tail];
            return res;
        }
    }

private:
    int* arr;
    int cap;
    int head;
    int tail;
    void recap()
    {
        int* arr2 = new int[cap * 2];
        for (int i = 0; i < cap; i++)  
            arr2[i] = arr[(head + i) % cap];
        delete[] arr;
        arr = arr2;
        head = 0;
        tail = cap; 
        cap *= 2;
    }

};


int main()
{
	MyQ l(8);
	int n,a,b;
	std::cin >> n;
	for(int i = 0; i < n; ++i)
	{
		std::cin >> a >> b;
		if(a == 1)
			l.push_front(b);
		if(a == 3)
			l.push_back(b);
		if(a == 2)
		{
			if(l.pop_front() != b)
				{
					std::cout << "NO";
					return 0;
				}
		}
		if(a == 4)
		{
			if(l.pop_back() != b)
				{
					std::cout << "NO";
					return 0;
				}
		}

	}
	std::cout << "YES";
	return 0;
}