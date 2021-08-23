class Solution {
    public long[] solution(long[] numbers) {
        int len = numbers.length;
        long[] answer = new long[len];
        for(int i=0; i<len; i++){
            //짝수
            //ans = num + 1
            if(numbers[i] % 2 == 0){
                answer[i] = numbers[i] + 1;
            }
            //홀수
            //ans = num + 2^(cnt)
            else{
                long tmp = numbers[i];
                long cal=1;
                int cnt=0;
                //1이 몇개 연속되는지 찾기
                while(tmp>0){
                    if(tmp % 2 == 1)
                        cnt++;
                    else
                        break;
                    tmp /= 2;
                }
                for(int j=0; j<cnt-1; j++){
                    cal*=2;
                }
                answer[i] = numbers[i] + cal;
            }
        }
        return answer;
    }
}
