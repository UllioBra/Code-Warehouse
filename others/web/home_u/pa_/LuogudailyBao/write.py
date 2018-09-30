import os
import time
from Get_Bao import *

tim = time.asctime(time.localtime(time.time()))
print("<!DOCTYPE html>")
print("<html>")


print("<head>")
print('''
<meta charset="utf-8">
<title>ContestsGet</title>
<link rel="stylesheet" href="/ware/1.css">
<script src="/ware/2.js"></script>
<script src="/ware/3.js"></script>

<style type="text/css">
    div.panel-default {
        /*
        background-color:bisque;
        background-image: url(./ware/pic/1.jpg);
        background-position:center;
        background-repeat: repeat-y;
        background-size: cover;
        */
        margin-left: 25%;
        margin-right: 25%;
    }
</style>

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
                洛谷日报
            </a>
        </b>
    </h4>
</div>
''')
print('''
<div id="collapseOne" class="panel-collapse collapse">
    <div class="panel-body">
''')
li_1 = func()
if not li_1:
    print("<b>错误</b>\n<hr>")
for i in li_1:
    if (i[0] == False):
        print("%s\n<hr>" %(i[1]))
    else:
        print("<a href = '%s'>%s</a>\n<hr>" % (i[2], i[1]))
print('''
        </div>
    </div>
</div>
''')


print("<br></br>")  # --------------------------------------------------


print("</div>")
print("</body>")

print("</html>")
