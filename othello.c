#include "othello.h"

#include <math.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define valid_space 'o'


/*
#define player_1 'r'
#define player_2 'b'
#define empty_space 'x'
*/
int COUNTER = 1;
int PLAYERTURN = 1;

int PLAYER1COUNT =0;
int PLAYER2COUNT =0;


/*initializes a 8x8 board, with the middle being r's and b's (red and blue later)*/
oBoard *initialize_board()
{
    oBoard *myBoard = malloc(sizeof(oBoard));
    myBoard->size = 64;
    /*sets top numbers to 1-8 at the top of the board*/
    
    for(int i=0;i<8;i++)
    {
        
        for (int j=0;j<8;j++)
        {
            
            myBoard->oBoard[i][j] = empty_space;
            if((myBoard->oBoard[i][j])==(myBoard->oBoard[3][3])|| (myBoard->oBoard[i][j])==(myBoard->oBoard[4][4]))
            {
                
                myBoard->oBoard[i][j]=player_2;
            }
            else if((myBoard->oBoard[i][j])==(myBoard->oBoard[3][4])|| (myBoard->oBoard[i][j])==(myBoard->oBoard[4][3]))
            {
                
                myBoard->oBoard[i][j]=player_1;
            }
            
            
        }
    }
    //print_othello_board(myBoard);
    return myBoard;

}
//function prints the board
void print_othello_board(oBoard *board)
{
    //int column =  malloc(sizeof(int));
    int column =0;

    //int row =  malloc(sizeof(int));
    int row = 0;
   //top of board coordinates
    printf("%s","   0  1  2  3  4  5  6  7");
    
    printf("\n");
    
    for (int i = 0;i< 8;i++ )
    {
        //prints the side numbers of board
        printf("%d  ", column);
        column++;
        for(int j =0;j<8;j++)
        {
            
            
            printf("%c  ",(char)board->oBoard[i][j]);
            
        }
        
        printf("\n");
    }
    
    //printf("\n");
}
/*this function tests if the board is full, i'm adding a full board to this*/
oBoard *initialize_full_board()
{
    oBoard *myBoard = malloc(sizeof(oBoard));
    myBoard->size = 64;
    
    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            myBoard->oBoard[i][j] = player_1;
            myBoard->oBoard[3][3]=player_1;
            myBoard->oBoard[4][4] = player_1;
            myBoard->oBoard[3][4] = player_2;
            myBoard->oBoard[4][3] = player_2;
            
        }
    }
    return myBoard;
    opponent(player_1);
}
oBoard *initialize_empty_board()
{
    oBoard *myBoard = malloc(sizeof(oBoard));
    myBoard->size = 64;
    
    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            myBoard->oBoard[i][j] = empty_space;
        }
    }
    return myBoard;
}
/*this checks if a board has been filled up with r's and b's by checking for an x. later, I will add a "continuing" method to it so gameplay can be resumed*/
char* is_board_full(oBoard *board)
{
    char* returnstat = "the board is not full";
   for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if ((board->oBoard[i][j])== empty_space)
            {
                printf ("%s","the board is not full\n");
                goto returnStatement;
                //printf ("%s","the board is not full\n");
                goto endOfGame;
                //break;
            }
            
        }
        endOfGame:
        break;

        returnStatement:
        return returnstat;
    }
    
}
/*this function copies the board to another board, we will use this so we can revert moves later*/
oBoard *copy_board(oBoard *board)
{
    oBoard *newBoard = malloc(sizeof(oBoard));
    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            //(board->oBoard[i][j]) = (newBoard->oBoard[i][j]);
            (newBoard->oBoard[i][j]) =(board->oBoard[i][j]);
            
        }
    }
    print_othello_board(newBoard);
    return newBoard;
}
/*char c will be the player's turn, this function takes in a scanner, and puts a piece to the location that the user chooses*/
void add_piece_to_board(oBoard *board)
{
    
    
    int k = 0;
    
    //int COUNTER = 1;
    char opp = 'x';
    if(COUNTER%2==1)
    {
        opp = opponent(player_1);
        COUNTER = COUNTER+1;

        
    }
    else if (COUNTER%2==0)
    {
        opp = opponent(player_2);
        COUNTER = COUNTER+1;
        
    }
    
    highlight_next_move(board,opp);
    no_more_moves(board,opp);
    int x = no_more_moves(board,opp);
    if(x ==0)
    {
        printf("no more valid moves for %\c, switch to the next player.\n",opp);
        opp=switch_opponent(opp);
        highlight_next_move(board,opp);
    }
   if(k==0)
    {
    print_othello_board(board);
    printf("player %c: %d chips\n",player_1,count_p1_pieces(board));
    PLAYER1COUNT =0;

    //count_p1_pieces(board);
    printf("player %c: %d chips\n",player_2,count_p2_pieces(board));
    PLAYER2COUNT=0;
    k++;
    }
    if(PLAYERTURN<61)
    {
    printf("it is player %c 's turn, and it is turn %d \n", opp, PLAYERTURN);
    }

    call_game(board);
   int x_index;
   int y_index;
   char ans;
    coordinate:
    {
        printf("please enter a x coordinate to place your piece. you can pick from an 'o' spot!");
        scanf("%d",&x_index);
    
        printf("please enter a y coordinate to place your piece.");
        scanf("%d",&y_index);
        
    }
    printf("you selected the coordinate %d,%d would you like to continue? y or n:", x_index,y_index);
   scanf(" %c",&ans);

    if(ans =='y')
    {
        goto continue_game;
    }
    if(ans =='n')
    {
        goto coordinate;
    }
    else
    {
        printf("type a letter please");
        printf("you selected the coordinate %d,%d would you like to continue? y or n:", x_index,y_index);
    scanf(" %c",&ans);
    }
    continue_game:
    {
     if((board->oBoard[y_index][x_index])==valid_space)
     {
       //printf("%c",(board->oBoard[x_index][y_index]));
        (board->oBoard[y_index][x_index]) = opp;
        //char* statement = "";
       clear_board_of_openings(board);
       flip(opp, board, y_index,x_index);
        PLAYERTURN++;
       
   }
   else
   {
       printf("%s","this space is not valid. pick another pls!\n");
       COUNTER--;
       add_piece_to_board(board);
   }
   //this is the important print
    //clear_board_of_openings(board);
    //printf("%c",board->oBoard[4][4]);
    //board = highlight_next_move(board,opp);
    //count_pieces(board);
   // print_othello_board(board);
   /*
   if(PLAYERTURN==61)
   {
       printf("game over");
   }
   */
   
      add_piece_to_board(board);
   
}
}
void call_game(oBoard *board)
{
    if(PLAYERTURN==61) 
    {
        printf("game is over, ");
        if(count_p1_pieces(board)>count_p2_pieces(board))
        {
            printf("%c wins!\n",player_1);
            exit(0);
        }
        else if(count_p2_pieces(board)>count_p1_pieces(board))
        {
            printf("%c wins!\n", player_2);
            exit(0);
        }
        else if(count_p1_pieces(board)==count_p2_pieces(board))
        {
            printf("it's a draw!");
            exit(0);
        } 

    }
    else
    {
        printf("game is not over yet, please continue:\n");
    }
    
}
int if_no_more_moves(oBoard *board,char player)
{
    /* declare global array that is empty
    loop through array, if a character is an o, add that value of i to the array
    if array is empty, no more moves */
    int arr[30];
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if(board->oBoard[i][j]==valid_space)
            {
                arr[0]=7;
                return 1;
            }
        }
    }
    if(arr[0]!=7)
    {
        printf("no more valid moves\n");
        PLAYERTURN++;
        return 0;
    }
    else
    {
        printf("there are valid moves.\n");
        return 1;
    }
}
int no_more_moves(oBoard *board,char player)
{
    /* declare global array that is empty
    loop through array, if a character is an o, add that value of i to the array
    if array is empty, no more moves */
    int arr[30];
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if(board->oBoard[i][j]==valid_space)
            {
                arr[0]=7;
                return 1;
            }
        }
    }
    if(arr[0]!=7)
    {
        
       // PLAYERTURN++;
        return 0;
    }
    else
    {
       
        return 1;
    }
}
/*allows us to pick player 1 or 2*/
char opponent(char players)
{
    switch(players){
        case player_1: 
            return player_1;
        case player_2: 
            return player_2;
    }
}

