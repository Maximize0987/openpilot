#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5866923855832820417);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7354374655466778507);
void pose_H_mod_fun(double *state, double *out_5435820587083186523);
void pose_f_fun(double *state, double dt, double *out_5089910609496554967);
void pose_F_fun(double *state, double dt, double *out_7337888639276922507);
void pose_h_4(double *state, double *unused, double *out_2944115722558364854);
void pose_H_4(double *state, double *unused, double *out_2235410685981716499);
void pose_h_10(double *state, double *unused, double *out_5480980924344673221);
void pose_H_10(double *state, double *unused, double *out_6151696322213561701);
void pose_h_13(double *state, double *unused, double *out_1838073821593632587);
void pose_H_13(double *state, double *unused, double *out_8600702179411134188);
void pose_h_14(double *state, double *unused, double *out_7366225133021847841);
void pose_H_14(double *state, double *unused, double *out_6198651542321201028);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}