#include "needs.h"

namespace Player {
    using namespace std;
    class Shiki {
        private:
            string Name_;
            int age,hp_;

        public:
            Shiki(){age = 0; hp_ = 0; Name_ = "����ʽ"; }
            void Chg(const int&a,const int &b) {age = a; hp_ = b; }
            bool Hurt_(const int&x) {return (hp_ -= x) > 0; }
            bool Grown_up(const int&x) {return (age += x) > 0; }
            int Get_hp() {return hp_; } 
            int Get_age() {return age; }
            string Get_Name() {return Name_; }
    }Shi;
}

namespace Narr {
    using namespace std;
    std::string a[17] = {
        {"-----------------------------"},
        {"��һ�죬��ѡ���ߴ���·�ؼҡ�"},
        {"������˵�������ѵõ���Ѫ������"},
        {"��ãȻ���������ѿ���Ĵ�¥֮�䣬"},
        {"û��þ���һ���˵���������"},
        {"�����л����������������۶ϵĿ�������"},
        {"���˺������ǴӴ�¥׹������ġ�"},
        {"��ɫ�ڰ���·��������������"},
        {"�к��б���ԭ�εĲ��֣���һͷ�����ĺڷ���"},
        {"����ϸ���������뵽��ɫ�Ĵ����ֽţ�"},
        {"�Լ�Ѫ��ģ�������ס�"},
        {"��һ������Ӱ��"},
        {"���һ�������ھ���ҳ���У�"},
        {"��ѹ�ɱ�ƽ��Ѻ����"},
        {"�����������Ϊ��"},
        {"�Ǿ�ֻ�о�������̥�������۵�������"},
        {"���ҿ��������۶ϵİٺϰɡ�"},
    };

    void print() {
        for(int i = 0; i < 17; i++) {
            for(int j = 0; j < a[i].size(); j++) {
                cout << a[i][j];
                Sleep(50);
            }
            cout << endl;
            Sleep(800);
        }
        printf("---------��֮����---------\n");
    }
}

namespace Game {
    using namespace std;
    using namespace Player;
    int diff_ = -1;

    void Start_Game() {
        while(diff_ <= 0 || diff_ > 5) {
            cout << "��������Ϸ�Ѷ�(1-4/����->����):";
            scanf("%d",&diff_);
        }
        Sleep(1000);
        system("cls");
        Shi.Chg(12,10*(10-diff_));
        cout << Shi.Get_Name() << " Ѫ��:" << Shi.Get_hp() << " ����:" << Shi.Get_age() << endl;
    }



}

int main() {
    Narr::print();
    Sleep(3000);
    system("cls");
    Game::Start_Game();
    return 0;
}