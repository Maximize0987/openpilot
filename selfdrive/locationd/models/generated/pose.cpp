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
void err_fun(double *nom_x, double *delta_x, double *out_5866923855832820417) {
   out_5866923855832820417[0] = delta_x[0] + nom_x[0];
   out_5866923855832820417[1] = delta_x[1] + nom_x[1];
   out_5866923855832820417[2] = delta_x[2] + nom_x[2];
   out_5866923855832820417[3] = delta_x[3] + nom_x[3];
   out_5866923855832820417[4] = delta_x[4] + nom_x[4];
   out_5866923855832820417[5] = delta_x[5] + nom_x[5];
   out_5866923855832820417[6] = delta_x[6] + nom_x[6];
   out_5866923855832820417[7] = delta_x[7] + nom_x[7];
   out_5866923855832820417[8] = delta_x[8] + nom_x[8];
   out_5866923855832820417[9] = delta_x[9] + nom_x[9];
   out_5866923855832820417[10] = delta_x[10] + nom_x[10];
   out_5866923855832820417[11] = delta_x[11] + nom_x[11];
   out_5866923855832820417[12] = delta_x[12] + nom_x[12];
   out_5866923855832820417[13] = delta_x[13] + nom_x[13];
   out_5866923855832820417[14] = delta_x[14] + nom_x[14];
   out_5866923855832820417[15] = delta_x[15] + nom_x[15];
   out_5866923855832820417[16] = delta_x[16] + nom_x[16];
   out_5866923855832820417[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7354374655466778507) {
   out_7354374655466778507[0] = -nom_x[0] + true_x[0];
   out_7354374655466778507[1] = -nom_x[1] + true_x[1];
   out_7354374655466778507[2] = -nom_x[2] + true_x[2];
   out_7354374655466778507[3] = -nom_x[3] + true_x[3];
   out_7354374655466778507[4] = -nom_x[4] + true_x[4];
   out_7354374655466778507[5] = -nom_x[5] + true_x[5];
   out_7354374655466778507[6] = -nom_x[6] + true_x[6];
   out_7354374655466778507[7] = -nom_x[7] + true_x[7];
   out_7354374655466778507[8] = -nom_x[8] + true_x[8];
   out_7354374655466778507[9] = -nom_x[9] + true_x[9];
   out_7354374655466778507[10] = -nom_x[10] + true_x[10];
   out_7354374655466778507[11] = -nom_x[11] + true_x[11];
   out_7354374655466778507[12] = -nom_x[12] + true_x[12];
   out_7354374655466778507[13] = -nom_x[13] + true_x[13];
   out_7354374655466778507[14] = -nom_x[14] + true_x[14];
   out_7354374655466778507[15] = -nom_x[15] + true_x[15];
   out_7354374655466778507[16] = -nom_x[16] + true_x[16];
   out_7354374655466778507[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5435820587083186523) {
   out_5435820587083186523[0] = 1.0;
   out_5435820587083186523[1] = 0.0;
   out_5435820587083186523[2] = 0.0;
   out_5435820587083186523[3] = 0.0;
   out_5435820587083186523[4] = 0.0;
   out_5435820587083186523[5] = 0.0;
   out_5435820587083186523[6] = 0.0;
   out_5435820587083186523[7] = 0.0;
   out_5435820587083186523[8] = 0.0;
   out_5435820587083186523[9] = 0.0;
   out_5435820587083186523[10] = 0.0;
   out_5435820587083186523[11] = 0.0;
   out_5435820587083186523[12] = 0.0;
   out_5435820587083186523[13] = 0.0;
   out_5435820587083186523[14] = 0.0;
   out_5435820587083186523[15] = 0.0;
   out_5435820587083186523[16] = 0.0;
   out_5435820587083186523[17] = 0.0;
   out_5435820587083186523[18] = 0.0;
   out_5435820587083186523[19] = 1.0;
   out_5435820587083186523[20] = 0.0;
   out_5435820587083186523[21] = 0.0;
   out_5435820587083186523[22] = 0.0;
   out_5435820587083186523[23] = 0.0;
   out_5435820587083186523[24] = 0.0;
   out_5435820587083186523[25] = 0.0;
   out_5435820587083186523[26] = 0.0;
   out_5435820587083186523[27] = 0.0;
   out_5435820587083186523[28] = 0.0;
   out_5435820587083186523[29] = 0.0;
   out_5435820587083186523[30] = 0.0;
   out_5435820587083186523[31] = 0.0;
   out_5435820587083186523[32] = 0.0;
   out_5435820587083186523[33] = 0.0;
   out_5435820587083186523[34] = 0.0;
   out_5435820587083186523[35] = 0.0;
   out_5435820587083186523[36] = 0.0;
   out_5435820587083186523[37] = 0.0;
   out_5435820587083186523[38] = 1.0;
   out_5435820587083186523[39] = 0.0;
   out_5435820587083186523[40] = 0.0;
   out_5435820587083186523[41] = 0.0;
   out_5435820587083186523[42] = 0.0;
   out_5435820587083186523[43] = 0.0;
   out_5435820587083186523[44] = 0.0;
   out_5435820587083186523[45] = 0.0;
   out_5435820587083186523[46] = 0.0;
   out_5435820587083186523[47] = 0.0;
   out_5435820587083186523[48] = 0.0;
   out_5435820587083186523[49] = 0.0;
   out_5435820587083186523[50] = 0.0;
   out_5435820587083186523[51] = 0.0;
   out_5435820587083186523[52] = 0.0;
   out_5435820587083186523[53] = 0.0;
   out_5435820587083186523[54] = 0.0;
   out_5435820587083186523[55] = 0.0;
   out_5435820587083186523[56] = 0.0;
   out_5435820587083186523[57] = 1.0;
   out_5435820587083186523[58] = 0.0;
   out_5435820587083186523[59] = 0.0;
   out_5435820587083186523[60] = 0.0;
   out_5435820587083186523[61] = 0.0;
   out_5435820587083186523[62] = 0.0;
   out_5435820587083186523[63] = 0.0;
   out_5435820587083186523[64] = 0.0;
   out_5435820587083186523[65] = 0.0;
   out_5435820587083186523[66] = 0.0;
   out_5435820587083186523[67] = 0.0;
   out_5435820587083186523[68] = 0.0;
   out_5435820587083186523[69] = 0.0;
   out_5435820587083186523[70] = 0.0;
   out_5435820587083186523[71] = 0.0;
   out_5435820587083186523[72] = 0.0;
   out_5435820587083186523[73] = 0.0;
   out_5435820587083186523[74] = 0.0;
   out_5435820587083186523[75] = 0.0;
   out_5435820587083186523[76] = 1.0;
   out_5435820587083186523[77] = 0.0;
   out_5435820587083186523[78] = 0.0;
   out_5435820587083186523[79] = 0.0;
   out_5435820587083186523[80] = 0.0;
   out_5435820587083186523[81] = 0.0;
   out_5435820587083186523[82] = 0.0;
   out_5435820587083186523[83] = 0.0;
   out_5435820587083186523[84] = 0.0;
   out_5435820587083186523[85] = 0.0;
   out_5435820587083186523[86] = 0.0;
   out_5435820587083186523[87] = 0.0;
   out_5435820587083186523[88] = 0.0;
   out_5435820587083186523[89] = 0.0;
   out_5435820587083186523[90] = 0.0;
   out_5435820587083186523[91] = 0.0;
   out_5435820587083186523[92] = 0.0;
   out_5435820587083186523[93] = 0.0;
   out_5435820587083186523[94] = 0.0;
   out_5435820587083186523[95] = 1.0;
   out_5435820587083186523[96] = 0.0;
   out_5435820587083186523[97] = 0.0;
   out_5435820587083186523[98] = 0.0;
   out_5435820587083186523[99] = 0.0;
   out_5435820587083186523[100] = 0.0;
   out_5435820587083186523[101] = 0.0;
   out_5435820587083186523[102] = 0.0;
   out_5435820587083186523[103] = 0.0;
   out_5435820587083186523[104] = 0.0;
   out_5435820587083186523[105] = 0.0;
   out_5435820587083186523[106] = 0.0;
   out_5435820587083186523[107] = 0.0;
   out_5435820587083186523[108] = 0.0;
   out_5435820587083186523[109] = 0.0;
   out_5435820587083186523[110] = 0.0;
   out_5435820587083186523[111] = 0.0;
   out_5435820587083186523[112] = 0.0;
   out_5435820587083186523[113] = 0.0;
   out_5435820587083186523[114] = 1.0;
   out_5435820587083186523[115] = 0.0;
   out_5435820587083186523[116] = 0.0;
   out_5435820587083186523[117] = 0.0;
   out_5435820587083186523[118] = 0.0;
   out_5435820587083186523[119] = 0.0;
   out_5435820587083186523[120] = 0.0;
   out_5435820587083186523[121] = 0.0;
   out_5435820587083186523[122] = 0.0;
   out_5435820587083186523[123] = 0.0;
   out_5435820587083186523[124] = 0.0;
   out_5435820587083186523[125] = 0.0;
   out_5435820587083186523[126] = 0.0;
   out_5435820587083186523[127] = 0.0;
   out_5435820587083186523[128] = 0.0;
   out_5435820587083186523[129] = 0.0;
   out_5435820587083186523[130] = 0.0;
   out_5435820587083186523[131] = 0.0;
   out_5435820587083186523[132] = 0.0;
   out_5435820587083186523[133] = 1.0;
   out_5435820587083186523[134] = 0.0;
   out_5435820587083186523[135] = 0.0;
   out_5435820587083186523[136] = 0.0;
   out_5435820587083186523[137] = 0.0;
   out_5435820587083186523[138] = 0.0;
   out_5435820587083186523[139] = 0.0;
   out_5435820587083186523[140] = 0.0;
   out_5435820587083186523[141] = 0.0;
   out_5435820587083186523[142] = 0.0;
   out_5435820587083186523[143] = 0.0;
   out_5435820587083186523[144] = 0.0;
   out_5435820587083186523[145] = 0.0;
   out_5435820587083186523[146] = 0.0;
   out_5435820587083186523[147] = 0.0;
   out_5435820587083186523[148] = 0.0;
   out_5435820587083186523[149] = 0.0;
   out_5435820587083186523[150] = 0.0;
   out_5435820587083186523[151] = 0.0;
   out_5435820587083186523[152] = 1.0;
   out_5435820587083186523[153] = 0.0;
   out_5435820587083186523[154] = 0.0;
   out_5435820587083186523[155] = 0.0;
   out_5435820587083186523[156] = 0.0;
   out_5435820587083186523[157] = 0.0;
   out_5435820587083186523[158] = 0.0;
   out_5435820587083186523[159] = 0.0;
   out_5435820587083186523[160] = 0.0;
   out_5435820587083186523[161] = 0.0;
   out_5435820587083186523[162] = 0.0;
   out_5435820587083186523[163] = 0.0;
   out_5435820587083186523[164] = 0.0;
   out_5435820587083186523[165] = 0.0;
   out_5435820587083186523[166] = 0.0;
   out_5435820587083186523[167] = 0.0;
   out_5435820587083186523[168] = 0.0;
   out_5435820587083186523[169] = 0.0;
   out_5435820587083186523[170] = 0.0;
   out_5435820587083186523[171] = 1.0;
   out_5435820587083186523[172] = 0.0;
   out_5435820587083186523[173] = 0.0;
   out_5435820587083186523[174] = 0.0;
   out_5435820587083186523[175] = 0.0;
   out_5435820587083186523[176] = 0.0;
   out_5435820587083186523[177] = 0.0;
   out_5435820587083186523[178] = 0.0;
   out_5435820587083186523[179] = 0.0;
   out_5435820587083186523[180] = 0.0;
   out_5435820587083186523[181] = 0.0;
   out_5435820587083186523[182] = 0.0;
   out_5435820587083186523[183] = 0.0;
   out_5435820587083186523[184] = 0.0;
   out_5435820587083186523[185] = 0.0;
   out_5435820587083186523[186] = 0.0;
   out_5435820587083186523[187] = 0.0;
   out_5435820587083186523[188] = 0.0;
   out_5435820587083186523[189] = 0.0;
   out_5435820587083186523[190] = 1.0;
   out_5435820587083186523[191] = 0.0;
   out_5435820587083186523[192] = 0.0;
   out_5435820587083186523[193] = 0.0;
   out_5435820587083186523[194] = 0.0;
   out_5435820587083186523[195] = 0.0;
   out_5435820587083186523[196] = 0.0;
   out_5435820587083186523[197] = 0.0;
   out_5435820587083186523[198] = 0.0;
   out_5435820587083186523[199] = 0.0;
   out_5435820587083186523[200] = 0.0;
   out_5435820587083186523[201] = 0.0;
   out_5435820587083186523[202] = 0.0;
   out_5435820587083186523[203] = 0.0;
   out_5435820587083186523[204] = 0.0;
   out_5435820587083186523[205] = 0.0;
   out_5435820587083186523[206] = 0.0;
   out_5435820587083186523[207] = 0.0;
   out_5435820587083186523[208] = 0.0;
   out_5435820587083186523[209] = 1.0;
   out_5435820587083186523[210] = 0.0;
   out_5435820587083186523[211] = 0.0;
   out_5435820587083186523[212] = 0.0;
   out_5435820587083186523[213] = 0.0;
   out_5435820587083186523[214] = 0.0;
   out_5435820587083186523[215] = 0.0;
   out_5435820587083186523[216] = 0.0;
   out_5435820587083186523[217] = 0.0;
   out_5435820587083186523[218] = 0.0;
   out_5435820587083186523[219] = 0.0;
   out_5435820587083186523[220] = 0.0;
   out_5435820587083186523[221] = 0.0;
   out_5435820587083186523[222] = 0.0;
   out_5435820587083186523[223] = 0.0;
   out_5435820587083186523[224] = 0.0;
   out_5435820587083186523[225] = 0.0;
   out_5435820587083186523[226] = 0.0;
   out_5435820587083186523[227] = 0.0;
   out_5435820587083186523[228] = 1.0;
   out_5435820587083186523[229] = 0.0;
   out_5435820587083186523[230] = 0.0;
   out_5435820587083186523[231] = 0.0;
   out_5435820587083186523[232] = 0.0;
   out_5435820587083186523[233] = 0.0;
   out_5435820587083186523[234] = 0.0;
   out_5435820587083186523[235] = 0.0;
   out_5435820587083186523[236] = 0.0;
   out_5435820587083186523[237] = 0.0;
   out_5435820587083186523[238] = 0.0;
   out_5435820587083186523[239] = 0.0;
   out_5435820587083186523[240] = 0.0;
   out_5435820587083186523[241] = 0.0;
   out_5435820587083186523[242] = 0.0;
   out_5435820587083186523[243] = 0.0;
   out_5435820587083186523[244] = 0.0;
   out_5435820587083186523[245] = 0.0;
   out_5435820587083186523[246] = 0.0;
   out_5435820587083186523[247] = 1.0;
   out_5435820587083186523[248] = 0.0;
   out_5435820587083186523[249] = 0.0;
   out_5435820587083186523[250] = 0.0;
   out_5435820587083186523[251] = 0.0;
   out_5435820587083186523[252] = 0.0;
   out_5435820587083186523[253] = 0.0;
   out_5435820587083186523[254] = 0.0;
   out_5435820587083186523[255] = 0.0;
   out_5435820587083186523[256] = 0.0;
   out_5435820587083186523[257] = 0.0;
   out_5435820587083186523[258] = 0.0;
   out_5435820587083186523[259] = 0.0;
   out_5435820587083186523[260] = 0.0;
   out_5435820587083186523[261] = 0.0;
   out_5435820587083186523[262] = 0.0;
   out_5435820587083186523[263] = 0.0;
   out_5435820587083186523[264] = 0.0;
   out_5435820587083186523[265] = 0.0;
   out_5435820587083186523[266] = 1.0;
   out_5435820587083186523[267] = 0.0;
   out_5435820587083186523[268] = 0.0;
   out_5435820587083186523[269] = 0.0;
   out_5435820587083186523[270] = 0.0;
   out_5435820587083186523[271] = 0.0;
   out_5435820587083186523[272] = 0.0;
   out_5435820587083186523[273] = 0.0;
   out_5435820587083186523[274] = 0.0;
   out_5435820587083186523[275] = 0.0;
   out_5435820587083186523[276] = 0.0;
   out_5435820587083186523[277] = 0.0;
   out_5435820587083186523[278] = 0.0;
   out_5435820587083186523[279] = 0.0;
   out_5435820587083186523[280] = 0.0;
   out_5435820587083186523[281] = 0.0;
   out_5435820587083186523[282] = 0.0;
   out_5435820587083186523[283] = 0.0;
   out_5435820587083186523[284] = 0.0;
   out_5435820587083186523[285] = 1.0;
   out_5435820587083186523[286] = 0.0;
   out_5435820587083186523[287] = 0.0;
   out_5435820587083186523[288] = 0.0;
   out_5435820587083186523[289] = 0.0;
   out_5435820587083186523[290] = 0.0;
   out_5435820587083186523[291] = 0.0;
   out_5435820587083186523[292] = 0.0;
   out_5435820587083186523[293] = 0.0;
   out_5435820587083186523[294] = 0.0;
   out_5435820587083186523[295] = 0.0;
   out_5435820587083186523[296] = 0.0;
   out_5435820587083186523[297] = 0.0;
   out_5435820587083186523[298] = 0.0;
   out_5435820587083186523[299] = 0.0;
   out_5435820587083186523[300] = 0.0;
   out_5435820587083186523[301] = 0.0;
   out_5435820587083186523[302] = 0.0;
   out_5435820587083186523[303] = 0.0;
   out_5435820587083186523[304] = 1.0;
   out_5435820587083186523[305] = 0.0;
   out_5435820587083186523[306] = 0.0;
   out_5435820587083186523[307] = 0.0;
   out_5435820587083186523[308] = 0.0;
   out_5435820587083186523[309] = 0.0;
   out_5435820587083186523[310] = 0.0;
   out_5435820587083186523[311] = 0.0;
   out_5435820587083186523[312] = 0.0;
   out_5435820587083186523[313] = 0.0;
   out_5435820587083186523[314] = 0.0;
   out_5435820587083186523[315] = 0.0;
   out_5435820587083186523[316] = 0.0;
   out_5435820587083186523[317] = 0.0;
   out_5435820587083186523[318] = 0.0;
   out_5435820587083186523[319] = 0.0;
   out_5435820587083186523[320] = 0.0;
   out_5435820587083186523[321] = 0.0;
   out_5435820587083186523[322] = 0.0;
   out_5435820587083186523[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5089910609496554967) {
   out_5089910609496554967[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5089910609496554967[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5089910609496554967[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5089910609496554967[3] = dt*state[12] + state[3];
   out_5089910609496554967[4] = dt*state[13] + state[4];
   out_5089910609496554967[5] = dt*state[14] + state[5];
   out_5089910609496554967[6] = state[6];
   out_5089910609496554967[7] = state[7];
   out_5089910609496554967[8] = state[8];
   out_5089910609496554967[9] = state[9];
   out_5089910609496554967[10] = state[10];
   out_5089910609496554967[11] = state[11];
   out_5089910609496554967[12] = state[12];
   out_5089910609496554967[13] = state[13];
   out_5089910609496554967[14] = state[14];
   out_5089910609496554967[15] = state[15];
   out_5089910609496554967[16] = state[16];
   out_5089910609496554967[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7337888639276922507) {
   out_7337888639276922507[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7337888639276922507[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7337888639276922507[2] = 0;
   out_7337888639276922507[3] = 0;
   out_7337888639276922507[4] = 0;
   out_7337888639276922507[5] = 0;
   out_7337888639276922507[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7337888639276922507[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7337888639276922507[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7337888639276922507[9] = 0;
   out_7337888639276922507[10] = 0;
   out_7337888639276922507[11] = 0;
   out_7337888639276922507[12] = 0;
   out_7337888639276922507[13] = 0;
   out_7337888639276922507[14] = 0;
   out_7337888639276922507[15] = 0;
   out_7337888639276922507[16] = 0;
   out_7337888639276922507[17] = 0;
   out_7337888639276922507[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7337888639276922507[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7337888639276922507[20] = 0;
   out_7337888639276922507[21] = 0;
   out_7337888639276922507[22] = 0;
   out_7337888639276922507[23] = 0;
   out_7337888639276922507[24] = 0;
   out_7337888639276922507[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7337888639276922507[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7337888639276922507[27] = 0;
   out_7337888639276922507[28] = 0;
   out_7337888639276922507[29] = 0;
   out_7337888639276922507[30] = 0;
   out_7337888639276922507[31] = 0;
   out_7337888639276922507[32] = 0;
   out_7337888639276922507[33] = 0;
   out_7337888639276922507[34] = 0;
   out_7337888639276922507[35] = 0;
   out_7337888639276922507[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7337888639276922507[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7337888639276922507[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7337888639276922507[39] = 0;
   out_7337888639276922507[40] = 0;
   out_7337888639276922507[41] = 0;
   out_7337888639276922507[42] = 0;
   out_7337888639276922507[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7337888639276922507[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7337888639276922507[45] = 0;
   out_7337888639276922507[46] = 0;
   out_7337888639276922507[47] = 0;
   out_7337888639276922507[48] = 0;
   out_7337888639276922507[49] = 0;
   out_7337888639276922507[50] = 0;
   out_7337888639276922507[51] = 0;
   out_7337888639276922507[52] = 0;
   out_7337888639276922507[53] = 0;
   out_7337888639276922507[54] = 0;
   out_7337888639276922507[55] = 0;
   out_7337888639276922507[56] = 0;
   out_7337888639276922507[57] = 1;
   out_7337888639276922507[58] = 0;
   out_7337888639276922507[59] = 0;
   out_7337888639276922507[60] = 0;
   out_7337888639276922507[61] = 0;
   out_7337888639276922507[62] = 0;
   out_7337888639276922507[63] = 0;
   out_7337888639276922507[64] = 0;
   out_7337888639276922507[65] = 0;
   out_7337888639276922507[66] = dt;
   out_7337888639276922507[67] = 0;
   out_7337888639276922507[68] = 0;
   out_7337888639276922507[69] = 0;
   out_7337888639276922507[70] = 0;
   out_7337888639276922507[71] = 0;
   out_7337888639276922507[72] = 0;
   out_7337888639276922507[73] = 0;
   out_7337888639276922507[74] = 0;
   out_7337888639276922507[75] = 0;
   out_7337888639276922507[76] = 1;
   out_7337888639276922507[77] = 0;
   out_7337888639276922507[78] = 0;
   out_7337888639276922507[79] = 0;
   out_7337888639276922507[80] = 0;
   out_7337888639276922507[81] = 0;
   out_7337888639276922507[82] = 0;
   out_7337888639276922507[83] = 0;
   out_7337888639276922507[84] = 0;
   out_7337888639276922507[85] = dt;
   out_7337888639276922507[86] = 0;
   out_7337888639276922507[87] = 0;
   out_7337888639276922507[88] = 0;
   out_7337888639276922507[89] = 0;
   out_7337888639276922507[90] = 0;
   out_7337888639276922507[91] = 0;
   out_7337888639276922507[92] = 0;
   out_7337888639276922507[93] = 0;
   out_7337888639276922507[94] = 0;
   out_7337888639276922507[95] = 1;
   out_7337888639276922507[96] = 0;
   out_7337888639276922507[97] = 0;
   out_7337888639276922507[98] = 0;
   out_7337888639276922507[99] = 0;
   out_7337888639276922507[100] = 0;
   out_7337888639276922507[101] = 0;
   out_7337888639276922507[102] = 0;
   out_7337888639276922507[103] = 0;
   out_7337888639276922507[104] = dt;
   out_7337888639276922507[105] = 0;
   out_7337888639276922507[106] = 0;
   out_7337888639276922507[107] = 0;
   out_7337888639276922507[108] = 0;
   out_7337888639276922507[109] = 0;
   out_7337888639276922507[110] = 0;
   out_7337888639276922507[111] = 0;
   out_7337888639276922507[112] = 0;
   out_7337888639276922507[113] = 0;
   out_7337888639276922507[114] = 1;
   out_7337888639276922507[115] = 0;
   out_7337888639276922507[116] = 0;
   out_7337888639276922507[117] = 0;
   out_7337888639276922507[118] = 0;
   out_7337888639276922507[119] = 0;
   out_7337888639276922507[120] = 0;
   out_7337888639276922507[121] = 0;
   out_7337888639276922507[122] = 0;
   out_7337888639276922507[123] = 0;
   out_7337888639276922507[124] = 0;
   out_7337888639276922507[125] = 0;
   out_7337888639276922507[126] = 0;
   out_7337888639276922507[127] = 0;
   out_7337888639276922507[128] = 0;
   out_7337888639276922507[129] = 0;
   out_7337888639276922507[130] = 0;
   out_7337888639276922507[131] = 0;
   out_7337888639276922507[132] = 0;
   out_7337888639276922507[133] = 1;
   out_7337888639276922507[134] = 0;
   out_7337888639276922507[135] = 0;
   out_7337888639276922507[136] = 0;
   out_7337888639276922507[137] = 0;
   out_7337888639276922507[138] = 0;
   out_7337888639276922507[139] = 0;
   out_7337888639276922507[140] = 0;
   out_7337888639276922507[141] = 0;
   out_7337888639276922507[142] = 0;
   out_7337888639276922507[143] = 0;
   out_7337888639276922507[144] = 0;
   out_7337888639276922507[145] = 0;
   out_7337888639276922507[146] = 0;
   out_7337888639276922507[147] = 0;
   out_7337888639276922507[148] = 0;
   out_7337888639276922507[149] = 0;
   out_7337888639276922507[150] = 0;
   out_7337888639276922507[151] = 0;
   out_7337888639276922507[152] = 1;
   out_7337888639276922507[153] = 0;
   out_7337888639276922507[154] = 0;
   out_7337888639276922507[155] = 0;
   out_7337888639276922507[156] = 0;
   out_7337888639276922507[157] = 0;
   out_7337888639276922507[158] = 0;
   out_7337888639276922507[159] = 0;
   out_7337888639276922507[160] = 0;
   out_7337888639276922507[161] = 0;
   out_7337888639276922507[162] = 0;
   out_7337888639276922507[163] = 0;
   out_7337888639276922507[164] = 0;
   out_7337888639276922507[165] = 0;
   out_7337888639276922507[166] = 0;
   out_7337888639276922507[167] = 0;
   out_7337888639276922507[168] = 0;
   out_7337888639276922507[169] = 0;
   out_7337888639276922507[170] = 0;
   out_7337888639276922507[171] = 1;
   out_7337888639276922507[172] = 0;
   out_7337888639276922507[173] = 0;
   out_7337888639276922507[174] = 0;
   out_7337888639276922507[175] = 0;
   out_7337888639276922507[176] = 0;
   out_7337888639276922507[177] = 0;
   out_7337888639276922507[178] = 0;
   out_7337888639276922507[179] = 0;
   out_7337888639276922507[180] = 0;
   out_7337888639276922507[181] = 0;
   out_7337888639276922507[182] = 0;
   out_7337888639276922507[183] = 0;
   out_7337888639276922507[184] = 0;
   out_7337888639276922507[185] = 0;
   out_7337888639276922507[186] = 0;
   out_7337888639276922507[187] = 0;
   out_7337888639276922507[188] = 0;
   out_7337888639276922507[189] = 0;
   out_7337888639276922507[190] = 1;
   out_7337888639276922507[191] = 0;
   out_7337888639276922507[192] = 0;
   out_7337888639276922507[193] = 0;
   out_7337888639276922507[194] = 0;
   out_7337888639276922507[195] = 0;
   out_7337888639276922507[196] = 0;
   out_7337888639276922507[197] = 0;
   out_7337888639276922507[198] = 0;
   out_7337888639276922507[199] = 0;
   out_7337888639276922507[200] = 0;
   out_7337888639276922507[201] = 0;
   out_7337888639276922507[202] = 0;
   out_7337888639276922507[203] = 0;
   out_7337888639276922507[204] = 0;
   out_7337888639276922507[205] = 0;
   out_7337888639276922507[206] = 0;
   out_7337888639276922507[207] = 0;
   out_7337888639276922507[208] = 0;
   out_7337888639276922507[209] = 1;
   out_7337888639276922507[210] = 0;
   out_7337888639276922507[211] = 0;
   out_7337888639276922507[212] = 0;
   out_7337888639276922507[213] = 0;
   out_7337888639276922507[214] = 0;
   out_7337888639276922507[215] = 0;
   out_7337888639276922507[216] = 0;
   out_7337888639276922507[217] = 0;
   out_7337888639276922507[218] = 0;
   out_7337888639276922507[219] = 0;
   out_7337888639276922507[220] = 0;
   out_7337888639276922507[221] = 0;
   out_7337888639276922507[222] = 0;
   out_7337888639276922507[223] = 0;
   out_7337888639276922507[224] = 0;
   out_7337888639276922507[225] = 0;
   out_7337888639276922507[226] = 0;
   out_7337888639276922507[227] = 0;
   out_7337888639276922507[228] = 1;
   out_7337888639276922507[229] = 0;
   out_7337888639276922507[230] = 0;
   out_7337888639276922507[231] = 0;
   out_7337888639276922507[232] = 0;
   out_7337888639276922507[233] = 0;
   out_7337888639276922507[234] = 0;
   out_7337888639276922507[235] = 0;
   out_7337888639276922507[236] = 0;
   out_7337888639276922507[237] = 0;
   out_7337888639276922507[238] = 0;
   out_7337888639276922507[239] = 0;
   out_7337888639276922507[240] = 0;
   out_7337888639276922507[241] = 0;
   out_7337888639276922507[242] = 0;
   out_7337888639276922507[243] = 0;
   out_7337888639276922507[244] = 0;
   out_7337888639276922507[245] = 0;
   out_7337888639276922507[246] = 0;
   out_7337888639276922507[247] = 1;
   out_7337888639276922507[248] = 0;
   out_7337888639276922507[249] = 0;
   out_7337888639276922507[250] = 0;
   out_7337888639276922507[251] = 0;
   out_7337888639276922507[252] = 0;
   out_7337888639276922507[253] = 0;
   out_7337888639276922507[254] = 0;
   out_7337888639276922507[255] = 0;
   out_7337888639276922507[256] = 0;
   out_7337888639276922507[257] = 0;
   out_7337888639276922507[258] = 0;
   out_7337888639276922507[259] = 0;
   out_7337888639276922507[260] = 0;
   out_7337888639276922507[261] = 0;
   out_7337888639276922507[262] = 0;
   out_7337888639276922507[263] = 0;
   out_7337888639276922507[264] = 0;
   out_7337888639276922507[265] = 0;
   out_7337888639276922507[266] = 1;
   out_7337888639276922507[267] = 0;
   out_7337888639276922507[268] = 0;
   out_7337888639276922507[269] = 0;
   out_7337888639276922507[270] = 0;
   out_7337888639276922507[271] = 0;
   out_7337888639276922507[272] = 0;
   out_7337888639276922507[273] = 0;
   out_7337888639276922507[274] = 0;
   out_7337888639276922507[275] = 0;
   out_7337888639276922507[276] = 0;
   out_7337888639276922507[277] = 0;
   out_7337888639276922507[278] = 0;
   out_7337888639276922507[279] = 0;
   out_7337888639276922507[280] = 0;
   out_7337888639276922507[281] = 0;
   out_7337888639276922507[282] = 0;
   out_7337888639276922507[283] = 0;
   out_7337888639276922507[284] = 0;
   out_7337888639276922507[285] = 1;
   out_7337888639276922507[286] = 0;
   out_7337888639276922507[287] = 0;
   out_7337888639276922507[288] = 0;
   out_7337888639276922507[289] = 0;
   out_7337888639276922507[290] = 0;
   out_7337888639276922507[291] = 0;
   out_7337888639276922507[292] = 0;
   out_7337888639276922507[293] = 0;
   out_7337888639276922507[294] = 0;
   out_7337888639276922507[295] = 0;
   out_7337888639276922507[296] = 0;
   out_7337888639276922507[297] = 0;
   out_7337888639276922507[298] = 0;
   out_7337888639276922507[299] = 0;
   out_7337888639276922507[300] = 0;
   out_7337888639276922507[301] = 0;
   out_7337888639276922507[302] = 0;
   out_7337888639276922507[303] = 0;
   out_7337888639276922507[304] = 1;
   out_7337888639276922507[305] = 0;
   out_7337888639276922507[306] = 0;
   out_7337888639276922507[307] = 0;
   out_7337888639276922507[308] = 0;
   out_7337888639276922507[309] = 0;
   out_7337888639276922507[310] = 0;
   out_7337888639276922507[311] = 0;
   out_7337888639276922507[312] = 0;
   out_7337888639276922507[313] = 0;
   out_7337888639276922507[314] = 0;
   out_7337888639276922507[315] = 0;
   out_7337888639276922507[316] = 0;
   out_7337888639276922507[317] = 0;
   out_7337888639276922507[318] = 0;
   out_7337888639276922507[319] = 0;
   out_7337888639276922507[320] = 0;
   out_7337888639276922507[321] = 0;
   out_7337888639276922507[322] = 0;
   out_7337888639276922507[323] = 1;
}
void h_4(double *state, double *unused, double *out_2944115722558364854) {
   out_2944115722558364854[0] = state[6] + state[9];
   out_2944115722558364854[1] = state[7] + state[10];
   out_2944115722558364854[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2235410685981716499) {
   out_2235410685981716499[0] = 0;
   out_2235410685981716499[1] = 0;
   out_2235410685981716499[2] = 0;
   out_2235410685981716499[3] = 0;
   out_2235410685981716499[4] = 0;
   out_2235410685981716499[5] = 0;
   out_2235410685981716499[6] = 1;
   out_2235410685981716499[7] = 0;
   out_2235410685981716499[8] = 0;
   out_2235410685981716499[9] = 1;
   out_2235410685981716499[10] = 0;
   out_2235410685981716499[11] = 0;
   out_2235410685981716499[12] = 0;
   out_2235410685981716499[13] = 0;
   out_2235410685981716499[14] = 0;
   out_2235410685981716499[15] = 0;
   out_2235410685981716499[16] = 0;
   out_2235410685981716499[17] = 0;
   out_2235410685981716499[18] = 0;
   out_2235410685981716499[19] = 0;
   out_2235410685981716499[20] = 0;
   out_2235410685981716499[21] = 0;
   out_2235410685981716499[22] = 0;
   out_2235410685981716499[23] = 0;
   out_2235410685981716499[24] = 0;
   out_2235410685981716499[25] = 1;
   out_2235410685981716499[26] = 0;
   out_2235410685981716499[27] = 0;
   out_2235410685981716499[28] = 1;
   out_2235410685981716499[29] = 0;
   out_2235410685981716499[30] = 0;
   out_2235410685981716499[31] = 0;
   out_2235410685981716499[32] = 0;
   out_2235410685981716499[33] = 0;
   out_2235410685981716499[34] = 0;
   out_2235410685981716499[35] = 0;
   out_2235410685981716499[36] = 0;
   out_2235410685981716499[37] = 0;
   out_2235410685981716499[38] = 0;
   out_2235410685981716499[39] = 0;
   out_2235410685981716499[40] = 0;
   out_2235410685981716499[41] = 0;
   out_2235410685981716499[42] = 0;
   out_2235410685981716499[43] = 0;
   out_2235410685981716499[44] = 1;
   out_2235410685981716499[45] = 0;
   out_2235410685981716499[46] = 0;
   out_2235410685981716499[47] = 1;
   out_2235410685981716499[48] = 0;
   out_2235410685981716499[49] = 0;
   out_2235410685981716499[50] = 0;
   out_2235410685981716499[51] = 0;
   out_2235410685981716499[52] = 0;
   out_2235410685981716499[53] = 0;
}
void h_10(double *state, double *unused, double *out_5480980924344673221) {
   out_5480980924344673221[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5480980924344673221[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5480980924344673221[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6151696322213561701) {
   out_6151696322213561701[0] = 0;
   out_6151696322213561701[1] = 9.8100000000000005*cos(state[1]);
   out_6151696322213561701[2] = 0;
   out_6151696322213561701[3] = 0;
   out_6151696322213561701[4] = -state[8];
   out_6151696322213561701[5] = state[7];
   out_6151696322213561701[6] = 0;
   out_6151696322213561701[7] = state[5];
   out_6151696322213561701[8] = -state[4];
   out_6151696322213561701[9] = 0;
   out_6151696322213561701[10] = 0;
   out_6151696322213561701[11] = 0;
   out_6151696322213561701[12] = 1;
   out_6151696322213561701[13] = 0;
   out_6151696322213561701[14] = 0;
   out_6151696322213561701[15] = 1;
   out_6151696322213561701[16] = 0;
   out_6151696322213561701[17] = 0;
   out_6151696322213561701[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6151696322213561701[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6151696322213561701[20] = 0;
   out_6151696322213561701[21] = state[8];
   out_6151696322213561701[22] = 0;
   out_6151696322213561701[23] = -state[6];
   out_6151696322213561701[24] = -state[5];
   out_6151696322213561701[25] = 0;
   out_6151696322213561701[26] = state[3];
   out_6151696322213561701[27] = 0;
   out_6151696322213561701[28] = 0;
   out_6151696322213561701[29] = 0;
   out_6151696322213561701[30] = 0;
   out_6151696322213561701[31] = 1;
   out_6151696322213561701[32] = 0;
   out_6151696322213561701[33] = 0;
   out_6151696322213561701[34] = 1;
   out_6151696322213561701[35] = 0;
   out_6151696322213561701[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6151696322213561701[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6151696322213561701[38] = 0;
   out_6151696322213561701[39] = -state[7];
   out_6151696322213561701[40] = state[6];
   out_6151696322213561701[41] = 0;
   out_6151696322213561701[42] = state[4];
   out_6151696322213561701[43] = -state[3];
   out_6151696322213561701[44] = 0;
   out_6151696322213561701[45] = 0;
   out_6151696322213561701[46] = 0;
   out_6151696322213561701[47] = 0;
   out_6151696322213561701[48] = 0;
   out_6151696322213561701[49] = 0;
   out_6151696322213561701[50] = 1;
   out_6151696322213561701[51] = 0;
   out_6151696322213561701[52] = 0;
   out_6151696322213561701[53] = 1;
}
void h_13(double *state, double *unused, double *out_1838073821593632587) {
   out_1838073821593632587[0] = state[3];
   out_1838073821593632587[1] = state[4];
   out_1838073821593632587[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8600702179411134188) {
   out_8600702179411134188[0] = 0;
   out_8600702179411134188[1] = 0;
   out_8600702179411134188[2] = 0;
   out_8600702179411134188[3] = 1;
   out_8600702179411134188[4] = 0;
   out_8600702179411134188[5] = 0;
   out_8600702179411134188[6] = 0;
   out_8600702179411134188[7] = 0;
   out_8600702179411134188[8] = 0;
   out_8600702179411134188[9] = 0;
   out_8600702179411134188[10] = 0;
   out_8600702179411134188[11] = 0;
   out_8600702179411134188[12] = 0;
   out_8600702179411134188[13] = 0;
   out_8600702179411134188[14] = 0;
   out_8600702179411134188[15] = 0;
   out_8600702179411134188[16] = 0;
   out_8600702179411134188[17] = 0;
   out_8600702179411134188[18] = 0;
   out_8600702179411134188[19] = 0;
   out_8600702179411134188[20] = 0;
   out_8600702179411134188[21] = 0;
   out_8600702179411134188[22] = 1;
   out_8600702179411134188[23] = 0;
   out_8600702179411134188[24] = 0;
   out_8600702179411134188[25] = 0;
   out_8600702179411134188[26] = 0;
   out_8600702179411134188[27] = 0;
   out_8600702179411134188[28] = 0;
   out_8600702179411134188[29] = 0;
   out_8600702179411134188[30] = 0;
   out_8600702179411134188[31] = 0;
   out_8600702179411134188[32] = 0;
   out_8600702179411134188[33] = 0;
   out_8600702179411134188[34] = 0;
   out_8600702179411134188[35] = 0;
   out_8600702179411134188[36] = 0;
   out_8600702179411134188[37] = 0;
   out_8600702179411134188[38] = 0;
   out_8600702179411134188[39] = 0;
   out_8600702179411134188[40] = 0;
   out_8600702179411134188[41] = 1;
   out_8600702179411134188[42] = 0;
   out_8600702179411134188[43] = 0;
   out_8600702179411134188[44] = 0;
   out_8600702179411134188[45] = 0;
   out_8600702179411134188[46] = 0;
   out_8600702179411134188[47] = 0;
   out_8600702179411134188[48] = 0;
   out_8600702179411134188[49] = 0;
   out_8600702179411134188[50] = 0;
   out_8600702179411134188[51] = 0;
   out_8600702179411134188[52] = 0;
   out_8600702179411134188[53] = 0;
}
void h_14(double *state, double *unused, double *out_7366225133021847841) {
   out_7366225133021847841[0] = state[6];
   out_7366225133021847841[1] = state[7];
   out_7366225133021847841[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6198651542321201028) {
   out_6198651542321201028[0] = 0;
   out_6198651542321201028[1] = 0;
   out_6198651542321201028[2] = 0;
   out_6198651542321201028[3] = 0;
   out_6198651542321201028[4] = 0;
   out_6198651542321201028[5] = 0;
   out_6198651542321201028[6] = 1;
   out_6198651542321201028[7] = 0;
   out_6198651542321201028[8] = 0;
   out_6198651542321201028[9] = 0;
   out_6198651542321201028[10] = 0;
   out_6198651542321201028[11] = 0;
   out_6198651542321201028[12] = 0;
   out_6198651542321201028[13] = 0;
   out_6198651542321201028[14] = 0;
   out_6198651542321201028[15] = 0;
   out_6198651542321201028[16] = 0;
   out_6198651542321201028[17] = 0;
   out_6198651542321201028[18] = 0;
   out_6198651542321201028[19] = 0;
   out_6198651542321201028[20] = 0;
   out_6198651542321201028[21] = 0;
   out_6198651542321201028[22] = 0;
   out_6198651542321201028[23] = 0;
   out_6198651542321201028[24] = 0;
   out_6198651542321201028[25] = 1;
   out_6198651542321201028[26] = 0;
   out_6198651542321201028[27] = 0;
   out_6198651542321201028[28] = 0;
   out_6198651542321201028[29] = 0;
   out_6198651542321201028[30] = 0;
   out_6198651542321201028[31] = 0;
   out_6198651542321201028[32] = 0;
   out_6198651542321201028[33] = 0;
   out_6198651542321201028[34] = 0;
   out_6198651542321201028[35] = 0;
   out_6198651542321201028[36] = 0;
   out_6198651542321201028[37] = 0;
   out_6198651542321201028[38] = 0;
   out_6198651542321201028[39] = 0;
   out_6198651542321201028[40] = 0;
   out_6198651542321201028[41] = 0;
   out_6198651542321201028[42] = 0;
   out_6198651542321201028[43] = 0;
   out_6198651542321201028[44] = 1;
   out_6198651542321201028[45] = 0;
   out_6198651542321201028[46] = 0;
   out_6198651542321201028[47] = 0;
   out_6198651542321201028[48] = 0;
   out_6198651542321201028[49] = 0;
   out_6198651542321201028[50] = 0;
   out_6198651542321201028[51] = 0;
   out_6198651542321201028[52] = 0;
   out_6198651542321201028[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5866923855832820417) {
  err_fun(nom_x, delta_x, out_5866923855832820417);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7354374655466778507) {
  inv_err_fun(nom_x, true_x, out_7354374655466778507);
}
void pose_H_mod_fun(double *state, double *out_5435820587083186523) {
  H_mod_fun(state, out_5435820587083186523);
}
void pose_f_fun(double *state, double dt, double *out_5089910609496554967) {
  f_fun(state,  dt, out_5089910609496554967);
}
void pose_F_fun(double *state, double dt, double *out_7337888639276922507) {
  F_fun(state,  dt, out_7337888639276922507);
}
void pose_h_4(double *state, double *unused, double *out_2944115722558364854) {
  h_4(state, unused, out_2944115722558364854);
}
void pose_H_4(double *state, double *unused, double *out_2235410685981716499) {
  H_4(state, unused, out_2235410685981716499);
}
void pose_h_10(double *state, double *unused, double *out_5480980924344673221) {
  h_10(state, unused, out_5480980924344673221);
}
void pose_H_10(double *state, double *unused, double *out_6151696322213561701) {
  H_10(state, unused, out_6151696322213561701);
}
void pose_h_13(double *state, double *unused, double *out_1838073821593632587) {
  h_13(state, unused, out_1838073821593632587);
}
void pose_H_13(double *state, double *unused, double *out_8600702179411134188) {
  H_13(state, unused, out_8600702179411134188);
}
void pose_h_14(double *state, double *unused, double *out_7366225133021847841) {
  h_14(state, unused, out_7366225133021847841);
}
void pose_H_14(double *state, double *unused, double *out_6198651542321201028) {
  H_14(state, unused, out_6198651542321201028);
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
