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
void car_err_fun(double *nom_x, double *delta_x, double *out_3239626159248919555);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7776805117874316837);
void car_H_mod_fun(double *state, double *out_857826347354799703);
void car_f_fun(double *state, double dt, double *out_8901269396414862155);
void car_F_fun(double *state, double dt, double *out_8699189799260073455);
void car_h_25(double *state, double *unused, double *out_7376242857501384597);
void car_H_25(double *state, double *unused, double *out_4045865477829865137);
void car_h_24(double *state, double *unused, double *out_8059939713516192443);
void car_H_24(double *state, double *unused, double *out_6223079901437015110);
void car_h_30(double *state, double *unused, double *out_4428516867145899636);
void car_H_30(double *state, double *unused, double *out_6564198436337113764);
void car_h_26(double *state, double *unused, double *out_6344022010831827263);
void car_H_26(double *state, double *unused, double *out_7350391447590665738);
void car_h_27(double *state, double *unused, double *out_8466095895399469368);
void car_H_27(double *state, double *unused, double *out_4389435124536688853);
void car_h_29(double *state, double *unused, double *out_3825200982469422119);
void car_H_29(double *state, double *unused, double *out_7074429780651505948);
void car_h_28(double *state, double *unused, double *out_515873276607371397);
void car_H_28(double *state, double *unused, double *out_1992030763581975374);
void car_h_31(double *state, double *unused, double *out_3189228565454117834);
void car_H_31(double *state, double *unused, double *out_6724183345357314262);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}