// Large sum
import java.io.*;
import java.util.*;
import java.math.*;
public class Solution {
    public static int digitcount(BigInteger a) {
        int count=0;
        while(a.compareTo(new BigInteger("0"))>0) {
            a=a.divide(new BigInteger("10"));
            count++;
        }
        return count;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BigInteger a[],sum=new BigInteger("0"),ten=new BigInteger("10"); int i,n,c;
        Scanner s=new Scanner(System.in);
        n=s.nextInt();
        a=new BigInteger[n];
        for(i=0;i<n;i++) {
            a[i]=s.nextBigInteger();
            sum=sum.add(a[i]);
        }
        c=digitcount(sum);
        sum=sum.divide(ten.pow(c-10));
        System.out.println(sum);
    }
}
