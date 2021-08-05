class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        int[] alpha = new int[26];
        int temp;
        int bef, after, sw;
        
        for(String data : skill_trees){
            
            //idx를 100으로 초기화
            for(int i=0; i<26; i++)
                alpha[i] = 100;
            
            //스킬트리의 스킬 순서 저장.'A'는 alpha[0]에 저장됨.
            for(int i=0; i<data.length(); i++){
                temp = data.charAt(i)-'A';
                alpha[temp] = i;
            }
            
            temp = skill.charAt(0)-'A';
            bef = alpha[temp];
            sw = 1;
            //배울 수 있는지 확인
            for(int i=1; i<skill.length(); i++){
                temp = skill.charAt(i)-'A';
                after = alpha[temp];
                
                //현재 배우는 skill이 이전에 배운 스킬보다
                //선행되어야하는 경우 -> 불가능
                if(after < bef){
                    sw = 0;
                    break;
                }
                //차례로 배운 경우 비교할 이전 skill의 idx를 현재꺼로 업데이트
                else{
                    bef = after;
                }
                
            }
            //가능한 스킬 트리
            if(sw==1){
                answer++;
            }
                
        }
        return answer;
    }
}
