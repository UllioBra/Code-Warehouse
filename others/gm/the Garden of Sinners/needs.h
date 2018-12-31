#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <windows.h>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/writer.h"

namespace Random {

}

template <class T>
int GetArrLen(T& arr) {return sizeof(arr) / sizeof(arr[0]); }

void Delayed_Print(const std::string&a, const int&x, const int&y, const int&z) {
    for(int i = 0; i < a.size(); i++) {
        std::cout << a[i];
        Sleep(x);
    }
    std::cout << std::endl;
    Sleep(y);
    if(z) system("cls");
}
