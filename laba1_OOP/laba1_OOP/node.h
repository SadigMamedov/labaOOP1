#pragma once
#include <iostream>
#include <initializer_list>
#include <stdio.h>
#include <string.h>
#include <math.h>

template<typename T>
class Node
{
public:
    T field;
    Node* next;
    Node* prev;
    Node(T elem)
    {
        field = elem;
        next = prev = NULL;
    }
};