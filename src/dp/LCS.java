package dp;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class LCS {

	static int[][] dp;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String s = scan.next();
		String t = scan.next();

		scan.close();

		dp = new int[s.length()+1][t.length()+1];

		for(int i = 0; i < s.length() +1 ; i++) {
			for(int j = 0; j < t.length() + 1; j++) {
				if(i > 0 && j > 0) {
					if(s.charAt(i-1) == t.charAt(j-1)) {
						dp[i][j] = dp[i-1][j-1] + 1;
					} else {
						dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
					}
				}
			}
		}

		List<String> ans = new ArrayList<String>();

		int len = dp[s.length()][t.length()];
		int i = s.length() - 1;
		int j = t.length() - 1;
		while(len > 0) {
			if(s.charAt(i) == t.charAt(j)) {
				ans.add(String.valueOf(s.charAt(i)));
				i--;
				j--;
				len--;
			} else if(dp[i][j] == dp[i-1][j]) {
				i--;
			} else {
				j--;
			}
		}
	}

}
