#include <iostream>
#include <string>
#include "Ice.hpp"

Ice::Ice( void )
{
    this->_type = "ice";
    std::cout << "Ice default constructor is call." << std::endl;
    return ;
}

Ice::Ice( Ice const & src)
{
    std::cout << "Ice copy constructor is call." << std::endl;
    this->_type = src._type;
    return ;
}

Ice::Ice( std::string const & type)
{
    this->_type = type;
    std::cout << "Ice Name constructor is call." << std::endl;
    return ;
}

Ice* Ice::clone( void ) const
{
    return (new Ice(*this));
}

Ice::~Ice( void )
{
    std::cout << "Ice destructor is call." << std::endl;
    return ;
}

Ice & Ice::operator=( Ice const & src )
{
    (void)src;
    return *this;
}

void    Ice::use(ICharacter & target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}