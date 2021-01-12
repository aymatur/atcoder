package practice_20210112;

import java.util.Scanner;

public class Kdigit {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int K = scan.nextInt();
		scan.close();

		int digit = 0;

		while(N>0) {
			digit++;
			N = N/K;
		}
		System.out.println(digit);

	}

}
