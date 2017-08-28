/* 5_1
* Дан фрагмент последовательности скобок, состоящей из символов (){}[]. 
* Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную  последовательность. 
* Длина исходной последовательности ≤ 200000.  Формат входных данных.​ Строка, содержащая символы (){}[] и, 
* возможно, перевод строки.  Формат выходных данных.​ Если возможно ­ вывести минимальную корректную последовательность, 
* иначе ­  напечатать "​IMPOSSIBLE​". 
* */
#include <iostream>
#include <string>

class MyQ 
{
public:
    MyQ(int cap) :cap(cap), head(0), tail(0) 
    {
        arr = new char[cap];
    }
    ~MyQ()
    {
        delete[] arr;
    }
    void push_back(char value) 
    {
        arr[tail] = value;
        tail = (tail + 1) % cap;
        if (tail == head)
            recap();
    }
    void push_front(char value) 
    {
        if(head == 0)
            head = cap - 1;
        else 
            head --;
        arr[head] = value;
        if (tail == head)
            recap();
    }

    char pop_front() 
    {
        if (head == tail)
        {
            return -1;
        } 
        else
        {
            char res = arr[head];
            head = (head + 1) % cap;
            return res;
        }
    }
    char pop_back() 
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
            char res = arr[tail];
            return res;
        }
    }
    bool Empty()
    {
        if(head == tail)
            return true;
        else
            return false;
    }

private:
    char* arr;
    int cap;
    int head;
    int tail;
    void recap()
    {
        char* arr2 = new char[cap * 2];
        for (int i = 0; i < cap; i++)  
            arr2[i] = arr[(head + i) % cap];
        delete[] arr;
        arr = arr2;  
        head = 0;
        tail = cap; 
        cap *= 2;
    }

};


bool checkbrackets(MyQ& l1, MyQ& l2, char c1, char c2)
{
        char buf;
        l2.push_back(c1);
        if(l1.Empty())
        {
          l2.push_front(c2);
        }
        else
        {
            buf = l1.pop_back();
            if(buf != c2)
            {
                std::cout << "IMPOSSIBLE";
                return false;
            }
        }
        return true;
}

bool check(MyQ& l1, MyQ& l2, char* str,int size)
{
    char buf = 0;
	for(int i = 0; i < size; i++)
	{
		if(str[i] == '{' || str[i] == '(' || str[i] == '[' )
        {
			l1.push_back(str[i]);
            l2.push_back(str[i]);
        }
        if(str[i] == '}')
        {
            if(!checkbrackets(l1,l2,'}','{'))
                return false;
        }

        if(str[i] == ')')
        {
            if(!checkbrackets(l1,l2,')','('))
                return false;
        }
        if(str[i] == ']')
        {
            if(!checkbrackets(l1,l2,']','['))
                return false;
        }
	}
    while(!l1.Empty())
    {
        buf = l1.pop_back();
        if(buf == '{')
            l2.push_back('}');
        if(buf == '(')
            l2.push_back(')');
        if(buf == '[')
            l2.push_back(']');
    }
    return true;
}

int main()
{
	MyQ l1(8);
	MyQ l2(8);
	//std::string str;
	//std::cin >> str;
    int size = 20;
    char* str = new char[size];
    char buf;
    int i;
    while(std::cin >> buf)
    {
        if(i == size)
        {
            char* str2 = new char[size*2];
            for(int i = 0; i < size; i++)
                str2[i] = str[i];
            delete[] str;
            str = str2;
            size *= 2;
        }
        str[i] = buf;
        i++;
    }
    if(!check(l1,l2,str,i))
        return 0;
    while(!l2.Empty())
        std::cout << l2.pop_front();

	return 0;

}
