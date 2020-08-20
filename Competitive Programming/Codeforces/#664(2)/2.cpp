#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, vis[101][101], x, y;
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

void fun(int a, int b){
	if( !vis[a][b] )
		cout << a << " " << b << endl;
	vis[a][b] = true;
	ll k = -1, ctr = 0;
	for(int i = 1 ; i <= m ; i++)
		if( !vis[a][i] ){
			if( !ctr and a < n and !vis[a + 1][i] ){
				k = i;
				ctr++;
				continue;
			}
			cout << a << " " << i << endl;
		}
	if( k > 0 ){
		cout << a << " " << k << endl;
		fun(a + 1, k);
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> x >> y;
    if( x != 1 and y != 1 ){
		cout << x << " " << y << endl;
		vis[x][y] = true;    	
    	cout << "1" << " " << y << endl;
    	vis[1][y] = true;
    	fun(1, 1);
    }
    else if( x == 1 ){
   		cout << x << " " << y << endl;
		vis[x][y] = true; 
    	fun(1, 1);
    }
    else if( y == 1 ){
		cout << x << " " << y << endl;
		vis[x][y] = true;     	
		fun(1, 1);
    }
    else
    	fun(1, 1);
    return(0);
}