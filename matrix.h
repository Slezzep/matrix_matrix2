///Wujuju
#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>



class Matrix4{
    public:
        Matrix4(std::initializer_list<float> list) : cols(4), rows(4) {
            std::copy(list.begin(), list.end(), data);
        }

        float& operator[](size_t index){
            return data[index];
        }
        const float& operator[](size_t index) const{
            return data[index];
        }

        size_t size(){
            return sizeof(this->data) / sizeof(this->data[0]);
        }

        Matrix4 operator*(const Matrix4 &other){
            //If code its running here then both vectors are square

            Matrix4 matrix_result = {0,0,0,0,
                                     0,0,0,0,
                                     0,0,0,0,
                                     0,0,0,0};

            for(int i = 0; i < 4; i++){
                for(int k = 0; k < 4; k++){
                    float tem = this->data[i * 4 + k];
                    for(int j = 0; j < 4; j++){
                        matrix_result[i * 4  + j] += (tem * other[k * 4 + j]);
                    }
                }
            }
            //std::cout << "Matriz (" << &matrix_result[0] << "," << &matrix_result << ") " << 4 << "x" << 4 << " calculada correctamente." << std::endl;
            return matrix_result;
        }
    private:
         size_t cols, rows;
         float data[16];

};

class Matrix3{
    public:
        Matrix3(std::initializer_list<float> list) : cols(3), rows(3) {
            std::copy(list.begin(), list.end(), data);
        }
        Matrix3(float& v){

        }

        float& operator[](size_t index){
            return data[index];
        }
        const float& operator[](size_t index) const{
            return data[index];
        }


        size_t size(){
            return sizeof(this->data) / sizeof(this->data[0]);
        }

        Matrix3 operator*(const Matrix3 &other){
            //If code its running here then both vectors are square

            Matrix3 matrix_result = {0,0,0,
                                     0,0,0,
                                     0,0,0};

            for(int i = 0; i < 3; i++){
                for(int k = 0; k < 3; k++){
                    float tem = this->data[i * 3 + k];
                    for(int j = 0; j < 3; j++){
                        matrix_result[i * 3  + j] += (tem * other[k * 3 + j]);
                    }
                }
            }
            //std::cout << "Matriz (" << &matrix_result[0] << "," << &matrix_result << ") " << 4 << "x" << 4 << " calculada correctamente." << std::endl;
            return matrix_result;
        }
    private:
         size_t cols, rows;
         float data[9];

};

class Matrix2{
    public:
        Matrix2(std::initializer_list<float> list) : cols(2), rows(2) {
            std::copy(list.begin(), list.end(), data);
        }
        Matrix2(float& v){

        }

        float& operator[](size_t index){
            return data[index];
        }
        const float& operator[](size_t index) const{
            return data[index];
        }


        size_t size(){
            return sizeof(this->data) / sizeof(this->data[0]);
        }

        Matrix2 operator*(const Matrix2 &other){
            //If code its running here then both vectors are square

            Matrix2 matrix_result = {0,0,0,
                                     0,0,0,
                                     0,0,0};

            for(int i = 0; i < 2; i++){
                for(int k = 0; k < 2; k++){
                    float tem = this->data[i * 2 + k];
                    for(int j = 0; j < 2; j++){
                        matrix_result[i * 2  + j] += (tem * other[k * 2 + j]);
                    }
                }
            }
            //std::cout << "Matriz (" << &matrix_result[0] << "," << &matrix_result << ") " << 4 << "x" << 4 << " calculada correctamente." << std::endl;
            return matrix_result;
        }
        float sumAll(){
            float sum = 0;
            return sum;
        }
    private:
         size_t cols, rows;
         float data[4];

};
