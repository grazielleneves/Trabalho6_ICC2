#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int shell(int v[], int n) ;
void quick(int v[], int f, int l) ;

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int vetorPrin[tamanho];

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetorPrin[i]);
    }

    int vetorAux[tamanho];
    int cont=1;
    int retornoShell=0;
    while(cont <= tamanho){
        //printf("cont eh: %d\n",cont);
        printf("Aux: ");
        for(int i=0;i<cont;i++){
            vetorAux[i] = vetorPrin[i];
            printf("%d ",vetorAux[i]);
        }
        printf("\n");
        // 1
        retornoShell = shell(vetorAux,cont);
        printf("Shell eh: %d\n",retornoShell);
        cont++;
    }
    return 0;
}

int shell(int v[], int n) {
    int comp=0,cpy=0;
    int gap = pow(2,n-1);
    while(gap <= n) {
        gap *= 2;

    }
    gap = gap / 2 - 1;
    while(gap > 0) {
        for (int i = gap; i < n; i+=gap){
            int x = v[i];
            cpy=cpy+1;
            int j = i - gap;
            while(j >= 0 && v[j]>x){
                comp=comp+1;
                v[j + gap] = v[j];
                cpy=cpy+1;
                j -= gap;
            }
            if(j>=0 && v[j]<=x){
                comp=comp+1;
            }
            v[j + gap] = x;
            cpy=cpy+1;
        }
        gap /= 2;
    }
    for(int aj=0;aj<n;aj++){
        printf("%d ",v[aj]);
    }
    printf("\n");
    return (comp+cpy);
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
