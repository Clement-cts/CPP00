#include "contact.hpp"

Contact::Contact() : active(false) {}
Contact::~Contact() {}

void    Contact::setContact(std::string fn, std::string ln, std::string nn,
                            std:: string pn, std::string ds) {
    First_Name = fn;
    Last_Name = ln;
    NickName = nn;
    Phone_Number = pn;
    Darkest_Secret = ds;
    active = true;
}

bool    Contact::isActive() const {
    return active;
}

std::string Contact::getFirst_Name() const { return First_Name; }
std::string Contact::getLast_Name() const { return Last_Name; }
std::string Contact::getNickName() const { return NickName;}
std::string Contact::getPhone_Number() const { return Phone_Number; }
std::string Contact::getDarkest_Secret() const { return Darkest_Secret; }

void    Contact::displayContact() const {
    std::cout << "First Name:      " << First_Name << std::endl;
    std::cout << "Last Name:       " << Last_Name << std::endl;
    std::cout << "Nickname:        " << NickName << std::endl;
    std::cout << "Phone Number:    " << Phone_Number << std::endl;
    std::cout << "Darkest Secret:  " << Darkest_Secret << std::endl;
}
