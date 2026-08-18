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
void err_fun(double *nom_x, double *delta_x, double *out_8334628911363265031) {
   out_8334628911363265031[0] = delta_x[0] + nom_x[0];
   out_8334628911363265031[1] = delta_x[1] + nom_x[1];
   out_8334628911363265031[2] = delta_x[2] + nom_x[2];
   out_8334628911363265031[3] = delta_x[3] + nom_x[3];
   out_8334628911363265031[4] = delta_x[4] + nom_x[4];
   out_8334628911363265031[5] = delta_x[5] + nom_x[5];
   out_8334628911363265031[6] = delta_x[6] + nom_x[6];
   out_8334628911363265031[7] = delta_x[7] + nom_x[7];
   out_8334628911363265031[8] = delta_x[8] + nom_x[8];
   out_8334628911363265031[9] = delta_x[9] + nom_x[9];
   out_8334628911363265031[10] = delta_x[10] + nom_x[10];
   out_8334628911363265031[11] = delta_x[11] + nom_x[11];
   out_8334628911363265031[12] = delta_x[12] + nom_x[12];
   out_8334628911363265031[13] = delta_x[13] + nom_x[13];
   out_8334628911363265031[14] = delta_x[14] + nom_x[14];
   out_8334628911363265031[15] = delta_x[15] + nom_x[15];
   out_8334628911363265031[16] = delta_x[16] + nom_x[16];
   out_8334628911363265031[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6557509511038369963) {
   out_6557509511038369963[0] = -nom_x[0] + true_x[0];
   out_6557509511038369963[1] = -nom_x[1] + true_x[1];
   out_6557509511038369963[2] = -nom_x[2] + true_x[2];
   out_6557509511038369963[3] = -nom_x[3] + true_x[3];
   out_6557509511038369963[4] = -nom_x[4] + true_x[4];
   out_6557509511038369963[5] = -nom_x[5] + true_x[5];
   out_6557509511038369963[6] = -nom_x[6] + true_x[6];
   out_6557509511038369963[7] = -nom_x[7] + true_x[7];
   out_6557509511038369963[8] = -nom_x[8] + true_x[8];
   out_6557509511038369963[9] = -nom_x[9] + true_x[9];
   out_6557509511038369963[10] = -nom_x[10] + true_x[10];
   out_6557509511038369963[11] = -nom_x[11] + true_x[11];
   out_6557509511038369963[12] = -nom_x[12] + true_x[12];
   out_6557509511038369963[13] = -nom_x[13] + true_x[13];
   out_6557509511038369963[14] = -nom_x[14] + true_x[14];
   out_6557509511038369963[15] = -nom_x[15] + true_x[15];
   out_6557509511038369963[16] = -nom_x[16] + true_x[16];
   out_6557509511038369963[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2207458853057691014) {
   out_2207458853057691014[0] = 1.0;
   out_2207458853057691014[1] = 0.0;
   out_2207458853057691014[2] = 0.0;
   out_2207458853057691014[3] = 0.0;
   out_2207458853057691014[4] = 0.0;
   out_2207458853057691014[5] = 0.0;
   out_2207458853057691014[6] = 0.0;
   out_2207458853057691014[7] = 0.0;
   out_2207458853057691014[8] = 0.0;
   out_2207458853057691014[9] = 0.0;
   out_2207458853057691014[10] = 0.0;
   out_2207458853057691014[11] = 0.0;
   out_2207458853057691014[12] = 0.0;
   out_2207458853057691014[13] = 0.0;
   out_2207458853057691014[14] = 0.0;
   out_2207458853057691014[15] = 0.0;
   out_2207458853057691014[16] = 0.0;
   out_2207458853057691014[17] = 0.0;
   out_2207458853057691014[18] = 0.0;
   out_2207458853057691014[19] = 1.0;
   out_2207458853057691014[20] = 0.0;
   out_2207458853057691014[21] = 0.0;
   out_2207458853057691014[22] = 0.0;
   out_2207458853057691014[23] = 0.0;
   out_2207458853057691014[24] = 0.0;
   out_2207458853057691014[25] = 0.0;
   out_2207458853057691014[26] = 0.0;
   out_2207458853057691014[27] = 0.0;
   out_2207458853057691014[28] = 0.0;
   out_2207458853057691014[29] = 0.0;
   out_2207458853057691014[30] = 0.0;
   out_2207458853057691014[31] = 0.0;
   out_2207458853057691014[32] = 0.0;
   out_2207458853057691014[33] = 0.0;
   out_2207458853057691014[34] = 0.0;
   out_2207458853057691014[35] = 0.0;
   out_2207458853057691014[36] = 0.0;
   out_2207458853057691014[37] = 0.0;
   out_2207458853057691014[38] = 1.0;
   out_2207458853057691014[39] = 0.0;
   out_2207458853057691014[40] = 0.0;
   out_2207458853057691014[41] = 0.0;
   out_2207458853057691014[42] = 0.0;
   out_2207458853057691014[43] = 0.0;
   out_2207458853057691014[44] = 0.0;
   out_2207458853057691014[45] = 0.0;
   out_2207458853057691014[46] = 0.0;
   out_2207458853057691014[47] = 0.0;
   out_2207458853057691014[48] = 0.0;
   out_2207458853057691014[49] = 0.0;
   out_2207458853057691014[50] = 0.0;
   out_2207458853057691014[51] = 0.0;
   out_2207458853057691014[52] = 0.0;
   out_2207458853057691014[53] = 0.0;
   out_2207458853057691014[54] = 0.0;
   out_2207458853057691014[55] = 0.0;
   out_2207458853057691014[56] = 0.0;
   out_2207458853057691014[57] = 1.0;
   out_2207458853057691014[58] = 0.0;
   out_2207458853057691014[59] = 0.0;
   out_2207458853057691014[60] = 0.0;
   out_2207458853057691014[61] = 0.0;
   out_2207458853057691014[62] = 0.0;
   out_2207458853057691014[63] = 0.0;
   out_2207458853057691014[64] = 0.0;
   out_2207458853057691014[65] = 0.0;
   out_2207458853057691014[66] = 0.0;
   out_2207458853057691014[67] = 0.0;
   out_2207458853057691014[68] = 0.0;
   out_2207458853057691014[69] = 0.0;
   out_2207458853057691014[70] = 0.0;
   out_2207458853057691014[71] = 0.0;
   out_2207458853057691014[72] = 0.0;
   out_2207458853057691014[73] = 0.0;
   out_2207458853057691014[74] = 0.0;
   out_2207458853057691014[75] = 0.0;
   out_2207458853057691014[76] = 1.0;
   out_2207458853057691014[77] = 0.0;
   out_2207458853057691014[78] = 0.0;
   out_2207458853057691014[79] = 0.0;
   out_2207458853057691014[80] = 0.0;
   out_2207458853057691014[81] = 0.0;
   out_2207458853057691014[82] = 0.0;
   out_2207458853057691014[83] = 0.0;
   out_2207458853057691014[84] = 0.0;
   out_2207458853057691014[85] = 0.0;
   out_2207458853057691014[86] = 0.0;
   out_2207458853057691014[87] = 0.0;
   out_2207458853057691014[88] = 0.0;
   out_2207458853057691014[89] = 0.0;
   out_2207458853057691014[90] = 0.0;
   out_2207458853057691014[91] = 0.0;
   out_2207458853057691014[92] = 0.0;
   out_2207458853057691014[93] = 0.0;
   out_2207458853057691014[94] = 0.0;
   out_2207458853057691014[95] = 1.0;
   out_2207458853057691014[96] = 0.0;
   out_2207458853057691014[97] = 0.0;
   out_2207458853057691014[98] = 0.0;
   out_2207458853057691014[99] = 0.0;
   out_2207458853057691014[100] = 0.0;
   out_2207458853057691014[101] = 0.0;
   out_2207458853057691014[102] = 0.0;
   out_2207458853057691014[103] = 0.0;
   out_2207458853057691014[104] = 0.0;
   out_2207458853057691014[105] = 0.0;
   out_2207458853057691014[106] = 0.0;
   out_2207458853057691014[107] = 0.0;
   out_2207458853057691014[108] = 0.0;
   out_2207458853057691014[109] = 0.0;
   out_2207458853057691014[110] = 0.0;
   out_2207458853057691014[111] = 0.0;
   out_2207458853057691014[112] = 0.0;
   out_2207458853057691014[113] = 0.0;
   out_2207458853057691014[114] = 1.0;
   out_2207458853057691014[115] = 0.0;
   out_2207458853057691014[116] = 0.0;
   out_2207458853057691014[117] = 0.0;
   out_2207458853057691014[118] = 0.0;
   out_2207458853057691014[119] = 0.0;
   out_2207458853057691014[120] = 0.0;
   out_2207458853057691014[121] = 0.0;
   out_2207458853057691014[122] = 0.0;
   out_2207458853057691014[123] = 0.0;
   out_2207458853057691014[124] = 0.0;
   out_2207458853057691014[125] = 0.0;
   out_2207458853057691014[126] = 0.0;
   out_2207458853057691014[127] = 0.0;
   out_2207458853057691014[128] = 0.0;
   out_2207458853057691014[129] = 0.0;
   out_2207458853057691014[130] = 0.0;
   out_2207458853057691014[131] = 0.0;
   out_2207458853057691014[132] = 0.0;
   out_2207458853057691014[133] = 1.0;
   out_2207458853057691014[134] = 0.0;
   out_2207458853057691014[135] = 0.0;
   out_2207458853057691014[136] = 0.0;
   out_2207458853057691014[137] = 0.0;
   out_2207458853057691014[138] = 0.0;
   out_2207458853057691014[139] = 0.0;
   out_2207458853057691014[140] = 0.0;
   out_2207458853057691014[141] = 0.0;
   out_2207458853057691014[142] = 0.0;
   out_2207458853057691014[143] = 0.0;
   out_2207458853057691014[144] = 0.0;
   out_2207458853057691014[145] = 0.0;
   out_2207458853057691014[146] = 0.0;
   out_2207458853057691014[147] = 0.0;
   out_2207458853057691014[148] = 0.0;
   out_2207458853057691014[149] = 0.0;
   out_2207458853057691014[150] = 0.0;
   out_2207458853057691014[151] = 0.0;
   out_2207458853057691014[152] = 1.0;
   out_2207458853057691014[153] = 0.0;
   out_2207458853057691014[154] = 0.0;
   out_2207458853057691014[155] = 0.0;
   out_2207458853057691014[156] = 0.0;
   out_2207458853057691014[157] = 0.0;
   out_2207458853057691014[158] = 0.0;
   out_2207458853057691014[159] = 0.0;
   out_2207458853057691014[160] = 0.0;
   out_2207458853057691014[161] = 0.0;
   out_2207458853057691014[162] = 0.0;
   out_2207458853057691014[163] = 0.0;
   out_2207458853057691014[164] = 0.0;
   out_2207458853057691014[165] = 0.0;
   out_2207458853057691014[166] = 0.0;
   out_2207458853057691014[167] = 0.0;
   out_2207458853057691014[168] = 0.0;
   out_2207458853057691014[169] = 0.0;
   out_2207458853057691014[170] = 0.0;
   out_2207458853057691014[171] = 1.0;
   out_2207458853057691014[172] = 0.0;
   out_2207458853057691014[173] = 0.0;
   out_2207458853057691014[174] = 0.0;
   out_2207458853057691014[175] = 0.0;
   out_2207458853057691014[176] = 0.0;
   out_2207458853057691014[177] = 0.0;
   out_2207458853057691014[178] = 0.0;
   out_2207458853057691014[179] = 0.0;
   out_2207458853057691014[180] = 0.0;
   out_2207458853057691014[181] = 0.0;
   out_2207458853057691014[182] = 0.0;
   out_2207458853057691014[183] = 0.0;
   out_2207458853057691014[184] = 0.0;
   out_2207458853057691014[185] = 0.0;
   out_2207458853057691014[186] = 0.0;
   out_2207458853057691014[187] = 0.0;
   out_2207458853057691014[188] = 0.0;
   out_2207458853057691014[189] = 0.0;
   out_2207458853057691014[190] = 1.0;
   out_2207458853057691014[191] = 0.0;
   out_2207458853057691014[192] = 0.0;
   out_2207458853057691014[193] = 0.0;
   out_2207458853057691014[194] = 0.0;
   out_2207458853057691014[195] = 0.0;
   out_2207458853057691014[196] = 0.0;
   out_2207458853057691014[197] = 0.0;
   out_2207458853057691014[198] = 0.0;
   out_2207458853057691014[199] = 0.0;
   out_2207458853057691014[200] = 0.0;
   out_2207458853057691014[201] = 0.0;
   out_2207458853057691014[202] = 0.0;
   out_2207458853057691014[203] = 0.0;
   out_2207458853057691014[204] = 0.0;
   out_2207458853057691014[205] = 0.0;
   out_2207458853057691014[206] = 0.0;
   out_2207458853057691014[207] = 0.0;
   out_2207458853057691014[208] = 0.0;
   out_2207458853057691014[209] = 1.0;
   out_2207458853057691014[210] = 0.0;
   out_2207458853057691014[211] = 0.0;
   out_2207458853057691014[212] = 0.0;
   out_2207458853057691014[213] = 0.0;
   out_2207458853057691014[214] = 0.0;
   out_2207458853057691014[215] = 0.0;
   out_2207458853057691014[216] = 0.0;
   out_2207458853057691014[217] = 0.0;
   out_2207458853057691014[218] = 0.0;
   out_2207458853057691014[219] = 0.0;
   out_2207458853057691014[220] = 0.0;
   out_2207458853057691014[221] = 0.0;
   out_2207458853057691014[222] = 0.0;
   out_2207458853057691014[223] = 0.0;
   out_2207458853057691014[224] = 0.0;
   out_2207458853057691014[225] = 0.0;
   out_2207458853057691014[226] = 0.0;
   out_2207458853057691014[227] = 0.0;
   out_2207458853057691014[228] = 1.0;
   out_2207458853057691014[229] = 0.0;
   out_2207458853057691014[230] = 0.0;
   out_2207458853057691014[231] = 0.0;
   out_2207458853057691014[232] = 0.0;
   out_2207458853057691014[233] = 0.0;
   out_2207458853057691014[234] = 0.0;
   out_2207458853057691014[235] = 0.0;
   out_2207458853057691014[236] = 0.0;
   out_2207458853057691014[237] = 0.0;
   out_2207458853057691014[238] = 0.0;
   out_2207458853057691014[239] = 0.0;
   out_2207458853057691014[240] = 0.0;
   out_2207458853057691014[241] = 0.0;
   out_2207458853057691014[242] = 0.0;
   out_2207458853057691014[243] = 0.0;
   out_2207458853057691014[244] = 0.0;
   out_2207458853057691014[245] = 0.0;
   out_2207458853057691014[246] = 0.0;
   out_2207458853057691014[247] = 1.0;
   out_2207458853057691014[248] = 0.0;
   out_2207458853057691014[249] = 0.0;
   out_2207458853057691014[250] = 0.0;
   out_2207458853057691014[251] = 0.0;
   out_2207458853057691014[252] = 0.0;
   out_2207458853057691014[253] = 0.0;
   out_2207458853057691014[254] = 0.0;
   out_2207458853057691014[255] = 0.0;
   out_2207458853057691014[256] = 0.0;
   out_2207458853057691014[257] = 0.0;
   out_2207458853057691014[258] = 0.0;
   out_2207458853057691014[259] = 0.0;
   out_2207458853057691014[260] = 0.0;
   out_2207458853057691014[261] = 0.0;
   out_2207458853057691014[262] = 0.0;
   out_2207458853057691014[263] = 0.0;
   out_2207458853057691014[264] = 0.0;
   out_2207458853057691014[265] = 0.0;
   out_2207458853057691014[266] = 1.0;
   out_2207458853057691014[267] = 0.0;
   out_2207458853057691014[268] = 0.0;
   out_2207458853057691014[269] = 0.0;
   out_2207458853057691014[270] = 0.0;
   out_2207458853057691014[271] = 0.0;
   out_2207458853057691014[272] = 0.0;
   out_2207458853057691014[273] = 0.0;
   out_2207458853057691014[274] = 0.0;
   out_2207458853057691014[275] = 0.0;
   out_2207458853057691014[276] = 0.0;
   out_2207458853057691014[277] = 0.0;
   out_2207458853057691014[278] = 0.0;
   out_2207458853057691014[279] = 0.0;
   out_2207458853057691014[280] = 0.0;
   out_2207458853057691014[281] = 0.0;
   out_2207458853057691014[282] = 0.0;
   out_2207458853057691014[283] = 0.0;
   out_2207458853057691014[284] = 0.0;
   out_2207458853057691014[285] = 1.0;
   out_2207458853057691014[286] = 0.0;
   out_2207458853057691014[287] = 0.0;
   out_2207458853057691014[288] = 0.0;
   out_2207458853057691014[289] = 0.0;
   out_2207458853057691014[290] = 0.0;
   out_2207458853057691014[291] = 0.0;
   out_2207458853057691014[292] = 0.0;
   out_2207458853057691014[293] = 0.0;
   out_2207458853057691014[294] = 0.0;
   out_2207458853057691014[295] = 0.0;
   out_2207458853057691014[296] = 0.0;
   out_2207458853057691014[297] = 0.0;
   out_2207458853057691014[298] = 0.0;
   out_2207458853057691014[299] = 0.0;
   out_2207458853057691014[300] = 0.0;
   out_2207458853057691014[301] = 0.0;
   out_2207458853057691014[302] = 0.0;
   out_2207458853057691014[303] = 0.0;
   out_2207458853057691014[304] = 1.0;
   out_2207458853057691014[305] = 0.0;
   out_2207458853057691014[306] = 0.0;
   out_2207458853057691014[307] = 0.0;
   out_2207458853057691014[308] = 0.0;
   out_2207458853057691014[309] = 0.0;
   out_2207458853057691014[310] = 0.0;
   out_2207458853057691014[311] = 0.0;
   out_2207458853057691014[312] = 0.0;
   out_2207458853057691014[313] = 0.0;
   out_2207458853057691014[314] = 0.0;
   out_2207458853057691014[315] = 0.0;
   out_2207458853057691014[316] = 0.0;
   out_2207458853057691014[317] = 0.0;
   out_2207458853057691014[318] = 0.0;
   out_2207458853057691014[319] = 0.0;
   out_2207458853057691014[320] = 0.0;
   out_2207458853057691014[321] = 0.0;
   out_2207458853057691014[322] = 0.0;
   out_2207458853057691014[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7635303320387631810) {
   out_7635303320387631810[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7635303320387631810[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7635303320387631810[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7635303320387631810[3] = dt*state[12] + state[3];
   out_7635303320387631810[4] = dt*state[13] + state[4];
   out_7635303320387631810[5] = dt*state[14] + state[5];
   out_7635303320387631810[6] = state[6];
   out_7635303320387631810[7] = state[7];
   out_7635303320387631810[8] = state[8];
   out_7635303320387631810[9] = state[9];
   out_7635303320387631810[10] = state[10];
   out_7635303320387631810[11] = state[11];
   out_7635303320387631810[12] = state[12];
   out_7635303320387631810[13] = state[13];
   out_7635303320387631810[14] = state[14];
   out_7635303320387631810[15] = state[15];
   out_7635303320387631810[16] = state[16];
   out_7635303320387631810[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8324840199262111301) {
   out_8324840199262111301[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8324840199262111301[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8324840199262111301[2] = 0;
   out_8324840199262111301[3] = 0;
   out_8324840199262111301[4] = 0;
   out_8324840199262111301[5] = 0;
   out_8324840199262111301[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8324840199262111301[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8324840199262111301[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8324840199262111301[9] = 0;
   out_8324840199262111301[10] = 0;
   out_8324840199262111301[11] = 0;
   out_8324840199262111301[12] = 0;
   out_8324840199262111301[13] = 0;
   out_8324840199262111301[14] = 0;
   out_8324840199262111301[15] = 0;
   out_8324840199262111301[16] = 0;
   out_8324840199262111301[17] = 0;
   out_8324840199262111301[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8324840199262111301[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8324840199262111301[20] = 0;
   out_8324840199262111301[21] = 0;
   out_8324840199262111301[22] = 0;
   out_8324840199262111301[23] = 0;
   out_8324840199262111301[24] = 0;
   out_8324840199262111301[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8324840199262111301[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8324840199262111301[27] = 0;
   out_8324840199262111301[28] = 0;
   out_8324840199262111301[29] = 0;
   out_8324840199262111301[30] = 0;
   out_8324840199262111301[31] = 0;
   out_8324840199262111301[32] = 0;
   out_8324840199262111301[33] = 0;
   out_8324840199262111301[34] = 0;
   out_8324840199262111301[35] = 0;
   out_8324840199262111301[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8324840199262111301[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8324840199262111301[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8324840199262111301[39] = 0;
   out_8324840199262111301[40] = 0;
   out_8324840199262111301[41] = 0;
   out_8324840199262111301[42] = 0;
   out_8324840199262111301[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8324840199262111301[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8324840199262111301[45] = 0;
   out_8324840199262111301[46] = 0;
   out_8324840199262111301[47] = 0;
   out_8324840199262111301[48] = 0;
   out_8324840199262111301[49] = 0;
   out_8324840199262111301[50] = 0;
   out_8324840199262111301[51] = 0;
   out_8324840199262111301[52] = 0;
   out_8324840199262111301[53] = 0;
   out_8324840199262111301[54] = 0;
   out_8324840199262111301[55] = 0;
   out_8324840199262111301[56] = 0;
   out_8324840199262111301[57] = 1;
   out_8324840199262111301[58] = 0;
   out_8324840199262111301[59] = 0;
   out_8324840199262111301[60] = 0;
   out_8324840199262111301[61] = 0;
   out_8324840199262111301[62] = 0;
   out_8324840199262111301[63] = 0;
   out_8324840199262111301[64] = 0;
   out_8324840199262111301[65] = 0;
   out_8324840199262111301[66] = dt;
   out_8324840199262111301[67] = 0;
   out_8324840199262111301[68] = 0;
   out_8324840199262111301[69] = 0;
   out_8324840199262111301[70] = 0;
   out_8324840199262111301[71] = 0;
   out_8324840199262111301[72] = 0;
   out_8324840199262111301[73] = 0;
   out_8324840199262111301[74] = 0;
   out_8324840199262111301[75] = 0;
   out_8324840199262111301[76] = 1;
   out_8324840199262111301[77] = 0;
   out_8324840199262111301[78] = 0;
   out_8324840199262111301[79] = 0;
   out_8324840199262111301[80] = 0;
   out_8324840199262111301[81] = 0;
   out_8324840199262111301[82] = 0;
   out_8324840199262111301[83] = 0;
   out_8324840199262111301[84] = 0;
   out_8324840199262111301[85] = dt;
   out_8324840199262111301[86] = 0;
   out_8324840199262111301[87] = 0;
   out_8324840199262111301[88] = 0;
   out_8324840199262111301[89] = 0;
   out_8324840199262111301[90] = 0;
   out_8324840199262111301[91] = 0;
   out_8324840199262111301[92] = 0;
   out_8324840199262111301[93] = 0;
   out_8324840199262111301[94] = 0;
   out_8324840199262111301[95] = 1;
   out_8324840199262111301[96] = 0;
   out_8324840199262111301[97] = 0;
   out_8324840199262111301[98] = 0;
   out_8324840199262111301[99] = 0;
   out_8324840199262111301[100] = 0;
   out_8324840199262111301[101] = 0;
   out_8324840199262111301[102] = 0;
   out_8324840199262111301[103] = 0;
   out_8324840199262111301[104] = dt;
   out_8324840199262111301[105] = 0;
   out_8324840199262111301[106] = 0;
   out_8324840199262111301[107] = 0;
   out_8324840199262111301[108] = 0;
   out_8324840199262111301[109] = 0;
   out_8324840199262111301[110] = 0;
   out_8324840199262111301[111] = 0;
   out_8324840199262111301[112] = 0;
   out_8324840199262111301[113] = 0;
   out_8324840199262111301[114] = 1;
   out_8324840199262111301[115] = 0;
   out_8324840199262111301[116] = 0;
   out_8324840199262111301[117] = 0;
   out_8324840199262111301[118] = 0;
   out_8324840199262111301[119] = 0;
   out_8324840199262111301[120] = 0;
   out_8324840199262111301[121] = 0;
   out_8324840199262111301[122] = 0;
   out_8324840199262111301[123] = 0;
   out_8324840199262111301[124] = 0;
   out_8324840199262111301[125] = 0;
   out_8324840199262111301[126] = 0;
   out_8324840199262111301[127] = 0;
   out_8324840199262111301[128] = 0;
   out_8324840199262111301[129] = 0;
   out_8324840199262111301[130] = 0;
   out_8324840199262111301[131] = 0;
   out_8324840199262111301[132] = 0;
   out_8324840199262111301[133] = 1;
   out_8324840199262111301[134] = 0;
   out_8324840199262111301[135] = 0;
   out_8324840199262111301[136] = 0;
   out_8324840199262111301[137] = 0;
   out_8324840199262111301[138] = 0;
   out_8324840199262111301[139] = 0;
   out_8324840199262111301[140] = 0;
   out_8324840199262111301[141] = 0;
   out_8324840199262111301[142] = 0;
   out_8324840199262111301[143] = 0;
   out_8324840199262111301[144] = 0;
   out_8324840199262111301[145] = 0;
   out_8324840199262111301[146] = 0;
   out_8324840199262111301[147] = 0;
   out_8324840199262111301[148] = 0;
   out_8324840199262111301[149] = 0;
   out_8324840199262111301[150] = 0;
   out_8324840199262111301[151] = 0;
   out_8324840199262111301[152] = 1;
   out_8324840199262111301[153] = 0;
   out_8324840199262111301[154] = 0;
   out_8324840199262111301[155] = 0;
   out_8324840199262111301[156] = 0;
   out_8324840199262111301[157] = 0;
   out_8324840199262111301[158] = 0;
   out_8324840199262111301[159] = 0;
   out_8324840199262111301[160] = 0;
   out_8324840199262111301[161] = 0;
   out_8324840199262111301[162] = 0;
   out_8324840199262111301[163] = 0;
   out_8324840199262111301[164] = 0;
   out_8324840199262111301[165] = 0;
   out_8324840199262111301[166] = 0;
   out_8324840199262111301[167] = 0;
   out_8324840199262111301[168] = 0;
   out_8324840199262111301[169] = 0;
   out_8324840199262111301[170] = 0;
   out_8324840199262111301[171] = 1;
   out_8324840199262111301[172] = 0;
   out_8324840199262111301[173] = 0;
   out_8324840199262111301[174] = 0;
   out_8324840199262111301[175] = 0;
   out_8324840199262111301[176] = 0;
   out_8324840199262111301[177] = 0;
   out_8324840199262111301[178] = 0;
   out_8324840199262111301[179] = 0;
   out_8324840199262111301[180] = 0;
   out_8324840199262111301[181] = 0;
   out_8324840199262111301[182] = 0;
   out_8324840199262111301[183] = 0;
   out_8324840199262111301[184] = 0;
   out_8324840199262111301[185] = 0;
   out_8324840199262111301[186] = 0;
   out_8324840199262111301[187] = 0;
   out_8324840199262111301[188] = 0;
   out_8324840199262111301[189] = 0;
   out_8324840199262111301[190] = 1;
   out_8324840199262111301[191] = 0;
   out_8324840199262111301[192] = 0;
   out_8324840199262111301[193] = 0;
   out_8324840199262111301[194] = 0;
   out_8324840199262111301[195] = 0;
   out_8324840199262111301[196] = 0;
   out_8324840199262111301[197] = 0;
   out_8324840199262111301[198] = 0;
   out_8324840199262111301[199] = 0;
   out_8324840199262111301[200] = 0;
   out_8324840199262111301[201] = 0;
   out_8324840199262111301[202] = 0;
   out_8324840199262111301[203] = 0;
   out_8324840199262111301[204] = 0;
   out_8324840199262111301[205] = 0;
   out_8324840199262111301[206] = 0;
   out_8324840199262111301[207] = 0;
   out_8324840199262111301[208] = 0;
   out_8324840199262111301[209] = 1;
   out_8324840199262111301[210] = 0;
   out_8324840199262111301[211] = 0;
   out_8324840199262111301[212] = 0;
   out_8324840199262111301[213] = 0;
   out_8324840199262111301[214] = 0;
   out_8324840199262111301[215] = 0;
   out_8324840199262111301[216] = 0;
   out_8324840199262111301[217] = 0;
   out_8324840199262111301[218] = 0;
   out_8324840199262111301[219] = 0;
   out_8324840199262111301[220] = 0;
   out_8324840199262111301[221] = 0;
   out_8324840199262111301[222] = 0;
   out_8324840199262111301[223] = 0;
   out_8324840199262111301[224] = 0;
   out_8324840199262111301[225] = 0;
   out_8324840199262111301[226] = 0;
   out_8324840199262111301[227] = 0;
   out_8324840199262111301[228] = 1;
   out_8324840199262111301[229] = 0;
   out_8324840199262111301[230] = 0;
   out_8324840199262111301[231] = 0;
   out_8324840199262111301[232] = 0;
   out_8324840199262111301[233] = 0;
   out_8324840199262111301[234] = 0;
   out_8324840199262111301[235] = 0;
   out_8324840199262111301[236] = 0;
   out_8324840199262111301[237] = 0;
   out_8324840199262111301[238] = 0;
   out_8324840199262111301[239] = 0;
   out_8324840199262111301[240] = 0;
   out_8324840199262111301[241] = 0;
   out_8324840199262111301[242] = 0;
   out_8324840199262111301[243] = 0;
   out_8324840199262111301[244] = 0;
   out_8324840199262111301[245] = 0;
   out_8324840199262111301[246] = 0;
   out_8324840199262111301[247] = 1;
   out_8324840199262111301[248] = 0;
   out_8324840199262111301[249] = 0;
   out_8324840199262111301[250] = 0;
   out_8324840199262111301[251] = 0;
   out_8324840199262111301[252] = 0;
   out_8324840199262111301[253] = 0;
   out_8324840199262111301[254] = 0;
   out_8324840199262111301[255] = 0;
   out_8324840199262111301[256] = 0;
   out_8324840199262111301[257] = 0;
   out_8324840199262111301[258] = 0;
   out_8324840199262111301[259] = 0;
   out_8324840199262111301[260] = 0;
   out_8324840199262111301[261] = 0;
   out_8324840199262111301[262] = 0;
   out_8324840199262111301[263] = 0;
   out_8324840199262111301[264] = 0;
   out_8324840199262111301[265] = 0;
   out_8324840199262111301[266] = 1;
   out_8324840199262111301[267] = 0;
   out_8324840199262111301[268] = 0;
   out_8324840199262111301[269] = 0;
   out_8324840199262111301[270] = 0;
   out_8324840199262111301[271] = 0;
   out_8324840199262111301[272] = 0;
   out_8324840199262111301[273] = 0;
   out_8324840199262111301[274] = 0;
   out_8324840199262111301[275] = 0;
   out_8324840199262111301[276] = 0;
   out_8324840199262111301[277] = 0;
   out_8324840199262111301[278] = 0;
   out_8324840199262111301[279] = 0;
   out_8324840199262111301[280] = 0;
   out_8324840199262111301[281] = 0;
   out_8324840199262111301[282] = 0;
   out_8324840199262111301[283] = 0;
   out_8324840199262111301[284] = 0;
   out_8324840199262111301[285] = 1;
   out_8324840199262111301[286] = 0;
   out_8324840199262111301[287] = 0;
   out_8324840199262111301[288] = 0;
   out_8324840199262111301[289] = 0;
   out_8324840199262111301[290] = 0;
   out_8324840199262111301[291] = 0;
   out_8324840199262111301[292] = 0;
   out_8324840199262111301[293] = 0;
   out_8324840199262111301[294] = 0;
   out_8324840199262111301[295] = 0;
   out_8324840199262111301[296] = 0;
   out_8324840199262111301[297] = 0;
   out_8324840199262111301[298] = 0;
   out_8324840199262111301[299] = 0;
   out_8324840199262111301[300] = 0;
   out_8324840199262111301[301] = 0;
   out_8324840199262111301[302] = 0;
   out_8324840199262111301[303] = 0;
   out_8324840199262111301[304] = 1;
   out_8324840199262111301[305] = 0;
   out_8324840199262111301[306] = 0;
   out_8324840199262111301[307] = 0;
   out_8324840199262111301[308] = 0;
   out_8324840199262111301[309] = 0;
   out_8324840199262111301[310] = 0;
   out_8324840199262111301[311] = 0;
   out_8324840199262111301[312] = 0;
   out_8324840199262111301[313] = 0;
   out_8324840199262111301[314] = 0;
   out_8324840199262111301[315] = 0;
   out_8324840199262111301[316] = 0;
   out_8324840199262111301[317] = 0;
   out_8324840199262111301[318] = 0;
   out_8324840199262111301[319] = 0;
   out_8324840199262111301[320] = 0;
   out_8324840199262111301[321] = 0;
   out_8324840199262111301[322] = 0;
   out_8324840199262111301[323] = 1;
}
void h_4(double *state, double *unused, double *out_2118179578320955915) {
   out_2118179578320955915[0] = state[6] + state[9];
   out_2118179578320955915[1] = state[7] + state[10];
   out_2118179578320955915[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7359977238096771749) {
   out_7359977238096771749[0] = 0;
   out_7359977238096771749[1] = 0;
   out_7359977238096771749[2] = 0;
   out_7359977238096771749[3] = 0;
   out_7359977238096771749[4] = 0;
   out_7359977238096771749[5] = 0;
   out_7359977238096771749[6] = 1;
   out_7359977238096771749[7] = 0;
   out_7359977238096771749[8] = 0;
   out_7359977238096771749[9] = 1;
   out_7359977238096771749[10] = 0;
   out_7359977238096771749[11] = 0;
   out_7359977238096771749[12] = 0;
   out_7359977238096771749[13] = 0;
   out_7359977238096771749[14] = 0;
   out_7359977238096771749[15] = 0;
   out_7359977238096771749[16] = 0;
   out_7359977238096771749[17] = 0;
   out_7359977238096771749[18] = 0;
   out_7359977238096771749[19] = 0;
   out_7359977238096771749[20] = 0;
   out_7359977238096771749[21] = 0;
   out_7359977238096771749[22] = 0;
   out_7359977238096771749[23] = 0;
   out_7359977238096771749[24] = 0;
   out_7359977238096771749[25] = 1;
   out_7359977238096771749[26] = 0;
   out_7359977238096771749[27] = 0;
   out_7359977238096771749[28] = 1;
   out_7359977238096771749[29] = 0;
   out_7359977238096771749[30] = 0;
   out_7359977238096771749[31] = 0;
   out_7359977238096771749[32] = 0;
   out_7359977238096771749[33] = 0;
   out_7359977238096771749[34] = 0;
   out_7359977238096771749[35] = 0;
   out_7359977238096771749[36] = 0;
   out_7359977238096771749[37] = 0;
   out_7359977238096771749[38] = 0;
   out_7359977238096771749[39] = 0;
   out_7359977238096771749[40] = 0;
   out_7359977238096771749[41] = 0;
   out_7359977238096771749[42] = 0;
   out_7359977238096771749[43] = 0;
   out_7359977238096771749[44] = 1;
   out_7359977238096771749[45] = 0;
   out_7359977238096771749[46] = 0;
   out_7359977238096771749[47] = 1;
   out_7359977238096771749[48] = 0;
   out_7359977238096771749[49] = 0;
   out_7359977238096771749[50] = 0;
   out_7359977238096771749[51] = 0;
   out_7359977238096771749[52] = 0;
   out_7359977238096771749[53] = 0;
}
void h_10(double *state, double *unused, double *out_863109591849531819) {
   out_863109591849531819[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_863109591849531819[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_863109591849531819[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6053481103905099724) {
   out_6053481103905099724[0] = 0;
   out_6053481103905099724[1] = 9.8100000000000005*cos(state[1]);
   out_6053481103905099724[2] = 0;
   out_6053481103905099724[3] = 0;
   out_6053481103905099724[4] = -state[8];
   out_6053481103905099724[5] = state[7];
   out_6053481103905099724[6] = 0;
   out_6053481103905099724[7] = state[5];
   out_6053481103905099724[8] = -state[4];
   out_6053481103905099724[9] = 0;
   out_6053481103905099724[10] = 0;
   out_6053481103905099724[11] = 0;
   out_6053481103905099724[12] = 1;
   out_6053481103905099724[13] = 0;
   out_6053481103905099724[14] = 0;
   out_6053481103905099724[15] = 1;
   out_6053481103905099724[16] = 0;
   out_6053481103905099724[17] = 0;
   out_6053481103905099724[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6053481103905099724[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6053481103905099724[20] = 0;
   out_6053481103905099724[21] = state[8];
   out_6053481103905099724[22] = 0;
   out_6053481103905099724[23] = -state[6];
   out_6053481103905099724[24] = -state[5];
   out_6053481103905099724[25] = 0;
   out_6053481103905099724[26] = state[3];
   out_6053481103905099724[27] = 0;
   out_6053481103905099724[28] = 0;
   out_6053481103905099724[29] = 0;
   out_6053481103905099724[30] = 0;
   out_6053481103905099724[31] = 1;
   out_6053481103905099724[32] = 0;
   out_6053481103905099724[33] = 0;
   out_6053481103905099724[34] = 1;
   out_6053481103905099724[35] = 0;
   out_6053481103905099724[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6053481103905099724[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6053481103905099724[38] = 0;
   out_6053481103905099724[39] = -state[7];
   out_6053481103905099724[40] = state[6];
   out_6053481103905099724[41] = 0;
   out_6053481103905099724[42] = state[4];
   out_6053481103905099724[43] = -state[3];
   out_6053481103905099724[44] = 0;
   out_6053481103905099724[45] = 0;
   out_6053481103905099724[46] = 0;
   out_6053481103905099724[47] = 0;
   out_6053481103905099724[48] = 0;
   out_6053481103905099724[49] = 0;
   out_6053481103905099724[50] = 1;
   out_6053481103905099724[51] = 0;
   out_6053481103905099724[52] = 0;
   out_6053481103905099724[53] = 1;
}
void h_13(double *state, double *unused, double *out_8506504787708500859) {
   out_8506504787708500859[0] = state[3];
   out_8506504787708500859[1] = state[4];
   out_8506504787708500859[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7874493010280447066) {
   out_7874493010280447066[0] = 0;
   out_7874493010280447066[1] = 0;
   out_7874493010280447066[2] = 0;
   out_7874493010280447066[3] = 1;
   out_7874493010280447066[4] = 0;
   out_7874493010280447066[5] = 0;
   out_7874493010280447066[6] = 0;
   out_7874493010280447066[7] = 0;
   out_7874493010280447066[8] = 0;
   out_7874493010280447066[9] = 0;
   out_7874493010280447066[10] = 0;
   out_7874493010280447066[11] = 0;
   out_7874493010280447066[12] = 0;
   out_7874493010280447066[13] = 0;
   out_7874493010280447066[14] = 0;
   out_7874493010280447066[15] = 0;
   out_7874493010280447066[16] = 0;
   out_7874493010280447066[17] = 0;
   out_7874493010280447066[18] = 0;
   out_7874493010280447066[19] = 0;
   out_7874493010280447066[20] = 0;
   out_7874493010280447066[21] = 0;
   out_7874493010280447066[22] = 1;
   out_7874493010280447066[23] = 0;
   out_7874493010280447066[24] = 0;
   out_7874493010280447066[25] = 0;
   out_7874493010280447066[26] = 0;
   out_7874493010280447066[27] = 0;
   out_7874493010280447066[28] = 0;
   out_7874493010280447066[29] = 0;
   out_7874493010280447066[30] = 0;
   out_7874493010280447066[31] = 0;
   out_7874493010280447066[32] = 0;
   out_7874493010280447066[33] = 0;
   out_7874493010280447066[34] = 0;
   out_7874493010280447066[35] = 0;
   out_7874493010280447066[36] = 0;
   out_7874493010280447066[37] = 0;
   out_7874493010280447066[38] = 0;
   out_7874493010280447066[39] = 0;
   out_7874493010280447066[40] = 0;
   out_7874493010280447066[41] = 1;
   out_7874493010280447066[42] = 0;
   out_7874493010280447066[43] = 0;
   out_7874493010280447066[44] = 0;
   out_7874493010280447066[45] = 0;
   out_7874493010280447066[46] = 0;
   out_7874493010280447066[47] = 0;
   out_7874493010280447066[48] = 0;
   out_7874493010280447066[49] = 0;
   out_7874493010280447066[50] = 0;
   out_7874493010280447066[51] = 0;
   out_7874493010280447066[52] = 0;
   out_7874493010280447066[53] = 0;
}
void h_14(double *state, double *unused, double *out_6030639671543279411) {
   out_6030639671543279411[0] = state[6];
   out_6030639671543279411[1] = state[7];
   out_6030639671543279411[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7123525979273295338) {
   out_7123525979273295338[0] = 0;
   out_7123525979273295338[1] = 0;
   out_7123525979273295338[2] = 0;
   out_7123525979273295338[3] = 0;
   out_7123525979273295338[4] = 0;
   out_7123525979273295338[5] = 0;
   out_7123525979273295338[6] = 1;
   out_7123525979273295338[7] = 0;
   out_7123525979273295338[8] = 0;
   out_7123525979273295338[9] = 0;
   out_7123525979273295338[10] = 0;
   out_7123525979273295338[11] = 0;
   out_7123525979273295338[12] = 0;
   out_7123525979273295338[13] = 0;
   out_7123525979273295338[14] = 0;
   out_7123525979273295338[15] = 0;
   out_7123525979273295338[16] = 0;
   out_7123525979273295338[17] = 0;
   out_7123525979273295338[18] = 0;
   out_7123525979273295338[19] = 0;
   out_7123525979273295338[20] = 0;
   out_7123525979273295338[21] = 0;
   out_7123525979273295338[22] = 0;
   out_7123525979273295338[23] = 0;
   out_7123525979273295338[24] = 0;
   out_7123525979273295338[25] = 1;
   out_7123525979273295338[26] = 0;
   out_7123525979273295338[27] = 0;
   out_7123525979273295338[28] = 0;
   out_7123525979273295338[29] = 0;
   out_7123525979273295338[30] = 0;
   out_7123525979273295338[31] = 0;
   out_7123525979273295338[32] = 0;
   out_7123525979273295338[33] = 0;
   out_7123525979273295338[34] = 0;
   out_7123525979273295338[35] = 0;
   out_7123525979273295338[36] = 0;
   out_7123525979273295338[37] = 0;
   out_7123525979273295338[38] = 0;
   out_7123525979273295338[39] = 0;
   out_7123525979273295338[40] = 0;
   out_7123525979273295338[41] = 0;
   out_7123525979273295338[42] = 0;
   out_7123525979273295338[43] = 0;
   out_7123525979273295338[44] = 1;
   out_7123525979273295338[45] = 0;
   out_7123525979273295338[46] = 0;
   out_7123525979273295338[47] = 0;
   out_7123525979273295338[48] = 0;
   out_7123525979273295338[49] = 0;
   out_7123525979273295338[50] = 0;
   out_7123525979273295338[51] = 0;
   out_7123525979273295338[52] = 0;
   out_7123525979273295338[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8334628911363265031) {
  err_fun(nom_x, delta_x, out_8334628911363265031);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6557509511038369963) {
  inv_err_fun(nom_x, true_x, out_6557509511038369963);
}
void pose_H_mod_fun(double *state, double *out_2207458853057691014) {
  H_mod_fun(state, out_2207458853057691014);
}
void pose_f_fun(double *state, double dt, double *out_7635303320387631810) {
  f_fun(state,  dt, out_7635303320387631810);
}
void pose_F_fun(double *state, double dt, double *out_8324840199262111301) {
  F_fun(state,  dt, out_8324840199262111301);
}
void pose_h_4(double *state, double *unused, double *out_2118179578320955915) {
  h_4(state, unused, out_2118179578320955915);
}
void pose_H_4(double *state, double *unused, double *out_7359977238096771749) {
  H_4(state, unused, out_7359977238096771749);
}
void pose_h_10(double *state, double *unused, double *out_863109591849531819) {
  h_10(state, unused, out_863109591849531819);
}
void pose_H_10(double *state, double *unused, double *out_6053481103905099724) {
  H_10(state, unused, out_6053481103905099724);
}
void pose_h_13(double *state, double *unused, double *out_8506504787708500859) {
  h_13(state, unused, out_8506504787708500859);
}
void pose_H_13(double *state, double *unused, double *out_7874493010280447066) {
  H_13(state, unused, out_7874493010280447066);
}
void pose_h_14(double *state, double *unused, double *out_6030639671543279411) {
  h_14(state, unused, out_6030639671543279411);
}
void pose_H_14(double *state, double *unused, double *out_7123525979273295338) {
  H_14(state, unused, out_7123525979273295338);
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
