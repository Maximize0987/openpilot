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
void car_err_fun(double *nom_x, double *delta_x, double *out_3355904321462358618);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_201422243433114007);
void car_H_mod_fun(double *state, double *out_99163613418102636);
void car_f_fun(double *state, double dt, double *out_4535403042767963777);
void car_F_fun(double *state, double dt, double *out_3611627361836084616);
void car_h_25(double *state, double *unused, double *out_5863917325441369509);
void car_H_25(double *state, double *unused, double *out_4695667229509766473);
void car_h_24(double *state, double *unused, double *out_3481314710267158875);
void car_H_24(double *state, double *unused, double *out_4606210134248907981);
void car_h_30(double *state, double *unused, double *out_723910601034925654);
void car_H_30(double *state, double *unused, double *out_2177334271002517846);
void car_h_26(double *state, double *unused, double *out_120594716358448137);
void car_H_26(double *state, double *unused, double *out_8437170548383822697);
void car_h_27(double *state, double *unused, double *out_6807427178343031944);
void car_H_27(double *state, double *unused, double *out_4352097582802942757);
void car_h_29(double *state, double *unused, double *out_2312875450409407031);
void car_H_29(double *state, double *unused, double *out_1667102926688125662);
void car_h_28(double *state, double *unused, double *out_4636554191573453893);
void car_H_28(double *state, double *unused, double *out_6749501943757656236);
void car_h_31(double *state, double *unused, double *out_5706730657090240364);
void car_H_31(double *state, double *unused, double *out_9063378650617174173);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}