// EightQueens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Res[16][16] = { 0 };
int nsolution=0;

void test(int P[][16]) {

    P[1][1] = 1;
}

void fill_the_board(int *P, int x, int y) {
    int i, j;
    for (i = x; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            if ((i == x || j == y) && *((P + i * 16) + j) == 0)
                *((P + i * 16) + j) = 1;
            if (((i - x) == (j - y) || (i + j) == (x + y)) || *((P + i * 16) + j) == 0)
                *((P + i * 16) + j) = 1;
            cout << *((P + i * 16) + j);
        }
        cout << '\n';
    }
}


void EightQueens(int P[][16],int k, int qn) {
    int i,j,ii,jj;
    int temp[16][16];

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            temp[i][j] = P[i][j];
        }
    } // save the current board

    if (qn == 16) { //if all eight queens are settled, then print the board
        nsolution++;
      /*  for (i = 0; i < 16; i++) {
            for (j = 0; j < 16; j++) {
                cout << Res[i][j] << ' ';
            }
            cout << '\n';
        }*/
        cout << "this is the " << nsolution << "th solution";
        cout << '\n';
        
    }

    else { // place the queen
        for (j = 0; j < 16; j++) {
            if (P[k][j] == 0) {
                P[k][j] = 1;
                temp[k][j] = 1;
                Res[k][j] = 1;
                // fill the board
                for (ii = 0; ii < 16; ii++) {
                    for (jj = 0; jj < 16; jj++) {
                        if ((ii == k || jj == j) && P[ii][jj] == 0)
                            P[ii][jj] = 1;
                        if (((ii - k) == (jj - j) || (ii + jj) == (k + j)) && P[ii][jj] == 0)
                            P[ii][jj] = 1;
                    }
                }


                EightQueens(P, k + 1,qn+1);
                Res[k][j] = 0;
                for (ii = 0; ii < 16; ii++) {
                    for (jj = 0; jj < 16; jj++) {
                        P[ii][jj] = temp[ii][jj];
                    }
                }
            }
        }
    }
}


int main()
{
    int P[16][16] = { 0 };
    int A[10] = {0};
//    EightQueens(P,0,0);
    test(P);
    cout << A[1];
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   16. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
