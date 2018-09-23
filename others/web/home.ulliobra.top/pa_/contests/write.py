import os, time
from contests_my import *

tim = time.asctime(time.localtime(time.time()))
print("<html>")
print("<meta http-equiv=\"Content-Type\" content=\"text/html\"; charset=\"utf-8\" />")


print("<head>")
print("<title>ContestsGet</title>")
print("</head>")


print("<body>")
print("<b>上次更新时间</b>:<b>%s</b> (如发现挂掉请Q1019641963谢谢^_^)\n<hr>" % (tim))

print("<h1>Atcoder</h1>")
li_1 = Atcoder_Upcoming_Contests()
for i in li_1:
    print("<b>比赛</b>:%s\n<b>时间</b>:%s\n<b>时长</b>:%s \n<hr>" % (i[0], i[1], i[2]))

print("<br></br>")

print("<h1>Codeforces</h1>")
li_2 = Codeforces_Upcoming_Contests()
for i in li_2:
    print("<b>比赛</b>:%s\n<b>时间</b>:%s\n<b>时长</b>:%s \n<hr>" % (i[0], i[1], i[2]))

print("<br></br>")

print("<h1>Luogu</h1>")
li_3 = Luogu_Upcoming_Contests()
for i in li_3:
    print("<b>比赛</b>:%s\n<b>开始时间</b>:%s\n<b>结束时间</b>:%s \n<hr>" % (i[0], i[1], i[2]))

print("<br></br>")

print("<h1>Nowcoder</h1>")
li_4 = Nowcoder_Upcoming_Contests()
for i in li_4:
    print("<b>比赛</b>:%s\n<b>%s</b>\n<b>%s</b> \n<hr>" % (i[0], i[1], i[2]))

print("<br></br>")

print("</body>")

print("</html>")
