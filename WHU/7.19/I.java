import java.io.*;
import java.math.*;
import java.util.*;

public class Main{

    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        boolean first=true;
        while (cin.hasNext()){
            if (!first) System.out.println();
            else first=false;
            BigInteger n = cin.nextBigInteger(), m=cin.nextBigInteger();
            System.out.println(n.gcd(m));
            
        }
    }
}
