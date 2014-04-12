#!/usr/bin/python
import cgi
import cgitb
cgitb.enable()

#Take user input
form=cgi.FieldStorage()
if len(form)>0:
	data= form["question"].value

#Name = first line of survey.ssv
survey=open("http://www.cs.mcgill.ca/~ctrinh2/cgi-bin/survey.ssv", "r")
name = survey.readline()
survey.close

#Add question to survey.ssv
survey=open("http://www.cs.mcgill.ca/~ctrinh2/cgi-bin/survey.ssv", "a")
if len(form)>0:
	survey.write(form["question"].value+ "\n")
survey.close

survey=open("http://www.cs.mcgill.ca/~ctrinh2/cgi-bin/survey.ssv", "r")
contents = survey.read()
survey.close

if not contents:
	print "Content-Type:text/html\n"

	print "<!DOCTYPE HTML>" 
	print '<link rel="stylesheet" href="surveyStyle.css">'
	print "<head>" 
	print '<link rel="shortcut icon" href="http://i68.photobucket.com/albums/i7/newphew92/fd3b869e-122d-4361-9889-50cf85e17d0f_zps5d4d4153.jpg">'
	print "<h1>Survey Creation</h1>" 
	print "</head>"

	print "<BODY>"
	print '<p style="text-align:center; margin-top:26px">'
	print "Survey title: %s" %name
	print '</p>'


	print '<p>Enter the desired question in the text box and click "add" to add a question to your survey. Once you are done, click "done" to submit your 	survey.'
	print '</p>' 
	print '<form id="add" style="text-align:center" action="http://www.cs.mcgill.ca/~vwen/cgi-bin/addQuestion.py">'
	print '<br>'
	print '<textarea name="question" form="add" rows="4" cols= "70" autofocus></textarea><br>'
	print '<span class="right">'
	print '<input type="submit" value="Add">'
	print '</span>	<br>'
	print '</form>'
	print '<h3 style="clear:both"></h3>'
	print '<div style="text-align: center">'
	print '<form action="http://www.cs.mcgill.ca/~vwen/cgi-bin/endSurvey.py">'
	print '<input type="submit" value="Done"style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
	print '</form>'
	print '</div>'


	print '<form action="http://www.cs.mcgill.ca/~vwen/cgi-bin/newSurvey.py" style="text-align:center">'
	print '<input  type="submit"  value="New"  style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
	print '</form><br>'
	print '<p style="text-align:center">'
	print '<a href="http://cs.mcgill.ca/~ctrinh2/welcome.html">Return to homepage</a>'
	print '</BODY>'


if  contents:
	print "Content-Type:text/html\n"

	print "<!DOCTYPE HTML>" 
	print '<link rel="stylesheet" href="surveyStyle.css">'
	print "<head>" 
	print '<link rel="shortcut icon" href="http://i68.photobucket.com/albums/i7/newphew92/fd3b869e-122d-4361-9889-50cf85e17d0f_zps5d4d4153.jpg">'
	print "<h1>Survey Creation</h1>" 
	print "</head>"

	print "<BODY>"
	print '<p style="text-align:center; margin-top:26px">'
	print "Survey title: %s" %name
	print '</p>'



	#Print the questions
	survey = open("http://www.cs.mcgill.ca/~ctrinh2/cgi-bin/survey.ssv", "r")

	lines = survey.readlines()
	for i in range(1, len(lines)):
	    	line = lines[i]
		print"<p> Question: %s </p>" % line
	survey.close()


	print '<p>Enter the desired question in the text box and click "add" to add a question to your survey. Once you are done, click "done" to submit your 	survey.'
	print '</p>' 
	print '<form id="add" style="text-align: center" action="http://www.cs.mcgill.ca/~vwen/cgi-bin/addQuestion.py">'
	print '<br>'
	print '<textarea name="question" form="add" rows="4" cols= "70" autofocus></textarea><br>'
	print '<span class="center">'
	print '<input type="submit" value="Add">'
	print '</span>	<br>'
	print '</form>'
	print '<h3 style="clear:both"></h3>'
	print '<div style="text-align: center">'
	print '<form action="http://www.cs.mcgill.ca/~vwen/cgi-bin/endSurvey.py">'
	print '<input type="submit" value="Done"style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
	print '</form>'
	print '</div>'


	print '<form action="http://www.cs.mcgill.ca/~vwen/cgi-bin/newSurvey.py" style="text-align:center">'
	print '<input  type="submit"  value="New"  style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
	print '</form><br>'
	print '<p style="text-align:center">'
	print '<a href="http://cs.mcgill.ca/~ctrinh2/welcome.html">Return to homepage</a>'
	print '</BODY>'




