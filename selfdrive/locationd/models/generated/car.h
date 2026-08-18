#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3441370810429516799);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1747596067924150076);
void car_H_mod_fun(double *state, double *out_5211544030531521198);
void car_f_fun(double *state, double dt, double *out_3273966994803944680);
void car_F_fun(double *state, double dt, double *out_3584498956988590310);
void car_h_25(double *state, double *unused, double *out_1500665077942884314);
void car_H_25(double *state, double *unused, double *out_8734592669176886346);
void car_h_24(double *state, double *unused, double *out_8867867868219610133);
void car_H_24(double *state, double *unused, double *out_5176667070374563210);
void car_h_30(double *state, double *unused, double *out_6184127634480483313);
void car_H_30(double *state, double *unused, double *out_1817902327685269591);
void car_h_26(double *state, double *unused, double *out_3579722313671785662);
void car_H_26(double *state, double *unused, double *out_5970648085658609046);
void car_h_27(double *state, double *unused, double *out_4755159644016162940);
void car_H_27(double *state, double *unused, double *out_3992665639485694502);
void car_h_29(double *state, double *unused, double *out_5051706952974846792);
void car_H_29(double *state, double *unused, double *out_1307670983370877407);
void car_h_28(double *state, double *unused, double *out_2479630826403110806);
void car_H_28(double *state, double *unused, double *out_6390070000440407981);
void car_h_31(double *state, double *unused, double *out_2361018398485617338);
void car_H_31(double *state, double *unused, double *out_8703946707299925918);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}