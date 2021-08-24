package abc172;

import java.util.Scanner;

public class Tsundoku {

	static int[] a;
	static int[] b;
	static long[] atot;
	static long[] btot;
	static int[][] dp;
	static int ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int M = sc.nextInt();
		int K = sc.nextInt();

		a = new int[N];
		b = new int[M];

		for(int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
		}
		for(int i = 0; i < M; i++) {
			b[i] = sc.nextInt();
		}

		atot = new long[N+1];
		btot = new long[M+1];

		atot[0] = 0;

		// 累積和を求める
		for(int i = 0; i < N; i++) {
			atot[i+1] = atot[i] + a[i];
		}

		btot[0] = 0;

		for(int i = 0; i < M; i++) {
			btot[i+1] = btot[i] + b[i];
		}

		ans = 0;

		int ok = M;

		for(int i = 0; i < N+1; i++) {
			while(0 <= ok && K < atot[i] + btot[ok]) ok--;
			if(0 <= ok) {
				if(ans < i + ok) ans = i + ok;
			}
		}

		System.out.print(ans);
	}

	static void chmax(long a, long b) {
		if(a < b) {
			a = b;
		}
	}



}
