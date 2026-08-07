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
void car_err_fun(double *nom_x, double *delta_x, double *out_3432893246118840176);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1800982245938664737);
void car_H_mod_fun(double *state, double *out_1928298863277366044);
void car_f_fun(double *state, double dt, double *out_4615698619111285378);
void car_F_fun(double *state, double dt, double *out_4973087374980231388);
void car_h_25(double *state, double *unused, double *out_725345121681315694);
void car_H_25(double *state, double *unused, double *out_140226422483346712);
void car_h_24(double *state, double *unused, double *out_4245224659262713745);
void car_H_24(double *state, double *unused, double *out_610683904526685436);
void car_h_30(double *state, double *unused, double *out_882531790032444839);
void car_H_30(double *state, double *unused, double *out_269565369626586782);
void car_h_26(double *state, double *unused, double *out_1240296775338871155);
void car_H_26(double *state, double *unused, double *out_3881729741357402936);
void car_h_27(double *state, double *unused, double *out_4276328145979529951);
void car_H_27(double *state, double *unused, double *out_2444328681427011693);
void car_h_29(double *state, double *unused, double *out_3486937110841142490);
void car_H_29(double *state, double *unused, double *out_240665974687805402);
void car_h_28(double *state, double *unused, double *out_4705641026027310814);
void car_H_28(double *state, double *unused, double *out_9206653648343458316);
void car_h_31(double *state, double *unused, double *out_6045490104669035242);
void car_H_31(double *state, double *unused, double *out_109580460606386284);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}