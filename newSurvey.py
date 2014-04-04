import web
import cgitb
cgitb.enable()


formInput=cgi.FieldStorage()

survey=open('survey.ssv', w)
survey.truncate(0)
survey.write(formInput)
survey.close

