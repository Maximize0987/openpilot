#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_709589957515877441);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3661238081000149023);
void pose_H_mod_fun(double *state, double *out_3274536842161333363);
void pose_f_fun(double *state, double dt, double *out_54085149498667220);
void pose_F_fun(double *state, double dt, double *out_3360900556715541089);
void pose_h_4(double *state, double *unused, double *out_6781682784175939845);
void pose_H_4(double *state, double *unused, double *out_2076589360278435259);
void pose_h_10(double *state, double *unused, double *out_4409132040641892266);
void pose_H_10(double *state, double *unused, double *out_6826621589500186302);
void pose_h_13(double *state, double *unused, double *out_1754250637475505882);
void pose_H_13(double *state, double *unused, double *out_1135684465053897542);
void pose_h_14(double *state, double *unused, double *out_2425630726311968111);
void pose_H_14(double *state, double *unused, double *out_1886651496061049270);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}