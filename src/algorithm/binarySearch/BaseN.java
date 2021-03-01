package algorithm.binarySearch;

import java.util.Arrays;
import java.util.Scanner;

public class BaseN {

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

		int ans = countPattern(a, b, c, n);

		System.out.print(ans);

	}

	static int countPattern(int[] a, int[] b, int[] c, int length) {

		int count = 0;
		if(a[0] >= b[length - 1]) return count;
		if(b[0] >= c[length - 1]) return count;
		for(int i = 0; i < length; i++) {
			if(binary_search(a, b[i]) < 0);
			int numA = binary_search(a, b[i]) >= length ? length - 1 : binary_search(a, b[i]);
			if(binary_search(c, b[i]) >= length) break;
			int numC = binary_search(c, b[i]) >= length ? length - 1 : binary_search(c, b[i]);
			count = count + (length - 1 - numC)*(numA + 1);
		}
		return count;
	}

	static boolean isOK(int[] array, int index, int key) {
	    if (array[index] > key) return true;
	    else return false;
	}


	static int binary_search(int[] array, int key) {
	    int left = -1;
	    int right = array.length;

	    while (right - left > 1) {
	        int mid = left + (right - left) / 2;

	        if (isOK(array, mid, key)) right = mid;
	        else left = mid;
	    }

	    return right;
	}

}
