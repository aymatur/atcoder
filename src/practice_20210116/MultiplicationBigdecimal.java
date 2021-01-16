package practice_20210116;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.MessageFormat;

public class MultiplicationBigdecimal {

	public static void main(String[] args) {
//		Scanner scan = new Scanner(System.in);
//
//		String A = scan.next();
//		String B = scan.next();
//
//		scan.close();

		String formatLine = "--------------{0}--------------";

		// BigDecimal型を使った計算
		String A = "0.05";
		String B = "7";

		BigDecimal bigA = new BigDecimal(A);
		BigDecimal bigB = new BigDecimal(B);

		BigDecimal value = bigA.multiply(bigB);
		BigDecimal valueRoundDown = bigA.multiply(bigB).setScale(0, RoundingMode.DOWN);

		System.out.println(MessageFormat.format(formatLine, "1.10×198の計算"));

		System.out.println(MessageFormat.format(formatLine, "BigDecimalここから"));
		System.out.println(value);
		System.out.println(MessageFormat.format(formatLine, "BigDecimal小数点以下切り捨て"));
		System.out.println(valueRoundDown);
		System.out.println(MessageFormat.format(formatLine, "BigDecimalここまで"));

		// double型での計算
		System.out.println(MessageFormat.format(formatLine, "doubleここから"));
		double dA = 0.05;
		double dB = 7;
		double answerD = dA*dB;
		System.out.println(answerD);
		System.out.println(MessageFormat.format(formatLine, "doubleここまで"));
	}

}
