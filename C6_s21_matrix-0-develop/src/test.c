#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"
void generate_matrix(matrix_t *A, double start, double step) {
    double value = start;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            A->matrix[i][j] = value;
            value = value + step;
        }
    }
    A->matrix_type = CORRECT_MATRIX;
    if (start == 0. && step == 0.) {
    A->matrix_type = ZERO_MATRIX;
    }
    if (start == 1. && step == 0. && A->columns == 1 && A->rows == 1) {
        A->matrix_type = IDENTITY_MATRIX;
    }
}

void fill_matrix_from_arr(matrix_t *dst, int columns, double src[][columns]) {
    for (int i = 0; i < dst->rows; i++) {
        for (int j = 0; j < dst->columns; j++) {
            dst->matrix[i][j] = src[i][j];
        }
    }

    dst->matrix_type = GetMatrixType(dst);
}

START_TEST(test_create_and_remove_matrix) {
    int rows = 5;
    int columns = 5;
    matrix_t A = s21_create_matrix(rows, columns);
    ck_assert_int_eq(A.rows, rows);
    ck_assert_int_eq(A.columns, columns);
    ck_assert_int_eq(A.matrix_type, ZERO_MATRIX);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
        ck_assert_double_eq(A.matrix[i][j], 0);
        }
    }
    s21_remove_matrix(&A);

    rows = 1;
    columns = 1;
    A = s21_create_matrix(rows, columns);
    A.matrix[0][0] = 5;
    A.matrix_type = GetMatrixType(&A);
    ck_assert_int_eq(A.rows, rows);
    ck_assert_int_eq(A.columns, columns);
    ck_assert_int_eq(A.matrix_type, CORRECT_MATRIX);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
        ck_assert_double_eq(A.matrix[i][j], 5);
        }
    }
    s21_remove_matrix(&A);

    rows = 1;
    columns = 1;
    A = s21_create_matrix(rows, columns);
    A.matrix[0][0] = 1;
    A.matrix_type = GetMatrixType(&A);
    ck_assert_int_eq(A.rows, rows);
    ck_assert_int_eq(A.columns, columns);
    ck_assert_int_eq(A.matrix_type, IDENTITY_MATRIX);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
        ck_assert_double_eq(A.matrix[i][j], 1);
        }
    }
    s21_remove_matrix(&A);

    rows = 0;
    columns = 0;
    A = s21_create_matrix(rows, columns);
    ck_assert_int_eq(A.rows, rows);
    ck_assert_int_eq(A.columns, columns);
    ck_assert_int_eq(A.matrix_type, INCORRECT_MATRIX);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
        ck_assert_double_eq(A.matrix[i][j], 0);
        }
    }
    s21_remove_matrix(&A);

    rows = -0;
    columns = -1;
    A = s21_create_matrix(rows, columns);
    ck_assert_int_eq(A.matrix_type, INCORRECT_MATRIX);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_eq_matrix) {
    double arr1[3][3] = {
                        {1, 0, -3},
                        {0, 1, 2},
                        {0, 1, 5}
                        };

    double arr2[3][3] = {
                        {1, 0, -3},
                        {0, 1, 2},
                        {0, 1, 5}
                        };


    matrix_t testMatrix1 = s21_create_matrix(3, 3);
    fill_matrix_from_arr(&testMatrix1, 3, arr1);
    matrix_t testMatrix2 = s21_create_matrix(3, 3);
    fill_matrix_from_arr(&testMatrix2, 3, arr2);
    ck_assert_int_eq(s21_eq_matrix(&testMatrix1, &testMatrix2), SUCCESS);
    s21_remove_matrix(&testMatrix1);
    s21_remove_matrix(&testMatrix2);

    double arr3[2][3] = {
                        {1, 0, -3},
                        {0, 1, 2}
                        };

    double arr4[2][4] = {
                        {1, 0, -3, 5},
                        {0, 1, 2, 4}
                        };


    matrix_t testMatrix3 = s21_create_matrix(2, 3);
    fill_matrix_from_arr(&testMatrix3, 3, arr3);
    matrix_t testMatrix4 = s21_create_matrix(2, 4);
    fill_matrix_from_arr(&testMatrix4, 4, arr4);
    ck_assert_int_eq(s21_eq_matrix(&testMatrix3, &testMatrix4), FAILURE);
    s21_remove_matrix(&testMatrix3);
    s21_remove_matrix(&testMatrix4);

        double arr5[2][3] = {
                        {1, 0, -3},
                        {0, 1, 2}
                        };

    double arr6[2][3] = {
                        {1, 0, -3},
                        {0, 666, 2}
                        };

    matrix_t testMatrix5 = s21_create_matrix(2, 3);
    fill_matrix_from_arr(&testMatrix5, 3, arr5);
    matrix_t testMatrix6 = s21_create_matrix(2, 3);
    fill_matrix_from_arr(&testMatrix6, 3, arr6);
    ck_assert_int_eq(s21_eq_matrix(&testMatrix5, &testMatrix6), FAILURE);
    s21_remove_matrix(&testMatrix5);
    s21_remove_matrix(&testMatrix6);

        double arr7[2][3] = {
                        {1, 0, -3},
                        {0, 1, 2}
                        };

    matrix_t testMatrix7 = s21_create_matrix(2, 3);
    fill_matrix_from_arr(&testMatrix7, 3, arr7);
    matrix_t testMatrix8 = s21_create_matrix(2, -3);
    ck_assert_int_eq(s21_eq_matrix(&testMatrix7, &testMatrix8), FAILURE);
    s21_remove_matrix(&testMatrix7);
    s21_remove_matrix(&testMatrix8);
}
END_TEST

