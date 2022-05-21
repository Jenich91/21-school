#include "s21_matrix.h"

matrix_t s21_create_matrix(int rows, int columns) {
    matrix_t newMatrix = { NULL, 0, 0, ZERO_MATRIX };
    if (rows < 1 || columns < 1) {
        newMatrix.matrix_type = INCORRECT_MATRIX;
    } else {
        newMatrix.rows = rows;
        newMatrix.columns = columns;

        newMatrix.matrix = (double **)malloc(rows*sizeof(double *));
        for (int i = 0; i < rows; i++) {
            newMatrix.matrix[i] = (double *)malloc(columns*sizeof(double));
            for (int j = 0; j < columns; j++) {
                newMatrix.matrix[i][j] = 0;
            }
        }

    newMatrix.matrix_type = GetMatrixType(&newMatrix);
    }

    return newMatrix;
}

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix_type != INCORRECT_MATRIX) {
        double **p = A->matrix;
        for (int i = 0; i < A->rows; i++) {
            free(p[i]);
        }
        free(p);
    }
}

int isEquale(double src1, double src2) {
    int result = 0;

    if (fabs(src1-src2) < 1e-7) {
        result = SUCCESS;
    } else {
        result = FAILURE;
    }

    return result;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int result = SUCCESS;

    if (A->matrix_type == INCORRECT_MATRIX || B->matrix_type == INCORRECT_MATRIX) {
        result = FAILURE;
    }
    if (A->columns != B->columns || A->rows != B->rows) {
        result = FAILURE;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (!isEquale(A->matrix[i][j], B->matrix[i][j])) {
                    result = FAILURE;
                    break;
                }
            }
        }
    }

    return result;
}

bool isZeroMatrix(matrix_t *A) {
    bool result = false;
    bool notZeroFlag = false;
    for (int i = 0; i < A->rows && notZeroFlag == false; i++) {
        for (int j = 0; j < A->columns; j++) {
            if (!isEquale(A->matrix[i][j], 0)) {
                notZeroFlag = true;
                break;
            }
        }
    }

    if (!notZeroFlag) {
        result = true;
    }

    return result;
}

bool isIdentityMatrix(matrix_t *A) {
    bool result = false;
    bool wrongValueFlag = false;
    for (int i = 0; i < A->rows && wrongValueFlag == false; i++) {
        for (int j = 0; j < A->columns; j++) {
            if (i != j && !isEquale(A->matrix[i][j], 0)) {
                wrongValueFlag = true;
                break;
            } else if (!isEquale(A->matrix[i][i], 1)) {
                wrongValueFlag = true;
                break;
            }
        }
    }

    if (!wrongValueFlag) {
        result = true;
    }

    return result;
}

matrix_type_t GetMatrixType(matrix_t *A) {
    matrix_type_t result = CORRECT_MATRIX;

    if (isIdentityMatrix(A)) {
        result = IDENTITY_MATRIX;
    } else if (isZeroMatrix(A)) {
        result = ZERO_MATRIX;
    }

    return result;
}

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    matrix_t resultMatrix  = { NULL, 0, 0, ZERO_MATRIX };

    if (A->rows != B->rows || A->columns != B->columns) {
        resultMatrix.matrix_type = INCORRECT_MATRIX;
    } else if (A->matrix_type != INCORRECT_MATRIX && B->matrix_type != INCORRECT_MATRIX) {
        resultMatrix = s21_create_matrix(A->rows, A->columns);

        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                resultMatrix.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }

        resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
    }


    return resultMatrix;
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
    matrix_t resultMatrix  = { NULL, 0, 0, ZERO_MATRIX };

    if (A->rows != B->rows || A->columns != B->columns) {
        resultMatrix.matrix_type = INCORRECT_MATRIX;
    } else if (A->matrix_type != INCORRECT_MATRIX && B->matrix_type != INCORRECT_MATRIX) {
        resultMatrix = s21_create_matrix(A->rows, A->columns);

        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                resultMatrix.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }

        resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
    }

    return resultMatrix;
}

matrix_t s21_mult_number(matrix_t *A, double number) {
    matrix_t resultMatrix = s21_create_matrix(A->rows, A->columns);

    if (A->matrix_type != INCORRECT_MATRIX) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                resultMatrix.matrix[i][j] = A->matrix[i][j] * number;
                if (number == 0 && resultMatrix.matrix[i][j] == -0) {
                    resultMatrix.matrix[i][j] = 0;
                }
            }
        }

        resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
    }

    return resultMatrix;
}

matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
    matrix_t resultMatrix  = { NULL, 0, 0, ZERO_MATRIX };

    if (A->columns != B->rows) {
        resultMatrix.matrix_type = INCORRECT_MATRIX;
    } else if (A->matrix_type != INCORRECT_MATRIX && B->matrix_type != INCORRECT_MATRIX) {
        resultMatrix = s21_create_matrix(A->rows, B->columns);

        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                resultMatrix.matrix[i][j] = 0;
                    for (int k = 0; k < A->columns; k++) {
                        resultMatrix.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                    }
                }
            }

        resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
    }

    return resultMatrix;
}

matrix_t s21_transpose(matrix_t *A) {
    matrix_t resultMatrix  = { NULL, 0, 0, ZERO_MATRIX };

    if (A->matrix_type != INCORRECT_MATRIX && A->columns > 0 && A->rows > 0) {
        resultMatrix = s21_create_matrix(A->columns, A->rows);

        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                resultMatrix.matrix[j][i] = A->matrix[i][j];
            }
        }
        resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
    } else {
        resultMatrix.matrix_type = INCORRECT_MATRIX;
    }

    return resultMatrix;
}

double s21_determinant(matrix_t *A) {
    double determinant = NAN;

    if (A->rows == A->columns && A->matrix_type != INCORRECT_MATRIX) {
        int size = A->columns;
        if (size == 1) {
            determinant = A->matrix[0][0];
        } else if (size == 2) {
            determinant = (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[1][0] * A->matrix[0][1]);
        } else if (size > 2) {
            determinant = 0;
            int sign = 1;

            for (int i = 0; i < size; i++) {
                matrix_t newMatrix = getSubMatrix(A, i, 0);

                determinant = determinant + sign * A->matrix[i][0] * s21_determinant(&newMatrix);
                sign =- sign;
                s21_remove_matrix(&newMatrix);
            }
        }
    }

    return determinant;
}

matrix_t getSubMatrix(matrix_t *src, int rowForDelete, int columnForDelete) {
    matrix_t newMatrix = s21_create_matrix(src->rows-1, src->columns-1);

    int offsetRow = 0;
    for (size_t i = 0; i < src->rows-1; i++) {
        if (i == rowForDelete) {
            offsetRow = 1;
        }
        int offsetCollum = 0;
        for (size_t j = 0; j < src->columns-1; j++)  {
            if (j == columnForDelete) {
                offsetCollum = 1;
            }
            newMatrix.matrix[i][j] = src->matrix[i + offsetRow][j + offsetCollum];
        }
    }

    return newMatrix;
}

matrix_t s21_calc_complements(matrix_t *A) {
    matrix_t resultMatrix  = { NULL, 0, 0, ZERO_MATRIX };

    if ((A->rows == A->columns) && (A->rows > 1) && (A->matrix_type != INCORRECT_MATRIX)) {
        resultMatrix = s21_create_matrix(A->rows, A->columns);
        int size = A->columns;

        for (size_t i = 0; i < size; i++)  {
            for (size_t j = 0; j < size; j++) {
                matrix_t subMatrix = getSubMatrix(A, i, j);
                resultMatrix.matrix[i][j] = pow(-1, ((j+1)+(i+1))) * s21_determinant(&subMatrix);
                s21_remove_matrix(&subMatrix);
            }
        }
        resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
    } else {
        resultMatrix.matrix_type = INCORRECT_MATRIX;
    }

    return resultMatrix;
}

matrix_t s21_inverse_matrix(matrix_t *A) {
    matrix_t resultMatrix  = { NULL, 0, 0, ZERO_MATRIX };

    if (A->rows == 1 && A->columns == 1) {
        if (isEquale(A->matrix[0][0], 0)) {
            resultMatrix.matrix_type = INCORRECT_MATRIX;
        } else {
            resultMatrix = s21_create_matrix(1, 1);
            resultMatrix.matrix[0][0] = 1/A->matrix[0][0];
            resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
        }
    } else if (A->matrix_type != INCORRECT_MATRIX) {
        double det = s21_determinant(A);

        if (isEquale(det, 0) || isnan(det)) {
            resultMatrix.matrix_type = INCORRECT_MATRIX;
        } else {
            matrix_t C = s21_calc_complements(A);
            matrix_t T = s21_transpose(&C);
            resultMatrix = s21_mult_number(&T, 1/det);

            resultMatrix.matrix_type = GetMatrixType(&resultMatrix);
            s21_remove_matrix(&C);
            s21_remove_matrix(&T);
        }
    } else {
        resultMatrix.matrix_type = INCORRECT_MATRIX;
    }

    return resultMatrix;
}
