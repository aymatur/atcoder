import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		String s = scan.next();

		scan.close();

		String[] slist = s.split("");

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < slist.length; i += 2) {
			sb.append(slist[i]);
		}

		System.out.print(sb.toString());

	}

}
