package practice_20200111;
import java.text.MessageFormat;
import java.util.Arrays;

public class ManipulateArray {

	public static void main(String[] args) {

		String format = "--------------{0}--------------";

		//配列のコピー
		int[] a = {1,2,4,5,3};
		// これではaとbはメモリ上で同じ値を参照しているためbをsortしてもaとbに違いがみられない
		int[] b = a;
		Arrays.sort(b);
		System.out.println(MessageFormat.format(format, "a=bで代入"));
		System.out.println("a: "+Arrays.toString(a));
		System.out.println("b: "+Arrays.toString(b));

		//配列aを全範囲コピーする
		int[] c = Arrays.copyOf(a, a.length);
		System.out.println(MessageFormat.format(format, "Arrays.copyOfで丸ごとコピー"));
		System.out.println("a: "+Arrays.toString(a));
		System.out.println("c: "+Arrays.toString(c));
		Arrays.sort(c);
		System.out.println("ソートしたc: "+Arrays.toString(c));

		// 範囲指定してコピーする
		int[] d = Arrays.copyOfRange(a, 0, 3);
		int[] e = Arrays.copyOfRange(a, 0, 4);
		int[] f = Arrays.copyOfRange(a, 1, 5);
		System.out.println(MessageFormat.format(format, "Arrays.copyOfRangeでコピー"));
		System.out.println("a: "+Arrays.toString(a));
		System.out.println("d: "+Arrays.toString(d));
		System.out.println("e: "+Arrays.toString(e));
		System.out.println("f: "+Arrays.toString(f));

		// 要素の位置を取得
		// int[]型の変数をArrays.asListでlistにした際の挙動については注意が必要
 		int indexOfFive = Arrays.asList(a).indexOf(5);
		System.out.println(MessageFormat.format(format, "int[]型の変数をArrays.asListでlistにした際の挙動"));
 		System.out.println("5の位置: "+indexOfFive);

 		System.out.println(MessageFormat.format(format, "Arrays.asList(a)"));
 		System.out.println(Arrays.toString(Arrays.asList(a).get(0)));
 		System.out.println(Arrays.asList(a).get(0).getClass());

 		// Integer型を使用する
 		Integer[] aInteger = {1,2,4,5,3};
		System.out.println(MessageFormat.format(format, "Integer[]をlistに変換して要素を検索"));
 		indexOfFive = Arrays.asList(aInteger).indexOf(5);
 		System.out.println("5の位置: "+indexOfFive);

 		// binarySearchメソッドはソートしてから使用する
 		System.out.println(MessageFormat.format(format, "ArraysのbinarySearch"));
 		int[] notSortedArray = {5,2,4,1,3};
 		int[] sortedArray = {1,2,3,4,5};
 		System.out.println("ソートしてない場合"+Arrays.binarySearch(notSortedArray, 1));
 		System.out.println("ソートした場合"+Arrays.binarySearch(sortedArray, 1));

	}

}
