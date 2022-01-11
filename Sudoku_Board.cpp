#include <iostream>
#include "Sudoku_Board.h"
#include <string>
using namespace std;

int main(){
    int board[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 8, 7, 0, 0, 0, 0, 0, 1}, 
    {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
    {0, 0, 0, 8, 6, 3, 0, 0, 5}, 
    {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
    {1, 0, 0, 0, 0, 0, 2, 5, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0} } ;

    int board_2[9][9] = { {0, 2, 0, 6, 0, 8, 0, 0, 0}, 
    {5, 8, 0, 0, 0, 9, 7, 0, 0}, 
    {0, 0, 0, 0, 4, 0, 0, 0, 0}, 
    {3, 7, 0, 0, 0, 0, 5, 0, 0}, 
    {6, 0, 0, 0, 0, 0, 0, 0, 4}, 
    {0, 0, 8, 0, 0, 0, 0, 1, 3}, 
    {0, 0, 0, 0, 2, 0, 0, 0, 0}, 
    {0, 0, 9, 8, 0, 0, 0, 3, 6}, 
    {0, 0, 0, 3, 0, 6, 0, 9, 0} } ;
    
    Sudoku A (9,board);
    Sudoku B (9,board_2) ;
    //A.Create_Board() ;

    bool check = false ;

    int row ;
    int column ;
    int value ;
    char check_to_continue ;


    cout << endl;

    A.Print_Boards() ;

    cout << endl ;

    A.backtracking_algo() ;

    A.Print_Boards() ;

    cout << endl ;

    cout << endl;

    B.Print_Boards() ;

    cout << endl ;

    B.backtracking_algo() ;

    B.Print_Boards() ;

    cout << endl ;
    


}