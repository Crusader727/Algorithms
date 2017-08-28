#include <iostream>
#include <queue>
#include <stack>


template <class node>
int GetMaxW(node* root)
{
    if (root == NULL)
        return 0;

    std::queue<node*> Que;
    Que.push(root);
    int res = 0;
    int curCount = 0;
    node* BufNode = NULL;

    while (!Que.empty())
    {
        curCount = Que.size();
        res = std::max(curCount, res);
        for(int i = 0; i < curCount; i++)
        {
            BufNode = Que.front();
            Que.pop();
            if (BufNode->left != NULL)
                Que.push(BufNode->left);
            if (BufNode->right != NULL)
                Que.push(BufNode->right);
        }
    }
    return res;
}


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
};

template<class T>
class MyTree
{
    public:
        MyTree(): root(NULL){}
        int GetMaxWidth()
        {
            return GetMaxW< Node<T> >(root);
        }
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
        
        std::queue<T>* In_O1rder()
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

template <class T>
class NodeD
{
    public:
        T x;
        int y;
        NodeD* left;
        NodeD* right;
        NodeD(): left(NULL) , right(NULL){}
        NodeD(T dt, int dt2): left(NULL) , right(NULL), x(dt), y(dt2){}
        ~NodeD()
        {
            if(left != NULL)
                delete left;
            if(right != NULL)
                delete right;
        }
};

template <class T>
class MyTreeD
{
    public:
        MyTreeD(): root(NULL){}
        void Insert(T data, int priority)
        {
            NodeD<T>* newNode = new NodeD<T>(data, priority);
            add(root, newNode);
        }
        int GetMaxWidth()
        {
            return GetMaxW< NodeD<T> >(root);
        }
        ~MyTreeD()
        {
            delete root;
        }
    private:
        void add(NodeD<T>*& curNode, NodeD<T>* newNode) 
        {
	        if (curNode == NULL)
		        curNode = newNode;
	        else if (newNode->y > curNode->y)
            {
		        Split (curNode, newNode->x, newNode->left, newNode->right);
                curNode = newNode;
            }
	        else
            {
                if(newNode->x < curNode->x)
                {
                    add(curNode->left, newNode);
                }
                else
                {
                    add(curNode->right, newNode);
                }
            }
        }
        void Split(NodeD<T>* CurNode, T key, NodeD<T>*& left, NodeD<T>*& right)
        {
            if(CurNode == NULL)
            {
                left = NULL;
                right = NULL;
            }
            else if(key < CurNode->x)
            {
                Split(CurNode->left, key, left, CurNode->left);
                right = CurNode;
            }
            else
            {

                Split(CurNode->right, key, CurNode->right, right);
                left = CurNode;
            }
        }
        NodeD<T>* root;
};



int main()
{
    MyTree<int> tree;
    MyTreeD<int> Dtree;
    int count = 0;
    int data;
    int prior;
    std::cin >> count;
    for(int i  = 0; i < count ; i++)
    {
        std::cin >> data >> prior;
        tree.Insert(data);
        Dtree.Insert(data, prior);
    }
    std::cout << Dtree.GetMaxWidth() - tree.GetMaxWidth() ;
    return 0;
}