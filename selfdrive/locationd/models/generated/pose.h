#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4860250714300227404);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6437944255548658708);
void pose_H_mod_fun(double *state, double *out_22797630451996970);
void pose_f_fun(double *state, double dt, double *out_2362837524605346595);
void pose_F_fun(double *state, double dt, double *out_4166989473592392013);
void pose_h_4(double *state, double *unused, double *out_800785631088066019);
void pose_H_4(double *state, double *unused, double *out_2555861026626074297);
void pose_h_10(double *state, double *unused, double *out_7585285090603906809);
void pose_H_10(double *state, double *unused, double *out_6341548427213940478);
void pose_h_13(double *state, double *unused, double *out_7888682643875678910);
void pose_H_13(double *state, double *unused, double *out_5768134851958407098);
void pose_h_14(double *state, double *unused, double *out_3441729687180753414);
void pose_H_14(double *state, double *unused, double *out_4925284788653666127);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}