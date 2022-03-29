#include "Card.h"

Card::Card(int f,int s):face(f),suit(s)
{

}



void Card::toString()
{
    
        cout << faces[face] << "of";
        cout << suits[suit] << endl;
    
}

string Card::toString2()
{
    cout << faces[face]<<endl;
    return faces[face];
}

string Card::getCardFace()
{
    return faces[face];
}

string Card::getCardSuit()
{
    return suits[suit];
}

void Card::showStringSuit()
{
    cout << suits[suit]<<endl;
}

int Card::getFace()
{
    return face;
}





