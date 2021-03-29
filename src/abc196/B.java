package abc196;

import java.util.Scanner;
import java.util.regex.Pattern;

public class B {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String M = scan.next();

		scan.close();

		String ans = M.split(Pattern.quote("."))[0];

		System.out.print(ans);

	}

}
