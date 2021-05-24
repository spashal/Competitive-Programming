#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}	

ll po(int i){
	ll ans = 1;
	for(int j = 0 ; j < i ; j++)
		ans *= 10;
	return ans;
}

ll cmp(string s1, string s2){
	ll ans = 0;
	for(int i = 0 ; i < s1.size() ; i++){
		ans += s1[i] - s2[i];
		ans *= 10;
	}
	return llabs(ans/10);
}

ll fun(string cur, string s){
	cout << cur << " * " << s << endl;
	if(cur < s)
		return 0;
	ll ans = 1e18;
	string tempcur, temps;
	for(int i = 0 ; i < min(cur.size(), s.size()) ; i++){
		temps.pb(s[i]);
		tempcur.pb(cur[i]);
		if(tempcur[i] + 1 < temps[i]){
			ll temp = 0;
			for(int j = i + 1 ; j < s.size() ; j++){
				temp += s[j] - '0';
				temp *= 10;
			}
			string s1 = to_string(temp/10);
			ans = min(ans, fun(temps, s1) + po(s.size())*abs(temps[i] - tempcur[i]));
			continue;
		}
		if(temps == tempcur)
			continue;
		if(tempcur[i] - temps[i] > 1 )
			break;
		ll temp = 0;
		for(int j = i + 1 ; j < s.size() ; j++){
			temp += s[j] - '0';
			temp *= 10;
		}
		string s1 = to_string(temp/10);
		ans = min(ans, fun(temps ,s1) + po(s.size()-i-1)*abs(cmp(tempcur, temps)));
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int i = 1 ; i <= t ; i++){
		cin >> n;
		n++;
		string sn = to_string(n);
		ll nlen = sn.size(), ans = 0;
		for(int j = 0 ; j < nlen ; j++){
			ll cur = n/(po(nlen-j-1));
			string scur = to_string(cur);
			string neW = to_string(n%(po(nlen-j-1)));
			ans = min(ans, fun(scur, neW));
		}
		cout << "Case #" << i << ": " << ans + n << endl;
	}	
	return(0);
}