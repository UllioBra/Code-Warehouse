from django.shortcuts import render
from django.http import HttpResponse

def index(request):
	list_ = ['ContestsGet', 'Luogu日报',]
	dict_ = {'Main_Name' : '辣鸡爬虫', 'name' : list_}
	return render(request, 'home/index.html', dict_)