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
void err_fun(double *nom_x, double *delta_x, double *out_3009395508469456389) {
   out_3009395508469456389[0] = delta_x[0] + nom_x[0];
   out_3009395508469456389[1] = delta_x[1] + nom_x[1];
   out_3009395508469456389[2] = delta_x[2] + nom_x[2];
   out_3009395508469456389[3] = delta_x[3] + nom_x[3];
   out_3009395508469456389[4] = delta_x[4] + nom_x[4];
   out_3009395508469456389[5] = delta_x[5] + nom_x[5];
   out_3009395508469456389[6] = delta_x[6] + nom_x[6];
   out_3009395508469456389[7] = delta_x[7] + nom_x[7];
   out_3009395508469456389[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6058691817726549063) {
   out_6058691817726549063[0] = -nom_x[0] + true_x[0];
   out_6058691817726549063[1] = -nom_x[1] + true_x[1];
   out_6058691817726549063[2] = -nom_x[2] + true_x[2];
   out_6058691817726549063[3] = -nom_x[3] + true_x[3];
   out_6058691817726549063[4] = -nom_x[4] + true_x[4];
   out_6058691817726549063[5] = -nom_x[5] + true_x[5];
   out_6058691817726549063[6] = -nom_x[6] + true_x[6];
   out_6058691817726549063[7] = -nom_x[7] + true_x[7];
   out_6058691817726549063[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6620632585560778509) {
   out_6620632585560778509[0] = 1.0;
   out_6620632585560778509[1] = 0.0;
   out_6620632585560778509[2] = 0.0;
   out_6620632585560778509[3] = 0.0;
   out_6620632585560778509[4] = 0.0;
   out_6620632585560778509[5] = 0.0;
   out_6620632585560778509[6] = 0.0;
   out_6620632585560778509[7] = 0.0;
   out_6620632585560778509[8] = 0.0;
   out_6620632585560778509[9] = 0.0;
   out_6620632585560778509[10] = 1.0;
   out_6620632585560778509[11] = 0.0;
   out_6620632585560778509[12] = 0.0;
   out_6620632585560778509[13] = 0.0;
   out_6620632585560778509[14] = 0.0;
   out_6620632585560778509[15] = 0.0;
   out_6620632585560778509[16] = 0.0;
   out_6620632585560778509[17] = 0.0;
   out_6620632585560778509[18] = 0.0;
   out_6620632585560778509[19] = 0.0;
   out_6620632585560778509[20] = 1.0;
   out_6620632585560778509[21] = 0.0;
   out_6620632585560778509[22] = 0.0;
   out_6620632585560778509[23] = 0.0;
   out_6620632585560778509[24] = 0.0;
   out_6620632585560778509[25] = 0.0;
   out_6620632585560778509[26] = 0.0;
   out_6620632585560778509[27] = 0.0;
   out_6620632585560778509[28] = 0.0;
   out_6620632585560778509[29] = 0.0;
   out_6620632585560778509[30] = 1.0;
   out_6620632585560778509[31] = 0.0;
   out_6620632585560778509[32] = 0.0;
   out_6620632585560778509[33] = 0.0;
   out_6620632585560778509[34] = 0.0;
   out_6620632585560778509[35] = 0.0;
   out_6620632585560778509[36] = 0.0;
   out_6620632585560778509[37] = 0.0;
   out_6620632585560778509[38] = 0.0;
   out_6620632585560778509[39] = 0.0;
   out_6620632585560778509[40] = 1.0;
   out_6620632585560778509[41] = 0.0;
   out_6620632585560778509[42] = 0.0;
   out_6620632585560778509[43] = 0.0;
   out_6620632585560778509[44] = 0.0;
   out_6620632585560778509[45] = 0.0;
   out_6620632585560778509[46] = 0.0;
   out_6620632585560778509[47] = 0.0;
   out_6620632585560778509[48] = 0.0;
   out_6620632585560778509[49] = 0.0;
   out_6620632585560778509[50] = 1.0;
   out_6620632585560778509[51] = 0.0;
   out_6620632585560778509[52] = 0.0;
   out_6620632585560778509[53] = 0.0;
   out_6620632585560778509[54] = 0.0;
   out_6620632585560778509[55] = 0.0;
   out_6620632585560778509[56] = 0.0;
   out_6620632585560778509[57] = 0.0;
   out_6620632585560778509[58] = 0.0;
   out_6620632585560778509[59] = 0.0;
   out_6620632585560778509[60] = 1.0;
   out_6620632585560778509[61] = 0.0;
   out_6620632585560778509[62] = 0.0;
   out_6620632585560778509[63] = 0.0;
   out_6620632585560778509[64] = 0.0;
   out_6620632585560778509[65] = 0.0;
   out_6620632585560778509[66] = 0.0;
   out_6620632585560778509[67] = 0.0;
   out_6620632585560778509[68] = 0.0;
   out_6620632585560778509[69] = 0.0;
   out_6620632585560778509[70] = 1.0;
   out_6620632585560778509[71] = 0.0;
   out_6620632585560778509[72] = 0.0;
   out_6620632585560778509[73] = 0.0;
   out_6620632585560778509[74] = 0.0;
   out_6620632585560778509[75] = 0.0;
   out_6620632585560778509[76] = 0.0;
   out_6620632585560778509[77] = 0.0;
   out_6620632585560778509[78] = 0.0;
   out_6620632585560778509[79] = 0.0;
   out_6620632585560778509[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3578319971516081169) {
   out_3578319971516081169[0] = state[0];
   out_3578319971516081169[1] = state[1];
   out_3578319971516081169[2] = state[2];
   out_3578319971516081169[3] = state[3];
   out_3578319971516081169[4] = state[4];
   out_3578319971516081169[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3578319971516081169[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3578319971516081169[7] = state[7];
   out_3578319971516081169[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2530937000049298875) {
   out_2530937000049298875[0] = 1;
   out_2530937000049298875[1] = 0;
   out_2530937000049298875[2] = 0;
   out_2530937000049298875[3] = 0;
   out_2530937000049298875[4] = 0;
   out_2530937000049298875[5] = 0;
   out_2530937000049298875[6] = 0;
   out_2530937000049298875[7] = 0;
   out_2530937000049298875[8] = 0;
   out_2530937000049298875[9] = 0;
   out_2530937000049298875[10] = 1;
   out_2530937000049298875[11] = 0;
   out_2530937000049298875[12] = 0;
   out_2530937000049298875[13] = 0;
   out_2530937000049298875[14] = 0;
   out_2530937000049298875[15] = 0;
   out_2530937000049298875[16] = 0;
   out_2530937000049298875[17] = 0;
   out_2530937000049298875[18] = 0;
   out_2530937000049298875[19] = 0;
   out_2530937000049298875[20] = 1;
   out_2530937000049298875[21] = 0;
   out_2530937000049298875[22] = 0;
   out_2530937000049298875[23] = 0;
   out_2530937000049298875[24] = 0;
   out_2530937000049298875[25] = 0;
   out_2530937000049298875[26] = 0;
   out_2530937000049298875[27] = 0;
   out_2530937000049298875[28] = 0;
   out_2530937000049298875[29] = 0;
   out_2530937000049298875[30] = 1;
   out_2530937000049298875[31] = 0;
   out_2530937000049298875[32] = 0;
   out_2530937000049298875[33] = 0;
   out_2530937000049298875[34] = 0;
   out_2530937000049298875[35] = 0;
   out_2530937000049298875[36] = 0;
   out_2530937000049298875[37] = 0;
   out_2530937000049298875[38] = 0;
   out_2530937000049298875[39] = 0;
   out_2530937000049298875[40] = 1;
   out_2530937000049298875[41] = 0;
   out_2530937000049298875[42] = 0;
   out_2530937000049298875[43] = 0;
   out_2530937000049298875[44] = 0;
   out_2530937000049298875[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2530937000049298875[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2530937000049298875[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2530937000049298875[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2530937000049298875[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2530937000049298875[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2530937000049298875[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2530937000049298875[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2530937000049298875[53] = -9.8100000000000005*dt;
   out_2530937000049298875[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2530937000049298875[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2530937000049298875[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2530937000049298875[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2530937000049298875[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2530937000049298875[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2530937000049298875[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2530937000049298875[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2530937000049298875[62] = 0;
   out_2530937000049298875[63] = 0;
   out_2530937000049298875[64] = 0;
   out_2530937000049298875[65] = 0;
   out_2530937000049298875[66] = 0;
   out_2530937000049298875[67] = 0;
   out_2530937000049298875[68] = 0;
   out_2530937000049298875[69] = 0;
   out_2530937000049298875[70] = 1;
   out_2530937000049298875[71] = 0;
   out_2530937000049298875[72] = 0;
   out_2530937000049298875[73] = 0;
   out_2530937000049298875[74] = 0;
   out_2530937000049298875[75] = 0;
   out_2530937000049298875[76] = 0;
   out_2530937000049298875[77] = 0;
   out_2530937000049298875[78] = 0;
   out_2530937000049298875[79] = 0;
   out_2530937000049298875[80] = 1;
}
void h_25(double *state, double *unused, double *out_2134931354245078390) {
   out_2134931354245078390[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2632923262236535870) {
   out_2632923262236535870[0] = 0;
   out_2632923262236535870[1] = 0;
   out_2632923262236535870[2] = 0;
   out_2632923262236535870[3] = 0;
   out_2632923262236535870[4] = 0;
   out_2632923262236535870[5] = 0;
   out_2632923262236535870[6] = 1;
   out_2632923262236535870[7] = 0;
   out_2632923262236535870[8] = 0;
}
void h_24(double *state, double *unused, double *out_8365765087520140722) {
   out_8365765087520140722[0] = state[4];
   out_8365765087520140722[1] = state[5];
}
void H_24(double *state, double *unused, double *out_460273663231036304) {
   out_460273663231036304[0] = 0;
   out_460273663231036304[1] = 0;
   out_460273663231036304[2] = 0;
   out_460273663231036304[3] = 0;
   out_460273663231036304[4] = 1;
   out_460273663231036304[5] = 0;
   out_460273663231036304[6] = 0;
   out_460273663231036304[7] = 0;
   out_460273663231036304[8] = 0;
   out_460273663231036304[9] = 0;
   out_460273663231036304[10] = 0;
   out_460273663231036304[11] = 0;
   out_460273663231036304[12] = 0;
   out_460273663231036304[13] = 0;
   out_460273663231036304[14] = 1;
   out_460273663231036304[15] = 0;
   out_460273663231036304[16] = 0;
   out_460273663231036304[17] = 0;
}
void h_30(double *state, double *unused, double *out_5772380882499100740) {
   out_5772380882499100740[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5151256220743784497) {
   out_5151256220743784497[0] = 0;
   out_5151256220743784497[1] = 0;
   out_5151256220743784497[2] = 0;
   out_5151256220743784497[3] = 0;
   out_5151256220743784497[4] = 1;
   out_5151256220743784497[5] = 0;
   out_5151256220743784497[6] = 0;
   out_5151256220743784497[7] = 0;
   out_5151256220743784497[8] = 0;
}
void h_26(double *state, double *unused, double *out_770707614838255095) {
   out_770707614838255095[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1108580056637520354) {
   out_1108580056637520354[0] = 0;
   out_1108580056637520354[1] = 0;
   out_1108580056637520354[2] = 0;
   out_1108580056637520354[3] = 0;
   out_1108580056637520354[4] = 0;
   out_1108580056637520354[5] = 0;
   out_1108580056637520354[6] = 0;
   out_1108580056637520354[7] = 1;
   out_1108580056637520354[8] = 0;
}
void h_27(double *state, double *unused, double *out_7593975799595780900) {
   out_7593975799595780900[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7374850291927727714) {
   out_7374850291927727714[0] = 0;
   out_7374850291927727714[1] = 0;
   out_7374850291927727714[2] = 0;
   out_7374850291927727714[3] = 1;
   out_7374850291927727714[4] = 0;
   out_7374850291927727714[5] = 0;
   out_7374850291927727714[6] = 0;
   out_7374850291927727714[7] = 0;
   out_7374850291927727714[8] = 0;
}
void h_29(double *state, double *unused, double *out_287296851158268285) {
   out_287296851158268285[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5661487565058176681) {
   out_5661487565058176681[0] = 0;
   out_5661487565058176681[1] = 1;
   out_5661487565058176681[2] = 0;
   out_5661487565058176681[3] = 0;
   out_5661487565058176681[4] = 0;
   out_5661487565058176681[5] = 0;
   out_5661487565058176681[6] = 0;
   out_5661487565058176681[7] = 0;
   out_5661487565058176681[8] = 0;
}
void h_28(double *state, double *unused, double *out_6243721933085284858) {
   out_6243721933085284858[0] = state[0];
}
void H_28(double *state, double *unused, double *out_579088547988646107) {
   out_579088547988646107[0] = 1;
   out_579088547988646107[1] = 0;
   out_579088547988646107[2] = 0;
   out_579088547988646107[3] = 0;
   out_579088547988646107[4] = 0;
   out_579088547988646107[5] = 0;
   out_579088547988646107[6] = 0;
   out_579088547988646107[7] = 0;
   out_579088547988646107[8] = 0;
}
void h_31(double *state, double *unused, double *out_8851253955215584901) {
   out_8851253955215584901[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2663569224113496298) {
   out_2663569224113496298[0] = 0;
   out_2663569224113496298[1] = 0;
   out_2663569224113496298[2] = 0;
   out_2663569224113496298[3] = 0;
   out_2663569224113496298[4] = 0;
   out_2663569224113496298[5] = 0;
   out_2663569224113496298[6] = 0;
   out_2663569224113496298[7] = 0;
   out_2663569224113496298[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3009395508469456389) {
  err_fun(nom_x, delta_x, out_3009395508469456389);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6058691817726549063) {
  inv_err_fun(nom_x, true_x, out_6058691817726549063);
}
void car_H_mod_fun(double *state, double *out_6620632585560778509) {
  H_mod_fun(state, out_6620632585560778509);
}
void car_f_fun(double *state, double dt, double *out_3578319971516081169) {
  f_fun(state,  dt, out_3578319971516081169);
}
void car_F_fun(double *state, double dt, double *out_2530937000049298875) {
  F_fun(state,  dt, out_2530937000049298875);
}
void car_h_25(double *state, double *unused, double *out_2134931354245078390) {
  h_25(state, unused, out_2134931354245078390);
}
void car_H_25(double *state, double *unused, double *out_2632923262236535870) {
  H_25(state, unused, out_2632923262236535870);
}
void car_h_24(double *state, double *unused, double *out_8365765087520140722) {
  h_24(state, unused, out_8365765087520140722);
}
void car_H_24(double *state, double *unused, double *out_460273663231036304) {
  H_24(state, unused, out_460273663231036304);
}
void car_h_30(double *state, double *unused, double *out_5772380882499100740) {
  h_30(state, unused, out_5772380882499100740);
}
void car_H_30(double *state, double *unused, double *out_5151256220743784497) {
  H_30(state, unused, out_5151256220743784497);
}
void car_h_26(double *state, double *unused, double *out_770707614838255095) {
  h_26(state, unused, out_770707614838255095);
}
void car_H_26(double *state, double *unused, double *out_1108580056637520354) {
  H_26(state, unused, out_1108580056637520354);
}
void car_h_27(double *state, double *unused, double *out_7593975799595780900) {
  h_27(state, unused, out_7593975799595780900);
}
void car_H_27(double *state, double *unused, double *out_7374850291927727714) {
  H_27(state, unused, out_7374850291927727714);
}
void car_h_29(double *state, double *unused, double *out_287296851158268285) {
  h_29(state, unused, out_287296851158268285);
}
void car_H_29(double *state, double *unused, double *out_5661487565058176681) {
  H_29(state, unused, out_5661487565058176681);
}
void car_h_28(double *state, double *unused, double *out_6243721933085284858) {
  h_28(state, unused, out_6243721933085284858);
}
void car_H_28(double *state, double *unused, double *out_579088547988646107) {
  H_28(state, unused, out_579088547988646107);
}
void car_h_31(double *state, double *unused, double *out_8851253955215584901) {
  h_31(state, unused, out_8851253955215584901);
}
void car_H_31(double *state, double *unused, double *out_2663569224113496298) {
  H_31(state, unused, out_2663569224113496298);
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
