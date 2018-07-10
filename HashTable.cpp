#include "HashTable.h"
#include <iostream>

void HashTable::insert(int key, int value)
{
    int index = hash(key);
    Node** temp = &table_[index];
    Node** prev = temp;

    while (*temp && (*temp)->key_ != key)
    {
        prev = temp;
        temp = &((*temp)->next);
    }

    if (*temp && (*temp)->key_ == key)
    {
        (*temp)->value_ = value;
        return;
    }

    Node* insertNode = new Node(key, value);
    *temp = insertNode;

}

void HashTable::print()
{

    for (int i = 0; i < size_; ++i)
    {
        if (table_[i])
        {
            Node* temp = table_[i];
            std::cout << "Head -> ";

            while (temp)
            {
                std::cout << temp->key_ << "," << temp->value_ << ", next -> ";
                temp = temp->next;
            }

        }

        std::cout << "Null" << std::endl;
    }


}

int HashTable::hash(int key)
{
    return key % size_;
}


