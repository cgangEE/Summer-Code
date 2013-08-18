#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;
template<class T> T _checkmin(T &a, T b){ if (a==-1 || a>b) a=b; }
template<class T> T _checkmax(T &a, T b){ if (a==-1 || a<b) a=b; }
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define clr(a, b) memset(a, b, sizeof(a))
typedef long long ll;
#define N 100000

ll i,j,k,m,n,l,s,t;
ll a[N+10];

int main(){
    while (cin>>n>>m>>s>>t){
        rep(i, n) cin>>a[i];
        m=(1ll<<m);
        ll ans=0;
        while (t--){
            ll k=0;
            rep(i, n) a[i]=(a[i]+1)%m, k^=a[i];
            if (k==s) ans++;
            cout<<k<<endl;
        }
        cout<<ans<<endl;
    }
	return 0;
}
