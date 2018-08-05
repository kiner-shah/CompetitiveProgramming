import java.util.*;
import java.lang.*;
import java.io.*;
/*class Pair {
	String str;
	long score;
}
class PairCompare implements Comparator<Pair> {
	@Override
	public int compare(Pair p1, Pair p2) {
		if(p1.score < p2.score) return -1;
		else return 1;
	}
}*/
class Solution
{
	public static long count_score(String s) {
	    long val = 0, curstrength = 1;
	    int l = s.length();
	    for(int i = 0; i < l; i++) {
	        if(s.charAt(i) == 'C') curstrength *= 2;
	        else val += curstrength;
	    }
	    return val;
	}
	public static ArrayList<Integer> find_CS(String s) {
	    int l = s.length();
	    char prev = s.charAt(0);
	    ArrayList<Integer> pos_vec = new ArrayList();
	    for(int i = 1; i < l; i++) {
	        if(s.charAt(i) == 'S' && prev == 'C') pos_vec.add(i - 1);
	        prev = s.charAt(i);
	    }
	    return pos_vec;
	}
	public static void main (String[] args) throws java.lang.Exception {
		int t, i = 0;
		long d;
		String p;
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(r.readLine());
		while(t-- > 0) {

			String[] test_case = r.readLine().split(" ");
			d = Integer.parseInt(test_case[0]);
			p = test_case[1];
			long score = count_score(p);
			int count = 0;
			boolean ans = true;
			while(score > d) {
				ArrayList<Integer> l = find_CS(p);
				if(l.isEmpty()) { ans = false; break; }
				for(int x : l) {
					char[] tmp_arr = p.toCharArray();
					char tmp = tmp_arr[x];
					tmp_arr[x] = tmp_arr[x + 1];
					tmp_arr[x + 1] = tmp;

					String tmp_p = String.valueOf(tmp_arr);
					//System.out.println(tmp_p);
					long sc = count_score(tmp_p);
					if(sc < score) { score = sc; count++; p = tmp_p; }
					if(sc <= d) break;
				}
			}
			if(ans) System.out.println("Case #" + (i+1) + ": " + count);
			else System.out.println("Case #" + (i+1) + ": IMPOSSIBLE");
			i++;
		}
	}
}