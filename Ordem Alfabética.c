#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char string1 [40], string2 [40];
    int i = 0;
    
    printf("Digite a primeira palavra:\n");
    gets(string1);

    printf("Digite a segunda palavra:\n");
    gets(string2);
    
    printf("\n--- ORDEM ALFABETICA ---\n");

    while (1) {
        if(string1[i] == string2[i]){
            i++; continue;
        }
    
        else if (string1[i] < string2[i]){
            printf("\n%s \n%s \n", string1, string2);
            break;
        }
        else{
            printf("\n%s \n%s \n", string2, string1);
            break;
        }

    }
    return 0;
}
