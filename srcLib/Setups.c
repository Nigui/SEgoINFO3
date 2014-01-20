#include "Setups.h"

void SetupPieces(int nb,EPiece boardInit[4][10])
{
    switch( nb )
    {
        case 1: Setup1(boardInit);break;
        case 2: Setup2(boardInit);break;
        case 3: Setup3(boardInit);break;
        case 4: Setup4(boardInit);break;
        case 5: Setup5(boardInit);break;
        case 6: Setup6(boardInit);break;
        case 7: Setup7(boardInit);break;
        case 8: Setup8(boardInit);break;
        case 9: Setup9(boardInit);break;
        case 10: Setup10(boardInit);break;
        case 11: Setup11(boardInit);break;
        case 12: Setup12(boardInit);break;
        case 13: Setup13(boardInit);break;
        case 14: Setup14(boardInit);break;
        case 15: Setup15(boardInit);break;
        case 16: Setup16(boardInit);break;
        case 17: Setup17(boardInit);break;
        case 18: Setup18(boardInit);break;
        case 19: Setup19(boardInit);break;
        default : break;
    }
}

void Setup1(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPscout;
        boardInit[0][1] = EPminer;
        boardInit[0][2] = EPbomb;
        boardInit[0][3] = EPscout;
        boardInit[0][4] = EPminer;
        boardInit[0][5] = EPbomb;
        boardInit[0][6] = EPflag;
        boardInit[0][7] = EPbomb;
        boardInit[0][8] = EPminer;
        boardInit[0][9] = EPminer;
        
        boardInit[1][0] = EPsergeant;
        boardInit[1][1] = EPbomb;
        boardInit[1][2] = EPsergeant;
        boardInit[1][3] = EPmajor;
        boardInit[1][4] = EPcolonel;
        boardInit[1][5] = EPlieutenant;
        boardInit[1][6] = EPbomb;
        boardInit[1][7] = EPlieutenant;
        boardInit[1][8] = EPcaptain;
        boardInit[1][9] = EPsergeant;
        
        boardInit[2][0] = EPlieutenant;
        boardInit[2][1] = EPsergeant;
        boardInit[2][2] = EPbomb;
        boardInit[2][3] = EPspy;
        boardInit[2][4] = EPgeneral;
        boardInit[2][5] = EPscout;
        boardInit[2][6] = EPmajor;
        boardInit[2][7] = EPmajor;
        boardInit[2][8] = EPcolonel;
        boardInit[2][9] = EPscout;
        
        boardInit[3][0] = EPcaptain;
        boardInit[3][1] = EPscout;
        boardInit[3][2] = EPscout;
        boardInit[3][3] = EPlieutenant;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPcaptain;
        boardInit[3][6] = EPminer;
        boardInit[3][7] = EPmarshal;
        boardInit[3][8] = EPscout;
        boardInit[3][9] = EPcaptain; 
}
void Setup2(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPmajor;
        boardInit[0][1] = EPminer;
        boardInit[0][2] = EPminer;
        boardInit[0][3] = EPminer;
        boardInit[0][4] = EPsergeant;
        boardInit[0][5] = EPbomb;
        boardInit[0][6] = EPflag;
        boardInit[0][7] = EPbomb;
        boardInit[0][8] = EPbomb;
        boardInit[0][9] = EPminer;
        
        boardInit[1][0] = EPmajor;
        boardInit[1][1] = EPscout;
        boardInit[1][2] = EPmajor;
        boardInit[1][3] = EPspy;
        boardInit[1][4] = EPcaptain;
        boardInit[1][5] = EPlieutenant;
        boardInit[1][6] = EPbomb;
        boardInit[1][7] = EPsergeant;
        boardInit[1][8] = EPlieutenant;
        boardInit[1][9] = EPscout;
        
        boardInit[2][0] = EPsergeant;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPcolonel;
        boardInit[2][3] = EPcolonel;
        boardInit[2][4] = EPgeneral;
        boardInit[2][5] = EPscout;
        boardInit[2][6] = EPsergeant;
        boardInit[2][7] = EPbomb;
        boardInit[2][8] = EPbomb;
        boardInit[2][9] = EPlieutenant;
        
        boardInit[3][0] = EPmarshal;
        boardInit[3][1] = EPcaptain;
        boardInit[3][2] = EPlieutenant;
        boardInit[3][3] = EPminer;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPcaptain;
        boardInit[3][6] = EPscout;
        boardInit[3][7] = EPscout;
        boardInit[3][8] = EPscout;
        boardInit[3][9] = EPcaptain;
}
void Setup3(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPminer;
        boardInit[0][1] = EPbomb;
        boardInit[0][2] = EPsergeant;
        boardInit[0][3] = EPbomb;
        boardInit[0][4] = EPsergeant;
        boardInit[0][5] = EPscout;
        boardInit[0][6] = EPminer;
        boardInit[0][7] = EPminer;
        boardInit[0][8] = EPbomb;
        boardInit[0][9] = EPflag;
        
        boardInit[1][0] = EPsergeant;
        boardInit[1][1] = EPcolonel;
        boardInit[1][2] = EPspy;
        boardInit[1][3] = EPminer;
        boardInit[1][4] = EPbomb;
        boardInit[1][5] = EPscout;
        boardInit[1][6] = EPcaptain;
        boardInit[1][7] = EPlieutenant;
        boardInit[1][8] = EPlieutenant;
        boardInit[1][9] = EPbomb;
        
        boardInit[2][0] = EPlieutenant;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPmajor;
        boardInit[2][3] = EPlieutenant;
        boardInit[2][4] = EPbomb;
        boardInit[2][5] = EPscout;
        boardInit[2][6] = EPmajor;
        boardInit[2][7] = EPmajor;
        boardInit[2][8] = EPcolonel;
        boardInit[2][9] = EPminer;
        
        boardInit[3][0] = EPcaptain;
        boardInit[3][1] = EPscout;
        boardInit[3][2] = EPsergeant;
        boardInit[3][3] = EPgeneral;
        boardInit[3][4] = EPcaptain;
        boardInit[3][5] = EPscout;
        boardInit[3][6] = EPscout;
        boardInit[3][7] = EPmarshal;
        boardInit[3][8] = EPscout;
        boardInit[3][9] = EPcaptain;
}
void Setup4(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPminer;
        boardInit[0][1] = EPscout;
        boardInit[0][2] = EPminer;
        boardInit[0][3] = EPminer;
        boardInit[0][4] = EPsergeant;
        boardInit[0][5] = EPbomb;
        boardInit[0][6] = EPflag;
        boardInit[0][7] = EPbomb;
        boardInit[0][8] = EPminer;
        boardInit[0][9] = EPscout;
        
        boardInit[1][0] = EPcaptain;
        boardInit[1][1] = EPsergeant;
        boardInit[1][2] = EPmajor;
        boardInit[1][3] = EPspy;
        boardInit[1][4] = EPmajor;
        boardInit[1][5] = EPlieutenant;
        boardInit[1][6] = EPbomb;
        boardInit[1][7] = EPsergeant;
        boardInit[1][8] = EPbomb;
        boardInit[1][9] = EPsergeant;
        
        boardInit[2][0] = EPmarshal;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPmajor;
        boardInit[2][3] = EPcolonel;
        boardInit[2][4] = EPscout;
        boardInit[2][5] = EPcaptain;
        boardInit[2][6] = EPbomb;
        boardInit[2][7] = EPlieutenant;
        boardInit[2][8] = EPbomb;
        boardInit[2][9] = EPlieutenant;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPcolonel;
        boardInit[3][2] = EPlieutenant;
        boardInit[3][3] = EPscout;
        boardInit[3][4] = EPcaptain;
        boardInit[3][5] = EPscout;
        boardInit[3][6] = EPgeneral;
        boardInit[3][7] = EPminer;
        boardInit[3][8] = EPscout;
        boardInit[3][9] = EPcaptain;
}
void Setup5(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPsergeant;
        boardInit[0][1] = EPscout;
        boardInit[0][2] = EPminer;
        boardInit[0][3] = EPbomb;
        boardInit[0][4] = EPsergeant;
        boardInit[0][5] = EPminer;
        boardInit[0][6] = EPminer;
        boardInit[0][7] = EPbomb;
        boardInit[0][8] = EPflag;
        boardInit[0][9] = EPbomb;
        
        boardInit[1][0] = EPbomb;
        boardInit[1][1] = EPcaptain;
        boardInit[1][2] = EPspy;
        boardInit[1][3] = EPmajor;
        boardInit[1][4] = EPlieutenant;
        boardInit[1][5] = EPscout;
        boardInit[1][6] = EPcaptain;
        boardInit[1][7] = EPlieutenant;
        boardInit[1][8] = EPbomb;
        boardInit[1][9] = EPsergeant;
        
        boardInit[2][0] = EPminer;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPcolonel;
        boardInit[2][3] = EPmajor;
        boardInit[2][4] = EPbomb;
        boardInit[2][5] = EPlieutenant;
        boardInit[2][6] = EPmarshal;
        boardInit[2][7] = EPmajor;
        boardInit[2][8] = EPlieutenant;
        boardInit[2][9] = EPcolonel;
        
        boardInit[3][0] = EPgeneral;
        boardInit[3][1] = EPcaptain;
        boardInit[3][2] = EPscout;
        boardInit[3][3] = EPsergeant;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPscout;
        boardInit[3][6] = EPscout;
        boardInit[3][7] = EPminer;
        boardInit[3][8] = EPcaptain;
        boardInit[3][9] = EPscout;
}
void Setup6(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPminer;
        boardInit[0][1] = EPbomb;
        boardInit[0][2] = EPsergeant;
        boardInit[0][3] = EPscout;
        boardInit[0][4] = EPminer;
        boardInit[0][5] = EPbomb;
        boardInit[0][6] = EPminer;
        boardInit[0][7] = EPminer;
        boardInit[0][8] = EPbomb;
        boardInit[0][9] = EPflag;
        
        boardInit[1][0] = EPlieutenant;
        boardInit[1][1] = EPsergeant;
        boardInit[1][2] = EPbomb;
        boardInit[1][3] = EPscout;
        boardInit[1][4] = EPmajor;
        boardInit[1][5] = EPminer;
        boardInit[1][6] = EPlieutenant;
        boardInit[1][7] = EPcaptain;
        boardInit[1][8] = EPlieutenant;
        boardInit[1][9] = EPbomb;
        
        boardInit[2][0] = EPmajor;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPbomb;
        boardInit[2][3] = EPspy;
        boardInit[2][4] = EPcolonel;
        boardInit[2][5] = EPsergeant;
        boardInit[2][6] = EPscout;
        boardInit[2][7] = EPmajor;
        boardInit[2][8] = EPcolonel;
        boardInit[2][9] = EPsergeant;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPcaptain;
        boardInit[3][2] = EPlieutenant;
        boardInit[3][3] = EPgeneral;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPcaptain;
        boardInit[3][6] = EPscout;
        boardInit[3][7] = EPmarshal;
        boardInit[3][8] = EPcaptain;
        boardInit[3][9] = EPscout;
}
void Setup7(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPmajor;
        boardInit[0][1] = EPsergeant;
        boardInit[0][2] = EPbomb;
        boardInit[0][3] = EPsergeant;
        boardInit[0][4] = EPscout;
        boardInit[0][5] = EPscout;
        boardInit[0][6] = EPlieutenant;
        boardInit[0][7] = EPscout;
        boardInit[0][8] = EPlieutenant;
        boardInit[0][9] = EPscout;
        
        boardInit[1][0] = EPspy;
        boardInit[1][1] = EPbomb;
        boardInit[1][2] = EPflag;
        boardInit[1][3] = EPbomb;
        boardInit[1][4] = EPminer;
        boardInit[1][5] = EPgeneral;
        boardInit[1][6] = EPlieutenant;
        boardInit[1][7] = EPscout;
        boardInit[1][8] = EPsergeant;
        boardInit[1][9] = EPcaptain;
        
        boardInit[2][0] = EPmarshal;
        boardInit[2][1] = EPcaptain;
        boardInit[2][2] = EPbomb;
        boardInit[2][3] = EPminer;
        boardInit[2][4] = EPcolonel;
        boardInit[2][5] = EPcaptain;
        boardInit[2][6] = EPminer;
        boardInit[2][7] = EPminer;
        boardInit[2][8] = EPbomb;
        boardInit[2][9] = EPsergeant;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPmajor;
        boardInit[3][2] = EPminer;
        boardInit[3][3] = EPscout;
        boardInit[3][4] = EPcaptain;
        boardInit[3][5] = EPlieutenant;
        boardInit[3][6] = EPmajor;
        boardInit[3][7] = EPscout;
        boardInit[3][8] = EPcolonel;
        boardInit[3][9] = EPbomb;
}
void Setup8(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPbomb;
        boardInit[0][1] = EPflag;
        boardInit[0][2] = EPbomb;
        boardInit[0][3] = EPsergeant;
        boardInit[0][4] = EPscout;
        boardInit[0][5] = EPlieutenant;
        boardInit[0][6] = EPminer;
        boardInit[0][7] = EPscout;
        boardInit[0][8] = EPminer;
        boardInit[0][9] = EPmajor;
        
        boardInit[1][0] = EPmajor;
        boardInit[1][1] = EPbomb;
        boardInit[1][2] = EPlieutenant;
        boardInit[1][3] = EPbomb;
        boardInit[1][4] = EPcaptain;
        boardInit[1][5] = EPminer;
        boardInit[1][6] = EPbomb;
        boardInit[1][7] = EPspy;
        boardInit[1][8] = EPlieutenant;
        boardInit[1][9] = EPsergeant;
        
        boardInit[2][0] = EPbomb;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPscout;
        boardInit[2][3] = EPminer;
        boardInit[2][4] = EPcolonel;
        boardInit[2][5] = EPcaptain;
        boardInit[2][6] = EPlieutenant;
        boardInit[2][7] = EPminer;
        boardInit[2][8] = EPmarshal;
        boardInit[2][9] = EPscout;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPmajor;
        boardInit[3][2] = EPgeneral;
        boardInit[3][3] = EPcaptain;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPsergeant;
        boardInit[3][6] = EPcaptain;
        boardInit[3][7] = EPscout;
        boardInit[3][8] = EPcolonel;
        boardInit[3][9] = EPsergeant;
}
void Setup9(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPbomb;
        boardInit[0][1] = EPflag;
        boardInit[0][2] = EPbomb;
        boardInit[0][3] = EPbomb;
        boardInit[0][4] = EPbomb;
        boardInit[0][5] = EPscout;
        boardInit[0][6] = EPlieutenant;
        boardInit[0][7] = EPscout;
        boardInit[0][8] = EPbomb;
        boardInit[0][9] = EPminer;
        
        boardInit[1][0] = EPlieutenant;
        boardInit[1][1] = EPbomb;
        boardInit[1][2] = EPmajor;
        boardInit[1][3] = EPscout;
        boardInit[1][4] = EPminer;
        boardInit[1][5] = EPminer;
        boardInit[1][6] = EPmajor;
        boardInit[1][7] = EPcaptain;
        boardInit[1][8] = EPsergeant;
        boardInit[1][9] = EPminer;
        
        boardInit[2][0] = EPsergeant;
        boardInit[2][1] = EPcaptain;
        boardInit[2][2] = EPlieutenant;
        boardInit[2][3] = EPscout;
        boardInit[2][4] = EPscout;
        boardInit[2][5] = EPcaptain;
        boardInit[2][6] = EPmarshal;
        boardInit[2][7] = EPspy;
        boardInit[2][8] = EPmajor;
        boardInit[2][9] = EPsergeant;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPgeneral;
        boardInit[3][2] = EPcolonel;
        boardInit[3][3] = EPcaptain;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPlieutenant;
        boardInit[3][6] = EPminer;
        boardInit[3][7] = EPcolonel;
        boardInit[3][8] = EPscout;
        boardInit[3][9] = EPsergeant;
}
void Setup10(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPflag;
        boardInit[0][1] = EPbomb;
        boardInit[0][2] = EPsergeant;
        boardInit[0][3] = EPminer;
        boardInit[0][4] = EPscout;
        boardInit[0][5] = EPminer;
        boardInit[0][6] = EPlieutenant;
        boardInit[0][7] = EPscout;
        boardInit[0][8] = EPlieutenant;
        boardInit[0][9] = EPscout;
        
        boardInit[1][0] = EPbomb;
        boardInit[1][1] = EPcaptain;
        boardInit[1][2] = EPminer;
        boardInit[1][3] = EPsergeant;
        boardInit[1][4] = EPbomb;
        boardInit[1][5] = EPmajor;
        boardInit[1][6] = EPlieutenant;
        boardInit[1][7] = EPspy;
        boardInit[1][8] = EPminer;
        boardInit[1][9] = EPbomb;
        
        boardInit[2][0] = EPmajor;
        boardInit[2][1] = EPbomb;
        boardInit[2][2] = EPsergeant;
        boardInit[2][3] = EPcolonel;
        boardInit[2][4] = EPscout;
        boardInit[2][5] = EPmarshal;
        boardInit[2][6] = EPbomb;
        boardInit[2][7] = EPscout;
        boardInit[2][8] = EPgeneral;
        boardInit[2][9] = EPcaptain;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPlieutenant;
        boardInit[3][2] = EPcolonel;
        boardInit[3][3] = EPsergeant;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPcaptain;
        boardInit[3][6] = EPminer;
        boardInit[3][7] = EPcaptain;
        boardInit[3][8] = EPmajor;
        boardInit[3][9] = EPscout;
}
void Setup11(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPsergeant;
        boardInit[0][1] = EPbomb;
        boardInit[0][2] = EPflag;
        boardInit[0][3] = EPbomb;
        boardInit[0][4] = EPscout;
        boardInit[0][5] = EPscout;
        boardInit[0][6] = EPsergeant;
        boardInit[0][7] = EPsergeant;
        boardInit[0][8] = EPcaptain;
        boardInit[0][9] = EPscout;
        
        boardInit[1][0] = EPgeneral;
        boardInit[1][1] = EPmajor;
        boardInit[1][2] = EPbomb;
        boardInit[1][3] = EPminer;
        boardInit[1][4] = EPlieutenant;
        boardInit[1][5] = EPminer;
        boardInit[1][6] = EPcaptain;
        boardInit[1][7] = EPlieutenant;
        boardInit[1][8] = EPscout;
        boardInit[1][9] = EPminer;
        
        boardInit[2][0] = EPscout;
        boardInit[2][1] = EPlieutenant;
        boardInit[2][2] = EPcolonel;
        boardInit[2][3] = EPspy;
        boardInit[2][4] = EPminer;
        boardInit[2][5] = EPbomb;
        boardInit[2][6] = EPlieutenant;
        boardInit[2][7] = EPbomb;
        boardInit[2][8] = EPbomb;
        boardInit[2][9] = EPcolonel;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPsergeant;
        boardInit[3][2] = EPminer;
        boardInit[3][3] = EPmarshal;
        boardInit[3][4] = EPmajor;
        boardInit[3][5] = EPscout;
        boardInit[3][6] = EPcaptain;
        boardInit[3][7] = EPcaptain;
        boardInit[3][8] = EPmajor;
        boardInit[3][9] = EPscout;
}
void Setup12(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPscout;
        boardInit[0][1] = EPminer;
        boardInit[0][2] = EPsergeant;
        boardInit[0][3] = EPcaptain;
        boardInit[0][4] = EPscout;
        boardInit[0][5] = EPscout;
        boardInit[0][6] = EPminer;
        boardInit[0][7] = EPbomb;
        boardInit[0][8] = EPcaptain;
        boardInit[0][9] = EPscout;
        
        boardInit[1][0] = EPspy;
        boardInit[1][1] = EPmajor;
        boardInit[1][2] = EPlieutenant;
        boardInit[1][3] = EPbomb;
        boardInit[1][4] = EPlieutenant;
        boardInit[1][5] = EPminer;
        boardInit[1][6] = EPbomb;
        boardInit[1][7] = EPlieutenant;
        boardInit[1][8] = EPmajor;
        boardInit[1][9] = EPcaptain;
        
        boardInit[2][0] = EPmarshal;
        boardInit[2][1] = EPsergeant;
        boardInit[2][2] = EPcolonel;
        boardInit[2][3] = EPsergeant;
        boardInit[2][4] = EPminer;
        boardInit[2][5] = EPcaptain;
        boardInit[2][6] = EPscout;
        boardInit[2][7] = EPsergeant;
        boardInit[2][8] = EPminer;
        boardInit[2][9] = EPlieutenant;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPbomb;
        boardInit[3][2] = EPflag;
        boardInit[3][3] = EPbomb;
        boardInit[3][4] = EPgeneral;
        boardInit[3][5] = EPscout;
        boardInit[3][6] = EPmajor;
        boardInit[3][7] = EPbomb;
        boardInit[3][8] = EPcolonel;
        boardInit[3][9] = EPscout;
}
void Setup13(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPflag;
        boardInit[0][1] = EPsergeant;
        boardInit[0][2] = EPbomb;
        boardInit[0][3] = EPmajor;
        boardInit[0][4] = EPminer;
        boardInit[0][5] = EPsergeant;
        boardInit[0][6] = EPcaptain;
        boardInit[0][7] = EPminer;
        boardInit[0][8] = EPlieutenant;
        boardInit[0][9] = EPbomb;
        
        boardInit[1][0] = EPsergeant;
        boardInit[1][1] = EPbomb;
        boardInit[1][2] = EPcolonel;
        boardInit[1][3] = EPlieutenant;
        boardInit[1][4] = EPbomb;
        boardInit[1][5] = EPcaptain;
        boardInit[1][6] = EPspy;
        boardInit[1][7] = EPbomb;
        boardInit[1][8] = EPscout;
        boardInit[1][9] = EPminer;
        
        boardInit[2][0] = EPbomb;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPmajor;
        boardInit[2][3] = EPcaptain;
        boardInit[2][4] = EPscout;
        boardInit[2][5] = EPscout;
        boardInit[2][6] = EPminer;
        boardInit[2][7] = EPmarshal;
        boardInit[2][8] = EPminer;
        boardInit[2][9] = EPmajor;
        
        boardInit[3][0] = EPcaptain;
        boardInit[3][1] = EPscout;
        boardInit[3][2] = EPgeneral;
        boardInit[3][3] = EPlieutenant;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPcolonel;
        boardInit[3][6] = EPscout;
        boardInit[3][7] = EPsergeant;
        boardInit[3][8] = EPlieutenant;
        boardInit[3][9] = EPscout;
}
void Setup14(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPminer;
        boardInit[0][1] = EPcaptain;
        boardInit[0][2] = EPminer;
        boardInit[0][3] = EPbomb;
        boardInit[0][4] = EPflag;
        boardInit[0][5] = EPbomb;
        boardInit[0][6] = EPscout;
        boardInit[0][7] = EPmajor;
        boardInit[0][8] = EPminer;
        boardInit[0][9] = EPsergeant;
        
        boardInit[1][0] = EPcaptain;
        boardInit[1][1] = EPminer;
        boardInit[1][2] = EPspy;
        boardInit[1][3] = EPscout;
        boardInit[1][4] = EPbomb;
        boardInit[1][5] = EPsergeant;
        boardInit[1][6] = EPminer;
        boardInit[1][7] = EPsergeant;
        boardInit[1][8] = EPlieutenant;
        boardInit[1][9] = EPbomb;
        
        boardInit[2][0] = EPmajor;
        boardInit[2][1] = EPcolonel;
        boardInit[2][2] = EPsergeant;
        boardInit[2][3] = EPcaptain;
        boardInit[2][4] = EPscout;
        boardInit[2][5] = EPcolonel;
        boardInit[2][6] = EPmajor;
        boardInit[2][7] = EPbomb;
        boardInit[2][8] = EPscout;
        boardInit[2][9] = EPcaptain;
        
        boardInit[3][0] = EPlieutenant;
        boardInit[3][1] = EPscout;
        boardInit[3][2] = EPmarshal;
        boardInit[3][3] = EPscout;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPbomb;
        boardInit[3][6] = EPlieutenant;
        boardInit[3][7] = EPgeneral;
        boardInit[3][8] = EPscout;
        boardInit[3][9] = EPlieutenant;
}
void Setup15(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPflag;
        boardInit[0][1] = EPbomb;
        boardInit[0][2] = EPscout;
        boardInit[0][3] = EPbomb;
        boardInit[0][4] = EPminer;
        boardInit[0][5] = EPsergeant;
        boardInit[0][6] = EPbomb;
        boardInit[0][7] = EPscout;
        boardInit[0][8] = EPbomb;
        boardInit[0][9] = EPminer;
        
        boardInit[1][0] = EPbomb;
        boardInit[1][1] = EPmajor;
        boardInit[1][2] = EPsergeant;
        boardInit[1][3] = EPmajor;
        boardInit[1][4] = EPspy;
        boardInit[1][5] = EPminer;
        boardInit[1][6] = EPsergeant;
        boardInit[1][7] = EPlieutenant;
        boardInit[1][8] = EPcaptain;
        boardInit[1][9] = EPminer;
        
        boardInit[2][0] = EPlieutenant;
        boardInit[2][1] = EPscout;
        boardInit[2][2] = EPcaptain;
        boardInit[2][3] = EPcolonel;
        boardInit[2][4] = EPmajor;
        boardInit[2][5] = EPscout;
        boardInit[2][6] = EPscout;
        boardInit[2][7] = EPminer;
        boardInit[2][8] = EPbomb;
        boardInit[2][9] = EPmarshal;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPlieutenant;
        boardInit[3][2] = EPgeneral;
        boardInit[3][3] = EPcaptain;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPlieutenant;
        boardInit[3][6] = EPcaptain;
        boardInit[3][7] = EPcolonel;
        boardInit[3][8] = EPsergeant;
        boardInit[3][9] = EPscout;
}
void Setup16(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPsergeant;
        boardInit[0][1] = EPscout;
        boardInit[0][2] = EPsergeant;
        boardInit[0][3] = EPminer;
        boardInit[0][4] = EPbomb;
        boardInit[0][5] = EPmajor;
        boardInit[0][6] = EPcolonel;
        boardInit[0][7] = EPspy;
        boardInit[0][8] = EPscout;
        boardInit[0][9] = EPminer;
        
        boardInit[1][0] = EPcaptain;
        boardInit[1][1] = EPcolonel;
        boardInit[1][2] = EPmarshal;
        boardInit[1][3] = EPbomb;
        boardInit[1][4] = EPflag;
        boardInit[1][5] = EPbomb;
        boardInit[1][6] = EPcaptain;
        boardInit[1][7] = EPminer;
        boardInit[1][8] = EPsergeant;
        boardInit[1][9] = EPcaptain;
        
        boardInit[2][0] = EPlieutenant;
        boardInit[2][1] = EPbomb;
        boardInit[2][2] = EPsergeant;
        boardInit[2][3] = EPlieutenant;
        boardInit[2][4] = EPbomb;
        boardInit[2][5] = EPlieutenant;
        boardInit[2][6] = EPcaptain;
        boardInit[2][7] = EPbomb;
        boardInit[2][8] = EPlieutenant;
        boardInit[2][9] = EPmajor;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPscout;
        boardInit[3][2] = EPminer;
        boardInit[3][3] = EPmajor;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPscout;
        boardInit[3][6] = EPgeneral;
        boardInit[3][7] = EPscout;
        boardInit[3][8] = EPminer;
        boardInit[3][9] = EPscout;
}
void Setup17(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPscout;
        boardInit[0][1] = EPbomb;
        boardInit[0][2] = EPflag;
        boardInit[0][3] = EPbomb;
        boardInit[0][4] = EPcaptain;
        boardInit[0][5] = EPminer;
        boardInit[0][6] = EPscout;
        boardInit[0][7] = EPlieutenant;
        boardInit[0][8] = EPsergeant;
        boardInit[0][9] = EPsergeant;
        
        boardInit[1][0] = EPmajor;
        boardInit[1][1] = EPscout;
        boardInit[1][2] = EPbomb;
        boardInit[1][3] = EPscout;
        boardInit[1][4] = EPmajor;
        boardInit[1][5] = EPminer;
        boardInit[1][6] = EPsergeant;
        boardInit[1][7] = EPbomb;
        boardInit[1][8] = EPspy;
        boardInit[1][9] = EPlieutenant;
        
        boardInit[2][0] = EPlieutenant;
        boardInit[2][1] = EPminer;
        boardInit[2][2] = EPminer;
        boardInit[2][3] = EPscout;
        boardInit[2][4] = EPbomb;
        boardInit[2][5] = EPscout;
        boardInit[2][6] = EPcaptain;
        boardInit[2][7] = EPscout;
        boardInit[2][8] = EPmajor;
        boardInit[2][9] = EPbomb;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPcolonel;
        boardInit[3][2] = EPcaptain;
        boardInit[3][3] = EPsergeant;
        boardInit[3][4] = EPmarshal;
        boardInit[3][5] = EPgeneral;
        boardInit[3][6] = EPcaptain;
        boardInit[3][7] = EPlieutenant;
        boardInit[3][8] = EPcolonel;
        boardInit[3][9] = EPminer;
}
void Setup18(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPscout;
        boardInit[0][1] = EPsergeant;
        boardInit[0][2] = EPbomb;
        boardInit[0][3] = EPflag;
        boardInit[0][4] = EPbomb;
        boardInit[0][5] = EPminer;
        boardInit[0][6] = EPlieutenant;
        boardInit[0][7] = EPcaptain;
        boardInit[0][8] = EPcaptain;
        boardInit[0][9] = EPminer;
        
        boardInit[1][0] = EPcaptain;
        boardInit[1][1] = EPbomb;
        boardInit[1][2] = EPlieutenant;
        boardInit[1][3] = EPbomb;
        boardInit[1][4] = EPminer;
        boardInit[1][5] = EPsergeant;
        boardInit[1][6] = EPscout;
        boardInit[1][7] = EPcaptain;
        boardInit[1][8] = EPminer;
        boardInit[1][9] = EPlieutenant;
        
        boardInit[2][0] = EPmajor;
        boardInit[2][1] = EPbomb;
        boardInit[2][2] = EPspy;
        boardInit[2][3] = EPmajor;
        boardInit[2][4] = EPsergeant;
        boardInit[2][5] = EPcolonel;
        boardInit[2][6] = EPmajor;
        boardInit[2][7] = EPgeneral;
        boardInit[2][8] = EPminer;
        boardInit[2][9] = EPscout;
        
        boardInit[3][0] = EPscout;
        boardInit[3][1] = EPsergeant;
        boardInit[3][2] = EPmarshal;
        boardInit[3][3] = EPscout;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPbomb;
        boardInit[3][6] = EPscout;
        boardInit[3][7] = EPcolonel;
        boardInit[3][8] = EPlieutenant;
        boardInit[3][9] = EPscout;
}
void Setup19(EPiece boardInit[4][10])
{
        boardInit[0][0] = EPflag;
        boardInit[0][1] = EPmarshal;
        boardInit[0][2] = EPscout;
        boardInit[0][3] = EPsergeant;
        boardInit[0][4] = EPscout;
        boardInit[0][5] = EPminer;
        boardInit[0][6] = EPscout;
        boardInit[0][7] = EPcolonel;
        boardInit[0][8] = EPminer;
        boardInit[0][9] = EPscout;
        
        boardInit[1][0] = EPsergeant;
        boardInit[1][1] = EPsergeant;
        boardInit[1][2] = EPcaptain;
        boardInit[1][3] = EPminer;
        boardInit[1][4] = EPlieutenant;
        boardInit[1][5] = EPsergeant;
        boardInit[1][6] = EPminer;
        boardInit[1][7] = EPcaptain;
        boardInit[1][8] = EPscout;
        boardInit[1][9] = EPminer;
        
        boardInit[2][0] = EPbomb;
        boardInit[2][1] = EPbomb;
        boardInit[2][2] = EPlieutenant;
        boardInit[2][3] = EPmajor;
        boardInit[2][4] = EPbomb;
        boardInit[2][5] = EPbomb;
        boardInit[2][6] = EPmajor;
        boardInit[2][7] = EPspy;
        boardInit[2][8] = EPbomb;
        boardInit[2][9] = EPbomb;
        
        boardInit[3][0] = EPmajor;
        boardInit[3][1] = EPlieutenant;
        boardInit[3][2] = EPcaptain;
        boardInit[3][3] = EPgeneral;
        boardInit[3][4] = EPscout;
        boardInit[3][5] = EPscout;
        boardInit[3][6] = EPcolonel;
        boardInit[3][7] = EPlieutenant;
        boardInit[3][8] = EPscout;
        boardInit[3][9] = EPcaptain;
}