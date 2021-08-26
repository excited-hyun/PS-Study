class Solution {
    public int solution(int n) {
        int answer = 0;
        //n을 2진수 변환시 1이 몇개 인지
        int cnt = countOne(n);
        int num = n+1;
        //n+1부터 확인하면서 찾기
        while(true){
            int check = countOne(num);
            if(check == cnt){
                answer =  num;
                break;
            }
            num++;
        }
        return answer;
    }
    
    //2진수 변환 시 1이 몇개 있는지 세주는 함수
    int countOne(int num){
        int cnt = 0;
        
        while(num > 0){
            if(num%2 == 1)
                cnt++;
            num = num / 2;
        }
        return cnt;
    }
}
