import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
    static final BigInteger zero = BigInteger.ZERO;
    static final BigInteger one = BigInteger.ONE;
    static final BigInteger two = one.add(one);
    static final BigInteger ten = BigInteger.TEN;
    
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int ts=cin.nextInt();
        while (ts-->0){
            BigInteger n = cin.nextBigInteger();
            int k = cin.nextInt();
            
            BigInteger ret = zero;
            
            while (n.compareTo(zero)>0){
                n = n.shiftRight(k-1);
                ret=ret.add( n.add(one).divide(two)   );
                n = n.shiftRight(1);
            }
            
            System.out.println(ret);
        }
    }
}