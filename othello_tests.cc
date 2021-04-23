/* test cases */

#include <gtest/gtest.h>

#include "othello.hh"
//#include "othello.h"

/*can the board be initialized without failure*/
TEST(boardTest,BoardSimple) {
    ASSERT_NO_THROW(oBoard *board = initialize_board());
}
/*more complex test, checks that the board is not full*/
TEST(boardTest,BoardComplex) {
    oBoard *board = initialize_board();
    char* statement = "the board is not full";
    ASSERT_STREQ(statement, is_board_full(board));
}
//test for opponent function, is player 1 '1'?
TEST(oppTest, boardOpponent)
{   
    ASSERT_EQ('b',opponent(player_1));	
}
// tests for the week of 11/1
TEST(highlightTest, BoardHighlight)
{
    oBoard *board = initialize_board();
    char player = player_1;
    int PLAYERTURN = 1;
    highlight_next_move(board,player);
    //char (board->oBoard[2][4] = valid_space);
    ASSERT_EQ('o',(board->oBoard[2][3]));
    ASSERT_EQ('x',(board->oBoard[4][2]));
    ASSERT_EQ('o',(board->oBoard[5][4]));
    ASSERT_EQ('x',(board->oBoard[1][1]));


}
TEST(highlightTest, BoardNotHighlight)
{
    oBoard *board = initialize_board();
    char player = player_1;
    int PLAYERTURN = 1;
    highlight_next_move(board,player);
    //char (board->oBoard[2][4] = valid_space);
    ASSERT_EQ('x',(board->oBoard[1][1]));

}
TEST(clearBoardTest, boardCleared)
{
    oBoard *board = initialize_board();
    oBoard *newBoard = initialize_board();
    highlight_next_move(newBoard, player_1);
    clear_board_of_openings(newBoard);
    ASSERT_EQ(board->oBoard[2][4],newBoard->oBoard[2][4]);

}

//tests for week of 11/8/2020
TEST(switchOpponent, boardSwitch)
{
    char x = switch_opponent(player_1);
    ASSERT_EQ(x,player_2);
}
//int line_match(char player, int direcRow, int direcColumn, int row, int col, oBoard *board)
//asserts that there is no line that can be flipped from an initial board
TEST(lineMatchTest, boardMatch)
{
    oBoard *board = initialize_board();
    int x = line_match(player_1,1,1,4,2,board);
    ASSERT_EQ(x,0);

}
//int is_valid_move(char player, int direcRow, int direcCol, int row, int column, oBoard *board )
TEST(validMoveTest, boardValidity)
{
    oBoard *board = initialize_board();
    int x = is_valid_move(player_1,1,1,4,2,board);
    ASSERT_EQ(x,0);

}
//int flip_one_way(char player, int direcRow, int direcColumn, int row, int column, oBoard *board)
//initialized a full board and flipped accordingly 
TEST(flipTest, boardFlip)
{
    oBoard *board = initialize_full_board();
    int x = flip_one_way(player_1,1,1,5,4,board);
    ASSERT_EQ(x,1);
}

// tests for 11/15/2020 check in 

//this checks if after the board is initialized, it can be highlighted
TEST(highlightTestComplex, boardHighlightP1)
{
     oBoard *board = initialize_board();
    highlight_next_move(board, player_1);
    ASSERT_EQ(board->oBoard[3][2],'o');
}
TEST(highlightTestComplex, boardHighlightP2)
{
     oBoard *board = initialize_board();
    highlight_next_move(board, player_2);
    ASSERT_EQ(board->oBoard[4][2],'o');
}

//this test allows flipping of a premade board, after move one 
TEST(flipTest, flipTesting)
{
    oBoard *board = initialize_board();
    board->oBoard[4][5]= 'b';
    //print_othello_board(board);
    flip(player_1, board, 5,4);
    //print_othello_board(board);
    ASSERT_EQ(board->oBoard[4][4],'b');
}
// these tests checks if an initialized board has 2 pieces for p1, then p2
TEST(countTest,Player1Count)
{
    oBoard *board = initialize_board();
    int c = count_p1_pieces(board);
    ASSERT_EQ(c, 2);
}
TEST(countTest,Player2Count)
{
    oBoard *board = initialize_board();
    int c = count_p2_pieces(board);
    ASSERT_EQ(c, 2);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();


}