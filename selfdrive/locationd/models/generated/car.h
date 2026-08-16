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
void car_err_fun(double *nom_x, double *delta_x, double *out_3350045275544931453);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_537147974555085981);
void car_H_mod_fun(double *state, double *out_7775026745617319605);
void car_f_fun(double *state, double dt, double *out_4198835588916233412);
void car_F_fun(double *state, double dt, double *out_4444349682340675673);
void car_h_25(double *state, double *unused, double *out_6936843442256047922);
void car_H_25(double *state, double *unused, double *out_1418161480294917632);
void car_h_24(double *state, double *unused, double *out_5320826123735066091);
void car_H_24(double *state, double *unused, double *out_6164670807261426666);
void car_h_30(double *state, double *unused, double *out_956096052628475437);
void car_H_30(double *state, double *unused, double *out_1100171478212330995);
void car_h_26(double *state, double *unused, double *out_1856456050641377946);
void car_H_26(double *state, double *unused, double *out_1886364489465882969);
void car_h_27(double *state, double *unused, double *out_6508227363792658049);
void car_H_27(double *state, double *unused, double *out_3323765549396274212);
void car_h_29(double *state, double *unused, double *out_3441856028653153575);
void car_H_29(double *state, double *unused, double *out_1610402822526723179);
void car_h_28(double *state, double *unused, double *out_8901730658472560882);
void car_H_28(double *state, double *unused, double *out_3471996194542807395);
void car_h_31(double *state, double *unused, double *out_6661649379971542033);
void car_H_31(double *state, double *unused, double *out_1260156387232531493);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}