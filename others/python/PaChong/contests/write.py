import os
import time
from contests_my import *

tim = time.asctime(time.localtime(time.time()))
print("<!DOCTYPE html>")
print("<html>")


print("<head>")
print('''
<meta charset="utf-8">
<title>ContestsGet</title>
<link rel="stylesheet" href="1.css">
<script src="2.js"></script>
<script src="3.js"></script>
''')
print("</head>")


print("<body>")
print("<b>上次更新时间</b>:<b>%s</b> (如发现挂掉请Q1019641963谢谢^_^)\n<hr>" % (tim))
print("<div class=\"panel-group\" id=\"accordion\">")


print("<div class=\"panel panel-default\">")
print('''
<div class="panel-heading">
    <h4 class="panel-title">
        <b>
            <a data-toggle="collapse" data-parent="#accordion" href="#collapseOne">
                Atcoder
            </a>
        </b>
    </h4>
</div>
''')
print('''
<div id="collapseOne" class="panel-collapse collapse">
    <div class="panel-body">
''')
li_1 = Atcoder_Upcoming_Contests()
if not li_1:
    print("<b>暂无还未开始的比赛</b>\n<hr>")
for i in li_1:
    print("<b>比赛</b>:%s\n<b>时间</b>:%s\n<b>时长</b>:%s \n<hr>" % (i[0], i[1], i[2]))
print('''
        </div>
    </div>
</div>
''')


print("<br></br>")  # --------------------------------------------------

print("<div class=\"panel panel-default\">")
print('''
<div class="panel-heading">
    <h4 class="panel-title">
        <b>
            <a data-toggle="collapse" data-parent="#accordion" href="#collapseTwo">
                Codeforces
            </a>
        </b>
    </h4>
</div>
''')
print('''
<div id="collapseTwo" class="panel-collapse collapse">
    <div class="panel-body">
''')
li_2 = Codeforces_Upcoming_Contests()
if not li_2:
    print("<b>暂无还未开始的比赛</b>\n<hr>")
le_2 = len(li_2)
for i in range(le_2):
    print("<b>比赛</b>:%s\n<b>开始时间</b>:%s\n<b>结束时间</b>:%s \n<hr>" % (li_2[le_2-i-1][0], li_2[le_2-i-1][1], li_2[le_2-i-1][2]))
print('''
        </div>
    </div>
</div>
''')


print("<br></br>")  # --------------------------------------------------


print("<div class=\"panel panel-default\">")
print('''
<div class="panel-heading">
    <h4 class="panel-title">
        <b>
            <a data-toggle="collapse" data-parent="#accordion" href="#collapseThree">
                Luogu
            </a>
        </b>
    </h4>
</div>
''')
print('''
<div id="collapseThree" class="panel-collapse collapse">
    <div class="panel-body">
''')
li_3 = Luogu_Upcoming_Contests()
if not li_3:
    print("<b>暂无还未开始的比赛</b>\n<hr>")
for i in li_3:
    print("<b>比赛</b>:%s\n<b>开始时间</b>:%s\n<b>结束时间</b>:%s \n<hr>" % (i[0], i[1], i[2]))
print('''
        </div>
    </div>
</div>
''')


print("<br></br>")  # --------------------------------------------------


print("<div class=\"panel panel-default\">")
print('''
<div class="panel-heading">
    <h4 class="panel-title">
        <b>
            <a data-toggle="collapse" data-parent="#accordion" href="#collapseFour">
                Nowcoder
            </a>
        </b>
    </h4>
</div>
''')
print('''
<div id="collapseFour" class="panel-collapse collapse">
    <div class="panel-body">
''')
li_4 = Nowcoder_Upcoming_Contests()
if not li_4:
    print("<b>暂无还未开始的比赛</b>\n<hr>")
for i in li_4:
    print("<b>比赛</b>:%s\n<b>%s</b>\n<b>%s</b> \n<hr>" % (i[0], i[1], i[2]))
print('''
        </div>
    </div>
</div>
''')


print("<br></br>")  # --------------------------------------------------


print("</div>")
print("</body>")

print("</html>")
