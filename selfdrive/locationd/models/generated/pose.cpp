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
void err_fun(double *nom_x, double *delta_x, double *out_5836812006117722374) {
   out_5836812006117722374[0] = delta_x[0] + nom_x[0];
   out_5836812006117722374[1] = delta_x[1] + nom_x[1];
   out_5836812006117722374[2] = delta_x[2] + nom_x[2];
   out_5836812006117722374[3] = delta_x[3] + nom_x[3];
   out_5836812006117722374[4] = delta_x[4] + nom_x[4];
   out_5836812006117722374[5] = delta_x[5] + nom_x[5];
   out_5836812006117722374[6] = delta_x[6] + nom_x[6];
   out_5836812006117722374[7] = delta_x[7] + nom_x[7];
   out_5836812006117722374[8] = delta_x[8] + nom_x[8];
   out_5836812006117722374[9] = delta_x[9] + nom_x[9];
   out_5836812006117722374[10] = delta_x[10] + nom_x[10];
   out_5836812006117722374[11] = delta_x[11] + nom_x[11];
   out_5836812006117722374[12] = delta_x[12] + nom_x[12];
   out_5836812006117722374[13] = delta_x[13] + nom_x[13];
   out_5836812006117722374[14] = delta_x[14] + nom_x[14];
   out_5836812006117722374[15] = delta_x[15] + nom_x[15];
   out_5836812006117722374[16] = delta_x[16] + nom_x[16];
   out_5836812006117722374[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_368701023819567149) {
   out_368701023819567149[0] = -nom_x[0] + true_x[0];
   out_368701023819567149[1] = -nom_x[1] + true_x[1];
   out_368701023819567149[2] = -nom_x[2] + true_x[2];
   out_368701023819567149[3] = -nom_x[3] + true_x[3];
   out_368701023819567149[4] = -nom_x[4] + true_x[4];
   out_368701023819567149[5] = -nom_x[5] + true_x[5];
   out_368701023819567149[6] = -nom_x[6] + true_x[6];
   out_368701023819567149[7] = -nom_x[7] + true_x[7];
   out_368701023819567149[8] = -nom_x[8] + true_x[8];
   out_368701023819567149[9] = -nom_x[9] + true_x[9];
   out_368701023819567149[10] = -nom_x[10] + true_x[10];
   out_368701023819567149[11] = -nom_x[11] + true_x[11];
   out_368701023819567149[12] = -nom_x[12] + true_x[12];
   out_368701023819567149[13] = -nom_x[13] + true_x[13];
   out_368701023819567149[14] = -nom_x[14] + true_x[14];
   out_368701023819567149[15] = -nom_x[15] + true_x[15];
   out_368701023819567149[16] = -nom_x[16] + true_x[16];
   out_368701023819567149[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5720830998239473631) {
   out_5720830998239473631[0] = 1.0;
   out_5720830998239473631[1] = 0.0;
   out_5720830998239473631[2] = 0.0;
   out_5720830998239473631[3] = 0.0;
   out_5720830998239473631[4] = 0.0;
   out_5720830998239473631[5] = 0.0;
   out_5720830998239473631[6] = 0.0;
   out_5720830998239473631[7] = 0.0;
   out_5720830998239473631[8] = 0.0;
   out_5720830998239473631[9] = 0.0;
   out_5720830998239473631[10] = 0.0;
   out_5720830998239473631[11] = 0.0;
   out_5720830998239473631[12] = 0.0;
   out_5720830998239473631[13] = 0.0;
   out_5720830998239473631[14] = 0.0;
   out_5720830998239473631[15] = 0.0;
   out_5720830998239473631[16] = 0.0;
   out_5720830998239473631[17] = 0.0;
   out_5720830998239473631[18] = 0.0;
   out_5720830998239473631[19] = 1.0;
   out_5720830998239473631[20] = 0.0;
   out_5720830998239473631[21] = 0.0;
   out_5720830998239473631[22] = 0.0;
   out_5720830998239473631[23] = 0.0;
   out_5720830998239473631[24] = 0.0;
   out_5720830998239473631[25] = 0.0;
   out_5720830998239473631[26] = 0.0;
   out_5720830998239473631[27] = 0.0;
   out_5720830998239473631[28] = 0.0;
   out_5720830998239473631[29] = 0.0;
   out_5720830998239473631[30] = 0.0;
   out_5720830998239473631[31] = 0.0;
   out_5720830998239473631[32] = 0.0;
   out_5720830998239473631[33] = 0.0;
   out_5720830998239473631[34] = 0.0;
   out_5720830998239473631[35] = 0.0;
   out_5720830998239473631[36] = 0.0;
   out_5720830998239473631[37] = 0.0;
   out_5720830998239473631[38] = 1.0;
   out_5720830998239473631[39] = 0.0;
   out_5720830998239473631[40] = 0.0;
   out_5720830998239473631[41] = 0.0;
   out_5720830998239473631[42] = 0.0;
   out_5720830998239473631[43] = 0.0;
   out_5720830998239473631[44] = 0.0;
   out_5720830998239473631[45] = 0.0;
   out_5720830998239473631[46] = 0.0;
   out_5720830998239473631[47] = 0.0;
   out_5720830998239473631[48] = 0.0;
   out_5720830998239473631[49] = 0.0;
   out_5720830998239473631[50] = 0.0;
   out_5720830998239473631[51] = 0.0;
   out_5720830998239473631[52] = 0.0;
   out_5720830998239473631[53] = 0.0;
   out_5720830998239473631[54] = 0.0;
   out_5720830998239473631[55] = 0.0;
   out_5720830998239473631[56] = 0.0;
   out_5720830998239473631[57] = 1.0;
   out_5720830998239473631[58] = 0.0;
   out_5720830998239473631[59] = 0.0;
   out_5720830998239473631[60] = 0.0;
   out_5720830998239473631[61] = 0.0;
   out_5720830998239473631[62] = 0.0;
   out_5720830998239473631[63] = 0.0;
   out_5720830998239473631[64] = 0.0;
   out_5720830998239473631[65] = 0.0;
   out_5720830998239473631[66] = 0.0;
   out_5720830998239473631[67] = 0.0;
   out_5720830998239473631[68] = 0.0;
   out_5720830998239473631[69] = 0.0;
   out_5720830998239473631[70] = 0.0;
   out_5720830998239473631[71] = 0.0;
   out_5720830998239473631[72] = 0.0;
   out_5720830998239473631[73] = 0.0;
   out_5720830998239473631[74] = 0.0;
   out_5720830998239473631[75] = 0.0;
   out_5720830998239473631[76] = 1.0;
   out_5720830998239473631[77] = 0.0;
   out_5720830998239473631[78] = 0.0;
   out_5720830998239473631[79] = 0.0;
   out_5720830998239473631[80] = 0.0;
   out_5720830998239473631[81] = 0.0;
   out_5720830998239473631[82] = 0.0;
   out_5720830998239473631[83] = 0.0;
   out_5720830998239473631[84] = 0.0;
   out_5720830998239473631[85] = 0.0;
   out_5720830998239473631[86] = 0.0;
   out_5720830998239473631[87] = 0.0;
   out_5720830998239473631[88] = 0.0;
   out_5720830998239473631[89] = 0.0;
   out_5720830998239473631[90] = 0.0;
   out_5720830998239473631[91] = 0.0;
   out_5720830998239473631[92] = 0.0;
   out_5720830998239473631[93] = 0.0;
   out_5720830998239473631[94] = 0.0;
   out_5720830998239473631[95] = 1.0;
   out_5720830998239473631[96] = 0.0;
   out_5720830998239473631[97] = 0.0;
   out_5720830998239473631[98] = 0.0;
   out_5720830998239473631[99] = 0.0;
   out_5720830998239473631[100] = 0.0;
   out_5720830998239473631[101] = 0.0;
   out_5720830998239473631[102] = 0.0;
   out_5720830998239473631[103] = 0.0;
   out_5720830998239473631[104] = 0.0;
   out_5720830998239473631[105] = 0.0;
   out_5720830998239473631[106] = 0.0;
   out_5720830998239473631[107] = 0.0;
   out_5720830998239473631[108] = 0.0;
   out_5720830998239473631[109] = 0.0;
   out_5720830998239473631[110] = 0.0;
   out_5720830998239473631[111] = 0.0;
   out_5720830998239473631[112] = 0.0;
   out_5720830998239473631[113] = 0.0;
   out_5720830998239473631[114] = 1.0;
   out_5720830998239473631[115] = 0.0;
   out_5720830998239473631[116] = 0.0;
   out_5720830998239473631[117] = 0.0;
   out_5720830998239473631[118] = 0.0;
   out_5720830998239473631[119] = 0.0;
   out_5720830998239473631[120] = 0.0;
   out_5720830998239473631[121] = 0.0;
   out_5720830998239473631[122] = 0.0;
   out_5720830998239473631[123] = 0.0;
   out_5720830998239473631[124] = 0.0;
   out_5720830998239473631[125] = 0.0;
   out_5720830998239473631[126] = 0.0;
   out_5720830998239473631[127] = 0.0;
   out_5720830998239473631[128] = 0.0;
   out_5720830998239473631[129] = 0.0;
   out_5720830998239473631[130] = 0.0;
   out_5720830998239473631[131] = 0.0;
   out_5720830998239473631[132] = 0.0;
   out_5720830998239473631[133] = 1.0;
   out_5720830998239473631[134] = 0.0;
   out_5720830998239473631[135] = 0.0;
   out_5720830998239473631[136] = 0.0;
   out_5720830998239473631[137] = 0.0;
   out_5720830998239473631[138] = 0.0;
   out_5720830998239473631[139] = 0.0;
   out_5720830998239473631[140] = 0.0;
   out_5720830998239473631[141] = 0.0;
   out_5720830998239473631[142] = 0.0;
   out_5720830998239473631[143] = 0.0;
   out_5720830998239473631[144] = 0.0;
   out_5720830998239473631[145] = 0.0;
   out_5720830998239473631[146] = 0.0;
   out_5720830998239473631[147] = 0.0;
   out_5720830998239473631[148] = 0.0;
   out_5720830998239473631[149] = 0.0;
   out_5720830998239473631[150] = 0.0;
   out_5720830998239473631[151] = 0.0;
   out_5720830998239473631[152] = 1.0;
   out_5720830998239473631[153] = 0.0;
   out_5720830998239473631[154] = 0.0;
   out_5720830998239473631[155] = 0.0;
   out_5720830998239473631[156] = 0.0;
   out_5720830998239473631[157] = 0.0;
   out_5720830998239473631[158] = 0.0;
   out_5720830998239473631[159] = 0.0;
   out_5720830998239473631[160] = 0.0;
   out_5720830998239473631[161] = 0.0;
   out_5720830998239473631[162] = 0.0;
   out_5720830998239473631[163] = 0.0;
   out_5720830998239473631[164] = 0.0;
   out_5720830998239473631[165] = 0.0;
   out_5720830998239473631[166] = 0.0;
   out_5720830998239473631[167] = 0.0;
   out_5720830998239473631[168] = 0.0;
   out_5720830998239473631[169] = 0.0;
   out_5720830998239473631[170] = 0.0;
   out_5720830998239473631[171] = 1.0;
   out_5720830998239473631[172] = 0.0;
   out_5720830998239473631[173] = 0.0;
   out_5720830998239473631[174] = 0.0;
   out_5720830998239473631[175] = 0.0;
   out_5720830998239473631[176] = 0.0;
   out_5720830998239473631[177] = 0.0;
   out_5720830998239473631[178] = 0.0;
   out_5720830998239473631[179] = 0.0;
   out_5720830998239473631[180] = 0.0;
   out_5720830998239473631[181] = 0.0;
   out_5720830998239473631[182] = 0.0;
   out_5720830998239473631[183] = 0.0;
   out_5720830998239473631[184] = 0.0;
   out_5720830998239473631[185] = 0.0;
   out_5720830998239473631[186] = 0.0;
   out_5720830998239473631[187] = 0.0;
   out_5720830998239473631[188] = 0.0;
   out_5720830998239473631[189] = 0.0;
   out_5720830998239473631[190] = 1.0;
   out_5720830998239473631[191] = 0.0;
   out_5720830998239473631[192] = 0.0;
   out_5720830998239473631[193] = 0.0;
   out_5720830998239473631[194] = 0.0;
   out_5720830998239473631[195] = 0.0;
   out_5720830998239473631[196] = 0.0;
   out_5720830998239473631[197] = 0.0;
   out_5720830998239473631[198] = 0.0;
   out_5720830998239473631[199] = 0.0;
   out_5720830998239473631[200] = 0.0;
   out_5720830998239473631[201] = 0.0;
   out_5720830998239473631[202] = 0.0;
   out_5720830998239473631[203] = 0.0;
   out_5720830998239473631[204] = 0.0;
   out_5720830998239473631[205] = 0.0;
   out_5720830998239473631[206] = 0.0;
   out_5720830998239473631[207] = 0.0;
   out_5720830998239473631[208] = 0.0;
   out_5720830998239473631[209] = 1.0;
   out_5720830998239473631[210] = 0.0;
   out_5720830998239473631[211] = 0.0;
   out_5720830998239473631[212] = 0.0;
   out_5720830998239473631[213] = 0.0;
   out_5720830998239473631[214] = 0.0;
   out_5720830998239473631[215] = 0.0;
   out_5720830998239473631[216] = 0.0;
   out_5720830998239473631[217] = 0.0;
   out_5720830998239473631[218] = 0.0;
   out_5720830998239473631[219] = 0.0;
   out_5720830998239473631[220] = 0.0;
   out_5720830998239473631[221] = 0.0;
   out_5720830998239473631[222] = 0.0;
   out_5720830998239473631[223] = 0.0;
   out_5720830998239473631[224] = 0.0;
   out_5720830998239473631[225] = 0.0;
   out_5720830998239473631[226] = 0.0;
   out_5720830998239473631[227] = 0.0;
   out_5720830998239473631[228] = 1.0;
   out_5720830998239473631[229] = 0.0;
   out_5720830998239473631[230] = 0.0;
   out_5720830998239473631[231] = 0.0;
   out_5720830998239473631[232] = 0.0;
   out_5720830998239473631[233] = 0.0;
   out_5720830998239473631[234] = 0.0;
   out_5720830998239473631[235] = 0.0;
   out_5720830998239473631[236] = 0.0;
   out_5720830998239473631[237] = 0.0;
   out_5720830998239473631[238] = 0.0;
   out_5720830998239473631[239] = 0.0;
   out_5720830998239473631[240] = 0.0;
   out_5720830998239473631[241] = 0.0;
   out_5720830998239473631[242] = 0.0;
   out_5720830998239473631[243] = 0.0;
   out_5720830998239473631[244] = 0.0;
   out_5720830998239473631[245] = 0.0;
   out_5720830998239473631[246] = 0.0;
   out_5720830998239473631[247] = 1.0;
   out_5720830998239473631[248] = 0.0;
   out_5720830998239473631[249] = 0.0;
   out_5720830998239473631[250] = 0.0;
   out_5720830998239473631[251] = 0.0;
   out_5720830998239473631[252] = 0.0;
   out_5720830998239473631[253] = 0.0;
   out_5720830998239473631[254] = 0.0;
   out_5720830998239473631[255] = 0.0;
   out_5720830998239473631[256] = 0.0;
   out_5720830998239473631[257] = 0.0;
   out_5720830998239473631[258] = 0.0;
   out_5720830998239473631[259] = 0.0;
   out_5720830998239473631[260] = 0.0;
   out_5720830998239473631[261] = 0.0;
   out_5720830998239473631[262] = 0.0;
   out_5720830998239473631[263] = 0.0;
   out_5720830998239473631[264] = 0.0;
   out_5720830998239473631[265] = 0.0;
   out_5720830998239473631[266] = 1.0;
   out_5720830998239473631[267] = 0.0;
   out_5720830998239473631[268] = 0.0;
   out_5720830998239473631[269] = 0.0;
   out_5720830998239473631[270] = 0.0;
   out_5720830998239473631[271] = 0.0;
   out_5720830998239473631[272] = 0.0;
   out_5720830998239473631[273] = 0.0;
   out_5720830998239473631[274] = 0.0;
   out_5720830998239473631[275] = 0.0;
   out_5720830998239473631[276] = 0.0;
   out_5720830998239473631[277] = 0.0;
   out_5720830998239473631[278] = 0.0;
   out_5720830998239473631[279] = 0.0;
   out_5720830998239473631[280] = 0.0;
   out_5720830998239473631[281] = 0.0;
   out_5720830998239473631[282] = 0.0;
   out_5720830998239473631[283] = 0.0;
   out_5720830998239473631[284] = 0.0;
   out_5720830998239473631[285] = 1.0;
   out_5720830998239473631[286] = 0.0;
   out_5720830998239473631[287] = 0.0;
   out_5720830998239473631[288] = 0.0;
   out_5720830998239473631[289] = 0.0;
   out_5720830998239473631[290] = 0.0;
   out_5720830998239473631[291] = 0.0;
   out_5720830998239473631[292] = 0.0;
   out_5720830998239473631[293] = 0.0;
   out_5720830998239473631[294] = 0.0;
   out_5720830998239473631[295] = 0.0;
   out_5720830998239473631[296] = 0.0;
   out_5720830998239473631[297] = 0.0;
   out_5720830998239473631[298] = 0.0;
   out_5720830998239473631[299] = 0.0;
   out_5720830998239473631[300] = 0.0;
   out_5720830998239473631[301] = 0.0;
   out_5720830998239473631[302] = 0.0;
   out_5720830998239473631[303] = 0.0;
   out_5720830998239473631[304] = 1.0;
   out_5720830998239473631[305] = 0.0;
   out_5720830998239473631[306] = 0.0;
   out_5720830998239473631[307] = 0.0;
   out_5720830998239473631[308] = 0.0;
   out_5720830998239473631[309] = 0.0;
   out_5720830998239473631[310] = 0.0;
   out_5720830998239473631[311] = 0.0;
   out_5720830998239473631[312] = 0.0;
   out_5720830998239473631[313] = 0.0;
   out_5720830998239473631[314] = 0.0;
   out_5720830998239473631[315] = 0.0;
   out_5720830998239473631[316] = 0.0;
   out_5720830998239473631[317] = 0.0;
   out_5720830998239473631[318] = 0.0;
   out_5720830998239473631[319] = 0.0;
   out_5720830998239473631[320] = 0.0;
   out_5720830998239473631[321] = 0.0;
   out_5720830998239473631[322] = 0.0;
   out_5720830998239473631[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3302434187336556995) {
   out_3302434187336556995[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3302434187336556995[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3302434187336556995[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3302434187336556995[3] = dt*state[12] + state[3];
   out_3302434187336556995[4] = dt*state[13] + state[4];
   out_3302434187336556995[5] = dt*state[14] + state[5];
   out_3302434187336556995[6] = state[6];
   out_3302434187336556995[7] = state[7];
   out_3302434187336556995[8] = state[8];
   out_3302434187336556995[9] = state[9];
   out_3302434187336556995[10] = state[10];
   out_3302434187336556995[11] = state[11];
   out_3302434187336556995[12] = state[12];
   out_3302434187336556995[13] = state[13];
   out_3302434187336556995[14] = state[14];
   out_3302434187336556995[15] = state[15];
   out_3302434187336556995[16] = state[16];
   out_3302434187336556995[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2147733219597398466) {
   out_2147733219597398466[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2147733219597398466[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2147733219597398466[2] = 0;
   out_2147733219597398466[3] = 0;
   out_2147733219597398466[4] = 0;
   out_2147733219597398466[5] = 0;
   out_2147733219597398466[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2147733219597398466[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2147733219597398466[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2147733219597398466[9] = 0;
   out_2147733219597398466[10] = 0;
   out_2147733219597398466[11] = 0;
   out_2147733219597398466[12] = 0;
   out_2147733219597398466[13] = 0;
   out_2147733219597398466[14] = 0;
   out_2147733219597398466[15] = 0;
   out_2147733219597398466[16] = 0;
   out_2147733219597398466[17] = 0;
   out_2147733219597398466[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2147733219597398466[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2147733219597398466[20] = 0;
   out_2147733219597398466[21] = 0;
   out_2147733219597398466[22] = 0;
   out_2147733219597398466[23] = 0;
   out_2147733219597398466[24] = 0;
   out_2147733219597398466[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2147733219597398466[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2147733219597398466[27] = 0;
   out_2147733219597398466[28] = 0;
   out_2147733219597398466[29] = 0;
   out_2147733219597398466[30] = 0;
   out_2147733219597398466[31] = 0;
   out_2147733219597398466[32] = 0;
   out_2147733219597398466[33] = 0;
   out_2147733219597398466[34] = 0;
   out_2147733219597398466[35] = 0;
   out_2147733219597398466[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2147733219597398466[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2147733219597398466[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2147733219597398466[39] = 0;
   out_2147733219597398466[40] = 0;
   out_2147733219597398466[41] = 0;
   out_2147733219597398466[42] = 0;
   out_2147733219597398466[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2147733219597398466[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2147733219597398466[45] = 0;
   out_2147733219597398466[46] = 0;
   out_2147733219597398466[47] = 0;
   out_2147733219597398466[48] = 0;
   out_2147733219597398466[49] = 0;
   out_2147733219597398466[50] = 0;
   out_2147733219597398466[51] = 0;
   out_2147733219597398466[52] = 0;
   out_2147733219597398466[53] = 0;
   out_2147733219597398466[54] = 0;
   out_2147733219597398466[55] = 0;
   out_2147733219597398466[56] = 0;
   out_2147733219597398466[57] = 1;
   out_2147733219597398466[58] = 0;
   out_2147733219597398466[59] = 0;
   out_2147733219597398466[60] = 0;
   out_2147733219597398466[61] = 0;
   out_2147733219597398466[62] = 0;
   out_2147733219597398466[63] = 0;
   out_2147733219597398466[64] = 0;
   out_2147733219597398466[65] = 0;
   out_2147733219597398466[66] = dt;
   out_2147733219597398466[67] = 0;
   out_2147733219597398466[68] = 0;
   out_2147733219597398466[69] = 0;
   out_2147733219597398466[70] = 0;
   out_2147733219597398466[71] = 0;
   out_2147733219597398466[72] = 0;
   out_2147733219597398466[73] = 0;
   out_2147733219597398466[74] = 0;
   out_2147733219597398466[75] = 0;
   out_2147733219597398466[76] = 1;
   out_2147733219597398466[77] = 0;
   out_2147733219597398466[78] = 0;
   out_2147733219597398466[79] = 0;
   out_2147733219597398466[80] = 0;
   out_2147733219597398466[81] = 0;
   out_2147733219597398466[82] = 0;
   out_2147733219597398466[83] = 0;
   out_2147733219597398466[84] = 0;
   out_2147733219597398466[85] = dt;
   out_2147733219597398466[86] = 0;
   out_2147733219597398466[87] = 0;
   out_2147733219597398466[88] = 0;
   out_2147733219597398466[89] = 0;
   out_2147733219597398466[90] = 0;
   out_2147733219597398466[91] = 0;
   out_2147733219597398466[92] = 0;
   out_2147733219597398466[93] = 0;
   out_2147733219597398466[94] = 0;
   out_2147733219597398466[95] = 1;
   out_2147733219597398466[96] = 0;
   out_2147733219597398466[97] = 0;
   out_2147733219597398466[98] = 0;
   out_2147733219597398466[99] = 0;
   out_2147733219597398466[100] = 0;
   out_2147733219597398466[101] = 0;
   out_2147733219597398466[102] = 0;
   out_2147733219597398466[103] = 0;
   out_2147733219597398466[104] = dt;
   out_2147733219597398466[105] = 0;
   out_2147733219597398466[106] = 0;
   out_2147733219597398466[107] = 0;
   out_2147733219597398466[108] = 0;
   out_2147733219597398466[109] = 0;
   out_2147733219597398466[110] = 0;
   out_2147733219597398466[111] = 0;
   out_2147733219597398466[112] = 0;
   out_2147733219597398466[113] = 0;
   out_2147733219597398466[114] = 1;
   out_2147733219597398466[115] = 0;
   out_2147733219597398466[116] = 0;
   out_2147733219597398466[117] = 0;
   out_2147733219597398466[118] = 0;
   out_2147733219597398466[119] = 0;
   out_2147733219597398466[120] = 0;
   out_2147733219597398466[121] = 0;
   out_2147733219597398466[122] = 0;
   out_2147733219597398466[123] = 0;
   out_2147733219597398466[124] = 0;
   out_2147733219597398466[125] = 0;
   out_2147733219597398466[126] = 0;
   out_2147733219597398466[127] = 0;
   out_2147733219597398466[128] = 0;
   out_2147733219597398466[129] = 0;
   out_2147733219597398466[130] = 0;
   out_2147733219597398466[131] = 0;
   out_2147733219597398466[132] = 0;
   out_2147733219597398466[133] = 1;
   out_2147733219597398466[134] = 0;
   out_2147733219597398466[135] = 0;
   out_2147733219597398466[136] = 0;
   out_2147733219597398466[137] = 0;
   out_2147733219597398466[138] = 0;
   out_2147733219597398466[139] = 0;
   out_2147733219597398466[140] = 0;
   out_2147733219597398466[141] = 0;
   out_2147733219597398466[142] = 0;
   out_2147733219597398466[143] = 0;
   out_2147733219597398466[144] = 0;
   out_2147733219597398466[145] = 0;
   out_2147733219597398466[146] = 0;
   out_2147733219597398466[147] = 0;
   out_2147733219597398466[148] = 0;
   out_2147733219597398466[149] = 0;
   out_2147733219597398466[150] = 0;
   out_2147733219597398466[151] = 0;
   out_2147733219597398466[152] = 1;
   out_2147733219597398466[153] = 0;
   out_2147733219597398466[154] = 0;
   out_2147733219597398466[155] = 0;
   out_2147733219597398466[156] = 0;
   out_2147733219597398466[157] = 0;
   out_2147733219597398466[158] = 0;
   out_2147733219597398466[159] = 0;
   out_2147733219597398466[160] = 0;
   out_2147733219597398466[161] = 0;
   out_2147733219597398466[162] = 0;
   out_2147733219597398466[163] = 0;
   out_2147733219597398466[164] = 0;
   out_2147733219597398466[165] = 0;
   out_2147733219597398466[166] = 0;
   out_2147733219597398466[167] = 0;
   out_2147733219597398466[168] = 0;
   out_2147733219597398466[169] = 0;
   out_2147733219597398466[170] = 0;
   out_2147733219597398466[171] = 1;
   out_2147733219597398466[172] = 0;
   out_2147733219597398466[173] = 0;
   out_2147733219597398466[174] = 0;
   out_2147733219597398466[175] = 0;
   out_2147733219597398466[176] = 0;
   out_2147733219597398466[177] = 0;
   out_2147733219597398466[178] = 0;
   out_2147733219597398466[179] = 0;
   out_2147733219597398466[180] = 0;
   out_2147733219597398466[181] = 0;
   out_2147733219597398466[182] = 0;
   out_2147733219597398466[183] = 0;
   out_2147733219597398466[184] = 0;
   out_2147733219597398466[185] = 0;
   out_2147733219597398466[186] = 0;
   out_2147733219597398466[187] = 0;
   out_2147733219597398466[188] = 0;
   out_2147733219597398466[189] = 0;
   out_2147733219597398466[190] = 1;
   out_2147733219597398466[191] = 0;
   out_2147733219597398466[192] = 0;
   out_2147733219597398466[193] = 0;
   out_2147733219597398466[194] = 0;
   out_2147733219597398466[195] = 0;
   out_2147733219597398466[196] = 0;
   out_2147733219597398466[197] = 0;
   out_2147733219597398466[198] = 0;
   out_2147733219597398466[199] = 0;
   out_2147733219597398466[200] = 0;
   out_2147733219597398466[201] = 0;
   out_2147733219597398466[202] = 0;
   out_2147733219597398466[203] = 0;
   out_2147733219597398466[204] = 0;
   out_2147733219597398466[205] = 0;
   out_2147733219597398466[206] = 0;
   out_2147733219597398466[207] = 0;
   out_2147733219597398466[208] = 0;
   out_2147733219597398466[209] = 1;
   out_2147733219597398466[210] = 0;
   out_2147733219597398466[211] = 0;
   out_2147733219597398466[212] = 0;
   out_2147733219597398466[213] = 0;
   out_2147733219597398466[214] = 0;
   out_2147733219597398466[215] = 0;
   out_2147733219597398466[216] = 0;
   out_2147733219597398466[217] = 0;
   out_2147733219597398466[218] = 0;
   out_2147733219597398466[219] = 0;
   out_2147733219597398466[220] = 0;
   out_2147733219597398466[221] = 0;
   out_2147733219597398466[222] = 0;
   out_2147733219597398466[223] = 0;
   out_2147733219597398466[224] = 0;
   out_2147733219597398466[225] = 0;
   out_2147733219597398466[226] = 0;
   out_2147733219597398466[227] = 0;
   out_2147733219597398466[228] = 1;
   out_2147733219597398466[229] = 0;
   out_2147733219597398466[230] = 0;
   out_2147733219597398466[231] = 0;
   out_2147733219597398466[232] = 0;
   out_2147733219597398466[233] = 0;
   out_2147733219597398466[234] = 0;
   out_2147733219597398466[235] = 0;
   out_2147733219597398466[236] = 0;
   out_2147733219597398466[237] = 0;
   out_2147733219597398466[238] = 0;
   out_2147733219597398466[239] = 0;
   out_2147733219597398466[240] = 0;
   out_2147733219597398466[241] = 0;
   out_2147733219597398466[242] = 0;
   out_2147733219597398466[243] = 0;
   out_2147733219597398466[244] = 0;
   out_2147733219597398466[245] = 0;
   out_2147733219597398466[246] = 0;
   out_2147733219597398466[247] = 1;
   out_2147733219597398466[248] = 0;
   out_2147733219597398466[249] = 0;
   out_2147733219597398466[250] = 0;
   out_2147733219597398466[251] = 0;
   out_2147733219597398466[252] = 0;
   out_2147733219597398466[253] = 0;
   out_2147733219597398466[254] = 0;
   out_2147733219597398466[255] = 0;
   out_2147733219597398466[256] = 0;
   out_2147733219597398466[257] = 0;
   out_2147733219597398466[258] = 0;
   out_2147733219597398466[259] = 0;
   out_2147733219597398466[260] = 0;
   out_2147733219597398466[261] = 0;
   out_2147733219597398466[262] = 0;
   out_2147733219597398466[263] = 0;
   out_2147733219597398466[264] = 0;
   out_2147733219597398466[265] = 0;
   out_2147733219597398466[266] = 1;
   out_2147733219597398466[267] = 0;
   out_2147733219597398466[268] = 0;
   out_2147733219597398466[269] = 0;
   out_2147733219597398466[270] = 0;
   out_2147733219597398466[271] = 0;
   out_2147733219597398466[272] = 0;
   out_2147733219597398466[273] = 0;
   out_2147733219597398466[274] = 0;
   out_2147733219597398466[275] = 0;
   out_2147733219597398466[276] = 0;
   out_2147733219597398466[277] = 0;
   out_2147733219597398466[278] = 0;
   out_2147733219597398466[279] = 0;
   out_2147733219597398466[280] = 0;
   out_2147733219597398466[281] = 0;
   out_2147733219597398466[282] = 0;
   out_2147733219597398466[283] = 0;
   out_2147733219597398466[284] = 0;
   out_2147733219597398466[285] = 1;
   out_2147733219597398466[286] = 0;
   out_2147733219597398466[287] = 0;
   out_2147733219597398466[288] = 0;
   out_2147733219597398466[289] = 0;
   out_2147733219597398466[290] = 0;
   out_2147733219597398466[291] = 0;
   out_2147733219597398466[292] = 0;
   out_2147733219597398466[293] = 0;
   out_2147733219597398466[294] = 0;
   out_2147733219597398466[295] = 0;
   out_2147733219597398466[296] = 0;
   out_2147733219597398466[297] = 0;
   out_2147733219597398466[298] = 0;
   out_2147733219597398466[299] = 0;
   out_2147733219597398466[300] = 0;
   out_2147733219597398466[301] = 0;
   out_2147733219597398466[302] = 0;
   out_2147733219597398466[303] = 0;
   out_2147733219597398466[304] = 1;
   out_2147733219597398466[305] = 0;
   out_2147733219597398466[306] = 0;
   out_2147733219597398466[307] = 0;
   out_2147733219597398466[308] = 0;
   out_2147733219597398466[309] = 0;
   out_2147733219597398466[310] = 0;
   out_2147733219597398466[311] = 0;
   out_2147733219597398466[312] = 0;
   out_2147733219597398466[313] = 0;
   out_2147733219597398466[314] = 0;
   out_2147733219597398466[315] = 0;
   out_2147733219597398466[316] = 0;
   out_2147733219597398466[317] = 0;
   out_2147733219597398466[318] = 0;
   out_2147733219597398466[319] = 0;
   out_2147733219597398466[320] = 0;
   out_2147733219597398466[321] = 0;
   out_2147733219597398466[322] = 0;
   out_2147733219597398466[323] = 1;
}
void h_4(double *state, double *unused, double *out_390661508853925842) {
   out_390661508853925842[0] = state[6] + state[9];
   out_390661508853925842[1] = state[7] + state[10];
   out_390661508853925842[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3712928655556393493) {
   out_3712928655556393493[0] = 0;
   out_3712928655556393493[1] = 0;
   out_3712928655556393493[2] = 0;
   out_3712928655556393493[3] = 0;
   out_3712928655556393493[4] = 0;
   out_3712928655556393493[5] = 0;
   out_3712928655556393493[6] = 1;
   out_3712928655556393493[7] = 0;
   out_3712928655556393493[8] = 0;
   out_3712928655556393493[9] = 1;
   out_3712928655556393493[10] = 0;
   out_3712928655556393493[11] = 0;
   out_3712928655556393493[12] = 0;
   out_3712928655556393493[13] = 0;
   out_3712928655556393493[14] = 0;
   out_3712928655556393493[15] = 0;
   out_3712928655556393493[16] = 0;
   out_3712928655556393493[17] = 0;
   out_3712928655556393493[18] = 0;
   out_3712928655556393493[19] = 0;
   out_3712928655556393493[20] = 0;
   out_3712928655556393493[21] = 0;
   out_3712928655556393493[22] = 0;
   out_3712928655556393493[23] = 0;
   out_3712928655556393493[24] = 0;
   out_3712928655556393493[25] = 1;
   out_3712928655556393493[26] = 0;
   out_3712928655556393493[27] = 0;
   out_3712928655556393493[28] = 1;
   out_3712928655556393493[29] = 0;
   out_3712928655556393493[30] = 0;
   out_3712928655556393493[31] = 0;
   out_3712928655556393493[32] = 0;
   out_3712928655556393493[33] = 0;
   out_3712928655556393493[34] = 0;
   out_3712928655556393493[35] = 0;
   out_3712928655556393493[36] = 0;
   out_3712928655556393493[37] = 0;
   out_3712928655556393493[38] = 0;
   out_3712928655556393493[39] = 0;
   out_3712928655556393493[40] = 0;
   out_3712928655556393493[41] = 0;
   out_3712928655556393493[42] = 0;
   out_3712928655556393493[43] = 0;
   out_3712928655556393493[44] = 1;
   out_3712928655556393493[45] = 0;
   out_3712928655556393493[46] = 0;
   out_3712928655556393493[47] = 1;
   out_3712928655556393493[48] = 0;
   out_3712928655556393493[49] = 0;
   out_3712928655556393493[50] = 0;
   out_3712928655556393493[51] = 0;
   out_3712928655556393493[52] = 0;
   out_3712928655556393493[53] = 0;
}
void h_10(double *state, double *unused, double *out_4622668875416301287) {
   out_4622668875416301287[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4622668875416301287[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4622668875416301287[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_9222803918002037771) {
   out_9222803918002037771[0] = 0;
   out_9222803918002037771[1] = 9.8100000000000005*cos(state[1]);
   out_9222803918002037771[2] = 0;
   out_9222803918002037771[3] = 0;
   out_9222803918002037771[4] = -state[8];
   out_9222803918002037771[5] = state[7];
   out_9222803918002037771[6] = 0;
   out_9222803918002037771[7] = state[5];
   out_9222803918002037771[8] = -state[4];
   out_9222803918002037771[9] = 0;
   out_9222803918002037771[10] = 0;
   out_9222803918002037771[11] = 0;
   out_9222803918002037771[12] = 1;
   out_9222803918002037771[13] = 0;
   out_9222803918002037771[14] = 0;
   out_9222803918002037771[15] = 1;
   out_9222803918002037771[16] = 0;
   out_9222803918002037771[17] = 0;
   out_9222803918002037771[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_9222803918002037771[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_9222803918002037771[20] = 0;
   out_9222803918002037771[21] = state[8];
   out_9222803918002037771[22] = 0;
   out_9222803918002037771[23] = -state[6];
   out_9222803918002037771[24] = -state[5];
   out_9222803918002037771[25] = 0;
   out_9222803918002037771[26] = state[3];
   out_9222803918002037771[27] = 0;
   out_9222803918002037771[28] = 0;
   out_9222803918002037771[29] = 0;
   out_9222803918002037771[30] = 0;
   out_9222803918002037771[31] = 1;
   out_9222803918002037771[32] = 0;
   out_9222803918002037771[33] = 0;
   out_9222803918002037771[34] = 1;
   out_9222803918002037771[35] = 0;
   out_9222803918002037771[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_9222803918002037771[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_9222803918002037771[38] = 0;
   out_9222803918002037771[39] = -state[7];
   out_9222803918002037771[40] = state[6];
   out_9222803918002037771[41] = 0;
   out_9222803918002037771[42] = state[4];
   out_9222803918002037771[43] = -state[3];
   out_9222803918002037771[44] = 0;
   out_9222803918002037771[45] = 0;
   out_9222803918002037771[46] = 0;
   out_9222803918002037771[47] = 0;
   out_9222803918002037771[48] = 0;
   out_9222803918002037771[49] = 0;
   out_9222803918002037771[50] = 1;
   out_9222803918002037771[51] = 0;
   out_9222803918002037771[52] = 0;
   out_9222803918002037771[53] = 1;
}
void h_13(double *state, double *unused, double *out_7573083638476335875) {
   out_7573083638476335875[0] = state[3];
   out_7573083638476335875[1] = state[4];
   out_7573083638476335875[2] = state[5];
}
void H_13(double *state, double *unused, double *out_500654830224060692) {
   out_500654830224060692[0] = 0;
   out_500654830224060692[1] = 0;
   out_500654830224060692[2] = 0;
   out_500654830224060692[3] = 1;
   out_500654830224060692[4] = 0;
   out_500654830224060692[5] = 0;
   out_500654830224060692[6] = 0;
   out_500654830224060692[7] = 0;
   out_500654830224060692[8] = 0;
   out_500654830224060692[9] = 0;
   out_500654830224060692[10] = 0;
   out_500654830224060692[11] = 0;
   out_500654830224060692[12] = 0;
   out_500654830224060692[13] = 0;
   out_500654830224060692[14] = 0;
   out_500654830224060692[15] = 0;
   out_500654830224060692[16] = 0;
   out_500654830224060692[17] = 0;
   out_500654830224060692[18] = 0;
   out_500654830224060692[19] = 0;
   out_500654830224060692[20] = 0;
   out_500654830224060692[21] = 0;
   out_500654830224060692[22] = 1;
   out_500654830224060692[23] = 0;
   out_500654830224060692[24] = 0;
   out_500654830224060692[25] = 0;
   out_500654830224060692[26] = 0;
   out_500654830224060692[27] = 0;
   out_500654830224060692[28] = 0;
   out_500654830224060692[29] = 0;
   out_500654830224060692[30] = 0;
   out_500654830224060692[31] = 0;
   out_500654830224060692[32] = 0;
   out_500654830224060692[33] = 0;
   out_500654830224060692[34] = 0;
   out_500654830224060692[35] = 0;
   out_500654830224060692[36] = 0;
   out_500654830224060692[37] = 0;
   out_500654830224060692[38] = 0;
   out_500654830224060692[39] = 0;
   out_500654830224060692[40] = 0;
   out_500654830224060692[41] = 1;
   out_500654830224060692[42] = 0;
   out_500654830224060692[43] = 0;
   out_500654830224060692[44] = 0;
   out_500654830224060692[45] = 0;
   out_500654830224060692[46] = 0;
   out_500654830224060692[47] = 0;
   out_500654830224060692[48] = 0;
   out_500654830224060692[49] = 0;
   out_500654830224060692[50] = 0;
   out_500654830224060692[51] = 0;
   out_500654830224060692[52] = 0;
   out_500654830224060692[53] = 0;
}
void h_14(double *state, double *unused, double *out_4512296191106361905) {
   out_4512296191106361905[0] = state[6];
   out_4512296191106361905[1] = state[7];
   out_4512296191106361905[2] = state[8];
}
void H_14(double *state, double *unused, double *out_250312200783091036) {
   out_250312200783091036[0] = 0;
   out_250312200783091036[1] = 0;
   out_250312200783091036[2] = 0;
   out_250312200783091036[3] = 0;
   out_250312200783091036[4] = 0;
   out_250312200783091036[5] = 0;
   out_250312200783091036[6] = 1;
   out_250312200783091036[7] = 0;
   out_250312200783091036[8] = 0;
   out_250312200783091036[9] = 0;
   out_250312200783091036[10] = 0;
   out_250312200783091036[11] = 0;
   out_250312200783091036[12] = 0;
   out_250312200783091036[13] = 0;
   out_250312200783091036[14] = 0;
   out_250312200783091036[15] = 0;
   out_250312200783091036[16] = 0;
   out_250312200783091036[17] = 0;
   out_250312200783091036[18] = 0;
   out_250312200783091036[19] = 0;
   out_250312200783091036[20] = 0;
   out_250312200783091036[21] = 0;
   out_250312200783091036[22] = 0;
   out_250312200783091036[23] = 0;
   out_250312200783091036[24] = 0;
   out_250312200783091036[25] = 1;
   out_250312200783091036[26] = 0;
   out_250312200783091036[27] = 0;
   out_250312200783091036[28] = 0;
   out_250312200783091036[29] = 0;
   out_250312200783091036[30] = 0;
   out_250312200783091036[31] = 0;
   out_250312200783091036[32] = 0;
   out_250312200783091036[33] = 0;
   out_250312200783091036[34] = 0;
   out_250312200783091036[35] = 0;
   out_250312200783091036[36] = 0;
   out_250312200783091036[37] = 0;
   out_250312200783091036[38] = 0;
   out_250312200783091036[39] = 0;
   out_250312200783091036[40] = 0;
   out_250312200783091036[41] = 0;
   out_250312200783091036[42] = 0;
   out_250312200783091036[43] = 0;
   out_250312200783091036[44] = 1;
   out_250312200783091036[45] = 0;
   out_250312200783091036[46] = 0;
   out_250312200783091036[47] = 0;
   out_250312200783091036[48] = 0;
   out_250312200783091036[49] = 0;
   out_250312200783091036[50] = 0;
   out_250312200783091036[51] = 0;
   out_250312200783091036[52] = 0;
   out_250312200783091036[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5836812006117722374) {
  err_fun(nom_x, delta_x, out_5836812006117722374);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_368701023819567149) {
  inv_err_fun(nom_x, true_x, out_368701023819567149);
}
void pose_H_mod_fun(double *state, double *out_5720830998239473631) {
  H_mod_fun(state, out_5720830998239473631);
}
void pose_f_fun(double *state, double dt, double *out_3302434187336556995) {
  f_fun(state,  dt, out_3302434187336556995);
}
void pose_F_fun(double *state, double dt, double *out_2147733219597398466) {
  F_fun(state,  dt, out_2147733219597398466);
}
void pose_h_4(double *state, double *unused, double *out_390661508853925842) {
  h_4(state, unused, out_390661508853925842);
}
void pose_H_4(double *state, double *unused, double *out_3712928655556393493) {
  H_4(state, unused, out_3712928655556393493);
}
void pose_h_10(double *state, double *unused, double *out_4622668875416301287) {
  h_10(state, unused, out_4622668875416301287);
}
void pose_H_10(double *state, double *unused, double *out_9222803918002037771) {
  H_10(state, unused, out_9222803918002037771);
}
void pose_h_13(double *state, double *unused, double *out_7573083638476335875) {
  h_13(state, unused, out_7573083638476335875);
}
void pose_H_13(double *state, double *unused, double *out_500654830224060692) {
  H_13(state, unused, out_500654830224060692);
}
void pose_h_14(double *state, double *unused, double *out_4512296191106361905) {
  h_14(state, unused, out_4512296191106361905);
}
void pose_H_14(double *state, double *unused, double *out_250312200783091036) {
  H_14(state, unused, out_250312200783091036);
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
