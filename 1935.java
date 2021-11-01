import java.util.Scanner;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] arr = new int[num+1];
		String s = sc.next();

		for(int i=0; i<num; i++)
			arr[i] = sc.nextInt();

		Stack<Double> stack = new Stack<Double>();

		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if(c == '+') {
				double num2 = stack.pop();
				double num1 = stack.pop();
				double num3 = num1 + num2;
				stack.add(num3);
			}
			else if (c == '-') {
				double num2 = stack.pop();
				double num1 = stack.pop();
				double num3 = num1 - num2;
				stack.add(num3);
			}
			else if (c == '/') {
				double num2 = stack.pop();
				double num1 = stack.pop();
				double num3 = num1 / num2;
				stack.add(num3);
			}
			else if (c == '*') {
				double num2 = stack.pop();
				double num1 = stack.pop();
				double num3 = num1 * num2;
				stack.add(num3);
			}
			else {
				int idx = c - 'A';
				stack.add((double) arr[idx]);
				
			}
		}
		double ans = stack.pop();
		System.out.printf("%.2f\n", ans);

	}

}

