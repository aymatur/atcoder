package abc171;

import java.util.Scanner;

public class OneQuadrillionandOneDalmatians {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		long N = sc.nextLong();

		sc.close();

		String ans = convert(N);

		System.out.print(ans);


	}

	public static String convert(long N) {

		String ans = "";

		long remain = N;
		long surplus = 0;
		char add = 0;
		int i = 0;
		while(remain > 0) {

			surplus = remain%26;
			remain = remain/26;

			if(surplus == 0 && remain > 0) {
				ans = "z" + ans;
				remain--;
			}
			else {
				add = (char) (surplus + 96);
				ans = add + ans;
			}

//			System.out.println("----------------");
//			System.out.println(++i +"回目");
//			System.out.println("あまり："+surplus);
//			System.out.println("商："+remain);
//			System.out.println("----------------");

		}

		return ans;
	}

}
