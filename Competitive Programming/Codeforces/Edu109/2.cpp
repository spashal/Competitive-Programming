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
		cin >> n;
		vector< int > inp1(n, 0), inp2;
		for(int i = 0 ; i < n ; i++){
			int aa;
			cin >> inp1[i];
		}
		inp2 = inp1;
		sort(inp2.begin(), inp2.end());
		if(inp2 == inp1)
			cout << "0" << endl;
		else if(inp1[0] == inp2[0] or inp1[n-1] == inp2[n-1])
			cout << "1" << endl;
		else if(inp1[0] == inp2[n-1] and inp1[n-1] == inp2[0])
			cout << "3" << endl;
		else
			cout << "2" << endl;
	}
	return(0);
}