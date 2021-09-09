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
		string s;
		cin >> s;

		// main logic is here
		ll a = 0;
		for(int i = 0 ; i < n ; i++)
			if(s[i] == 'a')
				a++;
		ll count = 0, ans = 0;
		ll w = 0, x = 0, y = 0, z = 0;
		if(a%3 == 0){
			for(int i = 0 ; i < n ; i++)
				if(s[i] == 'a'){
					if(count < a/3){
						w = i;
					}
					else if(count < (2*a)/3)
						y = i;
					count++;
				}
				else{
					if(count == (2*a/3))
						z = i;
					else if(count == a/3)
						x = i;
				}
			z = max(z, y);
			x = max(x, w);
			ans = (x-w+1)*(z-y+1);
			// cout << w << x << y << z << endl;;
			if(a == 0)
				ans = ((n-1)*(n-2))/2;
		}
		cout << ans << endl;

	}
	return(0);
}