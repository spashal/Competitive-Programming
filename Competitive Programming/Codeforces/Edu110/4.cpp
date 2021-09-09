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
    cin >> n;
    ll nn = n;
    n = (1 << n) - 1;
    vector< ll > tree(n, 0);
    string s;
    cin >> s;
    vector< pair<ll, ll> > child(2*n, mp(-1, -1));
    vector< ll > parent(n, -1);
    int level = 0, last = 0;
    for(int i = 0 ; i < (n+1)/2 ; i++){
    	if(s[i] == '?')
    		tree[i] = 2;
    	else
    		tree[i] = 1;
    	if(i%2==0){
    		child[(1<<(nn-1)) + i/2].ff = i;
    		parent[i] = (1<<(nn-1)) + i/2;
    	}
    	else{
    		child[(1<<(nn-1)) + i/2].ss = i;
    		parent[i] = (1<<(nn-1)) + i/2;
    	}
    }
    level = 1;
    last = (n+1)/2;
    for(int i = last ; i < n ; i++){
    	if(s[i] == '?'){
    		tree[i] = tree[child[i].first] + tree[child[i].second];
    	}
    	else if(s[i] == '0')
    		tree[i] = tree[child[i].ff];
    	else
    		tree[i] = tree[child[i].ss];
    	if(i%2==0){
	    	child[last + (1<<(nn-level-1)) + (i-last)/2].ff = i;
    		parent[i] = last + (1<<(nn-level-1)) + (i-last)/2;
    	}
	    else{
	    	child[last + (1<<(nn-level-1)) + (i-last)/2].ss = i;
    		parent[i] = last + (1<<(nn-level-1)) + (i-last)/2;
	    }
	    if((i+1-last) == (1<<(nn-level-1))){
	    	level++;
	    	last = i + 1;
	    }
	}
	
    ll q;
    cin >> q;
  	for(int i = 0 ; i < q ; i++){
  		ll index;
  		char c;
  		cin >> index >> c;
  		index--;
  		if(c == '?'){
  			s[index] = '?';
  			if(child[index].ff != -1){
  				tree[index] = tree[child[index].ff] + tree[child[index].ss];
  			}
  			else
  				tree[index] = 2;
		}
		else if(c == '1'){
			s[index] = '1';
			if(child[index].ff != -1)
				tree[index] = tree[child[index].ss];
			else
				tree[index] = 1;
		}
		else{
			s[index] = '0';
			if(child[index].ff != -1)
				tree[index] = tree[child[index].ff];
			else
				tree[index] = 1;
		}
  		while(n > parent[index]){
  				index = parent[index];
  				if(s[index] == '?')
	  				tree[index] = tree[child[index].ff] + tree[child[index].ss];
	  			else if(s[index] == '0')
	  				tree[index] = tree[child[index].ff];
	  			else
	  				tree[index] = tree[child[index].ss];
  		}
  		cout << tree[n-1] << "\n";
  	}
	return(0);
}