#include <iostream>
#include <string>
#include "Form.hpp"

Form::Form( void) : _name("default"), _sign(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor is call." << std::endl;
    return ;
}

Form::Form( std::string const & name, int const Tosign, int const Toexecute) : _name(name), _sign(false), _gradeToSign(Tosign), _gradeToExecute(Toexecute)
{
    if (Toexecute < 1 || Tosign < 1)
		throw GradeTooLowException();
	if (Toexecute > 150 || Tosign > 150)
		throw GradeTooHighException();
    std::cout << "Form name constructor is call." << std::endl;
    return ;
}

Form::Form( Form const & src) : _name(src.getName()), _sign(src.getSign()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
    std::cout << "Form copy constructor is call." << std::endl;
    return ;
}

std::string Form::getName( void ) const
{
    return this->_name;
}

int Form::getGradeToSign( void ) const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute( void ) const
{
    return this->_gradeToExecute;
}

bool Form::getSign( void ) const
{
    return this->_sign;
}

void Form::beSigned( Bureaucrat & src)
{
    if (src.getGrade() <= this->_gradeToSign)
        this->_sign = true;
    else  
        throw GradeTooLowException();
    return ;
}


Form::~Form( void )
{
    std::cout << "Form destructor is call." << std::endl;
    return ;
}

Form & Form::operator=( Form const & src ) 
{
    (void)src;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
    if (i.getSign() == true)
        o << i.getName() << " is signed. Form grade to sign = " << i.getGradeToSign() << " and to execute : " << i.getGradeToExecute(); 
    else
        o << i.getName() << " isn't signed. Form grade to sign = " << i.getGradeToSign() << " and to execute : " << i.getGradeToExecute(); 
    return o;
}

