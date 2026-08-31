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
void car_err_fun(double *nom_x, double *delta_x, double *out_7311248151803822396);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5602719869542378501);
void car_H_mod_fun(double *state, double *out_6859429191092688662);
void car_f_fun(double *state, double dt, double *out_3400060270232460893);
void car_F_fun(double *state, double dt, double *out_6511275578440991802);
void car_h_25(double *state, double *unused, double *out_2633570630840598096);
void car_H_25(double *state, double *unused, double *out_2394126656704625717);
void car_h_24(double *state, double *unused, double *out_3094145344632818755);
void car_H_24(double *state, double *unused, double *out_665263537527311648);
void car_h_30(double *state, double *unused, double *out_1872662776110252318);
void car_H_30(double *state, double *unused, double *out_9135927075513309144);
void car_h_26(double *state, double *unused, double *out_2552698139187979215);
void car_H_26(double *state, double *unused, double *out_1347376662169430507);
void car_h_27(double *state, double *unused, double *out_8276300501921554931);
void car_H_27(double *state, double *unused, double *out_7136053686395817561);
void car_h_29(double *state, double *unused, double *out_6874336043771097963);
void car_H_29(double *state, double *unused, double *out_8625695731198916960);
void car_h_28(double *state, double *unused, double *out_1452606651919304359);
void car_H_28(double *state, double *unused, double *out_340291942456735954);
void car_h_31(double *state, double *unused, double *out_4557978482014913700);
void car_H_31(double *state, double *unused, double *out_2424772618581586145);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}