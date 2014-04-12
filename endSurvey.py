#!/usr/bin/python
import cgi


print "Content-Type:text/html\n"
print '<!DOCTYPE HTML>'
print "<link rel=\"stylesheet\" href=\"surveyStyle.css\">"

print "<head>"

print '<link rel="shortcut icon" href="http://i68.photobucket.com/albums/i7/newphew92/fd3b869e-122d-4361-9889-50cf85e17d0f_zps5d4d4153.jpg">'
print "<title>Team Nice Bagel</title>"

print "<link rel=\shortcut icon\ href=\http://i68.photobucket.com/albums/i7/newphew92/fd3b869e-122d-4361-9889-50cf85e17d0f_zps5d4d4153.jpg\">"
print "<h1>Team Nice Bagel</h1>"

print "</head>"


print "<BODY>"

print "<P style=\"border-radius:10px; text-align:center\">If you would like to return to the welcome page, click on the link below<br>"
print "<a href=\"http://www.cs.mcgill.ca/~ctrinh2/welcome.html\">Return to the welcome page</a></p>"

print "<P style=\"border-radius:10px; text-align:center\">If you would like to create another survey, click on the link below<br>"
print "<a href=\"http://www.cs.mcgill.ca/~tko4/surveyCreation.html\">Create a new survey</a></p>"

print "<P style=\"border-radius:10px; text-align:center\">If you would like to fill a survey, click on the link below<br>"
print "<a href=\"http://www.cs.mcgill.ca/~ctrinh2/cgi-bin/survey.py\">Click here to fill a survey</a></p>"

print "</BODY>"