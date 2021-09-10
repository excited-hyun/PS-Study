import java.util.Scanner;

public class Main {

	static int n;
	static int[] nums = new int[12];
	
	static int maxA = -1000000000;
	static int minA = 1000000000;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();

		for(int i=0; i<n; i++)
			nums[i] = sc.nextInt();

		int[] operand = new int[4];
		for(int i=0; i<4; i++)
			operand[i] = sc.nextInt();

		String temp = "";
		addOper(0, temp, operand);
		
		System.out.println(maxA);
		System.out.println(minA);

	}

	// 연산자 차례로 추가하는 함수 
	static void addOper(int cnt, String formula, int[] operand) {
		//연산자 모두 생성 완료!
		if(cnt == n-1)
			calc(formula);

		//각각의 연산자 추가 
		// plus +
		if(operand[0]!=0) {
			operand[0]--;
			addOper(cnt+1, formula+"+", operand);
			operand[0]++;
		}
		// minus -
		if(operand[1]!=0) {
			operand[1]--;
			addOper(cnt+1, formula+"-", operand);
			operand[1]++;
		}
		// mul *
		if(operand[2]!=0) {
			operand[2]--;
			addOper(cnt+1, formula+"*", operand);
			operand[2]++;
		}
		// div /
		if(operand[3]!=0) {
			operand[3]--;
			addOper(cnt+1, formula+"/", operand);
			operand[3]++;
		}


	}

	// 수식 계산하는 함수
	static void calc(String formula) {
		int result = nums[0];
		for(int i=1; i<n; i++) {
			char operand = formula.charAt(i-1);

			if(operand == '+') {
				result += nums[i];
			}
			else if(operand == '-') {
				result -= nums[i];
			}
			else if(operand == '*') {
				result *= nums[i];
			}
			else if(operand == '/') {
				result /= nums[i];
			}
		}
		if(result > maxA)
			maxA = result;
		if(result < minA)
			minA = result;
	}
}

