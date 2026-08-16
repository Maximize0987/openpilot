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
void err_fun(double *nom_x, double *delta_x, double *out_7783868612103190645) {
   out_7783868612103190645[0] = delta_x[0] + nom_x[0];
   out_7783868612103190645[1] = delta_x[1] + nom_x[1];
   out_7783868612103190645[2] = delta_x[2] + nom_x[2];
   out_7783868612103190645[3] = delta_x[3] + nom_x[3];
   out_7783868612103190645[4] = delta_x[4] + nom_x[4];
   out_7783868612103190645[5] = delta_x[5] + nom_x[5];
   out_7783868612103190645[6] = delta_x[6] + nom_x[6];
   out_7783868612103190645[7] = delta_x[7] + nom_x[7];
   out_7783868612103190645[8] = delta_x[8] + nom_x[8];
   out_7783868612103190645[9] = delta_x[9] + nom_x[9];
   out_7783868612103190645[10] = delta_x[10] + nom_x[10];
   out_7783868612103190645[11] = delta_x[11] + nom_x[11];
   out_7783868612103190645[12] = delta_x[12] + nom_x[12];
   out_7783868612103190645[13] = delta_x[13] + nom_x[13];
   out_7783868612103190645[14] = delta_x[14] + nom_x[14];
   out_7783868612103190645[15] = delta_x[15] + nom_x[15];
   out_7783868612103190645[16] = delta_x[16] + nom_x[16];
   out_7783868612103190645[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6605006959385105646) {
   out_6605006959385105646[0] = -nom_x[0] + true_x[0];
   out_6605006959385105646[1] = -nom_x[1] + true_x[1];
   out_6605006959385105646[2] = -nom_x[2] + true_x[2];
   out_6605006959385105646[3] = -nom_x[3] + true_x[3];
   out_6605006959385105646[4] = -nom_x[4] + true_x[4];
   out_6605006959385105646[5] = -nom_x[5] + true_x[5];
   out_6605006959385105646[6] = -nom_x[6] + true_x[6];
   out_6605006959385105646[7] = -nom_x[7] + true_x[7];
   out_6605006959385105646[8] = -nom_x[8] + true_x[8];
   out_6605006959385105646[9] = -nom_x[9] + true_x[9];
   out_6605006959385105646[10] = -nom_x[10] + true_x[10];
   out_6605006959385105646[11] = -nom_x[11] + true_x[11];
   out_6605006959385105646[12] = -nom_x[12] + true_x[12];
   out_6605006959385105646[13] = -nom_x[13] + true_x[13];
   out_6605006959385105646[14] = -nom_x[14] + true_x[14];
   out_6605006959385105646[15] = -nom_x[15] + true_x[15];
   out_6605006959385105646[16] = -nom_x[16] + true_x[16];
   out_6605006959385105646[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4214017023834556037) {
   out_4214017023834556037[0] = 1.0;
   out_4214017023834556037[1] = 0.0;
   out_4214017023834556037[2] = 0.0;
   out_4214017023834556037[3] = 0.0;
   out_4214017023834556037[4] = 0.0;
   out_4214017023834556037[5] = 0.0;
   out_4214017023834556037[6] = 0.0;
   out_4214017023834556037[7] = 0.0;
   out_4214017023834556037[8] = 0.0;
   out_4214017023834556037[9] = 0.0;
   out_4214017023834556037[10] = 0.0;
   out_4214017023834556037[11] = 0.0;
   out_4214017023834556037[12] = 0.0;
   out_4214017023834556037[13] = 0.0;
   out_4214017023834556037[14] = 0.0;
   out_4214017023834556037[15] = 0.0;
   out_4214017023834556037[16] = 0.0;
   out_4214017023834556037[17] = 0.0;
   out_4214017023834556037[18] = 0.0;
   out_4214017023834556037[19] = 1.0;
   out_4214017023834556037[20] = 0.0;
   out_4214017023834556037[21] = 0.0;
   out_4214017023834556037[22] = 0.0;
   out_4214017023834556037[23] = 0.0;
   out_4214017023834556037[24] = 0.0;
   out_4214017023834556037[25] = 0.0;
   out_4214017023834556037[26] = 0.0;
   out_4214017023834556037[27] = 0.0;
   out_4214017023834556037[28] = 0.0;
   out_4214017023834556037[29] = 0.0;
   out_4214017023834556037[30] = 0.0;
   out_4214017023834556037[31] = 0.0;
   out_4214017023834556037[32] = 0.0;
   out_4214017023834556037[33] = 0.0;
   out_4214017023834556037[34] = 0.0;
   out_4214017023834556037[35] = 0.0;
   out_4214017023834556037[36] = 0.0;
   out_4214017023834556037[37] = 0.0;
   out_4214017023834556037[38] = 1.0;
   out_4214017023834556037[39] = 0.0;
   out_4214017023834556037[40] = 0.0;
   out_4214017023834556037[41] = 0.0;
   out_4214017023834556037[42] = 0.0;
   out_4214017023834556037[43] = 0.0;
   out_4214017023834556037[44] = 0.0;
   out_4214017023834556037[45] = 0.0;
   out_4214017023834556037[46] = 0.0;
   out_4214017023834556037[47] = 0.0;
   out_4214017023834556037[48] = 0.0;
   out_4214017023834556037[49] = 0.0;
   out_4214017023834556037[50] = 0.0;
   out_4214017023834556037[51] = 0.0;
   out_4214017023834556037[52] = 0.0;
   out_4214017023834556037[53] = 0.0;
   out_4214017023834556037[54] = 0.0;
   out_4214017023834556037[55] = 0.0;
   out_4214017023834556037[56] = 0.0;
   out_4214017023834556037[57] = 1.0;
   out_4214017023834556037[58] = 0.0;
   out_4214017023834556037[59] = 0.0;
   out_4214017023834556037[60] = 0.0;
   out_4214017023834556037[61] = 0.0;
   out_4214017023834556037[62] = 0.0;
   out_4214017023834556037[63] = 0.0;
   out_4214017023834556037[64] = 0.0;
   out_4214017023834556037[65] = 0.0;
   out_4214017023834556037[66] = 0.0;
   out_4214017023834556037[67] = 0.0;
   out_4214017023834556037[68] = 0.0;
   out_4214017023834556037[69] = 0.0;
   out_4214017023834556037[70] = 0.0;
   out_4214017023834556037[71] = 0.0;
   out_4214017023834556037[72] = 0.0;
   out_4214017023834556037[73] = 0.0;
   out_4214017023834556037[74] = 0.0;
   out_4214017023834556037[75] = 0.0;
   out_4214017023834556037[76] = 1.0;
   out_4214017023834556037[77] = 0.0;
   out_4214017023834556037[78] = 0.0;
   out_4214017023834556037[79] = 0.0;
   out_4214017023834556037[80] = 0.0;
   out_4214017023834556037[81] = 0.0;
   out_4214017023834556037[82] = 0.0;
   out_4214017023834556037[83] = 0.0;
   out_4214017023834556037[84] = 0.0;
   out_4214017023834556037[85] = 0.0;
   out_4214017023834556037[86] = 0.0;
   out_4214017023834556037[87] = 0.0;
   out_4214017023834556037[88] = 0.0;
   out_4214017023834556037[89] = 0.0;
   out_4214017023834556037[90] = 0.0;
   out_4214017023834556037[91] = 0.0;
   out_4214017023834556037[92] = 0.0;
   out_4214017023834556037[93] = 0.0;
   out_4214017023834556037[94] = 0.0;
   out_4214017023834556037[95] = 1.0;
   out_4214017023834556037[96] = 0.0;
   out_4214017023834556037[97] = 0.0;
   out_4214017023834556037[98] = 0.0;
   out_4214017023834556037[99] = 0.0;
   out_4214017023834556037[100] = 0.0;
   out_4214017023834556037[101] = 0.0;
   out_4214017023834556037[102] = 0.0;
   out_4214017023834556037[103] = 0.0;
   out_4214017023834556037[104] = 0.0;
   out_4214017023834556037[105] = 0.0;
   out_4214017023834556037[106] = 0.0;
   out_4214017023834556037[107] = 0.0;
   out_4214017023834556037[108] = 0.0;
   out_4214017023834556037[109] = 0.0;
   out_4214017023834556037[110] = 0.0;
   out_4214017023834556037[111] = 0.0;
   out_4214017023834556037[112] = 0.0;
   out_4214017023834556037[113] = 0.0;
   out_4214017023834556037[114] = 1.0;
   out_4214017023834556037[115] = 0.0;
   out_4214017023834556037[116] = 0.0;
   out_4214017023834556037[117] = 0.0;
   out_4214017023834556037[118] = 0.0;
   out_4214017023834556037[119] = 0.0;
   out_4214017023834556037[120] = 0.0;
   out_4214017023834556037[121] = 0.0;
   out_4214017023834556037[122] = 0.0;
   out_4214017023834556037[123] = 0.0;
   out_4214017023834556037[124] = 0.0;
   out_4214017023834556037[125] = 0.0;
   out_4214017023834556037[126] = 0.0;
   out_4214017023834556037[127] = 0.0;
   out_4214017023834556037[128] = 0.0;
   out_4214017023834556037[129] = 0.0;
   out_4214017023834556037[130] = 0.0;
   out_4214017023834556037[131] = 0.0;
   out_4214017023834556037[132] = 0.0;
   out_4214017023834556037[133] = 1.0;
   out_4214017023834556037[134] = 0.0;
   out_4214017023834556037[135] = 0.0;
   out_4214017023834556037[136] = 0.0;
   out_4214017023834556037[137] = 0.0;
   out_4214017023834556037[138] = 0.0;
   out_4214017023834556037[139] = 0.0;
   out_4214017023834556037[140] = 0.0;
   out_4214017023834556037[141] = 0.0;
   out_4214017023834556037[142] = 0.0;
   out_4214017023834556037[143] = 0.0;
   out_4214017023834556037[144] = 0.0;
   out_4214017023834556037[145] = 0.0;
   out_4214017023834556037[146] = 0.0;
   out_4214017023834556037[147] = 0.0;
   out_4214017023834556037[148] = 0.0;
   out_4214017023834556037[149] = 0.0;
   out_4214017023834556037[150] = 0.0;
   out_4214017023834556037[151] = 0.0;
   out_4214017023834556037[152] = 1.0;
   out_4214017023834556037[153] = 0.0;
   out_4214017023834556037[154] = 0.0;
   out_4214017023834556037[155] = 0.0;
   out_4214017023834556037[156] = 0.0;
   out_4214017023834556037[157] = 0.0;
   out_4214017023834556037[158] = 0.0;
   out_4214017023834556037[159] = 0.0;
   out_4214017023834556037[160] = 0.0;
   out_4214017023834556037[161] = 0.0;
   out_4214017023834556037[162] = 0.0;
   out_4214017023834556037[163] = 0.0;
   out_4214017023834556037[164] = 0.0;
   out_4214017023834556037[165] = 0.0;
   out_4214017023834556037[166] = 0.0;
   out_4214017023834556037[167] = 0.0;
   out_4214017023834556037[168] = 0.0;
   out_4214017023834556037[169] = 0.0;
   out_4214017023834556037[170] = 0.0;
   out_4214017023834556037[171] = 1.0;
   out_4214017023834556037[172] = 0.0;
   out_4214017023834556037[173] = 0.0;
   out_4214017023834556037[174] = 0.0;
   out_4214017023834556037[175] = 0.0;
   out_4214017023834556037[176] = 0.0;
   out_4214017023834556037[177] = 0.0;
   out_4214017023834556037[178] = 0.0;
   out_4214017023834556037[179] = 0.0;
   out_4214017023834556037[180] = 0.0;
   out_4214017023834556037[181] = 0.0;
   out_4214017023834556037[182] = 0.0;
   out_4214017023834556037[183] = 0.0;
   out_4214017023834556037[184] = 0.0;
   out_4214017023834556037[185] = 0.0;
   out_4214017023834556037[186] = 0.0;
   out_4214017023834556037[187] = 0.0;
   out_4214017023834556037[188] = 0.0;
   out_4214017023834556037[189] = 0.0;
   out_4214017023834556037[190] = 1.0;
   out_4214017023834556037[191] = 0.0;
   out_4214017023834556037[192] = 0.0;
   out_4214017023834556037[193] = 0.0;
   out_4214017023834556037[194] = 0.0;
   out_4214017023834556037[195] = 0.0;
   out_4214017023834556037[196] = 0.0;
   out_4214017023834556037[197] = 0.0;
   out_4214017023834556037[198] = 0.0;
   out_4214017023834556037[199] = 0.0;
   out_4214017023834556037[200] = 0.0;
   out_4214017023834556037[201] = 0.0;
   out_4214017023834556037[202] = 0.0;
   out_4214017023834556037[203] = 0.0;
   out_4214017023834556037[204] = 0.0;
   out_4214017023834556037[205] = 0.0;
   out_4214017023834556037[206] = 0.0;
   out_4214017023834556037[207] = 0.0;
   out_4214017023834556037[208] = 0.0;
   out_4214017023834556037[209] = 1.0;
   out_4214017023834556037[210] = 0.0;
   out_4214017023834556037[211] = 0.0;
   out_4214017023834556037[212] = 0.0;
   out_4214017023834556037[213] = 0.0;
   out_4214017023834556037[214] = 0.0;
   out_4214017023834556037[215] = 0.0;
   out_4214017023834556037[216] = 0.0;
   out_4214017023834556037[217] = 0.0;
   out_4214017023834556037[218] = 0.0;
   out_4214017023834556037[219] = 0.0;
   out_4214017023834556037[220] = 0.0;
   out_4214017023834556037[221] = 0.0;
   out_4214017023834556037[222] = 0.0;
   out_4214017023834556037[223] = 0.0;
   out_4214017023834556037[224] = 0.0;
   out_4214017023834556037[225] = 0.0;
   out_4214017023834556037[226] = 0.0;
   out_4214017023834556037[227] = 0.0;
   out_4214017023834556037[228] = 1.0;
   out_4214017023834556037[229] = 0.0;
   out_4214017023834556037[230] = 0.0;
   out_4214017023834556037[231] = 0.0;
   out_4214017023834556037[232] = 0.0;
   out_4214017023834556037[233] = 0.0;
   out_4214017023834556037[234] = 0.0;
   out_4214017023834556037[235] = 0.0;
   out_4214017023834556037[236] = 0.0;
   out_4214017023834556037[237] = 0.0;
   out_4214017023834556037[238] = 0.0;
   out_4214017023834556037[239] = 0.0;
   out_4214017023834556037[240] = 0.0;
   out_4214017023834556037[241] = 0.0;
   out_4214017023834556037[242] = 0.0;
   out_4214017023834556037[243] = 0.0;
   out_4214017023834556037[244] = 0.0;
   out_4214017023834556037[245] = 0.0;
   out_4214017023834556037[246] = 0.0;
   out_4214017023834556037[247] = 1.0;
   out_4214017023834556037[248] = 0.0;
   out_4214017023834556037[249] = 0.0;
   out_4214017023834556037[250] = 0.0;
   out_4214017023834556037[251] = 0.0;
   out_4214017023834556037[252] = 0.0;
   out_4214017023834556037[253] = 0.0;
   out_4214017023834556037[254] = 0.0;
   out_4214017023834556037[255] = 0.0;
   out_4214017023834556037[256] = 0.0;
   out_4214017023834556037[257] = 0.0;
   out_4214017023834556037[258] = 0.0;
   out_4214017023834556037[259] = 0.0;
   out_4214017023834556037[260] = 0.0;
   out_4214017023834556037[261] = 0.0;
   out_4214017023834556037[262] = 0.0;
   out_4214017023834556037[263] = 0.0;
   out_4214017023834556037[264] = 0.0;
   out_4214017023834556037[265] = 0.0;
   out_4214017023834556037[266] = 1.0;
   out_4214017023834556037[267] = 0.0;
   out_4214017023834556037[268] = 0.0;
   out_4214017023834556037[269] = 0.0;
   out_4214017023834556037[270] = 0.0;
   out_4214017023834556037[271] = 0.0;
   out_4214017023834556037[272] = 0.0;
   out_4214017023834556037[273] = 0.0;
   out_4214017023834556037[274] = 0.0;
   out_4214017023834556037[275] = 0.0;
   out_4214017023834556037[276] = 0.0;
   out_4214017023834556037[277] = 0.0;
   out_4214017023834556037[278] = 0.0;
   out_4214017023834556037[279] = 0.0;
   out_4214017023834556037[280] = 0.0;
   out_4214017023834556037[281] = 0.0;
   out_4214017023834556037[282] = 0.0;
   out_4214017023834556037[283] = 0.0;
   out_4214017023834556037[284] = 0.0;
   out_4214017023834556037[285] = 1.0;
   out_4214017023834556037[286] = 0.0;
   out_4214017023834556037[287] = 0.0;
   out_4214017023834556037[288] = 0.0;
   out_4214017023834556037[289] = 0.0;
   out_4214017023834556037[290] = 0.0;
   out_4214017023834556037[291] = 0.0;
   out_4214017023834556037[292] = 0.0;
   out_4214017023834556037[293] = 0.0;
   out_4214017023834556037[294] = 0.0;
   out_4214017023834556037[295] = 0.0;
   out_4214017023834556037[296] = 0.0;
   out_4214017023834556037[297] = 0.0;
   out_4214017023834556037[298] = 0.0;
   out_4214017023834556037[299] = 0.0;
   out_4214017023834556037[300] = 0.0;
   out_4214017023834556037[301] = 0.0;
   out_4214017023834556037[302] = 0.0;
   out_4214017023834556037[303] = 0.0;
   out_4214017023834556037[304] = 1.0;
   out_4214017023834556037[305] = 0.0;
   out_4214017023834556037[306] = 0.0;
   out_4214017023834556037[307] = 0.0;
   out_4214017023834556037[308] = 0.0;
   out_4214017023834556037[309] = 0.0;
   out_4214017023834556037[310] = 0.0;
   out_4214017023834556037[311] = 0.0;
   out_4214017023834556037[312] = 0.0;
   out_4214017023834556037[313] = 0.0;
   out_4214017023834556037[314] = 0.0;
   out_4214017023834556037[315] = 0.0;
   out_4214017023834556037[316] = 0.0;
   out_4214017023834556037[317] = 0.0;
   out_4214017023834556037[318] = 0.0;
   out_4214017023834556037[319] = 0.0;
   out_4214017023834556037[320] = 0.0;
   out_4214017023834556037[321] = 0.0;
   out_4214017023834556037[322] = 0.0;
   out_4214017023834556037[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_446156685689757577) {
   out_446156685689757577[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_446156685689757577[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_446156685689757577[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_446156685689757577[3] = dt*state[12] + state[3];
   out_446156685689757577[4] = dt*state[13] + state[4];
   out_446156685689757577[5] = dt*state[14] + state[5];
   out_446156685689757577[6] = state[6];
   out_446156685689757577[7] = state[7];
   out_446156685689757577[8] = state[8];
   out_446156685689757577[9] = state[9];
   out_446156685689757577[10] = state[10];
   out_446156685689757577[11] = state[11];
   out_446156685689757577[12] = state[12];
   out_446156685689757577[13] = state[13];
   out_446156685689757577[14] = state[14];
   out_446156685689757577[15] = state[15];
   out_446156685689757577[16] = state[16];
   out_446156685689757577[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1314145057723334901) {
   out_1314145057723334901[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1314145057723334901[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1314145057723334901[2] = 0;
   out_1314145057723334901[3] = 0;
   out_1314145057723334901[4] = 0;
   out_1314145057723334901[5] = 0;
   out_1314145057723334901[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1314145057723334901[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1314145057723334901[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1314145057723334901[9] = 0;
   out_1314145057723334901[10] = 0;
   out_1314145057723334901[11] = 0;
   out_1314145057723334901[12] = 0;
   out_1314145057723334901[13] = 0;
   out_1314145057723334901[14] = 0;
   out_1314145057723334901[15] = 0;
   out_1314145057723334901[16] = 0;
   out_1314145057723334901[17] = 0;
   out_1314145057723334901[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1314145057723334901[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1314145057723334901[20] = 0;
   out_1314145057723334901[21] = 0;
   out_1314145057723334901[22] = 0;
   out_1314145057723334901[23] = 0;
   out_1314145057723334901[24] = 0;
   out_1314145057723334901[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1314145057723334901[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1314145057723334901[27] = 0;
   out_1314145057723334901[28] = 0;
   out_1314145057723334901[29] = 0;
   out_1314145057723334901[30] = 0;
   out_1314145057723334901[31] = 0;
   out_1314145057723334901[32] = 0;
   out_1314145057723334901[33] = 0;
   out_1314145057723334901[34] = 0;
   out_1314145057723334901[35] = 0;
   out_1314145057723334901[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1314145057723334901[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1314145057723334901[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1314145057723334901[39] = 0;
   out_1314145057723334901[40] = 0;
   out_1314145057723334901[41] = 0;
   out_1314145057723334901[42] = 0;
   out_1314145057723334901[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1314145057723334901[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1314145057723334901[45] = 0;
   out_1314145057723334901[46] = 0;
   out_1314145057723334901[47] = 0;
   out_1314145057723334901[48] = 0;
   out_1314145057723334901[49] = 0;
   out_1314145057723334901[50] = 0;
   out_1314145057723334901[51] = 0;
   out_1314145057723334901[52] = 0;
   out_1314145057723334901[53] = 0;
   out_1314145057723334901[54] = 0;
   out_1314145057723334901[55] = 0;
   out_1314145057723334901[56] = 0;
   out_1314145057723334901[57] = 1;
   out_1314145057723334901[58] = 0;
   out_1314145057723334901[59] = 0;
   out_1314145057723334901[60] = 0;
   out_1314145057723334901[61] = 0;
   out_1314145057723334901[62] = 0;
   out_1314145057723334901[63] = 0;
   out_1314145057723334901[64] = 0;
   out_1314145057723334901[65] = 0;
   out_1314145057723334901[66] = dt;
   out_1314145057723334901[67] = 0;
   out_1314145057723334901[68] = 0;
   out_1314145057723334901[69] = 0;
   out_1314145057723334901[70] = 0;
   out_1314145057723334901[71] = 0;
   out_1314145057723334901[72] = 0;
   out_1314145057723334901[73] = 0;
   out_1314145057723334901[74] = 0;
   out_1314145057723334901[75] = 0;
   out_1314145057723334901[76] = 1;
   out_1314145057723334901[77] = 0;
   out_1314145057723334901[78] = 0;
   out_1314145057723334901[79] = 0;
   out_1314145057723334901[80] = 0;
   out_1314145057723334901[81] = 0;
   out_1314145057723334901[82] = 0;
   out_1314145057723334901[83] = 0;
   out_1314145057723334901[84] = 0;
   out_1314145057723334901[85] = dt;
   out_1314145057723334901[86] = 0;
   out_1314145057723334901[87] = 0;
   out_1314145057723334901[88] = 0;
   out_1314145057723334901[89] = 0;
   out_1314145057723334901[90] = 0;
   out_1314145057723334901[91] = 0;
   out_1314145057723334901[92] = 0;
   out_1314145057723334901[93] = 0;
   out_1314145057723334901[94] = 0;
   out_1314145057723334901[95] = 1;
   out_1314145057723334901[96] = 0;
   out_1314145057723334901[97] = 0;
   out_1314145057723334901[98] = 0;
   out_1314145057723334901[99] = 0;
   out_1314145057723334901[100] = 0;
   out_1314145057723334901[101] = 0;
   out_1314145057723334901[102] = 0;
   out_1314145057723334901[103] = 0;
   out_1314145057723334901[104] = dt;
   out_1314145057723334901[105] = 0;
   out_1314145057723334901[106] = 0;
   out_1314145057723334901[107] = 0;
   out_1314145057723334901[108] = 0;
   out_1314145057723334901[109] = 0;
   out_1314145057723334901[110] = 0;
   out_1314145057723334901[111] = 0;
   out_1314145057723334901[112] = 0;
   out_1314145057723334901[113] = 0;
   out_1314145057723334901[114] = 1;
   out_1314145057723334901[115] = 0;
   out_1314145057723334901[116] = 0;
   out_1314145057723334901[117] = 0;
   out_1314145057723334901[118] = 0;
   out_1314145057723334901[119] = 0;
   out_1314145057723334901[120] = 0;
   out_1314145057723334901[121] = 0;
   out_1314145057723334901[122] = 0;
   out_1314145057723334901[123] = 0;
   out_1314145057723334901[124] = 0;
   out_1314145057723334901[125] = 0;
   out_1314145057723334901[126] = 0;
   out_1314145057723334901[127] = 0;
   out_1314145057723334901[128] = 0;
   out_1314145057723334901[129] = 0;
   out_1314145057723334901[130] = 0;
   out_1314145057723334901[131] = 0;
   out_1314145057723334901[132] = 0;
   out_1314145057723334901[133] = 1;
   out_1314145057723334901[134] = 0;
   out_1314145057723334901[135] = 0;
   out_1314145057723334901[136] = 0;
   out_1314145057723334901[137] = 0;
   out_1314145057723334901[138] = 0;
   out_1314145057723334901[139] = 0;
   out_1314145057723334901[140] = 0;
   out_1314145057723334901[141] = 0;
   out_1314145057723334901[142] = 0;
   out_1314145057723334901[143] = 0;
   out_1314145057723334901[144] = 0;
   out_1314145057723334901[145] = 0;
   out_1314145057723334901[146] = 0;
   out_1314145057723334901[147] = 0;
   out_1314145057723334901[148] = 0;
   out_1314145057723334901[149] = 0;
   out_1314145057723334901[150] = 0;
   out_1314145057723334901[151] = 0;
   out_1314145057723334901[152] = 1;
   out_1314145057723334901[153] = 0;
   out_1314145057723334901[154] = 0;
   out_1314145057723334901[155] = 0;
   out_1314145057723334901[156] = 0;
   out_1314145057723334901[157] = 0;
   out_1314145057723334901[158] = 0;
   out_1314145057723334901[159] = 0;
   out_1314145057723334901[160] = 0;
   out_1314145057723334901[161] = 0;
   out_1314145057723334901[162] = 0;
   out_1314145057723334901[163] = 0;
   out_1314145057723334901[164] = 0;
   out_1314145057723334901[165] = 0;
   out_1314145057723334901[166] = 0;
   out_1314145057723334901[167] = 0;
   out_1314145057723334901[168] = 0;
   out_1314145057723334901[169] = 0;
   out_1314145057723334901[170] = 0;
   out_1314145057723334901[171] = 1;
   out_1314145057723334901[172] = 0;
   out_1314145057723334901[173] = 0;
   out_1314145057723334901[174] = 0;
   out_1314145057723334901[175] = 0;
   out_1314145057723334901[176] = 0;
   out_1314145057723334901[177] = 0;
   out_1314145057723334901[178] = 0;
   out_1314145057723334901[179] = 0;
   out_1314145057723334901[180] = 0;
   out_1314145057723334901[181] = 0;
   out_1314145057723334901[182] = 0;
   out_1314145057723334901[183] = 0;
   out_1314145057723334901[184] = 0;
   out_1314145057723334901[185] = 0;
   out_1314145057723334901[186] = 0;
   out_1314145057723334901[187] = 0;
   out_1314145057723334901[188] = 0;
   out_1314145057723334901[189] = 0;
   out_1314145057723334901[190] = 1;
   out_1314145057723334901[191] = 0;
   out_1314145057723334901[192] = 0;
   out_1314145057723334901[193] = 0;
   out_1314145057723334901[194] = 0;
   out_1314145057723334901[195] = 0;
   out_1314145057723334901[196] = 0;
   out_1314145057723334901[197] = 0;
   out_1314145057723334901[198] = 0;
   out_1314145057723334901[199] = 0;
   out_1314145057723334901[200] = 0;
   out_1314145057723334901[201] = 0;
   out_1314145057723334901[202] = 0;
   out_1314145057723334901[203] = 0;
   out_1314145057723334901[204] = 0;
   out_1314145057723334901[205] = 0;
   out_1314145057723334901[206] = 0;
   out_1314145057723334901[207] = 0;
   out_1314145057723334901[208] = 0;
   out_1314145057723334901[209] = 1;
   out_1314145057723334901[210] = 0;
   out_1314145057723334901[211] = 0;
   out_1314145057723334901[212] = 0;
   out_1314145057723334901[213] = 0;
   out_1314145057723334901[214] = 0;
   out_1314145057723334901[215] = 0;
   out_1314145057723334901[216] = 0;
   out_1314145057723334901[217] = 0;
   out_1314145057723334901[218] = 0;
   out_1314145057723334901[219] = 0;
   out_1314145057723334901[220] = 0;
   out_1314145057723334901[221] = 0;
   out_1314145057723334901[222] = 0;
   out_1314145057723334901[223] = 0;
   out_1314145057723334901[224] = 0;
   out_1314145057723334901[225] = 0;
   out_1314145057723334901[226] = 0;
   out_1314145057723334901[227] = 0;
   out_1314145057723334901[228] = 1;
   out_1314145057723334901[229] = 0;
   out_1314145057723334901[230] = 0;
   out_1314145057723334901[231] = 0;
   out_1314145057723334901[232] = 0;
   out_1314145057723334901[233] = 0;
   out_1314145057723334901[234] = 0;
   out_1314145057723334901[235] = 0;
   out_1314145057723334901[236] = 0;
   out_1314145057723334901[237] = 0;
   out_1314145057723334901[238] = 0;
   out_1314145057723334901[239] = 0;
   out_1314145057723334901[240] = 0;
   out_1314145057723334901[241] = 0;
   out_1314145057723334901[242] = 0;
   out_1314145057723334901[243] = 0;
   out_1314145057723334901[244] = 0;
   out_1314145057723334901[245] = 0;
   out_1314145057723334901[246] = 0;
   out_1314145057723334901[247] = 1;
   out_1314145057723334901[248] = 0;
   out_1314145057723334901[249] = 0;
   out_1314145057723334901[250] = 0;
   out_1314145057723334901[251] = 0;
   out_1314145057723334901[252] = 0;
   out_1314145057723334901[253] = 0;
   out_1314145057723334901[254] = 0;
   out_1314145057723334901[255] = 0;
   out_1314145057723334901[256] = 0;
   out_1314145057723334901[257] = 0;
   out_1314145057723334901[258] = 0;
   out_1314145057723334901[259] = 0;
   out_1314145057723334901[260] = 0;
   out_1314145057723334901[261] = 0;
   out_1314145057723334901[262] = 0;
   out_1314145057723334901[263] = 0;
   out_1314145057723334901[264] = 0;
   out_1314145057723334901[265] = 0;
   out_1314145057723334901[266] = 1;
   out_1314145057723334901[267] = 0;
   out_1314145057723334901[268] = 0;
   out_1314145057723334901[269] = 0;
   out_1314145057723334901[270] = 0;
   out_1314145057723334901[271] = 0;
   out_1314145057723334901[272] = 0;
   out_1314145057723334901[273] = 0;
   out_1314145057723334901[274] = 0;
   out_1314145057723334901[275] = 0;
   out_1314145057723334901[276] = 0;
   out_1314145057723334901[277] = 0;
   out_1314145057723334901[278] = 0;
   out_1314145057723334901[279] = 0;
   out_1314145057723334901[280] = 0;
   out_1314145057723334901[281] = 0;
   out_1314145057723334901[282] = 0;
   out_1314145057723334901[283] = 0;
   out_1314145057723334901[284] = 0;
   out_1314145057723334901[285] = 1;
   out_1314145057723334901[286] = 0;
   out_1314145057723334901[287] = 0;
   out_1314145057723334901[288] = 0;
   out_1314145057723334901[289] = 0;
   out_1314145057723334901[290] = 0;
   out_1314145057723334901[291] = 0;
   out_1314145057723334901[292] = 0;
   out_1314145057723334901[293] = 0;
   out_1314145057723334901[294] = 0;
   out_1314145057723334901[295] = 0;
   out_1314145057723334901[296] = 0;
   out_1314145057723334901[297] = 0;
   out_1314145057723334901[298] = 0;
   out_1314145057723334901[299] = 0;
   out_1314145057723334901[300] = 0;
   out_1314145057723334901[301] = 0;
   out_1314145057723334901[302] = 0;
   out_1314145057723334901[303] = 0;
   out_1314145057723334901[304] = 1;
   out_1314145057723334901[305] = 0;
   out_1314145057723334901[306] = 0;
   out_1314145057723334901[307] = 0;
   out_1314145057723334901[308] = 0;
   out_1314145057723334901[309] = 0;
   out_1314145057723334901[310] = 0;
   out_1314145057723334901[311] = 0;
   out_1314145057723334901[312] = 0;
   out_1314145057723334901[313] = 0;
   out_1314145057723334901[314] = 0;
   out_1314145057723334901[315] = 0;
   out_1314145057723334901[316] = 0;
   out_1314145057723334901[317] = 0;
   out_1314145057723334901[318] = 0;
   out_1314145057723334901[319] = 0;
   out_1314145057723334901[320] = 0;
   out_1314145057723334901[321] = 0;
   out_1314145057723334901[322] = 0;
   out_1314145057723334901[323] = 1;
}
void h_4(double *state, double *unused, double *out_3131871851783197102) {
   out_3131871851783197102[0] = state[6] + state[9];
   out_3131871851783197102[1] = state[7] + state[10];
   out_3131871851783197102[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_7985824233678463609) {
   out_7985824233678463609[0] = 0;
   out_7985824233678463609[1] = 0;
   out_7985824233678463609[2] = 0;
   out_7985824233678463609[3] = 0;
   out_7985824233678463609[4] = 0;
   out_7985824233678463609[5] = 0;
   out_7985824233678463609[6] = 1;
   out_7985824233678463609[7] = 0;
   out_7985824233678463609[8] = 0;
   out_7985824233678463609[9] = 1;
   out_7985824233678463609[10] = 0;
   out_7985824233678463609[11] = 0;
   out_7985824233678463609[12] = 0;
   out_7985824233678463609[13] = 0;
   out_7985824233678463609[14] = 0;
   out_7985824233678463609[15] = 0;
   out_7985824233678463609[16] = 0;
   out_7985824233678463609[17] = 0;
   out_7985824233678463609[18] = 0;
   out_7985824233678463609[19] = 0;
   out_7985824233678463609[20] = 0;
   out_7985824233678463609[21] = 0;
   out_7985824233678463609[22] = 0;
   out_7985824233678463609[23] = 0;
   out_7985824233678463609[24] = 0;
   out_7985824233678463609[25] = 1;
   out_7985824233678463609[26] = 0;
   out_7985824233678463609[27] = 0;
   out_7985824233678463609[28] = 1;
   out_7985824233678463609[29] = 0;
   out_7985824233678463609[30] = 0;
   out_7985824233678463609[31] = 0;
   out_7985824233678463609[32] = 0;
   out_7985824233678463609[33] = 0;
   out_7985824233678463609[34] = 0;
   out_7985824233678463609[35] = 0;
   out_7985824233678463609[36] = 0;
   out_7985824233678463609[37] = 0;
   out_7985824233678463609[38] = 0;
   out_7985824233678463609[39] = 0;
   out_7985824233678463609[40] = 0;
   out_7985824233678463609[41] = 0;
   out_7985824233678463609[42] = 0;
   out_7985824233678463609[43] = 0;
   out_7985824233678463609[44] = 1;
   out_7985824233678463609[45] = 0;
   out_7985824233678463609[46] = 0;
   out_7985824233678463609[47] = 1;
   out_7985824233678463609[48] = 0;
   out_7985824233678463609[49] = 0;
   out_7985824233678463609[50] = 0;
   out_7985824233678463609[51] = 0;
   out_7985824233678463609[52] = 0;
   out_7985824233678463609[53] = 0;
}
void h_10(double *state, double *unused, double *out_4732705393461985535) {
   out_4732705393461985535[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4732705393461985535[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4732705393461985535[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_25842791302237901) {
   out_25842791302237901[0] = 0;
   out_25842791302237901[1] = 9.8100000000000005*cos(state[1]);
   out_25842791302237901[2] = 0;
   out_25842791302237901[3] = 0;
   out_25842791302237901[4] = -state[8];
   out_25842791302237901[5] = state[7];
   out_25842791302237901[6] = 0;
   out_25842791302237901[7] = state[5];
   out_25842791302237901[8] = -state[4];
   out_25842791302237901[9] = 0;
   out_25842791302237901[10] = 0;
   out_25842791302237901[11] = 0;
   out_25842791302237901[12] = 1;
   out_25842791302237901[13] = 0;
   out_25842791302237901[14] = 0;
   out_25842791302237901[15] = 1;
   out_25842791302237901[16] = 0;
   out_25842791302237901[17] = 0;
   out_25842791302237901[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_25842791302237901[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_25842791302237901[20] = 0;
   out_25842791302237901[21] = state[8];
   out_25842791302237901[22] = 0;
   out_25842791302237901[23] = -state[6];
   out_25842791302237901[24] = -state[5];
   out_25842791302237901[25] = 0;
   out_25842791302237901[26] = state[3];
   out_25842791302237901[27] = 0;
   out_25842791302237901[28] = 0;
   out_25842791302237901[29] = 0;
   out_25842791302237901[30] = 0;
   out_25842791302237901[31] = 1;
   out_25842791302237901[32] = 0;
   out_25842791302237901[33] = 0;
   out_25842791302237901[34] = 1;
   out_25842791302237901[35] = 0;
   out_25842791302237901[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_25842791302237901[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_25842791302237901[38] = 0;
   out_25842791302237901[39] = -state[7];
   out_25842791302237901[40] = state[6];
   out_25842791302237901[41] = 0;
   out_25842791302237901[42] = state[4];
   out_25842791302237901[43] = -state[3];
   out_25842791302237901[44] = 0;
   out_25842791302237901[45] = 0;
   out_25842791302237901[46] = 0;
   out_25842791302237901[47] = 0;
   out_25842791302237901[48] = 0;
   out_25842791302237901[49] = 0;
   out_25842791302237901[50] = 1;
   out_25842791302237901[51] = 0;
   out_25842791302237901[52] = 0;
   out_25842791302237901[53] = 1;
}
void h_13(double *state, double *unused, double *out_3855617401361447493) {
   out_3855617401361447493[0] = state[3];
   out_3855617401361447493[1] = state[4];
   out_3855617401361447493[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2850288631714387078) {
   out_2850288631714387078[0] = 0;
   out_2850288631714387078[1] = 0;
   out_2850288631714387078[2] = 0;
   out_2850288631714387078[3] = 1;
   out_2850288631714387078[4] = 0;
   out_2850288631714387078[5] = 0;
   out_2850288631714387078[6] = 0;
   out_2850288631714387078[7] = 0;
   out_2850288631714387078[8] = 0;
   out_2850288631714387078[9] = 0;
   out_2850288631714387078[10] = 0;
   out_2850288631714387078[11] = 0;
   out_2850288631714387078[12] = 0;
   out_2850288631714387078[13] = 0;
   out_2850288631714387078[14] = 0;
   out_2850288631714387078[15] = 0;
   out_2850288631714387078[16] = 0;
   out_2850288631714387078[17] = 0;
   out_2850288631714387078[18] = 0;
   out_2850288631714387078[19] = 0;
   out_2850288631714387078[20] = 0;
   out_2850288631714387078[21] = 0;
   out_2850288631714387078[22] = 1;
   out_2850288631714387078[23] = 0;
   out_2850288631714387078[24] = 0;
   out_2850288631714387078[25] = 0;
   out_2850288631714387078[26] = 0;
   out_2850288631714387078[27] = 0;
   out_2850288631714387078[28] = 0;
   out_2850288631714387078[29] = 0;
   out_2850288631714387078[30] = 0;
   out_2850288631714387078[31] = 0;
   out_2850288631714387078[32] = 0;
   out_2850288631714387078[33] = 0;
   out_2850288631714387078[34] = 0;
   out_2850288631714387078[35] = 0;
   out_2850288631714387078[36] = 0;
   out_2850288631714387078[37] = 0;
   out_2850288631714387078[38] = 0;
   out_2850288631714387078[39] = 0;
   out_2850288631714387078[40] = 0;
   out_2850288631714387078[41] = 1;
   out_2850288631714387078[42] = 0;
   out_2850288631714387078[43] = 0;
   out_2850288631714387078[44] = 0;
   out_2850288631714387078[45] = 0;
   out_2850288631714387078[46] = 0;
   out_2850288631714387078[47] = 0;
   out_2850288631714387078[48] = 0;
   out_2850288631714387078[49] = 0;
   out_2850288631714387078[50] = 0;
   out_2850288631714387078[51] = 0;
   out_2850288631714387078[52] = 0;
   out_2850288631714387078[53] = 0;
}
void h_14(double *state, double *unused, double *out_2052081526966194460) {
   out_2052081526966194460[0] = state[6];
   out_2052081526966194460[1] = state[7];
   out_2052081526966194460[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4903035801383091313) {
   out_4903035801383091313[0] = 0;
   out_4903035801383091313[1] = 0;
   out_4903035801383091313[2] = 0;
   out_4903035801383091313[3] = 0;
   out_4903035801383091313[4] = 0;
   out_4903035801383091313[5] = 0;
   out_4903035801383091313[6] = 1;
   out_4903035801383091313[7] = 0;
   out_4903035801383091313[8] = 0;
   out_4903035801383091313[9] = 0;
   out_4903035801383091313[10] = 0;
   out_4903035801383091313[11] = 0;
   out_4903035801383091313[12] = 0;
   out_4903035801383091313[13] = 0;
   out_4903035801383091313[14] = 0;
   out_4903035801383091313[15] = 0;
   out_4903035801383091313[16] = 0;
   out_4903035801383091313[17] = 0;
   out_4903035801383091313[18] = 0;
   out_4903035801383091313[19] = 0;
   out_4903035801383091313[20] = 0;
   out_4903035801383091313[21] = 0;
   out_4903035801383091313[22] = 0;
   out_4903035801383091313[23] = 0;
   out_4903035801383091313[24] = 0;
   out_4903035801383091313[25] = 1;
   out_4903035801383091313[26] = 0;
   out_4903035801383091313[27] = 0;
   out_4903035801383091313[28] = 0;
   out_4903035801383091313[29] = 0;
   out_4903035801383091313[30] = 0;
   out_4903035801383091313[31] = 0;
   out_4903035801383091313[32] = 0;
   out_4903035801383091313[33] = 0;
   out_4903035801383091313[34] = 0;
   out_4903035801383091313[35] = 0;
   out_4903035801383091313[36] = 0;
   out_4903035801383091313[37] = 0;
   out_4903035801383091313[38] = 0;
   out_4903035801383091313[39] = 0;
   out_4903035801383091313[40] = 0;
   out_4903035801383091313[41] = 0;
   out_4903035801383091313[42] = 0;
   out_4903035801383091313[43] = 0;
   out_4903035801383091313[44] = 1;
   out_4903035801383091313[45] = 0;
   out_4903035801383091313[46] = 0;
   out_4903035801383091313[47] = 0;
   out_4903035801383091313[48] = 0;
   out_4903035801383091313[49] = 0;
   out_4903035801383091313[50] = 0;
   out_4903035801383091313[51] = 0;
   out_4903035801383091313[52] = 0;
   out_4903035801383091313[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7783868612103190645) {
  err_fun(nom_x, delta_x, out_7783868612103190645);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6605006959385105646) {
  inv_err_fun(nom_x, true_x, out_6605006959385105646);
}
void pose_H_mod_fun(double *state, double *out_4214017023834556037) {
  H_mod_fun(state, out_4214017023834556037);
}
void pose_f_fun(double *state, double dt, double *out_446156685689757577) {
  f_fun(state,  dt, out_446156685689757577);
}
void pose_F_fun(double *state, double dt, double *out_1314145057723334901) {
  F_fun(state,  dt, out_1314145057723334901);
}
void pose_h_4(double *state, double *unused, double *out_3131871851783197102) {
  h_4(state, unused, out_3131871851783197102);
}
void pose_H_4(double *state, double *unused, double *out_7985824233678463609) {
  H_4(state, unused, out_7985824233678463609);
}
void pose_h_10(double *state, double *unused, double *out_4732705393461985535) {
  h_10(state, unused, out_4732705393461985535);
}
void pose_H_10(double *state, double *unused, double *out_25842791302237901) {
  H_10(state, unused, out_25842791302237901);
}
void pose_h_13(double *state, double *unused, double *out_3855617401361447493) {
  h_13(state, unused, out_3855617401361447493);
}
void pose_H_13(double *state, double *unused, double *out_2850288631714387078) {
  H_13(state, unused, out_2850288631714387078);
}
void pose_h_14(double *state, double *unused, double *out_2052081526966194460) {
  h_14(state, unused, out_2052081526966194460);
}
void pose_H_14(double *state, double *unused, double *out_4903035801383091313) {
  H_14(state, unused, out_4903035801383091313);
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
