#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4358722787451740543);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8563351397910358896);
void pose_H_mod_fun(double *state, double *out_5753197897836805411);
void pose_f_fun(double *state, double dt, double *out_4934931273554332776);
void pose_F_fun(double *state, double dt, double *out_3951309264317131877);
void pose_h_4(double *state, double *unused, double *out_9124951261160774984);
void pose_H_4(double *state, double *unused, double *out_1981390687992897839);
void pose_h_10(double *state, double *unused, double *out_5902756371163799354);
void pose_H_10(double *state, double *unused, double *out_3301172069868817257);
void pose_h_13(double *state, double *unused, double *out_1037730484658777493);
void pose_H_13(double *state, double *unused, double *out_1230883137339434962);
void pose_h_14(double *state, double *unused, double *out_8550422043798884554);
void pose_H_14(double *state, double *unused, double *out_5064179120288270135);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}