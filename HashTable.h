#pragma once
#include <iostream>


class HashTable
{
    struct Node
    {
        Node(int key, int value) : key_(key), value_(value), next(nullptr) {}

        int key_;
        int value_;
        Node* next;
    };


public:

    HashTable(int size) : size_(size) 
    {
        table_ = new Node*[size_];
        for (int i = 0; i < size_; ++i)
        {
            table_[i] = nullptr;
        }
    }
    
    ~HashTable()
    {
        for (int i = 0; i < size_; ++i)
        {
            Node* temp = table_[i];
            Node* prev;

            while (temp)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
            }
        }

        delete table_;
    }


    void insert(int key, int value);
    void print();

       
private:

    int hash(int key);
    // for resize if the size is powers of 2 then the index is
    // key & size-1 which is the same as a mod hash function
    int size_;
    Node** table_;

};
