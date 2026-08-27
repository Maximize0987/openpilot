#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3753506106150578989);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1593625426676531654);
void car_H_mod_fun(double *state, double *out_8762705886933200550);
void car_f_fun(double *state, double dt, double *out_5029070318695641969);
void car_F_fun(double *state, double dt, double *out_2813073183560075211);
void car_h_25(double *state, double *unused, double *out_658669783575432838);
void car_H_25(double *state, double *unused, double *out_430482338979036687);
void car_h_24(double *state, double *unused, double *out_5825414391673489257);
void car_H_24(double *state, double *unused, double *out_1795225444999831875);
void car_h_30(double *state, double *unused, double *out_383475721290926949);
void car_H_30(double *state, double *unused, double *out_6486208002512580068);
void car_h_26(double *state, double *unused, double *out_4460551706629794316);
void car_H_26(double *state, double *unused, double *out_4171985657853092911);
void car_h_27(double *state, double *unused, double *out_4343003484085412807);
void car_H_27(double *state, double *unused, double *out_4311444690712155157);
void car_h_29(double *state, double *unused, double *out_4618197546369918696);
void car_H_29(double *state, double *unused, double *out_6996439346826972252);
void car_h_28(double *state, double *unused, double *out_3399493631183750372);
void car_H_28(double *state, double *unused, double *out_1914040329757441678);
void car_h_31(double *state, double *unused, double *out_501483115224303693);
void car_H_31(double *state, double *unused, double *out_399836377102076259);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}