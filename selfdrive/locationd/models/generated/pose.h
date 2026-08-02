#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_9137514370372247790);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3476070474607186610);
void pose_H_mod_fun(double *state, double *out_2374218852650606410);
void pose_f_fun(double *state, double dt, double *out_4392889107205501252);
void pose_F_fun(double *state, double dt, double *out_5161498735714983758);
void pose_h_4(double *state, double *unused, double *out_6700070712992729001);
void pose_H_4(double *state, double *unused, double *out_554520126744309549);
void pose_h_10(double *state, double *unused, double *out_326755883218172788);
void pose_H_10(double *state, double *unused, double *out_3618077715207225770);
void pose_h_13(double *state, double *unused, double *out_8852328989829848020);
void pose_H_13(double *state, double *unused, double *out_3279235336558214475);
void pose_h_14(double *state, double *unused, double *out_2099262646432106248);
void pose_H_14(double *state, double *unused, double *out_2528268305551062747);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}