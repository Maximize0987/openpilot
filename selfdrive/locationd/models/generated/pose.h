#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_384350097947890971);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_161730175994041380);
void pose_H_mod_fun(double *state, double *out_511897058818169074);
void pose_f_fun(double *state, double dt, double *out_4006543374555760922);
void pose_F_fun(double *state, double dt, double *out_8169752966009844936);
void pose_h_4(double *state, double *unused, double *out_2516225834102864115);
void pose_H_4(double *state, double *unused, double *out_686050423064729030);
void pose_h_10(double *state, double *unused, double *out_865522221082823214);
void pose_H_10(double *state, double *unused, double *out_8576192708028364696);
void pose_h_13(double *state, double *unused, double *out_8706817024690289876);
void pose_H_13(double *state, double *unused, double *out_3898324248397061831);
void pose_h_14(double *state, double *unused, double *out_1828120776349525591);
void pose_H_14(double *state, double *unused, double *out_2396738009230643266);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}