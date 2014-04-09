#!usr/bin/python
import web
import cgitb
cgitb.enable()


formInput=cgi.FieldStorage()

survey=open("survey.ssv", w)
survey.write(\n)
survey.write(formInput)
survey.close

survey=open("survey.ssv", r)
name = survey.readline()
survey.close



print "Content-Type:text/html\n"
print "<!DOCTYPE HTML>" 
print '<link rel="stylesheet" href="surveyStyle.css">'
print "<head>" 
print '<link rel="shortcut icon" href="http://i68.photobucket.com/albums/i7/newphew92/fd3b869e-122d-4361-9889-50cf85e17d0f_zps5d4d4153.jpg">'
print "<h1>Survey Creation</h1>" 
print "</head>" 
print "<BODY>"

survey=open("survey.ssv", r)
	next(survey)
    	for line in survey:
    	question = survey.readline()
    	next(survey)
    	print'<p> Question: %s </p>' % question
	print'<form action="http://cs.mcgill.ca/~tko4/results.html" method="post">'
	print'<input type="radio" name="choice1" value="stronglyAgree"> Strongly Agree<br>'
	print'<input type="radio" name="choice1" value="agree"> Agree<br>'
	print'<input type="radio" name="choice1" value="disagree"> Disagree<br>'
	print'<input type="radio" name="choice1" value="stronglyDisagree"> Strongly Disagree<br>'
	survey.close



print '<form style="text-align:center"> <br>'
print '<input type="text" value=%s style="font-size:15"><br>' % name
print '</form>" 
print '<p style="width:50%; float:left; margin-top:26px">'
print 'Enter the desired question in the text box and click "add" to add a question to your survey. Once you are done, click "done" to submit your 	survey.'
print '</p>" 
print '<form style="float:left">'
print '<br>'
print '<textarea rows="4" cols= "70" autofocus></textarea><br>'
print '<span class="right">'
print '<input type="submit" value="Add">'
print '</span>	<br>'
print '</form>'
print '<h3 style="clear:both"></h3>'
print '<div style="text-align: center">'
print '<input type="submit" value="Done"style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
print '</div>'
print '<form target="_blank" action="surveyCreation.html" style="text-align:center">'
print '<input  type="submit"  value="New"  style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
print '</form><br>'
print '<a href="http://cs.mcgill.ca/~ctrinh2/welcome.html">Return to homepage</a>'
print '</BODY>'