START_TEST(test_sum_matrix) {
    int rows = 2;
    int columns = 2;
    double a = 999999.999999;
    double b = -1.999998;
    double c = 999998.000001;
    int type = CORRECT_MATRIX;
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);
    matrix_t C = s21_create_matrix(rows, columns);

    generate_matrix(&A, a, 0);
    generate_matrix(&B, b, 0);
    generate_matrix(&C, c, 0);

    matrix_t C_test = s21_sum_matrix(&A, &B);
    ck_assert_int_eq(s21_eq_matrix(&C, &C_test), SUCCESS);
    ck_assert_int_eq(C_test.matrix_type, type);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&C_test);
}
END_TEST

START_TEST(test_sub_matrix) {
    int rows = 100;
    int columns = 300;
    double a = 1;
    double b = 0.999999;
    double c = 0.000001;
    int type = CORRECT_MATRIX;
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);
    matrix_t C = s21_create_matrix(rows, columns);

    generate_matrix(&A, a, 0);
    generate_matrix(&B, b, 0);
    generate_matrix(&C, c, 0);

    matrix_t C_test = s21_sub_matrix(&A, &B);
    ck_assert_int_eq(s21_eq_matrix(&C, &C_test), SUCCESS);
    ck_assert_int_eq(C_test.matrix_type, type);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&C_test);
}
END_TEST

START_TEST(test_mult_number) {
    int rows = 2000;
    int columns = 20;
    double a = 1;
    double b = 500;
    int type = CORRECT_MATRIX;
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(rows, columns);

    generate_matrix(&A, a, 0);
    generate_matrix(&B, a * b, 0);

    matrix_t B_test = s21_mult_number(&A, b);
    ck_assert_int_eq(s21_eq_matrix(&B, &B_test), SUCCESS);
    ck_assert_int_eq(B_test.matrix_type, type);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&B_test);
}
END_TEST

START_TEST(test_mult_matrix) {
    int rows = 100;
    int columns = 200;
    matrix_t A = s21_create_matrix(rows, columns);
    matrix_t B = s21_create_matrix(columns, rows);
    matrix_t C = s21_create_matrix(rows, rows);

    generate_matrix(&A, 1, 0);
    generate_matrix(&B, 1, 0);
    generate_matrix(&C, A.columns, 0);

    matrix_t C_test = s21_mult_matrix(&A, &B);
    ck_assert_int_eq(C.rows, A.rows);
    ck_assert_int_eq(C.columns, B.columns);
    ck_assert_int_eq(s21_eq_matrix(&C, &C_test), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&C_test);
}
END_TEST

START_TEST(test_transpose) {
    int rows = 1000;
    int columns = 2000;
    double a = 1111111;
    double b = 000001;
    matrix_t A = s21_create_matrix(rows, columns);
    generate_matrix(&A, a, b);

    matrix_t B = s21_transpose(&A);
    matrix_t C = s21_transpose(&B);

    ck_assert_int_eq(s21_eq_matrix(&A, &C), SUCCESS);
    ck_assert_int_eq(A.matrix_type, C.matrix_type);
    ck_assert_int_eq(A.rows, B.columns);
    ck_assert_int_eq(A.columns, B.rows);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_determinant) {
    int rows = 2;
    int value = 100.;
    double result = 20000.;
    matrix_t A = s21_create_matrix(rows, rows);
    double eps = 1e-7;
    for (int i = 0; i < A.rows; i++) {
    A.matrix[i][i] = value;
    }
    ck_assert_double_le(s21_determinant(&A) - result, eps);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_and_inverse_matrix) {
    int rows = 4;
    double start = 5;
    double step = 0.1;
    matrix_t A = s21_create_matrix(rows, rows);
    generate_matrix(&A, start, step);
    A.matrix[0][0] = 0;
    A.matrix[rows - 1][rows - 1] = A.matrix[rows - 1][rows - 1] * 10;
    matrix_t I = s21_inverse_matrix(&A);
    matrix_t M = s21_mult_matrix(&A, &I);
    ck_assert_int_eq(M.matrix_type, IDENTITY_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&I);
    s21_remove_matrix(&M);

    matrix_t B = s21_create_matrix(1, 1);
    B.matrix[0][0] = 0;
    I = s21_inverse_matrix(&B);
    ck_assert_int_eq(I.matrix_type, INCORRECT_MATRIX);
    s21_remove_matrix(&B);
    s21_remove_matrix(&I);

    B = s21_create_matrix(1, 1);
    B.matrix[0][0] = 5;
    I = s21_inverse_matrix(&B);
    M = s21_mult_matrix(&B, &I);
    ck_assert_int_eq(M.matrix_type, IDENTITY_MATRIX);
    s21_remove_matrix(&B);
    s21_remove_matrix(&I);
    s21_remove_matrix(&M);
}
END_TEST

Suite *s21_suite(void) {
    Suite *suite = suite_create("Matrix");
    TCase *tcase_core = tcase_create("Equelity");

    tcase_add_test(tcase_core, test_create_and_remove_matrix);
    tcase_add_test(tcase_core, test_eq_matrix);
    tcase_add_test(tcase_core, test_sum_matrix);
    tcase_add_test(tcase_core, test_sub_matrix);
    tcase_add_test(tcase_core, test_mult_number);
    tcase_add_test(tcase_core, test_mult_matrix);
    tcase_add_test(tcase_core, test_transpose);
    tcase_add_test(tcase_core, test_determinant);
    tcase_add_test(tcase_core, test_calc_complements_and_inverse_matrix);
    suite_add_tcase(suite, tcase_core);
    return suite;
}

int main(void) {
    Suite *suite = s21_suite();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
