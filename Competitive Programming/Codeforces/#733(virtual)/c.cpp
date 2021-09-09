#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, aa[100005];
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
		vector<int> a(n, 0), b(n, 0);
		ari;
		for(int i = 0 ; i < n ; i++)
			cin >> b[i];

		// calculate scores yet
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		priority_queue<int> pq1, pq2, pq;
		int score1 = 0, score2 = 0;
		for(int i = 0 ; i < n ; i++){
			pq1.push(a[i]);
			pq2.push(b[i]);
		}
		int size;
		size = n - n/4;
		for(int i = 0 ; i < size ; i++){
			score2 += pq2.top();
			pq2.pop();
		}
		for(int i = 0 ; i < size ; i++){
			score1 += pq1.top();
			pq.push(-pq1.top());
			pq1.pop();
		}
		int ans = 0;
		while(score1 < score2){
			ans++;
			bool dodo = false;
			if((ans+n-(ans+n)/4) > (ans+n-1-(ans+n-1)/4))
				dodo = true;
			if(pq.size() and !dodo){
				score1 += 100;
				score1 += pq.top();
				pq.pop();
			}
			if(dodo){
				score1 += 100;
				if(pq2.size()){
					score2 += pq2.top();
					pq2.pop();
				}
			}
		}
		cout << ans << endl;
	}
	return(0);
}