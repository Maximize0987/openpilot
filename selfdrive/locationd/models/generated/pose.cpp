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
void err_fun(double *nom_x, double *delta_x, double *out_1282506072975981321) {
   out_1282506072975981321[0] = delta_x[0] + nom_x[0];
   out_1282506072975981321[1] = delta_x[1] + nom_x[1];
   out_1282506072975981321[2] = delta_x[2] + nom_x[2];
   out_1282506072975981321[3] = delta_x[3] + nom_x[3];
   out_1282506072975981321[4] = delta_x[4] + nom_x[4];
   out_1282506072975981321[5] = delta_x[5] + nom_x[5];
   out_1282506072975981321[6] = delta_x[6] + nom_x[6];
   out_1282506072975981321[7] = delta_x[7] + nom_x[7];
   out_1282506072975981321[8] = delta_x[8] + nom_x[8];
   out_1282506072975981321[9] = delta_x[9] + nom_x[9];
   out_1282506072975981321[10] = delta_x[10] + nom_x[10];
   out_1282506072975981321[11] = delta_x[11] + nom_x[11];
   out_1282506072975981321[12] = delta_x[12] + nom_x[12];
   out_1282506072975981321[13] = delta_x[13] + nom_x[13];
   out_1282506072975981321[14] = delta_x[14] + nom_x[14];
   out_1282506072975981321[15] = delta_x[15] + nom_x[15];
   out_1282506072975981321[16] = delta_x[16] + nom_x[16];
   out_1282506072975981321[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8512738075508223963) {
   out_8512738075508223963[0] = -nom_x[0] + true_x[0];
   out_8512738075508223963[1] = -nom_x[1] + true_x[1];
   out_8512738075508223963[2] = -nom_x[2] + true_x[2];
   out_8512738075508223963[3] = -nom_x[3] + true_x[3];
   out_8512738075508223963[4] = -nom_x[4] + true_x[4];
   out_8512738075508223963[5] = -nom_x[5] + true_x[5];
   out_8512738075508223963[6] = -nom_x[6] + true_x[6];
   out_8512738075508223963[7] = -nom_x[7] + true_x[7];
   out_8512738075508223963[8] = -nom_x[8] + true_x[8];
   out_8512738075508223963[9] = -nom_x[9] + true_x[9];
   out_8512738075508223963[10] = -nom_x[10] + true_x[10];
   out_8512738075508223963[11] = -nom_x[11] + true_x[11];
   out_8512738075508223963[12] = -nom_x[12] + true_x[12];
   out_8512738075508223963[13] = -nom_x[13] + true_x[13];
   out_8512738075508223963[14] = -nom_x[14] + true_x[14];
   out_8512738075508223963[15] = -nom_x[15] + true_x[15];
   out_8512738075508223963[16] = -nom_x[16] + true_x[16];
   out_8512738075508223963[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3135048301285292021) {
   out_3135048301285292021[0] = 1.0;
   out_3135048301285292021[1] = 0.0;
   out_3135048301285292021[2] = 0.0;
   out_3135048301285292021[3] = 0.0;
   out_3135048301285292021[4] = 0.0;
   out_3135048301285292021[5] = 0.0;
   out_3135048301285292021[6] = 0.0;
   out_3135048301285292021[7] = 0.0;
   out_3135048301285292021[8] = 0.0;
   out_3135048301285292021[9] = 0.0;
   out_3135048301285292021[10] = 0.0;
   out_3135048301285292021[11] = 0.0;
   out_3135048301285292021[12] = 0.0;
   out_3135048301285292021[13] = 0.0;
   out_3135048301285292021[14] = 0.0;
   out_3135048301285292021[15] = 0.0;
   out_3135048301285292021[16] = 0.0;
   out_3135048301285292021[17] = 0.0;
   out_3135048301285292021[18] = 0.0;
   out_3135048301285292021[19] = 1.0;
   out_3135048301285292021[20] = 0.0;
   out_3135048301285292021[21] = 0.0;
   out_3135048301285292021[22] = 0.0;
   out_3135048301285292021[23] = 0.0;
   out_3135048301285292021[24] = 0.0;
   out_3135048301285292021[25] = 0.0;
   out_3135048301285292021[26] = 0.0;
   out_3135048301285292021[27] = 0.0;
   out_3135048301285292021[28] = 0.0;
   out_3135048301285292021[29] = 0.0;
   out_3135048301285292021[30] = 0.0;
   out_3135048301285292021[31] = 0.0;
   out_3135048301285292021[32] = 0.0;
   out_3135048301285292021[33] = 0.0;
   out_3135048301285292021[34] = 0.0;
   out_3135048301285292021[35] = 0.0;
   out_3135048301285292021[36] = 0.0;
   out_3135048301285292021[37] = 0.0;
   out_3135048301285292021[38] = 1.0;
   out_3135048301285292021[39] = 0.0;
   out_3135048301285292021[40] = 0.0;
   out_3135048301285292021[41] = 0.0;
   out_3135048301285292021[42] = 0.0;
   out_3135048301285292021[43] = 0.0;
   out_3135048301285292021[44] = 0.0;
   out_3135048301285292021[45] = 0.0;
   out_3135048301285292021[46] = 0.0;
   out_3135048301285292021[47] = 0.0;
   out_3135048301285292021[48] = 0.0;
   out_3135048301285292021[49] = 0.0;
   out_3135048301285292021[50] = 0.0;
   out_3135048301285292021[51] = 0.0;
   out_3135048301285292021[52] = 0.0;
   out_3135048301285292021[53] = 0.0;
   out_3135048301285292021[54] = 0.0;
   out_3135048301285292021[55] = 0.0;
   out_3135048301285292021[56] = 0.0;
   out_3135048301285292021[57] = 1.0;
   out_3135048301285292021[58] = 0.0;
   out_3135048301285292021[59] = 0.0;
   out_3135048301285292021[60] = 0.0;
   out_3135048301285292021[61] = 0.0;
   out_3135048301285292021[62] = 0.0;
   out_3135048301285292021[63] = 0.0;
   out_3135048301285292021[64] = 0.0;
   out_3135048301285292021[65] = 0.0;
   out_3135048301285292021[66] = 0.0;
   out_3135048301285292021[67] = 0.0;
   out_3135048301285292021[68] = 0.0;
   out_3135048301285292021[69] = 0.0;
   out_3135048301285292021[70] = 0.0;
   out_3135048301285292021[71] = 0.0;
   out_3135048301285292021[72] = 0.0;
   out_3135048301285292021[73] = 0.0;
   out_3135048301285292021[74] = 0.0;
   out_3135048301285292021[75] = 0.0;
   out_3135048301285292021[76] = 1.0;
   out_3135048301285292021[77] = 0.0;
   out_3135048301285292021[78] = 0.0;
   out_3135048301285292021[79] = 0.0;
   out_3135048301285292021[80] = 0.0;
   out_3135048301285292021[81] = 0.0;
   out_3135048301285292021[82] = 0.0;
   out_3135048301285292021[83] = 0.0;
   out_3135048301285292021[84] = 0.0;
   out_3135048301285292021[85] = 0.0;
   out_3135048301285292021[86] = 0.0;
   out_3135048301285292021[87] = 0.0;
   out_3135048301285292021[88] = 0.0;
   out_3135048301285292021[89] = 0.0;
   out_3135048301285292021[90] = 0.0;
   out_3135048301285292021[91] = 0.0;
   out_3135048301285292021[92] = 0.0;
   out_3135048301285292021[93] = 0.0;
   out_3135048301285292021[94] = 0.0;
   out_3135048301285292021[95] = 1.0;
   out_3135048301285292021[96] = 0.0;
   out_3135048301285292021[97] = 0.0;
   out_3135048301285292021[98] = 0.0;
   out_3135048301285292021[99] = 0.0;
   out_3135048301285292021[100] = 0.0;
   out_3135048301285292021[101] = 0.0;
   out_3135048301285292021[102] = 0.0;
   out_3135048301285292021[103] = 0.0;
   out_3135048301285292021[104] = 0.0;
   out_3135048301285292021[105] = 0.0;
   out_3135048301285292021[106] = 0.0;
   out_3135048301285292021[107] = 0.0;
   out_3135048301285292021[108] = 0.0;
   out_3135048301285292021[109] = 0.0;
   out_3135048301285292021[110] = 0.0;
   out_3135048301285292021[111] = 0.0;
   out_3135048301285292021[112] = 0.0;
   out_3135048301285292021[113] = 0.0;
   out_3135048301285292021[114] = 1.0;
   out_3135048301285292021[115] = 0.0;
   out_3135048301285292021[116] = 0.0;
   out_3135048301285292021[117] = 0.0;
   out_3135048301285292021[118] = 0.0;
   out_3135048301285292021[119] = 0.0;
   out_3135048301285292021[120] = 0.0;
   out_3135048301285292021[121] = 0.0;
   out_3135048301285292021[122] = 0.0;
   out_3135048301285292021[123] = 0.0;
   out_3135048301285292021[124] = 0.0;
   out_3135048301285292021[125] = 0.0;
   out_3135048301285292021[126] = 0.0;
   out_3135048301285292021[127] = 0.0;
   out_3135048301285292021[128] = 0.0;
   out_3135048301285292021[129] = 0.0;
   out_3135048301285292021[130] = 0.0;
   out_3135048301285292021[131] = 0.0;
   out_3135048301285292021[132] = 0.0;
   out_3135048301285292021[133] = 1.0;
   out_3135048301285292021[134] = 0.0;
   out_3135048301285292021[135] = 0.0;
   out_3135048301285292021[136] = 0.0;
   out_3135048301285292021[137] = 0.0;
   out_3135048301285292021[138] = 0.0;
   out_3135048301285292021[139] = 0.0;
   out_3135048301285292021[140] = 0.0;
   out_3135048301285292021[141] = 0.0;
   out_3135048301285292021[142] = 0.0;
   out_3135048301285292021[143] = 0.0;
   out_3135048301285292021[144] = 0.0;
   out_3135048301285292021[145] = 0.0;
   out_3135048301285292021[146] = 0.0;
   out_3135048301285292021[147] = 0.0;
   out_3135048301285292021[148] = 0.0;
   out_3135048301285292021[149] = 0.0;
   out_3135048301285292021[150] = 0.0;
   out_3135048301285292021[151] = 0.0;
   out_3135048301285292021[152] = 1.0;
   out_3135048301285292021[153] = 0.0;
   out_3135048301285292021[154] = 0.0;
   out_3135048301285292021[155] = 0.0;
   out_3135048301285292021[156] = 0.0;
   out_3135048301285292021[157] = 0.0;
   out_3135048301285292021[158] = 0.0;
   out_3135048301285292021[159] = 0.0;
   out_3135048301285292021[160] = 0.0;
   out_3135048301285292021[161] = 0.0;
   out_3135048301285292021[162] = 0.0;
   out_3135048301285292021[163] = 0.0;
   out_3135048301285292021[164] = 0.0;
   out_3135048301285292021[165] = 0.0;
   out_3135048301285292021[166] = 0.0;
   out_3135048301285292021[167] = 0.0;
   out_3135048301285292021[168] = 0.0;
   out_3135048301285292021[169] = 0.0;
   out_3135048301285292021[170] = 0.0;
   out_3135048301285292021[171] = 1.0;
   out_3135048301285292021[172] = 0.0;
   out_3135048301285292021[173] = 0.0;
   out_3135048301285292021[174] = 0.0;
   out_3135048301285292021[175] = 0.0;
   out_3135048301285292021[176] = 0.0;
   out_3135048301285292021[177] = 0.0;
   out_3135048301285292021[178] = 0.0;
   out_3135048301285292021[179] = 0.0;
   out_3135048301285292021[180] = 0.0;
   out_3135048301285292021[181] = 0.0;
   out_3135048301285292021[182] = 0.0;
   out_3135048301285292021[183] = 0.0;
   out_3135048301285292021[184] = 0.0;
   out_3135048301285292021[185] = 0.0;
   out_3135048301285292021[186] = 0.0;
   out_3135048301285292021[187] = 0.0;
   out_3135048301285292021[188] = 0.0;
   out_3135048301285292021[189] = 0.0;
   out_3135048301285292021[190] = 1.0;
   out_3135048301285292021[191] = 0.0;
   out_3135048301285292021[192] = 0.0;
   out_3135048301285292021[193] = 0.0;
   out_3135048301285292021[194] = 0.0;
   out_3135048301285292021[195] = 0.0;
   out_3135048301285292021[196] = 0.0;
   out_3135048301285292021[197] = 0.0;
   out_3135048301285292021[198] = 0.0;
   out_3135048301285292021[199] = 0.0;
   out_3135048301285292021[200] = 0.0;
   out_3135048301285292021[201] = 0.0;
   out_3135048301285292021[202] = 0.0;
   out_3135048301285292021[203] = 0.0;
   out_3135048301285292021[204] = 0.0;
   out_3135048301285292021[205] = 0.0;
   out_3135048301285292021[206] = 0.0;
   out_3135048301285292021[207] = 0.0;
   out_3135048301285292021[208] = 0.0;
   out_3135048301285292021[209] = 1.0;
   out_3135048301285292021[210] = 0.0;
   out_3135048301285292021[211] = 0.0;
   out_3135048301285292021[212] = 0.0;
   out_3135048301285292021[213] = 0.0;
   out_3135048301285292021[214] = 0.0;
   out_3135048301285292021[215] = 0.0;
   out_3135048301285292021[216] = 0.0;
   out_3135048301285292021[217] = 0.0;
   out_3135048301285292021[218] = 0.0;
   out_3135048301285292021[219] = 0.0;
   out_3135048301285292021[220] = 0.0;
   out_3135048301285292021[221] = 0.0;
   out_3135048301285292021[222] = 0.0;
   out_3135048301285292021[223] = 0.0;
   out_3135048301285292021[224] = 0.0;
   out_3135048301285292021[225] = 0.0;
   out_3135048301285292021[226] = 0.0;
   out_3135048301285292021[227] = 0.0;
   out_3135048301285292021[228] = 1.0;
   out_3135048301285292021[229] = 0.0;
   out_3135048301285292021[230] = 0.0;
   out_3135048301285292021[231] = 0.0;
   out_3135048301285292021[232] = 0.0;
   out_3135048301285292021[233] = 0.0;
   out_3135048301285292021[234] = 0.0;
   out_3135048301285292021[235] = 0.0;
   out_3135048301285292021[236] = 0.0;
   out_3135048301285292021[237] = 0.0;
   out_3135048301285292021[238] = 0.0;
   out_3135048301285292021[239] = 0.0;
   out_3135048301285292021[240] = 0.0;
   out_3135048301285292021[241] = 0.0;
   out_3135048301285292021[242] = 0.0;
   out_3135048301285292021[243] = 0.0;
   out_3135048301285292021[244] = 0.0;
   out_3135048301285292021[245] = 0.0;
   out_3135048301285292021[246] = 0.0;
   out_3135048301285292021[247] = 1.0;
   out_3135048301285292021[248] = 0.0;
   out_3135048301285292021[249] = 0.0;
   out_3135048301285292021[250] = 0.0;
   out_3135048301285292021[251] = 0.0;
   out_3135048301285292021[252] = 0.0;
   out_3135048301285292021[253] = 0.0;
   out_3135048301285292021[254] = 0.0;
   out_3135048301285292021[255] = 0.0;
   out_3135048301285292021[256] = 0.0;
   out_3135048301285292021[257] = 0.0;
   out_3135048301285292021[258] = 0.0;
   out_3135048301285292021[259] = 0.0;
   out_3135048301285292021[260] = 0.0;
   out_3135048301285292021[261] = 0.0;
   out_3135048301285292021[262] = 0.0;
   out_3135048301285292021[263] = 0.0;
   out_3135048301285292021[264] = 0.0;
   out_3135048301285292021[265] = 0.0;
   out_3135048301285292021[266] = 1.0;
   out_3135048301285292021[267] = 0.0;
   out_3135048301285292021[268] = 0.0;
   out_3135048301285292021[269] = 0.0;
   out_3135048301285292021[270] = 0.0;
   out_3135048301285292021[271] = 0.0;
   out_3135048301285292021[272] = 0.0;
   out_3135048301285292021[273] = 0.0;
   out_3135048301285292021[274] = 0.0;
   out_3135048301285292021[275] = 0.0;
   out_3135048301285292021[276] = 0.0;
   out_3135048301285292021[277] = 0.0;
   out_3135048301285292021[278] = 0.0;
   out_3135048301285292021[279] = 0.0;
   out_3135048301285292021[280] = 0.0;
   out_3135048301285292021[281] = 0.0;
   out_3135048301285292021[282] = 0.0;
   out_3135048301285292021[283] = 0.0;
   out_3135048301285292021[284] = 0.0;
   out_3135048301285292021[285] = 1.0;
   out_3135048301285292021[286] = 0.0;
   out_3135048301285292021[287] = 0.0;
   out_3135048301285292021[288] = 0.0;
   out_3135048301285292021[289] = 0.0;
   out_3135048301285292021[290] = 0.0;
   out_3135048301285292021[291] = 0.0;
   out_3135048301285292021[292] = 0.0;
   out_3135048301285292021[293] = 0.0;
   out_3135048301285292021[294] = 0.0;
   out_3135048301285292021[295] = 0.0;
   out_3135048301285292021[296] = 0.0;
   out_3135048301285292021[297] = 0.0;
   out_3135048301285292021[298] = 0.0;
   out_3135048301285292021[299] = 0.0;
   out_3135048301285292021[300] = 0.0;
   out_3135048301285292021[301] = 0.0;
   out_3135048301285292021[302] = 0.0;
   out_3135048301285292021[303] = 0.0;
   out_3135048301285292021[304] = 1.0;
   out_3135048301285292021[305] = 0.0;
   out_3135048301285292021[306] = 0.0;
   out_3135048301285292021[307] = 0.0;
   out_3135048301285292021[308] = 0.0;
   out_3135048301285292021[309] = 0.0;
   out_3135048301285292021[310] = 0.0;
   out_3135048301285292021[311] = 0.0;
   out_3135048301285292021[312] = 0.0;
   out_3135048301285292021[313] = 0.0;
   out_3135048301285292021[314] = 0.0;
   out_3135048301285292021[315] = 0.0;
   out_3135048301285292021[316] = 0.0;
   out_3135048301285292021[317] = 0.0;
   out_3135048301285292021[318] = 0.0;
   out_3135048301285292021[319] = 0.0;
   out_3135048301285292021[320] = 0.0;
   out_3135048301285292021[321] = 0.0;
   out_3135048301285292021[322] = 0.0;
   out_3135048301285292021[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8178969782644284561) {
   out_8178969782644284561[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8178969782644284561[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8178969782644284561[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8178969782644284561[3] = dt*state[12] + state[3];
   out_8178969782644284561[4] = dt*state[13] + state[4];
   out_8178969782644284561[5] = dt*state[14] + state[5];
   out_8178969782644284561[6] = state[6];
   out_8178969782644284561[7] = state[7];
   out_8178969782644284561[8] = state[8];
   out_8178969782644284561[9] = state[9];
   out_8178969782644284561[10] = state[10];
   out_8178969782644284561[11] = state[11];
   out_8178969782644284561[12] = state[12];
   out_8178969782644284561[13] = state[13];
   out_8178969782644284561[14] = state[14];
   out_8178969782644284561[15] = state[15];
   out_8178969782644284561[16] = state[16];
   out_8178969782644284561[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7659025943100145673) {
   out_7659025943100145673[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7659025943100145673[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7659025943100145673[2] = 0;
   out_7659025943100145673[3] = 0;
   out_7659025943100145673[4] = 0;
   out_7659025943100145673[5] = 0;
   out_7659025943100145673[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7659025943100145673[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7659025943100145673[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7659025943100145673[9] = 0;
   out_7659025943100145673[10] = 0;
   out_7659025943100145673[11] = 0;
   out_7659025943100145673[12] = 0;
   out_7659025943100145673[13] = 0;
   out_7659025943100145673[14] = 0;
   out_7659025943100145673[15] = 0;
   out_7659025943100145673[16] = 0;
   out_7659025943100145673[17] = 0;
   out_7659025943100145673[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7659025943100145673[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7659025943100145673[20] = 0;
   out_7659025943100145673[21] = 0;
   out_7659025943100145673[22] = 0;
   out_7659025943100145673[23] = 0;
   out_7659025943100145673[24] = 0;
   out_7659025943100145673[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7659025943100145673[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7659025943100145673[27] = 0;
   out_7659025943100145673[28] = 0;
   out_7659025943100145673[29] = 0;
   out_7659025943100145673[30] = 0;
   out_7659025943100145673[31] = 0;
   out_7659025943100145673[32] = 0;
   out_7659025943100145673[33] = 0;
   out_7659025943100145673[34] = 0;
   out_7659025943100145673[35] = 0;
   out_7659025943100145673[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7659025943100145673[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7659025943100145673[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7659025943100145673[39] = 0;
   out_7659025943100145673[40] = 0;
   out_7659025943100145673[41] = 0;
   out_7659025943100145673[42] = 0;
   out_7659025943100145673[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7659025943100145673[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7659025943100145673[45] = 0;
   out_7659025943100145673[46] = 0;
   out_7659025943100145673[47] = 0;
   out_7659025943100145673[48] = 0;
   out_7659025943100145673[49] = 0;
   out_7659025943100145673[50] = 0;
   out_7659025943100145673[51] = 0;
   out_7659025943100145673[52] = 0;
   out_7659025943100145673[53] = 0;
   out_7659025943100145673[54] = 0;
   out_7659025943100145673[55] = 0;
   out_7659025943100145673[56] = 0;
   out_7659025943100145673[57] = 1;
   out_7659025943100145673[58] = 0;
   out_7659025943100145673[59] = 0;
   out_7659025943100145673[60] = 0;
   out_7659025943100145673[61] = 0;
   out_7659025943100145673[62] = 0;
   out_7659025943100145673[63] = 0;
   out_7659025943100145673[64] = 0;
   out_7659025943100145673[65] = 0;
   out_7659025943100145673[66] = dt;
   out_7659025943100145673[67] = 0;
   out_7659025943100145673[68] = 0;
   out_7659025943100145673[69] = 0;
   out_7659025943100145673[70] = 0;
   out_7659025943100145673[71] = 0;
   out_7659025943100145673[72] = 0;
   out_7659025943100145673[73] = 0;
   out_7659025943100145673[74] = 0;
   out_7659025943100145673[75] = 0;
   out_7659025943100145673[76] = 1;
   out_7659025943100145673[77] = 0;
   out_7659025943100145673[78] = 0;
   out_7659025943100145673[79] = 0;
   out_7659025943100145673[80] = 0;
   out_7659025943100145673[81] = 0;
   out_7659025943100145673[82] = 0;
   out_7659025943100145673[83] = 0;
   out_7659025943100145673[84] = 0;
   out_7659025943100145673[85] = dt;
   out_7659025943100145673[86] = 0;
   out_7659025943100145673[87] = 0;
   out_7659025943100145673[88] = 0;
   out_7659025943100145673[89] = 0;
   out_7659025943100145673[90] = 0;
   out_7659025943100145673[91] = 0;
   out_7659025943100145673[92] = 0;
   out_7659025943100145673[93] = 0;
   out_7659025943100145673[94] = 0;
   out_7659025943100145673[95] = 1;
   out_7659025943100145673[96] = 0;
   out_7659025943100145673[97] = 0;
   out_7659025943100145673[98] = 0;
   out_7659025943100145673[99] = 0;
   out_7659025943100145673[100] = 0;
   out_7659025943100145673[101] = 0;
   out_7659025943100145673[102] = 0;
   out_7659025943100145673[103] = 0;
   out_7659025943100145673[104] = dt;
   out_7659025943100145673[105] = 0;
   out_7659025943100145673[106] = 0;
   out_7659025943100145673[107] = 0;
   out_7659025943100145673[108] = 0;
   out_7659025943100145673[109] = 0;
   out_7659025943100145673[110] = 0;
   out_7659025943100145673[111] = 0;
   out_7659025943100145673[112] = 0;
   out_7659025943100145673[113] = 0;
   out_7659025943100145673[114] = 1;
   out_7659025943100145673[115] = 0;
   out_7659025943100145673[116] = 0;
   out_7659025943100145673[117] = 0;
   out_7659025943100145673[118] = 0;
   out_7659025943100145673[119] = 0;
   out_7659025943100145673[120] = 0;
   out_7659025943100145673[121] = 0;
   out_7659025943100145673[122] = 0;
   out_7659025943100145673[123] = 0;
   out_7659025943100145673[124] = 0;
   out_7659025943100145673[125] = 0;
   out_7659025943100145673[126] = 0;
   out_7659025943100145673[127] = 0;
   out_7659025943100145673[128] = 0;
   out_7659025943100145673[129] = 0;
   out_7659025943100145673[130] = 0;
   out_7659025943100145673[131] = 0;
   out_7659025943100145673[132] = 0;
   out_7659025943100145673[133] = 1;
   out_7659025943100145673[134] = 0;
   out_7659025943100145673[135] = 0;
   out_7659025943100145673[136] = 0;
   out_7659025943100145673[137] = 0;
   out_7659025943100145673[138] = 0;
   out_7659025943100145673[139] = 0;
   out_7659025943100145673[140] = 0;
   out_7659025943100145673[141] = 0;
   out_7659025943100145673[142] = 0;
   out_7659025943100145673[143] = 0;
   out_7659025943100145673[144] = 0;
   out_7659025943100145673[145] = 0;
   out_7659025943100145673[146] = 0;
   out_7659025943100145673[147] = 0;
   out_7659025943100145673[148] = 0;
   out_7659025943100145673[149] = 0;
   out_7659025943100145673[150] = 0;
   out_7659025943100145673[151] = 0;
   out_7659025943100145673[152] = 1;
   out_7659025943100145673[153] = 0;
   out_7659025943100145673[154] = 0;
   out_7659025943100145673[155] = 0;
   out_7659025943100145673[156] = 0;
   out_7659025943100145673[157] = 0;
   out_7659025943100145673[158] = 0;
   out_7659025943100145673[159] = 0;
   out_7659025943100145673[160] = 0;
   out_7659025943100145673[161] = 0;
   out_7659025943100145673[162] = 0;
   out_7659025943100145673[163] = 0;
   out_7659025943100145673[164] = 0;
   out_7659025943100145673[165] = 0;
   out_7659025943100145673[166] = 0;
   out_7659025943100145673[167] = 0;
   out_7659025943100145673[168] = 0;
   out_7659025943100145673[169] = 0;
   out_7659025943100145673[170] = 0;
   out_7659025943100145673[171] = 1;
   out_7659025943100145673[172] = 0;
   out_7659025943100145673[173] = 0;
   out_7659025943100145673[174] = 0;
   out_7659025943100145673[175] = 0;
   out_7659025943100145673[176] = 0;
   out_7659025943100145673[177] = 0;
   out_7659025943100145673[178] = 0;
   out_7659025943100145673[179] = 0;
   out_7659025943100145673[180] = 0;
   out_7659025943100145673[181] = 0;
   out_7659025943100145673[182] = 0;
   out_7659025943100145673[183] = 0;
   out_7659025943100145673[184] = 0;
   out_7659025943100145673[185] = 0;
   out_7659025943100145673[186] = 0;
   out_7659025943100145673[187] = 0;
   out_7659025943100145673[188] = 0;
   out_7659025943100145673[189] = 0;
   out_7659025943100145673[190] = 1;
   out_7659025943100145673[191] = 0;
   out_7659025943100145673[192] = 0;
   out_7659025943100145673[193] = 0;
   out_7659025943100145673[194] = 0;
   out_7659025943100145673[195] = 0;
   out_7659025943100145673[196] = 0;
   out_7659025943100145673[197] = 0;
   out_7659025943100145673[198] = 0;
   out_7659025943100145673[199] = 0;
   out_7659025943100145673[200] = 0;
   out_7659025943100145673[201] = 0;
   out_7659025943100145673[202] = 0;
   out_7659025943100145673[203] = 0;
   out_7659025943100145673[204] = 0;
   out_7659025943100145673[205] = 0;
   out_7659025943100145673[206] = 0;
   out_7659025943100145673[207] = 0;
   out_7659025943100145673[208] = 0;
   out_7659025943100145673[209] = 1;
   out_7659025943100145673[210] = 0;
   out_7659025943100145673[211] = 0;
   out_7659025943100145673[212] = 0;
   out_7659025943100145673[213] = 0;
   out_7659025943100145673[214] = 0;
   out_7659025943100145673[215] = 0;
   out_7659025943100145673[216] = 0;
   out_7659025943100145673[217] = 0;
   out_7659025943100145673[218] = 0;
   out_7659025943100145673[219] = 0;
   out_7659025943100145673[220] = 0;
   out_7659025943100145673[221] = 0;
   out_7659025943100145673[222] = 0;
   out_7659025943100145673[223] = 0;
   out_7659025943100145673[224] = 0;
   out_7659025943100145673[225] = 0;
   out_7659025943100145673[226] = 0;
   out_7659025943100145673[227] = 0;
   out_7659025943100145673[228] = 1;
   out_7659025943100145673[229] = 0;
   out_7659025943100145673[230] = 0;
   out_7659025943100145673[231] = 0;
   out_7659025943100145673[232] = 0;
   out_7659025943100145673[233] = 0;
   out_7659025943100145673[234] = 0;
   out_7659025943100145673[235] = 0;
   out_7659025943100145673[236] = 0;
   out_7659025943100145673[237] = 0;
   out_7659025943100145673[238] = 0;
   out_7659025943100145673[239] = 0;
   out_7659025943100145673[240] = 0;
   out_7659025943100145673[241] = 0;
   out_7659025943100145673[242] = 0;
   out_7659025943100145673[243] = 0;
   out_7659025943100145673[244] = 0;
   out_7659025943100145673[245] = 0;
   out_7659025943100145673[246] = 0;
   out_7659025943100145673[247] = 1;
   out_7659025943100145673[248] = 0;
   out_7659025943100145673[249] = 0;
   out_7659025943100145673[250] = 0;
   out_7659025943100145673[251] = 0;
   out_7659025943100145673[252] = 0;
   out_7659025943100145673[253] = 0;
   out_7659025943100145673[254] = 0;
   out_7659025943100145673[255] = 0;
   out_7659025943100145673[256] = 0;
   out_7659025943100145673[257] = 0;
   out_7659025943100145673[258] = 0;
   out_7659025943100145673[259] = 0;
   out_7659025943100145673[260] = 0;
   out_7659025943100145673[261] = 0;
   out_7659025943100145673[262] = 0;
   out_7659025943100145673[263] = 0;
   out_7659025943100145673[264] = 0;
   out_7659025943100145673[265] = 0;
   out_7659025943100145673[266] = 1;
   out_7659025943100145673[267] = 0;
   out_7659025943100145673[268] = 0;
   out_7659025943100145673[269] = 0;
   out_7659025943100145673[270] = 0;
   out_7659025943100145673[271] = 0;
   out_7659025943100145673[272] = 0;
   out_7659025943100145673[273] = 0;
   out_7659025943100145673[274] = 0;
   out_7659025943100145673[275] = 0;
   out_7659025943100145673[276] = 0;
   out_7659025943100145673[277] = 0;
   out_7659025943100145673[278] = 0;
   out_7659025943100145673[279] = 0;
   out_7659025943100145673[280] = 0;
   out_7659025943100145673[281] = 0;
   out_7659025943100145673[282] = 0;
   out_7659025943100145673[283] = 0;
   out_7659025943100145673[284] = 0;
   out_7659025943100145673[285] = 1;
   out_7659025943100145673[286] = 0;
   out_7659025943100145673[287] = 0;
   out_7659025943100145673[288] = 0;
   out_7659025943100145673[289] = 0;
   out_7659025943100145673[290] = 0;
   out_7659025943100145673[291] = 0;
   out_7659025943100145673[292] = 0;
   out_7659025943100145673[293] = 0;
   out_7659025943100145673[294] = 0;
   out_7659025943100145673[295] = 0;
   out_7659025943100145673[296] = 0;
   out_7659025943100145673[297] = 0;
   out_7659025943100145673[298] = 0;
   out_7659025943100145673[299] = 0;
   out_7659025943100145673[300] = 0;
   out_7659025943100145673[301] = 0;
   out_7659025943100145673[302] = 0;
   out_7659025943100145673[303] = 0;
   out_7659025943100145673[304] = 1;
   out_7659025943100145673[305] = 0;
   out_7659025943100145673[306] = 0;
   out_7659025943100145673[307] = 0;
   out_7659025943100145673[308] = 0;
   out_7659025943100145673[309] = 0;
   out_7659025943100145673[310] = 0;
   out_7659025943100145673[311] = 0;
   out_7659025943100145673[312] = 0;
   out_7659025943100145673[313] = 0;
   out_7659025943100145673[314] = 0;
   out_7659025943100145673[315] = 0;
   out_7659025943100145673[316] = 0;
   out_7659025943100145673[317] = 0;
   out_7659025943100145673[318] = 0;
   out_7659025943100145673[319] = 0;
   out_7659025943100145673[320] = 0;
   out_7659025943100145673[321] = 0;
   out_7659025943100145673[322] = 0;
   out_7659025943100145673[323] = 1;
}
void h_4(double *state, double *unused, double *out_6376674584644624571) {
   out_6376674584644624571[0] = state[6] + state[9];
   out_6376674584644624571[1] = state[7] + state[10];
   out_6376674584644624571[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1315349575378995160) {
   out_1315349575378995160[0] = 0;
   out_1315349575378995160[1] = 0;
   out_1315349575378995160[2] = 0;
   out_1315349575378995160[3] = 0;
   out_1315349575378995160[4] = 0;
   out_1315349575378995160[5] = 0;
   out_1315349575378995160[6] = 1;
   out_1315349575378995160[7] = 0;
   out_1315349575378995160[8] = 0;
   out_1315349575378995160[9] = 1;
   out_1315349575378995160[10] = 0;
   out_1315349575378995160[11] = 0;
   out_1315349575378995160[12] = 0;
   out_1315349575378995160[13] = 0;
   out_1315349575378995160[14] = 0;
   out_1315349575378995160[15] = 0;
   out_1315349575378995160[16] = 0;
   out_1315349575378995160[17] = 0;
   out_1315349575378995160[18] = 0;
   out_1315349575378995160[19] = 0;
   out_1315349575378995160[20] = 0;
   out_1315349575378995160[21] = 0;
   out_1315349575378995160[22] = 0;
   out_1315349575378995160[23] = 0;
   out_1315349575378995160[24] = 0;
   out_1315349575378995160[25] = 1;
   out_1315349575378995160[26] = 0;
   out_1315349575378995160[27] = 0;
   out_1315349575378995160[28] = 1;
   out_1315349575378995160[29] = 0;
   out_1315349575378995160[30] = 0;
   out_1315349575378995160[31] = 0;
   out_1315349575378995160[32] = 0;
   out_1315349575378995160[33] = 0;
   out_1315349575378995160[34] = 0;
   out_1315349575378995160[35] = 0;
   out_1315349575378995160[36] = 0;
   out_1315349575378995160[37] = 0;
   out_1315349575378995160[38] = 0;
   out_1315349575378995160[39] = 0;
   out_1315349575378995160[40] = 0;
   out_1315349575378995160[41] = 0;
   out_1315349575378995160[42] = 0;
   out_1315349575378995160[43] = 0;
   out_1315349575378995160[44] = 1;
   out_1315349575378995160[45] = 0;
   out_1315349575378995160[46] = 0;
   out_1315349575378995160[47] = 1;
   out_1315349575378995160[48] = 0;
   out_1315349575378995160[49] = 0;
   out_1315349575378995160[50] = 0;
   out_1315349575378995160[51] = 0;
   out_1315349575378995160[52] = 0;
   out_1315349575378995160[53] = 0;
}
void h_10(double *state, double *unused, double *out_7386007572913415364) {
   out_7386007572913415364[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7386007572913415364[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7386007572913415364[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2432083188517445378) {
   out_2432083188517445378[0] = 0;
   out_2432083188517445378[1] = 9.8100000000000005*cos(state[1]);
   out_2432083188517445378[2] = 0;
   out_2432083188517445378[3] = 0;
   out_2432083188517445378[4] = -state[8];
   out_2432083188517445378[5] = state[7];
   out_2432083188517445378[6] = 0;
   out_2432083188517445378[7] = state[5];
   out_2432083188517445378[8] = -state[4];
   out_2432083188517445378[9] = 0;
   out_2432083188517445378[10] = 0;
   out_2432083188517445378[11] = 0;
   out_2432083188517445378[12] = 1;
   out_2432083188517445378[13] = 0;
   out_2432083188517445378[14] = 0;
   out_2432083188517445378[15] = 1;
   out_2432083188517445378[16] = 0;
   out_2432083188517445378[17] = 0;
   out_2432083188517445378[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2432083188517445378[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2432083188517445378[20] = 0;
   out_2432083188517445378[21] = state[8];
   out_2432083188517445378[22] = 0;
   out_2432083188517445378[23] = -state[6];
   out_2432083188517445378[24] = -state[5];
   out_2432083188517445378[25] = 0;
   out_2432083188517445378[26] = state[3];
   out_2432083188517445378[27] = 0;
   out_2432083188517445378[28] = 0;
   out_2432083188517445378[29] = 0;
   out_2432083188517445378[30] = 0;
   out_2432083188517445378[31] = 1;
   out_2432083188517445378[32] = 0;
   out_2432083188517445378[33] = 0;
   out_2432083188517445378[34] = 1;
   out_2432083188517445378[35] = 0;
   out_2432083188517445378[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2432083188517445378[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2432083188517445378[38] = 0;
   out_2432083188517445378[39] = -state[7];
   out_2432083188517445378[40] = state[6];
   out_2432083188517445378[41] = 0;
   out_2432083188517445378[42] = state[4];
   out_2432083188517445378[43] = -state[3];
   out_2432083188517445378[44] = 0;
   out_2432083188517445378[45] = 0;
   out_2432083188517445378[46] = 0;
   out_2432083188517445378[47] = 0;
   out_2432083188517445378[48] = 0;
   out_2432083188517445378[49] = 0;
   out_2432083188517445378[50] = 1;
   out_2432083188517445378[51] = 0;
   out_2432083188517445378[52] = 0;
   out_2432083188517445378[53] = 1;
}
void h_13(double *state, double *unused, double *out_2876319704878199880) {
   out_2876319704878199880[0] = state[3];
   out_2876319704878199880[1] = state[4];
   out_2876319704878199880[2] = state[5];
}
void H_13(double *state, double *unused, double *out_8925980783695696089) {
   out_8925980783695696089[0] = 0;
   out_8925980783695696089[1] = 0;
   out_8925980783695696089[2] = 0;
   out_8925980783695696089[3] = 1;
   out_8925980783695696089[4] = 0;
   out_8925980783695696089[5] = 0;
   out_8925980783695696089[6] = 0;
   out_8925980783695696089[7] = 0;
   out_8925980783695696089[8] = 0;
   out_8925980783695696089[9] = 0;
   out_8925980783695696089[10] = 0;
   out_8925980783695696089[11] = 0;
   out_8925980783695696089[12] = 0;
   out_8925980783695696089[13] = 0;
   out_8925980783695696089[14] = 0;
   out_8925980783695696089[15] = 0;
   out_8925980783695696089[16] = 0;
   out_8925980783695696089[17] = 0;
   out_8925980783695696089[18] = 0;
   out_8925980783695696089[19] = 0;
   out_8925980783695696089[20] = 0;
   out_8925980783695696089[21] = 0;
   out_8925980783695696089[22] = 1;
   out_8925980783695696089[23] = 0;
   out_8925980783695696089[24] = 0;
   out_8925980783695696089[25] = 0;
   out_8925980783695696089[26] = 0;
   out_8925980783695696089[27] = 0;
   out_8925980783695696089[28] = 0;
   out_8925980783695696089[29] = 0;
   out_8925980783695696089[30] = 0;
   out_8925980783695696089[31] = 0;
   out_8925980783695696089[32] = 0;
   out_8925980783695696089[33] = 0;
   out_8925980783695696089[34] = 0;
   out_8925980783695696089[35] = 0;
   out_8925980783695696089[36] = 0;
   out_8925980783695696089[37] = 0;
   out_8925980783695696089[38] = 0;
   out_8925980783695696089[39] = 0;
   out_8925980783695696089[40] = 0;
   out_8925980783695696089[41] = 1;
   out_8925980783695696089[42] = 0;
   out_8925980783695696089[43] = 0;
   out_8925980783695696089[44] = 0;
   out_8925980783695696089[45] = 0;
   out_8925980783695696089[46] = 0;
   out_8925980783695696089[47] = 0;
   out_8925980783695696089[48] = 0;
   out_8925980783695696089[49] = 0;
   out_8925980783695696089[50] = 0;
   out_8925980783695696089[51] = 0;
   out_8925980783695696089[52] = 0;
   out_8925980783695696089[53] = 0;
}
void h_14(double *state, double *unused, double *out_1255542748321681251) {
   out_1255542748321681251[0] = state[6];
   out_1255542748321681251[1] = state[7];
   out_1255542748321681251[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5278590431718479689) {
   out_5278590431718479689[0] = 0;
   out_5278590431718479689[1] = 0;
   out_5278590431718479689[2] = 0;
   out_5278590431718479689[3] = 0;
   out_5278590431718479689[4] = 0;
   out_5278590431718479689[5] = 0;
   out_5278590431718479689[6] = 1;
   out_5278590431718479689[7] = 0;
   out_5278590431718479689[8] = 0;
   out_5278590431718479689[9] = 0;
   out_5278590431718479689[10] = 0;
   out_5278590431718479689[11] = 0;
   out_5278590431718479689[12] = 0;
   out_5278590431718479689[13] = 0;
   out_5278590431718479689[14] = 0;
   out_5278590431718479689[15] = 0;
   out_5278590431718479689[16] = 0;
   out_5278590431718479689[17] = 0;
   out_5278590431718479689[18] = 0;
   out_5278590431718479689[19] = 0;
   out_5278590431718479689[20] = 0;
   out_5278590431718479689[21] = 0;
   out_5278590431718479689[22] = 0;
   out_5278590431718479689[23] = 0;
   out_5278590431718479689[24] = 0;
   out_5278590431718479689[25] = 1;
   out_5278590431718479689[26] = 0;
   out_5278590431718479689[27] = 0;
   out_5278590431718479689[28] = 0;
   out_5278590431718479689[29] = 0;
   out_5278590431718479689[30] = 0;
   out_5278590431718479689[31] = 0;
   out_5278590431718479689[32] = 0;
   out_5278590431718479689[33] = 0;
   out_5278590431718479689[34] = 0;
   out_5278590431718479689[35] = 0;
   out_5278590431718479689[36] = 0;
   out_5278590431718479689[37] = 0;
   out_5278590431718479689[38] = 0;
   out_5278590431718479689[39] = 0;
   out_5278590431718479689[40] = 0;
   out_5278590431718479689[41] = 0;
   out_5278590431718479689[42] = 0;
   out_5278590431718479689[43] = 0;
   out_5278590431718479689[44] = 1;
   out_5278590431718479689[45] = 0;
   out_5278590431718479689[46] = 0;
   out_5278590431718479689[47] = 0;
   out_5278590431718479689[48] = 0;
   out_5278590431718479689[49] = 0;
   out_5278590431718479689[50] = 0;
   out_5278590431718479689[51] = 0;
   out_5278590431718479689[52] = 0;
   out_5278590431718479689[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1282506072975981321) {
  err_fun(nom_x, delta_x, out_1282506072975981321);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8512738075508223963) {
  inv_err_fun(nom_x, true_x, out_8512738075508223963);
}
void pose_H_mod_fun(double *state, double *out_3135048301285292021) {
  H_mod_fun(state, out_3135048301285292021);
}
void pose_f_fun(double *state, double dt, double *out_8178969782644284561) {
  f_fun(state,  dt, out_8178969782644284561);
}
void pose_F_fun(double *state, double dt, double *out_7659025943100145673) {
  F_fun(state,  dt, out_7659025943100145673);
}
void pose_h_4(double *state, double *unused, double *out_6376674584644624571) {
  h_4(state, unused, out_6376674584644624571);
}
void pose_H_4(double *state, double *unused, double *out_1315349575378995160) {
  H_4(state, unused, out_1315349575378995160);
}
void pose_h_10(double *state, double *unused, double *out_7386007572913415364) {
  h_10(state, unused, out_7386007572913415364);
}
void pose_H_10(double *state, double *unused, double *out_2432083188517445378) {
  H_10(state, unused, out_2432083188517445378);
}
void pose_h_13(double *state, double *unused, double *out_2876319704878199880) {
  h_13(state, unused, out_2876319704878199880);
}
void pose_H_13(double *state, double *unused, double *out_8925980783695696089) {
  H_13(state, unused, out_8925980783695696089);
}
void pose_h_14(double *state, double *unused, double *out_1255542748321681251) {
  h_14(state, unused, out_1255542748321681251);
}
void pose_H_14(double *state, double *unused, double *out_5278590431718479689) {
  H_14(state, unused, out_5278590431718479689);
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
