#include <stdio.h>
int main() 
{
    int n, m;
    int card[120];
    int sum = 0;
    int dif = 1000000000;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }
    for(int i = 0; i < n-2; i++) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                int tmp = card[i] + card[j] + card[k];
                if(m-tmp >= 0 && m-tmp < dif) {
                    sum = tmp;
                    dif = m-sum;
                }

            }
        }
    }
    printf("%d**", sum);
    return 0;
}