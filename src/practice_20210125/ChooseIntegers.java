package practice_20210125;
import java.util.Scanner;

public class ChooseIntegers {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int A = scan.nextInt();
		int B = scan.nextInt();
		int C = scan.nextInt();

		scan.close();

		int multipluedA = A;
		int surplus = multipluedA%B;
		int initialSurplus = A%B;

		String answer = "NO";

		if(initialSurplus == C) {
			answer = "YES";
		}else {
			while(true) {
				multipluedA += A;
				surplus = multipluedA%B;
				if(surplus == C) {
					answer = "YES";
					break;
				}
				if(surplus == initialSurplus) break;
			}
		}

		System.out.print(answer);

	}

}
