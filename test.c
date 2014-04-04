#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
FILE * file;
char buffer[100];
char c;
int a=0;
char string[200];

printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

int n = atoi(getenv("CONTENT_LENGTH"));
     
    // Decode String
    while ((c = getchar()) != EOF && a<n)
    {
        if (a < 200)
        {
            if (c!='+' && c!='&')       //The ampersand is there for splitting string for sscanf
                string[a]=c;
            else
                string[a]=' ';
            a++;
        }
        printf("%c",a );
    }
    string[a] = '\0';


	return 0;
}