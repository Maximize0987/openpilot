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
void car_err_fun(double *nom_x, double *delta_x, double *out_5769240825907262247);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2180470504006262414);
void car_H_mod_fun(double *state, double *out_199921167776384783);
void car_f_fun(double *state, double dt, double *out_1042331506821406330);
void car_F_fun(double *state, double dt, double *out_8550568359085178836);
void car_h_25(double *state, double *unused, double *out_5837605696441742449);
void car_H_25(double *state, double *unused, double *out_8993267058135852454);
void car_h_24(double *state, double *unused, double *out_5044076517459918856);
void car_H_24(double *state, double *unused, double *out_7280827416568199596);
void car_h_30(double *state, double *unused, double *out_5983125520662397420);
void car_H_30(double *state, double *unused, double *out_2076576716644235699);
void car_h_26(double *state, double *unused, double *out_234514271167533250);
void car_H_26(double *state, double *unused, double *out_5688741088375051853);
void car_h_27(double *state, double *unused, double *out_7383231161432484220);
void car_H_27(double *state, double *unused, double *out_4251340028444660610);
void car_h_29(double *state, double *unused, double *out_7461945285386308551);
void car_H_29(double *state, double *unused, double *out_5964702755314211643);
void car_h_28(double *state, double *unused, double *out_2381557893771638575);
void car_H_28(double *state, double *unused, double *out_7399642301325809399);
void car_h_31(double *state, double *unused, double *out_4845873120447136726);
void car_H_31(double *state, double *unused, double *out_8962621096258892026);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}