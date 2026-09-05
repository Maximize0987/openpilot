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
void err_fun(double *nom_x, double *delta_x, double *out_7136046097392635975) {
   out_7136046097392635975[0] = delta_x[0] + nom_x[0];
   out_7136046097392635975[1] = delta_x[1] + nom_x[1];
   out_7136046097392635975[2] = delta_x[2] + nom_x[2];
   out_7136046097392635975[3] = delta_x[3] + nom_x[3];
   out_7136046097392635975[4] = delta_x[4] + nom_x[4];
   out_7136046097392635975[5] = delta_x[5] + nom_x[5];
   out_7136046097392635975[6] = delta_x[6] + nom_x[6];
   out_7136046097392635975[7] = delta_x[7] + nom_x[7];
   out_7136046097392635975[8] = delta_x[8] + nom_x[8];
   out_7136046097392635975[9] = delta_x[9] + nom_x[9];
   out_7136046097392635975[10] = delta_x[10] + nom_x[10];
   out_7136046097392635975[11] = delta_x[11] + nom_x[11];
   out_7136046097392635975[12] = delta_x[12] + nom_x[12];
   out_7136046097392635975[13] = delta_x[13] + nom_x[13];
   out_7136046097392635975[14] = delta_x[14] + nom_x[14];
   out_7136046097392635975[15] = delta_x[15] + nom_x[15];
   out_7136046097392635975[16] = delta_x[16] + nom_x[16];
   out_7136046097392635975[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7829757394788773504) {
   out_7829757394788773504[0] = -nom_x[0] + true_x[0];
   out_7829757394788773504[1] = -nom_x[1] + true_x[1];
   out_7829757394788773504[2] = -nom_x[2] + true_x[2];
   out_7829757394788773504[3] = -nom_x[3] + true_x[3];
   out_7829757394788773504[4] = -nom_x[4] + true_x[4];
   out_7829757394788773504[5] = -nom_x[5] + true_x[5];
   out_7829757394788773504[6] = -nom_x[6] + true_x[6];
   out_7829757394788773504[7] = -nom_x[7] + true_x[7];
   out_7829757394788773504[8] = -nom_x[8] + true_x[8];
   out_7829757394788773504[9] = -nom_x[9] + true_x[9];
   out_7829757394788773504[10] = -nom_x[10] + true_x[10];
   out_7829757394788773504[11] = -nom_x[11] + true_x[11];
   out_7829757394788773504[12] = -nom_x[12] + true_x[12];
   out_7829757394788773504[13] = -nom_x[13] + true_x[13];
   out_7829757394788773504[14] = -nom_x[14] + true_x[14];
   out_7829757394788773504[15] = -nom_x[15] + true_x[15];
   out_7829757394788773504[16] = -nom_x[16] + true_x[16];
   out_7829757394788773504[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4151448671193851274) {
   out_4151448671193851274[0] = 1.0;
   out_4151448671193851274[1] = 0.0;
   out_4151448671193851274[2] = 0.0;
   out_4151448671193851274[3] = 0.0;
   out_4151448671193851274[4] = 0.0;
   out_4151448671193851274[5] = 0.0;
   out_4151448671193851274[6] = 0.0;
   out_4151448671193851274[7] = 0.0;
   out_4151448671193851274[8] = 0.0;
   out_4151448671193851274[9] = 0.0;
   out_4151448671193851274[10] = 0.0;
   out_4151448671193851274[11] = 0.0;
   out_4151448671193851274[12] = 0.0;
   out_4151448671193851274[13] = 0.0;
   out_4151448671193851274[14] = 0.0;
   out_4151448671193851274[15] = 0.0;
   out_4151448671193851274[16] = 0.0;
   out_4151448671193851274[17] = 0.0;
   out_4151448671193851274[18] = 0.0;
   out_4151448671193851274[19] = 1.0;
   out_4151448671193851274[20] = 0.0;
   out_4151448671193851274[21] = 0.0;
   out_4151448671193851274[22] = 0.0;
   out_4151448671193851274[23] = 0.0;
   out_4151448671193851274[24] = 0.0;
   out_4151448671193851274[25] = 0.0;
   out_4151448671193851274[26] = 0.0;
   out_4151448671193851274[27] = 0.0;
   out_4151448671193851274[28] = 0.0;
   out_4151448671193851274[29] = 0.0;
   out_4151448671193851274[30] = 0.0;
   out_4151448671193851274[31] = 0.0;
   out_4151448671193851274[32] = 0.0;
   out_4151448671193851274[33] = 0.0;
   out_4151448671193851274[34] = 0.0;
   out_4151448671193851274[35] = 0.0;
   out_4151448671193851274[36] = 0.0;
   out_4151448671193851274[37] = 0.0;
   out_4151448671193851274[38] = 1.0;
   out_4151448671193851274[39] = 0.0;
   out_4151448671193851274[40] = 0.0;
   out_4151448671193851274[41] = 0.0;
   out_4151448671193851274[42] = 0.0;
   out_4151448671193851274[43] = 0.0;
   out_4151448671193851274[44] = 0.0;
   out_4151448671193851274[45] = 0.0;
   out_4151448671193851274[46] = 0.0;
   out_4151448671193851274[47] = 0.0;
   out_4151448671193851274[48] = 0.0;
   out_4151448671193851274[49] = 0.0;
   out_4151448671193851274[50] = 0.0;
   out_4151448671193851274[51] = 0.0;
   out_4151448671193851274[52] = 0.0;
   out_4151448671193851274[53] = 0.0;
   out_4151448671193851274[54] = 0.0;
   out_4151448671193851274[55] = 0.0;
   out_4151448671193851274[56] = 0.0;
   out_4151448671193851274[57] = 1.0;
   out_4151448671193851274[58] = 0.0;
   out_4151448671193851274[59] = 0.0;
   out_4151448671193851274[60] = 0.0;
   out_4151448671193851274[61] = 0.0;
   out_4151448671193851274[62] = 0.0;
   out_4151448671193851274[63] = 0.0;
   out_4151448671193851274[64] = 0.0;
   out_4151448671193851274[65] = 0.0;
   out_4151448671193851274[66] = 0.0;
   out_4151448671193851274[67] = 0.0;
   out_4151448671193851274[68] = 0.0;
   out_4151448671193851274[69] = 0.0;
   out_4151448671193851274[70] = 0.0;
   out_4151448671193851274[71] = 0.0;
   out_4151448671193851274[72] = 0.0;
   out_4151448671193851274[73] = 0.0;
   out_4151448671193851274[74] = 0.0;
   out_4151448671193851274[75] = 0.0;
   out_4151448671193851274[76] = 1.0;
   out_4151448671193851274[77] = 0.0;
   out_4151448671193851274[78] = 0.0;
   out_4151448671193851274[79] = 0.0;
   out_4151448671193851274[80] = 0.0;
   out_4151448671193851274[81] = 0.0;
   out_4151448671193851274[82] = 0.0;
   out_4151448671193851274[83] = 0.0;
   out_4151448671193851274[84] = 0.0;
   out_4151448671193851274[85] = 0.0;
   out_4151448671193851274[86] = 0.0;
   out_4151448671193851274[87] = 0.0;
   out_4151448671193851274[88] = 0.0;
   out_4151448671193851274[89] = 0.0;
   out_4151448671193851274[90] = 0.0;
   out_4151448671193851274[91] = 0.0;
   out_4151448671193851274[92] = 0.0;
   out_4151448671193851274[93] = 0.0;
   out_4151448671193851274[94] = 0.0;
   out_4151448671193851274[95] = 1.0;
   out_4151448671193851274[96] = 0.0;
   out_4151448671193851274[97] = 0.0;
   out_4151448671193851274[98] = 0.0;
   out_4151448671193851274[99] = 0.0;
   out_4151448671193851274[100] = 0.0;
   out_4151448671193851274[101] = 0.0;
   out_4151448671193851274[102] = 0.0;
   out_4151448671193851274[103] = 0.0;
   out_4151448671193851274[104] = 0.0;
   out_4151448671193851274[105] = 0.0;
   out_4151448671193851274[106] = 0.0;
   out_4151448671193851274[107] = 0.0;
   out_4151448671193851274[108] = 0.0;
   out_4151448671193851274[109] = 0.0;
   out_4151448671193851274[110] = 0.0;
   out_4151448671193851274[111] = 0.0;
   out_4151448671193851274[112] = 0.0;
   out_4151448671193851274[113] = 0.0;
   out_4151448671193851274[114] = 1.0;
   out_4151448671193851274[115] = 0.0;
   out_4151448671193851274[116] = 0.0;
   out_4151448671193851274[117] = 0.0;
   out_4151448671193851274[118] = 0.0;
   out_4151448671193851274[119] = 0.0;
   out_4151448671193851274[120] = 0.0;
   out_4151448671193851274[121] = 0.0;
   out_4151448671193851274[122] = 0.0;
   out_4151448671193851274[123] = 0.0;
   out_4151448671193851274[124] = 0.0;
   out_4151448671193851274[125] = 0.0;
   out_4151448671193851274[126] = 0.0;
   out_4151448671193851274[127] = 0.0;
   out_4151448671193851274[128] = 0.0;
   out_4151448671193851274[129] = 0.0;
   out_4151448671193851274[130] = 0.0;
   out_4151448671193851274[131] = 0.0;
   out_4151448671193851274[132] = 0.0;
   out_4151448671193851274[133] = 1.0;
   out_4151448671193851274[134] = 0.0;
   out_4151448671193851274[135] = 0.0;
   out_4151448671193851274[136] = 0.0;
   out_4151448671193851274[137] = 0.0;
   out_4151448671193851274[138] = 0.0;
   out_4151448671193851274[139] = 0.0;
   out_4151448671193851274[140] = 0.0;
   out_4151448671193851274[141] = 0.0;
   out_4151448671193851274[142] = 0.0;
   out_4151448671193851274[143] = 0.0;
   out_4151448671193851274[144] = 0.0;
   out_4151448671193851274[145] = 0.0;
   out_4151448671193851274[146] = 0.0;
   out_4151448671193851274[147] = 0.0;
   out_4151448671193851274[148] = 0.0;
   out_4151448671193851274[149] = 0.0;
   out_4151448671193851274[150] = 0.0;
   out_4151448671193851274[151] = 0.0;
   out_4151448671193851274[152] = 1.0;
   out_4151448671193851274[153] = 0.0;
   out_4151448671193851274[154] = 0.0;
   out_4151448671193851274[155] = 0.0;
   out_4151448671193851274[156] = 0.0;
   out_4151448671193851274[157] = 0.0;
   out_4151448671193851274[158] = 0.0;
   out_4151448671193851274[159] = 0.0;
   out_4151448671193851274[160] = 0.0;
   out_4151448671193851274[161] = 0.0;
   out_4151448671193851274[162] = 0.0;
   out_4151448671193851274[163] = 0.0;
   out_4151448671193851274[164] = 0.0;
   out_4151448671193851274[165] = 0.0;
   out_4151448671193851274[166] = 0.0;
   out_4151448671193851274[167] = 0.0;
   out_4151448671193851274[168] = 0.0;
   out_4151448671193851274[169] = 0.0;
   out_4151448671193851274[170] = 0.0;
   out_4151448671193851274[171] = 1.0;
   out_4151448671193851274[172] = 0.0;
   out_4151448671193851274[173] = 0.0;
   out_4151448671193851274[174] = 0.0;
   out_4151448671193851274[175] = 0.0;
   out_4151448671193851274[176] = 0.0;
   out_4151448671193851274[177] = 0.0;
   out_4151448671193851274[178] = 0.0;
   out_4151448671193851274[179] = 0.0;
   out_4151448671193851274[180] = 0.0;
   out_4151448671193851274[181] = 0.0;
   out_4151448671193851274[182] = 0.0;
   out_4151448671193851274[183] = 0.0;
   out_4151448671193851274[184] = 0.0;
   out_4151448671193851274[185] = 0.0;
   out_4151448671193851274[186] = 0.0;
   out_4151448671193851274[187] = 0.0;
   out_4151448671193851274[188] = 0.0;
   out_4151448671193851274[189] = 0.0;
   out_4151448671193851274[190] = 1.0;
   out_4151448671193851274[191] = 0.0;
   out_4151448671193851274[192] = 0.0;
   out_4151448671193851274[193] = 0.0;
   out_4151448671193851274[194] = 0.0;
   out_4151448671193851274[195] = 0.0;
   out_4151448671193851274[196] = 0.0;
   out_4151448671193851274[197] = 0.0;
   out_4151448671193851274[198] = 0.0;
   out_4151448671193851274[199] = 0.0;
   out_4151448671193851274[200] = 0.0;
   out_4151448671193851274[201] = 0.0;
   out_4151448671193851274[202] = 0.0;
   out_4151448671193851274[203] = 0.0;
   out_4151448671193851274[204] = 0.0;
   out_4151448671193851274[205] = 0.0;
   out_4151448671193851274[206] = 0.0;
   out_4151448671193851274[207] = 0.0;
   out_4151448671193851274[208] = 0.0;
   out_4151448671193851274[209] = 1.0;
   out_4151448671193851274[210] = 0.0;
   out_4151448671193851274[211] = 0.0;
   out_4151448671193851274[212] = 0.0;
   out_4151448671193851274[213] = 0.0;
   out_4151448671193851274[214] = 0.0;
   out_4151448671193851274[215] = 0.0;
   out_4151448671193851274[216] = 0.0;
   out_4151448671193851274[217] = 0.0;
   out_4151448671193851274[218] = 0.0;
   out_4151448671193851274[219] = 0.0;
   out_4151448671193851274[220] = 0.0;
   out_4151448671193851274[221] = 0.0;
   out_4151448671193851274[222] = 0.0;
   out_4151448671193851274[223] = 0.0;
   out_4151448671193851274[224] = 0.0;
   out_4151448671193851274[225] = 0.0;
   out_4151448671193851274[226] = 0.0;
   out_4151448671193851274[227] = 0.0;
   out_4151448671193851274[228] = 1.0;
   out_4151448671193851274[229] = 0.0;
   out_4151448671193851274[230] = 0.0;
   out_4151448671193851274[231] = 0.0;
   out_4151448671193851274[232] = 0.0;
   out_4151448671193851274[233] = 0.0;
   out_4151448671193851274[234] = 0.0;
   out_4151448671193851274[235] = 0.0;
   out_4151448671193851274[236] = 0.0;
   out_4151448671193851274[237] = 0.0;
   out_4151448671193851274[238] = 0.0;
   out_4151448671193851274[239] = 0.0;
   out_4151448671193851274[240] = 0.0;
   out_4151448671193851274[241] = 0.0;
   out_4151448671193851274[242] = 0.0;
   out_4151448671193851274[243] = 0.0;
   out_4151448671193851274[244] = 0.0;
   out_4151448671193851274[245] = 0.0;
   out_4151448671193851274[246] = 0.0;
   out_4151448671193851274[247] = 1.0;
   out_4151448671193851274[248] = 0.0;
   out_4151448671193851274[249] = 0.0;
   out_4151448671193851274[250] = 0.0;
   out_4151448671193851274[251] = 0.0;
   out_4151448671193851274[252] = 0.0;
   out_4151448671193851274[253] = 0.0;
   out_4151448671193851274[254] = 0.0;
   out_4151448671193851274[255] = 0.0;
   out_4151448671193851274[256] = 0.0;
   out_4151448671193851274[257] = 0.0;
   out_4151448671193851274[258] = 0.0;
   out_4151448671193851274[259] = 0.0;
   out_4151448671193851274[260] = 0.0;
   out_4151448671193851274[261] = 0.0;
   out_4151448671193851274[262] = 0.0;
   out_4151448671193851274[263] = 0.0;
   out_4151448671193851274[264] = 0.0;
   out_4151448671193851274[265] = 0.0;
   out_4151448671193851274[266] = 1.0;
   out_4151448671193851274[267] = 0.0;
   out_4151448671193851274[268] = 0.0;
   out_4151448671193851274[269] = 0.0;
   out_4151448671193851274[270] = 0.0;
   out_4151448671193851274[271] = 0.0;
   out_4151448671193851274[272] = 0.0;
   out_4151448671193851274[273] = 0.0;
   out_4151448671193851274[274] = 0.0;
   out_4151448671193851274[275] = 0.0;
   out_4151448671193851274[276] = 0.0;
   out_4151448671193851274[277] = 0.0;
   out_4151448671193851274[278] = 0.0;
   out_4151448671193851274[279] = 0.0;
   out_4151448671193851274[280] = 0.0;
   out_4151448671193851274[281] = 0.0;
   out_4151448671193851274[282] = 0.0;
   out_4151448671193851274[283] = 0.0;
   out_4151448671193851274[284] = 0.0;
   out_4151448671193851274[285] = 1.0;
   out_4151448671193851274[286] = 0.0;
   out_4151448671193851274[287] = 0.0;
   out_4151448671193851274[288] = 0.0;
   out_4151448671193851274[289] = 0.0;
   out_4151448671193851274[290] = 0.0;
   out_4151448671193851274[291] = 0.0;
   out_4151448671193851274[292] = 0.0;
   out_4151448671193851274[293] = 0.0;
   out_4151448671193851274[294] = 0.0;
   out_4151448671193851274[295] = 0.0;
   out_4151448671193851274[296] = 0.0;
   out_4151448671193851274[297] = 0.0;
   out_4151448671193851274[298] = 0.0;
   out_4151448671193851274[299] = 0.0;
   out_4151448671193851274[300] = 0.0;
   out_4151448671193851274[301] = 0.0;
   out_4151448671193851274[302] = 0.0;
   out_4151448671193851274[303] = 0.0;
   out_4151448671193851274[304] = 1.0;
   out_4151448671193851274[305] = 0.0;
   out_4151448671193851274[306] = 0.0;
   out_4151448671193851274[307] = 0.0;
   out_4151448671193851274[308] = 0.0;
   out_4151448671193851274[309] = 0.0;
   out_4151448671193851274[310] = 0.0;
   out_4151448671193851274[311] = 0.0;
   out_4151448671193851274[312] = 0.0;
   out_4151448671193851274[313] = 0.0;
   out_4151448671193851274[314] = 0.0;
   out_4151448671193851274[315] = 0.0;
   out_4151448671193851274[316] = 0.0;
   out_4151448671193851274[317] = 0.0;
   out_4151448671193851274[318] = 0.0;
   out_4151448671193851274[319] = 0.0;
   out_4151448671193851274[320] = 0.0;
   out_4151448671193851274[321] = 0.0;
   out_4151448671193851274[322] = 0.0;
   out_4151448671193851274[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1642603653923874431) {
   out_1642603653923874431[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1642603653923874431[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1642603653923874431[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1642603653923874431[3] = dt*state[12] + state[3];
   out_1642603653923874431[4] = dt*state[13] + state[4];
   out_1642603653923874431[5] = dt*state[14] + state[5];
   out_1642603653923874431[6] = state[6];
   out_1642603653923874431[7] = state[7];
   out_1642603653923874431[8] = state[8];
   out_1642603653923874431[9] = state[9];
   out_1642603653923874431[10] = state[10];
   out_1642603653923874431[11] = state[11];
   out_1642603653923874431[12] = state[12];
   out_1642603653923874431[13] = state[13];
   out_1642603653923874431[14] = state[14];
   out_1642603653923874431[15] = state[15];
   out_1642603653923874431[16] = state[16];
   out_1642603653923874431[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7023136226815456968) {
   out_7023136226815456968[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7023136226815456968[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7023136226815456968[2] = 0;
   out_7023136226815456968[3] = 0;
   out_7023136226815456968[4] = 0;
   out_7023136226815456968[5] = 0;
   out_7023136226815456968[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7023136226815456968[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7023136226815456968[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7023136226815456968[9] = 0;
   out_7023136226815456968[10] = 0;
   out_7023136226815456968[11] = 0;
   out_7023136226815456968[12] = 0;
   out_7023136226815456968[13] = 0;
   out_7023136226815456968[14] = 0;
   out_7023136226815456968[15] = 0;
   out_7023136226815456968[16] = 0;
   out_7023136226815456968[17] = 0;
   out_7023136226815456968[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7023136226815456968[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7023136226815456968[20] = 0;
   out_7023136226815456968[21] = 0;
   out_7023136226815456968[22] = 0;
   out_7023136226815456968[23] = 0;
   out_7023136226815456968[24] = 0;
   out_7023136226815456968[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7023136226815456968[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7023136226815456968[27] = 0;
   out_7023136226815456968[28] = 0;
   out_7023136226815456968[29] = 0;
   out_7023136226815456968[30] = 0;
   out_7023136226815456968[31] = 0;
   out_7023136226815456968[32] = 0;
   out_7023136226815456968[33] = 0;
   out_7023136226815456968[34] = 0;
   out_7023136226815456968[35] = 0;
   out_7023136226815456968[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7023136226815456968[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7023136226815456968[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7023136226815456968[39] = 0;
   out_7023136226815456968[40] = 0;
   out_7023136226815456968[41] = 0;
   out_7023136226815456968[42] = 0;
   out_7023136226815456968[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7023136226815456968[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7023136226815456968[45] = 0;
   out_7023136226815456968[46] = 0;
   out_7023136226815456968[47] = 0;
   out_7023136226815456968[48] = 0;
   out_7023136226815456968[49] = 0;
   out_7023136226815456968[50] = 0;
   out_7023136226815456968[51] = 0;
   out_7023136226815456968[52] = 0;
   out_7023136226815456968[53] = 0;
   out_7023136226815456968[54] = 0;
   out_7023136226815456968[55] = 0;
   out_7023136226815456968[56] = 0;
   out_7023136226815456968[57] = 1;
   out_7023136226815456968[58] = 0;
   out_7023136226815456968[59] = 0;
   out_7023136226815456968[60] = 0;
   out_7023136226815456968[61] = 0;
   out_7023136226815456968[62] = 0;
   out_7023136226815456968[63] = 0;
   out_7023136226815456968[64] = 0;
   out_7023136226815456968[65] = 0;
   out_7023136226815456968[66] = dt;
   out_7023136226815456968[67] = 0;
   out_7023136226815456968[68] = 0;
   out_7023136226815456968[69] = 0;
   out_7023136226815456968[70] = 0;
   out_7023136226815456968[71] = 0;
   out_7023136226815456968[72] = 0;
   out_7023136226815456968[73] = 0;
   out_7023136226815456968[74] = 0;
   out_7023136226815456968[75] = 0;
   out_7023136226815456968[76] = 1;
   out_7023136226815456968[77] = 0;
   out_7023136226815456968[78] = 0;
   out_7023136226815456968[79] = 0;
   out_7023136226815456968[80] = 0;
   out_7023136226815456968[81] = 0;
   out_7023136226815456968[82] = 0;
   out_7023136226815456968[83] = 0;
   out_7023136226815456968[84] = 0;
   out_7023136226815456968[85] = dt;
   out_7023136226815456968[86] = 0;
   out_7023136226815456968[87] = 0;
   out_7023136226815456968[88] = 0;
   out_7023136226815456968[89] = 0;
   out_7023136226815456968[90] = 0;
   out_7023136226815456968[91] = 0;
   out_7023136226815456968[92] = 0;
   out_7023136226815456968[93] = 0;
   out_7023136226815456968[94] = 0;
   out_7023136226815456968[95] = 1;
   out_7023136226815456968[96] = 0;
   out_7023136226815456968[97] = 0;
   out_7023136226815456968[98] = 0;
   out_7023136226815456968[99] = 0;
   out_7023136226815456968[100] = 0;
   out_7023136226815456968[101] = 0;
   out_7023136226815456968[102] = 0;
   out_7023136226815456968[103] = 0;
   out_7023136226815456968[104] = dt;
   out_7023136226815456968[105] = 0;
   out_7023136226815456968[106] = 0;
   out_7023136226815456968[107] = 0;
   out_7023136226815456968[108] = 0;
   out_7023136226815456968[109] = 0;
   out_7023136226815456968[110] = 0;
   out_7023136226815456968[111] = 0;
   out_7023136226815456968[112] = 0;
   out_7023136226815456968[113] = 0;
   out_7023136226815456968[114] = 1;
   out_7023136226815456968[115] = 0;
   out_7023136226815456968[116] = 0;
   out_7023136226815456968[117] = 0;
   out_7023136226815456968[118] = 0;
   out_7023136226815456968[119] = 0;
   out_7023136226815456968[120] = 0;
   out_7023136226815456968[121] = 0;
   out_7023136226815456968[122] = 0;
   out_7023136226815456968[123] = 0;
   out_7023136226815456968[124] = 0;
   out_7023136226815456968[125] = 0;
   out_7023136226815456968[126] = 0;
   out_7023136226815456968[127] = 0;
   out_7023136226815456968[128] = 0;
   out_7023136226815456968[129] = 0;
   out_7023136226815456968[130] = 0;
   out_7023136226815456968[131] = 0;
   out_7023136226815456968[132] = 0;
   out_7023136226815456968[133] = 1;
   out_7023136226815456968[134] = 0;
   out_7023136226815456968[135] = 0;
   out_7023136226815456968[136] = 0;
   out_7023136226815456968[137] = 0;
   out_7023136226815456968[138] = 0;
   out_7023136226815456968[139] = 0;
   out_7023136226815456968[140] = 0;
   out_7023136226815456968[141] = 0;
   out_7023136226815456968[142] = 0;
   out_7023136226815456968[143] = 0;
   out_7023136226815456968[144] = 0;
   out_7023136226815456968[145] = 0;
   out_7023136226815456968[146] = 0;
   out_7023136226815456968[147] = 0;
   out_7023136226815456968[148] = 0;
   out_7023136226815456968[149] = 0;
   out_7023136226815456968[150] = 0;
   out_7023136226815456968[151] = 0;
   out_7023136226815456968[152] = 1;
   out_7023136226815456968[153] = 0;
   out_7023136226815456968[154] = 0;
   out_7023136226815456968[155] = 0;
   out_7023136226815456968[156] = 0;
   out_7023136226815456968[157] = 0;
   out_7023136226815456968[158] = 0;
   out_7023136226815456968[159] = 0;
   out_7023136226815456968[160] = 0;
   out_7023136226815456968[161] = 0;
   out_7023136226815456968[162] = 0;
   out_7023136226815456968[163] = 0;
   out_7023136226815456968[164] = 0;
   out_7023136226815456968[165] = 0;
   out_7023136226815456968[166] = 0;
   out_7023136226815456968[167] = 0;
   out_7023136226815456968[168] = 0;
   out_7023136226815456968[169] = 0;
   out_7023136226815456968[170] = 0;
   out_7023136226815456968[171] = 1;
   out_7023136226815456968[172] = 0;
   out_7023136226815456968[173] = 0;
   out_7023136226815456968[174] = 0;
   out_7023136226815456968[175] = 0;
   out_7023136226815456968[176] = 0;
   out_7023136226815456968[177] = 0;
   out_7023136226815456968[178] = 0;
   out_7023136226815456968[179] = 0;
   out_7023136226815456968[180] = 0;
   out_7023136226815456968[181] = 0;
   out_7023136226815456968[182] = 0;
   out_7023136226815456968[183] = 0;
   out_7023136226815456968[184] = 0;
   out_7023136226815456968[185] = 0;
   out_7023136226815456968[186] = 0;
   out_7023136226815456968[187] = 0;
   out_7023136226815456968[188] = 0;
   out_7023136226815456968[189] = 0;
   out_7023136226815456968[190] = 1;
   out_7023136226815456968[191] = 0;
   out_7023136226815456968[192] = 0;
   out_7023136226815456968[193] = 0;
   out_7023136226815456968[194] = 0;
   out_7023136226815456968[195] = 0;
   out_7023136226815456968[196] = 0;
   out_7023136226815456968[197] = 0;
   out_7023136226815456968[198] = 0;
   out_7023136226815456968[199] = 0;
   out_7023136226815456968[200] = 0;
   out_7023136226815456968[201] = 0;
   out_7023136226815456968[202] = 0;
   out_7023136226815456968[203] = 0;
   out_7023136226815456968[204] = 0;
   out_7023136226815456968[205] = 0;
   out_7023136226815456968[206] = 0;
   out_7023136226815456968[207] = 0;
   out_7023136226815456968[208] = 0;
   out_7023136226815456968[209] = 1;
   out_7023136226815456968[210] = 0;
   out_7023136226815456968[211] = 0;
   out_7023136226815456968[212] = 0;
   out_7023136226815456968[213] = 0;
   out_7023136226815456968[214] = 0;
   out_7023136226815456968[215] = 0;
   out_7023136226815456968[216] = 0;
   out_7023136226815456968[217] = 0;
   out_7023136226815456968[218] = 0;
   out_7023136226815456968[219] = 0;
   out_7023136226815456968[220] = 0;
   out_7023136226815456968[221] = 0;
   out_7023136226815456968[222] = 0;
   out_7023136226815456968[223] = 0;
   out_7023136226815456968[224] = 0;
   out_7023136226815456968[225] = 0;
   out_7023136226815456968[226] = 0;
   out_7023136226815456968[227] = 0;
   out_7023136226815456968[228] = 1;
   out_7023136226815456968[229] = 0;
   out_7023136226815456968[230] = 0;
   out_7023136226815456968[231] = 0;
   out_7023136226815456968[232] = 0;
   out_7023136226815456968[233] = 0;
   out_7023136226815456968[234] = 0;
   out_7023136226815456968[235] = 0;
   out_7023136226815456968[236] = 0;
   out_7023136226815456968[237] = 0;
   out_7023136226815456968[238] = 0;
   out_7023136226815456968[239] = 0;
   out_7023136226815456968[240] = 0;
   out_7023136226815456968[241] = 0;
   out_7023136226815456968[242] = 0;
   out_7023136226815456968[243] = 0;
   out_7023136226815456968[244] = 0;
   out_7023136226815456968[245] = 0;
   out_7023136226815456968[246] = 0;
   out_7023136226815456968[247] = 1;
   out_7023136226815456968[248] = 0;
   out_7023136226815456968[249] = 0;
   out_7023136226815456968[250] = 0;
   out_7023136226815456968[251] = 0;
   out_7023136226815456968[252] = 0;
   out_7023136226815456968[253] = 0;
   out_7023136226815456968[254] = 0;
   out_7023136226815456968[255] = 0;
   out_7023136226815456968[256] = 0;
   out_7023136226815456968[257] = 0;
   out_7023136226815456968[258] = 0;
   out_7023136226815456968[259] = 0;
   out_7023136226815456968[260] = 0;
   out_7023136226815456968[261] = 0;
   out_7023136226815456968[262] = 0;
   out_7023136226815456968[263] = 0;
   out_7023136226815456968[264] = 0;
   out_7023136226815456968[265] = 0;
   out_7023136226815456968[266] = 1;
   out_7023136226815456968[267] = 0;
   out_7023136226815456968[268] = 0;
   out_7023136226815456968[269] = 0;
   out_7023136226815456968[270] = 0;
   out_7023136226815456968[271] = 0;
   out_7023136226815456968[272] = 0;
   out_7023136226815456968[273] = 0;
   out_7023136226815456968[274] = 0;
   out_7023136226815456968[275] = 0;
   out_7023136226815456968[276] = 0;
   out_7023136226815456968[277] = 0;
   out_7023136226815456968[278] = 0;
   out_7023136226815456968[279] = 0;
   out_7023136226815456968[280] = 0;
   out_7023136226815456968[281] = 0;
   out_7023136226815456968[282] = 0;
   out_7023136226815456968[283] = 0;
   out_7023136226815456968[284] = 0;
   out_7023136226815456968[285] = 1;
   out_7023136226815456968[286] = 0;
   out_7023136226815456968[287] = 0;
   out_7023136226815456968[288] = 0;
   out_7023136226815456968[289] = 0;
   out_7023136226815456968[290] = 0;
   out_7023136226815456968[291] = 0;
   out_7023136226815456968[292] = 0;
   out_7023136226815456968[293] = 0;
   out_7023136226815456968[294] = 0;
   out_7023136226815456968[295] = 0;
   out_7023136226815456968[296] = 0;
   out_7023136226815456968[297] = 0;
   out_7023136226815456968[298] = 0;
   out_7023136226815456968[299] = 0;
   out_7023136226815456968[300] = 0;
   out_7023136226815456968[301] = 0;
   out_7023136226815456968[302] = 0;
   out_7023136226815456968[303] = 0;
   out_7023136226815456968[304] = 1;
   out_7023136226815456968[305] = 0;
   out_7023136226815456968[306] = 0;
   out_7023136226815456968[307] = 0;
   out_7023136226815456968[308] = 0;
   out_7023136226815456968[309] = 0;
   out_7023136226815456968[310] = 0;
   out_7023136226815456968[311] = 0;
   out_7023136226815456968[312] = 0;
   out_7023136226815456968[313] = 0;
   out_7023136226815456968[314] = 0;
   out_7023136226815456968[315] = 0;
   out_7023136226815456968[316] = 0;
   out_7023136226815456968[317] = 0;
   out_7023136226815456968[318] = 0;
   out_7023136226815456968[319] = 0;
   out_7023136226815456968[320] = 0;
   out_7023136226815456968[321] = 0;
   out_7023136226815456968[322] = 0;
   out_7023136226815456968[323] = 1;
}
void h_4(double *state, double *unused, double *out_4588754796686824329) {
   out_4588754796686824329[0] = state[6] + state[9];
   out_4588754796686824329[1] = state[7] + state[10];
   out_4588754796686824329[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6094990518542475575) {
   out_6094990518542475575[0] = 0;
   out_6094990518542475575[1] = 0;
   out_6094990518542475575[2] = 0;
   out_6094990518542475575[3] = 0;
   out_6094990518542475575[4] = 0;
   out_6094990518542475575[5] = 0;
   out_6094990518542475575[6] = 1;
   out_6094990518542475575[7] = 0;
   out_6094990518542475575[8] = 0;
   out_6094990518542475575[9] = 1;
   out_6094990518542475575[10] = 0;
   out_6094990518542475575[11] = 0;
   out_6094990518542475575[12] = 0;
   out_6094990518542475575[13] = 0;
   out_6094990518542475575[14] = 0;
   out_6094990518542475575[15] = 0;
   out_6094990518542475575[16] = 0;
   out_6094990518542475575[17] = 0;
   out_6094990518542475575[18] = 0;
   out_6094990518542475575[19] = 0;
   out_6094990518542475575[20] = 0;
   out_6094990518542475575[21] = 0;
   out_6094990518542475575[22] = 0;
   out_6094990518542475575[23] = 0;
   out_6094990518542475575[24] = 0;
   out_6094990518542475575[25] = 1;
   out_6094990518542475575[26] = 0;
   out_6094990518542475575[27] = 0;
   out_6094990518542475575[28] = 1;
   out_6094990518542475575[29] = 0;
   out_6094990518542475575[30] = 0;
   out_6094990518542475575[31] = 0;
   out_6094990518542475575[32] = 0;
   out_6094990518542475575[33] = 0;
   out_6094990518542475575[34] = 0;
   out_6094990518542475575[35] = 0;
   out_6094990518542475575[36] = 0;
   out_6094990518542475575[37] = 0;
   out_6094990518542475575[38] = 0;
   out_6094990518542475575[39] = 0;
   out_6094990518542475575[40] = 0;
   out_6094990518542475575[41] = 0;
   out_6094990518542475575[42] = 0;
   out_6094990518542475575[43] = 0;
   out_6094990518542475575[44] = 1;
   out_6094990518542475575[45] = 0;
   out_6094990518542475575[46] = 0;
   out_6094990518542475575[47] = 1;
   out_6094990518542475575[48] = 0;
   out_6094990518542475575[49] = 0;
   out_6094990518542475575[50] = 0;
   out_6094990518542475575[51] = 0;
   out_6094990518542475575[52] = 0;
   out_6094990518542475575[53] = 0;
}
void h_10(double *state, double *unused, double *out_2376996171077473254) {
   out_2376996171077473254[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2376996171077473254[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2376996171077473254[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3986987343223994685) {
   out_3986987343223994685[0] = 0;
   out_3986987343223994685[1] = 9.8100000000000005*cos(state[1]);
   out_3986987343223994685[2] = 0;
   out_3986987343223994685[3] = 0;
   out_3986987343223994685[4] = -state[8];
   out_3986987343223994685[5] = state[7];
   out_3986987343223994685[6] = 0;
   out_3986987343223994685[7] = state[5];
   out_3986987343223994685[8] = -state[4];
   out_3986987343223994685[9] = 0;
   out_3986987343223994685[10] = 0;
   out_3986987343223994685[11] = 0;
   out_3986987343223994685[12] = 1;
   out_3986987343223994685[13] = 0;
   out_3986987343223994685[14] = 0;
   out_3986987343223994685[15] = 1;
   out_3986987343223994685[16] = 0;
   out_3986987343223994685[17] = 0;
   out_3986987343223994685[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3986987343223994685[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3986987343223994685[20] = 0;
   out_3986987343223994685[21] = state[8];
   out_3986987343223994685[22] = 0;
   out_3986987343223994685[23] = -state[6];
   out_3986987343223994685[24] = -state[5];
   out_3986987343223994685[25] = 0;
   out_3986987343223994685[26] = state[3];
   out_3986987343223994685[27] = 0;
   out_3986987343223994685[28] = 0;
   out_3986987343223994685[29] = 0;
   out_3986987343223994685[30] = 0;
   out_3986987343223994685[31] = 1;
   out_3986987343223994685[32] = 0;
   out_3986987343223994685[33] = 0;
   out_3986987343223994685[34] = 1;
   out_3986987343223994685[35] = 0;
   out_3986987343223994685[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3986987343223994685[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3986987343223994685[38] = 0;
   out_3986987343223994685[39] = -state[7];
   out_3986987343223994685[40] = state[6];
   out_3986987343223994685[41] = 0;
   out_3986987343223994685[42] = state[4];
   out_3986987343223994685[43] = -state[3];
   out_3986987343223994685[44] = 0;
   out_3986987343223994685[45] = 0;
   out_3986987343223994685[46] = 0;
   out_3986987343223994685[47] = 0;
   out_3986987343223994685[48] = 0;
   out_3986987343223994685[49] = 0;
   out_3986987343223994685[50] = 1;
   out_3986987343223994685[51] = 0;
   out_3986987343223994685[52] = 0;
   out_3986987343223994685[53] = 1;
}
void h_13(double *state, double *unused, double *out_4475690324738606342) {
   out_4475690324738606342[0] = state[3];
   out_4475690324738606342[1] = state[4];
   out_4475690324738606342[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1515640689774225354) {
   out_1515640689774225354[0] = 0;
   out_1515640689774225354[1] = 0;
   out_1515640689774225354[2] = 0;
   out_1515640689774225354[3] = 1;
   out_1515640689774225354[4] = 0;
   out_1515640689774225354[5] = 0;
   out_1515640689774225354[6] = 0;
   out_1515640689774225354[7] = 0;
   out_1515640689774225354[8] = 0;
   out_1515640689774225354[9] = 0;
   out_1515640689774225354[10] = 0;
   out_1515640689774225354[11] = 0;
   out_1515640689774225354[12] = 0;
   out_1515640689774225354[13] = 0;
   out_1515640689774225354[14] = 0;
   out_1515640689774225354[15] = 0;
   out_1515640689774225354[16] = 0;
   out_1515640689774225354[17] = 0;
   out_1515640689774225354[18] = 0;
   out_1515640689774225354[19] = 0;
   out_1515640689774225354[20] = 0;
   out_1515640689774225354[21] = 0;
   out_1515640689774225354[22] = 1;
   out_1515640689774225354[23] = 0;
   out_1515640689774225354[24] = 0;
   out_1515640689774225354[25] = 0;
   out_1515640689774225354[26] = 0;
   out_1515640689774225354[27] = 0;
   out_1515640689774225354[28] = 0;
   out_1515640689774225354[29] = 0;
   out_1515640689774225354[30] = 0;
   out_1515640689774225354[31] = 0;
   out_1515640689774225354[32] = 0;
   out_1515640689774225354[33] = 0;
   out_1515640689774225354[34] = 0;
   out_1515640689774225354[35] = 0;
   out_1515640689774225354[36] = 0;
   out_1515640689774225354[37] = 0;
   out_1515640689774225354[38] = 0;
   out_1515640689774225354[39] = 0;
   out_1515640689774225354[40] = 0;
   out_1515640689774225354[41] = 1;
   out_1515640689774225354[42] = 0;
   out_1515640689774225354[43] = 0;
   out_1515640689774225354[44] = 0;
   out_1515640689774225354[45] = 0;
   out_1515640689774225354[46] = 0;
   out_1515640689774225354[47] = 0;
   out_1515640689774225354[48] = 0;
   out_1515640689774225354[49] = 0;
   out_1515640689774225354[50] = 0;
   out_1515640689774225354[51] = 0;
   out_1515640689774225354[52] = 0;
   out_1515640689774225354[53] = 0;
}
void h_14(double *state, double *unused, double *out_4137331969092828561) {
   out_4137331969092828561[0] = state[6];
   out_4137331969092828561[1] = state[7];
   out_4137331969092828561[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2131749662202991046) {
   out_2131749662202991046[0] = 0;
   out_2131749662202991046[1] = 0;
   out_2131749662202991046[2] = 0;
   out_2131749662202991046[3] = 0;
   out_2131749662202991046[4] = 0;
   out_2131749662202991046[5] = 0;
   out_2131749662202991046[6] = 1;
   out_2131749662202991046[7] = 0;
   out_2131749662202991046[8] = 0;
   out_2131749662202991046[9] = 0;
   out_2131749662202991046[10] = 0;
   out_2131749662202991046[11] = 0;
   out_2131749662202991046[12] = 0;
   out_2131749662202991046[13] = 0;
   out_2131749662202991046[14] = 0;
   out_2131749662202991046[15] = 0;
   out_2131749662202991046[16] = 0;
   out_2131749662202991046[17] = 0;
   out_2131749662202991046[18] = 0;
   out_2131749662202991046[19] = 0;
   out_2131749662202991046[20] = 0;
   out_2131749662202991046[21] = 0;
   out_2131749662202991046[22] = 0;
   out_2131749662202991046[23] = 0;
   out_2131749662202991046[24] = 0;
   out_2131749662202991046[25] = 1;
   out_2131749662202991046[26] = 0;
   out_2131749662202991046[27] = 0;
   out_2131749662202991046[28] = 0;
   out_2131749662202991046[29] = 0;
   out_2131749662202991046[30] = 0;
   out_2131749662202991046[31] = 0;
   out_2131749662202991046[32] = 0;
   out_2131749662202991046[33] = 0;
   out_2131749662202991046[34] = 0;
   out_2131749662202991046[35] = 0;
   out_2131749662202991046[36] = 0;
   out_2131749662202991046[37] = 0;
   out_2131749662202991046[38] = 0;
   out_2131749662202991046[39] = 0;
   out_2131749662202991046[40] = 0;
   out_2131749662202991046[41] = 0;
   out_2131749662202991046[42] = 0;
   out_2131749662202991046[43] = 0;
   out_2131749662202991046[44] = 1;
   out_2131749662202991046[45] = 0;
   out_2131749662202991046[46] = 0;
   out_2131749662202991046[47] = 0;
   out_2131749662202991046[48] = 0;
   out_2131749662202991046[49] = 0;
   out_2131749662202991046[50] = 0;
   out_2131749662202991046[51] = 0;
   out_2131749662202991046[52] = 0;
   out_2131749662202991046[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7136046097392635975) {
  err_fun(nom_x, delta_x, out_7136046097392635975);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7829757394788773504) {
  inv_err_fun(nom_x, true_x, out_7829757394788773504);
}
void pose_H_mod_fun(double *state, double *out_4151448671193851274) {
  H_mod_fun(state, out_4151448671193851274);
}
void pose_f_fun(double *state, double dt, double *out_1642603653923874431) {
  f_fun(state,  dt, out_1642603653923874431);
}
void pose_F_fun(double *state, double dt, double *out_7023136226815456968) {
  F_fun(state,  dt, out_7023136226815456968);
}
void pose_h_4(double *state, double *unused, double *out_4588754796686824329) {
  h_4(state, unused, out_4588754796686824329);
}
void pose_H_4(double *state, double *unused, double *out_6094990518542475575) {
  H_4(state, unused, out_6094990518542475575);
}
void pose_h_10(double *state, double *unused, double *out_2376996171077473254) {
  h_10(state, unused, out_2376996171077473254);
}
void pose_H_10(double *state, double *unused, double *out_3986987343223994685) {
  H_10(state, unused, out_3986987343223994685);
}
void pose_h_13(double *state, double *unused, double *out_4475690324738606342) {
  h_13(state, unused, out_4475690324738606342);
}
void pose_H_13(double *state, double *unused, double *out_1515640689774225354) {
  H_13(state, unused, out_1515640689774225354);
}
void pose_h_14(double *state, double *unused, double *out_4137331969092828561) {
  h_14(state, unused, out_4137331969092828561);
}
void pose_H_14(double *state, double *unused, double *out_2131749662202991046) {
  H_14(state, unused, out_2131749662202991046);
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
