// Barýþ GÜZEL 2304764 Programming Assigment 2
#include <iostream>
#include<string>
#include <fstream>
#include "maze.h"
#include "stackqueue.h"
using namespace std;
// Constants defined in the PDF file
int main()
{
    int i;
    char a;
    Maze maze;
    cout<<"SQ: "<<endl;
    maze.print_state();
    StackQueue<char>  sq;
    while (!maze.is_solved()){
    if (maze.can_move_left()) {
    maze.move_left();
    if (sq.data[sq.front-1] != 'B') {
      sq.push_front('L');
    } else {
      if (sq.data[sq.front-1] == 'L' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('F');
      } else if (sq.data[sq.front-1] == 'F' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('R');
      } else if (sq.data[sq.front-1] == 'R' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('B');
      }
    }
    cout<<"SQ: ";
    sq.print_elements();
    cout<<endl;
    maze.print_state();
  }
else if (maze.can_move_forward()) {
    maze.move_forward();
    if (sq.data[sq.front-1] != 'B') {
      sq.push_front('F');
    } else {
      if (sq.data[sq.front-1] == 'L' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('F');
      } else if (sq.data[sq.front-1] == 'F' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('R');
      } else if (sq.data[sq.front-1] == 'R' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('B');
      }
    }
     cout<<"SQ: ";
    sq.print_elements();
    cout<<endl;
    maze.print_state();
  }
  else if (maze.can_move_right()) {
    maze.move_right();
    if (sq.data[sq.front-1] != 'B') {
      sq.push_front('R');
    }

    else {
      if (sq.data[sq.front-1] == 'L' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('F');
      } else if (sq.data[sq.front-1] == 'F' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('R');
      } else if (sq.data[sq.front-1] == 'R' && sq.data[sq.front-2] == 'B') {
        sq.pop_front();
        sq.pop_front();
        sq.push_front('B');
      }
    }
     cout<<"SQ: ";
    sq.print_elements();
    cout<<endl;
    maze.print_state();
  }
    else {
    maze.move_back();
    sq.push_front('B');
    cout<<"SQ: ";
    sq.print_elements();
    cout<<endl;
    maze.print_state();
  }
//maze.reset();
if(maze.is_solved()){
    cout<<"Maze is solved";
}
    }
    return 0;
}
