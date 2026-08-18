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
void car_err_fun(double *nom_x, double *delta_x, double *out_5328892797193692082);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6664197118630309465);
void car_H_mod_fun(double *state, double *out_7049792320674666550);
void car_f_fun(double *state, double dt, double *out_8058289693715916474);
void car_F_fun(double *state, double dt, double *out_6834456908135559848);
void car_h_25(double *state, double *unused, double *out_3817993858643920850);
void car_H_25(double *state, double *unused, double *out_2203763527122647829);
void car_h_24(double *state, double *unused, double *out_589890583681194954);
void car_H_24(double *state, double *unused, double *out_31113928117148263);
void car_h_30(double *state, double *unused, double *out_855557586624953167);
void car_H_30(double *state, double *unused, double *out_4722096485629896456);
void car_h_26(double *state, double *unused, double *out_3459962907433650818);
void car_H_26(double *state, double *unused, double *out_1537739791751408395);
void car_h_27(double *state, double *unused, double *out_2284525577089273540);
void car_H_27(double *state, double *unused, double *out_6945690556813839673);
void car_h_29(double *state, double *unused, double *out_1458873471301430684);
void car_H_29(double *state, double *unused, double *out_5232327829944288640);
void car_h_28(double *state, double *unused, double *out_7286198844750119185);
void car_H_28(double *state, double *unused, double *out_149928812874758066);
void car_h_31(double *state, double *unused, double *out_9220241001058989162);
void car_H_31(double *state, double *unused, double *out_2163947893984759871);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}