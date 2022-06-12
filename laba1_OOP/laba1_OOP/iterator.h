#include "node.h"

template<typename T>
class Iterator
{
public:
    Iterator(Node<T>* lst);
    Iterator<T> next();
    T value();
    bool is_end();
    Iterator<T>& operator++();
    T& operator*();
    bool operator==(Iterator& b);
    bool operator!=(Iterator& b);
private:
    Node<T>* iterator;
};

template<typename T>
Iterator<T>::Iterator(Node<T>* lst)
{
    if (lst == NULL)
        throw "The list is empty";

    iterator = lst;
}

template<typename T>
Iterator<T> Iterator<T>::next()
{
    if (this->iterator->next == NULL)
        throw "The next element does not exist";
    else
        this->iterator = this->iterator->next;

    return *this;
}

template<typename T>
T Iterator<T>::value()
{
    T elem = NULL;
    if (this->iterator == NULL)
        throw "The list is empty";
    elem = this->iterator->field;

    return elem;
}

template<typename T>
bool Iterator<T>::is_end()
{
    return this->iterator ? 0 : 1;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    this->next();

    return *this;
}

template<typename T>
T& Iterator<T>::operator*()
{
    T elem = this->value();

    return elem;
}

template<typename T>
bool Iterator<T>::operator==(Iterator& b)
{
    return this->iterator == b.iterator;
}

template<typename T>
bool Iterator<T>::operator!=(Iterator& b)
{
    return !(this->iterator == b.iterator);
}

