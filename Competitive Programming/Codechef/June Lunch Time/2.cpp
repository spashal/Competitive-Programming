#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector< ll > q, one, two;
ll n, m, t, ctr, a[200005], s[200005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ){ cin >> a[i]; s[a[i]]++; if( s[a[i]] == 1 ) one.push_back(a[i]); else if( s[a[i]] == 2 ) two.push_back(a[i]); if(s[a[i]] > 2 ) ctr = 1; q.push_back(a[i]);}
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		ctr = 0;
		cin >> n;
		ari;
		for(int i = 0 ; i < n ; i++){
			s[q.back()] = 0;
			q.pop_back();
		}
		sort(one.begin(), one.end());
		sort(two.begin(), two.end(), greater< ll > ());
		if( ctr or ( !two.empty() and one.back() == two[0] ) ) 
			cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i = 0 ; i < one.size() ; i++)
				cout << one[i] << " ";
			for(int i = 0 ; i < two.size() ; i++)
				cout << two[i] << " ";
			cout << endl;
		}
		one.clear();
		two.clear();
	}
	return(0);
}