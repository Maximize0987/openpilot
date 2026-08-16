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
void car_err_fun(double *nom_x, double *delta_x, double *out_3975331509919415286);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7634853030167298340);
void car_H_mod_fun(double *state, double *out_5558041618437033789);
void car_f_fun(double *state, double dt, double *out_8628820520711137836);
void car_F_fun(double *state, double dt, double *out_937688393817481927);
void car_h_25(double *state, double *unused, double *out_4714258583115160121);
void car_H_25(double *state, double *unused, double *out_3228209521213378417);
void car_h_24(double *state, double *unused, double *out_8700237868881615564);
void car_H_24(double *state, double *unused, double *out_8097024386241085269);
void car_h_30(double *state, double *unused, double *out_4557071914764030976);
void car_H_30(double *state, double *unused, double *out_7755905851340986615);
void car_h_26(double *state, double *unused, double *out_7593857966208363661);
void car_H_26(double *state, double *unused, double *out_6969712840087434641);
void car_h_27(double *state, double *unused, double *out_8506578274759066548);
void car_H_27(double *state, double *unused, double *out_5532311780157043398);
void car_h_29(double *state, double *unused, double *out_4869128746505044198);
void car_H_29(double *state, double *unused, double *out_7245674507026594431);
void car_h_28(double *state, double *unused, double *out_3664394704215203127);
void car_H_28(double *state, double *unused, double *out_5282044235461268180);
void car_h_31(double *state, double *unused, double *out_6047692778171023868);
void car_H_31(double *state, double *unused, double *out_7595920942320786117);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}