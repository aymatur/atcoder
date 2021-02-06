package algorithm.fullSearch.allEnumeration;

import java.util.Scanner;

public class Karaoke {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int M = scan.nextInt();

		int[][] a = new int[N][M];

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				a[i][j] = scan.nextInt();
			}
		}

		scan.close();

		long ans = 0;
		long cnt = 0;

		for(int i = 0; i < M - 1; i++) {
			for(int j = i + 1; j < M; j++) {
				for(int n = 0; n < N; n++) {
					cnt = a[n][i] > a[n][j] ? cnt + a[n][i] : cnt + a[n][j];
				}
				ans = ans > cnt ? ans : cnt;
				cnt = 0;
			}
		}

		System.out.print(ans);



	}

}
