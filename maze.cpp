#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
#define N 4
#define M 5
class node 
{
	public:
	int x, y;
	node(int i, int j)
	{
		x = i;
		y = j;
	}
};

int n=N, m=M;
bool visit[N][M];

bool isReachable(int maze[N][M],int fx,int fy)
{
	int i,j;
	stack<node>s;
	node temp(0,0);
	s.push(temp);

	while (!s.empty())
	{
		temp = s.top();
		//Remove the node from stack
		s.pop();  
		i = temp.x, j = temp.y;
		if (i == fx and j == fy)
		{
			return 1;
		}
		//Add all nodes to stack that are traversable from current node
		//up
		if(i-1>=0 && maze[i-1][j]== 1 && visit[i-1][j])
		{
			node temp1(i - 1, j);
			visit[i - 1][j] = 0;
			s.push(temp1);
		}
		// left
		if(j-1>=0 && maze[i][j-1]== 1 && visit[i][j-1])
		{
			node temp1(i, j - 1);
			visit[i][j - 1] = 0;
			s.push(temp1);
		}
		// down
		if(i+1<N && maze[i+1][j]== 1 && visit[i+1][j])
		{
			node temp1(i + 1, j);
			visit[i + 1][j] = 0;
			s.push(temp1);
		}
		// right
		if(j+1<M && maze[i][j+1]== 1 && visit[i][j+1])
		{
			node temp1(i, j + 1);
			visit[i][j + 1] = 0;
			s.push(temp1);
		}
	}
	return 0;
}
int main()
{
	memset(visit, 1, sizeof(visit));
	int maze[N][M] = {
					{ 1, 0, 1, 1, 1 },
					{ 1, 1, 1, 0, 1 },
					{ 0, 0, 0, 0, 1 },
					{ 1, 1, 1, 0, 1 }
					};
	int fx = 3;
	int fy = 4;
	if (isReachable(maze,fx,fy)) 
	{
		cout << "Path Found!" << '\n';
	}
	else
	{
		cout << "No Path Found!" << '\n';
	}
	return 0;
}