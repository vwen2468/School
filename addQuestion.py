import web
import cgitb
cgitb.enable()


formInput=cgi.FieldStorage()

survey=open('survey.ssv', a)
survey.write(formInput)
survey.close

