
import java.util.Scanner;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		Queue<Truck> q = new LinkedList<>();

		int n, w, L;


		n = sc.nextInt();
		w = sc.nextInt();
		L = sc.nextInt();
		int[] truck = new int[n];

		for(int i=0; i<n; i++) {
			truck[i] = sc.nextInt();
		}

		int time = 0;			//현재 시간 
		int passed = 0;			//다리 지나간 트럭 수 
		int truckIdx = 0;		//다음에 다리에 올린 트럭 idx
		int truckCnt = 0;		//다리 위에 있는 트럭 수 
		int truckWeight = 0; 	//다리 위에 있는 트럭 무게 



		while(passed < n) {
			time++;

			//다리 건넌 트럭 있는지 확인!
			if(!q.isEmpty()) {
				int tTime = q.peek().time;
				int tWeight = q.peek().weight;
				// 다리 다 건넘!!
				if(time - tTime >= w) {
					passed++;
					q.remove();
					truckCnt--;
					truckWeight -= tWeight;
				}
			}

			//다리 위에 트럭 추가 
			if(truckIdx <n) {
				if(L >= truckWeight + truck[truckIdx] && w > truckCnt) {
					q.add(new Truck(time, truck[truckIdx]));
					truckCnt++;
					truckWeight += truck[truckIdx];
					truckIdx++;
				}
			}


		}


		System.out.println(time);
	}

	static class Truck{
		int time, weight;

		Truck(int time, int weight){
			this.time = time;
			this.weight = weight;

		}
	}

}

