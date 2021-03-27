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
		string s;
		cin >> n >> m >> s;
		bool true1 = false, true2 = false;
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i] == 'R' and n > 0 )
				n--;
			else if(s[i] == 'U' and m > 0)
				m--;
			else if(s[i] == 'L' and n < 0 )
				n++;
			else if(s[i] == 'D' and m < 0)
				m++;
		if(n == 0 and m == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return(0);
}