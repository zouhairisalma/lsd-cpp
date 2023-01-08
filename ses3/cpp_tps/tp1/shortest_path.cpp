#include <iostream>
#include <vector>
#include "shortest_path.hpp"

using namespace std;


vector<int> Adjacents(unsigned i,vector<vector<int>> G ,unsigned n)
{
    vector <int> V;
    for(int j=0;j<n;j++)
    {
        //cout << "IN ADJACENTS ?!";
        if(G[i-1][j]==1)
        {
            V.push_back(j+1);
            //cout<< "j+1 "<<j+1;
            //cout <<"\n";
        }
    }
    return V;
}
int Search(unsigned i,vector <int> V)
{
    for (int j=0;j<V.size();j++)
    {
        if (V[j]==i)
            return 1;
    }
    return 0;
}

vector <int> shortestpath (unsigned n,vector<vector<int>> G,unsigned z )
{
  vector<int> F;  
  vector<int> visited;  
  F={1};
  int i=0;

  while (F.size()!=0 && i<n)
  { 
    int m=F.size();
    int v=F.at(0);
    F.erase(F.begin());
    visited.push_back(v);
    //create a function that returns the list of adjacents of a number
    //but also another that searches an element in a vector
    vector<int> ADJ=Adjacents(v,G,n);
   
    for(int j=0 ;j<ADJ.size();j++)
    { 
       if (Search(ADJ[j],visited)==0)
        {
            F.push_back(ADJ[j]); 
           break;
        }
    }

    i++; 
}
 
  vector <int> path;

  int k=0;

  while(visited[k]!=z and k<6)
  {
    path.push_back(visited[k]);
    k++;
  } 
  

if( Search(z, Adjacents(visited[visited.size()-1],G,n))==1)
{
    path.push_back(z);
}
else
{
    vector <int> SP={1};
    return SP;
}
 
vector <int> shortestpath={1};

int e=path.size();
int a=0;
while(a<e)
{
     if(Search(path[e-a-1],Adjacents(1,G,n)))
     {
        for(int j=e-a-1;j<e;j++)
            shortestpath.push_back(path[j]);
        break;
     }
     a++;
}

  return shortestpath;
}





int main()
{
    vector<vector<int>> G= {{0,0,0,1,1,0},{0,0,0,0,0,0},{0,0,0,1,1,0},{1,0,1,0,1,0},{1,0,1,1,0,0},{0,0,0,0,1,0}};
    //cout <<G.size();
    int k=2;
    vector <int> path=shortestpath (6,G,k);
    cout <<"SHORTEST PATH from 1 to "<<k<<"is :\n";
    for (int i=0;i<path.size();i++)
    {
        cout <<path[i]<<"\t";
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
#include "shortest_path.hpp"

using namespace std;


vector<int> Adjacents(unsigned i,vector<vector<int>> G ,unsigned n)
{
    vector <int> V;
    for(int j=0;j<n;j++)
    {
        //cout << "IN ADJACENTS ?!";
        if(G[i-1][j]==1)
        {
            V.push_back(j+1);
            //cout<< "j+1 "<<j+1;
            //cout <<"\n";
        }
    }
    return V;
}
int Search(unsigned i,vector <int> V)
{
    for (int j=0;j<V.size();j++)
    {
        if (V[j]==i)
            return 1;
    }
    return 0;
}

void DFSUtil(int i, bool visited[],vector<vector <int>>G,unsigned n)
{
	// Mark the current node as visited and print it
	visited[i] = true;
	cout << i+1 << " ";
	// Recur for all the vertices
	// adjacent to this vertex
	
    vector <int> Z=Adjacents(i+1,G,n);

	for (int j =0; j<Z.size();j++)
    {
		if (!visited[Z[j]-1])
			DFSUtil(Z[j]-1, visited,G,n);

    }
}



void connectedComponents(vector<vector<int>> G,unsigned n)//n is no of compenents
{
	// Mark all the vertices as not visited
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
    
	for (int i = 0; i<n; i++) 
    {
		if (visited[i] == false)
        {
			DFSUtil(i, visited,G,n);
			cout << "\n";
		}
	}
	delete[] visited;
}



int main()
{
    vector<vector<int>> G= {{0,0,0,1,1,0},{0,0,0,0,0,0},{0,0,0,1,1,0},{1,0,1,0,1,0},{1,0,1,1,0,0},{0,0,0,0,0,0}};
    connectedComponents(G,6);

	return 0;
}


*/