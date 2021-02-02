package practice_20210202;

import java.util.Scanner;

public class YakusuuRekkyo {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		long N = scan.nextLong();

		scan.close();

		int ans = 0;

		for(int i = 1; i <=  Math.sqrt(2*N); i++) {
			if(2*N%i == 0) {
				if((2*N/i)%2 != i%2) ans = ans+2;
			}
		}

		System.out.print(ans);

	}

}
