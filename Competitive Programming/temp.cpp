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

long long int mod = 1e9+7;
bool check(long long int num, int x, int y){
    int temp = 0;
    while(num){
        temp += num%10;
        num /= 10;
    }
    num = temp;
    while(num){
        if(num%10 != x and num%10 != y)
            return false;
        num /= 10;
    }
    return true;
}

void rec(long long int yet, int size, long long int &ans, int x, int y){
    if(size == 0 and check(yet, x, y)){
        ans = (ans+1)%mod;
        return;
    }
    else if(size == 0)
    	return;
    for(int i = 0 ; i <= 9 ; i++){
        rec((yet*10+i), size-1, ans, x, y);
    }
}

long long FY22CampusCompactNumbers(int x, int y, int n) {
    long long int ans = 0;
    for(int i = 1 ; i <= 9 ; i++)
	    rec(i, n-1, ans, x, y);
    return ans;
}



	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> n >> m >> k;
    cout << FY22CampusCompactNumbers(n, m, k) << endl;
	return(0);
}