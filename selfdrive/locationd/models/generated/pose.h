#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5836812006117722374);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_368701023819567149);
void pose_H_mod_fun(double *state, double *out_5720830998239473631);
void pose_f_fun(double *state, double dt, double *out_3302434187336556995);
void pose_F_fun(double *state, double dt, double *out_2147733219597398466);
void pose_h_4(double *state, double *unused, double *out_390661508853925842);
void pose_H_4(double *state, double *unused, double *out_3712928655556393493);
void pose_h_10(double *state, double *unused, double *out_4622668875416301287);
void pose_H_10(double *state, double *unused, double *out_9222803918002037771);
void pose_h_13(double *state, double *unused, double *out_7573083638476335875);
void pose_H_13(double *state, double *unused, double *out_500654830224060692);
void pose_h_14(double *state, double *unused, double *out_4512296191106361905);
void pose_H_14(double *state, double *unused, double *out_250312200783091036);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}