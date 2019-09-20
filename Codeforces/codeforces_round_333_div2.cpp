/* package whatever; // don't place package name! */
 
import java.util.*;
import java.lang.*;
import java.io.*;
/* Name of the class has to be "Main" only if the class is public. */
class Solution
{
	public static void twoBases() {
		int i,n,b1,m,b2;
        long x,sum=0,sum1=0;
        Scanner s=new Scanner(System.in);
        n=s.nextInt();
        b1=s.nextInt();
        for(i=n-1;i>=0;i--) {
            x=s.nextLong();
            sum+=x*(long)Math.pow(b1,i);
        } 
        m=s.nextInt(); b2=s.nextInt();
        for(i=m-1;i>=0;i--) {
            x=s.nextLong();
            sum1+=x*(long)Math.pow(b2,i);
        }
        if(sum1 == sum) System.out.print("=");
        else if(sum1>sum) System.out.print("<");
        else System.out.print(">");
	}
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        // twoBases();
    }
}
