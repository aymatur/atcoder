package dp;

import java.util.Scanner;

public class Vacation {

	public static void main(String[] args) {
		Scanner scan  = new Scanner(System.in);

		int n = scan.nextInt();

		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];

		for(int i = 0; i < n ; i++) {
			a[i] = scan.nextInt();
			b[i] = scan.nextInt();
			c[i] = scan.nextInt();
		}

		scan.close();

		int[][] dp = new int[n+1][3];

		for(int i = 1; i < n + 1; i++) {
			dp[i][0]=Math.max(dp[i-1][1]+a[i-1],dp[i-1][2]+a[i-1]);
			dp[i][1]=Math.max(dp[i-1][0]+b[i-1],dp[i-1][2]+b[i-1]);
			dp[i][2]=Math.max(dp[i-1][0]+c[i-1],dp[i-1][1]+c[i-1]);
		}

		int ans=Math.max(dp[n][0],Math.max(dp[n][1],dp[n][2]));

		System.out.print(ans);

	}

}
