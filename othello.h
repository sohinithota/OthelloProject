#ifndef _OTHELLO_H_
#define _OTHELLO_H_

#include <stdio.h>

#define BOARDSIZE 8
#define ROWS 8
#define COLUMNS 8


#define player_1 'b'
#define player_2 'w'
#define empty_space 'x'
#define valid_space 'o'

//othello board is going to be a board of chars
/*key: 
empty/noone =0
 black = 1
 white =2*/
typedef struct othelloBoard{
    //create an array of chars that is an 8x8 board
    //int ROW = 8;
    //int COL = 8;
    char piece;
    //board of chars, can add the othello_piece to it which is also a char
    char oBoard[BOARDSIZE][BOARDSIZE];
    int size;
}oBoard;



//typedef struct othelloBoard oBoard;

//typedef struct othelloBoard myBoard;
void print_othello_board(oBoard *board);
oBoard *initialize_board();
oBoard *initialize_full_board();
char* is_board_full(oBoard *board);
oBoard *copy_board(oBoard *board);
void add_piece_to_board(oBoard *board);
char opponent(char players);
void possible_moves(char player, oBoard *board);
oBoard *highlight_next_move(oBoard *board,char player);
//void highlight_next_move(oBoard *board,char player);
void clear_board_of_openings(oBoard *board);
void function();
char switch_opponent(char players);
//void flip(oBoard *board, char player);
void flip(char player,oBoard *board, int row, int column);
//char valid_move(char player, int row, int column, int inirow, int inicol, oBoard *board );
//char line_match(char player, int row, int column, int inirow, int inicol, oBoard *board);
int is_valid_move(char player, int direcRow, int direcCol, int row, int column, oBoard *board );
int line_match(char player, int direcRow, int direcColumn, int row, int col, oBoard *board);
oBoard *initialize_empty_board();
int flip_one_way(char player, int direcRow, int direcColumn, int row, int column, oBoard *board);
int count_pieces(oBoard *board);
int count_p1_pieces(oBoard *board);
int count_p2_pieces(oBoard *board);
void call_game(oBoard *board);
void track_of_moves(int x, int y);
int if_no_more_moves(oBoard *board,char player);
int no_more_moves(oBoard *board,char player);
#endif