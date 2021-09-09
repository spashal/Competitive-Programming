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
		vector< ll > val(n, 0);
		cin >> s;
		string last = s;
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				if(j == 0 and s[j] == '0' and j + 1 < n and s[j+1] == '1'){
					last[j] = '1';
				}
				else if(j > 0 and s[j] == '0'){
					if(j == n - 1 and s[j-1] == '1')
						last[j] = '1';
					else if(j < n - 1 and s[j-1] == '1' and s[j+1] == '0')
						last[j] = '1';
					else if(j < n - 1 and s[j-1] == '0' and s[j+1] == '1')
						last[j] = '1';
				}
			}
			if( last == s)
				break;
			s = last;
		}
		cout << s << endl;
	}
	return(0);
}