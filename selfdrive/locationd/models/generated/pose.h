#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2717418772724129561);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6564594974930648805);
void pose_H_mod_fun(double *state, double *out_500884218142268447);
void pose_f_fun(double *state, double dt, double *out_4066820228930702403);
void pose_F_fun(double *state, double dt, double *out_4990161262598215268);
void pose_h_4(double *state, double *unused, double *out_6356659530746877918);
void pose_H_4(double *state, double *unused, double *out_9001498189509461827);
void pose_h_10(double *state, double *unused, double *out_4540118139912947621);
void pose_H_10(double *state, double *unused, double *out_2609551212551183976);
void pose_h_13(double *state, double *unused, double *out_8965537497810380637);
void pose_H_13(double *state, double *unused, double *out_6232972058867756988);
void pose_h_14(double *state, double *unused, double *out_6865363732186478618);
void pose_H_14(double *state, double *unused, double *out_8566381662864578228);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}