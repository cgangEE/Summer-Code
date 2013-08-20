#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

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
#define clr(a, b) memset(a, b, sizeof(a))
template<class T> void checkmax(T &a, T b){ if (b>a) a=b; }

typedef long long ll;

#define N 300000

const double pi = acos(-1.0);
struct vir{
	double re, im;
	vir(){}
	vir(double re, double im):re(re),im(im){}
	vir operator +(const vir &b){ return vir(re+b.re,im+b.im); }
	vir operator -(const vir &b){ return vir(re-b.re,im-b.im); }
	vir operator *(const vir &b){ return vir(re*b.re-im*b.im, re*b.im+im*b.re); }
};

void brc(vir *y, int l){
	for (int i=1, j=l>>1; i<l-1; ++i){
		if (i<j) swap(y[i], y[j]);
		int k=l>>1;
		while (j>=k) j-=k, k>>=1;
		if (j<k) j+=k;
	}
}

void fft(vir *y, int l, int on){
	vir u, t;
	brc(y, l);
	for (int h=2; h<=l; h<<=1){
		vir wn(cos(on*2*pi/h), sin(on*2*pi/h));
		for (int j=0; j<l; j+=h){
			vir w(1,0);
			for (int k=j; k<j+h/2; ++k){
				u=y[k];
				t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn;
			}
		}
	}
	if (on==-1)
		for (int i=0; i<l; ++i)
			y[i].re/=l;
}

int i,j,k,m,n,l;
int a[N+10];
ll res[N+10];
vir y[N+10];

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		clr(a, 0);

		scanf("%d", &n);
		m=0;
		while (n--) scanf("%d", &k), a[k]++, checkmax(m, k);

		m++, l=1;
		while (l<m*2) l<<=1;

		rep(i, m) y[i]=vir(a[i], 0);
		repf(i, m, l-1) y[i]=vir(0, 0);

		fft(y, l, 1);
		rep(i, l) y[i]=y[i]*y[i];
		fft(y, l, -1);

		rep(i, l) res[i]=(ll)(y[i].re+0.5);
		rep(i, m) res[i*2]=(res[i*2]-a[i])/2;

		rep(i, l) cout<<i<<' '<<res[i]<<endl;
	}
	return 0;
}

