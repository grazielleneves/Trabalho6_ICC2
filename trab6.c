#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int shell(int v[], int n) ;
int quick(int v[], int f, int l) ;

int compsQ=0,cpysQ=0;

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int vetorPrin[tamanho];

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetorPrin[i]);
    }

    int vetorAux[tamanho];
    int cont=1;
    while(cont <= tamanho){
        int retornoShell=0,retornoquick=0;
        compsQ=0,cpysQ=0;

        for(int i=0;i<cont;i++){
            vetorAux[i] = vetorPrin[i];
        }

        retornoShell = shell(vetorAux,cont);
        for(int i=0;i<cont;i++){
            vetorAux[i] = vetorPrin[i];
        }

        quick(vetorAux,0,cont-1);

        retornoquick = compsQ+ cpysQ;

        
        cont++;

        if (retornoShell > retornoquick)
            printf("Q "); 
        if (retornoShell < retornoquick)
            printf("S "); 
        if (retornoShell == retornoquick)
            printf("- "); 
    }
    printf("\n");
    return 0;
}

int shell(int v[], int n) {
    int comp=0,cpy=0;
    int gap = 1;

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
            if(j>=0){
                comp=comp+1;
            }

            v[j + gap] = x;
            cpy=cpy+1;

        }
        gap /= 2;
    }
    /*for(int aj=0;aj<n;aj++){
        printf("%d ",v[aj]);
    }
    printf("\n");
    */
    int resultado = comp+cpy;
    return resultado;
}



int quick(int v[], int f, int l) {

   

    if (f >= l) {
        return 0;
    }
    int m = (l + f)/2;

    int pivot = v[m];
    cpysQ=cpysQ+1;

    int i = f;
    int j = l;
    while(1) {
        while(v[i] < pivot) {   
            compsQ=compsQ+1;
            i++;
        }
        compsQ=compsQ+1;

        while(v[j] > pivot) {
            compsQ=compsQ+1;
            j--;
        }
        compsQ=compsQ+1;

        if (i >= j) {
            break;
        }

        cpysQ=cpysQ+1;
        int aux = v[i];

        cpysQ=cpysQ+1;
        v[i] = v[j];

        cpysQ=cpysQ+1;
        v[j] = aux;

        i++;
        j--;
    }
    quick(v, f, j);
    quick(v, j+1, l);
    
    int resultado = compsQ+cpysQ;
    return resultado;
}
