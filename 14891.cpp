#include <cstdio>

int main (){
    char wheel[4][8];
    char temp[4][8];
    int k;
    int ans = 0;
    
    for(int i=0; i<4; i++){
        scanf("%s", wheel[i]);
    }
    
    for(int j=0; j<4; j++)
        for(int l=0; l<8; l++)
            temp[j][l] = wheel[j][l];
    
    scanf("%d", &k);
    int num, dir;
    for(int i=0; i<k; i++){
        scanf("%d %d", &num, &dir);
        //1번 톱니
        if(num == 1){
            
            //1번 부터 회전
            if(dir == 1){
                for(int j=0; j<7; j++){
                    temp[0][j+1] = wheel[0][j];
                }
                temp[0][0] = wheel[0][7];
            }
            else if(dir == -1){
                for(int j=0; j<7; j++){
                    temp[0][j] = wheel[0][j+1];
                }
                temp[0][7] = wheel[0][0];
            }
            //비교할 이전 톱니바퀴
            char bef = wheel[0][2];
            //다음꺼는 반대방향!
            int nowDir = -dir;
            for(int l=1; l<4; l++){
                //같은 경우 안돌아감
                if(bef == wheel[l][6])
                    break;
                
                if(nowDir == 1){
                    for(int j=0; j<7; j++){
                        temp[l][j+1] = wheel[l][j];
                    }
                    temp[l][0] = wheel[l][7];
                }
                else if(nowDir == -1){
                    for(int j=0; j<7; j++){
                        temp[l][j] = wheel[l][j+1];
                    }
                    temp[l][7] = wheel[l][0];
                }
                
                bef = wheel[l][2];
                nowDir = -nowDir;   //다음꺼는 반대방향!
            }
            
            
        }
        else if(num == 2){
            //2번 부터 회전
            if(dir == 1){
                for(int j=0; j<7; j++){
                    temp[1][j+1] = wheel[1][j];
                }
                temp[1][0] = wheel[1][7];
            }
            else if(dir == -1){
                for(int j=0; j<7; j++){
                    temp[1][j] = wheel[1][j+1];
                }
                temp[1][7] = wheel[1][0];
            }
            
            char bef = wheel[1][6];
            //다음꺼는 반대방향!
            int nowDir = -dir;
            //1번 회전
            if(bef != wheel[0][2]){
                if(nowDir == 1){
                    for(int j=0; j<7; j++){
                        temp[0][j+1] = wheel[0][j];
                    }
                    temp[0][0] = wheel[0][7];
                }
                else if(nowDir == -1){
                    for(int j=0; j<7; j++){
                        temp[0][j] = wheel[0][j+1];
                    }
                    temp[0][7] = wheel[0][0];
                }
            }
            //3, 4번 회전
            //3번과 1번은 회전방향이 동일!!
            bef = wheel[1][2];
            for(int l=2; l<4; l++){
                //같은 경우 안돌아감
                if(bef == wheel[l][6])
                    break;
                
                if(nowDir == 1){
                    for(int j=0; j<7; j++){
                        temp[l][j+1] = wheel[l][j];
                    }
                    temp[l][0] = wheel[l][7];
                }
                else if(nowDir == -1){
                    for(int j=0; j<7; j++){
                        temp[l][j] = wheel[l][j+1];
                    }
                    temp[l][7] = wheel[l][0];
                }
                
                bef = wheel[l][2];
                nowDir = -nowDir;       //다음꺼는 반대방향!
            }
            
        }
        else if(num == 3){
            //3번 부터 회전
            if(dir == 1){
                for(int j=0; j<7; j++){
                    temp[2][j+1] = wheel[2][j];
                }
                temp[2][0] = wheel[2][7];
            }
            else if(dir == -1){
                for(int j=0; j<7; j++){
                    temp[2][j] = wheel[2][j+1];
                }
                temp[2][7] = wheel[2][0];
            }
            
            char bef = wheel[2][2];
            //다음꺼는 반대방향!
            int nowDir = -dir;
            //4번 회전
            if(bef != wheel[3][6]){
                if(nowDir == 1){
                    for(int j=0; j<7; j++){
                        temp[3][j+1] = wheel[3][j];
                    }
                    temp[3][0] = wheel[3][7];
                }
                else if(nowDir == -1){
                    for(int j=0; j<7; j++){
                        temp[3][j] = wheel[3][j+1];
                    }
                    temp[3][7] = wheel[3][0];
                }
            }
            //1, 2번 회전
            bef = wheel[2][6];
            //4번과 2번은 회전 방향이 동일
            for(int l=1; l>=0; l--){
                //같은 경우 안돌아감
                if(bef == wheel[l][2])
                    break;
                
                if(nowDir == 1){
                    for(int j=0; j<7; j++){
                        temp[l][j+1] = wheel[l][j];
                    }
                    temp[l][0] = wheel[l][7];
                }
                else if(nowDir == -1){
                    for(int j=0; j<7; j++){
                        temp[l][j] = wheel[l][j+1];
                    }
                    temp[l][7] = wheel[l][0];
                }
                
                bef = wheel[l][6];
                nowDir = -nowDir;       //다음꺼는 반대방향!
            }
        }
        
        //4번 회전
        else if(num == 4){
            //4번 부터 회전
            if(dir == 1){
                for(int j=0; j<7; j++){
                    temp[3][j+1] = wheel[3][j];
                }
                temp[3][0] = wheel[3][7];
            }
            else if(dir == -1){
                for(int j=0; j<7; j++){
                    temp[3][j] = wheel[3][j+1];
                }
                temp[3][7] = wheel[3][0];
            }
            //비교할 이전 톱니바퀴
            char bef = wheel[3][6];
            //다음꺼는 반대방향!
            int nowDir = -dir;
            for(int l=2; l>=0; l--){
                //같은 경우 안돌아감
                if(bef == wheel[l][2])
                    break;
                
                if(nowDir == 1){
                    for(int j=0; j<7; j++){
                        temp[l][j+1] = wheel[l][j];
                    }
                    temp[l][0] = wheel[l][7];
                }
                else if(nowDir == -1){
                    for(int j=0; j<7; j++){
                        temp[l][j] = wheel[l][j+1];
                    }
                    temp[l][7] = wheel[l][0];
                }
                
                bef = wheel[l][6];
                nowDir = -nowDir;       //다음꺼는 반대방향!
            }
        }
        
        
        
        for(int j=0; j<4; j++){
            for(int l=0; l<8; l++){
                wheel[j][l] = temp[j][l];
                //printf("%c", wheel[j][l]);
            }
            //printf("\n");
        }
        //printf("\n");
    }
    
    if(wheel[0][0] == '1'){
        ans+=1;
    }
    if(wheel[1][0] == '1'){
        ans+=2;
    }
    if(wheel[2][0] == '1'){
        ans+=4;
    }
    if(wheel[3][0] == '1'){
        ans+=8;
    }
    
    printf("%d\n", ans);
}
