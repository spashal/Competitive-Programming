#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005], b[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < n ; i++ ) cin >> b[i];
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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		ari;
		bri;
		vector< set<ll> > happy(n + 1), clrs(n + 1);
		vector< ll > ans(m, 0);
		set< ll > unsettled;		
		for(int i = 0 ; i < n ; i++){
			if(a[i] != b[i]){
				unsettled.insert(i);
				clrs[b[i]].insert(i);
			}
			else
				happy[a[i]].insert(i);
		}
		bool possible = true;
		ll painter;
		stack< ll > stk;
		for(int i = 0 ; i < m ; i++){
			cin >> painter;
			if(clrs[painter].size() == 0 and unsettled.empty() and happy[painter].size() == 0){
				stk.push(i);
			}
			else if(clrs[painter].size() == 0 and happy[painter].size() > 0){
				ans[i] = *happy[painter].begin();
				while(!stk.empty()){
					ans[stk.top()] = ans[i];
					stk.pop();
				}
			}
			else if(clrs[painter].size() == 0){
				ans[i] = *unsettled.begin();
			}
			else{
				ll removing = *clrs[painter].begin();
				unsettled.erase(removing);
				ans[i] = removing;
				happy[painter].insert(removing);
				clrs[painter].erase(*clrs[painter].begin());
				while(!stk.empty()){
					ans[stk.top()] = ans[i];
					stk.pop();
				}
			}
		}
		for(int i = 1 ; i <= n ; i++)
			if(clrs[i].size())
				stk.push(i);
		if(stk.empty()){
			cout << "YES\n";
			for(int i = 0 ; i < m ; i++)
				cout << ans[i] + 1 << " ";
			cout << endl;
		}
		else
			cout << "NO\n";
	}
	return(0);
}