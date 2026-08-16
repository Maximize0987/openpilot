#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_776419627085520882);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3246049781621128423);
void pose_H_mod_fun(double *state, double *out_5710430290201935803);
void pose_f_fun(double *state, double dt, double *out_5795859550853760244);
void pose_F_fun(double *state, double dt, double *out_391118642873528758);
void pose_h_4(double *state, double *unused, double *out_3587574498855600647);
void pose_H_4(double *state, double *unused, double *out_1095803253272619439);
void pose_h_10(double *state, double *unused, double *out_5054997698151726674);
void pose_H_10(double *state, double *unused, double *out_4117080739741493196);
void pose_h_13(double *state, double *unused, double *out_3693365734857647821);
void pose_H_13(double *state, double *unused, double *out_6514827955044081490);
void pose_h_14(double *state, double *unused, double *out_1461011669399451348);
void pose_H_14(double *state, double *unused, double *out_2867437603066865090);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}