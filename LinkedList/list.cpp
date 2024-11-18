#include "list.hpp"


template<typename T>
void List<T>::clear(void)
{
    Node *curr = this->head;
    while(curr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    this->head = nullptr;
    this->_length = 0;
}


template <typename T>
int List<T>::find(const T& key)
{
    int i = 0;
    for(Node *curr = this->head; curr != nullptr; curr = curr->next)
    {
        if(curr->data == key)
            return i;
        i++;
    }
    return -1;
}


template <typename T>
T List<T>::get(size_t pos)
{
    if(pos >= this->_length || pos < 0)
        throw std::out_of_range("List index out of range");
    
    Node *curr = this->head;
    for(size_t i = 0; i < pos; i++)
        curr = curr->next;
    return curr->data;
}


template<typename T>
size_t List<T>::length(void)
{
    return this->_length;
}


template<typename T>
T List<T>::pop(void)
{
    if(!this->head)
        throw std::underflow_error("List is empty");

    T data = this->head->data;
    Node *next = this->head->next;
    delete this->head;
    this->head = next;
    this->_length--;
    return data;
}


template<typename T>
T List<T>::pop(size_t pos)
{
    if(pos >= this->_length || pos < 0)
        throw std::out_of_range("List index out of range");

    if(pos == 0)
        return this->pop();

    Node *curr = this->head, *prev = nullptr;
    for(size_t i = 0; i < pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    T data = curr->data;
    delete curr;
    this->_length--;
    return data;
}


template<typename T>
T List<T>::pop_back(void)
{
    return this->pop(this->_length - 1);
}


template<typename T>
void List<T>::push(const T& data)
{
    Node *tmp = new Node(data);
    tmp->next = this->head;
    this->head = tmp;
    this->_length++;
}


template<typename T>
void List<T>::push_back(const T& data)
{
    if(!this->head)
        return this->push(data);

    Node *curr = this->head;
    while(curr->next)
        curr = curr->next;
    curr->next = new Node(data);
    this->_length++;
}


template<typename T>
void List<T>::reverse(void)
{
    Node *prev = nullptr, *curr = this->head;
    while(curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    this->head = prev;
}


template<typename T>
List<T>::~List(void)
{
    this->clear();
}