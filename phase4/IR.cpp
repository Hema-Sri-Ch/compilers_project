#include <bits/stdc++.h>
#include "improvisations.h"
using namespace std;

struct type1 {
	graph grp{5};
	matrix mat{4, 4};
};
int main ()
	{
		struct type1 a, b, c;
		a.mat.vals = {{1,2,3,4},{1,1,1,1},{2,3,1,4},{9,1,0,0}};
		a.grp.addWeightedEdge(1, 2, 10);
		a.grp.addWeightedEdge(1, 5, 1);
		a.grp.addWeightedEdge(5, 4, 11);
		a.grp.addWeightedEdge(2, 5, 2);
		a.grp.addWeightedEdge(2, 3, 6);
		a.grp.addWeightedEdge(3, 4, 0);
		a.grp.setFlag(1);

		int v;
		v = shortest_path_value(a.grp,1,4);

		cout << v << endl;
		return 0;
	}
