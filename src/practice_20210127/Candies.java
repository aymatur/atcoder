package practice_20210127;

import java.util.Scanner;

public class Candies {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int[] A1 = new int[N];
		int[] A2 = new int[N];

		for(int i = 0; i < N; i++) {
			A1[i] = scan.nextInt();
		}
		for(int i = 0; i < N; i++) {
			A2[i] = scan.nextInt();
		}

		scan.close();

		int sum = 0;
		int maxSum = 0;

		for(int changePoint = 0; changePoint < N; changePoint++) {
			sum = 0;
			for(int i = 0; i < changePoint+1; i++) {
				sum += A1[i];
			}
			for(int j = changePoint; j < N;j++) {
				sum += A2[j];
			}
			maxSum = maxSum < sum ? sum : maxSum;
		}

		System.out.print(maxSum);

	}

}
