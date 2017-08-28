/*
Формат входных данных.

В первой строке количество команд n. n ≤ 1000000.

Каждая команда задаётся как 2 целых числа: a b.

a = 1 - push front

a = 2 - pop front

a = 3 - push back

a = 4 - pop back

Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.

Для очереди используются команды 2 и 3. Для дека используются все четыре команды.

Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры

данных, то ожидается “-1”.

Формат выходных данных.

Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не

оправдалось, то напечатать NO.

////////////////////
4_2. ​Реализовать дек с динамическим зацикленным буфером.
///////////////////////
*/


#include <iostream>


struct node
{
	node* prev;
	node* next;
	int value;
};


class List
{
public:
	node* head;
	node* tail;
	List()
	{
		head = NULL;
		tail = NULL;
	}
	void push_front(int v)
	{
		if(head == NULL)
		{
			node* ptr = new node;
			ptr->prev = ptr;
			ptr->next = ptr;
			ptr->value = v;
			head = ptr;
			tail = ptr;
		}
		else
		{
			node* ptr = new node;
			ptr->next = head;
			ptr->prev = tail;
			ptr->value = v;
			tail->next = ptr;
			head->prev = ptr;
			head = ptr;
		}
	}
	void push_back(int v)
	{
		if(head == NULL)
		{
			node* ptr = new node;
			ptr->next = ptr;
			ptr->prev = ptr;
			ptr->value = v;
			head = ptr;
			tail = ptr;
		}
		else
		{
			node* ptr = new node;
			ptr->next = head;
			ptr->prev = tail;
			ptr->value = v;
			tail->next = ptr;
			head->prev = ptr;
			tail = ptr;
		}
	}



	bool pop_front(int v)
	{
		if(head == NULL)
		{
			if(v == -1)
				return true;

			else
				return false;
		}
		else
		{
			if(head->value != v)
			{
				return false;
			}
			else
			{
				if(head == tail)
				{
					delete head;
					head = tail = NULL;
					return true;
				}
				else
				{
					node* ptr = head;
					head = ptr->next;
					head->prev = tail;
					tail->next = head;
					delete ptr;
					return true;
				}
			}
		}
	}

	bool pop_back(int v)
	{
		//count--;
		if(tail == NULL)
		{
			if(v == -1)
				return true;
			else
				return false;
		}
		else
		{
			if(tail->value != v)
			{
				return false;
			}
			else
			{
				if(head == tail)
				{
					delete head;
					head = tail = NULL;
					return true;
				}
				else
				{
					node* ptr = tail;
					tail = ptr->prev;
					head->prev = tail;
					tail->next = head;
					delete ptr;
					return true;
				}
			}
		}	
	}
	~List()
	{
			while(head != NULL)
				pop_front(head->value);
			head = tail = NULL;
	}

};

int main()
{
	List l;
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
			if(!l.pop_front(b))
				{
					std::cout << "NO";
					return 0;
				}
		}
		if(a == 4)
		{
			if(!l.pop_back(b))
				{
					std::cout << "NO";
					return 0;
				}
		}

	}
	std::cout << "YES";
	return 0;
}