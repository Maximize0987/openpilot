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
void car_err_fun(double *nom_x, double *delta_x, double *out_943833552876303288);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_528301401300769025);
void car_H_mod_fun(double *state, double *out_7538255523593818631);
void car_f_fun(double *state, double dt, double *out_3917173406968738478);
void car_F_fun(double *state, double dt, double *out_547656323515283001);
void car_h_25(double *state, double *unused, double *out_3127457687100704828);
void car_H_25(double *state, double *unused, double *out_7385507900126241308);
void car_h_24(double *state, double *unused, double *out_1385747192697667747);
void car_H_24(double *state, double *unused, double *out_3827582301323918172);
void car_h_30(double *state, double *unused, double *out_4635807569719967613);
void car_H_30(double *state, double *unused, double *out_7514846847269481378);
void car_h_26(double *state, double *unused, double *out_4346161602286873152);
void car_H_26(double *state, double *unused, double *out_7319732854709254084);
void car_h_27(double *state, double *unused, double *out_90671635656372143);
void car_H_27(double *state, double *unused, double *out_8757133914639645327);
void car_h_29(double *state, double *unused, double *out_365865697940878032);
void car_H_29(double *state, double *unused, double *out_7004615502955089194);
void car_h_28(double *state, double *unused, double *out_6687857119962214334);
void car_H_28(double *state, double *unused, double *out_5040985231389762943);
void car_h_31(double *state, double *unused, double *out_8548451160258495852);
void car_H_31(double *state, double *unused, double *out_7354861938249280880);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}