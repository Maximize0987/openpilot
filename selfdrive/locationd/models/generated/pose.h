#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7136046097392635975);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7829757394788773504);
void pose_H_mod_fun(double *state, double *out_4151448671193851274);
void pose_f_fun(double *state, double dt, double *out_1642603653923874431);
void pose_F_fun(double *state, double dt, double *out_7023136226815456968);
void pose_h_4(double *state, double *unused, double *out_4588754796686824329);
void pose_H_4(double *state, double *unused, double *out_6094990518542475575);
void pose_h_10(double *state, double *unused, double *out_2376996171077473254);
void pose_H_10(double *state, double *unused, double *out_3986987343223994685);
void pose_h_13(double *state, double *unused, double *out_4475690324738606342);
void pose_H_13(double *state, double *unused, double *out_1515640689774225354);
void pose_h_14(double *state, double *unused, double *out_4137331969092828561);
void pose_H_14(double *state, double *unused, double *out_2131749662202991046);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}