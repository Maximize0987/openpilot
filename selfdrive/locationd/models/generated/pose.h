#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8334628911363265031);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6557509511038369963);
void pose_H_mod_fun(double *state, double *out_2207458853057691014);
void pose_f_fun(double *state, double dt, double *out_7635303320387631810);
void pose_F_fun(double *state, double dt, double *out_8324840199262111301);
void pose_h_4(double *state, double *unused, double *out_2118179578320955915);
void pose_H_4(double *state, double *unused, double *out_7359977238096771749);
void pose_h_10(double *state, double *unused, double *out_863109591849531819);
void pose_H_10(double *state, double *unused, double *out_6053481103905099724);
void pose_h_13(double *state, double *unused, double *out_8506504787708500859);
void pose_H_13(double *state, double *unused, double *out_7874493010280447066);
void pose_h_14(double *state, double *unused, double *out_6030639671543279411);
void pose_H_14(double *state, double *unused, double *out_7123525979273295338);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}