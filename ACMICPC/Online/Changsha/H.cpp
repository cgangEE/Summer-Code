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
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define clr(a, b) memset(a, b, sizeof(a))
template<class T> T _checkmin(T &a, T b){ if (a==-1 || a>b) a=b; }
template<class T> T _checkmax(T &a, T b){ if (a==-1 || a<b) a=b; }
typedef long long ll;

ll i,j,k,m,n,l,a,b,M;

struct mat{
    ll a[2][2];
    mat(){clr (a, 0);}
    mat(int i, int j, int k, int l){
        a[0][0]=i, a[0][1]=j, a[1][0]=k, a[1][1]=l; 
    }
    mat operator *(const mat & m){
        mat c;
        rep(i, 2) rep(j, 2){
            c.a[i][j]=0;
            rep(k, 2) c.a[i][j]=(c.a[i][j]+a[i][k]*m.a[k][j]%M)%M;;
        }
        return c;
    }
    void out(){
        rep(i, 2){
            rep(j, 2) cout<<a[i][j]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    while (cin>>n>>a){
        m=M=n;
		a%=m;
		b=(a*(a-1+m))%m;

        mat x(1, 0, 0, 1);
        mat y((2*a)%m, 1,  ((b-a*a)%m+m)%m , 0);
     //   y.out();
        while (n){
            if (n&1) x=x*y;
            y=y*y;
          //  y.out();
            n>>=1;
        }
     //   x.out();
        cout<<(   (2*a)%m*x.a[0][1]%m +2*x.a[1][1]-1+m)%m<<endl;
    }
	return 0;
}

