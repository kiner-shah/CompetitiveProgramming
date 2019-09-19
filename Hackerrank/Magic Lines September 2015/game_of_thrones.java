import java.io.*;
import java.util.*;

class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        String s; char c[];
        int occ,i,b[],count=0;
        HashMap m=new HashMap();
        Scanner s1=new Scanner(System.in);
        s=s1.nextLine();
        c=s.toCharArray();
        b=new int[s.length()];
       for (i = 0; i < s.length(); i++) 
        {
            if(m.containsKey(c[i]))
            {
                occ=(Integer)m.get(c[i]);
                m.put(c[i],occ+1);
            }
            else
                m.put(c[i],1);
        }
        Set set=m.entrySet();
        Iterator e=set.iterator();
        i=0;
        while(e.hasNext())
        {
            Map.Entry k=(Map.Entry)e.next();
            b[i]=(Integer)k.getValue(); i++; count++;
        } int count1=0;
        for(i=0;i<count;i++)
            {
            if(b[i]%2==1)
                count1++;
        }
        if(count1>1)
            System.out.println("NO");
        else
            System.out.println("YES");
    }
}
