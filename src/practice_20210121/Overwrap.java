package practice_20210121;

import java.util.Scanner;

public class Overwrap {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int A = scan.nextInt();
		int B = scan.nextInt();
		int C = scan.nextInt();
		int D = scan.nextInt();

		scan.close();

		int answer = 0;

		if(D <= A) {

		} else if(C <= A) {
			if(D <= B ) {
				answer = D - A;
			} else {
				answer = B - A;
			}
		} else if(B <= C) {

		} else if(A < C) {
			if(D <= B) {
				answer = D - C;
			} else {
				answer = B - C;
			}
		}

		System.out.print(answer);

	}

}
