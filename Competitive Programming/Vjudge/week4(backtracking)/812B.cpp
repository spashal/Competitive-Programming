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
string s[15];
bool leave[16];
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

int move(int x, int y){
	if( x == 0 ){
		if( y == 0 ){
			for(int i = m ; i > 0 ; i--)
				if( s[x][i] == '1' )
					return i;
			return 0;
		}
		else{
			for(int i = 1 ; i < m + 1 ; i++)
				if( s[x][i] == '1' )
					return m + 1 - i;
			return 0;
		}
	}
	ll cur = INT_MAX;
	ll next = -1;
	for(int i = x - 1 ; i >= 0 ; i--)
		if( !leave[i] )
			next = i;
	if( y == 0 ){
		if( next > -1 )
			cur = min(cur, move(x - 1, 1) + m + 2);
		ll temp = 0;
		for(int i = m ; i > 0 ; i--)
			if( s[x][i] == '1' ){
				temp = i;
				break;
			}
		if( next > -1 ){
			cur = min(cur, move(x - 1, 0) + 2 * temp + 1);
			return cur;
		}
		return temp;
	}
	if( next > -1 )
		cur = min(cur, move(x - 1, 0) + m + 2);
	ll temp = 0;
	for(int i = 1 ; i < m + 1 ; i++)
		if( s[x][i] == '1' ){
			temp = m + 1 - i;
			break;
		}
	if( next > -1 ){
		cur = min(cur, move(x - 1, 1) + 2 * temp + 1);
		return cur;
	}
	return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
    	cin >> s[i];
    	leave[i] = true;
    	for(int j = 1 ; j < m + 1 ; j++)
    		if( s[i][j] == '1' )
    			leave[i] = false;
    }
    cout << move(n - 1, 0) << endl;
	return(0);
}