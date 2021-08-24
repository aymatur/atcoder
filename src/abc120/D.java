package abc120;

import java.util.Arrays;
import java.util.Scanner;

public class D {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int m = scan.nextInt();

		UnionFind uf = new UnionFind(n);

		int[] bridge = new int[m];

		for(int i = 0; i < n; i++) {
			int a = scan.nextInt() - 1;
			int b = scan.nextInt() - 1;
			uf.unite(a, b);
		}

		scan.close();

		int res = 0;

		for(int i = 0; i < n; i++) {
			if(uf.root(i) != i) res++;
		}

		System.out.print(res);


	}

	static class UnionFind {
		int[] par, siz;

		UnionFind(int n){
			par = new int[n];
			siz = new int[n];
			Arrays.stream(par).forEach(i -> i = -1);
			Arrays.stream(siz).forEach(i -> i = 1);
		}

		int root(int x) {
			if(par[x] == -1) return x;
			else return par[x] = root(par[x]);
		}

		boolean issame(int x, int y) {
			return root(x) == root(y);
		}

		boolean unite(int x, int y) {
			x = root(x); y = root(y);

			if(x == y) return false;

			if(siz[x] < siz[y]) swap(x, y);

			par[y] = x;
			siz[x] += siz[y];
			return true;
		}

		void swap(int x, int y) {
			int tmp = x;
			x = y;
			y = tmp;
		}

		void destroy(int x) {
			par[x] = -1;
		}
	}
}
