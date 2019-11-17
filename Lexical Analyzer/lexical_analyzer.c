#include<stdio.h>
#include<ctype.h>
#include<string.h>

int num_list[100] , x = 0 , y = 0 , z =0 , k = 0  , lineno =0  ;
char keyword_list[100][100]  , identifier_list[100][100] , specialsymbol_list[100];
void display ( char  [100][100] , int  );
void display_specialsymbols ( char  [100] , int  );
void display_numbers ( int [100] , int );
void insert ( char [100][100] , int , char[]);


int main()
{
    char c , str[100]  ;
    int num , i=0;
    FILE * f1;
    f1 = fopen("input.c","r");
    while( (c = getc(f1)) != EOF )
    {
        if ( c== '#')
        {
            while( c != '\n')
            {
                c = getc(f1);
            }
            ungetc(c,f1);
        }
        else if (isdigit(c))
        {
           num = c - 48 ;
           c=getc(f1);
           while(isdigit(c))
           {
               num = num * 10 +(c - 48);
               c = getc(f1);
           }
           num_list[x] = num;
           x++;
           ungetc(c,f1);
        }
        else if (isalpha(c))
        {
            str[i++] = c;
            c=getc(f1);
            while(isdigit(c) || isalpha(c) || c == '_' || c == '$' )
            {
                str[i++] = c;
                c = getc(f1);

            }
            str[i++]='\0';

            if (!strcmp(str, "auto") || !strcmp(str, "default") || !strcmp(str, "signed") || !strcmp(str, "enum")  ||
                !strcmp(str, "extern") || !strcmp(str, "for")  || !strcmp(str, "register") || !strcmp(str, "if")  ||
                !strcmp(str, "else")  || !strcmp(str, "int") || !strcmp(str, "while") || !strcmp(str, "do") ||
                !strcmp(str, "break") || !strcmp(str, "continue")  || !strcmp(str, "double") || !strcmp(str, "float") ||
                !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "const") ||
                !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") ||
                !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") ||
                !strcmp(str, "struct") || !strcmp(str, "goto") || !strcmp(str, "union") || !strcmp(str, "volatile"))
            {
                insert(keyword_list , y , str);
                y++;
            }
            else
            {
                insert(identifier_list, z ,str);
                z++;
                ungetc(c,f1);

            }
            i=0;
        }
        else if ( c == ' ' || c == '\t')
        {
            continue;
        }
        else if ( c == '\n')
        {
            lineno++;
        }
        else
        {
            specialsymbol_list[k] = c;
            k++;
        }
    }
    fclose(f1);
    printf(" Total no of lines are %d . \n",lineno);
    printf(" Keywords are ");
    display(keyword_list , y );
    printf(" Identifiers are ");
    display(identifier_list , z );
     printf(" Special Symbols are ");
    display_specialsymbols(specialsymbol_list , k );
    printf(" Numbers are  ");
    display_numbers(num_list , x );

}
void display ( char array [100][100] , int length )
{
    int i  ;
    for ( i=0 ; i< length ; i++)
    {
        printf ( "%s , ",array[i]);
    }
    printf("\n");

}
void display_specialsymbols ( char array [100] , int length )
{
    int i  ;
    for ( i=0 ; i< length ; i++)
    {
        printf ( "%c , ",array[i]);
    }
    printf("\n");

}
void display_numbers ( int array[100] , int  length )
{
    int i  ;
    for ( i=0 ; i< length ; i++)
    {
        printf ( "%d , ",array[i]);
    }
    printf("\n");

}

void insert ( char array[100][100] , int index , char str[100])
{
    int l = strlen(str);
    int i = 0;
    for (i=0 ; i<l;i++)
    {
        array[index][i] = str[i];
    }

}














