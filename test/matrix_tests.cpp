#include "gtest/gtest.h"
#include "../src/structs/rt_tuples.hpp"
#include "../src/structs/rt_matrix.hpp"

TEST(matrixTests, constructing_4x4_matrix) {
    double ref[4][4] = {{1, 2, 3, 4},
        {5.5, 6.5, 7.5, 8.5},
        {9, 10, 11, 12},
        {13.5, 14.5, 15.5, 16.5}};
    rt_matrix_4 x = rt_matrix_4(ref);
    EXPECT_TRUE(equal(x.mat[0][0], 1));
    EXPECT_TRUE(equal(x.mat[0][3], 4));
    EXPECT_TRUE(equal(x.mat[1][0], 5.5));
    EXPECT_TRUE(equal(x.mat[1][2], 7.5));
    EXPECT_TRUE(equal(x.mat[2][2], 11));
    EXPECT_TRUE(equal(x.mat[3][0], 13.5));
    EXPECT_TRUE(equal(x.mat[3][2], 15.5));
}

TEST(matrixTests, constructing_2x2_matrix) {
    double ref[2][2] = {{-3, 5},
        {1, -2}};
    rt_matrix_2 x = rt_matrix_2(ref);
    EXPECT_TRUE(equal(x.mat[0][0], -3));
    EXPECT_TRUE(equal(x.mat[0][1], 5));
    EXPECT_TRUE(equal(x.mat[1][0], 1));
    EXPECT_TRUE(equal(x.mat[1][1], -2));
}

TEST(matrixTests, constructing_3x3_matrix) {
    double ref[3][3] = {{-3, 5, 0},
        {1, -2, -7},
        {0, 1, 1}};
    rt_matrix_3 x = rt_matrix_3(ref);
    EXPECT_TRUE(equal(x.mat[0][0], -3));
    EXPECT_TRUE(equal(x.mat[1][1], -2));
    EXPECT_TRUE(equal(x.mat[2][2], 1));
}

TEST(matrixTests, check_4x4_matrix_equality) {
    double ref_1[4][4] = {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};
    double ref_2[4][4] = {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};
    rt_matrix_4 a = rt_matrix_4(ref_1);
    rt_matrix_4 b = rt_matrix_4(ref_2);
    EXPECT_TRUE(a==b);
}

TEST(matrixTests, check_4x4_matrix_inequality) {
    double ref_1[4][4] = {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};
    double ref_2[4][4] = {{2, 3, 4, 5},
        {6, 7, 8, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}};
    rt_matrix_4 a = rt_matrix_4(ref_1);
    rt_matrix_4 b = rt_matrix_4(ref_2);
    EXPECT_TRUE(a!=b);
}

TEST(matrixTests, multiplying_4x4_matrices) {
    double in_1[4][4] = {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 8, 7, 6},
        {5, 4, 3, 2}};
    double in_2[4][4] = {{-2, 1, 2, 3},
        {3, 2, 1, -1},
        {4, 3, 6, 5},
        {1, 2, 7, 8}};
    double ref[4][4] = {{20, 22, 50, 48},
        {44, 54, 114, 108},
        {40, 58, 110, 102},
        {16, 26, 46, 42}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    rt_matrix_4 b = rt_matrix_4(in_2);
    rt_matrix_4 c = rt_matrix_4(ref);
    EXPECT_EQ(a*b, c);
}

TEST(matrixTests, multiplying_4x4_matrix_tuple) {
    double in_1[4][4] = {{1, 2, 3, 4},
        {2, 4, 4, 2},
        {8, 6, 4, 1},
        {0, 0, 0, 1}};
    rt_tuple b = rt_tuple(1, 2, 3, 1);
    rt_tuple ref = rt_tuple(18, 24, 33, 1);
    
    rt_matrix_4 a = rt_matrix_4(in_1);
    EXPECT_EQ(a*b, ref);
}

TEST(matrixTests, multiplying_4x4_matrix_by_identity_matrix) {
    double in_1[4][4] = {{1, 2, 3, 4},
        {2, 4, 4, 2},
        {8, 6, 4, 1},
        {0, 0, 0, 1}};
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    
    rt_matrix_4 a = rt_matrix_4(in_1);
    EXPECT_EQ(a*id, a);
}

TEST(matrixTests, multiplying_4x4_identity_matrix_tuple) {
    rt_tuple a = rt_tuple(1, 2, 3, 4);
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    
    EXPECT_EQ(id*a, a);
}

