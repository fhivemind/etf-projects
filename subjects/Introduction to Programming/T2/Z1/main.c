#include <stdio.h>

#define NSP1 90.0
#define NSP2 120.0

int main() {
    /* initial */
    float SP;
    printf("Unesite vrijednost sistolickog pritiska: "); scanf("%f", &SP);
    
    /* test */
    if(SP >= NSP1 && SP <= NSP2) 
        printf("Sistolicki pritisak je normalan!\n");
    else 
        printf("Sistolicki pritisak nije normalan!\n");
    
    return 0;
}