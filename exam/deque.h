#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include <cassert>
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& d): data(d), next(NULL) {}
};

template <typename T>
class Deque
{
    Node<T>* front;
    Node<T>* rear;

public:
    Deque():front(NULL), rear(NULL){}
    Deque(const Deque& other)
    {
        copy(other);
    }
    ~Deque()
    {
        destroy();
    }
    Deque<T>& operator =(const Deque& other);

    bool isEmpty() const
    {
        return front == NULL;
    }

    void pushBack(const T& element);
    void pushFront(const T& element);
    void popBack(T& element);
    void popFront(T& element);

    T& getFront() const
    {
        return front->data;
    }
    T& getBack() const
    {
        return rear->data;
    }

    std::ostream& print(std::ostream& out) const;
    size_t size() const;

    bool operator < (const Deque<T>& other)
    {
        return size() < other.size();
    }
private:
    void copy(const Deque& other);
    void destroy();
};

template <typename T>
void Deque<T>::copy(const Deque& other)
{
    if (other.front != NULL)
    {
        front = new Node<T>(other.front->data);
        Node<T>* p = other.front->next;
        Node<T>* q = front;
        while (p != NULL)
        {
            Node<T>* newBox = new Node<T>(p->data);
            p = p->next;
            q->next = newBox;
            q = newBox;
        }
        rear = q;
        q = NULL;
    }
    else
    {
        front = rear = NULL;
    }
}

template <typename T>
void Deque<T>::destroy()
{
    if (!isEmpty())
    {
        Node<T>* p;
        while (front != NULL)
        {
            p = front;
            front = front->next;
            delete p;
        }
        rear = NULL;
    }
}

template <typename T>
Deque<T>& Deque<T>::operator =(const Deque& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template <typename T>
void Deque<T>::pushBack(const T& element)
{
    if (isEmpty())
    {
        front = new Node<T>(element);
        rear = front;
        return;
    }
    Node<T>* p = rear;
    rear = new Node<T>(element);
    p->next = rear;
    p = NULL;
}

template <typename T>
void Deque<T>::pushFront(const T& element)
{
    Node<T>* p = new Node<T>(element);
    p->next = front;
    front = p;
    if (front->next == NULL)
    {
        rear = front;
    }
    p = NULL;
}


template <typename T>
void Deque<T>::popBack(T& element)
{
    if (isEmpty())
    {
        return;
    }

    element = rear->data;

    if (front == rear) //only 1 element
    {
        delete front;
        front = rear = NULL;
        return;
    }

    Node<T>* p = front;
    while (p->next != rear)
    {
        p = p->next;
    }
    //now p points at the element right before the last one

    delete rear;
    rear = p;
    rear->next = NULL;
}

template <typename T>
void Deque<T>::popFront(T& element)
{
    if (isEmpty())
    {
        return;
    }

    element = front->data;

    if (front == rear) //only 1 element
    {
        delete front;
        front = rear = NULL;
        return;
    }

    Node<T>* p = front;
    front = front->next;
    delete p;
}

template <typename T>
std::ostream& Deque<T>::print(std::ostream& out) const
{
    if (isEmpty())
    {
        out << "The list is isEmpty!";
        return out;
    }
    Node<T>* p = front;
    while (p != NULL)
    {
        out << p->data << " ";
        p = p->next;
    }
    return out;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const Deque<T>& list)
{
    return list.print(out);
}

template <typename T>
size_t Deque<T>::size() const
{
    if (isEmpty())
    {
        return 0;
    }
    size_t count = 0;
    Node<T>* p = front;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}


#endif // DEQUE_H_INCLUDED
