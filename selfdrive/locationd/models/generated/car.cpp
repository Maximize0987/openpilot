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
void err_fun(double *nom_x, double *delta_x, double *out_5870650175258852411) {
   out_5870650175258852411[0] = delta_x[0] + nom_x[0];
   out_5870650175258852411[1] = delta_x[1] + nom_x[1];
   out_5870650175258852411[2] = delta_x[2] + nom_x[2];
   out_5870650175258852411[3] = delta_x[3] + nom_x[3];
   out_5870650175258852411[4] = delta_x[4] + nom_x[4];
   out_5870650175258852411[5] = delta_x[5] + nom_x[5];
   out_5870650175258852411[6] = delta_x[6] + nom_x[6];
   out_5870650175258852411[7] = delta_x[7] + nom_x[7];
   out_5870650175258852411[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3265729657434381044) {
   out_3265729657434381044[0] = -nom_x[0] + true_x[0];
   out_3265729657434381044[1] = -nom_x[1] + true_x[1];
   out_3265729657434381044[2] = -nom_x[2] + true_x[2];
   out_3265729657434381044[3] = -nom_x[3] + true_x[3];
   out_3265729657434381044[4] = -nom_x[4] + true_x[4];
   out_3265729657434381044[5] = -nom_x[5] + true_x[5];
   out_3265729657434381044[6] = -nom_x[6] + true_x[6];
   out_3265729657434381044[7] = -nom_x[7] + true_x[7];
   out_3265729657434381044[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8559018147660225964) {
   out_8559018147660225964[0] = 1.0;
   out_8559018147660225964[1] = 0.0;
   out_8559018147660225964[2] = 0.0;
   out_8559018147660225964[3] = 0.0;
   out_8559018147660225964[4] = 0.0;
   out_8559018147660225964[5] = 0.0;
   out_8559018147660225964[6] = 0.0;
   out_8559018147660225964[7] = 0.0;
   out_8559018147660225964[8] = 0.0;
   out_8559018147660225964[9] = 0.0;
   out_8559018147660225964[10] = 1.0;
   out_8559018147660225964[11] = 0.0;
   out_8559018147660225964[12] = 0.0;
   out_8559018147660225964[13] = 0.0;
   out_8559018147660225964[14] = 0.0;
   out_8559018147660225964[15] = 0.0;
   out_8559018147660225964[16] = 0.0;
   out_8559018147660225964[17] = 0.0;
   out_8559018147660225964[18] = 0.0;
   out_8559018147660225964[19] = 0.0;
   out_8559018147660225964[20] = 1.0;
   out_8559018147660225964[21] = 0.0;
   out_8559018147660225964[22] = 0.0;
   out_8559018147660225964[23] = 0.0;
   out_8559018147660225964[24] = 0.0;
   out_8559018147660225964[25] = 0.0;
   out_8559018147660225964[26] = 0.0;
   out_8559018147660225964[27] = 0.0;
   out_8559018147660225964[28] = 0.0;
   out_8559018147660225964[29] = 0.0;
   out_8559018147660225964[30] = 1.0;
   out_8559018147660225964[31] = 0.0;
   out_8559018147660225964[32] = 0.0;
   out_8559018147660225964[33] = 0.0;
   out_8559018147660225964[34] = 0.0;
   out_8559018147660225964[35] = 0.0;
   out_8559018147660225964[36] = 0.0;
   out_8559018147660225964[37] = 0.0;
   out_8559018147660225964[38] = 0.0;
   out_8559018147660225964[39] = 0.0;
   out_8559018147660225964[40] = 1.0;
   out_8559018147660225964[41] = 0.0;
   out_8559018147660225964[42] = 0.0;
   out_8559018147660225964[43] = 0.0;
   out_8559018147660225964[44] = 0.0;
   out_8559018147660225964[45] = 0.0;
   out_8559018147660225964[46] = 0.0;
   out_8559018147660225964[47] = 0.0;
   out_8559018147660225964[48] = 0.0;
   out_8559018147660225964[49] = 0.0;
   out_8559018147660225964[50] = 1.0;
   out_8559018147660225964[51] = 0.0;
   out_8559018147660225964[52] = 0.0;
   out_8559018147660225964[53] = 0.0;
   out_8559018147660225964[54] = 0.0;
   out_8559018147660225964[55] = 0.0;
   out_8559018147660225964[56] = 0.0;
   out_8559018147660225964[57] = 0.0;
   out_8559018147660225964[58] = 0.0;
   out_8559018147660225964[59] = 0.0;
   out_8559018147660225964[60] = 1.0;
   out_8559018147660225964[61] = 0.0;
   out_8559018147660225964[62] = 0.0;
   out_8559018147660225964[63] = 0.0;
   out_8559018147660225964[64] = 0.0;
   out_8559018147660225964[65] = 0.0;
   out_8559018147660225964[66] = 0.0;
   out_8559018147660225964[67] = 0.0;
   out_8559018147660225964[68] = 0.0;
   out_8559018147660225964[69] = 0.0;
   out_8559018147660225964[70] = 1.0;
   out_8559018147660225964[71] = 0.0;
   out_8559018147660225964[72] = 0.0;
   out_8559018147660225964[73] = 0.0;
   out_8559018147660225964[74] = 0.0;
   out_8559018147660225964[75] = 0.0;
   out_8559018147660225964[76] = 0.0;
   out_8559018147660225964[77] = 0.0;
   out_8559018147660225964[78] = 0.0;
   out_8559018147660225964[79] = 0.0;
   out_8559018147660225964[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1736737013642959687) {
   out_1736737013642959687[0] = state[0];
   out_1736737013642959687[1] = state[1];
   out_1736737013642959687[2] = state[2];
   out_1736737013642959687[3] = state[3];
   out_1736737013642959687[4] = state[4];
   out_1736737013642959687[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1736737013642959687[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1736737013642959687[7] = state[7];
   out_1736737013642959687[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2126390936971804335) {
   out_2126390936971804335[0] = 1;
   out_2126390936971804335[1] = 0;
   out_2126390936971804335[2] = 0;
   out_2126390936971804335[3] = 0;
   out_2126390936971804335[4] = 0;
   out_2126390936971804335[5] = 0;
   out_2126390936971804335[6] = 0;
   out_2126390936971804335[7] = 0;
   out_2126390936971804335[8] = 0;
   out_2126390936971804335[9] = 0;
   out_2126390936971804335[10] = 1;
   out_2126390936971804335[11] = 0;
   out_2126390936971804335[12] = 0;
   out_2126390936971804335[13] = 0;
   out_2126390936971804335[14] = 0;
   out_2126390936971804335[15] = 0;
   out_2126390936971804335[16] = 0;
   out_2126390936971804335[17] = 0;
   out_2126390936971804335[18] = 0;
   out_2126390936971804335[19] = 0;
   out_2126390936971804335[20] = 1;
   out_2126390936971804335[21] = 0;
   out_2126390936971804335[22] = 0;
   out_2126390936971804335[23] = 0;
   out_2126390936971804335[24] = 0;
   out_2126390936971804335[25] = 0;
   out_2126390936971804335[26] = 0;
   out_2126390936971804335[27] = 0;
   out_2126390936971804335[28] = 0;
   out_2126390936971804335[29] = 0;
   out_2126390936971804335[30] = 1;
   out_2126390936971804335[31] = 0;
   out_2126390936971804335[32] = 0;
   out_2126390936971804335[33] = 0;
   out_2126390936971804335[34] = 0;
   out_2126390936971804335[35] = 0;
   out_2126390936971804335[36] = 0;
   out_2126390936971804335[37] = 0;
   out_2126390936971804335[38] = 0;
   out_2126390936971804335[39] = 0;
   out_2126390936971804335[40] = 1;
   out_2126390936971804335[41] = 0;
   out_2126390936971804335[42] = 0;
   out_2126390936971804335[43] = 0;
   out_2126390936971804335[44] = 0;
   out_2126390936971804335[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2126390936971804335[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2126390936971804335[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2126390936971804335[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2126390936971804335[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2126390936971804335[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2126390936971804335[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2126390936971804335[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2126390936971804335[53] = -9.8100000000000005*dt;
   out_2126390936971804335[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2126390936971804335[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2126390936971804335[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2126390936971804335[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2126390936971804335[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2126390936971804335[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2126390936971804335[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2126390936971804335[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2126390936971804335[62] = 0;
   out_2126390936971804335[63] = 0;
   out_2126390936971804335[64] = 0;
   out_2126390936971804335[65] = 0;
   out_2126390936971804335[66] = 0;
   out_2126390936971804335[67] = 0;
   out_2126390936971804335[68] = 0;
   out_2126390936971804335[69] = 0;
   out_2126390936971804335[70] = 1;
   out_2126390936971804335[71] = 0;
   out_2126390936971804335[72] = 0;
   out_2126390936971804335[73] = 0;
   out_2126390936971804335[74] = 0;
   out_2126390936971804335[75] = 0;
   out_2126390936971804335[76] = 0;
   out_2126390936971804335[77] = 0;
   out_2126390936971804335[78] = 0;
   out_2126390936971804335[79] = 0;
   out_2126390936971804335[80] = 1;
}
void h_25(double *state, double *unused, double *out_650360746861026872) {
   out_650360746861026872[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5521925448974425183) {
   out_5521925448974425183[0] = 0;
   out_5521925448974425183[1] = 0;
   out_5521925448974425183[2] = 0;
   out_5521925448974425183[3] = 0;
   out_5521925448974425183[4] = 0;
   out_5521925448974425183[5] = 0;
   out_5521925448974425183[6] = 1;
   out_5521925448974425183[7] = 0;
   out_5521925448974425183[8] = 0;
}
void h_24(double *state, double *unused, double *out_6354297212728781983) {
   out_6354297212728781983[0] = state[4];
   out_6354297212728781983[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1963999850172102047) {
   out_1963999850172102047[0] = 0;
   out_1963999850172102047[1] = 0;
   out_1963999850172102047[2] = 0;
   out_1963999850172102047[3] = 0;
   out_1963999850172102047[4] = 1;
   out_1963999850172102047[5] = 0;
   out_1963999850172102047[6] = 0;
   out_1963999850172102047[7] = 0;
   out_1963999850172102047[8] = 0;
   out_1963999850172102047[9] = 0;
   out_1963999850172102047[10] = 0;
   out_1963999850172102047[11] = 0;
   out_1963999850172102047[12] = 0;
   out_1963999850172102047[13] = 0;
   out_1963999850172102047[14] = 1;
   out_1963999850172102047[15] = 0;
   out_1963999850172102047[16] = 0;
   out_1963999850172102047[17] = 0;
}
void h_30(double *state, double *unused, double *out_5144912474794651785) {
   out_5144912474794651785[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1394764892517191572) {
   out_1394764892517191572[0] = 0;
   out_1394764892517191572[1] = 0;
   out_1394764892517191572[2] = 0;
   out_1394764892517191572[3] = 0;
   out_1394764892517191572[4] = 1;
   out_1394764892517191572[5] = 0;
   out_1394764892517191572[6] = 0;
   out_1394764892517191572[7] = 0;
   out_1394764892517191572[8] = 0;
}
void h_26(double *state, double *unused, double *out_4541596590118174268) {
   out_4541596590118174268[0] = state[7];
}
void H_26(double *state, double *unused, double *out_9183315305861070209) {
   out_9183315305861070209[0] = 0;
   out_9183315305861070209[1] = 0;
   out_9183315305861070209[2] = 0;
   out_9183315305861070209[3] = 0;
   out_9183315305861070209[4] = 0;
   out_9183315305861070209[5] = 0;
   out_9183315305861070209[6] = 0;
   out_9183315305861070209[7] = 1;
   out_9183315305861070209[8] = 0;
}
void h_27(double *state, double *unused, double *out_2386425304583305813) {
   out_2386425304583305813[0] = state[3];
}
void H_27(double *state, double *unused, double *out_779998419283233339) {
   out_779998419283233339[0] = 0;
   out_779998419283233339[1] = 0;
   out_779998419283233339[2] = 0;
   out_779998419283233339[3] = 1;
   out_779998419283233339[4] = 0;
   out_779998419283233339[5] = 0;
   out_779998419283233339[6] = 0;
   out_779998419283233339[7] = 0;
   out_779998419283233339[8] = 0;
}
void h_29(double *state, double *unused, double *out_4201402621892989350) {
   out_4201402621892989350[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1904996236831583756) {
   out_1904996236831583756[0] = 0;
   out_1904996236831583756[1] = 1;
   out_1904996236831583756[2] = 0;
   out_1904996236831583756[3] = 0;
   out_1904996236831583756[4] = 0;
   out_1904996236831583756[5] = 0;
   out_1904996236831583756[6] = 0;
   out_1904996236831583756[7] = 0;
   out_1904996236831583756[8] = 0;
}
void h_28(double *state, double *unused, double *out_1783109419906828296) {
   out_1783109419906828296[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3177402780237946818) {
   out_3177402780237946818[0] = 1;
   out_3177402780237946818[1] = 0;
   out_3177402780237946818[2] = 0;
   out_3177402780237946818[3] = 0;
   out_3177402780237946818[4] = 0;
   out_3177402780237946818[5] = 0;
   out_3177402780237946818[6] = 0;
   out_3177402780237946818[7] = 0;
   out_3177402780237946818[8] = 0;
}
void h_31(double *state, double *unused, double *out_7421195973211377808) {
   out_7421195973211377808[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5491279487097464755) {
   out_5491279487097464755[0] = 0;
   out_5491279487097464755[1] = 0;
   out_5491279487097464755[2] = 0;
   out_5491279487097464755[3] = 0;
   out_5491279487097464755[4] = 0;
   out_5491279487097464755[5] = 0;
   out_5491279487097464755[6] = 0;
   out_5491279487097464755[7] = 0;
   out_5491279487097464755[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5870650175258852411) {
  err_fun(nom_x, delta_x, out_5870650175258852411);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3265729657434381044) {
  inv_err_fun(nom_x, true_x, out_3265729657434381044);
}
void car_H_mod_fun(double *state, double *out_8559018147660225964) {
  H_mod_fun(state, out_8559018147660225964);
}
void car_f_fun(double *state, double dt, double *out_1736737013642959687) {
  f_fun(state,  dt, out_1736737013642959687);
}
void car_F_fun(double *state, double dt, double *out_2126390936971804335) {
  F_fun(state,  dt, out_2126390936971804335);
}
void car_h_25(double *state, double *unused, double *out_650360746861026872) {
  h_25(state, unused, out_650360746861026872);
}
void car_H_25(double *state, double *unused, double *out_5521925448974425183) {
  H_25(state, unused, out_5521925448974425183);
}
void car_h_24(double *state, double *unused, double *out_6354297212728781983) {
  h_24(state, unused, out_6354297212728781983);
}
void car_H_24(double *state, double *unused, double *out_1963999850172102047) {
  H_24(state, unused, out_1963999850172102047);
}
void car_h_30(double *state, double *unused, double *out_5144912474794651785) {
  h_30(state, unused, out_5144912474794651785);
}
void car_H_30(double *state, double *unused, double *out_1394764892517191572) {
  H_30(state, unused, out_1394764892517191572);
}
void car_h_26(double *state, double *unused, double *out_4541596590118174268) {
  h_26(state, unused, out_4541596590118174268);
}
void car_H_26(double *state, double *unused, double *out_9183315305861070209) {
  H_26(state, unused, out_9183315305861070209);
}
void car_h_27(double *state, double *unused, double *out_2386425304583305813) {
  h_27(state, unused, out_2386425304583305813);
}
void car_H_27(double *state, double *unused, double *out_779998419283233339) {
  H_27(state, unused, out_779998419283233339);
}
void car_h_29(double *state, double *unused, double *out_4201402621892989350) {
  h_29(state, unused, out_4201402621892989350);
}
void car_H_29(double *state, double *unused, double *out_1904996236831583756) {
  H_29(state, unused, out_1904996236831583756);
}
void car_h_28(double *state, double *unused, double *out_1783109419906828296) {
  h_28(state, unused, out_1783109419906828296);
}
void car_H_28(double *state, double *unused, double *out_3177402780237946818) {
  H_28(state, unused, out_3177402780237946818);
}
void car_h_31(double *state, double *unused, double *out_7421195973211377808) {
  h_31(state, unused, out_7421195973211377808);
}
void car_H_31(double *state, double *unused, double *out_5491279487097464755) {
  H_31(state, unused, out_5491279487097464755);
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
