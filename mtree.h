#ifndef MTREE
#define MTREE
#include "extree.h"

#include<iostream>

template<typename Type>
class Tree
{
    struct Node
    {
        Node    ();
        Node    (Type t);
        Node    (const Node &);
        Type    value;
        bool    isvalue;
        Node*   left;
        Node*   right;
        void    push_element(Type t) throw(ExTree);
        void    push_node(Node*) throw(ExTree);
        void    print_node(Node*, uint);

    };

    Node*               element;
    void                delete_tree(Node*);
    Type                _max_value(Node* node);
    Type                _min_value(Node* node);


public:
    Tree                () throw(ExTree);
    Tree                (Type t) throw(ExTree);
    Tree                (const Tree<Type>&) throw(ExTree);
    ~Tree               ();
    void                push(Type t);
    void                push_tree(const Tree<Type>&);
    void                print();
    Type                max_value()throw(ExTree);
    Type                min_value()throw(ExTree);
    Type                root()throw(ExTree);
    bool                isempty();
    Tree<Type>&         operator =(const Tree<Type>&)throw(ExTree);



};


//
//  ---------------------методы Node---------------------
//

template<typename Type>
Tree<Type>::Node::Node()
    :isvalue(false),left(nullptr),right(nullptr)
{}

template<typename Type>
Tree<Type>::Node::Node(Type t)
    :value(t),isvalue(true),left(nullptr),right(nullptr)
{}

template<typename Type>
Tree<Type>::Node::Node(const Node & node)
    :value(node.value),isvalue(node.isvalue),left(node.left),right(node.right)
{

}


template<typename Type>
void Tree<Type>::Node::push_element(Type t) throw(ExTree)
{
    try
    {
        if(isvalue!=true)
        {
            value=t;
            isvalue=true;
        }
        else
        {
            if(value>t)
            {
                if(left==nullptr)
                {
                    Node* data=new Node;
                    left=data;
                    left->push_element(t);
                }
                else
                {
                    left->push_element(t);
                }
            }
            else
            {
                if(right==nullptr)
                {
                    Node* data=new Node;
                    right=data;
                    right->push_element(t);
                }
                else
                {
                    right->push_element(t);

                }
            }
        }
    }
    catch(std::bad_alloc &bd)
    {
        throw ExTree("bad alloc");
    }
}

template<typename Type>
void Tree<Type>::Node::push_node(Tree::Node *node) throw(ExTree)
{
    try
    {
        if(isvalue!=true)
        {
            value=node->value;
            isvalue=true;
            left=node->left;
            right=node->right;
        }
        else
        {
            if(value>node->value)
            {
                if(left==nullptr)
                {
                    Node* data=new Node;
                    left=data;
                    left->push_node(node);
                }
                else
                {
                    left->push_node(node);
                }
            }
            else
            {
                if(right==nullptr)
                {
                    Node* data=new Node;
                    right=data;
                    right->push_node(node);
                }
                else
                {
                    right->push_node(node);

                }
            }
        }
    }
    catch(std::bad_alloc &bd)
    {
        throw ExTree("bad alloc");
    }
}

template<typename Type>
void Tree<Type>::Node::print_node(Node * node, uint lvl)
{
    if(node!=nullptr)
    {
        lvl++;
        print_node(node->right,lvl);
        for(uint i(0);i<lvl-1;i++)
        {
            std::cout<<"__";
        }
        std::cout << (node->value) << std::endl;

    }
    else
    {
        return;
    }

    print_node(node->left,lvl);

}


//
//  ---------------------privat методы Tree---------------------
//



template<typename Type>
void Tree<Type>::delete_tree(Tree::Node *node)
{
    if(node!=nullptr)
    {
        if(node->left!=nullptr)
        {
            delete_tree(node->left);
        }
        if(node->right!=nullptr)
        {
            delete_tree(node->right);
        }
        // std::cout << node->value << std::endl;
        delete node;

    }
}

template<typename Type>
Type Tree<Type>::_max_value(Node* node)
{
    if(node->right!=nullptr)
    {
        _max_value(node->right);
    }
    else
    {
        return node->value;
    }
}

template<typename Type>
Type Tree<Type>::_min_value(Tree::Node *node)
{
    if(node->left!=nullptr)
    {
        _min_value(node->left);
    }
    else
    {
        return node->value;
    }
}







//
//  --------------------- public методы Tree---------------------
//

template<typename Type>
Tree<Type>::Tree() throw(ExTree)
{
    try
    {
        element = new Node;
    }
    catch(std::bad_alloc &bd)
    {
        throw ExTree("bad alloc");
    }
}

template<typename Type>
Tree<Type>::Tree(Type t) throw(ExTree)
{
    try
    {
        element = new Node(t);
    }
    catch(std::bad_alloc &bd)
    {
        throw ExTree("bad alloc");
    }
}

template<typename Type>
Tree<Type>::Tree(const Tree<Type> &tree) throw(ExTree)
{
    try
    {
        element =new Node(*tree.element);
    }
    catch(std::bad_alloc &bd)
    {
        throw ExTree("bad alloc");
    }
}


template<typename Type>
Tree<Type>::~Tree()
{
    delete_tree(element);
}

template<typename Type>
void Tree<Type>::push(Type t)
{
    element->push_element(t);
}

template<typename Type>
void Tree<Type>::push_tree(const Tree<Type> & tree)
{
    element->push_node(tree.element);
}


template<typename Type>
void Tree<Type>::print()
{
    element->print_node(element,0);

}

template<typename Type>
Type Tree<Type>::max_value() throw(ExTree)
{
    if(element!=nullptr)
    {
        return _max_value(element);

    }
    else
    {
        throw ExTree("empty tree");
    }

}

template<typename Type>
Type Tree<Type>::min_value() throw(ExTree)
{
    if(element!=nullptr)
    {
        return _min_value(element);
    }
    else
    {
        throw ExTree("empty tree");
    }


}

template<typename Type>
Type Tree<Type>::root() throw(ExTree)
{
    if(element!=nullptr)
    {
        return element->value;
    }
    else
    {
        throw ExTree("empty tree");
    }


}

template<typename Type>
bool Tree<Type>::isempty()
{
    return element->isvalue;
}



template<typename Type>
Tree<Type> & Tree<Type>::operator =(const Tree<Type> &tree) throw(ExTree)
{
    try
    {
        delete_tree(element);
        element = new Node(*tree.element);
        return *this;
    }
    catch(std::bad_alloc &bd)
    {
        throw ExTree("bad alloc");
    }
}


#endif // MTREE

