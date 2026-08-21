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
void err_fun(double *nom_x, double *delta_x, double *out_943833552876303288) {
   out_943833552876303288[0] = delta_x[0] + nom_x[0];
   out_943833552876303288[1] = delta_x[1] + nom_x[1];
   out_943833552876303288[2] = delta_x[2] + nom_x[2];
   out_943833552876303288[3] = delta_x[3] + nom_x[3];
   out_943833552876303288[4] = delta_x[4] + nom_x[4];
   out_943833552876303288[5] = delta_x[5] + nom_x[5];
   out_943833552876303288[6] = delta_x[6] + nom_x[6];
   out_943833552876303288[7] = delta_x[7] + nom_x[7];
   out_943833552876303288[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_528301401300769025) {
   out_528301401300769025[0] = -nom_x[0] + true_x[0];
   out_528301401300769025[1] = -nom_x[1] + true_x[1];
   out_528301401300769025[2] = -nom_x[2] + true_x[2];
   out_528301401300769025[3] = -nom_x[3] + true_x[3];
   out_528301401300769025[4] = -nom_x[4] + true_x[4];
   out_528301401300769025[5] = -nom_x[5] + true_x[5];
   out_528301401300769025[6] = -nom_x[6] + true_x[6];
   out_528301401300769025[7] = -nom_x[7] + true_x[7];
   out_528301401300769025[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7538255523593818631) {
   out_7538255523593818631[0] = 1.0;
   out_7538255523593818631[1] = 0.0;
   out_7538255523593818631[2] = 0.0;
   out_7538255523593818631[3] = 0.0;
   out_7538255523593818631[4] = 0.0;
   out_7538255523593818631[5] = 0.0;
   out_7538255523593818631[6] = 0.0;
   out_7538255523593818631[7] = 0.0;
   out_7538255523593818631[8] = 0.0;
   out_7538255523593818631[9] = 0.0;
   out_7538255523593818631[10] = 1.0;
   out_7538255523593818631[11] = 0.0;
   out_7538255523593818631[12] = 0.0;
   out_7538255523593818631[13] = 0.0;
   out_7538255523593818631[14] = 0.0;
   out_7538255523593818631[15] = 0.0;
   out_7538255523593818631[16] = 0.0;
   out_7538255523593818631[17] = 0.0;
   out_7538255523593818631[18] = 0.0;
   out_7538255523593818631[19] = 0.0;
   out_7538255523593818631[20] = 1.0;
   out_7538255523593818631[21] = 0.0;
   out_7538255523593818631[22] = 0.0;
   out_7538255523593818631[23] = 0.0;
   out_7538255523593818631[24] = 0.0;
   out_7538255523593818631[25] = 0.0;
   out_7538255523593818631[26] = 0.0;
   out_7538255523593818631[27] = 0.0;
   out_7538255523593818631[28] = 0.0;
   out_7538255523593818631[29] = 0.0;
   out_7538255523593818631[30] = 1.0;
   out_7538255523593818631[31] = 0.0;
   out_7538255523593818631[32] = 0.0;
   out_7538255523593818631[33] = 0.0;
   out_7538255523593818631[34] = 0.0;
   out_7538255523593818631[35] = 0.0;
   out_7538255523593818631[36] = 0.0;
   out_7538255523593818631[37] = 0.0;
   out_7538255523593818631[38] = 0.0;
   out_7538255523593818631[39] = 0.0;
   out_7538255523593818631[40] = 1.0;
   out_7538255523593818631[41] = 0.0;
   out_7538255523593818631[42] = 0.0;
   out_7538255523593818631[43] = 0.0;
   out_7538255523593818631[44] = 0.0;
   out_7538255523593818631[45] = 0.0;
   out_7538255523593818631[46] = 0.0;
   out_7538255523593818631[47] = 0.0;
   out_7538255523593818631[48] = 0.0;
   out_7538255523593818631[49] = 0.0;
   out_7538255523593818631[50] = 1.0;
   out_7538255523593818631[51] = 0.0;
   out_7538255523593818631[52] = 0.0;
   out_7538255523593818631[53] = 0.0;
   out_7538255523593818631[54] = 0.0;
   out_7538255523593818631[55] = 0.0;
   out_7538255523593818631[56] = 0.0;
   out_7538255523593818631[57] = 0.0;
   out_7538255523593818631[58] = 0.0;
   out_7538255523593818631[59] = 0.0;
   out_7538255523593818631[60] = 1.0;
   out_7538255523593818631[61] = 0.0;
   out_7538255523593818631[62] = 0.0;
   out_7538255523593818631[63] = 0.0;
   out_7538255523593818631[64] = 0.0;
   out_7538255523593818631[65] = 0.0;
   out_7538255523593818631[66] = 0.0;
   out_7538255523593818631[67] = 0.0;
   out_7538255523593818631[68] = 0.0;
   out_7538255523593818631[69] = 0.0;
   out_7538255523593818631[70] = 1.0;
   out_7538255523593818631[71] = 0.0;
   out_7538255523593818631[72] = 0.0;
   out_7538255523593818631[73] = 0.0;
   out_7538255523593818631[74] = 0.0;
   out_7538255523593818631[75] = 0.0;
   out_7538255523593818631[76] = 0.0;
   out_7538255523593818631[77] = 0.0;
   out_7538255523593818631[78] = 0.0;
   out_7538255523593818631[79] = 0.0;
   out_7538255523593818631[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3917173406968738478) {
   out_3917173406968738478[0] = state[0];
   out_3917173406968738478[1] = state[1];
   out_3917173406968738478[2] = state[2];
   out_3917173406968738478[3] = state[3];
   out_3917173406968738478[4] = state[4];
   out_3917173406968738478[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3917173406968738478[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3917173406968738478[7] = state[7];
   out_3917173406968738478[8] = state[8];
}
void F_fun(double *state, double dt, double *out_547656323515283001) {
   out_547656323515283001[0] = 1;
   out_547656323515283001[1] = 0;
   out_547656323515283001[2] = 0;
   out_547656323515283001[3] = 0;
   out_547656323515283001[4] = 0;
   out_547656323515283001[5] = 0;
   out_547656323515283001[6] = 0;
   out_547656323515283001[7] = 0;
   out_547656323515283001[8] = 0;
   out_547656323515283001[9] = 0;
   out_547656323515283001[10] = 1;
   out_547656323515283001[11] = 0;
   out_547656323515283001[12] = 0;
   out_547656323515283001[13] = 0;
   out_547656323515283001[14] = 0;
   out_547656323515283001[15] = 0;
   out_547656323515283001[16] = 0;
   out_547656323515283001[17] = 0;
   out_547656323515283001[18] = 0;
   out_547656323515283001[19] = 0;
   out_547656323515283001[20] = 1;
   out_547656323515283001[21] = 0;
   out_547656323515283001[22] = 0;
   out_547656323515283001[23] = 0;
   out_547656323515283001[24] = 0;
   out_547656323515283001[25] = 0;
   out_547656323515283001[26] = 0;
   out_547656323515283001[27] = 0;
   out_547656323515283001[28] = 0;
   out_547656323515283001[29] = 0;
   out_547656323515283001[30] = 1;
   out_547656323515283001[31] = 0;
   out_547656323515283001[32] = 0;
   out_547656323515283001[33] = 0;
   out_547656323515283001[34] = 0;
   out_547656323515283001[35] = 0;
   out_547656323515283001[36] = 0;
   out_547656323515283001[37] = 0;
   out_547656323515283001[38] = 0;
   out_547656323515283001[39] = 0;
   out_547656323515283001[40] = 1;
   out_547656323515283001[41] = 0;
   out_547656323515283001[42] = 0;
   out_547656323515283001[43] = 0;
   out_547656323515283001[44] = 0;
   out_547656323515283001[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_547656323515283001[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_547656323515283001[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_547656323515283001[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_547656323515283001[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_547656323515283001[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_547656323515283001[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_547656323515283001[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_547656323515283001[53] = -9.8100000000000005*dt;
   out_547656323515283001[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_547656323515283001[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_547656323515283001[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_547656323515283001[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_547656323515283001[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_547656323515283001[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_547656323515283001[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_547656323515283001[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_547656323515283001[62] = 0;
   out_547656323515283001[63] = 0;
   out_547656323515283001[64] = 0;
   out_547656323515283001[65] = 0;
   out_547656323515283001[66] = 0;
   out_547656323515283001[67] = 0;
   out_547656323515283001[68] = 0;
   out_547656323515283001[69] = 0;
   out_547656323515283001[70] = 1;
   out_547656323515283001[71] = 0;
   out_547656323515283001[72] = 0;
   out_547656323515283001[73] = 0;
   out_547656323515283001[74] = 0;
   out_547656323515283001[75] = 0;
   out_547656323515283001[76] = 0;
   out_547656323515283001[77] = 0;
   out_547656323515283001[78] = 0;
   out_547656323515283001[79] = 0;
   out_547656323515283001[80] = 1;
}
void h_25(double *state, double *unused, double *out_3127457687100704828) {
   out_3127457687100704828[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7385507900126241308) {
   out_7385507900126241308[0] = 0;
   out_7385507900126241308[1] = 0;
   out_7385507900126241308[2] = 0;
   out_7385507900126241308[3] = 0;
   out_7385507900126241308[4] = 0;
   out_7385507900126241308[5] = 0;
   out_7385507900126241308[6] = 1;
   out_7385507900126241308[7] = 0;
   out_7385507900126241308[8] = 0;
}
void h_24(double *state, double *unused, double *out_1385747192697667747) {
   out_1385747192697667747[0] = state[4];
   out_1385747192697667747[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3827582301323918172) {
   out_3827582301323918172[0] = 0;
   out_3827582301323918172[1] = 0;
   out_3827582301323918172[2] = 0;
   out_3827582301323918172[3] = 0;
   out_3827582301323918172[4] = 1;
   out_3827582301323918172[5] = 0;
   out_3827582301323918172[6] = 0;
   out_3827582301323918172[7] = 0;
   out_3827582301323918172[8] = 0;
   out_3827582301323918172[9] = 0;
   out_3827582301323918172[10] = 0;
   out_3827582301323918172[11] = 0;
   out_3827582301323918172[12] = 0;
   out_3827582301323918172[13] = 0;
   out_3827582301323918172[14] = 1;
   out_3827582301323918172[15] = 0;
   out_3827582301323918172[16] = 0;
   out_3827582301323918172[17] = 0;
}
void h_30(double *state, double *unused, double *out_4635807569719967613) {
   out_4635807569719967613[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7514846847269481378) {
   out_7514846847269481378[0] = 0;
   out_7514846847269481378[1] = 0;
   out_7514846847269481378[2] = 0;
   out_7514846847269481378[3] = 0;
   out_7514846847269481378[4] = 1;
   out_7514846847269481378[5] = 0;
   out_7514846847269481378[6] = 0;
   out_7514846847269481378[7] = 0;
   out_7514846847269481378[8] = 0;
}
void h_26(double *state, double *unused, double *out_4346161602286873152) {
   out_4346161602286873152[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7319732854709254084) {
   out_7319732854709254084[0] = 0;
   out_7319732854709254084[1] = 0;
   out_7319732854709254084[2] = 0;
   out_7319732854709254084[3] = 0;
   out_7319732854709254084[4] = 0;
   out_7319732854709254084[5] = 0;
   out_7319732854709254084[6] = 0;
   out_7319732854709254084[7] = 1;
   out_7319732854709254084[8] = 0;
}
void h_27(double *state, double *unused, double *out_90671635656372143) {
   out_90671635656372143[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8757133914639645327) {
   out_8757133914639645327[0] = 0;
   out_8757133914639645327[1] = 0;
   out_8757133914639645327[2] = 0;
   out_8757133914639645327[3] = 1;
   out_8757133914639645327[4] = 0;
   out_8757133914639645327[5] = 0;
   out_8757133914639645327[6] = 0;
   out_8757133914639645327[7] = 0;
   out_8757133914639645327[8] = 0;
}
void h_29(double *state, double *unused, double *out_365865697940878032) {
   out_365865697940878032[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7004615502955089194) {
   out_7004615502955089194[0] = 0;
   out_7004615502955089194[1] = 1;
   out_7004615502955089194[2] = 0;
   out_7004615502955089194[3] = 0;
   out_7004615502955089194[4] = 0;
   out_7004615502955089194[5] = 0;
   out_7004615502955089194[6] = 0;
   out_7004615502955089194[7] = 0;
   out_7004615502955089194[8] = 0;
}
void h_28(double *state, double *unused, double *out_6687857119962214334) {
   out_6687857119962214334[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5040985231389762943) {
   out_5040985231389762943[0] = 1;
   out_5040985231389762943[1] = 0;
   out_5040985231389762943[2] = 0;
   out_5040985231389762943[3] = 0;
   out_5040985231389762943[4] = 0;
   out_5040985231389762943[5] = 0;
   out_5040985231389762943[6] = 0;
   out_5040985231389762943[7] = 0;
   out_5040985231389762943[8] = 0;
}
void h_31(double *state, double *unused, double *out_8548451160258495852) {
   out_8548451160258495852[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7354861938249280880) {
   out_7354861938249280880[0] = 0;
   out_7354861938249280880[1] = 0;
   out_7354861938249280880[2] = 0;
   out_7354861938249280880[3] = 0;
   out_7354861938249280880[4] = 0;
   out_7354861938249280880[5] = 0;
   out_7354861938249280880[6] = 0;
   out_7354861938249280880[7] = 0;
   out_7354861938249280880[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_943833552876303288) {
  err_fun(nom_x, delta_x, out_943833552876303288);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_528301401300769025) {
  inv_err_fun(nom_x, true_x, out_528301401300769025);
}
void car_H_mod_fun(double *state, double *out_7538255523593818631) {
  H_mod_fun(state, out_7538255523593818631);
}
void car_f_fun(double *state, double dt, double *out_3917173406968738478) {
  f_fun(state,  dt, out_3917173406968738478);
}
void car_F_fun(double *state, double dt, double *out_547656323515283001) {
  F_fun(state,  dt, out_547656323515283001);
}
void car_h_25(double *state, double *unused, double *out_3127457687100704828) {
  h_25(state, unused, out_3127457687100704828);
}
void car_H_25(double *state, double *unused, double *out_7385507900126241308) {
  H_25(state, unused, out_7385507900126241308);
}
void car_h_24(double *state, double *unused, double *out_1385747192697667747) {
  h_24(state, unused, out_1385747192697667747);
}
void car_H_24(double *state, double *unused, double *out_3827582301323918172) {
  H_24(state, unused, out_3827582301323918172);
}
void car_h_30(double *state, double *unused, double *out_4635807569719967613) {
  h_30(state, unused, out_4635807569719967613);
}
void car_H_30(double *state, double *unused, double *out_7514846847269481378) {
  H_30(state, unused, out_7514846847269481378);
}
void car_h_26(double *state, double *unused, double *out_4346161602286873152) {
  h_26(state, unused, out_4346161602286873152);
}
void car_H_26(double *state, double *unused, double *out_7319732854709254084) {
  H_26(state, unused, out_7319732854709254084);
}
void car_h_27(double *state, double *unused, double *out_90671635656372143) {
  h_27(state, unused, out_90671635656372143);
}
void car_H_27(double *state, double *unused, double *out_8757133914639645327) {
  H_27(state, unused, out_8757133914639645327);
}
void car_h_29(double *state, double *unused, double *out_365865697940878032) {
  h_29(state, unused, out_365865697940878032);
}
void car_H_29(double *state, double *unused, double *out_7004615502955089194) {
  H_29(state, unused, out_7004615502955089194);
}
void car_h_28(double *state, double *unused, double *out_6687857119962214334) {
  h_28(state, unused, out_6687857119962214334);
}
void car_H_28(double *state, double *unused, double *out_5040985231389762943) {
  H_28(state, unused, out_5040985231389762943);
}
void car_h_31(double *state, double *unused, double *out_8548451160258495852) {
  h_31(state, unused, out_8548451160258495852);
}
void car_H_31(double *state, double *unused, double *out_7354861938249280880) {
  H_31(state, unused, out_7354861938249280880);
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
