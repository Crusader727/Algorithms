#include <iostream>
#include <queue>
#include <stack>

template<class T>
class Node
{
    public:
        T data;
        Node* parent;
        Node* left;
        Node* right;
        Node(): parent(NULL), left(NULL) , right(NULL){}
        Node(T dt):parent(NULL), left(NULL) , right(NULL), data(dt){}
       /* ~Node()
        {
            if(left != NULL)
                delete left;
            if(right != NULL)
                delete right;
        }*/
};

template<class T>
class MyTree
{
    public:
        MyTree(): root(NULL){}
        void Insert(T data)
        {
            Node<T>* buf = root;
            while(buf != NULL)
            {
                if(data < buf->data)
                {
                    if(buf->left == NULL)
                    {
                        buf->left = new Node<T>(data);
                        buf->left->parent = buf;
                        return;
                    }
                    buf = buf->left;
                }
                else
                {
                    if(buf->right == NULL)
                    {
                        buf->right = new Node<T>(data);
                        buf->right->parent = buf;
                        return;
                    }
                    buf = buf->right;
                }
            }
            root = new Node<T>(data);
        }
        
        std::queue<T>* In_Order()
        {
            std::queue<T>* list = new std::queue<T>;
            Node<T>* node = root;
            Node<T>* lastNode = NULL;
            while (node != NULL)
            {
                if (lastNode == node->parent)
                {
                    if (node->left != NULL)
                    {
                        lastNode = node;
                        node = node->left;
                        continue;
                    }
                    else
                        lastNode = NULL;
                }
                if (lastNode == node->left)
                {
                   //std::cout << node->data << std::endl;// Output(node);
                   list->push(node->data);

                    if (node->right != NULL)
                    {
                        lastNode = node;
                        node = node->right;
                        continue;
                    }
                    else
                        lastNode = NULL;
                }
                if (lastNode == node->right)
                {
                    lastNode = node;
                    node = node->parent;
                }
            }
            return list;
        }
        ~MyTree()
        {
            /*if(root != NULL)
                delete root;*/
            std::stack<Node<T>*> ps;
            Node<T>* lnp = NULL;
            Node<T>* peekn = NULL;
            Node<T>* buff = root;

            while (ps.size() != 0 || buff != NULL) 
            {
                if (buff) 
                {
                    ps.push(buff);
                    buff = buff->left;
                } 
                else 
                {
                    peekn = ps.top();
                    if (peekn->right && lnp != peekn->right) 
                    {
                        buff = peekn->right;
                    } 
                    else 
                    {
                        ps.pop();
                        delete peekn;
                        lnp = peekn;
                    }
                }
            }
        
        }

    private:
        Node<T>* root;
};

int main()
{
    MyTree<int> tree;
    int count = 0;
    int data;
    std::cin >> count;
    for(int i  = 0; i < count ; i++)
    {
        std::cin >> data;
        tree.Insert(data);
    }
    std::queue<int>* list = tree.In_Order();
    int size = list->size();
    for(int i = 0; i < size; i++)
    {
        std::cout << list->front() << std::endl;
        list->pop();
    }
    delete list;
    return 0;
}