#include <stdio.h>

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWinner()
{
    int i;

    for(i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return 1;

        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return 1;
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return 1;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;

    return 0;
}

int main()
{
    int choice, row, col, turn = 1, moves = 0;
    char mark;

    while(1)
    {
        displayBoard();

        if(turn == 1)
            mark = 'X';
        else
            mark = 'O';

        printf("Player %d (%c), Enter position (1-9): ", turn, mark);
        scanf("%d", &choice);

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if(choice < 1 || choice > 9 || board[row][col]=='X' || board[row][col]=='O')
        {
            printf("Invalid Move! Try Again.\n");
            continue;
        }

        board[row][col] = mark;
        moves++;

        if(checkWinner())
        {
            displayBoard();
            printf("Player %d (%c) Wins!\n", turn, mark);
            break;
        }

        if(moves == 9)
        {
            displayBoard();
            printf("Match Draw!\n");
            break;
        }

        if(turn == 1)
            turn = 2;
        else
            turn = 1;
    }

    return 0;
}