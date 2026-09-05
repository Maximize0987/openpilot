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
void car_err_fun(double *nom_x, double *delta_x, double *out_5825026556611430403);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8876036798993240698);
void car_H_mod_fun(double *state, double *out_6203949078932441352);
void car_f_fun(double *state, double dt, double *out_343822199527135251);
void car_F_fun(double *state, double dt, double *out_7416815269748566643);
void car_h_25(double *state, double *unused, double *out_8641933420137717402);
void car_H_25(double *state, double *unused, double *out_7339103169592445424);
void car_h_24(double *state, double *unused, double *out_5501280400540853584);
void car_H_24(double *state, double *unused, double *out_9067966288769759493);
void car_h_30(double *state, double *unused, double *out_5706507355292462350);
void car_H_30(double *state, double *unused, double *out_422412828100828669);
void car_h_26(double *state, double *unused, double *out_8743293406736795035);
void car_H_26(double *state, double *unused, double *out_7366137585243049968);
void car_h_27(double *state, double *unused, double *out_6768024602127501529);
void car_H_27(double *state, double *unused, double *out_2597176139901253580);
void car_h_29(double *state, double *unused, double *out_5090891545105754924);
void car_H_29(double *state, double *unused, double *out_4310538866770804613);
void car_h_28(double *state, double *unused, double *out_5824514749225839094);
void car_H_28(double *state, double *unused, double *out_9053806189869216429);
void car_h_31(double *state, double *unused, double *out_8917127482422223291);
void car_H_31(double *state, double *unused, double *out_7308457207715484996);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}