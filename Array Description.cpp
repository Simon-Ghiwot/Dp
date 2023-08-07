// https://cses.fi/problemset/task/1746
#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const char ln = '\n';
 
int n, m, k, q, d;
string s, t;

const int N = 1e5 + 100;
const int M = 110;
const int mod = 1e9 + 7;

ll dp[N][M];

void run_test_case(){
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; i++)	cin >> v[i];

	if(v[0] == 0)
		for(int i = 1; i <= m; i++)
			dp[0][i] = 1;
	else
		dp[0][v[0]] = 1;

	for(int i = 1; i < n; i++){
	    if(v[i] == 0)
	        for(int j = 1; j <= m; j++)
	            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod + dp[i - 1][j + 1] % mod) % mod;
	    else
	        dp[i][v[i]] = (dp[i - 1][v[i] - 1] % mod + dp[i - 1][v[i]] % mod + dp[i - 1][v[i] + 1] % mod) % mod;

	}

	ll total = 0;
	for(int i = 0; i <= m; i++)
		total = (total + dp[n - 1][i]) % mod;
	cout << total << ln;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 1;
	// cin >> test;
	while(test--){
		run_test_case();
	}
}
