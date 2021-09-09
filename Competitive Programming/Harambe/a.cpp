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
		ll c = 0;
		vector<vector<ll> > inp(n);
		for(int i = 0 ; i < n ; i++){
			ll size = 0;
			cin >> size;
			inp[i].resize(size, 0);
			for(int j = 0 ; j < size ; j++)
				cin >> inp[i][j];
		} 
		vector<vector<ll> > fin;
		for(int i = 0 ; i < n ; i++){
			vector<ll> temp(1, inp[i][0]);
			deque<ll> dq;
			for(int j = 1 ; j < inp[i].size() ; j++){
				if(inp[i][j] > inp[i][j-1])
					temp.pb(inp[i][j]);
				else{
					fin.pb(temp);
					dq.push_back(temp.size());
					// c += min(temp.size(), inp[i].size()-j);
					temp.clear();
					temp.pb(inp[i][j]);
				}
			}
			fin.pb(temp);
			dq.pb(temp.size());
			while(dq.size() > 1){
				if(dq.front() > dq.back()){
					c += dq.back();
					dq.pop_back();
				}
				else{
					c += dq.front();
					dq.pop_front();
				}
			}
		}
		priority_queue<int> pq;
        for(int i = 0 ; i < fin.size() ; i++)
            pq.push(-fin[i].size());
        while(pq.size() > 1){
            ll pala = -pq.top();
            pq.pop();
            ll palaa = -pq.top();
            pq.pop();
            c += (pala+palaa);
            pq.push(-pala-palaa);
        }
        cout << c << endl;
	}
	return(0);
}