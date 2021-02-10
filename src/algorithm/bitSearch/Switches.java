package algorithm.bitSearch;

import java.util.Scanner;

public class Switches {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int M = scan.nextInt();

		int[] k = new int[M];

		int[][] s = new int[M][];

		for(int i = 0; i<M; i++) {
			k[i] = scan.nextInt();
			s[i] = new int[k[i]];
			for(int j = 0; j < k[i]; j++) {
				s[i][j] = scan.nextInt();
			}
		}

		int[] p = new int[M];
		for(int i = 0; i<M; i++) {
			p[i] = scan.nextInt();
		}

		scan.close();

		int[][] n = new int[(int)Math.pow(2, N)][N];

		for(int i = 0; i < Math.pow(2, N); i++) {
			for(int j = 0; j < N; j++) {
				if((i & (int)Math.pow(2, j)) >= 1) n[i][j] = 1;
			}
		}

		int ans = 0;

		for(int i = 0; i < Math.pow(2, N); i++) {
			for(int j = 0; j < M; j++) {
				int sum = 0;
				for(int y= 0; y < k[j]; y++) {
					sum = sum + n[i][s[j][y]-1];
				}
				if(sum%2 != p[j]) break;
				if(j == M -1) ans++;
			}
		}

		System.out.print(ans);




	}

}
