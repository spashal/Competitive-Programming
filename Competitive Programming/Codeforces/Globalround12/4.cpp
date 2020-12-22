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
vector< ll > inp;
bool pos[300005];
ll presence[300005];
	
void fun(ll l, ll r, ll num){
	ll look = n - num + 1;
	if( presence[look] == 0 )
		pos[num] = false;	
	else if( inp[l] == look ){
		pos[num] = true;
		if( l + 1 <= r and num > 1 )
			fun(l + 1, r, num - 1);
	}
	else if( inp[r] == look ){
		pos[num] = true;
		if( l <= r - 1 and num > 1 )
			fun(l, r - 1, num - 1);
	}
	else if( presence[look] )
		pos[num] = true;
	else
		pos[num] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		inp.resize(n, 0);
		for(int i = 1 ; i <= n ; i++){
			pos[i] = false;		
			presence[i] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> inp[i];
			presence[inp[i]]++;
		}
		for(int i = 1 ; i <= n ; i++)
			if( presence[i] > 1 ){
				for(i++; i <= n ; i++){
					presence[i] = 0;
					break;
				}
			}
		if( inp[0] == 1 )
			fun(1, n - 1, n - 1);
		else if( inp[n - 1] == 1 )
			fun(0, n - 2, n - 1);
		for(int i = 0 ; i < n ; i++)
			if( inp[i] == 1 )
				pos[n] = true;
		sort(inp.begin(), inp.end());
		pos[1] = true;
		for(int i = 0 ; i < n ; i++)
			if( inp[i] != i + 1 ){
				pos[1] = false;
				break;
			}
		for(int i = 1 ; i <= n ; i++)
			cout << pos[i];
		cout << endl;
		inp.clear();
	}
	return(0);
}