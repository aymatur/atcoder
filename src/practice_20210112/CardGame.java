package practice_20210112;

import java.util.Arrays;
import java.util.Scanner;

public class CardGame {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();

		int[] dekki = new int[N];
		for(int i =0; i<N ; i++) {
			dekki[i] = scan.nextInt();
		}
		scan.close();
		Arrays.sort(dekki);

		int alice = 0;
		int bob = 0;
		for(int i = N-1; i>=0; i = i-2) {
			if(i == -1)break;
			alice += dekki[i];
			if(i == 0) break;
			bob += dekki[i-1];
		}
		int answer = alice - bob;
		System.out.println(answer);

	}

}
