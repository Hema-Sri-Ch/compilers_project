# include <bits/stdc++.h>
using namespace std;

void unweightedDfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res)
{
	vis[node]=1;
	res.push_back(node);
	for(auto it: adj[node])
	{
		if(!vis[it])
			unweightedDfs(it, adj, vis, res);
	}
	return;
}

void weightedDfs(int node, vector<vector<pair<int, double>>>& adj, vector<int>& vis, vector<int>& res)
{
	vis[node]=1;
	res.push_back(node);
	for(auto it: adj[node])
	{
		int val = it.first;
		if(!vis[val])
			weightedDfs(val, adj, vis, res);
	}
	return;
}

void unweightedBfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res)
{
	vis[node]=1;
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		int t = q.front();
		res.push_back(t);
		q.pop();
		for(auto v: adj[t])
		{
			if(!vis[v])
			{
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return;
}

void weightedBfs(int node, vector<vector<pair<int, double>>>& adj, vector<int>& vis, vector<int>& res)
{
	vis[node]=1;
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		int t = q.front();
		res.push_back(t);
		q.pop();
		for(auto val: adj[t])
		{
			int v = val.first;
			if(!vis[v])
			{
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return;
}

class graph
{
	public:
	int vertices;
	vector<vector<int>> edges;
	vector<vector<pair<int, double>>> weightedEdges;
	int flag; // To tell whether it is weighted or unweighted


	graph(int n)
	{
		vertices = n;
		edges.resize(n+1, vector<int>(0));
		weightedEdges.resize(n+1, vector<pair<int,double>>(0) );
	}

	void setFlag(int val)
	{
		flag = val;
		// flag = 0 unweighted
		// flag = 1 weighted
	}

	int getFlag()
	{
		return flag;
	}

	int getVertices()
	{
		return vertices;
	}

	int addEdge(int u, int v)
	{
		if(u>vertices || v> vertices)
		{
			return 0;
		}
		edges[u].push_back(v);
		return 1;
	}

	vector<vector<int>> getEdges()
	{
		return edges;
	}

	vector<vector<pair<int, double>>> getWeightedEdges()
	{
		return weightedEdges;
	}

	int addWeightedEdge(int u, int v, double weight)
	{
		if(u>vertices || v> vertices)
		{
			return 0;
		}
		if(weight<0)
		{
			cout << "Weight has to be non-negative\n";
			exit(1);
		}
		weightedEdges[u].push_back({v,weight});
		return 1;
	}

	

	void printUnweighted()
	{
		cout << "\n";
		for(int i=1; i<=vertices; i++)
		{
			int sz = edges[i].size();
			if(sz==0) continue;
			cout << i << "\t:\t";
			for(int j=0; j<sz; j++)
			{
				cout << edges[i][j];
				if(j!=sz-1) cout << ",\t";
			}
			cout << endl;
		}
	}

	void printWeighted()
	{
		cout << "\n";
		for(int i=1; i<=vertices; i++)
		{
			int sz = weightedEdges[i].size();
			if(sz==0) continue;
			cout << i << "\t:\t";
			for(int j=0; j<sz; j++)
			{
				int node = weightedEdges[i][j].first;
				double weight = weightedEdges[i][j].second;
				cout << "(" << node << "," << weight << ")";
				if(j!=sz-1) cout << ",\t";
			}
			cout << endl;
		}
	}

	void printGraph()
	{
		if(flag==0) printUnweighted();
		else if(flag==1) printWeighted();
		else
		{
			cout << "\n{ }\n";
		}
	}

	vector<int> adjUnweighted(int node)
	{
		return edges[node];
	}

	vector<int> adjWeighted(int node)
	{
		vector<int> res;
		int sz = weightedEdges[node].size();
		for(int i=0; i<sz; i++)
		{
			res.push_back(weightedEdges[node][i].first);
		}
		return res;
	}

	vector<int> adjNodes(int node)
	{
		if(node>vertices)
		{
			cout << "ERROR: Invalid labelled node\n";
			exit(1);
		}
		if(flag==0) return adjUnweighted(node);
		else if(flag==1) return adjWeighted(node);
		else
		{
			cout << "ERROR: Graph is not initialised yet\n";
			exit(1);
		}
	}

	vector<int> dfs(int node)
	{
		if(node > vertices)
		{
			cout << "ERROR: Invalid labelled node\n";
			exit(1);
		}
		vector<int> vis(vertices+1, 0);
		vector<int> res;
		if(flag==0) unweightedDfs(node, edges, vis, res);
		else if(flag==1) weightedDfs(node, weightedEdges, vis, res);
		else
		{
			cout << "ERROR: Graph not yet initialized";
			exit(1);
		}
		return res;
	}

	vector<int> bfs(int node)
	{
		if(node > vertices)
		{
			cout << "ERROR: Invalid labelled node\n";
			exit(1);
		}
		vector<int> vis(vertices+1, 0);
		vector<int> res;
		if(flag==0) unweightedBfs(node, edges, vis, res);
		else if(flag==1)weightedBfs(node, weightedEdges, vis, res);
		else
		{
			cout << "ERROR: Graph not yet initialized";
			exit(1);
		}
		return res;
	}

};

typedef class graph graph;

vector<int> dfs(graph G, int node)
{
	int vertices = G.vertices;
	vector<vector<int>> edges = G.edges;
	vector<vector<pair<int, double>>> weightedEdges = G.weightedEdges;
	int flag = G.flag;
	if(node > vertices)
	{
		cout << "ERROR: Invalid labelled node\n";
		exit(1);
	}
	vector<int> vis(vertices+1, 0);
	vector<int> res;
	if(G.flag==0) unweightedDfs(node, edges, vis, res);
	else if(G.flag==1) weightedDfs(node, weightedEdges, vis, res);
	else
	{
		cout << "ERROR: Graph not yet initialized";
		exit(1);
	}
	return res;
}

vector<int> bfs(graph G, int node)
{
	int vertices = G.vertices;
	vector<vector<int>> edges = G.edges;
	vector<vector<pair<int, double>>> weightedEdges = G.weightedEdges;
	int flag = G.flag;
	if(node > vertices)
	{
		cout << "ERROR: Invalid labelled node\n";
		exit(1);
	}
	vector<int> vis(vertices+1, 0);
	vector<int> res;
	if(flag==0) unweightedBfs(node, edges, vis, res);
	else if(flag==1)weightedBfs(node, weightedEdges, vis, res);
	else
	{
		cout << "ERROR: Graph not yet initialized";
		exit(1);
	}
	return res;
}

void shortest_path_func(graph G, int n, int m, vector<int>& path, double& value)
{
	int vertices = G.vertices;
	int flag = G.flag;
	vector<vector<pair<int, double>>> weightedEdges = G.weightedEdges;
	if(n > vertices || m > vertices)
	{
		cout << "Invalid labelled node\n";
		exit(1);
	}
	if(flag==0)
	{
		cout << "Not a weighted graph\n";
		exit(1);
	}
	priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>> > pq;
	vector<double> dist (vertices+1, 1e9), parent(vertices+1);
	for(int i=1; i<vertices; i++) parent[i]=i;
	dist[n]=0;
	pq.push({0,n});
	while(!pq.empty())
	{
		auto it = pq.top();
		int node = it.second;
		double dis = it.first;
		pq.pop();
		for(auto it: weightedEdges[node])
		{
			int adjNode = it.first;
			double edW = it.second;
			if(dis+edW<dist[adjNode])
			{
				dist[adjNode] = dis+edW;
				pq.push({dis+edW, adjNode});
				parent[adjNode] = node;
			}
		}
	}
	if(dist[m]==1e9)
	{
		path = {};
		value = -1;
		return;
	}
	value = dist[m];
	int node = m;
	while(parent[node]!=node)
	{
		path.push_back(node);
		node = parent[node];
	}
	path.push_back(n);
	reverse(path.begin(), path.end());
	return;
}

double shortest_path_value(graph G, int n, int m)
{
	int vertices = G.vertices;
	vector<vector<pair<int, double>>> weightedEdges = G.weightedEdges;
	vector<int> path;
	double value;
	shortest_path_func(G,n,m,path,value);
	return value;
}

vector<int> shortest_path(graph G, int n, int m)
{
	int vertices = G.vertices;
	vector<vector<pair<int, double>>> weightedEdges = G.weightedEdges;
	vector<int> path;
	double value;
	shortest_path_func(G,n,m,path,value);
	return path;
}

class matrix
{
public:
	int rows;
	int cols;
	vector<vector<double>> vals;

	matrix(int r, int c)
	{
		rows = r;
		cols = c;
		vals.resize(rows+1, vector<double>(cols+1, 0));
	}

	int getRows()
	{
		return rows;
	}

	int getCols()
	{
		return cols;
	}

	int addValue(int rowNumber, int colNumber, double value)
	{
		if(rowNumber>=rows || colNumber>=cols)
		{
			cout << "ERROR: Row or col Number exceeding the matrix dimensions\n";
			exit(1);
		}
		vals[rowNumber][colNumber] = value;
		return 1;
	}

	double getValue(int rowNumber, int colNumber)
	{
		if(rowNumber>=rows || colNumber>=cols)
		{
			cout << "ERROR: Row or col Number exceeding the matrix dimensions\n";
			exit(1);
		}
		return vals[rowNumber][colNumber];
	}

	
	void printMatrix()
	{
		for(int i=0; i<rows; i++)
		{
			cout << "[\t";
			for(int j=0; j<cols; j++)
			{
				cout << vals[i][j] << "\t";
			}
			cout << "]\n";
		}
	}

};

typedef class matrix matrix;

double trace(matrix M)
{
	if(M.rows!=M.cols)
	{
		cout << "ERROR: Trace is defined only for square matrices\n";
	}
	double sum =0;
	for(int i=0; i<M.rows; i++)
	{
		sum+=M.vals[i][i];
	}
	return sum;
}


matrix transpose(matrix M)
{
	matrix* res = new matrix(M.cols, M.rows);
	for(int i=0; i<M.rows; i++)
	{
		for(int j=0; j<M.cols; j++)
		{
			res->addValue(j, i, M.vals[i][j]);
		}
	}
	return *res;
}

matrix GtM(graph G)
{
	int vertices = G.getVertices();
	vector<vector<int>> edges = G.getEdges();
	matrix res(vertices, vertices);
	for(int i=0; i<vertices; i++)
	{
		for(int j=0; j<vertices; j++)
		{
			res.addValue(i,j,0);
		}
	}
	for(int i=1; i<=vertices; i++)
	{
		for(int j=0; j<edges[i].size(); j++)
		{
			res.addValue(i-1, edges[i][j]-1, 1);
		}
	}
	return res;
}

matrix wGtM(graph G)
{
	int vertices = G.getVertices();
	vector<vector<pair<int, double>>> weightedEdges = G.getWeightedEdges();
	matrix res(vertices, vertices);
	for(int i=0; i<vertices; i++)
	{
		for(int j=0; j<vertices; j++)
		{
			res.addValue(i,j,0);
		}
	}
	for(int i=1; i<=vertices; i++)
	{
		for(int j=0; j<weightedEdges[i].size(); j++)
		{
			double weight = weightedEdges[i][j].second;
			res.addValue(i-1, weightedEdges[i][j].first-1, weight);
		}
	}
	return res;
}

matrix graph_to_matx(graph G)
{
	int flag = G.getFlag();
	if(flag==0) return GtM(G);
	else if(flag==1)return wGtM(G);
	else
	{
		cout << "Graph is not initialised yet\n";
		exit(1);
	}
}

graph matx_to_graph(matrix M)
{
	int rows = M.getRows();
	int cols = M.getCols();
	if(rows!=cols)
	{
		cout << "ERROR: Conversion possible only for square matrices\n";
		exit(1);
	}
	graph res(rows);
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			double x = M.getValue(i,j);
			if(x<0)
			{
				cout << "ERROR: Edge weight should be non-negative\n";
				exit(1);
			}
			res.setFlag(1);
			res.addWeightedEdge(i+1, j+1, x);
		}
	}
	return res;
}

matrix add_matx(matrix A, matrix B)
{
	int rows = A.getRows();
	int cols = A.getCols();
	// Check if dimensions of both of them are matching.
	// If not return an error
	if(rows != B.getRows() || cols != B.getCols())
	{
		cout << "ERROR: Dimensions of the matrices do not match\n";
		exit(1);
	}

	// Make new matrix res
	matrix res(rows, cols);

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			res.addValue(i, j, A.getValue(i,j)+B.getValue(i,j));
		}
	}
	return res;
}

