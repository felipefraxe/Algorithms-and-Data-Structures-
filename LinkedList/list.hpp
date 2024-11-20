#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <iostream>

template<typename T>
class List
{
    private:
        struct Node
        {
            T data;
            Node *next;

            Node(const T& data) : data(data), next(nullptr) {}
        };
        Node *head;
        size_t _length;

    public:
        List() : head(nullptr), _length(0) {}

        void clear(void);
        int find(const T& data);
        T get(size_t pos);
        void insert(size_t pos, const T& data);
        size_t length(void);
        T pop(void);
        T pop_back(void);
        void print(void);
        void push(const T& data);
        void push_back(const T& data);
        T remove(size_t pos);
        void reverse(void);

        ~List();
};

template<typename T>
void List<T>::clear(void)
{
    while (this->_length > 0)
        this->pop();
}

template <typename T>
int List<T>::find(const T& key)
{
    int i = 0;
    for (Node *curr = this->head; curr != nullptr; curr = curr->next)
    {
        if (curr->data == key)
            return i;
        i++;
    }
    return -1;
}

template <typename T>
T List<T>::get(size_t pos)
{
    if (pos >= this->_length)
        throw std::out_of_range("List index out of range");
    
    Node *curr = this->head;
    for (size_t i = 0; i < pos; i++)
        curr = curr->next;
    return curr->data;
}

template <typename T>
void List<T>::insert(size_t pos, const T& data)
{
    if (pos > this->_length)
        throw std::out_of_range("List index out of range");

    if (pos == 0)
    {
        this->push(data);
        return;
    }

    Node *node = new Node(data);
    Node *curr = this->head, *prev = nullptr;
    for (size_t i = 0; i < pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = node;
    node->next = curr;

    this->_length++;
}

template<typename T>
size_t List<T>::length(void)
{
    return this->_length;
}

template<typename T>
T List<T>::pop(void)
{
    if (this->head == nullptr)
        throw std::underflow_error("List is empty");

    T data = this->head->data;
    Node *next = this->head->next;

    delete this->head;

    this->head = next;
    this->_length--;

    return data;
}

template<typename T>
T List<T>::remove(size_t pos)
{
    if (pos >= this->_length)
        throw std::out_of_range("List index out of range");

    if (pos == 0)
        return this->pop();

    Node *curr = this->head, *prev = nullptr;
    for (size_t i = 0; i < pos; i++)
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
    return this->remove(this->_length - 1);
}

template <typename T>
void List<T>::print(void)
{
    std::cout << "[";
    for (Node* curr = this->head; curr != nullptr; curr = curr->next)
    {
        std::cout << curr->data;
        if (curr->next)
            std::cout << " -> ";
    }
    std::cout << "]" << std::endl;
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
    if (this->head == nullptr)
        return this->push(data);

    Node *curr = this->head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = new Node(data);

    this->_length++;
}

template<typename T>
void List<T>::reverse(void)
{
    Node *prev = nullptr, *curr = this->head;
    while (curr != nullptr)
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

#endif
