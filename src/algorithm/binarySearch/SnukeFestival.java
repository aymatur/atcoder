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

		int ans = countPattern(a, b, c, n);

		System.out.print(ans);

	}

	static int countPattern(int[] a, int[] b, int[] c, int length) {

		int count = 0;
		if(a[0] >= b[length - 1]) return count;
		if(b[0] >= c[length - 1]) return count;
		for(int i = 0; i < length; i++) {
			if(a[i] >= b[length - 1]) continue;
			int bIndex = binary_search(b, a[i]);
			if(b[bIndex] >= c[length - 1]) continue;
			for(int j = bIndex; j < length; j++) {
				int cIndex = binary_search(c, b[j]);
				count = count + length - cIndex;
			}
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
