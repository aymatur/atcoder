package algorithm.fullSearch.allEnumeration;

import java.util.Scanner;

public class HowManyWays {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		scan.close();

		int ans = 0;
		int cnt = 0;
		if(N >= 105) {
			ans++;
			N = N%2 == 0 ? N - 1: N;
			for(int i = N; i > 105; i=i-2) {
				for(int j = 1; j < Math.sqrt(i); j=j+2) {
					if(i%j == 0) cnt=cnt+2;
				}
				if(cnt == 8) ans++;
				cnt = 0;
			}
		}
		System.out.print(ans);
	}

}
