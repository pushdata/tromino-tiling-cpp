#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


using namespace std;
int count=0;
void tromino(int x_hole,int y_hole,int x_board, int y_board,int size, char (*board)[size],int board_size);
void printBoard(int size, char (*board)[size]){
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if(board[i][j]==(-1)){
                printf("X\t");
            }else{
                printf("%d\t",board[i][j]);
            }

        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    int k;
    if(argc!=4){
        cout<<"Usage: ./tromino.out <value of k> <hole position row number> <hole position column number>"<<endl;
        return -1;
       }
        srand((unsigned)time(NULL));
    if(atoi(argv[1])<1){
        printf("Board should not be less than than 2*2 \n");
    }else{
        k=atoi(argv[1]);
        int board_size=(int)pow(2,k);
        int i,j,x,y;
        count=0;
        x=atoi(argv[2]);//Hole X-Coordinate
        y=atoi(argv[3]);//Hole Y-Coordinate
        char board[board_size][board_size];
        for ( i = 0; i < board_size; ++i){
            for ( j = 0; j < board_size; ++j){
                board[i][j]=0;
            }
        }
        board[x][y]='X';
        tromino(x,y,0,0,board_size,board,board_size);
        printBoard(board_size,board);
    }
    return 0;
}


void tromino(int x_hole,int y_hole,int x_board, int y_board,int size, char (*board)[size],int board_size){
    if(board_size==2){
        count++;//For printing number in tromino tile
        int i,j;
        for ( i = x_board; i < (x_board+board_size); ++i)
        {
            for ( j = y_board; j< (y_board+board_size); ++j)
            {
                if(!(i==x_hole && j==y_hole)){
                    board[i][j]=(char)count;
                }
            }
        }
        return;

    }
    count++;//Printing next number for next tromino tile

    int new_size=board_size/2,x_center,y_center;
    int x_top_right,y_top_right,x_top_left,y_top_left, x_bottom_right,y_bottom_right,x_bottom_left,y_bottom_left;
    x_center=x_board+new_size;
    y_center=y_board+new_size;

    if(x_hole<x_center && y_hole< y_center){
        board[x_center-1][y_center]=board[x_center][y_center-1]=board[x_center][y_center]=(char)count;

        x_top_left=x_hole;y_top_left=y_hole;

        x_top_right=x_center-1; y_top_right=y_center;

        x_bottom_left=x_center; y_bottom_left=y_center-1;

        x_bottom_right=x_center; y_bottom_right=y_center;

    }else if(x_hole<x_center && y_hole>=y_center){
        board[x_center-1][y_center-1]=board[x_center][y_center-1]=board[x_center][y_center]=(char)count;

        x_top_left=x_center-1; y_top_left=y_center-1;

        x_top_right=x_hole; y_top_right=y_hole;

        x_bottom_left=x_center; y_bottom_left= y_center-1;

        x_bottom_right = x_center ; y_bottom_right = y_center;


    }else if(x_hole>=x_center && y_hole<y_center){
        board[x_center-1][y_center-1]=board[x_center-1][y_center]=board[x_center][y_center]=(char)count;

        x_top_left=x_center-1;y_top_left=y_center-1;

        x_top_right=x_center-1; y_top_right=y_center;

        x_bottom_left=x_hole; y_bottom_left=y_hole;

        x_bottom_right=x_center; y_bottom_right=y_center;


    }else if(x_hole>=x_center && y_hole>=y_center){
        board[x_center-1][y_center-1]=board[x_center-1][y_center]=board[x_center][y_center-1]=(char)count;

        x_top_left=x_center-1;y_top_left=y_center-1;

        x_top_right=x_center-1; y_top_right=y_center;

        x_bottom_left=x_center; y_bottom_left=y_center-1;

        x_bottom_right=x_hole; y_bottom_right=y_hole;

    }

    tromino(new_size,x_top_left, y_top_left, x_board,y_board,board,size);

    tromino(new_size,x_top_right, y_top_right, x_board,y_board+new_size,board,size);

    tromino(new_size,x_bottom_left, y_bottom_left, x_board+new_size,y_board,board,size);

    tromino(new_size,x_bottom_right, y_bottom_right, x_board+new_size,y_board+new_size,board,size);
}

