#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// ll n, m, t, a[200005];
// vector< ll > adj[100005];
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
    ll q, n;
    cin >> n >> q;
    set<int> s;
    for(int i = 0 ; i < n ; i++){
    	int temp;
    	cin >> temp;
    	s.insert(temp);
    }
    for(int i = 0 ; i < q ; i++){
    	int temp;
    	cin >> temp;
    	set<int>::iterator it = s.lower_bound(temp);
    	if(it != s.end() and *it == temp){
    		cout << "0\n";
    		continue;
    	}
    	else if(distance(it, s.end())%2 == 0)
    		cout << "POSITIVE\n";
    	else	
    		cout << "NEGATIVE\n";
    }
	return(0);
}