#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char username[30];
char password[30];
char* usernameInput;
char* passwordInput;
char* input;
int invalid=0;
char buffer[100];
char c;
int a=0;
char string[200];

int main(void)
{
FILE * file;
char buffer[100];

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
    }
    string[a] = '\0';
sscanf(string,"username=%s password=%s",usernameInput,passwordInput);
printf("%s\n", usernameInput);
printf("%s\n", passwordInput);
/*

//usernameInput="bad";
//file=fopen("members.ssv", "r");
while (fgets(buffer, 100, file)!=NULL){
	//printf("%s\n", buffer );
	sscanf(buffer, "%s %s", username, password);
	if (strcmp(username, usernameInput)==0){
		invalid=1;
		break;
	}
}	
fclose (file);
if (invalid==1){
printf("<link rel=\"stylesheet\" href=\"surveyStyle.css\">\n");
printf("<head>\n");
printf("<link rel=\"shortcut icon\" href=\"http://i68.photobucket.com/albums/i7/newphew92/bagel_zps29e40f4c.jpg\">\n");
printf("<h1>Username already taken!\n");
printf("</h1>\n");
printf("</head>\n");
printf("<BODY>\n");
printf("<p>\n");
printf("The username has been already taken, please use another\n");
printf("</p>\n");
printf("<div id=\"menu\">\n");
printf("<ul>\n");
printf("<li><a href=\"http://www.cs.mcgill.ca/~vwen/ass4/login.html\">Click here to login</a></li>\n");
printf("<li><a href=\"http://www.cs.mcgill.ca/~ctrinh2/ass4/welcome.html\">Click here to return home</a></li>\n");
printf("</div>\n");
printf("</BODY>\n");
}
else{
file=fopen("members.ssv", "a");
fprintf(file, "%s %s \n", usernameInput, passwordInput);
fclose(file);
printf("<link rel=\"stylesheet\" href=\"surveyStyle.css\">");
printf("<head>");
printf("<link rel=\"shortcut icon\" href=\"http://i68.photobucket.com/albums/i7/newphew92/bagel_zps29e40f4c.jpg\">");
printf("<h1>Account created!");
printf("</h1>");
printf("</head>");
printf("<BODY>");
printf("<p>");
printf("The username and password have been accepted");
printf("</p>");
printf("<div id=\"menu\">");
printf("<ul>");
printf("<li><a href=\"http://www.cs.mcgill.ca/~vwen/ass4/login.html\">Click here to login</a></li>");
printf("<li><a href=\"http://www.cs.mcgill.ca/~ctrinh2/ass4/welcome.html\">Click here to return homet</a></li>");
printf("</div>");
printf("</BODY>");
}
*/	return 0;
}