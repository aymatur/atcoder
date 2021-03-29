package abc196;

import java.util.Scanner;

public class D {

	static int H;
	static int W;
	static int ans = 0;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		H = scan.nextInt();
		W = scan.nextInt();
		int A = scan.nextInt();
		int B = scan.nextInt();

		scan.close();

		dfs(0,0,A,B);

		System.out.print(ans);

	}

	static void dfs(int i, int bit, int A, int B) {
		if(i == H*W) {
			ans++;
			return;
		}
		if((bit >> i & 1)>0) {
			dfs(i+1, bit, A, B);
			return;
		}
		if(B > 0) {
			dfs(i+1, bit| 1<< i | 1 << (i+1), A-1, B);
		}
		if(A > 0) {
			if((i % W != W - 1) && !(( bit & 1 << (i + 1)) > 0)) {
				dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B);
			}
			if(i + W < H * W) {
				dfs(i + 1, bit | 1 << i | 1 << (i + W), A - 1, B);
			}
		}
	}

}
