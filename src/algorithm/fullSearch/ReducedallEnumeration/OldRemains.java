package algorithm.fullSearch.ReducedallEnumeration;

import java.util.Arrays;
import java.util.Scanner;

public class OldRemains {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		int[] x = new int[N];
		int[] y = new int[N];

		for(int i = 0; i < N; i++) {
			x[i] = scan.nextInt();
			y[i] = scan.nextInt();
		}

		scan.close();

		int[] copyX = Arrays.copyOf(x, N);
		int[] copyY = Arrays.copyOf(x, N);

		Arrays.sort(copyX);
		Arrays.sort(copyY);

		int minX = copyX[0];
		int maxX = copyX[N-1];
		int minY = copyY[0];
		int maxY = copyY[N-1];

		boolean[][] isExist = new boolean[maxX+1][maxY+1];

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				isExist[x[i]][y[i]] = true;
			}
		}

		int diffX = 0;
		int diffY = 0;

		int nextX1 = 0;
		int nextX2 = 0;
		int nextY1 = 0;
		int nextY2 = 0;

		int maxSquare = 0;

		for(int i = 0; i < N - 1; i++) {
			for(int j = i + 1; j < N; j++) {
				diffX = Math.abs(x[i] - x[j]);
				diffY = Math.abs(y[i] - y[j]);

				nextX1 = x[j] - diffY;
				nextX2 = x[j] + diffY;
				nextY1 = y[j] + diffX;
				nextY2 = y[j] - diffX;


				if(nextX1 >= minX && nextX1 <= maxX
						&&nextY1>=minY &&nextY1 <= maxY) {
					if(isExist[nextX1][nextY1]) {
						nextX1 = x[i] - diffY;
						nextY1 = y[i] + diffX;

						if(nextX1 >= minX && nextX1 <= maxX
								&&nextY1>=minY &&nextY1 <= maxY) {
							if(isExist[nextX1][nextY1]) {
								maxSquare = maxSquare > Math.pow(diffX, 2) + Math.pow(diffY, 2)
								? maxSquare : (int)(Math.pow(diffX, 2) + Math.pow(diffY, 2));
							}
						}
					}
				}

				if(nextX2 >= minX && nextX2 <= maxX
						&&nextY2>=minY &&nextY2 <= maxY) {
					if(isExist[nextX2][nextY2]) {
						nextX2 = x[i] + diffY;
						nextY2 = y[i] - diffX;

						if(nextX2 >= minX && nextX2 <= maxX
								&&nextY2>=minY &&nextY2 <= maxY) {
							if(isExist[nextX2][nextY2]) {
								maxSquare = maxSquare > Math.pow(diffX, 2) + Math.pow(diffY, 2)
								? maxSquare : (int)(Math.pow(diffX, 2) + Math.pow(diffY, 2));
							}
						}
					}
				}
			}
		}

		System.out.print(maxSquare);

	}

}
