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
void err_fun(double *nom_x, double *delta_x, double *out_3970546799234288025) {
   out_3970546799234288025[0] = delta_x[0] + nom_x[0];
   out_3970546799234288025[1] = delta_x[1] + nom_x[1];
   out_3970546799234288025[2] = delta_x[2] + nom_x[2];
   out_3970546799234288025[3] = delta_x[3] + nom_x[3];
   out_3970546799234288025[4] = delta_x[4] + nom_x[4];
   out_3970546799234288025[5] = delta_x[5] + nom_x[5];
   out_3970546799234288025[6] = delta_x[6] + nom_x[6];
   out_3970546799234288025[7] = delta_x[7] + nom_x[7];
   out_3970546799234288025[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2567718075778826550) {
   out_2567718075778826550[0] = -nom_x[0] + true_x[0];
   out_2567718075778826550[1] = -nom_x[1] + true_x[1];
   out_2567718075778826550[2] = -nom_x[2] + true_x[2];
   out_2567718075778826550[3] = -nom_x[3] + true_x[3];
   out_2567718075778826550[4] = -nom_x[4] + true_x[4];
   out_2567718075778826550[5] = -nom_x[5] + true_x[5];
   out_2567718075778826550[6] = -nom_x[6] + true_x[6];
   out_2567718075778826550[7] = -nom_x[7] + true_x[7];
   out_2567718075778826550[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1717749627572306313) {
   out_1717749627572306313[0] = 1.0;
   out_1717749627572306313[1] = 0.0;
   out_1717749627572306313[2] = 0.0;
   out_1717749627572306313[3] = 0.0;
   out_1717749627572306313[4] = 0.0;
   out_1717749627572306313[5] = 0.0;
   out_1717749627572306313[6] = 0.0;
   out_1717749627572306313[7] = 0.0;
   out_1717749627572306313[8] = 0.0;
   out_1717749627572306313[9] = 0.0;
   out_1717749627572306313[10] = 1.0;
   out_1717749627572306313[11] = 0.0;
   out_1717749627572306313[12] = 0.0;
   out_1717749627572306313[13] = 0.0;
   out_1717749627572306313[14] = 0.0;
   out_1717749627572306313[15] = 0.0;
   out_1717749627572306313[16] = 0.0;
   out_1717749627572306313[17] = 0.0;
   out_1717749627572306313[18] = 0.0;
   out_1717749627572306313[19] = 0.0;
   out_1717749627572306313[20] = 1.0;
   out_1717749627572306313[21] = 0.0;
   out_1717749627572306313[22] = 0.0;
   out_1717749627572306313[23] = 0.0;
   out_1717749627572306313[24] = 0.0;
   out_1717749627572306313[25] = 0.0;
   out_1717749627572306313[26] = 0.0;
   out_1717749627572306313[27] = 0.0;
   out_1717749627572306313[28] = 0.0;
   out_1717749627572306313[29] = 0.0;
   out_1717749627572306313[30] = 1.0;
   out_1717749627572306313[31] = 0.0;
   out_1717749627572306313[32] = 0.0;
   out_1717749627572306313[33] = 0.0;
   out_1717749627572306313[34] = 0.0;
   out_1717749627572306313[35] = 0.0;
   out_1717749627572306313[36] = 0.0;
   out_1717749627572306313[37] = 0.0;
   out_1717749627572306313[38] = 0.0;
   out_1717749627572306313[39] = 0.0;
   out_1717749627572306313[40] = 1.0;
   out_1717749627572306313[41] = 0.0;
   out_1717749627572306313[42] = 0.0;
   out_1717749627572306313[43] = 0.0;
   out_1717749627572306313[44] = 0.0;
   out_1717749627572306313[45] = 0.0;
   out_1717749627572306313[46] = 0.0;
   out_1717749627572306313[47] = 0.0;
   out_1717749627572306313[48] = 0.0;
   out_1717749627572306313[49] = 0.0;
   out_1717749627572306313[50] = 1.0;
   out_1717749627572306313[51] = 0.0;
   out_1717749627572306313[52] = 0.0;
   out_1717749627572306313[53] = 0.0;
   out_1717749627572306313[54] = 0.0;
   out_1717749627572306313[55] = 0.0;
   out_1717749627572306313[56] = 0.0;
   out_1717749627572306313[57] = 0.0;
   out_1717749627572306313[58] = 0.0;
   out_1717749627572306313[59] = 0.0;
   out_1717749627572306313[60] = 1.0;
   out_1717749627572306313[61] = 0.0;
   out_1717749627572306313[62] = 0.0;
   out_1717749627572306313[63] = 0.0;
   out_1717749627572306313[64] = 0.0;
   out_1717749627572306313[65] = 0.0;
   out_1717749627572306313[66] = 0.0;
   out_1717749627572306313[67] = 0.0;
   out_1717749627572306313[68] = 0.0;
   out_1717749627572306313[69] = 0.0;
   out_1717749627572306313[70] = 1.0;
   out_1717749627572306313[71] = 0.0;
   out_1717749627572306313[72] = 0.0;
   out_1717749627572306313[73] = 0.0;
   out_1717749627572306313[74] = 0.0;
   out_1717749627572306313[75] = 0.0;
   out_1717749627572306313[76] = 0.0;
   out_1717749627572306313[77] = 0.0;
   out_1717749627572306313[78] = 0.0;
   out_1717749627572306313[79] = 0.0;
   out_1717749627572306313[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4680969065089583930) {
   out_4680969065089583930[0] = state[0];
   out_4680969065089583930[1] = state[1];
   out_4680969065089583930[2] = state[2];
   out_4680969065089583930[3] = state[3];
   out_4680969065089583930[4] = state[4];
   out_4680969065089583930[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4680969065089583930[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4680969065089583930[7] = state[7];
   out_4680969065089583930[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6937343164270022068) {
   out_6937343164270022068[0] = 1;
   out_6937343164270022068[1] = 0;
   out_6937343164270022068[2] = 0;
   out_6937343164270022068[3] = 0;
   out_6937343164270022068[4] = 0;
   out_6937343164270022068[5] = 0;
   out_6937343164270022068[6] = 0;
   out_6937343164270022068[7] = 0;
   out_6937343164270022068[8] = 0;
   out_6937343164270022068[9] = 0;
   out_6937343164270022068[10] = 1;
   out_6937343164270022068[11] = 0;
   out_6937343164270022068[12] = 0;
   out_6937343164270022068[13] = 0;
   out_6937343164270022068[14] = 0;
   out_6937343164270022068[15] = 0;
   out_6937343164270022068[16] = 0;
   out_6937343164270022068[17] = 0;
   out_6937343164270022068[18] = 0;
   out_6937343164270022068[19] = 0;
   out_6937343164270022068[20] = 1;
   out_6937343164270022068[21] = 0;
   out_6937343164270022068[22] = 0;
   out_6937343164270022068[23] = 0;
   out_6937343164270022068[24] = 0;
   out_6937343164270022068[25] = 0;
   out_6937343164270022068[26] = 0;
   out_6937343164270022068[27] = 0;
   out_6937343164270022068[28] = 0;
   out_6937343164270022068[29] = 0;
   out_6937343164270022068[30] = 1;
   out_6937343164270022068[31] = 0;
   out_6937343164270022068[32] = 0;
   out_6937343164270022068[33] = 0;
   out_6937343164270022068[34] = 0;
   out_6937343164270022068[35] = 0;
   out_6937343164270022068[36] = 0;
   out_6937343164270022068[37] = 0;
   out_6937343164270022068[38] = 0;
   out_6937343164270022068[39] = 0;
   out_6937343164270022068[40] = 1;
   out_6937343164270022068[41] = 0;
   out_6937343164270022068[42] = 0;
   out_6937343164270022068[43] = 0;
   out_6937343164270022068[44] = 0;
   out_6937343164270022068[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6937343164270022068[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6937343164270022068[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6937343164270022068[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6937343164270022068[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6937343164270022068[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6937343164270022068[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6937343164270022068[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6937343164270022068[53] = -9.8100000000000005*dt;
   out_6937343164270022068[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6937343164270022068[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6937343164270022068[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6937343164270022068[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6937343164270022068[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6937343164270022068[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6937343164270022068[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6937343164270022068[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6937343164270022068[62] = 0;
   out_6937343164270022068[63] = 0;
   out_6937343164270022068[64] = 0;
   out_6937343164270022068[65] = 0;
   out_6937343164270022068[66] = 0;
   out_6937343164270022068[67] = 0;
   out_6937343164270022068[68] = 0;
   out_6937343164270022068[69] = 0;
   out_6937343164270022068[70] = 1;
   out_6937343164270022068[71] = 0;
   out_6937343164270022068[72] = 0;
   out_6937343164270022068[73] = 0;
   out_6937343164270022068[74] = 0;
   out_6937343164270022068[75] = 0;
   out_6937343164270022068[76] = 0;
   out_6937343164270022068[77] = 0;
   out_6937343164270022068[78] = 0;
   out_6937343164270022068[79] = 0;
   out_6937343164270022068[80] = 1;
}
void h_25(double *state, double *unused, double *out_5928605043652166783) {
   out_5928605043652166783[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8807656413163385498) {
   out_8807656413163385498[0] = 0;
   out_8807656413163385498[1] = 0;
   out_8807656413163385498[2] = 0;
   out_8807656413163385498[3] = 0;
   out_8807656413163385498[4] = 0;
   out_8807656413163385498[5] = 0;
   out_8807656413163385498[6] = 1;
   out_8807656413163385498[7] = 0;
   out_8807656413163385498[8] = 0;
}
void h_24(double *state, double *unused, double *out_226265923538190981) {
   out_226265923538190981[0] = state[4];
   out_226265923538190981[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5249730814361062362) {
   out_5249730814361062362[0] = 0;
   out_5249730814361062362[1] = 0;
   out_5249730814361062362[2] = 0;
   out_5249730814361062362[3] = 0;
   out_5249730814361062362[4] = 1;
   out_5249730814361062362[5] = 0;
   out_5249730814361062362[6] = 0;
   out_5249730814361062362[7] = 0;
   out_5249730814361062362[8] = 0;
   out_5249730814361062362[9] = 0;
   out_5249730814361062362[10] = 0;
   out_5249730814361062362[11] = 0;
   out_5249730814361062362[12] = 0;
   out_5249730814361062362[13] = 0;
   out_5249730814361062362[14] = 1;
   out_5249730814361062362[15] = 0;
   out_5249730814361062362[16] = 0;
   out_5249730814361062362[17] = 0;
}
void h_30(double *state, double *unused, double *out_8880689501803362483) {
   out_8880689501803362483[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6289323454656136871) {
   out_6289323454656136871[0] = 0;
   out_6289323454656136871[1] = 0;
   out_6289323454656136871[2] = 0;
   out_6289323454656136871[3] = 0;
   out_6289323454656136871[4] = 1;
   out_6289323454656136871[5] = 0;
   out_6289323454656136871[6] = 0;
   out_6289323454656136871[7] = 0;
   out_6289323454656136871[8] = 0;
}
void h_26(double *state, double *unused, double *out_101279670203478282) {
   out_101279670203478282[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5897584341672109894) {
   out_5897584341672109894[0] = 0;
   out_5897584341672109894[1] = 0;
   out_5897584341672109894[2] = 0;
   out_5897584341672109894[3] = 0;
   out_5897584341672109894[4] = 0;
   out_5897584341672109894[5] = 0;
   out_5897584341672109894[6] = 0;
   out_5897584341672109894[7] = 1;
   out_5897584341672109894[8] = 0;
}
void h_27(double *state, double *unused, double *out_3324199722843469132) {
   out_3324199722843469132[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8464086766456561782) {
   out_8464086766456561782[0] = 0;
   out_8464086766456561782[1] = 0;
   out_8464086766456561782[2] = 0;
   out_8464086766456561782[3] = 1;
   out_8464086766456561782[4] = 0;
   out_8464086766456561782[5] = 0;
   out_8464086766456561782[6] = 0;
   out_8464086766456561782[7] = 0;
   out_8464086766456561782[8] = 0;
}
void h_29(double *state, double *unused, double *out_3167013054492339987) {
   out_3167013054492339987[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5779092110341744687) {
   out_5779092110341744687[0] = 0;
   out_5779092110341744687[1] = 1;
   out_5779092110341744687[2] = 0;
   out_5779092110341744687[3] = 0;
   out_5779092110341744687[4] = 0;
   out_5779092110341744687[5] = 0;
   out_5779092110341744687[6] = 0;
   out_5779092110341744687[7] = 0;
   out_5779092110341744687[8] = 0;
}
void h_28(double *state, double *unused, double *out_287413671399136447) {
   out_287413671399136447[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7585252946298276355) {
   out_7585252946298276355[0] = 1;
   out_7585252946298276355[1] = 0;
   out_7585252946298276355[2] = 0;
   out_7585252946298276355[3] = 0;
   out_7585252946298276355[4] = 0;
   out_7585252946298276355[5] = 0;
   out_7585252946298276355[6] = 0;
   out_7585252946298276355[7] = 0;
   out_7585252946298276355[8] = 0;
}
void h_31(double *state, double *unused, double *out_1952667607101882402) {
   out_1952667607101882402[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5271376239438758418) {
   out_5271376239438758418[0] = 0;
   out_5271376239438758418[1] = 0;
   out_5271376239438758418[2] = 0;
   out_5271376239438758418[3] = 0;
   out_5271376239438758418[4] = 0;
   out_5271376239438758418[5] = 0;
   out_5271376239438758418[6] = 0;
   out_5271376239438758418[7] = 0;
   out_5271376239438758418[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3970546799234288025) {
  err_fun(nom_x, delta_x, out_3970546799234288025);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2567718075778826550) {
  inv_err_fun(nom_x, true_x, out_2567718075778826550);
}
void car_H_mod_fun(double *state, double *out_1717749627572306313) {
  H_mod_fun(state, out_1717749627572306313);
}
void car_f_fun(double *state, double dt, double *out_4680969065089583930) {
  f_fun(state,  dt, out_4680969065089583930);
}
void car_F_fun(double *state, double dt, double *out_6937343164270022068) {
  F_fun(state,  dt, out_6937343164270022068);
}
void car_h_25(double *state, double *unused, double *out_5928605043652166783) {
  h_25(state, unused, out_5928605043652166783);
}
void car_H_25(double *state, double *unused, double *out_8807656413163385498) {
  H_25(state, unused, out_8807656413163385498);
}
void car_h_24(double *state, double *unused, double *out_226265923538190981) {
  h_24(state, unused, out_226265923538190981);
}
void car_H_24(double *state, double *unused, double *out_5249730814361062362) {
  H_24(state, unused, out_5249730814361062362);
}
void car_h_30(double *state, double *unused, double *out_8880689501803362483) {
  h_30(state, unused, out_8880689501803362483);
}
void car_H_30(double *state, double *unused, double *out_6289323454656136871) {
  H_30(state, unused, out_6289323454656136871);
}
void car_h_26(double *state, double *unused, double *out_101279670203478282) {
  h_26(state, unused, out_101279670203478282);
}
void car_H_26(double *state, double *unused, double *out_5897584341672109894) {
  H_26(state, unused, out_5897584341672109894);
}
void car_h_27(double *state, double *unused, double *out_3324199722843469132) {
  h_27(state, unused, out_3324199722843469132);
}
void car_H_27(double *state, double *unused, double *out_8464086766456561782) {
  H_27(state, unused, out_8464086766456561782);
}
void car_h_29(double *state, double *unused, double *out_3167013054492339987) {
  h_29(state, unused, out_3167013054492339987);
}
void car_H_29(double *state, double *unused, double *out_5779092110341744687) {
  H_29(state, unused, out_5779092110341744687);
}
void car_h_28(double *state, double *unused, double *out_287413671399136447) {
  h_28(state, unused, out_287413671399136447);
}
void car_H_28(double *state, double *unused, double *out_7585252946298276355) {
  H_28(state, unused, out_7585252946298276355);
}
void car_h_31(double *state, double *unused, double *out_1952667607101882402) {
  h_31(state, unused, out_1952667607101882402);
}
void car_H_31(double *state, double *unused, double *out_5271376239438758418) {
  H_31(state, unused, out_5271376239438758418);
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
