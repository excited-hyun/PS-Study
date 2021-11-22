import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] arr = new int[N];
		int answer = N+1;
		int idx = 0;
		int sum = 0;
		
		Queue<Integer> q = new LinkedList<Integer>();
		
		
		for(int i=0; i<N; i++)
			arr[i] = sc.nextInt();
		
		
		while(idx<N) {
			q.add(arr[idx]);
			sum+= arr[idx];
			while(sum > S && q.size() > 0) {
				int f = q.peek();
				if(sum-f >= S) {
					sum = sum-f;
					q.poll();
				}
				else
					break;
			}
			
			if(sum >= S) {
				if(q.size() < answer)
					answer = q.size();
			}
			
			idx++;
		}
		
		if(answer == N+1)
			answer = 0;
		
		System.out.println(answer);
	}

}

