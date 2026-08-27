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
void err_fun(double *nom_x, double *delta_x, double *out_6663383586198040946) {
   out_6663383586198040946[0] = delta_x[0] + nom_x[0];
   out_6663383586198040946[1] = delta_x[1] + nom_x[1];
   out_6663383586198040946[2] = delta_x[2] + nom_x[2];
   out_6663383586198040946[3] = delta_x[3] + nom_x[3];
   out_6663383586198040946[4] = delta_x[4] + nom_x[4];
   out_6663383586198040946[5] = delta_x[5] + nom_x[5];
   out_6663383586198040946[6] = delta_x[6] + nom_x[6];
   out_6663383586198040946[7] = delta_x[7] + nom_x[7];
   out_6663383586198040946[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8588337980518277825) {
   out_8588337980518277825[0] = -nom_x[0] + true_x[0];
   out_8588337980518277825[1] = -nom_x[1] + true_x[1];
   out_8588337980518277825[2] = -nom_x[2] + true_x[2];
   out_8588337980518277825[3] = -nom_x[3] + true_x[3];
   out_8588337980518277825[4] = -nom_x[4] + true_x[4];
   out_8588337980518277825[5] = -nom_x[5] + true_x[5];
   out_8588337980518277825[6] = -nom_x[6] + true_x[6];
   out_8588337980518277825[7] = -nom_x[7] + true_x[7];
   out_8588337980518277825[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6555656847717771558) {
   out_6555656847717771558[0] = 1.0;
   out_6555656847717771558[1] = 0.0;
   out_6555656847717771558[2] = 0.0;
   out_6555656847717771558[3] = 0.0;
   out_6555656847717771558[4] = 0.0;
   out_6555656847717771558[5] = 0.0;
   out_6555656847717771558[6] = 0.0;
   out_6555656847717771558[7] = 0.0;
   out_6555656847717771558[8] = 0.0;
   out_6555656847717771558[9] = 0.0;
   out_6555656847717771558[10] = 1.0;
   out_6555656847717771558[11] = 0.0;
   out_6555656847717771558[12] = 0.0;
   out_6555656847717771558[13] = 0.0;
   out_6555656847717771558[14] = 0.0;
   out_6555656847717771558[15] = 0.0;
   out_6555656847717771558[16] = 0.0;
   out_6555656847717771558[17] = 0.0;
   out_6555656847717771558[18] = 0.0;
   out_6555656847717771558[19] = 0.0;
   out_6555656847717771558[20] = 1.0;
   out_6555656847717771558[21] = 0.0;
   out_6555656847717771558[22] = 0.0;
   out_6555656847717771558[23] = 0.0;
   out_6555656847717771558[24] = 0.0;
   out_6555656847717771558[25] = 0.0;
   out_6555656847717771558[26] = 0.0;
   out_6555656847717771558[27] = 0.0;
   out_6555656847717771558[28] = 0.0;
   out_6555656847717771558[29] = 0.0;
   out_6555656847717771558[30] = 1.0;
   out_6555656847717771558[31] = 0.0;
   out_6555656847717771558[32] = 0.0;
   out_6555656847717771558[33] = 0.0;
   out_6555656847717771558[34] = 0.0;
   out_6555656847717771558[35] = 0.0;
   out_6555656847717771558[36] = 0.0;
   out_6555656847717771558[37] = 0.0;
   out_6555656847717771558[38] = 0.0;
   out_6555656847717771558[39] = 0.0;
   out_6555656847717771558[40] = 1.0;
   out_6555656847717771558[41] = 0.0;
   out_6555656847717771558[42] = 0.0;
   out_6555656847717771558[43] = 0.0;
   out_6555656847717771558[44] = 0.0;
   out_6555656847717771558[45] = 0.0;
   out_6555656847717771558[46] = 0.0;
   out_6555656847717771558[47] = 0.0;
   out_6555656847717771558[48] = 0.0;
   out_6555656847717771558[49] = 0.0;
   out_6555656847717771558[50] = 1.0;
   out_6555656847717771558[51] = 0.0;
   out_6555656847717771558[52] = 0.0;
   out_6555656847717771558[53] = 0.0;
   out_6555656847717771558[54] = 0.0;
   out_6555656847717771558[55] = 0.0;
   out_6555656847717771558[56] = 0.0;
   out_6555656847717771558[57] = 0.0;
   out_6555656847717771558[58] = 0.0;
   out_6555656847717771558[59] = 0.0;
   out_6555656847717771558[60] = 1.0;
   out_6555656847717771558[61] = 0.0;
   out_6555656847717771558[62] = 0.0;
   out_6555656847717771558[63] = 0.0;
   out_6555656847717771558[64] = 0.0;
   out_6555656847717771558[65] = 0.0;
   out_6555656847717771558[66] = 0.0;
   out_6555656847717771558[67] = 0.0;
   out_6555656847717771558[68] = 0.0;
   out_6555656847717771558[69] = 0.0;
   out_6555656847717771558[70] = 1.0;
   out_6555656847717771558[71] = 0.0;
   out_6555656847717771558[72] = 0.0;
   out_6555656847717771558[73] = 0.0;
   out_6555656847717771558[74] = 0.0;
   out_6555656847717771558[75] = 0.0;
   out_6555656847717771558[76] = 0.0;
   out_6555656847717771558[77] = 0.0;
   out_6555656847717771558[78] = 0.0;
   out_6555656847717771558[79] = 0.0;
   out_6555656847717771558[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7137582187284124708) {
   out_7137582187284124708[0] = state[0];
   out_7137582187284124708[1] = state[1];
   out_7137582187284124708[2] = state[2];
   out_7137582187284124708[3] = state[3];
   out_7137582187284124708[4] = state[4];
   out_7137582187284124708[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7137582187284124708[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7137582187284124708[7] = state[7];
   out_7137582187284124708[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2957883628728215032) {
   out_2957883628728215032[0] = 1;
   out_2957883628728215032[1] = 0;
   out_2957883628728215032[2] = 0;
   out_2957883628728215032[3] = 0;
   out_2957883628728215032[4] = 0;
   out_2957883628728215032[5] = 0;
   out_2957883628728215032[6] = 0;
   out_2957883628728215032[7] = 0;
   out_2957883628728215032[8] = 0;
   out_2957883628728215032[9] = 0;
   out_2957883628728215032[10] = 1;
   out_2957883628728215032[11] = 0;
   out_2957883628728215032[12] = 0;
   out_2957883628728215032[13] = 0;
   out_2957883628728215032[14] = 0;
   out_2957883628728215032[15] = 0;
   out_2957883628728215032[16] = 0;
   out_2957883628728215032[17] = 0;
   out_2957883628728215032[18] = 0;
   out_2957883628728215032[19] = 0;
   out_2957883628728215032[20] = 1;
   out_2957883628728215032[21] = 0;
   out_2957883628728215032[22] = 0;
   out_2957883628728215032[23] = 0;
   out_2957883628728215032[24] = 0;
   out_2957883628728215032[25] = 0;
   out_2957883628728215032[26] = 0;
   out_2957883628728215032[27] = 0;
   out_2957883628728215032[28] = 0;
   out_2957883628728215032[29] = 0;
   out_2957883628728215032[30] = 1;
   out_2957883628728215032[31] = 0;
   out_2957883628728215032[32] = 0;
   out_2957883628728215032[33] = 0;
   out_2957883628728215032[34] = 0;
   out_2957883628728215032[35] = 0;
   out_2957883628728215032[36] = 0;
   out_2957883628728215032[37] = 0;
   out_2957883628728215032[38] = 0;
   out_2957883628728215032[39] = 0;
   out_2957883628728215032[40] = 1;
   out_2957883628728215032[41] = 0;
   out_2957883628728215032[42] = 0;
   out_2957883628728215032[43] = 0;
   out_2957883628728215032[44] = 0;
   out_2957883628728215032[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2957883628728215032[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2957883628728215032[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2957883628728215032[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2957883628728215032[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2957883628728215032[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2957883628728215032[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2957883628728215032[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2957883628728215032[53] = -9.8100000000000005*dt;
   out_2957883628728215032[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2957883628728215032[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2957883628728215032[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2957883628728215032[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2957883628728215032[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2957883628728215032[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2957883628728215032[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2957883628728215032[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2957883628728215032[62] = 0;
   out_2957883628728215032[63] = 0;
   out_2957883628728215032[64] = 0;
   out_2957883628728215032[65] = 0;
   out_2957883628728215032[66] = 0;
   out_2957883628728215032[67] = 0;
   out_2957883628728215032[68] = 0;
   out_2957883628728215032[69] = 0;
   out_2957883628728215032[70] = 1;
   out_2957883628728215032[71] = 0;
   out_2957883628728215032[72] = 0;
   out_2957883628728215032[73] = 0;
   out_2957883628728215032[74] = 0;
   out_2957883628728215032[75] = 0;
   out_2957883628728215032[76] = 0;
   out_2957883628728215032[77] = 0;
   out_2957883628728215032[78] = 0;
   out_2957883628728215032[79] = 0;
   out_2957883628728215032[80] = 1;
}
void h_25(double *state, double *unused, double *out_753214482939102632) {
   out_753214482939102632[0] = state[6];
}
void H_25(double *state, double *unused, double *out_58633887827741607) {
   out_58633887827741607[0] = 0;
   out_58633887827741607[1] = 0;
   out_58633887827741607[2] = 0;
   out_58633887827741607[3] = 0;
   out_58633887827741607[4] = 0;
   out_58633887827741607[5] = 0;
   out_58633887827741607[6] = 1;
   out_58633887827741607[7] = 0;
   out_58633887827741607[8] = 0;
}
void h_24(double *state, double *unused, double *out_163608178505822735) {
   out_163608178505822735[0] = state[4];
   out_163608178505822735[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6142398792023419819) {
   out_6142398792023419819[0] = 0;
   out_6142398792023419819[1] = 0;
   out_6142398792023419819[2] = 0;
   out_6142398792023419819[3] = 0;
   out_6142398792023419819[4] = 1;
   out_6142398792023419819[5] = 0;
   out_6142398792023419819[6] = 0;
   out_6142398792023419819[7] = 0;
   out_6142398792023419819[8] = 0;
   out_6142398792023419819[9] = 0;
   out_6142398792023419819[10] = 0;
   out_6142398792023419819[11] = 0;
   out_6142398792023419819[12] = 0;
   out_6142398792023419819[13] = 0;
   out_6142398792023419819[14] = 1;
   out_6142398792023419819[15] = 0;
   out_6142398792023419819[16] = 0;
   out_6142398792023419819[17] = 0;
}
void h_30(double *state, double *unused, double *out_596027814587973487) {
   out_596027814587973487[0] = state[4];
}
void H_30(double *state, double *unused, double *out_70705059315498463) {
   out_70705059315498463[0] = 0;
   out_70705059315498463[1] = 0;
   out_70705059315498463[2] = 0;
   out_70705059315498463[3] = 0;
   out_70705059315498463[4] = 1;
   out_70705059315498463[5] = 0;
   out_70705059315498463[6] = 0;
   out_70705059315498463[7] = 0;
   out_70705059315498463[8] = 0;
}
void h_26(double *state, double *unused, double *out_6995069332001822633) {
   out_6995069332001822633[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3682869431046314617) {
   out_3682869431046314617[0] = 0;
   out_3682869431046314617[1] = 0;
   out_3682869431046314617[2] = 0;
   out_3682869431046314617[3] = 0;
   out_3682869431046314617[4] = 0;
   out_3682869431046314617[5] = 0;
   out_3682869431046314617[6] = 0;
   out_3682869431046314617[7] = 1;
   out_3682869431046314617[8] = 0;
}
void h_27(double *state, double *unused, double *out_8228754689067738133) {
   out_8228754689067738133[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2245468371115923374) {
   out_2245468371115923374[0] = 0;
   out_2245468371115923374[1] = 0;
   out_2245468371115923374[2] = 0;
   out_2245468371115923374[3] = 1;
   out_2245468371115923374[4] = 0;
   out_2245468371115923374[5] = 0;
   out_2245468371115923374[6] = 0;
   out_2245468371115923374[7] = 0;
   out_2245468371115923374[8] = 0;
}
void h_29(double *state, double *unused, double *out_347482038313688948) {
   out_347482038313688948[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3958831097985474407) {
   out_3958831097985474407[0] = 0;
   out_3958831097985474407[1] = 1;
   out_3958831097985474407[2] = 0;
   out_3958831097985474407[3] = 0;
   out_3958831097985474407[4] = 0;
   out_3958831097985474407[5] = 0;
   out_3958831097985474407[6] = 0;
   out_3958831097985474407[7] = 0;
   out_3958831097985474407[8] = 0;
}
void h_28(double *state, double *unused, double *out_7625438804391260616) {
   out_7625438804391260616[0] = state[0];
}
void H_28(double *state, double *unused, double *out_9041230115055004981) {
   out_9041230115055004981[0] = 1;
   out_9041230115055004981[1] = 0;
   out_9041230115055004981[2] = 0;
   out_9041230115055004981[3] = 0;
   out_9041230115055004981[4] = 0;
   out_9041230115055004981[5] = 0;
   out_9041230115055004981[6] = 0;
   out_9041230115055004981[7] = 0;
   out_9041230115055004981[8] = 0;
}
void h_31(double *state, double *unused, double *out_5467162699907911337) {
   out_5467162699907911337[0] = state[8];
}
void H_31(double *state, double *unused, double *out_89279849704702035) {
   out_89279849704702035[0] = 0;
   out_89279849704702035[1] = 0;
   out_89279849704702035[2] = 0;
   out_89279849704702035[3] = 0;
   out_89279849704702035[4] = 0;
   out_89279849704702035[5] = 0;
   out_89279849704702035[6] = 0;
   out_89279849704702035[7] = 0;
   out_89279849704702035[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6663383586198040946) {
  err_fun(nom_x, delta_x, out_6663383586198040946);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8588337980518277825) {
  inv_err_fun(nom_x, true_x, out_8588337980518277825);
}
void car_H_mod_fun(double *state, double *out_6555656847717771558) {
  H_mod_fun(state, out_6555656847717771558);
}
void car_f_fun(double *state, double dt, double *out_7137582187284124708) {
  f_fun(state,  dt, out_7137582187284124708);
}
void car_F_fun(double *state, double dt, double *out_2957883628728215032) {
  F_fun(state,  dt, out_2957883628728215032);
}
void car_h_25(double *state, double *unused, double *out_753214482939102632) {
  h_25(state, unused, out_753214482939102632);
}
void car_H_25(double *state, double *unused, double *out_58633887827741607) {
  H_25(state, unused, out_58633887827741607);
}
void car_h_24(double *state, double *unused, double *out_163608178505822735) {
  h_24(state, unused, out_163608178505822735);
}
void car_H_24(double *state, double *unused, double *out_6142398792023419819) {
  H_24(state, unused, out_6142398792023419819);
}
void car_h_30(double *state, double *unused, double *out_596027814587973487) {
  h_30(state, unused, out_596027814587973487);
}
void car_H_30(double *state, double *unused, double *out_70705059315498463) {
  H_30(state, unused, out_70705059315498463);
}
void car_h_26(double *state, double *unused, double *out_6995069332001822633) {
  h_26(state, unused, out_6995069332001822633);
}
void car_H_26(double *state, double *unused, double *out_3682869431046314617) {
  H_26(state, unused, out_3682869431046314617);
}
void car_h_27(double *state, double *unused, double *out_8228754689067738133) {
  h_27(state, unused, out_8228754689067738133);
}
void car_H_27(double *state, double *unused, double *out_2245468371115923374) {
  H_27(state, unused, out_2245468371115923374);
}
void car_h_29(double *state, double *unused, double *out_347482038313688948) {
  h_29(state, unused, out_347482038313688948);
}
void car_H_29(double *state, double *unused, double *out_3958831097985474407) {
  H_29(state, unused, out_3958831097985474407);
}
void car_h_28(double *state, double *unused, double *out_7625438804391260616) {
  h_28(state, unused, out_7625438804391260616);
}
void car_H_28(double *state, double *unused, double *out_9041230115055004981) {
  H_28(state, unused, out_9041230115055004981);
}
void car_h_31(double *state, double *unused, double *out_5467162699907911337) {
  h_31(state, unused, out_5467162699907911337);
}
void car_H_31(double *state, double *unused, double *out_89279849704702035) {
  H_31(state, unused, out_89279849704702035);
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
