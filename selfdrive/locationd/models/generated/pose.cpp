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
void err_fun(double *nom_x, double *delta_x, double *out_2717418772724129561) {
   out_2717418772724129561[0] = delta_x[0] + nom_x[0];
   out_2717418772724129561[1] = delta_x[1] + nom_x[1];
   out_2717418772724129561[2] = delta_x[2] + nom_x[2];
   out_2717418772724129561[3] = delta_x[3] + nom_x[3];
   out_2717418772724129561[4] = delta_x[4] + nom_x[4];
   out_2717418772724129561[5] = delta_x[5] + nom_x[5];
   out_2717418772724129561[6] = delta_x[6] + nom_x[6];
   out_2717418772724129561[7] = delta_x[7] + nom_x[7];
   out_2717418772724129561[8] = delta_x[8] + nom_x[8];
   out_2717418772724129561[9] = delta_x[9] + nom_x[9];
   out_2717418772724129561[10] = delta_x[10] + nom_x[10];
   out_2717418772724129561[11] = delta_x[11] + nom_x[11];
   out_2717418772724129561[12] = delta_x[12] + nom_x[12];
   out_2717418772724129561[13] = delta_x[13] + nom_x[13];
   out_2717418772724129561[14] = delta_x[14] + nom_x[14];
   out_2717418772724129561[15] = delta_x[15] + nom_x[15];
   out_2717418772724129561[16] = delta_x[16] + nom_x[16];
   out_2717418772724129561[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6564594974930648805) {
   out_6564594974930648805[0] = -nom_x[0] + true_x[0];
   out_6564594974930648805[1] = -nom_x[1] + true_x[1];
   out_6564594974930648805[2] = -nom_x[2] + true_x[2];
   out_6564594974930648805[3] = -nom_x[3] + true_x[3];
   out_6564594974930648805[4] = -nom_x[4] + true_x[4];
   out_6564594974930648805[5] = -nom_x[5] + true_x[5];
   out_6564594974930648805[6] = -nom_x[6] + true_x[6];
   out_6564594974930648805[7] = -nom_x[7] + true_x[7];
   out_6564594974930648805[8] = -nom_x[8] + true_x[8];
   out_6564594974930648805[9] = -nom_x[9] + true_x[9];
   out_6564594974930648805[10] = -nom_x[10] + true_x[10];
   out_6564594974930648805[11] = -nom_x[11] + true_x[11];
   out_6564594974930648805[12] = -nom_x[12] + true_x[12];
   out_6564594974930648805[13] = -nom_x[13] + true_x[13];
   out_6564594974930648805[14] = -nom_x[14] + true_x[14];
   out_6564594974930648805[15] = -nom_x[15] + true_x[15];
   out_6564594974930648805[16] = -nom_x[16] + true_x[16];
   out_6564594974930648805[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_500884218142268447) {
   out_500884218142268447[0] = 1.0;
   out_500884218142268447[1] = 0.0;
   out_500884218142268447[2] = 0.0;
   out_500884218142268447[3] = 0.0;
   out_500884218142268447[4] = 0.0;
   out_500884218142268447[5] = 0.0;
   out_500884218142268447[6] = 0.0;
   out_500884218142268447[7] = 0.0;
   out_500884218142268447[8] = 0.0;
   out_500884218142268447[9] = 0.0;
   out_500884218142268447[10] = 0.0;
   out_500884218142268447[11] = 0.0;
   out_500884218142268447[12] = 0.0;
   out_500884218142268447[13] = 0.0;
   out_500884218142268447[14] = 0.0;
   out_500884218142268447[15] = 0.0;
   out_500884218142268447[16] = 0.0;
   out_500884218142268447[17] = 0.0;
   out_500884218142268447[18] = 0.0;
   out_500884218142268447[19] = 1.0;
   out_500884218142268447[20] = 0.0;
   out_500884218142268447[21] = 0.0;
   out_500884218142268447[22] = 0.0;
   out_500884218142268447[23] = 0.0;
   out_500884218142268447[24] = 0.0;
   out_500884218142268447[25] = 0.0;
   out_500884218142268447[26] = 0.0;
   out_500884218142268447[27] = 0.0;
   out_500884218142268447[28] = 0.0;
   out_500884218142268447[29] = 0.0;
   out_500884218142268447[30] = 0.0;
   out_500884218142268447[31] = 0.0;
   out_500884218142268447[32] = 0.0;
   out_500884218142268447[33] = 0.0;
   out_500884218142268447[34] = 0.0;
   out_500884218142268447[35] = 0.0;
   out_500884218142268447[36] = 0.0;
   out_500884218142268447[37] = 0.0;
   out_500884218142268447[38] = 1.0;
   out_500884218142268447[39] = 0.0;
   out_500884218142268447[40] = 0.0;
   out_500884218142268447[41] = 0.0;
   out_500884218142268447[42] = 0.0;
   out_500884218142268447[43] = 0.0;
   out_500884218142268447[44] = 0.0;
   out_500884218142268447[45] = 0.0;
   out_500884218142268447[46] = 0.0;
   out_500884218142268447[47] = 0.0;
   out_500884218142268447[48] = 0.0;
   out_500884218142268447[49] = 0.0;
   out_500884218142268447[50] = 0.0;
   out_500884218142268447[51] = 0.0;
   out_500884218142268447[52] = 0.0;
   out_500884218142268447[53] = 0.0;
   out_500884218142268447[54] = 0.0;
   out_500884218142268447[55] = 0.0;
   out_500884218142268447[56] = 0.0;
   out_500884218142268447[57] = 1.0;
   out_500884218142268447[58] = 0.0;
   out_500884218142268447[59] = 0.0;
   out_500884218142268447[60] = 0.0;
   out_500884218142268447[61] = 0.0;
   out_500884218142268447[62] = 0.0;
   out_500884218142268447[63] = 0.0;
   out_500884218142268447[64] = 0.0;
   out_500884218142268447[65] = 0.0;
   out_500884218142268447[66] = 0.0;
   out_500884218142268447[67] = 0.0;
   out_500884218142268447[68] = 0.0;
   out_500884218142268447[69] = 0.0;
   out_500884218142268447[70] = 0.0;
   out_500884218142268447[71] = 0.0;
   out_500884218142268447[72] = 0.0;
   out_500884218142268447[73] = 0.0;
   out_500884218142268447[74] = 0.0;
   out_500884218142268447[75] = 0.0;
   out_500884218142268447[76] = 1.0;
   out_500884218142268447[77] = 0.0;
   out_500884218142268447[78] = 0.0;
   out_500884218142268447[79] = 0.0;
   out_500884218142268447[80] = 0.0;
   out_500884218142268447[81] = 0.0;
   out_500884218142268447[82] = 0.0;
   out_500884218142268447[83] = 0.0;
   out_500884218142268447[84] = 0.0;
   out_500884218142268447[85] = 0.0;
   out_500884218142268447[86] = 0.0;
   out_500884218142268447[87] = 0.0;
   out_500884218142268447[88] = 0.0;
   out_500884218142268447[89] = 0.0;
   out_500884218142268447[90] = 0.0;
   out_500884218142268447[91] = 0.0;
   out_500884218142268447[92] = 0.0;
   out_500884218142268447[93] = 0.0;
   out_500884218142268447[94] = 0.0;
   out_500884218142268447[95] = 1.0;
   out_500884218142268447[96] = 0.0;
   out_500884218142268447[97] = 0.0;
   out_500884218142268447[98] = 0.0;
   out_500884218142268447[99] = 0.0;
   out_500884218142268447[100] = 0.0;
   out_500884218142268447[101] = 0.0;
   out_500884218142268447[102] = 0.0;
   out_500884218142268447[103] = 0.0;
   out_500884218142268447[104] = 0.0;
   out_500884218142268447[105] = 0.0;
   out_500884218142268447[106] = 0.0;
   out_500884218142268447[107] = 0.0;
   out_500884218142268447[108] = 0.0;
   out_500884218142268447[109] = 0.0;
   out_500884218142268447[110] = 0.0;
   out_500884218142268447[111] = 0.0;
   out_500884218142268447[112] = 0.0;
   out_500884218142268447[113] = 0.0;
   out_500884218142268447[114] = 1.0;
   out_500884218142268447[115] = 0.0;
   out_500884218142268447[116] = 0.0;
   out_500884218142268447[117] = 0.0;
   out_500884218142268447[118] = 0.0;
   out_500884218142268447[119] = 0.0;
   out_500884218142268447[120] = 0.0;
   out_500884218142268447[121] = 0.0;
   out_500884218142268447[122] = 0.0;
   out_500884218142268447[123] = 0.0;
   out_500884218142268447[124] = 0.0;
   out_500884218142268447[125] = 0.0;
   out_500884218142268447[126] = 0.0;
   out_500884218142268447[127] = 0.0;
   out_500884218142268447[128] = 0.0;
   out_500884218142268447[129] = 0.0;
   out_500884218142268447[130] = 0.0;
   out_500884218142268447[131] = 0.0;
   out_500884218142268447[132] = 0.0;
   out_500884218142268447[133] = 1.0;
   out_500884218142268447[134] = 0.0;
   out_500884218142268447[135] = 0.0;
   out_500884218142268447[136] = 0.0;
   out_500884218142268447[137] = 0.0;
   out_500884218142268447[138] = 0.0;
   out_500884218142268447[139] = 0.0;
   out_500884218142268447[140] = 0.0;
   out_500884218142268447[141] = 0.0;
   out_500884218142268447[142] = 0.0;
   out_500884218142268447[143] = 0.0;
   out_500884218142268447[144] = 0.0;
   out_500884218142268447[145] = 0.0;
   out_500884218142268447[146] = 0.0;
   out_500884218142268447[147] = 0.0;
   out_500884218142268447[148] = 0.0;
   out_500884218142268447[149] = 0.0;
   out_500884218142268447[150] = 0.0;
   out_500884218142268447[151] = 0.0;
   out_500884218142268447[152] = 1.0;
   out_500884218142268447[153] = 0.0;
   out_500884218142268447[154] = 0.0;
   out_500884218142268447[155] = 0.0;
   out_500884218142268447[156] = 0.0;
   out_500884218142268447[157] = 0.0;
   out_500884218142268447[158] = 0.0;
   out_500884218142268447[159] = 0.0;
   out_500884218142268447[160] = 0.0;
   out_500884218142268447[161] = 0.0;
   out_500884218142268447[162] = 0.0;
   out_500884218142268447[163] = 0.0;
   out_500884218142268447[164] = 0.0;
   out_500884218142268447[165] = 0.0;
   out_500884218142268447[166] = 0.0;
   out_500884218142268447[167] = 0.0;
   out_500884218142268447[168] = 0.0;
   out_500884218142268447[169] = 0.0;
   out_500884218142268447[170] = 0.0;
   out_500884218142268447[171] = 1.0;
   out_500884218142268447[172] = 0.0;
   out_500884218142268447[173] = 0.0;
   out_500884218142268447[174] = 0.0;
   out_500884218142268447[175] = 0.0;
   out_500884218142268447[176] = 0.0;
   out_500884218142268447[177] = 0.0;
   out_500884218142268447[178] = 0.0;
   out_500884218142268447[179] = 0.0;
   out_500884218142268447[180] = 0.0;
   out_500884218142268447[181] = 0.0;
   out_500884218142268447[182] = 0.0;
   out_500884218142268447[183] = 0.0;
   out_500884218142268447[184] = 0.0;
   out_500884218142268447[185] = 0.0;
   out_500884218142268447[186] = 0.0;
   out_500884218142268447[187] = 0.0;
   out_500884218142268447[188] = 0.0;
   out_500884218142268447[189] = 0.0;
   out_500884218142268447[190] = 1.0;
   out_500884218142268447[191] = 0.0;
   out_500884218142268447[192] = 0.0;
   out_500884218142268447[193] = 0.0;
   out_500884218142268447[194] = 0.0;
   out_500884218142268447[195] = 0.0;
   out_500884218142268447[196] = 0.0;
   out_500884218142268447[197] = 0.0;
   out_500884218142268447[198] = 0.0;
   out_500884218142268447[199] = 0.0;
   out_500884218142268447[200] = 0.0;
   out_500884218142268447[201] = 0.0;
   out_500884218142268447[202] = 0.0;
   out_500884218142268447[203] = 0.0;
   out_500884218142268447[204] = 0.0;
   out_500884218142268447[205] = 0.0;
   out_500884218142268447[206] = 0.0;
   out_500884218142268447[207] = 0.0;
   out_500884218142268447[208] = 0.0;
   out_500884218142268447[209] = 1.0;
   out_500884218142268447[210] = 0.0;
   out_500884218142268447[211] = 0.0;
   out_500884218142268447[212] = 0.0;
   out_500884218142268447[213] = 0.0;
   out_500884218142268447[214] = 0.0;
   out_500884218142268447[215] = 0.0;
   out_500884218142268447[216] = 0.0;
   out_500884218142268447[217] = 0.0;
   out_500884218142268447[218] = 0.0;
   out_500884218142268447[219] = 0.0;
   out_500884218142268447[220] = 0.0;
   out_500884218142268447[221] = 0.0;
   out_500884218142268447[222] = 0.0;
   out_500884218142268447[223] = 0.0;
   out_500884218142268447[224] = 0.0;
   out_500884218142268447[225] = 0.0;
   out_500884218142268447[226] = 0.0;
   out_500884218142268447[227] = 0.0;
   out_500884218142268447[228] = 1.0;
   out_500884218142268447[229] = 0.0;
   out_500884218142268447[230] = 0.0;
   out_500884218142268447[231] = 0.0;
   out_500884218142268447[232] = 0.0;
   out_500884218142268447[233] = 0.0;
   out_500884218142268447[234] = 0.0;
   out_500884218142268447[235] = 0.0;
   out_500884218142268447[236] = 0.0;
   out_500884218142268447[237] = 0.0;
   out_500884218142268447[238] = 0.0;
   out_500884218142268447[239] = 0.0;
   out_500884218142268447[240] = 0.0;
   out_500884218142268447[241] = 0.0;
   out_500884218142268447[242] = 0.0;
   out_500884218142268447[243] = 0.0;
   out_500884218142268447[244] = 0.0;
   out_500884218142268447[245] = 0.0;
   out_500884218142268447[246] = 0.0;
   out_500884218142268447[247] = 1.0;
   out_500884218142268447[248] = 0.0;
   out_500884218142268447[249] = 0.0;
   out_500884218142268447[250] = 0.0;
   out_500884218142268447[251] = 0.0;
   out_500884218142268447[252] = 0.0;
   out_500884218142268447[253] = 0.0;
   out_500884218142268447[254] = 0.0;
   out_500884218142268447[255] = 0.0;
   out_500884218142268447[256] = 0.0;
   out_500884218142268447[257] = 0.0;
   out_500884218142268447[258] = 0.0;
   out_500884218142268447[259] = 0.0;
   out_500884218142268447[260] = 0.0;
   out_500884218142268447[261] = 0.0;
   out_500884218142268447[262] = 0.0;
   out_500884218142268447[263] = 0.0;
   out_500884218142268447[264] = 0.0;
   out_500884218142268447[265] = 0.0;
   out_500884218142268447[266] = 1.0;
   out_500884218142268447[267] = 0.0;
   out_500884218142268447[268] = 0.0;
   out_500884218142268447[269] = 0.0;
   out_500884218142268447[270] = 0.0;
   out_500884218142268447[271] = 0.0;
   out_500884218142268447[272] = 0.0;
   out_500884218142268447[273] = 0.0;
   out_500884218142268447[274] = 0.0;
   out_500884218142268447[275] = 0.0;
   out_500884218142268447[276] = 0.0;
   out_500884218142268447[277] = 0.0;
   out_500884218142268447[278] = 0.0;
   out_500884218142268447[279] = 0.0;
   out_500884218142268447[280] = 0.0;
   out_500884218142268447[281] = 0.0;
   out_500884218142268447[282] = 0.0;
   out_500884218142268447[283] = 0.0;
   out_500884218142268447[284] = 0.0;
   out_500884218142268447[285] = 1.0;
   out_500884218142268447[286] = 0.0;
   out_500884218142268447[287] = 0.0;
   out_500884218142268447[288] = 0.0;
   out_500884218142268447[289] = 0.0;
   out_500884218142268447[290] = 0.0;
   out_500884218142268447[291] = 0.0;
   out_500884218142268447[292] = 0.0;
   out_500884218142268447[293] = 0.0;
   out_500884218142268447[294] = 0.0;
   out_500884218142268447[295] = 0.0;
   out_500884218142268447[296] = 0.0;
   out_500884218142268447[297] = 0.0;
   out_500884218142268447[298] = 0.0;
   out_500884218142268447[299] = 0.0;
   out_500884218142268447[300] = 0.0;
   out_500884218142268447[301] = 0.0;
   out_500884218142268447[302] = 0.0;
   out_500884218142268447[303] = 0.0;
   out_500884218142268447[304] = 1.0;
   out_500884218142268447[305] = 0.0;
   out_500884218142268447[306] = 0.0;
   out_500884218142268447[307] = 0.0;
   out_500884218142268447[308] = 0.0;
   out_500884218142268447[309] = 0.0;
   out_500884218142268447[310] = 0.0;
   out_500884218142268447[311] = 0.0;
   out_500884218142268447[312] = 0.0;
   out_500884218142268447[313] = 0.0;
   out_500884218142268447[314] = 0.0;
   out_500884218142268447[315] = 0.0;
   out_500884218142268447[316] = 0.0;
   out_500884218142268447[317] = 0.0;
   out_500884218142268447[318] = 0.0;
   out_500884218142268447[319] = 0.0;
   out_500884218142268447[320] = 0.0;
   out_500884218142268447[321] = 0.0;
   out_500884218142268447[322] = 0.0;
   out_500884218142268447[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4066820228930702403) {
   out_4066820228930702403[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4066820228930702403[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4066820228930702403[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4066820228930702403[3] = dt*state[12] + state[3];
   out_4066820228930702403[4] = dt*state[13] + state[4];
   out_4066820228930702403[5] = dt*state[14] + state[5];
   out_4066820228930702403[6] = state[6];
   out_4066820228930702403[7] = state[7];
   out_4066820228930702403[8] = state[8];
   out_4066820228930702403[9] = state[9];
   out_4066820228930702403[10] = state[10];
   out_4066820228930702403[11] = state[11];
   out_4066820228930702403[12] = state[12];
   out_4066820228930702403[13] = state[13];
   out_4066820228930702403[14] = state[14];
   out_4066820228930702403[15] = state[15];
   out_4066820228930702403[16] = state[16];
   out_4066820228930702403[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4990161262598215268) {
   out_4990161262598215268[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4990161262598215268[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4990161262598215268[2] = 0;
   out_4990161262598215268[3] = 0;
   out_4990161262598215268[4] = 0;
   out_4990161262598215268[5] = 0;
   out_4990161262598215268[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4990161262598215268[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4990161262598215268[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4990161262598215268[9] = 0;
   out_4990161262598215268[10] = 0;
   out_4990161262598215268[11] = 0;
   out_4990161262598215268[12] = 0;
   out_4990161262598215268[13] = 0;
   out_4990161262598215268[14] = 0;
   out_4990161262598215268[15] = 0;
   out_4990161262598215268[16] = 0;
   out_4990161262598215268[17] = 0;
   out_4990161262598215268[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4990161262598215268[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4990161262598215268[20] = 0;
   out_4990161262598215268[21] = 0;
   out_4990161262598215268[22] = 0;
   out_4990161262598215268[23] = 0;
   out_4990161262598215268[24] = 0;
   out_4990161262598215268[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4990161262598215268[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4990161262598215268[27] = 0;
   out_4990161262598215268[28] = 0;
   out_4990161262598215268[29] = 0;
   out_4990161262598215268[30] = 0;
   out_4990161262598215268[31] = 0;
   out_4990161262598215268[32] = 0;
   out_4990161262598215268[33] = 0;
   out_4990161262598215268[34] = 0;
   out_4990161262598215268[35] = 0;
   out_4990161262598215268[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4990161262598215268[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4990161262598215268[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4990161262598215268[39] = 0;
   out_4990161262598215268[40] = 0;
   out_4990161262598215268[41] = 0;
   out_4990161262598215268[42] = 0;
   out_4990161262598215268[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4990161262598215268[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4990161262598215268[45] = 0;
   out_4990161262598215268[46] = 0;
   out_4990161262598215268[47] = 0;
   out_4990161262598215268[48] = 0;
   out_4990161262598215268[49] = 0;
   out_4990161262598215268[50] = 0;
   out_4990161262598215268[51] = 0;
   out_4990161262598215268[52] = 0;
   out_4990161262598215268[53] = 0;
   out_4990161262598215268[54] = 0;
   out_4990161262598215268[55] = 0;
   out_4990161262598215268[56] = 0;
   out_4990161262598215268[57] = 1;
   out_4990161262598215268[58] = 0;
   out_4990161262598215268[59] = 0;
   out_4990161262598215268[60] = 0;
   out_4990161262598215268[61] = 0;
   out_4990161262598215268[62] = 0;
   out_4990161262598215268[63] = 0;
   out_4990161262598215268[64] = 0;
   out_4990161262598215268[65] = 0;
   out_4990161262598215268[66] = dt;
   out_4990161262598215268[67] = 0;
   out_4990161262598215268[68] = 0;
   out_4990161262598215268[69] = 0;
   out_4990161262598215268[70] = 0;
   out_4990161262598215268[71] = 0;
   out_4990161262598215268[72] = 0;
   out_4990161262598215268[73] = 0;
   out_4990161262598215268[74] = 0;
   out_4990161262598215268[75] = 0;
   out_4990161262598215268[76] = 1;
   out_4990161262598215268[77] = 0;
   out_4990161262598215268[78] = 0;
   out_4990161262598215268[79] = 0;
   out_4990161262598215268[80] = 0;
   out_4990161262598215268[81] = 0;
   out_4990161262598215268[82] = 0;
   out_4990161262598215268[83] = 0;
   out_4990161262598215268[84] = 0;
   out_4990161262598215268[85] = dt;
   out_4990161262598215268[86] = 0;
   out_4990161262598215268[87] = 0;
   out_4990161262598215268[88] = 0;
   out_4990161262598215268[89] = 0;
   out_4990161262598215268[90] = 0;
   out_4990161262598215268[91] = 0;
   out_4990161262598215268[92] = 0;
   out_4990161262598215268[93] = 0;
   out_4990161262598215268[94] = 0;
   out_4990161262598215268[95] = 1;
   out_4990161262598215268[96] = 0;
   out_4990161262598215268[97] = 0;
   out_4990161262598215268[98] = 0;
   out_4990161262598215268[99] = 0;
   out_4990161262598215268[100] = 0;
   out_4990161262598215268[101] = 0;
   out_4990161262598215268[102] = 0;
   out_4990161262598215268[103] = 0;
   out_4990161262598215268[104] = dt;
   out_4990161262598215268[105] = 0;
   out_4990161262598215268[106] = 0;
   out_4990161262598215268[107] = 0;
   out_4990161262598215268[108] = 0;
   out_4990161262598215268[109] = 0;
   out_4990161262598215268[110] = 0;
   out_4990161262598215268[111] = 0;
   out_4990161262598215268[112] = 0;
   out_4990161262598215268[113] = 0;
   out_4990161262598215268[114] = 1;
   out_4990161262598215268[115] = 0;
   out_4990161262598215268[116] = 0;
   out_4990161262598215268[117] = 0;
   out_4990161262598215268[118] = 0;
   out_4990161262598215268[119] = 0;
   out_4990161262598215268[120] = 0;
   out_4990161262598215268[121] = 0;
   out_4990161262598215268[122] = 0;
   out_4990161262598215268[123] = 0;
   out_4990161262598215268[124] = 0;
   out_4990161262598215268[125] = 0;
   out_4990161262598215268[126] = 0;
   out_4990161262598215268[127] = 0;
   out_4990161262598215268[128] = 0;
   out_4990161262598215268[129] = 0;
   out_4990161262598215268[130] = 0;
   out_4990161262598215268[131] = 0;
   out_4990161262598215268[132] = 0;
   out_4990161262598215268[133] = 1;
   out_4990161262598215268[134] = 0;
   out_4990161262598215268[135] = 0;
   out_4990161262598215268[136] = 0;
   out_4990161262598215268[137] = 0;
   out_4990161262598215268[138] = 0;
   out_4990161262598215268[139] = 0;
   out_4990161262598215268[140] = 0;
   out_4990161262598215268[141] = 0;
   out_4990161262598215268[142] = 0;
   out_4990161262598215268[143] = 0;
   out_4990161262598215268[144] = 0;
   out_4990161262598215268[145] = 0;
   out_4990161262598215268[146] = 0;
   out_4990161262598215268[147] = 0;
   out_4990161262598215268[148] = 0;
   out_4990161262598215268[149] = 0;
   out_4990161262598215268[150] = 0;
   out_4990161262598215268[151] = 0;
   out_4990161262598215268[152] = 1;
   out_4990161262598215268[153] = 0;
   out_4990161262598215268[154] = 0;
   out_4990161262598215268[155] = 0;
   out_4990161262598215268[156] = 0;
   out_4990161262598215268[157] = 0;
   out_4990161262598215268[158] = 0;
   out_4990161262598215268[159] = 0;
   out_4990161262598215268[160] = 0;
   out_4990161262598215268[161] = 0;
   out_4990161262598215268[162] = 0;
   out_4990161262598215268[163] = 0;
   out_4990161262598215268[164] = 0;
   out_4990161262598215268[165] = 0;
   out_4990161262598215268[166] = 0;
   out_4990161262598215268[167] = 0;
   out_4990161262598215268[168] = 0;
   out_4990161262598215268[169] = 0;
   out_4990161262598215268[170] = 0;
   out_4990161262598215268[171] = 1;
   out_4990161262598215268[172] = 0;
   out_4990161262598215268[173] = 0;
   out_4990161262598215268[174] = 0;
   out_4990161262598215268[175] = 0;
   out_4990161262598215268[176] = 0;
   out_4990161262598215268[177] = 0;
   out_4990161262598215268[178] = 0;
   out_4990161262598215268[179] = 0;
   out_4990161262598215268[180] = 0;
   out_4990161262598215268[181] = 0;
   out_4990161262598215268[182] = 0;
   out_4990161262598215268[183] = 0;
   out_4990161262598215268[184] = 0;
   out_4990161262598215268[185] = 0;
   out_4990161262598215268[186] = 0;
   out_4990161262598215268[187] = 0;
   out_4990161262598215268[188] = 0;
   out_4990161262598215268[189] = 0;
   out_4990161262598215268[190] = 1;
   out_4990161262598215268[191] = 0;
   out_4990161262598215268[192] = 0;
   out_4990161262598215268[193] = 0;
   out_4990161262598215268[194] = 0;
   out_4990161262598215268[195] = 0;
   out_4990161262598215268[196] = 0;
   out_4990161262598215268[197] = 0;
   out_4990161262598215268[198] = 0;
   out_4990161262598215268[199] = 0;
   out_4990161262598215268[200] = 0;
   out_4990161262598215268[201] = 0;
   out_4990161262598215268[202] = 0;
   out_4990161262598215268[203] = 0;
   out_4990161262598215268[204] = 0;
   out_4990161262598215268[205] = 0;
   out_4990161262598215268[206] = 0;
   out_4990161262598215268[207] = 0;
   out_4990161262598215268[208] = 0;
   out_4990161262598215268[209] = 1;
   out_4990161262598215268[210] = 0;
   out_4990161262598215268[211] = 0;
   out_4990161262598215268[212] = 0;
   out_4990161262598215268[213] = 0;
   out_4990161262598215268[214] = 0;
   out_4990161262598215268[215] = 0;
   out_4990161262598215268[216] = 0;
   out_4990161262598215268[217] = 0;
   out_4990161262598215268[218] = 0;
   out_4990161262598215268[219] = 0;
   out_4990161262598215268[220] = 0;
   out_4990161262598215268[221] = 0;
   out_4990161262598215268[222] = 0;
   out_4990161262598215268[223] = 0;
   out_4990161262598215268[224] = 0;
   out_4990161262598215268[225] = 0;
   out_4990161262598215268[226] = 0;
   out_4990161262598215268[227] = 0;
   out_4990161262598215268[228] = 1;
   out_4990161262598215268[229] = 0;
   out_4990161262598215268[230] = 0;
   out_4990161262598215268[231] = 0;
   out_4990161262598215268[232] = 0;
   out_4990161262598215268[233] = 0;
   out_4990161262598215268[234] = 0;
   out_4990161262598215268[235] = 0;
   out_4990161262598215268[236] = 0;
   out_4990161262598215268[237] = 0;
   out_4990161262598215268[238] = 0;
   out_4990161262598215268[239] = 0;
   out_4990161262598215268[240] = 0;
   out_4990161262598215268[241] = 0;
   out_4990161262598215268[242] = 0;
   out_4990161262598215268[243] = 0;
   out_4990161262598215268[244] = 0;
   out_4990161262598215268[245] = 0;
   out_4990161262598215268[246] = 0;
   out_4990161262598215268[247] = 1;
   out_4990161262598215268[248] = 0;
   out_4990161262598215268[249] = 0;
   out_4990161262598215268[250] = 0;
   out_4990161262598215268[251] = 0;
   out_4990161262598215268[252] = 0;
   out_4990161262598215268[253] = 0;
   out_4990161262598215268[254] = 0;
   out_4990161262598215268[255] = 0;
   out_4990161262598215268[256] = 0;
   out_4990161262598215268[257] = 0;
   out_4990161262598215268[258] = 0;
   out_4990161262598215268[259] = 0;
   out_4990161262598215268[260] = 0;
   out_4990161262598215268[261] = 0;
   out_4990161262598215268[262] = 0;
   out_4990161262598215268[263] = 0;
   out_4990161262598215268[264] = 0;
   out_4990161262598215268[265] = 0;
   out_4990161262598215268[266] = 1;
   out_4990161262598215268[267] = 0;
   out_4990161262598215268[268] = 0;
   out_4990161262598215268[269] = 0;
   out_4990161262598215268[270] = 0;
   out_4990161262598215268[271] = 0;
   out_4990161262598215268[272] = 0;
   out_4990161262598215268[273] = 0;
   out_4990161262598215268[274] = 0;
   out_4990161262598215268[275] = 0;
   out_4990161262598215268[276] = 0;
   out_4990161262598215268[277] = 0;
   out_4990161262598215268[278] = 0;
   out_4990161262598215268[279] = 0;
   out_4990161262598215268[280] = 0;
   out_4990161262598215268[281] = 0;
   out_4990161262598215268[282] = 0;
   out_4990161262598215268[283] = 0;
   out_4990161262598215268[284] = 0;
   out_4990161262598215268[285] = 1;
   out_4990161262598215268[286] = 0;
   out_4990161262598215268[287] = 0;
   out_4990161262598215268[288] = 0;
   out_4990161262598215268[289] = 0;
   out_4990161262598215268[290] = 0;
   out_4990161262598215268[291] = 0;
   out_4990161262598215268[292] = 0;
   out_4990161262598215268[293] = 0;
   out_4990161262598215268[294] = 0;
   out_4990161262598215268[295] = 0;
   out_4990161262598215268[296] = 0;
   out_4990161262598215268[297] = 0;
   out_4990161262598215268[298] = 0;
   out_4990161262598215268[299] = 0;
   out_4990161262598215268[300] = 0;
   out_4990161262598215268[301] = 0;
   out_4990161262598215268[302] = 0;
   out_4990161262598215268[303] = 0;
   out_4990161262598215268[304] = 1;
   out_4990161262598215268[305] = 0;
   out_4990161262598215268[306] = 0;
   out_4990161262598215268[307] = 0;
   out_4990161262598215268[308] = 0;
   out_4990161262598215268[309] = 0;
   out_4990161262598215268[310] = 0;
   out_4990161262598215268[311] = 0;
   out_4990161262598215268[312] = 0;
   out_4990161262598215268[313] = 0;
   out_4990161262598215268[314] = 0;
   out_4990161262598215268[315] = 0;
   out_4990161262598215268[316] = 0;
   out_4990161262598215268[317] = 0;
   out_4990161262598215268[318] = 0;
   out_4990161262598215268[319] = 0;
   out_4990161262598215268[320] = 0;
   out_4990161262598215268[321] = 0;
   out_4990161262598215268[322] = 0;
   out_4990161262598215268[323] = 1;
}
void h_4(double *state, double *unused, double *out_6356659530746877918) {
   out_6356659530746877918[0] = state[6] + state[9];
   out_6356659530746877918[1] = state[7] + state[10];
   out_6356659530746877918[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_9001498189509461827) {
   out_9001498189509461827[0] = 0;
   out_9001498189509461827[1] = 0;
   out_9001498189509461827[2] = 0;
   out_9001498189509461827[3] = 0;
   out_9001498189509461827[4] = 0;
   out_9001498189509461827[5] = 0;
   out_9001498189509461827[6] = 1;
   out_9001498189509461827[7] = 0;
   out_9001498189509461827[8] = 0;
   out_9001498189509461827[9] = 1;
   out_9001498189509461827[10] = 0;
   out_9001498189509461827[11] = 0;
   out_9001498189509461827[12] = 0;
   out_9001498189509461827[13] = 0;
   out_9001498189509461827[14] = 0;
   out_9001498189509461827[15] = 0;
   out_9001498189509461827[16] = 0;
   out_9001498189509461827[17] = 0;
   out_9001498189509461827[18] = 0;
   out_9001498189509461827[19] = 0;
   out_9001498189509461827[20] = 0;
   out_9001498189509461827[21] = 0;
   out_9001498189509461827[22] = 0;
   out_9001498189509461827[23] = 0;
   out_9001498189509461827[24] = 0;
   out_9001498189509461827[25] = 1;
   out_9001498189509461827[26] = 0;
   out_9001498189509461827[27] = 0;
   out_9001498189509461827[28] = 1;
   out_9001498189509461827[29] = 0;
   out_9001498189509461827[30] = 0;
   out_9001498189509461827[31] = 0;
   out_9001498189509461827[32] = 0;
   out_9001498189509461827[33] = 0;
   out_9001498189509461827[34] = 0;
   out_9001498189509461827[35] = 0;
   out_9001498189509461827[36] = 0;
   out_9001498189509461827[37] = 0;
   out_9001498189509461827[38] = 0;
   out_9001498189509461827[39] = 0;
   out_9001498189509461827[40] = 0;
   out_9001498189509461827[41] = 0;
   out_9001498189509461827[42] = 0;
   out_9001498189509461827[43] = 0;
   out_9001498189509461827[44] = 1;
   out_9001498189509461827[45] = 0;
   out_9001498189509461827[46] = 0;
   out_9001498189509461827[47] = 1;
   out_9001498189509461827[48] = 0;
   out_9001498189509461827[49] = 0;
   out_9001498189509461827[50] = 0;
   out_9001498189509461827[51] = 0;
   out_9001498189509461827[52] = 0;
   out_9001498189509461827[53] = 0;
}
void h_10(double *state, double *unused, double *out_4540118139912947621) {
   out_4540118139912947621[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4540118139912947621[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4540118139912947621[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2609551212551183976) {
   out_2609551212551183976[0] = 0;
   out_2609551212551183976[1] = 9.8100000000000005*cos(state[1]);
   out_2609551212551183976[2] = 0;
   out_2609551212551183976[3] = 0;
   out_2609551212551183976[4] = -state[8];
   out_2609551212551183976[5] = state[7];
   out_2609551212551183976[6] = 0;
   out_2609551212551183976[7] = state[5];
   out_2609551212551183976[8] = -state[4];
   out_2609551212551183976[9] = 0;
   out_2609551212551183976[10] = 0;
   out_2609551212551183976[11] = 0;
   out_2609551212551183976[12] = 1;
   out_2609551212551183976[13] = 0;
   out_2609551212551183976[14] = 0;
   out_2609551212551183976[15] = 1;
   out_2609551212551183976[16] = 0;
   out_2609551212551183976[17] = 0;
   out_2609551212551183976[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2609551212551183976[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2609551212551183976[20] = 0;
   out_2609551212551183976[21] = state[8];
   out_2609551212551183976[22] = 0;
   out_2609551212551183976[23] = -state[6];
   out_2609551212551183976[24] = -state[5];
   out_2609551212551183976[25] = 0;
   out_2609551212551183976[26] = state[3];
   out_2609551212551183976[27] = 0;
   out_2609551212551183976[28] = 0;
   out_2609551212551183976[29] = 0;
   out_2609551212551183976[30] = 0;
   out_2609551212551183976[31] = 1;
   out_2609551212551183976[32] = 0;
   out_2609551212551183976[33] = 0;
   out_2609551212551183976[34] = 1;
   out_2609551212551183976[35] = 0;
   out_2609551212551183976[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2609551212551183976[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2609551212551183976[38] = 0;
   out_2609551212551183976[39] = -state[7];
   out_2609551212551183976[40] = state[6];
   out_2609551212551183976[41] = 0;
   out_2609551212551183976[42] = state[4];
   out_2609551212551183976[43] = -state[3];
   out_2609551212551183976[44] = 0;
   out_2609551212551183976[45] = 0;
   out_2609551212551183976[46] = 0;
   out_2609551212551183976[47] = 0;
   out_2609551212551183976[48] = 0;
   out_2609551212551183976[49] = 0;
   out_2609551212551183976[50] = 1;
   out_2609551212551183976[51] = 0;
   out_2609551212551183976[52] = 0;
   out_2609551212551183976[53] = 1;
}
void h_13(double *state, double *unused, double *out_8965537497810380637) {
   out_8965537497810380637[0] = state[3];
   out_8965537497810380637[1] = state[4];
   out_8965537497810380637[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6232972058867756988) {
   out_6232972058867756988[0] = 0;
   out_6232972058867756988[1] = 0;
   out_6232972058867756988[2] = 0;
   out_6232972058867756988[3] = 1;
   out_6232972058867756988[4] = 0;
   out_6232972058867756988[5] = 0;
   out_6232972058867756988[6] = 0;
   out_6232972058867756988[7] = 0;
   out_6232972058867756988[8] = 0;
   out_6232972058867756988[9] = 0;
   out_6232972058867756988[10] = 0;
   out_6232972058867756988[11] = 0;
   out_6232972058867756988[12] = 0;
   out_6232972058867756988[13] = 0;
   out_6232972058867756988[14] = 0;
   out_6232972058867756988[15] = 0;
   out_6232972058867756988[16] = 0;
   out_6232972058867756988[17] = 0;
   out_6232972058867756988[18] = 0;
   out_6232972058867756988[19] = 0;
   out_6232972058867756988[20] = 0;
   out_6232972058867756988[21] = 0;
   out_6232972058867756988[22] = 1;
   out_6232972058867756988[23] = 0;
   out_6232972058867756988[24] = 0;
   out_6232972058867756988[25] = 0;
   out_6232972058867756988[26] = 0;
   out_6232972058867756988[27] = 0;
   out_6232972058867756988[28] = 0;
   out_6232972058867756988[29] = 0;
   out_6232972058867756988[30] = 0;
   out_6232972058867756988[31] = 0;
   out_6232972058867756988[32] = 0;
   out_6232972058867756988[33] = 0;
   out_6232972058867756988[34] = 0;
   out_6232972058867756988[35] = 0;
   out_6232972058867756988[36] = 0;
   out_6232972058867756988[37] = 0;
   out_6232972058867756988[38] = 0;
   out_6232972058867756988[39] = 0;
   out_6232972058867756988[40] = 0;
   out_6232972058867756988[41] = 1;
   out_6232972058867756988[42] = 0;
   out_6232972058867756988[43] = 0;
   out_6232972058867756988[44] = 0;
   out_6232972058867756988[45] = 0;
   out_6232972058867756988[46] = 0;
   out_6232972058867756988[47] = 0;
   out_6232972058867756988[48] = 0;
   out_6232972058867756988[49] = 0;
   out_6232972058867756988[50] = 0;
   out_6232972058867756988[51] = 0;
   out_6232972058867756988[52] = 0;
   out_6232972058867756988[53] = 0;
}
void h_14(double *state, double *unused, double *out_6865363732186478618) {
   out_6865363732186478618[0] = state[6];
   out_6865363732186478618[1] = state[7];
   out_6865363732186478618[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8566381662864578228) {
   out_8566381662864578228[0] = 0;
   out_8566381662864578228[1] = 0;
   out_8566381662864578228[2] = 0;
   out_8566381662864578228[3] = 0;
   out_8566381662864578228[4] = 0;
   out_8566381662864578228[5] = 0;
   out_8566381662864578228[6] = 1;
   out_8566381662864578228[7] = 0;
   out_8566381662864578228[8] = 0;
   out_8566381662864578228[9] = 0;
   out_8566381662864578228[10] = 0;
   out_8566381662864578228[11] = 0;
   out_8566381662864578228[12] = 0;
   out_8566381662864578228[13] = 0;
   out_8566381662864578228[14] = 0;
   out_8566381662864578228[15] = 0;
   out_8566381662864578228[16] = 0;
   out_8566381662864578228[17] = 0;
   out_8566381662864578228[18] = 0;
   out_8566381662864578228[19] = 0;
   out_8566381662864578228[20] = 0;
   out_8566381662864578228[21] = 0;
   out_8566381662864578228[22] = 0;
   out_8566381662864578228[23] = 0;
   out_8566381662864578228[24] = 0;
   out_8566381662864578228[25] = 1;
   out_8566381662864578228[26] = 0;
   out_8566381662864578228[27] = 0;
   out_8566381662864578228[28] = 0;
   out_8566381662864578228[29] = 0;
   out_8566381662864578228[30] = 0;
   out_8566381662864578228[31] = 0;
   out_8566381662864578228[32] = 0;
   out_8566381662864578228[33] = 0;
   out_8566381662864578228[34] = 0;
   out_8566381662864578228[35] = 0;
   out_8566381662864578228[36] = 0;
   out_8566381662864578228[37] = 0;
   out_8566381662864578228[38] = 0;
   out_8566381662864578228[39] = 0;
   out_8566381662864578228[40] = 0;
   out_8566381662864578228[41] = 0;
   out_8566381662864578228[42] = 0;
   out_8566381662864578228[43] = 0;
   out_8566381662864578228[44] = 1;
   out_8566381662864578228[45] = 0;
   out_8566381662864578228[46] = 0;
   out_8566381662864578228[47] = 0;
   out_8566381662864578228[48] = 0;
   out_8566381662864578228[49] = 0;
   out_8566381662864578228[50] = 0;
   out_8566381662864578228[51] = 0;
   out_8566381662864578228[52] = 0;
   out_8566381662864578228[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2717418772724129561) {
  err_fun(nom_x, delta_x, out_2717418772724129561);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6564594974930648805) {
  inv_err_fun(nom_x, true_x, out_6564594974930648805);
}
void pose_H_mod_fun(double *state, double *out_500884218142268447) {
  H_mod_fun(state, out_500884218142268447);
}
void pose_f_fun(double *state, double dt, double *out_4066820228930702403) {
  f_fun(state,  dt, out_4066820228930702403);
}
void pose_F_fun(double *state, double dt, double *out_4990161262598215268) {
  F_fun(state,  dt, out_4990161262598215268);
}
void pose_h_4(double *state, double *unused, double *out_6356659530746877918) {
  h_4(state, unused, out_6356659530746877918);
}
void pose_H_4(double *state, double *unused, double *out_9001498189509461827) {
  H_4(state, unused, out_9001498189509461827);
}
void pose_h_10(double *state, double *unused, double *out_4540118139912947621) {
  h_10(state, unused, out_4540118139912947621);
}
void pose_H_10(double *state, double *unused, double *out_2609551212551183976) {
  H_10(state, unused, out_2609551212551183976);
}
void pose_h_13(double *state, double *unused, double *out_8965537497810380637) {
  h_13(state, unused, out_8965537497810380637);
}
void pose_H_13(double *state, double *unused, double *out_6232972058867756988) {
  H_13(state, unused, out_6232972058867756988);
}
void pose_h_14(double *state, double *unused, double *out_6865363732186478618) {
  h_14(state, unused, out_6865363732186478618);
}
void pose_H_14(double *state, double *unused, double *out_8566381662864578228) {
  H_14(state, unused, out_8566381662864578228);
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
