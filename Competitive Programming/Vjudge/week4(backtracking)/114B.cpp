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
vector< string > s;
map< pair< string, string >, bool > geton;
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

vector< string > best(int i, vector< string > r){
	bool flag = false;
	for(int j = 0 ; j < r.size() ; j++){
		if( geton[mp(s[i], r[j])] )
			flag = true;
	}
	vector< string > temp;
	temp = r;
	if( i == n - 1 ){
		temp.pb(s[i]);
		if( flag )
			return r;
		else
			return temp;
	}
	if( !flag ){
		r.push_back(s[i]);
		vector< string > a = best(i + 1, r);
		vector< string > b = best(i + 1, temp);
		if( a.size() > b.size() )
			return a;
		return b;
	}
	return best(i + 1, temp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
   	s.resize(n);
    for(int i = 0 ; i < n ; i++)
    	cin >> s[i];
    for(int i = 0 ; i < m ; i++){
    	string a, b;
    	cin >> a >> b;
    	geton[mp(a, b)] = true;
    	geton[mp(b, a)] = true;
    }
    vector< string > k;
    k = best(0, k);
    sort(k.begin(), k.end());
    cout << k.size() << endl;
    for(int i = 0 ; i < k.size() ; i++)
    	cout << k[i] << endl;
	return(0);
}