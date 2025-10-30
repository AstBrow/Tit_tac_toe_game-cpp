#include <iostream>
#include <vector>
using namespace std;

int testWin (char test [3][3]) 
{
    if ((test[0][0] == 'X' && test[0][1] == 'X' && test[0][2] == 'X') || (test[0][0] == 'X' && test[1][0] == 'X' && test[2][0] == 'X') 
      || (test[1][0] == 'X' && test[1][1] == 'X' && test[1][2] == 'X') || (test[2][0] == 'X' && test [2][1] == 'X' && test [2][2] == 'X') 
      || (test[0][0] == 'X' && test[1][1] == 'X' && test[2][2] == 'X')|| (test[0][1] == 'X' && test[1][1] == 'X' && test[2][1] == 'X') 
      || (test[0][2] == 'X' && test[1][2] == 'X' && test[2][2] == 'X')) 
      {
        return 1;
      } else if ((test[0][0] == 'O' && test[0][1] == 'O' && test[0][2] == 'O') || (test[0][0] == 'O' && test[1][0] == 'O' && test[2][0] == 'O') 
      || (test[1][0] == 'O' && test[1][1] == 'O' && test[1][2] == 'O') || (test[2][0] == 'O' && test [2][1] == 'O' && test [2][2] == 'O') 
      || (test[0][0] == 'O' && test[1][1] == 'O' && test[2][2] == 'O') || (test[0][1] == 'O' && test[1][1] == 'O' && test[2][1] == 'O') 
      || (test[0][2] == 'O' && test[1][2] == 'O' && test[2][2] == 'O')) 
      {
        return 2;
      } else return 3;
}

int main () 
{
    int result;
    int counter = 1;
    cout << "== Добро пожаловать в крестики-нолики! ==" << endl;
    char game_place [3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    bool fulled_game_place [3][3] = {{false, false, false}, {false, false, false}, {false, false, false}};

    while (counter != 10) 
    {
        cout << "=========================================" << endl;
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) 
            {
                cout << "\t   " << game_place[i][j] <<  " ";
            }
            cout << endl;
        }
        cout<< endl;
        cout << "=========================================" << endl;
        cout << "Введите координату для " << counter << " хода: " << endl;
        int a,b;
        while (true) 
        {
            cin >> a >> b;
            if (fulled_game_place[a][b] == true || (a < 0 || a > 2) || (b < 0 || b > 2)) 
            {
                cout << "Неверная координата! Введи еще раз." << endl;
            } else break;
        }
        if (counter % 2 == 0) 
        {
            game_place[a][b] = 'X';
            fulled_game_place[a][b] = true;
        } else 
        {
            game_place[a][b] = 'O';
            fulled_game_place[a][b] = true;
        }
        if (testWin(game_place) == 1) 
        {
            result = testWin(game_place);
            break;
        } else if (testWin(game_place) == 2) 
        {
            result = testWin(game_place);
            break;
        }
        counter++;
    }
    if (result == 1) 
    {
        cout << "== Поздравляем! Выиграли крестики! ==" << endl;
    } else if (result == 2) 
    {
        cout << "== Поздравляем! Выиграли нолики! ==" << endl;
    } else 
    {
        cout << "== Упс, ничья! Вы славно сражались! ==" << endl;
    }
    cout << "=========================================" << endl;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
            {
                cout << "\t   " << game_place[i][j] <<  " ";
            }
            cout << endl;
        }
    cout<< endl;
    cout << "=========================================" << endl;
}