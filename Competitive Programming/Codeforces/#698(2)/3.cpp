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
		priority_queue< ll > pq;
		for(int i = 0 ; i < 2 * n ; i++){
			cin >> a[0];
			pq.push(a[0]);
		}
		ll ctr = 0, yet = 0;
		bool no = false;
		ll last = -1;
		while(!pq.empty()){
			if(pq.top() <= yet or (pq.top() - yet) % (2 * (n - ctr)) > 0 or last == ((pq.top() - yet) / (2 * (n - ctr)))){

				// cout << "1 " << pq.top() << endl;
				no = true;
				break;
			}
			last = (pq.top() - yet) / (2 * n - 2 * ctr);
			yet += (pq.top() - yet) / (n - ctr);
			ll temp = pq.top();
			pq.pop();
			if(temp != pq.top()){
				// cout << "2 " << pq.top() << endl;
				no = true;
				break;
			}
			pq.pop();
			ctr++;
		}
		if(no)
			cout <<"No\n";
		else
			cout << "yes\n";
	}
	return(0);
}