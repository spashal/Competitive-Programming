#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, k, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; if( a[i] % k > 0 ) v.push_back(k - a[i] % k); }
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		vector< ll > v, p;
		cin >> n >> k;
		queue< ll > q;
		ll x = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> m;
			if( (m % k) != 0 )
				v.push_back(k - m % k);
			// if( !v.empty())
			// cout << v.back() << " ";
		}
		sort(v.begin(), v.end());
		for(int i = 0 ; i < v.size() ; i++){
			if( i > 0 and v[i] % k == v[i - 1] % k ){
				v[i] = v[i - 1] + k;

			}
			p.push_back(v[i]);
		}
		sort(p.begin(), p.end());
		for(int i = 0 ; i < p.size() ; i++)
			q.push(p[i]);
		while( !q.empty() ){
				ll temp = x;
				x = q.front();
				q.pop();
				x++;
		}
		cout << x << endl;
	}
	return(0);
}