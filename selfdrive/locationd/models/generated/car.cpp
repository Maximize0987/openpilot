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
void err_fun(double *nom_x, double *delta_x, double *out_8986378044421410730) {
   out_8986378044421410730[0] = delta_x[0] + nom_x[0];
   out_8986378044421410730[1] = delta_x[1] + nom_x[1];
   out_8986378044421410730[2] = delta_x[2] + nom_x[2];
   out_8986378044421410730[3] = delta_x[3] + nom_x[3];
   out_8986378044421410730[4] = delta_x[4] + nom_x[4];
   out_8986378044421410730[5] = delta_x[5] + nom_x[5];
   out_8986378044421410730[6] = delta_x[6] + nom_x[6];
   out_8986378044421410730[7] = delta_x[7] + nom_x[7];
   out_8986378044421410730[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1940910250995899848) {
   out_1940910250995899848[0] = -nom_x[0] + true_x[0];
   out_1940910250995899848[1] = -nom_x[1] + true_x[1];
   out_1940910250995899848[2] = -nom_x[2] + true_x[2];
   out_1940910250995899848[3] = -nom_x[3] + true_x[3];
   out_1940910250995899848[4] = -nom_x[4] + true_x[4];
   out_1940910250995899848[5] = -nom_x[5] + true_x[5];
   out_1940910250995899848[6] = -nom_x[6] + true_x[6];
   out_1940910250995899848[7] = -nom_x[7] + true_x[7];
   out_1940910250995899848[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1327881932680008443) {
   out_1327881932680008443[0] = 1.0;
   out_1327881932680008443[1] = 0.0;
   out_1327881932680008443[2] = 0.0;
   out_1327881932680008443[3] = 0.0;
   out_1327881932680008443[4] = 0.0;
   out_1327881932680008443[5] = 0.0;
   out_1327881932680008443[6] = 0.0;
   out_1327881932680008443[7] = 0.0;
   out_1327881932680008443[8] = 0.0;
   out_1327881932680008443[9] = 0.0;
   out_1327881932680008443[10] = 1.0;
   out_1327881932680008443[11] = 0.0;
   out_1327881932680008443[12] = 0.0;
   out_1327881932680008443[13] = 0.0;
   out_1327881932680008443[14] = 0.0;
   out_1327881932680008443[15] = 0.0;
   out_1327881932680008443[16] = 0.0;
   out_1327881932680008443[17] = 0.0;
   out_1327881932680008443[18] = 0.0;
   out_1327881932680008443[19] = 0.0;
   out_1327881932680008443[20] = 1.0;
   out_1327881932680008443[21] = 0.0;
   out_1327881932680008443[22] = 0.0;
   out_1327881932680008443[23] = 0.0;
   out_1327881932680008443[24] = 0.0;
   out_1327881932680008443[25] = 0.0;
   out_1327881932680008443[26] = 0.0;
   out_1327881932680008443[27] = 0.0;
   out_1327881932680008443[28] = 0.0;
   out_1327881932680008443[29] = 0.0;
   out_1327881932680008443[30] = 1.0;
   out_1327881932680008443[31] = 0.0;
   out_1327881932680008443[32] = 0.0;
   out_1327881932680008443[33] = 0.0;
   out_1327881932680008443[34] = 0.0;
   out_1327881932680008443[35] = 0.0;
   out_1327881932680008443[36] = 0.0;
   out_1327881932680008443[37] = 0.0;
   out_1327881932680008443[38] = 0.0;
   out_1327881932680008443[39] = 0.0;
   out_1327881932680008443[40] = 1.0;
   out_1327881932680008443[41] = 0.0;
   out_1327881932680008443[42] = 0.0;
   out_1327881932680008443[43] = 0.0;
   out_1327881932680008443[44] = 0.0;
   out_1327881932680008443[45] = 0.0;
   out_1327881932680008443[46] = 0.0;
   out_1327881932680008443[47] = 0.0;
   out_1327881932680008443[48] = 0.0;
   out_1327881932680008443[49] = 0.0;
   out_1327881932680008443[50] = 1.0;
   out_1327881932680008443[51] = 0.0;
   out_1327881932680008443[52] = 0.0;
   out_1327881932680008443[53] = 0.0;
   out_1327881932680008443[54] = 0.0;
   out_1327881932680008443[55] = 0.0;
   out_1327881932680008443[56] = 0.0;
   out_1327881932680008443[57] = 0.0;
   out_1327881932680008443[58] = 0.0;
   out_1327881932680008443[59] = 0.0;
   out_1327881932680008443[60] = 1.0;
   out_1327881932680008443[61] = 0.0;
   out_1327881932680008443[62] = 0.0;
   out_1327881932680008443[63] = 0.0;
   out_1327881932680008443[64] = 0.0;
   out_1327881932680008443[65] = 0.0;
   out_1327881932680008443[66] = 0.0;
   out_1327881932680008443[67] = 0.0;
   out_1327881932680008443[68] = 0.0;
   out_1327881932680008443[69] = 0.0;
   out_1327881932680008443[70] = 1.0;
   out_1327881932680008443[71] = 0.0;
   out_1327881932680008443[72] = 0.0;
   out_1327881932680008443[73] = 0.0;
   out_1327881932680008443[74] = 0.0;
   out_1327881932680008443[75] = 0.0;
   out_1327881932680008443[76] = 0.0;
   out_1327881932680008443[77] = 0.0;
   out_1327881932680008443[78] = 0.0;
   out_1327881932680008443[79] = 0.0;
   out_1327881932680008443[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7832214154397608531) {
   out_7832214154397608531[0] = state[0];
   out_7832214154397608531[1] = state[1];
   out_7832214154397608531[2] = state[2];
   out_7832214154397608531[3] = state[3];
   out_7832214154397608531[4] = state[4];
   out_7832214154397608531[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7832214154397608531[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7832214154397608531[7] = state[7];
   out_7832214154397608531[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4114606570946988857) {
   out_4114606570946988857[0] = 1;
   out_4114606570946988857[1] = 0;
   out_4114606570946988857[2] = 0;
   out_4114606570946988857[3] = 0;
   out_4114606570946988857[4] = 0;
   out_4114606570946988857[5] = 0;
   out_4114606570946988857[6] = 0;
   out_4114606570946988857[7] = 0;
   out_4114606570946988857[8] = 0;
   out_4114606570946988857[9] = 0;
   out_4114606570946988857[10] = 1;
   out_4114606570946988857[11] = 0;
   out_4114606570946988857[12] = 0;
   out_4114606570946988857[13] = 0;
   out_4114606570946988857[14] = 0;
   out_4114606570946988857[15] = 0;
   out_4114606570946988857[16] = 0;
   out_4114606570946988857[17] = 0;
   out_4114606570946988857[18] = 0;
   out_4114606570946988857[19] = 0;
   out_4114606570946988857[20] = 1;
   out_4114606570946988857[21] = 0;
   out_4114606570946988857[22] = 0;
   out_4114606570946988857[23] = 0;
   out_4114606570946988857[24] = 0;
   out_4114606570946988857[25] = 0;
   out_4114606570946988857[26] = 0;
   out_4114606570946988857[27] = 0;
   out_4114606570946988857[28] = 0;
   out_4114606570946988857[29] = 0;
   out_4114606570946988857[30] = 1;
   out_4114606570946988857[31] = 0;
   out_4114606570946988857[32] = 0;
   out_4114606570946988857[33] = 0;
   out_4114606570946988857[34] = 0;
   out_4114606570946988857[35] = 0;
   out_4114606570946988857[36] = 0;
   out_4114606570946988857[37] = 0;
   out_4114606570946988857[38] = 0;
   out_4114606570946988857[39] = 0;
   out_4114606570946988857[40] = 1;
   out_4114606570946988857[41] = 0;
   out_4114606570946988857[42] = 0;
   out_4114606570946988857[43] = 0;
   out_4114606570946988857[44] = 0;
   out_4114606570946988857[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4114606570946988857[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4114606570946988857[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4114606570946988857[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4114606570946988857[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4114606570946988857[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4114606570946988857[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4114606570946988857[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4114606570946988857[53] = -9.8100000000000005*dt;
   out_4114606570946988857[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4114606570946988857[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4114606570946988857[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4114606570946988857[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4114606570946988857[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4114606570946988857[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4114606570946988857[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4114606570946988857[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4114606570946988857[62] = 0;
   out_4114606570946988857[63] = 0;
   out_4114606570946988857[64] = 0;
   out_4114606570946988857[65] = 0;
   out_4114606570946988857[66] = 0;
   out_4114606570946988857[67] = 0;
   out_4114606570946988857[68] = 0;
   out_4114606570946988857[69] = 0;
   out_4114606570946988857[70] = 1;
   out_4114606570946988857[71] = 0;
   out_4114606570946988857[72] = 0;
   out_4114606570946988857[73] = 0;
   out_4114606570946988857[74] = 0;
   out_4114606570946988857[75] = 0;
   out_4114606570946988857[76] = 0;
   out_4114606570946988857[77] = 0;
   out_4114606570946988857[78] = 0;
   out_4114606570946988857[79] = 0;
   out_4114606570946988857[80] = 1;
}
void h_25(double *state, double *unused, double *out_8263447783360605785) {
   out_8263447783360605785[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5780776564353391637) {
   out_5780776564353391637[0] = 0;
   out_5780776564353391637[1] = 0;
   out_5780776564353391637[2] = 0;
   out_5780776564353391637[3] = 0;
   out_5780776564353391637[4] = 0;
   out_5780776564353391637[5] = 0;
   out_5780776564353391637[6] = 1;
   out_5780776564353391637[7] = 0;
   out_5780776564353391637[8] = 0;
}
void h_24(double *state, double *unused, double *out_4755010794979530940) {
   out_4755010794979530940[0] = state[4];
   out_4755010794979530940[1] = state[5];
}
void H_24(double *state, double *unused, double *out_9108041910553836843) {
   out_9108041910553836843[0] = 0;
   out_9108041910553836843[1] = 0;
   out_9108041910553836843[2] = 0;
   out_9108041910553836843[3] = 0;
   out_9108041910553836843[4] = 1;
   out_9108041910553836843[5] = 0;
   out_9108041910553836843[6] = 0;
   out_9108041910553836843[7] = 0;
   out_9108041910553836843[8] = 0;
   out_9108041910553836843[9] = 0;
   out_9108041910553836843[10] = 0;
   out_9108041910553836843[11] = 0;
   out_9108041910553836843[12] = 0;
   out_9108041910553836843[13] = 0;
   out_9108041910553836843[14] = 1;
   out_9108041910553836843[15] = 0;
   out_9108041910553836843[16] = 0;
   out_9108041910553836843[17] = 0;
}
void h_30(double *state, double *unused, double *out_6812816390731722618) {
   out_6812816390731722618[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5749277167864543224) {
   out_5749277167864543224[0] = 0;
   out_5749277167864543224[1] = 0;
   out_5749277167864543224[2] = 0;
   out_5749277167864543224[3] = 0;
   out_5749277167864543224[4] = 1;
   out_5749277167864543224[5] = 0;
   out_5749277167864543224[6] = 0;
   out_5749277167864543224[7] = 0;
   out_5749277167864543224[8] = 0;
}
void h_26(double *state, double *unused, double *out_4631164979184763219) {
   out_4631164979184763219[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2039273245479335413) {
   out_2039273245479335413[0] = 0;
   out_2039273245479335413[1] = 0;
   out_2039273245479335413[2] = 0;
   out_2039273245479335413[3] = 0;
   out_2039273245479335413[4] = 0;
   out_2039273245479335413[5] = 0;
   out_2039273245479335413[6] = 0;
   out_2039273245479335413[7] = 1;
   out_2039273245479335413[8] = 0;
}
void h_27(double *state, double *unused, double *out_6907448477601489242) {
   out_6907448477601489242[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7924040479664968135) {
   out_7924040479664968135[0] = 0;
   out_7924040479664968135[1] = 0;
   out_7924040479664968135[2] = 0;
   out_7924040479664968135[3] = 1;
   out_7924040479664968135[4] = 0;
   out_7924040479664968135[5] = 0;
   out_7924040479664968135[6] = 0;
   out_7924040479664968135[7] = 0;
   out_7924040479664968135[8] = 0;
}
void h_29(double *state, double *unused, double *out_6632254415316983353) {
   out_6632254415316983353[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5239045823550151040) {
   out_5239045823550151040[0] = 0;
   out_5239045823550151040[1] = 1;
   out_5239045823550151040[2] = 0;
   out_5239045823550151040[3] = 0;
   out_5239045823550151040[4] = 0;
   out_5239045823550151040[5] = 0;
   out_5239045823550151040[6] = 0;
   out_5239045823550151040[7] = 0;
   out_5239045823550151040[8] = 0;
}
void h_28(double *state, double *unused, double *out_4283151879014610665) {
   out_4283151879014610665[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8125299233089870002) {
   out_8125299233089870002[0] = 1;
   out_8125299233089870002[1] = 0;
   out_8125299233089870002[2] = 0;
   out_8125299233089870002[3] = 0;
   out_8125299233089870002[4] = 0;
   out_8125299233089870002[5] = 0;
   out_8125299233089870002[6] = 0;
   out_8125299233089870002[7] = 0;
   out_8125299233089870002[8] = 0;
}
void h_31(double *state, double *unused, double *out_7988253721076099896) {
   out_7988253721076099896[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5811422526230352065) {
   out_5811422526230352065[0] = 0;
   out_5811422526230352065[1] = 0;
   out_5811422526230352065[2] = 0;
   out_5811422526230352065[3] = 0;
   out_5811422526230352065[4] = 0;
   out_5811422526230352065[5] = 0;
   out_5811422526230352065[6] = 0;
   out_5811422526230352065[7] = 0;
   out_5811422526230352065[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8986378044421410730) {
  err_fun(nom_x, delta_x, out_8986378044421410730);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1940910250995899848) {
  inv_err_fun(nom_x, true_x, out_1940910250995899848);
}
void car_H_mod_fun(double *state, double *out_1327881932680008443) {
  H_mod_fun(state, out_1327881932680008443);
}
void car_f_fun(double *state, double dt, double *out_7832214154397608531) {
  f_fun(state,  dt, out_7832214154397608531);
}
void car_F_fun(double *state, double dt, double *out_4114606570946988857) {
  F_fun(state,  dt, out_4114606570946988857);
}
void car_h_25(double *state, double *unused, double *out_8263447783360605785) {
  h_25(state, unused, out_8263447783360605785);
}
void car_H_25(double *state, double *unused, double *out_5780776564353391637) {
  H_25(state, unused, out_5780776564353391637);
}
void car_h_24(double *state, double *unused, double *out_4755010794979530940) {
  h_24(state, unused, out_4755010794979530940);
}
void car_H_24(double *state, double *unused, double *out_9108041910553836843) {
  H_24(state, unused, out_9108041910553836843);
}
void car_h_30(double *state, double *unused, double *out_6812816390731722618) {
  h_30(state, unused, out_6812816390731722618);
}
void car_H_30(double *state, double *unused, double *out_5749277167864543224) {
  H_30(state, unused, out_5749277167864543224);
}
void car_h_26(double *state, double *unused, double *out_4631164979184763219) {
  h_26(state, unused, out_4631164979184763219);
}
void car_H_26(double *state, double *unused, double *out_2039273245479335413) {
  H_26(state, unused, out_2039273245479335413);
}
void car_h_27(double *state, double *unused, double *out_6907448477601489242) {
  h_27(state, unused, out_6907448477601489242);
}
void car_H_27(double *state, double *unused, double *out_7924040479664968135) {
  H_27(state, unused, out_7924040479664968135);
}
void car_h_29(double *state, double *unused, double *out_6632254415316983353) {
  h_29(state, unused, out_6632254415316983353);
}
void car_H_29(double *state, double *unused, double *out_5239045823550151040) {
  H_29(state, unused, out_5239045823550151040);
}
void car_h_28(double *state, double *unused, double *out_4283151879014610665) {
  h_28(state, unused, out_4283151879014610665);
}
void car_H_28(double *state, double *unused, double *out_8125299233089870002) {
  H_28(state, unused, out_8125299233089870002);
}
void car_h_31(double *state, double *unused, double *out_7988253721076099896) {
  h_31(state, unused, out_7988253721076099896);
}
void car_H_31(double *state, double *unused, double *out_5811422526230352065) {
  H_31(state, unused, out_5811422526230352065);
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
