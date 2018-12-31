#include "needs.h"

namespace Player {
    class Role {
        public:
            Role() {}
            Role(const std::string&a, const int&b, const int&c, const int&d, const int&f, const int&g) {
                Name_R = a; hp = b; atk = c; lev = d; def = f; luc = g; is_player = 0;
            }
            int C_hp(const int&x) {return hp -= x; }
            int C_atk(const int&x) {return atk += x; }
            int C_lev(const int&x) {return lev += x; }
            int C_def(const int&x) {return def += x; }
            int C_luc(const int&x) {return luc += x; }
            int C_isplayer(const int&x) {return is_player = x; }
            int Get_isplayer() {return is_player;}//1 is player
            std::string Get_name() {return Name_R; }

        private:
            std::string Name_R;
            int id, hp, atk, lev, def, luc, is_player;

            bool is_Equ[3]; 
            std::string Name_Equ[3];
            /*
                0: ÒÂ·ş
                1: ÎäÆ÷
            */

           int loc_id;
           std::string loc_Name;
    };
    class Skill {

    };
}