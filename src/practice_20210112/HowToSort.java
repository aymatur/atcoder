package practice_20210112;

import java.util.Arrays;
import java.util.Comparator;

public class HowToSort {

	public static void main(String[] args) {
		// プリミティブ型の場合は値の昇順で並び替え
		// オブジェクトの場合は、ComparableインターフェースのcompareToメソッドで並び替え

		int[] a = {2,5,4,7,4,9,};

		Integer[] b = {2,5,4,7,4,9,};

		Comparator<Integer> c = new Comparator<Integer>() {
			@Override
			public int compare(Integer n1, Integer n2) {
				return n2.compareTo(n1);
			}
		};


		// ソートする
		Arrays.sort(a);
		Arrays.sort(b,c);

		System.out.println("a: " + Arrays.toString(a));
		System.out.println("b: " + Arrays.toString(b));

	}

}
