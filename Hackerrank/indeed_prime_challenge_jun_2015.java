import java.io.*;
import java.util.*;

class Solution {

	public static void soyuz11() {
		int n,i;
        Scanner s=new Scanner(System.in);
        n=s.nextInt();
        System.out.println("  /\\");
        for(i=0;i<n;i++)
            System.out.println("  ||");
        System.out.println(" /||\\");
        System.out.println("/:||:\\");
        for(i=0;i<n-1;i++)
            System.out.println("|:||:|");
        System.out.print("|/||\\|\n");
        System.out.print("  **\n  **");
	}

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        // Solution.soyuz11();
    }
}
