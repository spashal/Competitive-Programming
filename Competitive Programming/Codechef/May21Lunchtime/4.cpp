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
		cin >> n >> m;
		string s;
		cin >> s;
		int distance = 0;
		for(int i = 0 ; i < s.size() - 1 ; i++){
			if(s[i] == s[i+1])
				distance++;
			distance++;
		}
		for(int i = 0 ; i < m ; i++){
			int q;
			cin >> q;
			s[q-1] = ('1' - s[q-1]) + '0';
			if(q != n){
				if(s[q] == s[q-1])
					distance++;
				else
					distance--;
			}
			if(q > 1){
				if(s[q-1] == s[q-2])
					distance++;
				else
					distance--;
			}
			cout << distance << endl;
		}
	}
	return(0);
}