import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int A = scan.nextInt();
		int B = scan.nextInt();

		scan.close();

		int sum = 0;
		int total = 0;

		for(int i = 1; i<=N; i++) {
			sum = findSumOfDigit(i);
			if(A <= sum && sum <= B) total += i;
		}

		System.out.println(total);


	}
	static int findSumOfDigit(int num) {
		int sum = 0;
		while(num>0) {
			sum += num%10;
			num = num/10;
		}
		return sum;
	}

}