matrix sub_matx(matrix A, matrix B)
{
	int rows = A.getRows();
	int cols = A.getCols();

	if(rows != B.getRows() || cols != B.getCols())
	{
		cout << "ERROR: Dimensions of the matrices do not match\n";
		exit(1);
	}

	matrix res(rows, cols);

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			res.addValue(i, j, A.getValue(i,j)-B.getValue(i,j));
		}
	}
	return res;
}

matrix mult_matx(matrix A, matrix B)
{
	int cols_A = A.getCols();
	int rows_B = B.getRows();

	if(cols_A != rows_B)
	{
		cout << "ERROR: Given matrices cannot undergo matrix multiplication\n";
		exit(1);
	}

	int rows_A = A.getRows();
	int cols_B = B.getCols();

	matrix res(rows_A, cols_B);

	for(int i=0; i<rows_A; i++)
	{
		for(int j=0; j<cols_B; j++)
		{
			double prod = 0;

			for(int k=0; k<rows_B; k++)
			{
				prod += A.getValue(i, k)*B.getValue(k, j);
			}
			
			res.addValue(i, j, prod);
		}
	}
	return res;
}

string strjoin(string str1, string str2)
{
	string result = str1 + str2;
	return result;
}

int strcmpr(string str1, string str2)
{
	int l1 = str1.size();
	int l2 = str2.size();
	if(l1!=l2) return 1;
	for(int i=0; i<l1; i++)
	{
		if(str1[i]!=str2[i]) return 1;
	}
	return 0;
}
