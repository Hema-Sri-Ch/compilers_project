#include <bits/stdc++.h>
#include "improvisations.h"
using namespace std;

struct myStructA {
	int itemA;
	vector<int> itemB;
};
struct myStructB {
	int itemC;
	struct myStructA itemD;
};
class myClassA {
public:	int itemE;
	struct myStructB itemF;
	int factorial ( int k )
		{
			int ans, num;
			num = itemE;
			ans = k;
			while(num--)
			{
				ans = (ans*num);
			}

			return k;
		}

};
class myClassB {
public:	int itemG;
	class myClassA itemH;
	int nCr ( int n, int r )
		{
			if((r>n))
			{
				return -1;
			}

			int a, b;
			a = itemH.factorial(n);
			b = (itemH.factorial((n-r))*itemH.factorial(r));
			return (a/b);
		}

	vector<int> getCoeffs ( int n )
		{
			vector<int> ans;
			return {1};
		}

	void printPyramid ()
		{
			return ;
		}

};
int main ()
	{
		return 0;
	}
