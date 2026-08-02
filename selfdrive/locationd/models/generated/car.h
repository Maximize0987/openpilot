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
void car_err_fun(double *nom_x, double *delta_x, double *out_3928386937016580969);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5072261536488927858);
void car_H_mod_fun(double *state, double *out_1805157416881491113);
void car_f_fun(double *state, double dt, double *out_779920196187082914);
void car_F_fun(double *state, double dt, double *out_3629707451146971735);
void car_h_25(double *state, double *unused, double *out_3062657207957604668);
void car_H_25(double *state, double *unused, double *out_6170957893956391582);
void car_h_24(double *state, double *unused, double *out_4363661235373079824);
void car_H_24(double *state, double *unused, double *out_6464400548730383069);
void car_h_30(double *state, double *unused, double *out_8192537752896435152);
void car_H_30(double *state, double *unused, double *out_5359095838261543279);
void car_h_26(double *state, double *unused, double *out_1793496235482586006);
void car_H_26(double *state, double *unused, double *out_8971260209992359433);
void car_h_27(double *state, double *unused, double *out_8064330475618450313);
void car_H_27(double *state, double *unused, double *out_7533859150061968190);
void car_h_29(double *state, double *unused, double *out_6613699082989567146);
void car_H_29(double *state, double *unused, double *out_4848864493947151095);
void car_h_28(double *state, double *unused, double *out_7120820622716787878);
void car_H_28(double *state, double *unused, double *out_4117123179708501819);
void car_h_31(double *state, double *unused, double *out_574792320296417682);
void car_H_31(double *state, double *unused, double *out_5199110929241342781);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}