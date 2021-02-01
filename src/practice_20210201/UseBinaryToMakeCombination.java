package practice_20210201;

import java.util.Arrays;
import java.util.Scanner;

public class UseBinaryToMakeCombination {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int M = scan.nextInt();

		int[] A = new int[M];
		int[] B = new int[M];

		for(int i = 0; i < M; i++) {
			A[i] = scan.nextInt();
			B[i] = scan.nextInt();
		}

		int K = scan.nextInt();
		int[] C = new int[K];
		int[] D = new int[K];

		for(int i = 0; i < K; i++) {
			C[i] = scan.nextInt();
			D[i] = scan.nextInt();
		}

		scan.close();

		int ans = 0;
		int cnt = 0;

		String format = "%1$"+K+"s";

		Integer[][] conbi = new Integer[(int)Math.pow(2, K)][K];

		for(int i = 0; i<Math.pow(2, K); i++) {
			String kBinary = String.format(format,Integer.toBinaryString(i)).replace(" ", "0");
			String[] kBinaryArray = kBinary.split("");

			for(int j = 0; j < K; j++) {
				if(kBinaryArray[j].equals("0")) {
					conbi[i][j] = C[j];
				}else {
					conbi[i][j] = D[j];
				}
			}

			for(int k = 0; k < M; k++) {
				if(Arrays.asList(conbi[i]).contains(A[k])
						&& Arrays.asList(conbi[i]).contains(B[k])) {
					cnt++;
				}
			}

			if(cnt > ans) ans = cnt;
			cnt = 0;

		}

		System.out.print(ans);


	}

}
