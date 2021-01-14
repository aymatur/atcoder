package practice20210113;

import java.util.Scanner;

public class Hakutyumu {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String S = scan.next();

		scan.close();

		StringBuilder sb = new StringBuilder(S);
		String reversedS = sb.reverse().toString();

		String[] findings = {"dream","dreamer","erase","eraser"};

		String[] reversedFindings = new String[4];

		for(int i = 0; i < 4 ; i++) {
			StringBuilder sb1 = new StringBuilder(findings[i]);
			reversedFindings[i] = sb1.reverse().toString();
		}

		boolean flag = true;
		for(int i = 0; i<reversedS.length();) {
			boolean flag2 = false;
			for(int j =0; j<4;j++) {
				String d = reversedFindings[j];
				if( i < reversedS.length() && (i + d.length() <= reversedS.length())) {
				if(reversedS.substring(i,i+d.length()).equals(d)) {
					flag2 = true;
					i += d.length();
				}
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
