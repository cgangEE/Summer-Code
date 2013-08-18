import java.math.*;
import java.io.*;
import java.util.*;

public class Main{
    
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
int tests=cin.nextInt();

for (int test=0; test<tests; ++test){
        if (test>0) System.out.println();            
            BigInteger n = cin.nextBigInteger();
            BigInteger x = n.remainder(new BigInteger("2"));
            if (x.equals(BigInteger.ZERO)) 
                System.out.println(n.divide(new BigInteger("4")).multiply(new BigInteger("2")).subtract(BigInteger.ONE));
            else
                System.out.println(n.divide(new BigInteger("2")));
        }
    }

}