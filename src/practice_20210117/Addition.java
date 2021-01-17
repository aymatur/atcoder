package practice_20210117;

import java.util.Arrays;
import java.util.Scanner;

public class Addition {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		Integer[] array = new Integer[3];

		for(int i = 0; i<3;i++) {
			array[i] = scan.nextInt();
		}

		scan.close();

		Arrays.sort(array);

		int smallDiff = array[2] - array[1];
		int bigDiff = array[2] - array[0];

		int diffOfDiff = bigDiff - smallDiff;

		int answer = 0;

		if(diffOfDiff == 0) {
			answer = smallDiff;
		} else if(diffOfDiff%2 == 0) {
			answer = smallDiff + diffOfDiff/2;
		} else if(diffOfDiff%2 != 0) {
			answer = smallDiff + (diffOfDiff+1)/2 + 1;
		}


		System.out.print(answer);

	}

}
