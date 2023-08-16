//https://codeforces.com/contest/1195/problem/C
#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const char ln = '\n';
 
int n, m, k, q, d;
string s, t;

const int N = 1e5 + 500;
ll v[N][2], dp[N][2];

void run_test_case(){
	cin >> n;
	for(int i = 0; i < n; i++)	cin >> v[i][0];
	for(int i = 0; i < n; i++)	cin >> v[i][1];

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			ll max_ = dp[i - 1][j];
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j ^ 1] + v[i - 1][1 ^ j]);
		}
	}
	cout << max(dp[n][1], dp[n][0]) << ln;
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
