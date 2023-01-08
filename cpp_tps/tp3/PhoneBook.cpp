#include <iostream>
#include <string>
#include "PB2.hpp"

using namespace std;

PhoneBook::PhoneBook()
{
    cout << "\nNew PhoneBook created\n";
}

PhoneBook::~PhoneBook()
{
    cout << "\nPhoneBook Deleted\n";
}

string PhoneBook::TRUNCATE(string A)
{
    if(A.size()<11)
        return A;
    else
    {
        string B=A.substr(0,9)+".";
        return B;
    }
}
void PhoneBook::EXIT()
{
    PhoneBook::~PhoneBook();
    cout <<"EXITING...\n";
    cout <<"EXIT!\n";
    exit(0);
}
void PhoneBook::SEARCH(int i)
{
    if(i>Full)
    {
        printf("\nNO SUCH CONTENT IN THIS PHONEBOOK\n");
    }
    else
    {

        std::cout.width(6);
        cout<< "\n";
        printf("[ ");
        std::cout << std::right <<TRUNCATE(Contacts[i].firstname);
        printf(" | ");
        std::cout << std::right <<TRUNCATE(Contacts[i].lastname);
        printf(" | ");
        std::cout << std::right <<TRUNCATE(Contacts[i].nickname);
        printf(" | ");
         std::cout << std::right <<TRUNCATE(Contacts[i].phonenumber);
        printf(" ]");
        cout<<"\n";
    }
}



void PhoneBook::ADD()
{
    if(Full<8)
    {
        cout<<"Enter firstname:";
        cin>>Contacts[Full].firstname;
        cout<<"Enter lastname:";
        cin>>Contacts[Full].lastname;
        cout<<"Enter nickname:";
        cin>>Contacts[Full].nickname;
        cout<<"Enter phonenumber:";
        cin>>Contacts[Full].phonenumber;
        Full++;
    }

    if (Full==8)
    {
    cout<<"Enter firstname:";
    cin>>Contacts[0].firstname;
    cout<<"Enter lastname:";
    cin>>Contacts[0].lastname;
    cout<<"Enter nickname:";
    cin>>Contacts[0].nickname;
    cout<<"Enter phonenumber:";
    cin>>Contacts[0].phonenumber;
    }
}

int main()
{
    PhoneBook A;
    while(0==0)
    {
        int i;
        cout << "if you want to add a new contact enter 1, to search a contact enter 2 , to exit click 0\n";
        cout << "Enter a number\n";
        cin >>i;
        if(i==0)
        {
            A.EXIT();
        }
        else
        {
            if (i==1)
            {
                A.ADD();
            }
            else 
            {
                if(i==2)
                {
                    int j;
                    cout << "enter the index of the contact you're searching: ";
                    cin>>j;
                    A.SEARCH(j);
                }
                else
                {
                    cout << "enter 0,1 or 2 :))";
                }
                
            }

        }

    }
    return 0;
}




