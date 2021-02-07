package algorithm.fullSearch.ReducedallEnumeration;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class LuckyPIN {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();

		String S = scan.next();

		scan.close();

		int firstIndex = 0;
		int secondIndex = 0;
		int thirdIndex = 0;

		List sList = Arrays.asList(S.split(""));
		List tmpList = new ArrayList<String>();

		int ans = 0;

		for(int i = 0; i < 10; i++ ) {
			firstIndex = sList.indexOf(Integer.toString(i));
			if(firstIndex < 0) continue;
			tmpList = Arrays.asList(Arrays.copyOfRange(S.split(""), firstIndex + 1, sList.size()));
			for(int j = 0; j < 10; j++ ) {
				secondIndex = tmpList.indexOf(Integer.toString(j));
				if(secondIndex < 0) continue;
				for(int k = 0; k < 10; k++ ) {
					thirdIndex = tmpList.lastIndexOf(Integer.toString(k));
					if(secondIndex >= thirdIndex || thirdIndex < 0) continue;
					ans++;
				}
			}
		}

		System.out.print(ans);

	}

}
