package practice_20210114;

import java.util.Scanner;

public class Parity {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		int[] t = new int[N];
		int[] x = new int[N];
		int[] y = new int[N];


		for(int i = 0; i < N ; i++) {
			t[i] = scan.nextInt();
			x[i] = scan.nextInt();
			y[i] = scan.nextInt();
		}

		scan.close();

		String answer = "Yes";

		int beforeX = 0;
		int beforeY = 0;
		int beforeT = 0;

		for(int i = 0; i<N ; i++) {

			int diffX = x[i] - beforeX;
			int diffY = y[i] - beforeY;
			int diffT = t[i] - beforeT;

			int diff = Math.abs(diffX) + Math.abs(diffY);
			if(diff > diffT
					||
					diff % 2 != diffT % 2) {
				answer = "No";
				break;
			}

			beforeX = x[i];
			beforeY = y[i];
			beforeT = t[i];

		}
		System.out.println(answer);

	}

}
