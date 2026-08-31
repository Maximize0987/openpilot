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
void err_fun(double *nom_x, double *delta_x, double *out_7251302496478371121) {
   out_7251302496478371121[0] = delta_x[0] + nom_x[0];
   out_7251302496478371121[1] = delta_x[1] + nom_x[1];
   out_7251302496478371121[2] = delta_x[2] + nom_x[2];
   out_7251302496478371121[3] = delta_x[3] + nom_x[3];
   out_7251302496478371121[4] = delta_x[4] + nom_x[4];
   out_7251302496478371121[5] = delta_x[5] + nom_x[5];
   out_7251302496478371121[6] = delta_x[6] + nom_x[6];
   out_7251302496478371121[7] = delta_x[7] + nom_x[7];
   out_7251302496478371121[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7757777920139399450) {
   out_7757777920139399450[0] = -nom_x[0] + true_x[0];
   out_7757777920139399450[1] = -nom_x[1] + true_x[1];
   out_7757777920139399450[2] = -nom_x[2] + true_x[2];
   out_7757777920139399450[3] = -nom_x[3] + true_x[3];
   out_7757777920139399450[4] = -nom_x[4] + true_x[4];
   out_7757777920139399450[5] = -nom_x[5] + true_x[5];
   out_7757777920139399450[6] = -nom_x[6] + true_x[6];
   out_7757777920139399450[7] = -nom_x[7] + true_x[7];
   out_7757777920139399450[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5994192809213785164) {
   out_5994192809213785164[0] = 1.0;
   out_5994192809213785164[1] = 0.0;
   out_5994192809213785164[2] = 0.0;
   out_5994192809213785164[3] = 0.0;
   out_5994192809213785164[4] = 0.0;
   out_5994192809213785164[5] = 0.0;
   out_5994192809213785164[6] = 0.0;
   out_5994192809213785164[7] = 0.0;
   out_5994192809213785164[8] = 0.0;
   out_5994192809213785164[9] = 0.0;
   out_5994192809213785164[10] = 1.0;
   out_5994192809213785164[11] = 0.0;
   out_5994192809213785164[12] = 0.0;
   out_5994192809213785164[13] = 0.0;
   out_5994192809213785164[14] = 0.0;
   out_5994192809213785164[15] = 0.0;
   out_5994192809213785164[16] = 0.0;
   out_5994192809213785164[17] = 0.0;
   out_5994192809213785164[18] = 0.0;
   out_5994192809213785164[19] = 0.0;
   out_5994192809213785164[20] = 1.0;
   out_5994192809213785164[21] = 0.0;
   out_5994192809213785164[22] = 0.0;
   out_5994192809213785164[23] = 0.0;
   out_5994192809213785164[24] = 0.0;
   out_5994192809213785164[25] = 0.0;
   out_5994192809213785164[26] = 0.0;
   out_5994192809213785164[27] = 0.0;
   out_5994192809213785164[28] = 0.0;
   out_5994192809213785164[29] = 0.0;
   out_5994192809213785164[30] = 1.0;
   out_5994192809213785164[31] = 0.0;
   out_5994192809213785164[32] = 0.0;
   out_5994192809213785164[33] = 0.0;
   out_5994192809213785164[34] = 0.0;
   out_5994192809213785164[35] = 0.0;
   out_5994192809213785164[36] = 0.0;
   out_5994192809213785164[37] = 0.0;
   out_5994192809213785164[38] = 0.0;
   out_5994192809213785164[39] = 0.0;
   out_5994192809213785164[40] = 1.0;
   out_5994192809213785164[41] = 0.0;
   out_5994192809213785164[42] = 0.0;
   out_5994192809213785164[43] = 0.0;
   out_5994192809213785164[44] = 0.0;
   out_5994192809213785164[45] = 0.0;
   out_5994192809213785164[46] = 0.0;
   out_5994192809213785164[47] = 0.0;
   out_5994192809213785164[48] = 0.0;
   out_5994192809213785164[49] = 0.0;
   out_5994192809213785164[50] = 1.0;
   out_5994192809213785164[51] = 0.0;
   out_5994192809213785164[52] = 0.0;
   out_5994192809213785164[53] = 0.0;
   out_5994192809213785164[54] = 0.0;
   out_5994192809213785164[55] = 0.0;
   out_5994192809213785164[56] = 0.0;
   out_5994192809213785164[57] = 0.0;
   out_5994192809213785164[58] = 0.0;
   out_5994192809213785164[59] = 0.0;
   out_5994192809213785164[60] = 1.0;
   out_5994192809213785164[61] = 0.0;
   out_5994192809213785164[62] = 0.0;
   out_5994192809213785164[63] = 0.0;
   out_5994192809213785164[64] = 0.0;
   out_5994192809213785164[65] = 0.0;
   out_5994192809213785164[66] = 0.0;
   out_5994192809213785164[67] = 0.0;
   out_5994192809213785164[68] = 0.0;
   out_5994192809213785164[69] = 0.0;
   out_5994192809213785164[70] = 1.0;
   out_5994192809213785164[71] = 0.0;
   out_5994192809213785164[72] = 0.0;
   out_5994192809213785164[73] = 0.0;
   out_5994192809213785164[74] = 0.0;
   out_5994192809213785164[75] = 0.0;
   out_5994192809213785164[76] = 0.0;
   out_5994192809213785164[77] = 0.0;
   out_5994192809213785164[78] = 0.0;
   out_5994192809213785164[79] = 0.0;
   out_5994192809213785164[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5541966606958472992) {
   out_5541966606958472992[0] = state[0];
   out_5541966606958472992[1] = state[1];
   out_5541966606958472992[2] = state[2];
   out_5541966606958472992[3] = state[3];
   out_5541966606958472992[4] = state[4];
   out_5541966606958472992[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5541966606958472992[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5541966606958472992[7] = state[7];
   out_5541966606958472992[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3805616153551932316) {
   out_3805616153551932316[0] = 1;
   out_3805616153551932316[1] = 0;
   out_3805616153551932316[2] = 0;
   out_3805616153551932316[3] = 0;
   out_3805616153551932316[4] = 0;
   out_3805616153551932316[5] = 0;
   out_3805616153551932316[6] = 0;
   out_3805616153551932316[7] = 0;
   out_3805616153551932316[8] = 0;
   out_3805616153551932316[9] = 0;
   out_3805616153551932316[10] = 1;
   out_3805616153551932316[11] = 0;
   out_3805616153551932316[12] = 0;
   out_3805616153551932316[13] = 0;
   out_3805616153551932316[14] = 0;
   out_3805616153551932316[15] = 0;
   out_3805616153551932316[16] = 0;
   out_3805616153551932316[17] = 0;
   out_3805616153551932316[18] = 0;
   out_3805616153551932316[19] = 0;
   out_3805616153551932316[20] = 1;
   out_3805616153551932316[21] = 0;
   out_3805616153551932316[22] = 0;
   out_3805616153551932316[23] = 0;
   out_3805616153551932316[24] = 0;
   out_3805616153551932316[25] = 0;
   out_3805616153551932316[26] = 0;
   out_3805616153551932316[27] = 0;
   out_3805616153551932316[28] = 0;
   out_3805616153551932316[29] = 0;
   out_3805616153551932316[30] = 1;
   out_3805616153551932316[31] = 0;
   out_3805616153551932316[32] = 0;
   out_3805616153551932316[33] = 0;
   out_3805616153551932316[34] = 0;
   out_3805616153551932316[35] = 0;
   out_3805616153551932316[36] = 0;
   out_3805616153551932316[37] = 0;
   out_3805616153551932316[38] = 0;
   out_3805616153551932316[39] = 0;
   out_3805616153551932316[40] = 1;
   out_3805616153551932316[41] = 0;
   out_3805616153551932316[42] = 0;
   out_3805616153551932316[43] = 0;
   out_3805616153551932316[44] = 0;
   out_3805616153551932316[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3805616153551932316[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3805616153551932316[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3805616153551932316[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3805616153551932316[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3805616153551932316[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3805616153551932316[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3805616153551932316[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3805616153551932316[53] = -9.8100000000000005*dt;
   out_3805616153551932316[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3805616153551932316[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3805616153551932316[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3805616153551932316[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3805616153551932316[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3805616153551932316[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3805616153551932316[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3805616153551932316[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3805616153551932316[62] = 0;
   out_3805616153551932316[63] = 0;
   out_3805616153551932316[64] = 0;
   out_3805616153551932316[65] = 0;
   out_3805616153551932316[66] = 0;
   out_3805616153551932316[67] = 0;
   out_3805616153551932316[68] = 0;
   out_3805616153551932316[69] = 0;
   out_3805616153551932316[70] = 1;
   out_3805616153551932316[71] = 0;
   out_3805616153551932316[72] = 0;
   out_3805616153551932316[73] = 0;
   out_3805616153551932316[74] = 0;
   out_3805616153551932316[75] = 0;
   out_3805616153551932316[76] = 0;
   out_3805616153551932316[77] = 0;
   out_3805616153551932316[78] = 0;
   out_3805616153551932316[79] = 0;
   out_3805616153551932316[80] = 1;
}
void h_25(double *state, double *unused, double *out_4112076348506573484) {
   out_4112076348506573484[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2471212159224293487) {
   out_2471212159224293487[0] = 0;
   out_2471212159224293487[1] = 0;
   out_2471212159224293487[2] = 0;
   out_2471212159224293487[3] = 0;
   out_2471212159224293487[4] = 0;
   out_2471212159224293487[5] = 0;
   out_2471212159224293487[6] = 1;
   out_2471212159224293487[7] = 0;
   out_2471212159224293487[8] = 0;
}
void h_24(double *state, double *unused, double *out_2715398695630647729) {
   out_2715398695630647729[0] = state[4];
   out_2715398695630647729[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1086713439578029649) {
   out_1086713439578029649[0] = 0;
   out_1086713439578029649[1] = 0;
   out_1086713439578029649[2] = 0;
   out_1086713439578029649[3] = 0;
   out_1086713439578029649[4] = 1;
   out_1086713439578029649[5] = 0;
   out_1086713439578029649[6] = 0;
   out_1086713439578029649[7] = 0;
   out_1086713439578029649[8] = 0;
   out_1086713439578029649[9] = 0;
   out_1086713439578029649[10] = 0;
   out_1086713439578029649[11] = 0;
   out_1086713439578029649[12] = 0;
   out_1086713439578029649[13] = 0;
   out_1086713439578029649[14] = 1;
   out_1086713439578029649[15] = 0;
   out_1086713439578029649[16] = 0;
   out_1086713439578029649[17] = 0;
}
void h_30(double *state, double *unused, double *out_3954889680155444339) {
   out_3954889680155444339[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4445478182267323268) {
   out_4445478182267323268[0] = 0;
   out_4445478182267323268[1] = 0;
   out_4445478182267323268[2] = 0;
   out_4445478182267323268[3] = 0;
   out_4445478182267323268[4] = 1;
   out_4445478182267323268[5] = 0;
   out_4445478182267323268[6] = 0;
   out_4445478182267323268[7] = 0;
   out_4445478182267323268[8] = 0;
}
void h_26(double *state, double *unused, double *out_1046783587505401306) {
   out_1046783587505401306[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6212715478098349711) {
   out_6212715478098349711[0] = 0;
   out_6212715478098349711[1] = 0;
   out_6212715478098349711[2] = 0;
   out_6212715478098349711[3] = 0;
   out_6212715478098349711[4] = 0;
   out_6212715478098349711[5] = 0;
   out_6212715478098349711[6] = 0;
   out_6212715478098349711[7] = 1;
   out_6212715478098349711[8] = 0;
}
void h_27(double *state, double *unused, double *out_1075290297062240799) {
   out_1075290297062240799[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2270714870466898357) {
   out_2270714870466898357[0] = 0;
   out_2270714870466898357[1] = 0;
   out_2270714870466898357[2] = 0;
   out_2270714870466898357[3] = 1;
   out_2270714870466898357[4] = 0;
   out_2270714870466898357[5] = 0;
   out_2270714870466898357[6] = 0;
   out_2270714870466898357[7] = 0;
   out_2270714870466898357[8] = 0;
}
void h_29(double *state, double *unused, double *out_5695544929288110137) {
   out_5695544929288110137[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4955709526581715452) {
   out_4955709526581715452[0] = 0;
   out_4955709526581715452[1] = 1;
   out_4955709526581715452[2] = 0;
   out_4955709526581715452[3] = 0;
   out_4955709526581715452[4] = 0;
   out_4955709526581715452[5] = 0;
   out_4955709526581715452[6] = 0;
   out_4955709526581715452[7] = 0;
   out_4955709526581715452[8] = 0;
}
void h_28(double *state, double *unused, double *out_131780444160578364) {
   out_131780444160578364[0] = state[0];
}
void H_28(double *state, double *unused, double *out_4525046873472183250) {
   out_4525046873472183250[0] = 1;
   out_4525046873472183250[1] = 0;
   out_4525046873472183250[2] = 0;
   out_4525046873472183250[3] = 0;
   out_4525046873472183250[4] = 0;
   out_4525046873472183250[5] = 0;
   out_4525046873472183250[6] = 0;
   out_4525046873472183250[7] = 0;
   out_4525046873472183250[8] = 0;
}
void h_31(double *state, double *unused, double *out_3836882286222067595) {
   out_3836882286222067595[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2440566197347333059) {
   out_2440566197347333059[0] = 0;
   out_2440566197347333059[1] = 0;
   out_2440566197347333059[2] = 0;
   out_2440566197347333059[3] = 0;
   out_2440566197347333059[4] = 0;
   out_2440566197347333059[5] = 0;
   out_2440566197347333059[6] = 0;
   out_2440566197347333059[7] = 0;
   out_2440566197347333059[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7251302496478371121) {
  err_fun(nom_x, delta_x, out_7251302496478371121);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7757777920139399450) {
  inv_err_fun(nom_x, true_x, out_7757777920139399450);
}
void car_H_mod_fun(double *state, double *out_5994192809213785164) {
  H_mod_fun(state, out_5994192809213785164);
}
void car_f_fun(double *state, double dt, double *out_5541966606958472992) {
  f_fun(state,  dt, out_5541966606958472992);
}
void car_F_fun(double *state, double dt, double *out_3805616153551932316) {
  F_fun(state,  dt, out_3805616153551932316);
}
void car_h_25(double *state, double *unused, double *out_4112076348506573484) {
  h_25(state, unused, out_4112076348506573484);
}
void car_H_25(double *state, double *unused, double *out_2471212159224293487) {
  H_25(state, unused, out_2471212159224293487);
}
void car_h_24(double *state, double *unused, double *out_2715398695630647729) {
  h_24(state, unused, out_2715398695630647729);
}
void car_H_24(double *state, double *unused, double *out_1086713439578029649) {
  H_24(state, unused, out_1086713439578029649);
}
void car_h_30(double *state, double *unused, double *out_3954889680155444339) {
  h_30(state, unused, out_3954889680155444339);
}
void car_H_30(double *state, double *unused, double *out_4445478182267323268) {
  H_30(state, unused, out_4445478182267323268);
}
void car_h_26(double *state, double *unused, double *out_1046783587505401306) {
  h_26(state, unused, out_1046783587505401306);
}
void car_H_26(double *state, double *unused, double *out_6212715478098349711) {
  H_26(state, unused, out_6212715478098349711);
}
void car_h_27(double *state, double *unused, double *out_1075290297062240799) {
  h_27(state, unused, out_1075290297062240799);
}
void car_H_27(double *state, double *unused, double *out_2270714870466898357) {
  H_27(state, unused, out_2270714870466898357);
}
void car_h_29(double *state, double *unused, double *out_5695544929288110137) {
  h_29(state, unused, out_5695544929288110137);
}
void car_H_29(double *state, double *unused, double *out_4955709526581715452) {
  H_29(state, unused, out_4955709526581715452);
}
void car_h_28(double *state, double *unused, double *out_131780444160578364) {
  h_28(state, unused, out_131780444160578364);
}
void car_H_28(double *state, double *unused, double *out_4525046873472183250) {
  H_28(state, unused, out_4525046873472183250);
}
void car_h_31(double *state, double *unused, double *out_3836882286222067595) {
  h_31(state, unused, out_3836882286222067595);
}
void car_H_31(double *state, double *unused, double *out_2440566197347333059) {
  H_31(state, unused, out_2440566197347333059);
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
