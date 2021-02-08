package algorithm.bitSearch;

import java.util.Scanner;

public class ExhaustiveSearch {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		int[] a = new int[n];

		for(int i = 0; i < n; i++) {
			a[i] = scan.nextInt();
		}

		int q = scan.nextInt();

		int[] m = new int[q];

		for(int i = 0; i < q; i++) {
			m[i] = scan.nextInt();
		}

		scan.close();

		boolean flag = false;

		String[] ans = new String[q];

		for(int i = 0; i < q; i++) {
			int sum = 0;
			int target = m[i];
			ans[i] = "no";
			for(int j = 0; j < Math.pow(2, n); j++) {
				sum = 0;
				for(int k = 0; k < n; k++) {
					if((j & (int)Math.pow(2, k)	) >= 1) sum = sum + a[k];
					if(sum == target) {
						ans[i] = "yes";
						flag = true;
						break;
					}
					if(flag) {
						flag = false;
						break;
					}
				}
			}
		}
		for(String answer : ans) {
			System.out.println(answer);
		}
	}

}
