#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int valid=0;
char username[200];
char password[200];
char* input;
char buffer[100];
char c;
int a=0;
char string[200];
char usernameInput[200];
char passwordInput[200];
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
                string[a]='=';
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
usernameInput[x]='\0';
passwordInput[y]='\0';    
//sscanf(string,"username=%s password=%s",usernameInput,passwordInput);

file=fopen("members.ssv", "r");
while (fgets(buffer, 100, file)!=NULL){
b=0;
c=0;
x=0;
y=0;
while (buffer[b]!='\n'){
    if (buffer[b]==' '){
        c++;
    }
    if (c==1){
        if (buffer[b]!=' '){
        password[y]=buffer[b];
        //printf("%c", buffer[b]);
        y++;
    }
    }   
    if (c==0){
        if (buffer[b]!=' '){
        username[x]=buffer[b];
        //printf("%c", buffer[b]);
        x++;
    }   
    }
    b++;

}
username[x]='\0';
password[y]='\0';  
    //sscanf(buffer, "%s %s", username, password);
    if (strcmp(username, usernameInput)==0 
        && strcmp(password, passwordInput)==0)
    {
        valid=1;
        break;
    }
//printf("<p>user%s", username);
//printf("|%s</p>", usernameInput);
//printf("<p>%s", password);
//printf("|%s\n</p>", passwordInput);
}
fclose(file); 


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
printf("<h1>Invalid username or password");
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
