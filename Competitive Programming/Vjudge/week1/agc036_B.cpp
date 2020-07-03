#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, k, a[200005];
bool inc[200005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> n >> k;
	ari;
	deque< ll > dq;
	for(int i = 0 ; i < n ; i++)
		if( !inc[a[i]] ){
			inc[a[i]] = true;
			dq.push_back(a[i]);
		}
		else{
			while( dq.back() != a[i] ){
				inc[dq.back()] = false;
				dq.pop_back();
			}
			inc[a[i]] = false;
			dq.pop_back();
		}
	vector< ll > s;
	while( !dq.empty() ){
		s.push_back(dq.back());
		dq.pop_back();
	}
	for(int i = 0 ; i <= (k - 1) % (int)s.size() ; i++)
		cout << s[i] << " ";
	cout << endl;
	return(0);
}