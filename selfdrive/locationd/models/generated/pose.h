#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_845527351868247428);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6367069276716114158);
void pose_H_mod_fun(double *state, double *out_7305256634145735915);
void pose_f_fun(double *state, double dt, double *out_9088132790328569434);
void pose_F_fun(double *state, double dt, double *out_729090673475074795);
void pose_h_4(double *state, double *unused, double *out_8764272932229882331);
void pose_H_4(double *state, double *unused, double *out_5988969054524734966);
void pose_h_10(double *state, double *unused, double *out_6414221724467934748);
void pose_H_10(double *state, double *unused, double *out_1153388749736371435);
void pose_h_13(double *state, double *unused, double *out_5610980844253424068);
void pose_H_13(double *state, double *unused, double *out_2776695229192402165);
void pose_h_14(double *state, double *unused, double *out_4768711222929490371);
void pose_H_14(double *state, double *unused, double *out_9071757486820107262);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}