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
#define pb push_back
#define all(a) a.begin(), a.end()
typedef long long ll;
#define N 1000
#define Y 10000

struct P{
    int i;    
    double d;    
    P(){}
    P(int i, double d):i(i),d(d){}
    bool operator<(const P&p)const{
        return d<p.d;
    }
};

ll i,j,k,m,n,l,y;
int a[N+10], d[N+10];

int main(){
    int tests;
    scanf("%d", &tests);
    rep(test, tests){
        if (test) puts("");
        scanf("%d%d%d", &n, &m, &y); int mm=m;
        repf(i, 1, n) scanf("%d", &a[i]), d[i]=a[i]*1.*m/y;
        repf(i, 1, n) m-=d[i];
        
        vector<P> v;
        repf(i, 1, n){
            double s=fabs(   (d[i]+1.)/mm-   1.*a[i]/y  );
            double t=fabs(    d[i]*1./mm - 1.*a[i]/y );
          //  cout<<d[i]<<' '<<mm<<' '<<(d[i]+1.)/mm<<endl;
           // cout<<(d[i]+1.)/mm<<' '<<d[i]*1./mm<<' '<<1.*a[i]/y<<' '<<s<<' '<<t<<endl;
            v.pb(P(i, s-t));
        }
        
      //  cout<<endl;
      //  rep(i, n) cout<<v[i].d<<' '; cout<<endl;
        sort(all(v));        
        rep(i, m) d[v[i].i]++;
        
        repf(i, 1, n){
            if (i-1) putchar(' ');
            printf("%d", d[i]);
        }
        putchar('\n');
    }
    return 0;
}
