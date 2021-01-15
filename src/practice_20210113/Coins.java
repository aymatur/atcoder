package practice_20210113;

import java.util.Scanner;

public class Coins {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int A = scan.nextInt();
		int B = scan.nextInt();
		int C = scan.nextInt();
		int X = scan.nextInt();

		scan.close();

		int d = X/50;

		int sum = 0;

		for(int a = A; a >= 0; a--) {
			for(int b = B; b >= 0; b--) {
				for(int c = C; c>=0; c--) {
					if(a+b+c == 0) break;
					if(10*a+2*b+c < d) break;
					if(10*a+2*b+c > d) continue;
					if(10*a+2*b+c == d) sum++;
				}
			}
		}

		System.out.println(sum);


	}

}
