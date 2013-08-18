#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a)
#define sz(a) ((int)(a).size())
typedef long long ll;
#define N 500000
#define map<int,int> mii

ll i,j,k,m,n,l,p;

struct P{
    ll k;
    P(){}
    P(ll k):k(k){}
    bool operator <(const P&p)const{return k>p.k; }
};

int main(){
    int tests;
    scanf("%d", &tests);
    rep(test, tests){
        if (test) puts("");
        scanf("%d", &n);
        priority_queue<P> q;
        repf(i, 1, n) scanf("%d", &k), q.push(P(k));
        ll ans=0;
        while (q.size()>1){
            ll i=q.top().k; q.pop(); 
            ll j=q.top().k; q.pop();
            ll k=i+j;
            ans+=k, q.push(k);
        }
        cout<<ans<<endl;
    }
    return 0;
}
