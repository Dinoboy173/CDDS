#include <stdlib.h>
#include <time.h>

template<class T>
class LinkedList
{
public:
    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    struct Iterator
    {
        Node* node = nullptr;

        // Constructors
        Iterator() : node(nullptr) {}
        Iterator(Node* node) : node(node) {}

        // Increment operators
        Iterator& operator ++ () { return Next(); }
        Iterator operator ++ (int) { return Next(); }

        // Decrement operators
        Iterator operator -- () { return Prev(); }
        Iterator operator -- (int) { return Prev(); }

        // Equality check operators
        bool operator == (const Iterator& rhs) { return node == rhs.node; }
        bool operator != (const Iterator& rhs) { return node != rhs.node; }

        // Dereference operators
        T& operator * () { return node->value; }
        T* operator -> () { return &node->value; }

        // Move to the next value
        Iterator& Next()
        {
            if (node != nullptr)
                node = node->next;

            return *this;
        }

        // Move to the previous value
        Iterator& Prev()
        {
            if (node != nullptr)
                node = node->prev;

            return *this;
        }
    };

    LinkedList()
    {
    }

    ~LinkedList()
    {
    }

    LinkedList(std::initializer_list<T> list)
    {
        for (auto iter = list.begin(); iter != list.end(); iter++)
            PushBack(*iter);
    }

    void PushBack(T value)
    {
        if (m_first == nullptr && m_last == nullptr)
        {
            CreateFirst(value);
        }
        else
        {
            Node* n = new Node();

            n->value = value;
            n->next = nullptr;
            n->prev = nullptr;

            n->prev = m_last;
            m_last->next = n;
            m_last = n;

            m_count++;
        }
    }

    void PopBack()
    {
        if (m_first == m_last)
        {
            RemoveWhenOne();
        }
        else if (m_first != nullptr && m_last != nullptr)
        {
            m_last = m_last->prev;

            delete m_last->next;
            m_last->next = nullptr;

            m_count--;
        }
    }
    void PushFront(T value)
    {
        if (m_first == nullptr && m_last == nullptr)
        {
            CreateFirst(value);
        }
        else
        {
            Node* n = new Node();

            n->value = value;
            n->next = nullptr;
            n->prev = nullptr;


            n->next = m_first;
            m_first->prev = n;
            m_first = n;

            m_count++;
        }
    }

    void PopFront()
    {
        if (m_first == m_last)
        {
            RemoveWhenOne();
        }
        else if (m_first != nullptr && m_last != nullptr)
        {
            m_first = m_first->next;

            delete m_first->prev;
            m_first->prev = nullptr;

            m_count--;
        }
    }

    void Sort()
    {
        bool isSorted = false;

        while (!isSorted)
        {
            Node* nodeToMove = new Node();

            nodeToMove->value = 0;
            nodeToMove->next = nullptr;
            nodeToMove->prev = nullptr;

            bool nodeSelected = false;
            int sortCount = m_count;
            int stop;

            srand(time(NULL));

            while (sortCount != 0)
            {
                while (!nodeSelected)
                {
                    for (auto iter = begin(); iter != end();)
                    {
                        stop = rand() % m_count + 1;

                        if (stop <= 1)
                        {
                            nodeToMove = iter.node;
                            nodeSelected = true;
                            break;
                        }
                        else
                            iter++;
                    }
                }

                while (nodeSelected)
                {
                    for (auto iter = begin(); iter != end();)
                    {
                        stop = rand() % m_count + 1;

                        if (stop <= 1)
                        {
                            if (iter == FirstNode())
                                PushFront(nodeToMove->value);
                            else if (iter == LastNode())
                                PushBack(nodeToMove->value);
                            else
                                Insert(iter, nodeToMove->value);

                            if (nodeToMove == FirstNode())
                                PopFront();
                            else if (nodeToMove == LastNode())
                                PopBack();
                            else
                                iter = Remove(nodeToMove);

                            sortCount--;
                            nodeSelected = false;
                            break;
                        }
                        else
                            iter++;
                    }
                }
            }

            for (auto iter = Iterator(FirstNode()->next); iter != end(); iter++)
            {
                if (iter.node->prev->value > iter.node->value)
                {
                    break;
                }

                if (iter == Iterator(LastNode()))
                    isSorted = true;
            }
        }
    }

    void Clear()
    {
        bool isOneLeft = false;

        while (!isOneLeft)
        {
            if (m_first == m_last)
            {
                isOneLeft = true;
            }

            PopBack();
        }
    }

    Iterator Remove(Iterator iter)
    {
        Node* nodeToRemove = iter.node;

        if (nodeToRemove == m_first)
            m_first = m_first->next;
        else if (nodeToRemove == m_last)
            m_last = m_last->prev;

        if (nodeToRemove->prev != nullptr)
            nodeToRemove->prev->next = nodeToRemove->next;

        if (nodeToRemove->next != nullptr)
            nodeToRemove->next->prev = nodeToRemove->prev;

        Node* nextNode = nodeToRemove->next;

        nodeToRemove->next = nullptr;
        nodeToRemove->prev = nullptr;
        delete nodeToRemove;

        m_count--;

        return Iterator(nextNode);
    }

    Iterator Insert(Iterator iter, const T& value)
    {
        Node* currentNode = iter.node;

        Node* newNode = new Node();
        newNode->value = value;

        currentNode->next->prev = newNode;
        newNode->next = currentNode->next;

        currentNode->next = newNode;
        newNode->prev = currentNode;

        m_count++;

        return Iterator(newNode);
    }

    bool IsEmpty()
    {
        if (m_first == nullptr && m_last == nullptr)
            return true;
        else
            return false;
    }

    unsigned int Count()
    {
        return m_count;
    }

    void CreateFirst(T value)
    {
        Node* n = new Node();

        n->value = value;
        n->next = nullptr;
        n->prev = nullptr;

        m_first = n;
        m_last = n;

        m_count++;
    }

    void RemoveWhenOne()
    {
        delete m_first;
        m_first = nullptr;
        m_last = nullptr;

        m_count--;
    }

    Node* FirstNode()
    {
        return m_first;
    }

    Node* LastNode()
    {
        return m_last;
    }

    Iterator begin()
    {
        return Iterator(m_first);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }

protected:
private:
    Node* m_first = nullptr;
    Node* m_last = nullptr;

    unsigned int m_count = 0;
};