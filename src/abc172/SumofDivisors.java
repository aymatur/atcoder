package abc172;

import java.util.Scanner;

public class SumofDivisors {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		sc.close();

		long ans = 0;

		for(long i = 1; i < N + 1; i++) {
			ans += i* (N/i) * (1 + (N/i)) /2;
		}
		System.out.print(ans);
	}

}
