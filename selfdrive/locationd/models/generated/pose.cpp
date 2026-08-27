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
void err_fun(double *nom_x, double *delta_x, double *out_1384224859777021071) {
   out_1384224859777021071[0] = delta_x[0] + nom_x[0];
   out_1384224859777021071[1] = delta_x[1] + nom_x[1];
   out_1384224859777021071[2] = delta_x[2] + nom_x[2];
   out_1384224859777021071[3] = delta_x[3] + nom_x[3];
   out_1384224859777021071[4] = delta_x[4] + nom_x[4];
   out_1384224859777021071[5] = delta_x[5] + nom_x[5];
   out_1384224859777021071[6] = delta_x[6] + nom_x[6];
   out_1384224859777021071[7] = delta_x[7] + nom_x[7];
   out_1384224859777021071[8] = delta_x[8] + nom_x[8];
   out_1384224859777021071[9] = delta_x[9] + nom_x[9];
   out_1384224859777021071[10] = delta_x[10] + nom_x[10];
   out_1384224859777021071[11] = delta_x[11] + nom_x[11];
   out_1384224859777021071[12] = delta_x[12] + nom_x[12];
   out_1384224859777021071[13] = delta_x[13] + nom_x[13];
   out_1384224859777021071[14] = delta_x[14] + nom_x[14];
   out_1384224859777021071[15] = delta_x[15] + nom_x[15];
   out_1384224859777021071[16] = delta_x[16] + nom_x[16];
   out_1384224859777021071[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6553735098488367695) {
   out_6553735098488367695[0] = -nom_x[0] + true_x[0];
   out_6553735098488367695[1] = -nom_x[1] + true_x[1];
   out_6553735098488367695[2] = -nom_x[2] + true_x[2];
   out_6553735098488367695[3] = -nom_x[3] + true_x[3];
   out_6553735098488367695[4] = -nom_x[4] + true_x[4];
   out_6553735098488367695[5] = -nom_x[5] + true_x[5];
   out_6553735098488367695[6] = -nom_x[6] + true_x[6];
   out_6553735098488367695[7] = -nom_x[7] + true_x[7];
   out_6553735098488367695[8] = -nom_x[8] + true_x[8];
   out_6553735098488367695[9] = -nom_x[9] + true_x[9];
   out_6553735098488367695[10] = -nom_x[10] + true_x[10];
   out_6553735098488367695[11] = -nom_x[11] + true_x[11];
   out_6553735098488367695[12] = -nom_x[12] + true_x[12];
   out_6553735098488367695[13] = -nom_x[13] + true_x[13];
   out_6553735098488367695[14] = -nom_x[14] + true_x[14];
   out_6553735098488367695[15] = -nom_x[15] + true_x[15];
   out_6553735098488367695[16] = -nom_x[16] + true_x[16];
   out_6553735098488367695[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7066952806100897033) {
   out_7066952806100897033[0] = 1.0;
   out_7066952806100897033[1] = 0.0;
   out_7066952806100897033[2] = 0.0;
   out_7066952806100897033[3] = 0.0;
   out_7066952806100897033[4] = 0.0;
   out_7066952806100897033[5] = 0.0;
   out_7066952806100897033[6] = 0.0;
   out_7066952806100897033[7] = 0.0;
   out_7066952806100897033[8] = 0.0;
   out_7066952806100897033[9] = 0.0;
   out_7066952806100897033[10] = 0.0;
   out_7066952806100897033[11] = 0.0;
   out_7066952806100897033[12] = 0.0;
   out_7066952806100897033[13] = 0.0;
   out_7066952806100897033[14] = 0.0;
   out_7066952806100897033[15] = 0.0;
   out_7066952806100897033[16] = 0.0;
   out_7066952806100897033[17] = 0.0;
   out_7066952806100897033[18] = 0.0;
   out_7066952806100897033[19] = 1.0;
   out_7066952806100897033[20] = 0.0;
   out_7066952806100897033[21] = 0.0;
   out_7066952806100897033[22] = 0.0;
   out_7066952806100897033[23] = 0.0;
   out_7066952806100897033[24] = 0.0;
   out_7066952806100897033[25] = 0.0;
   out_7066952806100897033[26] = 0.0;
   out_7066952806100897033[27] = 0.0;
   out_7066952806100897033[28] = 0.0;
   out_7066952806100897033[29] = 0.0;
   out_7066952806100897033[30] = 0.0;
   out_7066952806100897033[31] = 0.0;
   out_7066952806100897033[32] = 0.0;
   out_7066952806100897033[33] = 0.0;
   out_7066952806100897033[34] = 0.0;
   out_7066952806100897033[35] = 0.0;
   out_7066952806100897033[36] = 0.0;
   out_7066952806100897033[37] = 0.0;
   out_7066952806100897033[38] = 1.0;
   out_7066952806100897033[39] = 0.0;
   out_7066952806100897033[40] = 0.0;
   out_7066952806100897033[41] = 0.0;
   out_7066952806100897033[42] = 0.0;
   out_7066952806100897033[43] = 0.0;
   out_7066952806100897033[44] = 0.0;
   out_7066952806100897033[45] = 0.0;
   out_7066952806100897033[46] = 0.0;
   out_7066952806100897033[47] = 0.0;
   out_7066952806100897033[48] = 0.0;
   out_7066952806100897033[49] = 0.0;
   out_7066952806100897033[50] = 0.0;
   out_7066952806100897033[51] = 0.0;
   out_7066952806100897033[52] = 0.0;
   out_7066952806100897033[53] = 0.0;
   out_7066952806100897033[54] = 0.0;
   out_7066952806100897033[55] = 0.0;
   out_7066952806100897033[56] = 0.0;
   out_7066952806100897033[57] = 1.0;
   out_7066952806100897033[58] = 0.0;
   out_7066952806100897033[59] = 0.0;
   out_7066952806100897033[60] = 0.0;
   out_7066952806100897033[61] = 0.0;
   out_7066952806100897033[62] = 0.0;
   out_7066952806100897033[63] = 0.0;
   out_7066952806100897033[64] = 0.0;
   out_7066952806100897033[65] = 0.0;
   out_7066952806100897033[66] = 0.0;
   out_7066952806100897033[67] = 0.0;
   out_7066952806100897033[68] = 0.0;
   out_7066952806100897033[69] = 0.0;
   out_7066952806100897033[70] = 0.0;
   out_7066952806100897033[71] = 0.0;
   out_7066952806100897033[72] = 0.0;
   out_7066952806100897033[73] = 0.0;
   out_7066952806100897033[74] = 0.0;
   out_7066952806100897033[75] = 0.0;
   out_7066952806100897033[76] = 1.0;
   out_7066952806100897033[77] = 0.0;
   out_7066952806100897033[78] = 0.0;
   out_7066952806100897033[79] = 0.0;
   out_7066952806100897033[80] = 0.0;
   out_7066952806100897033[81] = 0.0;
   out_7066952806100897033[82] = 0.0;
   out_7066952806100897033[83] = 0.0;
   out_7066952806100897033[84] = 0.0;
   out_7066952806100897033[85] = 0.0;
   out_7066952806100897033[86] = 0.0;
   out_7066952806100897033[87] = 0.0;
   out_7066952806100897033[88] = 0.0;
   out_7066952806100897033[89] = 0.0;
   out_7066952806100897033[90] = 0.0;
   out_7066952806100897033[91] = 0.0;
   out_7066952806100897033[92] = 0.0;
   out_7066952806100897033[93] = 0.0;
   out_7066952806100897033[94] = 0.0;
   out_7066952806100897033[95] = 1.0;
   out_7066952806100897033[96] = 0.0;
   out_7066952806100897033[97] = 0.0;
   out_7066952806100897033[98] = 0.0;
   out_7066952806100897033[99] = 0.0;
   out_7066952806100897033[100] = 0.0;
   out_7066952806100897033[101] = 0.0;
   out_7066952806100897033[102] = 0.0;
   out_7066952806100897033[103] = 0.0;
   out_7066952806100897033[104] = 0.0;
   out_7066952806100897033[105] = 0.0;
   out_7066952806100897033[106] = 0.0;
   out_7066952806100897033[107] = 0.0;
   out_7066952806100897033[108] = 0.0;
   out_7066952806100897033[109] = 0.0;
   out_7066952806100897033[110] = 0.0;
   out_7066952806100897033[111] = 0.0;
   out_7066952806100897033[112] = 0.0;
   out_7066952806100897033[113] = 0.0;
   out_7066952806100897033[114] = 1.0;
   out_7066952806100897033[115] = 0.0;
   out_7066952806100897033[116] = 0.0;
   out_7066952806100897033[117] = 0.0;
   out_7066952806100897033[118] = 0.0;
   out_7066952806100897033[119] = 0.0;
   out_7066952806100897033[120] = 0.0;
   out_7066952806100897033[121] = 0.0;
   out_7066952806100897033[122] = 0.0;
   out_7066952806100897033[123] = 0.0;
   out_7066952806100897033[124] = 0.0;
   out_7066952806100897033[125] = 0.0;
   out_7066952806100897033[126] = 0.0;
   out_7066952806100897033[127] = 0.0;
   out_7066952806100897033[128] = 0.0;
   out_7066952806100897033[129] = 0.0;
   out_7066952806100897033[130] = 0.0;
   out_7066952806100897033[131] = 0.0;
   out_7066952806100897033[132] = 0.0;
   out_7066952806100897033[133] = 1.0;
   out_7066952806100897033[134] = 0.0;
   out_7066952806100897033[135] = 0.0;
   out_7066952806100897033[136] = 0.0;
   out_7066952806100897033[137] = 0.0;
   out_7066952806100897033[138] = 0.0;
   out_7066952806100897033[139] = 0.0;
   out_7066952806100897033[140] = 0.0;
   out_7066952806100897033[141] = 0.0;
   out_7066952806100897033[142] = 0.0;
   out_7066952806100897033[143] = 0.0;
   out_7066952806100897033[144] = 0.0;
   out_7066952806100897033[145] = 0.0;
   out_7066952806100897033[146] = 0.0;
   out_7066952806100897033[147] = 0.0;
   out_7066952806100897033[148] = 0.0;
   out_7066952806100897033[149] = 0.0;
   out_7066952806100897033[150] = 0.0;
   out_7066952806100897033[151] = 0.0;
   out_7066952806100897033[152] = 1.0;
   out_7066952806100897033[153] = 0.0;
   out_7066952806100897033[154] = 0.0;
   out_7066952806100897033[155] = 0.0;
   out_7066952806100897033[156] = 0.0;
   out_7066952806100897033[157] = 0.0;
   out_7066952806100897033[158] = 0.0;
   out_7066952806100897033[159] = 0.0;
   out_7066952806100897033[160] = 0.0;
   out_7066952806100897033[161] = 0.0;
   out_7066952806100897033[162] = 0.0;
   out_7066952806100897033[163] = 0.0;
   out_7066952806100897033[164] = 0.0;
   out_7066952806100897033[165] = 0.0;
   out_7066952806100897033[166] = 0.0;
   out_7066952806100897033[167] = 0.0;
   out_7066952806100897033[168] = 0.0;
   out_7066952806100897033[169] = 0.0;
   out_7066952806100897033[170] = 0.0;
   out_7066952806100897033[171] = 1.0;
   out_7066952806100897033[172] = 0.0;
   out_7066952806100897033[173] = 0.0;
   out_7066952806100897033[174] = 0.0;
   out_7066952806100897033[175] = 0.0;
   out_7066952806100897033[176] = 0.0;
   out_7066952806100897033[177] = 0.0;
   out_7066952806100897033[178] = 0.0;
   out_7066952806100897033[179] = 0.0;
   out_7066952806100897033[180] = 0.0;
   out_7066952806100897033[181] = 0.0;
   out_7066952806100897033[182] = 0.0;
   out_7066952806100897033[183] = 0.0;
   out_7066952806100897033[184] = 0.0;
   out_7066952806100897033[185] = 0.0;
   out_7066952806100897033[186] = 0.0;
   out_7066952806100897033[187] = 0.0;
   out_7066952806100897033[188] = 0.0;
   out_7066952806100897033[189] = 0.0;
   out_7066952806100897033[190] = 1.0;
   out_7066952806100897033[191] = 0.0;
   out_7066952806100897033[192] = 0.0;
   out_7066952806100897033[193] = 0.0;
   out_7066952806100897033[194] = 0.0;
   out_7066952806100897033[195] = 0.0;
   out_7066952806100897033[196] = 0.0;
   out_7066952806100897033[197] = 0.0;
   out_7066952806100897033[198] = 0.0;
   out_7066952806100897033[199] = 0.0;
   out_7066952806100897033[200] = 0.0;
   out_7066952806100897033[201] = 0.0;
   out_7066952806100897033[202] = 0.0;
   out_7066952806100897033[203] = 0.0;
   out_7066952806100897033[204] = 0.0;
   out_7066952806100897033[205] = 0.0;
   out_7066952806100897033[206] = 0.0;
   out_7066952806100897033[207] = 0.0;
   out_7066952806100897033[208] = 0.0;
   out_7066952806100897033[209] = 1.0;
   out_7066952806100897033[210] = 0.0;
   out_7066952806100897033[211] = 0.0;
   out_7066952806100897033[212] = 0.0;
   out_7066952806100897033[213] = 0.0;
   out_7066952806100897033[214] = 0.0;
   out_7066952806100897033[215] = 0.0;
   out_7066952806100897033[216] = 0.0;
   out_7066952806100897033[217] = 0.0;
   out_7066952806100897033[218] = 0.0;
   out_7066952806100897033[219] = 0.0;
   out_7066952806100897033[220] = 0.0;
   out_7066952806100897033[221] = 0.0;
   out_7066952806100897033[222] = 0.0;
   out_7066952806100897033[223] = 0.0;
   out_7066952806100897033[224] = 0.0;
   out_7066952806100897033[225] = 0.0;
   out_7066952806100897033[226] = 0.0;
   out_7066952806100897033[227] = 0.0;
   out_7066952806100897033[228] = 1.0;
   out_7066952806100897033[229] = 0.0;
   out_7066952806100897033[230] = 0.0;
   out_7066952806100897033[231] = 0.0;
   out_7066952806100897033[232] = 0.0;
   out_7066952806100897033[233] = 0.0;
   out_7066952806100897033[234] = 0.0;
   out_7066952806100897033[235] = 0.0;
   out_7066952806100897033[236] = 0.0;
   out_7066952806100897033[237] = 0.0;
   out_7066952806100897033[238] = 0.0;
   out_7066952806100897033[239] = 0.0;
   out_7066952806100897033[240] = 0.0;
   out_7066952806100897033[241] = 0.0;
   out_7066952806100897033[242] = 0.0;
   out_7066952806100897033[243] = 0.0;
   out_7066952806100897033[244] = 0.0;
   out_7066952806100897033[245] = 0.0;
   out_7066952806100897033[246] = 0.0;
   out_7066952806100897033[247] = 1.0;
   out_7066952806100897033[248] = 0.0;
   out_7066952806100897033[249] = 0.0;
   out_7066952806100897033[250] = 0.0;
   out_7066952806100897033[251] = 0.0;
   out_7066952806100897033[252] = 0.0;
   out_7066952806100897033[253] = 0.0;
   out_7066952806100897033[254] = 0.0;
   out_7066952806100897033[255] = 0.0;
   out_7066952806100897033[256] = 0.0;
   out_7066952806100897033[257] = 0.0;
   out_7066952806100897033[258] = 0.0;
   out_7066952806100897033[259] = 0.0;
   out_7066952806100897033[260] = 0.0;
   out_7066952806100897033[261] = 0.0;
   out_7066952806100897033[262] = 0.0;
   out_7066952806100897033[263] = 0.0;
   out_7066952806100897033[264] = 0.0;
   out_7066952806100897033[265] = 0.0;
   out_7066952806100897033[266] = 1.0;
   out_7066952806100897033[267] = 0.0;
   out_7066952806100897033[268] = 0.0;
   out_7066952806100897033[269] = 0.0;
   out_7066952806100897033[270] = 0.0;
   out_7066952806100897033[271] = 0.0;
   out_7066952806100897033[272] = 0.0;
   out_7066952806100897033[273] = 0.0;
   out_7066952806100897033[274] = 0.0;
   out_7066952806100897033[275] = 0.0;
   out_7066952806100897033[276] = 0.0;
   out_7066952806100897033[277] = 0.0;
   out_7066952806100897033[278] = 0.0;
   out_7066952806100897033[279] = 0.0;
   out_7066952806100897033[280] = 0.0;
   out_7066952806100897033[281] = 0.0;
   out_7066952806100897033[282] = 0.0;
   out_7066952806100897033[283] = 0.0;
   out_7066952806100897033[284] = 0.0;
   out_7066952806100897033[285] = 1.0;
   out_7066952806100897033[286] = 0.0;
   out_7066952806100897033[287] = 0.0;
   out_7066952806100897033[288] = 0.0;
   out_7066952806100897033[289] = 0.0;
   out_7066952806100897033[290] = 0.0;
   out_7066952806100897033[291] = 0.0;
   out_7066952806100897033[292] = 0.0;
   out_7066952806100897033[293] = 0.0;
   out_7066952806100897033[294] = 0.0;
   out_7066952806100897033[295] = 0.0;
   out_7066952806100897033[296] = 0.0;
   out_7066952806100897033[297] = 0.0;
   out_7066952806100897033[298] = 0.0;
   out_7066952806100897033[299] = 0.0;
   out_7066952806100897033[300] = 0.0;
   out_7066952806100897033[301] = 0.0;
   out_7066952806100897033[302] = 0.0;
   out_7066952806100897033[303] = 0.0;
   out_7066952806100897033[304] = 1.0;
   out_7066952806100897033[305] = 0.0;
   out_7066952806100897033[306] = 0.0;
   out_7066952806100897033[307] = 0.0;
   out_7066952806100897033[308] = 0.0;
   out_7066952806100897033[309] = 0.0;
   out_7066952806100897033[310] = 0.0;
   out_7066952806100897033[311] = 0.0;
   out_7066952806100897033[312] = 0.0;
   out_7066952806100897033[313] = 0.0;
   out_7066952806100897033[314] = 0.0;
   out_7066952806100897033[315] = 0.0;
   out_7066952806100897033[316] = 0.0;
   out_7066952806100897033[317] = 0.0;
   out_7066952806100897033[318] = 0.0;
   out_7066952806100897033[319] = 0.0;
   out_7066952806100897033[320] = 0.0;
   out_7066952806100897033[321] = 0.0;
   out_7066952806100897033[322] = 0.0;
   out_7066952806100897033[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5431061979149799049) {
   out_5431061979149799049[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5431061979149799049[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5431061979149799049[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5431061979149799049[3] = dt*state[12] + state[3];
   out_5431061979149799049[4] = dt*state[13] + state[4];
   out_5431061979149799049[5] = dt*state[14] + state[5];
   out_5431061979149799049[6] = state[6];
   out_5431061979149799049[7] = state[7];
   out_5431061979149799049[8] = state[8];
   out_5431061979149799049[9] = state[9];
   out_5431061979149799049[10] = state[10];
   out_5431061979149799049[11] = state[11];
   out_5431061979149799049[12] = state[12];
   out_5431061979149799049[13] = state[13];
   out_5431061979149799049[14] = state[14];
   out_5431061979149799049[15] = state[15];
   out_5431061979149799049[16] = state[16];
   out_5431061979149799049[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7283706501583847587) {
   out_7283706501583847587[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7283706501583847587[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7283706501583847587[2] = 0;
   out_7283706501583847587[3] = 0;
   out_7283706501583847587[4] = 0;
   out_7283706501583847587[5] = 0;
   out_7283706501583847587[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7283706501583847587[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7283706501583847587[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7283706501583847587[9] = 0;
   out_7283706501583847587[10] = 0;
   out_7283706501583847587[11] = 0;
   out_7283706501583847587[12] = 0;
   out_7283706501583847587[13] = 0;
   out_7283706501583847587[14] = 0;
   out_7283706501583847587[15] = 0;
   out_7283706501583847587[16] = 0;
   out_7283706501583847587[17] = 0;
   out_7283706501583847587[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7283706501583847587[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7283706501583847587[20] = 0;
   out_7283706501583847587[21] = 0;
   out_7283706501583847587[22] = 0;
   out_7283706501583847587[23] = 0;
   out_7283706501583847587[24] = 0;
   out_7283706501583847587[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7283706501583847587[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7283706501583847587[27] = 0;
   out_7283706501583847587[28] = 0;
   out_7283706501583847587[29] = 0;
   out_7283706501583847587[30] = 0;
   out_7283706501583847587[31] = 0;
   out_7283706501583847587[32] = 0;
   out_7283706501583847587[33] = 0;
   out_7283706501583847587[34] = 0;
   out_7283706501583847587[35] = 0;
   out_7283706501583847587[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7283706501583847587[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7283706501583847587[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7283706501583847587[39] = 0;
   out_7283706501583847587[40] = 0;
   out_7283706501583847587[41] = 0;
   out_7283706501583847587[42] = 0;
   out_7283706501583847587[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7283706501583847587[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7283706501583847587[45] = 0;
   out_7283706501583847587[46] = 0;
   out_7283706501583847587[47] = 0;
   out_7283706501583847587[48] = 0;
   out_7283706501583847587[49] = 0;
   out_7283706501583847587[50] = 0;
   out_7283706501583847587[51] = 0;
   out_7283706501583847587[52] = 0;
   out_7283706501583847587[53] = 0;
   out_7283706501583847587[54] = 0;
   out_7283706501583847587[55] = 0;
   out_7283706501583847587[56] = 0;
   out_7283706501583847587[57] = 1;
   out_7283706501583847587[58] = 0;
   out_7283706501583847587[59] = 0;
   out_7283706501583847587[60] = 0;
   out_7283706501583847587[61] = 0;
   out_7283706501583847587[62] = 0;
   out_7283706501583847587[63] = 0;
   out_7283706501583847587[64] = 0;
   out_7283706501583847587[65] = 0;
   out_7283706501583847587[66] = dt;
   out_7283706501583847587[67] = 0;
   out_7283706501583847587[68] = 0;
   out_7283706501583847587[69] = 0;
   out_7283706501583847587[70] = 0;
   out_7283706501583847587[71] = 0;
   out_7283706501583847587[72] = 0;
   out_7283706501583847587[73] = 0;
   out_7283706501583847587[74] = 0;
   out_7283706501583847587[75] = 0;
   out_7283706501583847587[76] = 1;
   out_7283706501583847587[77] = 0;
   out_7283706501583847587[78] = 0;
   out_7283706501583847587[79] = 0;
   out_7283706501583847587[80] = 0;
   out_7283706501583847587[81] = 0;
   out_7283706501583847587[82] = 0;
   out_7283706501583847587[83] = 0;
   out_7283706501583847587[84] = 0;
   out_7283706501583847587[85] = dt;
   out_7283706501583847587[86] = 0;
   out_7283706501583847587[87] = 0;
   out_7283706501583847587[88] = 0;
   out_7283706501583847587[89] = 0;
   out_7283706501583847587[90] = 0;
   out_7283706501583847587[91] = 0;
   out_7283706501583847587[92] = 0;
   out_7283706501583847587[93] = 0;
   out_7283706501583847587[94] = 0;
   out_7283706501583847587[95] = 1;
   out_7283706501583847587[96] = 0;
   out_7283706501583847587[97] = 0;
   out_7283706501583847587[98] = 0;
   out_7283706501583847587[99] = 0;
   out_7283706501583847587[100] = 0;
   out_7283706501583847587[101] = 0;
   out_7283706501583847587[102] = 0;
   out_7283706501583847587[103] = 0;
   out_7283706501583847587[104] = dt;
   out_7283706501583847587[105] = 0;
   out_7283706501583847587[106] = 0;
   out_7283706501583847587[107] = 0;
   out_7283706501583847587[108] = 0;
   out_7283706501583847587[109] = 0;
   out_7283706501583847587[110] = 0;
   out_7283706501583847587[111] = 0;
   out_7283706501583847587[112] = 0;
   out_7283706501583847587[113] = 0;
   out_7283706501583847587[114] = 1;
   out_7283706501583847587[115] = 0;
   out_7283706501583847587[116] = 0;
   out_7283706501583847587[117] = 0;
   out_7283706501583847587[118] = 0;
   out_7283706501583847587[119] = 0;
   out_7283706501583847587[120] = 0;
   out_7283706501583847587[121] = 0;
   out_7283706501583847587[122] = 0;
   out_7283706501583847587[123] = 0;
   out_7283706501583847587[124] = 0;
   out_7283706501583847587[125] = 0;
   out_7283706501583847587[126] = 0;
   out_7283706501583847587[127] = 0;
   out_7283706501583847587[128] = 0;
   out_7283706501583847587[129] = 0;
   out_7283706501583847587[130] = 0;
   out_7283706501583847587[131] = 0;
   out_7283706501583847587[132] = 0;
   out_7283706501583847587[133] = 1;
   out_7283706501583847587[134] = 0;
   out_7283706501583847587[135] = 0;
   out_7283706501583847587[136] = 0;
   out_7283706501583847587[137] = 0;
   out_7283706501583847587[138] = 0;
   out_7283706501583847587[139] = 0;
   out_7283706501583847587[140] = 0;
   out_7283706501583847587[141] = 0;
   out_7283706501583847587[142] = 0;
   out_7283706501583847587[143] = 0;
   out_7283706501583847587[144] = 0;
   out_7283706501583847587[145] = 0;
   out_7283706501583847587[146] = 0;
   out_7283706501583847587[147] = 0;
   out_7283706501583847587[148] = 0;
   out_7283706501583847587[149] = 0;
   out_7283706501583847587[150] = 0;
   out_7283706501583847587[151] = 0;
   out_7283706501583847587[152] = 1;
   out_7283706501583847587[153] = 0;
   out_7283706501583847587[154] = 0;
   out_7283706501583847587[155] = 0;
   out_7283706501583847587[156] = 0;
   out_7283706501583847587[157] = 0;
   out_7283706501583847587[158] = 0;
   out_7283706501583847587[159] = 0;
   out_7283706501583847587[160] = 0;
   out_7283706501583847587[161] = 0;
   out_7283706501583847587[162] = 0;
   out_7283706501583847587[163] = 0;
   out_7283706501583847587[164] = 0;
   out_7283706501583847587[165] = 0;
   out_7283706501583847587[166] = 0;
   out_7283706501583847587[167] = 0;
   out_7283706501583847587[168] = 0;
   out_7283706501583847587[169] = 0;
   out_7283706501583847587[170] = 0;
   out_7283706501583847587[171] = 1;
   out_7283706501583847587[172] = 0;
   out_7283706501583847587[173] = 0;
   out_7283706501583847587[174] = 0;
   out_7283706501583847587[175] = 0;
   out_7283706501583847587[176] = 0;
   out_7283706501583847587[177] = 0;
   out_7283706501583847587[178] = 0;
   out_7283706501583847587[179] = 0;
   out_7283706501583847587[180] = 0;
   out_7283706501583847587[181] = 0;
   out_7283706501583847587[182] = 0;
   out_7283706501583847587[183] = 0;
   out_7283706501583847587[184] = 0;
   out_7283706501583847587[185] = 0;
   out_7283706501583847587[186] = 0;
   out_7283706501583847587[187] = 0;
   out_7283706501583847587[188] = 0;
   out_7283706501583847587[189] = 0;
   out_7283706501583847587[190] = 1;
   out_7283706501583847587[191] = 0;
   out_7283706501583847587[192] = 0;
   out_7283706501583847587[193] = 0;
   out_7283706501583847587[194] = 0;
   out_7283706501583847587[195] = 0;
   out_7283706501583847587[196] = 0;
   out_7283706501583847587[197] = 0;
   out_7283706501583847587[198] = 0;
   out_7283706501583847587[199] = 0;
   out_7283706501583847587[200] = 0;
   out_7283706501583847587[201] = 0;
   out_7283706501583847587[202] = 0;
   out_7283706501583847587[203] = 0;
   out_7283706501583847587[204] = 0;
   out_7283706501583847587[205] = 0;
   out_7283706501583847587[206] = 0;
   out_7283706501583847587[207] = 0;
   out_7283706501583847587[208] = 0;
   out_7283706501583847587[209] = 1;
   out_7283706501583847587[210] = 0;
   out_7283706501583847587[211] = 0;
   out_7283706501583847587[212] = 0;
   out_7283706501583847587[213] = 0;
   out_7283706501583847587[214] = 0;
   out_7283706501583847587[215] = 0;
   out_7283706501583847587[216] = 0;
   out_7283706501583847587[217] = 0;
   out_7283706501583847587[218] = 0;
   out_7283706501583847587[219] = 0;
   out_7283706501583847587[220] = 0;
   out_7283706501583847587[221] = 0;
   out_7283706501583847587[222] = 0;
   out_7283706501583847587[223] = 0;
   out_7283706501583847587[224] = 0;
   out_7283706501583847587[225] = 0;
   out_7283706501583847587[226] = 0;
   out_7283706501583847587[227] = 0;
   out_7283706501583847587[228] = 1;
   out_7283706501583847587[229] = 0;
   out_7283706501583847587[230] = 0;
   out_7283706501583847587[231] = 0;
   out_7283706501583847587[232] = 0;
   out_7283706501583847587[233] = 0;
   out_7283706501583847587[234] = 0;
   out_7283706501583847587[235] = 0;
   out_7283706501583847587[236] = 0;
   out_7283706501583847587[237] = 0;
   out_7283706501583847587[238] = 0;
   out_7283706501583847587[239] = 0;
   out_7283706501583847587[240] = 0;
   out_7283706501583847587[241] = 0;
   out_7283706501583847587[242] = 0;
   out_7283706501583847587[243] = 0;
   out_7283706501583847587[244] = 0;
   out_7283706501583847587[245] = 0;
   out_7283706501583847587[246] = 0;
   out_7283706501583847587[247] = 1;
   out_7283706501583847587[248] = 0;
   out_7283706501583847587[249] = 0;
   out_7283706501583847587[250] = 0;
   out_7283706501583847587[251] = 0;
   out_7283706501583847587[252] = 0;
   out_7283706501583847587[253] = 0;
   out_7283706501583847587[254] = 0;
   out_7283706501583847587[255] = 0;
   out_7283706501583847587[256] = 0;
   out_7283706501583847587[257] = 0;
   out_7283706501583847587[258] = 0;
   out_7283706501583847587[259] = 0;
   out_7283706501583847587[260] = 0;
   out_7283706501583847587[261] = 0;
   out_7283706501583847587[262] = 0;
   out_7283706501583847587[263] = 0;
   out_7283706501583847587[264] = 0;
   out_7283706501583847587[265] = 0;
   out_7283706501583847587[266] = 1;
   out_7283706501583847587[267] = 0;
   out_7283706501583847587[268] = 0;
   out_7283706501583847587[269] = 0;
   out_7283706501583847587[270] = 0;
   out_7283706501583847587[271] = 0;
   out_7283706501583847587[272] = 0;
   out_7283706501583847587[273] = 0;
   out_7283706501583847587[274] = 0;
   out_7283706501583847587[275] = 0;
   out_7283706501583847587[276] = 0;
   out_7283706501583847587[277] = 0;
   out_7283706501583847587[278] = 0;
   out_7283706501583847587[279] = 0;
   out_7283706501583847587[280] = 0;
   out_7283706501583847587[281] = 0;
   out_7283706501583847587[282] = 0;
   out_7283706501583847587[283] = 0;
   out_7283706501583847587[284] = 0;
   out_7283706501583847587[285] = 1;
   out_7283706501583847587[286] = 0;
   out_7283706501583847587[287] = 0;
   out_7283706501583847587[288] = 0;
   out_7283706501583847587[289] = 0;
   out_7283706501583847587[290] = 0;
   out_7283706501583847587[291] = 0;
   out_7283706501583847587[292] = 0;
   out_7283706501583847587[293] = 0;
   out_7283706501583847587[294] = 0;
   out_7283706501583847587[295] = 0;
   out_7283706501583847587[296] = 0;
   out_7283706501583847587[297] = 0;
   out_7283706501583847587[298] = 0;
   out_7283706501583847587[299] = 0;
   out_7283706501583847587[300] = 0;
   out_7283706501583847587[301] = 0;
   out_7283706501583847587[302] = 0;
   out_7283706501583847587[303] = 0;
   out_7283706501583847587[304] = 1;
   out_7283706501583847587[305] = 0;
   out_7283706501583847587[306] = 0;
   out_7283706501583847587[307] = 0;
   out_7283706501583847587[308] = 0;
   out_7283706501583847587[309] = 0;
   out_7283706501583847587[310] = 0;
   out_7283706501583847587[311] = 0;
   out_7283706501583847587[312] = 0;
   out_7283706501583847587[313] = 0;
   out_7283706501583847587[314] = 0;
   out_7283706501583847587[315] = 0;
   out_7283706501583847587[316] = 0;
   out_7283706501583847587[317] = 0;
   out_7283706501583847587[318] = 0;
   out_7283706501583847587[319] = 0;
   out_7283706501583847587[320] = 0;
   out_7283706501583847587[321] = 0;
   out_7283706501583847587[322] = 0;
   out_7283706501583847587[323] = 1;
}
void h_4(double *state, double *unused, double *out_1801795458370807617) {
   out_1801795458370807617[0] = state[6] + state[9];
   out_1801795458370807617[1] = state[7] + state[10];
   out_1801795458370807617[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1671243425982092105) {
   out_1671243425982092105[0] = 0;
   out_1671243425982092105[1] = 0;
   out_1671243425982092105[2] = 0;
   out_1671243425982092105[3] = 0;
   out_1671243425982092105[4] = 0;
   out_1671243425982092105[5] = 0;
   out_1671243425982092105[6] = 1;
   out_1671243425982092105[7] = 0;
   out_1671243425982092105[8] = 0;
   out_1671243425982092105[9] = 1;
   out_1671243425982092105[10] = 0;
   out_1671243425982092105[11] = 0;
   out_1671243425982092105[12] = 0;
   out_1671243425982092105[13] = 0;
   out_1671243425982092105[14] = 0;
   out_1671243425982092105[15] = 0;
   out_1671243425982092105[16] = 0;
   out_1671243425982092105[17] = 0;
   out_1671243425982092105[18] = 0;
   out_1671243425982092105[19] = 0;
   out_1671243425982092105[20] = 0;
   out_1671243425982092105[21] = 0;
   out_1671243425982092105[22] = 0;
   out_1671243425982092105[23] = 0;
   out_1671243425982092105[24] = 0;
   out_1671243425982092105[25] = 1;
   out_1671243425982092105[26] = 0;
   out_1671243425982092105[27] = 0;
   out_1671243425982092105[28] = 1;
   out_1671243425982092105[29] = 0;
   out_1671243425982092105[30] = 0;
   out_1671243425982092105[31] = 0;
   out_1671243425982092105[32] = 0;
   out_1671243425982092105[33] = 0;
   out_1671243425982092105[34] = 0;
   out_1671243425982092105[35] = 0;
   out_1671243425982092105[36] = 0;
   out_1671243425982092105[37] = 0;
   out_1671243425982092105[38] = 0;
   out_1671243425982092105[39] = 0;
   out_1671243425982092105[40] = 0;
   out_1671243425982092105[41] = 0;
   out_1671243425982092105[42] = 0;
   out_1671243425982092105[43] = 0;
   out_1671243425982092105[44] = 1;
   out_1671243425982092105[45] = 0;
   out_1671243425982092105[46] = 0;
   out_1671243425982092105[47] = 1;
   out_1671243425982092105[48] = 0;
   out_1671243425982092105[49] = 0;
   out_1671243425982092105[50] = 0;
   out_1671243425982092105[51] = 0;
   out_1671243425982092105[52] = 0;
   out_1671243425982092105[53] = 0;
}
void h_10(double *state, double *unused, double *out_296127658211319494) {
   out_296127658211319494[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_296127658211319494[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_296127658211319494[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4354678574143084041) {
   out_4354678574143084041[0] = 0;
   out_4354678574143084041[1] = 9.8100000000000005*cos(state[1]);
   out_4354678574143084041[2] = 0;
   out_4354678574143084041[3] = 0;
   out_4354678574143084041[4] = -state[8];
   out_4354678574143084041[5] = state[7];
   out_4354678574143084041[6] = 0;
   out_4354678574143084041[7] = state[5];
   out_4354678574143084041[8] = -state[4];
   out_4354678574143084041[9] = 0;
   out_4354678574143084041[10] = 0;
   out_4354678574143084041[11] = 0;
   out_4354678574143084041[12] = 1;
   out_4354678574143084041[13] = 0;
   out_4354678574143084041[14] = 0;
   out_4354678574143084041[15] = 1;
   out_4354678574143084041[16] = 0;
   out_4354678574143084041[17] = 0;
   out_4354678574143084041[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4354678574143084041[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4354678574143084041[20] = 0;
   out_4354678574143084041[21] = state[8];
   out_4354678574143084041[22] = 0;
   out_4354678574143084041[23] = -state[6];
   out_4354678574143084041[24] = -state[5];
   out_4354678574143084041[25] = 0;
   out_4354678574143084041[26] = state[3];
   out_4354678574143084041[27] = 0;
   out_4354678574143084041[28] = 0;
   out_4354678574143084041[29] = 0;
   out_4354678574143084041[30] = 0;
   out_4354678574143084041[31] = 1;
   out_4354678574143084041[32] = 0;
   out_4354678574143084041[33] = 0;
   out_4354678574143084041[34] = 1;
   out_4354678574143084041[35] = 0;
   out_4354678574143084041[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4354678574143084041[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4354678574143084041[38] = 0;
   out_4354678574143084041[39] = -state[7];
   out_4354678574143084041[40] = state[6];
   out_4354678574143084041[41] = 0;
   out_4354678574143084041[42] = state[4];
   out_4354678574143084041[43] = -state[3];
   out_4354678574143084041[44] = 0;
   out_4354678574143084041[45] = 0;
   out_4354678574143084041[46] = 0;
   out_4354678574143084041[47] = 0;
   out_4354678574143084041[48] = 0;
   out_4354678574143084041[49] = 0;
   out_4354678574143084041[50] = 1;
   out_4354678574143084041[51] = 0;
   out_4354678574143084041[52] = 0;
   out_4354678574143084041[53] = 1;
}
void h_13(double *state, double *unused, double *out_3294015468262232612) {
   out_3294015468262232612[0] = state[3];
   out_3294015468262232612[1] = state[4];
   out_3294015468262232612[2] = state[5];
}
void H_13(double *state, double *unused, double *out_9164869439410758582) {
   out_9164869439410758582[0] = 0;
   out_9164869439410758582[1] = 0;
   out_9164869439410758582[2] = 0;
   out_9164869439410758582[3] = 1;
   out_9164869439410758582[4] = 0;
   out_9164869439410758582[5] = 0;
   out_9164869439410758582[6] = 0;
   out_9164869439410758582[7] = 0;
   out_9164869439410758582[8] = 0;
   out_9164869439410758582[9] = 0;
   out_9164869439410758582[10] = 0;
   out_9164869439410758582[11] = 0;
   out_9164869439410758582[12] = 0;
   out_9164869439410758582[13] = 0;
   out_9164869439410758582[14] = 0;
   out_9164869439410758582[15] = 0;
   out_9164869439410758582[16] = 0;
   out_9164869439410758582[17] = 0;
   out_9164869439410758582[18] = 0;
   out_9164869439410758582[19] = 0;
   out_9164869439410758582[20] = 0;
   out_9164869439410758582[21] = 0;
   out_9164869439410758582[22] = 1;
   out_9164869439410758582[23] = 0;
   out_9164869439410758582[24] = 0;
   out_9164869439410758582[25] = 0;
   out_9164869439410758582[26] = 0;
   out_9164869439410758582[27] = 0;
   out_9164869439410758582[28] = 0;
   out_9164869439410758582[29] = 0;
   out_9164869439410758582[30] = 0;
   out_9164869439410758582[31] = 0;
   out_9164869439410758582[32] = 0;
   out_9164869439410758582[33] = 0;
   out_9164869439410758582[34] = 0;
   out_9164869439410758582[35] = 0;
   out_9164869439410758582[36] = 0;
   out_9164869439410758582[37] = 0;
   out_9164869439410758582[38] = 0;
   out_9164869439410758582[39] = 0;
   out_9164869439410758582[40] = 0;
   out_9164869439410758582[41] = 1;
   out_9164869439410758582[42] = 0;
   out_9164869439410758582[43] = 0;
   out_9164869439410758582[44] = 0;
   out_9164869439410758582[45] = 0;
   out_9164869439410758582[46] = 0;
   out_9164869439410758582[47] = 0;
   out_9164869439410758582[48] = 0;
   out_9164869439410758582[49] = 0;
   out_9164869439410758582[50] = 0;
   out_9164869439410758582[51] = 0;
   out_9164869439410758582[52] = 0;
   out_9164869439410758582[53] = 0;
}
void h_14(double *state, double *unused, double *out_467053765268704623) {
   out_467053765268704623[0] = state[6];
   out_467053765268704623[1] = state[7];
   out_467053765268704623[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1411545006313280191) {
   out_1411545006313280191[0] = 0;
   out_1411545006313280191[1] = 0;
   out_1411545006313280191[2] = 0;
   out_1411545006313280191[3] = 0;
   out_1411545006313280191[4] = 0;
   out_1411545006313280191[5] = 0;
   out_1411545006313280191[6] = 1;
   out_1411545006313280191[7] = 0;
   out_1411545006313280191[8] = 0;
   out_1411545006313280191[9] = 0;
   out_1411545006313280191[10] = 0;
   out_1411545006313280191[11] = 0;
   out_1411545006313280191[12] = 0;
   out_1411545006313280191[13] = 0;
   out_1411545006313280191[14] = 0;
   out_1411545006313280191[15] = 0;
   out_1411545006313280191[16] = 0;
   out_1411545006313280191[17] = 0;
   out_1411545006313280191[18] = 0;
   out_1411545006313280191[19] = 0;
   out_1411545006313280191[20] = 0;
   out_1411545006313280191[21] = 0;
   out_1411545006313280191[22] = 0;
   out_1411545006313280191[23] = 0;
   out_1411545006313280191[24] = 0;
   out_1411545006313280191[25] = 1;
   out_1411545006313280191[26] = 0;
   out_1411545006313280191[27] = 0;
   out_1411545006313280191[28] = 0;
   out_1411545006313280191[29] = 0;
   out_1411545006313280191[30] = 0;
   out_1411545006313280191[31] = 0;
   out_1411545006313280191[32] = 0;
   out_1411545006313280191[33] = 0;
   out_1411545006313280191[34] = 0;
   out_1411545006313280191[35] = 0;
   out_1411545006313280191[36] = 0;
   out_1411545006313280191[37] = 0;
   out_1411545006313280191[38] = 0;
   out_1411545006313280191[39] = 0;
   out_1411545006313280191[40] = 0;
   out_1411545006313280191[41] = 0;
   out_1411545006313280191[42] = 0;
   out_1411545006313280191[43] = 0;
   out_1411545006313280191[44] = 1;
   out_1411545006313280191[45] = 0;
   out_1411545006313280191[46] = 0;
   out_1411545006313280191[47] = 0;
   out_1411545006313280191[48] = 0;
   out_1411545006313280191[49] = 0;
   out_1411545006313280191[50] = 0;
   out_1411545006313280191[51] = 0;
   out_1411545006313280191[52] = 0;
   out_1411545006313280191[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1384224859777021071) {
  err_fun(nom_x, delta_x, out_1384224859777021071);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6553735098488367695) {
  inv_err_fun(nom_x, true_x, out_6553735098488367695);
}
void pose_H_mod_fun(double *state, double *out_7066952806100897033) {
  H_mod_fun(state, out_7066952806100897033);
}
void pose_f_fun(double *state, double dt, double *out_5431061979149799049) {
  f_fun(state,  dt, out_5431061979149799049);
}
void pose_F_fun(double *state, double dt, double *out_7283706501583847587) {
  F_fun(state,  dt, out_7283706501583847587);
}
void pose_h_4(double *state, double *unused, double *out_1801795458370807617) {
  h_4(state, unused, out_1801795458370807617);
}
void pose_H_4(double *state, double *unused, double *out_1671243425982092105) {
  H_4(state, unused, out_1671243425982092105);
}
void pose_h_10(double *state, double *unused, double *out_296127658211319494) {
  h_10(state, unused, out_296127658211319494);
}
void pose_H_10(double *state, double *unused, double *out_4354678574143084041) {
  H_10(state, unused, out_4354678574143084041);
}
void pose_h_13(double *state, double *unused, double *out_3294015468262232612) {
  h_13(state, unused, out_3294015468262232612);
}
void pose_H_13(double *state, double *unused, double *out_9164869439410758582) {
  H_13(state, unused, out_9164869439410758582);
}
void pose_h_14(double *state, double *unused, double *out_467053765268704623) {
  h_14(state, unused, out_467053765268704623);
}
void pose_H_14(double *state, double *unused, double *out_1411545006313280191) {
  H_14(state, unused, out_1411545006313280191);
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
