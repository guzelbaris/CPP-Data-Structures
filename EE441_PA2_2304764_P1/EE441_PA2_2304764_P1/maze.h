#ifndef maze_h
#define maze_H
// Constants defined in the PDF file
constexpr int Column_Maximum_Size=20, Row_Maximum_Size =20;
class Maze {
    private:
        //char** state;
        char state[Row_Maximum_Size][Column_Maximum_Size];
        int n_row,n_col; // row and column size of the input file
        char orientation;
        int a_row,a_col,t_row,t_col; //a_ specifies agent and t_ specifies target row and column

    public:
        Maze();// constructor
        Maze(const Maze &maze);// copy constructor
        bool can_move_forward(void);// given in the pdf
        void move_forward(void);// given in the pdf
        bool can_move_back(void);// given in the pdf
        void move_back(void);// given in the pdf
        bool can_move_left(void);// given in the pdf
        void move_left(void);// given in the pdf
        bool can_move_right(void);// given in the pdf
        void move_right(void);// given in the pdf
        void print_state() const;// given in the pdf
        bool is_solved(void);// given in the pdf
};
#endif // maze_h