char switch_opponent(char players)
{
    switch(players){
        case player_2: 
            return player_1;
        case player_1: 
            return player_2;
    }
}
/*function gets rid of openings on board after each turn*/
void clear_board_of_openings(oBoard *board)
{
    for(int i=0;i<8;i++)
            {
                for (int j=0;j<8;j++)
                {    
                    if(board->oBoard[i][j]== valid_space )
                    {
                        board->oBoard[i][j] = empty_space;
                    }
                }
            }
            
}

int count_p1_pieces(oBoard *board)
{
    //char* statement = ("player 1: %d chips\n",PLAYER1COUNT);
    for(int i=0;i<8;i++)
            {
                for (int j=0;j<8;j++)
                {   
                    if(board->oBoard[i][j]==player_1){
                    PLAYER1COUNT++;
                    }


                }
            }
            //printf("player 1: %d chips\n",PLAYER1COUNT);
            //return PLAYER1COUNT;
           // printf("player 1: %d chips\n",PLAYER1COUNT);
           return PLAYER1COUNT;
           PLAYER1COUNT=0;
            
}
int count_p2_pieces(oBoard *board)
{
    for(int i=0;i<8;i++)
            {
                for (int j=0;j<8;j++)
                {   
                    if(board->oBoard[i][j]==player_2){
                    PLAYER2COUNT++;
                    
                    }
                }
            }
            return PLAYER2COUNT;
            PLAYER2COUNT =0;
            
}
//check if there is a color of player on line at row,column or anwhere futhere by adding to row,column, a fun recursive function!
int line_match(char player, int direcRow, int direcColumn, int row, int col, oBoard *board)
{
    //if the board matches the player, then it is true. this function recursively keeps adding to this part of the function until we hit a 0
    if((board->oBoard[row][col]== player) && (player != 'o'))
   // if(board->oBoard[row][col]== player)
    {
        return 1;
    }
    
    if(board->oBoard[row][col]== empty_space)
    {
        return 0;
    }
    
    if(board->oBoard[row][col]== valid_space)
    {
        return 0;
    }
    if((row+direcRow<0) || (row+direcRow >7))
    {
        return 0;
    }
    if((col+direcColumn) <0 || (col+direcColumn >7))
    {
        return 0;
    }
    return line_match(player, direcRow, direcColumn, direcRow+row, direcColumn+col,board);
}
//check if position at initrow,initcolumn contains opposite of the player on board, and line indicated by adding dr to r and dc to c ends in the opposite player color

