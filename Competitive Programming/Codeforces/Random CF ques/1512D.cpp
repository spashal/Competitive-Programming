#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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
		n += 2;
		ari;
		ll sum = 0;
		map< ll, ll > index;
		for(int i = 0 ; i < n ; i++){
			sum += a[i];
			index[a[i]] = i + 1;
		}
		ll ind1 = -1, ind2 = -1;
		for(int i = 0 ; i < n ; i++){
			if( (sum - a[i]) % 2 == 0 and index[(sum - a[i])/2] and index[(sum - a[i])/2] != i + 1 ){
				ind1 = i;
				ind2 = index[(sum - a[i])/2] - 1;
				break;
			}
		}
		if(ind1 != -1){
			for(int i = 0 ; i < n ; i++)
				if( i != ind1 and i != ind2)
					cout << a[i] << " ";
			cout << endl;
		}
		else
			cout << "-1\n";
	}
	return(0);
}