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
vector< ll > ctr(26, 0);
int cntr[26][26];


bool comp(pair<ll, ll>& lhs, pair<ll, ll>& rhs)
{
    if(cntr[lhs.ff][lhs.ss] < cntr[rhs.ff][rhs.ss]){
    	return true;
    }
    
   	else if(cntr[lhs.ff][lhs.ss] == cntr[rhs.ff][rhs.ss] and ctr[lhs.ss] > ctr[rhs.ss]){
    	return true;
    }
    else
	    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    if(m == 1){
    	for(int i = 0 ; i < n ; i++)
    		cout << 'a';
    	cout << endl;
    	return 0;
    }
    else if(n == 1){
    	cout << 'a' << endl;
    	return 0;
    }
    if(m >= n)
    	m = n - 1;
    string ans;
    ans.pb('a');    
    ans.pb('a');  
    ctr[0] = 1;
    cntr[0][0] = 1;
    for(int i = 1 ; i < n - 1; i++){
    	int ind = (int)(ans[i] - 'a');
    	ll best = 0;
    	for(int j = 0 ; j < m ; j++){
    		if(cntr[ind][best] >= cntr[ind][j])
    			best = j;
    		else if(cntr[ind][best] == cntr[ind][j] and ctr[best] >= ctr[j])
    			best = j;
    	}
    	ctr[best]++;
    	ans.pb((char)('a' + best));
    	cntr[ind][best]++;
    }
    cout << ans << endl;
	return(0);

















}