TEST(matrixTests, transposing_4x4_matrix) {
    double in_1[4][4] = {{0, 9, 3, 0},
        {9, 8, 0, 8},
        {1, 8, 5, 3},
        {0, 0, 5, 8}};
    double in_2[4][4] = {{0, 9, 1, 0},
        {9, 8, 8, 0},
        {3, 0, 5, 5},
        {0, 8, 3, 8}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    rt_matrix_4 ref = rt_matrix_4(in_2);
    EXPECT_EQ(rt_matrix_4::transpose(a), ref);
}

TEST(matrixTests, transposing_4x4_identity_matrix) {
    rt_matrix_4 id = rt_matrix_4::id_matrix();
    
    EXPECT_EQ(rt_matrix_4::transpose(id), id);
}

TEST(matrixTests, determinant_2x2_matrix) {
    double in_1[2][2] = {{1, 5}, {-3, 2}};
    rt_matrix_2 a = rt_matrix_2(in_1);
    
    EXPECT_EQ(rt_matrix_2::determinant(a), 17);
}

TEST(matrixTests, submatrix_of_3x3_is_2x2_matrix) {
    double in_1[3][3] = {{1, 5, 0},
        {-3, 2, 7},
        {0, 6, -3}};
    double in_2[2][2] = {{-3, 2}, {0, 6}};
    rt_matrix_3 a = rt_matrix_3(in_1);
    rt_matrix_2 ref = rt_matrix_2(in_2);
    
    EXPECT_EQ(rt_matrix_3::submatrix(a, 0, 2), ref);
}

TEST(matrixTests, submatrix_of_4x4_is_3x3_matrix) {
    double in_1[4][4] = {{-6, 1, 1, 6},
        {-8, 5, 8, 6},
        {-1, 0, 8, 2},
        {-7, 1, -1, 1}};
    double in_2[3][3] = {{-6, 1, 6},
        {-8, 8, 6},
        {-7, -1, 1}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    rt_matrix_3 ref = rt_matrix_3(in_2);
    
    EXPECT_EQ(rt_matrix_4::submatrix(a, 2, 1), ref);
}

TEST(matrixTests, minor_3x3_matrix) {
    double in_1[3][3] = {{3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}};
    rt_matrix_3 a = rt_matrix_3(in_1);
    rt_matrix_2 b = rt_matrix_3::submatrix(a, 1, 0);
    
    EXPECT_EQ(rt_matrix_2::determinant(b), 25);
    EXPECT_EQ(rt_matrix_3::minor(a, 1, 0), 25);
}

TEST(matrixTests, cofactor_3x3_matrix) {
    double in_1[3][3] = {{3, 5, 0},
        {2, -1, -7},
        {6, -1, 5}};
    rt_matrix_3 a = rt_matrix_3(in_1);
    
    EXPECT_EQ(rt_matrix_3::minor(a, 0, 0), -12);
    EXPECT_EQ(rt_matrix_3::cofactor(a, 0, 0), -12);
    EXPECT_EQ(rt_matrix_3::minor(a, 1, 0), 25);
    EXPECT_EQ(rt_matrix_3::cofactor(a, 1, 0), -25);
}

TEST(matrixTests, determinant_3x3_matrix) {
    double in_1[3][3] = {{1, 2, 6},
        {-5, 8, -4},
        {2, 6, 4}};
    rt_matrix_3 a = rt_matrix_3(in_1);
    
    EXPECT_EQ(rt_matrix_3::minor(a, 0, 0), 56);
    EXPECT_EQ(rt_matrix_3::cofactor(a, 0, 1), 12);
    EXPECT_EQ(rt_matrix_3::minor(a, 0, 2), -46);
    EXPECT_EQ(rt_matrix_3::determinant(a), -196);
}

TEST(matrixTests, determinant_4x4_matrix) {
    double in_1[4][4] = {{-2, -8, 3, 5},
        {-3, 1, 7, 3},
        {1, 2, -9, 6},
        {-6, 7, 7, -9}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    
    EXPECT_EQ(rt_matrix_4::cofactor(a, 0, 0), 690);
    EXPECT_EQ(rt_matrix_4::cofactor(a, 0, 1), 447);
    EXPECT_EQ(rt_matrix_4::cofactor(a, 0, 2), 210);
    EXPECT_EQ(rt_matrix_4::cofactor(a, 0, 3), 51);
    EXPECT_EQ(rt_matrix_4::determinant(a), -4071);
}

TEST(matrixTests, check_invertibility_of_invertible_4x4_matrix) {
    double in_1[4][4] = {{6, 4, 4, 4},
        {5, 5, 7, 6},
        {4, -9, 3, -7},
        {9, 1, 7, -6}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    
    EXPECT_EQ(rt_matrix_4::determinant(a), -2120);
    EXPECT_TRUE(rt_matrix_4::is_invertible(a));
}

TEST(matrixTests, check_invertibility_of_noninvertible_4x4_matrix) {
    double in_1[4][4] = {{-4, 2, -2, -3},
        {9, 6, 2, 6},
        {0, -5, 1, -5},
        {0, 0, 0, 0}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    
    EXPECT_EQ(rt_matrix_4::determinant(a), 0);
    EXPECT_FALSE(rt_matrix_4::is_invertible(a));
}

TEST(matrixTests, invert_4x4_matrix_1) {
    double in_1[4][4] = {{-5, 2, 6, -8},
        {1, -5, 1, 8},
        {7, 7, -6, -7},
        {1, -3, 7, 4}};
    double in_2[4][4] = {{0.21805, 0.45113, 0.24060, -0.04511},
        {-0.80827, -1.45677, -0.44361, 0.52068},
        {-0.07895, -0.22368, -0.05263, 0.19737},
        {-0.52256, -0.81391, -0.30075, 0.30639}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    rt_matrix_4 b = rt_matrix_4::inverse(a);
    rt_matrix_4 ref = rt_matrix_4(in_2);
    
    EXPECT_EQ(rt_matrix_4::determinant(a), 532);
    EXPECT_EQ(rt_matrix_4::cofactor(a, 2, 3), -160);
    EXPECT_TRUE(equal(b.mat[3][2], (double)-160/532));

    EXPECT_EQ(rt_matrix_4::cofactor(a, 3, 2), 105);
    EXPECT_TRUE(equal(b.mat[2][3], (double)105/532));
    EXPECT_EQ(b, ref);
}

TEST(matrixTests, invert_4x4_matrix_2) {
    double in_1[4][4] = {{8, -5, 9, 2},
        {7, 5, 6, 1},
        {-6, 0, 9, 6},
        {-3, 0, -9, -4}};
    double in_2[4][4] = {{-0.15385, -0.15385, -0.28205, -0.53846},
        {-0.07692, 0.12308, 0.02564, 0.03077},
        {0.35897, 0.35897, 0.43590, 0.92308},
        {-0.69231, -0.69231, -0.76923, -1.92308}};
    rt_matrix_4 a = rt_matrix_4(in_1);
    rt_matrix_4 b = rt_matrix_4::inverse(a);
    rt_matrix_4 ref = rt_matrix_4(in_2);
    
    EXPECT_EQ(b, ref);
}

TEST(matrixTests, invert_4x4_matrix_3) {
    double in_1[4][4] = {{9, 3, 0, 9},
    {-5, -2, -6, -3},
    {-4, 9, 6, 4},
    {-7, 6, 6, 2}};
    double in_2[4][4] = {{-0.04074, -0.07778, 0.14444, -0.22222},
    {-0.07778, 0.03333, 0.36667, -0.33333},
    {-0.02901, -0.14630, -0.10926, 0.12963},
    {0.17778, 0.06667, -0.26667, 0.33333}};

    rt_matrix_4 a = rt_matrix_4(in_1);
    rt_matrix_4 b = rt_matrix_4::inverse(a);
    rt_matrix_4 ref = rt_matrix_4(in_2);
    
    EXPECT_EQ(b, ref);
}

TEST(matrixTests, multiplying_4x4_product_by_inverse) {
    double in_1[4][4] = {{3, -9, 7, 3},
        {3, -8, 2, -9},
        {-4, 4, 4, 1},
        {-6, 5, -1, 1}};
    double in_2[4][4] = {{8, 2, 2, 2},
        {3, -1, 7, 0},
        {7, 0, 5, 4},
        {6, -2, 0, 5}};

    rt_matrix_4 a = rt_matrix_4(in_1);
    rt_matrix_4 b = rt_matrix_4(in_2);
    rt_matrix_4 c = a*b;

    EXPECT_EQ(c*rt_matrix_4::inverse(b), a);
}
