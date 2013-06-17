import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader bReader = new BufferedReader(new InputStreamReader(System.in));
		String code = bReader.readLine();

		boolean[] found = new boolean[27];
		Arrays.fill(found, Boolean.FALSE);
		int count = 10;

		BigInteger ans = BigInteger.valueOf(1);
		int tenCount = 0;
		long aProduct = 1;

		for(int i = 0; i < code.length(); i++) {
			char c = code.charAt(i);
			if (c >= 'A' && c <= 'J'){
				if (!found[c-'A']){
					found[c-'A'] = true;
					if (i > 0){
						aProduct = aProduct*count;
						count--;
					}
					else {
						aProduct = aProduct*9;
						count--;
					}
				}
			}
			else {
				if (c == '?' && i > 0)
					tenCount++;
				else if (c == '?' && i == 0)
					ans = ans.multiply(BigInteger.valueOf(9));
			}
		}
		ans = ans.multiply(BigInteger.valueOf(aProduct));

		BigInteger ten = BigInteger.valueOf(10);
		ten = ten.pow(tenCount);

		ans = ans.multiply(ten);

		System.out.println(ans);
	}
}