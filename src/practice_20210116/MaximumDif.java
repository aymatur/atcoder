package practice_20210116;

import java.util.Arrays;
import java.util.Scanner;

public class MaximumDif {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		int[] A = new int[N];

		for(int i = 0; i < N ; i++) {
			A[i] = scan.nextInt();
		}

		scan.close();

		Arrays.sort(A);

		int answer = A[N-1] - A[0];


		System.out.println(answer);

	}

}
