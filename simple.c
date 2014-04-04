#include <stdio.h>

int main(void)
{
printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);
printf("<link rel=\"stylesheet\" href=\"surveyStyle.css\">");
printf("<head>");
printf("<link rel=\"shortcut icon\" href=\"http://i68.photobucket.com/albums/i7/newphew92/bagel_zps29e40f4c.jpg\">");
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
	return 0;
}
