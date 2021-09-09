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
	
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		vector< ll > even, odd;
		for(int i = 0 ; i < n ; i++)
			if(a[i]%2)
				odd.pb(a[i]);
			else
				even.pb(a[i]);
		sort(odd.begin(), odd.end(), greater< ll > ());
		for(int i = 0 ; i < even.size() ; i++)
			a[i] = even[i];
		for(int i = even.size() ; i < n ; i++)
			a[i] = odd[i-even.size()];
		ll ans = 0;
		for(int i = 0 ; i < n ; i++)
			for(int j = i+1 ; j < n ; j++)
				if(gcd(a[i], 2*a[j]) > 1)
					ans++;
		cout << ans << endl;

	}
	return(0);
}