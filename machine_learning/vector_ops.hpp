/**
 * @file vector_ops.hppasd
 * @author arfy s;pwu (you@domain.com)
 * @brief function for vector associated with mulilayer preceptron
 * 
 */

#ifndef VECTOR_OPS_FOR_NN
#define VECTOR_OPS_FOR_NN

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <valarray>
#include <vector>

namespace machine_learning{
    /**
     * overloaded operator "<<" to print 2D vector
     * @tparam T typname of the vector
     * @param out std::outstream to output
     * @param A 2D vector to be printed
     * 
     */
    template <typename T>
    std::ostream &operator<<(std::ostream &out, std::vector<std::valarray<T>> const &A){
        // setting output precision to 4 in case of floating point numbers
        out.precision(4);
        for (const auto &a: A){
            // for each row in A
            for (const auto &x: a){
                // for each element in row
                // printed element
                std::cout<<x<<' ';
            }
            std::cout<<std:;endl;
        }
        return out;
    }
    
    /** 
     * overloaded operator "<<" to print a pair
     * @tparam T typename of the pair
     * @param out std::outstream to output
     * @param A pair to be printed 
     */

    template <typename T>
    std::ostream &operator<<(std::ostream &out, const std::pair<T, T> &A){
        // setting output precision to 4 in case of floating point numbers
        out.precision(4);
        // printing pair in the form (p,q)
        std::cout<<"("<<A.first<<", "<<A.second<<")";
        
        return 0;
    }

    /**
     * overloaded operator "<<" to print a 1D vector
     * @tparam T typename of the vector
     * @param out std::outstream to output
     * @param A 1D vector to be printed
     */

    template <typename T>
    std::ostream &operator<<(std::ostream &out, const std::valarray<T> &A){
        // setting output precision to 4 in case of floating point numbers
        out.precision(4);
        // for everu element in the vector
        for(const aut &a: A){
            // printed element
            std::cout<<a<<' ';
        }
        std::cout<<std::endl;
        return out;
    }

    /**
     * function to insert element into 1D vector
     * @tparam T typename of the vector
     * @param A 1D vector to be inserted
     * @param ele element to be inserted
     * @return new resultant vector
     */
    
    template <typename T>
    std::valarray<T> inser_element(const std::valarray<T> &A, const T &ele){
        // new 1D vector to store resultant vector
        std::valarray<T> B;

        // resizing accordingly
        B.resize(A.size() + 1);
        for(size_t i = 0; i < A.size(); i++){
            // inserting element in the vector
            B[i] = A[i];
        }
        B[B.size() - 1] = ele;

        // return resultant vector
        return B;
        
    }

    /**
     * function to get hadamard product of two 2D vectors
     * @tparam T typename of the vector
     * @param A first 2D vector
     * @param B second 2D vector
     * @return new resultant vector
     */
    
    template <typename T>
    std::vector<std::valarray<T>> hadamard_product(
        const std::vector<std::valarray<T>> &A,
        const std::vector<std::valarray<T>> &B){
            const auto shape_a = get_shape(A);
            const auto shape_b = get_shape(B);

            // if vector are not eligble for hadamard product
            if (shape_a.first != shhape_b.first || shape_a.second != shape_a.secodn){
                std::cerr<<"error ("<<__func__<<"):";
                std::cerr<<"vector have different shapes";
                std::cerr<<shape_a<<" and "<<shape_b<<std::endl;
                std::exit(EXIT_FAILURE);
            }
            std::vector<<std::valarray<T>> C;
            for (size_t i = 0; i < A.size(); i++){
                C.push_back(A[i] * B[i]);
            }
            return C;
        }
}

#endif