#ifndef Sudoku_Board_H
#define Sudoku_Board_H

#include <iostream>
using namespace std;

class Sudoku{
    public:
    Sudoku(int size) ;
    Sudoku(int size, int (*boar)[9]) ;
    ~Sudoku() ;
    void Create_Board() ;
    void Input_Value(int row,int column,int value) ;
    void Print_Boards() ;
    bool backtracking_algo(int row, int column) ;

    private:
    bool Checker() ;
    int (*board)[9] ;
    int size_of_board ;
    bool check_row(int value, int row) ;
    bool check_col(int value, int col) ; 
    bool check_grid(int value, int row, int col) ;
    void placement_board(int value, int row, int column) ;
} ;

Sudoku::Sudoku(int size){
    size_of_board = size ;
    cout << "\nWelcome to the Sudoku Solver" << endl ;
    cout << "There is no Sudoku puzzle that cannot be solved with this program" << endl ;
}

Sudoku::Sudoku(int size,int (*boar)[9]){
    board = boar ;
    size_of_board = size ;
    cout << "\nWelcome to the Sudoku Solver" << endl ;
    cout << "There is no Sudoku puzzle that cannot be solved with this program" << endl ;
}

Sudoku::~Sudoku(){
    cout << "\nThe destructor has been called" << endl ;
    cout << "Memory has been cleared" << endl ;

}


void Sudoku::Input_Value(int row, int column, int value){
    row  = row - 1 ;
    column = column - 1 ;
    board[row][column] = value ;
}

void Sudoku::Print_Boards(){
    for(int i = 0 ; i < size_of_board ; i++){
        for(int j = 0 ; j < size_of_board ; j++){
            if(board[i][j] != 0){
                cout << "[" << board[i][j] << "]" ;
            }else{
                cout << "[ ]" ;
            }
        }
        cout << endl ;
    }
}

bool Sudoku::check_row(int value, int row){
    for(int i = 0 ; i < size_of_board ; i++){
        if(board[row][i] == value){
            return false ;
        }
    }
    return true ;
}

bool Sudoku::check_col(int value, int col){
    for(int i = 0 ; i < size_of_board ; i++){
        if(board[i][col] == value){
            return false ;
        }
    }
    return true ;
}

bool Sudoku::check_grid(int value, int row, int col){
    int row_head ;
    int col_head ;
    if(row < 3){
        row_head = 0 ;
    }else if(row < 6){
        row_head = 3 ;
    }else{
        row_head = 6 ;
    }

    if(col < 3){
        col_head = 0 ;
    }else if(col < 6){
        col_head = 3 ;
    }else{
        col_head = 6 ;
    }

    for(int i = row_head ; i < row_head + 3; i++){
        for(int j = col_head ; j < col_head + 3 ; j++){
            if(board[i][j] == value){
                return false ;
            }
        }
    }

    return true ;
}

void Sudoku::placement_board(int value, int row, int column){
    board[row][column] = value ;
}

bool Sudoku::Checker(){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            if(board[i][j] == 0){
                return false ;
            }
        }
    }

    return true ;
}

bool Sudoku::backtracking_algo(int row = 0, int column = 0){

    if(Checker()){
        return true ; 
    }

    if(column == 9){
        row++ ;
        column = 0 ;
    }

    for(int i = 1 ; i <= 9 ; i++){
        if(board[row][column] == 0){
            if(check_col(i,column) && check_row(i,row) && check_grid(i,row,column)){
                placement_board(i,row,column) ;
                column++ ;
                if(backtracking_algo(row,column)){
                    return true ;
                }else{
                    column-- ;
                    placement_board(0,row,column) ;
                }
            }
        }else{
            column++ ;
            if(backtracking_algo(row,column)){
                return true ;
            }else{
                column-- ;
                return false ;
            }
        }
    }

    return false ;
}
#endif 


