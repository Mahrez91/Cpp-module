#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    public:
        Bureaucrat( void );
        Bureaucrat(std::string const & name, int level);
        Bureaucrat( Bureaucrat const & src );
        ~Bureaucrat(void);
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw()
                {
                    return ("Level is too high.");
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw()
                {
                    return ("Level is too low.");
                }
        };

        void    increment( void );
        void    decrement( void );
        std::string getName( void ) const;
        int         getGrade( void ) const;
        Bureaucrat & operator=( Bureaucrat const & src );
        
    private:
        const std::string _name;
        int _grade;
};

std::ostream &  operator<<( std::ostream & o, Bureaucrat const & i );

#endif