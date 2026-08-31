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
void err_fun(double *nom_x, double *delta_x, double *out_2665641701635233151) {
   out_2665641701635233151[0] = delta_x[0] + nom_x[0];
   out_2665641701635233151[1] = delta_x[1] + nom_x[1];
   out_2665641701635233151[2] = delta_x[2] + nom_x[2];
   out_2665641701635233151[3] = delta_x[3] + nom_x[3];
   out_2665641701635233151[4] = delta_x[4] + nom_x[4];
   out_2665641701635233151[5] = delta_x[5] + nom_x[5];
   out_2665641701635233151[6] = delta_x[6] + nom_x[6];
   out_2665641701635233151[7] = delta_x[7] + nom_x[7];
   out_2665641701635233151[8] = delta_x[8] + nom_x[8];
   out_2665641701635233151[9] = delta_x[9] + nom_x[9];
   out_2665641701635233151[10] = delta_x[10] + nom_x[10];
   out_2665641701635233151[11] = delta_x[11] + nom_x[11];
   out_2665641701635233151[12] = delta_x[12] + nom_x[12];
   out_2665641701635233151[13] = delta_x[13] + nom_x[13];
   out_2665641701635233151[14] = delta_x[14] + nom_x[14];
   out_2665641701635233151[15] = delta_x[15] + nom_x[15];
   out_2665641701635233151[16] = delta_x[16] + nom_x[16];
   out_2665641701635233151[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8375727440013270020) {
   out_8375727440013270020[0] = -nom_x[0] + true_x[0];
   out_8375727440013270020[1] = -nom_x[1] + true_x[1];
   out_8375727440013270020[2] = -nom_x[2] + true_x[2];
   out_8375727440013270020[3] = -nom_x[3] + true_x[3];
   out_8375727440013270020[4] = -nom_x[4] + true_x[4];
   out_8375727440013270020[5] = -nom_x[5] + true_x[5];
   out_8375727440013270020[6] = -nom_x[6] + true_x[6];
   out_8375727440013270020[7] = -nom_x[7] + true_x[7];
   out_8375727440013270020[8] = -nom_x[8] + true_x[8];
   out_8375727440013270020[9] = -nom_x[9] + true_x[9];
   out_8375727440013270020[10] = -nom_x[10] + true_x[10];
   out_8375727440013270020[11] = -nom_x[11] + true_x[11];
   out_8375727440013270020[12] = -nom_x[12] + true_x[12];
   out_8375727440013270020[13] = -nom_x[13] + true_x[13];
   out_8375727440013270020[14] = -nom_x[14] + true_x[14];
   out_8375727440013270020[15] = -nom_x[15] + true_x[15];
   out_8375727440013270020[16] = -nom_x[16] + true_x[16];
   out_8375727440013270020[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6067255468928274013) {
   out_6067255468928274013[0] = 1.0;
   out_6067255468928274013[1] = 0.0;
   out_6067255468928274013[2] = 0.0;
   out_6067255468928274013[3] = 0.0;
   out_6067255468928274013[4] = 0.0;
   out_6067255468928274013[5] = 0.0;
   out_6067255468928274013[6] = 0.0;
   out_6067255468928274013[7] = 0.0;
   out_6067255468928274013[8] = 0.0;
   out_6067255468928274013[9] = 0.0;
   out_6067255468928274013[10] = 0.0;
   out_6067255468928274013[11] = 0.0;
   out_6067255468928274013[12] = 0.0;
   out_6067255468928274013[13] = 0.0;
   out_6067255468928274013[14] = 0.0;
   out_6067255468928274013[15] = 0.0;
   out_6067255468928274013[16] = 0.0;
   out_6067255468928274013[17] = 0.0;
   out_6067255468928274013[18] = 0.0;
   out_6067255468928274013[19] = 1.0;
   out_6067255468928274013[20] = 0.0;
   out_6067255468928274013[21] = 0.0;
   out_6067255468928274013[22] = 0.0;
   out_6067255468928274013[23] = 0.0;
   out_6067255468928274013[24] = 0.0;
   out_6067255468928274013[25] = 0.0;
   out_6067255468928274013[26] = 0.0;
   out_6067255468928274013[27] = 0.0;
   out_6067255468928274013[28] = 0.0;
   out_6067255468928274013[29] = 0.0;
   out_6067255468928274013[30] = 0.0;
   out_6067255468928274013[31] = 0.0;
   out_6067255468928274013[32] = 0.0;
   out_6067255468928274013[33] = 0.0;
   out_6067255468928274013[34] = 0.0;
   out_6067255468928274013[35] = 0.0;
   out_6067255468928274013[36] = 0.0;
   out_6067255468928274013[37] = 0.0;
   out_6067255468928274013[38] = 1.0;
   out_6067255468928274013[39] = 0.0;
   out_6067255468928274013[40] = 0.0;
   out_6067255468928274013[41] = 0.0;
   out_6067255468928274013[42] = 0.0;
   out_6067255468928274013[43] = 0.0;
   out_6067255468928274013[44] = 0.0;
   out_6067255468928274013[45] = 0.0;
   out_6067255468928274013[46] = 0.0;
   out_6067255468928274013[47] = 0.0;
   out_6067255468928274013[48] = 0.0;
   out_6067255468928274013[49] = 0.0;
   out_6067255468928274013[50] = 0.0;
   out_6067255468928274013[51] = 0.0;
   out_6067255468928274013[52] = 0.0;
   out_6067255468928274013[53] = 0.0;
   out_6067255468928274013[54] = 0.0;
   out_6067255468928274013[55] = 0.0;
   out_6067255468928274013[56] = 0.0;
   out_6067255468928274013[57] = 1.0;
   out_6067255468928274013[58] = 0.0;
   out_6067255468928274013[59] = 0.0;
   out_6067255468928274013[60] = 0.0;
   out_6067255468928274013[61] = 0.0;
   out_6067255468928274013[62] = 0.0;
   out_6067255468928274013[63] = 0.0;
   out_6067255468928274013[64] = 0.0;
   out_6067255468928274013[65] = 0.0;
   out_6067255468928274013[66] = 0.0;
   out_6067255468928274013[67] = 0.0;
   out_6067255468928274013[68] = 0.0;
   out_6067255468928274013[69] = 0.0;
   out_6067255468928274013[70] = 0.0;
   out_6067255468928274013[71] = 0.0;
   out_6067255468928274013[72] = 0.0;
   out_6067255468928274013[73] = 0.0;
   out_6067255468928274013[74] = 0.0;
   out_6067255468928274013[75] = 0.0;
   out_6067255468928274013[76] = 1.0;
   out_6067255468928274013[77] = 0.0;
   out_6067255468928274013[78] = 0.0;
   out_6067255468928274013[79] = 0.0;
   out_6067255468928274013[80] = 0.0;
   out_6067255468928274013[81] = 0.0;
   out_6067255468928274013[82] = 0.0;
   out_6067255468928274013[83] = 0.0;
   out_6067255468928274013[84] = 0.0;
   out_6067255468928274013[85] = 0.0;
   out_6067255468928274013[86] = 0.0;
   out_6067255468928274013[87] = 0.0;
   out_6067255468928274013[88] = 0.0;
   out_6067255468928274013[89] = 0.0;
   out_6067255468928274013[90] = 0.0;
   out_6067255468928274013[91] = 0.0;
   out_6067255468928274013[92] = 0.0;
   out_6067255468928274013[93] = 0.0;
   out_6067255468928274013[94] = 0.0;
   out_6067255468928274013[95] = 1.0;
   out_6067255468928274013[96] = 0.0;
   out_6067255468928274013[97] = 0.0;
   out_6067255468928274013[98] = 0.0;
   out_6067255468928274013[99] = 0.0;
   out_6067255468928274013[100] = 0.0;
   out_6067255468928274013[101] = 0.0;
   out_6067255468928274013[102] = 0.0;
   out_6067255468928274013[103] = 0.0;
   out_6067255468928274013[104] = 0.0;
   out_6067255468928274013[105] = 0.0;
   out_6067255468928274013[106] = 0.0;
   out_6067255468928274013[107] = 0.0;
   out_6067255468928274013[108] = 0.0;
   out_6067255468928274013[109] = 0.0;
   out_6067255468928274013[110] = 0.0;
   out_6067255468928274013[111] = 0.0;
   out_6067255468928274013[112] = 0.0;
   out_6067255468928274013[113] = 0.0;
   out_6067255468928274013[114] = 1.0;
   out_6067255468928274013[115] = 0.0;
   out_6067255468928274013[116] = 0.0;
   out_6067255468928274013[117] = 0.0;
   out_6067255468928274013[118] = 0.0;
   out_6067255468928274013[119] = 0.0;
   out_6067255468928274013[120] = 0.0;
   out_6067255468928274013[121] = 0.0;
   out_6067255468928274013[122] = 0.0;
   out_6067255468928274013[123] = 0.0;
   out_6067255468928274013[124] = 0.0;
   out_6067255468928274013[125] = 0.0;
   out_6067255468928274013[126] = 0.0;
   out_6067255468928274013[127] = 0.0;
   out_6067255468928274013[128] = 0.0;
   out_6067255468928274013[129] = 0.0;
   out_6067255468928274013[130] = 0.0;
   out_6067255468928274013[131] = 0.0;
   out_6067255468928274013[132] = 0.0;
   out_6067255468928274013[133] = 1.0;
   out_6067255468928274013[134] = 0.0;
   out_6067255468928274013[135] = 0.0;
   out_6067255468928274013[136] = 0.0;
   out_6067255468928274013[137] = 0.0;
   out_6067255468928274013[138] = 0.0;
   out_6067255468928274013[139] = 0.0;
   out_6067255468928274013[140] = 0.0;
   out_6067255468928274013[141] = 0.0;
   out_6067255468928274013[142] = 0.0;
   out_6067255468928274013[143] = 0.0;
   out_6067255468928274013[144] = 0.0;
   out_6067255468928274013[145] = 0.0;
   out_6067255468928274013[146] = 0.0;
   out_6067255468928274013[147] = 0.0;
   out_6067255468928274013[148] = 0.0;
   out_6067255468928274013[149] = 0.0;
   out_6067255468928274013[150] = 0.0;
   out_6067255468928274013[151] = 0.0;
   out_6067255468928274013[152] = 1.0;
   out_6067255468928274013[153] = 0.0;
   out_6067255468928274013[154] = 0.0;
   out_6067255468928274013[155] = 0.0;
   out_6067255468928274013[156] = 0.0;
   out_6067255468928274013[157] = 0.0;
   out_6067255468928274013[158] = 0.0;
   out_6067255468928274013[159] = 0.0;
   out_6067255468928274013[160] = 0.0;
   out_6067255468928274013[161] = 0.0;
   out_6067255468928274013[162] = 0.0;
   out_6067255468928274013[163] = 0.0;
   out_6067255468928274013[164] = 0.0;
   out_6067255468928274013[165] = 0.0;
   out_6067255468928274013[166] = 0.0;
   out_6067255468928274013[167] = 0.0;
   out_6067255468928274013[168] = 0.0;
   out_6067255468928274013[169] = 0.0;
   out_6067255468928274013[170] = 0.0;
   out_6067255468928274013[171] = 1.0;
   out_6067255468928274013[172] = 0.0;
   out_6067255468928274013[173] = 0.0;
   out_6067255468928274013[174] = 0.0;
   out_6067255468928274013[175] = 0.0;
   out_6067255468928274013[176] = 0.0;
   out_6067255468928274013[177] = 0.0;
   out_6067255468928274013[178] = 0.0;
   out_6067255468928274013[179] = 0.0;
   out_6067255468928274013[180] = 0.0;
   out_6067255468928274013[181] = 0.0;
   out_6067255468928274013[182] = 0.0;
   out_6067255468928274013[183] = 0.0;
   out_6067255468928274013[184] = 0.0;
   out_6067255468928274013[185] = 0.0;
   out_6067255468928274013[186] = 0.0;
   out_6067255468928274013[187] = 0.0;
   out_6067255468928274013[188] = 0.0;
   out_6067255468928274013[189] = 0.0;
   out_6067255468928274013[190] = 1.0;
   out_6067255468928274013[191] = 0.0;
   out_6067255468928274013[192] = 0.0;
   out_6067255468928274013[193] = 0.0;
   out_6067255468928274013[194] = 0.0;
   out_6067255468928274013[195] = 0.0;
   out_6067255468928274013[196] = 0.0;
   out_6067255468928274013[197] = 0.0;
   out_6067255468928274013[198] = 0.0;
   out_6067255468928274013[199] = 0.0;
   out_6067255468928274013[200] = 0.0;
   out_6067255468928274013[201] = 0.0;
   out_6067255468928274013[202] = 0.0;
   out_6067255468928274013[203] = 0.0;
   out_6067255468928274013[204] = 0.0;
   out_6067255468928274013[205] = 0.0;
   out_6067255468928274013[206] = 0.0;
   out_6067255468928274013[207] = 0.0;
   out_6067255468928274013[208] = 0.0;
   out_6067255468928274013[209] = 1.0;
   out_6067255468928274013[210] = 0.0;
   out_6067255468928274013[211] = 0.0;
   out_6067255468928274013[212] = 0.0;
   out_6067255468928274013[213] = 0.0;
   out_6067255468928274013[214] = 0.0;
   out_6067255468928274013[215] = 0.0;
   out_6067255468928274013[216] = 0.0;
   out_6067255468928274013[217] = 0.0;
   out_6067255468928274013[218] = 0.0;
   out_6067255468928274013[219] = 0.0;
   out_6067255468928274013[220] = 0.0;
   out_6067255468928274013[221] = 0.0;
   out_6067255468928274013[222] = 0.0;
   out_6067255468928274013[223] = 0.0;
   out_6067255468928274013[224] = 0.0;
   out_6067255468928274013[225] = 0.0;
   out_6067255468928274013[226] = 0.0;
   out_6067255468928274013[227] = 0.0;
   out_6067255468928274013[228] = 1.0;
   out_6067255468928274013[229] = 0.0;
   out_6067255468928274013[230] = 0.0;
   out_6067255468928274013[231] = 0.0;
   out_6067255468928274013[232] = 0.0;
   out_6067255468928274013[233] = 0.0;
   out_6067255468928274013[234] = 0.0;
   out_6067255468928274013[235] = 0.0;
   out_6067255468928274013[236] = 0.0;
   out_6067255468928274013[237] = 0.0;
   out_6067255468928274013[238] = 0.0;
   out_6067255468928274013[239] = 0.0;
   out_6067255468928274013[240] = 0.0;
   out_6067255468928274013[241] = 0.0;
   out_6067255468928274013[242] = 0.0;
   out_6067255468928274013[243] = 0.0;
   out_6067255468928274013[244] = 0.0;
   out_6067255468928274013[245] = 0.0;
   out_6067255468928274013[246] = 0.0;
   out_6067255468928274013[247] = 1.0;
   out_6067255468928274013[248] = 0.0;
   out_6067255468928274013[249] = 0.0;
   out_6067255468928274013[250] = 0.0;
   out_6067255468928274013[251] = 0.0;
   out_6067255468928274013[252] = 0.0;
   out_6067255468928274013[253] = 0.0;
   out_6067255468928274013[254] = 0.0;
   out_6067255468928274013[255] = 0.0;
   out_6067255468928274013[256] = 0.0;
   out_6067255468928274013[257] = 0.0;
   out_6067255468928274013[258] = 0.0;
   out_6067255468928274013[259] = 0.0;
   out_6067255468928274013[260] = 0.0;
   out_6067255468928274013[261] = 0.0;
   out_6067255468928274013[262] = 0.0;
   out_6067255468928274013[263] = 0.0;
   out_6067255468928274013[264] = 0.0;
   out_6067255468928274013[265] = 0.0;
   out_6067255468928274013[266] = 1.0;
   out_6067255468928274013[267] = 0.0;
   out_6067255468928274013[268] = 0.0;
   out_6067255468928274013[269] = 0.0;
   out_6067255468928274013[270] = 0.0;
   out_6067255468928274013[271] = 0.0;
   out_6067255468928274013[272] = 0.0;
   out_6067255468928274013[273] = 0.0;
   out_6067255468928274013[274] = 0.0;
   out_6067255468928274013[275] = 0.0;
   out_6067255468928274013[276] = 0.0;
   out_6067255468928274013[277] = 0.0;
   out_6067255468928274013[278] = 0.0;
   out_6067255468928274013[279] = 0.0;
   out_6067255468928274013[280] = 0.0;
   out_6067255468928274013[281] = 0.0;
   out_6067255468928274013[282] = 0.0;
   out_6067255468928274013[283] = 0.0;
   out_6067255468928274013[284] = 0.0;
   out_6067255468928274013[285] = 1.0;
   out_6067255468928274013[286] = 0.0;
   out_6067255468928274013[287] = 0.0;
   out_6067255468928274013[288] = 0.0;
   out_6067255468928274013[289] = 0.0;
   out_6067255468928274013[290] = 0.0;
   out_6067255468928274013[291] = 0.0;
   out_6067255468928274013[292] = 0.0;
   out_6067255468928274013[293] = 0.0;
   out_6067255468928274013[294] = 0.0;
   out_6067255468928274013[295] = 0.0;
   out_6067255468928274013[296] = 0.0;
   out_6067255468928274013[297] = 0.0;
   out_6067255468928274013[298] = 0.0;
   out_6067255468928274013[299] = 0.0;
   out_6067255468928274013[300] = 0.0;
   out_6067255468928274013[301] = 0.0;
   out_6067255468928274013[302] = 0.0;
   out_6067255468928274013[303] = 0.0;
   out_6067255468928274013[304] = 1.0;
   out_6067255468928274013[305] = 0.0;
   out_6067255468928274013[306] = 0.0;
   out_6067255468928274013[307] = 0.0;
   out_6067255468928274013[308] = 0.0;
   out_6067255468928274013[309] = 0.0;
   out_6067255468928274013[310] = 0.0;
   out_6067255468928274013[311] = 0.0;
   out_6067255468928274013[312] = 0.0;
   out_6067255468928274013[313] = 0.0;
   out_6067255468928274013[314] = 0.0;
   out_6067255468928274013[315] = 0.0;
   out_6067255468928274013[316] = 0.0;
   out_6067255468928274013[317] = 0.0;
   out_6067255468928274013[318] = 0.0;
   out_6067255468928274013[319] = 0.0;
   out_6067255468928274013[320] = 0.0;
   out_6067255468928274013[321] = 0.0;
   out_6067255468928274013[322] = 0.0;
   out_6067255468928274013[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6773782600033783154) {
   out_6773782600033783154[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6773782600033783154[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6773782600033783154[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6773782600033783154[3] = dt*state[12] + state[3];
   out_6773782600033783154[4] = dt*state[13] + state[4];
   out_6773782600033783154[5] = dt*state[14] + state[5];
   out_6773782600033783154[6] = state[6];
   out_6773782600033783154[7] = state[7];
   out_6773782600033783154[8] = state[8];
   out_6773782600033783154[9] = state[9];
   out_6773782600033783154[10] = state[10];
   out_6773782600033783154[11] = state[11];
   out_6773782600033783154[12] = state[12];
   out_6773782600033783154[13] = state[13];
   out_6773782600033783154[14] = state[14];
   out_6773782600033783154[15] = state[15];
   out_6773782600033783154[16] = state[16];
   out_6773782600033783154[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6298375408118706110) {
   out_6298375408118706110[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6298375408118706110[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6298375408118706110[2] = 0;
   out_6298375408118706110[3] = 0;
   out_6298375408118706110[4] = 0;
   out_6298375408118706110[5] = 0;
   out_6298375408118706110[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6298375408118706110[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6298375408118706110[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6298375408118706110[9] = 0;
   out_6298375408118706110[10] = 0;
   out_6298375408118706110[11] = 0;
   out_6298375408118706110[12] = 0;
   out_6298375408118706110[13] = 0;
   out_6298375408118706110[14] = 0;
   out_6298375408118706110[15] = 0;
   out_6298375408118706110[16] = 0;
   out_6298375408118706110[17] = 0;
   out_6298375408118706110[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6298375408118706110[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6298375408118706110[20] = 0;
   out_6298375408118706110[21] = 0;
   out_6298375408118706110[22] = 0;
   out_6298375408118706110[23] = 0;
   out_6298375408118706110[24] = 0;
   out_6298375408118706110[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6298375408118706110[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6298375408118706110[27] = 0;
   out_6298375408118706110[28] = 0;
   out_6298375408118706110[29] = 0;
   out_6298375408118706110[30] = 0;
   out_6298375408118706110[31] = 0;
   out_6298375408118706110[32] = 0;
   out_6298375408118706110[33] = 0;
   out_6298375408118706110[34] = 0;
   out_6298375408118706110[35] = 0;
   out_6298375408118706110[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6298375408118706110[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6298375408118706110[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6298375408118706110[39] = 0;
   out_6298375408118706110[40] = 0;
   out_6298375408118706110[41] = 0;
   out_6298375408118706110[42] = 0;
   out_6298375408118706110[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6298375408118706110[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6298375408118706110[45] = 0;
   out_6298375408118706110[46] = 0;
   out_6298375408118706110[47] = 0;
   out_6298375408118706110[48] = 0;
   out_6298375408118706110[49] = 0;
   out_6298375408118706110[50] = 0;
   out_6298375408118706110[51] = 0;
   out_6298375408118706110[52] = 0;
   out_6298375408118706110[53] = 0;
   out_6298375408118706110[54] = 0;
   out_6298375408118706110[55] = 0;
   out_6298375408118706110[56] = 0;
   out_6298375408118706110[57] = 1;
   out_6298375408118706110[58] = 0;
   out_6298375408118706110[59] = 0;
   out_6298375408118706110[60] = 0;
   out_6298375408118706110[61] = 0;
   out_6298375408118706110[62] = 0;
   out_6298375408118706110[63] = 0;
   out_6298375408118706110[64] = 0;
   out_6298375408118706110[65] = 0;
   out_6298375408118706110[66] = dt;
   out_6298375408118706110[67] = 0;
   out_6298375408118706110[68] = 0;
   out_6298375408118706110[69] = 0;
   out_6298375408118706110[70] = 0;
   out_6298375408118706110[71] = 0;
   out_6298375408118706110[72] = 0;
   out_6298375408118706110[73] = 0;
   out_6298375408118706110[74] = 0;
   out_6298375408118706110[75] = 0;
   out_6298375408118706110[76] = 1;
   out_6298375408118706110[77] = 0;
   out_6298375408118706110[78] = 0;
   out_6298375408118706110[79] = 0;
   out_6298375408118706110[80] = 0;
   out_6298375408118706110[81] = 0;
   out_6298375408118706110[82] = 0;
   out_6298375408118706110[83] = 0;
   out_6298375408118706110[84] = 0;
   out_6298375408118706110[85] = dt;
   out_6298375408118706110[86] = 0;
   out_6298375408118706110[87] = 0;
   out_6298375408118706110[88] = 0;
   out_6298375408118706110[89] = 0;
   out_6298375408118706110[90] = 0;
   out_6298375408118706110[91] = 0;
   out_6298375408118706110[92] = 0;
   out_6298375408118706110[93] = 0;
   out_6298375408118706110[94] = 0;
   out_6298375408118706110[95] = 1;
   out_6298375408118706110[96] = 0;
   out_6298375408118706110[97] = 0;
   out_6298375408118706110[98] = 0;
   out_6298375408118706110[99] = 0;
   out_6298375408118706110[100] = 0;
   out_6298375408118706110[101] = 0;
   out_6298375408118706110[102] = 0;
   out_6298375408118706110[103] = 0;
   out_6298375408118706110[104] = dt;
   out_6298375408118706110[105] = 0;
   out_6298375408118706110[106] = 0;
   out_6298375408118706110[107] = 0;
   out_6298375408118706110[108] = 0;
   out_6298375408118706110[109] = 0;
   out_6298375408118706110[110] = 0;
   out_6298375408118706110[111] = 0;
   out_6298375408118706110[112] = 0;
   out_6298375408118706110[113] = 0;
   out_6298375408118706110[114] = 1;
   out_6298375408118706110[115] = 0;
   out_6298375408118706110[116] = 0;
   out_6298375408118706110[117] = 0;
   out_6298375408118706110[118] = 0;
   out_6298375408118706110[119] = 0;
   out_6298375408118706110[120] = 0;
   out_6298375408118706110[121] = 0;
   out_6298375408118706110[122] = 0;
   out_6298375408118706110[123] = 0;
   out_6298375408118706110[124] = 0;
   out_6298375408118706110[125] = 0;
   out_6298375408118706110[126] = 0;
   out_6298375408118706110[127] = 0;
   out_6298375408118706110[128] = 0;
   out_6298375408118706110[129] = 0;
   out_6298375408118706110[130] = 0;
   out_6298375408118706110[131] = 0;
   out_6298375408118706110[132] = 0;
   out_6298375408118706110[133] = 1;
   out_6298375408118706110[134] = 0;
   out_6298375408118706110[135] = 0;
   out_6298375408118706110[136] = 0;
   out_6298375408118706110[137] = 0;
   out_6298375408118706110[138] = 0;
   out_6298375408118706110[139] = 0;
   out_6298375408118706110[140] = 0;
   out_6298375408118706110[141] = 0;
   out_6298375408118706110[142] = 0;
   out_6298375408118706110[143] = 0;
   out_6298375408118706110[144] = 0;
   out_6298375408118706110[145] = 0;
   out_6298375408118706110[146] = 0;
   out_6298375408118706110[147] = 0;
   out_6298375408118706110[148] = 0;
   out_6298375408118706110[149] = 0;
   out_6298375408118706110[150] = 0;
   out_6298375408118706110[151] = 0;
   out_6298375408118706110[152] = 1;
   out_6298375408118706110[153] = 0;
   out_6298375408118706110[154] = 0;
   out_6298375408118706110[155] = 0;
   out_6298375408118706110[156] = 0;
   out_6298375408118706110[157] = 0;
   out_6298375408118706110[158] = 0;
   out_6298375408118706110[159] = 0;
   out_6298375408118706110[160] = 0;
   out_6298375408118706110[161] = 0;
   out_6298375408118706110[162] = 0;
   out_6298375408118706110[163] = 0;
   out_6298375408118706110[164] = 0;
   out_6298375408118706110[165] = 0;
   out_6298375408118706110[166] = 0;
   out_6298375408118706110[167] = 0;
   out_6298375408118706110[168] = 0;
   out_6298375408118706110[169] = 0;
   out_6298375408118706110[170] = 0;
   out_6298375408118706110[171] = 1;
   out_6298375408118706110[172] = 0;
   out_6298375408118706110[173] = 0;
   out_6298375408118706110[174] = 0;
   out_6298375408118706110[175] = 0;
   out_6298375408118706110[176] = 0;
   out_6298375408118706110[177] = 0;
   out_6298375408118706110[178] = 0;
   out_6298375408118706110[179] = 0;
   out_6298375408118706110[180] = 0;
   out_6298375408118706110[181] = 0;
   out_6298375408118706110[182] = 0;
   out_6298375408118706110[183] = 0;
   out_6298375408118706110[184] = 0;
   out_6298375408118706110[185] = 0;
   out_6298375408118706110[186] = 0;
   out_6298375408118706110[187] = 0;
   out_6298375408118706110[188] = 0;
   out_6298375408118706110[189] = 0;
   out_6298375408118706110[190] = 1;
   out_6298375408118706110[191] = 0;
   out_6298375408118706110[192] = 0;
   out_6298375408118706110[193] = 0;
   out_6298375408118706110[194] = 0;
   out_6298375408118706110[195] = 0;
   out_6298375408118706110[196] = 0;
   out_6298375408118706110[197] = 0;
   out_6298375408118706110[198] = 0;
   out_6298375408118706110[199] = 0;
   out_6298375408118706110[200] = 0;
   out_6298375408118706110[201] = 0;
   out_6298375408118706110[202] = 0;
   out_6298375408118706110[203] = 0;
   out_6298375408118706110[204] = 0;
   out_6298375408118706110[205] = 0;
   out_6298375408118706110[206] = 0;
   out_6298375408118706110[207] = 0;
   out_6298375408118706110[208] = 0;
   out_6298375408118706110[209] = 1;
   out_6298375408118706110[210] = 0;
   out_6298375408118706110[211] = 0;
   out_6298375408118706110[212] = 0;
   out_6298375408118706110[213] = 0;
   out_6298375408118706110[214] = 0;
   out_6298375408118706110[215] = 0;
   out_6298375408118706110[216] = 0;
   out_6298375408118706110[217] = 0;
   out_6298375408118706110[218] = 0;
   out_6298375408118706110[219] = 0;
   out_6298375408118706110[220] = 0;
   out_6298375408118706110[221] = 0;
   out_6298375408118706110[222] = 0;
   out_6298375408118706110[223] = 0;
   out_6298375408118706110[224] = 0;
   out_6298375408118706110[225] = 0;
   out_6298375408118706110[226] = 0;
   out_6298375408118706110[227] = 0;
   out_6298375408118706110[228] = 1;
   out_6298375408118706110[229] = 0;
   out_6298375408118706110[230] = 0;
   out_6298375408118706110[231] = 0;
   out_6298375408118706110[232] = 0;
   out_6298375408118706110[233] = 0;
   out_6298375408118706110[234] = 0;
   out_6298375408118706110[235] = 0;
   out_6298375408118706110[236] = 0;
   out_6298375408118706110[237] = 0;
   out_6298375408118706110[238] = 0;
   out_6298375408118706110[239] = 0;
   out_6298375408118706110[240] = 0;
   out_6298375408118706110[241] = 0;
   out_6298375408118706110[242] = 0;
   out_6298375408118706110[243] = 0;
   out_6298375408118706110[244] = 0;
   out_6298375408118706110[245] = 0;
   out_6298375408118706110[246] = 0;
   out_6298375408118706110[247] = 1;
   out_6298375408118706110[248] = 0;
   out_6298375408118706110[249] = 0;
   out_6298375408118706110[250] = 0;
   out_6298375408118706110[251] = 0;
   out_6298375408118706110[252] = 0;
   out_6298375408118706110[253] = 0;
   out_6298375408118706110[254] = 0;
   out_6298375408118706110[255] = 0;
   out_6298375408118706110[256] = 0;
   out_6298375408118706110[257] = 0;
   out_6298375408118706110[258] = 0;
   out_6298375408118706110[259] = 0;
   out_6298375408118706110[260] = 0;
   out_6298375408118706110[261] = 0;
   out_6298375408118706110[262] = 0;
   out_6298375408118706110[263] = 0;
   out_6298375408118706110[264] = 0;
   out_6298375408118706110[265] = 0;
   out_6298375408118706110[266] = 1;
   out_6298375408118706110[267] = 0;
   out_6298375408118706110[268] = 0;
   out_6298375408118706110[269] = 0;
   out_6298375408118706110[270] = 0;
   out_6298375408118706110[271] = 0;
   out_6298375408118706110[272] = 0;
   out_6298375408118706110[273] = 0;
   out_6298375408118706110[274] = 0;
   out_6298375408118706110[275] = 0;
   out_6298375408118706110[276] = 0;
   out_6298375408118706110[277] = 0;
   out_6298375408118706110[278] = 0;
   out_6298375408118706110[279] = 0;
   out_6298375408118706110[280] = 0;
   out_6298375408118706110[281] = 0;
   out_6298375408118706110[282] = 0;
   out_6298375408118706110[283] = 0;
   out_6298375408118706110[284] = 0;
   out_6298375408118706110[285] = 1;
   out_6298375408118706110[286] = 0;
   out_6298375408118706110[287] = 0;
   out_6298375408118706110[288] = 0;
   out_6298375408118706110[289] = 0;
   out_6298375408118706110[290] = 0;
   out_6298375408118706110[291] = 0;
   out_6298375408118706110[292] = 0;
   out_6298375408118706110[293] = 0;
   out_6298375408118706110[294] = 0;
   out_6298375408118706110[295] = 0;
   out_6298375408118706110[296] = 0;
   out_6298375408118706110[297] = 0;
   out_6298375408118706110[298] = 0;
   out_6298375408118706110[299] = 0;
   out_6298375408118706110[300] = 0;
   out_6298375408118706110[301] = 0;
   out_6298375408118706110[302] = 0;
   out_6298375408118706110[303] = 0;
   out_6298375408118706110[304] = 1;
   out_6298375408118706110[305] = 0;
   out_6298375408118706110[306] = 0;
   out_6298375408118706110[307] = 0;
   out_6298375408118706110[308] = 0;
   out_6298375408118706110[309] = 0;
   out_6298375408118706110[310] = 0;
   out_6298375408118706110[311] = 0;
   out_6298375408118706110[312] = 0;
   out_6298375408118706110[313] = 0;
   out_6298375408118706110[314] = 0;
   out_6298375408118706110[315] = 0;
   out_6298375408118706110[316] = 0;
   out_6298375408118706110[317] = 0;
   out_6298375408118706110[318] = 0;
   out_6298375408118706110[319] = 0;
   out_6298375408118706110[320] = 0;
   out_6298375408118706110[321] = 0;
   out_6298375408118706110[322] = 0;
   out_6298375408118706110[323] = 1;
}
void h_4(double *state, double *unused, double *out_6452539322350206189) {
   out_6452539322350206189[0] = state[6] + state[9];
   out_6452539322350206189[1] = state[7] + state[10];
   out_6452539322350206189[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4829214681067158040) {
   out_4829214681067158040[0] = 0;
   out_4829214681067158040[1] = 0;
   out_4829214681067158040[2] = 0;
   out_4829214681067158040[3] = 0;
   out_4829214681067158040[4] = 0;
   out_4829214681067158040[5] = 0;
   out_4829214681067158040[6] = 1;
   out_4829214681067158040[7] = 0;
   out_4829214681067158040[8] = 0;
   out_4829214681067158040[9] = 1;
   out_4829214681067158040[10] = 0;
   out_4829214681067158040[11] = 0;
   out_4829214681067158040[12] = 0;
   out_4829214681067158040[13] = 0;
   out_4829214681067158040[14] = 0;
   out_4829214681067158040[15] = 0;
   out_4829214681067158040[16] = 0;
   out_4829214681067158040[17] = 0;
   out_4829214681067158040[18] = 0;
   out_4829214681067158040[19] = 0;
   out_4829214681067158040[20] = 0;
   out_4829214681067158040[21] = 0;
   out_4829214681067158040[22] = 0;
   out_4829214681067158040[23] = 0;
   out_4829214681067158040[24] = 0;
   out_4829214681067158040[25] = 1;
   out_4829214681067158040[26] = 0;
   out_4829214681067158040[27] = 0;
   out_4829214681067158040[28] = 1;
   out_4829214681067158040[29] = 0;
   out_4829214681067158040[30] = 0;
   out_4829214681067158040[31] = 0;
   out_4829214681067158040[32] = 0;
   out_4829214681067158040[33] = 0;
   out_4829214681067158040[34] = 0;
   out_4829214681067158040[35] = 0;
   out_4829214681067158040[36] = 0;
   out_4829214681067158040[37] = 0;
   out_4829214681067158040[38] = 0;
   out_4829214681067158040[39] = 0;
   out_4829214681067158040[40] = 0;
   out_4829214681067158040[41] = 0;
   out_4829214681067158040[42] = 0;
   out_4829214681067158040[43] = 0;
   out_4829214681067158040[44] = 1;
   out_4829214681067158040[45] = 0;
   out_4829214681067158040[46] = 0;
   out_4829214681067158040[47] = 1;
   out_4829214681067158040[48] = 0;
   out_4829214681067158040[49] = 0;
   out_4829214681067158040[50] = 0;
   out_4829214681067158040[51] = 0;
   out_4829214681067158040[52] = 0;
   out_4829214681067158040[53] = 0;
}
void h_10(double *state, double *unused, double *out_5957134933492111448) {
   out_5957134933492111448[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5957134933492111448[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5957134933492111448[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3625295134339217134) {
   out_3625295134339217134[0] = 0;
   out_3625295134339217134[1] = 9.8100000000000005*cos(state[1]);
   out_3625295134339217134[2] = 0;
   out_3625295134339217134[3] = 0;
   out_3625295134339217134[4] = -state[8];
   out_3625295134339217134[5] = state[7];
   out_3625295134339217134[6] = 0;
   out_3625295134339217134[7] = state[5];
   out_3625295134339217134[8] = -state[4];
   out_3625295134339217134[9] = 0;
   out_3625295134339217134[10] = 0;
   out_3625295134339217134[11] = 0;
   out_3625295134339217134[12] = 1;
   out_3625295134339217134[13] = 0;
   out_3625295134339217134[14] = 0;
   out_3625295134339217134[15] = 1;
   out_3625295134339217134[16] = 0;
   out_3625295134339217134[17] = 0;
   out_3625295134339217134[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3625295134339217134[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3625295134339217134[20] = 0;
   out_3625295134339217134[21] = state[8];
   out_3625295134339217134[22] = 0;
   out_3625295134339217134[23] = -state[6];
   out_3625295134339217134[24] = -state[5];
   out_3625295134339217134[25] = 0;
   out_3625295134339217134[26] = state[3];
   out_3625295134339217134[27] = 0;
   out_3625295134339217134[28] = 0;
   out_3625295134339217134[29] = 0;
   out_3625295134339217134[30] = 0;
   out_3625295134339217134[31] = 1;
   out_3625295134339217134[32] = 0;
   out_3625295134339217134[33] = 0;
   out_3625295134339217134[34] = 1;
   out_3625295134339217134[35] = 0;
   out_3625295134339217134[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3625295134339217134[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3625295134339217134[38] = 0;
   out_3625295134339217134[39] = -state[7];
   out_3625295134339217134[40] = state[6];
   out_3625295134339217134[41] = 0;
   out_3625295134339217134[42] = state[4];
   out_3625295134339217134[43] = -state[3];
   out_3625295134339217134[44] = 0;
   out_3625295134339217134[45] = 0;
   out_3625295134339217134[46] = 0;
   out_3625295134339217134[47] = 0;
   out_3625295134339217134[48] = 0;
   out_3625295134339217134[49] = 0;
   out_3625295134339217134[50] = 1;
   out_3625295134339217134[51] = 0;
   out_3625295134339217134[52] = 0;
   out_3625295134339217134[53] = 1;
}
void h_13(double *state, double *unused, double *out_6701412570788452504) {
   out_6701412570788452504[0] = state[3];
   out_6701412570788452504[1] = state[4];
   out_6701412570788452504[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5393816600749002144) {
   out_5393816600749002144[0] = 0;
   out_5393816600749002144[1] = 0;
   out_5393816600749002144[2] = 0;
   out_5393816600749002144[3] = 1;
   out_5393816600749002144[4] = 0;
   out_5393816600749002144[5] = 0;
   out_5393816600749002144[6] = 0;
   out_5393816600749002144[7] = 0;
   out_5393816600749002144[8] = 0;
   out_5393816600749002144[9] = 0;
   out_5393816600749002144[10] = 0;
   out_5393816600749002144[11] = 0;
   out_5393816600749002144[12] = 0;
   out_5393816600749002144[13] = 0;
   out_5393816600749002144[14] = 0;
   out_5393816600749002144[15] = 0;
   out_5393816600749002144[16] = 0;
   out_5393816600749002144[17] = 0;
   out_5393816600749002144[18] = 0;
   out_5393816600749002144[19] = 0;
   out_5393816600749002144[20] = 0;
   out_5393816600749002144[21] = 0;
   out_5393816600749002144[22] = 1;
   out_5393816600749002144[23] = 0;
   out_5393816600749002144[24] = 0;
   out_5393816600749002144[25] = 0;
   out_5393816600749002144[26] = 0;
   out_5393816600749002144[27] = 0;
   out_5393816600749002144[28] = 0;
   out_5393816600749002144[29] = 0;
   out_5393816600749002144[30] = 0;
   out_5393816600749002144[31] = 0;
   out_5393816600749002144[32] = 0;
   out_5393816600749002144[33] = 0;
   out_5393816600749002144[34] = 0;
   out_5393816600749002144[35] = 0;
   out_5393816600749002144[36] = 0;
   out_5393816600749002144[37] = 0;
   out_5393816600749002144[38] = 0;
   out_5393816600749002144[39] = 0;
   out_5393816600749002144[40] = 0;
   out_5393816600749002144[41] = 1;
   out_5393816600749002144[42] = 0;
   out_5393816600749002144[43] = 0;
   out_5393816600749002144[44] = 0;
   out_5393816600749002144[45] = 0;
   out_5393816600749002144[46] = 0;
   out_5393816600749002144[47] = 0;
   out_5393816600749002144[48] = 0;
   out_5393816600749002144[49] = 0;
   out_5393816600749002144[50] = 0;
   out_5393816600749002144[51] = 0;
   out_5393816600749002144[52] = 0;
   out_5393816600749002144[53] = 0;
}
void h_14(double *state, double *unused, double *out_192900434341408297) {
   out_192900434341408297[0] = state[6];
   out_192900434341408297[1] = state[7];
   out_192900434341408297[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1746426248771785744) {
   out_1746426248771785744[0] = 0;
   out_1746426248771785744[1] = 0;
   out_1746426248771785744[2] = 0;
   out_1746426248771785744[3] = 0;
   out_1746426248771785744[4] = 0;
   out_1746426248771785744[5] = 0;
   out_1746426248771785744[6] = 1;
   out_1746426248771785744[7] = 0;
   out_1746426248771785744[8] = 0;
   out_1746426248771785744[9] = 0;
   out_1746426248771785744[10] = 0;
   out_1746426248771785744[11] = 0;
   out_1746426248771785744[12] = 0;
   out_1746426248771785744[13] = 0;
   out_1746426248771785744[14] = 0;
   out_1746426248771785744[15] = 0;
   out_1746426248771785744[16] = 0;
   out_1746426248771785744[17] = 0;
   out_1746426248771785744[18] = 0;
   out_1746426248771785744[19] = 0;
   out_1746426248771785744[20] = 0;
   out_1746426248771785744[21] = 0;
   out_1746426248771785744[22] = 0;
   out_1746426248771785744[23] = 0;
   out_1746426248771785744[24] = 0;
   out_1746426248771785744[25] = 1;
   out_1746426248771785744[26] = 0;
   out_1746426248771785744[27] = 0;
   out_1746426248771785744[28] = 0;
   out_1746426248771785744[29] = 0;
   out_1746426248771785744[30] = 0;
   out_1746426248771785744[31] = 0;
   out_1746426248771785744[32] = 0;
   out_1746426248771785744[33] = 0;
   out_1746426248771785744[34] = 0;
   out_1746426248771785744[35] = 0;
   out_1746426248771785744[36] = 0;
   out_1746426248771785744[37] = 0;
   out_1746426248771785744[38] = 0;
   out_1746426248771785744[39] = 0;
   out_1746426248771785744[40] = 0;
   out_1746426248771785744[41] = 0;
   out_1746426248771785744[42] = 0;
   out_1746426248771785744[43] = 0;
   out_1746426248771785744[44] = 1;
   out_1746426248771785744[45] = 0;
   out_1746426248771785744[46] = 0;
   out_1746426248771785744[47] = 0;
   out_1746426248771785744[48] = 0;
   out_1746426248771785744[49] = 0;
   out_1746426248771785744[50] = 0;
   out_1746426248771785744[51] = 0;
   out_1746426248771785744[52] = 0;
   out_1746426248771785744[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2665641701635233151) {
  err_fun(nom_x, delta_x, out_2665641701635233151);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8375727440013270020) {
  inv_err_fun(nom_x, true_x, out_8375727440013270020);
}
void pose_H_mod_fun(double *state, double *out_6067255468928274013) {
  H_mod_fun(state, out_6067255468928274013);
}
void pose_f_fun(double *state, double dt, double *out_6773782600033783154) {
  f_fun(state,  dt, out_6773782600033783154);
}
void pose_F_fun(double *state, double dt, double *out_6298375408118706110) {
  F_fun(state,  dt, out_6298375408118706110);
}
void pose_h_4(double *state, double *unused, double *out_6452539322350206189) {
  h_4(state, unused, out_6452539322350206189);
}
void pose_H_4(double *state, double *unused, double *out_4829214681067158040) {
  H_4(state, unused, out_4829214681067158040);
}
void pose_h_10(double *state, double *unused, double *out_5957134933492111448) {
  h_10(state, unused, out_5957134933492111448);
}
void pose_H_10(double *state, double *unused, double *out_3625295134339217134) {
  H_10(state, unused, out_3625295134339217134);
}
void pose_h_13(double *state, double *unused, double *out_6701412570788452504) {
  h_13(state, unused, out_6701412570788452504);
}
void pose_H_13(double *state, double *unused, double *out_5393816600749002144) {
  H_13(state, unused, out_5393816600749002144);
}
void pose_h_14(double *state, double *unused, double *out_192900434341408297) {
  h_14(state, unused, out_192900434341408297);
}
void pose_H_14(double *state, double *unused, double *out_1746426248771785744) {
  H_14(state, unused, out_1746426248771785744);
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
