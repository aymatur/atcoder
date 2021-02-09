package algorithm.graph;

import java.util.Scanner;

public class SingleSourceShortestPath {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int V = scan.nextInt();
		int E = scan.nextInt();
		int r = scan.nextInt();

		int[][] st = new int[V][V];

		int[] s = new int[E];
		int[] t = new int[E];
		int[] d = new int[E];

		for(int i = 0; i < E; i++) {
			s[i] = scan.nextInt();
			t[i] = scan.nextInt();
			d[i] = scan.nextInt();
		}

		scan.close();




	}

}
