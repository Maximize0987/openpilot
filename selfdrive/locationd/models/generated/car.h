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
void car_err_fun(double *nom_x, double *delta_x, double *out_3009395508469456389);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6058691817726549063);
void car_H_mod_fun(double *state, double *out_6620632585560778509);
void car_f_fun(double *state, double dt, double *out_3578319971516081169);
void car_F_fun(double *state, double dt, double *out_2530937000049298875);
void car_h_25(double *state, double *unused, double *out_2134931354245078390);
void car_H_25(double *state, double *unused, double *out_2632923262236535870);
void car_h_24(double *state, double *unused, double *out_8365765087520140722);
void car_H_24(double *state, double *unused, double *out_460273663231036304);
void car_h_30(double *state, double *unused, double *out_5772380882499100740);
void car_H_30(double *state, double *unused, double *out_5151256220743784497);
void car_h_26(double *state, double *unused, double *out_770707614838255095);
void car_H_26(double *state, double *unused, double *out_1108580056637520354);
void car_h_27(double *state, double *unused, double *out_7593975799595780900);
void car_H_27(double *state, double *unused, double *out_7374850291927727714);
void car_h_29(double *state, double *unused, double *out_287296851158268285);
void car_H_29(double *state, double *unused, double *out_5661487565058176681);
void car_h_28(double *state, double *unused, double *out_6243721933085284858);
void car_H_28(double *state, double *unused, double *out_579088547988646107);
void car_h_31(double *state, double *unused, double *out_8851253955215584901);
void car_H_31(double *state, double *unused, double *out_2663569224113496298);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}