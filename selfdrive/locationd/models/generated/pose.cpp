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
void err_fun(double *nom_x, double *delta_x, double *out_309314752274053340) {
   out_309314752274053340[0] = delta_x[0] + nom_x[0];
   out_309314752274053340[1] = delta_x[1] + nom_x[1];
   out_309314752274053340[2] = delta_x[2] + nom_x[2];
   out_309314752274053340[3] = delta_x[3] + nom_x[3];
   out_309314752274053340[4] = delta_x[4] + nom_x[4];
   out_309314752274053340[5] = delta_x[5] + nom_x[5];
   out_309314752274053340[6] = delta_x[6] + nom_x[6];
   out_309314752274053340[7] = delta_x[7] + nom_x[7];
   out_309314752274053340[8] = delta_x[8] + nom_x[8];
   out_309314752274053340[9] = delta_x[9] + nom_x[9];
   out_309314752274053340[10] = delta_x[10] + nom_x[10];
   out_309314752274053340[11] = delta_x[11] + nom_x[11];
   out_309314752274053340[12] = delta_x[12] + nom_x[12];
   out_309314752274053340[13] = delta_x[13] + nom_x[13];
   out_309314752274053340[14] = delta_x[14] + nom_x[14];
   out_309314752274053340[15] = delta_x[15] + nom_x[15];
   out_309314752274053340[16] = delta_x[16] + nom_x[16];
   out_309314752274053340[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_651338713617187314) {
   out_651338713617187314[0] = -nom_x[0] + true_x[0];
   out_651338713617187314[1] = -nom_x[1] + true_x[1];
   out_651338713617187314[2] = -nom_x[2] + true_x[2];
   out_651338713617187314[3] = -nom_x[3] + true_x[3];
   out_651338713617187314[4] = -nom_x[4] + true_x[4];
   out_651338713617187314[5] = -nom_x[5] + true_x[5];
   out_651338713617187314[6] = -nom_x[6] + true_x[6];
   out_651338713617187314[7] = -nom_x[7] + true_x[7];
   out_651338713617187314[8] = -nom_x[8] + true_x[8];
   out_651338713617187314[9] = -nom_x[9] + true_x[9];
   out_651338713617187314[10] = -nom_x[10] + true_x[10];
   out_651338713617187314[11] = -nom_x[11] + true_x[11];
   out_651338713617187314[12] = -nom_x[12] + true_x[12];
   out_651338713617187314[13] = -nom_x[13] + true_x[13];
   out_651338713617187314[14] = -nom_x[14] + true_x[14];
   out_651338713617187314[15] = -nom_x[15] + true_x[15];
   out_651338713617187314[16] = -nom_x[16] + true_x[16];
   out_651338713617187314[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1638652939169850596) {
   out_1638652939169850596[0] = 1.0;
   out_1638652939169850596[1] = 0.0;
   out_1638652939169850596[2] = 0.0;
   out_1638652939169850596[3] = 0.0;
   out_1638652939169850596[4] = 0.0;
   out_1638652939169850596[5] = 0.0;
   out_1638652939169850596[6] = 0.0;
   out_1638652939169850596[7] = 0.0;
   out_1638652939169850596[8] = 0.0;
   out_1638652939169850596[9] = 0.0;
   out_1638652939169850596[10] = 0.0;
   out_1638652939169850596[11] = 0.0;
   out_1638652939169850596[12] = 0.0;
   out_1638652939169850596[13] = 0.0;
   out_1638652939169850596[14] = 0.0;
   out_1638652939169850596[15] = 0.0;
   out_1638652939169850596[16] = 0.0;
   out_1638652939169850596[17] = 0.0;
   out_1638652939169850596[18] = 0.0;
   out_1638652939169850596[19] = 1.0;
   out_1638652939169850596[20] = 0.0;
   out_1638652939169850596[21] = 0.0;
   out_1638652939169850596[22] = 0.0;
   out_1638652939169850596[23] = 0.0;
   out_1638652939169850596[24] = 0.0;
   out_1638652939169850596[25] = 0.0;
   out_1638652939169850596[26] = 0.0;
   out_1638652939169850596[27] = 0.0;
   out_1638652939169850596[28] = 0.0;
   out_1638652939169850596[29] = 0.0;
   out_1638652939169850596[30] = 0.0;
   out_1638652939169850596[31] = 0.0;
   out_1638652939169850596[32] = 0.0;
   out_1638652939169850596[33] = 0.0;
   out_1638652939169850596[34] = 0.0;
   out_1638652939169850596[35] = 0.0;
   out_1638652939169850596[36] = 0.0;
   out_1638652939169850596[37] = 0.0;
   out_1638652939169850596[38] = 1.0;
   out_1638652939169850596[39] = 0.0;
   out_1638652939169850596[40] = 0.0;
   out_1638652939169850596[41] = 0.0;
   out_1638652939169850596[42] = 0.0;
   out_1638652939169850596[43] = 0.0;
   out_1638652939169850596[44] = 0.0;
   out_1638652939169850596[45] = 0.0;
   out_1638652939169850596[46] = 0.0;
   out_1638652939169850596[47] = 0.0;
   out_1638652939169850596[48] = 0.0;
   out_1638652939169850596[49] = 0.0;
   out_1638652939169850596[50] = 0.0;
   out_1638652939169850596[51] = 0.0;
   out_1638652939169850596[52] = 0.0;
   out_1638652939169850596[53] = 0.0;
   out_1638652939169850596[54] = 0.0;
   out_1638652939169850596[55] = 0.0;
   out_1638652939169850596[56] = 0.0;
   out_1638652939169850596[57] = 1.0;
   out_1638652939169850596[58] = 0.0;
   out_1638652939169850596[59] = 0.0;
   out_1638652939169850596[60] = 0.0;
   out_1638652939169850596[61] = 0.0;
   out_1638652939169850596[62] = 0.0;
   out_1638652939169850596[63] = 0.0;
   out_1638652939169850596[64] = 0.0;
   out_1638652939169850596[65] = 0.0;
   out_1638652939169850596[66] = 0.0;
   out_1638652939169850596[67] = 0.0;
   out_1638652939169850596[68] = 0.0;
   out_1638652939169850596[69] = 0.0;
   out_1638652939169850596[70] = 0.0;
   out_1638652939169850596[71] = 0.0;
   out_1638652939169850596[72] = 0.0;
   out_1638652939169850596[73] = 0.0;
   out_1638652939169850596[74] = 0.0;
   out_1638652939169850596[75] = 0.0;
   out_1638652939169850596[76] = 1.0;
   out_1638652939169850596[77] = 0.0;
   out_1638652939169850596[78] = 0.0;
   out_1638652939169850596[79] = 0.0;
   out_1638652939169850596[80] = 0.0;
   out_1638652939169850596[81] = 0.0;
   out_1638652939169850596[82] = 0.0;
   out_1638652939169850596[83] = 0.0;
   out_1638652939169850596[84] = 0.0;
   out_1638652939169850596[85] = 0.0;
   out_1638652939169850596[86] = 0.0;
   out_1638652939169850596[87] = 0.0;
   out_1638652939169850596[88] = 0.0;
   out_1638652939169850596[89] = 0.0;
   out_1638652939169850596[90] = 0.0;
   out_1638652939169850596[91] = 0.0;
   out_1638652939169850596[92] = 0.0;
   out_1638652939169850596[93] = 0.0;
   out_1638652939169850596[94] = 0.0;
   out_1638652939169850596[95] = 1.0;
   out_1638652939169850596[96] = 0.0;
   out_1638652939169850596[97] = 0.0;
   out_1638652939169850596[98] = 0.0;
   out_1638652939169850596[99] = 0.0;
   out_1638652939169850596[100] = 0.0;
   out_1638652939169850596[101] = 0.0;
   out_1638652939169850596[102] = 0.0;
   out_1638652939169850596[103] = 0.0;
   out_1638652939169850596[104] = 0.0;
   out_1638652939169850596[105] = 0.0;
   out_1638652939169850596[106] = 0.0;
   out_1638652939169850596[107] = 0.0;
   out_1638652939169850596[108] = 0.0;
   out_1638652939169850596[109] = 0.0;
   out_1638652939169850596[110] = 0.0;
   out_1638652939169850596[111] = 0.0;
   out_1638652939169850596[112] = 0.0;
   out_1638652939169850596[113] = 0.0;
   out_1638652939169850596[114] = 1.0;
   out_1638652939169850596[115] = 0.0;
   out_1638652939169850596[116] = 0.0;
   out_1638652939169850596[117] = 0.0;
   out_1638652939169850596[118] = 0.0;
   out_1638652939169850596[119] = 0.0;
   out_1638652939169850596[120] = 0.0;
   out_1638652939169850596[121] = 0.0;
   out_1638652939169850596[122] = 0.0;
   out_1638652939169850596[123] = 0.0;
   out_1638652939169850596[124] = 0.0;
   out_1638652939169850596[125] = 0.0;
   out_1638652939169850596[126] = 0.0;
   out_1638652939169850596[127] = 0.0;
   out_1638652939169850596[128] = 0.0;
   out_1638652939169850596[129] = 0.0;
   out_1638652939169850596[130] = 0.0;
   out_1638652939169850596[131] = 0.0;
   out_1638652939169850596[132] = 0.0;
   out_1638652939169850596[133] = 1.0;
   out_1638652939169850596[134] = 0.0;
   out_1638652939169850596[135] = 0.0;
   out_1638652939169850596[136] = 0.0;
   out_1638652939169850596[137] = 0.0;
   out_1638652939169850596[138] = 0.0;
   out_1638652939169850596[139] = 0.0;
   out_1638652939169850596[140] = 0.0;
   out_1638652939169850596[141] = 0.0;
   out_1638652939169850596[142] = 0.0;
   out_1638652939169850596[143] = 0.0;
   out_1638652939169850596[144] = 0.0;
   out_1638652939169850596[145] = 0.0;
   out_1638652939169850596[146] = 0.0;
   out_1638652939169850596[147] = 0.0;
   out_1638652939169850596[148] = 0.0;
   out_1638652939169850596[149] = 0.0;
   out_1638652939169850596[150] = 0.0;
   out_1638652939169850596[151] = 0.0;
   out_1638652939169850596[152] = 1.0;
   out_1638652939169850596[153] = 0.0;
   out_1638652939169850596[154] = 0.0;
   out_1638652939169850596[155] = 0.0;
   out_1638652939169850596[156] = 0.0;
   out_1638652939169850596[157] = 0.0;
   out_1638652939169850596[158] = 0.0;
   out_1638652939169850596[159] = 0.0;
   out_1638652939169850596[160] = 0.0;
   out_1638652939169850596[161] = 0.0;
   out_1638652939169850596[162] = 0.0;
   out_1638652939169850596[163] = 0.0;
   out_1638652939169850596[164] = 0.0;
   out_1638652939169850596[165] = 0.0;
   out_1638652939169850596[166] = 0.0;
   out_1638652939169850596[167] = 0.0;
   out_1638652939169850596[168] = 0.0;
   out_1638652939169850596[169] = 0.0;
   out_1638652939169850596[170] = 0.0;
   out_1638652939169850596[171] = 1.0;
   out_1638652939169850596[172] = 0.0;
   out_1638652939169850596[173] = 0.0;
   out_1638652939169850596[174] = 0.0;
   out_1638652939169850596[175] = 0.0;
   out_1638652939169850596[176] = 0.0;
   out_1638652939169850596[177] = 0.0;
   out_1638652939169850596[178] = 0.0;
   out_1638652939169850596[179] = 0.0;
   out_1638652939169850596[180] = 0.0;
   out_1638652939169850596[181] = 0.0;
   out_1638652939169850596[182] = 0.0;
   out_1638652939169850596[183] = 0.0;
   out_1638652939169850596[184] = 0.0;
   out_1638652939169850596[185] = 0.0;
   out_1638652939169850596[186] = 0.0;
   out_1638652939169850596[187] = 0.0;
   out_1638652939169850596[188] = 0.0;
   out_1638652939169850596[189] = 0.0;
   out_1638652939169850596[190] = 1.0;
   out_1638652939169850596[191] = 0.0;
   out_1638652939169850596[192] = 0.0;
   out_1638652939169850596[193] = 0.0;
   out_1638652939169850596[194] = 0.0;
   out_1638652939169850596[195] = 0.0;
   out_1638652939169850596[196] = 0.0;
   out_1638652939169850596[197] = 0.0;
   out_1638652939169850596[198] = 0.0;
   out_1638652939169850596[199] = 0.0;
   out_1638652939169850596[200] = 0.0;
   out_1638652939169850596[201] = 0.0;
   out_1638652939169850596[202] = 0.0;
   out_1638652939169850596[203] = 0.0;
   out_1638652939169850596[204] = 0.0;
   out_1638652939169850596[205] = 0.0;
   out_1638652939169850596[206] = 0.0;
   out_1638652939169850596[207] = 0.0;
   out_1638652939169850596[208] = 0.0;
   out_1638652939169850596[209] = 1.0;
   out_1638652939169850596[210] = 0.0;
   out_1638652939169850596[211] = 0.0;
   out_1638652939169850596[212] = 0.0;
   out_1638652939169850596[213] = 0.0;
   out_1638652939169850596[214] = 0.0;
   out_1638652939169850596[215] = 0.0;
   out_1638652939169850596[216] = 0.0;
   out_1638652939169850596[217] = 0.0;
   out_1638652939169850596[218] = 0.0;
   out_1638652939169850596[219] = 0.0;
   out_1638652939169850596[220] = 0.0;
   out_1638652939169850596[221] = 0.0;
   out_1638652939169850596[222] = 0.0;
   out_1638652939169850596[223] = 0.0;
   out_1638652939169850596[224] = 0.0;
   out_1638652939169850596[225] = 0.0;
   out_1638652939169850596[226] = 0.0;
   out_1638652939169850596[227] = 0.0;
   out_1638652939169850596[228] = 1.0;
   out_1638652939169850596[229] = 0.0;
   out_1638652939169850596[230] = 0.0;
   out_1638652939169850596[231] = 0.0;
   out_1638652939169850596[232] = 0.0;
   out_1638652939169850596[233] = 0.0;
   out_1638652939169850596[234] = 0.0;
   out_1638652939169850596[235] = 0.0;
   out_1638652939169850596[236] = 0.0;
   out_1638652939169850596[237] = 0.0;
   out_1638652939169850596[238] = 0.0;
   out_1638652939169850596[239] = 0.0;
   out_1638652939169850596[240] = 0.0;
   out_1638652939169850596[241] = 0.0;
   out_1638652939169850596[242] = 0.0;
   out_1638652939169850596[243] = 0.0;
   out_1638652939169850596[244] = 0.0;
   out_1638652939169850596[245] = 0.0;
   out_1638652939169850596[246] = 0.0;
   out_1638652939169850596[247] = 1.0;
   out_1638652939169850596[248] = 0.0;
   out_1638652939169850596[249] = 0.0;
   out_1638652939169850596[250] = 0.0;
   out_1638652939169850596[251] = 0.0;
   out_1638652939169850596[252] = 0.0;
   out_1638652939169850596[253] = 0.0;
   out_1638652939169850596[254] = 0.0;
   out_1638652939169850596[255] = 0.0;
   out_1638652939169850596[256] = 0.0;
   out_1638652939169850596[257] = 0.0;
   out_1638652939169850596[258] = 0.0;
   out_1638652939169850596[259] = 0.0;
   out_1638652939169850596[260] = 0.0;
   out_1638652939169850596[261] = 0.0;
   out_1638652939169850596[262] = 0.0;
   out_1638652939169850596[263] = 0.0;
   out_1638652939169850596[264] = 0.0;
   out_1638652939169850596[265] = 0.0;
   out_1638652939169850596[266] = 1.0;
   out_1638652939169850596[267] = 0.0;
   out_1638652939169850596[268] = 0.0;
   out_1638652939169850596[269] = 0.0;
   out_1638652939169850596[270] = 0.0;
   out_1638652939169850596[271] = 0.0;
   out_1638652939169850596[272] = 0.0;
   out_1638652939169850596[273] = 0.0;
   out_1638652939169850596[274] = 0.0;
   out_1638652939169850596[275] = 0.0;
   out_1638652939169850596[276] = 0.0;
   out_1638652939169850596[277] = 0.0;
   out_1638652939169850596[278] = 0.0;
   out_1638652939169850596[279] = 0.0;
   out_1638652939169850596[280] = 0.0;
   out_1638652939169850596[281] = 0.0;
   out_1638652939169850596[282] = 0.0;
   out_1638652939169850596[283] = 0.0;
   out_1638652939169850596[284] = 0.0;
   out_1638652939169850596[285] = 1.0;
   out_1638652939169850596[286] = 0.0;
   out_1638652939169850596[287] = 0.0;
   out_1638652939169850596[288] = 0.0;
   out_1638652939169850596[289] = 0.0;
   out_1638652939169850596[290] = 0.0;
   out_1638652939169850596[291] = 0.0;
   out_1638652939169850596[292] = 0.0;
   out_1638652939169850596[293] = 0.0;
   out_1638652939169850596[294] = 0.0;
   out_1638652939169850596[295] = 0.0;
   out_1638652939169850596[296] = 0.0;
   out_1638652939169850596[297] = 0.0;
   out_1638652939169850596[298] = 0.0;
   out_1638652939169850596[299] = 0.0;
   out_1638652939169850596[300] = 0.0;
   out_1638652939169850596[301] = 0.0;
   out_1638652939169850596[302] = 0.0;
   out_1638652939169850596[303] = 0.0;
   out_1638652939169850596[304] = 1.0;
   out_1638652939169850596[305] = 0.0;
   out_1638652939169850596[306] = 0.0;
   out_1638652939169850596[307] = 0.0;
   out_1638652939169850596[308] = 0.0;
   out_1638652939169850596[309] = 0.0;
   out_1638652939169850596[310] = 0.0;
   out_1638652939169850596[311] = 0.0;
   out_1638652939169850596[312] = 0.0;
   out_1638652939169850596[313] = 0.0;
   out_1638652939169850596[314] = 0.0;
   out_1638652939169850596[315] = 0.0;
   out_1638652939169850596[316] = 0.0;
   out_1638652939169850596[317] = 0.0;
   out_1638652939169850596[318] = 0.0;
   out_1638652939169850596[319] = 0.0;
   out_1638652939169850596[320] = 0.0;
   out_1638652939169850596[321] = 0.0;
   out_1638652939169850596[322] = 0.0;
   out_1638652939169850596[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2831397313375340905) {
   out_2831397313375340905[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2831397313375340905[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2831397313375340905[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2831397313375340905[3] = dt*state[12] + state[3];
   out_2831397313375340905[4] = dt*state[13] + state[4];
   out_2831397313375340905[5] = dt*state[14] + state[5];
   out_2831397313375340905[6] = state[6];
   out_2831397313375340905[7] = state[7];
   out_2831397313375340905[8] = state[8];
   out_2831397313375340905[9] = state[9];
   out_2831397313375340905[10] = state[10];
   out_2831397313375340905[11] = state[11];
   out_2831397313375340905[12] = state[12];
   out_2831397313375340905[13] = state[13];
   out_2831397313375340905[14] = state[14];
   out_2831397313375340905[15] = state[15];
   out_2831397313375340905[16] = state[16];
   out_2831397313375340905[17] = state[17];
}
void F_fun(double *state, double dt, double *out_852487606375420018) {
   out_852487606375420018[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_852487606375420018[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_852487606375420018[2] = 0;
   out_852487606375420018[3] = 0;
   out_852487606375420018[4] = 0;
   out_852487606375420018[5] = 0;
   out_852487606375420018[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_852487606375420018[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_852487606375420018[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_852487606375420018[9] = 0;
   out_852487606375420018[10] = 0;
   out_852487606375420018[11] = 0;
   out_852487606375420018[12] = 0;
   out_852487606375420018[13] = 0;
   out_852487606375420018[14] = 0;
   out_852487606375420018[15] = 0;
   out_852487606375420018[16] = 0;
   out_852487606375420018[17] = 0;
   out_852487606375420018[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_852487606375420018[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_852487606375420018[20] = 0;
   out_852487606375420018[21] = 0;
   out_852487606375420018[22] = 0;
   out_852487606375420018[23] = 0;
   out_852487606375420018[24] = 0;
   out_852487606375420018[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_852487606375420018[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_852487606375420018[27] = 0;
   out_852487606375420018[28] = 0;
   out_852487606375420018[29] = 0;
   out_852487606375420018[30] = 0;
   out_852487606375420018[31] = 0;
   out_852487606375420018[32] = 0;
   out_852487606375420018[33] = 0;
   out_852487606375420018[34] = 0;
   out_852487606375420018[35] = 0;
   out_852487606375420018[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_852487606375420018[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_852487606375420018[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_852487606375420018[39] = 0;
   out_852487606375420018[40] = 0;
   out_852487606375420018[41] = 0;
   out_852487606375420018[42] = 0;
   out_852487606375420018[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_852487606375420018[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_852487606375420018[45] = 0;
   out_852487606375420018[46] = 0;
   out_852487606375420018[47] = 0;
   out_852487606375420018[48] = 0;
   out_852487606375420018[49] = 0;
   out_852487606375420018[50] = 0;
   out_852487606375420018[51] = 0;
   out_852487606375420018[52] = 0;
   out_852487606375420018[53] = 0;
   out_852487606375420018[54] = 0;
   out_852487606375420018[55] = 0;
   out_852487606375420018[56] = 0;
   out_852487606375420018[57] = 1;
   out_852487606375420018[58] = 0;
   out_852487606375420018[59] = 0;
   out_852487606375420018[60] = 0;
   out_852487606375420018[61] = 0;
   out_852487606375420018[62] = 0;
   out_852487606375420018[63] = 0;
   out_852487606375420018[64] = 0;
   out_852487606375420018[65] = 0;
   out_852487606375420018[66] = dt;
   out_852487606375420018[67] = 0;
   out_852487606375420018[68] = 0;
   out_852487606375420018[69] = 0;
   out_852487606375420018[70] = 0;
   out_852487606375420018[71] = 0;
   out_852487606375420018[72] = 0;
   out_852487606375420018[73] = 0;
   out_852487606375420018[74] = 0;
   out_852487606375420018[75] = 0;
   out_852487606375420018[76] = 1;
   out_852487606375420018[77] = 0;
   out_852487606375420018[78] = 0;
   out_852487606375420018[79] = 0;
   out_852487606375420018[80] = 0;
   out_852487606375420018[81] = 0;
   out_852487606375420018[82] = 0;
   out_852487606375420018[83] = 0;
   out_852487606375420018[84] = 0;
   out_852487606375420018[85] = dt;
   out_852487606375420018[86] = 0;
   out_852487606375420018[87] = 0;
   out_852487606375420018[88] = 0;
   out_852487606375420018[89] = 0;
   out_852487606375420018[90] = 0;
   out_852487606375420018[91] = 0;
   out_852487606375420018[92] = 0;
   out_852487606375420018[93] = 0;
   out_852487606375420018[94] = 0;
   out_852487606375420018[95] = 1;
   out_852487606375420018[96] = 0;
   out_852487606375420018[97] = 0;
   out_852487606375420018[98] = 0;
   out_852487606375420018[99] = 0;
   out_852487606375420018[100] = 0;
   out_852487606375420018[101] = 0;
   out_852487606375420018[102] = 0;
   out_852487606375420018[103] = 0;
   out_852487606375420018[104] = dt;
   out_852487606375420018[105] = 0;
   out_852487606375420018[106] = 0;
   out_852487606375420018[107] = 0;
   out_852487606375420018[108] = 0;
   out_852487606375420018[109] = 0;
   out_852487606375420018[110] = 0;
   out_852487606375420018[111] = 0;
   out_852487606375420018[112] = 0;
   out_852487606375420018[113] = 0;
   out_852487606375420018[114] = 1;
   out_852487606375420018[115] = 0;
   out_852487606375420018[116] = 0;
   out_852487606375420018[117] = 0;
   out_852487606375420018[118] = 0;
   out_852487606375420018[119] = 0;
   out_852487606375420018[120] = 0;
   out_852487606375420018[121] = 0;
   out_852487606375420018[122] = 0;
   out_852487606375420018[123] = 0;
   out_852487606375420018[124] = 0;
   out_852487606375420018[125] = 0;
   out_852487606375420018[126] = 0;
   out_852487606375420018[127] = 0;
   out_852487606375420018[128] = 0;
   out_852487606375420018[129] = 0;
   out_852487606375420018[130] = 0;
   out_852487606375420018[131] = 0;
   out_852487606375420018[132] = 0;
   out_852487606375420018[133] = 1;
   out_852487606375420018[134] = 0;
   out_852487606375420018[135] = 0;
   out_852487606375420018[136] = 0;
   out_852487606375420018[137] = 0;
   out_852487606375420018[138] = 0;
   out_852487606375420018[139] = 0;
   out_852487606375420018[140] = 0;
   out_852487606375420018[141] = 0;
   out_852487606375420018[142] = 0;
   out_852487606375420018[143] = 0;
   out_852487606375420018[144] = 0;
   out_852487606375420018[145] = 0;
   out_852487606375420018[146] = 0;
   out_852487606375420018[147] = 0;
   out_852487606375420018[148] = 0;
   out_852487606375420018[149] = 0;
   out_852487606375420018[150] = 0;
   out_852487606375420018[151] = 0;
   out_852487606375420018[152] = 1;
   out_852487606375420018[153] = 0;
   out_852487606375420018[154] = 0;
   out_852487606375420018[155] = 0;
   out_852487606375420018[156] = 0;
   out_852487606375420018[157] = 0;
   out_852487606375420018[158] = 0;
   out_852487606375420018[159] = 0;
   out_852487606375420018[160] = 0;
   out_852487606375420018[161] = 0;
   out_852487606375420018[162] = 0;
   out_852487606375420018[163] = 0;
   out_852487606375420018[164] = 0;
   out_852487606375420018[165] = 0;
   out_852487606375420018[166] = 0;
   out_852487606375420018[167] = 0;
   out_852487606375420018[168] = 0;
   out_852487606375420018[169] = 0;
   out_852487606375420018[170] = 0;
   out_852487606375420018[171] = 1;
   out_852487606375420018[172] = 0;
   out_852487606375420018[173] = 0;
   out_852487606375420018[174] = 0;
   out_852487606375420018[175] = 0;
   out_852487606375420018[176] = 0;
   out_852487606375420018[177] = 0;
   out_852487606375420018[178] = 0;
   out_852487606375420018[179] = 0;
   out_852487606375420018[180] = 0;
   out_852487606375420018[181] = 0;
   out_852487606375420018[182] = 0;
   out_852487606375420018[183] = 0;
   out_852487606375420018[184] = 0;
   out_852487606375420018[185] = 0;
   out_852487606375420018[186] = 0;
   out_852487606375420018[187] = 0;
   out_852487606375420018[188] = 0;
   out_852487606375420018[189] = 0;
   out_852487606375420018[190] = 1;
   out_852487606375420018[191] = 0;
   out_852487606375420018[192] = 0;
   out_852487606375420018[193] = 0;
   out_852487606375420018[194] = 0;
   out_852487606375420018[195] = 0;
   out_852487606375420018[196] = 0;
   out_852487606375420018[197] = 0;
   out_852487606375420018[198] = 0;
   out_852487606375420018[199] = 0;
   out_852487606375420018[200] = 0;
   out_852487606375420018[201] = 0;
   out_852487606375420018[202] = 0;
   out_852487606375420018[203] = 0;
   out_852487606375420018[204] = 0;
   out_852487606375420018[205] = 0;
   out_852487606375420018[206] = 0;
   out_852487606375420018[207] = 0;
   out_852487606375420018[208] = 0;
   out_852487606375420018[209] = 1;
   out_852487606375420018[210] = 0;
   out_852487606375420018[211] = 0;
   out_852487606375420018[212] = 0;
   out_852487606375420018[213] = 0;
   out_852487606375420018[214] = 0;
   out_852487606375420018[215] = 0;
   out_852487606375420018[216] = 0;
   out_852487606375420018[217] = 0;
   out_852487606375420018[218] = 0;
   out_852487606375420018[219] = 0;
   out_852487606375420018[220] = 0;
   out_852487606375420018[221] = 0;
   out_852487606375420018[222] = 0;
   out_852487606375420018[223] = 0;
   out_852487606375420018[224] = 0;
   out_852487606375420018[225] = 0;
   out_852487606375420018[226] = 0;
   out_852487606375420018[227] = 0;
   out_852487606375420018[228] = 1;
   out_852487606375420018[229] = 0;
   out_852487606375420018[230] = 0;
   out_852487606375420018[231] = 0;
   out_852487606375420018[232] = 0;
   out_852487606375420018[233] = 0;
   out_852487606375420018[234] = 0;
   out_852487606375420018[235] = 0;
   out_852487606375420018[236] = 0;
   out_852487606375420018[237] = 0;
   out_852487606375420018[238] = 0;
   out_852487606375420018[239] = 0;
   out_852487606375420018[240] = 0;
   out_852487606375420018[241] = 0;
   out_852487606375420018[242] = 0;
   out_852487606375420018[243] = 0;
   out_852487606375420018[244] = 0;
   out_852487606375420018[245] = 0;
   out_852487606375420018[246] = 0;
   out_852487606375420018[247] = 1;
   out_852487606375420018[248] = 0;
   out_852487606375420018[249] = 0;
   out_852487606375420018[250] = 0;
   out_852487606375420018[251] = 0;
   out_852487606375420018[252] = 0;
   out_852487606375420018[253] = 0;
   out_852487606375420018[254] = 0;
   out_852487606375420018[255] = 0;
   out_852487606375420018[256] = 0;
   out_852487606375420018[257] = 0;
   out_852487606375420018[258] = 0;
   out_852487606375420018[259] = 0;
   out_852487606375420018[260] = 0;
   out_852487606375420018[261] = 0;
   out_852487606375420018[262] = 0;
   out_852487606375420018[263] = 0;
   out_852487606375420018[264] = 0;
   out_852487606375420018[265] = 0;
   out_852487606375420018[266] = 1;
   out_852487606375420018[267] = 0;
   out_852487606375420018[268] = 0;
   out_852487606375420018[269] = 0;
   out_852487606375420018[270] = 0;
   out_852487606375420018[271] = 0;
   out_852487606375420018[272] = 0;
   out_852487606375420018[273] = 0;
   out_852487606375420018[274] = 0;
   out_852487606375420018[275] = 0;
   out_852487606375420018[276] = 0;
   out_852487606375420018[277] = 0;
   out_852487606375420018[278] = 0;
   out_852487606375420018[279] = 0;
   out_852487606375420018[280] = 0;
   out_852487606375420018[281] = 0;
   out_852487606375420018[282] = 0;
   out_852487606375420018[283] = 0;
   out_852487606375420018[284] = 0;
   out_852487606375420018[285] = 1;
   out_852487606375420018[286] = 0;
   out_852487606375420018[287] = 0;
   out_852487606375420018[288] = 0;
   out_852487606375420018[289] = 0;
   out_852487606375420018[290] = 0;
   out_852487606375420018[291] = 0;
   out_852487606375420018[292] = 0;
   out_852487606375420018[293] = 0;
   out_852487606375420018[294] = 0;
   out_852487606375420018[295] = 0;
   out_852487606375420018[296] = 0;
   out_852487606375420018[297] = 0;
   out_852487606375420018[298] = 0;
   out_852487606375420018[299] = 0;
   out_852487606375420018[300] = 0;
   out_852487606375420018[301] = 0;
   out_852487606375420018[302] = 0;
   out_852487606375420018[303] = 0;
   out_852487606375420018[304] = 1;
   out_852487606375420018[305] = 0;
   out_852487606375420018[306] = 0;
   out_852487606375420018[307] = 0;
   out_852487606375420018[308] = 0;
   out_852487606375420018[309] = 0;
   out_852487606375420018[310] = 0;
   out_852487606375420018[311] = 0;
   out_852487606375420018[312] = 0;
   out_852487606375420018[313] = 0;
   out_852487606375420018[314] = 0;
   out_852487606375420018[315] = 0;
   out_852487606375420018[316] = 0;
   out_852487606375420018[317] = 0;
   out_852487606375420018[318] = 0;
   out_852487606375420018[319] = 0;
   out_852487606375420018[320] = 0;
   out_852487606375420018[321] = 0;
   out_852487606375420018[322] = 0;
   out_852487606375420018[323] = 1;
}
void h_4(double *state, double *unused, double *out_6027168379751608829) {
   out_6027168379751608829[0] = state[6] + state[9];
   out_6027168379751608829[1] = state[7] + state[10];
   out_6027168379751608829[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4209428867582108125) {
   out_4209428867582108125[0] = 0;
   out_4209428867582108125[1] = 0;
   out_4209428867582108125[2] = 0;
   out_4209428867582108125[3] = 0;
   out_4209428867582108125[4] = 0;
   out_4209428867582108125[5] = 0;
   out_4209428867582108125[6] = 1;
   out_4209428867582108125[7] = 0;
   out_4209428867582108125[8] = 0;
   out_4209428867582108125[9] = 1;
   out_4209428867582108125[10] = 0;
   out_4209428867582108125[11] = 0;
   out_4209428867582108125[12] = 0;
   out_4209428867582108125[13] = 0;
   out_4209428867582108125[14] = 0;
   out_4209428867582108125[15] = 0;
   out_4209428867582108125[16] = 0;
   out_4209428867582108125[17] = 0;
   out_4209428867582108125[18] = 0;
   out_4209428867582108125[19] = 0;
   out_4209428867582108125[20] = 0;
   out_4209428867582108125[21] = 0;
   out_4209428867582108125[22] = 0;
   out_4209428867582108125[23] = 0;
   out_4209428867582108125[24] = 0;
   out_4209428867582108125[25] = 1;
   out_4209428867582108125[26] = 0;
   out_4209428867582108125[27] = 0;
   out_4209428867582108125[28] = 1;
   out_4209428867582108125[29] = 0;
   out_4209428867582108125[30] = 0;
   out_4209428867582108125[31] = 0;
   out_4209428867582108125[32] = 0;
   out_4209428867582108125[33] = 0;
   out_4209428867582108125[34] = 0;
   out_4209428867582108125[35] = 0;
   out_4209428867582108125[36] = 0;
   out_4209428867582108125[37] = 0;
   out_4209428867582108125[38] = 0;
   out_4209428867582108125[39] = 0;
   out_4209428867582108125[40] = 0;
   out_4209428867582108125[41] = 0;
   out_4209428867582108125[42] = 0;
   out_4209428867582108125[43] = 0;
   out_4209428867582108125[44] = 1;
   out_4209428867582108125[45] = 0;
   out_4209428867582108125[46] = 0;
   out_4209428867582108125[47] = 1;
   out_4209428867582108125[48] = 0;
   out_4209428867582108125[49] = 0;
   out_4209428867582108125[50] = 0;
   out_4209428867582108125[51] = 0;
   out_4209428867582108125[52] = 0;
   out_4209428867582108125[53] = 0;
}
void h_10(double *state, double *unused, double *out_744954405419605369) {
   out_744954405419605369[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_744954405419605369[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_744954405419605369[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4888049829332208881) {
   out_4888049829332208881[0] = 0;
   out_4888049829332208881[1] = 9.8100000000000005*cos(state[1]);
   out_4888049829332208881[2] = 0;
   out_4888049829332208881[3] = 0;
   out_4888049829332208881[4] = -state[8];
   out_4888049829332208881[5] = state[7];
   out_4888049829332208881[6] = 0;
   out_4888049829332208881[7] = state[5];
   out_4888049829332208881[8] = -state[4];
   out_4888049829332208881[9] = 0;
   out_4888049829332208881[10] = 0;
   out_4888049829332208881[11] = 0;
   out_4888049829332208881[12] = 1;
   out_4888049829332208881[13] = 0;
   out_4888049829332208881[14] = 0;
   out_4888049829332208881[15] = 1;
   out_4888049829332208881[16] = 0;
   out_4888049829332208881[17] = 0;
   out_4888049829332208881[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4888049829332208881[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4888049829332208881[20] = 0;
   out_4888049829332208881[21] = state[8];
   out_4888049829332208881[22] = 0;
   out_4888049829332208881[23] = -state[6];
   out_4888049829332208881[24] = -state[5];
   out_4888049829332208881[25] = 0;
   out_4888049829332208881[26] = state[3];
   out_4888049829332208881[27] = 0;
   out_4888049829332208881[28] = 0;
   out_4888049829332208881[29] = 0;
   out_4888049829332208881[30] = 0;
   out_4888049829332208881[31] = 1;
   out_4888049829332208881[32] = 0;
   out_4888049829332208881[33] = 0;
   out_4888049829332208881[34] = 1;
   out_4888049829332208881[35] = 0;
   out_4888049829332208881[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4888049829332208881[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4888049829332208881[38] = 0;
   out_4888049829332208881[39] = -state[7];
   out_4888049829332208881[40] = state[6];
   out_4888049829332208881[41] = 0;
   out_4888049829332208881[42] = state[4];
   out_4888049829332208881[43] = -state[3];
   out_4888049829332208881[44] = 0;
   out_4888049829332208881[45] = 0;
   out_4888049829332208881[46] = 0;
   out_4888049829332208881[47] = 0;
   out_4888049829332208881[48] = 0;
   out_4888049829332208881[49] = 0;
   out_4888049829332208881[50] = 1;
   out_4888049829332208881[51] = 0;
   out_4888049829332208881[52] = 0;
   out_4888049829332208881[53] = 1;
}
void h_13(double *state, double *unused, double *out_6652718215234119768) {
   out_6652718215234119768[0] = state[3];
   out_6652718215234119768[1] = state[4];
   out_6652718215234119768[2] = state[5];
}
void H_13(double *state, double *unused, double *out_997155042249775324) {
   out_997155042249775324[0] = 0;
   out_997155042249775324[1] = 0;
   out_997155042249775324[2] = 0;
   out_997155042249775324[3] = 1;
   out_997155042249775324[4] = 0;
   out_997155042249775324[5] = 0;
   out_997155042249775324[6] = 0;
   out_997155042249775324[7] = 0;
   out_997155042249775324[8] = 0;
   out_997155042249775324[9] = 0;
   out_997155042249775324[10] = 0;
   out_997155042249775324[11] = 0;
   out_997155042249775324[12] = 0;
   out_997155042249775324[13] = 0;
   out_997155042249775324[14] = 0;
   out_997155042249775324[15] = 0;
   out_997155042249775324[16] = 0;
   out_997155042249775324[17] = 0;
   out_997155042249775324[18] = 0;
   out_997155042249775324[19] = 0;
   out_997155042249775324[20] = 0;
   out_997155042249775324[21] = 0;
   out_997155042249775324[22] = 1;
   out_997155042249775324[23] = 0;
   out_997155042249775324[24] = 0;
   out_997155042249775324[25] = 0;
   out_997155042249775324[26] = 0;
   out_997155042249775324[27] = 0;
   out_997155042249775324[28] = 0;
   out_997155042249775324[29] = 0;
   out_997155042249775324[30] = 0;
   out_997155042249775324[31] = 0;
   out_997155042249775324[32] = 0;
   out_997155042249775324[33] = 0;
   out_997155042249775324[34] = 0;
   out_997155042249775324[35] = 0;
   out_997155042249775324[36] = 0;
   out_997155042249775324[37] = 0;
   out_997155042249775324[38] = 0;
   out_997155042249775324[39] = 0;
   out_997155042249775324[40] = 0;
   out_997155042249775324[41] = 1;
   out_997155042249775324[42] = 0;
   out_997155042249775324[43] = 0;
   out_997155042249775324[44] = 0;
   out_997155042249775324[45] = 0;
   out_997155042249775324[46] = 0;
   out_997155042249775324[47] = 0;
   out_997155042249775324[48] = 0;
   out_997155042249775324[49] = 0;
   out_997155042249775324[50] = 0;
   out_997155042249775324[51] = 0;
   out_997155042249775324[52] = 0;
   out_997155042249775324[53] = 0;
}
void h_14(double *state, double *unused, double *out_7748768270616969343) {
   out_7748768270616969343[0] = state[6];
   out_7748768270616969343[1] = state[7];
   out_7748768270616969343[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4644545394226991724) {
   out_4644545394226991724[0] = 0;
   out_4644545394226991724[1] = 0;
   out_4644545394226991724[2] = 0;
   out_4644545394226991724[3] = 0;
   out_4644545394226991724[4] = 0;
   out_4644545394226991724[5] = 0;
   out_4644545394226991724[6] = 1;
   out_4644545394226991724[7] = 0;
   out_4644545394226991724[8] = 0;
   out_4644545394226991724[9] = 0;
   out_4644545394226991724[10] = 0;
   out_4644545394226991724[11] = 0;
   out_4644545394226991724[12] = 0;
   out_4644545394226991724[13] = 0;
   out_4644545394226991724[14] = 0;
   out_4644545394226991724[15] = 0;
   out_4644545394226991724[16] = 0;
   out_4644545394226991724[17] = 0;
   out_4644545394226991724[18] = 0;
   out_4644545394226991724[19] = 0;
   out_4644545394226991724[20] = 0;
   out_4644545394226991724[21] = 0;
   out_4644545394226991724[22] = 0;
   out_4644545394226991724[23] = 0;
   out_4644545394226991724[24] = 0;
   out_4644545394226991724[25] = 1;
   out_4644545394226991724[26] = 0;
   out_4644545394226991724[27] = 0;
   out_4644545394226991724[28] = 0;
   out_4644545394226991724[29] = 0;
   out_4644545394226991724[30] = 0;
   out_4644545394226991724[31] = 0;
   out_4644545394226991724[32] = 0;
   out_4644545394226991724[33] = 0;
   out_4644545394226991724[34] = 0;
   out_4644545394226991724[35] = 0;
   out_4644545394226991724[36] = 0;
   out_4644545394226991724[37] = 0;
   out_4644545394226991724[38] = 0;
   out_4644545394226991724[39] = 0;
   out_4644545394226991724[40] = 0;
   out_4644545394226991724[41] = 0;
   out_4644545394226991724[42] = 0;
   out_4644545394226991724[43] = 0;
   out_4644545394226991724[44] = 1;
   out_4644545394226991724[45] = 0;
   out_4644545394226991724[46] = 0;
   out_4644545394226991724[47] = 0;
   out_4644545394226991724[48] = 0;
   out_4644545394226991724[49] = 0;
   out_4644545394226991724[50] = 0;
   out_4644545394226991724[51] = 0;
   out_4644545394226991724[52] = 0;
   out_4644545394226991724[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_309314752274053340) {
  err_fun(nom_x, delta_x, out_309314752274053340);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_651338713617187314) {
  inv_err_fun(nom_x, true_x, out_651338713617187314);
}
void pose_H_mod_fun(double *state, double *out_1638652939169850596) {
  H_mod_fun(state, out_1638652939169850596);
}
void pose_f_fun(double *state, double dt, double *out_2831397313375340905) {
  f_fun(state,  dt, out_2831397313375340905);
}
void pose_F_fun(double *state, double dt, double *out_852487606375420018) {
  F_fun(state,  dt, out_852487606375420018);
}
void pose_h_4(double *state, double *unused, double *out_6027168379751608829) {
  h_4(state, unused, out_6027168379751608829);
}
void pose_H_4(double *state, double *unused, double *out_4209428867582108125) {
  H_4(state, unused, out_4209428867582108125);
}
void pose_h_10(double *state, double *unused, double *out_744954405419605369) {
  h_10(state, unused, out_744954405419605369);
}
void pose_H_10(double *state, double *unused, double *out_4888049829332208881) {
  H_10(state, unused, out_4888049829332208881);
}
void pose_h_13(double *state, double *unused, double *out_6652718215234119768) {
  h_13(state, unused, out_6652718215234119768);
}
void pose_H_13(double *state, double *unused, double *out_997155042249775324) {
  H_13(state, unused, out_997155042249775324);
}
void pose_h_14(double *state, double *unused, double *out_7748768270616969343) {
  h_14(state, unused, out_7748768270616969343);
}
void pose_H_14(double *state, double *unused, double *out_4644545394226991724) {
  H_14(state, unused, out_4644545394226991724);
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
