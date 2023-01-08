#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "classes.cpp"
//REDEFINITION OF THE CLASS MADE ME GO CRAZY, INsCLUDE TWICE :)))

using namespace std;
template <typename S>
ostream& operator<<(ostream& os, 
                   const vector<S>& vector)
{
    for (auto element : vector)
	{
        os << element.get_name() << " ";
    }
    return os;
}

//MKDIR DONE
Directory mkdir (string nom, Directory* current)
{

	Directory dir;
	
	dir.set_name(nom);
	dir.set_location(current->get_location() + "/" + current->get_name());
	dir.set_parent(current);
	//add dir to sub_dir of parent(current)
	std::vector <Directory> C=current->get_sub_dir();
	C.push_back(dir);
	current->set_sub_dir(C);
	return dir;
}
/*-----------------------------------------------------------*/
//LS NOT REALLY COUT THE CONTENT I think I fixed it ?!
//LS DONE
void ls(Directory*  current)
{
	
	std::cout<< current->get_sub_dir();
	cout<< "\n";
	std::cout<< current->get_sub_fex();
	cout<< "\n";
	std::cout<< current->get_sub_fl();
	return;
}
/*-----------------------------------------------------------*/
//DONE WITH CD
Directory* cd(Directory* current, string Destination)
{
	vector <Directory> L=current->get_sub_dir();
	for (int i=0;i<L.size();i++)
	{
		if(L[i].get_name()==Destination)
			return &L[i];
		else
		{
			cout << "No such Directory in the current directory";
			return NULL;
		}
	}
}

/*-----------------------------------------------------------*/
// DONE WITH find?!
string find(string file_name, Directory* D)
{
	std::vector <Directory> V=D->get_sub_dir();
	std::vector <TextFile> W=D->get_sub_fl();
	std::vector <ExecFile> X=D->get_sub_fex();
	int i;
//searching in textFiles category
	for(i=0;i<W.size();i++)
	{
		if (W[i].get_name()==file_name)
		{
			return W[i].get_location();
		}
	}
//Searching in ExecFiles category
	for(i=0;i<X.size();i++)
	{
		if (X[i].get_name()==file_name)
		{
			return X[i].get_location();
		}
	}
//Searching Through Directories Category and TextFiles and ExecFiles within
	for(i==0;i<V.size();i++)
	{
		if(V[i].get_name()==file_name)
		{
			return V[i].get_location();
		}
	}
	//Searching in sub_directories of wach sub_directory
	for(i==0;i<V.size();i++)
	{
		return find(file_name,&V[i]);
	}
	return "!!!Not Found!!!";
}
/*-----------------------------------------------------------*/
int rm(string file_name, Directory* D)// 1 if deleted otherwise 0
{

	std::vector <Directory> V=D->get_sub_dir();
	std::vector <TextFile> W=D->get_sub_fl();
	std::vector <ExecFile> X=D->get_sub_fex();
	int i;
	int s=0;

//searching in textFiles category
	for(i=0;i<W.size();i++)
	{
		if (W[i].get_name()==file_name)
		{
			s=1;
			W.erase(W.begin() + i);
			D->set_sub_fl(W);
			return 1;
		}
	}

//Searching in ExecFiles category
	for(i=0;i<X.size();i++)
	{
		if (X[i].get_name()==file_name)
		{
			s=1;
			X.erase(X.begin() + i);
			D->set_sub_fex(X);
			return 1;
		}
	}

//Searching Through Directories Category and TextFiles and ExecFiles within
	
	for(i==0;i<V.size();i++)
	{
		
		if (V[i].get_name()==file_name)
		{
			s=1;
			V.erase(V.begin() + i);
			D->set_sub_dir(V);
			return 1;
		}
	}

	//Searching in sub_directories of wach sub_directory
	for(i==0;i<V.size();i++)
	{	
		rm(file_name,&V[i]);
	}
	
	if(s==0)
		return 0;
	else 
		return 1;
}

/*int main()
{
	return 0;
}-----------------------------------------------------------*/



