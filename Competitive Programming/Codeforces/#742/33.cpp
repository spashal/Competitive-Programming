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
vector<vector<ll> > fax(10, vector<ll> (2, 0));
ll fun(string &s, int index, vector<bool> &carry){
	if(index == s.size())
		return 1;
	else if(index > s.size())
		return 0;
	ll num = s[index]-'0';
	if(carry[index]){
		num = (num-1);
		if(num == -1){
			if(index + 2 >= s.size())
				return 0;
			carry[index+2] = true;
			ll ans = fun(s, index+1, carry)*10;
			carry[index+2] = false;
			return ans;
		}
	}
	ll ans = fun(s, index+1, carry)*fax[num][0];
	if(index+2 < s.size()){
		carry[index+2] = true;
		ans += fun(s, index+1, carry)*fax[num][1];
		carry[index+2] = false;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0 ; i < 10 ; i++)
    	for(int j = 0 ; j < 10 ; j++)
    		if((i+j)>9)
    			fax[(i+j)%10][1]++;
    		else
    			fax[i+j][0]++;
    cin >> t;
	while( t-- ){
		cin >> n;
		int count = 0, temp = n;
		while(temp){
			count++;
			temp /= 2;
		}
		vector<vector<ll> > dp(count+2, vector<ll> (2, 0));
		vector<bool> carry(count+1, false);
		string s = to_string(n);
		reverse(s.begin(), s.end());
		cout << fun(s, 0, carry)-2 << endl;
	}
	return(0);
}