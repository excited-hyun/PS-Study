import java.util.*;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<Integer> q = new LinkedList<Integer>();
		
		int N = sc.nextInt();
		
		for(int i=1; i<=N; i++) {
			q.add(i);
		}
		
		while(q.size()>1) {
			q.poll();
			
			int num = q.poll();
			q.add(num);
		}
		
		int result = q.poll();
		System.out.println(result);
	}
}

