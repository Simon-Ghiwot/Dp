https://cses.fi/problemset/task/1633/
#include<bits/stdc++.h>

#define ll long long

using namespace std;

const char ln = '\n';

int n, m, k, q, d;
string s, t;

const int mod = 1e9 + 7;

void run_test_case(){
	cin >> n;
	vector<ll> dp(n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int dice = 1; dice <= 6; dice++)
			if(i - dice >= 0)
				dp[i] = (dp[i] % mod + dp[i - dice] % mod) % mod;
	cout << dp[n] << ln;
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


