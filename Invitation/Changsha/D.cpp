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
#define sz(a) ((int)(a).size())
typedef long long ll;
typedef vector<int> vi;
#define N 200
#define G 13

struct P{
    int x, y;
    P(){}
    P(int x, int y):x(x),y(y){}
    void input(){ scanf("%d%d", &x, &y); }
    P operator +(const P &p){ return P(x+p.x, y+p.y); }
};

int i,j,k,m,n,l,g;
int a[N+10][N+10];
P t[N+10];
vi w[G+13];
int d[G+10][G+10];
int f[1<<G][G+10];
int ans[G+10];
int sc[G+10];

int solve(){
    repf(i, 0, g) w[i].clear();
    rep(i, g) sc[i]=a[t[i].x][t[i].y];
    rep(i, 1<<g){
        int k=i, l=0;
        while (k) l+=(k&1), k>>=1; 
        w[l].pb(i);
    }
    clr(f, -1), clr(ans, -1);
    rep(i, g){
        f[1<<i][i]=d[g][i];
        if (f[1<<i][i]!=-1 && d[i][g]!=-1)
            _checkmin(ans[1], f[1<<i][i]+d[i][g]-sc[i]);
    }

    repf(i, 2, g) rep(jj, sz(w[i])){
        int j=w[i][jj];
        rep(k, g) if ((1<<k)&j) rep(l, g) if(l!=k && ((1<<l)&j) && f[j-(1<<k)][l]!=-1 && d[l][k]!=-1)
                _checkmin(f[j][k], f[j-(1<<k)][l]+d[l][k]-sc[l]);
                
        rep(l, g) if ((l&j) && d[l][g]!=-1 && f[j][l]!=-1)
            _checkmin(ans[i], f[j][l]+d[l][g]-sc[l]);
    }
    repd(i, g, 1) if (ans[i]!=-1)
         return ans[i];
    return 0;
}

bool v[N+10][N+10];
int dt[N+10][N+10];
P dr[]={P(-1,0), P(1,0), P(0,-1), P(0,1)};

void spfa(int i){
    queue<P> Q; clr(v, 0), clr(dt, -1);
    Q.push(t[i]), v[t[i].x][t[i].y]=1, dt[t[i].x][t[i].y]=a[t[i].x][t[i].y];
    while (Q.size()){
        P p=Q.front(); Q.pop(); v[p.x][p.y]=0;
        rep(k, 4){
            P q=p+dr[k];
            if (q.x<0 || q.y<0 || q.x==n || q.y==m || a[q.x][q.y]==-1) continue;
            if (dt[q.x][q.y]==-1 || dt[q.x][q.y]>dt[p.x][p.y]+a[q.x][q.y]){
                dt[q.x][q.y]=dt[p.x][p.y]+a[q.x][q.y];
                if (!v[q.x][q.y])
                    v[q.x][q.y]=1, Q.push(q);
            }
        }
    }
    rep(j, g) d[i][j]=d[j][i]=dt[t[j].x][t[j].y];
    rep(x, n){
        if (dt[x][0]!=-1) _checkmin(d[g][i], dt[x][0]);
        if (dt[x][m-1]!=-1)  _checkmin(d[g][i], dt[x][m-1]);
    }
    rep(y, m){
        if (dt[0][y]!=-1) _checkmin(d[g][i], dt[0][y]);
        if (dt[n-1][y]!=-1) _checkmin(d[g][i], dt[n-1][y]);
    }
    d[i][g]=d[g][i];
}

int main(){
    int tests;
    scanf("%d", &tests);
    while (tests--){
        scanf("%d%d", &n, &m);
        rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
        scanf("%d", &g);
        rep(i, g) t[i].input();
        clr(d, -1);
        rep(i, g) if (a[t[i].x][t[i].y]!=-1) spfa(i);

        printf("%d\n", solve());
    }
	return 0;
}
