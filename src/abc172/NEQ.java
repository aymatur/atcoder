package abc172;

import java.util.Scanner;

public class NEQ {

	public static void main(String[] args) {
		
		int base = 1000000007;
		
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		
		int M = sc.nextInt();
		
		sc.close();
		
		long aNum = 1;
		
		// Aの並べ方
		for(int i = M; i > M - N; i-- ) {
			aNum = aNum * i % base;
		}
		
		long bNum = 1;
		// Bの並べ方
		for(int i = M; i > M - N; i-- ) {
			bNum = bNum * i % base;
		}

	}

}
