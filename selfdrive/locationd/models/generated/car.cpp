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
void err_fun(double *nom_x, double *delta_x, double *out_4885896537278282144) {
   out_4885896537278282144[0] = delta_x[0] + nom_x[0];
   out_4885896537278282144[1] = delta_x[1] + nom_x[1];
   out_4885896537278282144[2] = delta_x[2] + nom_x[2];
   out_4885896537278282144[3] = delta_x[3] + nom_x[3];
   out_4885896537278282144[4] = delta_x[4] + nom_x[4];
   out_4885896537278282144[5] = delta_x[5] + nom_x[5];
   out_4885896537278282144[6] = delta_x[6] + nom_x[6];
   out_4885896537278282144[7] = delta_x[7] + nom_x[7];
   out_4885896537278282144[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3745151970403573209) {
   out_3745151970403573209[0] = -nom_x[0] + true_x[0];
   out_3745151970403573209[1] = -nom_x[1] + true_x[1];
   out_3745151970403573209[2] = -nom_x[2] + true_x[2];
   out_3745151970403573209[3] = -nom_x[3] + true_x[3];
   out_3745151970403573209[4] = -nom_x[4] + true_x[4];
   out_3745151970403573209[5] = -nom_x[5] + true_x[5];
   out_3745151970403573209[6] = -nom_x[6] + true_x[6];
   out_3745151970403573209[7] = -nom_x[7] + true_x[7];
   out_3745151970403573209[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2937880372820632520) {
   out_2937880372820632520[0] = 1.0;
   out_2937880372820632520[1] = 0.0;
   out_2937880372820632520[2] = 0.0;
   out_2937880372820632520[3] = 0.0;
   out_2937880372820632520[4] = 0.0;
   out_2937880372820632520[5] = 0.0;
   out_2937880372820632520[6] = 0.0;
   out_2937880372820632520[7] = 0.0;
   out_2937880372820632520[8] = 0.0;
   out_2937880372820632520[9] = 0.0;
   out_2937880372820632520[10] = 1.0;
   out_2937880372820632520[11] = 0.0;
   out_2937880372820632520[12] = 0.0;
   out_2937880372820632520[13] = 0.0;
   out_2937880372820632520[14] = 0.0;
   out_2937880372820632520[15] = 0.0;
   out_2937880372820632520[16] = 0.0;
   out_2937880372820632520[17] = 0.0;
   out_2937880372820632520[18] = 0.0;
   out_2937880372820632520[19] = 0.0;
   out_2937880372820632520[20] = 1.0;
   out_2937880372820632520[21] = 0.0;
   out_2937880372820632520[22] = 0.0;
   out_2937880372820632520[23] = 0.0;
   out_2937880372820632520[24] = 0.0;
   out_2937880372820632520[25] = 0.0;
   out_2937880372820632520[26] = 0.0;
   out_2937880372820632520[27] = 0.0;
   out_2937880372820632520[28] = 0.0;
   out_2937880372820632520[29] = 0.0;
   out_2937880372820632520[30] = 1.0;
   out_2937880372820632520[31] = 0.0;
   out_2937880372820632520[32] = 0.0;
   out_2937880372820632520[33] = 0.0;
   out_2937880372820632520[34] = 0.0;
   out_2937880372820632520[35] = 0.0;
   out_2937880372820632520[36] = 0.0;
   out_2937880372820632520[37] = 0.0;
   out_2937880372820632520[38] = 0.0;
   out_2937880372820632520[39] = 0.0;
   out_2937880372820632520[40] = 1.0;
   out_2937880372820632520[41] = 0.0;
   out_2937880372820632520[42] = 0.0;
   out_2937880372820632520[43] = 0.0;
   out_2937880372820632520[44] = 0.0;
   out_2937880372820632520[45] = 0.0;
   out_2937880372820632520[46] = 0.0;
   out_2937880372820632520[47] = 0.0;
   out_2937880372820632520[48] = 0.0;
   out_2937880372820632520[49] = 0.0;
   out_2937880372820632520[50] = 1.0;
   out_2937880372820632520[51] = 0.0;
   out_2937880372820632520[52] = 0.0;
   out_2937880372820632520[53] = 0.0;
   out_2937880372820632520[54] = 0.0;
   out_2937880372820632520[55] = 0.0;
   out_2937880372820632520[56] = 0.0;
   out_2937880372820632520[57] = 0.0;
   out_2937880372820632520[58] = 0.0;
   out_2937880372820632520[59] = 0.0;
   out_2937880372820632520[60] = 1.0;
   out_2937880372820632520[61] = 0.0;
   out_2937880372820632520[62] = 0.0;
   out_2937880372820632520[63] = 0.0;
   out_2937880372820632520[64] = 0.0;
   out_2937880372820632520[65] = 0.0;
   out_2937880372820632520[66] = 0.0;
   out_2937880372820632520[67] = 0.0;
   out_2937880372820632520[68] = 0.0;
   out_2937880372820632520[69] = 0.0;
   out_2937880372820632520[70] = 1.0;
   out_2937880372820632520[71] = 0.0;
   out_2937880372820632520[72] = 0.0;
   out_2937880372820632520[73] = 0.0;
   out_2937880372820632520[74] = 0.0;
   out_2937880372820632520[75] = 0.0;
   out_2937880372820632520[76] = 0.0;
   out_2937880372820632520[77] = 0.0;
   out_2937880372820632520[78] = 0.0;
   out_2937880372820632520[79] = 0.0;
   out_2937880372820632520[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4204558600518622219) {
   out_4204558600518622219[0] = state[0];
   out_4204558600518622219[1] = state[1];
   out_4204558600518622219[2] = state[2];
   out_4204558600518622219[3] = state[3];
   out_4204558600518622219[4] = state[4];
   out_4204558600518622219[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4204558600518622219[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4204558600518622219[7] = state[7];
   out_4204558600518622219[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3726788735705827984) {
   out_3726788735705827984[0] = 1;
   out_3726788735705827984[1] = 0;
   out_3726788735705827984[2] = 0;
   out_3726788735705827984[3] = 0;
   out_3726788735705827984[4] = 0;
   out_3726788735705827984[5] = 0;
   out_3726788735705827984[6] = 0;
   out_3726788735705827984[7] = 0;
   out_3726788735705827984[8] = 0;
   out_3726788735705827984[9] = 0;
   out_3726788735705827984[10] = 1;
   out_3726788735705827984[11] = 0;
   out_3726788735705827984[12] = 0;
   out_3726788735705827984[13] = 0;
   out_3726788735705827984[14] = 0;
   out_3726788735705827984[15] = 0;
   out_3726788735705827984[16] = 0;
   out_3726788735705827984[17] = 0;
   out_3726788735705827984[18] = 0;
   out_3726788735705827984[19] = 0;
   out_3726788735705827984[20] = 1;
   out_3726788735705827984[21] = 0;
   out_3726788735705827984[22] = 0;
   out_3726788735705827984[23] = 0;
   out_3726788735705827984[24] = 0;
   out_3726788735705827984[25] = 0;
   out_3726788735705827984[26] = 0;
   out_3726788735705827984[27] = 0;
   out_3726788735705827984[28] = 0;
   out_3726788735705827984[29] = 0;
   out_3726788735705827984[30] = 1;
   out_3726788735705827984[31] = 0;
   out_3726788735705827984[32] = 0;
   out_3726788735705827984[33] = 0;
   out_3726788735705827984[34] = 0;
   out_3726788735705827984[35] = 0;
   out_3726788735705827984[36] = 0;
   out_3726788735705827984[37] = 0;
   out_3726788735705827984[38] = 0;
   out_3726788735705827984[39] = 0;
   out_3726788735705827984[40] = 1;
   out_3726788735705827984[41] = 0;
   out_3726788735705827984[42] = 0;
   out_3726788735705827984[43] = 0;
   out_3726788735705827984[44] = 0;
   out_3726788735705827984[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3726788735705827984[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3726788735705827984[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3726788735705827984[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3726788735705827984[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3726788735705827984[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3726788735705827984[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3726788735705827984[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3726788735705827984[53] = -9.8100000000000005*dt;
   out_3726788735705827984[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3726788735705827984[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3726788735705827984[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3726788735705827984[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3726788735705827984[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3726788735705827984[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3726788735705827984[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3726788735705827984[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3726788735705827984[62] = 0;
   out_3726788735705827984[63] = 0;
   out_3726788735705827984[64] = 0;
   out_3726788735705827984[65] = 0;
   out_3726788735705827984[66] = 0;
   out_3726788735705827984[67] = 0;
   out_3726788735705827984[68] = 0;
   out_3726788735705827984[69] = 0;
   out_3726788735705827984[70] = 1;
   out_3726788735705827984[71] = 0;
   out_3726788735705827984[72] = 0;
   out_3726788735705827984[73] = 0;
   out_3726788735705827984[74] = 0;
   out_3726788735705827984[75] = 0;
   out_3726788735705827984[76] = 0;
   out_3726788735705827984[77] = 0;
   out_3726788735705827984[78] = 0;
   out_3726788735705827984[79] = 0;
   out_3726788735705827984[80] = 1;
}
void h_25(double *state, double *unused, double *out_6349123496291746259) {
   out_6349123496291746259[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7841572198005297360) {
   out_7841572198005297360[0] = 0;
   out_7841572198005297360[1] = 0;
   out_7841572198005297360[2] = 0;
   out_7841572198005297360[3] = 0;
   out_7841572198005297360[4] = 0;
   out_7841572198005297360[5] = 0;
   out_7841572198005297360[6] = 1;
   out_7841572198005297360[7] = 0;
   out_7841572198005297360[8] = 0;
}
void h_24(double *state, double *unused, double *out_2774216340997546785) {
   out_2774216340997546785[0] = state[4];
   out_2774216340997546785[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8427957452097104283) {
   out_8427957452097104283[0] = 0;
   out_8427957452097104283[1] = 0;
   out_8427957452097104283[2] = 0;
   out_8427957452097104283[3] = 0;
   out_8427957452097104283[4] = 1;
   out_8427957452097104283[5] = 0;
   out_8427957452097104283[6] = 0;
   out_8427957452097104283[7] = 0;
   out_8427957452097104283[8] = 0;
   out_8427957452097104283[9] = 0;
   out_8427957452097104283[10] = 0;
   out_8427957452097104283[11] = 0;
   out_8427957452097104283[12] = 0;
   out_8427957452097104283[13] = 0;
   out_8427957452097104283[14] = 1;
   out_8427957452097104283[15] = 0;
   out_8427957452097104283[16] = 0;
   out_8427957452097104283[17] = 0;
}
void h_30(double *state, double *unused, double *out_5326785351067454421) {
   out_5326785351067454421[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8086838917197005629) {
   out_8086838917197005629[0] = 0;
   out_8086838917197005629[1] = 0;
   out_8086838917197005629[2] = 0;
   out_8086838917197005629[3] = 0;
   out_8086838917197005629[4] = 1;
   out_8086838917197005629[5] = 0;
   out_8086838917197005629[6] = 0;
   out_8086838917197005629[7] = 0;
   out_8086838917197005629[8] = 0;
}
void h_26(double *state, double *unused, double *out_3469524113198542719) {
   out_3469524113198542719[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4100068879131241136) {
   out_4100068879131241136[0] = 0;
   out_4100068879131241136[1] = 0;
   out_4100068879131241136[2] = 0;
   out_4100068879131241136[3] = 0;
   out_4100068879131241136[4] = 0;
   out_4100068879131241136[5] = 0;
   out_4100068879131241136[6] = 0;
   out_4100068879131241136[7] = 1;
   out_4100068879131241136[8] = 0;
}
void h_27(double *state, double *unused, double *out_1347450228630900614) {
   out_1347450228630900614[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8185141844712121076) {
   out_8185141844712121076[0] = 0;
   out_8185141844712121076[1] = 0;
   out_8185141844712121076[2] = 0;
   out_8185141844712121076[3] = 1;
   out_8185141844712121076[4] = 0;
   out_8185141844712121076[5] = 0;
   out_8185141844712121076[6] = 0;
   out_8185141844712121076[7] = 0;
   out_8185141844712121076[8] = 0;
}
void h_29(double *state, double *unused, double *out_2289999299623121736) {
   out_2289999299623121736[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7576607572882613445) {
   out_7576607572882613445[0] = 0;
   out_7576607572882613445[1] = 1;
   out_7576607572882613445[2] = 0;
   out_7576607572882613445[3] = 0;
   out_7576607572882613445[4] = 0;
   out_7576607572882613445[5] = 0;
   out_7576607572882613445[6] = 0;
   out_7576607572882613445[7] = 0;
   out_7576607572882613445[8] = 0;
}
void h_28(double *state, double *unused, double *out_2290960081532563049) {
   out_2290960081532563049[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5787737483757407597) {
   out_5787737483757407597[0] = 1;
   out_5787737483757407597[1] = 0;
   out_5787737483757407597[2] = 0;
   out_5787737483757407597[3] = 0;
   out_5787737483757407597[4] = 0;
   out_5787737483757407597[5] = 0;
   out_5787737483757407597[6] = 0;
   out_5787737483757407597[7] = 0;
   out_5787737483757407597[8] = 0;
}
void h_31(double *state, double *unused, double *out_8460171049163783007) {
   out_8460171049163783007[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3473860776897889660) {
   out_3473860776897889660[0] = 0;
   out_3473860776897889660[1] = 0;
   out_3473860776897889660[2] = 0;
   out_3473860776897889660[3] = 0;
   out_3473860776897889660[4] = 0;
   out_3473860776897889660[5] = 0;
   out_3473860776897889660[6] = 0;
   out_3473860776897889660[7] = 0;
   out_3473860776897889660[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4885896537278282144) {
  err_fun(nom_x, delta_x, out_4885896537278282144);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3745151970403573209) {
  inv_err_fun(nom_x, true_x, out_3745151970403573209);
}
void car_H_mod_fun(double *state, double *out_2937880372820632520) {
  H_mod_fun(state, out_2937880372820632520);
}
void car_f_fun(double *state, double dt, double *out_4204558600518622219) {
  f_fun(state,  dt, out_4204558600518622219);
}
void car_F_fun(double *state, double dt, double *out_3726788735705827984) {
  F_fun(state,  dt, out_3726788735705827984);
}
void car_h_25(double *state, double *unused, double *out_6349123496291746259) {
  h_25(state, unused, out_6349123496291746259);
}
void car_H_25(double *state, double *unused, double *out_7841572198005297360) {
  H_25(state, unused, out_7841572198005297360);
}
void car_h_24(double *state, double *unused, double *out_2774216340997546785) {
  h_24(state, unused, out_2774216340997546785);
}
void car_H_24(double *state, double *unused, double *out_8427957452097104283) {
  H_24(state, unused, out_8427957452097104283);
}
void car_h_30(double *state, double *unused, double *out_5326785351067454421) {
  h_30(state, unused, out_5326785351067454421);
}
void car_H_30(double *state, double *unused, double *out_8086838917197005629) {
  H_30(state, unused, out_8086838917197005629);
}
void car_h_26(double *state, double *unused, double *out_3469524113198542719) {
  h_26(state, unused, out_3469524113198542719);
}
void car_H_26(double *state, double *unused, double *out_4100068879131241136) {
  H_26(state, unused, out_4100068879131241136);
}
void car_h_27(double *state, double *unused, double *out_1347450228630900614) {
  h_27(state, unused, out_1347450228630900614);
}
void car_H_27(double *state, double *unused, double *out_8185141844712121076) {
  H_27(state, unused, out_8185141844712121076);
}
void car_h_29(double *state, double *unused, double *out_2289999299623121736) {
  h_29(state, unused, out_2289999299623121736);
}
void car_H_29(double *state, double *unused, double *out_7576607572882613445) {
  H_29(state, unused, out_7576607572882613445);
}
void car_h_28(double *state, double *unused, double *out_2290960081532563049) {
  h_28(state, unused, out_2290960081532563049);
}
void car_H_28(double *state, double *unused, double *out_5787737483757407597) {
  H_28(state, unused, out_5787737483757407597);
}
void car_h_31(double *state, double *unused, double *out_8460171049163783007) {
  h_31(state, unused, out_8460171049163783007);
}
void car_H_31(double *state, double *unused, double *out_3473860776897889660) {
  H_31(state, unused, out_3473860776897889660);
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
