package abc196;

import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		long N = scan.nextLong();

		scan.close();

		int ans = 0;

		for(int i = 1; ;i++) {
			if(Long.valueOf(String.valueOf(i)+String.valueOf(i)) > N) {
				break;
			}
			ans++;
		}

		System.out.print(ans);

	}




}
