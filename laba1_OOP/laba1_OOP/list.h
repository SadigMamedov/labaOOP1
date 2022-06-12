#include "iterator.h"

template<typename T>
class List
{
public:
    friend class Node<T>;
    friend class Iterator<T>;
    List();
    List(List<T>& lst);
    explicit List(std::initializer_list<T> lst);
    ~List();
    List<T>& operator=(const List<T>& lst);
    int get_length();
    void add(T& elem);
    void add_range(List<T>& lst);
    void add_range(T* arr, int size);
    void set_elem(int index, T& elem);
    T& get_elem(int index);
    void remove_elem(int index);
    List<T> combine(List<T>& lst);
    void sort(int (*comp)(T& r1, T& r2));
    int get_index(T& elem);
    T* to_array();
    T& operator[](int index);
    template<typename _T> friend List<_T> operator+(List<_T>& l1, List<_T>& l2);
    List<T>& operator+=(List<T>& lst);
    template<typename _T> friend std::ostream& operator<<(std::ostream& os, List<_T>& lst);
    Iterator<T> iterator_begin();
    Iterator<T> iterator_end();
    void clear();
private:
    Node<T>* head;
    Node<T>* tail;
    int quantity;
};

template<typename T>
int comp(T& r1, T& r2);
template<typename T>
void swap_elem(T* r1, T* r2);

template<typename T>
List<T>::List()  //конструктор
{
    head = tail = NULL;
    quantity = 0;
}

template<typename T>
List<T>::List(List<T>& lst) //конструктор копирования
{
    if (lst.head == NULL) {
        throw "The list is empty";
    }
    else {
        Node<T>* ptr1 = lst.head;
        this->head = this->tail = new Node<T>(ptr1->field);
        ptr1 = ptr1->next;
        while (ptr1 != NULL) {
            this->add(ptr1->field);
            ptr1 = ptr1->next;
        }
        this->quantity = lst.quantity;
    }
}

template<typename T>
List<T>::List(std::initializer_list<T> lst) //конструктор со списком инициализации
{
    int count = 0;
    Node<T>* ptr = this->head = NULL;
    if (lst.size() == 0) {
        throw "The list is empty";
    }
    else {
        for (auto element : lst) {
            if (count++ == 0) {
                this->head = this->tail = new Node<T>(element);
                ptr = this->head;
            }
            else {
                this->add(element);
                ptr = ptr->next;
            }
        }
        this->quantity = (int)lst.size();
    }
}

