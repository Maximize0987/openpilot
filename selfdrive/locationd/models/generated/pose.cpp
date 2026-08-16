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
void err_fun(double *nom_x, double *delta_x, double *out_776419627085520882) {
   out_776419627085520882[0] = delta_x[0] + nom_x[0];
   out_776419627085520882[1] = delta_x[1] + nom_x[1];
   out_776419627085520882[2] = delta_x[2] + nom_x[2];
   out_776419627085520882[3] = delta_x[3] + nom_x[3];
   out_776419627085520882[4] = delta_x[4] + nom_x[4];
   out_776419627085520882[5] = delta_x[5] + nom_x[5];
   out_776419627085520882[6] = delta_x[6] + nom_x[6];
   out_776419627085520882[7] = delta_x[7] + nom_x[7];
   out_776419627085520882[8] = delta_x[8] + nom_x[8];
   out_776419627085520882[9] = delta_x[9] + nom_x[9];
   out_776419627085520882[10] = delta_x[10] + nom_x[10];
   out_776419627085520882[11] = delta_x[11] + nom_x[11];
   out_776419627085520882[12] = delta_x[12] + nom_x[12];
   out_776419627085520882[13] = delta_x[13] + nom_x[13];
   out_776419627085520882[14] = delta_x[14] + nom_x[14];
   out_776419627085520882[15] = delta_x[15] + nom_x[15];
   out_776419627085520882[16] = delta_x[16] + nom_x[16];
   out_776419627085520882[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3246049781621128423) {
   out_3246049781621128423[0] = -nom_x[0] + true_x[0];
   out_3246049781621128423[1] = -nom_x[1] + true_x[1];
   out_3246049781621128423[2] = -nom_x[2] + true_x[2];
   out_3246049781621128423[3] = -nom_x[3] + true_x[3];
   out_3246049781621128423[4] = -nom_x[4] + true_x[4];
   out_3246049781621128423[5] = -nom_x[5] + true_x[5];
   out_3246049781621128423[6] = -nom_x[6] + true_x[6];
   out_3246049781621128423[7] = -nom_x[7] + true_x[7];
   out_3246049781621128423[8] = -nom_x[8] + true_x[8];
   out_3246049781621128423[9] = -nom_x[9] + true_x[9];
   out_3246049781621128423[10] = -nom_x[10] + true_x[10];
   out_3246049781621128423[11] = -nom_x[11] + true_x[11];
   out_3246049781621128423[12] = -nom_x[12] + true_x[12];
   out_3246049781621128423[13] = -nom_x[13] + true_x[13];
   out_3246049781621128423[14] = -nom_x[14] + true_x[14];
   out_3246049781621128423[15] = -nom_x[15] + true_x[15];
   out_3246049781621128423[16] = -nom_x[16] + true_x[16];
   out_3246049781621128423[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_5710430290201935803) {
   out_5710430290201935803[0] = 1.0;
   out_5710430290201935803[1] = 0.0;
   out_5710430290201935803[2] = 0.0;
   out_5710430290201935803[3] = 0.0;
   out_5710430290201935803[4] = 0.0;
   out_5710430290201935803[5] = 0.0;
   out_5710430290201935803[6] = 0.0;
   out_5710430290201935803[7] = 0.0;
   out_5710430290201935803[8] = 0.0;
   out_5710430290201935803[9] = 0.0;
   out_5710430290201935803[10] = 0.0;
   out_5710430290201935803[11] = 0.0;
   out_5710430290201935803[12] = 0.0;
   out_5710430290201935803[13] = 0.0;
   out_5710430290201935803[14] = 0.0;
   out_5710430290201935803[15] = 0.0;
   out_5710430290201935803[16] = 0.0;
   out_5710430290201935803[17] = 0.0;
   out_5710430290201935803[18] = 0.0;
   out_5710430290201935803[19] = 1.0;
   out_5710430290201935803[20] = 0.0;
   out_5710430290201935803[21] = 0.0;
   out_5710430290201935803[22] = 0.0;
   out_5710430290201935803[23] = 0.0;
   out_5710430290201935803[24] = 0.0;
   out_5710430290201935803[25] = 0.0;
   out_5710430290201935803[26] = 0.0;
   out_5710430290201935803[27] = 0.0;
   out_5710430290201935803[28] = 0.0;
   out_5710430290201935803[29] = 0.0;
   out_5710430290201935803[30] = 0.0;
   out_5710430290201935803[31] = 0.0;
   out_5710430290201935803[32] = 0.0;
   out_5710430290201935803[33] = 0.0;
   out_5710430290201935803[34] = 0.0;
   out_5710430290201935803[35] = 0.0;
   out_5710430290201935803[36] = 0.0;
   out_5710430290201935803[37] = 0.0;
   out_5710430290201935803[38] = 1.0;
   out_5710430290201935803[39] = 0.0;
   out_5710430290201935803[40] = 0.0;
   out_5710430290201935803[41] = 0.0;
   out_5710430290201935803[42] = 0.0;
   out_5710430290201935803[43] = 0.0;
   out_5710430290201935803[44] = 0.0;
   out_5710430290201935803[45] = 0.0;
   out_5710430290201935803[46] = 0.0;
   out_5710430290201935803[47] = 0.0;
   out_5710430290201935803[48] = 0.0;
   out_5710430290201935803[49] = 0.0;
   out_5710430290201935803[50] = 0.0;
   out_5710430290201935803[51] = 0.0;
   out_5710430290201935803[52] = 0.0;
   out_5710430290201935803[53] = 0.0;
   out_5710430290201935803[54] = 0.0;
   out_5710430290201935803[55] = 0.0;
   out_5710430290201935803[56] = 0.0;
   out_5710430290201935803[57] = 1.0;
   out_5710430290201935803[58] = 0.0;
   out_5710430290201935803[59] = 0.0;
   out_5710430290201935803[60] = 0.0;
   out_5710430290201935803[61] = 0.0;
   out_5710430290201935803[62] = 0.0;
   out_5710430290201935803[63] = 0.0;
   out_5710430290201935803[64] = 0.0;
   out_5710430290201935803[65] = 0.0;
   out_5710430290201935803[66] = 0.0;
   out_5710430290201935803[67] = 0.0;
   out_5710430290201935803[68] = 0.0;
   out_5710430290201935803[69] = 0.0;
   out_5710430290201935803[70] = 0.0;
   out_5710430290201935803[71] = 0.0;
   out_5710430290201935803[72] = 0.0;
   out_5710430290201935803[73] = 0.0;
   out_5710430290201935803[74] = 0.0;
   out_5710430290201935803[75] = 0.0;
   out_5710430290201935803[76] = 1.0;
   out_5710430290201935803[77] = 0.0;
   out_5710430290201935803[78] = 0.0;
   out_5710430290201935803[79] = 0.0;
   out_5710430290201935803[80] = 0.0;
   out_5710430290201935803[81] = 0.0;
   out_5710430290201935803[82] = 0.0;
   out_5710430290201935803[83] = 0.0;
   out_5710430290201935803[84] = 0.0;
   out_5710430290201935803[85] = 0.0;
   out_5710430290201935803[86] = 0.0;
   out_5710430290201935803[87] = 0.0;
   out_5710430290201935803[88] = 0.0;
   out_5710430290201935803[89] = 0.0;
   out_5710430290201935803[90] = 0.0;
   out_5710430290201935803[91] = 0.0;
   out_5710430290201935803[92] = 0.0;
   out_5710430290201935803[93] = 0.0;
   out_5710430290201935803[94] = 0.0;
   out_5710430290201935803[95] = 1.0;
   out_5710430290201935803[96] = 0.0;
   out_5710430290201935803[97] = 0.0;
   out_5710430290201935803[98] = 0.0;
   out_5710430290201935803[99] = 0.0;
   out_5710430290201935803[100] = 0.0;
   out_5710430290201935803[101] = 0.0;
   out_5710430290201935803[102] = 0.0;
   out_5710430290201935803[103] = 0.0;
   out_5710430290201935803[104] = 0.0;
   out_5710430290201935803[105] = 0.0;
   out_5710430290201935803[106] = 0.0;
   out_5710430290201935803[107] = 0.0;
   out_5710430290201935803[108] = 0.0;
   out_5710430290201935803[109] = 0.0;
   out_5710430290201935803[110] = 0.0;
   out_5710430290201935803[111] = 0.0;
   out_5710430290201935803[112] = 0.0;
   out_5710430290201935803[113] = 0.0;
   out_5710430290201935803[114] = 1.0;
   out_5710430290201935803[115] = 0.0;
   out_5710430290201935803[116] = 0.0;
   out_5710430290201935803[117] = 0.0;
   out_5710430290201935803[118] = 0.0;
   out_5710430290201935803[119] = 0.0;
   out_5710430290201935803[120] = 0.0;
   out_5710430290201935803[121] = 0.0;
   out_5710430290201935803[122] = 0.0;
   out_5710430290201935803[123] = 0.0;
   out_5710430290201935803[124] = 0.0;
   out_5710430290201935803[125] = 0.0;
   out_5710430290201935803[126] = 0.0;
   out_5710430290201935803[127] = 0.0;
   out_5710430290201935803[128] = 0.0;
   out_5710430290201935803[129] = 0.0;
   out_5710430290201935803[130] = 0.0;
   out_5710430290201935803[131] = 0.0;
   out_5710430290201935803[132] = 0.0;
   out_5710430290201935803[133] = 1.0;
   out_5710430290201935803[134] = 0.0;
   out_5710430290201935803[135] = 0.0;
   out_5710430290201935803[136] = 0.0;
   out_5710430290201935803[137] = 0.0;
   out_5710430290201935803[138] = 0.0;
   out_5710430290201935803[139] = 0.0;
   out_5710430290201935803[140] = 0.0;
   out_5710430290201935803[141] = 0.0;
   out_5710430290201935803[142] = 0.0;
   out_5710430290201935803[143] = 0.0;
   out_5710430290201935803[144] = 0.0;
   out_5710430290201935803[145] = 0.0;
   out_5710430290201935803[146] = 0.0;
   out_5710430290201935803[147] = 0.0;
   out_5710430290201935803[148] = 0.0;
   out_5710430290201935803[149] = 0.0;
   out_5710430290201935803[150] = 0.0;
   out_5710430290201935803[151] = 0.0;
   out_5710430290201935803[152] = 1.0;
   out_5710430290201935803[153] = 0.0;
   out_5710430290201935803[154] = 0.0;
   out_5710430290201935803[155] = 0.0;
   out_5710430290201935803[156] = 0.0;
   out_5710430290201935803[157] = 0.0;
   out_5710430290201935803[158] = 0.0;
   out_5710430290201935803[159] = 0.0;
   out_5710430290201935803[160] = 0.0;
   out_5710430290201935803[161] = 0.0;
   out_5710430290201935803[162] = 0.0;
   out_5710430290201935803[163] = 0.0;
   out_5710430290201935803[164] = 0.0;
   out_5710430290201935803[165] = 0.0;
   out_5710430290201935803[166] = 0.0;
   out_5710430290201935803[167] = 0.0;
   out_5710430290201935803[168] = 0.0;
   out_5710430290201935803[169] = 0.0;
   out_5710430290201935803[170] = 0.0;
   out_5710430290201935803[171] = 1.0;
   out_5710430290201935803[172] = 0.0;
   out_5710430290201935803[173] = 0.0;
   out_5710430290201935803[174] = 0.0;
   out_5710430290201935803[175] = 0.0;
   out_5710430290201935803[176] = 0.0;
   out_5710430290201935803[177] = 0.0;
   out_5710430290201935803[178] = 0.0;
   out_5710430290201935803[179] = 0.0;
   out_5710430290201935803[180] = 0.0;
   out_5710430290201935803[181] = 0.0;
   out_5710430290201935803[182] = 0.0;
   out_5710430290201935803[183] = 0.0;
   out_5710430290201935803[184] = 0.0;
   out_5710430290201935803[185] = 0.0;
   out_5710430290201935803[186] = 0.0;
   out_5710430290201935803[187] = 0.0;
   out_5710430290201935803[188] = 0.0;
   out_5710430290201935803[189] = 0.0;
   out_5710430290201935803[190] = 1.0;
   out_5710430290201935803[191] = 0.0;
   out_5710430290201935803[192] = 0.0;
   out_5710430290201935803[193] = 0.0;
   out_5710430290201935803[194] = 0.0;
   out_5710430290201935803[195] = 0.0;
   out_5710430290201935803[196] = 0.0;
   out_5710430290201935803[197] = 0.0;
   out_5710430290201935803[198] = 0.0;
   out_5710430290201935803[199] = 0.0;
   out_5710430290201935803[200] = 0.0;
   out_5710430290201935803[201] = 0.0;
   out_5710430290201935803[202] = 0.0;
   out_5710430290201935803[203] = 0.0;
   out_5710430290201935803[204] = 0.0;
   out_5710430290201935803[205] = 0.0;
   out_5710430290201935803[206] = 0.0;
   out_5710430290201935803[207] = 0.0;
   out_5710430290201935803[208] = 0.0;
   out_5710430290201935803[209] = 1.0;
   out_5710430290201935803[210] = 0.0;
   out_5710430290201935803[211] = 0.0;
   out_5710430290201935803[212] = 0.0;
   out_5710430290201935803[213] = 0.0;
   out_5710430290201935803[214] = 0.0;
   out_5710430290201935803[215] = 0.0;
   out_5710430290201935803[216] = 0.0;
   out_5710430290201935803[217] = 0.0;
   out_5710430290201935803[218] = 0.0;
   out_5710430290201935803[219] = 0.0;
   out_5710430290201935803[220] = 0.0;
   out_5710430290201935803[221] = 0.0;
   out_5710430290201935803[222] = 0.0;
   out_5710430290201935803[223] = 0.0;
   out_5710430290201935803[224] = 0.0;
   out_5710430290201935803[225] = 0.0;
   out_5710430290201935803[226] = 0.0;
   out_5710430290201935803[227] = 0.0;
   out_5710430290201935803[228] = 1.0;
   out_5710430290201935803[229] = 0.0;
   out_5710430290201935803[230] = 0.0;
   out_5710430290201935803[231] = 0.0;
   out_5710430290201935803[232] = 0.0;
   out_5710430290201935803[233] = 0.0;
   out_5710430290201935803[234] = 0.0;
   out_5710430290201935803[235] = 0.0;
   out_5710430290201935803[236] = 0.0;
   out_5710430290201935803[237] = 0.0;
   out_5710430290201935803[238] = 0.0;
   out_5710430290201935803[239] = 0.0;
   out_5710430290201935803[240] = 0.0;
   out_5710430290201935803[241] = 0.0;
   out_5710430290201935803[242] = 0.0;
   out_5710430290201935803[243] = 0.0;
   out_5710430290201935803[244] = 0.0;
   out_5710430290201935803[245] = 0.0;
   out_5710430290201935803[246] = 0.0;
   out_5710430290201935803[247] = 1.0;
   out_5710430290201935803[248] = 0.0;
   out_5710430290201935803[249] = 0.0;
   out_5710430290201935803[250] = 0.0;
   out_5710430290201935803[251] = 0.0;
   out_5710430290201935803[252] = 0.0;
   out_5710430290201935803[253] = 0.0;
   out_5710430290201935803[254] = 0.0;
   out_5710430290201935803[255] = 0.0;
   out_5710430290201935803[256] = 0.0;
   out_5710430290201935803[257] = 0.0;
   out_5710430290201935803[258] = 0.0;
   out_5710430290201935803[259] = 0.0;
   out_5710430290201935803[260] = 0.0;
   out_5710430290201935803[261] = 0.0;
   out_5710430290201935803[262] = 0.0;
   out_5710430290201935803[263] = 0.0;
   out_5710430290201935803[264] = 0.0;
   out_5710430290201935803[265] = 0.0;
   out_5710430290201935803[266] = 1.0;
   out_5710430290201935803[267] = 0.0;
   out_5710430290201935803[268] = 0.0;
   out_5710430290201935803[269] = 0.0;
   out_5710430290201935803[270] = 0.0;
   out_5710430290201935803[271] = 0.0;
   out_5710430290201935803[272] = 0.0;
   out_5710430290201935803[273] = 0.0;
   out_5710430290201935803[274] = 0.0;
   out_5710430290201935803[275] = 0.0;
   out_5710430290201935803[276] = 0.0;
   out_5710430290201935803[277] = 0.0;
   out_5710430290201935803[278] = 0.0;
   out_5710430290201935803[279] = 0.0;
   out_5710430290201935803[280] = 0.0;
   out_5710430290201935803[281] = 0.0;
   out_5710430290201935803[282] = 0.0;
   out_5710430290201935803[283] = 0.0;
   out_5710430290201935803[284] = 0.0;
   out_5710430290201935803[285] = 1.0;
   out_5710430290201935803[286] = 0.0;
   out_5710430290201935803[287] = 0.0;
   out_5710430290201935803[288] = 0.0;
   out_5710430290201935803[289] = 0.0;
   out_5710430290201935803[290] = 0.0;
   out_5710430290201935803[291] = 0.0;
   out_5710430290201935803[292] = 0.0;
   out_5710430290201935803[293] = 0.0;
   out_5710430290201935803[294] = 0.0;
   out_5710430290201935803[295] = 0.0;
   out_5710430290201935803[296] = 0.0;
   out_5710430290201935803[297] = 0.0;
   out_5710430290201935803[298] = 0.0;
   out_5710430290201935803[299] = 0.0;
   out_5710430290201935803[300] = 0.0;
   out_5710430290201935803[301] = 0.0;
   out_5710430290201935803[302] = 0.0;
   out_5710430290201935803[303] = 0.0;
   out_5710430290201935803[304] = 1.0;
   out_5710430290201935803[305] = 0.0;
   out_5710430290201935803[306] = 0.0;
   out_5710430290201935803[307] = 0.0;
   out_5710430290201935803[308] = 0.0;
   out_5710430290201935803[309] = 0.0;
   out_5710430290201935803[310] = 0.0;
   out_5710430290201935803[311] = 0.0;
   out_5710430290201935803[312] = 0.0;
   out_5710430290201935803[313] = 0.0;
   out_5710430290201935803[314] = 0.0;
   out_5710430290201935803[315] = 0.0;
   out_5710430290201935803[316] = 0.0;
   out_5710430290201935803[317] = 0.0;
   out_5710430290201935803[318] = 0.0;
   out_5710430290201935803[319] = 0.0;
   out_5710430290201935803[320] = 0.0;
   out_5710430290201935803[321] = 0.0;
   out_5710430290201935803[322] = 0.0;
   out_5710430290201935803[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5795859550853760244) {
   out_5795859550853760244[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5795859550853760244[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5795859550853760244[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5795859550853760244[3] = dt*state[12] + state[3];
   out_5795859550853760244[4] = dt*state[13] + state[4];
   out_5795859550853760244[5] = dt*state[14] + state[5];
   out_5795859550853760244[6] = state[6];
   out_5795859550853760244[7] = state[7];
   out_5795859550853760244[8] = state[8];
   out_5795859550853760244[9] = state[9];
   out_5795859550853760244[10] = state[10];
   out_5795859550853760244[11] = state[11];
   out_5795859550853760244[12] = state[12];
   out_5795859550853760244[13] = state[13];
   out_5795859550853760244[14] = state[14];
   out_5795859550853760244[15] = state[15];
   out_5795859550853760244[16] = state[16];
   out_5795859550853760244[17] = state[17];
}
void F_fun(double *state, double dt, double *out_391118642873528758) {
   out_391118642873528758[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_391118642873528758[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_391118642873528758[2] = 0;
   out_391118642873528758[3] = 0;
   out_391118642873528758[4] = 0;
   out_391118642873528758[5] = 0;
   out_391118642873528758[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_391118642873528758[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_391118642873528758[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_391118642873528758[9] = 0;
   out_391118642873528758[10] = 0;
   out_391118642873528758[11] = 0;
   out_391118642873528758[12] = 0;
   out_391118642873528758[13] = 0;
   out_391118642873528758[14] = 0;
   out_391118642873528758[15] = 0;
   out_391118642873528758[16] = 0;
   out_391118642873528758[17] = 0;
   out_391118642873528758[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_391118642873528758[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_391118642873528758[20] = 0;
   out_391118642873528758[21] = 0;
   out_391118642873528758[22] = 0;
   out_391118642873528758[23] = 0;
   out_391118642873528758[24] = 0;
   out_391118642873528758[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_391118642873528758[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_391118642873528758[27] = 0;
   out_391118642873528758[28] = 0;
   out_391118642873528758[29] = 0;
   out_391118642873528758[30] = 0;
   out_391118642873528758[31] = 0;
   out_391118642873528758[32] = 0;
   out_391118642873528758[33] = 0;
   out_391118642873528758[34] = 0;
   out_391118642873528758[35] = 0;
   out_391118642873528758[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_391118642873528758[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_391118642873528758[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_391118642873528758[39] = 0;
   out_391118642873528758[40] = 0;
   out_391118642873528758[41] = 0;
   out_391118642873528758[42] = 0;
   out_391118642873528758[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_391118642873528758[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_391118642873528758[45] = 0;
   out_391118642873528758[46] = 0;
   out_391118642873528758[47] = 0;
   out_391118642873528758[48] = 0;
   out_391118642873528758[49] = 0;
   out_391118642873528758[50] = 0;
   out_391118642873528758[51] = 0;
   out_391118642873528758[52] = 0;
   out_391118642873528758[53] = 0;
   out_391118642873528758[54] = 0;
   out_391118642873528758[55] = 0;
   out_391118642873528758[56] = 0;
   out_391118642873528758[57] = 1;
   out_391118642873528758[58] = 0;
   out_391118642873528758[59] = 0;
   out_391118642873528758[60] = 0;
   out_391118642873528758[61] = 0;
   out_391118642873528758[62] = 0;
   out_391118642873528758[63] = 0;
   out_391118642873528758[64] = 0;
   out_391118642873528758[65] = 0;
   out_391118642873528758[66] = dt;
   out_391118642873528758[67] = 0;
   out_391118642873528758[68] = 0;
   out_391118642873528758[69] = 0;
   out_391118642873528758[70] = 0;
   out_391118642873528758[71] = 0;
   out_391118642873528758[72] = 0;
   out_391118642873528758[73] = 0;
   out_391118642873528758[74] = 0;
   out_391118642873528758[75] = 0;
   out_391118642873528758[76] = 1;
   out_391118642873528758[77] = 0;
   out_391118642873528758[78] = 0;
   out_391118642873528758[79] = 0;
   out_391118642873528758[80] = 0;
   out_391118642873528758[81] = 0;
   out_391118642873528758[82] = 0;
   out_391118642873528758[83] = 0;
   out_391118642873528758[84] = 0;
   out_391118642873528758[85] = dt;
   out_391118642873528758[86] = 0;
   out_391118642873528758[87] = 0;
   out_391118642873528758[88] = 0;
   out_391118642873528758[89] = 0;
   out_391118642873528758[90] = 0;
   out_391118642873528758[91] = 0;
   out_391118642873528758[92] = 0;
   out_391118642873528758[93] = 0;
   out_391118642873528758[94] = 0;
   out_391118642873528758[95] = 1;
   out_391118642873528758[96] = 0;
   out_391118642873528758[97] = 0;
   out_391118642873528758[98] = 0;
   out_391118642873528758[99] = 0;
   out_391118642873528758[100] = 0;
   out_391118642873528758[101] = 0;
   out_391118642873528758[102] = 0;
   out_391118642873528758[103] = 0;
   out_391118642873528758[104] = dt;
   out_391118642873528758[105] = 0;
   out_391118642873528758[106] = 0;
   out_391118642873528758[107] = 0;
   out_391118642873528758[108] = 0;
   out_391118642873528758[109] = 0;
   out_391118642873528758[110] = 0;
   out_391118642873528758[111] = 0;
   out_391118642873528758[112] = 0;
   out_391118642873528758[113] = 0;
   out_391118642873528758[114] = 1;
   out_391118642873528758[115] = 0;
   out_391118642873528758[116] = 0;
   out_391118642873528758[117] = 0;
   out_391118642873528758[118] = 0;
   out_391118642873528758[119] = 0;
   out_391118642873528758[120] = 0;
   out_391118642873528758[121] = 0;
   out_391118642873528758[122] = 0;
   out_391118642873528758[123] = 0;
   out_391118642873528758[124] = 0;
   out_391118642873528758[125] = 0;
   out_391118642873528758[126] = 0;
   out_391118642873528758[127] = 0;
   out_391118642873528758[128] = 0;
   out_391118642873528758[129] = 0;
   out_391118642873528758[130] = 0;
   out_391118642873528758[131] = 0;
   out_391118642873528758[132] = 0;
   out_391118642873528758[133] = 1;
   out_391118642873528758[134] = 0;
   out_391118642873528758[135] = 0;
   out_391118642873528758[136] = 0;
   out_391118642873528758[137] = 0;
   out_391118642873528758[138] = 0;
   out_391118642873528758[139] = 0;
   out_391118642873528758[140] = 0;
   out_391118642873528758[141] = 0;
   out_391118642873528758[142] = 0;
   out_391118642873528758[143] = 0;
   out_391118642873528758[144] = 0;
   out_391118642873528758[145] = 0;
   out_391118642873528758[146] = 0;
   out_391118642873528758[147] = 0;
   out_391118642873528758[148] = 0;
   out_391118642873528758[149] = 0;
   out_391118642873528758[150] = 0;
   out_391118642873528758[151] = 0;
   out_391118642873528758[152] = 1;
   out_391118642873528758[153] = 0;
   out_391118642873528758[154] = 0;
   out_391118642873528758[155] = 0;
   out_391118642873528758[156] = 0;
   out_391118642873528758[157] = 0;
   out_391118642873528758[158] = 0;
   out_391118642873528758[159] = 0;
   out_391118642873528758[160] = 0;
   out_391118642873528758[161] = 0;
   out_391118642873528758[162] = 0;
   out_391118642873528758[163] = 0;
   out_391118642873528758[164] = 0;
   out_391118642873528758[165] = 0;
   out_391118642873528758[166] = 0;
   out_391118642873528758[167] = 0;
   out_391118642873528758[168] = 0;
   out_391118642873528758[169] = 0;
   out_391118642873528758[170] = 0;
   out_391118642873528758[171] = 1;
   out_391118642873528758[172] = 0;
   out_391118642873528758[173] = 0;
   out_391118642873528758[174] = 0;
   out_391118642873528758[175] = 0;
   out_391118642873528758[176] = 0;
   out_391118642873528758[177] = 0;
   out_391118642873528758[178] = 0;
   out_391118642873528758[179] = 0;
   out_391118642873528758[180] = 0;
   out_391118642873528758[181] = 0;
   out_391118642873528758[182] = 0;
   out_391118642873528758[183] = 0;
   out_391118642873528758[184] = 0;
   out_391118642873528758[185] = 0;
   out_391118642873528758[186] = 0;
   out_391118642873528758[187] = 0;
   out_391118642873528758[188] = 0;
   out_391118642873528758[189] = 0;
   out_391118642873528758[190] = 1;
   out_391118642873528758[191] = 0;
   out_391118642873528758[192] = 0;
   out_391118642873528758[193] = 0;
   out_391118642873528758[194] = 0;
   out_391118642873528758[195] = 0;
   out_391118642873528758[196] = 0;
   out_391118642873528758[197] = 0;
   out_391118642873528758[198] = 0;
   out_391118642873528758[199] = 0;
   out_391118642873528758[200] = 0;
   out_391118642873528758[201] = 0;
   out_391118642873528758[202] = 0;
   out_391118642873528758[203] = 0;
   out_391118642873528758[204] = 0;
   out_391118642873528758[205] = 0;
   out_391118642873528758[206] = 0;
   out_391118642873528758[207] = 0;
   out_391118642873528758[208] = 0;
   out_391118642873528758[209] = 1;
   out_391118642873528758[210] = 0;
   out_391118642873528758[211] = 0;
   out_391118642873528758[212] = 0;
   out_391118642873528758[213] = 0;
   out_391118642873528758[214] = 0;
   out_391118642873528758[215] = 0;
   out_391118642873528758[216] = 0;
   out_391118642873528758[217] = 0;
   out_391118642873528758[218] = 0;
   out_391118642873528758[219] = 0;
   out_391118642873528758[220] = 0;
   out_391118642873528758[221] = 0;
   out_391118642873528758[222] = 0;
   out_391118642873528758[223] = 0;
   out_391118642873528758[224] = 0;
   out_391118642873528758[225] = 0;
   out_391118642873528758[226] = 0;
   out_391118642873528758[227] = 0;
   out_391118642873528758[228] = 1;
   out_391118642873528758[229] = 0;
   out_391118642873528758[230] = 0;
   out_391118642873528758[231] = 0;
   out_391118642873528758[232] = 0;
   out_391118642873528758[233] = 0;
   out_391118642873528758[234] = 0;
   out_391118642873528758[235] = 0;
   out_391118642873528758[236] = 0;
   out_391118642873528758[237] = 0;
   out_391118642873528758[238] = 0;
   out_391118642873528758[239] = 0;
   out_391118642873528758[240] = 0;
   out_391118642873528758[241] = 0;
   out_391118642873528758[242] = 0;
   out_391118642873528758[243] = 0;
   out_391118642873528758[244] = 0;
   out_391118642873528758[245] = 0;
   out_391118642873528758[246] = 0;
   out_391118642873528758[247] = 1;
   out_391118642873528758[248] = 0;
   out_391118642873528758[249] = 0;
   out_391118642873528758[250] = 0;
   out_391118642873528758[251] = 0;
   out_391118642873528758[252] = 0;
   out_391118642873528758[253] = 0;
   out_391118642873528758[254] = 0;
   out_391118642873528758[255] = 0;
   out_391118642873528758[256] = 0;
   out_391118642873528758[257] = 0;
   out_391118642873528758[258] = 0;
   out_391118642873528758[259] = 0;
   out_391118642873528758[260] = 0;
   out_391118642873528758[261] = 0;
   out_391118642873528758[262] = 0;
   out_391118642873528758[263] = 0;
   out_391118642873528758[264] = 0;
   out_391118642873528758[265] = 0;
   out_391118642873528758[266] = 1;
   out_391118642873528758[267] = 0;
   out_391118642873528758[268] = 0;
   out_391118642873528758[269] = 0;
   out_391118642873528758[270] = 0;
   out_391118642873528758[271] = 0;
   out_391118642873528758[272] = 0;
   out_391118642873528758[273] = 0;
   out_391118642873528758[274] = 0;
   out_391118642873528758[275] = 0;
   out_391118642873528758[276] = 0;
   out_391118642873528758[277] = 0;
   out_391118642873528758[278] = 0;
   out_391118642873528758[279] = 0;
   out_391118642873528758[280] = 0;
   out_391118642873528758[281] = 0;
   out_391118642873528758[282] = 0;
   out_391118642873528758[283] = 0;
   out_391118642873528758[284] = 0;
   out_391118642873528758[285] = 1;
   out_391118642873528758[286] = 0;
   out_391118642873528758[287] = 0;
   out_391118642873528758[288] = 0;
   out_391118642873528758[289] = 0;
   out_391118642873528758[290] = 0;
   out_391118642873528758[291] = 0;
   out_391118642873528758[292] = 0;
   out_391118642873528758[293] = 0;
   out_391118642873528758[294] = 0;
   out_391118642873528758[295] = 0;
   out_391118642873528758[296] = 0;
   out_391118642873528758[297] = 0;
   out_391118642873528758[298] = 0;
   out_391118642873528758[299] = 0;
   out_391118642873528758[300] = 0;
   out_391118642873528758[301] = 0;
   out_391118642873528758[302] = 0;
   out_391118642873528758[303] = 0;
   out_391118642873528758[304] = 1;
   out_391118642873528758[305] = 0;
   out_391118642873528758[306] = 0;
   out_391118642873528758[307] = 0;
   out_391118642873528758[308] = 0;
   out_391118642873528758[309] = 0;
   out_391118642873528758[310] = 0;
   out_391118642873528758[311] = 0;
   out_391118642873528758[312] = 0;
   out_391118642873528758[313] = 0;
   out_391118642873528758[314] = 0;
   out_391118642873528758[315] = 0;
   out_391118642873528758[316] = 0;
   out_391118642873528758[317] = 0;
   out_391118642873528758[318] = 0;
   out_391118642873528758[319] = 0;
   out_391118642873528758[320] = 0;
   out_391118642873528758[321] = 0;
   out_391118642873528758[322] = 0;
   out_391118642873528758[323] = 1;
}
void h_4(double *state, double *unused, double *out_3587574498855600647) {
   out_3587574498855600647[0] = state[6] + state[9];
   out_3587574498855600647[1] = state[7] + state[10];
   out_3587574498855600647[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1095803253272619439) {
   out_1095803253272619439[0] = 0;
   out_1095803253272619439[1] = 0;
   out_1095803253272619439[2] = 0;
   out_1095803253272619439[3] = 0;
   out_1095803253272619439[4] = 0;
   out_1095803253272619439[5] = 0;
   out_1095803253272619439[6] = 1;
   out_1095803253272619439[7] = 0;
   out_1095803253272619439[8] = 0;
   out_1095803253272619439[9] = 1;
   out_1095803253272619439[10] = 0;
   out_1095803253272619439[11] = 0;
   out_1095803253272619439[12] = 0;
   out_1095803253272619439[13] = 0;
   out_1095803253272619439[14] = 0;
   out_1095803253272619439[15] = 0;
   out_1095803253272619439[16] = 0;
   out_1095803253272619439[17] = 0;
   out_1095803253272619439[18] = 0;
   out_1095803253272619439[19] = 0;
   out_1095803253272619439[20] = 0;
   out_1095803253272619439[21] = 0;
   out_1095803253272619439[22] = 0;
   out_1095803253272619439[23] = 0;
   out_1095803253272619439[24] = 0;
   out_1095803253272619439[25] = 1;
   out_1095803253272619439[26] = 0;
   out_1095803253272619439[27] = 0;
   out_1095803253272619439[28] = 1;
   out_1095803253272619439[29] = 0;
   out_1095803253272619439[30] = 0;
   out_1095803253272619439[31] = 0;
   out_1095803253272619439[32] = 0;
   out_1095803253272619439[33] = 0;
   out_1095803253272619439[34] = 0;
   out_1095803253272619439[35] = 0;
   out_1095803253272619439[36] = 0;
   out_1095803253272619439[37] = 0;
   out_1095803253272619439[38] = 0;
   out_1095803253272619439[39] = 0;
   out_1095803253272619439[40] = 0;
   out_1095803253272619439[41] = 0;
   out_1095803253272619439[42] = 0;
   out_1095803253272619439[43] = 0;
   out_1095803253272619439[44] = 1;
   out_1095803253272619439[45] = 0;
   out_1095803253272619439[46] = 0;
   out_1095803253272619439[47] = 1;
   out_1095803253272619439[48] = 0;
   out_1095803253272619439[49] = 0;
   out_1095803253272619439[50] = 0;
   out_1095803253272619439[51] = 0;
   out_1095803253272619439[52] = 0;
   out_1095803253272619439[53] = 0;
}
void h_10(double *state, double *unused, double *out_5054997698151726674) {
   out_5054997698151726674[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5054997698151726674[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5054997698151726674[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4117080739741493196) {
   out_4117080739741493196[0] = 0;
   out_4117080739741493196[1] = 9.8100000000000005*cos(state[1]);
   out_4117080739741493196[2] = 0;
   out_4117080739741493196[3] = 0;
   out_4117080739741493196[4] = -state[8];
   out_4117080739741493196[5] = state[7];
   out_4117080739741493196[6] = 0;
   out_4117080739741493196[7] = state[5];
   out_4117080739741493196[8] = -state[4];
   out_4117080739741493196[9] = 0;
   out_4117080739741493196[10] = 0;
   out_4117080739741493196[11] = 0;
   out_4117080739741493196[12] = 1;
   out_4117080739741493196[13] = 0;
   out_4117080739741493196[14] = 0;
   out_4117080739741493196[15] = 1;
   out_4117080739741493196[16] = 0;
   out_4117080739741493196[17] = 0;
   out_4117080739741493196[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4117080739741493196[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4117080739741493196[20] = 0;
   out_4117080739741493196[21] = state[8];
   out_4117080739741493196[22] = 0;
   out_4117080739741493196[23] = -state[6];
   out_4117080739741493196[24] = -state[5];
   out_4117080739741493196[25] = 0;
   out_4117080739741493196[26] = state[3];
   out_4117080739741493196[27] = 0;
   out_4117080739741493196[28] = 0;
   out_4117080739741493196[29] = 0;
   out_4117080739741493196[30] = 0;
   out_4117080739741493196[31] = 1;
   out_4117080739741493196[32] = 0;
   out_4117080739741493196[33] = 0;
   out_4117080739741493196[34] = 1;
   out_4117080739741493196[35] = 0;
   out_4117080739741493196[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4117080739741493196[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4117080739741493196[38] = 0;
   out_4117080739741493196[39] = -state[7];
   out_4117080739741493196[40] = state[6];
   out_4117080739741493196[41] = 0;
   out_4117080739741493196[42] = state[4];
   out_4117080739741493196[43] = -state[3];
   out_4117080739741493196[44] = 0;
   out_4117080739741493196[45] = 0;
   out_4117080739741493196[46] = 0;
   out_4117080739741493196[47] = 0;
   out_4117080739741493196[48] = 0;
   out_4117080739741493196[49] = 0;
   out_4117080739741493196[50] = 1;
   out_4117080739741493196[51] = 0;
   out_4117080739741493196[52] = 0;
   out_4117080739741493196[53] = 1;
}
void h_13(double *state, double *unused, double *out_3693365734857647821) {
   out_3693365734857647821[0] = state[3];
   out_3693365734857647821[1] = state[4];
   out_3693365734857647821[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6514827955044081490) {
   out_6514827955044081490[0] = 0;
   out_6514827955044081490[1] = 0;
   out_6514827955044081490[2] = 0;
   out_6514827955044081490[3] = 1;
   out_6514827955044081490[4] = 0;
   out_6514827955044081490[5] = 0;
   out_6514827955044081490[6] = 0;
   out_6514827955044081490[7] = 0;
   out_6514827955044081490[8] = 0;
   out_6514827955044081490[9] = 0;
   out_6514827955044081490[10] = 0;
   out_6514827955044081490[11] = 0;
   out_6514827955044081490[12] = 0;
   out_6514827955044081490[13] = 0;
   out_6514827955044081490[14] = 0;
   out_6514827955044081490[15] = 0;
   out_6514827955044081490[16] = 0;
   out_6514827955044081490[17] = 0;
   out_6514827955044081490[18] = 0;
   out_6514827955044081490[19] = 0;
   out_6514827955044081490[20] = 0;
   out_6514827955044081490[21] = 0;
   out_6514827955044081490[22] = 1;
   out_6514827955044081490[23] = 0;
   out_6514827955044081490[24] = 0;
   out_6514827955044081490[25] = 0;
   out_6514827955044081490[26] = 0;
   out_6514827955044081490[27] = 0;
   out_6514827955044081490[28] = 0;
   out_6514827955044081490[29] = 0;
   out_6514827955044081490[30] = 0;
   out_6514827955044081490[31] = 0;
   out_6514827955044081490[32] = 0;
   out_6514827955044081490[33] = 0;
   out_6514827955044081490[34] = 0;
   out_6514827955044081490[35] = 0;
   out_6514827955044081490[36] = 0;
   out_6514827955044081490[37] = 0;
   out_6514827955044081490[38] = 0;
   out_6514827955044081490[39] = 0;
   out_6514827955044081490[40] = 0;
   out_6514827955044081490[41] = 1;
   out_6514827955044081490[42] = 0;
   out_6514827955044081490[43] = 0;
   out_6514827955044081490[44] = 0;
   out_6514827955044081490[45] = 0;
   out_6514827955044081490[46] = 0;
   out_6514827955044081490[47] = 0;
   out_6514827955044081490[48] = 0;
   out_6514827955044081490[49] = 0;
   out_6514827955044081490[50] = 0;
   out_6514827955044081490[51] = 0;
   out_6514827955044081490[52] = 0;
   out_6514827955044081490[53] = 0;
}
void h_14(double *state, double *unused, double *out_1461011669399451348) {
   out_1461011669399451348[0] = state[6];
   out_1461011669399451348[1] = state[7];
   out_1461011669399451348[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2867437603066865090) {
   out_2867437603066865090[0] = 0;
   out_2867437603066865090[1] = 0;
   out_2867437603066865090[2] = 0;
   out_2867437603066865090[3] = 0;
   out_2867437603066865090[4] = 0;
   out_2867437603066865090[5] = 0;
   out_2867437603066865090[6] = 1;
   out_2867437603066865090[7] = 0;
   out_2867437603066865090[8] = 0;
   out_2867437603066865090[9] = 0;
   out_2867437603066865090[10] = 0;
   out_2867437603066865090[11] = 0;
   out_2867437603066865090[12] = 0;
   out_2867437603066865090[13] = 0;
   out_2867437603066865090[14] = 0;
   out_2867437603066865090[15] = 0;
   out_2867437603066865090[16] = 0;
   out_2867437603066865090[17] = 0;
   out_2867437603066865090[18] = 0;
   out_2867437603066865090[19] = 0;
   out_2867437603066865090[20] = 0;
   out_2867437603066865090[21] = 0;
   out_2867437603066865090[22] = 0;
   out_2867437603066865090[23] = 0;
   out_2867437603066865090[24] = 0;
   out_2867437603066865090[25] = 1;
   out_2867437603066865090[26] = 0;
   out_2867437603066865090[27] = 0;
   out_2867437603066865090[28] = 0;
   out_2867437603066865090[29] = 0;
   out_2867437603066865090[30] = 0;
   out_2867437603066865090[31] = 0;
   out_2867437603066865090[32] = 0;
   out_2867437603066865090[33] = 0;
   out_2867437603066865090[34] = 0;
   out_2867437603066865090[35] = 0;
   out_2867437603066865090[36] = 0;
   out_2867437603066865090[37] = 0;
   out_2867437603066865090[38] = 0;
   out_2867437603066865090[39] = 0;
   out_2867437603066865090[40] = 0;
   out_2867437603066865090[41] = 0;
   out_2867437603066865090[42] = 0;
   out_2867437603066865090[43] = 0;
   out_2867437603066865090[44] = 1;
   out_2867437603066865090[45] = 0;
   out_2867437603066865090[46] = 0;
   out_2867437603066865090[47] = 0;
   out_2867437603066865090[48] = 0;
   out_2867437603066865090[49] = 0;
   out_2867437603066865090[50] = 0;
   out_2867437603066865090[51] = 0;
   out_2867437603066865090[52] = 0;
   out_2867437603066865090[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_776419627085520882) {
  err_fun(nom_x, delta_x, out_776419627085520882);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3246049781621128423) {
  inv_err_fun(nom_x, true_x, out_3246049781621128423);
}
void pose_H_mod_fun(double *state, double *out_5710430290201935803) {
  H_mod_fun(state, out_5710430290201935803);
}
void pose_f_fun(double *state, double dt, double *out_5795859550853760244) {
  f_fun(state,  dt, out_5795859550853760244);
}
void pose_F_fun(double *state, double dt, double *out_391118642873528758) {
  F_fun(state,  dt, out_391118642873528758);
}
void pose_h_4(double *state, double *unused, double *out_3587574498855600647) {
  h_4(state, unused, out_3587574498855600647);
}
void pose_H_4(double *state, double *unused, double *out_1095803253272619439) {
  H_4(state, unused, out_1095803253272619439);
}
void pose_h_10(double *state, double *unused, double *out_5054997698151726674) {
  h_10(state, unused, out_5054997698151726674);
}
void pose_H_10(double *state, double *unused, double *out_4117080739741493196) {
  H_10(state, unused, out_4117080739741493196);
}
void pose_h_13(double *state, double *unused, double *out_3693365734857647821) {
  h_13(state, unused, out_3693365734857647821);
}
void pose_H_13(double *state, double *unused, double *out_6514827955044081490) {
  H_13(state, unused, out_6514827955044081490);
}
void pose_h_14(double *state, double *unused, double *out_1461011669399451348) {
  h_14(state, unused, out_1461011669399451348);
}
void pose_H_14(double *state, double *unused, double *out_2867437603066865090) {
  H_14(state, unused, out_2867437603066865090);
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
