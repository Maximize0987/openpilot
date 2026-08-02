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
void err_fun(double *nom_x, double *delta_x, double *out_9137514370372247790) {
   out_9137514370372247790[0] = delta_x[0] + nom_x[0];
   out_9137514370372247790[1] = delta_x[1] + nom_x[1];
   out_9137514370372247790[2] = delta_x[2] + nom_x[2];
   out_9137514370372247790[3] = delta_x[3] + nom_x[3];
   out_9137514370372247790[4] = delta_x[4] + nom_x[4];
   out_9137514370372247790[5] = delta_x[5] + nom_x[5];
   out_9137514370372247790[6] = delta_x[6] + nom_x[6];
   out_9137514370372247790[7] = delta_x[7] + nom_x[7];
   out_9137514370372247790[8] = delta_x[8] + nom_x[8];
   out_9137514370372247790[9] = delta_x[9] + nom_x[9];
   out_9137514370372247790[10] = delta_x[10] + nom_x[10];
   out_9137514370372247790[11] = delta_x[11] + nom_x[11];
   out_9137514370372247790[12] = delta_x[12] + nom_x[12];
   out_9137514370372247790[13] = delta_x[13] + nom_x[13];
   out_9137514370372247790[14] = delta_x[14] + nom_x[14];
   out_9137514370372247790[15] = delta_x[15] + nom_x[15];
   out_9137514370372247790[16] = delta_x[16] + nom_x[16];
   out_9137514370372247790[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3476070474607186610) {
   out_3476070474607186610[0] = -nom_x[0] + true_x[0];
   out_3476070474607186610[1] = -nom_x[1] + true_x[1];
   out_3476070474607186610[2] = -nom_x[2] + true_x[2];
   out_3476070474607186610[3] = -nom_x[3] + true_x[3];
   out_3476070474607186610[4] = -nom_x[4] + true_x[4];
   out_3476070474607186610[5] = -nom_x[5] + true_x[5];
   out_3476070474607186610[6] = -nom_x[6] + true_x[6];
   out_3476070474607186610[7] = -nom_x[7] + true_x[7];
   out_3476070474607186610[8] = -nom_x[8] + true_x[8];
   out_3476070474607186610[9] = -nom_x[9] + true_x[9];
   out_3476070474607186610[10] = -nom_x[10] + true_x[10];
   out_3476070474607186610[11] = -nom_x[11] + true_x[11];
   out_3476070474607186610[12] = -nom_x[12] + true_x[12];
   out_3476070474607186610[13] = -nom_x[13] + true_x[13];
   out_3476070474607186610[14] = -nom_x[14] + true_x[14];
   out_3476070474607186610[15] = -nom_x[15] + true_x[15];
   out_3476070474607186610[16] = -nom_x[16] + true_x[16];
   out_3476070474607186610[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2374218852650606410) {
   out_2374218852650606410[0] = 1.0;
   out_2374218852650606410[1] = 0.0;
   out_2374218852650606410[2] = 0.0;
   out_2374218852650606410[3] = 0.0;
   out_2374218852650606410[4] = 0.0;
   out_2374218852650606410[5] = 0.0;
   out_2374218852650606410[6] = 0.0;
   out_2374218852650606410[7] = 0.0;
   out_2374218852650606410[8] = 0.0;
   out_2374218852650606410[9] = 0.0;
   out_2374218852650606410[10] = 0.0;
   out_2374218852650606410[11] = 0.0;
   out_2374218852650606410[12] = 0.0;
   out_2374218852650606410[13] = 0.0;
   out_2374218852650606410[14] = 0.0;
   out_2374218852650606410[15] = 0.0;
   out_2374218852650606410[16] = 0.0;
   out_2374218852650606410[17] = 0.0;
   out_2374218852650606410[18] = 0.0;
   out_2374218852650606410[19] = 1.0;
   out_2374218852650606410[20] = 0.0;
   out_2374218852650606410[21] = 0.0;
   out_2374218852650606410[22] = 0.0;
   out_2374218852650606410[23] = 0.0;
   out_2374218852650606410[24] = 0.0;
   out_2374218852650606410[25] = 0.0;
   out_2374218852650606410[26] = 0.0;
   out_2374218852650606410[27] = 0.0;
   out_2374218852650606410[28] = 0.0;
   out_2374218852650606410[29] = 0.0;
   out_2374218852650606410[30] = 0.0;
   out_2374218852650606410[31] = 0.0;
   out_2374218852650606410[32] = 0.0;
   out_2374218852650606410[33] = 0.0;
   out_2374218852650606410[34] = 0.0;
   out_2374218852650606410[35] = 0.0;
   out_2374218852650606410[36] = 0.0;
   out_2374218852650606410[37] = 0.0;
   out_2374218852650606410[38] = 1.0;
   out_2374218852650606410[39] = 0.0;
   out_2374218852650606410[40] = 0.0;
   out_2374218852650606410[41] = 0.0;
   out_2374218852650606410[42] = 0.0;
   out_2374218852650606410[43] = 0.0;
   out_2374218852650606410[44] = 0.0;
   out_2374218852650606410[45] = 0.0;
   out_2374218852650606410[46] = 0.0;
   out_2374218852650606410[47] = 0.0;
   out_2374218852650606410[48] = 0.0;
   out_2374218852650606410[49] = 0.0;
   out_2374218852650606410[50] = 0.0;
   out_2374218852650606410[51] = 0.0;
   out_2374218852650606410[52] = 0.0;
   out_2374218852650606410[53] = 0.0;
   out_2374218852650606410[54] = 0.0;
   out_2374218852650606410[55] = 0.0;
   out_2374218852650606410[56] = 0.0;
   out_2374218852650606410[57] = 1.0;
   out_2374218852650606410[58] = 0.0;
   out_2374218852650606410[59] = 0.0;
   out_2374218852650606410[60] = 0.0;
   out_2374218852650606410[61] = 0.0;
   out_2374218852650606410[62] = 0.0;
   out_2374218852650606410[63] = 0.0;
   out_2374218852650606410[64] = 0.0;
   out_2374218852650606410[65] = 0.0;
   out_2374218852650606410[66] = 0.0;
   out_2374218852650606410[67] = 0.0;
   out_2374218852650606410[68] = 0.0;
   out_2374218852650606410[69] = 0.0;
   out_2374218852650606410[70] = 0.0;
   out_2374218852650606410[71] = 0.0;
   out_2374218852650606410[72] = 0.0;
   out_2374218852650606410[73] = 0.0;
   out_2374218852650606410[74] = 0.0;
   out_2374218852650606410[75] = 0.0;
   out_2374218852650606410[76] = 1.0;
   out_2374218852650606410[77] = 0.0;
   out_2374218852650606410[78] = 0.0;
   out_2374218852650606410[79] = 0.0;
   out_2374218852650606410[80] = 0.0;
   out_2374218852650606410[81] = 0.0;
   out_2374218852650606410[82] = 0.0;
   out_2374218852650606410[83] = 0.0;
   out_2374218852650606410[84] = 0.0;
   out_2374218852650606410[85] = 0.0;
   out_2374218852650606410[86] = 0.0;
   out_2374218852650606410[87] = 0.0;
   out_2374218852650606410[88] = 0.0;
   out_2374218852650606410[89] = 0.0;
   out_2374218852650606410[90] = 0.0;
   out_2374218852650606410[91] = 0.0;
   out_2374218852650606410[92] = 0.0;
   out_2374218852650606410[93] = 0.0;
   out_2374218852650606410[94] = 0.0;
   out_2374218852650606410[95] = 1.0;
   out_2374218852650606410[96] = 0.0;
   out_2374218852650606410[97] = 0.0;
   out_2374218852650606410[98] = 0.0;
   out_2374218852650606410[99] = 0.0;
   out_2374218852650606410[100] = 0.0;
   out_2374218852650606410[101] = 0.0;
   out_2374218852650606410[102] = 0.0;
   out_2374218852650606410[103] = 0.0;
   out_2374218852650606410[104] = 0.0;
   out_2374218852650606410[105] = 0.0;
   out_2374218852650606410[106] = 0.0;
   out_2374218852650606410[107] = 0.0;
   out_2374218852650606410[108] = 0.0;
   out_2374218852650606410[109] = 0.0;
   out_2374218852650606410[110] = 0.0;
   out_2374218852650606410[111] = 0.0;
   out_2374218852650606410[112] = 0.0;
   out_2374218852650606410[113] = 0.0;
   out_2374218852650606410[114] = 1.0;
   out_2374218852650606410[115] = 0.0;
   out_2374218852650606410[116] = 0.0;
   out_2374218852650606410[117] = 0.0;
   out_2374218852650606410[118] = 0.0;
   out_2374218852650606410[119] = 0.0;
   out_2374218852650606410[120] = 0.0;
   out_2374218852650606410[121] = 0.0;
   out_2374218852650606410[122] = 0.0;
   out_2374218852650606410[123] = 0.0;
   out_2374218852650606410[124] = 0.0;
   out_2374218852650606410[125] = 0.0;
   out_2374218852650606410[126] = 0.0;
   out_2374218852650606410[127] = 0.0;
   out_2374218852650606410[128] = 0.0;
   out_2374218852650606410[129] = 0.0;
   out_2374218852650606410[130] = 0.0;
   out_2374218852650606410[131] = 0.0;
   out_2374218852650606410[132] = 0.0;
   out_2374218852650606410[133] = 1.0;
   out_2374218852650606410[134] = 0.0;
   out_2374218852650606410[135] = 0.0;
   out_2374218852650606410[136] = 0.0;
   out_2374218852650606410[137] = 0.0;
   out_2374218852650606410[138] = 0.0;
   out_2374218852650606410[139] = 0.0;
   out_2374218852650606410[140] = 0.0;
   out_2374218852650606410[141] = 0.0;
   out_2374218852650606410[142] = 0.0;
   out_2374218852650606410[143] = 0.0;
   out_2374218852650606410[144] = 0.0;
   out_2374218852650606410[145] = 0.0;
   out_2374218852650606410[146] = 0.0;
   out_2374218852650606410[147] = 0.0;
   out_2374218852650606410[148] = 0.0;
   out_2374218852650606410[149] = 0.0;
   out_2374218852650606410[150] = 0.0;
   out_2374218852650606410[151] = 0.0;
   out_2374218852650606410[152] = 1.0;
   out_2374218852650606410[153] = 0.0;
   out_2374218852650606410[154] = 0.0;
   out_2374218852650606410[155] = 0.0;
   out_2374218852650606410[156] = 0.0;
   out_2374218852650606410[157] = 0.0;
   out_2374218852650606410[158] = 0.0;
   out_2374218852650606410[159] = 0.0;
   out_2374218852650606410[160] = 0.0;
   out_2374218852650606410[161] = 0.0;
   out_2374218852650606410[162] = 0.0;
   out_2374218852650606410[163] = 0.0;
   out_2374218852650606410[164] = 0.0;
   out_2374218852650606410[165] = 0.0;
   out_2374218852650606410[166] = 0.0;
   out_2374218852650606410[167] = 0.0;
   out_2374218852650606410[168] = 0.0;
   out_2374218852650606410[169] = 0.0;
   out_2374218852650606410[170] = 0.0;
   out_2374218852650606410[171] = 1.0;
   out_2374218852650606410[172] = 0.0;
   out_2374218852650606410[173] = 0.0;
   out_2374218852650606410[174] = 0.0;
   out_2374218852650606410[175] = 0.0;
   out_2374218852650606410[176] = 0.0;
   out_2374218852650606410[177] = 0.0;
   out_2374218852650606410[178] = 0.0;
   out_2374218852650606410[179] = 0.0;
   out_2374218852650606410[180] = 0.0;
   out_2374218852650606410[181] = 0.0;
   out_2374218852650606410[182] = 0.0;
   out_2374218852650606410[183] = 0.0;
   out_2374218852650606410[184] = 0.0;
   out_2374218852650606410[185] = 0.0;
   out_2374218852650606410[186] = 0.0;
   out_2374218852650606410[187] = 0.0;
   out_2374218852650606410[188] = 0.0;
   out_2374218852650606410[189] = 0.0;
   out_2374218852650606410[190] = 1.0;
   out_2374218852650606410[191] = 0.0;
   out_2374218852650606410[192] = 0.0;
   out_2374218852650606410[193] = 0.0;
   out_2374218852650606410[194] = 0.0;
   out_2374218852650606410[195] = 0.0;
   out_2374218852650606410[196] = 0.0;
   out_2374218852650606410[197] = 0.0;
   out_2374218852650606410[198] = 0.0;
   out_2374218852650606410[199] = 0.0;
   out_2374218852650606410[200] = 0.0;
   out_2374218852650606410[201] = 0.0;
   out_2374218852650606410[202] = 0.0;
   out_2374218852650606410[203] = 0.0;
   out_2374218852650606410[204] = 0.0;
   out_2374218852650606410[205] = 0.0;
   out_2374218852650606410[206] = 0.0;
   out_2374218852650606410[207] = 0.0;
   out_2374218852650606410[208] = 0.0;
   out_2374218852650606410[209] = 1.0;
   out_2374218852650606410[210] = 0.0;
   out_2374218852650606410[211] = 0.0;
   out_2374218852650606410[212] = 0.0;
   out_2374218852650606410[213] = 0.0;
   out_2374218852650606410[214] = 0.0;
   out_2374218852650606410[215] = 0.0;
   out_2374218852650606410[216] = 0.0;
   out_2374218852650606410[217] = 0.0;
   out_2374218852650606410[218] = 0.0;
   out_2374218852650606410[219] = 0.0;
   out_2374218852650606410[220] = 0.0;
   out_2374218852650606410[221] = 0.0;
   out_2374218852650606410[222] = 0.0;
   out_2374218852650606410[223] = 0.0;
   out_2374218852650606410[224] = 0.0;
   out_2374218852650606410[225] = 0.0;
   out_2374218852650606410[226] = 0.0;
   out_2374218852650606410[227] = 0.0;
   out_2374218852650606410[228] = 1.0;
   out_2374218852650606410[229] = 0.0;
   out_2374218852650606410[230] = 0.0;
   out_2374218852650606410[231] = 0.0;
   out_2374218852650606410[232] = 0.0;
   out_2374218852650606410[233] = 0.0;
   out_2374218852650606410[234] = 0.0;
   out_2374218852650606410[235] = 0.0;
   out_2374218852650606410[236] = 0.0;
   out_2374218852650606410[237] = 0.0;
   out_2374218852650606410[238] = 0.0;
   out_2374218852650606410[239] = 0.0;
   out_2374218852650606410[240] = 0.0;
   out_2374218852650606410[241] = 0.0;
   out_2374218852650606410[242] = 0.0;
   out_2374218852650606410[243] = 0.0;
   out_2374218852650606410[244] = 0.0;
   out_2374218852650606410[245] = 0.0;
   out_2374218852650606410[246] = 0.0;
   out_2374218852650606410[247] = 1.0;
   out_2374218852650606410[248] = 0.0;
   out_2374218852650606410[249] = 0.0;
   out_2374218852650606410[250] = 0.0;
   out_2374218852650606410[251] = 0.0;
   out_2374218852650606410[252] = 0.0;
   out_2374218852650606410[253] = 0.0;
   out_2374218852650606410[254] = 0.0;
   out_2374218852650606410[255] = 0.0;
   out_2374218852650606410[256] = 0.0;
   out_2374218852650606410[257] = 0.0;
   out_2374218852650606410[258] = 0.0;
   out_2374218852650606410[259] = 0.0;
   out_2374218852650606410[260] = 0.0;
   out_2374218852650606410[261] = 0.0;
   out_2374218852650606410[262] = 0.0;
   out_2374218852650606410[263] = 0.0;
   out_2374218852650606410[264] = 0.0;
   out_2374218852650606410[265] = 0.0;
   out_2374218852650606410[266] = 1.0;
   out_2374218852650606410[267] = 0.0;
   out_2374218852650606410[268] = 0.0;
   out_2374218852650606410[269] = 0.0;
   out_2374218852650606410[270] = 0.0;
   out_2374218852650606410[271] = 0.0;
   out_2374218852650606410[272] = 0.0;
   out_2374218852650606410[273] = 0.0;
   out_2374218852650606410[274] = 0.0;
   out_2374218852650606410[275] = 0.0;
   out_2374218852650606410[276] = 0.0;
   out_2374218852650606410[277] = 0.0;
   out_2374218852650606410[278] = 0.0;
   out_2374218852650606410[279] = 0.0;
   out_2374218852650606410[280] = 0.0;
   out_2374218852650606410[281] = 0.0;
   out_2374218852650606410[282] = 0.0;
   out_2374218852650606410[283] = 0.0;
   out_2374218852650606410[284] = 0.0;
   out_2374218852650606410[285] = 1.0;
   out_2374218852650606410[286] = 0.0;
   out_2374218852650606410[287] = 0.0;
   out_2374218852650606410[288] = 0.0;
   out_2374218852650606410[289] = 0.0;
   out_2374218852650606410[290] = 0.0;
   out_2374218852650606410[291] = 0.0;
   out_2374218852650606410[292] = 0.0;
   out_2374218852650606410[293] = 0.0;
   out_2374218852650606410[294] = 0.0;
   out_2374218852650606410[295] = 0.0;
   out_2374218852650606410[296] = 0.0;
   out_2374218852650606410[297] = 0.0;
   out_2374218852650606410[298] = 0.0;
   out_2374218852650606410[299] = 0.0;
   out_2374218852650606410[300] = 0.0;
   out_2374218852650606410[301] = 0.0;
   out_2374218852650606410[302] = 0.0;
   out_2374218852650606410[303] = 0.0;
   out_2374218852650606410[304] = 1.0;
   out_2374218852650606410[305] = 0.0;
   out_2374218852650606410[306] = 0.0;
   out_2374218852650606410[307] = 0.0;
   out_2374218852650606410[308] = 0.0;
   out_2374218852650606410[309] = 0.0;
   out_2374218852650606410[310] = 0.0;
   out_2374218852650606410[311] = 0.0;
   out_2374218852650606410[312] = 0.0;
   out_2374218852650606410[313] = 0.0;
   out_2374218852650606410[314] = 0.0;
   out_2374218852650606410[315] = 0.0;
   out_2374218852650606410[316] = 0.0;
   out_2374218852650606410[317] = 0.0;
   out_2374218852650606410[318] = 0.0;
   out_2374218852650606410[319] = 0.0;
   out_2374218852650606410[320] = 0.0;
   out_2374218852650606410[321] = 0.0;
   out_2374218852650606410[322] = 0.0;
   out_2374218852650606410[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4392889107205501252) {
   out_4392889107205501252[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4392889107205501252[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4392889107205501252[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4392889107205501252[3] = dt*state[12] + state[3];
   out_4392889107205501252[4] = dt*state[13] + state[4];
   out_4392889107205501252[5] = dt*state[14] + state[5];
   out_4392889107205501252[6] = state[6];
   out_4392889107205501252[7] = state[7];
   out_4392889107205501252[8] = state[8];
   out_4392889107205501252[9] = state[9];
   out_4392889107205501252[10] = state[10];
   out_4392889107205501252[11] = state[11];
   out_4392889107205501252[12] = state[12];
   out_4392889107205501252[13] = state[13];
   out_4392889107205501252[14] = state[14];
   out_4392889107205501252[15] = state[15];
   out_4392889107205501252[16] = state[16];
   out_4392889107205501252[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5161498735714983758) {
   out_5161498735714983758[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5161498735714983758[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5161498735714983758[2] = 0;
   out_5161498735714983758[3] = 0;
   out_5161498735714983758[4] = 0;
   out_5161498735714983758[5] = 0;
   out_5161498735714983758[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5161498735714983758[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5161498735714983758[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5161498735714983758[9] = 0;
   out_5161498735714983758[10] = 0;
   out_5161498735714983758[11] = 0;
   out_5161498735714983758[12] = 0;
   out_5161498735714983758[13] = 0;
   out_5161498735714983758[14] = 0;
   out_5161498735714983758[15] = 0;
   out_5161498735714983758[16] = 0;
   out_5161498735714983758[17] = 0;
   out_5161498735714983758[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5161498735714983758[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5161498735714983758[20] = 0;
   out_5161498735714983758[21] = 0;
   out_5161498735714983758[22] = 0;
   out_5161498735714983758[23] = 0;
   out_5161498735714983758[24] = 0;
   out_5161498735714983758[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5161498735714983758[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5161498735714983758[27] = 0;
   out_5161498735714983758[28] = 0;
   out_5161498735714983758[29] = 0;
   out_5161498735714983758[30] = 0;
   out_5161498735714983758[31] = 0;
   out_5161498735714983758[32] = 0;
   out_5161498735714983758[33] = 0;
   out_5161498735714983758[34] = 0;
   out_5161498735714983758[35] = 0;
   out_5161498735714983758[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5161498735714983758[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5161498735714983758[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5161498735714983758[39] = 0;
   out_5161498735714983758[40] = 0;
   out_5161498735714983758[41] = 0;
   out_5161498735714983758[42] = 0;
   out_5161498735714983758[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5161498735714983758[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5161498735714983758[45] = 0;
   out_5161498735714983758[46] = 0;
   out_5161498735714983758[47] = 0;
   out_5161498735714983758[48] = 0;
   out_5161498735714983758[49] = 0;
   out_5161498735714983758[50] = 0;
   out_5161498735714983758[51] = 0;
   out_5161498735714983758[52] = 0;
   out_5161498735714983758[53] = 0;
   out_5161498735714983758[54] = 0;
   out_5161498735714983758[55] = 0;
   out_5161498735714983758[56] = 0;
   out_5161498735714983758[57] = 1;
   out_5161498735714983758[58] = 0;
   out_5161498735714983758[59] = 0;
   out_5161498735714983758[60] = 0;
   out_5161498735714983758[61] = 0;
   out_5161498735714983758[62] = 0;
   out_5161498735714983758[63] = 0;
   out_5161498735714983758[64] = 0;
   out_5161498735714983758[65] = 0;
   out_5161498735714983758[66] = dt;
   out_5161498735714983758[67] = 0;
   out_5161498735714983758[68] = 0;
   out_5161498735714983758[69] = 0;
   out_5161498735714983758[70] = 0;
   out_5161498735714983758[71] = 0;
   out_5161498735714983758[72] = 0;
   out_5161498735714983758[73] = 0;
   out_5161498735714983758[74] = 0;
   out_5161498735714983758[75] = 0;
   out_5161498735714983758[76] = 1;
   out_5161498735714983758[77] = 0;
   out_5161498735714983758[78] = 0;
   out_5161498735714983758[79] = 0;
   out_5161498735714983758[80] = 0;
   out_5161498735714983758[81] = 0;
   out_5161498735714983758[82] = 0;
   out_5161498735714983758[83] = 0;
   out_5161498735714983758[84] = 0;
   out_5161498735714983758[85] = dt;
   out_5161498735714983758[86] = 0;
   out_5161498735714983758[87] = 0;
   out_5161498735714983758[88] = 0;
   out_5161498735714983758[89] = 0;
   out_5161498735714983758[90] = 0;
   out_5161498735714983758[91] = 0;
   out_5161498735714983758[92] = 0;
   out_5161498735714983758[93] = 0;
   out_5161498735714983758[94] = 0;
   out_5161498735714983758[95] = 1;
   out_5161498735714983758[96] = 0;
   out_5161498735714983758[97] = 0;
   out_5161498735714983758[98] = 0;
   out_5161498735714983758[99] = 0;
   out_5161498735714983758[100] = 0;
   out_5161498735714983758[101] = 0;
   out_5161498735714983758[102] = 0;
   out_5161498735714983758[103] = 0;
   out_5161498735714983758[104] = dt;
   out_5161498735714983758[105] = 0;
   out_5161498735714983758[106] = 0;
   out_5161498735714983758[107] = 0;
   out_5161498735714983758[108] = 0;
   out_5161498735714983758[109] = 0;
   out_5161498735714983758[110] = 0;
   out_5161498735714983758[111] = 0;
   out_5161498735714983758[112] = 0;
   out_5161498735714983758[113] = 0;
   out_5161498735714983758[114] = 1;
   out_5161498735714983758[115] = 0;
   out_5161498735714983758[116] = 0;
   out_5161498735714983758[117] = 0;
   out_5161498735714983758[118] = 0;
   out_5161498735714983758[119] = 0;
   out_5161498735714983758[120] = 0;
   out_5161498735714983758[121] = 0;
   out_5161498735714983758[122] = 0;
   out_5161498735714983758[123] = 0;
   out_5161498735714983758[124] = 0;
   out_5161498735714983758[125] = 0;
   out_5161498735714983758[126] = 0;
   out_5161498735714983758[127] = 0;
   out_5161498735714983758[128] = 0;
   out_5161498735714983758[129] = 0;
   out_5161498735714983758[130] = 0;
   out_5161498735714983758[131] = 0;
   out_5161498735714983758[132] = 0;
   out_5161498735714983758[133] = 1;
   out_5161498735714983758[134] = 0;
   out_5161498735714983758[135] = 0;
   out_5161498735714983758[136] = 0;
   out_5161498735714983758[137] = 0;
   out_5161498735714983758[138] = 0;
   out_5161498735714983758[139] = 0;
   out_5161498735714983758[140] = 0;
   out_5161498735714983758[141] = 0;
   out_5161498735714983758[142] = 0;
   out_5161498735714983758[143] = 0;
   out_5161498735714983758[144] = 0;
   out_5161498735714983758[145] = 0;
   out_5161498735714983758[146] = 0;
   out_5161498735714983758[147] = 0;
   out_5161498735714983758[148] = 0;
   out_5161498735714983758[149] = 0;
   out_5161498735714983758[150] = 0;
   out_5161498735714983758[151] = 0;
   out_5161498735714983758[152] = 1;
   out_5161498735714983758[153] = 0;
   out_5161498735714983758[154] = 0;
   out_5161498735714983758[155] = 0;
   out_5161498735714983758[156] = 0;
   out_5161498735714983758[157] = 0;
   out_5161498735714983758[158] = 0;
   out_5161498735714983758[159] = 0;
   out_5161498735714983758[160] = 0;
   out_5161498735714983758[161] = 0;
   out_5161498735714983758[162] = 0;
   out_5161498735714983758[163] = 0;
   out_5161498735714983758[164] = 0;
   out_5161498735714983758[165] = 0;
   out_5161498735714983758[166] = 0;
   out_5161498735714983758[167] = 0;
   out_5161498735714983758[168] = 0;
   out_5161498735714983758[169] = 0;
   out_5161498735714983758[170] = 0;
   out_5161498735714983758[171] = 1;
   out_5161498735714983758[172] = 0;
   out_5161498735714983758[173] = 0;
   out_5161498735714983758[174] = 0;
   out_5161498735714983758[175] = 0;
   out_5161498735714983758[176] = 0;
   out_5161498735714983758[177] = 0;
   out_5161498735714983758[178] = 0;
   out_5161498735714983758[179] = 0;
   out_5161498735714983758[180] = 0;
   out_5161498735714983758[181] = 0;
   out_5161498735714983758[182] = 0;
   out_5161498735714983758[183] = 0;
   out_5161498735714983758[184] = 0;
   out_5161498735714983758[185] = 0;
   out_5161498735714983758[186] = 0;
   out_5161498735714983758[187] = 0;
   out_5161498735714983758[188] = 0;
   out_5161498735714983758[189] = 0;
   out_5161498735714983758[190] = 1;
   out_5161498735714983758[191] = 0;
   out_5161498735714983758[192] = 0;
   out_5161498735714983758[193] = 0;
   out_5161498735714983758[194] = 0;
   out_5161498735714983758[195] = 0;
   out_5161498735714983758[196] = 0;
   out_5161498735714983758[197] = 0;
   out_5161498735714983758[198] = 0;
   out_5161498735714983758[199] = 0;
   out_5161498735714983758[200] = 0;
   out_5161498735714983758[201] = 0;
   out_5161498735714983758[202] = 0;
   out_5161498735714983758[203] = 0;
   out_5161498735714983758[204] = 0;
   out_5161498735714983758[205] = 0;
   out_5161498735714983758[206] = 0;
   out_5161498735714983758[207] = 0;
   out_5161498735714983758[208] = 0;
   out_5161498735714983758[209] = 1;
   out_5161498735714983758[210] = 0;
   out_5161498735714983758[211] = 0;
   out_5161498735714983758[212] = 0;
   out_5161498735714983758[213] = 0;
   out_5161498735714983758[214] = 0;
   out_5161498735714983758[215] = 0;
   out_5161498735714983758[216] = 0;
   out_5161498735714983758[217] = 0;
   out_5161498735714983758[218] = 0;
   out_5161498735714983758[219] = 0;
   out_5161498735714983758[220] = 0;
   out_5161498735714983758[221] = 0;
   out_5161498735714983758[222] = 0;
   out_5161498735714983758[223] = 0;
   out_5161498735714983758[224] = 0;
   out_5161498735714983758[225] = 0;
   out_5161498735714983758[226] = 0;
   out_5161498735714983758[227] = 0;
   out_5161498735714983758[228] = 1;
   out_5161498735714983758[229] = 0;
   out_5161498735714983758[230] = 0;
   out_5161498735714983758[231] = 0;
   out_5161498735714983758[232] = 0;
   out_5161498735714983758[233] = 0;
   out_5161498735714983758[234] = 0;
   out_5161498735714983758[235] = 0;
   out_5161498735714983758[236] = 0;
   out_5161498735714983758[237] = 0;
   out_5161498735714983758[238] = 0;
   out_5161498735714983758[239] = 0;
   out_5161498735714983758[240] = 0;
   out_5161498735714983758[241] = 0;
   out_5161498735714983758[242] = 0;
   out_5161498735714983758[243] = 0;
   out_5161498735714983758[244] = 0;
   out_5161498735714983758[245] = 0;
   out_5161498735714983758[246] = 0;
   out_5161498735714983758[247] = 1;
   out_5161498735714983758[248] = 0;
   out_5161498735714983758[249] = 0;
   out_5161498735714983758[250] = 0;
   out_5161498735714983758[251] = 0;
   out_5161498735714983758[252] = 0;
   out_5161498735714983758[253] = 0;
   out_5161498735714983758[254] = 0;
   out_5161498735714983758[255] = 0;
   out_5161498735714983758[256] = 0;
   out_5161498735714983758[257] = 0;
   out_5161498735714983758[258] = 0;
   out_5161498735714983758[259] = 0;
   out_5161498735714983758[260] = 0;
   out_5161498735714983758[261] = 0;
   out_5161498735714983758[262] = 0;
   out_5161498735714983758[263] = 0;
   out_5161498735714983758[264] = 0;
   out_5161498735714983758[265] = 0;
   out_5161498735714983758[266] = 1;
   out_5161498735714983758[267] = 0;
   out_5161498735714983758[268] = 0;
   out_5161498735714983758[269] = 0;
   out_5161498735714983758[270] = 0;
   out_5161498735714983758[271] = 0;
   out_5161498735714983758[272] = 0;
   out_5161498735714983758[273] = 0;
   out_5161498735714983758[274] = 0;
   out_5161498735714983758[275] = 0;
   out_5161498735714983758[276] = 0;
   out_5161498735714983758[277] = 0;
   out_5161498735714983758[278] = 0;
   out_5161498735714983758[279] = 0;
   out_5161498735714983758[280] = 0;
   out_5161498735714983758[281] = 0;
   out_5161498735714983758[282] = 0;
   out_5161498735714983758[283] = 0;
   out_5161498735714983758[284] = 0;
   out_5161498735714983758[285] = 1;
   out_5161498735714983758[286] = 0;
   out_5161498735714983758[287] = 0;
   out_5161498735714983758[288] = 0;
   out_5161498735714983758[289] = 0;
   out_5161498735714983758[290] = 0;
   out_5161498735714983758[291] = 0;
   out_5161498735714983758[292] = 0;
   out_5161498735714983758[293] = 0;
   out_5161498735714983758[294] = 0;
   out_5161498735714983758[295] = 0;
   out_5161498735714983758[296] = 0;
   out_5161498735714983758[297] = 0;
   out_5161498735714983758[298] = 0;
   out_5161498735714983758[299] = 0;
   out_5161498735714983758[300] = 0;
   out_5161498735714983758[301] = 0;
   out_5161498735714983758[302] = 0;
   out_5161498735714983758[303] = 0;
   out_5161498735714983758[304] = 1;
   out_5161498735714983758[305] = 0;
   out_5161498735714983758[306] = 0;
   out_5161498735714983758[307] = 0;
   out_5161498735714983758[308] = 0;
   out_5161498735714983758[309] = 0;
   out_5161498735714983758[310] = 0;
   out_5161498735714983758[311] = 0;
   out_5161498735714983758[312] = 0;
   out_5161498735714983758[313] = 0;
   out_5161498735714983758[314] = 0;
   out_5161498735714983758[315] = 0;
   out_5161498735714983758[316] = 0;
   out_5161498735714983758[317] = 0;
   out_5161498735714983758[318] = 0;
   out_5161498735714983758[319] = 0;
   out_5161498735714983758[320] = 0;
   out_5161498735714983758[321] = 0;
   out_5161498735714983758[322] = 0;
   out_5161498735714983758[323] = 1;
}
void h_4(double *state, double *unused, double *out_6700070712992729001) {
   out_6700070712992729001[0] = state[6] + state[9];
   out_6700070712992729001[1] = state[7] + state[10];
   out_6700070712992729001[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_554520126744309549) {
   out_554520126744309549[0] = 0;
   out_554520126744309549[1] = 0;
   out_554520126744309549[2] = 0;
   out_554520126744309549[3] = 0;
   out_554520126744309549[4] = 0;
   out_554520126744309549[5] = 0;
   out_554520126744309549[6] = 1;
   out_554520126744309549[7] = 0;
   out_554520126744309549[8] = 0;
   out_554520126744309549[9] = 1;
   out_554520126744309549[10] = 0;
   out_554520126744309549[11] = 0;
   out_554520126744309549[12] = 0;
   out_554520126744309549[13] = 0;
   out_554520126744309549[14] = 0;
   out_554520126744309549[15] = 0;
   out_554520126744309549[16] = 0;
   out_554520126744309549[17] = 0;
   out_554520126744309549[18] = 0;
   out_554520126744309549[19] = 0;
   out_554520126744309549[20] = 0;
   out_554520126744309549[21] = 0;
   out_554520126744309549[22] = 0;
   out_554520126744309549[23] = 0;
   out_554520126744309549[24] = 0;
   out_554520126744309549[25] = 1;
   out_554520126744309549[26] = 0;
   out_554520126744309549[27] = 0;
   out_554520126744309549[28] = 1;
   out_554520126744309549[29] = 0;
   out_554520126744309549[30] = 0;
   out_554520126744309549[31] = 0;
   out_554520126744309549[32] = 0;
   out_554520126744309549[33] = 0;
   out_554520126744309549[34] = 0;
   out_554520126744309549[35] = 0;
   out_554520126744309549[36] = 0;
   out_554520126744309549[37] = 0;
   out_554520126744309549[38] = 0;
   out_554520126744309549[39] = 0;
   out_554520126744309549[40] = 0;
   out_554520126744309549[41] = 0;
   out_554520126744309549[42] = 0;
   out_554520126744309549[43] = 0;
   out_554520126744309549[44] = 1;
   out_554520126744309549[45] = 0;
   out_554520126744309549[46] = 0;
   out_554520126744309549[47] = 1;
   out_554520126744309549[48] = 0;
   out_554520126744309549[49] = 0;
   out_554520126744309549[50] = 0;
   out_554520126744309549[51] = 0;
   out_554520126744309549[52] = 0;
   out_554520126744309549[53] = 0;
}
void h_10(double *state, double *unused, double *out_326755883218172788) {
   out_326755883218172788[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_326755883218172788[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_326755883218172788[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3618077715207225770) {
   out_3618077715207225770[0] = 0;
   out_3618077715207225770[1] = 9.8100000000000005*cos(state[1]);
   out_3618077715207225770[2] = 0;
   out_3618077715207225770[3] = 0;
   out_3618077715207225770[4] = -state[8];
   out_3618077715207225770[5] = state[7];
   out_3618077715207225770[6] = 0;
   out_3618077715207225770[7] = state[5];
   out_3618077715207225770[8] = -state[4];
   out_3618077715207225770[9] = 0;
   out_3618077715207225770[10] = 0;
   out_3618077715207225770[11] = 0;
   out_3618077715207225770[12] = 1;
   out_3618077715207225770[13] = 0;
   out_3618077715207225770[14] = 0;
   out_3618077715207225770[15] = 1;
   out_3618077715207225770[16] = 0;
   out_3618077715207225770[17] = 0;
   out_3618077715207225770[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3618077715207225770[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3618077715207225770[20] = 0;
   out_3618077715207225770[21] = state[8];
   out_3618077715207225770[22] = 0;
   out_3618077715207225770[23] = -state[6];
   out_3618077715207225770[24] = -state[5];
   out_3618077715207225770[25] = 0;
   out_3618077715207225770[26] = state[3];
   out_3618077715207225770[27] = 0;
   out_3618077715207225770[28] = 0;
   out_3618077715207225770[29] = 0;
   out_3618077715207225770[30] = 0;
   out_3618077715207225770[31] = 1;
   out_3618077715207225770[32] = 0;
   out_3618077715207225770[33] = 0;
   out_3618077715207225770[34] = 1;
   out_3618077715207225770[35] = 0;
   out_3618077715207225770[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3618077715207225770[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3618077715207225770[38] = 0;
   out_3618077715207225770[39] = -state[7];
   out_3618077715207225770[40] = state[6];
   out_3618077715207225770[41] = 0;
   out_3618077715207225770[42] = state[4];
   out_3618077715207225770[43] = -state[3];
   out_3618077715207225770[44] = 0;
   out_3618077715207225770[45] = 0;
   out_3618077715207225770[46] = 0;
   out_3618077715207225770[47] = 0;
   out_3618077715207225770[48] = 0;
   out_3618077715207225770[49] = 0;
   out_3618077715207225770[50] = 1;
   out_3618077715207225770[51] = 0;
   out_3618077715207225770[52] = 0;
   out_3618077715207225770[53] = 1;
}
void h_13(double *state, double *unused, double *out_8852328989829848020) {
   out_8852328989829848020[0] = state[3];
   out_8852328989829848020[1] = state[4];
   out_8852328989829848020[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3279235336558214475) {
   out_3279235336558214475[0] = 0;
   out_3279235336558214475[1] = 0;
   out_3279235336558214475[2] = 0;
   out_3279235336558214475[3] = 1;
   out_3279235336558214475[4] = 0;
   out_3279235336558214475[5] = 0;
   out_3279235336558214475[6] = 0;
   out_3279235336558214475[7] = 0;
   out_3279235336558214475[8] = 0;
   out_3279235336558214475[9] = 0;
   out_3279235336558214475[10] = 0;
   out_3279235336558214475[11] = 0;
   out_3279235336558214475[12] = 0;
   out_3279235336558214475[13] = 0;
   out_3279235336558214475[14] = 0;
   out_3279235336558214475[15] = 0;
   out_3279235336558214475[16] = 0;
   out_3279235336558214475[17] = 0;
   out_3279235336558214475[18] = 0;
   out_3279235336558214475[19] = 0;
   out_3279235336558214475[20] = 0;
   out_3279235336558214475[21] = 0;
   out_3279235336558214475[22] = 1;
   out_3279235336558214475[23] = 0;
   out_3279235336558214475[24] = 0;
   out_3279235336558214475[25] = 0;
   out_3279235336558214475[26] = 0;
   out_3279235336558214475[27] = 0;
   out_3279235336558214475[28] = 0;
   out_3279235336558214475[29] = 0;
   out_3279235336558214475[30] = 0;
   out_3279235336558214475[31] = 0;
   out_3279235336558214475[32] = 0;
   out_3279235336558214475[33] = 0;
   out_3279235336558214475[34] = 0;
   out_3279235336558214475[35] = 0;
   out_3279235336558214475[36] = 0;
   out_3279235336558214475[37] = 0;
   out_3279235336558214475[38] = 0;
   out_3279235336558214475[39] = 0;
   out_3279235336558214475[40] = 0;
   out_3279235336558214475[41] = 1;
   out_3279235336558214475[42] = 0;
   out_3279235336558214475[43] = 0;
   out_3279235336558214475[44] = 0;
   out_3279235336558214475[45] = 0;
   out_3279235336558214475[46] = 0;
   out_3279235336558214475[47] = 0;
   out_3279235336558214475[48] = 0;
   out_3279235336558214475[49] = 0;
   out_3279235336558214475[50] = 0;
   out_3279235336558214475[51] = 0;
   out_3279235336558214475[52] = 0;
   out_3279235336558214475[53] = 0;
}
void h_14(double *state, double *unused, double *out_2099262646432106248) {
   out_2099262646432106248[0] = state[6];
   out_2099262646432106248[1] = state[7];
   out_2099262646432106248[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2528268305551062747) {
   out_2528268305551062747[0] = 0;
   out_2528268305551062747[1] = 0;
   out_2528268305551062747[2] = 0;
   out_2528268305551062747[3] = 0;
   out_2528268305551062747[4] = 0;
   out_2528268305551062747[5] = 0;
   out_2528268305551062747[6] = 1;
   out_2528268305551062747[7] = 0;
   out_2528268305551062747[8] = 0;
   out_2528268305551062747[9] = 0;
   out_2528268305551062747[10] = 0;
   out_2528268305551062747[11] = 0;
   out_2528268305551062747[12] = 0;
   out_2528268305551062747[13] = 0;
   out_2528268305551062747[14] = 0;
   out_2528268305551062747[15] = 0;
   out_2528268305551062747[16] = 0;
   out_2528268305551062747[17] = 0;
   out_2528268305551062747[18] = 0;
   out_2528268305551062747[19] = 0;
   out_2528268305551062747[20] = 0;
   out_2528268305551062747[21] = 0;
   out_2528268305551062747[22] = 0;
   out_2528268305551062747[23] = 0;
   out_2528268305551062747[24] = 0;
   out_2528268305551062747[25] = 1;
   out_2528268305551062747[26] = 0;
   out_2528268305551062747[27] = 0;
   out_2528268305551062747[28] = 0;
   out_2528268305551062747[29] = 0;
   out_2528268305551062747[30] = 0;
   out_2528268305551062747[31] = 0;
   out_2528268305551062747[32] = 0;
   out_2528268305551062747[33] = 0;
   out_2528268305551062747[34] = 0;
   out_2528268305551062747[35] = 0;
   out_2528268305551062747[36] = 0;
   out_2528268305551062747[37] = 0;
   out_2528268305551062747[38] = 0;
   out_2528268305551062747[39] = 0;
   out_2528268305551062747[40] = 0;
   out_2528268305551062747[41] = 0;
   out_2528268305551062747[42] = 0;
   out_2528268305551062747[43] = 0;
   out_2528268305551062747[44] = 1;
   out_2528268305551062747[45] = 0;
   out_2528268305551062747[46] = 0;
   out_2528268305551062747[47] = 0;
   out_2528268305551062747[48] = 0;
   out_2528268305551062747[49] = 0;
   out_2528268305551062747[50] = 0;
   out_2528268305551062747[51] = 0;
   out_2528268305551062747[52] = 0;
   out_2528268305551062747[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_9137514370372247790) {
  err_fun(nom_x, delta_x, out_9137514370372247790);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3476070474607186610) {
  inv_err_fun(nom_x, true_x, out_3476070474607186610);
}
void pose_H_mod_fun(double *state, double *out_2374218852650606410) {
  H_mod_fun(state, out_2374218852650606410);
}
void pose_f_fun(double *state, double dt, double *out_4392889107205501252) {
  f_fun(state,  dt, out_4392889107205501252);
}
void pose_F_fun(double *state, double dt, double *out_5161498735714983758) {
  F_fun(state,  dt, out_5161498735714983758);
}
void pose_h_4(double *state, double *unused, double *out_6700070712992729001) {
  h_4(state, unused, out_6700070712992729001);
}
void pose_H_4(double *state, double *unused, double *out_554520126744309549) {
  H_4(state, unused, out_554520126744309549);
}
void pose_h_10(double *state, double *unused, double *out_326755883218172788) {
  h_10(state, unused, out_326755883218172788);
}
void pose_H_10(double *state, double *unused, double *out_3618077715207225770) {
  H_10(state, unused, out_3618077715207225770);
}
void pose_h_13(double *state, double *unused, double *out_8852328989829848020) {
  h_13(state, unused, out_8852328989829848020);
}
void pose_H_13(double *state, double *unused, double *out_3279235336558214475) {
  H_13(state, unused, out_3279235336558214475);
}
void pose_h_14(double *state, double *unused, double *out_2099262646432106248) {
  h_14(state, unused, out_2099262646432106248);
}
void pose_H_14(double *state, double *unused, double *out_2528268305551062747) {
  H_14(state, unused, out_2528268305551062747);
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
