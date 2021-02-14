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




	}

	static int countPattern(int[] a, int[] b, int[] c, int length) {

		int count = 0;

		for(int i = 0; i < length; i++) {
			if(binarySearch(b, a[i]) == -1) continue;
			int bIndex = binarySearch(b, a[i]);
			for(int j = bIndex; j < length; j++) {
				if(binarySearch(c, b[bIndex]) == -1) continue;
				int cIndex = binarySearch(c, b[bIndex]);
				count = count + (length - bIndex - 1)*(length - bIndex - 1);
			}

		}

		return count;
	}

	static int binarySearch(int[] b, int i) {

		int result = 0;

		int start = b.length%2 ==0 ? b.length/2 : (b.length+1)/2;

		while(true) {
			if(i > b[b.length-1]) {
				result = -1;
				break;
			}
			if(b[start] > i) {
				if(b[start - 1] < i) {
					result = start - 1;
					break;
				}else if(b[start - 1] == i ){
					result = start;
				}else {
					start = start - start/2;
				}
			}
			if(b[start] < i) {
				if(b[start + 1] > i) {
					result = start + 1;
					break;
				} else if(b[start + 1] == i) {
					result = start + 2;
				} else {
					start = start + start/2;
				}
			}
			if(b[start] == i) {
				result = start + 1;
				break;
			}
		}
		return result;

	}

}
