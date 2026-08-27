#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_309314752274053340);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_651338713617187314);
void pose_H_mod_fun(double *state, double *out_1638652939169850596);
void pose_f_fun(double *state, double dt, double *out_2831397313375340905);
void pose_F_fun(double *state, double dt, double *out_852487606375420018);
void pose_h_4(double *state, double *unused, double *out_6027168379751608829);
void pose_H_4(double *state, double *unused, double *out_4209428867582108125);
void pose_h_10(double *state, double *unused, double *out_744954405419605369);
void pose_H_10(double *state, double *unused, double *out_4888049829332208881);
void pose_h_13(double *state, double *unused, double *out_6652718215234119768);
void pose_H_13(double *state, double *unused, double *out_997155042249775324);
void pose_h_14(double *state, double *unused, double *out_7748768270616969343);
void pose_H_14(double *state, double *unused, double *out_4644545394226991724);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}