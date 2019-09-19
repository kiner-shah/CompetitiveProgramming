import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {
    public static int search(boolean[][] visited, boolean[][] matrix, int maxRows, int maxCols, int row, int col){
        if(visited[row][col] || !matrix[row][col]) return 0;
        int count =1;
        //mark us as visited
        visited[row][col] = true;
        //check up
        if(row-1 >=0){
            count+=search(visited, matrix, maxRows, maxCols, row-1, col);
            if(col-1>=0) count+=search(visited, matrix, maxRows, maxCols, row-1, col-1);
            if(col+1<maxCols) count+=search(visited, matrix, maxRows, maxCols, row-1, col+1);
        }
        //check down
        if(row+1<maxRows){
            count+=search(visited, matrix, maxRows, maxCols, row+1, col);
            if(col-1>=0) count+=search(visited, matrix, maxRows, maxCols, row+1, col-1);
            if(col+1<maxCols) count+=search(visited, matrix, maxRows, maxCols, row+1, col+1);
        }
        //check left
        if(col-1>=0) count+=search(visited, matrix, maxRows, maxCols, row, col-1);
        if(col+1<maxCols) count+=search(visited, matrix, maxRows, maxCols, row, col+1);
        return count;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int numRows = Integer.parseInt(s.nextLine());
        int numCols = Integer.parseInt(s.nextLine());
        boolean[][] matrix = new boolean[numRows][numCols];
        boolean[][] counted = new boolean[numRows][numCols];
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                counted[i][j] = false;
                matrix[i][j] = s.nextInt()==1;
            }
        }
        int maxCount =0;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                if(matrix[i][j]==true){
                    int dfs = search(counted, matrix, numRows, numCols, i, j);
                    if(dfs>=maxCount) maxCount = dfs;
                }
            }
        }
        System.out.println(maxCount);
    }
}
