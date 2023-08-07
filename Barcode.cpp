//https://codeforces.com/problemset/problem/225/C
#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const char ln = '\n';
 
int n, m, k, q, d;
string s, t;

void run_test_case(){
	int x, y;
	cin >> n >> m >> x >> y;
	vector<string> board(n);
	for(int i = 0; i < n; i++)	cin >> board[i];

	vector<array<int, 2>> pref = {{0, 0}};
	for(int i = 0; i < m; i++){
		int dot = 0;
		for(int j = 0; j < n; j++)
			dot += board[j][i] == '.';
		pref.push_back({pref.back()[0] + n - dot, pref.back()[1] + dot});
	}
	vector<vector<ll>> dp(m + 1, vector<ll>(2, 1e9));

	dp[0][0] = dp[0][1] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < 2; j++){
			for(int k = x; k <= y; k++){
				if(i - k < 0)	continue;
				ll cur = (pref[i][j] - pref[i - k][j]) + dp[i - k][1 ^ j];
				dp[i][j] = min(dp[i][j], cur);
			}
		}
	}
	cout << min(dp[m][0], dp[m][1]) << ln;
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
