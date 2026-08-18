#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3059462324026594541);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7293350812574481008);
void pose_H_mod_fun(double *state, double *out_1219845042234673490);
void pose_f_fun(double *state, double dt, double *out_6142826586467809321);
void pose_F_fun(double *state, double dt, double *out_8396239383595830029);
void pose_h_4(double *state, double *unused, double *out_1811902591494823997);
void pose_H_4(double *state, double *unused, double *out_599853683671623371);
void pose_h_10(double *state, double *unused, double *out_8987115705540323441);
void pose_H_10(double *state, double *unused, double *out_4430606342081287306);
void pose_h_13(double *state, double *unused, double *out_745002374354712655);
void pose_H_13(double *state, double *unused, double *out_4433609146974147395);
void pose_h_14(double *state, double *unused, double *out_7578055683598024511);
void pose_H_14(double *state, double *unused, double *out_3682642115966995667);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}