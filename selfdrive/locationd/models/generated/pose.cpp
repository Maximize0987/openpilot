#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_384350097947890971) {
   out_384350097947890971[0] = delta_x[0] + nom_x[0];
   out_384350097947890971[1] = delta_x[1] + nom_x[1];
   out_384350097947890971[2] = delta_x[2] + nom_x[2];
   out_384350097947890971[3] = delta_x[3] + nom_x[3];
   out_384350097947890971[4] = delta_x[4] + nom_x[4];
   out_384350097947890971[5] = delta_x[5] + nom_x[5];
   out_384350097947890971[6] = delta_x[6] + nom_x[6];
   out_384350097947890971[7] = delta_x[7] + nom_x[7];
   out_384350097947890971[8] = delta_x[8] + nom_x[8];
   out_384350097947890971[9] = delta_x[9] + nom_x[9];
   out_384350097947890971[10] = delta_x[10] + nom_x[10];
   out_384350097947890971[11] = delta_x[11] + nom_x[11];
   out_384350097947890971[12] = delta_x[12] + nom_x[12];
   out_384350097947890971[13] = delta_x[13] + nom_x[13];
   out_384350097947890971[14] = delta_x[14] + nom_x[14];
   out_384350097947890971[15] = delta_x[15] + nom_x[15];
   out_384350097947890971[16] = delta_x[16] + nom_x[16];
   out_384350097947890971[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_161730175994041380) {
   out_161730175994041380[0] = -nom_x[0] + true_x[0];
   out_161730175994041380[1] = -nom_x[1] + true_x[1];
   out_161730175994041380[2] = -nom_x[2] + true_x[2];
   out_161730175994041380[3] = -nom_x[3] + true_x[3];
   out_161730175994041380[4] = -nom_x[4] + true_x[4];
   out_161730175994041380[5] = -nom_x[5] + true_x[5];
   out_161730175994041380[6] = -nom_x[6] + true_x[6];
   out_161730175994041380[7] = -nom_x[7] + true_x[7];
   out_161730175994041380[8] = -nom_x[8] + true_x[8];
   out_161730175994041380[9] = -nom_x[9] + true_x[9];
   out_161730175994041380[10] = -nom_x[10] + true_x[10];
   out_161730175994041380[11] = -nom_x[11] + true_x[11];
   out_161730175994041380[12] = -nom_x[12] + true_x[12];
   out_161730175994041380[13] = -nom_x[13] + true_x[13];
   out_161730175994041380[14] = -nom_x[14] + true_x[14];
   out_161730175994041380[15] = -nom_x[15] + true_x[15];
   out_161730175994041380[16] = -nom_x[16] + true_x[16];
   out_161730175994041380[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_511897058818169074) {
   out_511897058818169074[0] = 1.0;
   out_511897058818169074[1] = 0.0;
   out_511897058818169074[2] = 0.0;
   out_511897058818169074[3] = 0.0;
   out_511897058818169074[4] = 0.0;
   out_511897058818169074[5] = 0.0;
   out_511897058818169074[6] = 0.0;
   out_511897058818169074[7] = 0.0;
   out_511897058818169074[8] = 0.0;
   out_511897058818169074[9] = 0.0;
   out_511897058818169074[10] = 0.0;
   out_511897058818169074[11] = 0.0;
   out_511897058818169074[12] = 0.0;
   out_511897058818169074[13] = 0.0;
   out_511897058818169074[14] = 0.0;
   out_511897058818169074[15] = 0.0;
   out_511897058818169074[16] = 0.0;
   out_511897058818169074[17] = 0.0;
   out_511897058818169074[18] = 0.0;
   out_511897058818169074[19] = 1.0;
   out_511897058818169074[20] = 0.0;
   out_511897058818169074[21] = 0.0;
   out_511897058818169074[22] = 0.0;
   out_511897058818169074[23] = 0.0;
   out_511897058818169074[24] = 0.0;
   out_511897058818169074[25] = 0.0;
   out_511897058818169074[26] = 0.0;
   out_511897058818169074[27] = 0.0;
   out_511897058818169074[28] = 0.0;
   out_511897058818169074[29] = 0.0;
   out_511897058818169074[30] = 0.0;
   out_511897058818169074[31] = 0.0;
   out_511897058818169074[32] = 0.0;
   out_511897058818169074[33] = 0.0;
   out_511897058818169074[34] = 0.0;
   out_511897058818169074[35] = 0.0;
   out_511897058818169074[36] = 0.0;
   out_511897058818169074[37] = 0.0;
   out_511897058818169074[38] = 1.0;
   out_511897058818169074[39] = 0.0;
   out_511897058818169074[40] = 0.0;
   out_511897058818169074[41] = 0.0;
   out_511897058818169074[42] = 0.0;
   out_511897058818169074[43] = 0.0;
   out_511897058818169074[44] = 0.0;
   out_511897058818169074[45] = 0.0;
   out_511897058818169074[46] = 0.0;
   out_511897058818169074[47] = 0.0;
   out_511897058818169074[48] = 0.0;
   out_511897058818169074[49] = 0.0;
   out_511897058818169074[50] = 0.0;
   out_511897058818169074[51] = 0.0;
   out_511897058818169074[52] = 0.0;
   out_511897058818169074[53] = 0.0;
   out_511897058818169074[54] = 0.0;
   out_511897058818169074[55] = 0.0;
   out_511897058818169074[56] = 0.0;
   out_511897058818169074[57] = 1.0;
   out_511897058818169074[58] = 0.0;
   out_511897058818169074[59] = 0.0;
   out_511897058818169074[60] = 0.0;
   out_511897058818169074[61] = 0.0;
   out_511897058818169074[62] = 0.0;
   out_511897058818169074[63] = 0.0;
   out_511897058818169074[64] = 0.0;
   out_511897058818169074[65] = 0.0;
   out_511897058818169074[66] = 0.0;
   out_511897058818169074[67] = 0.0;
   out_511897058818169074[68] = 0.0;
   out_511897058818169074[69] = 0.0;
   out_511897058818169074[70] = 0.0;
   out_511897058818169074[71] = 0.0;
   out_511897058818169074[72] = 0.0;
   out_511897058818169074[73] = 0.0;
   out_511897058818169074[74] = 0.0;
   out_511897058818169074[75] = 0.0;
   out_511897058818169074[76] = 1.0;
   out_511897058818169074[77] = 0.0;
   out_511897058818169074[78] = 0.0;
   out_511897058818169074[79] = 0.0;
   out_511897058818169074[80] = 0.0;
   out_511897058818169074[81] = 0.0;
   out_511897058818169074[82] = 0.0;
   out_511897058818169074[83] = 0.0;
   out_511897058818169074[84] = 0.0;
   out_511897058818169074[85] = 0.0;
   out_511897058818169074[86] = 0.0;
   out_511897058818169074[87] = 0.0;
   out_511897058818169074[88] = 0.0;
   out_511897058818169074[89] = 0.0;
   out_511897058818169074[90] = 0.0;
   out_511897058818169074[91] = 0.0;
   out_511897058818169074[92] = 0.0;
   out_511897058818169074[93] = 0.0;
   out_511897058818169074[94] = 0.0;
   out_511897058818169074[95] = 1.0;
   out_511897058818169074[96] = 0.0;
   out_511897058818169074[97] = 0.0;
   out_511897058818169074[98] = 0.0;
   out_511897058818169074[99] = 0.0;
   out_511897058818169074[100] = 0.0;
   out_511897058818169074[101] = 0.0;
   out_511897058818169074[102] = 0.0;
   out_511897058818169074[103] = 0.0;
   out_511897058818169074[104] = 0.0;
   out_511897058818169074[105] = 0.0;
   out_511897058818169074[106] = 0.0;
   out_511897058818169074[107] = 0.0;
   out_511897058818169074[108] = 0.0;
   out_511897058818169074[109] = 0.0;
   out_511897058818169074[110] = 0.0;
   out_511897058818169074[111] = 0.0;
   out_511897058818169074[112] = 0.0;
   out_511897058818169074[113] = 0.0;
   out_511897058818169074[114] = 1.0;
   out_511897058818169074[115] = 0.0;
   out_511897058818169074[116] = 0.0;
   out_511897058818169074[117] = 0.0;
   out_511897058818169074[118] = 0.0;
   out_511897058818169074[119] = 0.0;
   out_511897058818169074[120] = 0.0;
   out_511897058818169074[121] = 0.0;
   out_511897058818169074[122] = 0.0;
   out_511897058818169074[123] = 0.0;
   out_511897058818169074[124] = 0.0;
   out_511897058818169074[125] = 0.0;
   out_511897058818169074[126] = 0.0;
   out_511897058818169074[127] = 0.0;
   out_511897058818169074[128] = 0.0;
   out_511897058818169074[129] = 0.0;
   out_511897058818169074[130] = 0.0;
   out_511897058818169074[131] = 0.0;
   out_511897058818169074[132] = 0.0;
   out_511897058818169074[133] = 1.0;
   out_511897058818169074[134] = 0.0;
   out_511897058818169074[135] = 0.0;
   out_511897058818169074[136] = 0.0;
   out_511897058818169074[137] = 0.0;
   out_511897058818169074[138] = 0.0;
   out_511897058818169074[139] = 0.0;
   out_511897058818169074[140] = 0.0;
   out_511897058818169074[141] = 0.0;
   out_511897058818169074[142] = 0.0;
   out_511897058818169074[143] = 0.0;
   out_511897058818169074[144] = 0.0;
   out_511897058818169074[145] = 0.0;
   out_511897058818169074[146] = 0.0;
   out_511897058818169074[147] = 0.0;
   out_511897058818169074[148] = 0.0;
   out_511897058818169074[149] = 0.0;
   out_511897058818169074[150] = 0.0;
   out_511897058818169074[151] = 0.0;
   out_511897058818169074[152] = 1.0;
   out_511897058818169074[153] = 0.0;
   out_511897058818169074[154] = 0.0;
   out_511897058818169074[155] = 0.0;
   out_511897058818169074[156] = 0.0;
   out_511897058818169074[157] = 0.0;
   out_511897058818169074[158] = 0.0;
   out_511897058818169074[159] = 0.0;
   out_511897058818169074[160] = 0.0;
   out_511897058818169074[161] = 0.0;
   out_511897058818169074[162] = 0.0;
   out_511897058818169074[163] = 0.0;
   out_511897058818169074[164] = 0.0;
   out_511897058818169074[165] = 0.0;
   out_511897058818169074[166] = 0.0;
   out_511897058818169074[167] = 0.0;
   out_511897058818169074[168] = 0.0;
   out_511897058818169074[169] = 0.0;
   out_511897058818169074[170] = 0.0;
   out_511897058818169074[171] = 1.0;
   out_511897058818169074[172] = 0.0;
   out_511897058818169074[173] = 0.0;
   out_511897058818169074[174] = 0.0;
   out_511897058818169074[175] = 0.0;
   out_511897058818169074[176] = 0.0;
   out_511897058818169074[177] = 0.0;
   out_511897058818169074[178] = 0.0;
   out_511897058818169074[179] = 0.0;
   out_511897058818169074[180] = 0.0;
   out_511897058818169074[181] = 0.0;
   out_511897058818169074[182] = 0.0;
   out_511897058818169074[183] = 0.0;
   out_511897058818169074[184] = 0.0;
   out_511897058818169074[185] = 0.0;
   out_511897058818169074[186] = 0.0;
   out_511897058818169074[187] = 0.0;
   out_511897058818169074[188] = 0.0;
   out_511897058818169074[189] = 0.0;
   out_511897058818169074[190] = 1.0;
   out_511897058818169074[191] = 0.0;
   out_511897058818169074[192] = 0.0;
   out_511897058818169074[193] = 0.0;
   out_511897058818169074[194] = 0.0;
   out_511897058818169074[195] = 0.0;
   out_511897058818169074[196] = 0.0;
   out_511897058818169074[197] = 0.0;
   out_511897058818169074[198] = 0.0;
   out_511897058818169074[199] = 0.0;
   out_511897058818169074[200] = 0.0;
   out_511897058818169074[201] = 0.0;
   out_511897058818169074[202] = 0.0;
   out_511897058818169074[203] = 0.0;
   out_511897058818169074[204] = 0.0;
   out_511897058818169074[205] = 0.0;
   out_511897058818169074[206] = 0.0;
   out_511897058818169074[207] = 0.0;
   out_511897058818169074[208] = 0.0;
   out_511897058818169074[209] = 1.0;
   out_511897058818169074[210] = 0.0;
   out_511897058818169074[211] = 0.0;
   out_511897058818169074[212] = 0.0;
   out_511897058818169074[213] = 0.0;
   out_511897058818169074[214] = 0.0;
   out_511897058818169074[215] = 0.0;
   out_511897058818169074[216] = 0.0;
   out_511897058818169074[217] = 0.0;
   out_511897058818169074[218] = 0.0;
   out_511897058818169074[219] = 0.0;
   out_511897058818169074[220] = 0.0;
   out_511897058818169074[221] = 0.0;
   out_511897058818169074[222] = 0.0;
   out_511897058818169074[223] = 0.0;
   out_511897058818169074[224] = 0.0;
   out_511897058818169074[225] = 0.0;
   out_511897058818169074[226] = 0.0;
   out_511897058818169074[227] = 0.0;
   out_511897058818169074[228] = 1.0;
   out_511897058818169074[229] = 0.0;
   out_511897058818169074[230] = 0.0;
   out_511897058818169074[231] = 0.0;
   out_511897058818169074[232] = 0.0;
   out_511897058818169074[233] = 0.0;
   out_511897058818169074[234] = 0.0;
   out_511897058818169074[235] = 0.0;
   out_511897058818169074[236] = 0.0;
   out_511897058818169074[237] = 0.0;
   out_511897058818169074[238] = 0.0;
   out_511897058818169074[239] = 0.0;
   out_511897058818169074[240] = 0.0;
   out_511897058818169074[241] = 0.0;
   out_511897058818169074[242] = 0.0;
   out_511897058818169074[243] = 0.0;
   out_511897058818169074[244] = 0.0;
   out_511897058818169074[245] = 0.0;
   out_511897058818169074[246] = 0.0;
   out_511897058818169074[247] = 1.0;
   out_511897058818169074[248] = 0.0;
   out_511897058818169074[249] = 0.0;
   out_511897058818169074[250] = 0.0;
   out_511897058818169074[251] = 0.0;
   out_511897058818169074[252] = 0.0;
   out_511897058818169074[253] = 0.0;
   out_511897058818169074[254] = 0.0;
   out_511897058818169074[255] = 0.0;
   out_511897058818169074[256] = 0.0;
   out_511897058818169074[257] = 0.0;
   out_511897058818169074[258] = 0.0;
   out_511897058818169074[259] = 0.0;
   out_511897058818169074[260] = 0.0;
   out_511897058818169074[261] = 0.0;
   out_511897058818169074[262] = 0.0;
   out_511897058818169074[263] = 0.0;
   out_511897058818169074[264] = 0.0;
   out_511897058818169074[265] = 0.0;
   out_511897058818169074[266] = 1.0;
   out_511897058818169074[267] = 0.0;
   out_511897058818169074[268] = 0.0;
   out_511897058818169074[269] = 0.0;
   out_511897058818169074[270] = 0.0;
   out_511897058818169074[271] = 0.0;
   out_511897058818169074[272] = 0.0;
   out_511897058818169074[273] = 0.0;
   out_511897058818169074[274] = 0.0;
   out_511897058818169074[275] = 0.0;
   out_511897058818169074[276] = 0.0;
   out_511897058818169074[277] = 0.0;
   out_511897058818169074[278] = 0.0;
   out_511897058818169074[279] = 0.0;
   out_511897058818169074[280] = 0.0;
   out_511897058818169074[281] = 0.0;
   out_511897058818169074[282] = 0.0;
   out_511897058818169074[283] = 0.0;
   out_511897058818169074[284] = 0.0;
   out_511897058818169074[285] = 1.0;
   out_511897058818169074[286] = 0.0;
   out_511897058818169074[287] = 0.0;
   out_511897058818169074[288] = 0.0;
   out_511897058818169074[289] = 0.0;
   out_511897058818169074[290] = 0.0;
   out_511897058818169074[291] = 0.0;
   out_511897058818169074[292] = 0.0;
   out_511897058818169074[293] = 0.0;
   out_511897058818169074[294] = 0.0;
   out_511897058818169074[295] = 0.0;
   out_511897058818169074[296] = 0.0;
   out_511897058818169074[297] = 0.0;
   out_511897058818169074[298] = 0.0;
   out_511897058818169074[299] = 0.0;
   out_511897058818169074[300] = 0.0;
   out_511897058818169074[301] = 0.0;
   out_511897058818169074[302] = 0.0;
   out_511897058818169074[303] = 0.0;
   out_511897058818169074[304] = 1.0;
   out_511897058818169074[305] = 0.0;
   out_511897058818169074[306] = 0.0;
   out_511897058818169074[307] = 0.0;
   out_511897058818169074[308] = 0.0;
   out_511897058818169074[309] = 0.0;
   out_511897058818169074[310] = 0.0;
   out_511897058818169074[311] = 0.0;
   out_511897058818169074[312] = 0.0;
   out_511897058818169074[313] = 0.0;
   out_511897058818169074[314] = 0.0;
   out_511897058818169074[315] = 0.0;
   out_511897058818169074[316] = 0.0;
   out_511897058818169074[317] = 0.0;
   out_511897058818169074[318] = 0.0;
   out_511897058818169074[319] = 0.0;
   out_511897058818169074[320] = 0.0;
   out_511897058818169074[321] = 0.0;
   out_511897058818169074[322] = 0.0;
   out_511897058818169074[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4006543374555760922) {
   out_4006543374555760922[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4006543374555760922[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4006543374555760922[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4006543374555760922[3] = dt*state[12] + state[3];
   out_4006543374555760922[4] = dt*state[13] + state[4];
   out_4006543374555760922[5] = dt*state[14] + state[5];
   out_4006543374555760922[6] = state[6];
   out_4006543374555760922[7] = state[7];
   out_4006543374555760922[8] = state[8];
   out_4006543374555760922[9] = state[9];
   out_4006543374555760922[10] = state[10];
   out_4006543374555760922[11] = state[11];
   out_4006543374555760922[12] = state[12];
   out_4006543374555760922[13] = state[13];
   out_4006543374555760922[14] = state[14];
   out_4006543374555760922[15] = state[15];
   out_4006543374555760922[16] = state[16];
   out_4006543374555760922[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8169752966009844936) {
   out_8169752966009844936[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8169752966009844936[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8169752966009844936[2] = 0;
   out_8169752966009844936[3] = 0;
   out_8169752966009844936[4] = 0;
   out_8169752966009844936[5] = 0;
   out_8169752966009844936[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8169752966009844936[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8169752966009844936[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8169752966009844936[9] = 0;
   out_8169752966009844936[10] = 0;
   out_8169752966009844936[11] = 0;
   out_8169752966009844936[12] = 0;
   out_8169752966009844936[13] = 0;
   out_8169752966009844936[14] = 0;
   out_8169752966009844936[15] = 0;
   out_8169752966009844936[16] = 0;
   out_8169752966009844936[17] = 0;
   out_8169752966009844936[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8169752966009844936[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8169752966009844936[20] = 0;
   out_8169752966009844936[21] = 0;
   out_8169752966009844936[22] = 0;
   out_8169752966009844936[23] = 0;
   out_8169752966009844936[24] = 0;
   out_8169752966009844936[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8169752966009844936[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8169752966009844936[27] = 0;
   out_8169752966009844936[28] = 0;
   out_8169752966009844936[29] = 0;
   out_8169752966009844936[30] = 0;
   out_8169752966009844936[31] = 0;
   out_8169752966009844936[32] = 0;
   out_8169752966009844936[33] = 0;
   out_8169752966009844936[34] = 0;
   out_8169752966009844936[35] = 0;
   out_8169752966009844936[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8169752966009844936[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8169752966009844936[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8169752966009844936[39] = 0;
   out_8169752966009844936[40] = 0;
   out_8169752966009844936[41] = 0;
   out_8169752966009844936[42] = 0;
   out_8169752966009844936[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8169752966009844936[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8169752966009844936[45] = 0;
   out_8169752966009844936[46] = 0;
   out_8169752966009844936[47] = 0;
   out_8169752966009844936[48] = 0;
   out_8169752966009844936[49] = 0;
   out_8169752966009844936[50] = 0;
   out_8169752966009844936[51] = 0;
   out_8169752966009844936[52] = 0;
   out_8169752966009844936[53] = 0;
   out_8169752966009844936[54] = 0;
   out_8169752966009844936[55] = 0;
   out_8169752966009844936[56] = 0;
   out_8169752966009844936[57] = 1;
   out_8169752966009844936[58] = 0;
   out_8169752966009844936[59] = 0;
   out_8169752966009844936[60] = 0;
   out_8169752966009844936[61] = 0;
   out_8169752966009844936[62] = 0;
   out_8169752966009844936[63] = 0;
   out_8169752966009844936[64] = 0;
   out_8169752966009844936[65] = 0;
   out_8169752966009844936[66] = dt;
   out_8169752966009844936[67] = 0;
   out_8169752966009844936[68] = 0;
   out_8169752966009844936[69] = 0;
   out_8169752966009844936[70] = 0;
   out_8169752966009844936[71] = 0;
   out_8169752966009844936[72] = 0;
   out_8169752966009844936[73] = 0;
   out_8169752966009844936[74] = 0;
   out_8169752966009844936[75] = 0;
   out_8169752966009844936[76] = 1;
   out_8169752966009844936[77] = 0;
   out_8169752966009844936[78] = 0;
   out_8169752966009844936[79] = 0;
   out_8169752966009844936[80] = 0;
   out_8169752966009844936[81] = 0;
   out_8169752966009844936[82] = 0;
   out_8169752966009844936[83] = 0;
   out_8169752966009844936[84] = 0;
   out_8169752966009844936[85] = dt;
   out_8169752966009844936[86] = 0;
   out_8169752966009844936[87] = 0;
   out_8169752966009844936[88] = 0;
   out_8169752966009844936[89] = 0;
   out_8169752966009844936[90] = 0;
   out_8169752966009844936[91] = 0;
   out_8169752966009844936[92] = 0;
   out_8169752966009844936[93] = 0;
   out_8169752966009844936[94] = 0;
   out_8169752966009844936[95] = 1;
   out_8169752966009844936[96] = 0;
   out_8169752966009844936[97] = 0;
   out_8169752966009844936[98] = 0;
   out_8169752966009844936[99] = 0;
   out_8169752966009844936[100] = 0;
   out_8169752966009844936[101] = 0;
   out_8169752966009844936[102] = 0;
   out_8169752966009844936[103] = 0;
   out_8169752966009844936[104] = dt;
   out_8169752966009844936[105] = 0;
   out_8169752966009844936[106] = 0;
   out_8169752966009844936[107] = 0;
   out_8169752966009844936[108] = 0;
   out_8169752966009844936[109] = 0;
   out_8169752966009844936[110] = 0;
   out_8169752966009844936[111] = 0;
   out_8169752966009844936[112] = 0;
   out_8169752966009844936[113] = 0;
   out_8169752966009844936[114] = 1;
   out_8169752966009844936[115] = 0;
   out_8169752966009844936[116] = 0;
   out_8169752966009844936[117] = 0;
   out_8169752966009844936[118] = 0;
   out_8169752966009844936[119] = 0;
   out_8169752966009844936[120] = 0;
   out_8169752966009844936[121] = 0;
   out_8169752966009844936[122] = 0;
   out_8169752966009844936[123] = 0;
   out_8169752966009844936[124] = 0;
   out_8169752966009844936[125] = 0;
   out_8169752966009844936[126] = 0;
   out_8169752966009844936[127] = 0;
   out_8169752966009844936[128] = 0;
   out_8169752966009844936[129] = 0;
   out_8169752966009844936[130] = 0;
   out_8169752966009844936[131] = 0;
   out_8169752966009844936[132] = 0;
   out_8169752966009844936[133] = 1;
   out_8169752966009844936[134] = 0;
   out_8169752966009844936[135] = 0;
   out_8169752966009844936[136] = 0;
   out_8169752966009844936[137] = 0;
   out_8169752966009844936[138] = 0;
   out_8169752966009844936[139] = 0;
   out_8169752966009844936[140] = 0;
   out_8169752966009844936[141] = 0;
   out_8169752966009844936[142] = 0;
   out_8169752966009844936[143] = 0;
   out_8169752966009844936[144] = 0;
   out_8169752966009844936[145] = 0;
   out_8169752966009844936[146] = 0;
   out_8169752966009844936[147] = 0;
   out_8169752966009844936[148] = 0;
   out_8169752966009844936[149] = 0;
   out_8169752966009844936[150] = 0;
   out_8169752966009844936[151] = 0;
   out_8169752966009844936[152] = 1;
   out_8169752966009844936[153] = 0;
   out_8169752966009844936[154] = 0;
   out_8169752966009844936[155] = 0;
   out_8169752966009844936[156] = 0;
   out_8169752966009844936[157] = 0;
   out_8169752966009844936[158] = 0;
   out_8169752966009844936[159] = 0;
   out_8169752966009844936[160] = 0;
   out_8169752966009844936[161] = 0;
   out_8169752966009844936[162] = 0;
   out_8169752966009844936[163] = 0;
   out_8169752966009844936[164] = 0;
   out_8169752966009844936[165] = 0;
   out_8169752966009844936[166] = 0;
   out_8169752966009844936[167] = 0;
   out_8169752966009844936[168] = 0;
   out_8169752966009844936[169] = 0;
   out_8169752966009844936[170] = 0;
   out_8169752966009844936[171] = 1;
   out_8169752966009844936[172] = 0;
   out_8169752966009844936[173] = 0;
   out_8169752966009844936[174] = 0;
   out_8169752966009844936[175] = 0;
   out_8169752966009844936[176] = 0;
   out_8169752966009844936[177] = 0;
   out_8169752966009844936[178] = 0;
   out_8169752966009844936[179] = 0;
   out_8169752966009844936[180] = 0;
   out_8169752966009844936[181] = 0;
   out_8169752966009844936[182] = 0;
   out_8169752966009844936[183] = 0;
   out_8169752966009844936[184] = 0;
   out_8169752966009844936[185] = 0;
   out_8169752966009844936[186] = 0;
   out_8169752966009844936[187] = 0;
   out_8169752966009844936[188] = 0;
   out_8169752966009844936[189] = 0;
   out_8169752966009844936[190] = 1;
   out_8169752966009844936[191] = 0;
   out_8169752966009844936[192] = 0;
   out_8169752966009844936[193] = 0;
   out_8169752966009844936[194] = 0;
   out_8169752966009844936[195] = 0;
   out_8169752966009844936[196] = 0;
   out_8169752966009844936[197] = 0;
   out_8169752966009844936[198] = 0;
   out_8169752966009844936[199] = 0;
   out_8169752966009844936[200] = 0;
   out_8169752966009844936[201] = 0;
   out_8169752966009844936[202] = 0;
   out_8169752966009844936[203] = 0;
   out_8169752966009844936[204] = 0;
   out_8169752966009844936[205] = 0;
   out_8169752966009844936[206] = 0;
   out_8169752966009844936[207] = 0;
   out_8169752966009844936[208] = 0;
   out_8169752966009844936[209] = 1;
   out_8169752966009844936[210] = 0;
   out_8169752966009844936[211] = 0;
   out_8169752966009844936[212] = 0;
   out_8169752966009844936[213] = 0;
   out_8169752966009844936[214] = 0;
   out_8169752966009844936[215] = 0;
   out_8169752966009844936[216] = 0;
   out_8169752966009844936[217] = 0;
   out_8169752966009844936[218] = 0;
   out_8169752966009844936[219] = 0;
   out_8169752966009844936[220] = 0;
   out_8169752966009844936[221] = 0;
   out_8169752966009844936[222] = 0;
   out_8169752966009844936[223] = 0;
   out_8169752966009844936[224] = 0;
   out_8169752966009844936[225] = 0;
   out_8169752966009844936[226] = 0;
   out_8169752966009844936[227] = 0;
   out_8169752966009844936[228] = 1;
   out_8169752966009844936[229] = 0;
   out_8169752966009844936[230] = 0;
   out_8169752966009844936[231] = 0;
   out_8169752966009844936[232] = 0;
   out_8169752966009844936[233] = 0;
   out_8169752966009844936[234] = 0;
   out_8169752966009844936[235] = 0;
   out_8169752966009844936[236] = 0;
   out_8169752966009844936[237] = 0;
   out_8169752966009844936[238] = 0;
   out_8169752966009844936[239] = 0;
   out_8169752966009844936[240] = 0;
   out_8169752966009844936[241] = 0;
   out_8169752966009844936[242] = 0;
   out_8169752966009844936[243] = 0;
   out_8169752966009844936[244] = 0;
   out_8169752966009844936[245] = 0;
   out_8169752966009844936[246] = 0;
   out_8169752966009844936[247] = 1;
   out_8169752966009844936[248] = 0;
   out_8169752966009844936[249] = 0;
   out_8169752966009844936[250] = 0;
   out_8169752966009844936[251] = 0;
   out_8169752966009844936[252] = 0;
   out_8169752966009844936[253] = 0;
   out_8169752966009844936[254] = 0;
   out_8169752966009844936[255] = 0;
   out_8169752966009844936[256] = 0;
   out_8169752966009844936[257] = 0;
   out_8169752966009844936[258] = 0;
   out_8169752966009844936[259] = 0;
   out_8169752966009844936[260] = 0;
   out_8169752966009844936[261] = 0;
   out_8169752966009844936[262] = 0;
   out_8169752966009844936[263] = 0;
   out_8169752966009844936[264] = 0;
   out_8169752966009844936[265] = 0;
   out_8169752966009844936[266] = 1;
   out_8169752966009844936[267] = 0;
   out_8169752966009844936[268] = 0;
   out_8169752966009844936[269] = 0;
   out_8169752966009844936[270] = 0;
   out_8169752966009844936[271] = 0;
   out_8169752966009844936[272] = 0;
   out_8169752966009844936[273] = 0;
   out_8169752966009844936[274] = 0;
   out_8169752966009844936[275] = 0;
   out_8169752966009844936[276] = 0;
   out_8169752966009844936[277] = 0;
   out_8169752966009844936[278] = 0;
   out_8169752966009844936[279] = 0;
   out_8169752966009844936[280] = 0;
   out_8169752966009844936[281] = 0;
   out_8169752966009844936[282] = 0;
   out_8169752966009844936[283] = 0;
   out_8169752966009844936[284] = 0;
   out_8169752966009844936[285] = 1;
   out_8169752966009844936[286] = 0;
   out_8169752966009844936[287] = 0;
   out_8169752966009844936[288] = 0;
   out_8169752966009844936[289] = 0;
   out_8169752966009844936[290] = 0;
   out_8169752966009844936[291] = 0;
   out_8169752966009844936[292] = 0;
   out_8169752966009844936[293] = 0;
   out_8169752966009844936[294] = 0;
   out_8169752966009844936[295] = 0;
   out_8169752966009844936[296] = 0;
   out_8169752966009844936[297] = 0;
   out_8169752966009844936[298] = 0;
   out_8169752966009844936[299] = 0;
   out_8169752966009844936[300] = 0;
   out_8169752966009844936[301] = 0;
   out_8169752966009844936[302] = 0;
   out_8169752966009844936[303] = 0;
   out_8169752966009844936[304] = 1;
   out_8169752966009844936[305] = 0;
   out_8169752966009844936[306] = 0;
   out_8169752966009844936[307] = 0;
   out_8169752966009844936[308] = 0;
   out_8169752966009844936[309] = 0;
   out_8169752966009844936[310] = 0;
   out_8169752966009844936[311] = 0;
   out_8169752966009844936[312] = 0;
   out_8169752966009844936[313] = 0;
   out_8169752966009844936[314] = 0;
   out_8169752966009844936[315] = 0;
   out_8169752966009844936[316] = 0;
   out_8169752966009844936[317] = 0;
   out_8169752966009844936[318] = 0;
   out_8169752966009844936[319] = 0;
   out_8169752966009844936[320] = 0;
   out_8169752966009844936[321] = 0;
   out_8169752966009844936[322] = 0;
   out_8169752966009844936[323] = 1;
}
void h_4(double *state, double *unused, double *out_2516225834102864115) {
   out_2516225834102864115[0] = state[6] + state[9];
   out_2516225834102864115[1] = state[7] + state[10];
   out_2516225834102864115[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_686050423064729030) {
   out_686050423064729030[0] = 0;
   out_686050423064729030[1] = 0;
   out_686050423064729030[2] = 0;
   out_686050423064729030[3] = 0;
   out_686050423064729030[4] = 0;
   out_686050423064729030[5] = 0;
   out_686050423064729030[6] = 1;
   out_686050423064729030[7] = 0;
   out_686050423064729030[8] = 0;
   out_686050423064729030[9] = 1;
   out_686050423064729030[10] = 0;
   out_686050423064729030[11] = 0;
   out_686050423064729030[12] = 0;
   out_686050423064729030[13] = 0;
   out_686050423064729030[14] = 0;
   out_686050423064729030[15] = 0;
   out_686050423064729030[16] = 0;
   out_686050423064729030[17] = 0;
   out_686050423064729030[18] = 0;
   out_686050423064729030[19] = 0;
   out_686050423064729030[20] = 0;
   out_686050423064729030[21] = 0;
   out_686050423064729030[22] = 0;
   out_686050423064729030[23] = 0;
   out_686050423064729030[24] = 0;
   out_686050423064729030[25] = 1;
   out_686050423064729030[26] = 0;
   out_686050423064729030[27] = 0;
   out_686050423064729030[28] = 1;
   out_686050423064729030[29] = 0;
   out_686050423064729030[30] = 0;
   out_686050423064729030[31] = 0;
   out_686050423064729030[32] = 0;
   out_686050423064729030[33] = 0;
   out_686050423064729030[34] = 0;
   out_686050423064729030[35] = 0;
   out_686050423064729030[36] = 0;
   out_686050423064729030[37] = 0;
   out_686050423064729030[38] = 0;
   out_686050423064729030[39] = 0;
   out_686050423064729030[40] = 0;
   out_686050423064729030[41] = 0;
   out_686050423064729030[42] = 0;
   out_686050423064729030[43] = 0;
   out_686050423064729030[44] = 1;
   out_686050423064729030[45] = 0;
   out_686050423064729030[46] = 0;
   out_686050423064729030[47] = 1;
   out_686050423064729030[48] = 0;
   out_686050423064729030[49] = 0;
   out_686050423064729030[50] = 0;
   out_686050423064729030[51] = 0;
   out_686050423064729030[52] = 0;
   out_686050423064729030[53] = 0;
}
void h_10(double *state, double *unused, double *out_865522221082823214) {
   out_865522221082823214[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_865522221082823214[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_865522221082823214[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8576192708028364696) {
   out_8576192708028364696[0] = 0;
   out_8576192708028364696[1] = 9.8100000000000005*cos(state[1]);
   out_8576192708028364696[2] = 0;
   out_8576192708028364696[3] = 0;
   out_8576192708028364696[4] = -state[8];
   out_8576192708028364696[5] = state[7];
   out_8576192708028364696[6] = 0;
   out_8576192708028364696[7] = state[5];
   out_8576192708028364696[8] = -state[4];
   out_8576192708028364696[9] = 0;
   out_8576192708028364696[10] = 0;
   out_8576192708028364696[11] = 0;
   out_8576192708028364696[12] = 1;
   out_8576192708028364696[13] = 0;
   out_8576192708028364696[14] = 0;
   out_8576192708028364696[15] = 1;
   out_8576192708028364696[16] = 0;
   out_8576192708028364696[17] = 0;
   out_8576192708028364696[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8576192708028364696[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8576192708028364696[20] = 0;
   out_8576192708028364696[21] = state[8];
   out_8576192708028364696[22] = 0;
   out_8576192708028364696[23] = -state[6];
   out_8576192708028364696[24] = -state[5];
   out_8576192708028364696[25] = 0;
   out_8576192708028364696[26] = state[3];
   out_8576192708028364696[27] = 0;
   out_8576192708028364696[28] = 0;
   out_8576192708028364696[29] = 0;
   out_8576192708028364696[30] = 0;
   out_8576192708028364696[31] = 1;
   out_8576192708028364696[32] = 0;
   out_8576192708028364696[33] = 0;
   out_8576192708028364696[34] = 1;
   out_8576192708028364696[35] = 0;
   out_8576192708028364696[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8576192708028364696[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8576192708028364696[38] = 0;
   out_8576192708028364696[39] = -state[7];
   out_8576192708028364696[40] = state[6];
   out_8576192708028364696[41] = 0;
   out_8576192708028364696[42] = state[4];
   out_8576192708028364696[43] = -state[3];
   out_8576192708028364696[44] = 0;
   out_8576192708028364696[45] = 0;
   out_8576192708028364696[46] = 0;
   out_8576192708028364696[47] = 0;
   out_8576192708028364696[48] = 0;
   out_8576192708028364696[49] = 0;
   out_8576192708028364696[50] = 1;
   out_8576192708028364696[51] = 0;
   out_8576192708028364696[52] = 0;
   out_8576192708028364696[53] = 1;
}
void h_13(double *state, double *unused, double *out_8706817024690289876) {
   out_8706817024690289876[0] = state[3];
   out_8706817024690289876[1] = state[4];
   out_8706817024690289876[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3898324248397061831) {
   out_3898324248397061831[0] = 0;
   out_3898324248397061831[1] = 0;
   out_3898324248397061831[2] = 0;
   out_3898324248397061831[3] = 1;
   out_3898324248397061831[4] = 0;
   out_3898324248397061831[5] = 0;
   out_3898324248397061831[6] = 0;
   out_3898324248397061831[7] = 0;
   out_3898324248397061831[8] = 0;
   out_3898324248397061831[9] = 0;
   out_3898324248397061831[10] = 0;
   out_3898324248397061831[11] = 0;
   out_3898324248397061831[12] = 0;
   out_3898324248397061831[13] = 0;
   out_3898324248397061831[14] = 0;
   out_3898324248397061831[15] = 0;
   out_3898324248397061831[16] = 0;
   out_3898324248397061831[17] = 0;
   out_3898324248397061831[18] = 0;
   out_3898324248397061831[19] = 0;
   out_3898324248397061831[20] = 0;
   out_3898324248397061831[21] = 0;
   out_3898324248397061831[22] = 1;
   out_3898324248397061831[23] = 0;
   out_3898324248397061831[24] = 0;
   out_3898324248397061831[25] = 0;
   out_3898324248397061831[26] = 0;
   out_3898324248397061831[27] = 0;
   out_3898324248397061831[28] = 0;
   out_3898324248397061831[29] = 0;
   out_3898324248397061831[30] = 0;
   out_3898324248397061831[31] = 0;
   out_3898324248397061831[32] = 0;
   out_3898324248397061831[33] = 0;
   out_3898324248397061831[34] = 0;
   out_3898324248397061831[35] = 0;
   out_3898324248397061831[36] = 0;
   out_3898324248397061831[37] = 0;
   out_3898324248397061831[38] = 0;
   out_3898324248397061831[39] = 0;
   out_3898324248397061831[40] = 0;
   out_3898324248397061831[41] = 1;
   out_3898324248397061831[42] = 0;
   out_3898324248397061831[43] = 0;
   out_3898324248397061831[44] = 0;
   out_3898324248397061831[45] = 0;
   out_3898324248397061831[46] = 0;
   out_3898324248397061831[47] = 0;
   out_3898324248397061831[48] = 0;
   out_3898324248397061831[49] = 0;
   out_3898324248397061831[50] = 0;
   out_3898324248397061831[51] = 0;
   out_3898324248397061831[52] = 0;
   out_3898324248397061831[53] = 0;
}
void h_14(double *state, double *unused, double *out_1828120776349525591) {
   out_1828120776349525591[0] = state[6];
   out_1828120776349525591[1] = state[7];
   out_1828120776349525591[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2396738009230643266) {
   out_2396738009230643266[0] = 0;
   out_2396738009230643266[1] = 0;
   out_2396738009230643266[2] = 0;
   out_2396738009230643266[3] = 0;
   out_2396738009230643266[4] = 0;
   out_2396738009230643266[5] = 0;
   out_2396738009230643266[6] = 1;
   out_2396738009230643266[7] = 0;
   out_2396738009230643266[8] = 0;
   out_2396738009230643266[9] = 0;
   out_2396738009230643266[10] = 0;
   out_2396738009230643266[11] = 0;
   out_2396738009230643266[12] = 0;
   out_2396738009230643266[13] = 0;
   out_2396738009230643266[14] = 0;
   out_2396738009230643266[15] = 0;
   out_2396738009230643266[16] = 0;
   out_2396738009230643266[17] = 0;
   out_2396738009230643266[18] = 0;
   out_2396738009230643266[19] = 0;
   out_2396738009230643266[20] = 0;
   out_2396738009230643266[21] = 0;
   out_2396738009230643266[22] = 0;
   out_2396738009230643266[23] = 0;
   out_2396738009230643266[24] = 0;
   out_2396738009230643266[25] = 1;
   out_2396738009230643266[26] = 0;
   out_2396738009230643266[27] = 0;
   out_2396738009230643266[28] = 0;
   out_2396738009230643266[29] = 0;
   out_2396738009230643266[30] = 0;
   out_2396738009230643266[31] = 0;
   out_2396738009230643266[32] = 0;
   out_2396738009230643266[33] = 0;
   out_2396738009230643266[34] = 0;
   out_2396738009230643266[35] = 0;
   out_2396738009230643266[36] = 0;
   out_2396738009230643266[37] = 0;
   out_2396738009230643266[38] = 0;
   out_2396738009230643266[39] = 0;
   out_2396738009230643266[40] = 0;
   out_2396738009230643266[41] = 0;
   out_2396738009230643266[42] = 0;
   out_2396738009230643266[43] = 0;
   out_2396738009230643266[44] = 1;
   out_2396738009230643266[45] = 0;
   out_2396738009230643266[46] = 0;
   out_2396738009230643266[47] = 0;
   out_2396738009230643266[48] = 0;
   out_2396738009230643266[49] = 0;
   out_2396738009230643266[50] = 0;
   out_2396738009230643266[51] = 0;
   out_2396738009230643266[52] = 0;
   out_2396738009230643266[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_384350097947890971) {
  err_fun(nom_x, delta_x, out_384350097947890971);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_161730175994041380) {
  inv_err_fun(nom_x, true_x, out_161730175994041380);
}
void pose_H_mod_fun(double *state, double *out_511897058818169074) {
  H_mod_fun(state, out_511897058818169074);
}
void pose_f_fun(double *state, double dt, double *out_4006543374555760922) {
  f_fun(state,  dt, out_4006543374555760922);
}
void pose_F_fun(double *state, double dt, double *out_8169752966009844936) {
  F_fun(state,  dt, out_8169752966009844936);
}
void pose_h_4(double *state, double *unused, double *out_2516225834102864115) {
  h_4(state, unused, out_2516225834102864115);
}
void pose_H_4(double *state, double *unused, double *out_686050423064729030) {
  H_4(state, unused, out_686050423064729030);
}
void pose_h_10(double *state, double *unused, double *out_865522221082823214) {
  h_10(state, unused, out_865522221082823214);
}
void pose_H_10(double *state, double *unused, double *out_8576192708028364696) {
  H_10(state, unused, out_8576192708028364696);
}
void pose_h_13(double *state, double *unused, double *out_8706817024690289876) {
  h_13(state, unused, out_8706817024690289876);
}
void pose_H_13(double *state, double *unused, double *out_3898324248397061831) {
  H_13(state, unused, out_3898324248397061831);
}
void pose_h_14(double *state, double *unused, double *out_1828120776349525591) {
  h_14(state, unused, out_1828120776349525591);
}
void pose_H_14(double *state, double *unused, double *out_2396738009230643266) {
  H_14(state, unused, out_2396738009230643266);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
