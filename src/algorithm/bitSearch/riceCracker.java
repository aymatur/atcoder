package algorithm.bitSearch;

import java.util.Scanner;

public class riceCracker {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int r = scan.nextInt();
		int c = scan.nextInt();

		int[][] rc = new int[r][c];

		for(int i = 0; i < r;i++) {
			for(int j = 0; j < c; j++) {
				rc[i][j] = scan.nextInt();
			}
		}

		scan.close();

		System.out.print(count(rc, r, c));
	}

	static int count(int[][] array, int row, int column) {
		int max = 0;
		int count = 0;
		int pattern1, pattern2 = 0;
		for(int i = 0; i < Math.pow(2, row+1); i++) {
			count = 0;
			for(int c = 0; c < column ; c++) {
				pattern1 = 0;
				pattern2 = 0;
				for(int r = 0; r < row ; r++) {
					if((((int)Math.pow(2, r) & i) >= 1)) {
						pattern1 = array[r][c] == 0 ? pattern1+1 : pattern1;
						pattern2 = array[r][c] == 1 ? pattern2+1 : pattern2;
					} else {
						pattern1 = array[r][c] == 1 ? pattern1+1 : pattern1;
						pattern2 = array[r][c] == 0 ? pattern2+1 : pattern2;
					}
				}
				count = pattern1 > pattern2 ? count + pattern1 : count + pattern2;
			}
			max = max > count ? max : count;
		}

		return max;
	}

}
