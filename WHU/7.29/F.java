import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	static final int M = 26;
	static final int N = 60;
	
	static final BigInteger zero = BigInteger.ZERO;
	static final BigInteger one = BigInteger.ONE;
	static final BigInteger ten = BigInteger.TEN;
	
	static int []a = new int [M+10], b= new int [M+10];
	static BigInteger[][] f = new BigInteger[M+10][N+10], g = new BigInteger[M+10][N+10];
	static BigInteger[] J = new BigInteger[N+10];
	
	static int n, m;
	
	static BigInteger cnt(int bg, int ed){
		BigInteger ret = one;
		for (int i=bg; i<=ed; ++i)
			ret = ret.multiply(BigInteger.valueOf(i));
		return ret;
	}
	
	static BigInteger max(BigInteger a, BigInteger b){
		if (a.compareTo(b)>0) return a;
		return b;
	}
	
	static BigInteger min(BigInteger a, BigInteger b){
		if (a.compareTo(zero)==0) return b;
		if (a.compareTo(b)<0) return a;
		return b;
	}
	
	static void solve(BigInteger x){
		x = x.multiply(J[m].multiply(J[n-m]));
		BigInteger y =  J[n];
		for (int i=1; i<=b[0]; ++i) y = y.multiply(J[b[i]]);
		
		BigInteger g = x.gcd(y);
		x=x.divide(g);
		y=y.divide(g);
		System.out.println(x+"/"+y);
	}
	
	static void solve(){
		Arrays.fill(b, 0);
		for (int i=0; i<M; ++i) if (a[i]>0) b[++b[0]]=a[i];
		for (int i=0; i<=b[0]; ++i){
			Arrays.fill(f[i], zero);
			Arrays.fill(g[i], zero);
		}		
		
		f[0][0] = g[0][0] = one;
		for (int i=1; i<=b[0]; ++i){
			for (int j=0; j<=n-m; ++j)
				for (int k=0; k<=j; ++k){
					BigInteger w = cnt(k+1, k+b[i]);
					f[i][j] = max(f[i][j], f[i-1][j-k].multiply(w));
					g[i][j] = min(g[i][j], g[i-1][j-k].multiply(w));
				}
		}
		solve(f[b[0]][n-m]);
		solve(g[b[0]][n-m]);
		System.out.println("");
	}
	
	public static void main(String []args){
		J[0] = J[1] = one;
		for (int i=2; i<=N; ++i) J[i] = J[i-1].multiply(BigInteger.valueOf(i));
		
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()){
			n=cin.nextInt();
			String s=cin.next();
			m=s.length();
			
			Arrays.fill(a, 0);
			for (int i=0; i<m; ++i) a[s.charAt(i)-'A']++;
			
	
			solve();			
		}
	}
}