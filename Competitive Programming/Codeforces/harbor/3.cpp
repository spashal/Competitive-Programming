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

int rec(string s, int index, int x, int y){
	if(x > (y+(s.size()-index+1)/2) and index < s.size())
		return index;
	else if((x+(s.size()-index)/2) < y)
		return index;
	if(index == s.size())
		return 10;
	int temp = 15;
	if(s[index] == '0'){
		temp = rec(s, index+1, x, y);
	}
	else if(s[index] == '1'){
		if(index%2)
			temp = rec(s, index+1, x, y+1);
		else
			temp = rec(s,index+1, x+1, y);
	}
	else{
		temp = min(temp, rec(s, index+1, x, y));
		if(index%2)
			temp = min(temp, rec(s, index+1, x, y+1));
		else
			temp = min(temp, rec(s, index+1, x+1, y));
	}
	return temp;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		string s;
		cin >> s;
		cout << rec(s, 0, 0, 0) << endl;
	}
	return(0);
}