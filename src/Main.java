import java.util.Scanner;

public class Main {

	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		int[] A = new int[100001];

		int in = 0;

		long sum = 0;

		for(int i = 0; i < N; i++) {
			in = sc.nextInt();
			A[in]++;
			sum += in;
		}

		int Q = sc.nextInt();

		int[] B = new int[Q];
		int[] C = new int[Q];

		for(int i = 0; i < Q; i++) {
			B[i] = sc.nextInt();
			C[i] = sc.nextInt();
		}

		sc.close();

		int num = 0;
		int diff = 0;

		for(int i = 0; i < Q; i++) {
			num = A[B[i]];
			diff = C[i] - B[i];
			sum += diff*num;
			A[C[i]] += A[B[i]];
			A[B[i]] = 0;
			System.out.println(sum);
		}

	}

}
