package practice20210113;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class KagamiMochi {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		Integer[] numArray = new Integer[N];

		for(int i = 0; i < N; i++) {
			numArray[i] = scan.nextInt();
		}
		scan.close();

		Comparator<Integer> c = new Comparator<Integer>() {
			@Override
			public	int compare(Integer n1, Integer n2){
				return n2.compareTo(n1);
			}
		};

		Arrays.sort(numArray, c);

		int sum = 0;
		int lastnum = 0;

		for(Integer num : numArray) {
			if(num == lastnum) continue;
			sum++;
			lastnum = num;
		}

		System.out.print(sum);


	}

}
