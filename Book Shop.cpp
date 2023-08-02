// https://cses.fi/problemset/task/1158/
#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const char ln = '\n';
 
int n, m, k, q, d;
string s, t;
 
const int N = 1e3 + 100;
const int M = 1e5 + 100;
 
int dp[N][M];
 
void run_test_case(){
	cin >> n >> m;
	vector<int> price(n), pages(n);
	for(int i = 0; i < n; i++)	cin >> price[i];
	for(int i = 0; i < n; i++)	cin >> pages[i];
 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i - 1][j];
			ll cur = j - price[i - 1];
			if(cur >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
			}
		}
	}
	cout << dp[n][m] << ln;
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
