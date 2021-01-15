package practice_20210116;

import java.util.Scanner;

public class ConnectString {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String s = scan.next();

		scan.close();

		String answer = connectByStringBuilder(s);

		System.out.print(answer);

	}

	static String connectByStringBuilder(String s) {
		String[] slist = s.split("");

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < slist.length; i += 2) {
			sb.append(slist[i]);
		}

		return sb.toString();

	}

	static String connectByStringBufferr(String s) {
		String[] slist = s.split("");

		StringBuffer sb = new StringBuffer();

		for (int i = 0; i < slist.length; i += 2) {
			sb.append(slist[i]);
		}

		return sb.toString();

	}

}
