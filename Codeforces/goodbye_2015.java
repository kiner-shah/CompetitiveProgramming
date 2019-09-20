/* package whatever; // don't place package name! */
 
import java.util.*;
import java.lang.*;
import java.io.*;
 
/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void newYearAndDays() {
		String a;
        Scanner s=new Scanner(System.in);
        a=s.nextLine();
        String b[]=a.split("\\ ");
        if(b[2].equals("week")) {
            int x=Integer.parseInt(b[0]);
            if(x==1) System.out.print(52);
            else if(x==2) System.out.print(52);
            else if(x==3) System.out.print(52);
            else if(x==4) System.out.print(52);
            else if(x==5) System.out.print(53);
            else if(x==6) System.out.print(53);
            else if(x==7) System.out.print(52);
        }
        else if(b[2].equals("month")) {
            int x=Integer.parseInt(b[0]);
            if(x<=28) System.out.print(12);
            else if(x==29) System.out.print(12);
            else if(x==30) System.out.print(11);
            else if(x==31) System.out.print(7);
        }
	}
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        // newYearAndDays();
    }
}
