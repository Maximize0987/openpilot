#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7783868612103190645);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6605006959385105646);
void pose_H_mod_fun(double *state, double *out_4214017023834556037);
void pose_f_fun(double *state, double dt, double *out_446156685689757577);
void pose_F_fun(double *state, double dt, double *out_1314145057723334901);
void pose_h_4(double *state, double *unused, double *out_3131871851783197102);
void pose_H_4(double *state, double *unused, double *out_7985824233678463609);
void pose_h_10(double *state, double *unused, double *out_4732705393461985535);
void pose_H_10(double *state, double *unused, double *out_25842791302237901);
void pose_h_13(double *state, double *unused, double *out_3855617401361447493);
void pose_H_13(double *state, double *unused, double *out_2850288631714387078);
void pose_h_14(double *state, double *unused, double *out_2052081526966194460);
void pose_H_14(double *state, double *unused, double *out_4903035801383091313);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}