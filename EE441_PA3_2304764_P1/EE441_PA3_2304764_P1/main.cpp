#include <iostream>
#include "Matrix.h"
#include "Tree.h"

long determinant(Matrix M, BST& storage) {
    // check if M exists in storage
    int j;
    if (storage.key_exists(M)) {
        // return result corresponding to M from storage
        // M.display();  I added this line to observe sub matrix
        // cout<<"yes"<<endl; I added this line to observe sub matrix
        return storage.search(M);
    } else {
        // M.display();  I added this line to observe sub matrix
        // cout<<"no"<<endl; I added this line to observe sub matrix
        // calculate result recursively using cofactor method
        long result = 0;
        if (M.n_ == 1) {
            return M.data_[0][0];
        } else {
            for (int i = 0; i < M.n_; i++) {
                // create sub-matrix for cofactor
                Matrix sub_matrix;
                sub_matrix.n_ = M.n_ - 1;
                for (int j = 0; j < sub_matrix.n_; j++) {
                    for (int k = 0; k < sub_matrix.n_; k++) {
                        if (k < i) {
                            sub_matrix.data_[j][k] = M.data_[j+1][k];
                        } else {
                            sub_matrix.data_[j][k] = M.data_[j+1][k+1];
                        }
                    }
                }
                // calculate cofactor
                long cofactor = M.data_[0][i] * determinant(sub_matrix, storage);
                // alternate signs for each element
                if ((i+j) % 2 == 0) {
                    result += cofactor;
                } else {
                    result -= cofactor;
                }
            }
            // store (M, result) in storage
            storage.insert(M, result);
            // return result
            return result;
        }
    }
}


using namespace std;

int main() {
long det;
BST storage;

/* Matrix deneme(3);
deneme.set(0,0,1);
deneme.set(0,1,2);
deneme.set(0,2,3);
deneme.set(1,0,4);
deneme.set(1,1,5);
deneme.set(1,2,6);
deneme.set(2,2,7);
deneme.set(2,0,8);
deneme.set(2,1,9);
det=determinant(deneme,storage);
*/

/* Start First Matrix of 11*11 */
Matrix M_11_0(11); // In my project folder I added all matrices.

M_11_0.fillFromFile("11/0.txt");

M_11_0.display();

det=determinant(M_11_0,storage);

cout << "Determinant of M: " << det <<endl<<endl; // Determinant of The First Matrix 11*11

/* End First Matrix of 11*11 */

/* Start First Matrix of 12*12 */

Matrix M_12_0(12);  // In my project folder I added all matrices.
    M_12_0.fillFromFile("12/0.txt");
    M_12_0.display();

det=determinant(M_12_0,storage);

cout << "Determinant of M: " << det <<endl; // Determinant of The First Matrix 12*12

/* End First Matrix of 12*12 */

return 0;
}
