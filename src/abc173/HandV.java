package abc173;

import java.util.Scanner;

public class HandV {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int H = sc.nextInt();
		int W = sc.nextInt();
		int K = sc.nextInt();

		String[] line = new String[H];

		for(int i = 0; i < H; i++){
			line[i] = sc.next();
		}

		sc.close();

		String[][] map = new String[H][W];

		for(int i = 0; i < H; i++) {
			map[i] = line[i].split("");
		}

		int ans = 0;

		for(int bitH = 0; bitH < (1 << H); ++bitH ) {
			for(int bitW = 0; bitW < (1 << W); ++bitW) {
				int cnt = 0;
				for(int i = 0; i < H; ++i) {
					if((bitH & (1 << i)) > 0) continue;
					for(int j = 0; j < W; ++j) {
						if((bitW & (1 << j)) > 0) continue;
						if(map[i][j].equals("#")) cnt++;
					}
				}
				if(cnt == K) ans++;
			}
		}
		System.out.print(ans);
	}

}
