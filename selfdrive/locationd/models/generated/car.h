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
void car_err_fun(double *nom_x, double *delta_x, double *out_9188106750313616310);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7483849663979101547);
void car_H_mod_fun(double *state, double *out_8322118016658148449);
void car_f_fun(double *state, double dt, double *out_764867040202035176);
void car_F_fun(double *state, double dt, double *out_3503154027384229832);
void car_h_25(double *state, double *unused, double *out_8616684642006491626);
void car_H_25(double *state, double *unused, double *out_8659603401543260529);
void car_h_24(double *state, double *unused, double *out_1016016545338744668);
void car_H_24(double *state, double *unused, double *out_1012248264354120193);
void car_h_30(double *state, double *unused, double *out_7791032536218648770);
void car_H_30(double *state, double *unused, double *out_8788942348686500599);
void car_h_26(double *state, double *unused, double *out_2789359268557803125);
void car_H_26(double *state, double *unused, double *out_8002749337432948625);
void car_h_27(double *state, double *unused, double *out_9220000526682969143);
void car_H_27(double *state, double *unused, double *out_7483038413222626106);
void car_h_29(double *state, double *unused, double *out_2449165300332618207);
void car_H_29(double *state, double *unused, double *out_8278711004372108415);
void car_h_28(double *state, double *unused, double *out_4225070279365736828);
void car_H_28(double *state, double *unused, double *out_5085634052267912627);
void car_h_31(double *state, double *unused, double *out_5668958651651006665);
void car_H_31(double *state, double *unused, double *out_8628957439666300101);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}