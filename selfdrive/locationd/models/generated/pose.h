#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2665641701635233151);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8375727440013270020);
void pose_H_mod_fun(double *state, double *out_6067255468928274013);
void pose_f_fun(double *state, double dt, double *out_6773782600033783154);
void pose_F_fun(double *state, double dt, double *out_6298375408118706110);
void pose_h_4(double *state, double *unused, double *out_6452539322350206189);
void pose_H_4(double *state, double *unused, double *out_4829214681067158040);
void pose_h_10(double *state, double *unused, double *out_5957134933492111448);
void pose_H_10(double *state, double *unused, double *out_3625295134339217134);
void pose_h_13(double *state, double *unused, double *out_6701412570788452504);
void pose_H_13(double *state, double *unused, double *out_5393816600749002144);
void pose_h_14(double *state, double *unused, double *out_192900434341408297);
void pose_H_14(double *state, double *unused, double *out_1746426248771785744);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}