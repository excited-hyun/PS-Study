import java.util.*;

public class Solution {

	static int N, K;
	static HashMap<Character, Integer> m = new HashMap<Character, Integer>();
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		m.put('0', 0); m.put('1', 1); m.put('2', 2); m.put('3', 3); 
		m.put('4', 4); m.put('5', 5); m.put('6', 6); m.put('7', 7); 
		m.put('8', 8); m.put('9', 9); m.put('A', 10); m.put('B', 11); 
		m.put('C', 12); m.put('D', 13); m.put('E', 14); m.put('F', 15); 
		
		int T = sc.nextInt();
		
		for(int tc=1; tc<=T; tc++) {
			LinkedList<Character> list = new LinkedList<>();
			HashSet<Integer> s = new HashSet<>();
			
			N = sc.nextInt();
			K = sc.nextInt();
			String num = sc.next();
			
			for(int i=0; i<N; i++) {
				
				list.add(num.charAt(i));
			}
			
			int byun = N/4;
			
			// 확인해야할 모든 회전에 대해서 확인 
			for(int i=0; i<N/4; i++) {
				//4개의 변에 대해 10진수 변환 
				for(int j=0; j<4; j++) {
					int n = 0;
					
					// 한 변의 16진수들을 10진수 변환 
					for(int l = 0; l<byun; l++) {
						char now = list.get(l+j*byun);
						int deci = m.get(now);
						n = n*16 + deci;
					}
					//HashSet에 10진수 숫자 저장 
					s.add(n);
				}
				
				// 회전 수행 
				char back = list.pollLast();
				list.addFirst(back);
			}
			
			// 내림차순 정렬 
			LinkedList<Integer> l = new LinkedList(s);
			Collections.sort(l, Comparator.reverseOrder());
			
			// K번째 값 출력 
			System.out.println("#"+tc+" "+l.get(K-1));
			
		}

	}

}

