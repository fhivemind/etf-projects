#include <stdio.h>
#define DUZINA 10

int main() {
    double niz[DUZINA],temp;
    int i,j;
    /* unos niza */
    for (i=0; i<DUZINA; i++) {
        scanf("%lf", &niz[i]);
    }

    for (i=0; i<DUZINA; i++) {
        for (j=i+1; j<DUZINA; j++) {
            if (niz[j] < niz[i]) {
		        temp = niz[i];
		        niz[i] = niz[j];
		        niz[j] = temp;
            }
        }
    }

    /* ispis niza */
    for (i=0; i<DUZINA; i++)
        printf("%g ", niz[i]);
    printf("\n");
    return 0;
}
