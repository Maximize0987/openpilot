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
void car_err_fun(double *nom_x, double *delta_x, double *out_5397134643365763284);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_643379036491463030);
void car_H_mod_fun(double *state, double *out_8008223313057305919);
void car_f_fun(double *state, double dt, double *out_1320186800141293730);
void car_F_fun(double *state, double dt, double *out_4790924461105660686);
void car_h_25(double *state, double *unused, double *out_4267314374776649182);
void car_H_25(double *state, double *unused, double *out_5534828935467580857);
void car_h_24(double *state, double *unused, double *out_544790792172897547);
void car_H_24(double *state, double *unused, double *out_7263692054644894926);
void car_h_30(double *state, double *unused, double *out_1899799665194485121);
void car_H_30(double *state, double *unused, double *out_1381861406024035898);
void car_h_26(double *state, double *unused, double *out_956289812292822686);
void car_H_26(double *state, double *unused, double *out_2230302965706780256);
void car_h_27(double *state, double *unused, double *out_9177756431272056789);
void car_H_27(double *state, double *unused, double *out_792901905776389013);
void car_h_29(double *state, double *unused, double *out_8902562368987550900);
void car_H_29(double *state, double *unused, double *out_2506264632645940046);
void car_h_28(double *state, double *unused, double *out_3951849215436731842);
void car_H_28(double *state, double *unused, double *out_7588663649715470620);
void car_h_31(double *state, double *unused, double *out_629864846522626832);
void car_H_31(double *state, double *unused, double *out_1541846315044236396);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}