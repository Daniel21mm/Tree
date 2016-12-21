#ifndef EXTREE
#define EXTREE

#include  <stdexcept>
#include  <exception>

class ExTree:public std::exception
{
    std::string error_name;
public:
    ExTree();
    ExTree(std::string _name);
    std::string message();
};


ExTree::ExTree()
    :error_name ("no except")
{

}

ExTree::ExTree(std::string _name)
    :error_name(_name)
{

}

std::string ExTree::message()
{
    return error_name;
}

#endif // EXTREE

