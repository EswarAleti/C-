#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int vertices,edges,from,to;
	//User input for number of vertices and number of edges
	cin>>vertices;
	cin>>edges;
	//Initialize adjacency matrix with all entries with 0
	int graph[vertices][vertices];
	//Initializing all entries to 0
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			graph[i][j]=0;
		}
	}
	for(int i=0;i<edges;i++)
	{
		cin>>from;
		cin>>to;
		//If there is an edge then make entry as 1
		graph[from][to]=1;
	}

	//Initilize inedgree matrix with all entries 0
	int indegree[vertices];
	for(int i=0;i<vertices;i++)
	{
		//Inital indegree is 0
		indegree[i]=0;
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

	//Initialize q
	queue<int> q;
	//Insert all nodes into queue whose having indegree is 0
	for(int i=0;i<vertices;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}

	//If q is empty then there is no order
	if(q.empty())
	{
		cout<<"No order"<<endl;
		return 0;
	}

	cout<<"Order: ";
	//Iterate untill q is empty
	while(!q.empty())
	{
		//Take front vertex
		int vertex = q.front();
		q.pop();
		for(int i=0;i<vertices;i++)
		{
			//For all vertices adjacent to vertex and having indegree[i]=1
			if(graph[vertex][i]==1 && --indegree[i]==0)
			{
				//Push that vertex to q
				q.push(i);
			}
		}
		//Print the vertex 
		q.empty()?cout<<vertex:cout<<vertex<<"->";
	}

	return 0;
}