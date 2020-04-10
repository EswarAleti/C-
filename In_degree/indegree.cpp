#include<iostream>
using namespace std;

int main()
{
	int vertices,edges,from,to;
	//User input for number of vertices and number of edges
	cin>>vertices;
	cin>>edges;
	//Initialize adjacency matrix with all entries with 0
	int graph[vertices][vertices]={0};
	for(int i=0;i<edges;i++)
	{
		cin>>from;
		cin>>to;
		//If there is an edge then make entry as 1
		graph[from][to]=1;
	}

	//Initilize inedgree matrix with all entries 0
	int indegree[vertices]={0};
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			//If there exist an edge from j to i then increment indegree by 1
			if(graph[j][i]==1)
			{
				indegree[i]++;
			}
		}
	}

	//Output
	for(int i=0;i<vertices;i++)
	{
		cout<<"In-degree["<<i<<"]:"<<indegree[i]<<endl;
	}
	return 0;
}