#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[300005];
char b[300005];
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
		stack< int > stkOdd, stkEven;
		cin >> n >> m;
		vector< pair< pair< int, char >, int > > bb(n, mp(mp(0, 'R'), 0));
		for(int i = 0 ; i < n ; i++){
			cin >> bb[i].fff;
			bb[i].ss = i;
		}
		vector< int > Time(n, 0), ans(n, -1);
		for(int i = 0 ; i < n ; i++)
			cin >> bb[i].fs;
		sort(bb.begin(), bb.end());
		for(int i = 0 ; i < n ; i++){
			a[i] = bb[i].fff;
			b[i] = bb[i].fs;
		}
		for(int i = 0 ; i < n ; i++){
			if(b[i] == 'R' and a[i] % 2 == 0)
				stkEven.push(i);
			else if(b[i] == 'R')
				stkOdd.push(i);
			else{
				if(a[i] % 2 and stkOdd.empty()){
					b[i] = 'R';
					Time[i] = a[i];
					stkOdd.push(i);
					// take care of time here
				}
				else if(a[i] % 2 == 0 and stkEven.empty()){
					b[i] = 'R';
					Time[i] = a[i];
					stkEven.push(i);
				}
				else{
					if(a[i] % 2 == 0){
						ans[i] = Time[i] + Time[stkEven.top()] + (a[i] - a[stkEven.top()]) / 2;
						ans[stkEven.top()] = Time[i] + Time[stkEven.top()] + (a[i] - a[stkEven.top()]) / 2;
						stkEven.pop();
					}
					else{
						ans[i] = Time[i] + Time[stkOdd.top()] + (a[i] - a[stkOdd.top()]) / 2;
						ans[stkOdd.top()] = Time[i] + Time[stkOdd.top()] + (a[i] - a[stkOdd.top()]) / 2;
						stkOdd.pop();
					}
				}
			}
		}
		while(stkEven.size() > 1){
			int cur = stkEven.top();
			stkEven.pop();
			b[cur] = 'L';
			Time[cur] += m - a[cur];
			ans[cur] = Time[cur] + Time[stkEven.top()] + (a[cur] - a[stkEven.top()]) / 2;
			ans[stkEven.top()] = ans[cur];
			stkEven.pop();
		}
		while(stkOdd.size() > 1){
			int cur = stkOdd.top();
			stkOdd.pop();
			b[cur] = 'L';
			Time[cur] += m - a[cur];
			ans[cur] = Time[cur] + Time[stkOdd.top()] + (a[cur] - a[stkOdd.top()]) / 2;
			ans[stkOdd.top()] = ans[cur];
			stkOdd.pop();
		}
		vector< int > anss(n, 0);
		for(int i = 0 ; i < n ; i++)
			anss[bb[i].ss] = ans[i];
		for(int i = 0 ; i < n ; i++)
			cout << anss[i] << " ";
		cout << endl;
	}
	return(0);
}