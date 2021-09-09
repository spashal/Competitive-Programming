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
		map< string, string> variable;
		cin >> n;
		char c;
		cin.get(c);
		for(int i = 0 ; i < n ; i++){
			string s1, var1, var2, var3, s;
			string s2, s3, s4, s5;
			bool plus = false;
			cin >> s1;
			cin >> s2;
			cin >> s3;
			if(s2.size() == 1){
				cin >> s4 >> s5;
				plus = true;
			}
			if(plus)
				variable[s1] = variable[s3] + variable[s5];
			else
				variable[s1] = s3;
			if(i == n - 1){
				ll ans = 0;
				int size = variable[s1].size() - 4;
				for(int j = 0 ; j <= size ; j++){
					if(variable[s1].substr(j, 4) == "haha")
						ans++;
				}
				cout << ans << endl;
			}
		}
	}
	return(0);
}