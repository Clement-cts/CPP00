# include "PhoneBook.hpp"

int main(){
    std::cout << "=============================" << std::endl;
    std::cout << "|  Welcome to my PhoneBook  |" << std::endl;
    std::cout << "=============================" << std::endl;

    PhoneBook phonebook;
    std::string command;

    while (1){
        std::cout << "Enter a command (ADD, SEARCH, EXIT) :";
        std::getline(std::cin, command);

        if (std::cin.eof())
            break;
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return (0);
}