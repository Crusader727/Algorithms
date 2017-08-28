#include <iostream>
#include <vector>

#define HASH1 11
#define HASH2 13
#define REHASH 0.75
#define deleted "DEL"


int hash1(std::string& x, int size) // хеш-функция 1
{
	int hash = 0;
	for (int i = x.size(); i >= 0; i--) 
	{
		hash += (HASH1 * hash + (int)x[i]) % size;
	}
	return hash % size;
}

int hash2(std::string& x, int size) // хеш-функция 2
{
	int hash = 0;
	for (int i = x.size(); i >= 0; i--) 
	{
		hash += (HASH2 * hash + (int)x[i]) % size;
	}
	return (hash * 2 + 1) % size;
}

template<class T>
class MyMap
{
    public:
        MyMap(): map(8, ""),  capacity(8), size(0){}
        bool Add(T& x)
        {
            if ((float) size / (float) capacity >= REHASH)
                rehash();
            int hash11 = hash1(x, capacity);
            int hash22 = hash2(x, capacity);

            int i = 0;
            int deletedNodeIndex = -1;
            while (map[hash11] != "" && i < capacity) 
            {
                if (map[hash11] == x && map[hash11] != deleted) 
                    return false;
                
                if (map[hash11] == deleted && deletedNodeIndex < 0)
                    deletedNodeIndex = hash11;
                
                hash11 = (hash11 + hash22) % capacity;
                ++i;
            }

            if (deletedNodeIndex >= 0) 
            {
                map[deletedNodeIndex] = x;
            } 
            else 
                map[hash11] = x;

            size++;
            return true;
        }
        bool Remove(T& x) 
        {
            int hash11 = hash1(x, capacity);
            int hash22 = hash2(x, capacity);

            int i = 0;
            while (map[hash11] != "" && i < capacity) 
            {
                if (map[hash11] == x && map[hash11] != deleted)
                {
                    map[hash11] = deleted;
                    size--;
                    return true;
                }
                hash11 = (hash11 + hash22) % capacity;
                ++i;
            }
            return false;
        }
        void rehash() 
        {
            int newSize = capacity * 2;
            std::vector<T> newMap(newSize, "");
            for (int i = 0; i < capacity; ++i)
            {
                if (map[i] != "" && map[i] != deleted) 
                {
                    T data = map[i];
                    int Hcur = hash1(data, newSize);
                    int Hanother = hash2(data, newSize);
                    int j = 0;

                    while (newMap[Hcur] != "" && j < newSize) 
                    {
                        Hcur = (Hcur + Hanother) % newSize;
                        ++j;
                    }
                    newMap[Hcur] = data;
                }
            }

            map = newMap;
            capacity = newSize;
        }
        bool Has(T& x) {
            int hash11 = hash1(x, capacity);
            int hash22 = hash2(x, capacity);
            int i = 0;

            while (map[hash11] != "" && i < capacity)
            {
                if (map[hash11] == x && map[hash11] != deleted) 
                {
                    return true;
                }
                hash11 = (hash11 + hash22) % capacity;
                i++;
            }
            return false;
        }
    private:
	    std::vector<T> map; 
	    int capacity; 
	    int size;
};
int main() 
{
    char c;
    std::string str;

    MyMap<std::string> table;

    while (std::cin >> c >> str) {
        bool result;

        switch (c) {
        case '+':
            result = table.Add(str);
            break;
        case '-':
            result = table.Remove(str);
            break;
        case '?':
            result = table.Has(str);
            break;
        default:
            result = false;
        }

        std::cout << ((result) ? "OK" : "FAIL") << "\n";
    }

    return 0;
}