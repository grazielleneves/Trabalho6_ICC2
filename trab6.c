#include<stdio.h>

void main(){
    int n, i = 0, j, rep, p = 0, f = 1;
    scanf("%d", &n);
    int v[n];
    int vm[n-1][i];
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            vm[i][j]=v[j];
            //vm[0][0] = v[0]
            //vm[1][0] = v[0]
            //vm[1][1] = v[1]
            //continua...
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            printf("%d ", vm[i][j]);
        }
        printf("\n");
    }
}

void shell(int v[], int n) {
    int gap = 1;
    while(gap <= n) {
        gap *= 2;

    }
    gap = gap / 2 - 1;
    while(gap > 0) {
        for (int i = gap; i < n; i+=gap){
            int x = v[i];
            int j = i - gap;
                while(j >= 0 && v[j] > x) {
                    v[j + gap] = v[j];
                    j -= gap;
                }
                v[j + gap] = x;
            }
        gap /= 2;
    }
}

void quick(int v[], int f, int l) {
        if (f >= l) {
            return;
        }
        int m = (l + f)/2;
        int pivot = v[m];
        int i = f;
        int j = l;
        while(1) {
            while(v[i] < pivot) {
                i++;
            }
            while(v[j] > pivot) {
                j--;
            }
            if (i >= j) {
                break;
            }
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
        quick(v, f, j);
        quick(v, j+1, l);
}
