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
void err_fun(double *nom_x, double *delta_x, double *out_772147526555487692) {
   out_772147526555487692[0] = delta_x[0] + nom_x[0];
   out_772147526555487692[1] = delta_x[1] + nom_x[1];
   out_772147526555487692[2] = delta_x[2] + nom_x[2];
   out_772147526555487692[3] = delta_x[3] + nom_x[3];
   out_772147526555487692[4] = delta_x[4] + nom_x[4];
   out_772147526555487692[5] = delta_x[5] + nom_x[5];
   out_772147526555487692[6] = delta_x[6] + nom_x[6];
   out_772147526555487692[7] = delta_x[7] + nom_x[7];
   out_772147526555487692[8] = delta_x[8] + nom_x[8];
   out_772147526555487692[9] = delta_x[9] + nom_x[9];
   out_772147526555487692[10] = delta_x[10] + nom_x[10];
   out_772147526555487692[11] = delta_x[11] + nom_x[11];
   out_772147526555487692[12] = delta_x[12] + nom_x[12];
   out_772147526555487692[13] = delta_x[13] + nom_x[13];
   out_772147526555487692[14] = delta_x[14] + nom_x[14];
   out_772147526555487692[15] = delta_x[15] + nom_x[15];
   out_772147526555487692[16] = delta_x[16] + nom_x[16];
   out_772147526555487692[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4282924253332717604) {
   out_4282924253332717604[0] = -nom_x[0] + true_x[0];
   out_4282924253332717604[1] = -nom_x[1] + true_x[1];
   out_4282924253332717604[2] = -nom_x[2] + true_x[2];
   out_4282924253332717604[3] = -nom_x[3] + true_x[3];
   out_4282924253332717604[4] = -nom_x[4] + true_x[4];
   out_4282924253332717604[5] = -nom_x[5] + true_x[5];
   out_4282924253332717604[6] = -nom_x[6] + true_x[6];
   out_4282924253332717604[7] = -nom_x[7] + true_x[7];
   out_4282924253332717604[8] = -nom_x[8] + true_x[8];
   out_4282924253332717604[9] = -nom_x[9] + true_x[9];
   out_4282924253332717604[10] = -nom_x[10] + true_x[10];
   out_4282924253332717604[11] = -nom_x[11] + true_x[11];
   out_4282924253332717604[12] = -nom_x[12] + true_x[12];
   out_4282924253332717604[13] = -nom_x[13] + true_x[13];
   out_4282924253332717604[14] = -nom_x[14] + true_x[14];
   out_4282924253332717604[15] = -nom_x[15] + true_x[15];
   out_4282924253332717604[16] = -nom_x[16] + true_x[16];
   out_4282924253332717604[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4974307322782455600) {
   out_4974307322782455600[0] = 1.0;
   out_4974307322782455600[1] = 0.0;
   out_4974307322782455600[2] = 0.0;
   out_4974307322782455600[3] = 0.0;
   out_4974307322782455600[4] = 0.0;
   out_4974307322782455600[5] = 0.0;
   out_4974307322782455600[6] = 0.0;
   out_4974307322782455600[7] = 0.0;
   out_4974307322782455600[8] = 0.0;
   out_4974307322782455600[9] = 0.0;
   out_4974307322782455600[10] = 0.0;
   out_4974307322782455600[11] = 0.0;
   out_4974307322782455600[12] = 0.0;
   out_4974307322782455600[13] = 0.0;
   out_4974307322782455600[14] = 0.0;
   out_4974307322782455600[15] = 0.0;
   out_4974307322782455600[16] = 0.0;
   out_4974307322782455600[17] = 0.0;
   out_4974307322782455600[18] = 0.0;
   out_4974307322782455600[19] = 1.0;
   out_4974307322782455600[20] = 0.0;
   out_4974307322782455600[21] = 0.0;
   out_4974307322782455600[22] = 0.0;
   out_4974307322782455600[23] = 0.0;
   out_4974307322782455600[24] = 0.0;
   out_4974307322782455600[25] = 0.0;
   out_4974307322782455600[26] = 0.0;
   out_4974307322782455600[27] = 0.0;
   out_4974307322782455600[28] = 0.0;
   out_4974307322782455600[29] = 0.0;
   out_4974307322782455600[30] = 0.0;
   out_4974307322782455600[31] = 0.0;
   out_4974307322782455600[32] = 0.0;
   out_4974307322782455600[33] = 0.0;
   out_4974307322782455600[34] = 0.0;
   out_4974307322782455600[35] = 0.0;
   out_4974307322782455600[36] = 0.0;
   out_4974307322782455600[37] = 0.0;
   out_4974307322782455600[38] = 1.0;
   out_4974307322782455600[39] = 0.0;
   out_4974307322782455600[40] = 0.0;
   out_4974307322782455600[41] = 0.0;
   out_4974307322782455600[42] = 0.0;
   out_4974307322782455600[43] = 0.0;
   out_4974307322782455600[44] = 0.0;
   out_4974307322782455600[45] = 0.0;
   out_4974307322782455600[46] = 0.0;
   out_4974307322782455600[47] = 0.0;
   out_4974307322782455600[48] = 0.0;
   out_4974307322782455600[49] = 0.0;
   out_4974307322782455600[50] = 0.0;
   out_4974307322782455600[51] = 0.0;
   out_4974307322782455600[52] = 0.0;
   out_4974307322782455600[53] = 0.0;
   out_4974307322782455600[54] = 0.0;
   out_4974307322782455600[55] = 0.0;
   out_4974307322782455600[56] = 0.0;
   out_4974307322782455600[57] = 1.0;
   out_4974307322782455600[58] = 0.0;
   out_4974307322782455600[59] = 0.0;
   out_4974307322782455600[60] = 0.0;
   out_4974307322782455600[61] = 0.0;
   out_4974307322782455600[62] = 0.0;
   out_4974307322782455600[63] = 0.0;
   out_4974307322782455600[64] = 0.0;
   out_4974307322782455600[65] = 0.0;
   out_4974307322782455600[66] = 0.0;
   out_4974307322782455600[67] = 0.0;
   out_4974307322782455600[68] = 0.0;
   out_4974307322782455600[69] = 0.0;
   out_4974307322782455600[70] = 0.0;
   out_4974307322782455600[71] = 0.0;
   out_4974307322782455600[72] = 0.0;
   out_4974307322782455600[73] = 0.0;
   out_4974307322782455600[74] = 0.0;
   out_4974307322782455600[75] = 0.0;
   out_4974307322782455600[76] = 1.0;
   out_4974307322782455600[77] = 0.0;
   out_4974307322782455600[78] = 0.0;
   out_4974307322782455600[79] = 0.0;
   out_4974307322782455600[80] = 0.0;
   out_4974307322782455600[81] = 0.0;
   out_4974307322782455600[82] = 0.0;
   out_4974307322782455600[83] = 0.0;
   out_4974307322782455600[84] = 0.0;
   out_4974307322782455600[85] = 0.0;
   out_4974307322782455600[86] = 0.0;
   out_4974307322782455600[87] = 0.0;
   out_4974307322782455600[88] = 0.0;
   out_4974307322782455600[89] = 0.0;
   out_4974307322782455600[90] = 0.0;
   out_4974307322782455600[91] = 0.0;
   out_4974307322782455600[92] = 0.0;
   out_4974307322782455600[93] = 0.0;
   out_4974307322782455600[94] = 0.0;
   out_4974307322782455600[95] = 1.0;
   out_4974307322782455600[96] = 0.0;
   out_4974307322782455600[97] = 0.0;
   out_4974307322782455600[98] = 0.0;
   out_4974307322782455600[99] = 0.0;
   out_4974307322782455600[100] = 0.0;
   out_4974307322782455600[101] = 0.0;
   out_4974307322782455600[102] = 0.0;
   out_4974307322782455600[103] = 0.0;
   out_4974307322782455600[104] = 0.0;
   out_4974307322782455600[105] = 0.0;
   out_4974307322782455600[106] = 0.0;
   out_4974307322782455600[107] = 0.0;
   out_4974307322782455600[108] = 0.0;
   out_4974307322782455600[109] = 0.0;
   out_4974307322782455600[110] = 0.0;
   out_4974307322782455600[111] = 0.0;
   out_4974307322782455600[112] = 0.0;
   out_4974307322782455600[113] = 0.0;
   out_4974307322782455600[114] = 1.0;
   out_4974307322782455600[115] = 0.0;
   out_4974307322782455600[116] = 0.0;
   out_4974307322782455600[117] = 0.0;
   out_4974307322782455600[118] = 0.0;
   out_4974307322782455600[119] = 0.0;
   out_4974307322782455600[120] = 0.0;
   out_4974307322782455600[121] = 0.0;
   out_4974307322782455600[122] = 0.0;
   out_4974307322782455600[123] = 0.0;
   out_4974307322782455600[124] = 0.0;
   out_4974307322782455600[125] = 0.0;
   out_4974307322782455600[126] = 0.0;
   out_4974307322782455600[127] = 0.0;
   out_4974307322782455600[128] = 0.0;
   out_4974307322782455600[129] = 0.0;
   out_4974307322782455600[130] = 0.0;
   out_4974307322782455600[131] = 0.0;
   out_4974307322782455600[132] = 0.0;
   out_4974307322782455600[133] = 1.0;
   out_4974307322782455600[134] = 0.0;
   out_4974307322782455600[135] = 0.0;
   out_4974307322782455600[136] = 0.0;
   out_4974307322782455600[137] = 0.0;
   out_4974307322782455600[138] = 0.0;
   out_4974307322782455600[139] = 0.0;
   out_4974307322782455600[140] = 0.0;
   out_4974307322782455600[141] = 0.0;
   out_4974307322782455600[142] = 0.0;
   out_4974307322782455600[143] = 0.0;
   out_4974307322782455600[144] = 0.0;
   out_4974307322782455600[145] = 0.0;
   out_4974307322782455600[146] = 0.0;
   out_4974307322782455600[147] = 0.0;
   out_4974307322782455600[148] = 0.0;
   out_4974307322782455600[149] = 0.0;
   out_4974307322782455600[150] = 0.0;
   out_4974307322782455600[151] = 0.0;
   out_4974307322782455600[152] = 1.0;
   out_4974307322782455600[153] = 0.0;
   out_4974307322782455600[154] = 0.0;
   out_4974307322782455600[155] = 0.0;
   out_4974307322782455600[156] = 0.0;
   out_4974307322782455600[157] = 0.0;
   out_4974307322782455600[158] = 0.0;
   out_4974307322782455600[159] = 0.0;
   out_4974307322782455600[160] = 0.0;
   out_4974307322782455600[161] = 0.0;
   out_4974307322782455600[162] = 0.0;
   out_4974307322782455600[163] = 0.0;
   out_4974307322782455600[164] = 0.0;
   out_4974307322782455600[165] = 0.0;
   out_4974307322782455600[166] = 0.0;
   out_4974307322782455600[167] = 0.0;
   out_4974307322782455600[168] = 0.0;
   out_4974307322782455600[169] = 0.0;
   out_4974307322782455600[170] = 0.0;
   out_4974307322782455600[171] = 1.0;
   out_4974307322782455600[172] = 0.0;
   out_4974307322782455600[173] = 0.0;
   out_4974307322782455600[174] = 0.0;
   out_4974307322782455600[175] = 0.0;
   out_4974307322782455600[176] = 0.0;
   out_4974307322782455600[177] = 0.0;
   out_4974307322782455600[178] = 0.0;
   out_4974307322782455600[179] = 0.0;
   out_4974307322782455600[180] = 0.0;
   out_4974307322782455600[181] = 0.0;
   out_4974307322782455600[182] = 0.0;
   out_4974307322782455600[183] = 0.0;
   out_4974307322782455600[184] = 0.0;
   out_4974307322782455600[185] = 0.0;
   out_4974307322782455600[186] = 0.0;
   out_4974307322782455600[187] = 0.0;
   out_4974307322782455600[188] = 0.0;
   out_4974307322782455600[189] = 0.0;
   out_4974307322782455600[190] = 1.0;
   out_4974307322782455600[191] = 0.0;
   out_4974307322782455600[192] = 0.0;
   out_4974307322782455600[193] = 0.0;
   out_4974307322782455600[194] = 0.0;
   out_4974307322782455600[195] = 0.0;
   out_4974307322782455600[196] = 0.0;
   out_4974307322782455600[197] = 0.0;
   out_4974307322782455600[198] = 0.0;
   out_4974307322782455600[199] = 0.0;
   out_4974307322782455600[200] = 0.0;
   out_4974307322782455600[201] = 0.0;
   out_4974307322782455600[202] = 0.0;
   out_4974307322782455600[203] = 0.0;
   out_4974307322782455600[204] = 0.0;
   out_4974307322782455600[205] = 0.0;
   out_4974307322782455600[206] = 0.0;
   out_4974307322782455600[207] = 0.0;
   out_4974307322782455600[208] = 0.0;
   out_4974307322782455600[209] = 1.0;
   out_4974307322782455600[210] = 0.0;
   out_4974307322782455600[211] = 0.0;
   out_4974307322782455600[212] = 0.0;
   out_4974307322782455600[213] = 0.0;
   out_4974307322782455600[214] = 0.0;
   out_4974307322782455600[215] = 0.0;
   out_4974307322782455600[216] = 0.0;
   out_4974307322782455600[217] = 0.0;
   out_4974307322782455600[218] = 0.0;
   out_4974307322782455600[219] = 0.0;
   out_4974307322782455600[220] = 0.0;
   out_4974307322782455600[221] = 0.0;
   out_4974307322782455600[222] = 0.0;
   out_4974307322782455600[223] = 0.0;
   out_4974307322782455600[224] = 0.0;
   out_4974307322782455600[225] = 0.0;
   out_4974307322782455600[226] = 0.0;
   out_4974307322782455600[227] = 0.0;
   out_4974307322782455600[228] = 1.0;
   out_4974307322782455600[229] = 0.0;
   out_4974307322782455600[230] = 0.0;
   out_4974307322782455600[231] = 0.0;
   out_4974307322782455600[232] = 0.0;
   out_4974307322782455600[233] = 0.0;
   out_4974307322782455600[234] = 0.0;
   out_4974307322782455600[235] = 0.0;
   out_4974307322782455600[236] = 0.0;
   out_4974307322782455600[237] = 0.0;
   out_4974307322782455600[238] = 0.0;
   out_4974307322782455600[239] = 0.0;
   out_4974307322782455600[240] = 0.0;
   out_4974307322782455600[241] = 0.0;
   out_4974307322782455600[242] = 0.0;
   out_4974307322782455600[243] = 0.0;
   out_4974307322782455600[244] = 0.0;
   out_4974307322782455600[245] = 0.0;
   out_4974307322782455600[246] = 0.0;
   out_4974307322782455600[247] = 1.0;
   out_4974307322782455600[248] = 0.0;
   out_4974307322782455600[249] = 0.0;
   out_4974307322782455600[250] = 0.0;
   out_4974307322782455600[251] = 0.0;
   out_4974307322782455600[252] = 0.0;
   out_4974307322782455600[253] = 0.0;
   out_4974307322782455600[254] = 0.0;
   out_4974307322782455600[255] = 0.0;
   out_4974307322782455600[256] = 0.0;
   out_4974307322782455600[257] = 0.0;
   out_4974307322782455600[258] = 0.0;
   out_4974307322782455600[259] = 0.0;
   out_4974307322782455600[260] = 0.0;
   out_4974307322782455600[261] = 0.0;
   out_4974307322782455600[262] = 0.0;
   out_4974307322782455600[263] = 0.0;
   out_4974307322782455600[264] = 0.0;
   out_4974307322782455600[265] = 0.0;
   out_4974307322782455600[266] = 1.0;
   out_4974307322782455600[267] = 0.0;
   out_4974307322782455600[268] = 0.0;
   out_4974307322782455600[269] = 0.0;
   out_4974307322782455600[270] = 0.0;
   out_4974307322782455600[271] = 0.0;
   out_4974307322782455600[272] = 0.0;
   out_4974307322782455600[273] = 0.0;
   out_4974307322782455600[274] = 0.0;
   out_4974307322782455600[275] = 0.0;
   out_4974307322782455600[276] = 0.0;
   out_4974307322782455600[277] = 0.0;
   out_4974307322782455600[278] = 0.0;
   out_4974307322782455600[279] = 0.0;
   out_4974307322782455600[280] = 0.0;
   out_4974307322782455600[281] = 0.0;
   out_4974307322782455600[282] = 0.0;
   out_4974307322782455600[283] = 0.0;
   out_4974307322782455600[284] = 0.0;
   out_4974307322782455600[285] = 1.0;
   out_4974307322782455600[286] = 0.0;
   out_4974307322782455600[287] = 0.0;
   out_4974307322782455600[288] = 0.0;
   out_4974307322782455600[289] = 0.0;
   out_4974307322782455600[290] = 0.0;
   out_4974307322782455600[291] = 0.0;
   out_4974307322782455600[292] = 0.0;
   out_4974307322782455600[293] = 0.0;
   out_4974307322782455600[294] = 0.0;
   out_4974307322782455600[295] = 0.0;
   out_4974307322782455600[296] = 0.0;
   out_4974307322782455600[297] = 0.0;
   out_4974307322782455600[298] = 0.0;
   out_4974307322782455600[299] = 0.0;
   out_4974307322782455600[300] = 0.0;
   out_4974307322782455600[301] = 0.0;
   out_4974307322782455600[302] = 0.0;
   out_4974307322782455600[303] = 0.0;
   out_4974307322782455600[304] = 1.0;
   out_4974307322782455600[305] = 0.0;
   out_4974307322782455600[306] = 0.0;
   out_4974307322782455600[307] = 0.0;
   out_4974307322782455600[308] = 0.0;
   out_4974307322782455600[309] = 0.0;
   out_4974307322782455600[310] = 0.0;
   out_4974307322782455600[311] = 0.0;
   out_4974307322782455600[312] = 0.0;
   out_4974307322782455600[313] = 0.0;
   out_4974307322782455600[314] = 0.0;
   out_4974307322782455600[315] = 0.0;
   out_4974307322782455600[316] = 0.0;
   out_4974307322782455600[317] = 0.0;
   out_4974307322782455600[318] = 0.0;
   out_4974307322782455600[319] = 0.0;
   out_4974307322782455600[320] = 0.0;
   out_4974307322782455600[321] = 0.0;
   out_4974307322782455600[322] = 0.0;
   out_4974307322782455600[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1104587078015232117) {
   out_1104587078015232117[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1104587078015232117[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1104587078015232117[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1104587078015232117[3] = dt*state[12] + state[3];
   out_1104587078015232117[4] = dt*state[13] + state[4];
   out_1104587078015232117[5] = dt*state[14] + state[5];
   out_1104587078015232117[6] = state[6];
   out_1104587078015232117[7] = state[7];
   out_1104587078015232117[8] = state[8];
   out_1104587078015232117[9] = state[9];
   out_1104587078015232117[10] = state[10];
   out_1104587078015232117[11] = state[11];
   out_1104587078015232117[12] = state[12];
   out_1104587078015232117[13] = state[13];
   out_1104587078015232117[14] = state[14];
   out_1104587078015232117[15] = state[15];
   out_1104587078015232117[16] = state[16];
   out_1104587078015232117[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5293033715763511365) {
   out_5293033715763511365[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5293033715763511365[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5293033715763511365[2] = 0;
   out_5293033715763511365[3] = 0;
   out_5293033715763511365[4] = 0;
   out_5293033715763511365[5] = 0;
   out_5293033715763511365[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5293033715763511365[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5293033715763511365[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5293033715763511365[9] = 0;
   out_5293033715763511365[10] = 0;
   out_5293033715763511365[11] = 0;
   out_5293033715763511365[12] = 0;
   out_5293033715763511365[13] = 0;
   out_5293033715763511365[14] = 0;
   out_5293033715763511365[15] = 0;
   out_5293033715763511365[16] = 0;
   out_5293033715763511365[17] = 0;
   out_5293033715763511365[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5293033715763511365[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5293033715763511365[20] = 0;
   out_5293033715763511365[21] = 0;
   out_5293033715763511365[22] = 0;
   out_5293033715763511365[23] = 0;
   out_5293033715763511365[24] = 0;
   out_5293033715763511365[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5293033715763511365[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5293033715763511365[27] = 0;
   out_5293033715763511365[28] = 0;
   out_5293033715763511365[29] = 0;
   out_5293033715763511365[30] = 0;
   out_5293033715763511365[31] = 0;
   out_5293033715763511365[32] = 0;
   out_5293033715763511365[33] = 0;
   out_5293033715763511365[34] = 0;
   out_5293033715763511365[35] = 0;
   out_5293033715763511365[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5293033715763511365[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5293033715763511365[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5293033715763511365[39] = 0;
   out_5293033715763511365[40] = 0;
   out_5293033715763511365[41] = 0;
   out_5293033715763511365[42] = 0;
   out_5293033715763511365[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5293033715763511365[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5293033715763511365[45] = 0;
   out_5293033715763511365[46] = 0;
   out_5293033715763511365[47] = 0;
   out_5293033715763511365[48] = 0;
   out_5293033715763511365[49] = 0;
   out_5293033715763511365[50] = 0;
   out_5293033715763511365[51] = 0;
   out_5293033715763511365[52] = 0;
   out_5293033715763511365[53] = 0;
   out_5293033715763511365[54] = 0;
   out_5293033715763511365[55] = 0;
   out_5293033715763511365[56] = 0;
   out_5293033715763511365[57] = 1;
   out_5293033715763511365[58] = 0;
   out_5293033715763511365[59] = 0;
   out_5293033715763511365[60] = 0;
   out_5293033715763511365[61] = 0;
   out_5293033715763511365[62] = 0;
   out_5293033715763511365[63] = 0;
   out_5293033715763511365[64] = 0;
   out_5293033715763511365[65] = 0;
   out_5293033715763511365[66] = dt;
   out_5293033715763511365[67] = 0;
   out_5293033715763511365[68] = 0;
   out_5293033715763511365[69] = 0;
   out_5293033715763511365[70] = 0;
   out_5293033715763511365[71] = 0;
   out_5293033715763511365[72] = 0;
   out_5293033715763511365[73] = 0;
   out_5293033715763511365[74] = 0;
   out_5293033715763511365[75] = 0;
   out_5293033715763511365[76] = 1;
   out_5293033715763511365[77] = 0;
   out_5293033715763511365[78] = 0;
   out_5293033715763511365[79] = 0;
   out_5293033715763511365[80] = 0;
   out_5293033715763511365[81] = 0;
   out_5293033715763511365[82] = 0;
   out_5293033715763511365[83] = 0;
   out_5293033715763511365[84] = 0;
   out_5293033715763511365[85] = dt;
   out_5293033715763511365[86] = 0;
   out_5293033715763511365[87] = 0;
   out_5293033715763511365[88] = 0;
   out_5293033715763511365[89] = 0;
   out_5293033715763511365[90] = 0;
   out_5293033715763511365[91] = 0;
   out_5293033715763511365[92] = 0;
   out_5293033715763511365[93] = 0;
   out_5293033715763511365[94] = 0;
   out_5293033715763511365[95] = 1;
   out_5293033715763511365[96] = 0;
   out_5293033715763511365[97] = 0;
   out_5293033715763511365[98] = 0;
   out_5293033715763511365[99] = 0;
   out_5293033715763511365[100] = 0;
   out_5293033715763511365[101] = 0;
   out_5293033715763511365[102] = 0;
   out_5293033715763511365[103] = 0;
   out_5293033715763511365[104] = dt;
   out_5293033715763511365[105] = 0;
   out_5293033715763511365[106] = 0;
   out_5293033715763511365[107] = 0;
   out_5293033715763511365[108] = 0;
   out_5293033715763511365[109] = 0;
   out_5293033715763511365[110] = 0;
   out_5293033715763511365[111] = 0;
   out_5293033715763511365[112] = 0;
   out_5293033715763511365[113] = 0;
   out_5293033715763511365[114] = 1;
   out_5293033715763511365[115] = 0;
   out_5293033715763511365[116] = 0;
   out_5293033715763511365[117] = 0;
   out_5293033715763511365[118] = 0;
   out_5293033715763511365[119] = 0;
   out_5293033715763511365[120] = 0;
   out_5293033715763511365[121] = 0;
   out_5293033715763511365[122] = 0;
   out_5293033715763511365[123] = 0;
   out_5293033715763511365[124] = 0;
   out_5293033715763511365[125] = 0;
   out_5293033715763511365[126] = 0;
   out_5293033715763511365[127] = 0;
   out_5293033715763511365[128] = 0;
   out_5293033715763511365[129] = 0;
   out_5293033715763511365[130] = 0;
   out_5293033715763511365[131] = 0;
   out_5293033715763511365[132] = 0;
   out_5293033715763511365[133] = 1;
   out_5293033715763511365[134] = 0;
   out_5293033715763511365[135] = 0;
   out_5293033715763511365[136] = 0;
   out_5293033715763511365[137] = 0;
   out_5293033715763511365[138] = 0;
   out_5293033715763511365[139] = 0;
   out_5293033715763511365[140] = 0;
   out_5293033715763511365[141] = 0;
   out_5293033715763511365[142] = 0;
   out_5293033715763511365[143] = 0;
   out_5293033715763511365[144] = 0;
   out_5293033715763511365[145] = 0;
   out_5293033715763511365[146] = 0;
   out_5293033715763511365[147] = 0;
   out_5293033715763511365[148] = 0;
   out_5293033715763511365[149] = 0;
   out_5293033715763511365[150] = 0;
   out_5293033715763511365[151] = 0;
   out_5293033715763511365[152] = 1;
   out_5293033715763511365[153] = 0;
   out_5293033715763511365[154] = 0;
   out_5293033715763511365[155] = 0;
   out_5293033715763511365[156] = 0;
   out_5293033715763511365[157] = 0;
   out_5293033715763511365[158] = 0;
   out_5293033715763511365[159] = 0;
   out_5293033715763511365[160] = 0;
   out_5293033715763511365[161] = 0;
   out_5293033715763511365[162] = 0;
   out_5293033715763511365[163] = 0;
   out_5293033715763511365[164] = 0;
   out_5293033715763511365[165] = 0;
   out_5293033715763511365[166] = 0;
   out_5293033715763511365[167] = 0;
   out_5293033715763511365[168] = 0;
   out_5293033715763511365[169] = 0;
   out_5293033715763511365[170] = 0;
   out_5293033715763511365[171] = 1;
   out_5293033715763511365[172] = 0;
   out_5293033715763511365[173] = 0;
   out_5293033715763511365[174] = 0;
   out_5293033715763511365[175] = 0;
   out_5293033715763511365[176] = 0;
   out_5293033715763511365[177] = 0;
   out_5293033715763511365[178] = 0;
   out_5293033715763511365[179] = 0;
   out_5293033715763511365[180] = 0;
   out_5293033715763511365[181] = 0;
   out_5293033715763511365[182] = 0;
   out_5293033715763511365[183] = 0;
   out_5293033715763511365[184] = 0;
   out_5293033715763511365[185] = 0;
   out_5293033715763511365[186] = 0;
   out_5293033715763511365[187] = 0;
   out_5293033715763511365[188] = 0;
   out_5293033715763511365[189] = 0;
   out_5293033715763511365[190] = 1;
   out_5293033715763511365[191] = 0;
   out_5293033715763511365[192] = 0;
   out_5293033715763511365[193] = 0;
   out_5293033715763511365[194] = 0;
   out_5293033715763511365[195] = 0;
   out_5293033715763511365[196] = 0;
   out_5293033715763511365[197] = 0;
   out_5293033715763511365[198] = 0;
   out_5293033715763511365[199] = 0;
   out_5293033715763511365[200] = 0;
   out_5293033715763511365[201] = 0;
   out_5293033715763511365[202] = 0;
   out_5293033715763511365[203] = 0;
   out_5293033715763511365[204] = 0;
   out_5293033715763511365[205] = 0;
   out_5293033715763511365[206] = 0;
   out_5293033715763511365[207] = 0;
   out_5293033715763511365[208] = 0;
   out_5293033715763511365[209] = 1;
   out_5293033715763511365[210] = 0;
   out_5293033715763511365[211] = 0;
   out_5293033715763511365[212] = 0;
   out_5293033715763511365[213] = 0;
   out_5293033715763511365[214] = 0;
   out_5293033715763511365[215] = 0;
   out_5293033715763511365[216] = 0;
   out_5293033715763511365[217] = 0;
   out_5293033715763511365[218] = 0;
   out_5293033715763511365[219] = 0;
   out_5293033715763511365[220] = 0;
   out_5293033715763511365[221] = 0;
   out_5293033715763511365[222] = 0;
   out_5293033715763511365[223] = 0;
   out_5293033715763511365[224] = 0;
   out_5293033715763511365[225] = 0;
   out_5293033715763511365[226] = 0;
   out_5293033715763511365[227] = 0;
   out_5293033715763511365[228] = 1;
   out_5293033715763511365[229] = 0;
   out_5293033715763511365[230] = 0;
   out_5293033715763511365[231] = 0;
   out_5293033715763511365[232] = 0;
   out_5293033715763511365[233] = 0;
   out_5293033715763511365[234] = 0;
   out_5293033715763511365[235] = 0;
   out_5293033715763511365[236] = 0;
   out_5293033715763511365[237] = 0;
   out_5293033715763511365[238] = 0;
   out_5293033715763511365[239] = 0;
   out_5293033715763511365[240] = 0;
   out_5293033715763511365[241] = 0;
   out_5293033715763511365[242] = 0;
   out_5293033715763511365[243] = 0;
   out_5293033715763511365[244] = 0;
   out_5293033715763511365[245] = 0;
   out_5293033715763511365[246] = 0;
   out_5293033715763511365[247] = 1;
   out_5293033715763511365[248] = 0;
   out_5293033715763511365[249] = 0;
   out_5293033715763511365[250] = 0;
   out_5293033715763511365[251] = 0;
   out_5293033715763511365[252] = 0;
   out_5293033715763511365[253] = 0;
   out_5293033715763511365[254] = 0;
   out_5293033715763511365[255] = 0;
   out_5293033715763511365[256] = 0;
   out_5293033715763511365[257] = 0;
   out_5293033715763511365[258] = 0;
   out_5293033715763511365[259] = 0;
   out_5293033715763511365[260] = 0;
   out_5293033715763511365[261] = 0;
   out_5293033715763511365[262] = 0;
   out_5293033715763511365[263] = 0;
   out_5293033715763511365[264] = 0;
   out_5293033715763511365[265] = 0;
   out_5293033715763511365[266] = 1;
   out_5293033715763511365[267] = 0;
   out_5293033715763511365[268] = 0;
   out_5293033715763511365[269] = 0;
   out_5293033715763511365[270] = 0;
   out_5293033715763511365[271] = 0;
   out_5293033715763511365[272] = 0;
   out_5293033715763511365[273] = 0;
   out_5293033715763511365[274] = 0;
   out_5293033715763511365[275] = 0;
   out_5293033715763511365[276] = 0;
   out_5293033715763511365[277] = 0;
   out_5293033715763511365[278] = 0;
   out_5293033715763511365[279] = 0;
   out_5293033715763511365[280] = 0;
   out_5293033715763511365[281] = 0;
   out_5293033715763511365[282] = 0;
   out_5293033715763511365[283] = 0;
   out_5293033715763511365[284] = 0;
   out_5293033715763511365[285] = 1;
   out_5293033715763511365[286] = 0;
   out_5293033715763511365[287] = 0;
   out_5293033715763511365[288] = 0;
   out_5293033715763511365[289] = 0;
   out_5293033715763511365[290] = 0;
   out_5293033715763511365[291] = 0;
   out_5293033715763511365[292] = 0;
   out_5293033715763511365[293] = 0;
   out_5293033715763511365[294] = 0;
   out_5293033715763511365[295] = 0;
   out_5293033715763511365[296] = 0;
   out_5293033715763511365[297] = 0;
   out_5293033715763511365[298] = 0;
   out_5293033715763511365[299] = 0;
   out_5293033715763511365[300] = 0;
   out_5293033715763511365[301] = 0;
   out_5293033715763511365[302] = 0;
   out_5293033715763511365[303] = 0;
   out_5293033715763511365[304] = 1;
   out_5293033715763511365[305] = 0;
   out_5293033715763511365[306] = 0;
   out_5293033715763511365[307] = 0;
   out_5293033715763511365[308] = 0;
   out_5293033715763511365[309] = 0;
   out_5293033715763511365[310] = 0;
   out_5293033715763511365[311] = 0;
   out_5293033715763511365[312] = 0;
   out_5293033715763511365[313] = 0;
   out_5293033715763511365[314] = 0;
   out_5293033715763511365[315] = 0;
   out_5293033715763511365[316] = 0;
   out_5293033715763511365[317] = 0;
   out_5293033715763511365[318] = 0;
   out_5293033715763511365[319] = 0;
   out_5293033715763511365[320] = 0;
   out_5293033715763511365[321] = 0;
   out_5293033715763511365[322] = 0;
   out_5293033715763511365[323] = 1;
}
void h_4(double *state, double *unused, double *out_5228726973950769986) {
   out_5228726973950769986[0] = state[6] + state[9];
   out_5228726973950769986[1] = state[7] + state[10];
   out_5228726973950769986[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3032303058814960921) {
   out_3032303058814960921[0] = 0;
   out_3032303058814960921[1] = 0;
   out_3032303058814960921[2] = 0;
   out_3032303058814960921[3] = 0;
   out_3032303058814960921[4] = 0;
   out_3032303058814960921[5] = 0;
   out_3032303058814960921[6] = 1;
   out_3032303058814960921[7] = 0;
   out_3032303058814960921[8] = 0;
   out_3032303058814960921[9] = 1;
   out_3032303058814960921[10] = 0;
   out_3032303058814960921[11] = 0;
   out_3032303058814960921[12] = 0;
   out_3032303058814960921[13] = 0;
   out_3032303058814960921[14] = 0;
   out_3032303058814960921[15] = 0;
   out_3032303058814960921[16] = 0;
   out_3032303058814960921[17] = 0;
   out_3032303058814960921[18] = 0;
   out_3032303058814960921[19] = 0;
   out_3032303058814960921[20] = 0;
   out_3032303058814960921[21] = 0;
   out_3032303058814960921[22] = 0;
   out_3032303058814960921[23] = 0;
   out_3032303058814960921[24] = 0;
   out_3032303058814960921[25] = 1;
   out_3032303058814960921[26] = 0;
   out_3032303058814960921[27] = 0;
   out_3032303058814960921[28] = 1;
   out_3032303058814960921[29] = 0;
   out_3032303058814960921[30] = 0;
   out_3032303058814960921[31] = 0;
   out_3032303058814960921[32] = 0;
   out_3032303058814960921[33] = 0;
   out_3032303058814960921[34] = 0;
   out_3032303058814960921[35] = 0;
   out_3032303058814960921[36] = 0;
   out_3032303058814960921[37] = 0;
   out_3032303058814960921[38] = 0;
   out_3032303058814960921[39] = 0;
   out_3032303058814960921[40] = 0;
   out_3032303058814960921[41] = 0;
   out_3032303058814960921[42] = 0;
   out_3032303058814960921[43] = 0;
   out_3032303058814960921[44] = 1;
   out_3032303058814960921[45] = 0;
   out_3032303058814960921[46] = 0;
   out_3032303058814960921[47] = 1;
   out_3032303058814960921[48] = 0;
   out_3032303058814960921[49] = 0;
   out_3032303058814960921[50] = 0;
   out_3032303058814960921[51] = 0;
   out_3032303058814960921[52] = 0;
   out_3032303058814960921[53] = 0;
}
void h_10(double *state, double *unused, double *out_122492238844625391) {
   out_122492238844625391[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_122492238844625391[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_122492238844625391[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4293959578107599330) {
   out_4293959578107599330[0] = 0;
   out_4293959578107599330[1] = 9.8100000000000005*cos(state[1]);
   out_4293959578107599330[2] = 0;
   out_4293959578107599330[3] = 0;
   out_4293959578107599330[4] = -state[8];
   out_4293959578107599330[5] = state[7];
   out_4293959578107599330[6] = 0;
   out_4293959578107599330[7] = state[5];
   out_4293959578107599330[8] = -state[4];
   out_4293959578107599330[9] = 0;
   out_4293959578107599330[10] = 0;
   out_4293959578107599330[11] = 0;
   out_4293959578107599330[12] = 1;
   out_4293959578107599330[13] = 0;
   out_4293959578107599330[14] = 0;
   out_4293959578107599330[15] = 1;
   out_4293959578107599330[16] = 0;
   out_4293959578107599330[17] = 0;
   out_4293959578107599330[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4293959578107599330[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4293959578107599330[20] = 0;
   out_4293959578107599330[21] = state[8];
   out_4293959578107599330[22] = 0;
   out_4293959578107599330[23] = -state[6];
   out_4293959578107599330[24] = -state[5];
   out_4293959578107599330[25] = 0;
   out_4293959578107599330[26] = state[3];
   out_4293959578107599330[27] = 0;
   out_4293959578107599330[28] = 0;
   out_4293959578107599330[29] = 0;
   out_4293959578107599330[30] = 0;
   out_4293959578107599330[31] = 1;
   out_4293959578107599330[32] = 0;
   out_4293959578107599330[33] = 0;
   out_4293959578107599330[34] = 1;
   out_4293959578107599330[35] = 0;
   out_4293959578107599330[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4293959578107599330[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4293959578107599330[38] = 0;
   out_4293959578107599330[39] = -state[7];
   out_4293959578107599330[40] = state[6];
   out_4293959578107599330[41] = 0;
   out_4293959578107599330[42] = state[4];
   out_4293959578107599330[43] = -state[3];
   out_4293959578107599330[44] = 0;
   out_4293959578107599330[45] = 0;
   out_4293959578107599330[46] = 0;
   out_4293959578107599330[47] = 0;
   out_4293959578107599330[48] = 0;
   out_4293959578107599330[49] = 0;
   out_4293959578107599330[50] = 1;
   out_4293959578107599330[51] = 0;
   out_4293959578107599330[52] = 0;
   out_4293959578107599330[53] = 1;
}
void h_13(double *state, double *unused, double *out_4688840231226545336) {
   out_4688840231226545336[0] = state[3];
   out_4688840231226545336[1] = state[4];
   out_4688840231226545336[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7803809806577889766) {
   out_7803809806577889766[0] = 0;
   out_7803809806577889766[1] = 0;
   out_7803809806577889766[2] = 0;
   out_7803809806577889766[3] = 1;
   out_7803809806577889766[4] = 0;
   out_7803809806577889766[5] = 0;
   out_7803809806577889766[6] = 0;
   out_7803809806577889766[7] = 0;
   out_7803809806577889766[8] = 0;
   out_7803809806577889766[9] = 0;
   out_7803809806577889766[10] = 0;
   out_7803809806577889766[11] = 0;
   out_7803809806577889766[12] = 0;
   out_7803809806577889766[13] = 0;
   out_7803809806577889766[14] = 0;
   out_7803809806577889766[15] = 0;
   out_7803809806577889766[16] = 0;
   out_7803809806577889766[17] = 0;
   out_7803809806577889766[18] = 0;
   out_7803809806577889766[19] = 0;
   out_7803809806577889766[20] = 0;
   out_7803809806577889766[21] = 0;
   out_7803809806577889766[22] = 1;
   out_7803809806577889766[23] = 0;
   out_7803809806577889766[24] = 0;
   out_7803809806577889766[25] = 0;
   out_7803809806577889766[26] = 0;
   out_7803809806577889766[27] = 0;
   out_7803809806577889766[28] = 0;
   out_7803809806577889766[29] = 0;
   out_7803809806577889766[30] = 0;
   out_7803809806577889766[31] = 0;
   out_7803809806577889766[32] = 0;
   out_7803809806577889766[33] = 0;
   out_7803809806577889766[34] = 0;
   out_7803809806577889766[35] = 0;
   out_7803809806577889766[36] = 0;
   out_7803809806577889766[37] = 0;
   out_7803809806577889766[38] = 0;
   out_7803809806577889766[39] = 0;
   out_7803809806577889766[40] = 0;
   out_7803809806577889766[41] = 1;
   out_7803809806577889766[42] = 0;
   out_7803809806577889766[43] = 0;
   out_7803809806577889766[44] = 0;
   out_7803809806577889766[45] = 0;
   out_7803809806577889766[46] = 0;
   out_7803809806577889766[47] = 0;
   out_7803809806577889766[48] = 0;
   out_7803809806577889766[49] = 0;
   out_7803809806577889766[50] = 0;
   out_7803809806577889766[51] = 0;
   out_7803809806577889766[52] = 0;
   out_7803809806577889766[53] = 0;
}
void h_14(double *state, double *unused, double *out_5111785488402772162) {
   out_5111785488402772162[0] = state[6];
   out_5111785488402772162[1] = state[7];
   out_5111785488402772162[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6995543915154445450) {
   out_6995543915154445450[0] = 0;
   out_6995543915154445450[1] = 0;
   out_6995543915154445450[2] = 0;
   out_6995543915154445450[3] = 0;
   out_6995543915154445450[4] = 0;
   out_6995543915154445450[5] = 0;
   out_6995543915154445450[6] = 1;
   out_6995543915154445450[7] = 0;
   out_6995543915154445450[8] = 0;
   out_6995543915154445450[9] = 0;
   out_6995543915154445450[10] = 0;
   out_6995543915154445450[11] = 0;
   out_6995543915154445450[12] = 0;
   out_6995543915154445450[13] = 0;
   out_6995543915154445450[14] = 0;
   out_6995543915154445450[15] = 0;
   out_6995543915154445450[16] = 0;
   out_6995543915154445450[17] = 0;
   out_6995543915154445450[18] = 0;
   out_6995543915154445450[19] = 0;
   out_6995543915154445450[20] = 0;
   out_6995543915154445450[21] = 0;
   out_6995543915154445450[22] = 0;
   out_6995543915154445450[23] = 0;
   out_6995543915154445450[24] = 0;
   out_6995543915154445450[25] = 1;
   out_6995543915154445450[26] = 0;
   out_6995543915154445450[27] = 0;
   out_6995543915154445450[28] = 0;
   out_6995543915154445450[29] = 0;
   out_6995543915154445450[30] = 0;
   out_6995543915154445450[31] = 0;
   out_6995543915154445450[32] = 0;
   out_6995543915154445450[33] = 0;
   out_6995543915154445450[34] = 0;
   out_6995543915154445450[35] = 0;
   out_6995543915154445450[36] = 0;
   out_6995543915154445450[37] = 0;
   out_6995543915154445450[38] = 0;
   out_6995543915154445450[39] = 0;
   out_6995543915154445450[40] = 0;
   out_6995543915154445450[41] = 0;
   out_6995543915154445450[42] = 0;
   out_6995543915154445450[43] = 0;
   out_6995543915154445450[44] = 1;
   out_6995543915154445450[45] = 0;
   out_6995543915154445450[46] = 0;
   out_6995543915154445450[47] = 0;
   out_6995543915154445450[48] = 0;
   out_6995543915154445450[49] = 0;
   out_6995543915154445450[50] = 0;
   out_6995543915154445450[51] = 0;
   out_6995543915154445450[52] = 0;
   out_6995543915154445450[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_772147526555487692) {
  err_fun(nom_x, delta_x, out_772147526555487692);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4282924253332717604) {
  inv_err_fun(nom_x, true_x, out_4282924253332717604);
}
void pose_H_mod_fun(double *state, double *out_4974307322782455600) {
  H_mod_fun(state, out_4974307322782455600);
}
void pose_f_fun(double *state, double dt, double *out_1104587078015232117) {
  f_fun(state,  dt, out_1104587078015232117);
}
void pose_F_fun(double *state, double dt, double *out_5293033715763511365) {
  F_fun(state,  dt, out_5293033715763511365);
}
void pose_h_4(double *state, double *unused, double *out_5228726973950769986) {
  h_4(state, unused, out_5228726973950769986);
}
void pose_H_4(double *state, double *unused, double *out_3032303058814960921) {
  H_4(state, unused, out_3032303058814960921);
}
void pose_h_10(double *state, double *unused, double *out_122492238844625391) {
  h_10(state, unused, out_122492238844625391);
}
void pose_H_10(double *state, double *unused, double *out_4293959578107599330) {
  H_10(state, unused, out_4293959578107599330);
}
void pose_h_13(double *state, double *unused, double *out_4688840231226545336) {
  h_13(state, unused, out_4688840231226545336);
}
void pose_H_13(double *state, double *unused, double *out_7803809806577889766) {
  H_13(state, unused, out_7803809806577889766);
}
void pose_h_14(double *state, double *unused, double *out_5111785488402772162) {
  h_14(state, unused, out_5111785488402772162);
}
void pose_H_14(double *state, double *unused, double *out_6995543915154445450) {
  H_14(state, unused, out_6995543915154445450);
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
