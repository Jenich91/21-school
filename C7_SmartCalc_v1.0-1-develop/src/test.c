#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "s21_smartCalc.h"

START_TEST(test_plus) {
    char* inputStr = "12+5";
    double result = 12+5;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "12+0.0";
    result = 12+0.0;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "-12+2.34";
    result = -12+2.34;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "100+-234.";
    result = 100+-234.;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "9+(8+6)+1+(3+9)";
    result = 9+(8+6)+1+(3+9);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "21892683+(+60607476)";
    result = 21892683+(+60607476);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "794+(101+110)+387";
    result = 794+(101+110)+387;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);
}
END_TEST

START_TEST(test_minus) {
    char* inputStr = "416-434-(190-490)";
    double result = 416-434-(190-490);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "107-(928-166-438)";
    result = 107-(928-166-438);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(399-985)-63-352";
    result = (399-985)-63-352;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "107-(928-166-438)";
    result = 107-(928-166-438);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "107-(928-166-438)";
    result = 107-(928-166-438);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(399-985)-63-352";
    result = (399-985)-63-352;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "317-141-(118-695)";
    result = 317-141-(118-695);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(3879294-5309583)-(3744311-2467480-4787696)-3324295";
    result = (3879294-5309583)-(3744311-2467480-4787696)-3324295;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);
}
END_TEST

START_TEST(test_mult) {
    char* inputStr = "65991.*(.5312*5213.)*-(.9450*897643.)";
    double result = 65991.*(.5312*5213.)*-(.9450*897643.);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(-.38227*7856.815-0.)*(7759.3*-51507.96)";
    result = (-.38227*7856.815-0.)*(7759.3*-51507.96);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "6916.08*-(5855.31*75.6934)*-(-3272.10*4382.36)";
    result = 6916.08*-(5855.31*75.6934)*-(-3272.10*4382.36);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(-816.484*5.2422)*5106.881*(4849.3*401.9244)";
    result = (-816.484*5.2422)*5106.881*(4849.3*401.9244);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(91.226*-51.9)*(7.797*85.481)";
    result = (91.226*-51.9)*(7.797*85.481);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "-25.9655*-(-626.93*508.657)*(85.108*400.162)";
    result = -25.9655*-(-626.93*508.657)*(85.108*400.162);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "-(-356.081*4598.63)*803.928*(70.592*.1569)*-36.1566";
    result = -(-356.081*4598.63)*803.928*(70.592*.1569)*-36.1566;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);
}
END_TEST

START_TEST(test_div) {
    char* inputStr = "(432/9.57/321)/(76.4/78.0)/-35.8";
    double result = (432/9.57/321)/(76.4/78.0)/-35.8;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "43.1/(495.5/711.)/28.7";
    result = 43.1/(495.5/711.)/28.7;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(.5757/23.3/704.1/-31.27)";
    result = (.5757/23.3/704.1/-31.27);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(2451.0/43.94/-1.759)/62.72";
    result = (2451.0/43.94/-1.759)/62.72;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(1.375/930.0)/223.3/80.41";
    result = (1.375/930.0)/223.3/80.41;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "4.091/(23.04/1.075/42.8)";
    result = 4.091/(23.04/1.075/42.8);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(7068./33.59/9.13-4)/43.5";
    result = (7068./33.59/9.13-4)/43.5;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "97.66/(705.2/2619.)/59.59";
    result = 97.66/(705.2/2619.)/59.59;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);
}
END_TEST

START_TEST(test_pow) {
    char* inputStr = "8^(3^4)";
    double result = pow(8, pow(3, 4));
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(2^9)^1";
    result = pow(pow(2, 9), 1);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "2^2^3";
    result = (pow(2, pow(2, 3)));
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "5^(3^3)";
    result = (pow(5, pow(3, 3)));
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(4^10)^3";
    result = pow(pow(4, 10), 3);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(8^2)^8";
    result = pow(pow(8, 2), 8);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(4^10)^3";
    result = pow(pow(4, 10), 3);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);
}
END_TEST

