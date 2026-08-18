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
void err_fun(double *nom_x, double *delta_x, double *out_3441370810429516799) {
   out_3441370810429516799[0] = delta_x[0] + nom_x[0];
   out_3441370810429516799[1] = delta_x[1] + nom_x[1];
   out_3441370810429516799[2] = delta_x[2] + nom_x[2];
   out_3441370810429516799[3] = delta_x[3] + nom_x[3];
   out_3441370810429516799[4] = delta_x[4] + nom_x[4];
   out_3441370810429516799[5] = delta_x[5] + nom_x[5];
   out_3441370810429516799[6] = delta_x[6] + nom_x[6];
   out_3441370810429516799[7] = delta_x[7] + nom_x[7];
   out_3441370810429516799[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1747596067924150076) {
   out_1747596067924150076[0] = -nom_x[0] + true_x[0];
   out_1747596067924150076[1] = -nom_x[1] + true_x[1];
   out_1747596067924150076[2] = -nom_x[2] + true_x[2];
   out_1747596067924150076[3] = -nom_x[3] + true_x[3];
   out_1747596067924150076[4] = -nom_x[4] + true_x[4];
   out_1747596067924150076[5] = -nom_x[5] + true_x[5];
   out_1747596067924150076[6] = -nom_x[6] + true_x[6];
   out_1747596067924150076[7] = -nom_x[7] + true_x[7];
   out_1747596067924150076[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5211544030531521198) {
   out_5211544030531521198[0] = 1.0;
   out_5211544030531521198[1] = 0.0;
   out_5211544030531521198[2] = 0.0;
   out_5211544030531521198[3] = 0.0;
   out_5211544030531521198[4] = 0.0;
   out_5211544030531521198[5] = 0.0;
   out_5211544030531521198[6] = 0.0;
   out_5211544030531521198[7] = 0.0;
   out_5211544030531521198[8] = 0.0;
   out_5211544030531521198[9] = 0.0;
   out_5211544030531521198[10] = 1.0;
   out_5211544030531521198[11] = 0.0;
   out_5211544030531521198[12] = 0.0;
   out_5211544030531521198[13] = 0.0;
   out_5211544030531521198[14] = 0.0;
   out_5211544030531521198[15] = 0.0;
   out_5211544030531521198[16] = 0.0;
   out_5211544030531521198[17] = 0.0;
   out_5211544030531521198[18] = 0.0;
   out_5211544030531521198[19] = 0.0;
   out_5211544030531521198[20] = 1.0;
   out_5211544030531521198[21] = 0.0;
   out_5211544030531521198[22] = 0.0;
   out_5211544030531521198[23] = 0.0;
   out_5211544030531521198[24] = 0.0;
   out_5211544030531521198[25] = 0.0;
   out_5211544030531521198[26] = 0.0;
   out_5211544030531521198[27] = 0.0;
   out_5211544030531521198[28] = 0.0;
   out_5211544030531521198[29] = 0.0;
   out_5211544030531521198[30] = 1.0;
   out_5211544030531521198[31] = 0.0;
   out_5211544030531521198[32] = 0.0;
   out_5211544030531521198[33] = 0.0;
   out_5211544030531521198[34] = 0.0;
   out_5211544030531521198[35] = 0.0;
   out_5211544030531521198[36] = 0.0;
   out_5211544030531521198[37] = 0.0;
   out_5211544030531521198[38] = 0.0;
   out_5211544030531521198[39] = 0.0;
   out_5211544030531521198[40] = 1.0;
   out_5211544030531521198[41] = 0.0;
   out_5211544030531521198[42] = 0.0;
   out_5211544030531521198[43] = 0.0;
   out_5211544030531521198[44] = 0.0;
   out_5211544030531521198[45] = 0.0;
   out_5211544030531521198[46] = 0.0;
   out_5211544030531521198[47] = 0.0;
   out_5211544030531521198[48] = 0.0;
   out_5211544030531521198[49] = 0.0;
   out_5211544030531521198[50] = 1.0;
   out_5211544030531521198[51] = 0.0;
   out_5211544030531521198[52] = 0.0;
   out_5211544030531521198[53] = 0.0;
   out_5211544030531521198[54] = 0.0;
   out_5211544030531521198[55] = 0.0;
   out_5211544030531521198[56] = 0.0;
   out_5211544030531521198[57] = 0.0;
   out_5211544030531521198[58] = 0.0;
   out_5211544030531521198[59] = 0.0;
   out_5211544030531521198[60] = 1.0;
   out_5211544030531521198[61] = 0.0;
   out_5211544030531521198[62] = 0.0;
   out_5211544030531521198[63] = 0.0;
   out_5211544030531521198[64] = 0.0;
   out_5211544030531521198[65] = 0.0;
   out_5211544030531521198[66] = 0.0;
   out_5211544030531521198[67] = 0.0;
   out_5211544030531521198[68] = 0.0;
   out_5211544030531521198[69] = 0.0;
   out_5211544030531521198[70] = 1.0;
   out_5211544030531521198[71] = 0.0;
   out_5211544030531521198[72] = 0.0;
   out_5211544030531521198[73] = 0.0;
   out_5211544030531521198[74] = 0.0;
   out_5211544030531521198[75] = 0.0;
   out_5211544030531521198[76] = 0.0;
   out_5211544030531521198[77] = 0.0;
   out_5211544030531521198[78] = 0.0;
   out_5211544030531521198[79] = 0.0;
   out_5211544030531521198[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3273966994803944680) {
   out_3273966994803944680[0] = state[0];
   out_3273966994803944680[1] = state[1];
   out_3273966994803944680[2] = state[2];
   out_3273966994803944680[3] = state[3];
   out_3273966994803944680[4] = state[4];
   out_3273966994803944680[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3273966994803944680[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3273966994803944680[7] = state[7];
   out_3273966994803944680[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3584498956988590310) {
   out_3584498956988590310[0] = 1;
   out_3584498956988590310[1] = 0;
   out_3584498956988590310[2] = 0;
   out_3584498956988590310[3] = 0;
   out_3584498956988590310[4] = 0;
   out_3584498956988590310[5] = 0;
   out_3584498956988590310[6] = 0;
   out_3584498956988590310[7] = 0;
   out_3584498956988590310[8] = 0;
   out_3584498956988590310[9] = 0;
   out_3584498956988590310[10] = 1;
   out_3584498956988590310[11] = 0;
   out_3584498956988590310[12] = 0;
   out_3584498956988590310[13] = 0;
   out_3584498956988590310[14] = 0;
   out_3584498956988590310[15] = 0;
   out_3584498956988590310[16] = 0;
   out_3584498956988590310[17] = 0;
   out_3584498956988590310[18] = 0;
   out_3584498956988590310[19] = 0;
   out_3584498956988590310[20] = 1;
   out_3584498956988590310[21] = 0;
   out_3584498956988590310[22] = 0;
   out_3584498956988590310[23] = 0;
   out_3584498956988590310[24] = 0;
   out_3584498956988590310[25] = 0;
   out_3584498956988590310[26] = 0;
   out_3584498956988590310[27] = 0;
   out_3584498956988590310[28] = 0;
   out_3584498956988590310[29] = 0;
   out_3584498956988590310[30] = 1;
   out_3584498956988590310[31] = 0;
   out_3584498956988590310[32] = 0;
   out_3584498956988590310[33] = 0;
   out_3584498956988590310[34] = 0;
   out_3584498956988590310[35] = 0;
   out_3584498956988590310[36] = 0;
   out_3584498956988590310[37] = 0;
   out_3584498956988590310[38] = 0;
   out_3584498956988590310[39] = 0;
   out_3584498956988590310[40] = 1;
   out_3584498956988590310[41] = 0;
   out_3584498956988590310[42] = 0;
   out_3584498956988590310[43] = 0;
   out_3584498956988590310[44] = 0;
   out_3584498956988590310[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3584498956988590310[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3584498956988590310[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3584498956988590310[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3584498956988590310[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3584498956988590310[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3584498956988590310[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3584498956988590310[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3584498956988590310[53] = -9.8100000000000005*dt;
   out_3584498956988590310[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3584498956988590310[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3584498956988590310[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3584498956988590310[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3584498956988590310[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3584498956988590310[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3584498956988590310[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3584498956988590310[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3584498956988590310[62] = 0;
   out_3584498956988590310[63] = 0;
   out_3584498956988590310[64] = 0;
   out_3584498956988590310[65] = 0;
   out_3584498956988590310[66] = 0;
   out_3584498956988590310[67] = 0;
   out_3584498956988590310[68] = 0;
   out_3584498956988590310[69] = 0;
   out_3584498956988590310[70] = 1;
   out_3584498956988590310[71] = 0;
   out_3584498956988590310[72] = 0;
   out_3584498956988590310[73] = 0;
   out_3584498956988590310[74] = 0;
   out_3584498956988590310[75] = 0;
   out_3584498956988590310[76] = 0;
   out_3584498956988590310[77] = 0;
   out_3584498956988590310[78] = 0;
   out_3584498956988590310[79] = 0;
   out_3584498956988590310[80] = 1;
}
void h_25(double *state, double *unused, double *out_1500665077942884314) {
   out_1500665077942884314[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8734592669176886346) {
   out_8734592669176886346[0] = 0;
   out_8734592669176886346[1] = 0;
   out_8734592669176886346[2] = 0;
   out_8734592669176886346[3] = 0;
   out_8734592669176886346[4] = 0;
   out_8734592669176886346[5] = 0;
   out_8734592669176886346[6] = 1;
   out_8734592669176886346[7] = 0;
   out_8734592669176886346[8] = 0;
}
void h_24(double *state, double *unused, double *out_8867867868219610133) {
   out_8867867868219610133[0] = state[4];
   out_8867867868219610133[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5176667070374563210) {
   out_5176667070374563210[0] = 0;
   out_5176667070374563210[1] = 0;
   out_5176667070374563210[2] = 0;
   out_5176667070374563210[3] = 0;
   out_5176667070374563210[4] = 1;
   out_5176667070374563210[5] = 0;
   out_5176667070374563210[6] = 0;
   out_5176667070374563210[7] = 0;
   out_5176667070374563210[8] = 0;
   out_5176667070374563210[9] = 0;
   out_5176667070374563210[10] = 0;
   out_5176667070374563210[11] = 0;
   out_5176667070374563210[12] = 0;
   out_5176667070374563210[13] = 0;
   out_5176667070374563210[14] = 1;
   out_5176667070374563210[15] = 0;
   out_5176667070374563210[16] = 0;
   out_5176667070374563210[17] = 0;
}
void h_30(double *state, double *unused, double *out_6184127634480483313) {
   out_6184127634480483313[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1817902327685269591) {
   out_1817902327685269591[0] = 0;
   out_1817902327685269591[1] = 0;
   out_1817902327685269591[2] = 0;
   out_1817902327685269591[3] = 0;
   out_1817902327685269591[4] = 1;
   out_1817902327685269591[5] = 0;
   out_1817902327685269591[6] = 0;
   out_1817902327685269591[7] = 0;
   out_1817902327685269591[8] = 0;
}
void h_26(double *state, double *unused, double *out_3579722313671785662) {
   out_3579722313671785662[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5970648085658609046) {
   out_5970648085658609046[0] = 0;
   out_5970648085658609046[1] = 0;
   out_5970648085658609046[2] = 0;
   out_5970648085658609046[3] = 0;
   out_5970648085658609046[4] = 0;
   out_5970648085658609046[5] = 0;
   out_5970648085658609046[6] = 0;
   out_5970648085658609046[7] = 1;
   out_5970648085658609046[8] = 0;
}
void h_27(double *state, double *unused, double *out_4755159644016162940) {
   out_4755159644016162940[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3992665639485694502) {
   out_3992665639485694502[0] = 0;
   out_3992665639485694502[1] = 0;
   out_3992665639485694502[2] = 0;
   out_3992665639485694502[3] = 1;
   out_3992665639485694502[4] = 0;
   out_3992665639485694502[5] = 0;
   out_3992665639485694502[6] = 0;
   out_3992665639485694502[7] = 0;
   out_3992665639485694502[8] = 0;
}
void h_29(double *state, double *unused, double *out_5051706952974846792) {
   out_5051706952974846792[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1307670983370877407) {
   out_1307670983370877407[0] = 0;
   out_1307670983370877407[1] = 1;
   out_1307670983370877407[2] = 0;
   out_1307670983370877407[3] = 0;
   out_1307670983370877407[4] = 0;
   out_1307670983370877407[5] = 0;
   out_1307670983370877407[6] = 0;
   out_1307670983370877407[7] = 0;
   out_1307670983370877407[8] = 0;
}
void h_28(double *state, double *unused, double *out_2479630826403110806) {
   out_2479630826403110806[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6390070000440407981) {
   out_6390070000440407981[0] = 1;
   out_6390070000440407981[1] = 0;
   out_6390070000440407981[2] = 0;
   out_6390070000440407981[3] = 0;
   out_6390070000440407981[4] = 0;
   out_6390070000440407981[5] = 0;
   out_6390070000440407981[6] = 0;
   out_6390070000440407981[7] = 0;
   out_6390070000440407981[8] = 0;
}
void h_31(double *state, double *unused, double *out_2361018398485617338) {
   out_2361018398485617338[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8703946707299925918) {
   out_8703946707299925918[0] = 0;
   out_8703946707299925918[1] = 0;
   out_8703946707299925918[2] = 0;
   out_8703946707299925918[3] = 0;
   out_8703946707299925918[4] = 0;
   out_8703946707299925918[5] = 0;
   out_8703946707299925918[6] = 0;
   out_8703946707299925918[7] = 0;
   out_8703946707299925918[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3441370810429516799) {
  err_fun(nom_x, delta_x, out_3441370810429516799);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1747596067924150076) {
  inv_err_fun(nom_x, true_x, out_1747596067924150076);
}
void car_H_mod_fun(double *state, double *out_5211544030531521198) {
  H_mod_fun(state, out_5211544030531521198);
}
void car_f_fun(double *state, double dt, double *out_3273966994803944680) {
  f_fun(state,  dt, out_3273966994803944680);
}
void car_F_fun(double *state, double dt, double *out_3584498956988590310) {
  F_fun(state,  dt, out_3584498956988590310);
}
void car_h_25(double *state, double *unused, double *out_1500665077942884314) {
  h_25(state, unused, out_1500665077942884314);
}
void car_H_25(double *state, double *unused, double *out_8734592669176886346) {
  H_25(state, unused, out_8734592669176886346);
}
void car_h_24(double *state, double *unused, double *out_8867867868219610133) {
  h_24(state, unused, out_8867867868219610133);
}
void car_H_24(double *state, double *unused, double *out_5176667070374563210) {
  H_24(state, unused, out_5176667070374563210);
}
void car_h_30(double *state, double *unused, double *out_6184127634480483313) {
  h_30(state, unused, out_6184127634480483313);
}
void car_H_30(double *state, double *unused, double *out_1817902327685269591) {
  H_30(state, unused, out_1817902327685269591);
}
void car_h_26(double *state, double *unused, double *out_3579722313671785662) {
  h_26(state, unused, out_3579722313671785662);
}
void car_H_26(double *state, double *unused, double *out_5970648085658609046) {
  H_26(state, unused, out_5970648085658609046);
}
void car_h_27(double *state, double *unused, double *out_4755159644016162940) {
  h_27(state, unused, out_4755159644016162940);
}
void car_H_27(double *state, double *unused, double *out_3992665639485694502) {
  H_27(state, unused, out_3992665639485694502);
}
void car_h_29(double *state, double *unused, double *out_5051706952974846792) {
  h_29(state, unused, out_5051706952974846792);
}
void car_H_29(double *state, double *unused, double *out_1307670983370877407) {
  H_29(state, unused, out_1307670983370877407);
}
void car_h_28(double *state, double *unused, double *out_2479630826403110806) {
  h_28(state, unused, out_2479630826403110806);
}
void car_H_28(double *state, double *unused, double *out_6390070000440407981) {
  H_28(state, unused, out_6390070000440407981);
}
void car_h_31(double *state, double *unused, double *out_2361018398485617338) {
  h_31(state, unused, out_2361018398485617338);
}
void car_H_31(double *state, double *unused, double *out_8703946707299925918) {
  H_31(state, unused, out_8703946707299925918);
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
