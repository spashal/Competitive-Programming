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
    ll n1, n2, n3, one = 0, x, two = 0, three = 0, k = 0;
    vector< ll > a1, a2, a3;
    vector< pair< ll, ll> > a;
    ll ans = 0;
    cin >> n1 >> n2 >> n3;
    ll o1 = n1, o2 = n2, o3 = n3;
    for(int i = 0 ; i < n1 ; i++){
    	cin >> x;
    	a1.pb(x);
    	a.pb(mp(x, 1));
    }
    for(int i = 0 ; i < n2 ; i++){
    	cin >> x;
    	a2.pb(x);
    	a.pb(mp(x, 2));
    }
    for(int i = 0 ; i < n3 ; i++){
    	cin >> x;
    	a3.pb(x);
    	a.pb(mp(x, 3));
    }
    sort(a1.begin(), a1.end(), greater< ll > ());
    sort(a2.begin(), a2.end(), greater< ll > ());
    sort(a3.begin(), a3.end(), greater< ll > ());
    sort(a.begin(), a.end(), greater< pair<ll, ll> > ());
    while( n1 * n2 > 0 or n2 * n3 > 0 or n1 * n3 > 0 ){
    	if( a[k].ss == 1 ){
    		if( one == o1  or a[k].ff > a1[one] ){
    			k++;
    			continue;
    		}
    		if( two < o2 and three < o3 and a2[two] > a3[three] ){
    			ans += a[k].ff * a2[two];
    			two++;
    			n1--;
    			n2--;
    			k++;
    			one++;
    		}
    		else if( three < o3 ){
    			ans += a[k].ff * a3[three];
    			three++;
    			n1--;
    			n3--;
    			k++;
    			one++;
    		}
    		else{
    			ans += a[k].ff * a2[two];
    			two++;
    			n1--;
    			n2--;
    			k++;
    			one++;
    		}    			
    	}
    	else if( a[k].ss == 2 ){
    		if( two == o2 or a[k].ff > a2[two] ){
    			k++;
    			continue;
    		}
    		if( one < o1 and three < o3 and a1[one] > a3[three] ){
    			ans += a[k].ff * a1[one];
    			one++;
    			n1--;
    			n2--;
    			k++;
    			two++;
    			// cout << "no" << endl;
    		}
    		else if( three < o3 ){
    			// cout << "yeah" << endl;
    			ans += a[k].ff * a3[three];
    			three++;
    			n2--;
    			n3--;
    			k++;
    			two++;
    		}
    		else{
    			ans += a[k].ff * a1[one];
    			one++;
    			n1--;
    			n2--;
    			k++;
    			two++;
    		}
    	}
    	else{
    		if( three == o3 or a[k].ff > a3[three] ){
    			k++;
    			continue;
    		}
    		if( two < o2 and one < o1 and a2[two] > a1[one] ){
    			ans += a[k].ff * a2[two];
    			two++;
    			n3--;
    			n2--;
    			k++;
    			three++;
    		}
    		else if( one < o1 ){
    			ans += a[k].ff * a1[one];
    			one++;
    			k++;
    			n3--;
    			n1--;
    			three++;
    		}
    		else{
    			ans += a[k].ff * a2[two];
    			two++;
    			n3--;
    			n2--;
    			k++;
    			three++;
    		}
    	}
    }
    cout << ans << endl;
	return(0);
}