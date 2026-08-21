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
void err_fun(double *nom_x, double *delta_x, double *out_788519772333288428) {
   out_788519772333288428[0] = delta_x[0] + nom_x[0];
   out_788519772333288428[1] = delta_x[1] + nom_x[1];
   out_788519772333288428[2] = delta_x[2] + nom_x[2];
   out_788519772333288428[3] = delta_x[3] + nom_x[3];
   out_788519772333288428[4] = delta_x[4] + nom_x[4];
   out_788519772333288428[5] = delta_x[5] + nom_x[5];
   out_788519772333288428[6] = delta_x[6] + nom_x[6];
   out_788519772333288428[7] = delta_x[7] + nom_x[7];
   out_788519772333288428[8] = delta_x[8] + nom_x[8];
   out_788519772333288428[9] = delta_x[9] + nom_x[9];
   out_788519772333288428[10] = delta_x[10] + nom_x[10];
   out_788519772333288428[11] = delta_x[11] + nom_x[11];
   out_788519772333288428[12] = delta_x[12] + nom_x[12];
   out_788519772333288428[13] = delta_x[13] + nom_x[13];
   out_788519772333288428[14] = delta_x[14] + nom_x[14];
   out_788519772333288428[15] = delta_x[15] + nom_x[15];
   out_788519772333288428[16] = delta_x[16] + nom_x[16];
   out_788519772333288428[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3476371721226452847) {
   out_3476371721226452847[0] = -nom_x[0] + true_x[0];
   out_3476371721226452847[1] = -nom_x[1] + true_x[1];
   out_3476371721226452847[2] = -nom_x[2] + true_x[2];
   out_3476371721226452847[3] = -nom_x[3] + true_x[3];
   out_3476371721226452847[4] = -nom_x[4] + true_x[4];
   out_3476371721226452847[5] = -nom_x[5] + true_x[5];
   out_3476371721226452847[6] = -nom_x[6] + true_x[6];
   out_3476371721226452847[7] = -nom_x[7] + true_x[7];
   out_3476371721226452847[8] = -nom_x[8] + true_x[8];
   out_3476371721226452847[9] = -nom_x[9] + true_x[9];
   out_3476371721226452847[10] = -nom_x[10] + true_x[10];
   out_3476371721226452847[11] = -nom_x[11] + true_x[11];
   out_3476371721226452847[12] = -nom_x[12] + true_x[12];
   out_3476371721226452847[13] = -nom_x[13] + true_x[13];
   out_3476371721226452847[14] = -nom_x[14] + true_x[14];
   out_3476371721226452847[15] = -nom_x[15] + true_x[15];
   out_3476371721226452847[16] = -nom_x[16] + true_x[16];
   out_3476371721226452847[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1856202857491626372) {
   out_1856202857491626372[0] = 1.0;
   out_1856202857491626372[1] = 0.0;
   out_1856202857491626372[2] = 0.0;
   out_1856202857491626372[3] = 0.0;
   out_1856202857491626372[4] = 0.0;
   out_1856202857491626372[5] = 0.0;
   out_1856202857491626372[6] = 0.0;
   out_1856202857491626372[7] = 0.0;
   out_1856202857491626372[8] = 0.0;
   out_1856202857491626372[9] = 0.0;
   out_1856202857491626372[10] = 0.0;
   out_1856202857491626372[11] = 0.0;
   out_1856202857491626372[12] = 0.0;
   out_1856202857491626372[13] = 0.0;
   out_1856202857491626372[14] = 0.0;
   out_1856202857491626372[15] = 0.0;
   out_1856202857491626372[16] = 0.0;
   out_1856202857491626372[17] = 0.0;
   out_1856202857491626372[18] = 0.0;
   out_1856202857491626372[19] = 1.0;
   out_1856202857491626372[20] = 0.0;
   out_1856202857491626372[21] = 0.0;
   out_1856202857491626372[22] = 0.0;
   out_1856202857491626372[23] = 0.0;
   out_1856202857491626372[24] = 0.0;
   out_1856202857491626372[25] = 0.0;
   out_1856202857491626372[26] = 0.0;
   out_1856202857491626372[27] = 0.0;
   out_1856202857491626372[28] = 0.0;
   out_1856202857491626372[29] = 0.0;
   out_1856202857491626372[30] = 0.0;
   out_1856202857491626372[31] = 0.0;
   out_1856202857491626372[32] = 0.0;
   out_1856202857491626372[33] = 0.0;
   out_1856202857491626372[34] = 0.0;
   out_1856202857491626372[35] = 0.0;
   out_1856202857491626372[36] = 0.0;
   out_1856202857491626372[37] = 0.0;
   out_1856202857491626372[38] = 1.0;
   out_1856202857491626372[39] = 0.0;
   out_1856202857491626372[40] = 0.0;
   out_1856202857491626372[41] = 0.0;
   out_1856202857491626372[42] = 0.0;
   out_1856202857491626372[43] = 0.0;
   out_1856202857491626372[44] = 0.0;
   out_1856202857491626372[45] = 0.0;
   out_1856202857491626372[46] = 0.0;
   out_1856202857491626372[47] = 0.0;
   out_1856202857491626372[48] = 0.0;
   out_1856202857491626372[49] = 0.0;
   out_1856202857491626372[50] = 0.0;
   out_1856202857491626372[51] = 0.0;
   out_1856202857491626372[52] = 0.0;
   out_1856202857491626372[53] = 0.0;
   out_1856202857491626372[54] = 0.0;
   out_1856202857491626372[55] = 0.0;
   out_1856202857491626372[56] = 0.0;
   out_1856202857491626372[57] = 1.0;
   out_1856202857491626372[58] = 0.0;
   out_1856202857491626372[59] = 0.0;
   out_1856202857491626372[60] = 0.0;
   out_1856202857491626372[61] = 0.0;
   out_1856202857491626372[62] = 0.0;
   out_1856202857491626372[63] = 0.0;
   out_1856202857491626372[64] = 0.0;
   out_1856202857491626372[65] = 0.0;
   out_1856202857491626372[66] = 0.0;
   out_1856202857491626372[67] = 0.0;
   out_1856202857491626372[68] = 0.0;
   out_1856202857491626372[69] = 0.0;
   out_1856202857491626372[70] = 0.0;
   out_1856202857491626372[71] = 0.0;
   out_1856202857491626372[72] = 0.0;
   out_1856202857491626372[73] = 0.0;
   out_1856202857491626372[74] = 0.0;
   out_1856202857491626372[75] = 0.0;
   out_1856202857491626372[76] = 1.0;
   out_1856202857491626372[77] = 0.0;
   out_1856202857491626372[78] = 0.0;
   out_1856202857491626372[79] = 0.0;
   out_1856202857491626372[80] = 0.0;
   out_1856202857491626372[81] = 0.0;
   out_1856202857491626372[82] = 0.0;
   out_1856202857491626372[83] = 0.0;
   out_1856202857491626372[84] = 0.0;
   out_1856202857491626372[85] = 0.0;
   out_1856202857491626372[86] = 0.0;
   out_1856202857491626372[87] = 0.0;
   out_1856202857491626372[88] = 0.0;
   out_1856202857491626372[89] = 0.0;
   out_1856202857491626372[90] = 0.0;
   out_1856202857491626372[91] = 0.0;
   out_1856202857491626372[92] = 0.0;
   out_1856202857491626372[93] = 0.0;
   out_1856202857491626372[94] = 0.0;
   out_1856202857491626372[95] = 1.0;
   out_1856202857491626372[96] = 0.0;
   out_1856202857491626372[97] = 0.0;
   out_1856202857491626372[98] = 0.0;
   out_1856202857491626372[99] = 0.0;
   out_1856202857491626372[100] = 0.0;
   out_1856202857491626372[101] = 0.0;
   out_1856202857491626372[102] = 0.0;
   out_1856202857491626372[103] = 0.0;
   out_1856202857491626372[104] = 0.0;
   out_1856202857491626372[105] = 0.0;
   out_1856202857491626372[106] = 0.0;
   out_1856202857491626372[107] = 0.0;
   out_1856202857491626372[108] = 0.0;
   out_1856202857491626372[109] = 0.0;
   out_1856202857491626372[110] = 0.0;
   out_1856202857491626372[111] = 0.0;
   out_1856202857491626372[112] = 0.0;
   out_1856202857491626372[113] = 0.0;
   out_1856202857491626372[114] = 1.0;
   out_1856202857491626372[115] = 0.0;
   out_1856202857491626372[116] = 0.0;
   out_1856202857491626372[117] = 0.0;
   out_1856202857491626372[118] = 0.0;
   out_1856202857491626372[119] = 0.0;
   out_1856202857491626372[120] = 0.0;
   out_1856202857491626372[121] = 0.0;
   out_1856202857491626372[122] = 0.0;
   out_1856202857491626372[123] = 0.0;
   out_1856202857491626372[124] = 0.0;
   out_1856202857491626372[125] = 0.0;
   out_1856202857491626372[126] = 0.0;
   out_1856202857491626372[127] = 0.0;
   out_1856202857491626372[128] = 0.0;
   out_1856202857491626372[129] = 0.0;
   out_1856202857491626372[130] = 0.0;
   out_1856202857491626372[131] = 0.0;
   out_1856202857491626372[132] = 0.0;
   out_1856202857491626372[133] = 1.0;
   out_1856202857491626372[134] = 0.0;
   out_1856202857491626372[135] = 0.0;
   out_1856202857491626372[136] = 0.0;
   out_1856202857491626372[137] = 0.0;
   out_1856202857491626372[138] = 0.0;
   out_1856202857491626372[139] = 0.0;
   out_1856202857491626372[140] = 0.0;
   out_1856202857491626372[141] = 0.0;
   out_1856202857491626372[142] = 0.0;
   out_1856202857491626372[143] = 0.0;
   out_1856202857491626372[144] = 0.0;
   out_1856202857491626372[145] = 0.0;
   out_1856202857491626372[146] = 0.0;
   out_1856202857491626372[147] = 0.0;
   out_1856202857491626372[148] = 0.0;
   out_1856202857491626372[149] = 0.0;
   out_1856202857491626372[150] = 0.0;
   out_1856202857491626372[151] = 0.0;
   out_1856202857491626372[152] = 1.0;
   out_1856202857491626372[153] = 0.0;
   out_1856202857491626372[154] = 0.0;
   out_1856202857491626372[155] = 0.0;
   out_1856202857491626372[156] = 0.0;
   out_1856202857491626372[157] = 0.0;
   out_1856202857491626372[158] = 0.0;
   out_1856202857491626372[159] = 0.0;
   out_1856202857491626372[160] = 0.0;
   out_1856202857491626372[161] = 0.0;
   out_1856202857491626372[162] = 0.0;
   out_1856202857491626372[163] = 0.0;
   out_1856202857491626372[164] = 0.0;
   out_1856202857491626372[165] = 0.0;
   out_1856202857491626372[166] = 0.0;
   out_1856202857491626372[167] = 0.0;
   out_1856202857491626372[168] = 0.0;
   out_1856202857491626372[169] = 0.0;
   out_1856202857491626372[170] = 0.0;
   out_1856202857491626372[171] = 1.0;
   out_1856202857491626372[172] = 0.0;
   out_1856202857491626372[173] = 0.0;
   out_1856202857491626372[174] = 0.0;
   out_1856202857491626372[175] = 0.0;
   out_1856202857491626372[176] = 0.0;
   out_1856202857491626372[177] = 0.0;
   out_1856202857491626372[178] = 0.0;
   out_1856202857491626372[179] = 0.0;
   out_1856202857491626372[180] = 0.0;
   out_1856202857491626372[181] = 0.0;
   out_1856202857491626372[182] = 0.0;
   out_1856202857491626372[183] = 0.0;
   out_1856202857491626372[184] = 0.0;
   out_1856202857491626372[185] = 0.0;
   out_1856202857491626372[186] = 0.0;
   out_1856202857491626372[187] = 0.0;
   out_1856202857491626372[188] = 0.0;
   out_1856202857491626372[189] = 0.0;
   out_1856202857491626372[190] = 1.0;
   out_1856202857491626372[191] = 0.0;
   out_1856202857491626372[192] = 0.0;
   out_1856202857491626372[193] = 0.0;
   out_1856202857491626372[194] = 0.0;
   out_1856202857491626372[195] = 0.0;
   out_1856202857491626372[196] = 0.0;
   out_1856202857491626372[197] = 0.0;
   out_1856202857491626372[198] = 0.0;
   out_1856202857491626372[199] = 0.0;
   out_1856202857491626372[200] = 0.0;
   out_1856202857491626372[201] = 0.0;
   out_1856202857491626372[202] = 0.0;
   out_1856202857491626372[203] = 0.0;
   out_1856202857491626372[204] = 0.0;
   out_1856202857491626372[205] = 0.0;
   out_1856202857491626372[206] = 0.0;
   out_1856202857491626372[207] = 0.0;
   out_1856202857491626372[208] = 0.0;
   out_1856202857491626372[209] = 1.0;
   out_1856202857491626372[210] = 0.0;
   out_1856202857491626372[211] = 0.0;
   out_1856202857491626372[212] = 0.0;
   out_1856202857491626372[213] = 0.0;
   out_1856202857491626372[214] = 0.0;
   out_1856202857491626372[215] = 0.0;
   out_1856202857491626372[216] = 0.0;
   out_1856202857491626372[217] = 0.0;
   out_1856202857491626372[218] = 0.0;
   out_1856202857491626372[219] = 0.0;
   out_1856202857491626372[220] = 0.0;
   out_1856202857491626372[221] = 0.0;
   out_1856202857491626372[222] = 0.0;
   out_1856202857491626372[223] = 0.0;
   out_1856202857491626372[224] = 0.0;
   out_1856202857491626372[225] = 0.0;
   out_1856202857491626372[226] = 0.0;
   out_1856202857491626372[227] = 0.0;
   out_1856202857491626372[228] = 1.0;
   out_1856202857491626372[229] = 0.0;
   out_1856202857491626372[230] = 0.0;
   out_1856202857491626372[231] = 0.0;
   out_1856202857491626372[232] = 0.0;
   out_1856202857491626372[233] = 0.0;
   out_1856202857491626372[234] = 0.0;
   out_1856202857491626372[235] = 0.0;
   out_1856202857491626372[236] = 0.0;
   out_1856202857491626372[237] = 0.0;
   out_1856202857491626372[238] = 0.0;
   out_1856202857491626372[239] = 0.0;
   out_1856202857491626372[240] = 0.0;
   out_1856202857491626372[241] = 0.0;
   out_1856202857491626372[242] = 0.0;
   out_1856202857491626372[243] = 0.0;
   out_1856202857491626372[244] = 0.0;
   out_1856202857491626372[245] = 0.0;
   out_1856202857491626372[246] = 0.0;
   out_1856202857491626372[247] = 1.0;
   out_1856202857491626372[248] = 0.0;
   out_1856202857491626372[249] = 0.0;
   out_1856202857491626372[250] = 0.0;
   out_1856202857491626372[251] = 0.0;
   out_1856202857491626372[252] = 0.0;
   out_1856202857491626372[253] = 0.0;
   out_1856202857491626372[254] = 0.0;
   out_1856202857491626372[255] = 0.0;
   out_1856202857491626372[256] = 0.0;
   out_1856202857491626372[257] = 0.0;
   out_1856202857491626372[258] = 0.0;
   out_1856202857491626372[259] = 0.0;
   out_1856202857491626372[260] = 0.0;
   out_1856202857491626372[261] = 0.0;
   out_1856202857491626372[262] = 0.0;
   out_1856202857491626372[263] = 0.0;
   out_1856202857491626372[264] = 0.0;
   out_1856202857491626372[265] = 0.0;
   out_1856202857491626372[266] = 1.0;
   out_1856202857491626372[267] = 0.0;
   out_1856202857491626372[268] = 0.0;
   out_1856202857491626372[269] = 0.0;
   out_1856202857491626372[270] = 0.0;
   out_1856202857491626372[271] = 0.0;
   out_1856202857491626372[272] = 0.0;
   out_1856202857491626372[273] = 0.0;
   out_1856202857491626372[274] = 0.0;
   out_1856202857491626372[275] = 0.0;
   out_1856202857491626372[276] = 0.0;
   out_1856202857491626372[277] = 0.0;
   out_1856202857491626372[278] = 0.0;
   out_1856202857491626372[279] = 0.0;
   out_1856202857491626372[280] = 0.0;
   out_1856202857491626372[281] = 0.0;
   out_1856202857491626372[282] = 0.0;
   out_1856202857491626372[283] = 0.0;
   out_1856202857491626372[284] = 0.0;
   out_1856202857491626372[285] = 1.0;
   out_1856202857491626372[286] = 0.0;
   out_1856202857491626372[287] = 0.0;
   out_1856202857491626372[288] = 0.0;
   out_1856202857491626372[289] = 0.0;
   out_1856202857491626372[290] = 0.0;
   out_1856202857491626372[291] = 0.0;
   out_1856202857491626372[292] = 0.0;
   out_1856202857491626372[293] = 0.0;
   out_1856202857491626372[294] = 0.0;
   out_1856202857491626372[295] = 0.0;
   out_1856202857491626372[296] = 0.0;
   out_1856202857491626372[297] = 0.0;
   out_1856202857491626372[298] = 0.0;
   out_1856202857491626372[299] = 0.0;
   out_1856202857491626372[300] = 0.0;
   out_1856202857491626372[301] = 0.0;
   out_1856202857491626372[302] = 0.0;
   out_1856202857491626372[303] = 0.0;
   out_1856202857491626372[304] = 1.0;
   out_1856202857491626372[305] = 0.0;
   out_1856202857491626372[306] = 0.0;
   out_1856202857491626372[307] = 0.0;
   out_1856202857491626372[308] = 0.0;
   out_1856202857491626372[309] = 0.0;
   out_1856202857491626372[310] = 0.0;
   out_1856202857491626372[311] = 0.0;
   out_1856202857491626372[312] = 0.0;
   out_1856202857491626372[313] = 0.0;
   out_1856202857491626372[314] = 0.0;
   out_1856202857491626372[315] = 0.0;
   out_1856202857491626372[316] = 0.0;
   out_1856202857491626372[317] = 0.0;
   out_1856202857491626372[318] = 0.0;
   out_1856202857491626372[319] = 0.0;
   out_1856202857491626372[320] = 0.0;
   out_1856202857491626372[321] = 0.0;
   out_1856202857491626372[322] = 0.0;
   out_1856202857491626372[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7190390231498499682) {
   out_7190390231498499682[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7190390231498499682[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7190390231498499682[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7190390231498499682[3] = dt*state[12] + state[3];
   out_7190390231498499682[4] = dt*state[13] + state[4];
   out_7190390231498499682[5] = dt*state[14] + state[5];
   out_7190390231498499682[6] = state[6];
   out_7190390231498499682[7] = state[7];
   out_7190390231498499682[8] = state[8];
   out_7190390231498499682[9] = state[9];
   out_7190390231498499682[10] = state[10];
   out_7190390231498499682[11] = state[11];
   out_7190390231498499682[12] = state[12];
   out_7190390231498499682[13] = state[13];
   out_7190390231498499682[14] = state[14];
   out_7190390231498499682[15] = state[15];
   out_7190390231498499682[16] = state[16];
   out_7190390231498499682[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4238346152453461367) {
   out_4238346152453461367[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4238346152453461367[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4238346152453461367[2] = 0;
   out_4238346152453461367[3] = 0;
   out_4238346152453461367[4] = 0;
   out_4238346152453461367[5] = 0;
   out_4238346152453461367[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4238346152453461367[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4238346152453461367[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4238346152453461367[9] = 0;
   out_4238346152453461367[10] = 0;
   out_4238346152453461367[11] = 0;
   out_4238346152453461367[12] = 0;
   out_4238346152453461367[13] = 0;
   out_4238346152453461367[14] = 0;
   out_4238346152453461367[15] = 0;
   out_4238346152453461367[16] = 0;
   out_4238346152453461367[17] = 0;
   out_4238346152453461367[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4238346152453461367[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4238346152453461367[20] = 0;
   out_4238346152453461367[21] = 0;
   out_4238346152453461367[22] = 0;
   out_4238346152453461367[23] = 0;
   out_4238346152453461367[24] = 0;
   out_4238346152453461367[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4238346152453461367[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4238346152453461367[27] = 0;
   out_4238346152453461367[28] = 0;
   out_4238346152453461367[29] = 0;
   out_4238346152453461367[30] = 0;
   out_4238346152453461367[31] = 0;
   out_4238346152453461367[32] = 0;
   out_4238346152453461367[33] = 0;
   out_4238346152453461367[34] = 0;
   out_4238346152453461367[35] = 0;
   out_4238346152453461367[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4238346152453461367[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4238346152453461367[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4238346152453461367[39] = 0;
   out_4238346152453461367[40] = 0;
   out_4238346152453461367[41] = 0;
   out_4238346152453461367[42] = 0;
   out_4238346152453461367[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4238346152453461367[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4238346152453461367[45] = 0;
   out_4238346152453461367[46] = 0;
   out_4238346152453461367[47] = 0;
   out_4238346152453461367[48] = 0;
   out_4238346152453461367[49] = 0;
   out_4238346152453461367[50] = 0;
   out_4238346152453461367[51] = 0;
   out_4238346152453461367[52] = 0;
   out_4238346152453461367[53] = 0;
   out_4238346152453461367[54] = 0;
   out_4238346152453461367[55] = 0;
   out_4238346152453461367[56] = 0;
   out_4238346152453461367[57] = 1;
   out_4238346152453461367[58] = 0;
   out_4238346152453461367[59] = 0;
   out_4238346152453461367[60] = 0;
   out_4238346152453461367[61] = 0;
   out_4238346152453461367[62] = 0;
   out_4238346152453461367[63] = 0;
   out_4238346152453461367[64] = 0;
   out_4238346152453461367[65] = 0;
   out_4238346152453461367[66] = dt;
   out_4238346152453461367[67] = 0;
   out_4238346152453461367[68] = 0;
   out_4238346152453461367[69] = 0;
   out_4238346152453461367[70] = 0;
   out_4238346152453461367[71] = 0;
   out_4238346152453461367[72] = 0;
   out_4238346152453461367[73] = 0;
   out_4238346152453461367[74] = 0;
   out_4238346152453461367[75] = 0;
   out_4238346152453461367[76] = 1;
   out_4238346152453461367[77] = 0;
   out_4238346152453461367[78] = 0;
   out_4238346152453461367[79] = 0;
   out_4238346152453461367[80] = 0;
   out_4238346152453461367[81] = 0;
   out_4238346152453461367[82] = 0;
   out_4238346152453461367[83] = 0;
   out_4238346152453461367[84] = 0;
   out_4238346152453461367[85] = dt;
   out_4238346152453461367[86] = 0;
   out_4238346152453461367[87] = 0;
   out_4238346152453461367[88] = 0;
   out_4238346152453461367[89] = 0;
   out_4238346152453461367[90] = 0;
   out_4238346152453461367[91] = 0;
   out_4238346152453461367[92] = 0;
   out_4238346152453461367[93] = 0;
   out_4238346152453461367[94] = 0;
   out_4238346152453461367[95] = 1;
   out_4238346152453461367[96] = 0;
   out_4238346152453461367[97] = 0;
   out_4238346152453461367[98] = 0;
   out_4238346152453461367[99] = 0;
   out_4238346152453461367[100] = 0;
   out_4238346152453461367[101] = 0;
   out_4238346152453461367[102] = 0;
   out_4238346152453461367[103] = 0;
   out_4238346152453461367[104] = dt;
   out_4238346152453461367[105] = 0;
   out_4238346152453461367[106] = 0;
   out_4238346152453461367[107] = 0;
   out_4238346152453461367[108] = 0;
   out_4238346152453461367[109] = 0;
   out_4238346152453461367[110] = 0;
   out_4238346152453461367[111] = 0;
   out_4238346152453461367[112] = 0;
   out_4238346152453461367[113] = 0;
   out_4238346152453461367[114] = 1;
   out_4238346152453461367[115] = 0;
   out_4238346152453461367[116] = 0;
   out_4238346152453461367[117] = 0;
   out_4238346152453461367[118] = 0;
   out_4238346152453461367[119] = 0;
   out_4238346152453461367[120] = 0;
   out_4238346152453461367[121] = 0;
   out_4238346152453461367[122] = 0;
   out_4238346152453461367[123] = 0;
   out_4238346152453461367[124] = 0;
   out_4238346152453461367[125] = 0;
   out_4238346152453461367[126] = 0;
   out_4238346152453461367[127] = 0;
   out_4238346152453461367[128] = 0;
   out_4238346152453461367[129] = 0;
   out_4238346152453461367[130] = 0;
   out_4238346152453461367[131] = 0;
   out_4238346152453461367[132] = 0;
   out_4238346152453461367[133] = 1;
   out_4238346152453461367[134] = 0;
   out_4238346152453461367[135] = 0;
   out_4238346152453461367[136] = 0;
   out_4238346152453461367[137] = 0;
   out_4238346152453461367[138] = 0;
   out_4238346152453461367[139] = 0;
   out_4238346152453461367[140] = 0;
   out_4238346152453461367[141] = 0;
   out_4238346152453461367[142] = 0;
   out_4238346152453461367[143] = 0;
   out_4238346152453461367[144] = 0;
   out_4238346152453461367[145] = 0;
   out_4238346152453461367[146] = 0;
   out_4238346152453461367[147] = 0;
   out_4238346152453461367[148] = 0;
   out_4238346152453461367[149] = 0;
   out_4238346152453461367[150] = 0;
   out_4238346152453461367[151] = 0;
   out_4238346152453461367[152] = 1;
   out_4238346152453461367[153] = 0;
   out_4238346152453461367[154] = 0;
   out_4238346152453461367[155] = 0;
   out_4238346152453461367[156] = 0;
   out_4238346152453461367[157] = 0;
   out_4238346152453461367[158] = 0;
   out_4238346152453461367[159] = 0;
   out_4238346152453461367[160] = 0;
   out_4238346152453461367[161] = 0;
   out_4238346152453461367[162] = 0;
   out_4238346152453461367[163] = 0;
   out_4238346152453461367[164] = 0;
   out_4238346152453461367[165] = 0;
   out_4238346152453461367[166] = 0;
   out_4238346152453461367[167] = 0;
   out_4238346152453461367[168] = 0;
   out_4238346152453461367[169] = 0;
   out_4238346152453461367[170] = 0;
   out_4238346152453461367[171] = 1;
   out_4238346152453461367[172] = 0;
   out_4238346152453461367[173] = 0;
   out_4238346152453461367[174] = 0;
   out_4238346152453461367[175] = 0;
   out_4238346152453461367[176] = 0;
   out_4238346152453461367[177] = 0;
   out_4238346152453461367[178] = 0;
   out_4238346152453461367[179] = 0;
   out_4238346152453461367[180] = 0;
   out_4238346152453461367[181] = 0;
   out_4238346152453461367[182] = 0;
   out_4238346152453461367[183] = 0;
   out_4238346152453461367[184] = 0;
   out_4238346152453461367[185] = 0;
   out_4238346152453461367[186] = 0;
   out_4238346152453461367[187] = 0;
   out_4238346152453461367[188] = 0;
   out_4238346152453461367[189] = 0;
   out_4238346152453461367[190] = 1;
   out_4238346152453461367[191] = 0;
   out_4238346152453461367[192] = 0;
   out_4238346152453461367[193] = 0;
   out_4238346152453461367[194] = 0;
   out_4238346152453461367[195] = 0;
   out_4238346152453461367[196] = 0;
   out_4238346152453461367[197] = 0;
   out_4238346152453461367[198] = 0;
   out_4238346152453461367[199] = 0;
   out_4238346152453461367[200] = 0;
   out_4238346152453461367[201] = 0;
   out_4238346152453461367[202] = 0;
   out_4238346152453461367[203] = 0;
   out_4238346152453461367[204] = 0;
   out_4238346152453461367[205] = 0;
   out_4238346152453461367[206] = 0;
   out_4238346152453461367[207] = 0;
   out_4238346152453461367[208] = 0;
   out_4238346152453461367[209] = 1;
   out_4238346152453461367[210] = 0;
   out_4238346152453461367[211] = 0;
   out_4238346152453461367[212] = 0;
   out_4238346152453461367[213] = 0;
   out_4238346152453461367[214] = 0;
   out_4238346152453461367[215] = 0;
   out_4238346152453461367[216] = 0;
   out_4238346152453461367[217] = 0;
   out_4238346152453461367[218] = 0;
   out_4238346152453461367[219] = 0;
   out_4238346152453461367[220] = 0;
   out_4238346152453461367[221] = 0;
   out_4238346152453461367[222] = 0;
   out_4238346152453461367[223] = 0;
   out_4238346152453461367[224] = 0;
   out_4238346152453461367[225] = 0;
   out_4238346152453461367[226] = 0;
   out_4238346152453461367[227] = 0;
   out_4238346152453461367[228] = 1;
   out_4238346152453461367[229] = 0;
   out_4238346152453461367[230] = 0;
   out_4238346152453461367[231] = 0;
   out_4238346152453461367[232] = 0;
   out_4238346152453461367[233] = 0;
   out_4238346152453461367[234] = 0;
   out_4238346152453461367[235] = 0;
   out_4238346152453461367[236] = 0;
   out_4238346152453461367[237] = 0;
   out_4238346152453461367[238] = 0;
   out_4238346152453461367[239] = 0;
   out_4238346152453461367[240] = 0;
   out_4238346152453461367[241] = 0;
   out_4238346152453461367[242] = 0;
   out_4238346152453461367[243] = 0;
   out_4238346152453461367[244] = 0;
   out_4238346152453461367[245] = 0;
   out_4238346152453461367[246] = 0;
   out_4238346152453461367[247] = 1;
   out_4238346152453461367[248] = 0;
   out_4238346152453461367[249] = 0;
   out_4238346152453461367[250] = 0;
   out_4238346152453461367[251] = 0;
   out_4238346152453461367[252] = 0;
   out_4238346152453461367[253] = 0;
   out_4238346152453461367[254] = 0;
   out_4238346152453461367[255] = 0;
   out_4238346152453461367[256] = 0;
   out_4238346152453461367[257] = 0;
   out_4238346152453461367[258] = 0;
   out_4238346152453461367[259] = 0;
   out_4238346152453461367[260] = 0;
   out_4238346152453461367[261] = 0;
   out_4238346152453461367[262] = 0;
   out_4238346152453461367[263] = 0;
   out_4238346152453461367[264] = 0;
   out_4238346152453461367[265] = 0;
   out_4238346152453461367[266] = 1;
   out_4238346152453461367[267] = 0;
   out_4238346152453461367[268] = 0;
   out_4238346152453461367[269] = 0;
   out_4238346152453461367[270] = 0;
   out_4238346152453461367[271] = 0;
   out_4238346152453461367[272] = 0;
   out_4238346152453461367[273] = 0;
   out_4238346152453461367[274] = 0;
   out_4238346152453461367[275] = 0;
   out_4238346152453461367[276] = 0;
   out_4238346152453461367[277] = 0;
   out_4238346152453461367[278] = 0;
   out_4238346152453461367[279] = 0;
   out_4238346152453461367[280] = 0;
   out_4238346152453461367[281] = 0;
   out_4238346152453461367[282] = 0;
   out_4238346152453461367[283] = 0;
   out_4238346152453461367[284] = 0;
   out_4238346152453461367[285] = 1;
   out_4238346152453461367[286] = 0;
   out_4238346152453461367[287] = 0;
   out_4238346152453461367[288] = 0;
   out_4238346152453461367[289] = 0;
   out_4238346152453461367[290] = 0;
   out_4238346152453461367[291] = 0;
   out_4238346152453461367[292] = 0;
   out_4238346152453461367[293] = 0;
   out_4238346152453461367[294] = 0;
   out_4238346152453461367[295] = 0;
   out_4238346152453461367[296] = 0;
   out_4238346152453461367[297] = 0;
   out_4238346152453461367[298] = 0;
   out_4238346152453461367[299] = 0;
   out_4238346152453461367[300] = 0;
   out_4238346152453461367[301] = 0;
   out_4238346152453461367[302] = 0;
   out_4238346152453461367[303] = 0;
   out_4238346152453461367[304] = 1;
   out_4238346152453461367[305] = 0;
   out_4238346152453461367[306] = 0;
   out_4238346152453461367[307] = 0;
   out_4238346152453461367[308] = 0;
   out_4238346152453461367[309] = 0;
   out_4238346152453461367[310] = 0;
   out_4238346152453461367[311] = 0;
   out_4238346152453461367[312] = 0;
   out_4238346152453461367[313] = 0;
   out_4238346152453461367[314] = 0;
   out_4238346152453461367[315] = 0;
   out_4238346152453461367[316] = 0;
   out_4238346152453461367[317] = 0;
   out_4238346152453461367[318] = 0;
   out_4238346152453461367[319] = 0;
   out_4238346152453461367[320] = 0;
   out_4238346152453461367[321] = 0;
   out_4238346152453461367[322] = 0;
   out_4238346152453461367[323] = 1;
}
void h_4(double *state, double *unused, double *out_7341523241853351564) {
   out_7341523241853351564[0] = state[6] + state[9];
   out_7341523241853351564[1] = state[7] + state[10];
   out_7341523241853351564[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3675901583397923233) {
   out_3675901583397923233[0] = 0;
   out_3675901583397923233[1] = 0;
   out_3675901583397923233[2] = 0;
   out_3675901583397923233[3] = 0;
   out_3675901583397923233[4] = 0;
   out_3675901583397923233[5] = 0;
   out_3675901583397923233[6] = 1;
   out_3675901583397923233[7] = 0;
   out_3675901583397923233[8] = 0;
   out_3675901583397923233[9] = 1;
   out_3675901583397923233[10] = 0;
   out_3675901583397923233[11] = 0;
   out_3675901583397923233[12] = 0;
   out_3675901583397923233[13] = 0;
   out_3675901583397923233[14] = 0;
   out_3675901583397923233[15] = 0;
   out_3675901583397923233[16] = 0;
   out_3675901583397923233[17] = 0;
   out_3675901583397923233[18] = 0;
   out_3675901583397923233[19] = 0;
   out_3675901583397923233[20] = 0;
   out_3675901583397923233[21] = 0;
   out_3675901583397923233[22] = 0;
   out_3675901583397923233[23] = 0;
   out_3675901583397923233[24] = 0;
   out_3675901583397923233[25] = 1;
   out_3675901583397923233[26] = 0;
   out_3675901583397923233[27] = 0;
   out_3675901583397923233[28] = 1;
   out_3675901583397923233[29] = 0;
   out_3675901583397923233[30] = 0;
   out_3675901583397923233[31] = 0;
   out_3675901583397923233[32] = 0;
   out_3675901583397923233[33] = 0;
   out_3675901583397923233[34] = 0;
   out_3675901583397923233[35] = 0;
   out_3675901583397923233[36] = 0;
   out_3675901583397923233[37] = 0;
   out_3675901583397923233[38] = 0;
   out_3675901583397923233[39] = 0;
   out_3675901583397923233[40] = 0;
   out_3675901583397923233[41] = 0;
   out_3675901583397923233[42] = 0;
   out_3675901583397923233[43] = 0;
   out_3675901583397923233[44] = 1;
   out_3675901583397923233[45] = 0;
   out_3675901583397923233[46] = 0;
   out_3675901583397923233[47] = 1;
   out_3675901583397923233[48] = 0;
   out_3675901583397923233[49] = 0;
   out_3675901583397923233[50] = 0;
   out_3675901583397923233[51] = 0;
   out_3675901583397923233[52] = 0;
   out_3675901583397923233[53] = 0;
}
void h_10(double *state, double *unused, double *out_7979280784138322600) {
   out_7979280784138322600[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7979280784138322600[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7979280784138322600[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2717029967524110913) {
   out_2717029967524110913[0] = 0;
   out_2717029967524110913[1] = 9.8100000000000005*cos(state[1]);
   out_2717029967524110913[2] = 0;
   out_2717029967524110913[3] = 0;
   out_2717029967524110913[4] = -state[8];
   out_2717029967524110913[5] = state[7];
   out_2717029967524110913[6] = 0;
   out_2717029967524110913[7] = state[5];
   out_2717029967524110913[8] = -state[4];
   out_2717029967524110913[9] = 0;
   out_2717029967524110913[10] = 0;
   out_2717029967524110913[11] = 0;
   out_2717029967524110913[12] = 1;
   out_2717029967524110913[13] = 0;
   out_2717029967524110913[14] = 0;
   out_2717029967524110913[15] = 1;
   out_2717029967524110913[16] = 0;
   out_2717029967524110913[17] = 0;
   out_2717029967524110913[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2717029967524110913[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2717029967524110913[20] = 0;
   out_2717029967524110913[21] = state[8];
   out_2717029967524110913[22] = 0;
   out_2717029967524110913[23] = -state[6];
   out_2717029967524110913[24] = -state[5];
   out_2717029967524110913[25] = 0;
   out_2717029967524110913[26] = state[3];
   out_2717029967524110913[27] = 0;
   out_2717029967524110913[28] = 0;
   out_2717029967524110913[29] = 0;
   out_2717029967524110913[30] = 0;
   out_2717029967524110913[31] = 1;
   out_2717029967524110913[32] = 0;
   out_2717029967524110913[33] = 0;
   out_2717029967524110913[34] = 1;
   out_2717029967524110913[35] = 0;
   out_2717029967524110913[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2717029967524110913[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2717029967524110913[38] = 0;
   out_2717029967524110913[39] = -state[7];
   out_2717029967524110913[40] = state[6];
   out_2717029967524110913[41] = 0;
   out_2717029967524110913[42] = state[4];
   out_2717029967524110913[43] = -state[3];
   out_2717029967524110913[44] = 0;
   out_2717029967524110913[45] = 0;
   out_2717029967524110913[46] = 0;
   out_2717029967524110913[47] = 0;
   out_2717029967524110913[48] = 0;
   out_2717029967524110913[49] = 0;
   out_2717029967524110913[50] = 1;
   out_2717029967524110913[51] = 0;
   out_2717029967524110913[52] = 0;
   out_2717029967524110913[53] = 1;
}
void h_13(double *state, double *unused, double *out_2249980252911390508) {
   out_2249980252911390508[0] = state[3];
   out_2249980252911390508[1] = state[4];
   out_2249980252911390508[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3934729624918777696) {
   out_3934729624918777696[0] = 0;
   out_3934729624918777696[1] = 0;
   out_3934729624918777696[2] = 0;
   out_3934729624918777696[3] = 1;
   out_3934729624918777696[4] = 0;
   out_3934729624918777696[5] = 0;
   out_3934729624918777696[6] = 0;
   out_3934729624918777696[7] = 0;
   out_3934729624918777696[8] = 0;
   out_3934729624918777696[9] = 0;
   out_3934729624918777696[10] = 0;
   out_3934729624918777696[11] = 0;
   out_3934729624918777696[12] = 0;
   out_3934729624918777696[13] = 0;
   out_3934729624918777696[14] = 0;
   out_3934729624918777696[15] = 0;
   out_3934729624918777696[16] = 0;
   out_3934729624918777696[17] = 0;
   out_3934729624918777696[18] = 0;
   out_3934729624918777696[19] = 0;
   out_3934729624918777696[20] = 0;
   out_3934729624918777696[21] = 0;
   out_3934729624918777696[22] = 1;
   out_3934729624918777696[23] = 0;
   out_3934729624918777696[24] = 0;
   out_3934729624918777696[25] = 0;
   out_3934729624918777696[26] = 0;
   out_3934729624918777696[27] = 0;
   out_3934729624918777696[28] = 0;
   out_3934729624918777696[29] = 0;
   out_3934729624918777696[30] = 0;
   out_3934729624918777696[31] = 0;
   out_3934729624918777696[32] = 0;
   out_3934729624918777696[33] = 0;
   out_3934729624918777696[34] = 0;
   out_3934729624918777696[35] = 0;
   out_3934729624918777696[36] = 0;
   out_3934729624918777696[37] = 0;
   out_3934729624918777696[38] = 0;
   out_3934729624918777696[39] = 0;
   out_3934729624918777696[40] = 0;
   out_3934729624918777696[41] = 1;
   out_3934729624918777696[42] = 0;
   out_3934729624918777696[43] = 0;
   out_3934729624918777696[44] = 0;
   out_3934729624918777696[45] = 0;
   out_3934729624918777696[46] = 0;
   out_3934729624918777696[47] = 0;
   out_3934729624918777696[48] = 0;
   out_3934729624918777696[49] = 0;
   out_3934729624918777696[50] = 0;
   out_3934729624918777696[51] = 0;
   out_3934729624918777696[52] = 0;
   out_3934729624918777696[53] = 0;
}
void h_14(double *state, double *unused, double *out_6063115878095578816) {
   out_6063115878095578816[0] = state[6];
   out_6063115878095578816[1] = state[7];
   out_6063115878095578816[2] = state[8];
}
void H_14(double *state, double *unused, double *out_287339272941561296) {
   out_287339272941561296[0] = 0;
   out_287339272941561296[1] = 0;
   out_287339272941561296[2] = 0;
   out_287339272941561296[3] = 0;
   out_287339272941561296[4] = 0;
   out_287339272941561296[5] = 0;
   out_287339272941561296[6] = 1;
   out_287339272941561296[7] = 0;
   out_287339272941561296[8] = 0;
   out_287339272941561296[9] = 0;
   out_287339272941561296[10] = 0;
   out_287339272941561296[11] = 0;
   out_287339272941561296[12] = 0;
   out_287339272941561296[13] = 0;
   out_287339272941561296[14] = 0;
   out_287339272941561296[15] = 0;
   out_287339272941561296[16] = 0;
   out_287339272941561296[17] = 0;
   out_287339272941561296[18] = 0;
   out_287339272941561296[19] = 0;
   out_287339272941561296[20] = 0;
   out_287339272941561296[21] = 0;
   out_287339272941561296[22] = 0;
   out_287339272941561296[23] = 0;
   out_287339272941561296[24] = 0;
   out_287339272941561296[25] = 1;
   out_287339272941561296[26] = 0;
   out_287339272941561296[27] = 0;
   out_287339272941561296[28] = 0;
   out_287339272941561296[29] = 0;
   out_287339272941561296[30] = 0;
   out_287339272941561296[31] = 0;
   out_287339272941561296[32] = 0;
   out_287339272941561296[33] = 0;
   out_287339272941561296[34] = 0;
   out_287339272941561296[35] = 0;
   out_287339272941561296[36] = 0;
   out_287339272941561296[37] = 0;
   out_287339272941561296[38] = 0;
   out_287339272941561296[39] = 0;
   out_287339272941561296[40] = 0;
   out_287339272941561296[41] = 0;
   out_287339272941561296[42] = 0;
   out_287339272941561296[43] = 0;
   out_287339272941561296[44] = 1;
   out_287339272941561296[45] = 0;
   out_287339272941561296[46] = 0;
   out_287339272941561296[47] = 0;
   out_287339272941561296[48] = 0;
   out_287339272941561296[49] = 0;
   out_287339272941561296[50] = 0;
   out_287339272941561296[51] = 0;
   out_287339272941561296[52] = 0;
   out_287339272941561296[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_788519772333288428) {
  err_fun(nom_x, delta_x, out_788519772333288428);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3476371721226452847) {
  inv_err_fun(nom_x, true_x, out_3476371721226452847);
}
void pose_H_mod_fun(double *state, double *out_1856202857491626372) {
  H_mod_fun(state, out_1856202857491626372);
}
void pose_f_fun(double *state, double dt, double *out_7190390231498499682) {
  f_fun(state,  dt, out_7190390231498499682);
}
void pose_F_fun(double *state, double dt, double *out_4238346152453461367) {
  F_fun(state,  dt, out_4238346152453461367);
}
void pose_h_4(double *state, double *unused, double *out_7341523241853351564) {
  h_4(state, unused, out_7341523241853351564);
}
void pose_H_4(double *state, double *unused, double *out_3675901583397923233) {
  H_4(state, unused, out_3675901583397923233);
}
void pose_h_10(double *state, double *unused, double *out_7979280784138322600) {
  h_10(state, unused, out_7979280784138322600);
}
void pose_H_10(double *state, double *unused, double *out_2717029967524110913) {
  H_10(state, unused, out_2717029967524110913);
}
void pose_h_13(double *state, double *unused, double *out_2249980252911390508) {
  h_13(state, unused, out_2249980252911390508);
}
void pose_H_13(double *state, double *unused, double *out_3934729624918777696) {
  H_13(state, unused, out_3934729624918777696);
}
void pose_h_14(double *state, double *unused, double *out_6063115878095578816) {
  h_14(state, unused, out_6063115878095578816);
}
void pose_H_14(double *state, double *unused, double *out_287339272941561296) {
  H_14(state, unused, out_287339272941561296);
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
