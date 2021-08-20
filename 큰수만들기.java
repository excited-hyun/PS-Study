class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int len = number.length();
        char maxN;
        int maxIdx = 0;
        int nowIdx = 0;
        int check = 1;
        int del = 0;
        
        while(del < k){
            maxN = '0';
            int cnt = -1;   //삭제한 숫자 수
            //앞에서부터 삭제가능한 범위 내에서 큰 숫자 찾기
            for(int i=nowIdx; i < k+check; i++){
                //'9'면 절대 삭제하지 않음
                if(number.charAt(i) =='9'){
                    maxN = number.charAt(i);
                    maxIdx = i;
                    cnt = i-nowIdx;
                    break;
                }
                if(number.charAt(i) > maxN){
                    maxN = number.charAt(i);
                    maxIdx = i;
                    cnt = i-nowIdx;
                }
            }
            answer += maxN;
            nowIdx = maxIdx+1;
            check++;        //삭제하지 않기로 선택한 숫자 수
            del += cnt;     //총 삭제 수
            
            //삭제를 숫자의 뒤에서 해야할 경우
            if(check > len-k)
                break;
        }
        //뒤에 더 추가해야할 숫자 수
        int left = len - k - check+1;
        for(int i = nowIdx; i < nowIdx+left; i++)
            answer += number.charAt(i);
        
        return answer;
    }
}
