#!/usr/bin/python
import cgi
import cgitb
cgitb.enable()

#Take user input
form=cgi.FieldStorage()
if len(form)>0:
	data= form["title"].value
#Erase survey.ssv and write in formInput

survey=open("http://www.cs.mcgill.ca/~ctrinh2/cgi-bin/survey.ssv", "w")
survey.truncate(0)
if len(form)>0:
	survey.write(data+ "\n")
survey.close

survey=open("http://www.cs.mcgill.ca/~ctrinh2/cgi-bin/survey.ssv", "r")
contents = survey.read()
survey.close
if not contents:
	print "Content-Type:text/html\n"
	print '<!DOCTYPE HTML>'
	print '<link rel="stylesheet" href="surveyStyle.css">'
	print '<head>'
	print '<link rel="shortcut icon" href="http://i68.photobucket.com/albums/i7/newphew92/fd3b869e-122d-4361-9889-50cf85e17d0f_zps5d4d4153.jpg">'
	print '<h1>Survey Creation</h1>'
	print '</head>'
	print '<BODY>'
	print '<p style="text-align:center; margin-top:26px">'
	print "No survey title" 
	print '</p>'

	print '<p style="margin-top:26px">'
	print 'Please enter a title for the survey to be created. Then, click on "new" to create the survey.'
	print '</p>'

	print '<form id="new" style="text-align:center" action="http://www.cs.mcgill.ca/~vwen/cgi-bin/newSurvey.py">'
	print "<br>"
	print '<textarea name="title" form="new" rows="4" cols= "70" autofocus></textarea><br>'

	print '<input  type="submit"  value="New"  style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
	print '</form><br>'

	print "<P style=\"border-radius:10px; text-align:center\">If you would like to return to the welcome page, click on the link below<br>"
	print "<a href=\"http://www.cs.mcgill.ca/~ctrinh2/welcome.html\">Return to the welcome page</a></p>"

	print "<P style=\"border-radius:10px; text-align:center\">If you would like to return to the survey creation page, click on the link below<br>"
	print "<a href=\"http://www.cs.mcgill.ca/~tko4/surveyCreation.html\">Create a new survey</a></p>"

if  contents:
	#Name = first line
	survey=open("survey.ssv", "r")
	name = survey.readline()
	survey.close

	#Print webpage with name as the title of survey
	print "Content-Type:text/html\n"
	print '<!DOCTYPE HTML>'
	print '<link rel="stylesheet" href="surveyStyle.css">'
	print '<head>'
	print '<link rel="shortcut icon" href="http://i68.photobucket.com/albums/i7/newphew92/fd3b869e-122d-4361-9889-50cf85e17d0f_zps5d4d4153.jpg">'
	print '<h1>Survey Creation</h1>'
	print '</head>'

	print '<BODY>'


	print '<p style="text-align:center; margin-top:26px">'
	print "%s" %name
	print '</p>'

	print '<p style="text-align:center">'
	print 'Click "new" to create a new survey. Your current survey will however be deleted.'
	print '</p>'

	print '<form id="new" style="text-align:center" action="http://www.cs.mcgill.ca/~vwen/cgi-bin/newSurvey.py">'
	print "<br>"
	#print '<textarea name="title" id="new" rows="4" cols= "70" autofocus></textarea><br>'
	print '<span class="right">'
	print '<input  type="submit"  value="new"  style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
	print '</form>'
	print '<br>'



	print '<p style="text-align:center">'
	print 'Enter the desired question in the text box below and click "add" to add your question to your survey. Once you are done, click "done" to submit your survey.'
	print '</p>'

	print '<form id="add" style="text-align:center" action="http://www.cs.mcgill.ca/~vwen/cgi-bin/addQuestion.py">'
	print "<br>"
	print '<textarea name="question" form="add" rows="4" cols= "70" autofocus></textarea><br>'
	#print '<span class="right">'
	print '<input type="submit" value="Add">'
	#print '</span> '
	print '<br>'
	print '</form>' 

	print '<h3 style="clear:both"></h3>'
	print '<div style="text-align: center">'
	print '<input type="submit" value="Done"style="font-size:20px; font-family: "Times New Roman"; text-align:center">'
	print "</div>"
	print '<a href="http://cs.mcgill.ca/~ctrinh2/welcome.html">Return to homepage</a>'
	print '</BODY>'
