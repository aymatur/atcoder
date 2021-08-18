package abc171;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Replacing {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		Integer[] A = new Integer[N];

		int in = 0;

		long sum = 0;

		for(int i = 0; i < N; i++) {
			in = sc.nextInt();
			A[i] = in;
			sum += in;
		}

		int Q = sc.nextInt();

		int[] B = new int[Q];
		int[] C = new int[Q];

		for(int i = 0; i < Q; i++) {
			B[i] = sc.nextInt();
			C[i] = sc.nextInt();
		}

		sc.close();

		Arrays.sort(A);
		List<Integer> AList = Arrays.asList(A);

		int first = 0;
		int last = 0;
		int num = 0;
		int diff = 0;

		for(int i = 0; i < Q; i++) {
			first = AList.indexOf(B[i]);
			last = AList.lastIndexOf(B[i]);
			if(first >= 0) {
				num = last - first + 1;

			} else {
				num = 0;
			}
			diff = C[i] - B[i];
			sum += diff*num;
			Collections.replaceAll(AList, B[i], C[i]);
			System.out.println(sum);
		}

	}


}
