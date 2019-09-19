import java.io.*;
import java.util.*;

public class Solution {
	 public static void main(String args[]) {
		 String a,b; int p[],q[],i,j,sum=0;
		 Scanner s=new Scanner(System.in);
		 a=s.nextLine(); b=s.nextLine(); 
		 p=new int[26]; 
		 q=new int[26]; 
		 for(i=0;i<26;i++) {
			 p[i]=q[i]=0;
		 }
		 for(i=0;i<a.length();i++)
			 p[a.charAt(i)-'a']++;
		 for(i=0;i<b.length();i++)
			 q[b.charAt(i)-'a']++;
		 for(i=0;i<26;i++) {
			 sum += Math.abs(p[i]-q[i]);
		 }
		 System.out.println(sum);
	 }
}
