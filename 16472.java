import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int answer = 0;
		int N = sc.nextInt();
		int[] idx = new int[26];

		for(int i=0; i<26; i++)
			idx[i] = -1;

		String s = sc.next();

		Queue<Alphabet> q = new LinkedList<Alphabet>();
		int k = 0;
		int diff = 0;

		while(k<s.length()) {
			char c = s.charAt(k);
			q.add(new Alphabet(k, c));
			if(idx[c-'a'] == -1) {
				diff++;
			}
			idx[c-'a'] = k;


			while(diff > N) {
				Alphabet f = q.poll();
				if(f.index == idx[f.alpha-'a']) {
					idx[f.alpha-'a'] = -1;
					diff--;
					break;
				}
			}

			if(answer < q.size())
				answer = q.size();
			
			k++;

		}

		System.out.println(answer);
	}

	static class Alphabet {
		int index;
		char alpha;

		Alphabet(int index, char alpha) {
			this.index = index;
			this.alpha  = alpha;
		}
	}

}

