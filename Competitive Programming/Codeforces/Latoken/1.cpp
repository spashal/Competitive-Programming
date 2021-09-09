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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n  >> m;
		vector< string > inp(n);
		for(int i = 0 ; i < n ; i++)
			cin >> inp[i];
		bool reven = false, rodd = false, weven = false, wodd = false;
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++){
				if(inp[i][j] == 'R' and (i+j)%2 == 0)
					reven = true;
				else if(inp[i][j] == 'R' and (i+j)%2 == 1)
					rodd = true;
				else if(inp[i][j] == 'W' and (i+j)%2 == 0)
					weven = true;
				else if(inp[i][j] == 'W')
					wodd = true;
			}
		if((reven and wodd and !rodd and !weven) or 
			(!reven and !wodd and !rodd and !weven) or
			(reven and !wodd and !rodd and !weven) or
			(!reven and wodd and !rodd and !weven)){
			cout << "YES\n";
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++)
					if((i+j)%2)
						cout << "W";
					else
						cout << "R";
				cout << endl;
			}

		}
		else if((!reven and !wodd and rodd and weven) or 
			(!reven and !wodd and rodd and !weven) or
			(!reven and !wodd and !rodd and weven)){
			cout << "YES\n";
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++)
					if((i+j)%2==0)
						cout << "W";
					else
						cout << "R";
				cout << endl;
			}
		}
		else
			cout << "NO\n";
	}
	return(0);
}