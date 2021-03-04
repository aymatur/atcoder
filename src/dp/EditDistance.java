package dp;

import java.util.Arrays;
import java.util.Scanner;

public class EditDistance {

	static int[][] dp;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String S = scan.next();
		String T = scan.next();

		scan.close();

		dp = new int[S.length()+1][T.length()+1];
		for(int[] d : dp) {
			Arrays.stream(d).forEach(i -> i = Integer.MAX_VALUE);
		}

		dp[0][0] = 0;

		for(int i = 0; i < S.length(); i++) {
			for(int j = 0; j < T.length(); j++) {
				if(i > 0 && j > 0) {
					if(S.charAt(i-1) == T.charAt(j-1)) {
						chmin(dp[i][j], dp[i-1][j-1]);
					} else {
						chmin(dp[i][j], dp[i-1][j-1] + 1);
					}
				}

				if(i > 0) chmin(dp[i][j], dp[i-1][j] + 1);

				if(j > 0) chmin(dp[i][j], dp[i][j-1] + 1 );
			}
		}
	}

	static void chmin(int a, int b) {
		if(a > b) a = b;
	}

}
