#!/usr/bin/python 
import cgi
import requests 
import cgitb
cgi.test()
cgitb.enable()
form=cgi.FieldStorage()
choice=form.getvalue('choice')


strongAgree=agree=disagree=strongDisagree=0

if choice=="stronglyAgree":
	strongAgree+=1
elif choice=="agree":
	agree+=1
elif choice=="disagree":
	disagree+=1
elif choice=="stronglyDisagree":
	strongDisagree+=1
print "Content-type:text/html\r\n\r\n"
print "<html>"
print "<head>"
print "<title>Hello - Second CGI Program</title>"
print "</head>"
print "<body>"
print "</body>"
print "</html>"
print"<h1>%d</h1>" %strongAgree

#url= 'survey.html'
#response= requests.post(url, data=form_data)
