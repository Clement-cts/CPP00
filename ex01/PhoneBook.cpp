#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _count(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::prompt(std::string label) const{
	std::string s;
	std::cout << label << ": ";
	if (!std::getline(std::cin, s))
		exit(0);

	while (s.empty()) {
		std::cout << label << " cannot be empty. Try again.\n";
		std::cout << label << ": ";
		if (!std::getline(std::cin, s))
			exit(0);
	}
	return s;
}

std::string PhoneBook::truncate(std::string str) const{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::addContact() {
	std::string fn = prompt("First Name");
	std::string ln = prompt("Last Name");
	std::string nn = prompt("Nickename");
	std::string pn = prompt("Phone Number");
	std::string ds = prompt("Darkest Secret");

	_contacts[_count].setContact(fn, ln, nn, pn, ds);

	_count = (_count + 1) % 8;
	std::cout << "Contact added successfully!\n";
}

void	PhoneBook::printContacts() const {
	std::cout << "---------------------------------------------\n";
	std::cout << "|  Index   |First Name| Last Name| Nickname |\n";
	std::cout << "---------------------------------------------\n";

	for (int i = 0; i < 8; i++) {
		if (!_contacts[i].isActive())
			continue;

		std::cout << "|" << std::setw(10) << i + 1
					<< "|" << std::setw(10) << truncate(_contacts[i].getFirst_Name())
					<< "|" << std::setw(10) << truncate(_contacts[i].getLast_Name())
					<< "|" << std::setw(10) << truncate(_contacts[i].getNickName())
					<< "|" << std::endl;
    }
	std::cout << "---------------------------------------------\n";
}

void	PhoneBook::searchContact() {
	printContacts();

	std::string input;

	std::cout << "Enter the index to display (0 to cancel): ";
	if (!std::getline(std::cin, input))
		exit(0);
	if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
		std::cout << "Invalid index.\n";
		return ;
	}
	int index = std::atoi(input.c_str());
	if (index == 0)
		return ;
	if (index < 0 || index > 8 || !_contacts[index - 1].isActive()) {
		std::cout << "Contact not found.\n";
		return ;
	}
	_contacts[index - 1].displayContact();
}
