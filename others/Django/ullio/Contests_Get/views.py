from django.shortcuts import render
from . import ContestsGet

def contests(request):
    dict_ = ContestsGet.Get_Dict()
    return render(request, 'Contests_Get/contests.html', dict_)
    
