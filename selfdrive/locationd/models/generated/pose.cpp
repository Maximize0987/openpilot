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
void err_fun(double *nom_x, double *delta_x, double *out_709589957515877441) {
   out_709589957515877441[0] = delta_x[0] + nom_x[0];
   out_709589957515877441[1] = delta_x[1] + nom_x[1];
   out_709589957515877441[2] = delta_x[2] + nom_x[2];
   out_709589957515877441[3] = delta_x[3] + nom_x[3];
   out_709589957515877441[4] = delta_x[4] + nom_x[4];
   out_709589957515877441[5] = delta_x[5] + nom_x[5];
   out_709589957515877441[6] = delta_x[6] + nom_x[6];
   out_709589957515877441[7] = delta_x[7] + nom_x[7];
   out_709589957515877441[8] = delta_x[8] + nom_x[8];
   out_709589957515877441[9] = delta_x[9] + nom_x[9];
   out_709589957515877441[10] = delta_x[10] + nom_x[10];
   out_709589957515877441[11] = delta_x[11] + nom_x[11];
   out_709589957515877441[12] = delta_x[12] + nom_x[12];
   out_709589957515877441[13] = delta_x[13] + nom_x[13];
   out_709589957515877441[14] = delta_x[14] + nom_x[14];
   out_709589957515877441[15] = delta_x[15] + nom_x[15];
   out_709589957515877441[16] = delta_x[16] + nom_x[16];
   out_709589957515877441[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3661238081000149023) {
   out_3661238081000149023[0] = -nom_x[0] + true_x[0];
   out_3661238081000149023[1] = -nom_x[1] + true_x[1];
   out_3661238081000149023[2] = -nom_x[2] + true_x[2];
   out_3661238081000149023[3] = -nom_x[3] + true_x[3];
   out_3661238081000149023[4] = -nom_x[4] + true_x[4];
   out_3661238081000149023[5] = -nom_x[5] + true_x[5];
   out_3661238081000149023[6] = -nom_x[6] + true_x[6];
   out_3661238081000149023[7] = -nom_x[7] + true_x[7];
   out_3661238081000149023[8] = -nom_x[8] + true_x[8];
   out_3661238081000149023[9] = -nom_x[9] + true_x[9];
   out_3661238081000149023[10] = -nom_x[10] + true_x[10];
   out_3661238081000149023[11] = -nom_x[11] + true_x[11];
   out_3661238081000149023[12] = -nom_x[12] + true_x[12];
   out_3661238081000149023[13] = -nom_x[13] + true_x[13];
   out_3661238081000149023[14] = -nom_x[14] + true_x[14];
   out_3661238081000149023[15] = -nom_x[15] + true_x[15];
   out_3661238081000149023[16] = -nom_x[16] + true_x[16];
   out_3661238081000149023[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3274536842161333363) {
   out_3274536842161333363[0] = 1.0;
   out_3274536842161333363[1] = 0.0;
   out_3274536842161333363[2] = 0.0;
   out_3274536842161333363[3] = 0.0;
   out_3274536842161333363[4] = 0.0;
   out_3274536842161333363[5] = 0.0;
   out_3274536842161333363[6] = 0.0;
   out_3274536842161333363[7] = 0.0;
   out_3274536842161333363[8] = 0.0;
   out_3274536842161333363[9] = 0.0;
   out_3274536842161333363[10] = 0.0;
   out_3274536842161333363[11] = 0.0;
   out_3274536842161333363[12] = 0.0;
   out_3274536842161333363[13] = 0.0;
   out_3274536842161333363[14] = 0.0;
   out_3274536842161333363[15] = 0.0;
   out_3274536842161333363[16] = 0.0;
   out_3274536842161333363[17] = 0.0;
   out_3274536842161333363[18] = 0.0;
   out_3274536842161333363[19] = 1.0;
   out_3274536842161333363[20] = 0.0;
   out_3274536842161333363[21] = 0.0;
   out_3274536842161333363[22] = 0.0;
   out_3274536842161333363[23] = 0.0;
   out_3274536842161333363[24] = 0.0;
   out_3274536842161333363[25] = 0.0;
   out_3274536842161333363[26] = 0.0;
   out_3274536842161333363[27] = 0.0;
   out_3274536842161333363[28] = 0.0;
   out_3274536842161333363[29] = 0.0;
   out_3274536842161333363[30] = 0.0;
   out_3274536842161333363[31] = 0.0;
   out_3274536842161333363[32] = 0.0;
   out_3274536842161333363[33] = 0.0;
   out_3274536842161333363[34] = 0.0;
   out_3274536842161333363[35] = 0.0;
   out_3274536842161333363[36] = 0.0;
   out_3274536842161333363[37] = 0.0;
   out_3274536842161333363[38] = 1.0;
   out_3274536842161333363[39] = 0.0;
   out_3274536842161333363[40] = 0.0;
   out_3274536842161333363[41] = 0.0;
   out_3274536842161333363[42] = 0.0;
   out_3274536842161333363[43] = 0.0;
   out_3274536842161333363[44] = 0.0;
   out_3274536842161333363[45] = 0.0;
   out_3274536842161333363[46] = 0.0;
   out_3274536842161333363[47] = 0.0;
   out_3274536842161333363[48] = 0.0;
   out_3274536842161333363[49] = 0.0;
   out_3274536842161333363[50] = 0.0;
   out_3274536842161333363[51] = 0.0;
   out_3274536842161333363[52] = 0.0;
   out_3274536842161333363[53] = 0.0;
   out_3274536842161333363[54] = 0.0;
   out_3274536842161333363[55] = 0.0;
   out_3274536842161333363[56] = 0.0;
   out_3274536842161333363[57] = 1.0;
   out_3274536842161333363[58] = 0.0;
   out_3274536842161333363[59] = 0.0;
   out_3274536842161333363[60] = 0.0;
   out_3274536842161333363[61] = 0.0;
   out_3274536842161333363[62] = 0.0;
   out_3274536842161333363[63] = 0.0;
   out_3274536842161333363[64] = 0.0;
   out_3274536842161333363[65] = 0.0;
   out_3274536842161333363[66] = 0.0;
   out_3274536842161333363[67] = 0.0;
   out_3274536842161333363[68] = 0.0;
   out_3274536842161333363[69] = 0.0;
   out_3274536842161333363[70] = 0.0;
   out_3274536842161333363[71] = 0.0;
   out_3274536842161333363[72] = 0.0;
   out_3274536842161333363[73] = 0.0;
   out_3274536842161333363[74] = 0.0;
   out_3274536842161333363[75] = 0.0;
   out_3274536842161333363[76] = 1.0;
   out_3274536842161333363[77] = 0.0;
   out_3274536842161333363[78] = 0.0;
   out_3274536842161333363[79] = 0.0;
   out_3274536842161333363[80] = 0.0;
   out_3274536842161333363[81] = 0.0;
   out_3274536842161333363[82] = 0.0;
   out_3274536842161333363[83] = 0.0;
   out_3274536842161333363[84] = 0.0;
   out_3274536842161333363[85] = 0.0;
   out_3274536842161333363[86] = 0.0;
   out_3274536842161333363[87] = 0.0;
   out_3274536842161333363[88] = 0.0;
   out_3274536842161333363[89] = 0.0;
   out_3274536842161333363[90] = 0.0;
   out_3274536842161333363[91] = 0.0;
   out_3274536842161333363[92] = 0.0;
   out_3274536842161333363[93] = 0.0;
   out_3274536842161333363[94] = 0.0;
   out_3274536842161333363[95] = 1.0;
   out_3274536842161333363[96] = 0.0;
   out_3274536842161333363[97] = 0.0;
   out_3274536842161333363[98] = 0.0;
   out_3274536842161333363[99] = 0.0;
   out_3274536842161333363[100] = 0.0;
   out_3274536842161333363[101] = 0.0;
   out_3274536842161333363[102] = 0.0;
   out_3274536842161333363[103] = 0.0;
   out_3274536842161333363[104] = 0.0;
   out_3274536842161333363[105] = 0.0;
   out_3274536842161333363[106] = 0.0;
   out_3274536842161333363[107] = 0.0;
   out_3274536842161333363[108] = 0.0;
   out_3274536842161333363[109] = 0.0;
   out_3274536842161333363[110] = 0.0;
   out_3274536842161333363[111] = 0.0;
   out_3274536842161333363[112] = 0.0;
   out_3274536842161333363[113] = 0.0;
   out_3274536842161333363[114] = 1.0;
   out_3274536842161333363[115] = 0.0;
   out_3274536842161333363[116] = 0.0;
   out_3274536842161333363[117] = 0.0;
   out_3274536842161333363[118] = 0.0;
   out_3274536842161333363[119] = 0.0;
   out_3274536842161333363[120] = 0.0;
   out_3274536842161333363[121] = 0.0;
   out_3274536842161333363[122] = 0.0;
   out_3274536842161333363[123] = 0.0;
   out_3274536842161333363[124] = 0.0;
   out_3274536842161333363[125] = 0.0;
   out_3274536842161333363[126] = 0.0;
   out_3274536842161333363[127] = 0.0;
   out_3274536842161333363[128] = 0.0;
   out_3274536842161333363[129] = 0.0;
   out_3274536842161333363[130] = 0.0;
   out_3274536842161333363[131] = 0.0;
   out_3274536842161333363[132] = 0.0;
   out_3274536842161333363[133] = 1.0;
   out_3274536842161333363[134] = 0.0;
   out_3274536842161333363[135] = 0.0;
   out_3274536842161333363[136] = 0.0;
   out_3274536842161333363[137] = 0.0;
   out_3274536842161333363[138] = 0.0;
   out_3274536842161333363[139] = 0.0;
   out_3274536842161333363[140] = 0.0;
   out_3274536842161333363[141] = 0.0;
   out_3274536842161333363[142] = 0.0;
   out_3274536842161333363[143] = 0.0;
   out_3274536842161333363[144] = 0.0;
   out_3274536842161333363[145] = 0.0;
   out_3274536842161333363[146] = 0.0;
   out_3274536842161333363[147] = 0.0;
   out_3274536842161333363[148] = 0.0;
   out_3274536842161333363[149] = 0.0;
   out_3274536842161333363[150] = 0.0;
   out_3274536842161333363[151] = 0.0;
   out_3274536842161333363[152] = 1.0;
   out_3274536842161333363[153] = 0.0;
   out_3274536842161333363[154] = 0.0;
   out_3274536842161333363[155] = 0.0;
   out_3274536842161333363[156] = 0.0;
   out_3274536842161333363[157] = 0.0;
   out_3274536842161333363[158] = 0.0;
   out_3274536842161333363[159] = 0.0;
   out_3274536842161333363[160] = 0.0;
   out_3274536842161333363[161] = 0.0;
   out_3274536842161333363[162] = 0.0;
   out_3274536842161333363[163] = 0.0;
   out_3274536842161333363[164] = 0.0;
   out_3274536842161333363[165] = 0.0;
   out_3274536842161333363[166] = 0.0;
   out_3274536842161333363[167] = 0.0;
   out_3274536842161333363[168] = 0.0;
   out_3274536842161333363[169] = 0.0;
   out_3274536842161333363[170] = 0.0;
   out_3274536842161333363[171] = 1.0;
   out_3274536842161333363[172] = 0.0;
   out_3274536842161333363[173] = 0.0;
   out_3274536842161333363[174] = 0.0;
   out_3274536842161333363[175] = 0.0;
   out_3274536842161333363[176] = 0.0;
   out_3274536842161333363[177] = 0.0;
   out_3274536842161333363[178] = 0.0;
   out_3274536842161333363[179] = 0.0;
   out_3274536842161333363[180] = 0.0;
   out_3274536842161333363[181] = 0.0;
   out_3274536842161333363[182] = 0.0;
   out_3274536842161333363[183] = 0.0;
   out_3274536842161333363[184] = 0.0;
   out_3274536842161333363[185] = 0.0;
   out_3274536842161333363[186] = 0.0;
   out_3274536842161333363[187] = 0.0;
   out_3274536842161333363[188] = 0.0;
   out_3274536842161333363[189] = 0.0;
   out_3274536842161333363[190] = 1.0;
   out_3274536842161333363[191] = 0.0;
   out_3274536842161333363[192] = 0.0;
   out_3274536842161333363[193] = 0.0;
   out_3274536842161333363[194] = 0.0;
   out_3274536842161333363[195] = 0.0;
   out_3274536842161333363[196] = 0.0;
   out_3274536842161333363[197] = 0.0;
   out_3274536842161333363[198] = 0.0;
   out_3274536842161333363[199] = 0.0;
   out_3274536842161333363[200] = 0.0;
   out_3274536842161333363[201] = 0.0;
   out_3274536842161333363[202] = 0.0;
   out_3274536842161333363[203] = 0.0;
   out_3274536842161333363[204] = 0.0;
   out_3274536842161333363[205] = 0.0;
   out_3274536842161333363[206] = 0.0;
   out_3274536842161333363[207] = 0.0;
   out_3274536842161333363[208] = 0.0;
   out_3274536842161333363[209] = 1.0;
   out_3274536842161333363[210] = 0.0;
   out_3274536842161333363[211] = 0.0;
   out_3274536842161333363[212] = 0.0;
   out_3274536842161333363[213] = 0.0;
   out_3274536842161333363[214] = 0.0;
   out_3274536842161333363[215] = 0.0;
   out_3274536842161333363[216] = 0.0;
   out_3274536842161333363[217] = 0.0;
   out_3274536842161333363[218] = 0.0;
   out_3274536842161333363[219] = 0.0;
   out_3274536842161333363[220] = 0.0;
   out_3274536842161333363[221] = 0.0;
   out_3274536842161333363[222] = 0.0;
   out_3274536842161333363[223] = 0.0;
   out_3274536842161333363[224] = 0.0;
   out_3274536842161333363[225] = 0.0;
   out_3274536842161333363[226] = 0.0;
   out_3274536842161333363[227] = 0.0;
   out_3274536842161333363[228] = 1.0;
   out_3274536842161333363[229] = 0.0;
   out_3274536842161333363[230] = 0.0;
   out_3274536842161333363[231] = 0.0;
   out_3274536842161333363[232] = 0.0;
   out_3274536842161333363[233] = 0.0;
   out_3274536842161333363[234] = 0.0;
   out_3274536842161333363[235] = 0.0;
   out_3274536842161333363[236] = 0.0;
   out_3274536842161333363[237] = 0.0;
   out_3274536842161333363[238] = 0.0;
   out_3274536842161333363[239] = 0.0;
   out_3274536842161333363[240] = 0.0;
   out_3274536842161333363[241] = 0.0;
   out_3274536842161333363[242] = 0.0;
   out_3274536842161333363[243] = 0.0;
   out_3274536842161333363[244] = 0.0;
   out_3274536842161333363[245] = 0.0;
   out_3274536842161333363[246] = 0.0;
   out_3274536842161333363[247] = 1.0;
   out_3274536842161333363[248] = 0.0;
   out_3274536842161333363[249] = 0.0;
   out_3274536842161333363[250] = 0.0;
   out_3274536842161333363[251] = 0.0;
   out_3274536842161333363[252] = 0.0;
   out_3274536842161333363[253] = 0.0;
   out_3274536842161333363[254] = 0.0;
   out_3274536842161333363[255] = 0.0;
   out_3274536842161333363[256] = 0.0;
   out_3274536842161333363[257] = 0.0;
   out_3274536842161333363[258] = 0.0;
   out_3274536842161333363[259] = 0.0;
   out_3274536842161333363[260] = 0.0;
   out_3274536842161333363[261] = 0.0;
   out_3274536842161333363[262] = 0.0;
   out_3274536842161333363[263] = 0.0;
   out_3274536842161333363[264] = 0.0;
   out_3274536842161333363[265] = 0.0;
   out_3274536842161333363[266] = 1.0;
   out_3274536842161333363[267] = 0.0;
   out_3274536842161333363[268] = 0.0;
   out_3274536842161333363[269] = 0.0;
   out_3274536842161333363[270] = 0.0;
   out_3274536842161333363[271] = 0.0;
   out_3274536842161333363[272] = 0.0;
   out_3274536842161333363[273] = 0.0;
   out_3274536842161333363[274] = 0.0;
   out_3274536842161333363[275] = 0.0;
   out_3274536842161333363[276] = 0.0;
   out_3274536842161333363[277] = 0.0;
   out_3274536842161333363[278] = 0.0;
   out_3274536842161333363[279] = 0.0;
   out_3274536842161333363[280] = 0.0;
   out_3274536842161333363[281] = 0.0;
   out_3274536842161333363[282] = 0.0;
   out_3274536842161333363[283] = 0.0;
   out_3274536842161333363[284] = 0.0;
   out_3274536842161333363[285] = 1.0;
   out_3274536842161333363[286] = 0.0;
   out_3274536842161333363[287] = 0.0;
   out_3274536842161333363[288] = 0.0;
   out_3274536842161333363[289] = 0.0;
   out_3274536842161333363[290] = 0.0;
   out_3274536842161333363[291] = 0.0;
   out_3274536842161333363[292] = 0.0;
   out_3274536842161333363[293] = 0.0;
   out_3274536842161333363[294] = 0.0;
   out_3274536842161333363[295] = 0.0;
   out_3274536842161333363[296] = 0.0;
   out_3274536842161333363[297] = 0.0;
   out_3274536842161333363[298] = 0.0;
   out_3274536842161333363[299] = 0.0;
   out_3274536842161333363[300] = 0.0;
   out_3274536842161333363[301] = 0.0;
   out_3274536842161333363[302] = 0.0;
   out_3274536842161333363[303] = 0.0;
   out_3274536842161333363[304] = 1.0;
   out_3274536842161333363[305] = 0.0;
   out_3274536842161333363[306] = 0.0;
   out_3274536842161333363[307] = 0.0;
   out_3274536842161333363[308] = 0.0;
   out_3274536842161333363[309] = 0.0;
   out_3274536842161333363[310] = 0.0;
   out_3274536842161333363[311] = 0.0;
   out_3274536842161333363[312] = 0.0;
   out_3274536842161333363[313] = 0.0;
   out_3274536842161333363[314] = 0.0;
   out_3274536842161333363[315] = 0.0;
   out_3274536842161333363[316] = 0.0;
   out_3274536842161333363[317] = 0.0;
   out_3274536842161333363[318] = 0.0;
   out_3274536842161333363[319] = 0.0;
   out_3274536842161333363[320] = 0.0;
   out_3274536842161333363[321] = 0.0;
   out_3274536842161333363[322] = 0.0;
   out_3274536842161333363[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_54085149498667220) {
   out_54085149498667220[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_54085149498667220[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_54085149498667220[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_54085149498667220[3] = dt*state[12] + state[3];
   out_54085149498667220[4] = dt*state[13] + state[4];
   out_54085149498667220[5] = dt*state[14] + state[5];
   out_54085149498667220[6] = state[6];
   out_54085149498667220[7] = state[7];
   out_54085149498667220[8] = state[8];
   out_54085149498667220[9] = state[9];
   out_54085149498667220[10] = state[10];
   out_54085149498667220[11] = state[11];
   out_54085149498667220[12] = state[12];
   out_54085149498667220[13] = state[13];
   out_54085149498667220[14] = state[14];
   out_54085149498667220[15] = state[15];
   out_54085149498667220[16] = state[16];
   out_54085149498667220[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3360900556715541089) {
   out_3360900556715541089[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3360900556715541089[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3360900556715541089[2] = 0;
   out_3360900556715541089[3] = 0;
   out_3360900556715541089[4] = 0;
   out_3360900556715541089[5] = 0;
   out_3360900556715541089[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3360900556715541089[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3360900556715541089[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3360900556715541089[9] = 0;
   out_3360900556715541089[10] = 0;
   out_3360900556715541089[11] = 0;
   out_3360900556715541089[12] = 0;
   out_3360900556715541089[13] = 0;
   out_3360900556715541089[14] = 0;
   out_3360900556715541089[15] = 0;
   out_3360900556715541089[16] = 0;
   out_3360900556715541089[17] = 0;
   out_3360900556715541089[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3360900556715541089[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3360900556715541089[20] = 0;
   out_3360900556715541089[21] = 0;
   out_3360900556715541089[22] = 0;
   out_3360900556715541089[23] = 0;
   out_3360900556715541089[24] = 0;
   out_3360900556715541089[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3360900556715541089[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3360900556715541089[27] = 0;
   out_3360900556715541089[28] = 0;
   out_3360900556715541089[29] = 0;
   out_3360900556715541089[30] = 0;
   out_3360900556715541089[31] = 0;
   out_3360900556715541089[32] = 0;
   out_3360900556715541089[33] = 0;
   out_3360900556715541089[34] = 0;
   out_3360900556715541089[35] = 0;
   out_3360900556715541089[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3360900556715541089[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3360900556715541089[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3360900556715541089[39] = 0;
   out_3360900556715541089[40] = 0;
   out_3360900556715541089[41] = 0;
   out_3360900556715541089[42] = 0;
   out_3360900556715541089[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3360900556715541089[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3360900556715541089[45] = 0;
   out_3360900556715541089[46] = 0;
   out_3360900556715541089[47] = 0;
   out_3360900556715541089[48] = 0;
   out_3360900556715541089[49] = 0;
   out_3360900556715541089[50] = 0;
   out_3360900556715541089[51] = 0;
   out_3360900556715541089[52] = 0;
   out_3360900556715541089[53] = 0;
   out_3360900556715541089[54] = 0;
   out_3360900556715541089[55] = 0;
   out_3360900556715541089[56] = 0;
   out_3360900556715541089[57] = 1;
   out_3360900556715541089[58] = 0;
   out_3360900556715541089[59] = 0;
   out_3360900556715541089[60] = 0;
   out_3360900556715541089[61] = 0;
   out_3360900556715541089[62] = 0;
   out_3360900556715541089[63] = 0;
   out_3360900556715541089[64] = 0;
   out_3360900556715541089[65] = 0;
   out_3360900556715541089[66] = dt;
   out_3360900556715541089[67] = 0;
   out_3360900556715541089[68] = 0;
   out_3360900556715541089[69] = 0;
   out_3360900556715541089[70] = 0;
   out_3360900556715541089[71] = 0;
   out_3360900556715541089[72] = 0;
   out_3360900556715541089[73] = 0;
   out_3360900556715541089[74] = 0;
   out_3360900556715541089[75] = 0;
   out_3360900556715541089[76] = 1;
   out_3360900556715541089[77] = 0;
   out_3360900556715541089[78] = 0;
   out_3360900556715541089[79] = 0;
   out_3360900556715541089[80] = 0;
   out_3360900556715541089[81] = 0;
   out_3360900556715541089[82] = 0;
   out_3360900556715541089[83] = 0;
   out_3360900556715541089[84] = 0;
   out_3360900556715541089[85] = dt;
   out_3360900556715541089[86] = 0;
   out_3360900556715541089[87] = 0;
   out_3360900556715541089[88] = 0;
   out_3360900556715541089[89] = 0;
   out_3360900556715541089[90] = 0;
   out_3360900556715541089[91] = 0;
   out_3360900556715541089[92] = 0;
   out_3360900556715541089[93] = 0;
   out_3360900556715541089[94] = 0;
   out_3360900556715541089[95] = 1;
   out_3360900556715541089[96] = 0;
   out_3360900556715541089[97] = 0;
   out_3360900556715541089[98] = 0;
   out_3360900556715541089[99] = 0;
   out_3360900556715541089[100] = 0;
   out_3360900556715541089[101] = 0;
   out_3360900556715541089[102] = 0;
   out_3360900556715541089[103] = 0;
   out_3360900556715541089[104] = dt;
   out_3360900556715541089[105] = 0;
   out_3360900556715541089[106] = 0;
   out_3360900556715541089[107] = 0;
   out_3360900556715541089[108] = 0;
   out_3360900556715541089[109] = 0;
   out_3360900556715541089[110] = 0;
   out_3360900556715541089[111] = 0;
   out_3360900556715541089[112] = 0;
   out_3360900556715541089[113] = 0;
   out_3360900556715541089[114] = 1;
   out_3360900556715541089[115] = 0;
   out_3360900556715541089[116] = 0;
   out_3360900556715541089[117] = 0;
   out_3360900556715541089[118] = 0;
   out_3360900556715541089[119] = 0;
   out_3360900556715541089[120] = 0;
   out_3360900556715541089[121] = 0;
   out_3360900556715541089[122] = 0;
   out_3360900556715541089[123] = 0;
   out_3360900556715541089[124] = 0;
   out_3360900556715541089[125] = 0;
   out_3360900556715541089[126] = 0;
   out_3360900556715541089[127] = 0;
   out_3360900556715541089[128] = 0;
   out_3360900556715541089[129] = 0;
   out_3360900556715541089[130] = 0;
   out_3360900556715541089[131] = 0;
   out_3360900556715541089[132] = 0;
   out_3360900556715541089[133] = 1;
   out_3360900556715541089[134] = 0;
   out_3360900556715541089[135] = 0;
   out_3360900556715541089[136] = 0;
   out_3360900556715541089[137] = 0;
   out_3360900556715541089[138] = 0;
   out_3360900556715541089[139] = 0;
   out_3360900556715541089[140] = 0;
   out_3360900556715541089[141] = 0;
   out_3360900556715541089[142] = 0;
   out_3360900556715541089[143] = 0;
   out_3360900556715541089[144] = 0;
   out_3360900556715541089[145] = 0;
   out_3360900556715541089[146] = 0;
   out_3360900556715541089[147] = 0;
   out_3360900556715541089[148] = 0;
   out_3360900556715541089[149] = 0;
   out_3360900556715541089[150] = 0;
   out_3360900556715541089[151] = 0;
   out_3360900556715541089[152] = 1;
   out_3360900556715541089[153] = 0;
   out_3360900556715541089[154] = 0;
   out_3360900556715541089[155] = 0;
   out_3360900556715541089[156] = 0;
   out_3360900556715541089[157] = 0;
   out_3360900556715541089[158] = 0;
   out_3360900556715541089[159] = 0;
   out_3360900556715541089[160] = 0;
   out_3360900556715541089[161] = 0;
   out_3360900556715541089[162] = 0;
   out_3360900556715541089[163] = 0;
   out_3360900556715541089[164] = 0;
   out_3360900556715541089[165] = 0;
   out_3360900556715541089[166] = 0;
   out_3360900556715541089[167] = 0;
   out_3360900556715541089[168] = 0;
   out_3360900556715541089[169] = 0;
   out_3360900556715541089[170] = 0;
   out_3360900556715541089[171] = 1;
   out_3360900556715541089[172] = 0;
   out_3360900556715541089[173] = 0;
   out_3360900556715541089[174] = 0;
   out_3360900556715541089[175] = 0;
   out_3360900556715541089[176] = 0;
   out_3360900556715541089[177] = 0;
   out_3360900556715541089[178] = 0;
   out_3360900556715541089[179] = 0;
   out_3360900556715541089[180] = 0;
   out_3360900556715541089[181] = 0;
   out_3360900556715541089[182] = 0;
   out_3360900556715541089[183] = 0;
   out_3360900556715541089[184] = 0;
   out_3360900556715541089[185] = 0;
   out_3360900556715541089[186] = 0;
   out_3360900556715541089[187] = 0;
   out_3360900556715541089[188] = 0;
   out_3360900556715541089[189] = 0;
   out_3360900556715541089[190] = 1;
   out_3360900556715541089[191] = 0;
   out_3360900556715541089[192] = 0;
   out_3360900556715541089[193] = 0;
   out_3360900556715541089[194] = 0;
   out_3360900556715541089[195] = 0;
   out_3360900556715541089[196] = 0;
   out_3360900556715541089[197] = 0;
   out_3360900556715541089[198] = 0;
   out_3360900556715541089[199] = 0;
   out_3360900556715541089[200] = 0;
   out_3360900556715541089[201] = 0;
   out_3360900556715541089[202] = 0;
   out_3360900556715541089[203] = 0;
   out_3360900556715541089[204] = 0;
   out_3360900556715541089[205] = 0;
   out_3360900556715541089[206] = 0;
   out_3360900556715541089[207] = 0;
   out_3360900556715541089[208] = 0;
   out_3360900556715541089[209] = 1;
   out_3360900556715541089[210] = 0;
   out_3360900556715541089[211] = 0;
   out_3360900556715541089[212] = 0;
   out_3360900556715541089[213] = 0;
   out_3360900556715541089[214] = 0;
   out_3360900556715541089[215] = 0;
   out_3360900556715541089[216] = 0;
   out_3360900556715541089[217] = 0;
   out_3360900556715541089[218] = 0;
   out_3360900556715541089[219] = 0;
   out_3360900556715541089[220] = 0;
   out_3360900556715541089[221] = 0;
   out_3360900556715541089[222] = 0;
   out_3360900556715541089[223] = 0;
   out_3360900556715541089[224] = 0;
   out_3360900556715541089[225] = 0;
   out_3360900556715541089[226] = 0;
   out_3360900556715541089[227] = 0;
   out_3360900556715541089[228] = 1;
   out_3360900556715541089[229] = 0;
   out_3360900556715541089[230] = 0;
   out_3360900556715541089[231] = 0;
   out_3360900556715541089[232] = 0;
   out_3360900556715541089[233] = 0;
   out_3360900556715541089[234] = 0;
   out_3360900556715541089[235] = 0;
   out_3360900556715541089[236] = 0;
   out_3360900556715541089[237] = 0;
   out_3360900556715541089[238] = 0;
   out_3360900556715541089[239] = 0;
   out_3360900556715541089[240] = 0;
   out_3360900556715541089[241] = 0;
   out_3360900556715541089[242] = 0;
   out_3360900556715541089[243] = 0;
   out_3360900556715541089[244] = 0;
   out_3360900556715541089[245] = 0;
   out_3360900556715541089[246] = 0;
   out_3360900556715541089[247] = 1;
   out_3360900556715541089[248] = 0;
   out_3360900556715541089[249] = 0;
   out_3360900556715541089[250] = 0;
   out_3360900556715541089[251] = 0;
   out_3360900556715541089[252] = 0;
   out_3360900556715541089[253] = 0;
   out_3360900556715541089[254] = 0;
   out_3360900556715541089[255] = 0;
   out_3360900556715541089[256] = 0;
   out_3360900556715541089[257] = 0;
   out_3360900556715541089[258] = 0;
   out_3360900556715541089[259] = 0;
   out_3360900556715541089[260] = 0;
   out_3360900556715541089[261] = 0;
   out_3360900556715541089[262] = 0;
   out_3360900556715541089[263] = 0;
   out_3360900556715541089[264] = 0;
   out_3360900556715541089[265] = 0;
   out_3360900556715541089[266] = 1;
   out_3360900556715541089[267] = 0;
   out_3360900556715541089[268] = 0;
   out_3360900556715541089[269] = 0;
   out_3360900556715541089[270] = 0;
   out_3360900556715541089[271] = 0;
   out_3360900556715541089[272] = 0;
   out_3360900556715541089[273] = 0;
   out_3360900556715541089[274] = 0;
   out_3360900556715541089[275] = 0;
   out_3360900556715541089[276] = 0;
   out_3360900556715541089[277] = 0;
   out_3360900556715541089[278] = 0;
   out_3360900556715541089[279] = 0;
   out_3360900556715541089[280] = 0;
   out_3360900556715541089[281] = 0;
   out_3360900556715541089[282] = 0;
   out_3360900556715541089[283] = 0;
   out_3360900556715541089[284] = 0;
   out_3360900556715541089[285] = 1;
   out_3360900556715541089[286] = 0;
   out_3360900556715541089[287] = 0;
   out_3360900556715541089[288] = 0;
   out_3360900556715541089[289] = 0;
   out_3360900556715541089[290] = 0;
   out_3360900556715541089[291] = 0;
   out_3360900556715541089[292] = 0;
   out_3360900556715541089[293] = 0;
   out_3360900556715541089[294] = 0;
   out_3360900556715541089[295] = 0;
   out_3360900556715541089[296] = 0;
   out_3360900556715541089[297] = 0;
   out_3360900556715541089[298] = 0;
   out_3360900556715541089[299] = 0;
   out_3360900556715541089[300] = 0;
   out_3360900556715541089[301] = 0;
   out_3360900556715541089[302] = 0;
   out_3360900556715541089[303] = 0;
   out_3360900556715541089[304] = 1;
   out_3360900556715541089[305] = 0;
   out_3360900556715541089[306] = 0;
   out_3360900556715541089[307] = 0;
   out_3360900556715541089[308] = 0;
   out_3360900556715541089[309] = 0;
   out_3360900556715541089[310] = 0;
   out_3360900556715541089[311] = 0;
   out_3360900556715541089[312] = 0;
   out_3360900556715541089[313] = 0;
   out_3360900556715541089[314] = 0;
   out_3360900556715541089[315] = 0;
   out_3360900556715541089[316] = 0;
   out_3360900556715541089[317] = 0;
   out_3360900556715541089[318] = 0;
   out_3360900556715541089[319] = 0;
   out_3360900556715541089[320] = 0;
   out_3360900556715541089[321] = 0;
   out_3360900556715541089[322] = 0;
   out_3360900556715541089[323] = 1;
}
void h_4(double *state, double *unused, double *out_6781682784175939845) {
   out_6781682784175939845[0] = state[6] + state[9];
   out_6781682784175939845[1] = state[7] + state[10];
   out_6781682784175939845[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2076589360278435259) {
   out_2076589360278435259[0] = 0;
   out_2076589360278435259[1] = 0;
   out_2076589360278435259[2] = 0;
   out_2076589360278435259[3] = 0;
   out_2076589360278435259[4] = 0;
   out_2076589360278435259[5] = 0;
   out_2076589360278435259[6] = 1;
   out_2076589360278435259[7] = 0;
   out_2076589360278435259[8] = 0;
   out_2076589360278435259[9] = 1;
   out_2076589360278435259[10] = 0;
   out_2076589360278435259[11] = 0;
   out_2076589360278435259[12] = 0;
   out_2076589360278435259[13] = 0;
   out_2076589360278435259[14] = 0;
   out_2076589360278435259[15] = 0;
   out_2076589360278435259[16] = 0;
   out_2076589360278435259[17] = 0;
   out_2076589360278435259[18] = 0;
   out_2076589360278435259[19] = 0;
   out_2076589360278435259[20] = 0;
   out_2076589360278435259[21] = 0;
   out_2076589360278435259[22] = 0;
   out_2076589360278435259[23] = 0;
   out_2076589360278435259[24] = 0;
   out_2076589360278435259[25] = 1;
   out_2076589360278435259[26] = 0;
   out_2076589360278435259[27] = 0;
   out_2076589360278435259[28] = 1;
   out_2076589360278435259[29] = 0;
   out_2076589360278435259[30] = 0;
   out_2076589360278435259[31] = 0;
   out_2076589360278435259[32] = 0;
   out_2076589360278435259[33] = 0;
   out_2076589360278435259[34] = 0;
   out_2076589360278435259[35] = 0;
   out_2076589360278435259[36] = 0;
   out_2076589360278435259[37] = 0;
   out_2076589360278435259[38] = 0;
   out_2076589360278435259[39] = 0;
   out_2076589360278435259[40] = 0;
   out_2076589360278435259[41] = 0;
   out_2076589360278435259[42] = 0;
   out_2076589360278435259[43] = 0;
   out_2076589360278435259[44] = 1;
   out_2076589360278435259[45] = 0;
   out_2076589360278435259[46] = 0;
   out_2076589360278435259[47] = 1;
   out_2076589360278435259[48] = 0;
   out_2076589360278435259[49] = 0;
   out_2076589360278435259[50] = 0;
   out_2076589360278435259[51] = 0;
   out_2076589360278435259[52] = 0;
   out_2076589360278435259[53] = 0;
}
void h_10(double *state, double *unused, double *out_4409132040641892266) {
   out_4409132040641892266[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4409132040641892266[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4409132040641892266[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6826621589500186302) {
   out_6826621589500186302[0] = 0;
   out_6826621589500186302[1] = 9.8100000000000005*cos(state[1]);
   out_6826621589500186302[2] = 0;
   out_6826621589500186302[3] = 0;
   out_6826621589500186302[4] = -state[8];
   out_6826621589500186302[5] = state[7];
   out_6826621589500186302[6] = 0;
   out_6826621589500186302[7] = state[5];
   out_6826621589500186302[8] = -state[4];
   out_6826621589500186302[9] = 0;
   out_6826621589500186302[10] = 0;
   out_6826621589500186302[11] = 0;
   out_6826621589500186302[12] = 1;
   out_6826621589500186302[13] = 0;
   out_6826621589500186302[14] = 0;
   out_6826621589500186302[15] = 1;
   out_6826621589500186302[16] = 0;
   out_6826621589500186302[17] = 0;
   out_6826621589500186302[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6826621589500186302[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6826621589500186302[20] = 0;
   out_6826621589500186302[21] = state[8];
   out_6826621589500186302[22] = 0;
   out_6826621589500186302[23] = -state[6];
   out_6826621589500186302[24] = -state[5];
   out_6826621589500186302[25] = 0;
   out_6826621589500186302[26] = state[3];
   out_6826621589500186302[27] = 0;
   out_6826621589500186302[28] = 0;
   out_6826621589500186302[29] = 0;
   out_6826621589500186302[30] = 0;
   out_6826621589500186302[31] = 1;
   out_6826621589500186302[32] = 0;
   out_6826621589500186302[33] = 0;
   out_6826621589500186302[34] = 1;
   out_6826621589500186302[35] = 0;
   out_6826621589500186302[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6826621589500186302[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6826621589500186302[38] = 0;
   out_6826621589500186302[39] = -state[7];
   out_6826621589500186302[40] = state[6];
   out_6826621589500186302[41] = 0;
   out_6826621589500186302[42] = state[4];
   out_6826621589500186302[43] = -state[3];
   out_6826621589500186302[44] = 0;
   out_6826621589500186302[45] = 0;
   out_6826621589500186302[46] = 0;
   out_6826621589500186302[47] = 0;
   out_6826621589500186302[48] = 0;
   out_6826621589500186302[49] = 0;
   out_6826621589500186302[50] = 1;
   out_6826621589500186302[51] = 0;
   out_6826621589500186302[52] = 0;
   out_6826621589500186302[53] = 1;
}
void h_13(double *state, double *unused, double *out_1754250637475505882) {
   out_1754250637475505882[0] = state[3];
   out_1754250637475505882[1] = state[4];
   out_1754250637475505882[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1135684465053897542) {
   out_1135684465053897542[0] = 0;
   out_1135684465053897542[1] = 0;
   out_1135684465053897542[2] = 0;
   out_1135684465053897542[3] = 1;
   out_1135684465053897542[4] = 0;
   out_1135684465053897542[5] = 0;
   out_1135684465053897542[6] = 0;
   out_1135684465053897542[7] = 0;
   out_1135684465053897542[8] = 0;
   out_1135684465053897542[9] = 0;
   out_1135684465053897542[10] = 0;
   out_1135684465053897542[11] = 0;
   out_1135684465053897542[12] = 0;
   out_1135684465053897542[13] = 0;
   out_1135684465053897542[14] = 0;
   out_1135684465053897542[15] = 0;
   out_1135684465053897542[16] = 0;
   out_1135684465053897542[17] = 0;
   out_1135684465053897542[18] = 0;
   out_1135684465053897542[19] = 0;
   out_1135684465053897542[20] = 0;
   out_1135684465053897542[21] = 0;
   out_1135684465053897542[22] = 1;
   out_1135684465053897542[23] = 0;
   out_1135684465053897542[24] = 0;
   out_1135684465053897542[25] = 0;
   out_1135684465053897542[26] = 0;
   out_1135684465053897542[27] = 0;
   out_1135684465053897542[28] = 0;
   out_1135684465053897542[29] = 0;
   out_1135684465053897542[30] = 0;
   out_1135684465053897542[31] = 0;
   out_1135684465053897542[32] = 0;
   out_1135684465053897542[33] = 0;
   out_1135684465053897542[34] = 0;
   out_1135684465053897542[35] = 0;
   out_1135684465053897542[36] = 0;
   out_1135684465053897542[37] = 0;
   out_1135684465053897542[38] = 0;
   out_1135684465053897542[39] = 0;
   out_1135684465053897542[40] = 0;
   out_1135684465053897542[41] = 1;
   out_1135684465053897542[42] = 0;
   out_1135684465053897542[43] = 0;
   out_1135684465053897542[44] = 0;
   out_1135684465053897542[45] = 0;
   out_1135684465053897542[46] = 0;
   out_1135684465053897542[47] = 0;
   out_1135684465053897542[48] = 0;
   out_1135684465053897542[49] = 0;
   out_1135684465053897542[50] = 0;
   out_1135684465053897542[51] = 0;
   out_1135684465053897542[52] = 0;
   out_1135684465053897542[53] = 0;
}
void h_14(double *state, double *unused, double *out_2425630726311968111) {
   out_2425630726311968111[0] = state[6];
   out_2425630726311968111[1] = state[7];
   out_2425630726311968111[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1886651496061049270) {
   out_1886651496061049270[0] = 0;
   out_1886651496061049270[1] = 0;
   out_1886651496061049270[2] = 0;
   out_1886651496061049270[3] = 0;
   out_1886651496061049270[4] = 0;
   out_1886651496061049270[5] = 0;
   out_1886651496061049270[6] = 1;
   out_1886651496061049270[7] = 0;
   out_1886651496061049270[8] = 0;
   out_1886651496061049270[9] = 0;
   out_1886651496061049270[10] = 0;
   out_1886651496061049270[11] = 0;
   out_1886651496061049270[12] = 0;
   out_1886651496061049270[13] = 0;
   out_1886651496061049270[14] = 0;
   out_1886651496061049270[15] = 0;
   out_1886651496061049270[16] = 0;
   out_1886651496061049270[17] = 0;
   out_1886651496061049270[18] = 0;
   out_1886651496061049270[19] = 0;
   out_1886651496061049270[20] = 0;
   out_1886651496061049270[21] = 0;
   out_1886651496061049270[22] = 0;
   out_1886651496061049270[23] = 0;
   out_1886651496061049270[24] = 0;
   out_1886651496061049270[25] = 1;
   out_1886651496061049270[26] = 0;
   out_1886651496061049270[27] = 0;
   out_1886651496061049270[28] = 0;
   out_1886651496061049270[29] = 0;
   out_1886651496061049270[30] = 0;
   out_1886651496061049270[31] = 0;
   out_1886651496061049270[32] = 0;
   out_1886651496061049270[33] = 0;
   out_1886651496061049270[34] = 0;
   out_1886651496061049270[35] = 0;
   out_1886651496061049270[36] = 0;
   out_1886651496061049270[37] = 0;
   out_1886651496061049270[38] = 0;
   out_1886651496061049270[39] = 0;
   out_1886651496061049270[40] = 0;
   out_1886651496061049270[41] = 0;
   out_1886651496061049270[42] = 0;
   out_1886651496061049270[43] = 0;
   out_1886651496061049270[44] = 1;
   out_1886651496061049270[45] = 0;
   out_1886651496061049270[46] = 0;
   out_1886651496061049270[47] = 0;
   out_1886651496061049270[48] = 0;
   out_1886651496061049270[49] = 0;
   out_1886651496061049270[50] = 0;
   out_1886651496061049270[51] = 0;
   out_1886651496061049270[52] = 0;
   out_1886651496061049270[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_709589957515877441) {
  err_fun(nom_x, delta_x, out_709589957515877441);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3661238081000149023) {
  inv_err_fun(nom_x, true_x, out_3661238081000149023);
}
void pose_H_mod_fun(double *state, double *out_3274536842161333363) {
  H_mod_fun(state, out_3274536842161333363);
}
void pose_f_fun(double *state, double dt, double *out_54085149498667220) {
  f_fun(state,  dt, out_54085149498667220);
}
void pose_F_fun(double *state, double dt, double *out_3360900556715541089) {
  F_fun(state,  dt, out_3360900556715541089);
}
void pose_h_4(double *state, double *unused, double *out_6781682784175939845) {
  h_4(state, unused, out_6781682784175939845);
}
void pose_H_4(double *state, double *unused, double *out_2076589360278435259) {
  H_4(state, unused, out_2076589360278435259);
}
void pose_h_10(double *state, double *unused, double *out_4409132040641892266) {
  h_10(state, unused, out_4409132040641892266);
}
void pose_H_10(double *state, double *unused, double *out_6826621589500186302) {
  H_10(state, unused, out_6826621589500186302);
}
void pose_h_13(double *state, double *unused, double *out_1754250637475505882) {
  h_13(state, unused, out_1754250637475505882);
}
void pose_H_13(double *state, double *unused, double *out_1135684465053897542) {
  H_13(state, unused, out_1135684465053897542);
}
void pose_h_14(double *state, double *unused, double *out_2425630726311968111) {
  h_14(state, unused, out_2425630726311968111);
}
void pose_H_14(double *state, double *unused, double *out_1886651496061049270) {
  H_14(state, unused, out_1886651496061049270);
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
