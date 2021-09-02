package abc174;

import java.util.Scanner;

public class Repsept {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int K = sc.nextInt();

		sc.close();

		if(K%2 == 0 || K%5 == 0) {
			System.out.print(-1);
			return;
		}

		int L = K%7 == 0 ? 9*K/7 : 9*K;

		int ans = 0;
		int base = 1;

		while(true) {
			ans++;
			base = base*10;
			base = base%L;
			if(base == 1) break;
		}

		System.out.print(ans);

	}

}
