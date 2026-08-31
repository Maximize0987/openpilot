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
void car_err_fun(double *nom_x, double *delta_x, double *out_7251302496478371121);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7757777920139399450);
void car_H_mod_fun(double *state, double *out_5994192809213785164);
void car_f_fun(double *state, double dt, double *out_5541966606958472992);
void car_F_fun(double *state, double dt, double *out_3805616153551932316);
void car_h_25(double *state, double *unused, double *out_4112076348506573484);
void car_H_25(double *state, double *unused, double *out_2471212159224293487);
void car_h_24(double *state, double *unused, double *out_2715398695630647729);
void car_H_24(double *state, double *unused, double *out_1086713439578029649);
void car_h_30(double *state, double *unused, double *out_3954889680155444339);
void car_H_30(double *state, double *unused, double *out_4445478182267323268);
void car_h_26(double *state, double *unused, double *out_1046783587505401306);
void car_H_26(double *state, double *unused, double *out_6212715478098349711);
void car_h_27(double *state, double *unused, double *out_1075290297062240799);
void car_H_27(double *state, double *unused, double *out_2270714870466898357);
void car_h_29(double *state, double *unused, double *out_5695544929288110137);
void car_H_29(double *state, double *unused, double *out_4955709526581715452);
void car_h_28(double *state, double *unused, double *out_131780444160578364);
void car_H_28(double *state, double *unused, double *out_4525046873472183250);
void car_h_31(double *state, double *unused, double *out_3836882286222067595);
void car_H_31(double *state, double *unused, double *out_2440566197347333059);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}