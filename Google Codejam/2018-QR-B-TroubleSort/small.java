import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
	public static void main (String[] args) throws java.lang.Exception {
		int i = 0, t, n;
		long v;
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(r.readLine());
		while(t-- > 0) {
			//ArrayList<String> lookup = new ArrayList();
			n = Integer.parseInt(r.readLine());

			String[] test_case = r.readLine().split(" ");
			int len = test_case.length;
			ArrayList<Long> l = new ArrayList();
			for(String s : test_case) {
				l.add(Long.parseLong(s));
			}
			boolean done = false;
			while(!done) {
				done = true;
				for(int j = 0; j < len - 2; j++) {
					//String tmp_s = Long.toString(val1) + " " + Long.toString(val2) + " " + Long.toString(val3);
					if(l.get(j) > l.get(j + 2)) {
						//lookup.add(tmp_s);
						Collections.swap(l, j, j + 2);
						done = false;
					}
				}
			}
			int pos = -1;
			for(int j = 1; j < len; j++) {
				if(l.get(j) < l.get(j - 1)) {
					pos = j - 1; break;
				}
			}
			if(pos == -1) System.out.println("Case #" + (i+1) + ": OK");
			else if(t > 0) System.out.println("Case #" + (i+1) + ": " + pos);
			else System.out.print("Case #" + (i+1) + ": " + pos);
			i++;
		}
	}
}