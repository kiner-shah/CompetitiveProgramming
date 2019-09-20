import java.util.*;
import java.io.*;
class Sol {
	public static void main(String args[]) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		
		String a[] = r.readLine().split("\\ ");
		int count = 0;
		for(String s : a) {
			boolean flag = false;
			if(s.length() > 1) {
			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i)>='A' && s.charAt(i)<='Z') flag  = true;
				else { flag = false; break; }
			}
			if(flag) count++;
			}
		}
		System.out.println(count);
	}
}
