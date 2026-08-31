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
void err_fun(double *nom_x, double *delta_x, double *out_7311248151803822396) {
   out_7311248151803822396[0] = delta_x[0] + nom_x[0];
   out_7311248151803822396[1] = delta_x[1] + nom_x[1];
   out_7311248151803822396[2] = delta_x[2] + nom_x[2];
   out_7311248151803822396[3] = delta_x[3] + nom_x[3];
   out_7311248151803822396[4] = delta_x[4] + nom_x[4];
   out_7311248151803822396[5] = delta_x[5] + nom_x[5];
   out_7311248151803822396[6] = delta_x[6] + nom_x[6];
   out_7311248151803822396[7] = delta_x[7] + nom_x[7];
   out_7311248151803822396[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5602719869542378501) {
   out_5602719869542378501[0] = -nom_x[0] + true_x[0];
   out_5602719869542378501[1] = -nom_x[1] + true_x[1];
   out_5602719869542378501[2] = -nom_x[2] + true_x[2];
   out_5602719869542378501[3] = -nom_x[3] + true_x[3];
   out_5602719869542378501[4] = -nom_x[4] + true_x[4];
   out_5602719869542378501[5] = -nom_x[5] + true_x[5];
   out_5602719869542378501[6] = -nom_x[6] + true_x[6];
   out_5602719869542378501[7] = -nom_x[7] + true_x[7];
   out_5602719869542378501[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6859429191092688662) {
   out_6859429191092688662[0] = 1.0;
   out_6859429191092688662[1] = 0.0;
   out_6859429191092688662[2] = 0.0;
   out_6859429191092688662[3] = 0.0;
   out_6859429191092688662[4] = 0.0;
   out_6859429191092688662[5] = 0.0;
   out_6859429191092688662[6] = 0.0;
   out_6859429191092688662[7] = 0.0;
   out_6859429191092688662[8] = 0.0;
   out_6859429191092688662[9] = 0.0;
   out_6859429191092688662[10] = 1.0;
   out_6859429191092688662[11] = 0.0;
   out_6859429191092688662[12] = 0.0;
   out_6859429191092688662[13] = 0.0;
   out_6859429191092688662[14] = 0.0;
   out_6859429191092688662[15] = 0.0;
   out_6859429191092688662[16] = 0.0;
   out_6859429191092688662[17] = 0.0;
   out_6859429191092688662[18] = 0.0;
   out_6859429191092688662[19] = 0.0;
   out_6859429191092688662[20] = 1.0;
   out_6859429191092688662[21] = 0.0;
   out_6859429191092688662[22] = 0.0;
   out_6859429191092688662[23] = 0.0;
   out_6859429191092688662[24] = 0.0;
   out_6859429191092688662[25] = 0.0;
   out_6859429191092688662[26] = 0.0;
   out_6859429191092688662[27] = 0.0;
   out_6859429191092688662[28] = 0.0;
   out_6859429191092688662[29] = 0.0;
   out_6859429191092688662[30] = 1.0;
   out_6859429191092688662[31] = 0.0;
   out_6859429191092688662[32] = 0.0;
   out_6859429191092688662[33] = 0.0;
   out_6859429191092688662[34] = 0.0;
   out_6859429191092688662[35] = 0.0;
   out_6859429191092688662[36] = 0.0;
   out_6859429191092688662[37] = 0.0;
   out_6859429191092688662[38] = 0.0;
   out_6859429191092688662[39] = 0.0;
   out_6859429191092688662[40] = 1.0;
   out_6859429191092688662[41] = 0.0;
   out_6859429191092688662[42] = 0.0;
   out_6859429191092688662[43] = 0.0;
   out_6859429191092688662[44] = 0.0;
   out_6859429191092688662[45] = 0.0;
   out_6859429191092688662[46] = 0.0;
   out_6859429191092688662[47] = 0.0;
   out_6859429191092688662[48] = 0.0;
   out_6859429191092688662[49] = 0.0;
   out_6859429191092688662[50] = 1.0;
   out_6859429191092688662[51] = 0.0;
   out_6859429191092688662[52] = 0.0;
   out_6859429191092688662[53] = 0.0;
   out_6859429191092688662[54] = 0.0;
   out_6859429191092688662[55] = 0.0;
   out_6859429191092688662[56] = 0.0;
   out_6859429191092688662[57] = 0.0;
   out_6859429191092688662[58] = 0.0;
   out_6859429191092688662[59] = 0.0;
   out_6859429191092688662[60] = 1.0;
   out_6859429191092688662[61] = 0.0;
   out_6859429191092688662[62] = 0.0;
   out_6859429191092688662[63] = 0.0;
   out_6859429191092688662[64] = 0.0;
   out_6859429191092688662[65] = 0.0;
   out_6859429191092688662[66] = 0.0;
   out_6859429191092688662[67] = 0.0;
   out_6859429191092688662[68] = 0.0;
   out_6859429191092688662[69] = 0.0;
   out_6859429191092688662[70] = 1.0;
   out_6859429191092688662[71] = 0.0;
   out_6859429191092688662[72] = 0.0;
   out_6859429191092688662[73] = 0.0;
   out_6859429191092688662[74] = 0.0;
   out_6859429191092688662[75] = 0.0;
   out_6859429191092688662[76] = 0.0;
   out_6859429191092688662[77] = 0.0;
   out_6859429191092688662[78] = 0.0;
   out_6859429191092688662[79] = 0.0;
   out_6859429191092688662[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3400060270232460893) {
   out_3400060270232460893[0] = state[0];
   out_3400060270232460893[1] = state[1];
   out_3400060270232460893[2] = state[2];
   out_3400060270232460893[3] = state[3];
   out_3400060270232460893[4] = state[4];
   out_3400060270232460893[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3400060270232460893[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3400060270232460893[7] = state[7];
   out_3400060270232460893[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6511275578440991802) {
   out_6511275578440991802[0] = 1;
   out_6511275578440991802[1] = 0;
   out_6511275578440991802[2] = 0;
   out_6511275578440991802[3] = 0;
   out_6511275578440991802[4] = 0;
   out_6511275578440991802[5] = 0;
   out_6511275578440991802[6] = 0;
   out_6511275578440991802[7] = 0;
   out_6511275578440991802[8] = 0;
   out_6511275578440991802[9] = 0;
   out_6511275578440991802[10] = 1;
   out_6511275578440991802[11] = 0;
   out_6511275578440991802[12] = 0;
   out_6511275578440991802[13] = 0;
   out_6511275578440991802[14] = 0;
   out_6511275578440991802[15] = 0;
   out_6511275578440991802[16] = 0;
   out_6511275578440991802[17] = 0;
   out_6511275578440991802[18] = 0;
   out_6511275578440991802[19] = 0;
   out_6511275578440991802[20] = 1;
   out_6511275578440991802[21] = 0;
   out_6511275578440991802[22] = 0;
   out_6511275578440991802[23] = 0;
   out_6511275578440991802[24] = 0;
   out_6511275578440991802[25] = 0;
   out_6511275578440991802[26] = 0;
   out_6511275578440991802[27] = 0;
   out_6511275578440991802[28] = 0;
   out_6511275578440991802[29] = 0;
   out_6511275578440991802[30] = 1;
   out_6511275578440991802[31] = 0;
   out_6511275578440991802[32] = 0;
   out_6511275578440991802[33] = 0;
   out_6511275578440991802[34] = 0;
   out_6511275578440991802[35] = 0;
   out_6511275578440991802[36] = 0;
   out_6511275578440991802[37] = 0;
   out_6511275578440991802[38] = 0;
   out_6511275578440991802[39] = 0;
   out_6511275578440991802[40] = 1;
   out_6511275578440991802[41] = 0;
   out_6511275578440991802[42] = 0;
   out_6511275578440991802[43] = 0;
   out_6511275578440991802[44] = 0;
   out_6511275578440991802[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6511275578440991802[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6511275578440991802[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6511275578440991802[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6511275578440991802[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6511275578440991802[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6511275578440991802[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6511275578440991802[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6511275578440991802[53] = -9.8100000000000005*dt;
   out_6511275578440991802[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6511275578440991802[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6511275578440991802[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6511275578440991802[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6511275578440991802[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6511275578440991802[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6511275578440991802[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6511275578440991802[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6511275578440991802[62] = 0;
   out_6511275578440991802[63] = 0;
   out_6511275578440991802[64] = 0;
   out_6511275578440991802[65] = 0;
   out_6511275578440991802[66] = 0;
   out_6511275578440991802[67] = 0;
   out_6511275578440991802[68] = 0;
   out_6511275578440991802[69] = 0;
   out_6511275578440991802[70] = 1;
   out_6511275578440991802[71] = 0;
   out_6511275578440991802[72] = 0;
   out_6511275578440991802[73] = 0;
   out_6511275578440991802[74] = 0;
   out_6511275578440991802[75] = 0;
   out_6511275578440991802[76] = 0;
   out_6511275578440991802[77] = 0;
   out_6511275578440991802[78] = 0;
   out_6511275578440991802[79] = 0;
   out_6511275578440991802[80] = 1;
}
void h_25(double *state, double *unused, double *out_2633570630840598096) {
   out_2633570630840598096[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2394126656704625717) {
   out_2394126656704625717[0] = 0;
   out_2394126656704625717[1] = 0;
   out_2394126656704625717[2] = 0;
   out_2394126656704625717[3] = 0;
   out_2394126656704625717[4] = 0;
   out_2394126656704625717[5] = 0;
   out_2394126656704625717[6] = 1;
   out_2394126656704625717[7] = 0;
   out_2394126656704625717[8] = 0;
}
void h_24(double *state, double *unused, double *out_3094145344632818755) {
   out_3094145344632818755[0] = state[4];
   out_3094145344632818755[1] = state[5];
}
void H_24(double *state, double *unused, double *out_665263537527311648) {
   out_665263537527311648[0] = 0;
   out_665263537527311648[1] = 0;
   out_665263537527311648[2] = 0;
   out_665263537527311648[3] = 0;
   out_665263537527311648[4] = 1;
   out_665263537527311648[5] = 0;
   out_665263537527311648[6] = 0;
   out_665263537527311648[7] = 0;
   out_665263537527311648[8] = 0;
   out_665263537527311648[9] = 0;
   out_665263537527311648[10] = 0;
   out_665263537527311648[11] = 0;
   out_665263537527311648[12] = 0;
   out_665263537527311648[13] = 0;
   out_665263537527311648[14] = 1;
   out_665263537527311648[15] = 0;
   out_665263537527311648[16] = 0;
   out_665263537527311648[17] = 0;
}
void h_30(double *state, double *unused, double *out_1872662776110252318) {
   out_1872662776110252318[0] = state[4];
}
void H_30(double *state, double *unused, double *out_9135927075513309144) {
   out_9135927075513309144[0] = 0;
   out_9135927075513309144[1] = 0;
   out_9135927075513309144[2] = 0;
   out_9135927075513309144[3] = 0;
   out_9135927075513309144[4] = 1;
   out_9135927075513309144[5] = 0;
   out_9135927075513309144[6] = 0;
   out_9135927075513309144[7] = 0;
   out_9135927075513309144[8] = 0;
}
void h_26(double *state, double *unused, double *out_2552698139187979215) {
   out_2552698139187979215[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1347376662169430507) {
   out_1347376662169430507[0] = 0;
   out_1347376662169430507[1] = 0;
   out_1347376662169430507[2] = 0;
   out_1347376662169430507[3] = 0;
   out_1347376662169430507[4] = 0;
   out_1347376662169430507[5] = 0;
   out_1347376662169430507[6] = 0;
   out_1347376662169430507[7] = 1;
   out_1347376662169430507[8] = 0;
}
void h_27(double *state, double *unused, double *out_8276300501921554931) {
   out_8276300501921554931[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7136053686395817561) {
   out_7136053686395817561[0] = 0;
   out_7136053686395817561[1] = 0;
   out_7136053686395817561[2] = 0;
   out_7136053686395817561[3] = 1;
   out_7136053686395817561[4] = 0;
   out_7136053686395817561[5] = 0;
   out_7136053686395817561[6] = 0;
   out_7136053686395817561[7] = 0;
   out_7136053686395817561[8] = 0;
}
void h_29(double *state, double *unused, double *out_6874336043771097963) {
   out_6874336043771097963[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8625695731198916960) {
   out_8625695731198916960[0] = 0;
   out_8625695731198916960[1] = 1;
   out_8625695731198916960[2] = 0;
   out_8625695731198916960[3] = 0;
   out_8625695731198916960[4] = 0;
   out_8625695731198916960[5] = 0;
   out_8625695731198916960[6] = 0;
   out_8625695731198916960[7] = 0;
   out_8625695731198916960[8] = 0;
}
void h_28(double *state, double *unused, double *out_1452606651919304359) {
   out_1452606651919304359[0] = state[0];
}
void H_28(double *state, double *unused, double *out_340291942456735954) {
   out_340291942456735954[0] = 1;
   out_340291942456735954[1] = 0;
   out_340291942456735954[2] = 0;
   out_340291942456735954[3] = 0;
   out_340291942456735954[4] = 0;
   out_340291942456735954[5] = 0;
   out_340291942456735954[6] = 0;
   out_340291942456735954[7] = 0;
   out_340291942456735954[8] = 0;
}
void h_31(double *state, double *unused, double *out_4557978482014913700) {
   out_4557978482014913700[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2424772618581586145) {
   out_2424772618581586145[0] = 0;
   out_2424772618581586145[1] = 0;
   out_2424772618581586145[2] = 0;
   out_2424772618581586145[3] = 0;
   out_2424772618581586145[4] = 0;
   out_2424772618581586145[5] = 0;
   out_2424772618581586145[6] = 0;
   out_2424772618581586145[7] = 0;
   out_2424772618581586145[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7311248151803822396) {
  err_fun(nom_x, delta_x, out_7311248151803822396);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5602719869542378501) {
  inv_err_fun(nom_x, true_x, out_5602719869542378501);
}
void car_H_mod_fun(double *state, double *out_6859429191092688662) {
  H_mod_fun(state, out_6859429191092688662);
}
void car_f_fun(double *state, double dt, double *out_3400060270232460893) {
  f_fun(state,  dt, out_3400060270232460893);
}
void car_F_fun(double *state, double dt, double *out_6511275578440991802) {
  F_fun(state,  dt, out_6511275578440991802);
}
void car_h_25(double *state, double *unused, double *out_2633570630840598096) {
  h_25(state, unused, out_2633570630840598096);
}
void car_H_25(double *state, double *unused, double *out_2394126656704625717) {
  H_25(state, unused, out_2394126656704625717);
}
void car_h_24(double *state, double *unused, double *out_3094145344632818755) {
  h_24(state, unused, out_3094145344632818755);
}
void car_H_24(double *state, double *unused, double *out_665263537527311648) {
  H_24(state, unused, out_665263537527311648);
}
void car_h_30(double *state, double *unused, double *out_1872662776110252318) {
  h_30(state, unused, out_1872662776110252318);
}
void car_H_30(double *state, double *unused, double *out_9135927075513309144) {
  H_30(state, unused, out_9135927075513309144);
}
void car_h_26(double *state, double *unused, double *out_2552698139187979215) {
  h_26(state, unused, out_2552698139187979215);
}
void car_H_26(double *state, double *unused, double *out_1347376662169430507) {
  H_26(state, unused, out_1347376662169430507);
}
void car_h_27(double *state, double *unused, double *out_8276300501921554931) {
  h_27(state, unused, out_8276300501921554931);
}
void car_H_27(double *state, double *unused, double *out_7136053686395817561) {
  H_27(state, unused, out_7136053686395817561);
}
void car_h_29(double *state, double *unused, double *out_6874336043771097963) {
  h_29(state, unused, out_6874336043771097963);
}
void car_H_29(double *state, double *unused, double *out_8625695731198916960) {
  H_29(state, unused, out_8625695731198916960);
}
void car_h_28(double *state, double *unused, double *out_1452606651919304359) {
  h_28(state, unused, out_1452606651919304359);
}
void car_H_28(double *state, double *unused, double *out_340291942456735954) {
  H_28(state, unused, out_340291942456735954);
}
void car_h_31(double *state, double *unused, double *out_4557978482014913700) {
  h_31(state, unused, out_4557978482014913700);
}
void car_H_31(double *state, double *unused, double *out_2424772618581586145) {
  H_31(state, unused, out_2424772618581586145);
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
