# include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res)
{
	vis[node]=1;
	res.push_back(node);
	for(auto it: adj[node])
	{
		if(!vis[it])
			dfs(it, adj, vis, res);
	}
	return;
}

void weightedDfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<int>& res)
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

void bfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res)
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

void weightedBfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<int>& res)
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
	int vertices;
	vector<vector<int>> edges;
	vector<vector<pair<int, int>>> weightedEdges;
	int flag; // To tell whether it is weighted or unweighted

public:

	graph(int n)
	{
		vertices = n;
		edges.resize(n+1, vector<int>(10));
		weightedEdges.resize(n+1, vector<pair<int,int>>(10) );
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

	int addEdge(int u, int v)
	{
		if(u>vertices || v> vertices)
		{
			return 0;
		}
		edges[u].push_back(v);
		return 1;
	}

	int addWeightedEdge(int u, int v, int weight)
	{
		if(u>vertices || v> vertices)
		{
			return 0;
		}
		weightedEdges[u].push_back({v,weight});
		return 1;
	}

	vector<int> getDfs(int node)
	{
		if(node > vertices)
		{
			cout << "ERROR: Invalid labelled node\n";
			exit(1);
		}
		vector<int> vis(vertices+1, 0);
		vector<int> res;
		if(flag==0) dfs(node, edges, vis, res);
		else weightedDfs(node, weightedEdges, vis, res);
		return res;
	}

	vector<int> getBfs(int node)
	{
		if(node > vertices)
		{
			cout << "ERROR: Invalid labelled node\n";
			exit(1);
		}
		vector<int> vis(vertices+1, 0);
		vector<int> res;
		if(flag==0) bfs(node, edges, vis, res);
		else weightedBfs(node, weightedEdges, vis, res);
		return res;
	}

	// vector<int> shortest_path(int n, int m)
	// {
	// 	if(n > vertices || m > vertices)
	// 	{
	// 		cout << "Invalid labelled node\n";
	// 		exit(1);
	// 	}
	// 	if(flag==0)
	// 	{
	// 		cout << "Not a weighted graph\n";
	// 		exit(1);
	// 	}
	// }

};

class matrix
{
	int rows;
	int cols;
	vector<vector<double>> vals;

public:
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
		return vals[rowNumber][colNumber];
	}

	matrix transpose()
	{
		matrix* res = new matrix(cols, rows);
		for(int i=0; i<rows; i++)
		{
			for(int j=0; j<cols; j++)
			{
				res->addValue(j, i, vals[i][j]);
			}
		}
		return *res;
	}

	double trace()
	{
		if(rows!=cols)
		{
			cout << "ERROR: Trace is defined only for square matrices\n";
		}
		double sum =0;
		for(int i=0; i<rows; i++)
		{
			sum+=vals[i][i];
		}
		return sum;
	}
};

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


int main()
{
	string str1 = "Hello, ";
	string str2 = "World!\n";
	
	string str3 = strjoin(str1, str2);
	cout << str3 << endl;
}
