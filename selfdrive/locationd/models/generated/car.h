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
void car_err_fun(double *nom_x, double *delta_x, double *out_5870650175258852411);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3265729657434381044);
void car_H_mod_fun(double *state, double *out_8559018147660225964);
void car_f_fun(double *state, double dt, double *out_1736737013642959687);
void car_F_fun(double *state, double dt, double *out_2126390936971804335);
void car_h_25(double *state, double *unused, double *out_650360746861026872);
void car_H_25(double *state, double *unused, double *out_5521925448974425183);
void car_h_24(double *state, double *unused, double *out_6354297212728781983);
void car_H_24(double *state, double *unused, double *out_1963999850172102047);
void car_h_30(double *state, double *unused, double *out_5144912474794651785);
void car_H_30(double *state, double *unused, double *out_1394764892517191572);
void car_h_26(double *state, double *unused, double *out_4541596590118174268);
void car_H_26(double *state, double *unused, double *out_9183315305861070209);
void car_h_27(double *state, double *unused, double *out_2386425304583305813);
void car_H_27(double *state, double *unused, double *out_779998419283233339);
void car_h_29(double *state, double *unused, double *out_4201402621892989350);
void car_H_29(double *state, double *unused, double *out_1904996236831583756);
void car_h_28(double *state, double *unused, double *out_1783109419906828296);
void car_H_28(double *state, double *unused, double *out_3177402780237946818);
void car_h_31(double *state, double *unused, double *out_7421195973211377808);
void car_H_31(double *state, double *unused, double *out_5491279487097464755);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}