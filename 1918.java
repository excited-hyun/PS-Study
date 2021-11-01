import java.util.Scanner;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		Stack<Character> stack = new Stack<Character>();

		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if(c == '+') {
				if(stack.isEmpty())
					stack.add(c);
				else {
					while(!stack.isEmpty()) {
						char bef = stack.peek();
						if(bef == '*' || bef == '/' || bef == '-' || bef == '+') {
							stack.pop();
							System.out.print(bef);
						}
						else
							break;

					}
					stack.add(c);
				}
			}
			else if(c == '-') {
				if(stack.isEmpty())
					stack.add(c);
				else {
					while(!stack.isEmpty()) {
						char bef = stack.peek();
						if(bef == '*' || bef == '/' || bef == '-' || bef == '+') {
							stack.pop();
							System.out.print(bef);
						}
						else
							break;

					}
					stack.add(c);
				}
			}
			else if(c == '*') {
				if(stack.isEmpty())
					stack.add(c);
				else {
					while(!stack.isEmpty()) {
						char bef = stack.peek();
						if(bef == '*' || bef == '/') {
							stack.pop();
							System.out.print(bef);
						}
						else
							break;

					}
					stack.add(c);
				}

			}
			else if(c == '/') {
				if(stack.isEmpty())
					stack.add(c);
				else {
					while(!stack.isEmpty()) {
						char bef = stack.peek();
						if(bef == '*' || bef == '/') {
							stack.pop();
							System.out.print(bef);
						}
						else
							break;

					}
					stack.add(c);
				}
			}
			else if(c == '(') {
				stack.add(c);
			}
			else if(c == ')') {
				while(!stack.isEmpty()) {
					char bef = stack.peek();
					if(bef == '(') {
						stack.pop();
						break;
					}
					else {
						stack.pop();
						System.out.print(bef);
					}
				}
			}
			else {
				System.out.print(c);
			}
		}

		while(!stack.isEmpty()) {
			char bef = stack.pop();
			System.out.print(bef);
		}

		System.out.println();

	}

}

