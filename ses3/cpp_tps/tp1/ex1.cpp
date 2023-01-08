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
	//cout << i+1 << " ";
  
	// Recur for all the vertices
	// adjacent to this vertex
	
    vector <int> Z=Adjacents(i+1,G,n);
    
	for (int j =0; j<Z.size();j++)
    {
		if (!visited[Z[j]-1])
        {
    
			DFSUtil(Z[j]-1, visited,G,n);
        }
    }
}



int connectedComponents(vector<vector<int>> G,unsigned n)//n is no of compenents
{
	// Mark all the vertices as not visited
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
    
    int count=0;
	for (int i = 0; i<n; i++) 
    {
		if (visited[i] == false)
        {
            count ++;
			DFSUtil(i, visited,G,n);
			cout << "\n";
		}
	}
	delete[] visited;
    return count;
}



int main()
{
    vector<vector<int>> G= {{0,1,1,0,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{0,0,0,0,1,0},{0,0,0,1,0,0},{0,0,0,0,0,0}};
    cout<<connectedComponents(G,6);
	return 0;
}
