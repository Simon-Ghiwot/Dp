// https://codeforces.com/problemset/problem/1741/E
#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const char ln = '\n';
 
int n, m, k, q, d;
string s, t;

void run_test_case(){
	cin >> n;
	vector<int> v(n);
	vector<bool> dp(n + 1);

	dp[0] = true;
	for(int i = 0; i < n; i++)	cin >> v[i];

	for(int i = 1; i <= n; i++){
		if(dp[i - 1] and i + v[i - 1] <= n)	dp[i + v[i - 1]] = true;

		if(i - v[i - 1] - 1 >= 0 and dp[i - v[i - 1] - 1]) dp[i] = true;
	}
	cout << (dp[n] ? "YES" : "NO") << ln;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 1;
	cin >> test;
	while(test--){
		run_test_case();
	}	
}
