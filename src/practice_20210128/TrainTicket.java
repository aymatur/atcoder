package practice_20210128;

import java.util.Scanner;

public class TrainTicket {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		String num = scan.next();

		scan.close();

		String[] nums = num.split("");

		int A = Integer.parseInt(nums[0]);
		int B = Integer.parseInt(nums[1]);
		int C = Integer.parseInt(nums[2]);
		int D = Integer.parseInt(nums[3]);

		int sum = A;

		String op1 = "";
		String op2 = "";
		String op3 = "";

		boolean flag = false;

		for(int i = 0; i < 2; i++) {
			sum = i == 0 ? sum + B: sum - B;
			op1 = i == 0 ? "+" : "-";
			for(int j = 0; j < 2; j++) {
				sum = j == 0 ? sum + C: sum - C;
				op2 = j == 0 ? "+" : "-";
				for(int k = 0; k < 2; k++) {
					sum = k == 0 ? sum + D: sum - D;
					op3 = k == 0 ? "+" : "-";
					if(sum == 7) {
						flag = true;
						break;
					}
					sum = k == 0 ? sum - D: sum + D;
				}
				if(flag) break;
				sum = j == 0 ? sum - C: sum + C;
			}
			if(flag) break;
			sum = i == 0 ? sum - B: sum + B;
		}

		System.out.print(A+op1+B+op2+C+op3+D+"="+7);



	}

}
