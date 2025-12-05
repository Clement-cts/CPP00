#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <stdlib.h>

class PhoneBook {
    private:
        Contact _contacts[8];
        int _count;

        std::string prompt(std::string label) const;
        std::string truncate(std::string str) const;

    public:
        PhoneBook();
        ~PhoneBook();

        void    addContact();
        void    searchContact();
        void    printContacts() const;
};

#endif