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
void err_fun(double *nom_x, double *delta_x, double *out_3928386937016580969) {
   out_3928386937016580969[0] = delta_x[0] + nom_x[0];
   out_3928386937016580969[1] = delta_x[1] + nom_x[1];
   out_3928386937016580969[2] = delta_x[2] + nom_x[2];
   out_3928386937016580969[3] = delta_x[3] + nom_x[3];
   out_3928386937016580969[4] = delta_x[4] + nom_x[4];
   out_3928386937016580969[5] = delta_x[5] + nom_x[5];
   out_3928386937016580969[6] = delta_x[6] + nom_x[6];
   out_3928386937016580969[7] = delta_x[7] + nom_x[7];
   out_3928386937016580969[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5072261536488927858) {
   out_5072261536488927858[0] = -nom_x[0] + true_x[0];
   out_5072261536488927858[1] = -nom_x[1] + true_x[1];
   out_5072261536488927858[2] = -nom_x[2] + true_x[2];
   out_5072261536488927858[3] = -nom_x[3] + true_x[3];
   out_5072261536488927858[4] = -nom_x[4] + true_x[4];
   out_5072261536488927858[5] = -nom_x[5] + true_x[5];
   out_5072261536488927858[6] = -nom_x[6] + true_x[6];
   out_5072261536488927858[7] = -nom_x[7] + true_x[7];
   out_5072261536488927858[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1805157416881491113) {
   out_1805157416881491113[0] = 1.0;
   out_1805157416881491113[1] = 0.0;
   out_1805157416881491113[2] = 0.0;
   out_1805157416881491113[3] = 0.0;
   out_1805157416881491113[4] = 0.0;
   out_1805157416881491113[5] = 0.0;
   out_1805157416881491113[6] = 0.0;
   out_1805157416881491113[7] = 0.0;
   out_1805157416881491113[8] = 0.0;
   out_1805157416881491113[9] = 0.0;
   out_1805157416881491113[10] = 1.0;
   out_1805157416881491113[11] = 0.0;
   out_1805157416881491113[12] = 0.0;
   out_1805157416881491113[13] = 0.0;
   out_1805157416881491113[14] = 0.0;
   out_1805157416881491113[15] = 0.0;
   out_1805157416881491113[16] = 0.0;
   out_1805157416881491113[17] = 0.0;
   out_1805157416881491113[18] = 0.0;
   out_1805157416881491113[19] = 0.0;
   out_1805157416881491113[20] = 1.0;
   out_1805157416881491113[21] = 0.0;
   out_1805157416881491113[22] = 0.0;
   out_1805157416881491113[23] = 0.0;
   out_1805157416881491113[24] = 0.0;
   out_1805157416881491113[25] = 0.0;
   out_1805157416881491113[26] = 0.0;
   out_1805157416881491113[27] = 0.0;
   out_1805157416881491113[28] = 0.0;
   out_1805157416881491113[29] = 0.0;
   out_1805157416881491113[30] = 1.0;
   out_1805157416881491113[31] = 0.0;
   out_1805157416881491113[32] = 0.0;
   out_1805157416881491113[33] = 0.0;
   out_1805157416881491113[34] = 0.0;
   out_1805157416881491113[35] = 0.0;
   out_1805157416881491113[36] = 0.0;
   out_1805157416881491113[37] = 0.0;
   out_1805157416881491113[38] = 0.0;
   out_1805157416881491113[39] = 0.0;
   out_1805157416881491113[40] = 1.0;
   out_1805157416881491113[41] = 0.0;
   out_1805157416881491113[42] = 0.0;
   out_1805157416881491113[43] = 0.0;
   out_1805157416881491113[44] = 0.0;
   out_1805157416881491113[45] = 0.0;
   out_1805157416881491113[46] = 0.0;
   out_1805157416881491113[47] = 0.0;
   out_1805157416881491113[48] = 0.0;
   out_1805157416881491113[49] = 0.0;
   out_1805157416881491113[50] = 1.0;
   out_1805157416881491113[51] = 0.0;
   out_1805157416881491113[52] = 0.0;
   out_1805157416881491113[53] = 0.0;
   out_1805157416881491113[54] = 0.0;
   out_1805157416881491113[55] = 0.0;
   out_1805157416881491113[56] = 0.0;
   out_1805157416881491113[57] = 0.0;
   out_1805157416881491113[58] = 0.0;
   out_1805157416881491113[59] = 0.0;
   out_1805157416881491113[60] = 1.0;
   out_1805157416881491113[61] = 0.0;
   out_1805157416881491113[62] = 0.0;
   out_1805157416881491113[63] = 0.0;
   out_1805157416881491113[64] = 0.0;
   out_1805157416881491113[65] = 0.0;
   out_1805157416881491113[66] = 0.0;
   out_1805157416881491113[67] = 0.0;
   out_1805157416881491113[68] = 0.0;
   out_1805157416881491113[69] = 0.0;
   out_1805157416881491113[70] = 1.0;
   out_1805157416881491113[71] = 0.0;
   out_1805157416881491113[72] = 0.0;
   out_1805157416881491113[73] = 0.0;
   out_1805157416881491113[74] = 0.0;
   out_1805157416881491113[75] = 0.0;
   out_1805157416881491113[76] = 0.0;
   out_1805157416881491113[77] = 0.0;
   out_1805157416881491113[78] = 0.0;
   out_1805157416881491113[79] = 0.0;
   out_1805157416881491113[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_779920196187082914) {
   out_779920196187082914[0] = state[0];
   out_779920196187082914[1] = state[1];
   out_779920196187082914[2] = state[2];
   out_779920196187082914[3] = state[3];
   out_779920196187082914[4] = state[4];
   out_779920196187082914[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_779920196187082914[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_779920196187082914[7] = state[7];
   out_779920196187082914[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3629707451146971735) {
   out_3629707451146971735[0] = 1;
   out_3629707451146971735[1] = 0;
   out_3629707451146971735[2] = 0;
   out_3629707451146971735[3] = 0;
   out_3629707451146971735[4] = 0;
   out_3629707451146971735[5] = 0;
   out_3629707451146971735[6] = 0;
   out_3629707451146971735[7] = 0;
   out_3629707451146971735[8] = 0;
   out_3629707451146971735[9] = 0;
   out_3629707451146971735[10] = 1;
   out_3629707451146971735[11] = 0;
   out_3629707451146971735[12] = 0;
   out_3629707451146971735[13] = 0;
   out_3629707451146971735[14] = 0;
   out_3629707451146971735[15] = 0;
   out_3629707451146971735[16] = 0;
   out_3629707451146971735[17] = 0;
   out_3629707451146971735[18] = 0;
   out_3629707451146971735[19] = 0;
   out_3629707451146971735[20] = 1;
   out_3629707451146971735[21] = 0;
   out_3629707451146971735[22] = 0;
   out_3629707451146971735[23] = 0;
   out_3629707451146971735[24] = 0;
   out_3629707451146971735[25] = 0;
   out_3629707451146971735[26] = 0;
   out_3629707451146971735[27] = 0;
   out_3629707451146971735[28] = 0;
   out_3629707451146971735[29] = 0;
   out_3629707451146971735[30] = 1;
   out_3629707451146971735[31] = 0;
   out_3629707451146971735[32] = 0;
   out_3629707451146971735[33] = 0;
   out_3629707451146971735[34] = 0;
   out_3629707451146971735[35] = 0;
   out_3629707451146971735[36] = 0;
   out_3629707451146971735[37] = 0;
   out_3629707451146971735[38] = 0;
   out_3629707451146971735[39] = 0;
   out_3629707451146971735[40] = 1;
   out_3629707451146971735[41] = 0;
   out_3629707451146971735[42] = 0;
   out_3629707451146971735[43] = 0;
   out_3629707451146971735[44] = 0;
   out_3629707451146971735[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3629707451146971735[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3629707451146971735[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3629707451146971735[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3629707451146971735[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3629707451146971735[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3629707451146971735[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3629707451146971735[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3629707451146971735[53] = -9.8100000000000005*dt;
   out_3629707451146971735[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3629707451146971735[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3629707451146971735[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3629707451146971735[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3629707451146971735[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3629707451146971735[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3629707451146971735[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3629707451146971735[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3629707451146971735[62] = 0;
   out_3629707451146971735[63] = 0;
   out_3629707451146971735[64] = 0;
   out_3629707451146971735[65] = 0;
   out_3629707451146971735[66] = 0;
   out_3629707451146971735[67] = 0;
   out_3629707451146971735[68] = 0;
   out_3629707451146971735[69] = 0;
   out_3629707451146971735[70] = 1;
   out_3629707451146971735[71] = 0;
   out_3629707451146971735[72] = 0;
   out_3629707451146971735[73] = 0;
   out_3629707451146971735[74] = 0;
   out_3629707451146971735[75] = 0;
   out_3629707451146971735[76] = 0;
   out_3629707451146971735[77] = 0;
   out_3629707451146971735[78] = 0;
   out_3629707451146971735[79] = 0;
   out_3629707451146971735[80] = 1;
}
void h_25(double *state, double *unused, double *out_3062657207957604668) {
   out_3062657207957604668[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6170957893956391582) {
   out_6170957893956391582[0] = 0;
   out_6170957893956391582[1] = 0;
   out_6170957893956391582[2] = 0;
   out_6170957893956391582[3] = 0;
   out_6170957893956391582[4] = 0;
   out_6170957893956391582[5] = 0;
   out_6170957893956391582[6] = 1;
   out_6170957893956391582[7] = 0;
   out_6170957893956391582[8] = 0;
}
void h_24(double *state, double *unused, double *out_4363661235373079824) {
   out_4363661235373079824[0] = state[4];
   out_4363661235373079824[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6464400548730383069) {
   out_6464400548730383069[0] = 0;
   out_6464400548730383069[1] = 0;
   out_6464400548730383069[2] = 0;
   out_6464400548730383069[3] = 0;
   out_6464400548730383069[4] = 1;
   out_6464400548730383069[5] = 0;
   out_6464400548730383069[6] = 0;
   out_6464400548730383069[7] = 0;
   out_6464400548730383069[8] = 0;
   out_6464400548730383069[9] = 0;
   out_6464400548730383069[10] = 0;
   out_6464400548730383069[11] = 0;
   out_6464400548730383069[12] = 0;
   out_6464400548730383069[13] = 0;
   out_6464400548730383069[14] = 1;
   out_6464400548730383069[15] = 0;
   out_6464400548730383069[16] = 0;
   out_6464400548730383069[17] = 0;
}
void h_30(double *state, double *unused, double *out_8192537752896435152) {
   out_8192537752896435152[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5359095838261543279) {
   out_5359095838261543279[0] = 0;
   out_5359095838261543279[1] = 0;
   out_5359095838261543279[2] = 0;
   out_5359095838261543279[3] = 0;
   out_5359095838261543279[4] = 1;
   out_5359095838261543279[5] = 0;
   out_5359095838261543279[6] = 0;
   out_5359095838261543279[7] = 0;
   out_5359095838261543279[8] = 0;
}
void h_26(double *state, double *unused, double *out_1793496235482586006) {
   out_1793496235482586006[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8971260209992359433) {
   out_8971260209992359433[0] = 0;
   out_8971260209992359433[1] = 0;
   out_8971260209992359433[2] = 0;
   out_8971260209992359433[3] = 0;
   out_8971260209992359433[4] = 0;
   out_8971260209992359433[5] = 0;
   out_8971260209992359433[6] = 0;
   out_8971260209992359433[7] = 1;
   out_8971260209992359433[8] = 0;
}
void h_27(double *state, double *unused, double *out_8064330475618450313) {
   out_8064330475618450313[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7533859150061968190) {
   out_7533859150061968190[0] = 0;
   out_7533859150061968190[1] = 0;
   out_7533859150061968190[2] = 0;
   out_7533859150061968190[3] = 1;
   out_7533859150061968190[4] = 0;
   out_7533859150061968190[5] = 0;
   out_7533859150061968190[6] = 0;
   out_7533859150061968190[7] = 0;
   out_7533859150061968190[8] = 0;
}
void h_29(double *state, double *unused, double *out_6613699082989567146) {
   out_6613699082989567146[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4848864493947151095) {
   out_4848864493947151095[0] = 0;
   out_4848864493947151095[1] = 1;
   out_4848864493947151095[2] = 0;
   out_4848864493947151095[3] = 0;
   out_4848864493947151095[4] = 0;
   out_4848864493947151095[5] = 0;
   out_4848864493947151095[6] = 0;
   out_4848864493947151095[7] = 0;
   out_4848864493947151095[8] = 0;
}
void h_28(double *state, double *unused, double *out_7120820622716787878) {
   out_7120820622716787878[0] = state[0];
}
void H_28(double *state, double *unused, double *out_4117123179708501819) {
   out_4117123179708501819[0] = 1;
   out_4117123179708501819[1] = 0;
   out_4117123179708501819[2] = 0;
   out_4117123179708501819[3] = 0;
   out_4117123179708501819[4] = 0;
   out_4117123179708501819[5] = 0;
   out_4117123179708501819[6] = 0;
   out_4117123179708501819[7] = 0;
   out_4117123179708501819[8] = 0;
}
void h_31(double *state, double *unused, double *out_574792320296417682) {
   out_574792320296417682[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5199110929241342781) {
   out_5199110929241342781[0] = 0;
   out_5199110929241342781[1] = 0;
   out_5199110929241342781[2] = 0;
   out_5199110929241342781[3] = 0;
   out_5199110929241342781[4] = 0;
   out_5199110929241342781[5] = 0;
   out_5199110929241342781[6] = 0;
   out_5199110929241342781[7] = 0;
   out_5199110929241342781[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3928386937016580969) {
  err_fun(nom_x, delta_x, out_3928386937016580969);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5072261536488927858) {
  inv_err_fun(nom_x, true_x, out_5072261536488927858);
}
void car_H_mod_fun(double *state, double *out_1805157416881491113) {
  H_mod_fun(state, out_1805157416881491113);
}
void car_f_fun(double *state, double dt, double *out_779920196187082914) {
  f_fun(state,  dt, out_779920196187082914);
}
void car_F_fun(double *state, double dt, double *out_3629707451146971735) {
  F_fun(state,  dt, out_3629707451146971735);
}
void car_h_25(double *state, double *unused, double *out_3062657207957604668) {
  h_25(state, unused, out_3062657207957604668);
}
void car_H_25(double *state, double *unused, double *out_6170957893956391582) {
  H_25(state, unused, out_6170957893956391582);
}
void car_h_24(double *state, double *unused, double *out_4363661235373079824) {
  h_24(state, unused, out_4363661235373079824);
}
void car_H_24(double *state, double *unused, double *out_6464400548730383069) {
  H_24(state, unused, out_6464400548730383069);
}
void car_h_30(double *state, double *unused, double *out_8192537752896435152) {
  h_30(state, unused, out_8192537752896435152);
}
void car_H_30(double *state, double *unused, double *out_5359095838261543279) {
  H_30(state, unused, out_5359095838261543279);
}
void car_h_26(double *state, double *unused, double *out_1793496235482586006) {
  h_26(state, unused, out_1793496235482586006);
}
void car_H_26(double *state, double *unused, double *out_8971260209992359433) {
  H_26(state, unused, out_8971260209992359433);
}
void car_h_27(double *state, double *unused, double *out_8064330475618450313) {
  h_27(state, unused, out_8064330475618450313);
}
void car_H_27(double *state, double *unused, double *out_7533859150061968190) {
  H_27(state, unused, out_7533859150061968190);
}
void car_h_29(double *state, double *unused, double *out_6613699082989567146) {
  h_29(state, unused, out_6613699082989567146);
}
void car_H_29(double *state, double *unused, double *out_4848864493947151095) {
  H_29(state, unused, out_4848864493947151095);
}
void car_h_28(double *state, double *unused, double *out_7120820622716787878) {
  h_28(state, unused, out_7120820622716787878);
}
void car_H_28(double *state, double *unused, double *out_4117123179708501819) {
  H_28(state, unused, out_4117123179708501819);
}
void car_h_31(double *state, double *unused, double *out_574792320296417682) {
  h_31(state, unused, out_574792320296417682);
}
void car_H_31(double *state, double *unused, double *out_5199110929241342781) {
  H_31(state, unused, out_5199110929241342781);
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
