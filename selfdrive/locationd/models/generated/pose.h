#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4298502647758524793);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5600470633109473941);
void pose_H_mod_fun(double *state, double *out_5604237734398293519);
void pose_f_fun(double *state, double dt, double *out_1603951998531582898);
void pose_F_fun(double *state, double dt, double *out_7355016791857912131);
void pose_h_4(double *state, double *unused, double *out_3151076657578519351);
void pose_H_4(double *state, double *unused, double *out_9070699129467350525);
void pose_h_10(double *state, double *unused, double *out_6670778953679817884);
void pose_H_10(double *state, double *unused, double *out_8318326309939820808);
void pose_h_13(double *state, double *unused, double *out_8670142885989515415);
void pose_H_13(double *state, double *unused, double *out_5542289480939677067);
void pose_h_14(double *state, double *unused, double *out_3946013715221375238);
void pose_H_14(double *state, double *unused, double *out_6293256511946828795);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}