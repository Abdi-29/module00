#ifndef PhoneBook_HPP
# define PhoneBook_HPP
# include <iostream>

#include "Contact.hpp"

#define MAX_CONTACT 8

class PhoneBook;

typedef struct s_function 
{
    std::string option;
    int (PhoneBook::*function_pointer)(void);
}               t_function;

class PhoneBook 
{
private:
	Contact		contacts[8];
	int 		_index;
    int     	_numberOfContact;
    std::string	buffer[MAX_CONTACT][5];

    void    PrintContact(std::string str) const;

public:
	int		search_function(void);
	int		exit_function(void);
	int 	add_function(void);

    PhoneBook(void);
    ~PhoneBook();
};

#endif