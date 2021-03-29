package abc196;

import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		int d = scan.nextInt();

		scan.close();

		int first = Math.max(a, b);
		int second = Math.min(c, d);

		int ans = first-second;

		System.out.print(ans);

	}

}
