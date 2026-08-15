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
void car_err_fun(double *nom_x, double *delta_x, double *out_3464059133551141831);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3057034877580327163);
void car_H_mod_fun(double *state, double *out_1278642935192462594);
void car_f_fun(double *state, double dt, double *out_258465026591330744);
void car_F_fun(double *state, double dt, double *out_5399477112920697267);
void car_h_25(double *state, double *unused, double *out_7067526126189904312);
void car_H_25(double *state, double *unused, double *out_7914545290719774643);
void car_h_24(double *state, double *unused, double *out_5828690765636070596);
void car_H_24(double *state, double *unused, double *out_1260339832611588886);
void car_h_30(double *state, double *unused, double *out_2572974398256279399);
void car_H_30(double *state, double *unused, double *out_6004502452862168775);
void car_h_26(double *state, double *unused, double *out_3176290282932756916);
void car_H_26(double *state, double *unused, double *out_6790695464115720749);
void car_h_27(double *state, double *unused, double *out_7048987171797560597);
void car_H_27(double *state, double *unused, double *out_3829739141061743864);
void car_h_29(double *state, double *unused, double *out_3516484251157941834);
void car_H_29(double *state, double *unused, double *out_6514733797176560959);
void car_h_28(double *state, double *unused, double *out_6396083634251145374);
void car_H_28(double *state, double *unused, double *out_1432334780107030385);
void car_h_31(double *state, double *unused, double *out_3497945296765598119);
void car_H_31(double *state, double *unused, double *out_6164487361882369273);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}