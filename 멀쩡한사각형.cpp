using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    int cut;
    
    cut = gcd(w, h);
    answer = (long long)w*h;
    answer -= (long long)(w+h-cut);
    return answer;
}
