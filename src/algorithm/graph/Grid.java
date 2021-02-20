package algorithm.graph;

import java.util.Scanner;

public class Grid {

	static boolean[][] seen;

	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};

	static int H;
	static int W;

	static String[][] field;

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		H = scan.nextInt();
		W = scan.nextInt();

		field = new String[H][W];

		for(int h = 0; h < H; h++) {
			field[h] = scan.next().split("");
		}

		scan.close();

//		for(int h = 0; h < H; h++) {
//			System.out.print(Arrays.toString(field[h]));
//		}


		int sh = 0, sw = 0, gh = 0, gw = 0;

		for(int h = 0; h < H; h++) {
			for(int w = 0; w < W; w++) {
				if(field[h][w].equals("s")) {
					sh = h; sw = w;
				}
				if(field[h][w].equals("g")) {
					gh = h; gw = w;
				}
			}
		}

		seen = new boolean[H][W];

		dfs(sh, sw);

		if(seen[gh][gw]) {
			System.out.print("Yes");
		} else {
			System.out.print("No");
		}

	}

	static void dfs(int h, int w) {

		seen[h][w] = true;

		for(int dir = 0; dir < 4; dir++) {
			int nh = h + dx[dir];
			int nw = w + dy[dir];

			if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
			if(field[nh][nw].equals("#")) continue;

			if(seen[nh][nw]) continue;

			dfs(nh, nw);
		}
	}
}
