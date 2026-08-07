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
void err_fun(double *nom_x, double *delta_x, double *out_3432893246118840176) {
   out_3432893246118840176[0] = delta_x[0] + nom_x[0];
   out_3432893246118840176[1] = delta_x[1] + nom_x[1];
   out_3432893246118840176[2] = delta_x[2] + nom_x[2];
   out_3432893246118840176[3] = delta_x[3] + nom_x[3];
   out_3432893246118840176[4] = delta_x[4] + nom_x[4];
   out_3432893246118840176[5] = delta_x[5] + nom_x[5];
   out_3432893246118840176[6] = delta_x[6] + nom_x[6];
   out_3432893246118840176[7] = delta_x[7] + nom_x[7];
   out_3432893246118840176[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1800982245938664737) {
   out_1800982245938664737[0] = -nom_x[0] + true_x[0];
   out_1800982245938664737[1] = -nom_x[1] + true_x[1];
   out_1800982245938664737[2] = -nom_x[2] + true_x[2];
   out_1800982245938664737[3] = -nom_x[3] + true_x[3];
   out_1800982245938664737[4] = -nom_x[4] + true_x[4];
   out_1800982245938664737[5] = -nom_x[5] + true_x[5];
   out_1800982245938664737[6] = -nom_x[6] + true_x[6];
   out_1800982245938664737[7] = -nom_x[7] + true_x[7];
   out_1800982245938664737[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1928298863277366044) {
   out_1928298863277366044[0] = 1.0;
   out_1928298863277366044[1] = 0.0;
   out_1928298863277366044[2] = 0.0;
   out_1928298863277366044[3] = 0.0;
   out_1928298863277366044[4] = 0.0;
   out_1928298863277366044[5] = 0.0;
   out_1928298863277366044[6] = 0.0;
   out_1928298863277366044[7] = 0.0;
   out_1928298863277366044[8] = 0.0;
   out_1928298863277366044[9] = 0.0;
   out_1928298863277366044[10] = 1.0;
   out_1928298863277366044[11] = 0.0;
   out_1928298863277366044[12] = 0.0;
   out_1928298863277366044[13] = 0.0;
   out_1928298863277366044[14] = 0.0;
   out_1928298863277366044[15] = 0.0;
   out_1928298863277366044[16] = 0.0;
   out_1928298863277366044[17] = 0.0;
   out_1928298863277366044[18] = 0.0;
   out_1928298863277366044[19] = 0.0;
   out_1928298863277366044[20] = 1.0;
   out_1928298863277366044[21] = 0.0;
   out_1928298863277366044[22] = 0.0;
   out_1928298863277366044[23] = 0.0;
   out_1928298863277366044[24] = 0.0;
   out_1928298863277366044[25] = 0.0;
   out_1928298863277366044[26] = 0.0;
   out_1928298863277366044[27] = 0.0;
   out_1928298863277366044[28] = 0.0;
   out_1928298863277366044[29] = 0.0;
   out_1928298863277366044[30] = 1.0;
   out_1928298863277366044[31] = 0.0;
   out_1928298863277366044[32] = 0.0;
   out_1928298863277366044[33] = 0.0;
   out_1928298863277366044[34] = 0.0;
   out_1928298863277366044[35] = 0.0;
   out_1928298863277366044[36] = 0.0;
   out_1928298863277366044[37] = 0.0;
   out_1928298863277366044[38] = 0.0;
   out_1928298863277366044[39] = 0.0;
   out_1928298863277366044[40] = 1.0;
   out_1928298863277366044[41] = 0.0;
   out_1928298863277366044[42] = 0.0;
   out_1928298863277366044[43] = 0.0;
   out_1928298863277366044[44] = 0.0;
   out_1928298863277366044[45] = 0.0;
   out_1928298863277366044[46] = 0.0;
   out_1928298863277366044[47] = 0.0;
   out_1928298863277366044[48] = 0.0;
   out_1928298863277366044[49] = 0.0;
   out_1928298863277366044[50] = 1.0;
   out_1928298863277366044[51] = 0.0;
   out_1928298863277366044[52] = 0.0;
   out_1928298863277366044[53] = 0.0;
   out_1928298863277366044[54] = 0.0;
   out_1928298863277366044[55] = 0.0;
   out_1928298863277366044[56] = 0.0;
   out_1928298863277366044[57] = 0.0;
   out_1928298863277366044[58] = 0.0;
   out_1928298863277366044[59] = 0.0;
   out_1928298863277366044[60] = 1.0;
   out_1928298863277366044[61] = 0.0;
   out_1928298863277366044[62] = 0.0;
   out_1928298863277366044[63] = 0.0;
   out_1928298863277366044[64] = 0.0;
   out_1928298863277366044[65] = 0.0;
   out_1928298863277366044[66] = 0.0;
   out_1928298863277366044[67] = 0.0;
   out_1928298863277366044[68] = 0.0;
   out_1928298863277366044[69] = 0.0;
   out_1928298863277366044[70] = 1.0;
   out_1928298863277366044[71] = 0.0;
   out_1928298863277366044[72] = 0.0;
   out_1928298863277366044[73] = 0.0;
   out_1928298863277366044[74] = 0.0;
   out_1928298863277366044[75] = 0.0;
   out_1928298863277366044[76] = 0.0;
   out_1928298863277366044[77] = 0.0;
   out_1928298863277366044[78] = 0.0;
   out_1928298863277366044[79] = 0.0;
   out_1928298863277366044[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4615698619111285378) {
   out_4615698619111285378[0] = state[0];
   out_4615698619111285378[1] = state[1];
   out_4615698619111285378[2] = state[2];
   out_4615698619111285378[3] = state[3];
   out_4615698619111285378[4] = state[4];
   out_4615698619111285378[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4615698619111285378[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4615698619111285378[7] = state[7];
   out_4615698619111285378[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4973087374980231388) {
   out_4973087374980231388[0] = 1;
   out_4973087374980231388[1] = 0;
   out_4973087374980231388[2] = 0;
   out_4973087374980231388[3] = 0;
   out_4973087374980231388[4] = 0;
   out_4973087374980231388[5] = 0;
   out_4973087374980231388[6] = 0;
   out_4973087374980231388[7] = 0;
   out_4973087374980231388[8] = 0;
   out_4973087374980231388[9] = 0;
   out_4973087374980231388[10] = 1;
   out_4973087374980231388[11] = 0;
   out_4973087374980231388[12] = 0;
   out_4973087374980231388[13] = 0;
   out_4973087374980231388[14] = 0;
   out_4973087374980231388[15] = 0;
   out_4973087374980231388[16] = 0;
   out_4973087374980231388[17] = 0;
   out_4973087374980231388[18] = 0;
   out_4973087374980231388[19] = 0;
   out_4973087374980231388[20] = 1;
   out_4973087374980231388[21] = 0;
   out_4973087374980231388[22] = 0;
   out_4973087374980231388[23] = 0;
   out_4973087374980231388[24] = 0;
   out_4973087374980231388[25] = 0;
   out_4973087374980231388[26] = 0;
   out_4973087374980231388[27] = 0;
   out_4973087374980231388[28] = 0;
   out_4973087374980231388[29] = 0;
   out_4973087374980231388[30] = 1;
   out_4973087374980231388[31] = 0;
   out_4973087374980231388[32] = 0;
   out_4973087374980231388[33] = 0;
   out_4973087374980231388[34] = 0;
   out_4973087374980231388[35] = 0;
   out_4973087374980231388[36] = 0;
   out_4973087374980231388[37] = 0;
   out_4973087374980231388[38] = 0;
   out_4973087374980231388[39] = 0;
   out_4973087374980231388[40] = 1;
   out_4973087374980231388[41] = 0;
   out_4973087374980231388[42] = 0;
   out_4973087374980231388[43] = 0;
   out_4973087374980231388[44] = 0;
   out_4973087374980231388[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4973087374980231388[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4973087374980231388[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4973087374980231388[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4973087374980231388[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4973087374980231388[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4973087374980231388[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4973087374980231388[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4973087374980231388[53] = -9.8100000000000005*dt;
   out_4973087374980231388[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4973087374980231388[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4973087374980231388[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4973087374980231388[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4973087374980231388[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4973087374980231388[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4973087374980231388[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4973087374980231388[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4973087374980231388[62] = 0;
   out_4973087374980231388[63] = 0;
   out_4973087374980231388[64] = 0;
   out_4973087374980231388[65] = 0;
   out_4973087374980231388[66] = 0;
   out_4973087374980231388[67] = 0;
   out_4973087374980231388[68] = 0;
   out_4973087374980231388[69] = 0;
   out_4973087374980231388[70] = 1;
   out_4973087374980231388[71] = 0;
   out_4973087374980231388[72] = 0;
   out_4973087374980231388[73] = 0;
   out_4973087374980231388[74] = 0;
   out_4973087374980231388[75] = 0;
   out_4973087374980231388[76] = 0;
   out_4973087374980231388[77] = 0;
   out_4973087374980231388[78] = 0;
   out_4973087374980231388[79] = 0;
   out_4973087374980231388[80] = 1;
}
void h_25(double *state, double *unused, double *out_725345121681315694) {
   out_725345121681315694[0] = state[6];
}
void H_25(double *state, double *unused, double *out_140226422483346712) {
   out_140226422483346712[0] = 0;
   out_140226422483346712[1] = 0;
   out_140226422483346712[2] = 0;
   out_140226422483346712[3] = 0;
   out_140226422483346712[4] = 0;
   out_140226422483346712[5] = 0;
   out_140226422483346712[6] = 1;
   out_140226422483346712[7] = 0;
   out_140226422483346712[8] = 0;
}
void h_24(double *state, double *unused, double *out_4245224659262713745) {
   out_4245224659262713745[0] = state[4];
   out_4245224659262713745[1] = state[5];
}
void H_24(double *state, double *unused, double *out_610683904526685436) {
   out_610683904526685436[0] = 0;
   out_610683904526685436[1] = 0;
   out_610683904526685436[2] = 0;
   out_610683904526685436[3] = 0;
   out_610683904526685436[4] = 1;
   out_610683904526685436[5] = 0;
   out_610683904526685436[6] = 0;
   out_610683904526685436[7] = 0;
   out_610683904526685436[8] = 0;
   out_610683904526685436[9] = 0;
   out_610683904526685436[10] = 0;
   out_610683904526685436[11] = 0;
   out_610683904526685436[12] = 0;
   out_610683904526685436[13] = 0;
   out_610683904526685436[14] = 1;
   out_610683904526685436[15] = 0;
   out_610683904526685436[16] = 0;
   out_610683904526685436[17] = 0;
}
void h_30(double *state, double *unused, double *out_882531790032444839) {
   out_882531790032444839[0] = state[4];
}
void H_30(double *state, double *unused, double *out_269565369626586782) {
   out_269565369626586782[0] = 0;
   out_269565369626586782[1] = 0;
   out_269565369626586782[2] = 0;
   out_269565369626586782[3] = 0;
   out_269565369626586782[4] = 1;
   out_269565369626586782[5] = 0;
   out_269565369626586782[6] = 0;
   out_269565369626586782[7] = 0;
   out_269565369626586782[8] = 0;
}
void h_26(double *state, double *unused, double *out_1240296775338871155) {
   out_1240296775338871155[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3881729741357402936) {
   out_3881729741357402936[0] = 0;
   out_3881729741357402936[1] = 0;
   out_3881729741357402936[2] = 0;
   out_3881729741357402936[3] = 0;
   out_3881729741357402936[4] = 0;
   out_3881729741357402936[5] = 0;
   out_3881729741357402936[6] = 0;
   out_3881729741357402936[7] = 1;
   out_3881729741357402936[8] = 0;
}
void h_27(double *state, double *unused, double *out_4276328145979529951) {
   out_4276328145979529951[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2444328681427011693) {
   out_2444328681427011693[0] = 0;
   out_2444328681427011693[1] = 0;
   out_2444328681427011693[2] = 0;
   out_2444328681427011693[3] = 1;
   out_2444328681427011693[4] = 0;
   out_2444328681427011693[5] = 0;
   out_2444328681427011693[6] = 0;
   out_2444328681427011693[7] = 0;
   out_2444328681427011693[8] = 0;
}
void h_29(double *state, double *unused, double *out_3486937110841142490) {
   out_3486937110841142490[0] = state[1];
}
void H_29(double *state, double *unused, double *out_240665974687805402) {
   out_240665974687805402[0] = 0;
   out_240665974687805402[1] = 1;
   out_240665974687805402[2] = 0;
   out_240665974687805402[3] = 0;
   out_240665974687805402[4] = 0;
   out_240665974687805402[5] = 0;
   out_240665974687805402[6] = 0;
   out_240665974687805402[7] = 0;
   out_240665974687805402[8] = 0;
}
void h_28(double *state, double *unused, double *out_4705641026027310814) {
   out_4705641026027310814[0] = state[0];
}
void H_28(double *state, double *unused, double *out_9206653648343458316) {
   out_9206653648343458316[0] = 1;
   out_9206653648343458316[1] = 0;
   out_9206653648343458316[2] = 0;
   out_9206653648343458316[3] = 0;
   out_9206653648343458316[4] = 0;
   out_9206653648343458316[5] = 0;
   out_9206653648343458316[6] = 0;
   out_9206653648343458316[7] = 0;
   out_9206653648343458316[8] = 0;
}
void h_31(double *state, double *unused, double *out_6045490104669035242) {
   out_6045490104669035242[0] = state[8];
}
void H_31(double *state, double *unused, double *out_109580460606386284) {
   out_109580460606386284[0] = 0;
   out_109580460606386284[1] = 0;
   out_109580460606386284[2] = 0;
   out_109580460606386284[3] = 0;
   out_109580460606386284[4] = 0;
   out_109580460606386284[5] = 0;
   out_109580460606386284[6] = 0;
   out_109580460606386284[7] = 0;
   out_109580460606386284[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3432893246118840176) {
  err_fun(nom_x, delta_x, out_3432893246118840176);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1800982245938664737) {
  inv_err_fun(nom_x, true_x, out_1800982245938664737);
}
void car_H_mod_fun(double *state, double *out_1928298863277366044) {
  H_mod_fun(state, out_1928298863277366044);
}
void car_f_fun(double *state, double dt, double *out_4615698619111285378) {
  f_fun(state,  dt, out_4615698619111285378);
}
void car_F_fun(double *state, double dt, double *out_4973087374980231388) {
  F_fun(state,  dt, out_4973087374980231388);
}
void car_h_25(double *state, double *unused, double *out_725345121681315694) {
  h_25(state, unused, out_725345121681315694);
}
void car_H_25(double *state, double *unused, double *out_140226422483346712) {
  H_25(state, unused, out_140226422483346712);
}
void car_h_24(double *state, double *unused, double *out_4245224659262713745) {
  h_24(state, unused, out_4245224659262713745);
}
void car_H_24(double *state, double *unused, double *out_610683904526685436) {
  H_24(state, unused, out_610683904526685436);
}
void car_h_30(double *state, double *unused, double *out_882531790032444839) {
  h_30(state, unused, out_882531790032444839);
}
void car_H_30(double *state, double *unused, double *out_269565369626586782) {
  H_30(state, unused, out_269565369626586782);
}
void car_h_26(double *state, double *unused, double *out_1240296775338871155) {
  h_26(state, unused, out_1240296775338871155);
}
void car_H_26(double *state, double *unused, double *out_3881729741357402936) {
  H_26(state, unused, out_3881729741357402936);
}
void car_h_27(double *state, double *unused, double *out_4276328145979529951) {
  h_27(state, unused, out_4276328145979529951);
}
void car_H_27(double *state, double *unused, double *out_2444328681427011693) {
  H_27(state, unused, out_2444328681427011693);
}
void car_h_29(double *state, double *unused, double *out_3486937110841142490) {
  h_29(state, unused, out_3486937110841142490);
}
void car_H_29(double *state, double *unused, double *out_240665974687805402) {
  H_29(state, unused, out_240665974687805402);
}
void car_h_28(double *state, double *unused, double *out_4705641026027310814) {
  h_28(state, unused, out_4705641026027310814);
}
void car_H_28(double *state, double *unused, double *out_9206653648343458316) {
  H_28(state, unused, out_9206653648343458316);
}
void car_h_31(double *state, double *unused, double *out_6045490104669035242) {
  h_31(state, unused, out_6045490104669035242);
}
void car_H_31(double *state, double *unused, double *out_109580460606386284) {
  H_31(state, unused, out_109580460606386284);
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
