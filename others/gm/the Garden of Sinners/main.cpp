#include "needs.h"

namespace Player {
    using namespace std;
    class Shiki {
        private:
            string Name_;
            int age,hp_;

        public:
            Shiki(){age = 0; hp_ = 0; Name_ = "两仪式"; }
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
        {"那一天，我选择走大马路回家。"},
        {"对我来说，这是难得的心血来潮。"},
        {"我茫然地走在早已看腻的大楼之间，"},
        {"没多久就有一个人掉了下来。"},
        {"很少有机会这样听见骨骼折断的喀嚓声，"},
        {"那人很明显是从大楼坠落而死的。"},
        {"红色在柏油路面上淌流开来，"},
        {"残骸中保有原形的部分，是一头长长的黑发，"},
        {"与纤细、让人联想到白色的脆弱手脚，"},
        {"以及血肉模糊的脸孔。"},
        {"这一连串的影像，"},
        {"令我幻想起夹在旧书页当中，"},
        {"被压成扁平的押花。"},
        {"——大概是因为，"},
        {"那具只有颈子宛如胎儿般弯折的亡骸，"},
        {"在我看来就像折断的百合吧。"},
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
        printf("---------空之境界---------\n");
    }
}

namespace Game {
    using namespace std;
    using namespace Player;
    int diff_ = -1;

    void Start_Game() {
        while(diff_ <= 0 || diff_ > 5) {
            cout << "请输入游戏难度(1-4/容易->困难):";
            scanf("%d",&diff_);
        }
        Sleep(1000);
        system("cls");
        Shi.Chg(12,10*(10-diff_));
        cout << Shi.Get_Name() << " 血量:" << Shi.Get_hp() << " 年龄:" << Shi.Get_age() << endl;
    }



}

int main() {
    Narr::print();
    Sleep(3000);
    system("cls");
    Game::Start_Game();
    return 0;
}