// Author: ufo008ahw
// Last modified: 2013-09-15 22:15



namespace maxMatch
{
	int nx, ny;
	vector<int> matchX, matchY;
	vector< vector<int> > biGraph;

	void initialize(vector< vector<int> > graph)
	{
		nx = graph.size();
		ny = graph[0].size();
		matchX.resize(nx);
		matchY.resize(ny);
		biGraph = graph;

		for(int i = 0;i < nx;i++)
			matchX[i] = -1;
		for(int i = 0;i < ny;i++)
			matchY[i] == -1;
	}
}

vector<int> yUsed;
// find augment path
int path(int xNode)
{
	for(int i = 0;i < maxMatch::ny;i++)
	{
		if (graph[xNode][i] && !yUsed[i])
		{
			yUsed[i] = 1;

			if (matchY[i] == -1 || path(matchY[i]))
			{
				matchX[xNode] = i;
				matchY[i] = xNode;
				return 1;
			}
		}
	}
}

int maxMatch(vector< vector<int> > graph);
{
	maxMatch::initialize(graph);
	yUsed.reisze(maxMatch::ny);

	int res = 0;
	for(int i = 0;i < nx;i++)
	{
		for(int j = 0;j < ny;j++)
			yUsed[j] = 0
		res += path(i);
	}

	return res;
}

/*
 * Input: graph, a adjacent matrix.
 * Ouput: tree, tree[i] store the father node. return the connected part number.
 * Complexity: O(n^2).
 */

static int minSpanTree_prime(vector<vector<int> > &graph, vector<int> &tree)
{
	assert(graph.size() == graph[0].size());
	int nodeNum = graph.size();

	vector<int> flag(nodeNum);
	vector<bool> cost(nodeNum);

	priority_queue<int,

	int startNode = 0;
	while(1)
	{
		for()

		for (i = 1; i < n; i++)
		{
			min = 1000000;
			v = 0;
			for (j = 0; j < n; j++)
		{
			if (!flag[j] && closet[j] < min)
			{
				v = j;
				min = closet[j];
			}
		}
		if (v)
		{
			tree[i] = v;
			flag[v] = 1;
			for (j = 0; j < n; j++)
				if (!flag[j] && graph[v][j] < closet[j])
					closet[j] = graph[v][j];
		}
	}
}

/*
 * Description: Gijkstra single source shortest path.
 * Input: 1. n: graph node number,
 *        2. path[]: shortest path
 * Output: path[]
 * Note: Time complexity: O(n^2), v is souce node.
 */
#define NMAX 100000
static void dijkstra(int n, int path[])
{
	int dis[NMAX], used[NMAX];
	int i, j, v, u, ldis;
	v = 0;
	for (i = 0; i < n; i++)
	{
		path[i] = -1;
		dis[i] = MAX;
		used[i] = 0;
	}
	dis[v] = 0;
	used[v] = 1;
	u = v;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (graph[u][j] != -1 && used[j] != 1 && dis[u] + graph[u][j] < dis[j])//最优子序列，这里可以变形)
			{
				dis[j] = dis[u] + graph[u][j];
				path[j] = u;
			}
		ldis = MAX;
		for (j = 0; j < n; j++)
			if (dis[j] < ldis && used[j] == 0)//&&dis[j]>0)
			{
				ldis = dis[j];
				u = j;
			}
		used[u] = 1;
	}
}

/**********************************************
 * Description: Floyd find all shortest path between any two nodes.
 *  Input: 1. n: graph node number,
 *         2. A[][]: shortest path value.
 *         3. path[][]: shortest path.
 * Output: path[][], A[][]
 * Note: Time complexity: O(n^3).
 **********************************************/
#define MAX 100
int path[MAX][MAX], A[MAX][MAX];
void floyd(int n)
{
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			A[i][j] = graph[i][j];
			if (i != j && A[i][j] != -1)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			if (i != k)
				for (j = 0; j < n; j++)
					if (j != k && j != i && A[i][k] != -1 && A[k][j] != -1 && A[i][k] + A[k][j] < A[i][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						path[i][j] = path[k][j];
					}
}

/***********************************
 * Description: Bipartite matching
 * Input: 1.nx:left part points number, 2.ny:left part points number.
 * Output: res, maxmium matching number.
 * Note: Time complexity: O(n^3).
 * **********************************/
#define MAXN 201
int g[MAXN][MAXN], cx[MAXN], cy[MAXN], used[MAN];
int nx, ny;
int path(int u)
{
	int i;
	for (i = 0; i < ny; i++)
	{
		if (g[u][i] && !used[i])
		{
			used[i] = 1;
			if (cy[i] == -1 || path(cy[i]))
			{
				cx[u] = i;
				cy[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
int maxMatch()
{
	int i, res;
	res = 0;
	memset(cx, 0xff, sizeof(cx));
	memset(cy, 0xff, sizeof(cy));
	for (i = 0; i < nx; i++)
		if (cx[i] == -1)
		{
			memset(used, 0, sizeof(used));
			res += path(i);
		}
	return res;
}
