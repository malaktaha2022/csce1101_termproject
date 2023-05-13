
#ifndef DEQ_hpp
#define DEQ_hpp

#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T>* next;
    
    node(T& value)
    {
        data = value;
        next = nullptr;
    }
};

template <class T>
class DEQ
{
private:
    node<T>* front;
    node<T>* rear;
    int length;
    
public:
    DEQ()
    {
        front = nullptr;
        rear = nullptr;
        length = 0;
    }
    ~DEQ()
    {
        node<T>* temp;
        while (front != nullptr)
            {
                temp = front;
                front = front->next;
                delete temp;
            }
        rear = nullptr;
        length = 0;
    }
    bool DEQisEmpty()
    {
        return (length == 0);
    }
    void Add_Front(T value)
    {
        node<T>* pnew = new node<T>(value);
        if (DEQisEmpty())
        {
            front = pnew;
            rear = pnew;
        }
        else
        {
            pnew->next = front;
            front = pnew;
        }
        length++;
    }
    void Add_Rear(T value)
    {
        node<T>* pnew = new node<T>(value);
        if (DEQisEmpty())
        {
            front = pnew;
            rear = pnew;
        }
        else
        {
            rear->next = pnew;
            front = pnew;
        }
        length++;
    }
    void Remove_Front()
    {
        node<T>* temp = front;
        if (DEQisEmpty())
        {
            cout << "the double-ended queue is empty!" << endl;
            exit(1);
        }
        front = front->next;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        length--;
    }
    void Remove_Rear()
    {
        if (DEQisEmpty())
        {
            cout << "the double-ended queue is empty!" << endl;
            exit(1);
        }
        if (front == rear)
        {
            delete front;
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            node<T>* temp = front;
            while (temp->next != rear)
            {
                temp = temp->next;
            }
            delete rear;
            rear = temp;
            rear->next = nullptr;
        }
        length--;
    }
    T View_Front()
    {
        if (DEQisEmpty())
        {
            cout << "double-ended queue is empty!" << endl;
            exit(1);
        }
        return front->data;
    }
    T View_Rear()
    {
        if (DEQisEmpty())
        {
            cout << "double-ended queue is empty!" << endl;
            exit(1);
        }
        return rear->data;
    }
    int DEQ_Length()
    {
        return length;
    }
  
};
#endif /* DEQ_hpp */