int is_valid_move(char player, int direcRow, int direcCol, int row, int column, oBoard *board )
{
    char opponent;
    //char opponent= switch_opponent(player);
    if(player == player_1)
    {
        opponent = player_2;
    }
    if (player == player_2)
    {
        opponent = player_1;
    }
    
    int rowadding = row+direcRow;
    int columnadding = column + direcCol;
    //prevents going off edges of the rows and then columns
    // without these, I get seg faultsD:
    if(((rowadding <0) || (rowadding >7)) )
    {
        return 0;
    }
    if((columnadding) <0 || (columnadding >7))
    {
        return 0;
    }
    if((board->oBoard[rowadding][columnadding]) != opponent)
    {
        return 0;
    }
    //prevents running off the edges of the board
    if((columnadding+direcCol) <0 || (columnadding+direcCol >7))
    {
        return 0;
    }
    if((rowadding+direcRow <0) || (rowadding+direcRow >7))
    {
        return 0;
    }
    //the method that highlights if it is valid, uses recursion!
    if( (line_match(player,direcRow, direcCol, row+direcRow+direcRow, column+direcCol+direcCol,board) == 1) )
    //if( (line_match(player,direcRow, direcCol, row+direcRow+direcRow, column+direcCol+direcCol,board) == 1 && (board->oBoard[row][column]== empty_space) ) )
    {
        board->oBoard[row][column]= valid_space;
    }
    

}
oBoard* highlight_next_move(oBoard *board,char player)
{
    oBoard *emptyBoard = malloc(sizeof(oBoard));
    emptyBoard = initialize_empty_board();
    emptyBoard->size = 64;

    for(int row=0;row<8;row++)
    {
       for(int column =0;column<8;column++)
       {
           if(board->oBoard[row][column] == empty_space)
           {
                int left = is_valid_move(player, 0,1,row,column,board); 
                int right = is_valid_move(player, 0,-1,row,column,board); 
            
                int downstraight = is_valid_move(player,-1 ,0, row, column, board);
                int upstraight = is_valid_move(player, 1,0, row, column, board);
                int downright = is_valid_move(player,-1 ,-1, row, column, board);
                int downleft = is_valid_move(player,-1 ,1, row, column, board);
                int upright = is_valid_move(player,1 ,-1, row, column, board);
                int upleft = is_valid_move(player,1 ,1, row, column, board);
            
            if( (  left || right || downstraight ||  upleft || upright || upstraight || downright ||downleft  ==1) )
            {
                
                board->oBoard[row][column]= valid_space;
                //printf("nw:%d nn:%d ne:%d ww:%d ee:%d sw:%d ss:%d se:%d\n ",nw, (int)nn, ne, ww, ee, sw, ss, se);
                //printf("%d\n");
            }
           }
       }
    }
    return board;
}


int flip_one_way(char player, int direcRow, int direcColumn, int row, int column, oBoard *board)
{
    int rowMovement = row + direcRow;
    int columnMovement = column +direcColumn;
    if((rowMovement<0 || rowMovement>7) || (columnMovement<0 || columnMovement>7) ) 
    {
         return 0;
    }
    if(board->oBoard[rowMovement][columnMovement]== empty_space)
    {
        return 0;
    }
    if(board->oBoard[rowMovement][columnMovement] == player)
    {
        return 1;
    }
    else
    {
        if((flip_one_way(player, direcRow, direcColumn, rowMovement, columnMovement, board))==1)
        {
            board->oBoard[rowMovement][columnMovement]= player;
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    
}

/*logic is just like the highlight function, but there is a helper function called flip_one_way that actually double checks to make sure the pieces can flip properly*/
void flip(char player,oBoard *board, int row, int column)
{
    int right = flip_one_way(player, 0,-1,row,column,board);
    int left = flip_one_way(player, 0,1,row,column,board);
    int upstraight = flip_one_way(player, 1, 0,row,column,board);
    int upleft = flip_one_way(player, 1, 1,row,column,board);
    int upright = flip_one_way(player, 1, -1,row,column,board);
    int downstraight = flip_one_way(player, -1,0,row,column,board);
    int downleft = flip_one_way(player, -1, 1,row,column,board);
    int downright = flip_one_way(player, -1, -1,row,column,board);

}
