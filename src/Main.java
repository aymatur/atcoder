import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String S = scan.nextLine();

		scan.close();

		StringBuilder sb = new StringBuilder(S);
		String reversedS = sb.reverse().toString();

		String[] findings = {"dream","dreamer","erase","eraser"};

		for(String s : findings) {
			StringBuilder sb1 = new StringBuilder(s);
			s = sb1.reverse().toString();
		}

		boolean flag = true;
		for(int i = 0; i<S.length();) {
			boolean flag2 = false;
			for(int j =0; j<4;j++) {
				String d = findings[j];
				if(S.substring(i,d.length()).equals(d)) {
					flag2 = true;
					i += d.length();
				}
			}
			if(!flag2) {
				flag = false;
				break;
			}
		}

		if(flag) {
			System.out.print("YES");
		}else {
			System.out.print("NO");
		}
	}

}
