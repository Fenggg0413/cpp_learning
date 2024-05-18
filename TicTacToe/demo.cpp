#include <iostream>
#include <vector>
#include <limits>

using namespace std;

enum Player
{
    NONE = 0,
    HUMAN,
    AI
};

struct Move
{
    int row, col;
};

// 绘制棋盘
void printBoard(const vector<vector<Player>> &board)
{
    for (const auto &row : board)
    {
        for (const auto &cell : row)
        {
            if (cell == HUMAN)
                cout << "X ";
            else if (cell == AI)
                cout << "O ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// 检查胜利条件
Player checkWin(const vector<vector<Player>> &board)
{
    // 行、列和对角线检查
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != NONE && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != NONE && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] != NONE && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != NONE && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return NONE;
}

// 检查是否有空位
bool isMovesLeft(const vector<vector<Player>> &board)
{
    for (const auto &row : board)
        for (const auto &cell : row)
            if (cell == NONE)
                return true;
    return false;
}

// MiniMax算法
int minimax(vector<vector<Player>> &board, int depth, bool isMax)
{
    Player winner = checkWin(board);
    if (winner == AI)
        return 10 - depth;
    if (winner == HUMAN)
        return depth - 10;
    if (!isMovesLeft(board))
        return 0;

    if (isMax)
    {
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == NONE)
                {
                    board[i][j] = AI;
                    best = max(best, minimax(board, depth + 1, false));
                    board[i][j] = NONE;
                }
            }
        }
        return best;
    }
    else
    {
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == NONE)
                {
                    board[i][j] = HUMAN;
                    best = min(best, minimax(board, depth + 1, true));
                    board[i][j] = NONE;
                }
            }
        }
        return best;
    }
}

// 找到最佳移动
Move findBestMove(vector<vector<Player>> &board)
{
    int bestVal = numeric_limits<int>::min();
    Move bestMove = {-1, -1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == NONE)
            {
                board[i][j] = AI;
                int moveVal = minimax(board, 0, false);
                board[i][j] = NONE;

                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main()
{
    vector<vector<Player>> board(3, vector<Player>(3, NONE));
    Player currentPlayer = AI;

    while (true)
    {
        printBoard(board);
        if (currentPlayer == HUMAN)
        {
            int row, col;
            cout << "Enter your move (row and column): ";
            cin >> row >> col;
            if (board[row][col] == NONE)
            {
                board[row][col] = HUMAN;
                currentPlayer = AI;
            }
            else
            {
                cout << "Invalid move! Try again." << endl;
            }
        }
        else
        {
            cout << "AI is making a move..." << endl;
            Move bestMove = findBestMove(board);
            board[bestMove.row][bestMove.col] = AI;
            currentPlayer = HUMAN;
        }

        Player winner = checkWin(board);
        if (winner != NONE || !isMovesLeft(board))
        {
            printBoard(board);
            if (winner == HUMAN)
                cout << "You win!" << endl;
            else if (winner == AI)
                cout << "AI wins!" << endl;
            else
                cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
