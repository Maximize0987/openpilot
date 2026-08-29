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
void car_err_fun(double *nom_x, double *delta_x, double *out_8986378044421410730);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1940910250995899848);
void car_H_mod_fun(double *state, double *out_1327881932680008443);
void car_f_fun(double *state, double dt, double *out_7832214154397608531);
void car_F_fun(double *state, double dt, double *out_4114606570946988857);
void car_h_25(double *state, double *unused, double *out_8263447783360605785);
void car_H_25(double *state, double *unused, double *out_5780776564353391637);
void car_h_24(double *state, double *unused, double *out_4755010794979530940);
void car_H_24(double *state, double *unused, double *out_9108041910553836843);
void car_h_30(double *state, double *unused, double *out_6812816390731722618);
void car_H_30(double *state, double *unused, double *out_5749277167864543224);
void car_h_26(double *state, double *unused, double *out_4631164979184763219);
void car_H_26(double *state, double *unused, double *out_2039273245479335413);
void car_h_27(double *state, double *unused, double *out_6907448477601489242);
void car_H_27(double *state, double *unused, double *out_7924040479664968135);
void car_h_29(double *state, double *unused, double *out_6632254415316983353);
void car_H_29(double *state, double *unused, double *out_5239045823550151040);
void car_h_28(double *state, double *unused, double *out_4283151879014610665);
void car_H_28(double *state, double *unused, double *out_8125299233089870002);
void car_h_31(double *state, double *unused, double *out_7988253721076099896);
void car_H_31(double *state, double *unused, double *out_5811422526230352065);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}