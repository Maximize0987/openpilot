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
void err_fun(double *nom_x, double *delta_x, double *out_3645428350016324042) {
   out_3645428350016324042[0] = delta_x[0] + nom_x[0];
   out_3645428350016324042[1] = delta_x[1] + nom_x[1];
   out_3645428350016324042[2] = delta_x[2] + nom_x[2];
   out_3645428350016324042[3] = delta_x[3] + nom_x[3];
   out_3645428350016324042[4] = delta_x[4] + nom_x[4];
   out_3645428350016324042[5] = delta_x[5] + nom_x[5];
   out_3645428350016324042[6] = delta_x[6] + nom_x[6];
   out_3645428350016324042[7] = delta_x[7] + nom_x[7];
   out_3645428350016324042[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6760420506725333180) {
   out_6760420506725333180[0] = -nom_x[0] + true_x[0];
   out_6760420506725333180[1] = -nom_x[1] + true_x[1];
   out_6760420506725333180[2] = -nom_x[2] + true_x[2];
   out_6760420506725333180[3] = -nom_x[3] + true_x[3];
   out_6760420506725333180[4] = -nom_x[4] + true_x[4];
   out_6760420506725333180[5] = -nom_x[5] + true_x[5];
   out_6760420506725333180[6] = -nom_x[6] + true_x[6];
   out_6760420506725333180[7] = -nom_x[7] + true_x[7];
   out_6760420506725333180[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2494414039273921066) {
   out_2494414039273921066[0] = 1.0;
   out_2494414039273921066[1] = 0.0;
   out_2494414039273921066[2] = 0.0;
   out_2494414039273921066[3] = 0.0;
   out_2494414039273921066[4] = 0.0;
   out_2494414039273921066[5] = 0.0;
   out_2494414039273921066[6] = 0.0;
   out_2494414039273921066[7] = 0.0;
   out_2494414039273921066[8] = 0.0;
   out_2494414039273921066[9] = 0.0;
   out_2494414039273921066[10] = 1.0;
   out_2494414039273921066[11] = 0.0;
   out_2494414039273921066[12] = 0.0;
   out_2494414039273921066[13] = 0.0;
   out_2494414039273921066[14] = 0.0;
   out_2494414039273921066[15] = 0.0;
   out_2494414039273921066[16] = 0.0;
   out_2494414039273921066[17] = 0.0;
   out_2494414039273921066[18] = 0.0;
   out_2494414039273921066[19] = 0.0;
   out_2494414039273921066[20] = 1.0;
   out_2494414039273921066[21] = 0.0;
   out_2494414039273921066[22] = 0.0;
   out_2494414039273921066[23] = 0.0;
   out_2494414039273921066[24] = 0.0;
   out_2494414039273921066[25] = 0.0;
   out_2494414039273921066[26] = 0.0;
   out_2494414039273921066[27] = 0.0;
   out_2494414039273921066[28] = 0.0;
   out_2494414039273921066[29] = 0.0;
   out_2494414039273921066[30] = 1.0;
   out_2494414039273921066[31] = 0.0;
   out_2494414039273921066[32] = 0.0;
   out_2494414039273921066[33] = 0.0;
   out_2494414039273921066[34] = 0.0;
   out_2494414039273921066[35] = 0.0;
   out_2494414039273921066[36] = 0.0;
   out_2494414039273921066[37] = 0.0;
   out_2494414039273921066[38] = 0.0;
   out_2494414039273921066[39] = 0.0;
   out_2494414039273921066[40] = 1.0;
   out_2494414039273921066[41] = 0.0;
   out_2494414039273921066[42] = 0.0;
   out_2494414039273921066[43] = 0.0;
   out_2494414039273921066[44] = 0.0;
   out_2494414039273921066[45] = 0.0;
   out_2494414039273921066[46] = 0.0;
   out_2494414039273921066[47] = 0.0;
   out_2494414039273921066[48] = 0.0;
   out_2494414039273921066[49] = 0.0;
   out_2494414039273921066[50] = 1.0;
   out_2494414039273921066[51] = 0.0;
   out_2494414039273921066[52] = 0.0;
   out_2494414039273921066[53] = 0.0;
   out_2494414039273921066[54] = 0.0;
   out_2494414039273921066[55] = 0.0;
   out_2494414039273921066[56] = 0.0;
   out_2494414039273921066[57] = 0.0;
   out_2494414039273921066[58] = 0.0;
   out_2494414039273921066[59] = 0.0;
   out_2494414039273921066[60] = 1.0;
   out_2494414039273921066[61] = 0.0;
   out_2494414039273921066[62] = 0.0;
   out_2494414039273921066[63] = 0.0;
   out_2494414039273921066[64] = 0.0;
   out_2494414039273921066[65] = 0.0;
   out_2494414039273921066[66] = 0.0;
   out_2494414039273921066[67] = 0.0;
   out_2494414039273921066[68] = 0.0;
   out_2494414039273921066[69] = 0.0;
   out_2494414039273921066[70] = 1.0;
   out_2494414039273921066[71] = 0.0;
   out_2494414039273921066[72] = 0.0;
   out_2494414039273921066[73] = 0.0;
   out_2494414039273921066[74] = 0.0;
   out_2494414039273921066[75] = 0.0;
   out_2494414039273921066[76] = 0.0;
   out_2494414039273921066[77] = 0.0;
   out_2494414039273921066[78] = 0.0;
   out_2494414039273921066[79] = 0.0;
   out_2494414039273921066[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7248228104803536253) {
   out_7248228104803536253[0] = state[0];
   out_7248228104803536253[1] = state[1];
   out_7248228104803536253[2] = state[2];
   out_7248228104803536253[3] = state[3];
   out_7248228104803536253[4] = state[4];
   out_7248228104803536253[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7248228104803536253[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7248228104803536253[7] = state[7];
   out_7248228104803536253[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8524982651096840533) {
   out_8524982651096840533[0] = 1;
   out_8524982651096840533[1] = 0;
   out_8524982651096840533[2] = 0;
   out_8524982651096840533[3] = 0;
   out_8524982651096840533[4] = 0;
   out_8524982651096840533[5] = 0;
   out_8524982651096840533[6] = 0;
   out_8524982651096840533[7] = 0;
   out_8524982651096840533[8] = 0;
   out_8524982651096840533[9] = 0;
   out_8524982651096840533[10] = 1;
   out_8524982651096840533[11] = 0;
   out_8524982651096840533[12] = 0;
   out_8524982651096840533[13] = 0;
   out_8524982651096840533[14] = 0;
   out_8524982651096840533[15] = 0;
   out_8524982651096840533[16] = 0;
   out_8524982651096840533[17] = 0;
   out_8524982651096840533[18] = 0;
   out_8524982651096840533[19] = 0;
   out_8524982651096840533[20] = 1;
   out_8524982651096840533[21] = 0;
   out_8524982651096840533[22] = 0;
   out_8524982651096840533[23] = 0;
   out_8524982651096840533[24] = 0;
   out_8524982651096840533[25] = 0;
   out_8524982651096840533[26] = 0;
   out_8524982651096840533[27] = 0;
   out_8524982651096840533[28] = 0;
   out_8524982651096840533[29] = 0;
   out_8524982651096840533[30] = 1;
   out_8524982651096840533[31] = 0;
   out_8524982651096840533[32] = 0;
   out_8524982651096840533[33] = 0;
   out_8524982651096840533[34] = 0;
   out_8524982651096840533[35] = 0;
   out_8524982651096840533[36] = 0;
   out_8524982651096840533[37] = 0;
   out_8524982651096840533[38] = 0;
   out_8524982651096840533[39] = 0;
   out_8524982651096840533[40] = 1;
   out_8524982651096840533[41] = 0;
   out_8524982651096840533[42] = 0;
   out_8524982651096840533[43] = 0;
   out_8524982651096840533[44] = 0;
   out_8524982651096840533[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8524982651096840533[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8524982651096840533[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8524982651096840533[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8524982651096840533[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8524982651096840533[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8524982651096840533[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8524982651096840533[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8524982651096840533[53] = -9.8100000000000005*dt;
   out_8524982651096840533[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8524982651096840533[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8524982651096840533[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8524982651096840533[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8524982651096840533[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8524982651096840533[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8524982651096840533[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8524982651096840533[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8524982651096840533[62] = 0;
   out_8524982651096840533[63] = 0;
   out_8524982651096840533[64] = 0;
   out_8524982651096840533[65] = 0;
   out_8524982651096840533[66] = 0;
   out_8524982651096840533[67] = 0;
   out_8524982651096840533[68] = 0;
   out_8524982651096840533[69] = 0;
   out_8524982651096840533[70] = 1;
   out_8524982651096840533[71] = 0;
   out_8524982651096840533[72] = 0;
   out_8524982651096840533[73] = 0;
   out_8524982651096840533[74] = 0;
   out_8524982651096840533[75] = 0;
   out_8524982651096840533[76] = 0;
   out_8524982651096840533[77] = 0;
   out_8524982651096840533[78] = 0;
   out_8524982651096840533[79] = 0;
   out_8524982651096840533[80] = 1;
}
void h_25(double *state, double *unused, double *out_8901373037917505693) {
   out_8901373037917505693[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6698774186638316171) {
   out_6698774186638316171[0] = 0;
   out_6698774186638316171[1] = 0;
   out_6698774186638316171[2] = 0;
   out_6698774186638316171[3] = 0;
   out_6698774186638316171[4] = 0;
   out_6698774186638316171[5] = 0;
   out_6698774186638316171[6] = 1;
   out_6698774186638316171[7] = 0;
   out_6698774186638316171[8] = 0;
}
void h_24(double *state, double *unused, double *out_4440266777255545355) {
   out_4440266777255545355[0] = state[4];
   out_4440266777255545355[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2529290999430879054) {
   out_2529290999430879054[0] = 0;
   out_2529290999430879054[1] = 0;
   out_2529290999430879054[2] = 0;
   out_2529290999430879054[3] = 0;
   out_2529290999430879054[4] = 1;
   out_2529290999430879054[5] = 0;
   out_2529290999430879054[6] = 0;
   out_2529290999430879054[7] = 0;
   out_2529290999430879054[8] = 0;
   out_2529290999430879054[9] = 0;
   out_2529290999430879054[10] = 0;
   out_2529290999430879054[11] = 0;
   out_2529290999430879054[12] = 0;
   out_2529290999430879054[13] = 0;
   out_2529290999430879054[14] = 1;
   out_2529290999430879054[15] = 0;
   out_2529290999430879054[16] = 0;
   out_2529290999430879054[17] = 0;
}
void h_30(double *state, double *unused, double *out_261495561198963809) {
   out_261495561198963809[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7220273556943627247) {
   out_7220273556943627247[0] = 0;
   out_7220273556943627247[1] = 0;
   out_7220273556943627247[2] = 0;
   out_7220273556943627247[3] = 0;
   out_7220273556943627247[4] = 1;
   out_7220273556943627247[5] = 0;
   out_7220273556943627247[6] = 0;
   out_7220273556943627247[7] = 0;
   out_7220273556943627247[8] = 0;
}
void h_26(double *state, double *unused, double *out_4740177706461881836) {
   out_4740177706461881836[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8006466568197179221) {
   out_8006466568197179221[0] = 0;
   out_8006466568197179221[1] = 0;
   out_8006466568197179221[2] = 0;
   out_8006466568197179221[3] = 0;
   out_8006466568197179221[4] = 0;
   out_8006466568197179221[5] = 0;
   out_8006466568197179221[6] = 0;
   out_8006466568197179221[7] = 1;
   out_8006466568197179221[8] = 0;
}
void h_27(double *state, double *unused, double *out_6088820934647652310) {
   out_6088820934647652310[0] = state[3];
}
void H_27(double *state, double *unused, double *out_9002876445581981152) {
   out_9002876445581981152[0] = 0;
   out_9002876445581981152[1] = 0;
   out_9002876445581981152[2] = 0;
   out_9002876445581981152[3] = 1;
   out_9002876445581981152[4] = 0;
   out_9002876445581981152[5] = 0;
   out_9002876445581981152[6] = 0;
   out_9002876445581981152[7] = 0;
   out_9002876445581981152[8] = 0;
}
void h_29(double *state, double *unused, double *out_906248239877177928) {
   out_906248239877177928[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7730504901258019431) {
   out_7730504901258019431[0] = 0;
   out_7730504901258019431[1] = 1;
   out_7730504901258019431[2] = 0;
   out_7730504901258019431[3] = 0;
   out_7730504901258019431[4] = 0;
   out_7730504901258019431[5] = 0;
   out_7730504901258019431[6] = 0;
   out_7730504901258019431[7] = 0;
   out_7730504901258019431[8] = 0;
}
void h_28(double *state, double *unused, double *out_3561613674795902166) {
   out_3561613674795902166[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2648105884188488857) {
   out_2648105884188488857[0] = 1;
   out_2648105884188488857[1] = 0;
   out_2648105884188488857[2] = 0;
   out_2648105884188488857[3] = 0;
   out_2648105884188488857[4] = 0;
   out_2648105884188488857[5] = 0;
   out_2648105884188488857[6] = 0;
   out_2648105884188488857[7] = 0;
   out_2648105884188488857[8] = 0;
}
void h_31(double *state, double *unused, double *out_8626178975632999804) {
   out_8626178975632999804[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6668128224761355743) {
   out_6668128224761355743[0] = 0;
   out_6668128224761355743[1] = 0;
   out_6668128224761355743[2] = 0;
   out_6668128224761355743[3] = 0;
   out_6668128224761355743[4] = 0;
   out_6668128224761355743[5] = 0;
   out_6668128224761355743[6] = 0;
   out_6668128224761355743[7] = 0;
   out_6668128224761355743[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3645428350016324042) {
  err_fun(nom_x, delta_x, out_3645428350016324042);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6760420506725333180) {
  inv_err_fun(nom_x, true_x, out_6760420506725333180);
}
void car_H_mod_fun(double *state, double *out_2494414039273921066) {
  H_mod_fun(state, out_2494414039273921066);
}
void car_f_fun(double *state, double dt, double *out_7248228104803536253) {
  f_fun(state,  dt, out_7248228104803536253);
}
void car_F_fun(double *state, double dt, double *out_8524982651096840533) {
  F_fun(state,  dt, out_8524982651096840533);
}
void car_h_25(double *state, double *unused, double *out_8901373037917505693) {
  h_25(state, unused, out_8901373037917505693);
}
void car_H_25(double *state, double *unused, double *out_6698774186638316171) {
  H_25(state, unused, out_6698774186638316171);
}
void car_h_24(double *state, double *unused, double *out_4440266777255545355) {
  h_24(state, unused, out_4440266777255545355);
}
void car_H_24(double *state, double *unused, double *out_2529290999430879054) {
  H_24(state, unused, out_2529290999430879054);
}
void car_h_30(double *state, double *unused, double *out_261495561198963809) {
  h_30(state, unused, out_261495561198963809);
}
void car_H_30(double *state, double *unused, double *out_7220273556943627247) {
  H_30(state, unused, out_7220273556943627247);
}
void car_h_26(double *state, double *unused, double *out_4740177706461881836) {
  h_26(state, unused, out_4740177706461881836);
}
void car_H_26(double *state, double *unused, double *out_8006466568197179221) {
  H_26(state, unused, out_8006466568197179221);
}
void car_h_27(double *state, double *unused, double *out_6088820934647652310) {
  h_27(state, unused, out_6088820934647652310);
}
void car_H_27(double *state, double *unused, double *out_9002876445581981152) {
  H_27(state, unused, out_9002876445581981152);
}
void car_h_29(double *state, double *unused, double *out_906248239877177928) {
  h_29(state, unused, out_906248239877177928);
}
void car_H_29(double *state, double *unused, double *out_7730504901258019431) {
  H_29(state, unused, out_7730504901258019431);
}
void car_h_28(double *state, double *unused, double *out_3561613674795902166) {
  h_28(state, unused, out_3561613674795902166);
}
void car_H_28(double *state, double *unused, double *out_2648105884188488857) {
  H_28(state, unused, out_2648105884188488857);
}
void car_h_31(double *state, double *unused, double *out_8626178975632999804) {
  h_31(state, unused, out_8626178975632999804);
}
void car_H_31(double *state, double *unused, double *out_6668128224761355743) {
  H_31(state, unused, out_6668128224761355743);
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
