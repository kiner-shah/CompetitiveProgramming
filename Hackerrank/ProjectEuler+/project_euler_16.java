// Power digit sum
import java.io.*;
import java.util.*;
import java.math.*;
public class Solution {
    public static BigInteger findsum(BigInteger a) {
        BigInteger sum=new BigInteger("0");
        while(a.compareTo(new BigInteger("0"))>0) {
            sum=sum.add(a.remainder(new BigInteger("10")));
            a=a.divide(new BigInteger("10"));
        }
        return sum;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BigInteger ans,m,two=new BigInteger("2"); int t,n,i;
        Scanner s=new Scanner(System.in);
        t=s.nextInt();
        for(i=0;i<t;i++) {
            n=s.nextInt();
            m=two.pow(n);
            ans=findsum(m);
            System.out.println(ans);
        }
    }
}
