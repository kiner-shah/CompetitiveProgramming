/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
/* Name of the class has to be "Main" only if the class is public. */
class Solution
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int t;
		Scanner s=new Scanner(System.in);
		t=s.nextInt();
		BigInteger n,x,ans; int y;
		n=s.nextBigInteger();
		while(t-- > 0) {
			x=s.nextBigInteger(); y=s.nextInt();
			ans=x.pow(y);
			System.out.println(ans.remainder(n));
		}
	}
}
