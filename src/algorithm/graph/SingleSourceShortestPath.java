package algorithm.graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class SingleSourceShortestPath {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int V = scan.nextInt();
		int E = scan.nextInt();
		int r = scan.nextInt();

		int[] s = new int[E];
		int[] t = new int[E];
		int[] d = new int[E];

		for(int i = 0; i < E; i++) {
			s[i] = scan.nextInt();
			t[i] = scan.nextInt();
			d[i] = scan.nextInt();
		}

		scan.close();

		List sMap = new ArrayList<HashMap<Integer, Integer>>();

		for(int i = 0; i < V; i++) {
			HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
			sMap.add(m);
		}

		for(int i = 0; i < E; i++) {
			HashMap<Integer, Integer> m = (HashMap<Integer, Integer>) sMap.get(s[i]);
			m.put(t[i], d[i]);
		}

		int[] ans = new int[V];
		for(int i = 0; i < V; i++) {
			ans[i] = Integer.MAX_VALUE;
		}

		int sum = 0;
		List passed = new ArrayList<Integer>();
		passed.add(r);

		ans = solve(sMap, ans, r, sum, passed);

		for(int i = 0; i < V; i++) {
			if(i == r) {
				System.out.println(0);
			} else if(ans[i] == Integer.MAX_VALUE) {
				System.out.println("INF");
			} else {
				System.out.println(ans[i]);
			}
		}

	}

	static int[] solve(List<Map<Integer,Integer>> m, int[] ans, int start, int sum, List a) {
		Map<Integer, Integer> next = m.get(start);
		Iterator<Integer> i = next.keySet().iterator();
		while(i.hasNext()) {
			Integer nextKey = i.next();
			if(a.contains(nextKey)) {
				continue;
			}
			a.add(nextKey);
			sum = sum + next.get(nextKey);
			if(ans[nextKey] > sum) ans[nextKey] = sum;
			ans = solve(m, ans, nextKey, sum, a);

		}

		return ans;

	}

}
