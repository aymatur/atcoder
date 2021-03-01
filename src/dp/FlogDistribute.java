package dp;

import java.util.Arrays;
import java.util.Scanner;

public class FlogDistribute {


	static int[] dp;
	static int[] h;

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		h = new int[N];

		for(int i = 0; i < N; i++) {
			h[i] = scan.nextInt();
		}

		scan.close();

		dp = new int[N+1];

		Arrays.stream(dp).forEach(i -> i = Integer.MAX_VALUE);

		for(int i = 1; i < N; i++) {

			if(i + 1 < N) {
				chmin(dp[i+1], dp[i] + Math.abs(h[i] - h[i+1]));
			}
			if(i + 2 < N) {
				chmin(dp[i+2], dp[i] + Math.abs(h[i] - h[i+2]));
			}
		}

		System.out.print(dp[N-1]);



	}

	static int chmin(int a, int b) {
		if(a > b) a = b;
		return a;
	}

}
