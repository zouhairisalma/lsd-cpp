#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "functions.cpp"


using namespace std;


int main()
{

    Shell SHELL;//here name of thee file twice ?
    Directory* CURRENT=SHELL.get_rootdir();
    //this is the current directory during the runtime each time 
    //we change the current directory through mkdir for example
    // this variable will point on a different directory 

    while(0==0)
    {
        string file;
        string command;
        cout << "\ncommand: ";
        cin >>command;
        if (command=="quit")
            exit(0);
        if(command=="ls")
                ls(CURRENT);
        else
        {
        cout << "\nfile: ";
        cin >>file;
        
    
       
        if (command=="mkdir")
            Directory dir=mkdir(file,CURRENT);
        else
        {
                if(command=="cd")
                    CURRENT=cd(CURRENT,file);
                else
                {
                    if(command=="find")
                        cout << find(file,CURRENT);
                        else
                        {
                            if(command=="rm")
                            {
                                int z;
                                z=rm(file,CURRENT);
                                std::cout << "The program finisheds with returning value: " << z;
                                std::cout<< "\nNOTE: 1 means file deleted, 0 not found in the first place\n";
                            }
                        }
                }
            }
        }
    }
    
    return 0;
}
    








