import java.io.;
import java.math.;
import java.util.;

public class Main {
	static BigInteger a[]= new BigInteger [2000];
	static BigInteger f[][] = new BigInteger [2000][2];
	
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		
		
		while (cin.hasNextBigInteger()){
			BigInteger n = cin.nextBigInteger();
			if (n.signum()==-1) break;
			int cnt=0, y=0, idx=0;
			for (int i=0; in.bitLength(); ++i){
				if (n.testBit(i)){
					if (y==0) continue;
					idx++;
					a[idx]=BigInteger.valueOf(cnt);
					cnt=0;
				}
				else{
					cnt++;
					y=1;
				}
			}
			BigInteger zero = BigInteger.ZERO; 
			BigInteger one = BigInteger.ONE;
			BigInteger two = new BigInteger(2);
			
			f[0][0]=zero;
			f[0][1]=one;
			for (int i=1; i=idx; ++i){
				System.out.println(a[i]+ );
				f[i][0]=f[i-1][1].multiply(a[i]).add(f[i-1][0].multiply(a[i].add(one)));
				f[i][1]=f[i-1][0].add(f[i-1][1]);
			}
			System.out.println();
			System.out.println(f[idx][0].add(f[idx][1]));
		}
	}
}
