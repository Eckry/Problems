#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> a;
bool check(ll n, ll k){
	ll cnt = 0;
	ll num = 0;
	vector<ll> seen(n + 1, 0);
	for(int i = 0 ;i < a.size();i++){
		if(a[i] > n || a[i] < num) continue;
		seen[a[i]] = 1;
		while(num != n && seen[num]) {
			seen[num] = 0;
			num++;
		}
		if(num == n) {
			num = 0;
			cnt++;
		}
		if(cnt == k) return 1;
	}	
	return 0;
}

void solve(){
	ll n, k; cin >> n >> k;

	a = vector<ll>(n);
	for(auto &c : a) cin >> c;

	ll l = 1;
	ll r = n;

	while(l <= r) {
		ll m = l + (r - l) / 2;
		if(!check(m, k)){
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << r << "\n";
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}
