//Vector Vector multiplication

#include <iostream>
#include <vector>

#include "matrix.h";


using namespace std;

///xd
std::vector<std::vector<float>> matrix_multiplication(std::vector<std::vector<float>>& vector1, std::vector<std::vector<float>>& vector2){
    std::vector<std::vector<float>> v(4, std::vector<float>(4, 0));
    try{
        for(const auto& fila : vector1){
            if(fila.size() != vector1.size()){
                throw "VECTOR_1_IS_NOT_SQUARE";
            }
        }

        for(const auto& fila : vector2){
            if(fila.size() != vector2.size()){
                throw "VECTOR_2_IS_NOT_SQUARE";
            }
        }

    } catch(const char* e){
        std::cerr << "ERROR::" << e;
        return v;
    }

    //If code its running here then both vectors are square

    if( vector1[0].size() != vector2.size()){
        std::cerr << "ERRROR::MATRIX_LENGTH_DOES_NOT_MATCH" << std::endl;
        return v;
    }
    int vector_size = static_cast<int>(vector1.size());
    std::vector<std::vector<float>> matrix_result(vector_size, std::vector<float>(vector_size, 0));

    for(int i = 0; i < vector_size; i++){
        for(int k = 0; k < vector_size; k++){
            int tem = vector1[i][k];
            for(int j = 0; j < vector_size; j++){
                matrix_result[i][j] += (tem * vector2[k][j]);
            }
        }
    }
    std::cout << "Matriz (" << &matrix_result << ") " << vector_size << "x" << vector_size << " calculada correctamente." << std::endl;
    return matrix_result;
}

int main(){
    std::vector<std::vector<float>> m1 = {
                        {4, 2, 0},
                        {0, 8, 1},
                        {0, 1, 0},
                     };
    std::vector<std::vector<float>> m2 = {
                        {4, 2, 1},
                        {2, 0, 4},
                        {9, 4, 2},
                     };
    //2nd Matrices--------------------------------

    std::vector<std::vector<float>> m3 = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9},
                     };
    std::vector<std::vector<float>> m4 = {
                        {9, 8, 7},
                        {6, 5, 4},
                        {3, 2, 1},
                     };
    //3rd Matrices---------------------------------
    std::vector <std::vector<float>> m5 = {
                                            {1, 2, 3, 4},
                                            {5, 6, 7, 8},
                                            {9, 1, 2, 3},
                                            {4, 5, 6, 7},
                                          };
    std::vector <std::vector<float>> m6 = {
                                            {1, 0, 2, 1},
                                            {0, 1, 0, 2},
                                            {2, 1, 0, 0},
                                            {1, 2, 1, 0},
                                          };

    std::vector<std::vector<float>> mx(1000, std::vector<float>(1000, 1));
    std::vector<std::vector<float>> my(1000, std::vector<float>(1000, 3));

    //std::vector<std::vector<float>> result = matrix_multiplication(m1, m2);
    /*
    for(size_t i = 0; i < result.size(); i++){
        for(size_t j = 0; j < result[i].size(); j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    Matrix4 m = {4, 2, 0, 4,
                 0, 8, 1, 8,
                 0, 1, 0, 3,
                 0, 3, 4, 7};

    Matrix4 _m = {4, 2, 1, 1,
                  0, 1, 0, 2,
                  2, 0, 4, 4,
                  9, 4, 2, 6};

    Matrix3 mx2 = {4, 2, 0,
                   0, 8, 1,
                   0, 1, 0};

    Matrix3 mx3 = {4, 2, 1,
                   2, 0, 4,
                   9, 4, 2};



    Matrix2 result = Matrix2({1, 2, 3, 4}) * Matrix2({5, 6, 7, 8});


    for(size_t i = 0; i < 2; i++){
        for(size_t j = 0; j < 2; j++){
            std::cout << result[i * 2 + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
