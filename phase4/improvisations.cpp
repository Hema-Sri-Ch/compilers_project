# include <bits/stdc++.h>
using namespace std;

string strjoin(string str1, string str2){
	string result = str1 + str2;
	return result;
}

int main(){
	string str1 = "Hello, ";
	string str2 = "World!\n";
	
	string str3 = strjoin(str1, str2);
	cout << str3 << endl;
}
