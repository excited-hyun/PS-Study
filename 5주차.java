class Solution {
    int answer = 0;
    public int solution(String word) {
        //빈 문자부터 시작
        dfs(0, "", word);
        return answer;
    }
    
    public boolean dfs(int cnt, String now, String word){
        //같은 단어 찾으면 true 반환
        if(word.equals(now))
            return true; 
        //같은 단어 찾기 전 길이 5 -> false 반환
        if(cnt == 5)
            return false;
        
        //A,E,I,O,U 순서로 하나씩 붙이면서 재귀 호출
        answer++;
        if(dfs(cnt+1, now+'A', word))
            return true;
        answer++;
        if(dfs(cnt+1, now+'E', word))
            return true;
        answer++;
        if(dfs(cnt+1, now+'I', word))
            return true;
        answer++;
        if(dfs(cnt+1, now+'O', word))
            return true;
        answer++;
        if(dfs(cnt+1, now+'U', word))
            return true;
        
        
        
        return false;
    }
}
