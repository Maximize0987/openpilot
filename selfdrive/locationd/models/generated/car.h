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
void car_err_fun(double *nom_x, double *delta_x, double *out_3970546799234288025);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2567718075778826550);
void car_H_mod_fun(double *state, double *out_1717749627572306313);
void car_f_fun(double *state, double dt, double *out_4680969065089583930);
void car_F_fun(double *state, double dt, double *out_6937343164270022068);
void car_h_25(double *state, double *unused, double *out_5928605043652166783);
void car_H_25(double *state, double *unused, double *out_8807656413163385498);
void car_h_24(double *state, double *unused, double *out_226265923538190981);
void car_H_24(double *state, double *unused, double *out_5249730814361062362);
void car_h_30(double *state, double *unused, double *out_8880689501803362483);
void car_H_30(double *state, double *unused, double *out_6289323454656136871);
void car_h_26(double *state, double *unused, double *out_101279670203478282);
void car_H_26(double *state, double *unused, double *out_5897584341672109894);
void car_h_27(double *state, double *unused, double *out_3324199722843469132);
void car_H_27(double *state, double *unused, double *out_8464086766456561782);
void car_h_29(double *state, double *unused, double *out_3167013054492339987);
void car_H_29(double *state, double *unused, double *out_5779092110341744687);
void car_h_28(double *state, double *unused, double *out_287413671399136447);
void car_H_28(double *state, double *unused, double *out_7585252946298276355);
void car_h_31(double *state, double *unused, double *out_1952667607101882402);
void car_H_31(double *state, double *unused, double *out_5271376239438758418);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}