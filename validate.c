#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char username[30];
char password[30];
char string[200];
char* usernameInput;
char* passwordInput;
char* input;
double inputLength;
int valid=0;
char c;
int a=0;

int main(void){

//int n = atoi(getenv("CONTENT_LENGTH"));
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



file=fopen("members.ssv", "r");
while (fgets(buffer, 100, file)!=NULL){
	sscanf(buffer, "%s %s", username, password);
	if (strcmp(username, usernameInput)==0 
		&& strcmp(password, passwordInput)==0)
	{
		valid=1;
		break;
	}
}

if (valid==1){
printf("<link rel=\"stylesheet\" href=\"surveyStyle.css\">");
printf("<head>");
printf("<link rel=\"shortcut icon\" href=\"http://i68.photobucket.com/albums/i7/newphew92/bagel_zps29e40f4c.jpg\">");
printf("<h1>Welcome %s", usernameInput);
printf("</h1>");
printf("</head>");
printf("<BODY>");
printf("<p>");
printf("The login is succesful");
printf("</p>");
printf("<div id=\"menu\">");
printf("<ul>");
printf("<li><a href=\"http://www.cs.mcgill.ca/~ctrinh2/ass4/welcome.html\">Return to homepage</a></li>");
printf("<li><a href=\"http://www.cs.mcgill.ca/~tko4/ass4/surveyCreation.html\">Click here to create a survey</a></li>");
printf("</ul>");
printf("</div>");
printf("</BODY>");
}

else{
	printf("<link rel=\"stylesheet\" href=\"surveyStyle.css\">");
printf("<head>");
printf("<link rel=\"shortcut icon\" href=\"http://i68.photobucket.com/albums/i7/newphew92/bagel_zps29e40f4c.jpg\">");
printf("<h1>Username exists already");
printf("</h1>");
printf("</head>");
printf("<BODY>");
printf("<p>");
printf("<a href=\"http://cs.mcgill.ca/~ctrinh2/ass4/welcome.html\">Return to homepage</a><br>");
printf("</p>");
printf("</BODY>");
}
return 0;
}
