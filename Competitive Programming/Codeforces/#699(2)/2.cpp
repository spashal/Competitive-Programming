#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, h[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> h[i];
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
		bool fell = false;
		ll ind = 0, yet = 0;
		while(!fell){
			if(n == 1)
				fell = true;
			for(int i = 0 ; i < n - 1 ; i++){
				if(h[i] < h[i + 1]){
					yet = i;
					h[i]++;
					break;
				}
				else if(i == n - 2 and h[i] >= h[i+1])
					fell = true;
			}
			if(fell)
				break;
			ind++;
			if(ind == m)
				break;

		}
		if(!fell)
			cout << yet + 1 << endl;
		else
			cout << "-1\n";
	}
	return(0);
}