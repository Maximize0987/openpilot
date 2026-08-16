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
void err_fun(double *nom_x, double *delta_x, double *out_5397134643365763284) {
   out_5397134643365763284[0] = delta_x[0] + nom_x[0];
   out_5397134643365763284[1] = delta_x[1] + nom_x[1];
   out_5397134643365763284[2] = delta_x[2] + nom_x[2];
   out_5397134643365763284[3] = delta_x[3] + nom_x[3];
   out_5397134643365763284[4] = delta_x[4] + nom_x[4];
   out_5397134643365763284[5] = delta_x[5] + nom_x[5];
   out_5397134643365763284[6] = delta_x[6] + nom_x[6];
   out_5397134643365763284[7] = delta_x[7] + nom_x[7];
   out_5397134643365763284[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_643379036491463030) {
   out_643379036491463030[0] = -nom_x[0] + true_x[0];
   out_643379036491463030[1] = -nom_x[1] + true_x[1];
   out_643379036491463030[2] = -nom_x[2] + true_x[2];
   out_643379036491463030[3] = -nom_x[3] + true_x[3];
   out_643379036491463030[4] = -nom_x[4] + true_x[4];
   out_643379036491463030[5] = -nom_x[5] + true_x[5];
   out_643379036491463030[6] = -nom_x[6] + true_x[6];
   out_643379036491463030[7] = -nom_x[7] + true_x[7];
   out_643379036491463030[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8008223313057305919) {
   out_8008223313057305919[0] = 1.0;
   out_8008223313057305919[1] = 0.0;
   out_8008223313057305919[2] = 0.0;
   out_8008223313057305919[3] = 0.0;
   out_8008223313057305919[4] = 0.0;
   out_8008223313057305919[5] = 0.0;
   out_8008223313057305919[6] = 0.0;
   out_8008223313057305919[7] = 0.0;
   out_8008223313057305919[8] = 0.0;
   out_8008223313057305919[9] = 0.0;
   out_8008223313057305919[10] = 1.0;
   out_8008223313057305919[11] = 0.0;
   out_8008223313057305919[12] = 0.0;
   out_8008223313057305919[13] = 0.0;
   out_8008223313057305919[14] = 0.0;
   out_8008223313057305919[15] = 0.0;
   out_8008223313057305919[16] = 0.0;
   out_8008223313057305919[17] = 0.0;
   out_8008223313057305919[18] = 0.0;
   out_8008223313057305919[19] = 0.0;
   out_8008223313057305919[20] = 1.0;
   out_8008223313057305919[21] = 0.0;
   out_8008223313057305919[22] = 0.0;
   out_8008223313057305919[23] = 0.0;
   out_8008223313057305919[24] = 0.0;
   out_8008223313057305919[25] = 0.0;
   out_8008223313057305919[26] = 0.0;
   out_8008223313057305919[27] = 0.0;
   out_8008223313057305919[28] = 0.0;
   out_8008223313057305919[29] = 0.0;
   out_8008223313057305919[30] = 1.0;
   out_8008223313057305919[31] = 0.0;
   out_8008223313057305919[32] = 0.0;
   out_8008223313057305919[33] = 0.0;
   out_8008223313057305919[34] = 0.0;
   out_8008223313057305919[35] = 0.0;
   out_8008223313057305919[36] = 0.0;
   out_8008223313057305919[37] = 0.0;
   out_8008223313057305919[38] = 0.0;
   out_8008223313057305919[39] = 0.0;
   out_8008223313057305919[40] = 1.0;
   out_8008223313057305919[41] = 0.0;
   out_8008223313057305919[42] = 0.0;
   out_8008223313057305919[43] = 0.0;
   out_8008223313057305919[44] = 0.0;
   out_8008223313057305919[45] = 0.0;
   out_8008223313057305919[46] = 0.0;
   out_8008223313057305919[47] = 0.0;
   out_8008223313057305919[48] = 0.0;
   out_8008223313057305919[49] = 0.0;
   out_8008223313057305919[50] = 1.0;
   out_8008223313057305919[51] = 0.0;
   out_8008223313057305919[52] = 0.0;
   out_8008223313057305919[53] = 0.0;
   out_8008223313057305919[54] = 0.0;
   out_8008223313057305919[55] = 0.0;
   out_8008223313057305919[56] = 0.0;
   out_8008223313057305919[57] = 0.0;
   out_8008223313057305919[58] = 0.0;
   out_8008223313057305919[59] = 0.0;
   out_8008223313057305919[60] = 1.0;
   out_8008223313057305919[61] = 0.0;
   out_8008223313057305919[62] = 0.0;
   out_8008223313057305919[63] = 0.0;
   out_8008223313057305919[64] = 0.0;
   out_8008223313057305919[65] = 0.0;
   out_8008223313057305919[66] = 0.0;
   out_8008223313057305919[67] = 0.0;
   out_8008223313057305919[68] = 0.0;
   out_8008223313057305919[69] = 0.0;
   out_8008223313057305919[70] = 1.0;
   out_8008223313057305919[71] = 0.0;
   out_8008223313057305919[72] = 0.0;
   out_8008223313057305919[73] = 0.0;
   out_8008223313057305919[74] = 0.0;
   out_8008223313057305919[75] = 0.0;
   out_8008223313057305919[76] = 0.0;
   out_8008223313057305919[77] = 0.0;
   out_8008223313057305919[78] = 0.0;
   out_8008223313057305919[79] = 0.0;
   out_8008223313057305919[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1320186800141293730) {
   out_1320186800141293730[0] = state[0];
   out_1320186800141293730[1] = state[1];
   out_1320186800141293730[2] = state[2];
   out_1320186800141293730[3] = state[3];
   out_1320186800141293730[4] = state[4];
   out_1320186800141293730[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1320186800141293730[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1320186800141293730[7] = state[7];
   out_1320186800141293730[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4790924461105660686) {
   out_4790924461105660686[0] = 1;
   out_4790924461105660686[1] = 0;
   out_4790924461105660686[2] = 0;
   out_4790924461105660686[3] = 0;
   out_4790924461105660686[4] = 0;
   out_4790924461105660686[5] = 0;
   out_4790924461105660686[6] = 0;
   out_4790924461105660686[7] = 0;
   out_4790924461105660686[8] = 0;
   out_4790924461105660686[9] = 0;
   out_4790924461105660686[10] = 1;
   out_4790924461105660686[11] = 0;
   out_4790924461105660686[12] = 0;
   out_4790924461105660686[13] = 0;
   out_4790924461105660686[14] = 0;
   out_4790924461105660686[15] = 0;
   out_4790924461105660686[16] = 0;
   out_4790924461105660686[17] = 0;
   out_4790924461105660686[18] = 0;
   out_4790924461105660686[19] = 0;
   out_4790924461105660686[20] = 1;
   out_4790924461105660686[21] = 0;
   out_4790924461105660686[22] = 0;
   out_4790924461105660686[23] = 0;
   out_4790924461105660686[24] = 0;
   out_4790924461105660686[25] = 0;
   out_4790924461105660686[26] = 0;
   out_4790924461105660686[27] = 0;
   out_4790924461105660686[28] = 0;
   out_4790924461105660686[29] = 0;
   out_4790924461105660686[30] = 1;
   out_4790924461105660686[31] = 0;
   out_4790924461105660686[32] = 0;
   out_4790924461105660686[33] = 0;
   out_4790924461105660686[34] = 0;
   out_4790924461105660686[35] = 0;
   out_4790924461105660686[36] = 0;
   out_4790924461105660686[37] = 0;
   out_4790924461105660686[38] = 0;
   out_4790924461105660686[39] = 0;
   out_4790924461105660686[40] = 1;
   out_4790924461105660686[41] = 0;
   out_4790924461105660686[42] = 0;
   out_4790924461105660686[43] = 0;
   out_4790924461105660686[44] = 0;
   out_4790924461105660686[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4790924461105660686[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4790924461105660686[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4790924461105660686[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4790924461105660686[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4790924461105660686[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4790924461105660686[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4790924461105660686[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4790924461105660686[53] = -9.8100000000000005*dt;
   out_4790924461105660686[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4790924461105660686[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4790924461105660686[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4790924461105660686[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4790924461105660686[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4790924461105660686[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4790924461105660686[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4790924461105660686[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4790924461105660686[62] = 0;
   out_4790924461105660686[63] = 0;
   out_4790924461105660686[64] = 0;
   out_4790924461105660686[65] = 0;
   out_4790924461105660686[66] = 0;
   out_4790924461105660686[67] = 0;
   out_4790924461105660686[68] = 0;
   out_4790924461105660686[69] = 0;
   out_4790924461105660686[70] = 1;
   out_4790924461105660686[71] = 0;
   out_4790924461105660686[72] = 0;
   out_4790924461105660686[73] = 0;
   out_4790924461105660686[74] = 0;
   out_4790924461105660686[75] = 0;
   out_4790924461105660686[76] = 0;
   out_4790924461105660686[77] = 0;
   out_4790924461105660686[78] = 0;
   out_4790924461105660686[79] = 0;
   out_4790924461105660686[80] = 1;
}
void h_25(double *state, double *unused, double *out_4267314374776649182) {
   out_4267314374776649182[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5534828935467580857) {
   out_5534828935467580857[0] = 0;
   out_5534828935467580857[1] = 0;
   out_5534828935467580857[2] = 0;
   out_5534828935467580857[3] = 0;
   out_5534828935467580857[4] = 0;
   out_5534828935467580857[5] = 0;
   out_5534828935467580857[6] = 1;
   out_5534828935467580857[7] = 0;
   out_5534828935467580857[8] = 0;
}
void h_24(double *state, double *unused, double *out_544790792172897547) {
   out_544790792172897547[0] = state[4];
   out_544790792172897547[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7263692054644894926) {
   out_7263692054644894926[0] = 0;
   out_7263692054644894926[1] = 0;
   out_7263692054644894926[2] = 0;
   out_7263692054644894926[3] = 0;
   out_7263692054644894926[4] = 1;
   out_7263692054644894926[5] = 0;
   out_7263692054644894926[6] = 0;
   out_7263692054644894926[7] = 0;
   out_7263692054644894926[8] = 0;
   out_7263692054644894926[9] = 0;
   out_7263692054644894926[10] = 0;
   out_7263692054644894926[11] = 0;
   out_7263692054644894926[12] = 0;
   out_7263692054644894926[13] = 0;
   out_7263692054644894926[14] = 1;
   out_7263692054644894926[15] = 0;
   out_7263692054644894926[16] = 0;
   out_7263692054644894926[17] = 0;
}
void h_30(double *state, double *unused, double *out_1899799665194485121) {
   out_1899799665194485121[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1381861406024035898) {
   out_1381861406024035898[0] = 0;
   out_1381861406024035898[1] = 0;
   out_1381861406024035898[2] = 0;
   out_1381861406024035898[3] = 0;
   out_1381861406024035898[4] = 1;
   out_1381861406024035898[5] = 0;
   out_1381861406024035898[6] = 0;
   out_1381861406024035898[7] = 0;
   out_1381861406024035898[8] = 0;
}
void h_26(double *state, double *unused, double *out_956289812292822686) {
   out_956289812292822686[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2230302965706780256) {
   out_2230302965706780256[0] = 0;
   out_2230302965706780256[1] = 0;
   out_2230302965706780256[2] = 0;
   out_2230302965706780256[3] = 0;
   out_2230302965706780256[4] = 0;
   out_2230302965706780256[5] = 0;
   out_2230302965706780256[6] = 0;
   out_2230302965706780256[7] = 1;
   out_2230302965706780256[8] = 0;
}
void h_27(double *state, double *unused, double *out_9177756431272056789) {
   out_9177756431272056789[0] = state[3];
}
void H_27(double *state, double *unused, double *out_792901905776389013) {
   out_792901905776389013[0] = 0;
   out_792901905776389013[1] = 0;
   out_792901905776389013[2] = 0;
   out_792901905776389013[3] = 1;
   out_792901905776389013[4] = 0;
   out_792901905776389013[5] = 0;
   out_792901905776389013[6] = 0;
   out_792901905776389013[7] = 0;
   out_792901905776389013[8] = 0;
}
void h_29(double *state, double *unused, double *out_8902562368987550900) {
   out_8902562368987550900[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2506264632645940046) {
   out_2506264632645940046[0] = 0;
   out_2506264632645940046[1] = 1;
   out_2506264632645940046[2] = 0;
   out_2506264632645940046[3] = 0;
   out_2506264632645940046[4] = 0;
   out_2506264632645940046[5] = 0;
   out_2506264632645940046[6] = 0;
   out_2506264632645940046[7] = 0;
   out_2506264632645940046[8] = 0;
}
void h_28(double *state, double *unused, double *out_3951849215436731842) {
   out_3951849215436731842[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7588663649715470620) {
   out_7588663649715470620[0] = 1;
   out_7588663649715470620[1] = 0;
   out_7588663649715470620[2] = 0;
   out_7588663649715470620[3] = 0;
   out_7588663649715470620[4] = 0;
   out_7588663649715470620[5] = 0;
   out_7588663649715470620[6] = 0;
   out_7588663649715470620[7] = 0;
   out_7588663649715470620[8] = 0;
}
void h_31(double *state, double *unused, double *out_629864846522626832) {
   out_629864846522626832[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1541846315044236396) {
   out_1541846315044236396[0] = 0;
   out_1541846315044236396[1] = 0;
   out_1541846315044236396[2] = 0;
   out_1541846315044236396[3] = 0;
   out_1541846315044236396[4] = 0;
   out_1541846315044236396[5] = 0;
   out_1541846315044236396[6] = 0;
   out_1541846315044236396[7] = 0;
   out_1541846315044236396[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5397134643365763284) {
  err_fun(nom_x, delta_x, out_5397134643365763284);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_643379036491463030) {
  inv_err_fun(nom_x, true_x, out_643379036491463030);
}
void car_H_mod_fun(double *state, double *out_8008223313057305919) {
  H_mod_fun(state, out_8008223313057305919);
}
void car_f_fun(double *state, double dt, double *out_1320186800141293730) {
  f_fun(state,  dt, out_1320186800141293730);
}
void car_F_fun(double *state, double dt, double *out_4790924461105660686) {
  F_fun(state,  dt, out_4790924461105660686);
}
void car_h_25(double *state, double *unused, double *out_4267314374776649182) {
  h_25(state, unused, out_4267314374776649182);
}
void car_H_25(double *state, double *unused, double *out_5534828935467580857) {
  H_25(state, unused, out_5534828935467580857);
}
void car_h_24(double *state, double *unused, double *out_544790792172897547) {
  h_24(state, unused, out_544790792172897547);
}
void car_H_24(double *state, double *unused, double *out_7263692054644894926) {
  H_24(state, unused, out_7263692054644894926);
}
void car_h_30(double *state, double *unused, double *out_1899799665194485121) {
  h_30(state, unused, out_1899799665194485121);
}
void car_H_30(double *state, double *unused, double *out_1381861406024035898) {
  H_30(state, unused, out_1381861406024035898);
}
void car_h_26(double *state, double *unused, double *out_956289812292822686) {
  h_26(state, unused, out_956289812292822686);
}
void car_H_26(double *state, double *unused, double *out_2230302965706780256) {
  H_26(state, unused, out_2230302965706780256);
}
void car_h_27(double *state, double *unused, double *out_9177756431272056789) {
  h_27(state, unused, out_9177756431272056789);
}
void car_H_27(double *state, double *unused, double *out_792901905776389013) {
  H_27(state, unused, out_792901905776389013);
}
void car_h_29(double *state, double *unused, double *out_8902562368987550900) {
  h_29(state, unused, out_8902562368987550900);
}
void car_H_29(double *state, double *unused, double *out_2506264632645940046) {
  H_29(state, unused, out_2506264632645940046);
}
void car_h_28(double *state, double *unused, double *out_3951849215436731842) {
  h_28(state, unused, out_3951849215436731842);
}
void car_H_28(double *state, double *unused, double *out_7588663649715470620) {
  H_28(state, unused, out_7588663649715470620);
}
void car_h_31(double *state, double *unused, double *out_629864846522626832) {
  h_31(state, unused, out_629864846522626832);
}
void car_H_31(double *state, double *unused, double *out_1541846315044236396) {
  H_31(state, unused, out_1541846315044236396);
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
