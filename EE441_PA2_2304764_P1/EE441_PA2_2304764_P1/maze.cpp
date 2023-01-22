#include "maze.h"
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
Maze::Maze()
{
 ifstream input_file; /* input file stream */
 input_file.open ("input_maze.txt");
 int nrow, ncol; /* number of rows and columns */
 input_file >> nrow >> ncol; /* read the size from file */
 n_row = nrow;
 n_col= ncol;
 for(int i=0; i<n_row; i++)
    {
     for(int j=0; j<n_col; j++)
     {
        input_file >> state[i][j];
     }
 }
 input_file.close();
 for(int i=0; i<n_row; ++i)
 {
     for(int j=0; j<n_col; ++j)
        {
        if(state[i][j] == 'T')
        {
            t_row = i;
            t_col = j;
        }
        else if(state[i][j] == 'W' || state[i][j] == 'E' || state[i][j] == 'S' ||state[i][j] == 'N')
        {
            orientation = state[i][j];
            a_row = i;
            a_col = j;
        }
     }
 }
}
Maze::Maze(const Maze &maze)
{
    n_row = maze.n_row;
    n_col = maze.n_col;
    orientation = maze.orientation;
    a_row = maze.a_row;
    a_col = maze.a_col;
    t_row = maze.t_row;
    t_col = maze.t_col;
    int i = 0;
    int j = 0;
    while (i < n_row && j < n_col)
    {
        state[i][j] = maze.state[i][j];
        j++;
        if (j >= n_col)
        {
            j = 0;
            i++;
        }
    }
}
void Maze::print_state() const{
 for(int i=0; i<n_row; i++){
     for(int j=0; j<n_col; j++){
        cout<<' '<<this->state[i][j];
     }
     cout<<endl;
 }
}
bool Maze::can_move_forward(void){
    switch (this->orientation) {
        case 'W':
            return state[a_row][a_col-1] == '.' || state[a_row][a_col-1] == 'T';
        case 'E':
            return state[a_row][a_col+1] == '.' || state[a_row][a_col+1] == 'T';
        case 'N':
            return state[a_row-1][a_col] == '.' || state[a_row-1][a_col] == 'T';
        case 'S':
            return state[a_row+1][a_col] == '.' || state[a_row+1][a_col] == 'T';
    }
}
void Maze::move_forward(void){
    if (this->can_move_forward()) {
        switch (this->orientation) {
            case 'W':
                state[a_row][a_col] ='.';
                a_col -=1;
                state[a_row][a_col] ='W';
                orientation = 'W';
                break;
            case 'E':
                state[a_row][a_col] ='.';
                a_col +=1;
                state[a_row][a_col] ='E';
                orientation = 'E';
                break;
            case 'N':
                state[a_row][a_col] ='.';
                a_row -=1;
                state[a_row][a_col] ='N';
                orientation = 'N';
                break;
            case 'S':
                state[a_row][a_col] ='.';
                a_row +=1;
                state[a_row][a_col] ='S';
                orientation = 'S';
                break;
        }
    }
}
bool Maze::can_move_back(void){
    switch (this->orientation) {
        case 'W':
            return state[a_row][a_col+1] == '.' || state[a_row][a_col+1] == 'T';
        case 'E':
            return state[a_row][a_col-1] == '.' || state[a_row][a_col-1] == 'T';
        case 'N':
            return state[a_row+1][a_col] == '.' || state[a_row+1][a_col] == 'T';
        case 'S':
            return state[a_row-1][a_col] == '.' || state[a_row-1][a_col] == 'T';
    }
}
void Maze::move_back(void){
    if (this->can_move_back()) {
        switch (this->orientation) {
            case 'W':
                state[a_row][a_col] ='.';
                a_col +=1;
                state[a_row][a_col] ='E';
                orientation = 'E';
                break;
            case 'E':
                state[a_row][a_col] ='.';
                a_col -=1;
                state[a_row][a_col] ='W';
                orientation = 'W';
                break;
            case 'N':
                state[a_row][a_col] ='.';
                a_row +=1;
                state[a_row][a_col] ='S';
                orientation = 'S';
                break;
            case 'S':
                state[a_row][a_col] ='.';
                a_row -=1;
                state[a_row][a_col] ='N';
                orientation = 'N';
                break;
        }
    }
}
bool Maze::can_move_left(void){

    switch (this->orientation) {
        case 'W':
            return state[a_row+1][a_col] == '.' || state[a_row+1][a_col] == 'T';
        case 'E':
            return state[a_row-1][a_col] == '.' || state[a_row-1][a_col] == 'T';
        case 'N':
            return state[a_row][a_col-1] == '.' || state[a_row][a_col-1] == 'T';
        case 'S':
            return state[a_row][a_col+1] == '.' || state[a_row][a_col+1] == 'T';
    }
}
void Maze::move_left(void){
    if (this->can_move_left()) {
        switch (this->orientation) {
            case 'W':
                state[a_row][a_col] ='.';
                a_row +=1;
                state[a_row][a_col] ='S';
                orientation = 'S';
                break;
            case 'E':
                state[a_row][a_col] ='.';
                a_row -=1;
                state[a_row][a_col] ='N';
                orientation = 'N';
                break;
            case 'N':
                state[a_row][a_col] ='.';
                a_col -=1;
                state[a_row][a_col] ='W';
                orientation = 'W';
                break;
            case 'S':
                state[a_row][a_col] ='.';
                a_col +=1;
                state[a_row][a_col] ='E';
                orientation = 'E';
                break;
        }
    }
}
bool Maze::can_move_right(void){
    switch (this->orientation) {
        case 'W':
            return state[a_row-1][a_col] == '.' || state[a_row-1][a_col] == 'T';
        case 'E':
            return state[a_row+1][a_col] == '.' || state[a_row+1][a_col] == 'T';
        case 'N':
            return state[a_row][a_col+1] == '.' || state[a_row][a_col+1] == 'T';
        case 'S':
            return state[a_row][a_col-1] == '.' || state[a_row][a_col-1] == 'T';
    }
}
void Maze::move_right(void){
    if (this->can_move_right()) {
        switch (this->orientation) {
            case 'W':
                state[a_row][a_col] ='.';
                a_row -=1;
                state[a_row][a_col] ='N';
                orientation = 'N';
                break;
            case 'E':
                state[a_row][a_col] ='.';
                a_row +=1;
                state[a_row][a_col] ='S';
                orientation = 'S';
                break;
            case 'N':
                state[a_row][a_col] ='.';
                a_col -=1;
                state[a_row][a_col] ='E';
                orientation = 'E';
                break;
            case 'S':
                state[a_row][a_col] ='.';
                a_col +=1;
                state[a_row][a_col] ='W';
                orientation = 'W';
                break;
        }
    }
}
bool Maze::is_solved(void){

    return (a_row == t_row && a_col == t_col);
}
