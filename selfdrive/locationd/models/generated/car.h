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
void car_err_fun(double *nom_x, double *delta_x, double *out_7775273935163259771);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7144320503723657844);
void car_H_mod_fun(double *state, double *out_5290264847807647293);
void car_f_fun(double *state, double dt, double *out_6558018291433416815);
void car_F_fun(double *state, double dt, double *out_7302370609560386304);
void car_h_25(double *state, double *unused, double *out_3941798905160139655);
void car_H_25(double *state, double *unused, double *out_1767216209162282145);
void car_h_24(double *state, double *unused, double *out_3290253106094290464);
void car_H_24(double *state, double *unused, double *out_2751282080003595813);
void car_h_30(double *state, double *unused, double *out_198122822665014747);
void car_H_30(double *state, double *unused, double *out_8683906550653898900);
void car_h_26(double *state, double *unused, double *out_4803550444995830898);
void car_H_26(double *state, double *unused, double *out_5071742178923082746);
void car_h_27(double *state, double *unused, double *out_2457242612253709491);
void car_H_27(double *state, double *unused, double *out_6509143238853473989);
void car_h_29(double *state, double *unused, double *out_8786285504469856155);
void car_H_29(double *state, double *unused, double *out_9194137894968291084);
void car_h_28(double *state, double *unused, double *out_1853926727577231974);
void car_H_28(double *state, double *unused, double *out_4111738877898760510);
void car_h_31(double *state, double *unused, double *out_8040102203439511519);
void car_H_31(double *state, double *unused, double *out_1797862171039242573);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}