#include "needs.h"
#include "Player.h"

namespace Events {
    class Battle {
        public:
            Battle(Player::Role*lis, int*a,int*b) {
                Delayed_Print("-------战斗开始-------",50,1000,1);
                LenA = GetArrLen(a);
                LenB = GetArrLen(b);
            }
            int Mk_Ba(Player::Role*lis, int*a,int*b);//战斗系统

        private:
            Player::Role lis;
            int *a, *b;
            int LenA,LenB;
    };
}

int Events::Battle::Mk_Ba(Player::Role*lis, int*a, int*b) {
}