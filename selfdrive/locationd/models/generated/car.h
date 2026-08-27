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
void car_err_fun(double *nom_x, double *delta_x, double *out_6663383586198040946);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8588337980518277825);
void car_H_mod_fun(double *state, double *out_6555656847717771558);
void car_f_fun(double *state, double dt, double *out_7137582187284124708);
void car_F_fun(double *state, double dt, double *out_2957883628728215032);
void car_h_25(double *state, double *unused, double *out_753214482939102632);
void car_H_25(double *state, double *unused, double *out_58633887827741607);
void car_h_24(double *state, double *unused, double *out_163608178505822735);
void car_H_24(double *state, double *unused, double *out_6142398792023419819);
void car_h_30(double *state, double *unused, double *out_596027814587973487);
void car_H_30(double *state, double *unused, double *out_70705059315498463);
void car_h_26(double *state, double *unused, double *out_6995069332001822633);
void car_H_26(double *state, double *unused, double *out_3682869431046314617);
void car_h_27(double *state, double *unused, double *out_8228754689067738133);
void car_H_27(double *state, double *unused, double *out_2245468371115923374);
void car_h_29(double *state, double *unused, double *out_347482038313688948);
void car_H_29(double *state, double *unused, double *out_3958831097985474407);
void car_h_28(double *state, double *unused, double *out_7625438804391260616);
void car_H_28(double *state, double *unused, double *out_9041230115055004981);
void car_h_31(double *state, double *unused, double *out_5467162699907911337);
void car_H_31(double *state, double *unused, double *out_89279849704702035);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}