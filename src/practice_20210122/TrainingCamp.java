package practice_20210122;

import java.util.Scanner;

public class TrainingCamp {

	public static void main(String[] args) {

				Scanner scan = new Scanner(System.in);

				long N = scan.nextInt();

				scan.close();

				long answer = 1;
				long d = 1000000007;

				for(int i = 1; i <= N; i++) {
					answer = answer*i%d;
				}

				System.out.print(answer);



	}

}
