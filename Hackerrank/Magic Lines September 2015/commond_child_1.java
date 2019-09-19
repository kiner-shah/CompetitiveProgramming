import java.io.*;
import java.util.*;
class LCS {
    public static void main(String[] args) {
        int c[][],t,i,j,k,n,m,count=0; String x,y;
        Scanner s = new Scanner(System.in);
        x=s.next(); y=s.next();
        c=new int[x.length()+1][y.length()+1]; 
        for(i=1;i<x.length()+1;i++) 
            c[i][0]=0;
        for(j=0;j<y.length()+1;j++)
            c[0][j]=0;
        for(i=1;i<x.length()+1;i++) {
            for(j=1;j<y.length()+1;j++) {
                if(x.charAt(i-1)==y.charAt(j-1))
                    c[i][j]=c[i-1][j-1]+1;
                else if(c[i-1][j]>=c[i][j-1])
                    c[i][j]=c[i-1][j];
                else
                    c[i][j]=c[i][j-1];
            }
        }
        i=x.length();j=y.length();
        while(i>0 && j>0) {    
            if(c[i-1][j]==c[i][j])
                    i--;
            else if(c[i-1][j]!=c[i][j]) {
                if(c[i][j-1]==c[i][j])
                    j--;
                else {
                    j--; i--; 
                    count++;
                }
            }
        } 
            System.out.print(count);
    }
}
