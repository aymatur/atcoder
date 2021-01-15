package practice_20210116;

import java.util.Arrays;
import java.util.Scanner;

public class Palace {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		Double T = scan.nextDouble();

		Double A = scan.nextDouble();

		Double[] diff = new Double[N];

		Double baseDiff = T - A;

		for(int i = 0; i < N ; i++) {
			diff[i] = Math.abs(baseDiff - 0.006*scan.nextDouble());
		}

		scan.close();

		Double[] sorted = Arrays.copyOf(diff, diff.length);
		Arrays.sort(sorted);

		int answer =Arrays.asList(diff).indexOf(sorted[0]) + 1;

		System.out.println(answer);

	}

}
