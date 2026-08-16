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
void err_fun(double *nom_x, double *delta_x, double *out_3350045275544931453) {
   out_3350045275544931453[0] = delta_x[0] + nom_x[0];
   out_3350045275544931453[1] = delta_x[1] + nom_x[1];
   out_3350045275544931453[2] = delta_x[2] + nom_x[2];
   out_3350045275544931453[3] = delta_x[3] + nom_x[3];
   out_3350045275544931453[4] = delta_x[4] + nom_x[4];
   out_3350045275544931453[5] = delta_x[5] + nom_x[5];
   out_3350045275544931453[6] = delta_x[6] + nom_x[6];
   out_3350045275544931453[7] = delta_x[7] + nom_x[7];
   out_3350045275544931453[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_537147974555085981) {
   out_537147974555085981[0] = -nom_x[0] + true_x[0];
   out_537147974555085981[1] = -nom_x[1] + true_x[1];
   out_537147974555085981[2] = -nom_x[2] + true_x[2];
   out_537147974555085981[3] = -nom_x[3] + true_x[3];
   out_537147974555085981[4] = -nom_x[4] + true_x[4];
   out_537147974555085981[5] = -nom_x[5] + true_x[5];
   out_537147974555085981[6] = -nom_x[6] + true_x[6];
   out_537147974555085981[7] = -nom_x[7] + true_x[7];
   out_537147974555085981[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7775026745617319605) {
   out_7775026745617319605[0] = 1.0;
   out_7775026745617319605[1] = 0.0;
   out_7775026745617319605[2] = 0.0;
   out_7775026745617319605[3] = 0.0;
   out_7775026745617319605[4] = 0.0;
   out_7775026745617319605[5] = 0.0;
   out_7775026745617319605[6] = 0.0;
   out_7775026745617319605[7] = 0.0;
   out_7775026745617319605[8] = 0.0;
   out_7775026745617319605[9] = 0.0;
   out_7775026745617319605[10] = 1.0;
   out_7775026745617319605[11] = 0.0;
   out_7775026745617319605[12] = 0.0;
   out_7775026745617319605[13] = 0.0;
   out_7775026745617319605[14] = 0.0;
   out_7775026745617319605[15] = 0.0;
   out_7775026745617319605[16] = 0.0;
   out_7775026745617319605[17] = 0.0;
   out_7775026745617319605[18] = 0.0;
   out_7775026745617319605[19] = 0.0;
   out_7775026745617319605[20] = 1.0;
   out_7775026745617319605[21] = 0.0;
   out_7775026745617319605[22] = 0.0;
   out_7775026745617319605[23] = 0.0;
   out_7775026745617319605[24] = 0.0;
   out_7775026745617319605[25] = 0.0;
   out_7775026745617319605[26] = 0.0;
   out_7775026745617319605[27] = 0.0;
   out_7775026745617319605[28] = 0.0;
   out_7775026745617319605[29] = 0.0;
   out_7775026745617319605[30] = 1.0;
   out_7775026745617319605[31] = 0.0;
   out_7775026745617319605[32] = 0.0;
   out_7775026745617319605[33] = 0.0;
   out_7775026745617319605[34] = 0.0;
   out_7775026745617319605[35] = 0.0;
   out_7775026745617319605[36] = 0.0;
   out_7775026745617319605[37] = 0.0;
   out_7775026745617319605[38] = 0.0;
   out_7775026745617319605[39] = 0.0;
   out_7775026745617319605[40] = 1.0;
   out_7775026745617319605[41] = 0.0;
   out_7775026745617319605[42] = 0.0;
   out_7775026745617319605[43] = 0.0;
   out_7775026745617319605[44] = 0.0;
   out_7775026745617319605[45] = 0.0;
   out_7775026745617319605[46] = 0.0;
   out_7775026745617319605[47] = 0.0;
   out_7775026745617319605[48] = 0.0;
   out_7775026745617319605[49] = 0.0;
   out_7775026745617319605[50] = 1.0;
   out_7775026745617319605[51] = 0.0;
   out_7775026745617319605[52] = 0.0;
   out_7775026745617319605[53] = 0.0;
   out_7775026745617319605[54] = 0.0;
   out_7775026745617319605[55] = 0.0;
   out_7775026745617319605[56] = 0.0;
   out_7775026745617319605[57] = 0.0;
   out_7775026745617319605[58] = 0.0;
   out_7775026745617319605[59] = 0.0;
   out_7775026745617319605[60] = 1.0;
   out_7775026745617319605[61] = 0.0;
   out_7775026745617319605[62] = 0.0;
   out_7775026745617319605[63] = 0.0;
   out_7775026745617319605[64] = 0.0;
   out_7775026745617319605[65] = 0.0;
   out_7775026745617319605[66] = 0.0;
   out_7775026745617319605[67] = 0.0;
   out_7775026745617319605[68] = 0.0;
   out_7775026745617319605[69] = 0.0;
   out_7775026745617319605[70] = 1.0;
   out_7775026745617319605[71] = 0.0;
   out_7775026745617319605[72] = 0.0;
   out_7775026745617319605[73] = 0.0;
   out_7775026745617319605[74] = 0.0;
   out_7775026745617319605[75] = 0.0;
   out_7775026745617319605[76] = 0.0;
   out_7775026745617319605[77] = 0.0;
   out_7775026745617319605[78] = 0.0;
   out_7775026745617319605[79] = 0.0;
   out_7775026745617319605[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4198835588916233412) {
   out_4198835588916233412[0] = state[0];
   out_4198835588916233412[1] = state[1];
   out_4198835588916233412[2] = state[2];
   out_4198835588916233412[3] = state[3];
   out_4198835588916233412[4] = state[4];
   out_4198835588916233412[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4198835588916233412[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4198835588916233412[7] = state[7];
   out_4198835588916233412[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4444349682340675673) {
   out_4444349682340675673[0] = 1;
   out_4444349682340675673[1] = 0;
   out_4444349682340675673[2] = 0;
   out_4444349682340675673[3] = 0;
   out_4444349682340675673[4] = 0;
   out_4444349682340675673[5] = 0;
   out_4444349682340675673[6] = 0;
   out_4444349682340675673[7] = 0;
   out_4444349682340675673[8] = 0;
   out_4444349682340675673[9] = 0;
   out_4444349682340675673[10] = 1;
   out_4444349682340675673[11] = 0;
   out_4444349682340675673[12] = 0;
   out_4444349682340675673[13] = 0;
   out_4444349682340675673[14] = 0;
   out_4444349682340675673[15] = 0;
   out_4444349682340675673[16] = 0;
   out_4444349682340675673[17] = 0;
   out_4444349682340675673[18] = 0;
   out_4444349682340675673[19] = 0;
   out_4444349682340675673[20] = 1;
   out_4444349682340675673[21] = 0;
   out_4444349682340675673[22] = 0;
   out_4444349682340675673[23] = 0;
   out_4444349682340675673[24] = 0;
   out_4444349682340675673[25] = 0;
   out_4444349682340675673[26] = 0;
   out_4444349682340675673[27] = 0;
   out_4444349682340675673[28] = 0;
   out_4444349682340675673[29] = 0;
   out_4444349682340675673[30] = 1;
   out_4444349682340675673[31] = 0;
   out_4444349682340675673[32] = 0;
   out_4444349682340675673[33] = 0;
   out_4444349682340675673[34] = 0;
   out_4444349682340675673[35] = 0;
   out_4444349682340675673[36] = 0;
   out_4444349682340675673[37] = 0;
   out_4444349682340675673[38] = 0;
   out_4444349682340675673[39] = 0;
   out_4444349682340675673[40] = 1;
   out_4444349682340675673[41] = 0;
   out_4444349682340675673[42] = 0;
   out_4444349682340675673[43] = 0;
   out_4444349682340675673[44] = 0;
   out_4444349682340675673[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4444349682340675673[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4444349682340675673[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4444349682340675673[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4444349682340675673[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4444349682340675673[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4444349682340675673[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4444349682340675673[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4444349682340675673[53] = -9.8100000000000005*dt;
   out_4444349682340675673[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4444349682340675673[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4444349682340675673[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4444349682340675673[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4444349682340675673[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4444349682340675673[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4444349682340675673[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4444349682340675673[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4444349682340675673[62] = 0;
   out_4444349682340675673[63] = 0;
   out_4444349682340675673[64] = 0;
   out_4444349682340675673[65] = 0;
   out_4444349682340675673[66] = 0;
   out_4444349682340675673[67] = 0;
   out_4444349682340675673[68] = 0;
   out_4444349682340675673[69] = 0;
   out_4444349682340675673[70] = 1;
   out_4444349682340675673[71] = 0;
   out_4444349682340675673[72] = 0;
   out_4444349682340675673[73] = 0;
   out_4444349682340675673[74] = 0;
   out_4444349682340675673[75] = 0;
   out_4444349682340675673[76] = 0;
   out_4444349682340675673[77] = 0;
   out_4444349682340675673[78] = 0;
   out_4444349682340675673[79] = 0;
   out_4444349682340675673[80] = 1;
}
void h_25(double *state, double *unused, double *out_6936843442256047922) {
   out_6936843442256047922[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1418161480294917632) {
   out_1418161480294917632[0] = 0;
   out_1418161480294917632[1] = 0;
   out_1418161480294917632[2] = 0;
   out_1418161480294917632[3] = 0;
   out_1418161480294917632[4] = 0;
   out_1418161480294917632[5] = 0;
   out_1418161480294917632[6] = 1;
   out_1418161480294917632[7] = 0;
   out_1418161480294917632[8] = 0;
}
void h_24(double *state, double *unused, double *out_5320826123735066091) {
   out_5320826123735066091[0] = state[4];
   out_5320826123735066091[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6164670807261426666) {
   out_6164670807261426666[0] = 0;
   out_6164670807261426666[1] = 0;
   out_6164670807261426666[2] = 0;
   out_6164670807261426666[3] = 0;
   out_6164670807261426666[4] = 1;
   out_6164670807261426666[5] = 0;
   out_6164670807261426666[6] = 0;
   out_6164670807261426666[7] = 0;
   out_6164670807261426666[8] = 0;
   out_6164670807261426666[9] = 0;
   out_6164670807261426666[10] = 0;
   out_6164670807261426666[11] = 0;
   out_6164670807261426666[12] = 0;
   out_6164670807261426666[13] = 0;
   out_6164670807261426666[14] = 1;
   out_6164670807261426666[15] = 0;
   out_6164670807261426666[16] = 0;
   out_6164670807261426666[17] = 0;
}
void h_30(double *state, double *unused, double *out_956096052628475437) {
   out_956096052628475437[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1100171478212330995) {
   out_1100171478212330995[0] = 0;
   out_1100171478212330995[1] = 0;
   out_1100171478212330995[2] = 0;
   out_1100171478212330995[3] = 0;
   out_1100171478212330995[4] = 1;
   out_1100171478212330995[5] = 0;
   out_1100171478212330995[6] = 0;
   out_1100171478212330995[7] = 0;
   out_1100171478212330995[8] = 0;
}
void h_26(double *state, double *unused, double *out_1856456050641377946) {
   out_1856456050641377946[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1886364489465882969) {
   out_1886364489465882969[0] = 0;
   out_1886364489465882969[1] = 0;
   out_1886364489465882969[2] = 0;
   out_1886364489465882969[3] = 0;
   out_1886364489465882969[4] = 0;
   out_1886364489465882969[5] = 0;
   out_1886364489465882969[6] = 0;
   out_1886364489465882969[7] = 1;
   out_1886364489465882969[8] = 0;
}
void h_27(double *state, double *unused, double *out_6508227363792658049) {
   out_6508227363792658049[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3323765549396274212) {
   out_3323765549396274212[0] = 0;
   out_3323765549396274212[1] = 0;
   out_3323765549396274212[2] = 0;
   out_3323765549396274212[3] = 1;
   out_3323765549396274212[4] = 0;
   out_3323765549396274212[5] = 0;
   out_3323765549396274212[6] = 0;
   out_3323765549396274212[7] = 0;
   out_3323765549396274212[8] = 0;
}
void h_29(double *state, double *unused, double *out_3441856028653153575) {
   out_3441856028653153575[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1610402822526723179) {
   out_1610402822526723179[0] = 0;
   out_1610402822526723179[1] = 1;
   out_1610402822526723179[2] = 0;
   out_1610402822526723179[3] = 0;
   out_1610402822526723179[4] = 0;
   out_1610402822526723179[5] = 0;
   out_1610402822526723179[6] = 0;
   out_1610402822526723179[7] = 0;
   out_1610402822526723179[8] = 0;
}
void h_28(double *state, double *unused, double *out_8901730658472560882) {
   out_8901730658472560882[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3471996194542807395) {
   out_3471996194542807395[0] = 1;
   out_3471996194542807395[1] = 0;
   out_3471996194542807395[2] = 0;
   out_3471996194542807395[3] = 0;
   out_3471996194542807395[4] = 0;
   out_3471996194542807395[5] = 0;
   out_3471996194542807395[6] = 0;
   out_3471996194542807395[7] = 0;
   out_3471996194542807395[8] = 0;
}
void h_31(double *state, double *unused, double *out_6661649379971542033) {
   out_6661649379971542033[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1260156387232531493) {
   out_1260156387232531493[0] = 0;
   out_1260156387232531493[1] = 0;
   out_1260156387232531493[2] = 0;
   out_1260156387232531493[3] = 0;
   out_1260156387232531493[4] = 0;
   out_1260156387232531493[5] = 0;
   out_1260156387232531493[6] = 0;
   out_1260156387232531493[7] = 0;
   out_1260156387232531493[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3350045275544931453) {
  err_fun(nom_x, delta_x, out_3350045275544931453);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_537147974555085981) {
  inv_err_fun(nom_x, true_x, out_537147974555085981);
}
void car_H_mod_fun(double *state, double *out_7775026745617319605) {
  H_mod_fun(state, out_7775026745617319605);
}
void car_f_fun(double *state, double dt, double *out_4198835588916233412) {
  f_fun(state,  dt, out_4198835588916233412);
}
void car_F_fun(double *state, double dt, double *out_4444349682340675673) {
  F_fun(state,  dt, out_4444349682340675673);
}
void car_h_25(double *state, double *unused, double *out_6936843442256047922) {
  h_25(state, unused, out_6936843442256047922);
}
void car_H_25(double *state, double *unused, double *out_1418161480294917632) {
  H_25(state, unused, out_1418161480294917632);
}
void car_h_24(double *state, double *unused, double *out_5320826123735066091) {
  h_24(state, unused, out_5320826123735066091);
}
void car_H_24(double *state, double *unused, double *out_6164670807261426666) {
  H_24(state, unused, out_6164670807261426666);
}
void car_h_30(double *state, double *unused, double *out_956096052628475437) {
  h_30(state, unused, out_956096052628475437);
}
void car_H_30(double *state, double *unused, double *out_1100171478212330995) {
  H_30(state, unused, out_1100171478212330995);
}
void car_h_26(double *state, double *unused, double *out_1856456050641377946) {
  h_26(state, unused, out_1856456050641377946);
}
void car_H_26(double *state, double *unused, double *out_1886364489465882969) {
  H_26(state, unused, out_1886364489465882969);
}
void car_h_27(double *state, double *unused, double *out_6508227363792658049) {
  h_27(state, unused, out_6508227363792658049);
}
void car_H_27(double *state, double *unused, double *out_3323765549396274212) {
  H_27(state, unused, out_3323765549396274212);
}
void car_h_29(double *state, double *unused, double *out_3441856028653153575) {
  h_29(state, unused, out_3441856028653153575);
}
void car_H_29(double *state, double *unused, double *out_1610402822526723179) {
  H_29(state, unused, out_1610402822526723179);
}
void car_h_28(double *state, double *unused, double *out_8901730658472560882) {
  h_28(state, unused, out_8901730658472560882);
}
void car_H_28(double *state, double *unused, double *out_3471996194542807395) {
  H_28(state, unused, out_3471996194542807395);
}
void car_h_31(double *state, double *unused, double *out_6661649379971542033) {
  h_31(state, unused, out_6661649379971542033);
}
void car_H_31(double *state, double *unused, double *out_1260156387232531493) {
  H_31(state, unused, out_1260156387232531493);
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
