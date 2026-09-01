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
void car_err_fun(double *nom_x, double *delta_x, double *out_1090979798261761109);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5039703447688746133);
void car_H_mod_fun(double *state, double *out_3925450346960244372);
void car_f_fun(double *state, double dt, double *out_5857249667330785024);
void car_F_fun(double *state, double dt, double *out_9115802330220690696);
void car_h_25(double *state, double *unused, double *out_5135803252423599804);
void car_H_25(double *state, double *unused, double *out_5267737878951992865);
void car_h_24(double *state, double *unused, double *out_511115109570268580);
void car_H_24(double *state, double *unused, double *out_8432496867791049717);
void car_h_30(double *state, double *unused, double *out_5547675564465279371);
void car_H_30(double *state, double *unused, double *out_1648952462539623890);
void car_h_26(double *state, double *unused, double *out_8360227667735132754);
void car_H_26(double *state, double *unused, double *out_9009241197826049089);
void car_h_27(double *state, double *unused, double *out_742482235135115284);
void car_H_27(double *state, double *unused, double *out_525810849260801021);
void car_h_29(double *state, double *unused, double *out_7897395241583426600);
void car_H_29(double *state, double *unused, double *out_2239173576130352054);
void car_h_28(double *state, double *unused, double *out_2070069868134738099);
void car_H_28(double *state, double *unused, double *out_7321572593199882628);
void car_h_31(double *state, double *unused, double *out_5281323076644254775);
void car_H_31(double *state, double *unused, double *out_5237091917075032437);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}