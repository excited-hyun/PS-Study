import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		PriorityQueue<Pair> pq = new PriorityQueue<>(); 	// A 전봇대 값을 기준으로 오름차순 
		ArrayList<Integer> arr = new ArrayList<Integer>();	// A의 증가하는 순서에 맞게 B전봇대값 저장 
		int[] dp = new int[N];
		
		// 입력 및 초기화 
		for(int i=0; i<N; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			pq.add(new Pair(a, b));
			dp[i] = 1;
		}
		
		// A값의 오름차순에 해당하는 B값 저장 
		while(!pq.isEmpty()) {
			Pair p = pq.poll();
			arr.add(p.b);
		}
		
		// 가장 긴 증가하는 부분수열 찾기 
		for(int i=0; i<N; i++) {
			int b = arr.get(i);
			
			int maxN = 0;
			for(int j=0; j<i; j++) {
				if(b < arr.get(j))
					continue;
				if(dp[j] > maxN)
					maxN = dp[j];
				
			}
			dp[i] = maxN+1;
		}
		
		// 존재가능한 최대 전깃줄 수 
		int save = 0;
		
		for(int i=0; i<N; i++) {
			if(dp[i] > save)
				save = dp[i];
		}
		
		System.out.println(N-save);
		
	}
	
	static class Pair implements Comparable<Pair>{
		int a, b;
		
		Pair(int a, int b){
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Pair o) {
			return this.a - o.a;
		}
	}

}

