#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char username[30];
char password[30];
char* usernameInput;
char* passwordInput;
char* input;
int invalid=0;

int main(void)
{
	FILE * file;
char buffer[100];

printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);
input=getenv("QUERY_STRING");
usernameInput=strtok(input, "=&");
passwordInput=strtok(NULL, "=&");

usernameInput="newphew92";
passwordInput="hash";
file=fopen("members.ssv", "r");
while (fgets(buffer, 100, file)!=NULL){
	sscanf(buffer, "%s %s", username, password);
	if (strcmp(username, usernameInput)==0){
		invalid=1;
		break;
	}
}	
fclose (file);
if (invalid==1){
printf("<link rel=\"stylesheet\" href=\"surveyStyle.css\">");
printf("<head>");
printf("<link rel=\"shortcut icon\" href=\"http://i68.photobucket.com/albums/i7/newphew92/bagel_zps29e40f4c.jpg\">");
printf("<h1>Username already taken!");
printf("</h1>");
printf("</head>");
printf("<BODY>");
printf("<p>");
printf("The username has been already taken, please use another");
printf("</p>");
printf("<div id=\"menu\">");
printf("<ul>");
printf("<li><a href=\"http://www.cs.mcgill.ca/~vwen/ass4/login.html\">Click here to login</a></li>");
printf("<li><a href=\"http://www.cs.mcgill.ca/~ctrinh2/ass4/welcome.html\">Click here to return home</a></li>");
printf("</div>");
printf("</BODY");
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
printf("</BODY");
}
	return 0;
}