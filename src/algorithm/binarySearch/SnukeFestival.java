package algorithm.binarySearch;

import java.util.Arrays;
import java.util.Scanner;

public class SnukeFestival {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];

		for(int i = 0; i < n; i++) {
			a[i] = scan.nextInt();
		}
		for(int i = 0; i < n; i++) {
			b[i] = scan.nextInt();
		}
		for(int i = 0; i < n; i++) {
			c[i] = scan.nextInt();
		}

		scan.close();

		Arrays.sort(a);
		Arrays.sort(b);
		Arrays.sort(c);

		int ans = 0;

		for(int i = 0; i < n; i++) {
			int anum = binarySearch(a, b[i]) + 1;
			int cnum = n - binarySearch(c, b[i]) 	- 1;
			ans += anum*cnum;
		}

		System.out.print(ans);


	}

	static int binarySearch(int[] numArray, int target) {

		int right = numArray.length;
		int left = -1;

		while(right - left > 1) {
			int mid = (right + left)/2;
			if(numArray[mid] > target) right = mid;
			else left = mid;
		}

		return right;

	}


}
