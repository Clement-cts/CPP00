#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
    private:
        std::string First_Name;
        std::string Last_Name;
        std::string NickName;
        std::string Phone_Number;
        std::string Darkest_Secret;
        bool    active;

    public:
        Contact();
        ~Contact();

        void    setContact(std::string fn, std::string ln, std::string nn,
                            std:: string pn, std::string ds);

    bool    isActive() const;
    std::string getFirst_Name() const;
    std::string getLast_Name() const;
    std::string getNickName() const;
    std::string getPhone_Number() const;
    std::string getDarkest_Secret() const;

    void    displayContact() const;
};

#endif