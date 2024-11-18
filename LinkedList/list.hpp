#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>


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
        size_t length(void);
        T pop(void);
        T pop(size_t pos);
        T pop_back(void);
        void push(const T& data);
        void push_back(const T& data);
        void reverse(void);

        ~List();
};


#endif