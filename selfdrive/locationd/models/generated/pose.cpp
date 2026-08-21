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
void err_fun(double *nom_x, double *delta_x, double *out_4298502647758524793) {
   out_4298502647758524793[0] = delta_x[0] + nom_x[0];
   out_4298502647758524793[1] = delta_x[1] + nom_x[1];
   out_4298502647758524793[2] = delta_x[2] + nom_x[2];
   out_4298502647758524793[3] = delta_x[3] + nom_x[3];
   out_4298502647758524793[4] = delta_x[4] + nom_x[4];
   out_4298502647758524793[5] = delta_x[5] + nom_x[5];
   out_4298502647758524793[6] = delta_x[6] + nom_x[6];
   out_4298502647758524793[7] = delta_x[7] + nom_x[7];
   out_4298502647758524793[8] = delta_x[8] + nom_x[8];
   out_4298502647758524793[9] = delta_x[9] + nom_x[9];
   out_4298502647758524793[10] = delta_x[10] + nom_x[10];
   out_4298502647758524793[11] = delta_x[11] + nom_x[11];
   out_4298502647758524793[12] = delta_x[12] + nom_x[12];
   out_4298502647758524793[13] = delta_x[13] + nom_x[13];
   out_4298502647758524793[14] = delta_x[14] + nom_x[14];
   out_4298502647758524793[15] = delta_x[15] + nom_x[15];
   out_4298502647758524793[16] = delta_x[16] + nom_x[16];
   out_4298502647758524793[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5600470633109473941) {
   out_5600470633109473941[0] = -nom_x[0] + true_x[0];
   out_5600470633109473941[1] = -nom_x[1] + true_x[1];
   out_5600470633109473941[2] = -nom_x[2] + true_x[2];
   out_5600470633109473941[3] = -nom_x[3] + true_x[3];
   out_5600470633109473941[4] = -nom_x[4] + true_x[4];
   out_5600470633109473941[5] = -nom_x[5] + true_x[5];
   out_5600470633109473941[6] = -nom_x[6] + true_x[6];
   out_5600470633109473941[7] = -nom_x[7] + true_x[7];
   out_5600470633109473941[8] = -nom_x[8] + true_x[8];
   out_5600470633109473941[9] = -nom_x[9] + true_x[9];
   out_5600470633109473941[10] = -nom_x[10] + true_x[10];
   out_5600470633109473941[11] = -nom_x[11] + true_x[11];
   out_5600470633109473941[12] = -nom_x[12] + true_x[12];
   out_5600470633109473941[13] = -nom_x[13] + true_x[13];
   out_5600470633109473941[14] = -nom_x[14] + true_x[14];
   out_5600470633109473941[15] = -nom_x[15] + true_x[15];
   out_5600470633109473941[16] = -nom_x[16] + true_x[16];
   out_5600470633109473941[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5604237734398293519) {
   out_5604237734398293519[0] = 1.0;
   out_5604237734398293519[1] = 0.0;
   out_5604237734398293519[2] = 0.0;
   out_5604237734398293519[3] = 0.0;
   out_5604237734398293519[4] = 0.0;
   out_5604237734398293519[5] = 0.0;
   out_5604237734398293519[6] = 0.0;
   out_5604237734398293519[7] = 0.0;
   out_5604237734398293519[8] = 0.0;
   out_5604237734398293519[9] = 0.0;
   out_5604237734398293519[10] = 0.0;
   out_5604237734398293519[11] = 0.0;
   out_5604237734398293519[12] = 0.0;
   out_5604237734398293519[13] = 0.0;
   out_5604237734398293519[14] = 0.0;
   out_5604237734398293519[15] = 0.0;
   out_5604237734398293519[16] = 0.0;
   out_5604237734398293519[17] = 0.0;
   out_5604237734398293519[18] = 0.0;
   out_5604237734398293519[19] = 1.0;
   out_5604237734398293519[20] = 0.0;
   out_5604237734398293519[21] = 0.0;
   out_5604237734398293519[22] = 0.0;
   out_5604237734398293519[23] = 0.0;
   out_5604237734398293519[24] = 0.0;
   out_5604237734398293519[25] = 0.0;
   out_5604237734398293519[26] = 0.0;
   out_5604237734398293519[27] = 0.0;
   out_5604237734398293519[28] = 0.0;
   out_5604237734398293519[29] = 0.0;
   out_5604237734398293519[30] = 0.0;
   out_5604237734398293519[31] = 0.0;
   out_5604237734398293519[32] = 0.0;
   out_5604237734398293519[33] = 0.0;
   out_5604237734398293519[34] = 0.0;
   out_5604237734398293519[35] = 0.0;
   out_5604237734398293519[36] = 0.0;
   out_5604237734398293519[37] = 0.0;
   out_5604237734398293519[38] = 1.0;
   out_5604237734398293519[39] = 0.0;
   out_5604237734398293519[40] = 0.0;
   out_5604237734398293519[41] = 0.0;
   out_5604237734398293519[42] = 0.0;
   out_5604237734398293519[43] = 0.0;
   out_5604237734398293519[44] = 0.0;
   out_5604237734398293519[45] = 0.0;
   out_5604237734398293519[46] = 0.0;
   out_5604237734398293519[47] = 0.0;
   out_5604237734398293519[48] = 0.0;
   out_5604237734398293519[49] = 0.0;
   out_5604237734398293519[50] = 0.0;
   out_5604237734398293519[51] = 0.0;
   out_5604237734398293519[52] = 0.0;
   out_5604237734398293519[53] = 0.0;
   out_5604237734398293519[54] = 0.0;
   out_5604237734398293519[55] = 0.0;
   out_5604237734398293519[56] = 0.0;
   out_5604237734398293519[57] = 1.0;
   out_5604237734398293519[58] = 0.0;
   out_5604237734398293519[59] = 0.0;
   out_5604237734398293519[60] = 0.0;
   out_5604237734398293519[61] = 0.0;
   out_5604237734398293519[62] = 0.0;
   out_5604237734398293519[63] = 0.0;
   out_5604237734398293519[64] = 0.0;
   out_5604237734398293519[65] = 0.0;
   out_5604237734398293519[66] = 0.0;
   out_5604237734398293519[67] = 0.0;
   out_5604237734398293519[68] = 0.0;
   out_5604237734398293519[69] = 0.0;
   out_5604237734398293519[70] = 0.0;
   out_5604237734398293519[71] = 0.0;
   out_5604237734398293519[72] = 0.0;
   out_5604237734398293519[73] = 0.0;
   out_5604237734398293519[74] = 0.0;
   out_5604237734398293519[75] = 0.0;
   out_5604237734398293519[76] = 1.0;
   out_5604237734398293519[77] = 0.0;
   out_5604237734398293519[78] = 0.0;
   out_5604237734398293519[79] = 0.0;
   out_5604237734398293519[80] = 0.0;
   out_5604237734398293519[81] = 0.0;
   out_5604237734398293519[82] = 0.0;
   out_5604237734398293519[83] = 0.0;
   out_5604237734398293519[84] = 0.0;
   out_5604237734398293519[85] = 0.0;
   out_5604237734398293519[86] = 0.0;
   out_5604237734398293519[87] = 0.0;
   out_5604237734398293519[88] = 0.0;
   out_5604237734398293519[89] = 0.0;
   out_5604237734398293519[90] = 0.0;
   out_5604237734398293519[91] = 0.0;
   out_5604237734398293519[92] = 0.0;
   out_5604237734398293519[93] = 0.0;
   out_5604237734398293519[94] = 0.0;
   out_5604237734398293519[95] = 1.0;
   out_5604237734398293519[96] = 0.0;
   out_5604237734398293519[97] = 0.0;
   out_5604237734398293519[98] = 0.0;
   out_5604237734398293519[99] = 0.0;
   out_5604237734398293519[100] = 0.0;
   out_5604237734398293519[101] = 0.0;
   out_5604237734398293519[102] = 0.0;
   out_5604237734398293519[103] = 0.0;
   out_5604237734398293519[104] = 0.0;
   out_5604237734398293519[105] = 0.0;
   out_5604237734398293519[106] = 0.0;
   out_5604237734398293519[107] = 0.0;
   out_5604237734398293519[108] = 0.0;
   out_5604237734398293519[109] = 0.0;
   out_5604237734398293519[110] = 0.0;
   out_5604237734398293519[111] = 0.0;
   out_5604237734398293519[112] = 0.0;
   out_5604237734398293519[113] = 0.0;
   out_5604237734398293519[114] = 1.0;
   out_5604237734398293519[115] = 0.0;
   out_5604237734398293519[116] = 0.0;
   out_5604237734398293519[117] = 0.0;
   out_5604237734398293519[118] = 0.0;
   out_5604237734398293519[119] = 0.0;
   out_5604237734398293519[120] = 0.0;
   out_5604237734398293519[121] = 0.0;
   out_5604237734398293519[122] = 0.0;
   out_5604237734398293519[123] = 0.0;
   out_5604237734398293519[124] = 0.0;
   out_5604237734398293519[125] = 0.0;
   out_5604237734398293519[126] = 0.0;
   out_5604237734398293519[127] = 0.0;
   out_5604237734398293519[128] = 0.0;
   out_5604237734398293519[129] = 0.0;
   out_5604237734398293519[130] = 0.0;
   out_5604237734398293519[131] = 0.0;
   out_5604237734398293519[132] = 0.0;
   out_5604237734398293519[133] = 1.0;
   out_5604237734398293519[134] = 0.0;
   out_5604237734398293519[135] = 0.0;
   out_5604237734398293519[136] = 0.0;
   out_5604237734398293519[137] = 0.0;
   out_5604237734398293519[138] = 0.0;
   out_5604237734398293519[139] = 0.0;
   out_5604237734398293519[140] = 0.0;
   out_5604237734398293519[141] = 0.0;
   out_5604237734398293519[142] = 0.0;
   out_5604237734398293519[143] = 0.0;
   out_5604237734398293519[144] = 0.0;
   out_5604237734398293519[145] = 0.0;
   out_5604237734398293519[146] = 0.0;
   out_5604237734398293519[147] = 0.0;
   out_5604237734398293519[148] = 0.0;
   out_5604237734398293519[149] = 0.0;
   out_5604237734398293519[150] = 0.0;
   out_5604237734398293519[151] = 0.0;
   out_5604237734398293519[152] = 1.0;
   out_5604237734398293519[153] = 0.0;
   out_5604237734398293519[154] = 0.0;
   out_5604237734398293519[155] = 0.0;
   out_5604237734398293519[156] = 0.0;
   out_5604237734398293519[157] = 0.0;
   out_5604237734398293519[158] = 0.0;
   out_5604237734398293519[159] = 0.0;
   out_5604237734398293519[160] = 0.0;
   out_5604237734398293519[161] = 0.0;
   out_5604237734398293519[162] = 0.0;
   out_5604237734398293519[163] = 0.0;
   out_5604237734398293519[164] = 0.0;
   out_5604237734398293519[165] = 0.0;
   out_5604237734398293519[166] = 0.0;
   out_5604237734398293519[167] = 0.0;
   out_5604237734398293519[168] = 0.0;
   out_5604237734398293519[169] = 0.0;
   out_5604237734398293519[170] = 0.0;
   out_5604237734398293519[171] = 1.0;
   out_5604237734398293519[172] = 0.0;
   out_5604237734398293519[173] = 0.0;
   out_5604237734398293519[174] = 0.0;
   out_5604237734398293519[175] = 0.0;
   out_5604237734398293519[176] = 0.0;
   out_5604237734398293519[177] = 0.0;
   out_5604237734398293519[178] = 0.0;
   out_5604237734398293519[179] = 0.0;
   out_5604237734398293519[180] = 0.0;
   out_5604237734398293519[181] = 0.0;
   out_5604237734398293519[182] = 0.0;
   out_5604237734398293519[183] = 0.0;
   out_5604237734398293519[184] = 0.0;
   out_5604237734398293519[185] = 0.0;
   out_5604237734398293519[186] = 0.0;
   out_5604237734398293519[187] = 0.0;
   out_5604237734398293519[188] = 0.0;
   out_5604237734398293519[189] = 0.0;
   out_5604237734398293519[190] = 1.0;
   out_5604237734398293519[191] = 0.0;
   out_5604237734398293519[192] = 0.0;
   out_5604237734398293519[193] = 0.0;
   out_5604237734398293519[194] = 0.0;
   out_5604237734398293519[195] = 0.0;
   out_5604237734398293519[196] = 0.0;
   out_5604237734398293519[197] = 0.0;
   out_5604237734398293519[198] = 0.0;
   out_5604237734398293519[199] = 0.0;
   out_5604237734398293519[200] = 0.0;
   out_5604237734398293519[201] = 0.0;
   out_5604237734398293519[202] = 0.0;
   out_5604237734398293519[203] = 0.0;
   out_5604237734398293519[204] = 0.0;
   out_5604237734398293519[205] = 0.0;
   out_5604237734398293519[206] = 0.0;
   out_5604237734398293519[207] = 0.0;
   out_5604237734398293519[208] = 0.0;
   out_5604237734398293519[209] = 1.0;
   out_5604237734398293519[210] = 0.0;
   out_5604237734398293519[211] = 0.0;
   out_5604237734398293519[212] = 0.0;
   out_5604237734398293519[213] = 0.0;
   out_5604237734398293519[214] = 0.0;
   out_5604237734398293519[215] = 0.0;
   out_5604237734398293519[216] = 0.0;
   out_5604237734398293519[217] = 0.0;
   out_5604237734398293519[218] = 0.0;
   out_5604237734398293519[219] = 0.0;
   out_5604237734398293519[220] = 0.0;
   out_5604237734398293519[221] = 0.0;
   out_5604237734398293519[222] = 0.0;
   out_5604237734398293519[223] = 0.0;
   out_5604237734398293519[224] = 0.0;
   out_5604237734398293519[225] = 0.0;
   out_5604237734398293519[226] = 0.0;
   out_5604237734398293519[227] = 0.0;
   out_5604237734398293519[228] = 1.0;
   out_5604237734398293519[229] = 0.0;
   out_5604237734398293519[230] = 0.0;
   out_5604237734398293519[231] = 0.0;
   out_5604237734398293519[232] = 0.0;
   out_5604237734398293519[233] = 0.0;
   out_5604237734398293519[234] = 0.0;
   out_5604237734398293519[235] = 0.0;
   out_5604237734398293519[236] = 0.0;
   out_5604237734398293519[237] = 0.0;
   out_5604237734398293519[238] = 0.0;
   out_5604237734398293519[239] = 0.0;
   out_5604237734398293519[240] = 0.0;
   out_5604237734398293519[241] = 0.0;
   out_5604237734398293519[242] = 0.0;
   out_5604237734398293519[243] = 0.0;
   out_5604237734398293519[244] = 0.0;
   out_5604237734398293519[245] = 0.0;
   out_5604237734398293519[246] = 0.0;
   out_5604237734398293519[247] = 1.0;
   out_5604237734398293519[248] = 0.0;
   out_5604237734398293519[249] = 0.0;
   out_5604237734398293519[250] = 0.0;
   out_5604237734398293519[251] = 0.0;
   out_5604237734398293519[252] = 0.0;
   out_5604237734398293519[253] = 0.0;
   out_5604237734398293519[254] = 0.0;
   out_5604237734398293519[255] = 0.0;
   out_5604237734398293519[256] = 0.0;
   out_5604237734398293519[257] = 0.0;
   out_5604237734398293519[258] = 0.0;
   out_5604237734398293519[259] = 0.0;
   out_5604237734398293519[260] = 0.0;
   out_5604237734398293519[261] = 0.0;
   out_5604237734398293519[262] = 0.0;
   out_5604237734398293519[263] = 0.0;
   out_5604237734398293519[264] = 0.0;
   out_5604237734398293519[265] = 0.0;
   out_5604237734398293519[266] = 1.0;
   out_5604237734398293519[267] = 0.0;
   out_5604237734398293519[268] = 0.0;
   out_5604237734398293519[269] = 0.0;
   out_5604237734398293519[270] = 0.0;
   out_5604237734398293519[271] = 0.0;
   out_5604237734398293519[272] = 0.0;
   out_5604237734398293519[273] = 0.0;
   out_5604237734398293519[274] = 0.0;
   out_5604237734398293519[275] = 0.0;
   out_5604237734398293519[276] = 0.0;
   out_5604237734398293519[277] = 0.0;
   out_5604237734398293519[278] = 0.0;
   out_5604237734398293519[279] = 0.0;
   out_5604237734398293519[280] = 0.0;
   out_5604237734398293519[281] = 0.0;
   out_5604237734398293519[282] = 0.0;
   out_5604237734398293519[283] = 0.0;
   out_5604237734398293519[284] = 0.0;
   out_5604237734398293519[285] = 1.0;
   out_5604237734398293519[286] = 0.0;
   out_5604237734398293519[287] = 0.0;
   out_5604237734398293519[288] = 0.0;
   out_5604237734398293519[289] = 0.0;
   out_5604237734398293519[290] = 0.0;
   out_5604237734398293519[291] = 0.0;
   out_5604237734398293519[292] = 0.0;
   out_5604237734398293519[293] = 0.0;
   out_5604237734398293519[294] = 0.0;
   out_5604237734398293519[295] = 0.0;
   out_5604237734398293519[296] = 0.0;
   out_5604237734398293519[297] = 0.0;
   out_5604237734398293519[298] = 0.0;
   out_5604237734398293519[299] = 0.0;
   out_5604237734398293519[300] = 0.0;
   out_5604237734398293519[301] = 0.0;
   out_5604237734398293519[302] = 0.0;
   out_5604237734398293519[303] = 0.0;
   out_5604237734398293519[304] = 1.0;
   out_5604237734398293519[305] = 0.0;
   out_5604237734398293519[306] = 0.0;
   out_5604237734398293519[307] = 0.0;
   out_5604237734398293519[308] = 0.0;
   out_5604237734398293519[309] = 0.0;
   out_5604237734398293519[310] = 0.0;
   out_5604237734398293519[311] = 0.0;
   out_5604237734398293519[312] = 0.0;
   out_5604237734398293519[313] = 0.0;
   out_5604237734398293519[314] = 0.0;
   out_5604237734398293519[315] = 0.0;
   out_5604237734398293519[316] = 0.0;
   out_5604237734398293519[317] = 0.0;
   out_5604237734398293519[318] = 0.0;
   out_5604237734398293519[319] = 0.0;
   out_5604237734398293519[320] = 0.0;
   out_5604237734398293519[321] = 0.0;
   out_5604237734398293519[322] = 0.0;
   out_5604237734398293519[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1603951998531582898) {
   out_1603951998531582898[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1603951998531582898[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1603951998531582898[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1603951998531582898[3] = dt*state[12] + state[3];
   out_1603951998531582898[4] = dt*state[13] + state[4];
   out_1603951998531582898[5] = dt*state[14] + state[5];
   out_1603951998531582898[6] = state[6];
   out_1603951998531582898[7] = state[7];
   out_1603951998531582898[8] = state[8];
   out_1603951998531582898[9] = state[9];
   out_1603951998531582898[10] = state[10];
   out_1603951998531582898[11] = state[11];
   out_1603951998531582898[12] = state[12];
   out_1603951998531582898[13] = state[13];
   out_1603951998531582898[14] = state[14];
   out_1603951998531582898[15] = state[15];
   out_1603951998531582898[16] = state[16];
   out_1603951998531582898[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7355016791857912131) {
   out_7355016791857912131[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7355016791857912131[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7355016791857912131[2] = 0;
   out_7355016791857912131[3] = 0;
   out_7355016791857912131[4] = 0;
   out_7355016791857912131[5] = 0;
   out_7355016791857912131[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7355016791857912131[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7355016791857912131[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7355016791857912131[9] = 0;
   out_7355016791857912131[10] = 0;
   out_7355016791857912131[11] = 0;
   out_7355016791857912131[12] = 0;
   out_7355016791857912131[13] = 0;
   out_7355016791857912131[14] = 0;
   out_7355016791857912131[15] = 0;
   out_7355016791857912131[16] = 0;
   out_7355016791857912131[17] = 0;
   out_7355016791857912131[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7355016791857912131[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7355016791857912131[20] = 0;
   out_7355016791857912131[21] = 0;
   out_7355016791857912131[22] = 0;
   out_7355016791857912131[23] = 0;
   out_7355016791857912131[24] = 0;
   out_7355016791857912131[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7355016791857912131[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7355016791857912131[27] = 0;
   out_7355016791857912131[28] = 0;
   out_7355016791857912131[29] = 0;
   out_7355016791857912131[30] = 0;
   out_7355016791857912131[31] = 0;
   out_7355016791857912131[32] = 0;
   out_7355016791857912131[33] = 0;
   out_7355016791857912131[34] = 0;
   out_7355016791857912131[35] = 0;
   out_7355016791857912131[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7355016791857912131[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7355016791857912131[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7355016791857912131[39] = 0;
   out_7355016791857912131[40] = 0;
   out_7355016791857912131[41] = 0;
   out_7355016791857912131[42] = 0;
   out_7355016791857912131[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7355016791857912131[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7355016791857912131[45] = 0;
   out_7355016791857912131[46] = 0;
   out_7355016791857912131[47] = 0;
   out_7355016791857912131[48] = 0;
   out_7355016791857912131[49] = 0;
   out_7355016791857912131[50] = 0;
   out_7355016791857912131[51] = 0;
   out_7355016791857912131[52] = 0;
   out_7355016791857912131[53] = 0;
   out_7355016791857912131[54] = 0;
   out_7355016791857912131[55] = 0;
   out_7355016791857912131[56] = 0;
   out_7355016791857912131[57] = 1;
   out_7355016791857912131[58] = 0;
   out_7355016791857912131[59] = 0;
   out_7355016791857912131[60] = 0;
   out_7355016791857912131[61] = 0;
   out_7355016791857912131[62] = 0;
   out_7355016791857912131[63] = 0;
   out_7355016791857912131[64] = 0;
   out_7355016791857912131[65] = 0;
   out_7355016791857912131[66] = dt;
   out_7355016791857912131[67] = 0;
   out_7355016791857912131[68] = 0;
   out_7355016791857912131[69] = 0;
   out_7355016791857912131[70] = 0;
   out_7355016791857912131[71] = 0;
   out_7355016791857912131[72] = 0;
   out_7355016791857912131[73] = 0;
   out_7355016791857912131[74] = 0;
   out_7355016791857912131[75] = 0;
   out_7355016791857912131[76] = 1;
   out_7355016791857912131[77] = 0;
   out_7355016791857912131[78] = 0;
   out_7355016791857912131[79] = 0;
   out_7355016791857912131[80] = 0;
   out_7355016791857912131[81] = 0;
   out_7355016791857912131[82] = 0;
   out_7355016791857912131[83] = 0;
   out_7355016791857912131[84] = 0;
   out_7355016791857912131[85] = dt;
   out_7355016791857912131[86] = 0;
   out_7355016791857912131[87] = 0;
   out_7355016791857912131[88] = 0;
   out_7355016791857912131[89] = 0;
   out_7355016791857912131[90] = 0;
   out_7355016791857912131[91] = 0;
   out_7355016791857912131[92] = 0;
   out_7355016791857912131[93] = 0;
   out_7355016791857912131[94] = 0;
   out_7355016791857912131[95] = 1;
   out_7355016791857912131[96] = 0;
   out_7355016791857912131[97] = 0;
   out_7355016791857912131[98] = 0;
   out_7355016791857912131[99] = 0;
   out_7355016791857912131[100] = 0;
   out_7355016791857912131[101] = 0;
   out_7355016791857912131[102] = 0;
   out_7355016791857912131[103] = 0;
   out_7355016791857912131[104] = dt;
   out_7355016791857912131[105] = 0;
   out_7355016791857912131[106] = 0;
   out_7355016791857912131[107] = 0;
   out_7355016791857912131[108] = 0;
   out_7355016791857912131[109] = 0;
   out_7355016791857912131[110] = 0;
   out_7355016791857912131[111] = 0;
   out_7355016791857912131[112] = 0;
   out_7355016791857912131[113] = 0;
   out_7355016791857912131[114] = 1;
   out_7355016791857912131[115] = 0;
   out_7355016791857912131[116] = 0;
   out_7355016791857912131[117] = 0;
   out_7355016791857912131[118] = 0;
   out_7355016791857912131[119] = 0;
   out_7355016791857912131[120] = 0;
   out_7355016791857912131[121] = 0;
   out_7355016791857912131[122] = 0;
   out_7355016791857912131[123] = 0;
   out_7355016791857912131[124] = 0;
   out_7355016791857912131[125] = 0;
   out_7355016791857912131[126] = 0;
   out_7355016791857912131[127] = 0;
   out_7355016791857912131[128] = 0;
   out_7355016791857912131[129] = 0;
   out_7355016791857912131[130] = 0;
   out_7355016791857912131[131] = 0;
   out_7355016791857912131[132] = 0;
   out_7355016791857912131[133] = 1;
   out_7355016791857912131[134] = 0;
   out_7355016791857912131[135] = 0;
   out_7355016791857912131[136] = 0;
   out_7355016791857912131[137] = 0;
   out_7355016791857912131[138] = 0;
   out_7355016791857912131[139] = 0;
   out_7355016791857912131[140] = 0;
   out_7355016791857912131[141] = 0;
   out_7355016791857912131[142] = 0;
   out_7355016791857912131[143] = 0;
   out_7355016791857912131[144] = 0;
   out_7355016791857912131[145] = 0;
   out_7355016791857912131[146] = 0;
   out_7355016791857912131[147] = 0;
   out_7355016791857912131[148] = 0;
   out_7355016791857912131[149] = 0;
   out_7355016791857912131[150] = 0;
   out_7355016791857912131[151] = 0;
   out_7355016791857912131[152] = 1;
   out_7355016791857912131[153] = 0;
   out_7355016791857912131[154] = 0;
   out_7355016791857912131[155] = 0;
   out_7355016791857912131[156] = 0;
   out_7355016791857912131[157] = 0;
   out_7355016791857912131[158] = 0;
   out_7355016791857912131[159] = 0;
   out_7355016791857912131[160] = 0;
   out_7355016791857912131[161] = 0;
   out_7355016791857912131[162] = 0;
   out_7355016791857912131[163] = 0;
   out_7355016791857912131[164] = 0;
   out_7355016791857912131[165] = 0;
   out_7355016791857912131[166] = 0;
   out_7355016791857912131[167] = 0;
   out_7355016791857912131[168] = 0;
   out_7355016791857912131[169] = 0;
   out_7355016791857912131[170] = 0;
   out_7355016791857912131[171] = 1;
   out_7355016791857912131[172] = 0;
   out_7355016791857912131[173] = 0;
   out_7355016791857912131[174] = 0;
   out_7355016791857912131[175] = 0;
   out_7355016791857912131[176] = 0;
   out_7355016791857912131[177] = 0;
   out_7355016791857912131[178] = 0;
   out_7355016791857912131[179] = 0;
   out_7355016791857912131[180] = 0;
   out_7355016791857912131[181] = 0;
   out_7355016791857912131[182] = 0;
   out_7355016791857912131[183] = 0;
   out_7355016791857912131[184] = 0;
   out_7355016791857912131[185] = 0;
   out_7355016791857912131[186] = 0;
   out_7355016791857912131[187] = 0;
   out_7355016791857912131[188] = 0;
   out_7355016791857912131[189] = 0;
   out_7355016791857912131[190] = 1;
   out_7355016791857912131[191] = 0;
   out_7355016791857912131[192] = 0;
   out_7355016791857912131[193] = 0;
   out_7355016791857912131[194] = 0;
   out_7355016791857912131[195] = 0;
   out_7355016791857912131[196] = 0;
   out_7355016791857912131[197] = 0;
   out_7355016791857912131[198] = 0;
   out_7355016791857912131[199] = 0;
   out_7355016791857912131[200] = 0;
   out_7355016791857912131[201] = 0;
   out_7355016791857912131[202] = 0;
   out_7355016791857912131[203] = 0;
   out_7355016791857912131[204] = 0;
   out_7355016791857912131[205] = 0;
   out_7355016791857912131[206] = 0;
   out_7355016791857912131[207] = 0;
   out_7355016791857912131[208] = 0;
   out_7355016791857912131[209] = 1;
   out_7355016791857912131[210] = 0;
   out_7355016791857912131[211] = 0;
   out_7355016791857912131[212] = 0;
   out_7355016791857912131[213] = 0;
   out_7355016791857912131[214] = 0;
   out_7355016791857912131[215] = 0;
   out_7355016791857912131[216] = 0;
   out_7355016791857912131[217] = 0;
   out_7355016791857912131[218] = 0;
   out_7355016791857912131[219] = 0;
   out_7355016791857912131[220] = 0;
   out_7355016791857912131[221] = 0;
   out_7355016791857912131[222] = 0;
   out_7355016791857912131[223] = 0;
   out_7355016791857912131[224] = 0;
   out_7355016791857912131[225] = 0;
   out_7355016791857912131[226] = 0;
   out_7355016791857912131[227] = 0;
   out_7355016791857912131[228] = 1;
   out_7355016791857912131[229] = 0;
   out_7355016791857912131[230] = 0;
   out_7355016791857912131[231] = 0;
   out_7355016791857912131[232] = 0;
   out_7355016791857912131[233] = 0;
   out_7355016791857912131[234] = 0;
   out_7355016791857912131[235] = 0;
   out_7355016791857912131[236] = 0;
   out_7355016791857912131[237] = 0;
   out_7355016791857912131[238] = 0;
   out_7355016791857912131[239] = 0;
   out_7355016791857912131[240] = 0;
   out_7355016791857912131[241] = 0;
   out_7355016791857912131[242] = 0;
   out_7355016791857912131[243] = 0;
   out_7355016791857912131[244] = 0;
   out_7355016791857912131[245] = 0;
   out_7355016791857912131[246] = 0;
   out_7355016791857912131[247] = 1;
   out_7355016791857912131[248] = 0;
   out_7355016791857912131[249] = 0;
   out_7355016791857912131[250] = 0;
   out_7355016791857912131[251] = 0;
   out_7355016791857912131[252] = 0;
   out_7355016791857912131[253] = 0;
   out_7355016791857912131[254] = 0;
   out_7355016791857912131[255] = 0;
   out_7355016791857912131[256] = 0;
   out_7355016791857912131[257] = 0;
   out_7355016791857912131[258] = 0;
   out_7355016791857912131[259] = 0;
   out_7355016791857912131[260] = 0;
   out_7355016791857912131[261] = 0;
   out_7355016791857912131[262] = 0;
   out_7355016791857912131[263] = 0;
   out_7355016791857912131[264] = 0;
   out_7355016791857912131[265] = 0;
   out_7355016791857912131[266] = 1;
   out_7355016791857912131[267] = 0;
   out_7355016791857912131[268] = 0;
   out_7355016791857912131[269] = 0;
   out_7355016791857912131[270] = 0;
   out_7355016791857912131[271] = 0;
   out_7355016791857912131[272] = 0;
   out_7355016791857912131[273] = 0;
   out_7355016791857912131[274] = 0;
   out_7355016791857912131[275] = 0;
   out_7355016791857912131[276] = 0;
   out_7355016791857912131[277] = 0;
   out_7355016791857912131[278] = 0;
   out_7355016791857912131[279] = 0;
   out_7355016791857912131[280] = 0;
   out_7355016791857912131[281] = 0;
   out_7355016791857912131[282] = 0;
   out_7355016791857912131[283] = 0;
   out_7355016791857912131[284] = 0;
   out_7355016791857912131[285] = 1;
   out_7355016791857912131[286] = 0;
   out_7355016791857912131[287] = 0;
   out_7355016791857912131[288] = 0;
   out_7355016791857912131[289] = 0;
   out_7355016791857912131[290] = 0;
   out_7355016791857912131[291] = 0;
   out_7355016791857912131[292] = 0;
   out_7355016791857912131[293] = 0;
   out_7355016791857912131[294] = 0;
   out_7355016791857912131[295] = 0;
   out_7355016791857912131[296] = 0;
   out_7355016791857912131[297] = 0;
   out_7355016791857912131[298] = 0;
   out_7355016791857912131[299] = 0;
   out_7355016791857912131[300] = 0;
   out_7355016791857912131[301] = 0;
   out_7355016791857912131[302] = 0;
   out_7355016791857912131[303] = 0;
   out_7355016791857912131[304] = 1;
   out_7355016791857912131[305] = 0;
   out_7355016791857912131[306] = 0;
   out_7355016791857912131[307] = 0;
   out_7355016791857912131[308] = 0;
   out_7355016791857912131[309] = 0;
   out_7355016791857912131[310] = 0;
   out_7355016791857912131[311] = 0;
   out_7355016791857912131[312] = 0;
   out_7355016791857912131[313] = 0;
   out_7355016791857912131[314] = 0;
   out_7355016791857912131[315] = 0;
   out_7355016791857912131[316] = 0;
   out_7355016791857912131[317] = 0;
   out_7355016791857912131[318] = 0;
   out_7355016791857912131[319] = 0;
   out_7355016791857912131[320] = 0;
   out_7355016791857912131[321] = 0;
   out_7355016791857912131[322] = 0;
   out_7355016791857912131[323] = 1;
}
void h_4(double *state, double *unused, double *out_3151076657578519351) {
   out_3151076657578519351[0] = state[6] + state[9];
   out_3151076657578519351[1] = state[7] + state[10];
   out_3151076657578519351[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_9070699129467350525) {
   out_9070699129467350525[0] = 0;
   out_9070699129467350525[1] = 0;
   out_9070699129467350525[2] = 0;
   out_9070699129467350525[3] = 0;
   out_9070699129467350525[4] = 0;
   out_9070699129467350525[5] = 0;
   out_9070699129467350525[6] = 1;
   out_9070699129467350525[7] = 0;
   out_9070699129467350525[8] = 0;
   out_9070699129467350525[9] = 1;
   out_9070699129467350525[10] = 0;
   out_9070699129467350525[11] = 0;
   out_9070699129467350525[12] = 0;
   out_9070699129467350525[13] = 0;
   out_9070699129467350525[14] = 0;
   out_9070699129467350525[15] = 0;
   out_9070699129467350525[16] = 0;
   out_9070699129467350525[17] = 0;
   out_9070699129467350525[18] = 0;
   out_9070699129467350525[19] = 0;
   out_9070699129467350525[20] = 0;
   out_9070699129467350525[21] = 0;
   out_9070699129467350525[22] = 0;
   out_9070699129467350525[23] = 0;
   out_9070699129467350525[24] = 0;
   out_9070699129467350525[25] = 1;
   out_9070699129467350525[26] = 0;
   out_9070699129467350525[27] = 0;
   out_9070699129467350525[28] = 1;
   out_9070699129467350525[29] = 0;
   out_9070699129467350525[30] = 0;
   out_9070699129467350525[31] = 0;
   out_9070699129467350525[32] = 0;
   out_9070699129467350525[33] = 0;
   out_9070699129467350525[34] = 0;
   out_9070699129467350525[35] = 0;
   out_9070699129467350525[36] = 0;
   out_9070699129467350525[37] = 0;
   out_9070699129467350525[38] = 0;
   out_9070699129467350525[39] = 0;
   out_9070699129467350525[40] = 0;
   out_9070699129467350525[41] = 0;
   out_9070699129467350525[42] = 0;
   out_9070699129467350525[43] = 0;
   out_9070699129467350525[44] = 1;
   out_9070699129467350525[45] = 0;
   out_9070699129467350525[46] = 0;
   out_9070699129467350525[47] = 1;
   out_9070699129467350525[48] = 0;
   out_9070699129467350525[49] = 0;
   out_9070699129467350525[50] = 0;
   out_9070699129467350525[51] = 0;
   out_9070699129467350525[52] = 0;
   out_9070699129467350525[53] = 0;
}
void h_10(double *state, double *unused, double *out_6670778953679817884) {
   out_6670778953679817884[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6670778953679817884[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6670778953679817884[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8318326309939820808) {
   out_8318326309939820808[0] = 0;
   out_8318326309939820808[1] = 9.8100000000000005*cos(state[1]);
   out_8318326309939820808[2] = 0;
   out_8318326309939820808[3] = 0;
   out_8318326309939820808[4] = -state[8];
   out_8318326309939820808[5] = state[7];
   out_8318326309939820808[6] = 0;
   out_8318326309939820808[7] = state[5];
   out_8318326309939820808[8] = -state[4];
   out_8318326309939820808[9] = 0;
   out_8318326309939820808[10] = 0;
   out_8318326309939820808[11] = 0;
   out_8318326309939820808[12] = 1;
   out_8318326309939820808[13] = 0;
   out_8318326309939820808[14] = 0;
   out_8318326309939820808[15] = 1;
   out_8318326309939820808[16] = 0;
   out_8318326309939820808[17] = 0;
   out_8318326309939820808[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8318326309939820808[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8318326309939820808[20] = 0;
   out_8318326309939820808[21] = state[8];
   out_8318326309939820808[22] = 0;
   out_8318326309939820808[23] = -state[6];
   out_8318326309939820808[24] = -state[5];
   out_8318326309939820808[25] = 0;
   out_8318326309939820808[26] = state[3];
   out_8318326309939820808[27] = 0;
   out_8318326309939820808[28] = 0;
   out_8318326309939820808[29] = 0;
   out_8318326309939820808[30] = 0;
   out_8318326309939820808[31] = 1;
   out_8318326309939820808[32] = 0;
   out_8318326309939820808[33] = 0;
   out_8318326309939820808[34] = 1;
   out_8318326309939820808[35] = 0;
   out_8318326309939820808[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8318326309939820808[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8318326309939820808[38] = 0;
   out_8318326309939820808[39] = -state[7];
   out_8318326309939820808[40] = state[6];
   out_8318326309939820808[41] = 0;
   out_8318326309939820808[42] = state[4];
   out_8318326309939820808[43] = -state[3];
   out_8318326309939820808[44] = 0;
   out_8318326309939820808[45] = 0;
   out_8318326309939820808[46] = 0;
   out_8318326309939820808[47] = 0;
   out_8318326309939820808[48] = 0;
   out_8318326309939820808[49] = 0;
   out_8318326309939820808[50] = 1;
   out_8318326309939820808[51] = 0;
   out_8318326309939820808[52] = 0;
   out_8318326309939820808[53] = 1;
}
void h_13(double *state, double *unused, double *out_8670142885989515415) {
   out_8670142885989515415[0] = state[3];
   out_8670142885989515415[1] = state[4];
   out_8670142885989515415[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5542289480939677067) {
   out_5542289480939677067[0] = 0;
   out_5542289480939677067[1] = 0;
   out_5542289480939677067[2] = 0;
   out_5542289480939677067[3] = 1;
   out_5542289480939677067[4] = 0;
   out_5542289480939677067[5] = 0;
   out_5542289480939677067[6] = 0;
   out_5542289480939677067[7] = 0;
   out_5542289480939677067[8] = 0;
   out_5542289480939677067[9] = 0;
   out_5542289480939677067[10] = 0;
   out_5542289480939677067[11] = 0;
   out_5542289480939677067[12] = 0;
   out_5542289480939677067[13] = 0;
   out_5542289480939677067[14] = 0;
   out_5542289480939677067[15] = 0;
   out_5542289480939677067[16] = 0;
   out_5542289480939677067[17] = 0;
   out_5542289480939677067[18] = 0;
   out_5542289480939677067[19] = 0;
   out_5542289480939677067[20] = 0;
   out_5542289480939677067[21] = 0;
   out_5542289480939677067[22] = 1;
   out_5542289480939677067[23] = 0;
   out_5542289480939677067[24] = 0;
   out_5542289480939677067[25] = 0;
   out_5542289480939677067[26] = 0;
   out_5542289480939677067[27] = 0;
   out_5542289480939677067[28] = 0;
   out_5542289480939677067[29] = 0;
   out_5542289480939677067[30] = 0;
   out_5542289480939677067[31] = 0;
   out_5542289480939677067[32] = 0;
   out_5542289480939677067[33] = 0;
   out_5542289480939677067[34] = 0;
   out_5542289480939677067[35] = 0;
   out_5542289480939677067[36] = 0;
   out_5542289480939677067[37] = 0;
   out_5542289480939677067[38] = 0;
   out_5542289480939677067[39] = 0;
   out_5542289480939677067[40] = 0;
   out_5542289480939677067[41] = 1;
   out_5542289480939677067[42] = 0;
   out_5542289480939677067[43] = 0;
   out_5542289480939677067[44] = 0;
   out_5542289480939677067[45] = 0;
   out_5542289480939677067[46] = 0;
   out_5542289480939677067[47] = 0;
   out_5542289480939677067[48] = 0;
   out_5542289480939677067[49] = 0;
   out_5542289480939677067[50] = 0;
   out_5542289480939677067[51] = 0;
   out_5542289480939677067[52] = 0;
   out_5542289480939677067[53] = 0;
}
void h_14(double *state, double *unused, double *out_3946013715221375238) {
   out_3946013715221375238[0] = state[6];
   out_3946013715221375238[1] = state[7];
   out_3946013715221375238[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6293256511946828795) {
   out_6293256511946828795[0] = 0;
   out_6293256511946828795[1] = 0;
   out_6293256511946828795[2] = 0;
   out_6293256511946828795[3] = 0;
   out_6293256511946828795[4] = 0;
   out_6293256511946828795[5] = 0;
   out_6293256511946828795[6] = 1;
   out_6293256511946828795[7] = 0;
   out_6293256511946828795[8] = 0;
   out_6293256511946828795[9] = 0;
   out_6293256511946828795[10] = 0;
   out_6293256511946828795[11] = 0;
   out_6293256511946828795[12] = 0;
   out_6293256511946828795[13] = 0;
   out_6293256511946828795[14] = 0;
   out_6293256511946828795[15] = 0;
   out_6293256511946828795[16] = 0;
   out_6293256511946828795[17] = 0;
   out_6293256511946828795[18] = 0;
   out_6293256511946828795[19] = 0;
   out_6293256511946828795[20] = 0;
   out_6293256511946828795[21] = 0;
   out_6293256511946828795[22] = 0;
   out_6293256511946828795[23] = 0;
   out_6293256511946828795[24] = 0;
   out_6293256511946828795[25] = 1;
   out_6293256511946828795[26] = 0;
   out_6293256511946828795[27] = 0;
   out_6293256511946828795[28] = 0;
   out_6293256511946828795[29] = 0;
   out_6293256511946828795[30] = 0;
   out_6293256511946828795[31] = 0;
   out_6293256511946828795[32] = 0;
   out_6293256511946828795[33] = 0;
   out_6293256511946828795[34] = 0;
   out_6293256511946828795[35] = 0;
   out_6293256511946828795[36] = 0;
   out_6293256511946828795[37] = 0;
   out_6293256511946828795[38] = 0;
   out_6293256511946828795[39] = 0;
   out_6293256511946828795[40] = 0;
   out_6293256511946828795[41] = 0;
   out_6293256511946828795[42] = 0;
   out_6293256511946828795[43] = 0;
   out_6293256511946828795[44] = 1;
   out_6293256511946828795[45] = 0;
   out_6293256511946828795[46] = 0;
   out_6293256511946828795[47] = 0;
   out_6293256511946828795[48] = 0;
   out_6293256511946828795[49] = 0;
   out_6293256511946828795[50] = 0;
   out_6293256511946828795[51] = 0;
   out_6293256511946828795[52] = 0;
   out_6293256511946828795[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4298502647758524793) {
  err_fun(nom_x, delta_x, out_4298502647758524793);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5600470633109473941) {
  inv_err_fun(nom_x, true_x, out_5600470633109473941);
}
void pose_H_mod_fun(double *state, double *out_5604237734398293519) {
  H_mod_fun(state, out_5604237734398293519);
}
void pose_f_fun(double *state, double dt, double *out_1603951998531582898) {
  f_fun(state,  dt, out_1603951998531582898);
}
void pose_F_fun(double *state, double dt, double *out_7355016791857912131) {
  F_fun(state,  dt, out_7355016791857912131);
}
void pose_h_4(double *state, double *unused, double *out_3151076657578519351) {
  h_4(state, unused, out_3151076657578519351);
}
void pose_H_4(double *state, double *unused, double *out_9070699129467350525) {
  H_4(state, unused, out_9070699129467350525);
}
void pose_h_10(double *state, double *unused, double *out_6670778953679817884) {
  h_10(state, unused, out_6670778953679817884);
}
void pose_H_10(double *state, double *unused, double *out_8318326309939820808) {
  H_10(state, unused, out_8318326309939820808);
}
void pose_h_13(double *state, double *unused, double *out_8670142885989515415) {
  h_13(state, unused, out_8670142885989515415);
}
void pose_H_13(double *state, double *unused, double *out_5542289480939677067) {
  H_13(state, unused, out_5542289480939677067);
}
void pose_h_14(double *state, double *unused, double *out_3946013715221375238) {
  h_14(state, unused, out_3946013715221375238);
}
void pose_H_14(double *state, double *unused, double *out_6293256511946828795) {
  H_14(state, unused, out_6293256511946828795);
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
