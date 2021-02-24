package algorithm.graph;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Ki {

	static int[] px;

	static boolean[] added;

	static List<Integer>[] graph;

	public static void main(String[] args) {

		Scanner scan  = new Scanner(System.in);

		int N = scan.nextInt();
		int Q = scan.nextInt();

		graph = new ArrayList[N];

		for(int i = 0; i < N ; i++) {
			graph[i] = new ArrayList<Integer>(0);
		}

		int[] a = new int[N-1];
		int[] b = new int[N-1];

		for(int i = 0; i < N-1; i++) {
			a[i] = scan.nextInt() - 1;
			b[i] = scan.nextInt() - 1;
		}

		px = new int[N];

		for(int i = 0; i < Q; i++) {
			px[scan.nextInt() - 1] += scan.nextInt();
		}

		scan.close();

		for(int i = 0; i < N-1; i++) {
			graph[a[i]].add(b[i]);
			graph[b[i]].add(a[i]);
		}

		Queue<Integer> q = new ArrayDeque<>();
		q.offer(0);
		boolean[] marked = new boolean[N];
		marked[0] = true;
		while (!q.isEmpty()) {
			int v = q.remove();
			for (int w : graph[v]) {
				if (marked[w])
					continue;
				marked[w] = true;
				q.add(w);
				px[w] += px[v];
			}
		}

		Arrays.stream(px).forEach(i -> System.out.print(i + " "));

	}

//	static void dfs(int v, int par, int sum) {
//
//		px[v] += sum;
//		for(int to : graph[v]) {
//			if(to == par)continue;
//			dfs(to, v, px[v]);
//		}
//
//	}

}
