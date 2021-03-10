#include <bits/stdc++.h>

using namespace std;

class coada {
    private:
        struct nod {
        int val = 0;
        nod * p = NULL;
        };

        int Qsize = 0;
        nod *frnt = NULL, *bck = NULL;

    public:
        void push( int x ) {
            nod *tmp = bck;

            bck = new nod;
            bck -> val = x;
            bck -> p = NULL;

            if( tmp != NULL ) tmp -> p = bck;

            if( frnt == NULL ) frnt = bck;

            Qsize++;
        }
        void pop() {
            if( Qsize == 0 ) return;

            /*if( Qsize == 1 ) {
                delete frnt;
                frnt = NULL;
                bck = NULL;
            }*/
           // else {
                nod *tmp = frnt;
                frnt = frnt -> p;
                delete tmp;
            //}
            Qsize--;
        }
        int qsize() {
            return Qsize;
        }
        int qfront() {
            if( frnt == NULL ) return -1;
            return frnt -> val;
        }
};

coada A;

int main()
{
    cout << "Operatii pe coada\n";
    cout << "push x         // adauga un intreg pozitiv la coada\n";
    cout << "pop            // elimina un element din coada\n";
    cout << "qfront         // afiseaza elementul din fata cozii\n";
    cout << "quit           // inchide consola\n";

    string inpt;
    bool valid;

    while( true ) {
        getline( cin, inpt );
        while( !inpt.empty() && inpt.back() == ' ')
            inpt.pop_back();


        valid = true;

        if( inpt == "quit" ) break;

        if( inpt == "pop" ) {
            A.pop();
        }
        else
            if( inpt == "qfront" ) {
                cout << A.qfront() << '\n';
            }
            else {
                if( inpt[0] != 'p' || inpt[1] != 'u' || inpt[2] != 's' || inpt[3] != 'h' || inpt[4] != ' ' )
                    valid = false;
                else {
                    int nr = 0;

                    for( int i = 5; i < inpt.size(); ++i ) {
                        if( '0' <= inpt[i] && inpt[i] <= '9' ) nr = nr * 10 + inpt[i] - '0';
                        else {
                            valid = false;
                            break;
                        }
                    }
                    if( valid ) A.push( nr );
                }
            }
            if( !valid ) cout << "Comanda nevalida\n";
    }

    cout << A.qsize() << '\n';

    return 0;
}
