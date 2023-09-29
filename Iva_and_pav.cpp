// https://codeforces.com/contest/1878/problem/E
#include<bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
const char ln = '\n';
 
ll n, m, k, q, d; 
string s, t;

void run_test_case(){
	cin >> n;
	vector<int> v(n);
	vector<vector<int>> zeros(31);
	for(int i = 0; i < n; i++)	cin >> v[i];

	for(int bit = 30; bit > -1; --bit){
		for(int i = 0; i < n; i++)	if((v[i] & (1 << bit)) == 0){
			zeros[bit].push_back(i + 1);
		}
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> m >> k;
		int ans = -1;
		vector<array<int, 2>> values;
		for(int i = 30; i > -1; --i){
			int idx = lower_bound(zeros[i].begin(), zeros[i].end(), m) - zeros[i].begin();
			int size = zeros[i].size();

			int cur = ((idx < size and zeros[i][idx] > m) or idx == size ) ? (1 << i) : 0;
			int val = (idx == size ? n : zeros[i][idx] - 1);

			if(cur == 0)	continue;
			
			if(cur >= k)	ans = max(ans, val);
			else	values.push_back({val, cur});
		}
		sort(values.begin(), values.end());
		reverse(values.begin(), values.end());
		int cur_sum = 0, min_idx = 1e9;
		
		for(auto [f, s] : values){
			cur_sum += s;
			min_idx = min(min_idx, f);
			if(cur_sum >= k)	break;
		}
		if(cur_sum >= k)	ans = max(ans, min_idx);
		cout << ans << " ";
	}
	cout << ln;
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