START_TEST(test_mod) {
    char* inputStr = "(45.34mod55.23)mod79.4";
    double result = fmod(fmod(45.34, 55.23), 79.4);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "357.34mod(952.34mod712.12)";
    result = fmod(357.34, fmod(952.34, 712.12));
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "15.234mod(0.52mod0.034)";
    result = fmod(15.234, fmod(0.52, 0.034));
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "499.23mod(1.8mod0.27)";
    result = fmod(499.23, fmod(1.8, 0.27));
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);
}
END_TEST

START_TEST(test_mix) {
    char* inputStr = "(72*533+u615)";
    double result = (72*533+-615);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "826-(738-+243)";
    result = 826-(738-+243);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "17mod863*-173";
    result = fmod(17, 863)*-173;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "40.34*(-0.424/-252)";
    result = 40.34*(-0.424/-252);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "(944mod918)/227";
    result = (fmod(944, 918))/227;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);
}
END_TEST

START_TEST(test_func) {
    char* inputStr = "acos(0.1)*sin(1)";
    double result = acos(0.1)*sin(1);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "cos(-1.34)+tan(+2.0)";
    result = cos(-1.34)+tan(+2);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "-(asin(+0.3465346)/2)";
    result = -(asin(+0.3465346)/2);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "+atan(1.302+0.5)-1.2";
    result = +atan(1.302+0.5)-1.2;
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "123modsqrt(100)";
    result = fmod(123, sqrt(100));
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "ln(256-3)";
    result = log(256-3);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    inputStr = "log(+123.345)";
    result = log10(+123.345);
    ck_assert_double_eq_tol(result, GetResult(inputStr, 0), 1e-6);

    double x = 5.5;
    inputStr = "log(x)";
    result = log10(x);
    ck_assert_double_eq_tol(result, GetResult(inputStr, x), 1e-6);
}
END_TEST

START_TEST(test_etc) {
    char* inputStr = "34.4+34/3";
    bool result = IsNormalInputString(inputStr);
    ck_assert_int_eq(true, result);

    inputStr = "34..4+5";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "34./.4+5";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "--34+5";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "*34+5";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "34*-5";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(true, result);

    inputStr = "34-*5";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "-(2*2)";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(true, result);

    inputStr = "-sin(1)";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(true, result);

    inputStr = "sin 1";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "mod";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "2mod";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "10*mod3";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "2mod/3";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "2mod(3)";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "sims(3)+cs(1.6)";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = ")2+2";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "2+3/sin()";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "2(+)3";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);

    inputStr = "2+(*3)";
    result = IsNormalInputString(inputStr);
    ck_assert_int_eq(false, result);
}
END_TEST


START_TEST(test_credit) {
    double result = CreditCalc(100000, 12, 15, 1);
    ck_assert_double_eq_tol(9025.83, result, 1e-2);

    result = CreditCalc(100000, 12, 15, 2);
    ck_assert_double_eq_tol(9583.33, result, 1e-2);

    result = CreditCalc(300000, 42, 5, 1);
    ck_assert_double_eq_tol(7800.91, result, 1e-2);

    result = CreditCalc(300000, 42, 5, 2);
    ck_assert_double_eq_tol(8392.86, result, 1e-2);

    result = CreditCalc(1, 1, 1, 1);
    ck_assert_double_eq_tol(1.00, result, 1e-2);

    result = CreditCalc(10000000000, 600, 999.99, 1);
    ck_assert_double_eq_tol(8.33325e+09, result, 1e-2);
}
END_TEST

Suite *s21_suite(void) {
    Suite *suite = suite_create("SmartCalc");
    TCase *tcase_core = tcase_create("Tests");

    tcase_add_test(tcase_core, test_plus);
    tcase_add_test(tcase_core, test_minus);
    tcase_add_test(tcase_core, test_mult);
    tcase_add_test(tcase_core, test_div);
    tcase_add_test(tcase_core, test_pow);
    tcase_add_test(tcase_core, test_mod);
    tcase_add_test(tcase_core, test_mix);
    tcase_add_test(tcase_core, test_func);
    tcase_add_test(tcase_core, test_etc);
    tcase_add_test(tcase_core, test_credit);

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
