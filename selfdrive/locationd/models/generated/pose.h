#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2394949464519988932);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6906452154256624155);
void pose_H_mod_fun(double *state, double *out_4838410850925167920);
void pose_f_fun(double *state, double dt, double *out_8751525120696163789);
void pose_F_fun(double *state, double dt, double *out_7175128552495691270);
void pose_h_4(double *state, double *unused, double *out_1724585592717515492);
void pose_H_4(double *state, double *unused, double *out_3018712125018871059);
void pose_h_10(double *state, double *unused, double *out_1452906161636095115);
void pose_H_10(double *state, double *unused, double *out_3099904708442444122);
void pose_h_13(double *state, double *unused, double *out_7528264878139249656);
void pose_H_13(double *state, double *unused, double *out_3583314044700715163);
void pose_h_14(double *state, double *unused, double *out_4413124467477602634);
void pose_H_14(double *state, double *unused, double *out_64076307276501237);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}