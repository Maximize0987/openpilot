#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7746602045410251207);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7631524114608656485);
void pose_H_mod_fun(double *state, double *out_506241675272442753);
void pose_f_fun(double *state, double dt, double *out_4178544833437689493);
void pose_F_fun(double *state, double dt, double *out_8152186578689356973);
void pose_h_4(double *state, double *unused, double *out_6179676342109340429);
void pose_H_4(double *state, double *unused, double *out_1260402677327155360);
void pose_h_10(double *state, double *unused, double *out_9202982941819295536);
void pose_H_10(double *state, double *unused, double *out_6171075050568888644);
void pose_h_13(double *state, double *unused, double *out_5137979176045158123);
void pose_H_13(double *state, double *unused, double *out_4472676502659488161);
void pose_h_14(double *state, double *unused, double *out_7033934925710428047);
void pose_H_14(double *state, double *unused, double *out_1822385754968216936);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}