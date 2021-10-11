import java.util.Scanner;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> truth = new ArrayList<>();
		
		int answer;
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		answer = M;
		
		ArrayList<Integer> [] party = new ArrayList[M];
		
		int cnt = sc.nextInt();
		for(int i=0; i<cnt; i++) {
			int people = sc.nextInt();
			truth.add(people);
		}
		
		for(int i=0; i<M; i++) {
			cnt = sc.nextInt();
			party[i] = new ArrayList<>();
			int canLie = 1;
			
			for(int j=0; j<cnt; j++) {
				int people = sc.nextInt();
				party[i].add(people);
			}
		}
		
		Queue<Integer> q = new LinkedList<>();
		int[] partyCheck = new int[M];
		int[] peopleCheck = new int[N+1];
		
		for(int i=0; i<truth.size(); i++) {
			q.add(truth.get(i));
			peopleCheck[truth.get(i)] = 1;
			
		}
		
		while(!q.isEmpty()) {
			int now = q.poll();
			for(int i=0; i<M; i++) {
				if(partyCheck[i] == 1)
					continue;
				if(!party[i].contains(now))
					continue;
				for(int j=0; j<party[i].size(); j++) {
					int next = party[i].get(j);
					
					if(peopleCheck[next] == 1)
						continue;
					peopleCheck[next] = 1;
					q.add(next);
				}
				
				partyCheck[i] = 1;
				answer--;
			}
		}
		
		
		System.out.println(answer);
	}

}

