#include <iostream>
#include <string>
#include "Cat.hpp"

Cat::Cat( void) 
{
    this->_type = "Cat";
    std::cout << "Cat default constructor is call." << std::endl;
    return ;
}

Cat::Cat( Cat const & src)
{
    *this = src;
    std::cout << "Cat copy constructor is call." << std::endl;
    return ;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor is call." << std::endl;
    return ;
}

Cat & Cat::operator=( Cat const & src )
{
    (void)src;
    return *this;
}

void  Cat::makeSound( void ) const
{
    std::cout << "Cat is Miaouuuu" << std::endl;
    return ;
}