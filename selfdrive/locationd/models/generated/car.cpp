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
void err_fun(double *nom_x, double *delta_x, double *out_5825026556611430403) {
   out_5825026556611430403[0] = delta_x[0] + nom_x[0];
   out_5825026556611430403[1] = delta_x[1] + nom_x[1];
   out_5825026556611430403[2] = delta_x[2] + nom_x[2];
   out_5825026556611430403[3] = delta_x[3] + nom_x[3];
   out_5825026556611430403[4] = delta_x[4] + nom_x[4];
   out_5825026556611430403[5] = delta_x[5] + nom_x[5];
   out_5825026556611430403[6] = delta_x[6] + nom_x[6];
   out_5825026556611430403[7] = delta_x[7] + nom_x[7];
   out_5825026556611430403[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8876036798993240698) {
   out_8876036798993240698[0] = -nom_x[0] + true_x[0];
   out_8876036798993240698[1] = -nom_x[1] + true_x[1];
   out_8876036798993240698[2] = -nom_x[2] + true_x[2];
   out_8876036798993240698[3] = -nom_x[3] + true_x[3];
   out_8876036798993240698[4] = -nom_x[4] + true_x[4];
   out_8876036798993240698[5] = -nom_x[5] + true_x[5];
   out_8876036798993240698[6] = -nom_x[6] + true_x[6];
   out_8876036798993240698[7] = -nom_x[7] + true_x[7];
   out_8876036798993240698[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6203949078932441352) {
   out_6203949078932441352[0] = 1.0;
   out_6203949078932441352[1] = 0.0;
   out_6203949078932441352[2] = 0.0;
   out_6203949078932441352[3] = 0.0;
   out_6203949078932441352[4] = 0.0;
   out_6203949078932441352[5] = 0.0;
   out_6203949078932441352[6] = 0.0;
   out_6203949078932441352[7] = 0.0;
   out_6203949078932441352[8] = 0.0;
   out_6203949078932441352[9] = 0.0;
   out_6203949078932441352[10] = 1.0;
   out_6203949078932441352[11] = 0.0;
   out_6203949078932441352[12] = 0.0;
   out_6203949078932441352[13] = 0.0;
   out_6203949078932441352[14] = 0.0;
   out_6203949078932441352[15] = 0.0;
   out_6203949078932441352[16] = 0.0;
   out_6203949078932441352[17] = 0.0;
   out_6203949078932441352[18] = 0.0;
   out_6203949078932441352[19] = 0.0;
   out_6203949078932441352[20] = 1.0;
   out_6203949078932441352[21] = 0.0;
   out_6203949078932441352[22] = 0.0;
   out_6203949078932441352[23] = 0.0;
   out_6203949078932441352[24] = 0.0;
   out_6203949078932441352[25] = 0.0;
   out_6203949078932441352[26] = 0.0;
   out_6203949078932441352[27] = 0.0;
   out_6203949078932441352[28] = 0.0;
   out_6203949078932441352[29] = 0.0;
   out_6203949078932441352[30] = 1.0;
   out_6203949078932441352[31] = 0.0;
   out_6203949078932441352[32] = 0.0;
   out_6203949078932441352[33] = 0.0;
   out_6203949078932441352[34] = 0.0;
   out_6203949078932441352[35] = 0.0;
   out_6203949078932441352[36] = 0.0;
   out_6203949078932441352[37] = 0.0;
   out_6203949078932441352[38] = 0.0;
   out_6203949078932441352[39] = 0.0;
   out_6203949078932441352[40] = 1.0;
   out_6203949078932441352[41] = 0.0;
   out_6203949078932441352[42] = 0.0;
   out_6203949078932441352[43] = 0.0;
   out_6203949078932441352[44] = 0.0;
   out_6203949078932441352[45] = 0.0;
   out_6203949078932441352[46] = 0.0;
   out_6203949078932441352[47] = 0.0;
   out_6203949078932441352[48] = 0.0;
   out_6203949078932441352[49] = 0.0;
   out_6203949078932441352[50] = 1.0;
   out_6203949078932441352[51] = 0.0;
   out_6203949078932441352[52] = 0.0;
   out_6203949078932441352[53] = 0.0;
   out_6203949078932441352[54] = 0.0;
   out_6203949078932441352[55] = 0.0;
   out_6203949078932441352[56] = 0.0;
   out_6203949078932441352[57] = 0.0;
   out_6203949078932441352[58] = 0.0;
   out_6203949078932441352[59] = 0.0;
   out_6203949078932441352[60] = 1.0;
   out_6203949078932441352[61] = 0.0;
   out_6203949078932441352[62] = 0.0;
   out_6203949078932441352[63] = 0.0;
   out_6203949078932441352[64] = 0.0;
   out_6203949078932441352[65] = 0.0;
   out_6203949078932441352[66] = 0.0;
   out_6203949078932441352[67] = 0.0;
   out_6203949078932441352[68] = 0.0;
   out_6203949078932441352[69] = 0.0;
   out_6203949078932441352[70] = 1.0;
   out_6203949078932441352[71] = 0.0;
   out_6203949078932441352[72] = 0.0;
   out_6203949078932441352[73] = 0.0;
   out_6203949078932441352[74] = 0.0;
   out_6203949078932441352[75] = 0.0;
   out_6203949078932441352[76] = 0.0;
   out_6203949078932441352[77] = 0.0;
   out_6203949078932441352[78] = 0.0;
   out_6203949078932441352[79] = 0.0;
   out_6203949078932441352[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_343822199527135251) {
   out_343822199527135251[0] = state[0];
   out_343822199527135251[1] = state[1];
   out_343822199527135251[2] = state[2];
   out_343822199527135251[3] = state[3];
   out_343822199527135251[4] = state[4];
   out_343822199527135251[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_343822199527135251[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_343822199527135251[7] = state[7];
   out_343822199527135251[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7416815269748566643) {
   out_7416815269748566643[0] = 1;
   out_7416815269748566643[1] = 0;
   out_7416815269748566643[2] = 0;
   out_7416815269748566643[3] = 0;
   out_7416815269748566643[4] = 0;
   out_7416815269748566643[5] = 0;
   out_7416815269748566643[6] = 0;
   out_7416815269748566643[7] = 0;
   out_7416815269748566643[8] = 0;
   out_7416815269748566643[9] = 0;
   out_7416815269748566643[10] = 1;
   out_7416815269748566643[11] = 0;
   out_7416815269748566643[12] = 0;
   out_7416815269748566643[13] = 0;
   out_7416815269748566643[14] = 0;
   out_7416815269748566643[15] = 0;
   out_7416815269748566643[16] = 0;
   out_7416815269748566643[17] = 0;
   out_7416815269748566643[18] = 0;
   out_7416815269748566643[19] = 0;
   out_7416815269748566643[20] = 1;
   out_7416815269748566643[21] = 0;
   out_7416815269748566643[22] = 0;
   out_7416815269748566643[23] = 0;
   out_7416815269748566643[24] = 0;
   out_7416815269748566643[25] = 0;
   out_7416815269748566643[26] = 0;
   out_7416815269748566643[27] = 0;
   out_7416815269748566643[28] = 0;
   out_7416815269748566643[29] = 0;
   out_7416815269748566643[30] = 1;
   out_7416815269748566643[31] = 0;
   out_7416815269748566643[32] = 0;
   out_7416815269748566643[33] = 0;
   out_7416815269748566643[34] = 0;
   out_7416815269748566643[35] = 0;
   out_7416815269748566643[36] = 0;
   out_7416815269748566643[37] = 0;
   out_7416815269748566643[38] = 0;
   out_7416815269748566643[39] = 0;
   out_7416815269748566643[40] = 1;
   out_7416815269748566643[41] = 0;
   out_7416815269748566643[42] = 0;
   out_7416815269748566643[43] = 0;
   out_7416815269748566643[44] = 0;
   out_7416815269748566643[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7416815269748566643[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7416815269748566643[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7416815269748566643[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7416815269748566643[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7416815269748566643[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7416815269748566643[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7416815269748566643[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7416815269748566643[53] = -9.8100000000000005*dt;
   out_7416815269748566643[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7416815269748566643[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7416815269748566643[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7416815269748566643[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7416815269748566643[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7416815269748566643[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7416815269748566643[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7416815269748566643[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7416815269748566643[62] = 0;
   out_7416815269748566643[63] = 0;
   out_7416815269748566643[64] = 0;
   out_7416815269748566643[65] = 0;
   out_7416815269748566643[66] = 0;
   out_7416815269748566643[67] = 0;
   out_7416815269748566643[68] = 0;
   out_7416815269748566643[69] = 0;
   out_7416815269748566643[70] = 1;
   out_7416815269748566643[71] = 0;
   out_7416815269748566643[72] = 0;
   out_7416815269748566643[73] = 0;
   out_7416815269748566643[74] = 0;
   out_7416815269748566643[75] = 0;
   out_7416815269748566643[76] = 0;
   out_7416815269748566643[77] = 0;
   out_7416815269748566643[78] = 0;
   out_7416815269748566643[79] = 0;
   out_7416815269748566643[80] = 1;
}
void h_25(double *state, double *unused, double *out_8641933420137717402) {
   out_8641933420137717402[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7339103169592445424) {
   out_7339103169592445424[0] = 0;
   out_7339103169592445424[1] = 0;
   out_7339103169592445424[2] = 0;
   out_7339103169592445424[3] = 0;
   out_7339103169592445424[4] = 0;
   out_7339103169592445424[5] = 0;
   out_7339103169592445424[6] = 1;
   out_7339103169592445424[7] = 0;
   out_7339103169592445424[8] = 0;
}
void h_24(double *state, double *unused, double *out_5501280400540853584) {
   out_5501280400540853584[0] = state[4];
   out_5501280400540853584[1] = state[5];
}
void H_24(double *state, double *unused, double *out_9067966288769759493) {
   out_9067966288769759493[0] = 0;
   out_9067966288769759493[1] = 0;
   out_9067966288769759493[2] = 0;
   out_9067966288769759493[3] = 0;
   out_9067966288769759493[4] = 1;
   out_9067966288769759493[5] = 0;
   out_9067966288769759493[6] = 0;
   out_9067966288769759493[7] = 0;
   out_9067966288769759493[8] = 0;
   out_9067966288769759493[9] = 0;
   out_9067966288769759493[10] = 0;
   out_9067966288769759493[11] = 0;
   out_9067966288769759493[12] = 0;
   out_9067966288769759493[13] = 0;
   out_9067966288769759493[14] = 1;
   out_9067966288769759493[15] = 0;
   out_9067966288769759493[16] = 0;
   out_9067966288769759493[17] = 0;
}
void h_30(double *state, double *unused, double *out_5706507355292462350) {
   out_5706507355292462350[0] = state[4];
}
void H_30(double *state, double *unused, double *out_422412828100828669) {
   out_422412828100828669[0] = 0;
   out_422412828100828669[1] = 0;
   out_422412828100828669[2] = 0;
   out_422412828100828669[3] = 0;
   out_422412828100828669[4] = 1;
   out_422412828100828669[5] = 0;
   out_422412828100828669[6] = 0;
   out_422412828100828669[7] = 0;
   out_422412828100828669[8] = 0;
}
void h_26(double *state, double *unused, double *out_8743293406736795035) {
   out_8743293406736795035[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7366137585243049968) {
   out_7366137585243049968[0] = 0;
   out_7366137585243049968[1] = 0;
   out_7366137585243049968[2] = 0;
   out_7366137585243049968[3] = 0;
   out_7366137585243049968[4] = 0;
   out_7366137585243049968[5] = 0;
   out_7366137585243049968[6] = 0;
   out_7366137585243049968[7] = 1;
   out_7366137585243049968[8] = 0;
}
void h_27(double *state, double *unused, double *out_6768024602127501529) {
   out_6768024602127501529[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2597176139901253580) {
   out_2597176139901253580[0] = 0;
   out_2597176139901253580[1] = 0;
   out_2597176139901253580[2] = 0;
   out_2597176139901253580[3] = 1;
   out_2597176139901253580[4] = 0;
   out_2597176139901253580[5] = 0;
   out_2597176139901253580[6] = 0;
   out_2597176139901253580[7] = 0;
   out_2597176139901253580[8] = 0;
}
void h_29(double *state, double *unused, double *out_5090891545105754924) {
   out_5090891545105754924[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4310538866770804613) {
   out_4310538866770804613[0] = 0;
   out_4310538866770804613[1] = 1;
   out_4310538866770804613[2] = 0;
   out_4310538866770804613[3] = 0;
   out_4310538866770804613[4] = 0;
   out_4310538866770804613[5] = 0;
   out_4310538866770804613[6] = 0;
   out_4310538866770804613[7] = 0;
   out_4310538866770804613[8] = 0;
}
void h_28(double *state, double *unused, double *out_5824514749225839094) {
   out_5824514749225839094[0] = state[0];
}
void H_28(double *state, double *unused, double *out_9053806189869216429) {
   out_9053806189869216429[0] = 1;
   out_9053806189869216429[1] = 0;
   out_9053806189869216429[2] = 0;
   out_9053806189869216429[3] = 0;
   out_9053806189869216429[4] = 0;
   out_9053806189869216429[5] = 0;
   out_9053806189869216429[6] = 0;
   out_9053806189869216429[7] = 0;
   out_9053806189869216429[8] = 0;
}
void h_31(double *state, double *unused, double *out_8917127482422223291) {
   out_8917127482422223291[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7308457207715484996) {
   out_7308457207715484996[0] = 0;
   out_7308457207715484996[1] = 0;
   out_7308457207715484996[2] = 0;
   out_7308457207715484996[3] = 0;
   out_7308457207715484996[4] = 0;
   out_7308457207715484996[5] = 0;
   out_7308457207715484996[6] = 0;
   out_7308457207715484996[7] = 0;
   out_7308457207715484996[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5825026556611430403) {
  err_fun(nom_x, delta_x, out_5825026556611430403);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8876036798993240698) {
  inv_err_fun(nom_x, true_x, out_8876036798993240698);
}
void car_H_mod_fun(double *state, double *out_6203949078932441352) {
  H_mod_fun(state, out_6203949078932441352);
}
void car_f_fun(double *state, double dt, double *out_343822199527135251) {
  f_fun(state,  dt, out_343822199527135251);
}
void car_F_fun(double *state, double dt, double *out_7416815269748566643) {
  F_fun(state,  dt, out_7416815269748566643);
}
void car_h_25(double *state, double *unused, double *out_8641933420137717402) {
  h_25(state, unused, out_8641933420137717402);
}
void car_H_25(double *state, double *unused, double *out_7339103169592445424) {
  H_25(state, unused, out_7339103169592445424);
}
void car_h_24(double *state, double *unused, double *out_5501280400540853584) {
  h_24(state, unused, out_5501280400540853584);
}
void car_H_24(double *state, double *unused, double *out_9067966288769759493) {
  H_24(state, unused, out_9067966288769759493);
}
void car_h_30(double *state, double *unused, double *out_5706507355292462350) {
  h_30(state, unused, out_5706507355292462350);
}
void car_H_30(double *state, double *unused, double *out_422412828100828669) {
  H_30(state, unused, out_422412828100828669);
}
void car_h_26(double *state, double *unused, double *out_8743293406736795035) {
  h_26(state, unused, out_8743293406736795035);
}
void car_H_26(double *state, double *unused, double *out_7366137585243049968) {
  H_26(state, unused, out_7366137585243049968);
}
void car_h_27(double *state, double *unused, double *out_6768024602127501529) {
  h_27(state, unused, out_6768024602127501529);
}
void car_H_27(double *state, double *unused, double *out_2597176139901253580) {
  H_27(state, unused, out_2597176139901253580);
}
void car_h_29(double *state, double *unused, double *out_5090891545105754924) {
  h_29(state, unused, out_5090891545105754924);
}
void car_H_29(double *state, double *unused, double *out_4310538866770804613) {
  H_29(state, unused, out_4310538866770804613);
}
void car_h_28(double *state, double *unused, double *out_5824514749225839094) {
  h_28(state, unused, out_5824514749225839094);
}
void car_H_28(double *state, double *unused, double *out_9053806189869216429) {
  H_28(state, unused, out_9053806189869216429);
}
void car_h_31(double *state, double *unused, double *out_8917127482422223291) {
  h_31(state, unused, out_8917127482422223291);
}
void car_H_31(double *state, double *unused, double *out_7308457207715484996) {
  H_31(state, unused, out_7308457207715484996);
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
