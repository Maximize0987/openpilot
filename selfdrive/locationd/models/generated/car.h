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
void car_err_fun(double *nom_x, double *delta_x, double *out_4885896537278282144);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3745151970403573209);
void car_H_mod_fun(double *state, double *out_2937880372820632520);
void car_f_fun(double *state, double dt, double *out_4204558600518622219);
void car_F_fun(double *state, double dt, double *out_3726788735705827984);
void car_h_25(double *state, double *unused, double *out_6349123496291746259);
void car_H_25(double *state, double *unused, double *out_7841572198005297360);
void car_h_24(double *state, double *unused, double *out_2774216340997546785);
void car_H_24(double *state, double *unused, double *out_8427957452097104283);
void car_h_30(double *state, double *unused, double *out_5326785351067454421);
void car_H_30(double *state, double *unused, double *out_8086838917197005629);
void car_h_26(double *state, double *unused, double *out_3469524113198542719);
void car_H_26(double *state, double *unused, double *out_4100068879131241136);
void car_h_27(double *state, double *unused, double *out_1347450228630900614);
void car_H_27(double *state, double *unused, double *out_8185141844712121076);
void car_h_29(double *state, double *unused, double *out_2289999299623121736);
void car_H_29(double *state, double *unused, double *out_7576607572882613445);
void car_h_28(double *state, double *unused, double *out_2290960081532563049);
void car_H_28(double *state, double *unused, double *out_5787737483757407597);
void car_h_31(double *state, double *unused, double *out_8460171049163783007);
void car_H_31(double *state, double *unused, double *out_3473860776897889660);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}