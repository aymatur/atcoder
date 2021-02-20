package algorithm.graph;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class BasicDFS {

	static int[] first_order;
	static int[] last_order;
	static boolean[] seen;

	static int first_ptr = 0;
	static int last_ptr = 0;
	static int ptr = 0;

	public static void main(String[] args) {


		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int M = scan.nextInt();

		ArrayList<List<Integer>> graph = new ArrayList<>();

		for(int i = 0; i < N ; i++) {
			graph.add(new ArrayList<Integer>(0));
		}


		for(int i = 0; i<M; i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			graph.get(a).add(b);
			graph.get(b).add(a);

		}

		scan.close();

		System.out.println(Arrays.asList(graph).toString());

		first_ptr = 0;
		last_ptr = 0;

		first_order = new int[N];
		last_order = new int[N];

		seen = new boolean[N];

		dfs(graph, 0);

		for(int i = 0; i < N ; i++) {
			System.out.print(i+": "+first_order[i]+", "+last_order[i]);
			System.out.println("");
		}

		System.out.println(Arrays.asList(graph).toString());


	}

	static void dfs(List<List<Integer>> graph, int v) {

		first_ptr++;
		first_order[v] = first_ptr;
		seen[v] = true;

		for(Integer g : graph.get(v)) {
			if(seen[g]) continue;
			dfs(graph, g);
		}

		last_ptr++;
		last_order[v] = last_ptr;
	}

	static void dfsTimestamp(List<List<Integer>> graph, int v) {

		ptr++;
		first_order[v] = ptr;
		seen[v] = true;

		for(Integer g : graph.get(v)) {
			if(seen[g]) continue;
			dfs(graph, g);
		}

		ptr++;
		last_order[v] = ptr;
	}

}


