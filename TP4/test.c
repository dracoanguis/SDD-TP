#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

char* readline(FILE* file)
{
    int count = 1;
    char x = fgetc(file);
    while (x != '\n' && x != EOF)
    {
        count ++;
        x=fgetc(file);
        
    }
    char* ligne = (char*)(malloc(count*(sizeof(char))));
    fseek(file, (- count -1),SEEK_CUR);
    if (x == EOF) {fseek(file,2,SEEK_CUR);}
    for (int i = 0; i < (count); i++)
    {
        *(ligne + i*(sizeof(char))) = fgetc(file);
    }
    *(ligne + (count -1)*(sizeof(char))) = '\0';
    printf("%s\n",ligne);
    if ( x == EOF) {return NULL;}
    return ligne;
}

// void testprint(const char* fforme,...)
// {
//     va_list parametre;
//     va_start(a);
//     printf(fforme,);
// }

#define CASE(ligne,colonne,taille) (sizeof(int)*taille*ligne + sizeof(int)*colonne)
int main(int argc, char const *argv[])
{
    int taille = 7;
    int* matrix = malloc(sizeof(int)*taille*taille);
    *(matrix + CASE(0,0,taille)) = 1;

    for (int i = 0; i < taille; i++)
    {
        for (int e = 0; e < taille; e++)
        {
            *(matrix + CASE(i,e,taille)) = 1;
        }
    }
    
    for (int i = 0; i < taille; i++)
    {
        for (int e = 0; e < taille; e++)
        {
            printf("\t%d",*(matrix + CASE(i,e,taille)));
        }
        printf("\n");
    }
    return 0;
}
