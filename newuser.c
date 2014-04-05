#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char username[200];
char password[200];

char* input;
int invalid=0;
char buffer[100];
char c;
int a=0;
char string[200];
char usernameInput[200];
char passwordInput[200];
int main(void)
{
FILE * file;
char buffer[100];

printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

int n = atoi(getenv("CONTENT_LENGTH"));
     
    // Decode String
    while ((c = getchar()) != EOF && a<n)
    {
//printf("%c",c);
        if (a < 200)
        {
            if (c!='+' && c!='&')       //The ampersand is there for splitting string for sscanf
                string[a]=c;
            else
                string[a]='=';
            //printf("%c", string[a]);
a++;
        }

    }
    string[a] = '\0';
int b=0;
int c=0;
int x=0;
int y=0;
//This is why everybody fucking hates CGI with C, sscanf can't compile to CGI FFS.
while (string[b]!='\0'){
	if (string[b]=='='){
		c++;
	}
	if (c==3){
		if (string[b]!='='){
		passwordInput[y]=string[b];
		//printf("%c", string[b]);
		y++;
	}
	}	
	if (c==1){
		if (string[b]!='='){
		usernameInput[x]=string[b];
		//printf("%c", string[b]);
		x++;
	}	
	}



	b++;

}
//printf("hash\n");
usernameInput[x]='\0';
passwordInput[y]='\0';
//sscanf(hash,"%s", example);
//printf("%s\n", string);
//sscanf(string,"username=%s password=%s",usernameInput,passwordInput);
//printf("<p>%s\n</p>", usernameInput);
//printf("<p>%s\n</p>", passwordInput);

//usernameInput="newphew92";
//passwordInput="hash";

file=fopen("members.ssv", "r");
//printf("hash\n");
while (fgets(buffer, 100, file)!=NULL){
b=0;
c=0;
x=0;
y=0;
//This is why everybody fucking hates CGI with C, sscanf can't compile to CGI FFS.
while (buffer[b]!=' '){
  
if (buffer[b]!=' '){
username[x]=buffer[b];
		//printf("%c", string[b]);
	x++;
	}	

	b++;

}
//printf("hash\n");
username[x]='\0';
password[y]='\0';	
//printf("<p>user%s", username);
//printf("|%s</p>", usernameInput);

	if (strcmp(username, usernameInput)==0){
		invalid=1;
		break;
	}
}	
fclose (file);
if (invalid==1){
printf("<link rel=\"stylesheet\" href=\"../surveyStyle.css\">\n");
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
printf("</BODY\n");
}
else if (invalid==0){
file=fopen("members.ssv", "a");
fseek(file, 1, SEEK_END);
fprintf(file, "%s %s\n", usernameInput, passwordInput);
fclose(file);
printf("<link rel=\"stylesheet\" href=\"../surveyStyle.css\">");
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