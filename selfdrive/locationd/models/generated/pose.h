#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1282506072975981321);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8512738075508223963);
void pose_H_mod_fun(double *state, double *out_3135048301285292021);
void pose_f_fun(double *state, double dt, double *out_8178969782644284561);
void pose_F_fun(double *state, double dt, double *out_7659025943100145673);
void pose_h_4(double *state, double *unused, double *out_6376674584644624571);
void pose_H_4(double *state, double *unused, double *out_1315349575378995160);
void pose_h_10(double *state, double *unused, double *out_7386007572913415364);
void pose_H_10(double *state, double *unused, double *out_2432083188517445378);
void pose_h_13(double *state, double *unused, double *out_2876319704878199880);
void pose_H_13(double *state, double *unused, double *out_8925980783695696089);
void pose_h_14(double *state, double *unused, double *out_1255542748321681251);
void pose_H_14(double *state, double *unused, double *out_5278590431718479689);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}