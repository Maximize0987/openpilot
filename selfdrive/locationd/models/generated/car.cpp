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
void err_fun(double *nom_x, double *delta_x, double *out_3355904321462358618) {
   out_3355904321462358618[0] = delta_x[0] + nom_x[0];
   out_3355904321462358618[1] = delta_x[1] + nom_x[1];
   out_3355904321462358618[2] = delta_x[2] + nom_x[2];
   out_3355904321462358618[3] = delta_x[3] + nom_x[3];
   out_3355904321462358618[4] = delta_x[4] + nom_x[4];
   out_3355904321462358618[5] = delta_x[5] + nom_x[5];
   out_3355904321462358618[6] = delta_x[6] + nom_x[6];
   out_3355904321462358618[7] = delta_x[7] + nom_x[7];
   out_3355904321462358618[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_201422243433114007) {
   out_201422243433114007[0] = -nom_x[0] + true_x[0];
   out_201422243433114007[1] = -nom_x[1] + true_x[1];
   out_201422243433114007[2] = -nom_x[2] + true_x[2];
   out_201422243433114007[3] = -nom_x[3] + true_x[3];
   out_201422243433114007[4] = -nom_x[4] + true_x[4];
   out_201422243433114007[5] = -nom_x[5] + true_x[5];
   out_201422243433114007[6] = -nom_x[6] + true_x[6];
   out_201422243433114007[7] = -nom_x[7] + true_x[7];
   out_201422243433114007[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_99163613418102636) {
   out_99163613418102636[0] = 1.0;
   out_99163613418102636[1] = 0.0;
   out_99163613418102636[2] = 0.0;
   out_99163613418102636[3] = 0.0;
   out_99163613418102636[4] = 0.0;
   out_99163613418102636[5] = 0.0;
   out_99163613418102636[6] = 0.0;
   out_99163613418102636[7] = 0.0;
   out_99163613418102636[8] = 0.0;
   out_99163613418102636[9] = 0.0;
   out_99163613418102636[10] = 1.0;
   out_99163613418102636[11] = 0.0;
   out_99163613418102636[12] = 0.0;
   out_99163613418102636[13] = 0.0;
   out_99163613418102636[14] = 0.0;
   out_99163613418102636[15] = 0.0;
   out_99163613418102636[16] = 0.0;
   out_99163613418102636[17] = 0.0;
   out_99163613418102636[18] = 0.0;
   out_99163613418102636[19] = 0.0;
   out_99163613418102636[20] = 1.0;
   out_99163613418102636[21] = 0.0;
   out_99163613418102636[22] = 0.0;
   out_99163613418102636[23] = 0.0;
   out_99163613418102636[24] = 0.0;
   out_99163613418102636[25] = 0.0;
   out_99163613418102636[26] = 0.0;
   out_99163613418102636[27] = 0.0;
   out_99163613418102636[28] = 0.0;
   out_99163613418102636[29] = 0.0;
   out_99163613418102636[30] = 1.0;
   out_99163613418102636[31] = 0.0;
   out_99163613418102636[32] = 0.0;
   out_99163613418102636[33] = 0.0;
   out_99163613418102636[34] = 0.0;
   out_99163613418102636[35] = 0.0;
   out_99163613418102636[36] = 0.0;
   out_99163613418102636[37] = 0.0;
   out_99163613418102636[38] = 0.0;
   out_99163613418102636[39] = 0.0;
   out_99163613418102636[40] = 1.0;
   out_99163613418102636[41] = 0.0;
   out_99163613418102636[42] = 0.0;
   out_99163613418102636[43] = 0.0;
   out_99163613418102636[44] = 0.0;
   out_99163613418102636[45] = 0.0;
   out_99163613418102636[46] = 0.0;
   out_99163613418102636[47] = 0.0;
   out_99163613418102636[48] = 0.0;
   out_99163613418102636[49] = 0.0;
   out_99163613418102636[50] = 1.0;
   out_99163613418102636[51] = 0.0;
   out_99163613418102636[52] = 0.0;
   out_99163613418102636[53] = 0.0;
   out_99163613418102636[54] = 0.0;
   out_99163613418102636[55] = 0.0;
   out_99163613418102636[56] = 0.0;
   out_99163613418102636[57] = 0.0;
   out_99163613418102636[58] = 0.0;
   out_99163613418102636[59] = 0.0;
   out_99163613418102636[60] = 1.0;
   out_99163613418102636[61] = 0.0;
   out_99163613418102636[62] = 0.0;
   out_99163613418102636[63] = 0.0;
   out_99163613418102636[64] = 0.0;
   out_99163613418102636[65] = 0.0;
   out_99163613418102636[66] = 0.0;
   out_99163613418102636[67] = 0.0;
   out_99163613418102636[68] = 0.0;
   out_99163613418102636[69] = 0.0;
   out_99163613418102636[70] = 1.0;
   out_99163613418102636[71] = 0.0;
   out_99163613418102636[72] = 0.0;
   out_99163613418102636[73] = 0.0;
   out_99163613418102636[74] = 0.0;
   out_99163613418102636[75] = 0.0;
   out_99163613418102636[76] = 0.0;
   out_99163613418102636[77] = 0.0;
   out_99163613418102636[78] = 0.0;
   out_99163613418102636[79] = 0.0;
   out_99163613418102636[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4535403042767963777) {
   out_4535403042767963777[0] = state[0];
   out_4535403042767963777[1] = state[1];
   out_4535403042767963777[2] = state[2];
   out_4535403042767963777[3] = state[3];
   out_4535403042767963777[4] = state[4];
   out_4535403042767963777[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4535403042767963777[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4535403042767963777[7] = state[7];
   out_4535403042767963777[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3611627361836084616) {
   out_3611627361836084616[0] = 1;
   out_3611627361836084616[1] = 0;
   out_3611627361836084616[2] = 0;
   out_3611627361836084616[3] = 0;
   out_3611627361836084616[4] = 0;
   out_3611627361836084616[5] = 0;
   out_3611627361836084616[6] = 0;
   out_3611627361836084616[7] = 0;
   out_3611627361836084616[8] = 0;
   out_3611627361836084616[9] = 0;
   out_3611627361836084616[10] = 1;
   out_3611627361836084616[11] = 0;
   out_3611627361836084616[12] = 0;
   out_3611627361836084616[13] = 0;
   out_3611627361836084616[14] = 0;
   out_3611627361836084616[15] = 0;
   out_3611627361836084616[16] = 0;
   out_3611627361836084616[17] = 0;
   out_3611627361836084616[18] = 0;
   out_3611627361836084616[19] = 0;
   out_3611627361836084616[20] = 1;
   out_3611627361836084616[21] = 0;
   out_3611627361836084616[22] = 0;
   out_3611627361836084616[23] = 0;
   out_3611627361836084616[24] = 0;
   out_3611627361836084616[25] = 0;
   out_3611627361836084616[26] = 0;
   out_3611627361836084616[27] = 0;
   out_3611627361836084616[28] = 0;
   out_3611627361836084616[29] = 0;
   out_3611627361836084616[30] = 1;
   out_3611627361836084616[31] = 0;
   out_3611627361836084616[32] = 0;
   out_3611627361836084616[33] = 0;
   out_3611627361836084616[34] = 0;
   out_3611627361836084616[35] = 0;
   out_3611627361836084616[36] = 0;
   out_3611627361836084616[37] = 0;
   out_3611627361836084616[38] = 0;
   out_3611627361836084616[39] = 0;
   out_3611627361836084616[40] = 1;
   out_3611627361836084616[41] = 0;
   out_3611627361836084616[42] = 0;
   out_3611627361836084616[43] = 0;
   out_3611627361836084616[44] = 0;
   out_3611627361836084616[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3611627361836084616[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3611627361836084616[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3611627361836084616[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3611627361836084616[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3611627361836084616[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3611627361836084616[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3611627361836084616[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3611627361836084616[53] = -9.8100000000000005*dt;
   out_3611627361836084616[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3611627361836084616[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3611627361836084616[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3611627361836084616[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3611627361836084616[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3611627361836084616[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3611627361836084616[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3611627361836084616[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3611627361836084616[62] = 0;
   out_3611627361836084616[63] = 0;
   out_3611627361836084616[64] = 0;
   out_3611627361836084616[65] = 0;
   out_3611627361836084616[66] = 0;
   out_3611627361836084616[67] = 0;
   out_3611627361836084616[68] = 0;
   out_3611627361836084616[69] = 0;
   out_3611627361836084616[70] = 1;
   out_3611627361836084616[71] = 0;
   out_3611627361836084616[72] = 0;
   out_3611627361836084616[73] = 0;
   out_3611627361836084616[74] = 0;
   out_3611627361836084616[75] = 0;
   out_3611627361836084616[76] = 0;
   out_3611627361836084616[77] = 0;
   out_3611627361836084616[78] = 0;
   out_3611627361836084616[79] = 0;
   out_3611627361836084616[80] = 1;
}
void h_25(double *state, double *unused, double *out_5863917325441369509) {
   out_5863917325441369509[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4695667229509766473) {
   out_4695667229509766473[0] = 0;
   out_4695667229509766473[1] = 0;
   out_4695667229509766473[2] = 0;
   out_4695667229509766473[3] = 0;
   out_4695667229509766473[4] = 0;
   out_4695667229509766473[5] = 0;
   out_4695667229509766473[6] = 1;
   out_4695667229509766473[7] = 0;
   out_4695667229509766473[8] = 0;
}
void h_24(double *state, double *unused, double *out_3481314710267158875) {
   out_3481314710267158875[0] = state[4];
   out_3481314710267158875[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4606210134248907981) {
   out_4606210134248907981[0] = 0;
   out_4606210134248907981[1] = 0;
   out_4606210134248907981[2] = 0;
   out_4606210134248907981[3] = 0;
   out_4606210134248907981[4] = 1;
   out_4606210134248907981[5] = 0;
   out_4606210134248907981[6] = 0;
   out_4606210134248907981[7] = 0;
   out_4606210134248907981[8] = 0;
   out_4606210134248907981[9] = 0;
   out_4606210134248907981[10] = 0;
   out_4606210134248907981[11] = 0;
   out_4606210134248907981[12] = 0;
   out_4606210134248907981[13] = 0;
   out_4606210134248907981[14] = 1;
   out_4606210134248907981[15] = 0;
   out_4606210134248907981[16] = 0;
   out_4606210134248907981[17] = 0;
}
void h_30(double *state, double *unused, double *out_723910601034925654) {
   out_723910601034925654[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2177334271002517846) {
   out_2177334271002517846[0] = 0;
   out_2177334271002517846[1] = 0;
   out_2177334271002517846[2] = 0;
   out_2177334271002517846[3] = 0;
   out_2177334271002517846[4] = 1;
   out_2177334271002517846[5] = 0;
   out_2177334271002517846[6] = 0;
   out_2177334271002517846[7] = 0;
   out_2177334271002517846[8] = 0;
}
void h_26(double *state, double *unused, double *out_120594716358448137) {
   out_120594716358448137[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8437170548383822697) {
   out_8437170548383822697[0] = 0;
   out_8437170548383822697[1] = 0;
   out_8437170548383822697[2] = 0;
   out_8437170548383822697[3] = 0;
   out_8437170548383822697[4] = 0;
   out_8437170548383822697[5] = 0;
   out_8437170548383822697[6] = 0;
   out_8437170548383822697[7] = 1;
   out_8437170548383822697[8] = 0;
}
void h_27(double *state, double *unused, double *out_6807427178343031944) {
   out_6807427178343031944[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4352097582802942757) {
   out_4352097582802942757[0] = 0;
   out_4352097582802942757[1] = 0;
   out_4352097582802942757[2] = 0;
   out_4352097582802942757[3] = 1;
   out_4352097582802942757[4] = 0;
   out_4352097582802942757[5] = 0;
   out_4352097582802942757[6] = 0;
   out_4352097582802942757[7] = 0;
   out_4352097582802942757[8] = 0;
}
void h_29(double *state, double *unused, double *out_2312875450409407031) {
   out_2312875450409407031[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1667102926688125662) {
   out_1667102926688125662[0] = 0;
   out_1667102926688125662[1] = 1;
   out_1667102926688125662[2] = 0;
   out_1667102926688125662[3] = 0;
   out_1667102926688125662[4] = 0;
   out_1667102926688125662[5] = 0;
   out_1667102926688125662[6] = 0;
   out_1667102926688125662[7] = 0;
   out_1667102926688125662[8] = 0;
}
void h_28(double *state, double *unused, double *out_4636554191573453893) {
   out_4636554191573453893[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6749501943757656236) {
   out_6749501943757656236[0] = 1;
   out_6749501943757656236[1] = 0;
   out_6749501943757656236[2] = 0;
   out_6749501943757656236[3] = 0;
   out_6749501943757656236[4] = 0;
   out_6749501943757656236[5] = 0;
   out_6749501943757656236[6] = 0;
   out_6749501943757656236[7] = 0;
   out_6749501943757656236[8] = 0;
}
void h_31(double *state, double *unused, double *out_5706730657090240364) {
   out_5706730657090240364[0] = state[8];
}
void H_31(double *state, double *unused, double *out_9063378650617174173) {
   out_9063378650617174173[0] = 0;
   out_9063378650617174173[1] = 0;
   out_9063378650617174173[2] = 0;
   out_9063378650617174173[3] = 0;
   out_9063378650617174173[4] = 0;
   out_9063378650617174173[5] = 0;
   out_9063378650617174173[6] = 0;
   out_9063378650617174173[7] = 0;
   out_9063378650617174173[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3355904321462358618) {
  err_fun(nom_x, delta_x, out_3355904321462358618);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_201422243433114007) {
  inv_err_fun(nom_x, true_x, out_201422243433114007);
}
void car_H_mod_fun(double *state, double *out_99163613418102636) {
  H_mod_fun(state, out_99163613418102636);
}
void car_f_fun(double *state, double dt, double *out_4535403042767963777) {
  f_fun(state,  dt, out_4535403042767963777);
}
void car_F_fun(double *state, double dt, double *out_3611627361836084616) {
  F_fun(state,  dt, out_3611627361836084616);
}
void car_h_25(double *state, double *unused, double *out_5863917325441369509) {
  h_25(state, unused, out_5863917325441369509);
}
void car_H_25(double *state, double *unused, double *out_4695667229509766473) {
  H_25(state, unused, out_4695667229509766473);
}
void car_h_24(double *state, double *unused, double *out_3481314710267158875) {
  h_24(state, unused, out_3481314710267158875);
}
void car_H_24(double *state, double *unused, double *out_4606210134248907981) {
  H_24(state, unused, out_4606210134248907981);
}
void car_h_30(double *state, double *unused, double *out_723910601034925654) {
  h_30(state, unused, out_723910601034925654);
}
void car_H_30(double *state, double *unused, double *out_2177334271002517846) {
  H_30(state, unused, out_2177334271002517846);
}
void car_h_26(double *state, double *unused, double *out_120594716358448137) {
  h_26(state, unused, out_120594716358448137);
}
void car_H_26(double *state, double *unused, double *out_8437170548383822697) {
  H_26(state, unused, out_8437170548383822697);
}
void car_h_27(double *state, double *unused, double *out_6807427178343031944) {
  h_27(state, unused, out_6807427178343031944);
}
void car_H_27(double *state, double *unused, double *out_4352097582802942757) {
  H_27(state, unused, out_4352097582802942757);
}
void car_h_29(double *state, double *unused, double *out_2312875450409407031) {
  h_29(state, unused, out_2312875450409407031);
}
void car_H_29(double *state, double *unused, double *out_1667102926688125662) {
  H_29(state, unused, out_1667102926688125662);
}
void car_h_28(double *state, double *unused, double *out_4636554191573453893) {
  h_28(state, unused, out_4636554191573453893);
}
void car_H_28(double *state, double *unused, double *out_6749501943757656236) {
  H_28(state, unused, out_6749501943757656236);
}
void car_h_31(double *state, double *unused, double *out_5706730657090240364) {
  h_31(state, unused, out_5706730657090240364);
}
void car_H_31(double *state, double *unused, double *out_9063378650617174173) {
  H_31(state, unused, out_9063378650617174173);
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
