#include <iostream>
#include <string>

using namespace std;
class Contact 
{
    public://Not necessarily all of them are public we'll see later on 
        string firstname;
        string lastname;
        string nickname;
        string phonenumber;//All fields must be full
};
class PhoneBook
{
    public:
        Contact Contacts[8];
        int Full=0;//Number of saved contacts into the PhoneBook
        void ADD();
        void SEARCH(int);
        void EXIT();
};



void PhoneBook::EXIT()
{
    cout <<"WE'RE LEAVING, EVERYTHING S GONE";
    exit(0);
}

void PhoneBook::SEARCH(int i)
{
    if(i>Full)
    {
        printf("NO SUCH CONTENT IN THIS PHONEBOOK");
        exit(0);
    }
    else
    {
        printf("%d\n",Full);
        std::cout.width(6);
        printf("[ ");
        std::cout << std::right <<(Contacts[i].firstname).substr(0, 10);
        printf(" | ");
        std::cout << std::right <<(Contacts[i].lastname).substr(0, 10);
        printf(" | ");
        std::cout << std::right <<(Contacts[i].nickname).substr(0, 10);
        printf(" ]");
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
    A.ADD();
    A.SEARCH(0);
    A.ADD();
    //A.ADD();
    //A.ADD();
    //A.ADD();
    //A.ADD();
    //A.ADD();
    //A.ADD();
    //A.ADD();
    //A.ADD();
    A.SEARCH(0);
    A.EXIT();
    A.ADD();
    return 0;
}

