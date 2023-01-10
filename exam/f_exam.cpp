#include <iostream>
#include <string>


using namespace std;

class Book
{   
    private:
    string name;
    int ISBN;
    string author;
    string link;
    friend class Library;
    friend string display(string A);
};

class Library
{
    private:
        Book B[8];
    public:
    int n;//number or books in the library
    void ADD(); 
    void SEARCH();
    void EXIT();
    Library(){n=0;}//Constructor
    ~Library(){}//Deconstructor
    friend string display(string A);
    
};

void Library:: ADD()
{
    if (n<8)
    {
         
        cout<<"enter name for the new book:\n";
        cin>> B[n].name;
        cout<<"enter ISBN number for the new book:\n";
        cin>> B[n].ISBN;
        cout<<"enter author for the new book:\n";
        cin>> B[n].author;
        cout<<"enter link number for the new book:\n";
        cin>> B[n].link;
      
        n+=1;
    }
    if(n==8)
    {
         cout<<"enter name for the new book:\n";
        cin>> B[0].name;
        cout<<"enter ISBN number for the new book:\n";
        cin>> B[0].ISBN;
        cout<<"enter author for the new book:\n";
        cin>> B[0].author;
        cout<<"enter link number for the new book:\n";
        cin>> B[0].link;

    }
    return;
}
string display(string A)
{
    if (A.size()>10)
        A=A.substr(0,9)+".";
    return A;
}

void Library:: SEARCH()
{
    int i;
    cout <<"Enter index";
    cin>> i;
    /*while(i>n)
    {
        cout<<"No book of this index belongs to this Library";
        cout <<"Enter a valid index\n";
        cin >>i;
    }
    cout <<"Index    |"<<"Book name|"<<"AuthorName\n";
    cout<< i<<"        |"<<display(B[i].name)<<"|"<< display(B[i].author)<<"\n";
    */
      /// ////////////////////////////////////////
    while (i>n)
    {
        cout<<"No book of this index belongs to this Library\n";
        cout <<"Enter a valid index\n";
        cin >>i;
    }

    cout<< i<<"\n";
    cout <<std::right<<"||||||||||\n";
    cout <<std::right<<display(B[i].name)<<"\n";
    cout <<std::right<<"||||||||||\n";
    cout<<std::right<<display(B[i].author)<<"\n";
        
    return ;
}


void Library:: EXIT()
{
  
    exit(0);
}


int main()
{
    
    Library L;
    cout <<L.n<<"\n";
    while(0==0)
    {
        string S;
        cout << "Enter a command : ADD, SEARCH or EXIT : \n";
        cin >> S;
        if(S=="EXIT")
        {
            L.EXIT();
        }
        else 
        {   
            if (S=="SEARCH")
            {
                L.SEARCH();
            }
            else 
            {
                if (S=="ADD")
                {
                    L.ADD();
                }
            }

        }
    }


}
