#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1090979798261761109) {
   out_1090979798261761109[0] = delta_x[0] + nom_x[0];
   out_1090979798261761109[1] = delta_x[1] + nom_x[1];
   out_1090979798261761109[2] = delta_x[2] + nom_x[2];
   out_1090979798261761109[3] = delta_x[3] + nom_x[3];
   out_1090979798261761109[4] = delta_x[4] + nom_x[4];
   out_1090979798261761109[5] = delta_x[5] + nom_x[5];
   out_1090979798261761109[6] = delta_x[6] + nom_x[6];
   out_1090979798261761109[7] = delta_x[7] + nom_x[7];
   out_1090979798261761109[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5039703447688746133) {
   out_5039703447688746133[0] = -nom_x[0] + true_x[0];
   out_5039703447688746133[1] = -nom_x[1] + true_x[1];
   out_5039703447688746133[2] = -nom_x[2] + true_x[2];
   out_5039703447688746133[3] = -nom_x[3] + true_x[3];
   out_5039703447688746133[4] = -nom_x[4] + true_x[4];
   out_5039703447688746133[5] = -nom_x[5] + true_x[5];
   out_5039703447688746133[6] = -nom_x[6] + true_x[6];
   out_5039703447688746133[7] = -nom_x[7] + true_x[7];
   out_5039703447688746133[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3925450346960244372) {
   out_3925450346960244372[0] = 1.0;
   out_3925450346960244372[1] = 0.0;
   out_3925450346960244372[2] = 0.0;
   out_3925450346960244372[3] = 0.0;
   out_3925450346960244372[4] = 0.0;
   out_3925450346960244372[5] = 0.0;
   out_3925450346960244372[6] = 0.0;
   out_3925450346960244372[7] = 0.0;
   out_3925450346960244372[8] = 0.0;
   out_3925450346960244372[9] = 0.0;
   out_3925450346960244372[10] = 1.0;
   out_3925450346960244372[11] = 0.0;
   out_3925450346960244372[12] = 0.0;
   out_3925450346960244372[13] = 0.0;
   out_3925450346960244372[14] = 0.0;
   out_3925450346960244372[15] = 0.0;
   out_3925450346960244372[16] = 0.0;
   out_3925450346960244372[17] = 0.0;
   out_3925450346960244372[18] = 0.0;
   out_3925450346960244372[19] = 0.0;
   out_3925450346960244372[20] = 1.0;
   out_3925450346960244372[21] = 0.0;
   out_3925450346960244372[22] = 0.0;
   out_3925450346960244372[23] = 0.0;
   out_3925450346960244372[24] = 0.0;
   out_3925450346960244372[25] = 0.0;
   out_3925450346960244372[26] = 0.0;
   out_3925450346960244372[27] = 0.0;
   out_3925450346960244372[28] = 0.0;
   out_3925450346960244372[29] = 0.0;
   out_3925450346960244372[30] = 1.0;
   out_3925450346960244372[31] = 0.0;
   out_3925450346960244372[32] = 0.0;
   out_3925450346960244372[33] = 0.0;
   out_3925450346960244372[34] = 0.0;
   out_3925450346960244372[35] = 0.0;
   out_3925450346960244372[36] = 0.0;
   out_3925450346960244372[37] = 0.0;
   out_3925450346960244372[38] = 0.0;
   out_3925450346960244372[39] = 0.0;
   out_3925450346960244372[40] = 1.0;
   out_3925450346960244372[41] = 0.0;
   out_3925450346960244372[42] = 0.0;
   out_3925450346960244372[43] = 0.0;
   out_3925450346960244372[44] = 0.0;
   out_3925450346960244372[45] = 0.0;
   out_3925450346960244372[46] = 0.0;
   out_3925450346960244372[47] = 0.0;
   out_3925450346960244372[48] = 0.0;
   out_3925450346960244372[49] = 0.0;
   out_3925450346960244372[50] = 1.0;
   out_3925450346960244372[51] = 0.0;
   out_3925450346960244372[52] = 0.0;
   out_3925450346960244372[53] = 0.0;
   out_3925450346960244372[54] = 0.0;
   out_3925450346960244372[55] = 0.0;
   out_3925450346960244372[56] = 0.0;
   out_3925450346960244372[57] = 0.0;
   out_3925450346960244372[58] = 0.0;
   out_3925450346960244372[59] = 0.0;
   out_3925450346960244372[60] = 1.0;
   out_3925450346960244372[61] = 0.0;
   out_3925450346960244372[62] = 0.0;
   out_3925450346960244372[63] = 0.0;
   out_3925450346960244372[64] = 0.0;
   out_3925450346960244372[65] = 0.0;
   out_3925450346960244372[66] = 0.0;
   out_3925450346960244372[67] = 0.0;
   out_3925450346960244372[68] = 0.0;
   out_3925450346960244372[69] = 0.0;
   out_3925450346960244372[70] = 1.0;
   out_3925450346960244372[71] = 0.0;
   out_3925450346960244372[72] = 0.0;
   out_3925450346960244372[73] = 0.0;
   out_3925450346960244372[74] = 0.0;
   out_3925450346960244372[75] = 0.0;
   out_3925450346960244372[76] = 0.0;
   out_3925450346960244372[77] = 0.0;
   out_3925450346960244372[78] = 0.0;
   out_3925450346960244372[79] = 0.0;
   out_3925450346960244372[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5857249667330785024) {
   out_5857249667330785024[0] = state[0];
   out_5857249667330785024[1] = state[1];
   out_5857249667330785024[2] = state[2];
   out_5857249667330785024[3] = state[3];
   out_5857249667330785024[4] = state[4];
   out_5857249667330785024[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5857249667330785024[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5857249667330785024[7] = state[7];
   out_5857249667330785024[8] = state[8];
}
void F_fun(double *state, double dt, double *out_9115802330220690696) {
   out_9115802330220690696[0] = 1;
   out_9115802330220690696[1] = 0;
   out_9115802330220690696[2] = 0;
   out_9115802330220690696[3] = 0;
   out_9115802330220690696[4] = 0;
   out_9115802330220690696[5] = 0;
   out_9115802330220690696[6] = 0;
   out_9115802330220690696[7] = 0;
   out_9115802330220690696[8] = 0;
   out_9115802330220690696[9] = 0;
   out_9115802330220690696[10] = 1;
   out_9115802330220690696[11] = 0;
   out_9115802330220690696[12] = 0;
   out_9115802330220690696[13] = 0;
   out_9115802330220690696[14] = 0;
   out_9115802330220690696[15] = 0;
   out_9115802330220690696[16] = 0;
   out_9115802330220690696[17] = 0;
   out_9115802330220690696[18] = 0;
   out_9115802330220690696[19] = 0;
   out_9115802330220690696[20] = 1;
   out_9115802330220690696[21] = 0;
   out_9115802330220690696[22] = 0;
   out_9115802330220690696[23] = 0;
   out_9115802330220690696[24] = 0;
   out_9115802330220690696[25] = 0;
   out_9115802330220690696[26] = 0;
   out_9115802330220690696[27] = 0;
   out_9115802330220690696[28] = 0;
   out_9115802330220690696[29] = 0;
   out_9115802330220690696[30] = 1;
   out_9115802330220690696[31] = 0;
   out_9115802330220690696[32] = 0;
   out_9115802330220690696[33] = 0;
   out_9115802330220690696[34] = 0;
   out_9115802330220690696[35] = 0;
   out_9115802330220690696[36] = 0;
   out_9115802330220690696[37] = 0;
   out_9115802330220690696[38] = 0;
   out_9115802330220690696[39] = 0;
   out_9115802330220690696[40] = 1;
   out_9115802330220690696[41] = 0;
   out_9115802330220690696[42] = 0;
   out_9115802330220690696[43] = 0;
   out_9115802330220690696[44] = 0;
   out_9115802330220690696[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_9115802330220690696[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_9115802330220690696[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9115802330220690696[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9115802330220690696[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_9115802330220690696[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_9115802330220690696[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_9115802330220690696[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_9115802330220690696[53] = -9.8100000000000005*dt;
   out_9115802330220690696[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_9115802330220690696[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_9115802330220690696[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9115802330220690696[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9115802330220690696[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_9115802330220690696[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_9115802330220690696[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_9115802330220690696[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9115802330220690696[62] = 0;
   out_9115802330220690696[63] = 0;
   out_9115802330220690696[64] = 0;
   out_9115802330220690696[65] = 0;
   out_9115802330220690696[66] = 0;
   out_9115802330220690696[67] = 0;
   out_9115802330220690696[68] = 0;
   out_9115802330220690696[69] = 0;
   out_9115802330220690696[70] = 1;
   out_9115802330220690696[71] = 0;
   out_9115802330220690696[72] = 0;
   out_9115802330220690696[73] = 0;
   out_9115802330220690696[74] = 0;
   out_9115802330220690696[75] = 0;
   out_9115802330220690696[76] = 0;
   out_9115802330220690696[77] = 0;
   out_9115802330220690696[78] = 0;
   out_9115802330220690696[79] = 0;
   out_9115802330220690696[80] = 1;
}
void h_25(double *state, double *unused, double *out_5135803252423599804) {
   out_5135803252423599804[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5267737878951992865) {
   out_5267737878951992865[0] = 0;
   out_5267737878951992865[1] = 0;
   out_5267737878951992865[2] = 0;
   out_5267737878951992865[3] = 0;
   out_5267737878951992865[4] = 0;
   out_5267737878951992865[5] = 0;
   out_5267737878951992865[6] = 1;
   out_5267737878951992865[7] = 0;
   out_5267737878951992865[8] = 0;
}
void h_24(double *state, double *unused, double *out_511115109570268580) {
   out_511115109570268580[0] = state[4];
   out_511115109570268580[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8432496867791049717) {
   out_8432496867791049717[0] = 0;
   out_8432496867791049717[1] = 0;
   out_8432496867791049717[2] = 0;
   out_8432496867791049717[3] = 0;
   out_8432496867791049717[4] = 1;
   out_8432496867791049717[5] = 0;
   out_8432496867791049717[6] = 0;
   out_8432496867791049717[7] = 0;
   out_8432496867791049717[8] = 0;
   out_8432496867791049717[9] = 0;
   out_8432496867791049717[10] = 0;
   out_8432496867791049717[11] = 0;
   out_8432496867791049717[12] = 0;
   out_8432496867791049717[13] = 0;
   out_8432496867791049717[14] = 1;
   out_8432496867791049717[15] = 0;
   out_8432496867791049717[16] = 0;
   out_8432496867791049717[17] = 0;
}
void h_30(double *state, double *unused, double *out_5547675564465279371) {
   out_5547675564465279371[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1648952462539623890) {
   out_1648952462539623890[0] = 0;
   out_1648952462539623890[1] = 0;
   out_1648952462539623890[2] = 0;
   out_1648952462539623890[3] = 0;
   out_1648952462539623890[4] = 1;
   out_1648952462539623890[5] = 0;
   out_1648952462539623890[6] = 0;
   out_1648952462539623890[7] = 0;
   out_1648952462539623890[8] = 0;
}
void h_26(double *state, double *unused, double *out_8360227667735132754) {
   out_8360227667735132754[0] = state[7];
}
void H_26(double *state, double *unused, double *out_9009241197826049089) {
   out_9009241197826049089[0] = 0;
   out_9009241197826049089[1] = 0;
   out_9009241197826049089[2] = 0;
   out_9009241197826049089[3] = 0;
   out_9009241197826049089[4] = 0;
   out_9009241197826049089[5] = 0;
   out_9009241197826049089[6] = 0;
   out_9009241197826049089[7] = 1;
   out_9009241197826049089[8] = 0;
}
void h_27(double *state, double *unused, double *out_742482235135115284) {
   out_742482235135115284[0] = state[3];
}
void H_27(double *state, double *unused, double *out_525810849260801021) {
   out_525810849260801021[0] = 0;
   out_525810849260801021[1] = 0;
   out_525810849260801021[2] = 0;
   out_525810849260801021[3] = 1;
   out_525810849260801021[4] = 0;
   out_525810849260801021[5] = 0;
   out_525810849260801021[6] = 0;
   out_525810849260801021[7] = 0;
   out_525810849260801021[8] = 0;
}
void h_29(double *state, double *unused, double *out_7897395241583426600) {
   out_7897395241583426600[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2239173576130352054) {
   out_2239173576130352054[0] = 0;
   out_2239173576130352054[1] = 1;
   out_2239173576130352054[2] = 0;
   out_2239173576130352054[3] = 0;
   out_2239173576130352054[4] = 0;
   out_2239173576130352054[5] = 0;
   out_2239173576130352054[6] = 0;
   out_2239173576130352054[7] = 0;
   out_2239173576130352054[8] = 0;
}
void h_28(double *state, double *unused, double *out_2070069868134738099) {
   out_2070069868134738099[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7321572593199882628) {
   out_7321572593199882628[0] = 1;
   out_7321572593199882628[1] = 0;
   out_7321572593199882628[2] = 0;
   out_7321572593199882628[3] = 0;
   out_7321572593199882628[4] = 0;
   out_7321572593199882628[5] = 0;
   out_7321572593199882628[6] = 0;
   out_7321572593199882628[7] = 0;
   out_7321572593199882628[8] = 0;
}
void h_31(double *state, double *unused, double *out_5281323076644254775) {
   out_5281323076644254775[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5237091917075032437) {
   out_5237091917075032437[0] = 0;
   out_5237091917075032437[1] = 0;
   out_5237091917075032437[2] = 0;
   out_5237091917075032437[3] = 0;
   out_5237091917075032437[4] = 0;
   out_5237091917075032437[5] = 0;
   out_5237091917075032437[6] = 0;
   out_5237091917075032437[7] = 0;
   out_5237091917075032437[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1090979798261761109) {
  err_fun(nom_x, delta_x, out_1090979798261761109);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5039703447688746133) {
  inv_err_fun(nom_x, true_x, out_5039703447688746133);
}
void car_H_mod_fun(double *state, double *out_3925450346960244372) {
  H_mod_fun(state, out_3925450346960244372);
}
void car_f_fun(double *state, double dt, double *out_5857249667330785024) {
  f_fun(state,  dt, out_5857249667330785024);
}
void car_F_fun(double *state, double dt, double *out_9115802330220690696) {
  F_fun(state,  dt, out_9115802330220690696);
}
void car_h_25(double *state, double *unused, double *out_5135803252423599804) {
  h_25(state, unused, out_5135803252423599804);
}
void car_H_25(double *state, double *unused, double *out_5267737878951992865) {
  H_25(state, unused, out_5267737878951992865);
}
void car_h_24(double *state, double *unused, double *out_511115109570268580) {
  h_24(state, unused, out_511115109570268580);
}
void car_H_24(double *state, double *unused, double *out_8432496867791049717) {
  H_24(state, unused, out_8432496867791049717);
}
void car_h_30(double *state, double *unused, double *out_5547675564465279371) {
  h_30(state, unused, out_5547675564465279371);
}
void car_H_30(double *state, double *unused, double *out_1648952462539623890) {
  H_30(state, unused, out_1648952462539623890);
}
void car_h_26(double *state, double *unused, double *out_8360227667735132754) {
  h_26(state, unused, out_8360227667735132754);
}
void car_H_26(double *state, double *unused, double *out_9009241197826049089) {
  H_26(state, unused, out_9009241197826049089);
}
void car_h_27(double *state, double *unused, double *out_742482235135115284) {
  h_27(state, unused, out_742482235135115284);
}
void car_H_27(double *state, double *unused, double *out_525810849260801021) {
  H_27(state, unused, out_525810849260801021);
}
void car_h_29(double *state, double *unused, double *out_7897395241583426600) {
  h_29(state, unused, out_7897395241583426600);
}
void car_H_29(double *state, double *unused, double *out_2239173576130352054) {
  H_29(state, unused, out_2239173576130352054);
}
void car_h_28(double *state, double *unused, double *out_2070069868134738099) {
  h_28(state, unused, out_2070069868134738099);
}
void car_H_28(double *state, double *unused, double *out_7321572593199882628) {
  H_28(state, unused, out_7321572593199882628);
}
void car_h_31(double *state, double *unused, double *out_5281323076644254775) {
  h_31(state, unused, out_5281323076644254775);
}
void car_H_31(double *state, double *unused, double *out_5237091917075032437) {
  H_31(state, unused, out_5237091917075032437);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
