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
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    int left = 0, right = n-1;
    int ans = 0;
    while(k > 0){
    	while(left < n and s[left] == 'W'){
    		ans++;
    		left++;
    	}
    	while(right >= 0 and s[right] == 'W'){
    		ans++;
    		right--;
    	}
    	int c1 = 0, c2 = 0, ctr1 = 0, ctr2 = 0;
    	bool found = false;
    	for(int i = left + 1 ; i < n ; i++)
    		if(!found and s[i] == 'W'){
    			found = true;
    			c1++;
    		}
    		else if(s[i] == 'W')
    			c1++;
    		else if(found)
    			break;
    		else if(!found){
    			ctr1++;
    		}
    	found = false;
    	for(int i = right-1 ; i >= 0 ; i--)
    		if(!found and s[i] == 'W'){
    			found = true;
    			c2++;
    		}
    		else if(s[i] == 'W')
    			c2++;
    		else if(found)
    			break;
    		else if(!found){
    			ctr2++;
    		}
    	if(c1 >= c2 and ctr1 < k){
    		left += ctr1+1;
    		k -= ctr1+1;
    	}
    	else if(ctr2 < k){
    		right -= ctr2+1;
    		k -= ctr2+1;
    	}
    	else{
    		left += ctr1+1;
    		k -= ctr1+1;
    	}
    	if(left >= right or k < 0)
    		break;
    	// ans++;
    	while(left < n and s[left] == 'W'){
    		ans++;
    		left++;
    	}
    	while(right >= 0 and s[right] == 'W'){
    		ans++;
    		right--;
    	}
    }
    cout << ans << endl;
	return(0);
}