template<typename T>
List<T>::~List() //деструктор
{
    clear();
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& lst) //перегрузка оператора =
{
    if (lst.head == NULL) {
        throw "The list is empty";
    }

    this->clear();
    Node<T>* ptr1 = lst.head;
    this->head = this->tail = new Node<T>(ptr1->field);
    Node<T>* ptr = this->head;
    ptr1 = ptr1->next;
    while (ptr1 != NULL) {
        Node<T>* tmp = new Node<T>(ptr1->field);
        ptr->next = tmp;
        this->tail = tmp;
        tmp->prev = ptr;
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    this->quantity = lst.quantity;

    return *this;
}

template<typename T>
int List<T>::get_length() //возвращает длину списка
{
    return this->quantity;
}

template<typename T>
void List<T>::add(T& elem) //фция добавляет элемент в конец
{
    if (this->head == NULL) {
        this->head = this->tail = new Node<T>(elem);
    }
    else {
        Node<T>* ptr = this->tail;
        Node<T>* newNode = new Node<T>(elem);
        this->tail = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    this->quantity++;
}

template<typename T>
void List<T>::add_range(List<T>& lst) //добавляетт список элементов в конец
{
    if (lst.head == NULL) {
        throw "The list is empty";
    }
    else if (this->head == NULL) {
        List<T> tmp(lst);
        *this = tmp;
    }
    else {
        Node<T>* ptr1 = lst.head;
        while (ptr1 != NULL) {
            this->add(ptr1->field);
            ptr1 = ptr1->next;
        }
    }
}

template<typename T>
void List<T>::add_range(T* arr, int size) //добавляетт массив элементов в конец
{
    if (arr == NULL || size == 0) {
        throw "The array is empty";
    }
    else {
        for (int i = 0; i < size; i++)
            this->add(arr[i]);
    }
}

template<typename T>
void List<T>::set_elem(int index, T& elem) //изменить элем по индексу
{
    if (this->head == NULL) {
        throw "The list is empty";
    }
    else if (index >= this->quantity || index < 0) {
        throw "Going off the list";
    }
    else {
        int tmp = 0;
        Node<T>* ptr = this->head;
        do {
            if (tmp++ == index) {
                ptr->field = elem;
                break;
            }
            ptr = ptr->next;
        } while (ptr != NULL);
    }
}

template<typename T>
T& List<T>::get_elem(int index) //получить элем по номеру
{
    T elem;
    if (this->head == NULL) {
        throw "The list is empty";
    }
    else if (index >= this->quantity || index < 0) {
        throw "Going off the list";
    }
    else {
        int tmp = 0;
        Node<T>* ptr = this->head;
        do {
            if (tmp++ == index)
                elem = ptr->field;
            ptr = ptr->next;
        } while (ptr != NULL);
    }

    return elem;
}

template<typename T>
void List<T>::remove_elem(int index) //удалить элем по номеру
{
    if (this->head == NULL) {
        throw "The list is empty";
    }
    else if (index >= this->quantity || index < 0) {
        throw "Going off the list";
    }
    else {
        int tmp = 0;
        Node<T>* ptr = this->head;
        do {
            if (tmp++ == index) {
                if (ptr->prev == NULL) {
                    Node<T>* tmpptr1 = ptr->next;
                    tmpptr1->prev = NULL;
                    this->head = tmpptr1;
                    delete ptr;
                    break;
                }
                else if (ptr->next == NULL) {
                    Node<T>* tmpptr1 = ptr->prev;
                    tmpptr1->next = NULL;
                    this->tail = tmpptr1;
                    delete ptr;
                    break;
                }
                else {
                    Node<T>* tmpptr1 = ptr->next;
                    Node<T>* tmpptr2 = ptr->prev;
                    tmpptr1->prev = tmpptr2;
                    tmpptr2->next = tmpptr1;
                    delete ptr;
                    break;
                }
            }
            ptr = ptr->next;
        } while (ptr != NULL);
        this->quantity--;
    }
}

template<typename T>
List<T> List<T>::combine(List<T>& lst) //объединяет два списка
{
    List<T> newlist;
    if (this->head == NULL || lst.head == NULL) {
        throw "The list is empty";
    }
    else {
        newlist.add_range(*this);
        newlist.add_range(lst);
    }

    return newlist;
}

template<typename T>
void List<T>::sort(int (*comp)(T& r1, T& r2)) //сортирует по компаратору
{
    if (this->head == NULL) {
        throw "The list is empty";
    }
    else {
        for (Node<T>* ptr = this->head; ptr != this->tail;) {
            for (Node<T>* ptr1 = ptr->next; ptr1 != NULL;) {
                if (comp(ptr->field, ptr1->field)) {
                    swap_elem(&ptr->field, &ptr1->field);
                }
                ptr1 = ptr1->next;
            }
            ptr = ptr->next;
        }
    }
}

template<typename T>
int comp(T& r1, T& r2)
{
    return (r1 > r2) ? 1 : 0;
}

template<typename T>
void swap_elem(T* r1, T* r2)
{
    T tmp = *r1;
    *r1 = *r2;
    *r2 = tmp;
}

template<typename T>
int List<T>::get_index(T& elem)
{
    int count = -1, flag = 0;
    if (this->head == NULL) {
        throw "The list is empty";
    }
    else {
        count = 0;
        Node<T>* ptr = this->head;
        do {
            if (ptr->field == elem) {
                flag = 1;
                break;
            }
            count++;
            ptr = ptr->next;
        } while (ptr != NULL);
        if (flag == 0)
            count = -1;
    }

    return count;
}

template<typename T>
T* List<T>::to_array()
{
    T* mas = new T[this->quantity];
    if (this->head == NULL) {
        throw "The list is empty";
    }
    else {
        Node<T>* ptr = this->head;
        for (int i = 0; i < this->quantity; i++) {
            mas[i] = ptr->field;
            ptr = ptr->next;
        }
    }

    return mas;
}

template<typename T>
T& List<T>::operator[](int index)
{
    return this->get_elem(index);
}

template<typename _T>
List<_T> operator+(List<_T>& l1, List<_T>& l2)
{
    List<_T> list;
    list = l1.combine(l2);
    return list;
}

template<typename T>
List<T>& List<T>::operator+=(List<T>& lst)
{
    if (lst.head == NULL)
        throw "The list is empty";
    else
        this->add_range(lst);

    return *this;
}

template<typename _T>
std::ostream& operator<<(std::ostream& os, List<_T>& lst)
{
    if (lst.head == NULL) {
        throw "The list is empty";
    }
    else {
        Node<_T>* ptr = lst.head;
        do {
            os << ptr->field << " ";
            ptr = ptr->next;
        } while (ptr != NULL);
    }

    return os;
}

template<typename T>
Iterator<T> List<T>::iterator_begin()
{
    Iterator<T>* newiterator = new Iterator<T>(this->head);

    return *newiterator;
}

template<typename T>
Iterator<T> List<T>::iterator_end()
{
    Iterator<T>* newiterator = new Iterator<T>(this->tail);

    return *newiterator;
}

template<typename T>
void List<T>::clear()
{
    Node<T>* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    quantity = 0;
}

