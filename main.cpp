#include<bits/stdc++.h>
using namespace std;

int table[3][3]; // if table[i][j] == 1 =>X else (2) => O

/*
    prints table
*/
void print () {
    system("cls");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (table[i][j] == 0) { // khane khali ast
                cout << "|   |";
            }
            else if (table[i][j] == 1) { // X
                cout << "| X |";
            }
            else { // O
                cout << "| O |";
            }
        }
        cout << endl;
    }
}

/*
    inputs: cnt=>tedad mohre haye bazi shode
    output: {
        0 if nothing
        1 if X wins
        2 if O wins
        3 if draw
    }
*/
int check (int cnt) {
    // rows
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == table[i][1] &&
         table[i][1] == table[i][2] &&
          table[i][0] != 0)
            return table[i][0];
    }

    // columns
    for (int i = 0; i < 3; i++) {
        if (table[0][i] == table[1][i] &&
        table[1][i] == table[2][i] &&
        table[0][i] != 0)
            return table[0][i];
    }

    // diag
    if (table[0][0] == table[1][1] && // qotr asli
    table[1][1] == table[2][2] &&
    table[0][0] != 0)
        return table[0][0];
    
    if (table[0][2] == table[1][1] && // qotr farii
    table[1][1] == table[2][0] && table[1][1] != 0)
        return table[1][1];
    
    if (cnt == 9) return 3; // mosavi shodan
    return 0;
}

/*
    input: mokhtasat x, y
    output: aya dar khane (x, y) mitavan bazi kard? True not False
*/
bool is_possible (int x, int y) { // aya in khane khali ast ya kheir
    if (table[x][y] != 0)
        return false;
    return true;
}

/*
    input: {
        mokhtasat (x, y)
        symbor: player
    }
*/
void play (int x, int y, int symbol) { // dar khane (x, y) mohre symbol ra bazi kon
    table[x][y] = symbol;
}

void execute () {
    int player = 1; // {1, 2}
    int cnt = 0; // tedad dor haye bazi shode
    while (cnt < 9 && !check(cnt)) {
        print();
        char symbol = 'X';
        if (player == 2)
            symbol = 'O';
        cout << "player : " << symbol << endl;
        int x, y;
        cin >> x >> y;
        if (is_possible(x, y)) {
            play (x, y, player);
            cnt ++;
            if (player == 1) // bazikon avaz mishavad
                player = 2;
            else
             player = 1;
        } else {
            continue;
        }
    }
    print();
    switch (check(cnt)) {
        case 1: {
            cout << "X won!!" << endl;
            break;
        }
        case 2: {
            cout << "O win!!" << endl;
            break;
        }
        case 3: {
            cout << "DRAW!" << endl;
            break;
        }
    }
}

int main () {
    execute();
    return 0;
}
