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
void err_fun(double *nom_x, double *delta_x, double *out_7431505958311813382) {
   out_7431505958311813382[0] = delta_x[0] + nom_x[0];
   out_7431505958311813382[1] = delta_x[1] + nom_x[1];
   out_7431505958311813382[2] = delta_x[2] + nom_x[2];
   out_7431505958311813382[3] = delta_x[3] + nom_x[3];
   out_7431505958311813382[4] = delta_x[4] + nom_x[4];
   out_7431505958311813382[5] = delta_x[5] + nom_x[5];
   out_7431505958311813382[6] = delta_x[6] + nom_x[6];
   out_7431505958311813382[7] = delta_x[7] + nom_x[7];
   out_7431505958311813382[8] = delta_x[8] + nom_x[8];
   out_7431505958311813382[9] = delta_x[9] + nom_x[9];
   out_7431505958311813382[10] = delta_x[10] + nom_x[10];
   out_7431505958311813382[11] = delta_x[11] + nom_x[11];
   out_7431505958311813382[12] = delta_x[12] + nom_x[12];
   out_7431505958311813382[13] = delta_x[13] + nom_x[13];
   out_7431505958311813382[14] = delta_x[14] + nom_x[14];
   out_7431505958311813382[15] = delta_x[15] + nom_x[15];
   out_7431505958311813382[16] = delta_x[16] + nom_x[16];
   out_7431505958311813382[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8551627000098797431) {
   out_8551627000098797431[0] = -nom_x[0] + true_x[0];
   out_8551627000098797431[1] = -nom_x[1] + true_x[1];
   out_8551627000098797431[2] = -nom_x[2] + true_x[2];
   out_8551627000098797431[3] = -nom_x[3] + true_x[3];
   out_8551627000098797431[4] = -nom_x[4] + true_x[4];
   out_8551627000098797431[5] = -nom_x[5] + true_x[5];
   out_8551627000098797431[6] = -nom_x[6] + true_x[6];
   out_8551627000098797431[7] = -nom_x[7] + true_x[7];
   out_8551627000098797431[8] = -nom_x[8] + true_x[8];
   out_8551627000098797431[9] = -nom_x[9] + true_x[9];
   out_8551627000098797431[10] = -nom_x[10] + true_x[10];
   out_8551627000098797431[11] = -nom_x[11] + true_x[11];
   out_8551627000098797431[12] = -nom_x[12] + true_x[12];
   out_8551627000098797431[13] = -nom_x[13] + true_x[13];
   out_8551627000098797431[14] = -nom_x[14] + true_x[14];
   out_8551627000098797431[15] = -nom_x[15] + true_x[15];
   out_8551627000098797431[16] = -nom_x[16] + true_x[16];
   out_8551627000098797431[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4284093078770863471) {
   out_4284093078770863471[0] = 1.0;
   out_4284093078770863471[1] = 0.0;
   out_4284093078770863471[2] = 0.0;
   out_4284093078770863471[3] = 0.0;
   out_4284093078770863471[4] = 0.0;
   out_4284093078770863471[5] = 0.0;
   out_4284093078770863471[6] = 0.0;
   out_4284093078770863471[7] = 0.0;
   out_4284093078770863471[8] = 0.0;
   out_4284093078770863471[9] = 0.0;
   out_4284093078770863471[10] = 0.0;
   out_4284093078770863471[11] = 0.0;
   out_4284093078770863471[12] = 0.0;
   out_4284093078770863471[13] = 0.0;
   out_4284093078770863471[14] = 0.0;
   out_4284093078770863471[15] = 0.0;
   out_4284093078770863471[16] = 0.0;
   out_4284093078770863471[17] = 0.0;
   out_4284093078770863471[18] = 0.0;
   out_4284093078770863471[19] = 1.0;
   out_4284093078770863471[20] = 0.0;
   out_4284093078770863471[21] = 0.0;
   out_4284093078770863471[22] = 0.0;
   out_4284093078770863471[23] = 0.0;
   out_4284093078770863471[24] = 0.0;
   out_4284093078770863471[25] = 0.0;
   out_4284093078770863471[26] = 0.0;
   out_4284093078770863471[27] = 0.0;
   out_4284093078770863471[28] = 0.0;
   out_4284093078770863471[29] = 0.0;
   out_4284093078770863471[30] = 0.0;
   out_4284093078770863471[31] = 0.0;
   out_4284093078770863471[32] = 0.0;
   out_4284093078770863471[33] = 0.0;
   out_4284093078770863471[34] = 0.0;
   out_4284093078770863471[35] = 0.0;
   out_4284093078770863471[36] = 0.0;
   out_4284093078770863471[37] = 0.0;
   out_4284093078770863471[38] = 1.0;
   out_4284093078770863471[39] = 0.0;
   out_4284093078770863471[40] = 0.0;
   out_4284093078770863471[41] = 0.0;
   out_4284093078770863471[42] = 0.0;
   out_4284093078770863471[43] = 0.0;
   out_4284093078770863471[44] = 0.0;
   out_4284093078770863471[45] = 0.0;
   out_4284093078770863471[46] = 0.0;
   out_4284093078770863471[47] = 0.0;
   out_4284093078770863471[48] = 0.0;
   out_4284093078770863471[49] = 0.0;
   out_4284093078770863471[50] = 0.0;
   out_4284093078770863471[51] = 0.0;
   out_4284093078770863471[52] = 0.0;
   out_4284093078770863471[53] = 0.0;
   out_4284093078770863471[54] = 0.0;
   out_4284093078770863471[55] = 0.0;
   out_4284093078770863471[56] = 0.0;
   out_4284093078770863471[57] = 1.0;
   out_4284093078770863471[58] = 0.0;
   out_4284093078770863471[59] = 0.0;
   out_4284093078770863471[60] = 0.0;
   out_4284093078770863471[61] = 0.0;
   out_4284093078770863471[62] = 0.0;
   out_4284093078770863471[63] = 0.0;
   out_4284093078770863471[64] = 0.0;
   out_4284093078770863471[65] = 0.0;
   out_4284093078770863471[66] = 0.0;
   out_4284093078770863471[67] = 0.0;
   out_4284093078770863471[68] = 0.0;
   out_4284093078770863471[69] = 0.0;
   out_4284093078770863471[70] = 0.0;
   out_4284093078770863471[71] = 0.0;
   out_4284093078770863471[72] = 0.0;
   out_4284093078770863471[73] = 0.0;
   out_4284093078770863471[74] = 0.0;
   out_4284093078770863471[75] = 0.0;
   out_4284093078770863471[76] = 1.0;
   out_4284093078770863471[77] = 0.0;
   out_4284093078770863471[78] = 0.0;
   out_4284093078770863471[79] = 0.0;
   out_4284093078770863471[80] = 0.0;
   out_4284093078770863471[81] = 0.0;
   out_4284093078770863471[82] = 0.0;
   out_4284093078770863471[83] = 0.0;
   out_4284093078770863471[84] = 0.0;
   out_4284093078770863471[85] = 0.0;
   out_4284093078770863471[86] = 0.0;
   out_4284093078770863471[87] = 0.0;
   out_4284093078770863471[88] = 0.0;
   out_4284093078770863471[89] = 0.0;
   out_4284093078770863471[90] = 0.0;
   out_4284093078770863471[91] = 0.0;
   out_4284093078770863471[92] = 0.0;
   out_4284093078770863471[93] = 0.0;
   out_4284093078770863471[94] = 0.0;
   out_4284093078770863471[95] = 1.0;
   out_4284093078770863471[96] = 0.0;
   out_4284093078770863471[97] = 0.0;
   out_4284093078770863471[98] = 0.0;
   out_4284093078770863471[99] = 0.0;
   out_4284093078770863471[100] = 0.0;
   out_4284093078770863471[101] = 0.0;
   out_4284093078770863471[102] = 0.0;
   out_4284093078770863471[103] = 0.0;
   out_4284093078770863471[104] = 0.0;
   out_4284093078770863471[105] = 0.0;
   out_4284093078770863471[106] = 0.0;
   out_4284093078770863471[107] = 0.0;
   out_4284093078770863471[108] = 0.0;
   out_4284093078770863471[109] = 0.0;
   out_4284093078770863471[110] = 0.0;
   out_4284093078770863471[111] = 0.0;
   out_4284093078770863471[112] = 0.0;
   out_4284093078770863471[113] = 0.0;
   out_4284093078770863471[114] = 1.0;
   out_4284093078770863471[115] = 0.0;
   out_4284093078770863471[116] = 0.0;
   out_4284093078770863471[117] = 0.0;
   out_4284093078770863471[118] = 0.0;
   out_4284093078770863471[119] = 0.0;
   out_4284093078770863471[120] = 0.0;
   out_4284093078770863471[121] = 0.0;
   out_4284093078770863471[122] = 0.0;
   out_4284093078770863471[123] = 0.0;
   out_4284093078770863471[124] = 0.0;
   out_4284093078770863471[125] = 0.0;
   out_4284093078770863471[126] = 0.0;
   out_4284093078770863471[127] = 0.0;
   out_4284093078770863471[128] = 0.0;
   out_4284093078770863471[129] = 0.0;
   out_4284093078770863471[130] = 0.0;
   out_4284093078770863471[131] = 0.0;
   out_4284093078770863471[132] = 0.0;
   out_4284093078770863471[133] = 1.0;
   out_4284093078770863471[134] = 0.0;
   out_4284093078770863471[135] = 0.0;
   out_4284093078770863471[136] = 0.0;
   out_4284093078770863471[137] = 0.0;
   out_4284093078770863471[138] = 0.0;
   out_4284093078770863471[139] = 0.0;
   out_4284093078770863471[140] = 0.0;
   out_4284093078770863471[141] = 0.0;
   out_4284093078770863471[142] = 0.0;
   out_4284093078770863471[143] = 0.0;
   out_4284093078770863471[144] = 0.0;
   out_4284093078770863471[145] = 0.0;
   out_4284093078770863471[146] = 0.0;
   out_4284093078770863471[147] = 0.0;
   out_4284093078770863471[148] = 0.0;
   out_4284093078770863471[149] = 0.0;
   out_4284093078770863471[150] = 0.0;
   out_4284093078770863471[151] = 0.0;
   out_4284093078770863471[152] = 1.0;
   out_4284093078770863471[153] = 0.0;
   out_4284093078770863471[154] = 0.0;
   out_4284093078770863471[155] = 0.0;
   out_4284093078770863471[156] = 0.0;
   out_4284093078770863471[157] = 0.0;
   out_4284093078770863471[158] = 0.0;
   out_4284093078770863471[159] = 0.0;
   out_4284093078770863471[160] = 0.0;
   out_4284093078770863471[161] = 0.0;
   out_4284093078770863471[162] = 0.0;
   out_4284093078770863471[163] = 0.0;
   out_4284093078770863471[164] = 0.0;
   out_4284093078770863471[165] = 0.0;
   out_4284093078770863471[166] = 0.0;
   out_4284093078770863471[167] = 0.0;
   out_4284093078770863471[168] = 0.0;
   out_4284093078770863471[169] = 0.0;
   out_4284093078770863471[170] = 0.0;
   out_4284093078770863471[171] = 1.0;
   out_4284093078770863471[172] = 0.0;
   out_4284093078770863471[173] = 0.0;
   out_4284093078770863471[174] = 0.0;
   out_4284093078770863471[175] = 0.0;
   out_4284093078770863471[176] = 0.0;
   out_4284093078770863471[177] = 0.0;
   out_4284093078770863471[178] = 0.0;
   out_4284093078770863471[179] = 0.0;
   out_4284093078770863471[180] = 0.0;
   out_4284093078770863471[181] = 0.0;
   out_4284093078770863471[182] = 0.0;
   out_4284093078770863471[183] = 0.0;
   out_4284093078770863471[184] = 0.0;
   out_4284093078770863471[185] = 0.0;
   out_4284093078770863471[186] = 0.0;
   out_4284093078770863471[187] = 0.0;
   out_4284093078770863471[188] = 0.0;
   out_4284093078770863471[189] = 0.0;
   out_4284093078770863471[190] = 1.0;
   out_4284093078770863471[191] = 0.0;
   out_4284093078770863471[192] = 0.0;
   out_4284093078770863471[193] = 0.0;
   out_4284093078770863471[194] = 0.0;
   out_4284093078770863471[195] = 0.0;
   out_4284093078770863471[196] = 0.0;
   out_4284093078770863471[197] = 0.0;
   out_4284093078770863471[198] = 0.0;
   out_4284093078770863471[199] = 0.0;
   out_4284093078770863471[200] = 0.0;
   out_4284093078770863471[201] = 0.0;
   out_4284093078770863471[202] = 0.0;
   out_4284093078770863471[203] = 0.0;
   out_4284093078770863471[204] = 0.0;
   out_4284093078770863471[205] = 0.0;
   out_4284093078770863471[206] = 0.0;
   out_4284093078770863471[207] = 0.0;
   out_4284093078770863471[208] = 0.0;
   out_4284093078770863471[209] = 1.0;
   out_4284093078770863471[210] = 0.0;
   out_4284093078770863471[211] = 0.0;
   out_4284093078770863471[212] = 0.0;
   out_4284093078770863471[213] = 0.0;
   out_4284093078770863471[214] = 0.0;
   out_4284093078770863471[215] = 0.0;
   out_4284093078770863471[216] = 0.0;
   out_4284093078770863471[217] = 0.0;
   out_4284093078770863471[218] = 0.0;
   out_4284093078770863471[219] = 0.0;
   out_4284093078770863471[220] = 0.0;
   out_4284093078770863471[221] = 0.0;
   out_4284093078770863471[222] = 0.0;
   out_4284093078770863471[223] = 0.0;
   out_4284093078770863471[224] = 0.0;
   out_4284093078770863471[225] = 0.0;
   out_4284093078770863471[226] = 0.0;
   out_4284093078770863471[227] = 0.0;
   out_4284093078770863471[228] = 1.0;
   out_4284093078770863471[229] = 0.0;
   out_4284093078770863471[230] = 0.0;
   out_4284093078770863471[231] = 0.0;
   out_4284093078770863471[232] = 0.0;
   out_4284093078770863471[233] = 0.0;
   out_4284093078770863471[234] = 0.0;
   out_4284093078770863471[235] = 0.0;
   out_4284093078770863471[236] = 0.0;
   out_4284093078770863471[237] = 0.0;
   out_4284093078770863471[238] = 0.0;
   out_4284093078770863471[239] = 0.0;
   out_4284093078770863471[240] = 0.0;
   out_4284093078770863471[241] = 0.0;
   out_4284093078770863471[242] = 0.0;
   out_4284093078770863471[243] = 0.0;
   out_4284093078770863471[244] = 0.0;
   out_4284093078770863471[245] = 0.0;
   out_4284093078770863471[246] = 0.0;
   out_4284093078770863471[247] = 1.0;
   out_4284093078770863471[248] = 0.0;
   out_4284093078770863471[249] = 0.0;
   out_4284093078770863471[250] = 0.0;
   out_4284093078770863471[251] = 0.0;
   out_4284093078770863471[252] = 0.0;
   out_4284093078770863471[253] = 0.0;
   out_4284093078770863471[254] = 0.0;
   out_4284093078770863471[255] = 0.0;
   out_4284093078770863471[256] = 0.0;
   out_4284093078770863471[257] = 0.0;
   out_4284093078770863471[258] = 0.0;
   out_4284093078770863471[259] = 0.0;
   out_4284093078770863471[260] = 0.0;
   out_4284093078770863471[261] = 0.0;
   out_4284093078770863471[262] = 0.0;
   out_4284093078770863471[263] = 0.0;
   out_4284093078770863471[264] = 0.0;
   out_4284093078770863471[265] = 0.0;
   out_4284093078770863471[266] = 1.0;
   out_4284093078770863471[267] = 0.0;
   out_4284093078770863471[268] = 0.0;
   out_4284093078770863471[269] = 0.0;
   out_4284093078770863471[270] = 0.0;
   out_4284093078770863471[271] = 0.0;
   out_4284093078770863471[272] = 0.0;
   out_4284093078770863471[273] = 0.0;
   out_4284093078770863471[274] = 0.0;
   out_4284093078770863471[275] = 0.0;
   out_4284093078770863471[276] = 0.0;
   out_4284093078770863471[277] = 0.0;
   out_4284093078770863471[278] = 0.0;
   out_4284093078770863471[279] = 0.0;
   out_4284093078770863471[280] = 0.0;
   out_4284093078770863471[281] = 0.0;
   out_4284093078770863471[282] = 0.0;
   out_4284093078770863471[283] = 0.0;
   out_4284093078770863471[284] = 0.0;
   out_4284093078770863471[285] = 1.0;
   out_4284093078770863471[286] = 0.0;
   out_4284093078770863471[287] = 0.0;
   out_4284093078770863471[288] = 0.0;
   out_4284093078770863471[289] = 0.0;
   out_4284093078770863471[290] = 0.0;
   out_4284093078770863471[291] = 0.0;
   out_4284093078770863471[292] = 0.0;
   out_4284093078770863471[293] = 0.0;
   out_4284093078770863471[294] = 0.0;
   out_4284093078770863471[295] = 0.0;
   out_4284093078770863471[296] = 0.0;
   out_4284093078770863471[297] = 0.0;
   out_4284093078770863471[298] = 0.0;
   out_4284093078770863471[299] = 0.0;
   out_4284093078770863471[300] = 0.0;
   out_4284093078770863471[301] = 0.0;
   out_4284093078770863471[302] = 0.0;
   out_4284093078770863471[303] = 0.0;
   out_4284093078770863471[304] = 1.0;
   out_4284093078770863471[305] = 0.0;
   out_4284093078770863471[306] = 0.0;
   out_4284093078770863471[307] = 0.0;
   out_4284093078770863471[308] = 0.0;
   out_4284093078770863471[309] = 0.0;
   out_4284093078770863471[310] = 0.0;
   out_4284093078770863471[311] = 0.0;
   out_4284093078770863471[312] = 0.0;
   out_4284093078770863471[313] = 0.0;
   out_4284093078770863471[314] = 0.0;
   out_4284093078770863471[315] = 0.0;
   out_4284093078770863471[316] = 0.0;
   out_4284093078770863471[317] = 0.0;
   out_4284093078770863471[318] = 0.0;
   out_4284093078770863471[319] = 0.0;
   out_4284093078770863471[320] = 0.0;
   out_4284093078770863471[321] = 0.0;
   out_4284093078770863471[322] = 0.0;
   out_4284093078770863471[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6442140298881834415) {
   out_6442140298881834415[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6442140298881834415[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6442140298881834415[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6442140298881834415[3] = dt*state[12] + state[3];
   out_6442140298881834415[4] = dt*state[13] + state[4];
   out_6442140298881834415[5] = dt*state[14] + state[5];
   out_6442140298881834415[6] = state[6];
   out_6442140298881834415[7] = state[7];
   out_6442140298881834415[8] = state[8];
   out_6442140298881834415[9] = state[9];
   out_6442140298881834415[10] = state[10];
   out_6442140298881834415[11] = state[11];
   out_6442140298881834415[12] = state[12];
   out_6442140298881834415[13] = state[13];
   out_6442140298881834415[14] = state[14];
   out_6442140298881834415[15] = state[15];
   out_6442140298881834415[16] = state[16];
   out_6442140298881834415[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3934539972733810872) {
   out_3934539972733810872[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3934539972733810872[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3934539972733810872[2] = 0;
   out_3934539972733810872[3] = 0;
   out_3934539972733810872[4] = 0;
   out_3934539972733810872[5] = 0;
   out_3934539972733810872[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3934539972733810872[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3934539972733810872[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3934539972733810872[9] = 0;
   out_3934539972733810872[10] = 0;
   out_3934539972733810872[11] = 0;
   out_3934539972733810872[12] = 0;
   out_3934539972733810872[13] = 0;
   out_3934539972733810872[14] = 0;
   out_3934539972733810872[15] = 0;
   out_3934539972733810872[16] = 0;
   out_3934539972733810872[17] = 0;
   out_3934539972733810872[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3934539972733810872[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3934539972733810872[20] = 0;
   out_3934539972733810872[21] = 0;
   out_3934539972733810872[22] = 0;
   out_3934539972733810872[23] = 0;
   out_3934539972733810872[24] = 0;
   out_3934539972733810872[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3934539972733810872[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3934539972733810872[27] = 0;
   out_3934539972733810872[28] = 0;
   out_3934539972733810872[29] = 0;
   out_3934539972733810872[30] = 0;
   out_3934539972733810872[31] = 0;
   out_3934539972733810872[32] = 0;
   out_3934539972733810872[33] = 0;
   out_3934539972733810872[34] = 0;
   out_3934539972733810872[35] = 0;
   out_3934539972733810872[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3934539972733810872[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3934539972733810872[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3934539972733810872[39] = 0;
   out_3934539972733810872[40] = 0;
   out_3934539972733810872[41] = 0;
   out_3934539972733810872[42] = 0;
   out_3934539972733810872[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3934539972733810872[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3934539972733810872[45] = 0;
   out_3934539972733810872[46] = 0;
   out_3934539972733810872[47] = 0;
   out_3934539972733810872[48] = 0;
   out_3934539972733810872[49] = 0;
   out_3934539972733810872[50] = 0;
   out_3934539972733810872[51] = 0;
   out_3934539972733810872[52] = 0;
   out_3934539972733810872[53] = 0;
   out_3934539972733810872[54] = 0;
   out_3934539972733810872[55] = 0;
   out_3934539972733810872[56] = 0;
   out_3934539972733810872[57] = 1;
   out_3934539972733810872[58] = 0;
   out_3934539972733810872[59] = 0;
   out_3934539972733810872[60] = 0;
   out_3934539972733810872[61] = 0;
   out_3934539972733810872[62] = 0;
   out_3934539972733810872[63] = 0;
   out_3934539972733810872[64] = 0;
   out_3934539972733810872[65] = 0;
   out_3934539972733810872[66] = dt;
   out_3934539972733810872[67] = 0;
   out_3934539972733810872[68] = 0;
   out_3934539972733810872[69] = 0;
   out_3934539972733810872[70] = 0;
   out_3934539972733810872[71] = 0;
   out_3934539972733810872[72] = 0;
   out_3934539972733810872[73] = 0;
   out_3934539972733810872[74] = 0;
   out_3934539972733810872[75] = 0;
   out_3934539972733810872[76] = 1;
   out_3934539972733810872[77] = 0;
   out_3934539972733810872[78] = 0;
   out_3934539972733810872[79] = 0;
   out_3934539972733810872[80] = 0;
   out_3934539972733810872[81] = 0;
   out_3934539972733810872[82] = 0;
   out_3934539972733810872[83] = 0;
   out_3934539972733810872[84] = 0;
   out_3934539972733810872[85] = dt;
   out_3934539972733810872[86] = 0;
   out_3934539972733810872[87] = 0;
   out_3934539972733810872[88] = 0;
   out_3934539972733810872[89] = 0;
   out_3934539972733810872[90] = 0;
   out_3934539972733810872[91] = 0;
   out_3934539972733810872[92] = 0;
   out_3934539972733810872[93] = 0;
   out_3934539972733810872[94] = 0;
   out_3934539972733810872[95] = 1;
   out_3934539972733810872[96] = 0;
   out_3934539972733810872[97] = 0;
   out_3934539972733810872[98] = 0;
   out_3934539972733810872[99] = 0;
   out_3934539972733810872[100] = 0;
   out_3934539972733810872[101] = 0;
   out_3934539972733810872[102] = 0;
   out_3934539972733810872[103] = 0;
   out_3934539972733810872[104] = dt;
   out_3934539972733810872[105] = 0;
   out_3934539972733810872[106] = 0;
   out_3934539972733810872[107] = 0;
   out_3934539972733810872[108] = 0;
   out_3934539972733810872[109] = 0;
   out_3934539972733810872[110] = 0;
   out_3934539972733810872[111] = 0;
   out_3934539972733810872[112] = 0;
   out_3934539972733810872[113] = 0;
   out_3934539972733810872[114] = 1;
   out_3934539972733810872[115] = 0;
   out_3934539972733810872[116] = 0;
   out_3934539972733810872[117] = 0;
   out_3934539972733810872[118] = 0;
   out_3934539972733810872[119] = 0;
   out_3934539972733810872[120] = 0;
   out_3934539972733810872[121] = 0;
   out_3934539972733810872[122] = 0;
   out_3934539972733810872[123] = 0;
   out_3934539972733810872[124] = 0;
   out_3934539972733810872[125] = 0;
   out_3934539972733810872[126] = 0;
   out_3934539972733810872[127] = 0;
   out_3934539972733810872[128] = 0;
   out_3934539972733810872[129] = 0;
   out_3934539972733810872[130] = 0;
   out_3934539972733810872[131] = 0;
   out_3934539972733810872[132] = 0;
   out_3934539972733810872[133] = 1;
   out_3934539972733810872[134] = 0;
   out_3934539972733810872[135] = 0;
   out_3934539972733810872[136] = 0;
   out_3934539972733810872[137] = 0;
   out_3934539972733810872[138] = 0;
   out_3934539972733810872[139] = 0;
   out_3934539972733810872[140] = 0;
   out_3934539972733810872[141] = 0;
   out_3934539972733810872[142] = 0;
   out_3934539972733810872[143] = 0;
   out_3934539972733810872[144] = 0;
   out_3934539972733810872[145] = 0;
   out_3934539972733810872[146] = 0;
   out_3934539972733810872[147] = 0;
   out_3934539972733810872[148] = 0;
   out_3934539972733810872[149] = 0;
   out_3934539972733810872[150] = 0;
   out_3934539972733810872[151] = 0;
   out_3934539972733810872[152] = 1;
   out_3934539972733810872[153] = 0;
   out_3934539972733810872[154] = 0;
   out_3934539972733810872[155] = 0;
   out_3934539972733810872[156] = 0;
   out_3934539972733810872[157] = 0;
   out_3934539972733810872[158] = 0;
   out_3934539972733810872[159] = 0;
   out_3934539972733810872[160] = 0;
   out_3934539972733810872[161] = 0;
   out_3934539972733810872[162] = 0;
   out_3934539972733810872[163] = 0;
   out_3934539972733810872[164] = 0;
   out_3934539972733810872[165] = 0;
   out_3934539972733810872[166] = 0;
   out_3934539972733810872[167] = 0;
   out_3934539972733810872[168] = 0;
   out_3934539972733810872[169] = 0;
   out_3934539972733810872[170] = 0;
   out_3934539972733810872[171] = 1;
   out_3934539972733810872[172] = 0;
   out_3934539972733810872[173] = 0;
   out_3934539972733810872[174] = 0;
   out_3934539972733810872[175] = 0;
   out_3934539972733810872[176] = 0;
   out_3934539972733810872[177] = 0;
   out_3934539972733810872[178] = 0;
   out_3934539972733810872[179] = 0;
   out_3934539972733810872[180] = 0;
   out_3934539972733810872[181] = 0;
   out_3934539972733810872[182] = 0;
   out_3934539972733810872[183] = 0;
   out_3934539972733810872[184] = 0;
   out_3934539972733810872[185] = 0;
   out_3934539972733810872[186] = 0;
   out_3934539972733810872[187] = 0;
   out_3934539972733810872[188] = 0;
   out_3934539972733810872[189] = 0;
   out_3934539972733810872[190] = 1;
   out_3934539972733810872[191] = 0;
   out_3934539972733810872[192] = 0;
   out_3934539972733810872[193] = 0;
   out_3934539972733810872[194] = 0;
   out_3934539972733810872[195] = 0;
   out_3934539972733810872[196] = 0;
   out_3934539972733810872[197] = 0;
   out_3934539972733810872[198] = 0;
   out_3934539972733810872[199] = 0;
   out_3934539972733810872[200] = 0;
   out_3934539972733810872[201] = 0;
   out_3934539972733810872[202] = 0;
   out_3934539972733810872[203] = 0;
   out_3934539972733810872[204] = 0;
   out_3934539972733810872[205] = 0;
   out_3934539972733810872[206] = 0;
   out_3934539972733810872[207] = 0;
   out_3934539972733810872[208] = 0;
   out_3934539972733810872[209] = 1;
   out_3934539972733810872[210] = 0;
   out_3934539972733810872[211] = 0;
   out_3934539972733810872[212] = 0;
   out_3934539972733810872[213] = 0;
   out_3934539972733810872[214] = 0;
   out_3934539972733810872[215] = 0;
   out_3934539972733810872[216] = 0;
   out_3934539972733810872[217] = 0;
   out_3934539972733810872[218] = 0;
   out_3934539972733810872[219] = 0;
   out_3934539972733810872[220] = 0;
   out_3934539972733810872[221] = 0;
   out_3934539972733810872[222] = 0;
   out_3934539972733810872[223] = 0;
   out_3934539972733810872[224] = 0;
   out_3934539972733810872[225] = 0;
   out_3934539972733810872[226] = 0;
   out_3934539972733810872[227] = 0;
   out_3934539972733810872[228] = 1;
   out_3934539972733810872[229] = 0;
   out_3934539972733810872[230] = 0;
   out_3934539972733810872[231] = 0;
   out_3934539972733810872[232] = 0;
   out_3934539972733810872[233] = 0;
   out_3934539972733810872[234] = 0;
   out_3934539972733810872[235] = 0;
   out_3934539972733810872[236] = 0;
   out_3934539972733810872[237] = 0;
   out_3934539972733810872[238] = 0;
   out_3934539972733810872[239] = 0;
   out_3934539972733810872[240] = 0;
   out_3934539972733810872[241] = 0;
   out_3934539972733810872[242] = 0;
   out_3934539972733810872[243] = 0;
   out_3934539972733810872[244] = 0;
   out_3934539972733810872[245] = 0;
   out_3934539972733810872[246] = 0;
   out_3934539972733810872[247] = 1;
   out_3934539972733810872[248] = 0;
   out_3934539972733810872[249] = 0;
   out_3934539972733810872[250] = 0;
   out_3934539972733810872[251] = 0;
   out_3934539972733810872[252] = 0;
   out_3934539972733810872[253] = 0;
   out_3934539972733810872[254] = 0;
   out_3934539972733810872[255] = 0;
   out_3934539972733810872[256] = 0;
   out_3934539972733810872[257] = 0;
   out_3934539972733810872[258] = 0;
   out_3934539972733810872[259] = 0;
   out_3934539972733810872[260] = 0;
   out_3934539972733810872[261] = 0;
   out_3934539972733810872[262] = 0;
   out_3934539972733810872[263] = 0;
   out_3934539972733810872[264] = 0;
   out_3934539972733810872[265] = 0;
   out_3934539972733810872[266] = 1;
   out_3934539972733810872[267] = 0;
   out_3934539972733810872[268] = 0;
   out_3934539972733810872[269] = 0;
   out_3934539972733810872[270] = 0;
   out_3934539972733810872[271] = 0;
   out_3934539972733810872[272] = 0;
   out_3934539972733810872[273] = 0;
   out_3934539972733810872[274] = 0;
   out_3934539972733810872[275] = 0;
   out_3934539972733810872[276] = 0;
   out_3934539972733810872[277] = 0;
   out_3934539972733810872[278] = 0;
   out_3934539972733810872[279] = 0;
   out_3934539972733810872[280] = 0;
   out_3934539972733810872[281] = 0;
   out_3934539972733810872[282] = 0;
   out_3934539972733810872[283] = 0;
   out_3934539972733810872[284] = 0;
   out_3934539972733810872[285] = 1;
   out_3934539972733810872[286] = 0;
   out_3934539972733810872[287] = 0;
   out_3934539972733810872[288] = 0;
   out_3934539972733810872[289] = 0;
   out_3934539972733810872[290] = 0;
   out_3934539972733810872[291] = 0;
   out_3934539972733810872[292] = 0;
   out_3934539972733810872[293] = 0;
   out_3934539972733810872[294] = 0;
   out_3934539972733810872[295] = 0;
   out_3934539972733810872[296] = 0;
   out_3934539972733810872[297] = 0;
   out_3934539972733810872[298] = 0;
   out_3934539972733810872[299] = 0;
   out_3934539972733810872[300] = 0;
   out_3934539972733810872[301] = 0;
   out_3934539972733810872[302] = 0;
   out_3934539972733810872[303] = 0;
   out_3934539972733810872[304] = 1;
   out_3934539972733810872[305] = 0;
   out_3934539972733810872[306] = 0;
   out_3934539972733810872[307] = 0;
   out_3934539972733810872[308] = 0;
   out_3934539972733810872[309] = 0;
   out_3934539972733810872[310] = 0;
   out_3934539972733810872[311] = 0;
   out_3934539972733810872[312] = 0;
   out_3934539972733810872[313] = 0;
   out_3934539972733810872[314] = 0;
   out_3934539972733810872[315] = 0;
   out_3934539972733810872[316] = 0;
   out_3934539972733810872[317] = 0;
   out_3934539972733810872[318] = 0;
   out_3934539972733810872[319] = 0;
   out_3934539972733810872[320] = 0;
   out_3934539972733810872[321] = 0;
   out_3934539972733810872[322] = 0;
   out_3934539972733810872[323] = 1;
}
void h_4(double *state, double *unused, double *out_9108176221739377223) {
   out_9108176221739377223[0] = state[6] + state[9];
   out_9108176221739377223[1] = state[7] + state[10];
   out_9108176221739377223[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3529932076716150864) {
   out_3529932076716150864[0] = 0;
   out_3529932076716150864[1] = 0;
   out_3529932076716150864[2] = 0;
   out_3529932076716150864[3] = 0;
   out_3529932076716150864[4] = 0;
   out_3529932076716150864[5] = 0;
   out_3529932076716150864[6] = 1;
   out_3529932076716150864[7] = 0;
   out_3529932076716150864[8] = 0;
   out_3529932076716150864[9] = 1;
   out_3529932076716150864[10] = 0;
   out_3529932076716150864[11] = 0;
   out_3529932076716150864[12] = 0;
   out_3529932076716150864[13] = 0;
   out_3529932076716150864[14] = 0;
   out_3529932076716150864[15] = 0;
   out_3529932076716150864[16] = 0;
   out_3529932076716150864[17] = 0;
   out_3529932076716150864[18] = 0;
   out_3529932076716150864[19] = 0;
   out_3529932076716150864[20] = 0;
   out_3529932076716150864[21] = 0;
   out_3529932076716150864[22] = 0;
   out_3529932076716150864[23] = 0;
   out_3529932076716150864[24] = 0;
   out_3529932076716150864[25] = 1;
   out_3529932076716150864[26] = 0;
   out_3529932076716150864[27] = 0;
   out_3529932076716150864[28] = 1;
   out_3529932076716150864[29] = 0;
   out_3529932076716150864[30] = 0;
   out_3529932076716150864[31] = 0;
   out_3529932076716150864[32] = 0;
   out_3529932076716150864[33] = 0;
   out_3529932076716150864[34] = 0;
   out_3529932076716150864[35] = 0;
   out_3529932076716150864[36] = 0;
   out_3529932076716150864[37] = 0;
   out_3529932076716150864[38] = 0;
   out_3529932076716150864[39] = 0;
   out_3529932076716150864[40] = 0;
   out_3529932076716150864[41] = 0;
   out_3529932076716150864[42] = 0;
   out_3529932076716150864[43] = 0;
   out_3529932076716150864[44] = 1;
   out_3529932076716150864[45] = 0;
   out_3529932076716150864[46] = 0;
   out_3529932076716150864[47] = 1;
   out_3529932076716150864[48] = 0;
   out_3529932076716150864[49] = 0;
   out_3529932076716150864[50] = 0;
   out_3529932076716150864[51] = 0;
   out_3529932076716150864[52] = 0;
   out_3529932076716150864[53] = 0;
}
void h_10(double *state, double *unused, double *out_7468804800035159097) {
   out_7468804800035159097[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7468804800035159097[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7468804800035159097[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3178743347505224989) {
   out_3178743347505224989[0] = 0;
   out_3178743347505224989[1] = 9.8100000000000005*cos(state[1]);
   out_3178743347505224989[2] = 0;
   out_3178743347505224989[3] = 0;
   out_3178743347505224989[4] = -state[8];
   out_3178743347505224989[5] = state[7];
   out_3178743347505224989[6] = 0;
   out_3178743347505224989[7] = state[5];
   out_3178743347505224989[8] = -state[4];
   out_3178743347505224989[9] = 0;
   out_3178743347505224989[10] = 0;
   out_3178743347505224989[11] = 0;
   out_3178743347505224989[12] = 1;
   out_3178743347505224989[13] = 0;
   out_3178743347505224989[14] = 0;
   out_3178743347505224989[15] = 1;
   out_3178743347505224989[16] = 0;
   out_3178743347505224989[17] = 0;
   out_3178743347505224989[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3178743347505224989[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3178743347505224989[20] = 0;
   out_3178743347505224989[21] = state[8];
   out_3178743347505224989[22] = 0;
   out_3178743347505224989[23] = -state[6];
   out_3178743347505224989[24] = -state[5];
   out_3178743347505224989[25] = 0;
   out_3178743347505224989[26] = state[3];
   out_3178743347505224989[27] = 0;
   out_3178743347505224989[28] = 0;
   out_3178743347505224989[29] = 0;
   out_3178743347505224989[30] = 0;
   out_3178743347505224989[31] = 1;
   out_3178743347505224989[32] = 0;
   out_3178743347505224989[33] = 0;
   out_3178743347505224989[34] = 1;
   out_3178743347505224989[35] = 0;
   out_3178743347505224989[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3178743347505224989[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3178743347505224989[38] = 0;
   out_3178743347505224989[39] = -state[7];
   out_3178743347505224989[40] = state[6];
   out_3178743347505224989[41] = 0;
   out_3178743347505224989[42] = state[4];
   out_3178743347505224989[43] = -state[3];
   out_3178743347505224989[44] = 0;
   out_3178743347505224989[45] = 0;
   out_3178743347505224989[46] = 0;
   out_3178743347505224989[47] = 0;
   out_3178743347505224989[48] = 0;
   out_3178743347505224989[49] = 0;
   out_3178743347505224989[50] = 1;
   out_3178743347505224989[51] = 0;
   out_3178743347505224989[52] = 0;
   out_3178743347505224989[53] = 1;
}
void h_13(double *state, double *unused, double *out_2582510020496882256) {
   out_2582510020496882256[0] = state[3];
   out_2582510020496882256[1] = state[4];
   out_2582510020496882256[2] = state[5];
}
void H_13(double *state, double *unused, double *out_317658251383818063) {
   out_317658251383818063[0] = 0;
   out_317658251383818063[1] = 0;
   out_317658251383818063[2] = 0;
   out_317658251383818063[3] = 1;
   out_317658251383818063[4] = 0;
   out_317658251383818063[5] = 0;
   out_317658251383818063[6] = 0;
   out_317658251383818063[7] = 0;
   out_317658251383818063[8] = 0;
   out_317658251383818063[9] = 0;
   out_317658251383818063[10] = 0;
   out_317658251383818063[11] = 0;
   out_317658251383818063[12] = 0;
   out_317658251383818063[13] = 0;
   out_317658251383818063[14] = 0;
   out_317658251383818063[15] = 0;
   out_317658251383818063[16] = 0;
   out_317658251383818063[17] = 0;
   out_317658251383818063[18] = 0;
   out_317658251383818063[19] = 0;
   out_317658251383818063[20] = 0;
   out_317658251383818063[21] = 0;
   out_317658251383818063[22] = 1;
   out_317658251383818063[23] = 0;
   out_317658251383818063[24] = 0;
   out_317658251383818063[25] = 0;
   out_317658251383818063[26] = 0;
   out_317658251383818063[27] = 0;
   out_317658251383818063[28] = 0;
   out_317658251383818063[29] = 0;
   out_317658251383818063[30] = 0;
   out_317658251383818063[31] = 0;
   out_317658251383818063[32] = 0;
   out_317658251383818063[33] = 0;
   out_317658251383818063[34] = 0;
   out_317658251383818063[35] = 0;
   out_317658251383818063[36] = 0;
   out_317658251383818063[37] = 0;
   out_317658251383818063[38] = 0;
   out_317658251383818063[39] = 0;
   out_317658251383818063[40] = 0;
   out_317658251383818063[41] = 1;
   out_317658251383818063[42] = 0;
   out_317658251383818063[43] = 0;
   out_317658251383818063[44] = 0;
   out_317658251383818063[45] = 0;
   out_317658251383818063[46] = 0;
   out_317658251383818063[47] = 0;
   out_317658251383818063[48] = 0;
   out_317658251383818063[49] = 0;
   out_317658251383818063[50] = 0;
   out_317658251383818063[51] = 0;
   out_317658251383818063[52] = 0;
   out_317658251383818063[53] = 0;
}
void h_14(double *state, double *unused, double *out_7414566035535505034) {
   out_7414566035535505034[0] = state[6];
   out_7414566035535505034[1] = state[7];
   out_7414566035535505034[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6612720509011523160) {
   out_6612720509011523160[0] = 0;
   out_6612720509011523160[1] = 0;
   out_6612720509011523160[2] = 0;
   out_6612720509011523160[3] = 0;
   out_6612720509011523160[4] = 0;
   out_6612720509011523160[5] = 0;
   out_6612720509011523160[6] = 1;
   out_6612720509011523160[7] = 0;
   out_6612720509011523160[8] = 0;
   out_6612720509011523160[9] = 0;
   out_6612720509011523160[10] = 0;
   out_6612720509011523160[11] = 0;
   out_6612720509011523160[12] = 0;
   out_6612720509011523160[13] = 0;
   out_6612720509011523160[14] = 0;
   out_6612720509011523160[15] = 0;
   out_6612720509011523160[16] = 0;
   out_6612720509011523160[17] = 0;
   out_6612720509011523160[18] = 0;
   out_6612720509011523160[19] = 0;
   out_6612720509011523160[20] = 0;
   out_6612720509011523160[21] = 0;
   out_6612720509011523160[22] = 0;
   out_6612720509011523160[23] = 0;
   out_6612720509011523160[24] = 0;
   out_6612720509011523160[25] = 1;
   out_6612720509011523160[26] = 0;
   out_6612720509011523160[27] = 0;
   out_6612720509011523160[28] = 0;
   out_6612720509011523160[29] = 0;
   out_6612720509011523160[30] = 0;
   out_6612720509011523160[31] = 0;
   out_6612720509011523160[32] = 0;
   out_6612720509011523160[33] = 0;
   out_6612720509011523160[34] = 0;
   out_6612720509011523160[35] = 0;
   out_6612720509011523160[36] = 0;
   out_6612720509011523160[37] = 0;
   out_6612720509011523160[38] = 0;
   out_6612720509011523160[39] = 0;
   out_6612720509011523160[40] = 0;
   out_6612720509011523160[41] = 0;
   out_6612720509011523160[42] = 0;
   out_6612720509011523160[43] = 0;
   out_6612720509011523160[44] = 1;
   out_6612720509011523160[45] = 0;
   out_6612720509011523160[46] = 0;
   out_6612720509011523160[47] = 0;
   out_6612720509011523160[48] = 0;
   out_6612720509011523160[49] = 0;
   out_6612720509011523160[50] = 0;
   out_6612720509011523160[51] = 0;
   out_6612720509011523160[52] = 0;
   out_6612720509011523160[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7431505958311813382) {
  err_fun(nom_x, delta_x, out_7431505958311813382);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8551627000098797431) {
  inv_err_fun(nom_x, true_x, out_8551627000098797431);
}
void pose_H_mod_fun(double *state, double *out_4284093078770863471) {
  H_mod_fun(state, out_4284093078770863471);
}
void pose_f_fun(double *state, double dt, double *out_6442140298881834415) {
  f_fun(state,  dt, out_6442140298881834415);
}
void pose_F_fun(double *state, double dt, double *out_3934539972733810872) {
  F_fun(state,  dt, out_3934539972733810872);
}
void pose_h_4(double *state, double *unused, double *out_9108176221739377223) {
  h_4(state, unused, out_9108176221739377223);
}
void pose_H_4(double *state, double *unused, double *out_3529932076716150864) {
  H_4(state, unused, out_3529932076716150864);
}
void pose_h_10(double *state, double *unused, double *out_7468804800035159097) {
  h_10(state, unused, out_7468804800035159097);
}
void pose_H_10(double *state, double *unused, double *out_3178743347505224989) {
  H_10(state, unused, out_3178743347505224989);
}
void pose_h_13(double *state, double *unused, double *out_2582510020496882256) {
  h_13(state, unused, out_2582510020496882256);
}
void pose_H_13(double *state, double *unused, double *out_317658251383818063) {
  H_13(state, unused, out_317658251383818063);
}
void pose_h_14(double *state, double *unused, double *out_7414566035535505034) {
  h_14(state, unused, out_7414566035535505034);
}
void pose_H_14(double *state, double *unused, double *out_6612720509011523160) {
  H_14(state, unused, out_6612720509011523160);
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
