import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		String A = scan.next();
		String B = scan.next();

		scan.close();

		BigDecimal bigA = new BigDecimal(A);
		BigDecimal bigB = new BigDecimal(B);

		BigDecimal value = bigA.multiply(bigB).setScale(0, RoundingMode.DOWN);


		System.out.print(value);
	}

}
