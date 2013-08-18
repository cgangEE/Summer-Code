#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/100)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator
#define N 200

int i,j,k,m,n,l;

struct e_t{ 
	int to, cap, rev;
	e_t(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};

template<int SZ>
class Dinic{
public:
	vector<e_t> a[SZ+10];
	int lev[SZ+10], done[SZ+10];	
	int s, t;

	bool levelize(){
		queue<int> q; clr(lev, -1);
		q.push(s), lev[s]=0;
		while (!q.empty()){
			int i=q.front(); q.pop();
			rep(k, sz(a[i])){
				e_t e=a[i][k];
				if (!e.cap || lev[e.to]!=-1) continue;
				lev[e.to] = lev[i] + 1;
				q.push(e.to);
			}
		}
		return lev[t]!=-1;
	}

	int augment(int v, int f){
		if (v==t || !f) return f;
		for (; done[v] <sz(a[v]); ++done[v]){
			e_t &e = a[v][done[v]];
			if (lev[e.to] < lev[v] || !e.cap) continue;
			int t = augment(e.to, min(f, e.cap));
			if (t){
				e.cap -= t;
				a[e.to][e.rev].cap += t;
				return t;
			}
		}
		return 0;
	}

	void clear(){
		rep(i, SZ+10) a[i].clear();
	}

	void add(int i, int j, int c){
		a[i].pb(e_t(j, c, sz(a[j])));
		a[j].pb(e_t(i, 0, sz(a[i])-1));
	}

	int maxFlow(){
		int tot=0, tmp;
		while (levelize()){
			clr(done, 0);
			while (tmp = augment(s, INF))
				tot += tmp;
		}
		return tot;
	}
};



int M[N+10];
Dinic<N> dinic;
int b[N+10][N+10], c[N+10][N+10], d[N+10][N+10];


void solve(){
    scanf("%d%d", &n, &m);
    {
        dinic.clear(), clr(M, 0), clr(b, -1), clr(c, -1), clr(d, -1);
        vi ans(m);
        rep(dd, m){
            scanf("%d%d", &i, &j);
            scanf("%d%d", &b[i][j], &c[i][j]);
            dinic.add(i, j, c[i][j]-b[i][j]);
            M[j]+=b[i][j], M[i]-=b[i][j];
            d[i][j]=dd;
        }
        dinic.s=0, dinic.t=n+1;
        int flow=0;
        repf(i, 1, n) 
            if (M[i]>0) dinic.add(dinic.s, i, M[i]), flow+=M[i];
            else if (M[i]<0) dinic.add(i, dinic.t, -M[i]);
        if (flow!=dinic.maxFlow())
            puts("NO");
        else{
            puts("YES");
            repf(i, 1, n) rep(k, sz(dinic.a[i])){
                int j=dinic.a[i][k].to;
                if (d[i][j]!=-1) 
                    ans[d[i][j]]=c[i][j]-dinic.a[i][k].cap;
            }
            rep(i, m) printf("%d\n", ans[i]);
        }
    }
}

int main(){
    freopen("cooling.in", "r", stdin);
    freopen("cooling.out", "w", stdout);
    solve();

	return 0;
}


