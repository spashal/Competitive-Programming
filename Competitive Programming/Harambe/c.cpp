#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define loop(i,s,e) for(ll i=s;i<e;i++)
#define test ll x;cin>>x;while(x--)
#define pb push_back
#define vec vector<ll>
#define sortvec(x) sort(x.begin(),x.end())
#define sz(x) x.size()

ll high(ll n)
{
    float a=log(n);
    float b=log(2);
    return a/b;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    test{
        ll n,x;
        cin>>n>>x;

        if (n<=x)
        cout<<"1\n";

        else
        {
            ll ans=0;
            while(n>x)
            {
                ll temp = high(n);
                if (temp%2)
                {
                    n = n - pow(2,temp);
                    ans++;
                }
                else
                {
                    n = n-pow(2,temp-1);
                    ans++;
                }
            }
            if (n>0 && x>0)
            ans++;

            else if(x == 0) 
            ans=-1;
            cout<<ans<<"\n";
        }

    }

}