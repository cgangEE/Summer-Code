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
#define INF (INT_MAX/10)
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

#define eps 1e-9
int sgn(double d){
    return d<-eps?-1:d>eps;
}

struct P{
    double x, y, z;
    P(){}
    P(double x, double y, double z):x(x),y(y),z(z){}
    void in(){ scanf("%lf%lf%lf", &x, &y, &z); }
    void out(){ printf("%.6lf %.6lf %.6lf", x, y, z); }
    P operator +(const P&p)const{ return P(x+p.x, y+p.y, z+p.z); }
    P operator -(const P&p)const{ return P(x-p.x, y-p.y, z-p.z); }
    P operator *(const double &k)const{ return P(x*k, y*k, z*k); }
    P operator *(const P&p)const{ return P(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x); }
    double operator ^(const P&p)const{ return x*p.x+y*p.y+z*p.z; }
    double len()const{ return sqrt(x*x+y*y+z*z); }
};

struct L{
    P u, v;
    L(){}
    L (P u, P v):u(u),v(v){}
    void in(){ 
        u.in(), v.in(); 
        v=v-u;
    }
};

int i,j,k,m,n,l;
L alpha, beta;

double linetoline(P u1, P u2, P v1, P v2){
    P n = u2 * v2;
    if (sgn(n^n)==0) return ((v1-u1)*u2).len()/u2.len();
    return fabs( ((u1-v1)^n) / n.len());
}

void gao(P p1, P u, P p2, P v){
    double b = (u^u)*(v^v) - (u^v)*(u^v);
    double a = (u^v)*(v^(p1-p2)) - (v^v)*(u ^ (p1-p2));
    double s = a/b;
    double t = ( s*(u^v)+((p1-p2)^v) )/(v^v);

    P q1 = p1 + u * s;
    P q2 = p2 + v * t;

    printf("%.6lf\n", (q1-q2).len());

    q1.out();
    putchar(' ');
    q2.out();
    putchar('\n');
}

int main(){
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
        alpha.in(), beta.in();
        gao(alpha.u, alpha.v, beta.u, beta.v);
    }
    return 0;
}
