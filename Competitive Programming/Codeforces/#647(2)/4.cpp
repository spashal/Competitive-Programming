#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll t, n, m, a[500005], b[500005];
pair< int, int> p;
vector< int > ans;
vector< int > adj[500005];
priority_queue< pair< int, int> , vector< pair< int, int>  >, greater< pair< int, int> > > pq;

int main(){
	cin >> n >> m;
	for( int i = 0 ; i < m ; i++ ){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
		pq.push( make_pair( a[i], i));
	}
	int z = 0;
	while( !pq.empty() ){
		vector< int > temp;
		p = pq.top();
		pq.pop();
		for( int i = 0 ; i < adj[p.second].size() ; i++ ){
			if( b[adj[p.second][i]] > 0 )
				temp.push_back( b[adj[p.second][i]]);
		}
		if( !temp.empty()){
			sort( temp.begin(), temp.end());
			b[p.second] = 1;
			for( int i = 0 ; i < temp.size() ; i++ )
				if( temp[i] == b[p.second] )
					b[p.second] += 1;
		}
		else
			b[p.second] = 1;
		ans.push_back(p.second);
	}
	for( int i = 1 ; i <= n ; i++ ){
		if( a[i] != b[i] )
			z = 1;
	}
	if( z == 1 )
		cout << "-1" << endl;
	else{
		for( int i = 0 ; i < n ; i++ )
			cout << ans[i] << " ";
		cout << endl;
	}
	return(0);
}