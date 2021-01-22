package practice_20210122;

import java.util.Scanner;

public class PaintBall {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int K = scan.nextInt();

		scan.close();

		int answer = K;

		for(int i = 1; i < N; i++) {

			answer = answer*(K-1);

		}

		System.out.print(answer);



	}

}
