package dp;

import java.util.Scanner;

public class Knapsack {

	static int[][] dp;
	static int[] weight;
	static int[] value;

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int W = scan.nextInt();

		weight = new int[N];
		value = new int[N];

		for(int i = 0; i < N; i++) {
			weight[i] = scan.nextInt();
			value[i] = scan.nextInt();
		}

		scan.close();

		dp = new int[N+1][W+1];

		for(int i = 0; i < N; i++) {
			for(int w = 0; w <= W; w++) {
				//iを選ぶ場合
				if(w-weight[i] >= 0) chmax(dp[i+1][w], dp[i][w - weight[i]] + value[i]);

				//iを選ばない場合
				chmax(dp[i+1][w], dp[i][w]);
			}
		}

		System.out.println(dp[N][W]);


	}

	static int chmax(int a, int b) {
		if(a > b) a = b;
		return a;
	}

}
