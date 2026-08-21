#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_788519772333288428);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3476371721226452847);
void pose_H_mod_fun(double *state, double *out_1856202857491626372);
void pose_f_fun(double *state, double dt, double *out_7190390231498499682);
void pose_F_fun(double *state, double dt, double *out_4238346152453461367);
void pose_h_4(double *state, double *unused, double *out_7341523241853351564);
void pose_H_4(double *state, double *unused, double *out_3675901583397923233);
void pose_h_10(double *state, double *unused, double *out_7979280784138322600);
void pose_H_10(double *state, double *unused, double *out_2717029967524110913);
void pose_h_13(double *state, double *unused, double *out_2249980252911390508);
void pose_H_13(double *state, double *unused, double *out_3934729624918777696);
void pose_h_14(double *state, double *unused, double *out_6063115878095578816);
void pose_H_14(double *state, double *unused, double *out_287339272941561296);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}