package practice_20210120;

import java.util.Scanner;

public class Grid {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int H = scan.nextInt();
		int W = scan.nextInt();


		String[][] s = new String[H][W];

		for(int i = 0; i < H; i++) {
			s[i] = scan.next().split("");
		}

		scan.close();

		int num = 0;

		StringBuilder sb = new StringBuilder();
		String[] result = new String[H];

		for(int i = 0; i<H; i++) {
			for(int j = 0; j<W; j++) {
				if(s[i][j].equals(".")) {
					for(int k = -1; k <2; k++) {
						for(int l = -1; l <2; l++) {
							if(0 <= i+k
									&& i+k < H
									&& 0 <= j+l
									&& j+l < W) {
								if(s[i+k][j+l].equals("#")) num++;
							}
						}
					}
					s[i][j] = Integer.toString(num);
					num = 0;
				}
				sb.append(s[i][j]);
			}
			result[i] = sb.toString();
			sb = new StringBuilder();
		}

		for(int i = 0; i <H; i++) {
			System.out.println(result[i]);
		}

	}

}
