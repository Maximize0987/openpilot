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
void err_fun(double *nom_x, double *delta_x, double *out_4358722787451740543) {
   out_4358722787451740543[0] = delta_x[0] + nom_x[0];
   out_4358722787451740543[1] = delta_x[1] + nom_x[1];
   out_4358722787451740543[2] = delta_x[2] + nom_x[2];
   out_4358722787451740543[3] = delta_x[3] + nom_x[3];
   out_4358722787451740543[4] = delta_x[4] + nom_x[4];
   out_4358722787451740543[5] = delta_x[5] + nom_x[5];
   out_4358722787451740543[6] = delta_x[6] + nom_x[6];
   out_4358722787451740543[7] = delta_x[7] + nom_x[7];
   out_4358722787451740543[8] = delta_x[8] + nom_x[8];
   out_4358722787451740543[9] = delta_x[9] + nom_x[9];
   out_4358722787451740543[10] = delta_x[10] + nom_x[10];
   out_4358722787451740543[11] = delta_x[11] + nom_x[11];
   out_4358722787451740543[12] = delta_x[12] + nom_x[12];
   out_4358722787451740543[13] = delta_x[13] + nom_x[13];
   out_4358722787451740543[14] = delta_x[14] + nom_x[14];
   out_4358722787451740543[15] = delta_x[15] + nom_x[15];
   out_4358722787451740543[16] = delta_x[16] + nom_x[16];
   out_4358722787451740543[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8563351397910358896) {
   out_8563351397910358896[0] = -nom_x[0] + true_x[0];
   out_8563351397910358896[1] = -nom_x[1] + true_x[1];
   out_8563351397910358896[2] = -nom_x[2] + true_x[2];
   out_8563351397910358896[3] = -nom_x[3] + true_x[3];
   out_8563351397910358896[4] = -nom_x[4] + true_x[4];
   out_8563351397910358896[5] = -nom_x[5] + true_x[5];
   out_8563351397910358896[6] = -nom_x[6] + true_x[6];
   out_8563351397910358896[7] = -nom_x[7] + true_x[7];
   out_8563351397910358896[8] = -nom_x[8] + true_x[8];
   out_8563351397910358896[9] = -nom_x[9] + true_x[9];
   out_8563351397910358896[10] = -nom_x[10] + true_x[10];
   out_8563351397910358896[11] = -nom_x[11] + true_x[11];
   out_8563351397910358896[12] = -nom_x[12] + true_x[12];
   out_8563351397910358896[13] = -nom_x[13] + true_x[13];
   out_8563351397910358896[14] = -nom_x[14] + true_x[14];
   out_8563351397910358896[15] = -nom_x[15] + true_x[15];
   out_8563351397910358896[16] = -nom_x[16] + true_x[16];
   out_8563351397910358896[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5753197897836805411) {
   out_5753197897836805411[0] = 1.0;
   out_5753197897836805411[1] = 0.0;
   out_5753197897836805411[2] = 0.0;
   out_5753197897836805411[3] = 0.0;
   out_5753197897836805411[4] = 0.0;
   out_5753197897836805411[5] = 0.0;
   out_5753197897836805411[6] = 0.0;
   out_5753197897836805411[7] = 0.0;
   out_5753197897836805411[8] = 0.0;
   out_5753197897836805411[9] = 0.0;
   out_5753197897836805411[10] = 0.0;
   out_5753197897836805411[11] = 0.0;
   out_5753197897836805411[12] = 0.0;
   out_5753197897836805411[13] = 0.0;
   out_5753197897836805411[14] = 0.0;
   out_5753197897836805411[15] = 0.0;
   out_5753197897836805411[16] = 0.0;
   out_5753197897836805411[17] = 0.0;
   out_5753197897836805411[18] = 0.0;
   out_5753197897836805411[19] = 1.0;
   out_5753197897836805411[20] = 0.0;
   out_5753197897836805411[21] = 0.0;
   out_5753197897836805411[22] = 0.0;
   out_5753197897836805411[23] = 0.0;
   out_5753197897836805411[24] = 0.0;
   out_5753197897836805411[25] = 0.0;
   out_5753197897836805411[26] = 0.0;
   out_5753197897836805411[27] = 0.0;
   out_5753197897836805411[28] = 0.0;
   out_5753197897836805411[29] = 0.0;
   out_5753197897836805411[30] = 0.0;
   out_5753197897836805411[31] = 0.0;
   out_5753197897836805411[32] = 0.0;
   out_5753197897836805411[33] = 0.0;
   out_5753197897836805411[34] = 0.0;
   out_5753197897836805411[35] = 0.0;
   out_5753197897836805411[36] = 0.0;
   out_5753197897836805411[37] = 0.0;
   out_5753197897836805411[38] = 1.0;
   out_5753197897836805411[39] = 0.0;
   out_5753197897836805411[40] = 0.0;
   out_5753197897836805411[41] = 0.0;
   out_5753197897836805411[42] = 0.0;
   out_5753197897836805411[43] = 0.0;
   out_5753197897836805411[44] = 0.0;
   out_5753197897836805411[45] = 0.0;
   out_5753197897836805411[46] = 0.0;
   out_5753197897836805411[47] = 0.0;
   out_5753197897836805411[48] = 0.0;
   out_5753197897836805411[49] = 0.0;
   out_5753197897836805411[50] = 0.0;
   out_5753197897836805411[51] = 0.0;
   out_5753197897836805411[52] = 0.0;
   out_5753197897836805411[53] = 0.0;
   out_5753197897836805411[54] = 0.0;
   out_5753197897836805411[55] = 0.0;
   out_5753197897836805411[56] = 0.0;
   out_5753197897836805411[57] = 1.0;
   out_5753197897836805411[58] = 0.0;
   out_5753197897836805411[59] = 0.0;
   out_5753197897836805411[60] = 0.0;
   out_5753197897836805411[61] = 0.0;
   out_5753197897836805411[62] = 0.0;
   out_5753197897836805411[63] = 0.0;
   out_5753197897836805411[64] = 0.0;
   out_5753197897836805411[65] = 0.0;
   out_5753197897836805411[66] = 0.0;
   out_5753197897836805411[67] = 0.0;
   out_5753197897836805411[68] = 0.0;
   out_5753197897836805411[69] = 0.0;
   out_5753197897836805411[70] = 0.0;
   out_5753197897836805411[71] = 0.0;
   out_5753197897836805411[72] = 0.0;
   out_5753197897836805411[73] = 0.0;
   out_5753197897836805411[74] = 0.0;
   out_5753197897836805411[75] = 0.0;
   out_5753197897836805411[76] = 1.0;
   out_5753197897836805411[77] = 0.0;
   out_5753197897836805411[78] = 0.0;
   out_5753197897836805411[79] = 0.0;
   out_5753197897836805411[80] = 0.0;
   out_5753197897836805411[81] = 0.0;
   out_5753197897836805411[82] = 0.0;
   out_5753197897836805411[83] = 0.0;
   out_5753197897836805411[84] = 0.0;
   out_5753197897836805411[85] = 0.0;
   out_5753197897836805411[86] = 0.0;
   out_5753197897836805411[87] = 0.0;
   out_5753197897836805411[88] = 0.0;
   out_5753197897836805411[89] = 0.0;
   out_5753197897836805411[90] = 0.0;
   out_5753197897836805411[91] = 0.0;
   out_5753197897836805411[92] = 0.0;
   out_5753197897836805411[93] = 0.0;
   out_5753197897836805411[94] = 0.0;
   out_5753197897836805411[95] = 1.0;
   out_5753197897836805411[96] = 0.0;
   out_5753197897836805411[97] = 0.0;
   out_5753197897836805411[98] = 0.0;
   out_5753197897836805411[99] = 0.0;
   out_5753197897836805411[100] = 0.0;
   out_5753197897836805411[101] = 0.0;
   out_5753197897836805411[102] = 0.0;
   out_5753197897836805411[103] = 0.0;
   out_5753197897836805411[104] = 0.0;
   out_5753197897836805411[105] = 0.0;
   out_5753197897836805411[106] = 0.0;
   out_5753197897836805411[107] = 0.0;
   out_5753197897836805411[108] = 0.0;
   out_5753197897836805411[109] = 0.0;
   out_5753197897836805411[110] = 0.0;
   out_5753197897836805411[111] = 0.0;
   out_5753197897836805411[112] = 0.0;
   out_5753197897836805411[113] = 0.0;
   out_5753197897836805411[114] = 1.0;
   out_5753197897836805411[115] = 0.0;
   out_5753197897836805411[116] = 0.0;
   out_5753197897836805411[117] = 0.0;
   out_5753197897836805411[118] = 0.0;
   out_5753197897836805411[119] = 0.0;
   out_5753197897836805411[120] = 0.0;
   out_5753197897836805411[121] = 0.0;
   out_5753197897836805411[122] = 0.0;
   out_5753197897836805411[123] = 0.0;
   out_5753197897836805411[124] = 0.0;
   out_5753197897836805411[125] = 0.0;
   out_5753197897836805411[126] = 0.0;
   out_5753197897836805411[127] = 0.0;
   out_5753197897836805411[128] = 0.0;
   out_5753197897836805411[129] = 0.0;
   out_5753197897836805411[130] = 0.0;
   out_5753197897836805411[131] = 0.0;
   out_5753197897836805411[132] = 0.0;
   out_5753197897836805411[133] = 1.0;
   out_5753197897836805411[134] = 0.0;
   out_5753197897836805411[135] = 0.0;
   out_5753197897836805411[136] = 0.0;
   out_5753197897836805411[137] = 0.0;
   out_5753197897836805411[138] = 0.0;
   out_5753197897836805411[139] = 0.0;
   out_5753197897836805411[140] = 0.0;
   out_5753197897836805411[141] = 0.0;
   out_5753197897836805411[142] = 0.0;
   out_5753197897836805411[143] = 0.0;
   out_5753197897836805411[144] = 0.0;
   out_5753197897836805411[145] = 0.0;
   out_5753197897836805411[146] = 0.0;
   out_5753197897836805411[147] = 0.0;
   out_5753197897836805411[148] = 0.0;
   out_5753197897836805411[149] = 0.0;
   out_5753197897836805411[150] = 0.0;
   out_5753197897836805411[151] = 0.0;
   out_5753197897836805411[152] = 1.0;
   out_5753197897836805411[153] = 0.0;
   out_5753197897836805411[154] = 0.0;
   out_5753197897836805411[155] = 0.0;
   out_5753197897836805411[156] = 0.0;
   out_5753197897836805411[157] = 0.0;
   out_5753197897836805411[158] = 0.0;
   out_5753197897836805411[159] = 0.0;
   out_5753197897836805411[160] = 0.0;
   out_5753197897836805411[161] = 0.0;
   out_5753197897836805411[162] = 0.0;
   out_5753197897836805411[163] = 0.0;
   out_5753197897836805411[164] = 0.0;
   out_5753197897836805411[165] = 0.0;
   out_5753197897836805411[166] = 0.0;
   out_5753197897836805411[167] = 0.0;
   out_5753197897836805411[168] = 0.0;
   out_5753197897836805411[169] = 0.0;
   out_5753197897836805411[170] = 0.0;
   out_5753197897836805411[171] = 1.0;
   out_5753197897836805411[172] = 0.0;
   out_5753197897836805411[173] = 0.0;
   out_5753197897836805411[174] = 0.0;
   out_5753197897836805411[175] = 0.0;
   out_5753197897836805411[176] = 0.0;
   out_5753197897836805411[177] = 0.0;
   out_5753197897836805411[178] = 0.0;
   out_5753197897836805411[179] = 0.0;
   out_5753197897836805411[180] = 0.0;
   out_5753197897836805411[181] = 0.0;
   out_5753197897836805411[182] = 0.0;
   out_5753197897836805411[183] = 0.0;
   out_5753197897836805411[184] = 0.0;
   out_5753197897836805411[185] = 0.0;
   out_5753197897836805411[186] = 0.0;
   out_5753197897836805411[187] = 0.0;
   out_5753197897836805411[188] = 0.0;
   out_5753197897836805411[189] = 0.0;
   out_5753197897836805411[190] = 1.0;
   out_5753197897836805411[191] = 0.0;
   out_5753197897836805411[192] = 0.0;
   out_5753197897836805411[193] = 0.0;
   out_5753197897836805411[194] = 0.0;
   out_5753197897836805411[195] = 0.0;
   out_5753197897836805411[196] = 0.0;
   out_5753197897836805411[197] = 0.0;
   out_5753197897836805411[198] = 0.0;
   out_5753197897836805411[199] = 0.0;
   out_5753197897836805411[200] = 0.0;
   out_5753197897836805411[201] = 0.0;
   out_5753197897836805411[202] = 0.0;
   out_5753197897836805411[203] = 0.0;
   out_5753197897836805411[204] = 0.0;
   out_5753197897836805411[205] = 0.0;
   out_5753197897836805411[206] = 0.0;
   out_5753197897836805411[207] = 0.0;
   out_5753197897836805411[208] = 0.0;
   out_5753197897836805411[209] = 1.0;
   out_5753197897836805411[210] = 0.0;
   out_5753197897836805411[211] = 0.0;
   out_5753197897836805411[212] = 0.0;
   out_5753197897836805411[213] = 0.0;
   out_5753197897836805411[214] = 0.0;
   out_5753197897836805411[215] = 0.0;
   out_5753197897836805411[216] = 0.0;
   out_5753197897836805411[217] = 0.0;
   out_5753197897836805411[218] = 0.0;
   out_5753197897836805411[219] = 0.0;
   out_5753197897836805411[220] = 0.0;
   out_5753197897836805411[221] = 0.0;
   out_5753197897836805411[222] = 0.0;
   out_5753197897836805411[223] = 0.0;
   out_5753197897836805411[224] = 0.0;
   out_5753197897836805411[225] = 0.0;
   out_5753197897836805411[226] = 0.0;
   out_5753197897836805411[227] = 0.0;
   out_5753197897836805411[228] = 1.0;
   out_5753197897836805411[229] = 0.0;
   out_5753197897836805411[230] = 0.0;
   out_5753197897836805411[231] = 0.0;
   out_5753197897836805411[232] = 0.0;
   out_5753197897836805411[233] = 0.0;
   out_5753197897836805411[234] = 0.0;
   out_5753197897836805411[235] = 0.0;
   out_5753197897836805411[236] = 0.0;
   out_5753197897836805411[237] = 0.0;
   out_5753197897836805411[238] = 0.0;
   out_5753197897836805411[239] = 0.0;
   out_5753197897836805411[240] = 0.0;
   out_5753197897836805411[241] = 0.0;
   out_5753197897836805411[242] = 0.0;
   out_5753197897836805411[243] = 0.0;
   out_5753197897836805411[244] = 0.0;
   out_5753197897836805411[245] = 0.0;
   out_5753197897836805411[246] = 0.0;
   out_5753197897836805411[247] = 1.0;
   out_5753197897836805411[248] = 0.0;
   out_5753197897836805411[249] = 0.0;
   out_5753197897836805411[250] = 0.0;
   out_5753197897836805411[251] = 0.0;
   out_5753197897836805411[252] = 0.0;
   out_5753197897836805411[253] = 0.0;
   out_5753197897836805411[254] = 0.0;
   out_5753197897836805411[255] = 0.0;
   out_5753197897836805411[256] = 0.0;
   out_5753197897836805411[257] = 0.0;
   out_5753197897836805411[258] = 0.0;
   out_5753197897836805411[259] = 0.0;
   out_5753197897836805411[260] = 0.0;
   out_5753197897836805411[261] = 0.0;
   out_5753197897836805411[262] = 0.0;
   out_5753197897836805411[263] = 0.0;
   out_5753197897836805411[264] = 0.0;
   out_5753197897836805411[265] = 0.0;
   out_5753197897836805411[266] = 1.0;
   out_5753197897836805411[267] = 0.0;
   out_5753197897836805411[268] = 0.0;
   out_5753197897836805411[269] = 0.0;
   out_5753197897836805411[270] = 0.0;
   out_5753197897836805411[271] = 0.0;
   out_5753197897836805411[272] = 0.0;
   out_5753197897836805411[273] = 0.0;
   out_5753197897836805411[274] = 0.0;
   out_5753197897836805411[275] = 0.0;
   out_5753197897836805411[276] = 0.0;
   out_5753197897836805411[277] = 0.0;
   out_5753197897836805411[278] = 0.0;
   out_5753197897836805411[279] = 0.0;
   out_5753197897836805411[280] = 0.0;
   out_5753197897836805411[281] = 0.0;
   out_5753197897836805411[282] = 0.0;
   out_5753197897836805411[283] = 0.0;
   out_5753197897836805411[284] = 0.0;
   out_5753197897836805411[285] = 1.0;
   out_5753197897836805411[286] = 0.0;
   out_5753197897836805411[287] = 0.0;
   out_5753197897836805411[288] = 0.0;
   out_5753197897836805411[289] = 0.0;
   out_5753197897836805411[290] = 0.0;
   out_5753197897836805411[291] = 0.0;
   out_5753197897836805411[292] = 0.0;
   out_5753197897836805411[293] = 0.0;
   out_5753197897836805411[294] = 0.0;
   out_5753197897836805411[295] = 0.0;
   out_5753197897836805411[296] = 0.0;
   out_5753197897836805411[297] = 0.0;
   out_5753197897836805411[298] = 0.0;
   out_5753197897836805411[299] = 0.0;
   out_5753197897836805411[300] = 0.0;
   out_5753197897836805411[301] = 0.0;
   out_5753197897836805411[302] = 0.0;
   out_5753197897836805411[303] = 0.0;
   out_5753197897836805411[304] = 1.0;
   out_5753197897836805411[305] = 0.0;
   out_5753197897836805411[306] = 0.0;
   out_5753197897836805411[307] = 0.0;
   out_5753197897836805411[308] = 0.0;
   out_5753197897836805411[309] = 0.0;
   out_5753197897836805411[310] = 0.0;
   out_5753197897836805411[311] = 0.0;
   out_5753197897836805411[312] = 0.0;
   out_5753197897836805411[313] = 0.0;
   out_5753197897836805411[314] = 0.0;
   out_5753197897836805411[315] = 0.0;
   out_5753197897836805411[316] = 0.0;
   out_5753197897836805411[317] = 0.0;
   out_5753197897836805411[318] = 0.0;
   out_5753197897836805411[319] = 0.0;
   out_5753197897836805411[320] = 0.0;
   out_5753197897836805411[321] = 0.0;
   out_5753197897836805411[322] = 0.0;
   out_5753197897836805411[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4934931273554332776) {
   out_4934931273554332776[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4934931273554332776[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4934931273554332776[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4934931273554332776[3] = dt*state[12] + state[3];
   out_4934931273554332776[4] = dt*state[13] + state[4];
   out_4934931273554332776[5] = dt*state[14] + state[5];
   out_4934931273554332776[6] = state[6];
   out_4934931273554332776[7] = state[7];
   out_4934931273554332776[8] = state[8];
   out_4934931273554332776[9] = state[9];
   out_4934931273554332776[10] = state[10];
   out_4934931273554332776[11] = state[11];
   out_4934931273554332776[12] = state[12];
   out_4934931273554332776[13] = state[13];
   out_4934931273554332776[14] = state[14];
   out_4934931273554332776[15] = state[15];
   out_4934931273554332776[16] = state[16];
   out_4934931273554332776[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3951309264317131877) {
   out_3951309264317131877[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3951309264317131877[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3951309264317131877[2] = 0;
   out_3951309264317131877[3] = 0;
   out_3951309264317131877[4] = 0;
   out_3951309264317131877[5] = 0;
   out_3951309264317131877[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3951309264317131877[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3951309264317131877[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3951309264317131877[9] = 0;
   out_3951309264317131877[10] = 0;
   out_3951309264317131877[11] = 0;
   out_3951309264317131877[12] = 0;
   out_3951309264317131877[13] = 0;
   out_3951309264317131877[14] = 0;
   out_3951309264317131877[15] = 0;
   out_3951309264317131877[16] = 0;
   out_3951309264317131877[17] = 0;
   out_3951309264317131877[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3951309264317131877[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3951309264317131877[20] = 0;
   out_3951309264317131877[21] = 0;
   out_3951309264317131877[22] = 0;
   out_3951309264317131877[23] = 0;
   out_3951309264317131877[24] = 0;
   out_3951309264317131877[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3951309264317131877[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3951309264317131877[27] = 0;
   out_3951309264317131877[28] = 0;
   out_3951309264317131877[29] = 0;
   out_3951309264317131877[30] = 0;
   out_3951309264317131877[31] = 0;
   out_3951309264317131877[32] = 0;
   out_3951309264317131877[33] = 0;
   out_3951309264317131877[34] = 0;
   out_3951309264317131877[35] = 0;
   out_3951309264317131877[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3951309264317131877[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3951309264317131877[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3951309264317131877[39] = 0;
   out_3951309264317131877[40] = 0;
   out_3951309264317131877[41] = 0;
   out_3951309264317131877[42] = 0;
   out_3951309264317131877[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3951309264317131877[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3951309264317131877[45] = 0;
   out_3951309264317131877[46] = 0;
   out_3951309264317131877[47] = 0;
   out_3951309264317131877[48] = 0;
   out_3951309264317131877[49] = 0;
   out_3951309264317131877[50] = 0;
   out_3951309264317131877[51] = 0;
   out_3951309264317131877[52] = 0;
   out_3951309264317131877[53] = 0;
   out_3951309264317131877[54] = 0;
   out_3951309264317131877[55] = 0;
   out_3951309264317131877[56] = 0;
   out_3951309264317131877[57] = 1;
   out_3951309264317131877[58] = 0;
   out_3951309264317131877[59] = 0;
   out_3951309264317131877[60] = 0;
   out_3951309264317131877[61] = 0;
   out_3951309264317131877[62] = 0;
   out_3951309264317131877[63] = 0;
   out_3951309264317131877[64] = 0;
   out_3951309264317131877[65] = 0;
   out_3951309264317131877[66] = dt;
   out_3951309264317131877[67] = 0;
   out_3951309264317131877[68] = 0;
   out_3951309264317131877[69] = 0;
   out_3951309264317131877[70] = 0;
   out_3951309264317131877[71] = 0;
   out_3951309264317131877[72] = 0;
   out_3951309264317131877[73] = 0;
   out_3951309264317131877[74] = 0;
   out_3951309264317131877[75] = 0;
   out_3951309264317131877[76] = 1;
   out_3951309264317131877[77] = 0;
   out_3951309264317131877[78] = 0;
   out_3951309264317131877[79] = 0;
   out_3951309264317131877[80] = 0;
   out_3951309264317131877[81] = 0;
   out_3951309264317131877[82] = 0;
   out_3951309264317131877[83] = 0;
   out_3951309264317131877[84] = 0;
   out_3951309264317131877[85] = dt;
   out_3951309264317131877[86] = 0;
   out_3951309264317131877[87] = 0;
   out_3951309264317131877[88] = 0;
   out_3951309264317131877[89] = 0;
   out_3951309264317131877[90] = 0;
   out_3951309264317131877[91] = 0;
   out_3951309264317131877[92] = 0;
   out_3951309264317131877[93] = 0;
   out_3951309264317131877[94] = 0;
   out_3951309264317131877[95] = 1;
   out_3951309264317131877[96] = 0;
   out_3951309264317131877[97] = 0;
   out_3951309264317131877[98] = 0;
   out_3951309264317131877[99] = 0;
   out_3951309264317131877[100] = 0;
   out_3951309264317131877[101] = 0;
   out_3951309264317131877[102] = 0;
   out_3951309264317131877[103] = 0;
   out_3951309264317131877[104] = dt;
   out_3951309264317131877[105] = 0;
   out_3951309264317131877[106] = 0;
   out_3951309264317131877[107] = 0;
   out_3951309264317131877[108] = 0;
   out_3951309264317131877[109] = 0;
   out_3951309264317131877[110] = 0;
   out_3951309264317131877[111] = 0;
   out_3951309264317131877[112] = 0;
   out_3951309264317131877[113] = 0;
   out_3951309264317131877[114] = 1;
   out_3951309264317131877[115] = 0;
   out_3951309264317131877[116] = 0;
   out_3951309264317131877[117] = 0;
   out_3951309264317131877[118] = 0;
   out_3951309264317131877[119] = 0;
   out_3951309264317131877[120] = 0;
   out_3951309264317131877[121] = 0;
   out_3951309264317131877[122] = 0;
   out_3951309264317131877[123] = 0;
   out_3951309264317131877[124] = 0;
   out_3951309264317131877[125] = 0;
   out_3951309264317131877[126] = 0;
   out_3951309264317131877[127] = 0;
   out_3951309264317131877[128] = 0;
   out_3951309264317131877[129] = 0;
   out_3951309264317131877[130] = 0;
   out_3951309264317131877[131] = 0;
   out_3951309264317131877[132] = 0;
   out_3951309264317131877[133] = 1;
   out_3951309264317131877[134] = 0;
   out_3951309264317131877[135] = 0;
   out_3951309264317131877[136] = 0;
   out_3951309264317131877[137] = 0;
   out_3951309264317131877[138] = 0;
   out_3951309264317131877[139] = 0;
   out_3951309264317131877[140] = 0;
   out_3951309264317131877[141] = 0;
   out_3951309264317131877[142] = 0;
   out_3951309264317131877[143] = 0;
   out_3951309264317131877[144] = 0;
   out_3951309264317131877[145] = 0;
   out_3951309264317131877[146] = 0;
   out_3951309264317131877[147] = 0;
   out_3951309264317131877[148] = 0;
   out_3951309264317131877[149] = 0;
   out_3951309264317131877[150] = 0;
   out_3951309264317131877[151] = 0;
   out_3951309264317131877[152] = 1;
   out_3951309264317131877[153] = 0;
   out_3951309264317131877[154] = 0;
   out_3951309264317131877[155] = 0;
   out_3951309264317131877[156] = 0;
   out_3951309264317131877[157] = 0;
   out_3951309264317131877[158] = 0;
   out_3951309264317131877[159] = 0;
   out_3951309264317131877[160] = 0;
   out_3951309264317131877[161] = 0;
   out_3951309264317131877[162] = 0;
   out_3951309264317131877[163] = 0;
   out_3951309264317131877[164] = 0;
   out_3951309264317131877[165] = 0;
   out_3951309264317131877[166] = 0;
   out_3951309264317131877[167] = 0;
   out_3951309264317131877[168] = 0;
   out_3951309264317131877[169] = 0;
   out_3951309264317131877[170] = 0;
   out_3951309264317131877[171] = 1;
   out_3951309264317131877[172] = 0;
   out_3951309264317131877[173] = 0;
   out_3951309264317131877[174] = 0;
   out_3951309264317131877[175] = 0;
   out_3951309264317131877[176] = 0;
   out_3951309264317131877[177] = 0;
   out_3951309264317131877[178] = 0;
   out_3951309264317131877[179] = 0;
   out_3951309264317131877[180] = 0;
   out_3951309264317131877[181] = 0;
   out_3951309264317131877[182] = 0;
   out_3951309264317131877[183] = 0;
   out_3951309264317131877[184] = 0;
   out_3951309264317131877[185] = 0;
   out_3951309264317131877[186] = 0;
   out_3951309264317131877[187] = 0;
   out_3951309264317131877[188] = 0;
   out_3951309264317131877[189] = 0;
   out_3951309264317131877[190] = 1;
   out_3951309264317131877[191] = 0;
   out_3951309264317131877[192] = 0;
   out_3951309264317131877[193] = 0;
   out_3951309264317131877[194] = 0;
   out_3951309264317131877[195] = 0;
   out_3951309264317131877[196] = 0;
   out_3951309264317131877[197] = 0;
   out_3951309264317131877[198] = 0;
   out_3951309264317131877[199] = 0;
   out_3951309264317131877[200] = 0;
   out_3951309264317131877[201] = 0;
   out_3951309264317131877[202] = 0;
   out_3951309264317131877[203] = 0;
   out_3951309264317131877[204] = 0;
   out_3951309264317131877[205] = 0;
   out_3951309264317131877[206] = 0;
   out_3951309264317131877[207] = 0;
   out_3951309264317131877[208] = 0;
   out_3951309264317131877[209] = 1;
   out_3951309264317131877[210] = 0;
   out_3951309264317131877[211] = 0;
   out_3951309264317131877[212] = 0;
   out_3951309264317131877[213] = 0;
   out_3951309264317131877[214] = 0;
   out_3951309264317131877[215] = 0;
   out_3951309264317131877[216] = 0;
   out_3951309264317131877[217] = 0;
   out_3951309264317131877[218] = 0;
   out_3951309264317131877[219] = 0;
   out_3951309264317131877[220] = 0;
   out_3951309264317131877[221] = 0;
   out_3951309264317131877[222] = 0;
   out_3951309264317131877[223] = 0;
   out_3951309264317131877[224] = 0;
   out_3951309264317131877[225] = 0;
   out_3951309264317131877[226] = 0;
   out_3951309264317131877[227] = 0;
   out_3951309264317131877[228] = 1;
   out_3951309264317131877[229] = 0;
   out_3951309264317131877[230] = 0;
   out_3951309264317131877[231] = 0;
   out_3951309264317131877[232] = 0;
   out_3951309264317131877[233] = 0;
   out_3951309264317131877[234] = 0;
   out_3951309264317131877[235] = 0;
   out_3951309264317131877[236] = 0;
   out_3951309264317131877[237] = 0;
   out_3951309264317131877[238] = 0;
   out_3951309264317131877[239] = 0;
   out_3951309264317131877[240] = 0;
   out_3951309264317131877[241] = 0;
   out_3951309264317131877[242] = 0;
   out_3951309264317131877[243] = 0;
   out_3951309264317131877[244] = 0;
   out_3951309264317131877[245] = 0;
   out_3951309264317131877[246] = 0;
   out_3951309264317131877[247] = 1;
   out_3951309264317131877[248] = 0;
   out_3951309264317131877[249] = 0;
   out_3951309264317131877[250] = 0;
   out_3951309264317131877[251] = 0;
   out_3951309264317131877[252] = 0;
   out_3951309264317131877[253] = 0;
   out_3951309264317131877[254] = 0;
   out_3951309264317131877[255] = 0;
   out_3951309264317131877[256] = 0;
   out_3951309264317131877[257] = 0;
   out_3951309264317131877[258] = 0;
   out_3951309264317131877[259] = 0;
   out_3951309264317131877[260] = 0;
   out_3951309264317131877[261] = 0;
   out_3951309264317131877[262] = 0;
   out_3951309264317131877[263] = 0;
   out_3951309264317131877[264] = 0;
   out_3951309264317131877[265] = 0;
   out_3951309264317131877[266] = 1;
   out_3951309264317131877[267] = 0;
   out_3951309264317131877[268] = 0;
   out_3951309264317131877[269] = 0;
   out_3951309264317131877[270] = 0;
   out_3951309264317131877[271] = 0;
   out_3951309264317131877[272] = 0;
   out_3951309264317131877[273] = 0;
   out_3951309264317131877[274] = 0;
   out_3951309264317131877[275] = 0;
   out_3951309264317131877[276] = 0;
   out_3951309264317131877[277] = 0;
   out_3951309264317131877[278] = 0;
   out_3951309264317131877[279] = 0;
   out_3951309264317131877[280] = 0;
   out_3951309264317131877[281] = 0;
   out_3951309264317131877[282] = 0;
   out_3951309264317131877[283] = 0;
   out_3951309264317131877[284] = 0;
   out_3951309264317131877[285] = 1;
   out_3951309264317131877[286] = 0;
   out_3951309264317131877[287] = 0;
   out_3951309264317131877[288] = 0;
   out_3951309264317131877[289] = 0;
   out_3951309264317131877[290] = 0;
   out_3951309264317131877[291] = 0;
   out_3951309264317131877[292] = 0;
   out_3951309264317131877[293] = 0;
   out_3951309264317131877[294] = 0;
   out_3951309264317131877[295] = 0;
   out_3951309264317131877[296] = 0;
   out_3951309264317131877[297] = 0;
   out_3951309264317131877[298] = 0;
   out_3951309264317131877[299] = 0;
   out_3951309264317131877[300] = 0;
   out_3951309264317131877[301] = 0;
   out_3951309264317131877[302] = 0;
   out_3951309264317131877[303] = 0;
   out_3951309264317131877[304] = 1;
   out_3951309264317131877[305] = 0;
   out_3951309264317131877[306] = 0;
   out_3951309264317131877[307] = 0;
   out_3951309264317131877[308] = 0;
   out_3951309264317131877[309] = 0;
   out_3951309264317131877[310] = 0;
   out_3951309264317131877[311] = 0;
   out_3951309264317131877[312] = 0;
   out_3951309264317131877[313] = 0;
   out_3951309264317131877[314] = 0;
   out_3951309264317131877[315] = 0;
   out_3951309264317131877[316] = 0;
   out_3951309264317131877[317] = 0;
   out_3951309264317131877[318] = 0;
   out_3951309264317131877[319] = 0;
   out_3951309264317131877[320] = 0;
   out_3951309264317131877[321] = 0;
   out_3951309264317131877[322] = 0;
   out_3951309264317131877[323] = 1;
}
void h_4(double *state, double *unused, double *out_9124951261160774984) {
   out_9124951261160774984[0] = state[6] + state[9];
   out_9124951261160774984[1] = state[7] + state[10];
   out_9124951261160774984[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1981390687992897839) {
   out_1981390687992897839[0] = 0;
   out_1981390687992897839[1] = 0;
   out_1981390687992897839[2] = 0;
   out_1981390687992897839[3] = 0;
   out_1981390687992897839[4] = 0;
   out_1981390687992897839[5] = 0;
   out_1981390687992897839[6] = 1;
   out_1981390687992897839[7] = 0;
   out_1981390687992897839[8] = 0;
   out_1981390687992897839[9] = 1;
   out_1981390687992897839[10] = 0;
   out_1981390687992897839[11] = 0;
   out_1981390687992897839[12] = 0;
   out_1981390687992897839[13] = 0;
   out_1981390687992897839[14] = 0;
   out_1981390687992897839[15] = 0;
   out_1981390687992897839[16] = 0;
   out_1981390687992897839[17] = 0;
   out_1981390687992897839[18] = 0;
   out_1981390687992897839[19] = 0;
   out_1981390687992897839[20] = 0;
   out_1981390687992897839[21] = 0;
   out_1981390687992897839[22] = 0;
   out_1981390687992897839[23] = 0;
   out_1981390687992897839[24] = 0;
   out_1981390687992897839[25] = 1;
   out_1981390687992897839[26] = 0;
   out_1981390687992897839[27] = 0;
   out_1981390687992897839[28] = 1;
   out_1981390687992897839[29] = 0;
   out_1981390687992897839[30] = 0;
   out_1981390687992897839[31] = 0;
   out_1981390687992897839[32] = 0;
   out_1981390687992897839[33] = 0;
   out_1981390687992897839[34] = 0;
   out_1981390687992897839[35] = 0;
   out_1981390687992897839[36] = 0;
   out_1981390687992897839[37] = 0;
   out_1981390687992897839[38] = 0;
   out_1981390687992897839[39] = 0;
   out_1981390687992897839[40] = 0;
   out_1981390687992897839[41] = 0;
   out_1981390687992897839[42] = 0;
   out_1981390687992897839[43] = 0;
   out_1981390687992897839[44] = 1;
   out_1981390687992897839[45] = 0;
   out_1981390687992897839[46] = 0;
   out_1981390687992897839[47] = 1;
   out_1981390687992897839[48] = 0;
   out_1981390687992897839[49] = 0;
   out_1981390687992897839[50] = 0;
   out_1981390687992897839[51] = 0;
   out_1981390687992897839[52] = 0;
   out_1981390687992897839[53] = 0;
}
void h_10(double *state, double *unused, double *out_5902756371163799354) {
   out_5902756371163799354[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5902756371163799354[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5902756371163799354[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3301172069868817257) {
   out_3301172069868817257[0] = 0;
   out_3301172069868817257[1] = 9.8100000000000005*cos(state[1]);
   out_3301172069868817257[2] = 0;
   out_3301172069868817257[3] = 0;
   out_3301172069868817257[4] = -state[8];
   out_3301172069868817257[5] = state[7];
   out_3301172069868817257[6] = 0;
   out_3301172069868817257[7] = state[5];
   out_3301172069868817257[8] = -state[4];
   out_3301172069868817257[9] = 0;
   out_3301172069868817257[10] = 0;
   out_3301172069868817257[11] = 0;
   out_3301172069868817257[12] = 1;
   out_3301172069868817257[13] = 0;
   out_3301172069868817257[14] = 0;
   out_3301172069868817257[15] = 1;
   out_3301172069868817257[16] = 0;
   out_3301172069868817257[17] = 0;
   out_3301172069868817257[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3301172069868817257[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3301172069868817257[20] = 0;
   out_3301172069868817257[21] = state[8];
   out_3301172069868817257[22] = 0;
   out_3301172069868817257[23] = -state[6];
   out_3301172069868817257[24] = -state[5];
   out_3301172069868817257[25] = 0;
   out_3301172069868817257[26] = state[3];
   out_3301172069868817257[27] = 0;
   out_3301172069868817257[28] = 0;
   out_3301172069868817257[29] = 0;
   out_3301172069868817257[30] = 0;
   out_3301172069868817257[31] = 1;
   out_3301172069868817257[32] = 0;
   out_3301172069868817257[33] = 0;
   out_3301172069868817257[34] = 1;
   out_3301172069868817257[35] = 0;
   out_3301172069868817257[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3301172069868817257[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3301172069868817257[38] = 0;
   out_3301172069868817257[39] = -state[7];
   out_3301172069868817257[40] = state[6];
   out_3301172069868817257[41] = 0;
   out_3301172069868817257[42] = state[4];
   out_3301172069868817257[43] = -state[3];
   out_3301172069868817257[44] = 0;
   out_3301172069868817257[45] = 0;
   out_3301172069868817257[46] = 0;
   out_3301172069868817257[47] = 0;
   out_3301172069868817257[48] = 0;
   out_3301172069868817257[49] = 0;
   out_3301172069868817257[50] = 1;
   out_3301172069868817257[51] = 0;
   out_3301172069868817257[52] = 0;
   out_3301172069868817257[53] = 1;
}
void h_13(double *state, double *unused, double *out_1037730484658777493) {
   out_1037730484658777493[0] = state[3];
   out_1037730484658777493[1] = state[4];
   out_1037730484658777493[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1230883137339434962) {
   out_1230883137339434962[0] = 0;
   out_1230883137339434962[1] = 0;
   out_1230883137339434962[2] = 0;
   out_1230883137339434962[3] = 1;
   out_1230883137339434962[4] = 0;
   out_1230883137339434962[5] = 0;
   out_1230883137339434962[6] = 0;
   out_1230883137339434962[7] = 0;
   out_1230883137339434962[8] = 0;
   out_1230883137339434962[9] = 0;
   out_1230883137339434962[10] = 0;
   out_1230883137339434962[11] = 0;
   out_1230883137339434962[12] = 0;
   out_1230883137339434962[13] = 0;
   out_1230883137339434962[14] = 0;
   out_1230883137339434962[15] = 0;
   out_1230883137339434962[16] = 0;
   out_1230883137339434962[17] = 0;
   out_1230883137339434962[18] = 0;
   out_1230883137339434962[19] = 0;
   out_1230883137339434962[20] = 0;
   out_1230883137339434962[21] = 0;
   out_1230883137339434962[22] = 1;
   out_1230883137339434962[23] = 0;
   out_1230883137339434962[24] = 0;
   out_1230883137339434962[25] = 0;
   out_1230883137339434962[26] = 0;
   out_1230883137339434962[27] = 0;
   out_1230883137339434962[28] = 0;
   out_1230883137339434962[29] = 0;
   out_1230883137339434962[30] = 0;
   out_1230883137339434962[31] = 0;
   out_1230883137339434962[32] = 0;
   out_1230883137339434962[33] = 0;
   out_1230883137339434962[34] = 0;
   out_1230883137339434962[35] = 0;
   out_1230883137339434962[36] = 0;
   out_1230883137339434962[37] = 0;
   out_1230883137339434962[38] = 0;
   out_1230883137339434962[39] = 0;
   out_1230883137339434962[40] = 0;
   out_1230883137339434962[41] = 1;
   out_1230883137339434962[42] = 0;
   out_1230883137339434962[43] = 0;
   out_1230883137339434962[44] = 0;
   out_1230883137339434962[45] = 0;
   out_1230883137339434962[46] = 0;
   out_1230883137339434962[47] = 0;
   out_1230883137339434962[48] = 0;
   out_1230883137339434962[49] = 0;
   out_1230883137339434962[50] = 0;
   out_1230883137339434962[51] = 0;
   out_1230883137339434962[52] = 0;
   out_1230883137339434962[53] = 0;
}
void h_14(double *state, double *unused, double *out_8550422043798884554) {
   out_8550422043798884554[0] = state[6];
   out_8550422043798884554[1] = state[7];
   out_8550422043798884554[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5064179120288270135) {
   out_5064179120288270135[0] = 0;
   out_5064179120288270135[1] = 0;
   out_5064179120288270135[2] = 0;
   out_5064179120288270135[3] = 0;
   out_5064179120288270135[4] = 0;
   out_5064179120288270135[5] = 0;
   out_5064179120288270135[6] = 1;
   out_5064179120288270135[7] = 0;
   out_5064179120288270135[8] = 0;
   out_5064179120288270135[9] = 0;
   out_5064179120288270135[10] = 0;
   out_5064179120288270135[11] = 0;
   out_5064179120288270135[12] = 0;
   out_5064179120288270135[13] = 0;
   out_5064179120288270135[14] = 0;
   out_5064179120288270135[15] = 0;
   out_5064179120288270135[16] = 0;
   out_5064179120288270135[17] = 0;
   out_5064179120288270135[18] = 0;
   out_5064179120288270135[19] = 0;
   out_5064179120288270135[20] = 0;
   out_5064179120288270135[21] = 0;
   out_5064179120288270135[22] = 0;
   out_5064179120288270135[23] = 0;
   out_5064179120288270135[24] = 0;
   out_5064179120288270135[25] = 1;
   out_5064179120288270135[26] = 0;
   out_5064179120288270135[27] = 0;
   out_5064179120288270135[28] = 0;
   out_5064179120288270135[29] = 0;
   out_5064179120288270135[30] = 0;
   out_5064179120288270135[31] = 0;
   out_5064179120288270135[32] = 0;
   out_5064179120288270135[33] = 0;
   out_5064179120288270135[34] = 0;
   out_5064179120288270135[35] = 0;
   out_5064179120288270135[36] = 0;
   out_5064179120288270135[37] = 0;
   out_5064179120288270135[38] = 0;
   out_5064179120288270135[39] = 0;
   out_5064179120288270135[40] = 0;
   out_5064179120288270135[41] = 0;
   out_5064179120288270135[42] = 0;
   out_5064179120288270135[43] = 0;
   out_5064179120288270135[44] = 1;
   out_5064179120288270135[45] = 0;
   out_5064179120288270135[46] = 0;
   out_5064179120288270135[47] = 0;
   out_5064179120288270135[48] = 0;
   out_5064179120288270135[49] = 0;
   out_5064179120288270135[50] = 0;
   out_5064179120288270135[51] = 0;
   out_5064179120288270135[52] = 0;
   out_5064179120288270135[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4358722787451740543) {
  err_fun(nom_x, delta_x, out_4358722787451740543);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8563351397910358896) {
  inv_err_fun(nom_x, true_x, out_8563351397910358896);
}
void pose_H_mod_fun(double *state, double *out_5753197897836805411) {
  H_mod_fun(state, out_5753197897836805411);
}
void pose_f_fun(double *state, double dt, double *out_4934931273554332776) {
  f_fun(state,  dt, out_4934931273554332776);
}
void pose_F_fun(double *state, double dt, double *out_3951309264317131877) {
  F_fun(state,  dt, out_3951309264317131877);
}
void pose_h_4(double *state, double *unused, double *out_9124951261160774984) {
  h_4(state, unused, out_9124951261160774984);
}
void pose_H_4(double *state, double *unused, double *out_1981390687992897839) {
  H_4(state, unused, out_1981390687992897839);
}
void pose_h_10(double *state, double *unused, double *out_5902756371163799354) {
  h_10(state, unused, out_5902756371163799354);
}
void pose_H_10(double *state, double *unused, double *out_3301172069868817257) {
  H_10(state, unused, out_3301172069868817257);
}
void pose_h_13(double *state, double *unused, double *out_1037730484658777493) {
  h_13(state, unused, out_1037730484658777493);
}
void pose_H_13(double *state, double *unused, double *out_1230883137339434962) {
  H_13(state, unused, out_1230883137339434962);
}
void pose_h_14(double *state, double *unused, double *out_8550422043798884554) {
  h_14(state, unused, out_8550422043798884554);
}
void pose_H_14(double *state, double *unused, double *out_5064179120288270135) {
  H_14(state, unused, out_5064179120288270135);
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
