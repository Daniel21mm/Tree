#include <iostream>
#include "mtree.h"

int main()
{
    std::cout<<"создаем дерево 1, добавляем элементы 5 7 9 3 6 1 4 8 и отображаем на экран.\n";
    std::cout  << "колличестов __ определят глубину. правые элементы выше, левые ниже\n";


    Tree<int> t;
    t.push(5);
    t.push(7);
    t.push(9);
    t.push(3);
    t.push(6);
    t.push(1);
    t.push(4);
    t.push(8);
    t.print();
    std::cout<<"\n\n\n";


    std::cout<<"создаем дерево 2, добавляем элементы 2 1 3  и отображаем на экран.\n";

    Tree<int> p;
    p.push(2);
    p.push(1);
    p.push(3);
    p.print();
    std::cout<<"\n\n\n";
    std::cout<<"добавляем дерево 2 в дерево 1 как поддерево.\n";

    t.push_tree(p);
    t.print();
    std::cout<<"\n\n\n";
    std::cout<<"max.\n";

    std::cout<< t.max_value()<<"\n";

    std::cout<<"min.\n";

    std::cout<< t.min_value()<<"\n";


    std::cout<<"root.\n";
    std::cout<< t.root()<<"\n";

    std::cout<<"depth.\n";
    std::cout<< t.depth()<<"\n";




    std::cout<<"hello, world\n";
}
