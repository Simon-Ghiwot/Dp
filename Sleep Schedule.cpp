// https://codeforces.com/contest/1324/problem/E
#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const char ln = '\n';
 
ll n, m, k, q, d; 
string s, t;

const int N = 2e3 + 500;
ll dp[N][N];
int v[N];

void run_test_case(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dp[i][j] = -1e9;
	cin >> n >> m >> k >> q;
	for(int i = 0; i < n; i++)	cin >> v[i];

	// this is a push dp 
	// the next state in the left side of the equality and the old one is on the right
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int hour = 0; hour < m; hour++){
			int whole = (hour + v[i]) % m;
			int one_less = (hour + v[i] - 1) % m;
			
			dp[i + 1][whole] = max(dp[i + 1][whole], dp[i][hour] + (k <= whole and whole <= q));
			dp[i + 1][one_less] = max(dp[i + 1][one_less], dp[i][hour] + (k <= one_less and one_less <= q));

		}
	}
	cout << *max_element(dp[n], dp[n] + m) << ln;
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
