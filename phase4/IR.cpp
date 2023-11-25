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
	void Initialise ()
		{
			itemE = 16;
			itemF.itemC = 24;
			itemF.itemD.itemA = 32;
			itemF.itemD.itemB = {40, 48, 56, 64};
			return ;
		}

	int factorial ( int k )
		{
			if((k==0))
			{
				return 1;
			}

			int ans, num, i;
			num = k;
			ans = 1;
			for(			i = 1;(i<=k); i++ )
			{
				ans = (ans*i);
			}

			return ans;
		}

};
class myClassB {
public:	int itemG;
	class myClassA itemH;
	void Initialise ()
		{
			itemG = 8;
			itemH.Initialise();
			return ;
		}

	int nCr ( int n, int r )
		{
			if((r>n))
			{
				return 1;
			}

			if((r==0))
			{
				return 1;
			}

			if((r==n))
			{
				return 1;
			}

			int a, b;
			a = itemH.factorial(n);
			b = (itemH.factorial((n-r))*itemH.factorial(r));
			return (a/b);
		}

	vector<int> getCoeffs ( int n )
		{
			vector<int> ans;
			int i;
			i = 0;
			int temp;
			while((i<=n))
			{
				{vector<int> temp = ans;temp.push_back(nCr(n, i));ans = temp;}

				temp = nCr(n, i);
				cout << n << "C" << i << ": " << temp << endl;
				i++;
			}

			return ans;
		}

};
void printVec ( vector<int> myVec )
	{
		int i;
		int temp;
		for(		i = 0;(i<myVec.size()); i++ )
		{
			temp = myVec[i];
			cout << temp << endl;
		}

		return ;
	}
int main ()
	{
		class myClassB obj;
		int a;
		a = 1;
		labelA: 		{
			switch (a){
				case 1:
				{
					vector<int> myVec;
					int t;
					t = 6;
					myVec = obj.getCoeffs(t);
					cout << "coefficients of x in (1+x)^" << t << endl;
					printVec(myVec);
					break;

				}
				case 2:
				{
					int num;
					int t;
					t = 5;
					num = obj.itemH.factorial(t);
					cout << "Factorial of " << t << " = " << num << endl;
					break;

				}
				case 3:
				{
					obj.Initialise();
					cout << "Values of sub sub sub sub attributes:" << endl;
