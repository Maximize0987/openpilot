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
void err_fun(double *nom_x, double *delta_x, double *out_845527351868247428) {
   out_845527351868247428[0] = delta_x[0] + nom_x[0];
   out_845527351868247428[1] = delta_x[1] + nom_x[1];
   out_845527351868247428[2] = delta_x[2] + nom_x[2];
   out_845527351868247428[3] = delta_x[3] + nom_x[3];
   out_845527351868247428[4] = delta_x[4] + nom_x[4];
   out_845527351868247428[5] = delta_x[5] + nom_x[5];
   out_845527351868247428[6] = delta_x[6] + nom_x[6];
   out_845527351868247428[7] = delta_x[7] + nom_x[7];
   out_845527351868247428[8] = delta_x[8] + nom_x[8];
   out_845527351868247428[9] = delta_x[9] + nom_x[9];
   out_845527351868247428[10] = delta_x[10] + nom_x[10];
   out_845527351868247428[11] = delta_x[11] + nom_x[11];
   out_845527351868247428[12] = delta_x[12] + nom_x[12];
   out_845527351868247428[13] = delta_x[13] + nom_x[13];
   out_845527351868247428[14] = delta_x[14] + nom_x[14];
   out_845527351868247428[15] = delta_x[15] + nom_x[15];
   out_845527351868247428[16] = delta_x[16] + nom_x[16];
   out_845527351868247428[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6367069276716114158) {
   out_6367069276716114158[0] = -nom_x[0] + true_x[0];
   out_6367069276716114158[1] = -nom_x[1] + true_x[1];
   out_6367069276716114158[2] = -nom_x[2] + true_x[2];
   out_6367069276716114158[3] = -nom_x[3] + true_x[3];
   out_6367069276716114158[4] = -nom_x[4] + true_x[4];
   out_6367069276716114158[5] = -nom_x[5] + true_x[5];
   out_6367069276716114158[6] = -nom_x[6] + true_x[6];
   out_6367069276716114158[7] = -nom_x[7] + true_x[7];
   out_6367069276716114158[8] = -nom_x[8] + true_x[8];
   out_6367069276716114158[9] = -nom_x[9] + true_x[9];
   out_6367069276716114158[10] = -nom_x[10] + true_x[10];
   out_6367069276716114158[11] = -nom_x[11] + true_x[11];
   out_6367069276716114158[12] = -nom_x[12] + true_x[12];
   out_6367069276716114158[13] = -nom_x[13] + true_x[13];
   out_6367069276716114158[14] = -nom_x[14] + true_x[14];
   out_6367069276716114158[15] = -nom_x[15] + true_x[15];
   out_6367069276716114158[16] = -nom_x[16] + true_x[16];
   out_6367069276716114158[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7305256634145735915) {
   out_7305256634145735915[0] = 1.0;
   out_7305256634145735915[1] = 0.0;
   out_7305256634145735915[2] = 0.0;
   out_7305256634145735915[3] = 0.0;
   out_7305256634145735915[4] = 0.0;
   out_7305256634145735915[5] = 0.0;
   out_7305256634145735915[6] = 0.0;
   out_7305256634145735915[7] = 0.0;
   out_7305256634145735915[8] = 0.0;
   out_7305256634145735915[9] = 0.0;
   out_7305256634145735915[10] = 0.0;
   out_7305256634145735915[11] = 0.0;
   out_7305256634145735915[12] = 0.0;
   out_7305256634145735915[13] = 0.0;
   out_7305256634145735915[14] = 0.0;
   out_7305256634145735915[15] = 0.0;
   out_7305256634145735915[16] = 0.0;
   out_7305256634145735915[17] = 0.0;
   out_7305256634145735915[18] = 0.0;
   out_7305256634145735915[19] = 1.0;
   out_7305256634145735915[20] = 0.0;
   out_7305256634145735915[21] = 0.0;
   out_7305256634145735915[22] = 0.0;
   out_7305256634145735915[23] = 0.0;
   out_7305256634145735915[24] = 0.0;
   out_7305256634145735915[25] = 0.0;
   out_7305256634145735915[26] = 0.0;
   out_7305256634145735915[27] = 0.0;
   out_7305256634145735915[28] = 0.0;
   out_7305256634145735915[29] = 0.0;
   out_7305256634145735915[30] = 0.0;
   out_7305256634145735915[31] = 0.0;
   out_7305256634145735915[32] = 0.0;
   out_7305256634145735915[33] = 0.0;
   out_7305256634145735915[34] = 0.0;
   out_7305256634145735915[35] = 0.0;
   out_7305256634145735915[36] = 0.0;
   out_7305256634145735915[37] = 0.0;
   out_7305256634145735915[38] = 1.0;
   out_7305256634145735915[39] = 0.0;
   out_7305256634145735915[40] = 0.0;
   out_7305256634145735915[41] = 0.0;
   out_7305256634145735915[42] = 0.0;
   out_7305256634145735915[43] = 0.0;
   out_7305256634145735915[44] = 0.0;
   out_7305256634145735915[45] = 0.0;
   out_7305256634145735915[46] = 0.0;
   out_7305256634145735915[47] = 0.0;
   out_7305256634145735915[48] = 0.0;
   out_7305256634145735915[49] = 0.0;
   out_7305256634145735915[50] = 0.0;
   out_7305256634145735915[51] = 0.0;
   out_7305256634145735915[52] = 0.0;
   out_7305256634145735915[53] = 0.0;
   out_7305256634145735915[54] = 0.0;
   out_7305256634145735915[55] = 0.0;
   out_7305256634145735915[56] = 0.0;
   out_7305256634145735915[57] = 1.0;
   out_7305256634145735915[58] = 0.0;
   out_7305256634145735915[59] = 0.0;
   out_7305256634145735915[60] = 0.0;
   out_7305256634145735915[61] = 0.0;
   out_7305256634145735915[62] = 0.0;
   out_7305256634145735915[63] = 0.0;
   out_7305256634145735915[64] = 0.0;
   out_7305256634145735915[65] = 0.0;
   out_7305256634145735915[66] = 0.0;
   out_7305256634145735915[67] = 0.0;
   out_7305256634145735915[68] = 0.0;
   out_7305256634145735915[69] = 0.0;
   out_7305256634145735915[70] = 0.0;
   out_7305256634145735915[71] = 0.0;
   out_7305256634145735915[72] = 0.0;
   out_7305256634145735915[73] = 0.0;
   out_7305256634145735915[74] = 0.0;
   out_7305256634145735915[75] = 0.0;
   out_7305256634145735915[76] = 1.0;
   out_7305256634145735915[77] = 0.0;
   out_7305256634145735915[78] = 0.0;
   out_7305256634145735915[79] = 0.0;
   out_7305256634145735915[80] = 0.0;
   out_7305256634145735915[81] = 0.0;
   out_7305256634145735915[82] = 0.0;
   out_7305256634145735915[83] = 0.0;
   out_7305256634145735915[84] = 0.0;
   out_7305256634145735915[85] = 0.0;
   out_7305256634145735915[86] = 0.0;
   out_7305256634145735915[87] = 0.0;
   out_7305256634145735915[88] = 0.0;
   out_7305256634145735915[89] = 0.0;
   out_7305256634145735915[90] = 0.0;
   out_7305256634145735915[91] = 0.0;
   out_7305256634145735915[92] = 0.0;
   out_7305256634145735915[93] = 0.0;
   out_7305256634145735915[94] = 0.0;
   out_7305256634145735915[95] = 1.0;
   out_7305256634145735915[96] = 0.0;
   out_7305256634145735915[97] = 0.0;
   out_7305256634145735915[98] = 0.0;
   out_7305256634145735915[99] = 0.0;
   out_7305256634145735915[100] = 0.0;
   out_7305256634145735915[101] = 0.0;
   out_7305256634145735915[102] = 0.0;
   out_7305256634145735915[103] = 0.0;
   out_7305256634145735915[104] = 0.0;
   out_7305256634145735915[105] = 0.0;
   out_7305256634145735915[106] = 0.0;
   out_7305256634145735915[107] = 0.0;
   out_7305256634145735915[108] = 0.0;
   out_7305256634145735915[109] = 0.0;
   out_7305256634145735915[110] = 0.0;
   out_7305256634145735915[111] = 0.0;
   out_7305256634145735915[112] = 0.0;
   out_7305256634145735915[113] = 0.0;
   out_7305256634145735915[114] = 1.0;
   out_7305256634145735915[115] = 0.0;
   out_7305256634145735915[116] = 0.0;
   out_7305256634145735915[117] = 0.0;
   out_7305256634145735915[118] = 0.0;
   out_7305256634145735915[119] = 0.0;
   out_7305256634145735915[120] = 0.0;
   out_7305256634145735915[121] = 0.0;
   out_7305256634145735915[122] = 0.0;
   out_7305256634145735915[123] = 0.0;
   out_7305256634145735915[124] = 0.0;
   out_7305256634145735915[125] = 0.0;
   out_7305256634145735915[126] = 0.0;
   out_7305256634145735915[127] = 0.0;
   out_7305256634145735915[128] = 0.0;
   out_7305256634145735915[129] = 0.0;
   out_7305256634145735915[130] = 0.0;
   out_7305256634145735915[131] = 0.0;
   out_7305256634145735915[132] = 0.0;
   out_7305256634145735915[133] = 1.0;
   out_7305256634145735915[134] = 0.0;
   out_7305256634145735915[135] = 0.0;
   out_7305256634145735915[136] = 0.0;
   out_7305256634145735915[137] = 0.0;
   out_7305256634145735915[138] = 0.0;
   out_7305256634145735915[139] = 0.0;
   out_7305256634145735915[140] = 0.0;
   out_7305256634145735915[141] = 0.0;
   out_7305256634145735915[142] = 0.0;
   out_7305256634145735915[143] = 0.0;
   out_7305256634145735915[144] = 0.0;
   out_7305256634145735915[145] = 0.0;
   out_7305256634145735915[146] = 0.0;
   out_7305256634145735915[147] = 0.0;
   out_7305256634145735915[148] = 0.0;
   out_7305256634145735915[149] = 0.0;
   out_7305256634145735915[150] = 0.0;
   out_7305256634145735915[151] = 0.0;
   out_7305256634145735915[152] = 1.0;
   out_7305256634145735915[153] = 0.0;
   out_7305256634145735915[154] = 0.0;
   out_7305256634145735915[155] = 0.0;
   out_7305256634145735915[156] = 0.0;
   out_7305256634145735915[157] = 0.0;
   out_7305256634145735915[158] = 0.0;
   out_7305256634145735915[159] = 0.0;
   out_7305256634145735915[160] = 0.0;
   out_7305256634145735915[161] = 0.0;
   out_7305256634145735915[162] = 0.0;
   out_7305256634145735915[163] = 0.0;
   out_7305256634145735915[164] = 0.0;
   out_7305256634145735915[165] = 0.0;
   out_7305256634145735915[166] = 0.0;
   out_7305256634145735915[167] = 0.0;
   out_7305256634145735915[168] = 0.0;
   out_7305256634145735915[169] = 0.0;
   out_7305256634145735915[170] = 0.0;
   out_7305256634145735915[171] = 1.0;
   out_7305256634145735915[172] = 0.0;
   out_7305256634145735915[173] = 0.0;
   out_7305256634145735915[174] = 0.0;
   out_7305256634145735915[175] = 0.0;
   out_7305256634145735915[176] = 0.0;
   out_7305256634145735915[177] = 0.0;
   out_7305256634145735915[178] = 0.0;
   out_7305256634145735915[179] = 0.0;
   out_7305256634145735915[180] = 0.0;
   out_7305256634145735915[181] = 0.0;
   out_7305256634145735915[182] = 0.0;
   out_7305256634145735915[183] = 0.0;
   out_7305256634145735915[184] = 0.0;
   out_7305256634145735915[185] = 0.0;
   out_7305256634145735915[186] = 0.0;
   out_7305256634145735915[187] = 0.0;
   out_7305256634145735915[188] = 0.0;
   out_7305256634145735915[189] = 0.0;
   out_7305256634145735915[190] = 1.0;
   out_7305256634145735915[191] = 0.0;
   out_7305256634145735915[192] = 0.0;
   out_7305256634145735915[193] = 0.0;
   out_7305256634145735915[194] = 0.0;
   out_7305256634145735915[195] = 0.0;
   out_7305256634145735915[196] = 0.0;
   out_7305256634145735915[197] = 0.0;
   out_7305256634145735915[198] = 0.0;
   out_7305256634145735915[199] = 0.0;
   out_7305256634145735915[200] = 0.0;
   out_7305256634145735915[201] = 0.0;
   out_7305256634145735915[202] = 0.0;
   out_7305256634145735915[203] = 0.0;
   out_7305256634145735915[204] = 0.0;
   out_7305256634145735915[205] = 0.0;
   out_7305256634145735915[206] = 0.0;
   out_7305256634145735915[207] = 0.0;
   out_7305256634145735915[208] = 0.0;
   out_7305256634145735915[209] = 1.0;
   out_7305256634145735915[210] = 0.0;
   out_7305256634145735915[211] = 0.0;
   out_7305256634145735915[212] = 0.0;
   out_7305256634145735915[213] = 0.0;
   out_7305256634145735915[214] = 0.0;
   out_7305256634145735915[215] = 0.0;
   out_7305256634145735915[216] = 0.0;
   out_7305256634145735915[217] = 0.0;
   out_7305256634145735915[218] = 0.0;
   out_7305256634145735915[219] = 0.0;
   out_7305256634145735915[220] = 0.0;
   out_7305256634145735915[221] = 0.0;
   out_7305256634145735915[222] = 0.0;
   out_7305256634145735915[223] = 0.0;
   out_7305256634145735915[224] = 0.0;
   out_7305256634145735915[225] = 0.0;
   out_7305256634145735915[226] = 0.0;
   out_7305256634145735915[227] = 0.0;
   out_7305256634145735915[228] = 1.0;
   out_7305256634145735915[229] = 0.0;
   out_7305256634145735915[230] = 0.0;
   out_7305256634145735915[231] = 0.0;
   out_7305256634145735915[232] = 0.0;
   out_7305256634145735915[233] = 0.0;
   out_7305256634145735915[234] = 0.0;
   out_7305256634145735915[235] = 0.0;
   out_7305256634145735915[236] = 0.0;
   out_7305256634145735915[237] = 0.0;
   out_7305256634145735915[238] = 0.0;
   out_7305256634145735915[239] = 0.0;
   out_7305256634145735915[240] = 0.0;
   out_7305256634145735915[241] = 0.0;
   out_7305256634145735915[242] = 0.0;
   out_7305256634145735915[243] = 0.0;
   out_7305256634145735915[244] = 0.0;
   out_7305256634145735915[245] = 0.0;
   out_7305256634145735915[246] = 0.0;
   out_7305256634145735915[247] = 1.0;
   out_7305256634145735915[248] = 0.0;
   out_7305256634145735915[249] = 0.0;
   out_7305256634145735915[250] = 0.0;
   out_7305256634145735915[251] = 0.0;
   out_7305256634145735915[252] = 0.0;
   out_7305256634145735915[253] = 0.0;
   out_7305256634145735915[254] = 0.0;
   out_7305256634145735915[255] = 0.0;
   out_7305256634145735915[256] = 0.0;
   out_7305256634145735915[257] = 0.0;
   out_7305256634145735915[258] = 0.0;
   out_7305256634145735915[259] = 0.0;
   out_7305256634145735915[260] = 0.0;
   out_7305256634145735915[261] = 0.0;
   out_7305256634145735915[262] = 0.0;
   out_7305256634145735915[263] = 0.0;
   out_7305256634145735915[264] = 0.0;
   out_7305256634145735915[265] = 0.0;
   out_7305256634145735915[266] = 1.0;
   out_7305256634145735915[267] = 0.0;
   out_7305256634145735915[268] = 0.0;
   out_7305256634145735915[269] = 0.0;
   out_7305256634145735915[270] = 0.0;
   out_7305256634145735915[271] = 0.0;
   out_7305256634145735915[272] = 0.0;
   out_7305256634145735915[273] = 0.0;
   out_7305256634145735915[274] = 0.0;
   out_7305256634145735915[275] = 0.0;
   out_7305256634145735915[276] = 0.0;
   out_7305256634145735915[277] = 0.0;
   out_7305256634145735915[278] = 0.0;
   out_7305256634145735915[279] = 0.0;
   out_7305256634145735915[280] = 0.0;
   out_7305256634145735915[281] = 0.0;
   out_7305256634145735915[282] = 0.0;
   out_7305256634145735915[283] = 0.0;
   out_7305256634145735915[284] = 0.0;
   out_7305256634145735915[285] = 1.0;
   out_7305256634145735915[286] = 0.0;
   out_7305256634145735915[287] = 0.0;
   out_7305256634145735915[288] = 0.0;
   out_7305256634145735915[289] = 0.0;
   out_7305256634145735915[290] = 0.0;
   out_7305256634145735915[291] = 0.0;
   out_7305256634145735915[292] = 0.0;
   out_7305256634145735915[293] = 0.0;
   out_7305256634145735915[294] = 0.0;
   out_7305256634145735915[295] = 0.0;
   out_7305256634145735915[296] = 0.0;
   out_7305256634145735915[297] = 0.0;
   out_7305256634145735915[298] = 0.0;
   out_7305256634145735915[299] = 0.0;
   out_7305256634145735915[300] = 0.0;
   out_7305256634145735915[301] = 0.0;
   out_7305256634145735915[302] = 0.0;
   out_7305256634145735915[303] = 0.0;
   out_7305256634145735915[304] = 1.0;
   out_7305256634145735915[305] = 0.0;
   out_7305256634145735915[306] = 0.0;
   out_7305256634145735915[307] = 0.0;
   out_7305256634145735915[308] = 0.0;
   out_7305256634145735915[309] = 0.0;
   out_7305256634145735915[310] = 0.0;
   out_7305256634145735915[311] = 0.0;
   out_7305256634145735915[312] = 0.0;
   out_7305256634145735915[313] = 0.0;
   out_7305256634145735915[314] = 0.0;
   out_7305256634145735915[315] = 0.0;
   out_7305256634145735915[316] = 0.0;
   out_7305256634145735915[317] = 0.0;
   out_7305256634145735915[318] = 0.0;
   out_7305256634145735915[319] = 0.0;
   out_7305256634145735915[320] = 0.0;
   out_7305256634145735915[321] = 0.0;
   out_7305256634145735915[322] = 0.0;
   out_7305256634145735915[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_9088132790328569434) {
   out_9088132790328569434[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_9088132790328569434[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_9088132790328569434[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_9088132790328569434[3] = dt*state[12] + state[3];
   out_9088132790328569434[4] = dt*state[13] + state[4];
   out_9088132790328569434[5] = dt*state[14] + state[5];
   out_9088132790328569434[6] = state[6];
   out_9088132790328569434[7] = state[7];
   out_9088132790328569434[8] = state[8];
   out_9088132790328569434[9] = state[9];
   out_9088132790328569434[10] = state[10];
   out_9088132790328569434[11] = state[11];
   out_9088132790328569434[12] = state[12];
   out_9088132790328569434[13] = state[13];
   out_9088132790328569434[14] = state[14];
   out_9088132790328569434[15] = state[15];
   out_9088132790328569434[16] = state[16];
   out_9088132790328569434[17] = state[17];
}
void F_fun(double *state, double dt, double *out_729090673475074795) {
   out_729090673475074795[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_729090673475074795[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_729090673475074795[2] = 0;
   out_729090673475074795[3] = 0;
   out_729090673475074795[4] = 0;
   out_729090673475074795[5] = 0;
   out_729090673475074795[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_729090673475074795[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_729090673475074795[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_729090673475074795[9] = 0;
   out_729090673475074795[10] = 0;
   out_729090673475074795[11] = 0;
   out_729090673475074795[12] = 0;
   out_729090673475074795[13] = 0;
   out_729090673475074795[14] = 0;
   out_729090673475074795[15] = 0;
   out_729090673475074795[16] = 0;
   out_729090673475074795[17] = 0;
   out_729090673475074795[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_729090673475074795[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_729090673475074795[20] = 0;
   out_729090673475074795[21] = 0;
   out_729090673475074795[22] = 0;
   out_729090673475074795[23] = 0;
   out_729090673475074795[24] = 0;
   out_729090673475074795[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_729090673475074795[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_729090673475074795[27] = 0;
   out_729090673475074795[28] = 0;
   out_729090673475074795[29] = 0;
   out_729090673475074795[30] = 0;
   out_729090673475074795[31] = 0;
   out_729090673475074795[32] = 0;
   out_729090673475074795[33] = 0;
   out_729090673475074795[34] = 0;
   out_729090673475074795[35] = 0;
   out_729090673475074795[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_729090673475074795[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_729090673475074795[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_729090673475074795[39] = 0;
   out_729090673475074795[40] = 0;
   out_729090673475074795[41] = 0;
   out_729090673475074795[42] = 0;
   out_729090673475074795[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_729090673475074795[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_729090673475074795[45] = 0;
   out_729090673475074795[46] = 0;
   out_729090673475074795[47] = 0;
   out_729090673475074795[48] = 0;
   out_729090673475074795[49] = 0;
   out_729090673475074795[50] = 0;
   out_729090673475074795[51] = 0;
   out_729090673475074795[52] = 0;
   out_729090673475074795[53] = 0;
   out_729090673475074795[54] = 0;
   out_729090673475074795[55] = 0;
   out_729090673475074795[56] = 0;
   out_729090673475074795[57] = 1;
   out_729090673475074795[58] = 0;
   out_729090673475074795[59] = 0;
   out_729090673475074795[60] = 0;
   out_729090673475074795[61] = 0;
   out_729090673475074795[62] = 0;
   out_729090673475074795[63] = 0;
   out_729090673475074795[64] = 0;
   out_729090673475074795[65] = 0;
   out_729090673475074795[66] = dt;
   out_729090673475074795[67] = 0;
   out_729090673475074795[68] = 0;
   out_729090673475074795[69] = 0;
   out_729090673475074795[70] = 0;
   out_729090673475074795[71] = 0;
   out_729090673475074795[72] = 0;
   out_729090673475074795[73] = 0;
   out_729090673475074795[74] = 0;
   out_729090673475074795[75] = 0;
   out_729090673475074795[76] = 1;
   out_729090673475074795[77] = 0;
   out_729090673475074795[78] = 0;
   out_729090673475074795[79] = 0;
   out_729090673475074795[80] = 0;
   out_729090673475074795[81] = 0;
   out_729090673475074795[82] = 0;
   out_729090673475074795[83] = 0;
   out_729090673475074795[84] = 0;
   out_729090673475074795[85] = dt;
   out_729090673475074795[86] = 0;
   out_729090673475074795[87] = 0;
   out_729090673475074795[88] = 0;
   out_729090673475074795[89] = 0;
   out_729090673475074795[90] = 0;
   out_729090673475074795[91] = 0;
   out_729090673475074795[92] = 0;
   out_729090673475074795[93] = 0;
   out_729090673475074795[94] = 0;
   out_729090673475074795[95] = 1;
   out_729090673475074795[96] = 0;
   out_729090673475074795[97] = 0;
   out_729090673475074795[98] = 0;
   out_729090673475074795[99] = 0;
   out_729090673475074795[100] = 0;
   out_729090673475074795[101] = 0;
   out_729090673475074795[102] = 0;
   out_729090673475074795[103] = 0;
   out_729090673475074795[104] = dt;
   out_729090673475074795[105] = 0;
   out_729090673475074795[106] = 0;
   out_729090673475074795[107] = 0;
   out_729090673475074795[108] = 0;
   out_729090673475074795[109] = 0;
   out_729090673475074795[110] = 0;
   out_729090673475074795[111] = 0;
   out_729090673475074795[112] = 0;
   out_729090673475074795[113] = 0;
   out_729090673475074795[114] = 1;
   out_729090673475074795[115] = 0;
   out_729090673475074795[116] = 0;
   out_729090673475074795[117] = 0;
   out_729090673475074795[118] = 0;
   out_729090673475074795[119] = 0;
   out_729090673475074795[120] = 0;
   out_729090673475074795[121] = 0;
   out_729090673475074795[122] = 0;
   out_729090673475074795[123] = 0;
   out_729090673475074795[124] = 0;
   out_729090673475074795[125] = 0;
   out_729090673475074795[126] = 0;
   out_729090673475074795[127] = 0;
   out_729090673475074795[128] = 0;
   out_729090673475074795[129] = 0;
   out_729090673475074795[130] = 0;
   out_729090673475074795[131] = 0;
   out_729090673475074795[132] = 0;
   out_729090673475074795[133] = 1;
   out_729090673475074795[134] = 0;
   out_729090673475074795[135] = 0;
   out_729090673475074795[136] = 0;
   out_729090673475074795[137] = 0;
   out_729090673475074795[138] = 0;
   out_729090673475074795[139] = 0;
   out_729090673475074795[140] = 0;
   out_729090673475074795[141] = 0;
   out_729090673475074795[142] = 0;
   out_729090673475074795[143] = 0;
   out_729090673475074795[144] = 0;
   out_729090673475074795[145] = 0;
   out_729090673475074795[146] = 0;
   out_729090673475074795[147] = 0;
   out_729090673475074795[148] = 0;
   out_729090673475074795[149] = 0;
   out_729090673475074795[150] = 0;
   out_729090673475074795[151] = 0;
   out_729090673475074795[152] = 1;
   out_729090673475074795[153] = 0;
   out_729090673475074795[154] = 0;
   out_729090673475074795[155] = 0;
   out_729090673475074795[156] = 0;
   out_729090673475074795[157] = 0;
   out_729090673475074795[158] = 0;
   out_729090673475074795[159] = 0;
   out_729090673475074795[160] = 0;
   out_729090673475074795[161] = 0;
   out_729090673475074795[162] = 0;
   out_729090673475074795[163] = 0;
   out_729090673475074795[164] = 0;
   out_729090673475074795[165] = 0;
   out_729090673475074795[166] = 0;
   out_729090673475074795[167] = 0;
   out_729090673475074795[168] = 0;
   out_729090673475074795[169] = 0;
   out_729090673475074795[170] = 0;
   out_729090673475074795[171] = 1;
   out_729090673475074795[172] = 0;
   out_729090673475074795[173] = 0;
   out_729090673475074795[174] = 0;
   out_729090673475074795[175] = 0;
   out_729090673475074795[176] = 0;
   out_729090673475074795[177] = 0;
   out_729090673475074795[178] = 0;
   out_729090673475074795[179] = 0;
   out_729090673475074795[180] = 0;
   out_729090673475074795[181] = 0;
   out_729090673475074795[182] = 0;
   out_729090673475074795[183] = 0;
   out_729090673475074795[184] = 0;
   out_729090673475074795[185] = 0;
   out_729090673475074795[186] = 0;
   out_729090673475074795[187] = 0;
   out_729090673475074795[188] = 0;
   out_729090673475074795[189] = 0;
   out_729090673475074795[190] = 1;
   out_729090673475074795[191] = 0;
   out_729090673475074795[192] = 0;
   out_729090673475074795[193] = 0;
   out_729090673475074795[194] = 0;
   out_729090673475074795[195] = 0;
   out_729090673475074795[196] = 0;
   out_729090673475074795[197] = 0;
   out_729090673475074795[198] = 0;
   out_729090673475074795[199] = 0;
   out_729090673475074795[200] = 0;
   out_729090673475074795[201] = 0;
   out_729090673475074795[202] = 0;
   out_729090673475074795[203] = 0;
   out_729090673475074795[204] = 0;
   out_729090673475074795[205] = 0;
   out_729090673475074795[206] = 0;
   out_729090673475074795[207] = 0;
   out_729090673475074795[208] = 0;
   out_729090673475074795[209] = 1;
   out_729090673475074795[210] = 0;
   out_729090673475074795[211] = 0;
   out_729090673475074795[212] = 0;
   out_729090673475074795[213] = 0;
   out_729090673475074795[214] = 0;
   out_729090673475074795[215] = 0;
   out_729090673475074795[216] = 0;
   out_729090673475074795[217] = 0;
   out_729090673475074795[218] = 0;
   out_729090673475074795[219] = 0;
   out_729090673475074795[220] = 0;
   out_729090673475074795[221] = 0;
   out_729090673475074795[222] = 0;
   out_729090673475074795[223] = 0;
   out_729090673475074795[224] = 0;
   out_729090673475074795[225] = 0;
   out_729090673475074795[226] = 0;
   out_729090673475074795[227] = 0;
   out_729090673475074795[228] = 1;
   out_729090673475074795[229] = 0;
   out_729090673475074795[230] = 0;
   out_729090673475074795[231] = 0;
   out_729090673475074795[232] = 0;
   out_729090673475074795[233] = 0;
   out_729090673475074795[234] = 0;
   out_729090673475074795[235] = 0;
   out_729090673475074795[236] = 0;
   out_729090673475074795[237] = 0;
   out_729090673475074795[238] = 0;
   out_729090673475074795[239] = 0;
   out_729090673475074795[240] = 0;
   out_729090673475074795[241] = 0;
   out_729090673475074795[242] = 0;
   out_729090673475074795[243] = 0;
   out_729090673475074795[244] = 0;
   out_729090673475074795[245] = 0;
   out_729090673475074795[246] = 0;
   out_729090673475074795[247] = 1;
   out_729090673475074795[248] = 0;
   out_729090673475074795[249] = 0;
   out_729090673475074795[250] = 0;
   out_729090673475074795[251] = 0;
   out_729090673475074795[252] = 0;
   out_729090673475074795[253] = 0;
   out_729090673475074795[254] = 0;
   out_729090673475074795[255] = 0;
   out_729090673475074795[256] = 0;
   out_729090673475074795[257] = 0;
   out_729090673475074795[258] = 0;
   out_729090673475074795[259] = 0;
   out_729090673475074795[260] = 0;
   out_729090673475074795[261] = 0;
   out_729090673475074795[262] = 0;
   out_729090673475074795[263] = 0;
   out_729090673475074795[264] = 0;
   out_729090673475074795[265] = 0;
   out_729090673475074795[266] = 1;
   out_729090673475074795[267] = 0;
   out_729090673475074795[268] = 0;
   out_729090673475074795[269] = 0;
   out_729090673475074795[270] = 0;
   out_729090673475074795[271] = 0;
   out_729090673475074795[272] = 0;
   out_729090673475074795[273] = 0;
   out_729090673475074795[274] = 0;
   out_729090673475074795[275] = 0;
   out_729090673475074795[276] = 0;
   out_729090673475074795[277] = 0;
   out_729090673475074795[278] = 0;
   out_729090673475074795[279] = 0;
   out_729090673475074795[280] = 0;
   out_729090673475074795[281] = 0;
   out_729090673475074795[282] = 0;
   out_729090673475074795[283] = 0;
   out_729090673475074795[284] = 0;
   out_729090673475074795[285] = 1;
   out_729090673475074795[286] = 0;
   out_729090673475074795[287] = 0;
   out_729090673475074795[288] = 0;
   out_729090673475074795[289] = 0;
   out_729090673475074795[290] = 0;
   out_729090673475074795[291] = 0;
   out_729090673475074795[292] = 0;
   out_729090673475074795[293] = 0;
   out_729090673475074795[294] = 0;
   out_729090673475074795[295] = 0;
   out_729090673475074795[296] = 0;
   out_729090673475074795[297] = 0;
   out_729090673475074795[298] = 0;
   out_729090673475074795[299] = 0;
   out_729090673475074795[300] = 0;
   out_729090673475074795[301] = 0;
   out_729090673475074795[302] = 0;
   out_729090673475074795[303] = 0;
   out_729090673475074795[304] = 1;
   out_729090673475074795[305] = 0;
   out_729090673475074795[306] = 0;
   out_729090673475074795[307] = 0;
   out_729090673475074795[308] = 0;
   out_729090673475074795[309] = 0;
   out_729090673475074795[310] = 0;
   out_729090673475074795[311] = 0;
   out_729090673475074795[312] = 0;
   out_729090673475074795[313] = 0;
   out_729090673475074795[314] = 0;
   out_729090673475074795[315] = 0;
   out_729090673475074795[316] = 0;
   out_729090673475074795[317] = 0;
   out_729090673475074795[318] = 0;
   out_729090673475074795[319] = 0;
   out_729090673475074795[320] = 0;
   out_729090673475074795[321] = 0;
   out_729090673475074795[322] = 0;
   out_729090673475074795[323] = 1;
}
void h_4(double *state, double *unused, double *out_8764272932229882331) {
   out_8764272932229882331[0] = state[6] + state[9];
   out_8764272932229882331[1] = state[7] + state[10];
   out_8764272932229882331[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5988969054524734966) {
   out_5988969054524734966[0] = 0;
   out_5988969054524734966[1] = 0;
   out_5988969054524734966[2] = 0;
   out_5988969054524734966[3] = 0;
   out_5988969054524734966[4] = 0;
   out_5988969054524734966[5] = 0;
   out_5988969054524734966[6] = 1;
   out_5988969054524734966[7] = 0;
   out_5988969054524734966[8] = 0;
   out_5988969054524734966[9] = 1;
   out_5988969054524734966[10] = 0;
   out_5988969054524734966[11] = 0;
   out_5988969054524734966[12] = 0;
   out_5988969054524734966[13] = 0;
   out_5988969054524734966[14] = 0;
   out_5988969054524734966[15] = 0;
   out_5988969054524734966[16] = 0;
   out_5988969054524734966[17] = 0;
   out_5988969054524734966[18] = 0;
   out_5988969054524734966[19] = 0;
   out_5988969054524734966[20] = 0;
   out_5988969054524734966[21] = 0;
   out_5988969054524734966[22] = 0;
   out_5988969054524734966[23] = 0;
   out_5988969054524734966[24] = 0;
   out_5988969054524734966[25] = 1;
   out_5988969054524734966[26] = 0;
   out_5988969054524734966[27] = 0;
   out_5988969054524734966[28] = 1;
   out_5988969054524734966[29] = 0;
   out_5988969054524734966[30] = 0;
   out_5988969054524734966[31] = 0;
   out_5988969054524734966[32] = 0;
   out_5988969054524734966[33] = 0;
   out_5988969054524734966[34] = 0;
   out_5988969054524734966[35] = 0;
   out_5988969054524734966[36] = 0;
   out_5988969054524734966[37] = 0;
   out_5988969054524734966[38] = 0;
   out_5988969054524734966[39] = 0;
   out_5988969054524734966[40] = 0;
   out_5988969054524734966[41] = 0;
   out_5988969054524734966[42] = 0;
   out_5988969054524734966[43] = 0;
   out_5988969054524734966[44] = 1;
   out_5988969054524734966[45] = 0;
   out_5988969054524734966[46] = 0;
   out_5988969054524734966[47] = 1;
   out_5988969054524734966[48] = 0;
   out_5988969054524734966[49] = 0;
   out_5988969054524734966[50] = 0;
   out_5988969054524734966[51] = 0;
   out_5988969054524734966[52] = 0;
   out_5988969054524734966[53] = 0;
}
void h_10(double *state, double *unused, double *out_6414221724467934748) {
   out_6414221724467934748[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6414221724467934748[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6414221724467934748[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1153388749736371435) {
   out_1153388749736371435[0] = 0;
   out_1153388749736371435[1] = 9.8100000000000005*cos(state[1]);
   out_1153388749736371435[2] = 0;
   out_1153388749736371435[3] = 0;
   out_1153388749736371435[4] = -state[8];
   out_1153388749736371435[5] = state[7];
   out_1153388749736371435[6] = 0;
   out_1153388749736371435[7] = state[5];
   out_1153388749736371435[8] = -state[4];
   out_1153388749736371435[9] = 0;
   out_1153388749736371435[10] = 0;
   out_1153388749736371435[11] = 0;
   out_1153388749736371435[12] = 1;
   out_1153388749736371435[13] = 0;
   out_1153388749736371435[14] = 0;
   out_1153388749736371435[15] = 1;
   out_1153388749736371435[16] = 0;
   out_1153388749736371435[17] = 0;
   out_1153388749736371435[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1153388749736371435[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1153388749736371435[20] = 0;
   out_1153388749736371435[21] = state[8];
   out_1153388749736371435[22] = 0;
   out_1153388749736371435[23] = -state[6];
   out_1153388749736371435[24] = -state[5];
   out_1153388749736371435[25] = 0;
   out_1153388749736371435[26] = state[3];
   out_1153388749736371435[27] = 0;
   out_1153388749736371435[28] = 0;
   out_1153388749736371435[29] = 0;
   out_1153388749736371435[30] = 0;
   out_1153388749736371435[31] = 1;
   out_1153388749736371435[32] = 0;
   out_1153388749736371435[33] = 0;
   out_1153388749736371435[34] = 1;
   out_1153388749736371435[35] = 0;
   out_1153388749736371435[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1153388749736371435[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1153388749736371435[38] = 0;
   out_1153388749736371435[39] = -state[7];
   out_1153388749736371435[40] = state[6];
   out_1153388749736371435[41] = 0;
   out_1153388749736371435[42] = state[4];
   out_1153388749736371435[43] = -state[3];
   out_1153388749736371435[44] = 0;
   out_1153388749736371435[45] = 0;
   out_1153388749736371435[46] = 0;
   out_1153388749736371435[47] = 0;
   out_1153388749736371435[48] = 0;
   out_1153388749736371435[49] = 0;
   out_1153388749736371435[50] = 1;
   out_1153388749736371435[51] = 0;
   out_1153388749736371435[52] = 0;
   out_1153388749736371435[53] = 1;
}
void h_13(double *state, double *unused, double *out_5610980844253424068) {
   out_5610980844253424068[0] = state[3];
   out_5610980844253424068[1] = state[4];
   out_5610980844253424068[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2776695229192402165) {
   out_2776695229192402165[0] = 0;
   out_2776695229192402165[1] = 0;
   out_2776695229192402165[2] = 0;
   out_2776695229192402165[3] = 1;
   out_2776695229192402165[4] = 0;
   out_2776695229192402165[5] = 0;
   out_2776695229192402165[6] = 0;
   out_2776695229192402165[7] = 0;
   out_2776695229192402165[8] = 0;
   out_2776695229192402165[9] = 0;
   out_2776695229192402165[10] = 0;
   out_2776695229192402165[11] = 0;
   out_2776695229192402165[12] = 0;
   out_2776695229192402165[13] = 0;
   out_2776695229192402165[14] = 0;
   out_2776695229192402165[15] = 0;
   out_2776695229192402165[16] = 0;
   out_2776695229192402165[17] = 0;
   out_2776695229192402165[18] = 0;
   out_2776695229192402165[19] = 0;
   out_2776695229192402165[20] = 0;
   out_2776695229192402165[21] = 0;
   out_2776695229192402165[22] = 1;
   out_2776695229192402165[23] = 0;
   out_2776695229192402165[24] = 0;
   out_2776695229192402165[25] = 0;
   out_2776695229192402165[26] = 0;
   out_2776695229192402165[27] = 0;
   out_2776695229192402165[28] = 0;
   out_2776695229192402165[29] = 0;
   out_2776695229192402165[30] = 0;
   out_2776695229192402165[31] = 0;
   out_2776695229192402165[32] = 0;
   out_2776695229192402165[33] = 0;
   out_2776695229192402165[34] = 0;
   out_2776695229192402165[35] = 0;
   out_2776695229192402165[36] = 0;
   out_2776695229192402165[37] = 0;
   out_2776695229192402165[38] = 0;
   out_2776695229192402165[39] = 0;
   out_2776695229192402165[40] = 0;
   out_2776695229192402165[41] = 1;
   out_2776695229192402165[42] = 0;
   out_2776695229192402165[43] = 0;
   out_2776695229192402165[44] = 0;
   out_2776695229192402165[45] = 0;
   out_2776695229192402165[46] = 0;
   out_2776695229192402165[47] = 0;
   out_2776695229192402165[48] = 0;
   out_2776695229192402165[49] = 0;
   out_2776695229192402165[50] = 0;
   out_2776695229192402165[51] = 0;
   out_2776695229192402165[52] = 0;
   out_2776695229192402165[53] = 0;
}
void h_14(double *state, double *unused, double *out_4768711222929490371) {
   out_4768711222929490371[0] = state[6];
   out_4768711222929490371[1] = state[7];
   out_4768711222929490371[2] = state[8];
}
void H_14(double *state, double *unused, double *out_9071757486820107262) {
   out_9071757486820107262[0] = 0;
   out_9071757486820107262[1] = 0;
   out_9071757486820107262[2] = 0;
   out_9071757486820107262[3] = 0;
   out_9071757486820107262[4] = 0;
   out_9071757486820107262[5] = 0;
   out_9071757486820107262[6] = 1;
   out_9071757486820107262[7] = 0;
   out_9071757486820107262[8] = 0;
   out_9071757486820107262[9] = 0;
   out_9071757486820107262[10] = 0;
   out_9071757486820107262[11] = 0;
   out_9071757486820107262[12] = 0;
   out_9071757486820107262[13] = 0;
   out_9071757486820107262[14] = 0;
   out_9071757486820107262[15] = 0;
   out_9071757486820107262[16] = 0;
   out_9071757486820107262[17] = 0;
   out_9071757486820107262[18] = 0;
   out_9071757486820107262[19] = 0;
   out_9071757486820107262[20] = 0;
   out_9071757486820107262[21] = 0;
   out_9071757486820107262[22] = 0;
   out_9071757486820107262[23] = 0;
   out_9071757486820107262[24] = 0;
   out_9071757486820107262[25] = 1;
   out_9071757486820107262[26] = 0;
   out_9071757486820107262[27] = 0;
   out_9071757486820107262[28] = 0;
   out_9071757486820107262[29] = 0;
   out_9071757486820107262[30] = 0;
   out_9071757486820107262[31] = 0;
   out_9071757486820107262[32] = 0;
   out_9071757486820107262[33] = 0;
   out_9071757486820107262[34] = 0;
   out_9071757486820107262[35] = 0;
   out_9071757486820107262[36] = 0;
   out_9071757486820107262[37] = 0;
   out_9071757486820107262[38] = 0;
   out_9071757486820107262[39] = 0;
   out_9071757486820107262[40] = 0;
   out_9071757486820107262[41] = 0;
   out_9071757486820107262[42] = 0;
   out_9071757486820107262[43] = 0;
   out_9071757486820107262[44] = 1;
   out_9071757486820107262[45] = 0;
   out_9071757486820107262[46] = 0;
   out_9071757486820107262[47] = 0;
   out_9071757486820107262[48] = 0;
   out_9071757486820107262[49] = 0;
   out_9071757486820107262[50] = 0;
   out_9071757486820107262[51] = 0;
   out_9071757486820107262[52] = 0;
   out_9071757486820107262[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_845527351868247428) {
  err_fun(nom_x, delta_x, out_845527351868247428);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6367069276716114158) {
  inv_err_fun(nom_x, true_x, out_6367069276716114158);
}
void pose_H_mod_fun(double *state, double *out_7305256634145735915) {
  H_mod_fun(state, out_7305256634145735915);
}
void pose_f_fun(double *state, double dt, double *out_9088132790328569434) {
  f_fun(state,  dt, out_9088132790328569434);
}
void pose_F_fun(double *state, double dt, double *out_729090673475074795) {
  F_fun(state,  dt, out_729090673475074795);
}
void pose_h_4(double *state, double *unused, double *out_8764272932229882331) {
  h_4(state, unused, out_8764272932229882331);
}
void pose_H_4(double *state, double *unused, double *out_5988969054524734966) {
  H_4(state, unused, out_5988969054524734966);
}
void pose_h_10(double *state, double *unused, double *out_6414221724467934748) {
  h_10(state, unused, out_6414221724467934748);
}
void pose_H_10(double *state, double *unused, double *out_1153388749736371435) {
  H_10(state, unused, out_1153388749736371435);
}
void pose_h_13(double *state, double *unused, double *out_5610980844253424068) {
  h_13(state, unused, out_5610980844253424068);
}
void pose_H_13(double *state, double *unused, double *out_2776695229192402165) {
  H_13(state, unused, out_2776695229192402165);
}
void pose_h_14(double *state, double *unused, double *out_4768711222929490371) {
  h_14(state, unused, out_4768711222929490371);
}
void pose_H_14(double *state, double *unused, double *out_9071757486820107262) {
  H_14(state, unused, out_9071757486820107262);
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
