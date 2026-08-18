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
void err_fun(double *nom_x, double *delta_x, double *out_3059462324026594541) {
   out_3059462324026594541[0] = delta_x[0] + nom_x[0];
   out_3059462324026594541[1] = delta_x[1] + nom_x[1];
   out_3059462324026594541[2] = delta_x[2] + nom_x[2];
   out_3059462324026594541[3] = delta_x[3] + nom_x[3];
   out_3059462324026594541[4] = delta_x[4] + nom_x[4];
   out_3059462324026594541[5] = delta_x[5] + nom_x[5];
   out_3059462324026594541[6] = delta_x[6] + nom_x[6];
   out_3059462324026594541[7] = delta_x[7] + nom_x[7];
   out_3059462324026594541[8] = delta_x[8] + nom_x[8];
   out_3059462324026594541[9] = delta_x[9] + nom_x[9];
   out_3059462324026594541[10] = delta_x[10] + nom_x[10];
   out_3059462324026594541[11] = delta_x[11] + nom_x[11];
   out_3059462324026594541[12] = delta_x[12] + nom_x[12];
   out_3059462324026594541[13] = delta_x[13] + nom_x[13];
   out_3059462324026594541[14] = delta_x[14] + nom_x[14];
   out_3059462324026594541[15] = delta_x[15] + nom_x[15];
   out_3059462324026594541[16] = delta_x[16] + nom_x[16];
   out_3059462324026594541[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7293350812574481008) {
   out_7293350812574481008[0] = -nom_x[0] + true_x[0];
   out_7293350812574481008[1] = -nom_x[1] + true_x[1];
   out_7293350812574481008[2] = -nom_x[2] + true_x[2];
   out_7293350812574481008[3] = -nom_x[3] + true_x[3];
   out_7293350812574481008[4] = -nom_x[4] + true_x[4];
   out_7293350812574481008[5] = -nom_x[5] + true_x[5];
   out_7293350812574481008[6] = -nom_x[6] + true_x[6];
   out_7293350812574481008[7] = -nom_x[7] + true_x[7];
   out_7293350812574481008[8] = -nom_x[8] + true_x[8];
   out_7293350812574481008[9] = -nom_x[9] + true_x[9];
   out_7293350812574481008[10] = -nom_x[10] + true_x[10];
   out_7293350812574481008[11] = -nom_x[11] + true_x[11];
   out_7293350812574481008[12] = -nom_x[12] + true_x[12];
   out_7293350812574481008[13] = -nom_x[13] + true_x[13];
   out_7293350812574481008[14] = -nom_x[14] + true_x[14];
   out_7293350812574481008[15] = -nom_x[15] + true_x[15];
   out_7293350812574481008[16] = -nom_x[16] + true_x[16];
   out_7293350812574481008[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1219845042234673490) {
   out_1219845042234673490[0] = 1.0;
   out_1219845042234673490[1] = 0.0;
   out_1219845042234673490[2] = 0.0;
   out_1219845042234673490[3] = 0.0;
   out_1219845042234673490[4] = 0.0;
   out_1219845042234673490[5] = 0.0;
   out_1219845042234673490[6] = 0.0;
   out_1219845042234673490[7] = 0.0;
   out_1219845042234673490[8] = 0.0;
   out_1219845042234673490[9] = 0.0;
   out_1219845042234673490[10] = 0.0;
   out_1219845042234673490[11] = 0.0;
   out_1219845042234673490[12] = 0.0;
   out_1219845042234673490[13] = 0.0;
   out_1219845042234673490[14] = 0.0;
   out_1219845042234673490[15] = 0.0;
   out_1219845042234673490[16] = 0.0;
   out_1219845042234673490[17] = 0.0;
   out_1219845042234673490[18] = 0.0;
   out_1219845042234673490[19] = 1.0;
   out_1219845042234673490[20] = 0.0;
   out_1219845042234673490[21] = 0.0;
   out_1219845042234673490[22] = 0.0;
   out_1219845042234673490[23] = 0.0;
   out_1219845042234673490[24] = 0.0;
   out_1219845042234673490[25] = 0.0;
   out_1219845042234673490[26] = 0.0;
   out_1219845042234673490[27] = 0.0;
   out_1219845042234673490[28] = 0.0;
   out_1219845042234673490[29] = 0.0;
   out_1219845042234673490[30] = 0.0;
   out_1219845042234673490[31] = 0.0;
   out_1219845042234673490[32] = 0.0;
   out_1219845042234673490[33] = 0.0;
   out_1219845042234673490[34] = 0.0;
   out_1219845042234673490[35] = 0.0;
   out_1219845042234673490[36] = 0.0;
   out_1219845042234673490[37] = 0.0;
   out_1219845042234673490[38] = 1.0;
   out_1219845042234673490[39] = 0.0;
   out_1219845042234673490[40] = 0.0;
   out_1219845042234673490[41] = 0.0;
   out_1219845042234673490[42] = 0.0;
   out_1219845042234673490[43] = 0.0;
   out_1219845042234673490[44] = 0.0;
   out_1219845042234673490[45] = 0.0;
   out_1219845042234673490[46] = 0.0;
   out_1219845042234673490[47] = 0.0;
   out_1219845042234673490[48] = 0.0;
   out_1219845042234673490[49] = 0.0;
   out_1219845042234673490[50] = 0.0;
   out_1219845042234673490[51] = 0.0;
   out_1219845042234673490[52] = 0.0;
   out_1219845042234673490[53] = 0.0;
   out_1219845042234673490[54] = 0.0;
   out_1219845042234673490[55] = 0.0;
   out_1219845042234673490[56] = 0.0;
   out_1219845042234673490[57] = 1.0;
   out_1219845042234673490[58] = 0.0;
   out_1219845042234673490[59] = 0.0;
   out_1219845042234673490[60] = 0.0;
   out_1219845042234673490[61] = 0.0;
   out_1219845042234673490[62] = 0.0;
   out_1219845042234673490[63] = 0.0;
   out_1219845042234673490[64] = 0.0;
   out_1219845042234673490[65] = 0.0;
   out_1219845042234673490[66] = 0.0;
   out_1219845042234673490[67] = 0.0;
   out_1219845042234673490[68] = 0.0;
   out_1219845042234673490[69] = 0.0;
   out_1219845042234673490[70] = 0.0;
   out_1219845042234673490[71] = 0.0;
   out_1219845042234673490[72] = 0.0;
   out_1219845042234673490[73] = 0.0;
   out_1219845042234673490[74] = 0.0;
   out_1219845042234673490[75] = 0.0;
   out_1219845042234673490[76] = 1.0;
   out_1219845042234673490[77] = 0.0;
   out_1219845042234673490[78] = 0.0;
   out_1219845042234673490[79] = 0.0;
   out_1219845042234673490[80] = 0.0;
   out_1219845042234673490[81] = 0.0;
   out_1219845042234673490[82] = 0.0;
   out_1219845042234673490[83] = 0.0;
   out_1219845042234673490[84] = 0.0;
   out_1219845042234673490[85] = 0.0;
   out_1219845042234673490[86] = 0.0;
   out_1219845042234673490[87] = 0.0;
   out_1219845042234673490[88] = 0.0;
   out_1219845042234673490[89] = 0.0;
   out_1219845042234673490[90] = 0.0;
   out_1219845042234673490[91] = 0.0;
   out_1219845042234673490[92] = 0.0;
   out_1219845042234673490[93] = 0.0;
   out_1219845042234673490[94] = 0.0;
   out_1219845042234673490[95] = 1.0;
   out_1219845042234673490[96] = 0.0;
   out_1219845042234673490[97] = 0.0;
   out_1219845042234673490[98] = 0.0;
   out_1219845042234673490[99] = 0.0;
   out_1219845042234673490[100] = 0.0;
   out_1219845042234673490[101] = 0.0;
   out_1219845042234673490[102] = 0.0;
   out_1219845042234673490[103] = 0.0;
   out_1219845042234673490[104] = 0.0;
   out_1219845042234673490[105] = 0.0;
   out_1219845042234673490[106] = 0.0;
   out_1219845042234673490[107] = 0.0;
   out_1219845042234673490[108] = 0.0;
   out_1219845042234673490[109] = 0.0;
   out_1219845042234673490[110] = 0.0;
   out_1219845042234673490[111] = 0.0;
   out_1219845042234673490[112] = 0.0;
   out_1219845042234673490[113] = 0.0;
   out_1219845042234673490[114] = 1.0;
   out_1219845042234673490[115] = 0.0;
   out_1219845042234673490[116] = 0.0;
   out_1219845042234673490[117] = 0.0;
   out_1219845042234673490[118] = 0.0;
   out_1219845042234673490[119] = 0.0;
   out_1219845042234673490[120] = 0.0;
   out_1219845042234673490[121] = 0.0;
   out_1219845042234673490[122] = 0.0;
   out_1219845042234673490[123] = 0.0;
   out_1219845042234673490[124] = 0.0;
   out_1219845042234673490[125] = 0.0;
   out_1219845042234673490[126] = 0.0;
   out_1219845042234673490[127] = 0.0;
   out_1219845042234673490[128] = 0.0;
   out_1219845042234673490[129] = 0.0;
   out_1219845042234673490[130] = 0.0;
   out_1219845042234673490[131] = 0.0;
   out_1219845042234673490[132] = 0.0;
   out_1219845042234673490[133] = 1.0;
   out_1219845042234673490[134] = 0.0;
   out_1219845042234673490[135] = 0.0;
   out_1219845042234673490[136] = 0.0;
   out_1219845042234673490[137] = 0.0;
   out_1219845042234673490[138] = 0.0;
   out_1219845042234673490[139] = 0.0;
   out_1219845042234673490[140] = 0.0;
   out_1219845042234673490[141] = 0.0;
   out_1219845042234673490[142] = 0.0;
   out_1219845042234673490[143] = 0.0;
   out_1219845042234673490[144] = 0.0;
   out_1219845042234673490[145] = 0.0;
   out_1219845042234673490[146] = 0.0;
   out_1219845042234673490[147] = 0.0;
   out_1219845042234673490[148] = 0.0;
   out_1219845042234673490[149] = 0.0;
   out_1219845042234673490[150] = 0.0;
   out_1219845042234673490[151] = 0.0;
   out_1219845042234673490[152] = 1.0;
   out_1219845042234673490[153] = 0.0;
   out_1219845042234673490[154] = 0.0;
   out_1219845042234673490[155] = 0.0;
   out_1219845042234673490[156] = 0.0;
   out_1219845042234673490[157] = 0.0;
   out_1219845042234673490[158] = 0.0;
   out_1219845042234673490[159] = 0.0;
   out_1219845042234673490[160] = 0.0;
   out_1219845042234673490[161] = 0.0;
   out_1219845042234673490[162] = 0.0;
   out_1219845042234673490[163] = 0.0;
   out_1219845042234673490[164] = 0.0;
   out_1219845042234673490[165] = 0.0;
   out_1219845042234673490[166] = 0.0;
   out_1219845042234673490[167] = 0.0;
   out_1219845042234673490[168] = 0.0;
   out_1219845042234673490[169] = 0.0;
   out_1219845042234673490[170] = 0.0;
   out_1219845042234673490[171] = 1.0;
   out_1219845042234673490[172] = 0.0;
   out_1219845042234673490[173] = 0.0;
   out_1219845042234673490[174] = 0.0;
   out_1219845042234673490[175] = 0.0;
   out_1219845042234673490[176] = 0.0;
   out_1219845042234673490[177] = 0.0;
   out_1219845042234673490[178] = 0.0;
   out_1219845042234673490[179] = 0.0;
   out_1219845042234673490[180] = 0.0;
   out_1219845042234673490[181] = 0.0;
   out_1219845042234673490[182] = 0.0;
   out_1219845042234673490[183] = 0.0;
   out_1219845042234673490[184] = 0.0;
   out_1219845042234673490[185] = 0.0;
   out_1219845042234673490[186] = 0.0;
   out_1219845042234673490[187] = 0.0;
   out_1219845042234673490[188] = 0.0;
   out_1219845042234673490[189] = 0.0;
   out_1219845042234673490[190] = 1.0;
   out_1219845042234673490[191] = 0.0;
   out_1219845042234673490[192] = 0.0;
   out_1219845042234673490[193] = 0.0;
   out_1219845042234673490[194] = 0.0;
   out_1219845042234673490[195] = 0.0;
   out_1219845042234673490[196] = 0.0;
   out_1219845042234673490[197] = 0.0;
   out_1219845042234673490[198] = 0.0;
   out_1219845042234673490[199] = 0.0;
   out_1219845042234673490[200] = 0.0;
   out_1219845042234673490[201] = 0.0;
   out_1219845042234673490[202] = 0.0;
   out_1219845042234673490[203] = 0.0;
   out_1219845042234673490[204] = 0.0;
   out_1219845042234673490[205] = 0.0;
   out_1219845042234673490[206] = 0.0;
   out_1219845042234673490[207] = 0.0;
   out_1219845042234673490[208] = 0.0;
   out_1219845042234673490[209] = 1.0;
   out_1219845042234673490[210] = 0.0;
   out_1219845042234673490[211] = 0.0;
   out_1219845042234673490[212] = 0.0;
   out_1219845042234673490[213] = 0.0;
   out_1219845042234673490[214] = 0.0;
   out_1219845042234673490[215] = 0.0;
   out_1219845042234673490[216] = 0.0;
   out_1219845042234673490[217] = 0.0;
   out_1219845042234673490[218] = 0.0;
   out_1219845042234673490[219] = 0.0;
   out_1219845042234673490[220] = 0.0;
   out_1219845042234673490[221] = 0.0;
   out_1219845042234673490[222] = 0.0;
   out_1219845042234673490[223] = 0.0;
   out_1219845042234673490[224] = 0.0;
   out_1219845042234673490[225] = 0.0;
   out_1219845042234673490[226] = 0.0;
   out_1219845042234673490[227] = 0.0;
   out_1219845042234673490[228] = 1.0;
   out_1219845042234673490[229] = 0.0;
   out_1219845042234673490[230] = 0.0;
   out_1219845042234673490[231] = 0.0;
   out_1219845042234673490[232] = 0.0;
   out_1219845042234673490[233] = 0.0;
   out_1219845042234673490[234] = 0.0;
   out_1219845042234673490[235] = 0.0;
   out_1219845042234673490[236] = 0.0;
   out_1219845042234673490[237] = 0.0;
   out_1219845042234673490[238] = 0.0;
   out_1219845042234673490[239] = 0.0;
   out_1219845042234673490[240] = 0.0;
   out_1219845042234673490[241] = 0.0;
   out_1219845042234673490[242] = 0.0;
   out_1219845042234673490[243] = 0.0;
   out_1219845042234673490[244] = 0.0;
   out_1219845042234673490[245] = 0.0;
   out_1219845042234673490[246] = 0.0;
   out_1219845042234673490[247] = 1.0;
   out_1219845042234673490[248] = 0.0;
   out_1219845042234673490[249] = 0.0;
   out_1219845042234673490[250] = 0.0;
   out_1219845042234673490[251] = 0.0;
   out_1219845042234673490[252] = 0.0;
   out_1219845042234673490[253] = 0.0;
   out_1219845042234673490[254] = 0.0;
   out_1219845042234673490[255] = 0.0;
   out_1219845042234673490[256] = 0.0;
   out_1219845042234673490[257] = 0.0;
   out_1219845042234673490[258] = 0.0;
   out_1219845042234673490[259] = 0.0;
   out_1219845042234673490[260] = 0.0;
   out_1219845042234673490[261] = 0.0;
   out_1219845042234673490[262] = 0.0;
   out_1219845042234673490[263] = 0.0;
   out_1219845042234673490[264] = 0.0;
   out_1219845042234673490[265] = 0.0;
   out_1219845042234673490[266] = 1.0;
   out_1219845042234673490[267] = 0.0;
   out_1219845042234673490[268] = 0.0;
   out_1219845042234673490[269] = 0.0;
   out_1219845042234673490[270] = 0.0;
   out_1219845042234673490[271] = 0.0;
   out_1219845042234673490[272] = 0.0;
   out_1219845042234673490[273] = 0.0;
   out_1219845042234673490[274] = 0.0;
   out_1219845042234673490[275] = 0.0;
   out_1219845042234673490[276] = 0.0;
   out_1219845042234673490[277] = 0.0;
   out_1219845042234673490[278] = 0.0;
   out_1219845042234673490[279] = 0.0;
   out_1219845042234673490[280] = 0.0;
   out_1219845042234673490[281] = 0.0;
   out_1219845042234673490[282] = 0.0;
   out_1219845042234673490[283] = 0.0;
   out_1219845042234673490[284] = 0.0;
   out_1219845042234673490[285] = 1.0;
   out_1219845042234673490[286] = 0.0;
   out_1219845042234673490[287] = 0.0;
   out_1219845042234673490[288] = 0.0;
   out_1219845042234673490[289] = 0.0;
   out_1219845042234673490[290] = 0.0;
   out_1219845042234673490[291] = 0.0;
   out_1219845042234673490[292] = 0.0;
   out_1219845042234673490[293] = 0.0;
   out_1219845042234673490[294] = 0.0;
   out_1219845042234673490[295] = 0.0;
   out_1219845042234673490[296] = 0.0;
   out_1219845042234673490[297] = 0.0;
   out_1219845042234673490[298] = 0.0;
   out_1219845042234673490[299] = 0.0;
   out_1219845042234673490[300] = 0.0;
   out_1219845042234673490[301] = 0.0;
   out_1219845042234673490[302] = 0.0;
   out_1219845042234673490[303] = 0.0;
   out_1219845042234673490[304] = 1.0;
   out_1219845042234673490[305] = 0.0;
   out_1219845042234673490[306] = 0.0;
   out_1219845042234673490[307] = 0.0;
   out_1219845042234673490[308] = 0.0;
   out_1219845042234673490[309] = 0.0;
   out_1219845042234673490[310] = 0.0;
   out_1219845042234673490[311] = 0.0;
   out_1219845042234673490[312] = 0.0;
   out_1219845042234673490[313] = 0.0;
   out_1219845042234673490[314] = 0.0;
   out_1219845042234673490[315] = 0.0;
   out_1219845042234673490[316] = 0.0;
   out_1219845042234673490[317] = 0.0;
   out_1219845042234673490[318] = 0.0;
   out_1219845042234673490[319] = 0.0;
   out_1219845042234673490[320] = 0.0;
   out_1219845042234673490[321] = 0.0;
   out_1219845042234673490[322] = 0.0;
   out_1219845042234673490[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6142826586467809321) {
   out_6142826586467809321[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6142826586467809321[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6142826586467809321[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6142826586467809321[3] = dt*state[12] + state[3];
   out_6142826586467809321[4] = dt*state[13] + state[4];
   out_6142826586467809321[5] = dt*state[14] + state[5];
   out_6142826586467809321[6] = state[6];
   out_6142826586467809321[7] = state[7];
   out_6142826586467809321[8] = state[8];
   out_6142826586467809321[9] = state[9];
   out_6142826586467809321[10] = state[10];
   out_6142826586467809321[11] = state[11];
   out_6142826586467809321[12] = state[12];
   out_6142826586467809321[13] = state[13];
   out_6142826586467809321[14] = state[14];
   out_6142826586467809321[15] = state[15];
   out_6142826586467809321[16] = state[16];
   out_6142826586467809321[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8396239383595830029) {
   out_8396239383595830029[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8396239383595830029[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8396239383595830029[2] = 0;
   out_8396239383595830029[3] = 0;
   out_8396239383595830029[4] = 0;
   out_8396239383595830029[5] = 0;
   out_8396239383595830029[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8396239383595830029[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8396239383595830029[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8396239383595830029[9] = 0;
   out_8396239383595830029[10] = 0;
   out_8396239383595830029[11] = 0;
   out_8396239383595830029[12] = 0;
   out_8396239383595830029[13] = 0;
   out_8396239383595830029[14] = 0;
   out_8396239383595830029[15] = 0;
   out_8396239383595830029[16] = 0;
   out_8396239383595830029[17] = 0;
   out_8396239383595830029[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8396239383595830029[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8396239383595830029[20] = 0;
   out_8396239383595830029[21] = 0;
   out_8396239383595830029[22] = 0;
   out_8396239383595830029[23] = 0;
   out_8396239383595830029[24] = 0;
   out_8396239383595830029[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8396239383595830029[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8396239383595830029[27] = 0;
   out_8396239383595830029[28] = 0;
   out_8396239383595830029[29] = 0;
   out_8396239383595830029[30] = 0;
   out_8396239383595830029[31] = 0;
   out_8396239383595830029[32] = 0;
   out_8396239383595830029[33] = 0;
   out_8396239383595830029[34] = 0;
   out_8396239383595830029[35] = 0;
   out_8396239383595830029[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8396239383595830029[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8396239383595830029[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8396239383595830029[39] = 0;
   out_8396239383595830029[40] = 0;
   out_8396239383595830029[41] = 0;
   out_8396239383595830029[42] = 0;
   out_8396239383595830029[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8396239383595830029[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8396239383595830029[45] = 0;
   out_8396239383595830029[46] = 0;
   out_8396239383595830029[47] = 0;
   out_8396239383595830029[48] = 0;
   out_8396239383595830029[49] = 0;
   out_8396239383595830029[50] = 0;
   out_8396239383595830029[51] = 0;
   out_8396239383595830029[52] = 0;
   out_8396239383595830029[53] = 0;
   out_8396239383595830029[54] = 0;
   out_8396239383595830029[55] = 0;
   out_8396239383595830029[56] = 0;
   out_8396239383595830029[57] = 1;
   out_8396239383595830029[58] = 0;
   out_8396239383595830029[59] = 0;
   out_8396239383595830029[60] = 0;
   out_8396239383595830029[61] = 0;
   out_8396239383595830029[62] = 0;
   out_8396239383595830029[63] = 0;
   out_8396239383595830029[64] = 0;
   out_8396239383595830029[65] = 0;
   out_8396239383595830029[66] = dt;
   out_8396239383595830029[67] = 0;
   out_8396239383595830029[68] = 0;
   out_8396239383595830029[69] = 0;
   out_8396239383595830029[70] = 0;
   out_8396239383595830029[71] = 0;
   out_8396239383595830029[72] = 0;
   out_8396239383595830029[73] = 0;
   out_8396239383595830029[74] = 0;
   out_8396239383595830029[75] = 0;
   out_8396239383595830029[76] = 1;
   out_8396239383595830029[77] = 0;
   out_8396239383595830029[78] = 0;
   out_8396239383595830029[79] = 0;
   out_8396239383595830029[80] = 0;
   out_8396239383595830029[81] = 0;
   out_8396239383595830029[82] = 0;
   out_8396239383595830029[83] = 0;
   out_8396239383595830029[84] = 0;
   out_8396239383595830029[85] = dt;
   out_8396239383595830029[86] = 0;
   out_8396239383595830029[87] = 0;
   out_8396239383595830029[88] = 0;
   out_8396239383595830029[89] = 0;
   out_8396239383595830029[90] = 0;
   out_8396239383595830029[91] = 0;
   out_8396239383595830029[92] = 0;
   out_8396239383595830029[93] = 0;
   out_8396239383595830029[94] = 0;
   out_8396239383595830029[95] = 1;
   out_8396239383595830029[96] = 0;
   out_8396239383595830029[97] = 0;
   out_8396239383595830029[98] = 0;
   out_8396239383595830029[99] = 0;
   out_8396239383595830029[100] = 0;
   out_8396239383595830029[101] = 0;
   out_8396239383595830029[102] = 0;
   out_8396239383595830029[103] = 0;
   out_8396239383595830029[104] = dt;
   out_8396239383595830029[105] = 0;
   out_8396239383595830029[106] = 0;
   out_8396239383595830029[107] = 0;
   out_8396239383595830029[108] = 0;
   out_8396239383595830029[109] = 0;
   out_8396239383595830029[110] = 0;
   out_8396239383595830029[111] = 0;
   out_8396239383595830029[112] = 0;
   out_8396239383595830029[113] = 0;
   out_8396239383595830029[114] = 1;
   out_8396239383595830029[115] = 0;
   out_8396239383595830029[116] = 0;
   out_8396239383595830029[117] = 0;
   out_8396239383595830029[118] = 0;
   out_8396239383595830029[119] = 0;
   out_8396239383595830029[120] = 0;
   out_8396239383595830029[121] = 0;
   out_8396239383595830029[122] = 0;
   out_8396239383595830029[123] = 0;
   out_8396239383595830029[124] = 0;
   out_8396239383595830029[125] = 0;
   out_8396239383595830029[126] = 0;
   out_8396239383595830029[127] = 0;
   out_8396239383595830029[128] = 0;
   out_8396239383595830029[129] = 0;
   out_8396239383595830029[130] = 0;
   out_8396239383595830029[131] = 0;
   out_8396239383595830029[132] = 0;
   out_8396239383595830029[133] = 1;
   out_8396239383595830029[134] = 0;
   out_8396239383595830029[135] = 0;
   out_8396239383595830029[136] = 0;
   out_8396239383595830029[137] = 0;
   out_8396239383595830029[138] = 0;
   out_8396239383595830029[139] = 0;
   out_8396239383595830029[140] = 0;
   out_8396239383595830029[141] = 0;
   out_8396239383595830029[142] = 0;
   out_8396239383595830029[143] = 0;
   out_8396239383595830029[144] = 0;
   out_8396239383595830029[145] = 0;
   out_8396239383595830029[146] = 0;
   out_8396239383595830029[147] = 0;
   out_8396239383595830029[148] = 0;
   out_8396239383595830029[149] = 0;
   out_8396239383595830029[150] = 0;
   out_8396239383595830029[151] = 0;
   out_8396239383595830029[152] = 1;
   out_8396239383595830029[153] = 0;
   out_8396239383595830029[154] = 0;
   out_8396239383595830029[155] = 0;
   out_8396239383595830029[156] = 0;
   out_8396239383595830029[157] = 0;
   out_8396239383595830029[158] = 0;
   out_8396239383595830029[159] = 0;
   out_8396239383595830029[160] = 0;
   out_8396239383595830029[161] = 0;
   out_8396239383595830029[162] = 0;
   out_8396239383595830029[163] = 0;
   out_8396239383595830029[164] = 0;
   out_8396239383595830029[165] = 0;
   out_8396239383595830029[166] = 0;
   out_8396239383595830029[167] = 0;
   out_8396239383595830029[168] = 0;
   out_8396239383595830029[169] = 0;
   out_8396239383595830029[170] = 0;
   out_8396239383595830029[171] = 1;
   out_8396239383595830029[172] = 0;
   out_8396239383595830029[173] = 0;
   out_8396239383595830029[174] = 0;
   out_8396239383595830029[175] = 0;
   out_8396239383595830029[176] = 0;
   out_8396239383595830029[177] = 0;
   out_8396239383595830029[178] = 0;
   out_8396239383595830029[179] = 0;
   out_8396239383595830029[180] = 0;
   out_8396239383595830029[181] = 0;
   out_8396239383595830029[182] = 0;
   out_8396239383595830029[183] = 0;
   out_8396239383595830029[184] = 0;
   out_8396239383595830029[185] = 0;
   out_8396239383595830029[186] = 0;
   out_8396239383595830029[187] = 0;
   out_8396239383595830029[188] = 0;
   out_8396239383595830029[189] = 0;
   out_8396239383595830029[190] = 1;
   out_8396239383595830029[191] = 0;
   out_8396239383595830029[192] = 0;
   out_8396239383595830029[193] = 0;
   out_8396239383595830029[194] = 0;
   out_8396239383595830029[195] = 0;
   out_8396239383595830029[196] = 0;
   out_8396239383595830029[197] = 0;
   out_8396239383595830029[198] = 0;
   out_8396239383595830029[199] = 0;
   out_8396239383595830029[200] = 0;
   out_8396239383595830029[201] = 0;
   out_8396239383595830029[202] = 0;
   out_8396239383595830029[203] = 0;
   out_8396239383595830029[204] = 0;
   out_8396239383595830029[205] = 0;
   out_8396239383595830029[206] = 0;
   out_8396239383595830029[207] = 0;
   out_8396239383595830029[208] = 0;
   out_8396239383595830029[209] = 1;
   out_8396239383595830029[210] = 0;
   out_8396239383595830029[211] = 0;
   out_8396239383595830029[212] = 0;
   out_8396239383595830029[213] = 0;
   out_8396239383595830029[214] = 0;
   out_8396239383595830029[215] = 0;
   out_8396239383595830029[216] = 0;
   out_8396239383595830029[217] = 0;
   out_8396239383595830029[218] = 0;
   out_8396239383595830029[219] = 0;
   out_8396239383595830029[220] = 0;
   out_8396239383595830029[221] = 0;
   out_8396239383595830029[222] = 0;
   out_8396239383595830029[223] = 0;
   out_8396239383595830029[224] = 0;
   out_8396239383595830029[225] = 0;
   out_8396239383595830029[226] = 0;
   out_8396239383595830029[227] = 0;
   out_8396239383595830029[228] = 1;
   out_8396239383595830029[229] = 0;
   out_8396239383595830029[230] = 0;
   out_8396239383595830029[231] = 0;
   out_8396239383595830029[232] = 0;
   out_8396239383595830029[233] = 0;
   out_8396239383595830029[234] = 0;
   out_8396239383595830029[235] = 0;
   out_8396239383595830029[236] = 0;
   out_8396239383595830029[237] = 0;
   out_8396239383595830029[238] = 0;
   out_8396239383595830029[239] = 0;
   out_8396239383595830029[240] = 0;
   out_8396239383595830029[241] = 0;
   out_8396239383595830029[242] = 0;
   out_8396239383595830029[243] = 0;
   out_8396239383595830029[244] = 0;
   out_8396239383595830029[245] = 0;
   out_8396239383595830029[246] = 0;
   out_8396239383595830029[247] = 1;
   out_8396239383595830029[248] = 0;
   out_8396239383595830029[249] = 0;
   out_8396239383595830029[250] = 0;
   out_8396239383595830029[251] = 0;
   out_8396239383595830029[252] = 0;
   out_8396239383595830029[253] = 0;
   out_8396239383595830029[254] = 0;
   out_8396239383595830029[255] = 0;
   out_8396239383595830029[256] = 0;
   out_8396239383595830029[257] = 0;
   out_8396239383595830029[258] = 0;
   out_8396239383595830029[259] = 0;
   out_8396239383595830029[260] = 0;
   out_8396239383595830029[261] = 0;
   out_8396239383595830029[262] = 0;
   out_8396239383595830029[263] = 0;
   out_8396239383595830029[264] = 0;
   out_8396239383595830029[265] = 0;
   out_8396239383595830029[266] = 1;
   out_8396239383595830029[267] = 0;
   out_8396239383595830029[268] = 0;
   out_8396239383595830029[269] = 0;
   out_8396239383595830029[270] = 0;
   out_8396239383595830029[271] = 0;
   out_8396239383595830029[272] = 0;
   out_8396239383595830029[273] = 0;
   out_8396239383595830029[274] = 0;
   out_8396239383595830029[275] = 0;
   out_8396239383595830029[276] = 0;
   out_8396239383595830029[277] = 0;
   out_8396239383595830029[278] = 0;
   out_8396239383595830029[279] = 0;
   out_8396239383595830029[280] = 0;
   out_8396239383595830029[281] = 0;
   out_8396239383595830029[282] = 0;
   out_8396239383595830029[283] = 0;
   out_8396239383595830029[284] = 0;
   out_8396239383595830029[285] = 1;
   out_8396239383595830029[286] = 0;
   out_8396239383595830029[287] = 0;
   out_8396239383595830029[288] = 0;
   out_8396239383595830029[289] = 0;
   out_8396239383595830029[290] = 0;
   out_8396239383595830029[291] = 0;
   out_8396239383595830029[292] = 0;
   out_8396239383595830029[293] = 0;
   out_8396239383595830029[294] = 0;
   out_8396239383595830029[295] = 0;
   out_8396239383595830029[296] = 0;
   out_8396239383595830029[297] = 0;
   out_8396239383595830029[298] = 0;
   out_8396239383595830029[299] = 0;
   out_8396239383595830029[300] = 0;
   out_8396239383595830029[301] = 0;
   out_8396239383595830029[302] = 0;
   out_8396239383595830029[303] = 0;
   out_8396239383595830029[304] = 1;
   out_8396239383595830029[305] = 0;
   out_8396239383595830029[306] = 0;
   out_8396239383595830029[307] = 0;
   out_8396239383595830029[308] = 0;
   out_8396239383595830029[309] = 0;
   out_8396239383595830029[310] = 0;
   out_8396239383595830029[311] = 0;
   out_8396239383595830029[312] = 0;
   out_8396239383595830029[313] = 0;
   out_8396239383595830029[314] = 0;
   out_8396239383595830029[315] = 0;
   out_8396239383595830029[316] = 0;
   out_8396239383595830029[317] = 0;
   out_8396239383595830029[318] = 0;
   out_8396239383595830029[319] = 0;
   out_8396239383595830029[320] = 0;
   out_8396239383595830029[321] = 0;
   out_8396239383595830029[322] = 0;
   out_8396239383595830029[323] = 1;
}
void h_4(double *state, double *unused, double *out_1811902591494823997) {
   out_1811902591494823997[0] = state[6] + state[9];
   out_1811902591494823997[1] = state[7] + state[10];
   out_1811902591494823997[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_599853683671623371) {
   out_599853683671623371[0] = 0;
   out_599853683671623371[1] = 0;
   out_599853683671623371[2] = 0;
   out_599853683671623371[3] = 0;
   out_599853683671623371[4] = 0;
   out_599853683671623371[5] = 0;
   out_599853683671623371[6] = 1;
   out_599853683671623371[7] = 0;
   out_599853683671623371[8] = 0;
   out_599853683671623371[9] = 1;
   out_599853683671623371[10] = 0;
   out_599853683671623371[11] = 0;
   out_599853683671623371[12] = 0;
   out_599853683671623371[13] = 0;
   out_599853683671623371[14] = 0;
   out_599853683671623371[15] = 0;
   out_599853683671623371[16] = 0;
   out_599853683671623371[17] = 0;
   out_599853683671623371[18] = 0;
   out_599853683671623371[19] = 0;
   out_599853683671623371[20] = 0;
   out_599853683671623371[21] = 0;
   out_599853683671623371[22] = 0;
   out_599853683671623371[23] = 0;
   out_599853683671623371[24] = 0;
   out_599853683671623371[25] = 1;
   out_599853683671623371[26] = 0;
   out_599853683671623371[27] = 0;
   out_599853683671623371[28] = 1;
   out_599853683671623371[29] = 0;
   out_599853683671623371[30] = 0;
   out_599853683671623371[31] = 0;
   out_599853683671623371[32] = 0;
   out_599853683671623371[33] = 0;
   out_599853683671623371[34] = 0;
   out_599853683671623371[35] = 0;
   out_599853683671623371[36] = 0;
   out_599853683671623371[37] = 0;
   out_599853683671623371[38] = 0;
   out_599853683671623371[39] = 0;
   out_599853683671623371[40] = 0;
   out_599853683671623371[41] = 0;
   out_599853683671623371[42] = 0;
   out_599853683671623371[43] = 0;
   out_599853683671623371[44] = 1;
   out_599853683671623371[45] = 0;
   out_599853683671623371[46] = 0;
   out_599853683671623371[47] = 1;
   out_599853683671623371[48] = 0;
   out_599853683671623371[49] = 0;
   out_599853683671623371[50] = 0;
   out_599853683671623371[51] = 0;
   out_599853683671623371[52] = 0;
   out_599853683671623371[53] = 0;
}
void h_10(double *state, double *unused, double *out_8987115705540323441) {
   out_8987115705540323441[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8987115705540323441[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8987115705540323441[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4430606342081287306) {
   out_4430606342081287306[0] = 0;
   out_4430606342081287306[1] = 9.8100000000000005*cos(state[1]);
   out_4430606342081287306[2] = 0;
   out_4430606342081287306[3] = 0;
   out_4430606342081287306[4] = -state[8];
   out_4430606342081287306[5] = state[7];
   out_4430606342081287306[6] = 0;
   out_4430606342081287306[7] = state[5];
   out_4430606342081287306[8] = -state[4];
   out_4430606342081287306[9] = 0;
   out_4430606342081287306[10] = 0;
   out_4430606342081287306[11] = 0;
   out_4430606342081287306[12] = 1;
   out_4430606342081287306[13] = 0;
   out_4430606342081287306[14] = 0;
   out_4430606342081287306[15] = 1;
   out_4430606342081287306[16] = 0;
   out_4430606342081287306[17] = 0;
   out_4430606342081287306[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4430606342081287306[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4430606342081287306[20] = 0;
   out_4430606342081287306[21] = state[8];
   out_4430606342081287306[22] = 0;
   out_4430606342081287306[23] = -state[6];
   out_4430606342081287306[24] = -state[5];
   out_4430606342081287306[25] = 0;
   out_4430606342081287306[26] = state[3];
   out_4430606342081287306[27] = 0;
   out_4430606342081287306[28] = 0;
   out_4430606342081287306[29] = 0;
   out_4430606342081287306[30] = 0;
   out_4430606342081287306[31] = 1;
   out_4430606342081287306[32] = 0;
   out_4430606342081287306[33] = 0;
   out_4430606342081287306[34] = 1;
   out_4430606342081287306[35] = 0;
   out_4430606342081287306[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4430606342081287306[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4430606342081287306[38] = 0;
   out_4430606342081287306[39] = -state[7];
   out_4430606342081287306[40] = state[6];
   out_4430606342081287306[41] = 0;
   out_4430606342081287306[42] = state[4];
   out_4430606342081287306[43] = -state[3];
   out_4430606342081287306[44] = 0;
   out_4430606342081287306[45] = 0;
   out_4430606342081287306[46] = 0;
   out_4430606342081287306[47] = 0;
   out_4430606342081287306[48] = 0;
   out_4430606342081287306[49] = 0;
   out_4430606342081287306[50] = 1;
   out_4430606342081287306[51] = 0;
   out_4430606342081287306[52] = 0;
   out_4430606342081287306[53] = 1;
}
void h_13(double *state, double *unused, double *out_745002374354712655) {
   out_745002374354712655[0] = state[3];
   out_745002374354712655[1] = state[4];
   out_745002374354712655[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4433609146974147395) {
   out_4433609146974147395[0] = 0;
   out_4433609146974147395[1] = 0;
   out_4433609146974147395[2] = 0;
   out_4433609146974147395[3] = 1;
   out_4433609146974147395[4] = 0;
   out_4433609146974147395[5] = 0;
   out_4433609146974147395[6] = 0;
   out_4433609146974147395[7] = 0;
   out_4433609146974147395[8] = 0;
   out_4433609146974147395[9] = 0;
   out_4433609146974147395[10] = 0;
   out_4433609146974147395[11] = 0;
   out_4433609146974147395[12] = 0;
   out_4433609146974147395[13] = 0;
   out_4433609146974147395[14] = 0;
   out_4433609146974147395[15] = 0;
   out_4433609146974147395[16] = 0;
   out_4433609146974147395[17] = 0;
   out_4433609146974147395[18] = 0;
   out_4433609146974147395[19] = 0;
   out_4433609146974147395[20] = 0;
   out_4433609146974147395[21] = 0;
   out_4433609146974147395[22] = 1;
   out_4433609146974147395[23] = 0;
   out_4433609146974147395[24] = 0;
   out_4433609146974147395[25] = 0;
   out_4433609146974147395[26] = 0;
   out_4433609146974147395[27] = 0;
   out_4433609146974147395[28] = 0;
   out_4433609146974147395[29] = 0;
   out_4433609146974147395[30] = 0;
   out_4433609146974147395[31] = 0;
   out_4433609146974147395[32] = 0;
   out_4433609146974147395[33] = 0;
   out_4433609146974147395[34] = 0;
   out_4433609146974147395[35] = 0;
   out_4433609146974147395[36] = 0;
   out_4433609146974147395[37] = 0;
   out_4433609146974147395[38] = 0;
   out_4433609146974147395[39] = 0;
   out_4433609146974147395[40] = 0;
   out_4433609146974147395[41] = 1;
   out_4433609146974147395[42] = 0;
   out_4433609146974147395[43] = 0;
   out_4433609146974147395[44] = 0;
   out_4433609146974147395[45] = 0;
   out_4433609146974147395[46] = 0;
   out_4433609146974147395[47] = 0;
   out_4433609146974147395[48] = 0;
   out_4433609146974147395[49] = 0;
   out_4433609146974147395[50] = 0;
   out_4433609146974147395[51] = 0;
   out_4433609146974147395[52] = 0;
   out_4433609146974147395[53] = 0;
}
void h_14(double *state, double *unused, double *out_7578055683598024511) {
   out_7578055683598024511[0] = state[6];
   out_7578055683598024511[1] = state[7];
   out_7578055683598024511[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3682642115966995667) {
   out_3682642115966995667[0] = 0;
   out_3682642115966995667[1] = 0;
   out_3682642115966995667[2] = 0;
   out_3682642115966995667[3] = 0;
   out_3682642115966995667[4] = 0;
   out_3682642115966995667[5] = 0;
   out_3682642115966995667[6] = 1;
   out_3682642115966995667[7] = 0;
   out_3682642115966995667[8] = 0;
   out_3682642115966995667[9] = 0;
   out_3682642115966995667[10] = 0;
   out_3682642115966995667[11] = 0;
   out_3682642115966995667[12] = 0;
   out_3682642115966995667[13] = 0;
   out_3682642115966995667[14] = 0;
   out_3682642115966995667[15] = 0;
   out_3682642115966995667[16] = 0;
   out_3682642115966995667[17] = 0;
   out_3682642115966995667[18] = 0;
   out_3682642115966995667[19] = 0;
   out_3682642115966995667[20] = 0;
   out_3682642115966995667[21] = 0;
   out_3682642115966995667[22] = 0;
   out_3682642115966995667[23] = 0;
   out_3682642115966995667[24] = 0;
   out_3682642115966995667[25] = 1;
   out_3682642115966995667[26] = 0;
   out_3682642115966995667[27] = 0;
   out_3682642115966995667[28] = 0;
   out_3682642115966995667[29] = 0;
   out_3682642115966995667[30] = 0;
   out_3682642115966995667[31] = 0;
   out_3682642115966995667[32] = 0;
   out_3682642115966995667[33] = 0;
   out_3682642115966995667[34] = 0;
   out_3682642115966995667[35] = 0;
   out_3682642115966995667[36] = 0;
   out_3682642115966995667[37] = 0;
   out_3682642115966995667[38] = 0;
   out_3682642115966995667[39] = 0;
   out_3682642115966995667[40] = 0;
   out_3682642115966995667[41] = 0;
   out_3682642115966995667[42] = 0;
   out_3682642115966995667[43] = 0;
   out_3682642115966995667[44] = 1;
   out_3682642115966995667[45] = 0;
   out_3682642115966995667[46] = 0;
   out_3682642115966995667[47] = 0;
   out_3682642115966995667[48] = 0;
   out_3682642115966995667[49] = 0;
   out_3682642115966995667[50] = 0;
   out_3682642115966995667[51] = 0;
   out_3682642115966995667[52] = 0;
   out_3682642115966995667[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3059462324026594541) {
  err_fun(nom_x, delta_x, out_3059462324026594541);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7293350812574481008) {
  inv_err_fun(nom_x, true_x, out_7293350812574481008);
}
void pose_H_mod_fun(double *state, double *out_1219845042234673490) {
  H_mod_fun(state, out_1219845042234673490);
}
void pose_f_fun(double *state, double dt, double *out_6142826586467809321) {
  f_fun(state,  dt, out_6142826586467809321);
}
void pose_F_fun(double *state, double dt, double *out_8396239383595830029) {
  F_fun(state,  dt, out_8396239383595830029);
}
void pose_h_4(double *state, double *unused, double *out_1811902591494823997) {
  h_4(state, unused, out_1811902591494823997);
}
void pose_H_4(double *state, double *unused, double *out_599853683671623371) {
  H_4(state, unused, out_599853683671623371);
}
void pose_h_10(double *state, double *unused, double *out_8987115705540323441) {
  h_10(state, unused, out_8987115705540323441);
}
void pose_H_10(double *state, double *unused, double *out_4430606342081287306) {
  H_10(state, unused, out_4430606342081287306);
}
void pose_h_13(double *state, double *unused, double *out_745002374354712655) {
  h_13(state, unused, out_745002374354712655);
}
void pose_H_13(double *state, double *unused, double *out_4433609146974147395) {
  H_13(state, unused, out_4433609146974147395);
}
void pose_h_14(double *state, double *unused, double *out_7578055683598024511) {
  h_14(state, unused, out_7578055683598024511);
}
void pose_H_14(double *state, double *unused, double *out_3682642115966995667) {
  H_14(state, unused, out_3682642115966995667);
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
