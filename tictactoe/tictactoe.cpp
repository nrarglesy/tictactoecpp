#include <iostream>

void print_grid(char grid[3][3]);
bool checkwin(char grid[3][3]);

int main()
{
    char tictactoegrid[3][3] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
    char player = 'X';
    int row;
    int column;
    print_grid(tictactoegrid);
    while (!checkwin(tictactoegrid)) {
        std::cout << "Current player: " << player << std::endl;
        std::cout << "Enter a row (0-2): ";
        std::cin >> row;
        std::cout << "Enter a column (0-2): ";
        std::cin >> column;
        tictactoegrid[row][column]= (tictactoegrid[row][column] != '-') ? tictactoegrid[row][column] : player;
        player = (player == 'X') ? 'O' : 'X';
        print_grid(tictactoegrid);
    }
}

void print_grid(char grid[3][3])
{
    //self explanatory
    for (int y = 0; y <= 2; y++) {
        for (int x = 0; x <= 2; x++) {
            std::cout << grid[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkwin(char grid[3][3])
{   //check rows
    for (int i = 0; i <= 2; i++) {
        if (((grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2])) && (grid[i][0] != '-'))
        {
            return true;
        }
    }
    //check columns
    for (int j = 0; j <= 2; j++) {
        if (((grid[0][j] == grid[1][j]) && (grid[1][j] == grid[2][j])) && (grid[0][j] != '-'))
        {
            return true;
        }
    }
    //check diagonals
    if(((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) && (grid[0][0] != '-')) ||
            ((grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0]) && grid[0][2] != '-'))
    {
        return true;
    }
    return false;
}
