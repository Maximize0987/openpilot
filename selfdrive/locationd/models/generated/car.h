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
void car_err_fun(double *nom_x, double *delta_x, double *out_3645428350016324042);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6760420506725333180);
void car_H_mod_fun(double *state, double *out_2494414039273921066);
void car_f_fun(double *state, double dt, double *out_7248228104803536253);
void car_F_fun(double *state, double dt, double *out_8524982651096840533);
void car_h_25(double *state, double *unused, double *out_8901373037917505693);
void car_H_25(double *state, double *unused, double *out_6698774186638316171);
void car_h_24(double *state, double *unused, double *out_4440266777255545355);
void car_H_24(double *state, double *unused, double *out_2529290999430879054);
void car_h_30(double *state, double *unused, double *out_261495561198963809);
void car_H_30(double *state, double *unused, double *out_7220273556943627247);
void car_h_26(double *state, double *unused, double *out_4740177706461881836);
void car_H_26(double *state, double *unused, double *out_8006466568197179221);
void car_h_27(double *state, double *unused, double *out_6088820934647652310);
void car_H_27(double *state, double *unused, double *out_9002876445581981152);
void car_h_29(double *state, double *unused, double *out_906248239877177928);
void car_H_29(double *state, double *unused, double *out_7730504901258019431);
void car_h_28(double *state, double *unused, double *out_3561613674795902166);
void car_H_28(double *state, double *unused, double *out_2648105884188488857);
void car_h_31(double *state, double *unused, double *out_8626178975632999804);
void car_H_31(double *state, double *unused, double *out_6668128224761355743);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}