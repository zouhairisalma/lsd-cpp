#include <iostream>
#include <string>
using namespace std;


class Contact 
{
    private:
        string firstname;
        string lastname;
        string nickname;
        string phonenumber;
    public:
        Contact(){}
        ~Contact(){}
    friend class PhoneBook;
};

class PhoneBook
{
    private:
        Contact Contacts[8];
        int Full=0;//Number of saved contacts into the PhoneBook
    public:

        void ADD();
        string TRUNCATE(string);
        void SEARCH(int);
        void EXIT();

    PhoneBook();
    ~PhoneBook();     
};