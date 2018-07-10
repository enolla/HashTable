#include <Windows.h>
#include "HashTable.h"
#include <iostream>

int main()
{
    HashTable myTable(10);
    myTable.insert(2, 6);
    myTable.insert(22,7);
    myTable.insert(42, 6);

    myTable.print();
    std::cout << "After adding (22,8)" << std::endl;
    
    myTable.insert(22, 8);
    myTable.print();

    system("pause");
    return 0;

}
