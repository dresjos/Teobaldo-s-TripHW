#include <iostream>
#include <stdio.h>
using namespace std;
int no_Cities, no_links;
int links_ListA[500];
int links_ListB[500];
int counter;
int s_data, e_data, d_data;
void Init(int n);
bool Which_Or(int searhh);

void Init(int n)
{
    counter = 0;
    int i;
    for(i=0; i<n;++i)
    {
        cin >> links_ListA[i];
        cin >> links_ListB[i];
    }
    cin >> s_data >> e_data >> d_data;
}



bool Which_Or(int searhh)
{
    int aux_ = 0;
    int aux_2=0;
    for(int i=0; i<no_links; ++i)
    {
        if(links_ListA[i]==searhh)
        {
            aux_ = links_ListB[i];
            aux_2 = links_ListA[i];
        }else if(links_ListB[i] == searhh)
        {
            aux_ = links_ListA[i];
            aux_2 = links_ListB[i];
        }
        /*
                ****************************************************
                    The problem is that always it founds the target,
                    It will be i=0.
                ****************************************************
        */
        if(aux_ != 0 )
        {
            links_ListA[i] = links_ListB[i] = 0;
            //cout << "  dd " << aux_ << e_data <<  endl;
            if(aux_ == e_data)
            {

                //cout << " A and B: " << aux_ << aux_2 << endl;
                if(counter==0)
                {
                    //cout << "i==0 false" << endl;
                    return false;
                }else
                {
                    //cout << "i!=0 True" << endl;
                    return true;
                }
            }else
            {
                //cout << " second else " << endl;
                ++counter;
                if(aux_ == e_data)
                {
                    return true;
                }else
                {
                    return Which_Or(aux_);
                }
            }
        }
    }
    return false;
}

int main()
{
    while(true)
    {
        cin >> no_Cities >>  no_links;
        if(no_Cities==0 || no_links==0)
        {
            break;
        }
        Init(no_links);
        if(Which_Or(s_data))
        {
            cout << "Yes, Teobaldo can travel." << endl;
        }else
        {
            cout << "No, Teobaldo can not travel" << endl;
        }
        cout << endl;
    }
}
