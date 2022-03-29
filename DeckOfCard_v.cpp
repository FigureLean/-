#include"Card.h"
#include"DeckOfCard.h"
#include<cstdlib>
#include<ctime>
DeckOfCard::DeckOfCard()
{
    int cnt = 0;
    currentCard = deck.size()-1;
    for (int f = 1; f <= 13; f++)
    {
        for (int s = 0; s <= 3; s++)
        {
            deck.push_back(Card(f, s));
        }
    }
}

void DeckOfCard::shuffle()
{
    int c1;
    int c2;
    srand(time(0));

    for (int i = 0; i < 52; i++)
    {
        c1 = rand() % 52;
        c2 = rand() % 52;

        Card temp = deck[c1];
        deck[c1]=deck[c2];
        deck[c2] = temp;

    }
}

void DeckOfCard::print(int k)
{
    deck[k].toString();
}

Card DeckOfCard::dealCard()
{
    return deck[currentCard];
}

bool DeckOfCard::moreCards()
{
    if (deck.size()>0)
        return true;
    else
    {
        return false;
    }
    
}

void DeckOfCard::pair()
{
    vector<string>p;
    for (int i = 0; i < 5; i++)
    {
        p.push_back(deck[i].getCardFace());
        deck[i].toString2();
    }
    int x = p.size();
    int t = 0;
    int flag = 0;
   /* string* m;
    m = &p[0];
    string* n;
    n = &p[x - 1];*/

    for (int i = 0; i < x; i++)
    {
        string str;
        str = p[i];
        // int t = 0;
        for (int j = i + 1; j < x; j++)
        {
            if (p[j] == str)
            {
                t++;
                
            }
            if (t == 4)
            {
                flag = 1;
            }
        }
    }
    if (t ==1)
    {
        cout << "有" << t << "副对子" << endl;
    }
    if (t == 3 )
    {
        cout << "有一个三张同号牌" << endl;
    }
    if (t == 4)
    {
        if (flag == 1)
            cout << "有一个四张同号牌" << endl;
        else
            cout << "有两副对子" << endl;
    }
   
}

void DeckOfCard::pair2()
{
    vector<string>q;
    for (int i = 0; i < 5; i++)
    {
        q.push_back(deck[i].getCardSuit());
        deck[i].showStringSuit();
    }
    int x = q.size();
    int t = 0;
   // int flag = 0;
    for (int i = 0; i < x; i++)
    {
        string str;
        str = q[i];
        // int t = 0;
        for (int j = i + 1; j < x; j++)
        {
            if (q[j] == str)
            {
                t++;
            }
           
        }
    }

    if (t == 5)
    {
        cout << "有一副同花" << endl;
    }

}

void DeckOfCard::pair3()
{
    
    string faces[14] = { "\0 ","Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
    vector<string>p;

    for (int i = 0; i < 5; i++)
    {
        p.push_back(deck[i].getCardFace());
        deck[i].toString2();
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            string temp;
            if (p[i] < p[j])
            {
                temp = p[i];
                p[j] = temp;
                p[i] = p[j];
            }
        }
    }

    int y = deck[1].getFace();

    if (p[2] == faces[y + 1]&&p[3]==faces[y+2]&&p[4]==faces[y+3]&&p[5]==faces[y=4])
    {
        cout << "有一副顺子" << endl;
    }
}
