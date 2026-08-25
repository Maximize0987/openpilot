#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_772147526555487692);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4282924253332717604);
void pose_H_mod_fun(double *state, double *out_4974307322782455600);
void pose_f_fun(double *state, double dt, double *out_1104587078015232117);
void pose_F_fun(double *state, double dt, double *out_5293033715763511365);
void pose_h_4(double *state, double *unused, double *out_5228726973950769986);
void pose_H_4(double *state, double *unused, double *out_3032303058814960921);
void pose_h_10(double *state, double *unused, double *out_122492238844625391);
void pose_H_10(double *state, double *unused, double *out_4293959578107599330);
void pose_h_13(double *state, double *unused, double *out_4688840231226545336);
void pose_H_13(double *state, double *unused, double *out_7803809806577889766);
void pose_h_14(double *state, double *unused, double *out_5111785488402772162);
void pose_H_14(double *state, double *unused, double *out_6995543915154445450);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}