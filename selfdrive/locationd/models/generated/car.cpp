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
void err_fun(double *nom_x, double *delta_x, double *out_5769240825907262247) {
   out_5769240825907262247[0] = delta_x[0] + nom_x[0];
   out_5769240825907262247[1] = delta_x[1] + nom_x[1];
   out_5769240825907262247[2] = delta_x[2] + nom_x[2];
   out_5769240825907262247[3] = delta_x[3] + nom_x[3];
   out_5769240825907262247[4] = delta_x[4] + nom_x[4];
   out_5769240825907262247[5] = delta_x[5] + nom_x[5];
   out_5769240825907262247[6] = delta_x[6] + nom_x[6];
   out_5769240825907262247[7] = delta_x[7] + nom_x[7];
   out_5769240825907262247[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2180470504006262414) {
   out_2180470504006262414[0] = -nom_x[0] + true_x[0];
   out_2180470504006262414[1] = -nom_x[1] + true_x[1];
   out_2180470504006262414[2] = -nom_x[2] + true_x[2];
   out_2180470504006262414[3] = -nom_x[3] + true_x[3];
   out_2180470504006262414[4] = -nom_x[4] + true_x[4];
   out_2180470504006262414[5] = -nom_x[5] + true_x[5];
   out_2180470504006262414[6] = -nom_x[6] + true_x[6];
   out_2180470504006262414[7] = -nom_x[7] + true_x[7];
   out_2180470504006262414[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_199921167776384783) {
   out_199921167776384783[0] = 1.0;
   out_199921167776384783[1] = 0.0;
   out_199921167776384783[2] = 0.0;
   out_199921167776384783[3] = 0.0;
   out_199921167776384783[4] = 0.0;
   out_199921167776384783[5] = 0.0;
   out_199921167776384783[6] = 0.0;
   out_199921167776384783[7] = 0.0;
   out_199921167776384783[8] = 0.0;
   out_199921167776384783[9] = 0.0;
   out_199921167776384783[10] = 1.0;
   out_199921167776384783[11] = 0.0;
   out_199921167776384783[12] = 0.0;
   out_199921167776384783[13] = 0.0;
   out_199921167776384783[14] = 0.0;
   out_199921167776384783[15] = 0.0;
   out_199921167776384783[16] = 0.0;
   out_199921167776384783[17] = 0.0;
   out_199921167776384783[18] = 0.0;
   out_199921167776384783[19] = 0.0;
   out_199921167776384783[20] = 1.0;
   out_199921167776384783[21] = 0.0;
   out_199921167776384783[22] = 0.0;
   out_199921167776384783[23] = 0.0;
   out_199921167776384783[24] = 0.0;
   out_199921167776384783[25] = 0.0;
   out_199921167776384783[26] = 0.0;
   out_199921167776384783[27] = 0.0;
   out_199921167776384783[28] = 0.0;
   out_199921167776384783[29] = 0.0;
   out_199921167776384783[30] = 1.0;
   out_199921167776384783[31] = 0.0;
   out_199921167776384783[32] = 0.0;
   out_199921167776384783[33] = 0.0;
   out_199921167776384783[34] = 0.0;
   out_199921167776384783[35] = 0.0;
   out_199921167776384783[36] = 0.0;
   out_199921167776384783[37] = 0.0;
   out_199921167776384783[38] = 0.0;
   out_199921167776384783[39] = 0.0;
   out_199921167776384783[40] = 1.0;
   out_199921167776384783[41] = 0.0;
   out_199921167776384783[42] = 0.0;
   out_199921167776384783[43] = 0.0;
   out_199921167776384783[44] = 0.0;
   out_199921167776384783[45] = 0.0;
   out_199921167776384783[46] = 0.0;
   out_199921167776384783[47] = 0.0;
   out_199921167776384783[48] = 0.0;
   out_199921167776384783[49] = 0.0;
   out_199921167776384783[50] = 1.0;
   out_199921167776384783[51] = 0.0;
   out_199921167776384783[52] = 0.0;
   out_199921167776384783[53] = 0.0;
   out_199921167776384783[54] = 0.0;
   out_199921167776384783[55] = 0.0;
   out_199921167776384783[56] = 0.0;
   out_199921167776384783[57] = 0.0;
   out_199921167776384783[58] = 0.0;
   out_199921167776384783[59] = 0.0;
   out_199921167776384783[60] = 1.0;
   out_199921167776384783[61] = 0.0;
   out_199921167776384783[62] = 0.0;
   out_199921167776384783[63] = 0.0;
   out_199921167776384783[64] = 0.0;
   out_199921167776384783[65] = 0.0;
   out_199921167776384783[66] = 0.0;
   out_199921167776384783[67] = 0.0;
   out_199921167776384783[68] = 0.0;
   out_199921167776384783[69] = 0.0;
   out_199921167776384783[70] = 1.0;
   out_199921167776384783[71] = 0.0;
   out_199921167776384783[72] = 0.0;
   out_199921167776384783[73] = 0.0;
   out_199921167776384783[74] = 0.0;
   out_199921167776384783[75] = 0.0;
   out_199921167776384783[76] = 0.0;
   out_199921167776384783[77] = 0.0;
   out_199921167776384783[78] = 0.0;
   out_199921167776384783[79] = 0.0;
   out_199921167776384783[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1042331506821406330) {
   out_1042331506821406330[0] = state[0];
   out_1042331506821406330[1] = state[1];
   out_1042331506821406330[2] = state[2];
   out_1042331506821406330[3] = state[3];
   out_1042331506821406330[4] = state[4];
   out_1042331506821406330[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1042331506821406330[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1042331506821406330[7] = state[7];
   out_1042331506821406330[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8550568359085178836) {
   out_8550568359085178836[0] = 1;
   out_8550568359085178836[1] = 0;
   out_8550568359085178836[2] = 0;
   out_8550568359085178836[3] = 0;
   out_8550568359085178836[4] = 0;
   out_8550568359085178836[5] = 0;
   out_8550568359085178836[6] = 0;
   out_8550568359085178836[7] = 0;
   out_8550568359085178836[8] = 0;
   out_8550568359085178836[9] = 0;
   out_8550568359085178836[10] = 1;
   out_8550568359085178836[11] = 0;
   out_8550568359085178836[12] = 0;
   out_8550568359085178836[13] = 0;
   out_8550568359085178836[14] = 0;
   out_8550568359085178836[15] = 0;
   out_8550568359085178836[16] = 0;
   out_8550568359085178836[17] = 0;
   out_8550568359085178836[18] = 0;
   out_8550568359085178836[19] = 0;
   out_8550568359085178836[20] = 1;
   out_8550568359085178836[21] = 0;
   out_8550568359085178836[22] = 0;
   out_8550568359085178836[23] = 0;
   out_8550568359085178836[24] = 0;
   out_8550568359085178836[25] = 0;
   out_8550568359085178836[26] = 0;
   out_8550568359085178836[27] = 0;
   out_8550568359085178836[28] = 0;
   out_8550568359085178836[29] = 0;
   out_8550568359085178836[30] = 1;
   out_8550568359085178836[31] = 0;
   out_8550568359085178836[32] = 0;
   out_8550568359085178836[33] = 0;
   out_8550568359085178836[34] = 0;
   out_8550568359085178836[35] = 0;
   out_8550568359085178836[36] = 0;
   out_8550568359085178836[37] = 0;
   out_8550568359085178836[38] = 0;
   out_8550568359085178836[39] = 0;
   out_8550568359085178836[40] = 1;
   out_8550568359085178836[41] = 0;
   out_8550568359085178836[42] = 0;
   out_8550568359085178836[43] = 0;
   out_8550568359085178836[44] = 0;
   out_8550568359085178836[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8550568359085178836[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8550568359085178836[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8550568359085178836[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8550568359085178836[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8550568359085178836[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8550568359085178836[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8550568359085178836[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8550568359085178836[53] = -9.8100000000000005*dt;
   out_8550568359085178836[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8550568359085178836[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8550568359085178836[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8550568359085178836[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8550568359085178836[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8550568359085178836[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8550568359085178836[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8550568359085178836[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8550568359085178836[62] = 0;
   out_8550568359085178836[63] = 0;
   out_8550568359085178836[64] = 0;
   out_8550568359085178836[65] = 0;
   out_8550568359085178836[66] = 0;
   out_8550568359085178836[67] = 0;
   out_8550568359085178836[68] = 0;
   out_8550568359085178836[69] = 0;
   out_8550568359085178836[70] = 1;
   out_8550568359085178836[71] = 0;
   out_8550568359085178836[72] = 0;
   out_8550568359085178836[73] = 0;
   out_8550568359085178836[74] = 0;
   out_8550568359085178836[75] = 0;
   out_8550568359085178836[76] = 0;
   out_8550568359085178836[77] = 0;
   out_8550568359085178836[78] = 0;
   out_8550568359085178836[79] = 0;
   out_8550568359085178836[80] = 1;
}
void h_25(double *state, double *unused, double *out_5837605696441742449) {
   out_5837605696441742449[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8993267058135852454) {
   out_8993267058135852454[0] = 0;
   out_8993267058135852454[1] = 0;
   out_8993267058135852454[2] = 0;
   out_8993267058135852454[3] = 0;
   out_8993267058135852454[4] = 0;
   out_8993267058135852454[5] = 0;
   out_8993267058135852454[6] = 1;
   out_8993267058135852454[7] = 0;
   out_8993267058135852454[8] = 0;
}
void h_24(double *state, double *unused, double *out_5044076517459918856) {
   out_5044076517459918856[0] = state[4];
   out_5044076517459918856[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7280827416568199596) {
   out_7280827416568199596[0] = 0;
   out_7280827416568199596[1] = 0;
   out_7280827416568199596[2] = 0;
   out_7280827416568199596[3] = 0;
   out_7280827416568199596[4] = 1;
   out_7280827416568199596[5] = 0;
   out_7280827416568199596[6] = 0;
   out_7280827416568199596[7] = 0;
   out_7280827416568199596[8] = 0;
   out_7280827416568199596[9] = 0;
   out_7280827416568199596[10] = 0;
   out_7280827416568199596[11] = 0;
   out_7280827416568199596[12] = 0;
   out_7280827416568199596[13] = 0;
   out_7280827416568199596[14] = 1;
   out_7280827416568199596[15] = 0;
   out_7280827416568199596[16] = 0;
   out_7280827416568199596[17] = 0;
}
void h_30(double *state, double *unused, double *out_5983125520662397420) {
   out_5983125520662397420[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2076576716644235699) {
   out_2076576716644235699[0] = 0;
   out_2076576716644235699[1] = 0;
   out_2076576716644235699[2] = 0;
   out_2076576716644235699[3] = 0;
   out_2076576716644235699[4] = 1;
   out_2076576716644235699[5] = 0;
   out_2076576716644235699[6] = 0;
   out_2076576716644235699[7] = 0;
   out_2076576716644235699[8] = 0;
}
void h_26(double *state, double *unused, double *out_234514271167533250) {
   out_234514271167533250[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5688741088375051853) {
   out_5688741088375051853[0] = 0;
   out_5688741088375051853[1] = 0;
   out_5688741088375051853[2] = 0;
   out_5688741088375051853[3] = 0;
   out_5688741088375051853[4] = 0;
   out_5688741088375051853[5] = 0;
   out_5688741088375051853[6] = 0;
   out_5688741088375051853[7] = 1;
   out_5688741088375051853[8] = 0;
}
void h_27(double *state, double *unused, double *out_7383231161432484220) {
   out_7383231161432484220[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4251340028444660610) {
   out_4251340028444660610[0] = 0;
   out_4251340028444660610[1] = 0;
   out_4251340028444660610[2] = 0;
   out_4251340028444660610[3] = 1;
   out_4251340028444660610[4] = 0;
   out_4251340028444660610[5] = 0;
   out_4251340028444660610[6] = 0;
   out_4251340028444660610[7] = 0;
   out_4251340028444660610[8] = 0;
}
void h_29(double *state, double *unused, double *out_7461945285386308551) {
   out_7461945285386308551[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5964702755314211643) {
   out_5964702755314211643[0] = 0;
   out_5964702755314211643[1] = 1;
   out_5964702755314211643[2] = 0;
   out_5964702755314211643[3] = 0;
   out_5964702755314211643[4] = 0;
   out_5964702755314211643[5] = 0;
   out_5964702755314211643[6] = 0;
   out_5964702755314211643[7] = 0;
   out_5964702755314211643[8] = 0;
}
void h_28(double *state, double *unused, double *out_2381557893771638575) {
   out_2381557893771638575[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7399642301325809399) {
   out_7399642301325809399[0] = 1;
   out_7399642301325809399[1] = 0;
   out_7399642301325809399[2] = 0;
   out_7399642301325809399[3] = 0;
   out_7399642301325809399[4] = 0;
   out_7399642301325809399[5] = 0;
   out_7399642301325809399[6] = 0;
   out_7399642301325809399[7] = 0;
   out_7399642301325809399[8] = 0;
}
void h_31(double *state, double *unused, double *out_4845873120447136726) {
   out_4845873120447136726[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8962621096258892026) {
   out_8962621096258892026[0] = 0;
   out_8962621096258892026[1] = 0;
   out_8962621096258892026[2] = 0;
   out_8962621096258892026[3] = 0;
   out_8962621096258892026[4] = 0;
   out_8962621096258892026[5] = 0;
   out_8962621096258892026[6] = 0;
   out_8962621096258892026[7] = 0;
   out_8962621096258892026[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5769240825907262247) {
  err_fun(nom_x, delta_x, out_5769240825907262247);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2180470504006262414) {
  inv_err_fun(nom_x, true_x, out_2180470504006262414);
}
void car_H_mod_fun(double *state, double *out_199921167776384783) {
  H_mod_fun(state, out_199921167776384783);
}
void car_f_fun(double *state, double dt, double *out_1042331506821406330) {
  f_fun(state,  dt, out_1042331506821406330);
}
void car_F_fun(double *state, double dt, double *out_8550568359085178836) {
  F_fun(state,  dt, out_8550568359085178836);
}
void car_h_25(double *state, double *unused, double *out_5837605696441742449) {
  h_25(state, unused, out_5837605696441742449);
}
void car_H_25(double *state, double *unused, double *out_8993267058135852454) {
  H_25(state, unused, out_8993267058135852454);
}
void car_h_24(double *state, double *unused, double *out_5044076517459918856) {
  h_24(state, unused, out_5044076517459918856);
}
void car_H_24(double *state, double *unused, double *out_7280827416568199596) {
  H_24(state, unused, out_7280827416568199596);
}
void car_h_30(double *state, double *unused, double *out_5983125520662397420) {
  h_30(state, unused, out_5983125520662397420);
}
void car_H_30(double *state, double *unused, double *out_2076576716644235699) {
  H_30(state, unused, out_2076576716644235699);
}
void car_h_26(double *state, double *unused, double *out_234514271167533250) {
  h_26(state, unused, out_234514271167533250);
}
void car_H_26(double *state, double *unused, double *out_5688741088375051853) {
  H_26(state, unused, out_5688741088375051853);
}
void car_h_27(double *state, double *unused, double *out_7383231161432484220) {
  h_27(state, unused, out_7383231161432484220);
}
void car_H_27(double *state, double *unused, double *out_4251340028444660610) {
  H_27(state, unused, out_4251340028444660610);
}
void car_h_29(double *state, double *unused, double *out_7461945285386308551) {
  h_29(state, unused, out_7461945285386308551);
}
void car_H_29(double *state, double *unused, double *out_5964702755314211643) {
  H_29(state, unused, out_5964702755314211643);
}
void car_h_28(double *state, double *unused, double *out_2381557893771638575) {
  h_28(state, unused, out_2381557893771638575);
}
void car_H_28(double *state, double *unused, double *out_7399642301325809399) {
  H_28(state, unused, out_7399642301325809399);
}
void car_h_31(double *state, double *unused, double *out_4845873120447136726) {
  h_31(state, unused, out_4845873120447136726);
}
void car_H_31(double *state, double *unused, double *out_8962621096258892026) {
  H_31(state, unused, out_8962621096258892026);
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
