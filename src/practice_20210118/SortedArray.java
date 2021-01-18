package practice_20210118;

import java.util.Scanner;

public class SortedArray {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();

		Integer[] array = new Integer[N];

		for(int i = 0; i<N;i++) {
			array[i] = scan.nextInt();
		}


		scan.close();

		int start = 0;
		int splitNum = 1;

		for(int i = 1; i < N - 1 ; i++) {
			if(
				(array[i+1] > array[i] && array[i] < array[start])
				||
				(array[i+1] < array[i] && array[i] > array[start])
					) {
				splitNum++;
				i++;
				start = i;
				if(i >= N-1) break;
			}
		}
		System.out.println(splitNum);

	}

}
