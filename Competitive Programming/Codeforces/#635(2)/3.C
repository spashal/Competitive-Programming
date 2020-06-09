#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll bhai[200005] , level[200005] , parent[200005] , ans = 0 , n , k ;
ll bhaw[200005] ;
vector< ll > adj[200005] ;
queue< ll > q ;
vector< ll > formation ;
vector< ll > vec ;
bool included[200005] , inform[200005] , vis[200005] ;
bool yosort( ll a , ll b ){
	return bhaw[a] > bhaw[b] ;
}
bool yoyosort( ll a , ll b ){
	return level[a] > level[b] ;
}
void bfs(){
	level[1] = 0 ;
	vis[1] = 1 ;
	q.push(1) ;
	bhaw[1] = 0 ;
	while( !q.empty() ){
		int a = q.front() ;
		q.pop() ;
		for( ll i = 0 ; i < adj[a].size() ; i++ ){
			if( !vis[adj[a][i]] ){
				vis[adj[a][i]] = 1 ;
				level[adj[a][i]] = level[a] + 1 ;
				bhaw[adj[a][i]] = level[adj[a][i]] ;
				q.push( adj[a][i] ) ;
				parent[adj[a][i]] = a ;
				inform[a] = 1 ;
				formation.push_back( adj[a][i] ) ;
			}
		}
	}
}

void ulta_bfs(){
	int i = 0 ;
	while( ++i <= n )
		vec.push_back(i) ;
	sort( vec.begin() , vec.end() , yoyosort ) ;
	for( i = 0 ; i < n ; i++ )
		bhaw[parent[vec[i]]] -= ( level[vec[i]] - bhaw[vec[i]] + 1 ) ;
}

int main(){
	cin >> n >> k ;
	for( ll i = 0 ; i < n - 1 ; i++ ){
		ll u , v ;
		cin >> u >> v ;
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;
	}
	bfs() ;
	ulta_bfs() ;
	ll h = k ;
	ll i = 0 ;
	parent[1] = 0 ;
	sort( formation.begin() , formation.end() , yosort ) ;	
	while( h-- ){
		bhai[ parent[ formation[i] ] ] += bhai[formation[i]] + 1 ;
		included[ formation[i] ] = 1 ;
		i++ ;
	}	
	for( ll i = 1 ; i <= n ; i++ )
		if( included[i] and !included[ parent[i] ] ){
			ans += level[i] * ( bhai[i] + 1 ) ;
		}
	// for( int i = 1 ; i <= n ; i++ )
		// cout << i << " " << level[i] << " " << bhaw[i] << " " << bhai[i] << " " << inform[i] << endl ;
	cout << ans << endl ;
	return(0) ;
}