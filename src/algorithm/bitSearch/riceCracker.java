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
		for(int i = 1; i < Math.pow(2, row+1); i++) {
			for(int j = 1; j < Math.pow(2, column+1); j++) {
				count = 0;
				for(int r = 0; r < row ; r++) {
					for(int c = 0; c < column ; c++) {
						if(((r & (i>>1)) >= 1) ^ ((c & (j>>1)) >= 1)) {
							count = array[r][c] == 1 ? count+1 : count;
						} else {
							count = array[r][c] == 0 ? count+1 : count;
						}
					}
				}
				max = max > count ? max : count;
			}
		}

		return max;
	}

}
