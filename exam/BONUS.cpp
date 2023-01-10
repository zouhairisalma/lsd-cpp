#include <iostream>
#include <string>
#define N 1000 //Number max of pages in all books


using namespace std;

//CLASS Page
class Page
{
    private:
        int number;
        string content;
        string title;
    friend class Library;
};

class Book
{   
    private:
    string name;
    int ISBN;
    string author;
    string link;
    int nb_pages;
    Page pages[N];
    bool read;
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

//new ADD() method
void Library:: ADD()
{
    if (n<8)
    {
        cout<<"Is the book naive to the library if so print 1 otherwise 0";
        cin>> B[n].read;
        cout<<"enter name for the new book:\n";
        cin>> B[n].name;
        cout<<"enter ISBN number for the new book:\n";
        cin>> B[n].ISBN;
        cout<<"enter author for the new book:\n";
        cin>> B[n].author;
        cout<<"enter link number for the new book:\n";
        cin>> B[n].link;
        cout<<"enter number of pages for the new book:\n";
        cin>> B[n].nb_pages;
        if (B[n].read==1)
        {
            for (int j=0;j<B[n].nb_pages;j++)
            {
                cout << "enter the title for page"<<j<<"\n";
                cin >>(B[n].pages)[j].title;
                cout<< "enter the content for page"<<j<<"\n";
                cin >> (B[n].pages)[j].content;
                B[n].pages[j].number=j;
            }
        }

       
        n+=1;
    }
    if(n==8)
    {
         cout<<"Is the book naive to the library if so print 1 otherwise 0";
        cin>> B[0].read;
         cout<<"enter name for the new book:\n";
        cin>> B[0].name;
        cout<<"enter ISBN number for the new book:\n";
        cin>> B[0].ISBN;
        cout<<"enter author for the new book:\n";
        cin>> B[0].author;
        cout<<"enter link number for the new book:\n";
        cin>> B[0].link;
        cout<<"enter number of pages for the new book:\n";
        cin>> B[0].nb_pages;
        if (B[0].read==1)
        {
            for (int j=0;j<B[0].nb_pages;j++)
            {
                cout << "enter the title for page"<<j<<"\n";
                cin >>(B[0].pages)[j].title;
                cout<< "enter the content for page"<<j<<"\n";
                cin >> (B[0].pages)[j].content;
                B[0].pages[j].number=j;
            }
        }

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
    cout <<"Enter index of the book";
    cin>> i;

    while (i>n)
    {
        cout<<"No book of this index belongs to this Library\n";
        cout <<"Enter a valid index\n";
        cin >>i;
    }
    /*
    cout<< i<<"\n";
    cout <<"||||||||||\n";
    cout <<display(B[i].name)<<"\n";
    cout <<"||||||||||\n";
    cout<< display(B[i].author)<<"\n";
    */
    if (B[i].read==1)
    {
        int a;
        cout <<"enter page\n";
        cin >> a;
        if (a<B[i].nb_pages)
        {
            cout<< B[i].pages[a].number<<"\n";
            cout<< B[i].pages[a].title<<"   ";;
            cout<< B[i].pages[a].content<<"\n";

            char x;
            cout << "enter n if you want to show next page content:\n";
            cin >>x;
            if(x=='n')
            {
                if (a+1<B[i].nb_pages)
                {
                    cout<< B[i].pages[a+1].number<<"\n";
                    cout<< B[i].pages[a+1].title<<"   ";;
                    cout<< B[i].pages[a+1].content<<"\n";
                }
            }

        }
        
    }
    else
    {
        cout << "The book can't be read from within the program\n";

    }
    return ;
}


void Library:: EXIT()
{
    exit(0);
}


int main()
{
    
    Library L;
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