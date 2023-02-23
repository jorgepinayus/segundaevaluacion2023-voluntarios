#include <iostream>
using namespace std;

// Función para imprimir el tablero actual
void print_board(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Función para verificar si hay un ganador
char check_winner(char board[3][3]) {
    // Verificar filas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Verificar columnas
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Verificar diagonales
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // Si no hay ganador
    return ' ';
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;
    char player = 'X';
    char winner = ' ';
    bool game_over = false;
    // Ciclo principal del juego
    while (!game_over) {
        print_board(board);
        // Preguntar al jugador actual
        cout << "Jugador " << player << ", ingrese fila (0-2): ";
        cin >> row;
        cout << "Jugador " << player << ", ingrese columna (0-2): ";
        cin >> col;
        // Verificar si la posición está disponible
        if (board[row][col] == ' ') {
            board[row][col] = player;
            // Verificar si hay un ganador
            winner = check_winner(board);
            if (winner != ' ') {
                game_over = true;
                cout << "El ganador es el jugador " << winner << "!" << endl;
            } else {
                // Cambiar de jugador
                if (player == 'X') {
                    player = 'O';
                } else {
                    player = 'X';
                }
            }
        } else {
            cout << "La posición ya está ocupada. Intente nuevamente." << endl;
        }
    }
    // Imprimir el tablero final
    print_board(board);
    return 0;
}

