#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3576801538095390920);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3629669491519681211);
void pose_H_mod_fun(double *state, double *out_128220774054724087);
void pose_f_fun(double *state, double dt, double *out_8022018128441912094);
void pose_F_fun(double *state, double dt, double *out_4440336535941280195);
void pose_h_4(double *state, double *unused, double *out_1055205231970937411);
void pose_H_4(double *state, double *unused, double *out_5232245798722086233);
void pose_h_10(double *state, double *unused, double *out_4616527314461451432);
void pose_H_10(double *state, double *unused, double *out_5353452105284919759);
void pose_h_13(double *state, double *unused, double *out_35896446347085605);
void pose_H_13(double *state, double *unused, double *out_5603867066670764454);
void pose_h_14(double *state, double *unused, double *out_631141063206634270);
void pose_H_14(double *state, double *unused, double *out_9195486655061570762);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}