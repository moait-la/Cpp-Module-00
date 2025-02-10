#include "../includes/phonebook.hpp"

void    PhoneBook::addContact() {
    if (totalContacts >= MAXCONTACTS)
        std::cout << "Max Contacts Reaced. Replacing Contact " << index << "." << std::endl;
    contacts[index].insertContact();
    index = (index + 1) % MAXCONTACTS;
    totalContacts += 1;
    std::cout << "Contact addded successfully." << std::endl;
}

void    PhoneBook::requestIndex()
{
    std::string input;

    while (1)
    {
        std::cout << "Enter index: ";
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl; exit(0);
        }
        if (!ft_isdigit(input) || !ft_isValid(input)) {
            std::cout << "index is not valid!" << std::endl;
            continue;
        }
        this->requestedIndex = std::stoi(input);
        if (this->requestedIndex > totalContacts || !this->requestedIndex) {
            std::cout << "index is not valid!" << std::endl;
            continue;
        }
        break;
    }
}

void    PhoneBook::searchContact() {
    if (totalContacts == 0) {
        std::cout << "PhoneBook is empty!" << std::endl;
        return ;
    }
    printTable();
    for (int i = 0; i < MAXCONTACTS && i < totalContacts; i++) {
        contacts[i].displayOnTable(i + 1);
    }
    this->requestIndex();
    contacts[this->requestedIndex - 1].displayFullContact();
}
