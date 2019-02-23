// Sum square difference
import java.io.*;
import java.util.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BigInteger t,i,ans,n,sum1,sum2,j,temp;
        Scanner s=new Scanner(System.in);
        t=s.nextBigInteger();
        for(i=new BigInteger("0");i.compareTo(t)<0;i=i.add(new BigInteger("1"))) {
            n=s.nextBigInteger(); 
            sum1=n.multiply(n.add(new BigInteger("1"))).divide(new BigInteger("2"));
            temp=n.multiply(new BigInteger("2")).add(new BigInteger("1"));
            sum2=n.multiply(n.add(new BigInteger("1"))).multiply(temp).divide(new BigInteger("6"));
            ans=(sum1.pow(2)).subtract(sum2);
            System.out.println(ans);
        }
    }
}
