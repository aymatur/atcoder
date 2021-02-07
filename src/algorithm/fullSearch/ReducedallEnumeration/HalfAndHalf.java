package algorithm.fullSearch.ReducedallEnumeration;

import java.util.Scanner;

public class HalfAndHalf {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int A = scan.nextInt();
		int B = scan.nextInt();
		int C = scan.nextInt();
		int X = scan.nextInt();
		int Y = scan.nextInt();

		scan.close();

		boolean mixCheapFlag = A+B > C*2 ? true : false;

		boolean aIsMore = X > Y ? true : false;

		int caseNum = 0;

		if( X > Y) {
			caseNum = A < 2*C ? 1 : 0;
		} else if( X < Y) {
			caseNum = B < 2*C ? 2 : 0;
		}

		int diff = Math.abs(X - Y);
		int ans = 0;

		if(!mixCheapFlag) {
			ans = X*A + Y*B;
		}else if(caseNum == 1) {
			ans = Y*2*C + A*diff;
		}else if(caseNum == 2) {
			ans = X*2*C + B*diff;
		}else {
			ans = aIsMore ? X*2*C : Y*2*C;
		}

		System.out.print(ans);

	}

}
