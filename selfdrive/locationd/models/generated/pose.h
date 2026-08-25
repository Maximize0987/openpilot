#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7958882747940958001);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4703319146697471116);
void pose_H_mod_fun(double *state, double *out_656327009382969529);
void pose_f_fun(double *state, double dt, double *out_1970546984054209494);
void pose_F_fun(double *state, double dt, double *out_2484970000761638635);
void pose_h_4(double *state, double *unused, double *out_5725974613387962710);
void pose_H_4(double *state, double *unused, double *out_3808243550112720964);
void pose_h_10(double *state, double *unused, double *out_6479738358501538001);
void pose_H_10(double *state, double *unused, double *out_2571832150125994618);
void pose_h_13(double *state, double *unused, double *out_2468597468972695670);
void pose_H_13(double *state, double *unused, double *out_595969724780388163);
void pose_h_14(double *state, double *unused, double *out_7378190979403323616);
void pose_H_14(double *state, double *unused, double *out_6891031982408093260);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}