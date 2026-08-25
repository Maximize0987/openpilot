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
void err_fun(double *nom_x, double *delta_x, double *out_7958882747940958001) {
   out_7958882747940958001[0] = delta_x[0] + nom_x[0];
   out_7958882747940958001[1] = delta_x[1] + nom_x[1];
   out_7958882747940958001[2] = delta_x[2] + nom_x[2];
   out_7958882747940958001[3] = delta_x[3] + nom_x[3];
   out_7958882747940958001[4] = delta_x[4] + nom_x[4];
   out_7958882747940958001[5] = delta_x[5] + nom_x[5];
   out_7958882747940958001[6] = delta_x[6] + nom_x[6];
   out_7958882747940958001[7] = delta_x[7] + nom_x[7];
   out_7958882747940958001[8] = delta_x[8] + nom_x[8];
   out_7958882747940958001[9] = delta_x[9] + nom_x[9];
   out_7958882747940958001[10] = delta_x[10] + nom_x[10];
   out_7958882747940958001[11] = delta_x[11] + nom_x[11];
   out_7958882747940958001[12] = delta_x[12] + nom_x[12];
   out_7958882747940958001[13] = delta_x[13] + nom_x[13];
   out_7958882747940958001[14] = delta_x[14] + nom_x[14];
   out_7958882747940958001[15] = delta_x[15] + nom_x[15];
   out_7958882747940958001[16] = delta_x[16] + nom_x[16];
   out_7958882747940958001[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4703319146697471116) {
   out_4703319146697471116[0] = -nom_x[0] + true_x[0];
   out_4703319146697471116[1] = -nom_x[1] + true_x[1];
   out_4703319146697471116[2] = -nom_x[2] + true_x[2];
   out_4703319146697471116[3] = -nom_x[3] + true_x[3];
   out_4703319146697471116[4] = -nom_x[4] + true_x[4];
   out_4703319146697471116[5] = -nom_x[5] + true_x[5];
   out_4703319146697471116[6] = -nom_x[6] + true_x[6];
   out_4703319146697471116[7] = -nom_x[7] + true_x[7];
   out_4703319146697471116[8] = -nom_x[8] + true_x[8];
   out_4703319146697471116[9] = -nom_x[9] + true_x[9];
   out_4703319146697471116[10] = -nom_x[10] + true_x[10];
   out_4703319146697471116[11] = -nom_x[11] + true_x[11];
   out_4703319146697471116[12] = -nom_x[12] + true_x[12];
   out_4703319146697471116[13] = -nom_x[13] + true_x[13];
   out_4703319146697471116[14] = -nom_x[14] + true_x[14];
   out_4703319146697471116[15] = -nom_x[15] + true_x[15];
   out_4703319146697471116[16] = -nom_x[16] + true_x[16];
   out_4703319146697471116[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_656327009382969529) {
   out_656327009382969529[0] = 1.0;
   out_656327009382969529[1] = 0.0;
   out_656327009382969529[2] = 0.0;
   out_656327009382969529[3] = 0.0;
   out_656327009382969529[4] = 0.0;
   out_656327009382969529[5] = 0.0;
   out_656327009382969529[6] = 0.0;
   out_656327009382969529[7] = 0.0;
   out_656327009382969529[8] = 0.0;
   out_656327009382969529[9] = 0.0;
   out_656327009382969529[10] = 0.0;
   out_656327009382969529[11] = 0.0;
   out_656327009382969529[12] = 0.0;
   out_656327009382969529[13] = 0.0;
   out_656327009382969529[14] = 0.0;
   out_656327009382969529[15] = 0.0;
   out_656327009382969529[16] = 0.0;
   out_656327009382969529[17] = 0.0;
   out_656327009382969529[18] = 0.0;
   out_656327009382969529[19] = 1.0;
   out_656327009382969529[20] = 0.0;
   out_656327009382969529[21] = 0.0;
   out_656327009382969529[22] = 0.0;
   out_656327009382969529[23] = 0.0;
   out_656327009382969529[24] = 0.0;
   out_656327009382969529[25] = 0.0;
   out_656327009382969529[26] = 0.0;
   out_656327009382969529[27] = 0.0;
   out_656327009382969529[28] = 0.0;
   out_656327009382969529[29] = 0.0;
   out_656327009382969529[30] = 0.0;
   out_656327009382969529[31] = 0.0;
   out_656327009382969529[32] = 0.0;
   out_656327009382969529[33] = 0.0;
   out_656327009382969529[34] = 0.0;
   out_656327009382969529[35] = 0.0;
   out_656327009382969529[36] = 0.0;
   out_656327009382969529[37] = 0.0;
   out_656327009382969529[38] = 1.0;
   out_656327009382969529[39] = 0.0;
   out_656327009382969529[40] = 0.0;
   out_656327009382969529[41] = 0.0;
   out_656327009382969529[42] = 0.0;
   out_656327009382969529[43] = 0.0;
   out_656327009382969529[44] = 0.0;
   out_656327009382969529[45] = 0.0;
   out_656327009382969529[46] = 0.0;
   out_656327009382969529[47] = 0.0;
   out_656327009382969529[48] = 0.0;
   out_656327009382969529[49] = 0.0;
   out_656327009382969529[50] = 0.0;
   out_656327009382969529[51] = 0.0;
   out_656327009382969529[52] = 0.0;
   out_656327009382969529[53] = 0.0;
   out_656327009382969529[54] = 0.0;
   out_656327009382969529[55] = 0.0;
   out_656327009382969529[56] = 0.0;
   out_656327009382969529[57] = 1.0;
   out_656327009382969529[58] = 0.0;
   out_656327009382969529[59] = 0.0;
   out_656327009382969529[60] = 0.0;
   out_656327009382969529[61] = 0.0;
   out_656327009382969529[62] = 0.0;
   out_656327009382969529[63] = 0.0;
   out_656327009382969529[64] = 0.0;
   out_656327009382969529[65] = 0.0;
   out_656327009382969529[66] = 0.0;
   out_656327009382969529[67] = 0.0;
   out_656327009382969529[68] = 0.0;
   out_656327009382969529[69] = 0.0;
   out_656327009382969529[70] = 0.0;
   out_656327009382969529[71] = 0.0;
   out_656327009382969529[72] = 0.0;
   out_656327009382969529[73] = 0.0;
   out_656327009382969529[74] = 0.0;
   out_656327009382969529[75] = 0.0;
   out_656327009382969529[76] = 1.0;
   out_656327009382969529[77] = 0.0;
   out_656327009382969529[78] = 0.0;
   out_656327009382969529[79] = 0.0;
   out_656327009382969529[80] = 0.0;
   out_656327009382969529[81] = 0.0;
   out_656327009382969529[82] = 0.0;
   out_656327009382969529[83] = 0.0;
   out_656327009382969529[84] = 0.0;
   out_656327009382969529[85] = 0.0;
   out_656327009382969529[86] = 0.0;
   out_656327009382969529[87] = 0.0;
   out_656327009382969529[88] = 0.0;
   out_656327009382969529[89] = 0.0;
   out_656327009382969529[90] = 0.0;
   out_656327009382969529[91] = 0.0;
   out_656327009382969529[92] = 0.0;
   out_656327009382969529[93] = 0.0;
   out_656327009382969529[94] = 0.0;
   out_656327009382969529[95] = 1.0;
   out_656327009382969529[96] = 0.0;
   out_656327009382969529[97] = 0.0;
   out_656327009382969529[98] = 0.0;
   out_656327009382969529[99] = 0.0;
   out_656327009382969529[100] = 0.0;
   out_656327009382969529[101] = 0.0;
   out_656327009382969529[102] = 0.0;
   out_656327009382969529[103] = 0.0;
   out_656327009382969529[104] = 0.0;
   out_656327009382969529[105] = 0.0;
   out_656327009382969529[106] = 0.0;
   out_656327009382969529[107] = 0.0;
   out_656327009382969529[108] = 0.0;
   out_656327009382969529[109] = 0.0;
   out_656327009382969529[110] = 0.0;
   out_656327009382969529[111] = 0.0;
   out_656327009382969529[112] = 0.0;
   out_656327009382969529[113] = 0.0;
   out_656327009382969529[114] = 1.0;
   out_656327009382969529[115] = 0.0;
   out_656327009382969529[116] = 0.0;
   out_656327009382969529[117] = 0.0;
   out_656327009382969529[118] = 0.0;
   out_656327009382969529[119] = 0.0;
   out_656327009382969529[120] = 0.0;
   out_656327009382969529[121] = 0.0;
   out_656327009382969529[122] = 0.0;
   out_656327009382969529[123] = 0.0;
   out_656327009382969529[124] = 0.0;
   out_656327009382969529[125] = 0.0;
   out_656327009382969529[126] = 0.0;
   out_656327009382969529[127] = 0.0;
   out_656327009382969529[128] = 0.0;
   out_656327009382969529[129] = 0.0;
   out_656327009382969529[130] = 0.0;
   out_656327009382969529[131] = 0.0;
   out_656327009382969529[132] = 0.0;
   out_656327009382969529[133] = 1.0;
   out_656327009382969529[134] = 0.0;
   out_656327009382969529[135] = 0.0;
   out_656327009382969529[136] = 0.0;
   out_656327009382969529[137] = 0.0;
   out_656327009382969529[138] = 0.0;
   out_656327009382969529[139] = 0.0;
   out_656327009382969529[140] = 0.0;
   out_656327009382969529[141] = 0.0;
   out_656327009382969529[142] = 0.0;
   out_656327009382969529[143] = 0.0;
   out_656327009382969529[144] = 0.0;
   out_656327009382969529[145] = 0.0;
   out_656327009382969529[146] = 0.0;
   out_656327009382969529[147] = 0.0;
   out_656327009382969529[148] = 0.0;
   out_656327009382969529[149] = 0.0;
   out_656327009382969529[150] = 0.0;
   out_656327009382969529[151] = 0.0;
   out_656327009382969529[152] = 1.0;
   out_656327009382969529[153] = 0.0;
   out_656327009382969529[154] = 0.0;
   out_656327009382969529[155] = 0.0;
   out_656327009382969529[156] = 0.0;
   out_656327009382969529[157] = 0.0;
   out_656327009382969529[158] = 0.0;
   out_656327009382969529[159] = 0.0;
   out_656327009382969529[160] = 0.0;
   out_656327009382969529[161] = 0.0;
   out_656327009382969529[162] = 0.0;
   out_656327009382969529[163] = 0.0;
   out_656327009382969529[164] = 0.0;
   out_656327009382969529[165] = 0.0;
   out_656327009382969529[166] = 0.0;
   out_656327009382969529[167] = 0.0;
   out_656327009382969529[168] = 0.0;
   out_656327009382969529[169] = 0.0;
   out_656327009382969529[170] = 0.0;
   out_656327009382969529[171] = 1.0;
   out_656327009382969529[172] = 0.0;
   out_656327009382969529[173] = 0.0;
   out_656327009382969529[174] = 0.0;
   out_656327009382969529[175] = 0.0;
   out_656327009382969529[176] = 0.0;
   out_656327009382969529[177] = 0.0;
   out_656327009382969529[178] = 0.0;
   out_656327009382969529[179] = 0.0;
   out_656327009382969529[180] = 0.0;
   out_656327009382969529[181] = 0.0;
   out_656327009382969529[182] = 0.0;
   out_656327009382969529[183] = 0.0;
   out_656327009382969529[184] = 0.0;
   out_656327009382969529[185] = 0.0;
   out_656327009382969529[186] = 0.0;
   out_656327009382969529[187] = 0.0;
   out_656327009382969529[188] = 0.0;
   out_656327009382969529[189] = 0.0;
   out_656327009382969529[190] = 1.0;
   out_656327009382969529[191] = 0.0;
   out_656327009382969529[192] = 0.0;
   out_656327009382969529[193] = 0.0;
   out_656327009382969529[194] = 0.0;
   out_656327009382969529[195] = 0.0;
   out_656327009382969529[196] = 0.0;
   out_656327009382969529[197] = 0.0;
   out_656327009382969529[198] = 0.0;
   out_656327009382969529[199] = 0.0;
   out_656327009382969529[200] = 0.0;
   out_656327009382969529[201] = 0.0;
   out_656327009382969529[202] = 0.0;
   out_656327009382969529[203] = 0.0;
   out_656327009382969529[204] = 0.0;
   out_656327009382969529[205] = 0.0;
   out_656327009382969529[206] = 0.0;
   out_656327009382969529[207] = 0.0;
   out_656327009382969529[208] = 0.0;
   out_656327009382969529[209] = 1.0;
   out_656327009382969529[210] = 0.0;
   out_656327009382969529[211] = 0.0;
   out_656327009382969529[212] = 0.0;
   out_656327009382969529[213] = 0.0;
   out_656327009382969529[214] = 0.0;
   out_656327009382969529[215] = 0.0;
   out_656327009382969529[216] = 0.0;
   out_656327009382969529[217] = 0.0;
   out_656327009382969529[218] = 0.0;
   out_656327009382969529[219] = 0.0;
   out_656327009382969529[220] = 0.0;
   out_656327009382969529[221] = 0.0;
   out_656327009382969529[222] = 0.0;
   out_656327009382969529[223] = 0.0;
   out_656327009382969529[224] = 0.0;
   out_656327009382969529[225] = 0.0;
   out_656327009382969529[226] = 0.0;
   out_656327009382969529[227] = 0.0;
   out_656327009382969529[228] = 1.0;
   out_656327009382969529[229] = 0.0;
   out_656327009382969529[230] = 0.0;
   out_656327009382969529[231] = 0.0;
   out_656327009382969529[232] = 0.0;
   out_656327009382969529[233] = 0.0;
   out_656327009382969529[234] = 0.0;
   out_656327009382969529[235] = 0.0;
   out_656327009382969529[236] = 0.0;
   out_656327009382969529[237] = 0.0;
   out_656327009382969529[238] = 0.0;
   out_656327009382969529[239] = 0.0;
   out_656327009382969529[240] = 0.0;
   out_656327009382969529[241] = 0.0;
   out_656327009382969529[242] = 0.0;
   out_656327009382969529[243] = 0.0;
   out_656327009382969529[244] = 0.0;
   out_656327009382969529[245] = 0.0;
   out_656327009382969529[246] = 0.0;
   out_656327009382969529[247] = 1.0;
   out_656327009382969529[248] = 0.0;
   out_656327009382969529[249] = 0.0;
   out_656327009382969529[250] = 0.0;
   out_656327009382969529[251] = 0.0;
   out_656327009382969529[252] = 0.0;
   out_656327009382969529[253] = 0.0;
   out_656327009382969529[254] = 0.0;
   out_656327009382969529[255] = 0.0;
   out_656327009382969529[256] = 0.0;
   out_656327009382969529[257] = 0.0;
   out_656327009382969529[258] = 0.0;
   out_656327009382969529[259] = 0.0;
   out_656327009382969529[260] = 0.0;
   out_656327009382969529[261] = 0.0;
   out_656327009382969529[262] = 0.0;
   out_656327009382969529[263] = 0.0;
   out_656327009382969529[264] = 0.0;
   out_656327009382969529[265] = 0.0;
   out_656327009382969529[266] = 1.0;
   out_656327009382969529[267] = 0.0;
   out_656327009382969529[268] = 0.0;
   out_656327009382969529[269] = 0.0;
   out_656327009382969529[270] = 0.0;
   out_656327009382969529[271] = 0.0;
   out_656327009382969529[272] = 0.0;
   out_656327009382969529[273] = 0.0;
   out_656327009382969529[274] = 0.0;
   out_656327009382969529[275] = 0.0;
   out_656327009382969529[276] = 0.0;
   out_656327009382969529[277] = 0.0;
   out_656327009382969529[278] = 0.0;
   out_656327009382969529[279] = 0.0;
   out_656327009382969529[280] = 0.0;
   out_656327009382969529[281] = 0.0;
   out_656327009382969529[282] = 0.0;
   out_656327009382969529[283] = 0.0;
   out_656327009382969529[284] = 0.0;
   out_656327009382969529[285] = 1.0;
   out_656327009382969529[286] = 0.0;
   out_656327009382969529[287] = 0.0;
   out_656327009382969529[288] = 0.0;
   out_656327009382969529[289] = 0.0;
   out_656327009382969529[290] = 0.0;
   out_656327009382969529[291] = 0.0;
   out_656327009382969529[292] = 0.0;
   out_656327009382969529[293] = 0.0;
   out_656327009382969529[294] = 0.0;
   out_656327009382969529[295] = 0.0;
   out_656327009382969529[296] = 0.0;
   out_656327009382969529[297] = 0.0;
   out_656327009382969529[298] = 0.0;
   out_656327009382969529[299] = 0.0;
   out_656327009382969529[300] = 0.0;
   out_656327009382969529[301] = 0.0;
   out_656327009382969529[302] = 0.0;
   out_656327009382969529[303] = 0.0;
   out_656327009382969529[304] = 1.0;
   out_656327009382969529[305] = 0.0;
   out_656327009382969529[306] = 0.0;
   out_656327009382969529[307] = 0.0;
   out_656327009382969529[308] = 0.0;
   out_656327009382969529[309] = 0.0;
   out_656327009382969529[310] = 0.0;
   out_656327009382969529[311] = 0.0;
   out_656327009382969529[312] = 0.0;
   out_656327009382969529[313] = 0.0;
   out_656327009382969529[314] = 0.0;
   out_656327009382969529[315] = 0.0;
   out_656327009382969529[316] = 0.0;
   out_656327009382969529[317] = 0.0;
   out_656327009382969529[318] = 0.0;
   out_656327009382969529[319] = 0.0;
   out_656327009382969529[320] = 0.0;
   out_656327009382969529[321] = 0.0;
   out_656327009382969529[322] = 0.0;
   out_656327009382969529[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1970546984054209494) {
   out_1970546984054209494[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1970546984054209494[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1970546984054209494[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1970546984054209494[3] = dt*state[12] + state[3];
   out_1970546984054209494[4] = dt*state[13] + state[4];
   out_1970546984054209494[5] = dt*state[14] + state[5];
   out_1970546984054209494[6] = state[6];
   out_1970546984054209494[7] = state[7];
   out_1970546984054209494[8] = state[8];
   out_1970546984054209494[9] = state[9];
   out_1970546984054209494[10] = state[10];
   out_1970546984054209494[11] = state[11];
   out_1970546984054209494[12] = state[12];
   out_1970546984054209494[13] = state[13];
   out_1970546984054209494[14] = state[14];
   out_1970546984054209494[15] = state[15];
   out_1970546984054209494[16] = state[16];
   out_1970546984054209494[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2484970000761638635) {
   out_2484970000761638635[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2484970000761638635[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2484970000761638635[2] = 0;
   out_2484970000761638635[3] = 0;
   out_2484970000761638635[4] = 0;
   out_2484970000761638635[5] = 0;
   out_2484970000761638635[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2484970000761638635[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2484970000761638635[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2484970000761638635[9] = 0;
   out_2484970000761638635[10] = 0;
   out_2484970000761638635[11] = 0;
   out_2484970000761638635[12] = 0;
   out_2484970000761638635[13] = 0;
   out_2484970000761638635[14] = 0;
   out_2484970000761638635[15] = 0;
   out_2484970000761638635[16] = 0;
   out_2484970000761638635[17] = 0;
   out_2484970000761638635[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2484970000761638635[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2484970000761638635[20] = 0;
   out_2484970000761638635[21] = 0;
   out_2484970000761638635[22] = 0;
   out_2484970000761638635[23] = 0;
   out_2484970000761638635[24] = 0;
   out_2484970000761638635[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2484970000761638635[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2484970000761638635[27] = 0;
   out_2484970000761638635[28] = 0;
   out_2484970000761638635[29] = 0;
   out_2484970000761638635[30] = 0;
   out_2484970000761638635[31] = 0;
   out_2484970000761638635[32] = 0;
   out_2484970000761638635[33] = 0;
   out_2484970000761638635[34] = 0;
   out_2484970000761638635[35] = 0;
   out_2484970000761638635[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2484970000761638635[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2484970000761638635[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2484970000761638635[39] = 0;
   out_2484970000761638635[40] = 0;
   out_2484970000761638635[41] = 0;
   out_2484970000761638635[42] = 0;
   out_2484970000761638635[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2484970000761638635[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2484970000761638635[45] = 0;
   out_2484970000761638635[46] = 0;
   out_2484970000761638635[47] = 0;
   out_2484970000761638635[48] = 0;
   out_2484970000761638635[49] = 0;
   out_2484970000761638635[50] = 0;
   out_2484970000761638635[51] = 0;
   out_2484970000761638635[52] = 0;
   out_2484970000761638635[53] = 0;
   out_2484970000761638635[54] = 0;
   out_2484970000761638635[55] = 0;
   out_2484970000761638635[56] = 0;
   out_2484970000761638635[57] = 1;
   out_2484970000761638635[58] = 0;
   out_2484970000761638635[59] = 0;
   out_2484970000761638635[60] = 0;
   out_2484970000761638635[61] = 0;
   out_2484970000761638635[62] = 0;
   out_2484970000761638635[63] = 0;
   out_2484970000761638635[64] = 0;
   out_2484970000761638635[65] = 0;
   out_2484970000761638635[66] = dt;
   out_2484970000761638635[67] = 0;
   out_2484970000761638635[68] = 0;
   out_2484970000761638635[69] = 0;
   out_2484970000761638635[70] = 0;
   out_2484970000761638635[71] = 0;
   out_2484970000761638635[72] = 0;
   out_2484970000761638635[73] = 0;
   out_2484970000761638635[74] = 0;
   out_2484970000761638635[75] = 0;
   out_2484970000761638635[76] = 1;
   out_2484970000761638635[77] = 0;
   out_2484970000761638635[78] = 0;
   out_2484970000761638635[79] = 0;
   out_2484970000761638635[80] = 0;
   out_2484970000761638635[81] = 0;
   out_2484970000761638635[82] = 0;
   out_2484970000761638635[83] = 0;
   out_2484970000761638635[84] = 0;
   out_2484970000761638635[85] = dt;
   out_2484970000761638635[86] = 0;
   out_2484970000761638635[87] = 0;
   out_2484970000761638635[88] = 0;
   out_2484970000761638635[89] = 0;
   out_2484970000761638635[90] = 0;
   out_2484970000761638635[91] = 0;
   out_2484970000761638635[92] = 0;
   out_2484970000761638635[93] = 0;
   out_2484970000761638635[94] = 0;
   out_2484970000761638635[95] = 1;
   out_2484970000761638635[96] = 0;
   out_2484970000761638635[97] = 0;
   out_2484970000761638635[98] = 0;
   out_2484970000761638635[99] = 0;
   out_2484970000761638635[100] = 0;
   out_2484970000761638635[101] = 0;
   out_2484970000761638635[102] = 0;
   out_2484970000761638635[103] = 0;
   out_2484970000761638635[104] = dt;
   out_2484970000761638635[105] = 0;
   out_2484970000761638635[106] = 0;
   out_2484970000761638635[107] = 0;
   out_2484970000761638635[108] = 0;
   out_2484970000761638635[109] = 0;
   out_2484970000761638635[110] = 0;
   out_2484970000761638635[111] = 0;
   out_2484970000761638635[112] = 0;
   out_2484970000761638635[113] = 0;
   out_2484970000761638635[114] = 1;
   out_2484970000761638635[115] = 0;
   out_2484970000761638635[116] = 0;
   out_2484970000761638635[117] = 0;
   out_2484970000761638635[118] = 0;
   out_2484970000761638635[119] = 0;
   out_2484970000761638635[120] = 0;
   out_2484970000761638635[121] = 0;
   out_2484970000761638635[122] = 0;
   out_2484970000761638635[123] = 0;
   out_2484970000761638635[124] = 0;
   out_2484970000761638635[125] = 0;
   out_2484970000761638635[126] = 0;
   out_2484970000761638635[127] = 0;
   out_2484970000761638635[128] = 0;
   out_2484970000761638635[129] = 0;
   out_2484970000761638635[130] = 0;
   out_2484970000761638635[131] = 0;
   out_2484970000761638635[132] = 0;
   out_2484970000761638635[133] = 1;
   out_2484970000761638635[134] = 0;
   out_2484970000761638635[135] = 0;
   out_2484970000761638635[136] = 0;
   out_2484970000761638635[137] = 0;
   out_2484970000761638635[138] = 0;
   out_2484970000761638635[139] = 0;
   out_2484970000761638635[140] = 0;
   out_2484970000761638635[141] = 0;
   out_2484970000761638635[142] = 0;
   out_2484970000761638635[143] = 0;
   out_2484970000761638635[144] = 0;
   out_2484970000761638635[145] = 0;
   out_2484970000761638635[146] = 0;
   out_2484970000761638635[147] = 0;
   out_2484970000761638635[148] = 0;
   out_2484970000761638635[149] = 0;
   out_2484970000761638635[150] = 0;
   out_2484970000761638635[151] = 0;
   out_2484970000761638635[152] = 1;
   out_2484970000761638635[153] = 0;
   out_2484970000761638635[154] = 0;
   out_2484970000761638635[155] = 0;
   out_2484970000761638635[156] = 0;
   out_2484970000761638635[157] = 0;
   out_2484970000761638635[158] = 0;
   out_2484970000761638635[159] = 0;
   out_2484970000761638635[160] = 0;
   out_2484970000761638635[161] = 0;
   out_2484970000761638635[162] = 0;
   out_2484970000761638635[163] = 0;
   out_2484970000761638635[164] = 0;
   out_2484970000761638635[165] = 0;
   out_2484970000761638635[166] = 0;
   out_2484970000761638635[167] = 0;
   out_2484970000761638635[168] = 0;
   out_2484970000761638635[169] = 0;
   out_2484970000761638635[170] = 0;
   out_2484970000761638635[171] = 1;
   out_2484970000761638635[172] = 0;
   out_2484970000761638635[173] = 0;
   out_2484970000761638635[174] = 0;
   out_2484970000761638635[175] = 0;
   out_2484970000761638635[176] = 0;
   out_2484970000761638635[177] = 0;
   out_2484970000761638635[178] = 0;
   out_2484970000761638635[179] = 0;
   out_2484970000761638635[180] = 0;
   out_2484970000761638635[181] = 0;
   out_2484970000761638635[182] = 0;
   out_2484970000761638635[183] = 0;
   out_2484970000761638635[184] = 0;
   out_2484970000761638635[185] = 0;
   out_2484970000761638635[186] = 0;
   out_2484970000761638635[187] = 0;
   out_2484970000761638635[188] = 0;
   out_2484970000761638635[189] = 0;
   out_2484970000761638635[190] = 1;
   out_2484970000761638635[191] = 0;
   out_2484970000761638635[192] = 0;
   out_2484970000761638635[193] = 0;
   out_2484970000761638635[194] = 0;
   out_2484970000761638635[195] = 0;
   out_2484970000761638635[196] = 0;
   out_2484970000761638635[197] = 0;
   out_2484970000761638635[198] = 0;
   out_2484970000761638635[199] = 0;
   out_2484970000761638635[200] = 0;
   out_2484970000761638635[201] = 0;
   out_2484970000761638635[202] = 0;
   out_2484970000761638635[203] = 0;
   out_2484970000761638635[204] = 0;
   out_2484970000761638635[205] = 0;
   out_2484970000761638635[206] = 0;
   out_2484970000761638635[207] = 0;
   out_2484970000761638635[208] = 0;
   out_2484970000761638635[209] = 1;
   out_2484970000761638635[210] = 0;
   out_2484970000761638635[211] = 0;
   out_2484970000761638635[212] = 0;
   out_2484970000761638635[213] = 0;
   out_2484970000761638635[214] = 0;
   out_2484970000761638635[215] = 0;
   out_2484970000761638635[216] = 0;
   out_2484970000761638635[217] = 0;
   out_2484970000761638635[218] = 0;
   out_2484970000761638635[219] = 0;
   out_2484970000761638635[220] = 0;
   out_2484970000761638635[221] = 0;
   out_2484970000761638635[222] = 0;
   out_2484970000761638635[223] = 0;
   out_2484970000761638635[224] = 0;
   out_2484970000761638635[225] = 0;
   out_2484970000761638635[226] = 0;
   out_2484970000761638635[227] = 0;
   out_2484970000761638635[228] = 1;
   out_2484970000761638635[229] = 0;
   out_2484970000761638635[230] = 0;
   out_2484970000761638635[231] = 0;
   out_2484970000761638635[232] = 0;
   out_2484970000761638635[233] = 0;
   out_2484970000761638635[234] = 0;
   out_2484970000761638635[235] = 0;
   out_2484970000761638635[236] = 0;
   out_2484970000761638635[237] = 0;
   out_2484970000761638635[238] = 0;
   out_2484970000761638635[239] = 0;
   out_2484970000761638635[240] = 0;
   out_2484970000761638635[241] = 0;
   out_2484970000761638635[242] = 0;
   out_2484970000761638635[243] = 0;
   out_2484970000761638635[244] = 0;
   out_2484970000761638635[245] = 0;
   out_2484970000761638635[246] = 0;
   out_2484970000761638635[247] = 1;
   out_2484970000761638635[248] = 0;
   out_2484970000761638635[249] = 0;
   out_2484970000761638635[250] = 0;
   out_2484970000761638635[251] = 0;
   out_2484970000761638635[252] = 0;
   out_2484970000761638635[253] = 0;
   out_2484970000761638635[254] = 0;
   out_2484970000761638635[255] = 0;
   out_2484970000761638635[256] = 0;
   out_2484970000761638635[257] = 0;
   out_2484970000761638635[258] = 0;
   out_2484970000761638635[259] = 0;
   out_2484970000761638635[260] = 0;
   out_2484970000761638635[261] = 0;
   out_2484970000761638635[262] = 0;
   out_2484970000761638635[263] = 0;
   out_2484970000761638635[264] = 0;
   out_2484970000761638635[265] = 0;
   out_2484970000761638635[266] = 1;
   out_2484970000761638635[267] = 0;
   out_2484970000761638635[268] = 0;
   out_2484970000761638635[269] = 0;
   out_2484970000761638635[270] = 0;
   out_2484970000761638635[271] = 0;
   out_2484970000761638635[272] = 0;
   out_2484970000761638635[273] = 0;
   out_2484970000761638635[274] = 0;
   out_2484970000761638635[275] = 0;
   out_2484970000761638635[276] = 0;
   out_2484970000761638635[277] = 0;
   out_2484970000761638635[278] = 0;
   out_2484970000761638635[279] = 0;
   out_2484970000761638635[280] = 0;
   out_2484970000761638635[281] = 0;
   out_2484970000761638635[282] = 0;
   out_2484970000761638635[283] = 0;
   out_2484970000761638635[284] = 0;
   out_2484970000761638635[285] = 1;
   out_2484970000761638635[286] = 0;
   out_2484970000761638635[287] = 0;
   out_2484970000761638635[288] = 0;
   out_2484970000761638635[289] = 0;
   out_2484970000761638635[290] = 0;
   out_2484970000761638635[291] = 0;
   out_2484970000761638635[292] = 0;
   out_2484970000761638635[293] = 0;
   out_2484970000761638635[294] = 0;
   out_2484970000761638635[295] = 0;
   out_2484970000761638635[296] = 0;
   out_2484970000761638635[297] = 0;
   out_2484970000761638635[298] = 0;
   out_2484970000761638635[299] = 0;
   out_2484970000761638635[300] = 0;
   out_2484970000761638635[301] = 0;
   out_2484970000761638635[302] = 0;
   out_2484970000761638635[303] = 0;
   out_2484970000761638635[304] = 1;
   out_2484970000761638635[305] = 0;
   out_2484970000761638635[306] = 0;
   out_2484970000761638635[307] = 0;
   out_2484970000761638635[308] = 0;
   out_2484970000761638635[309] = 0;
   out_2484970000761638635[310] = 0;
   out_2484970000761638635[311] = 0;
   out_2484970000761638635[312] = 0;
   out_2484970000761638635[313] = 0;
   out_2484970000761638635[314] = 0;
   out_2484970000761638635[315] = 0;
   out_2484970000761638635[316] = 0;
   out_2484970000761638635[317] = 0;
   out_2484970000761638635[318] = 0;
   out_2484970000761638635[319] = 0;
   out_2484970000761638635[320] = 0;
   out_2484970000761638635[321] = 0;
   out_2484970000761638635[322] = 0;
   out_2484970000761638635[323] = 1;
}
void h_4(double *state, double *unused, double *out_5725974613387962710) {
   out_5725974613387962710[0] = state[6] + state[9];
   out_5725974613387962710[1] = state[7] + state[10];
   out_5725974613387962710[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3808243550112720964) {
   out_3808243550112720964[0] = 0;
   out_3808243550112720964[1] = 0;
   out_3808243550112720964[2] = 0;
   out_3808243550112720964[3] = 0;
   out_3808243550112720964[4] = 0;
   out_3808243550112720964[5] = 0;
   out_3808243550112720964[6] = 1;
   out_3808243550112720964[7] = 0;
   out_3808243550112720964[8] = 0;
   out_3808243550112720964[9] = 1;
   out_3808243550112720964[10] = 0;
   out_3808243550112720964[11] = 0;
   out_3808243550112720964[12] = 0;
   out_3808243550112720964[13] = 0;
   out_3808243550112720964[14] = 0;
   out_3808243550112720964[15] = 0;
   out_3808243550112720964[16] = 0;
   out_3808243550112720964[17] = 0;
   out_3808243550112720964[18] = 0;
   out_3808243550112720964[19] = 0;
   out_3808243550112720964[20] = 0;
   out_3808243550112720964[21] = 0;
   out_3808243550112720964[22] = 0;
   out_3808243550112720964[23] = 0;
   out_3808243550112720964[24] = 0;
   out_3808243550112720964[25] = 1;
   out_3808243550112720964[26] = 0;
   out_3808243550112720964[27] = 0;
   out_3808243550112720964[28] = 1;
   out_3808243550112720964[29] = 0;
   out_3808243550112720964[30] = 0;
   out_3808243550112720964[31] = 0;
   out_3808243550112720964[32] = 0;
   out_3808243550112720964[33] = 0;
   out_3808243550112720964[34] = 0;
   out_3808243550112720964[35] = 0;
   out_3808243550112720964[36] = 0;
   out_3808243550112720964[37] = 0;
   out_3808243550112720964[38] = 0;
   out_3808243550112720964[39] = 0;
   out_3808243550112720964[40] = 0;
   out_3808243550112720964[41] = 0;
   out_3808243550112720964[42] = 0;
   out_3808243550112720964[43] = 0;
   out_3808243550112720964[44] = 1;
   out_3808243550112720964[45] = 0;
   out_3808243550112720964[46] = 0;
   out_3808243550112720964[47] = 1;
   out_3808243550112720964[48] = 0;
   out_3808243550112720964[49] = 0;
   out_3808243550112720964[50] = 0;
   out_3808243550112720964[51] = 0;
   out_3808243550112720964[52] = 0;
   out_3808243550112720964[53] = 0;
}
void h_10(double *state, double *unused, double *out_6479738358501538001) {
   out_6479738358501538001[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6479738358501538001[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6479738358501538001[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2571832150125994618) {
   out_2571832150125994618[0] = 0;
   out_2571832150125994618[1] = 9.8100000000000005*cos(state[1]);
   out_2571832150125994618[2] = 0;
   out_2571832150125994618[3] = 0;
   out_2571832150125994618[4] = -state[8];
   out_2571832150125994618[5] = state[7];
   out_2571832150125994618[6] = 0;
   out_2571832150125994618[7] = state[5];
   out_2571832150125994618[8] = -state[4];
   out_2571832150125994618[9] = 0;
   out_2571832150125994618[10] = 0;
   out_2571832150125994618[11] = 0;
   out_2571832150125994618[12] = 1;
   out_2571832150125994618[13] = 0;
   out_2571832150125994618[14] = 0;
   out_2571832150125994618[15] = 1;
   out_2571832150125994618[16] = 0;
   out_2571832150125994618[17] = 0;
   out_2571832150125994618[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2571832150125994618[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2571832150125994618[20] = 0;
   out_2571832150125994618[21] = state[8];
   out_2571832150125994618[22] = 0;
   out_2571832150125994618[23] = -state[6];
   out_2571832150125994618[24] = -state[5];
   out_2571832150125994618[25] = 0;
   out_2571832150125994618[26] = state[3];
   out_2571832150125994618[27] = 0;
   out_2571832150125994618[28] = 0;
   out_2571832150125994618[29] = 0;
   out_2571832150125994618[30] = 0;
   out_2571832150125994618[31] = 1;
   out_2571832150125994618[32] = 0;
   out_2571832150125994618[33] = 0;
   out_2571832150125994618[34] = 1;
   out_2571832150125994618[35] = 0;
   out_2571832150125994618[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2571832150125994618[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2571832150125994618[38] = 0;
   out_2571832150125994618[39] = -state[7];
   out_2571832150125994618[40] = state[6];
   out_2571832150125994618[41] = 0;
   out_2571832150125994618[42] = state[4];
   out_2571832150125994618[43] = -state[3];
   out_2571832150125994618[44] = 0;
   out_2571832150125994618[45] = 0;
   out_2571832150125994618[46] = 0;
   out_2571832150125994618[47] = 0;
   out_2571832150125994618[48] = 0;
   out_2571832150125994618[49] = 0;
   out_2571832150125994618[50] = 1;
   out_2571832150125994618[51] = 0;
   out_2571832150125994618[52] = 0;
   out_2571832150125994618[53] = 1;
}
void h_13(double *state, double *unused, double *out_2468597468972695670) {
   out_2468597468972695670[0] = state[3];
   out_2468597468972695670[1] = state[4];
   out_2468597468972695670[2] = state[5];
}
void H_13(double *state, double *unused, double *out_595969724780388163) {
   out_595969724780388163[0] = 0;
   out_595969724780388163[1] = 0;
   out_595969724780388163[2] = 0;
   out_595969724780388163[3] = 1;
   out_595969724780388163[4] = 0;
   out_595969724780388163[5] = 0;
   out_595969724780388163[6] = 0;
   out_595969724780388163[7] = 0;
   out_595969724780388163[8] = 0;
   out_595969724780388163[9] = 0;
   out_595969724780388163[10] = 0;
   out_595969724780388163[11] = 0;
   out_595969724780388163[12] = 0;
   out_595969724780388163[13] = 0;
   out_595969724780388163[14] = 0;
   out_595969724780388163[15] = 0;
   out_595969724780388163[16] = 0;
   out_595969724780388163[17] = 0;
   out_595969724780388163[18] = 0;
   out_595969724780388163[19] = 0;
   out_595969724780388163[20] = 0;
   out_595969724780388163[21] = 0;
   out_595969724780388163[22] = 1;
   out_595969724780388163[23] = 0;
   out_595969724780388163[24] = 0;
   out_595969724780388163[25] = 0;
   out_595969724780388163[26] = 0;
   out_595969724780388163[27] = 0;
   out_595969724780388163[28] = 0;
   out_595969724780388163[29] = 0;
   out_595969724780388163[30] = 0;
   out_595969724780388163[31] = 0;
   out_595969724780388163[32] = 0;
   out_595969724780388163[33] = 0;
   out_595969724780388163[34] = 0;
   out_595969724780388163[35] = 0;
   out_595969724780388163[36] = 0;
   out_595969724780388163[37] = 0;
   out_595969724780388163[38] = 0;
   out_595969724780388163[39] = 0;
   out_595969724780388163[40] = 0;
   out_595969724780388163[41] = 1;
   out_595969724780388163[42] = 0;
   out_595969724780388163[43] = 0;
   out_595969724780388163[44] = 0;
   out_595969724780388163[45] = 0;
   out_595969724780388163[46] = 0;
   out_595969724780388163[47] = 0;
   out_595969724780388163[48] = 0;
   out_595969724780388163[49] = 0;
   out_595969724780388163[50] = 0;
   out_595969724780388163[51] = 0;
   out_595969724780388163[52] = 0;
   out_595969724780388163[53] = 0;
}
void h_14(double *state, double *unused, double *out_7378190979403323616) {
   out_7378190979403323616[0] = state[6];
   out_7378190979403323616[1] = state[7];
   out_7378190979403323616[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6891031982408093260) {
   out_6891031982408093260[0] = 0;
   out_6891031982408093260[1] = 0;
   out_6891031982408093260[2] = 0;
   out_6891031982408093260[3] = 0;
   out_6891031982408093260[4] = 0;
   out_6891031982408093260[5] = 0;
   out_6891031982408093260[6] = 1;
   out_6891031982408093260[7] = 0;
   out_6891031982408093260[8] = 0;
   out_6891031982408093260[9] = 0;
   out_6891031982408093260[10] = 0;
   out_6891031982408093260[11] = 0;
   out_6891031982408093260[12] = 0;
   out_6891031982408093260[13] = 0;
   out_6891031982408093260[14] = 0;
   out_6891031982408093260[15] = 0;
   out_6891031982408093260[16] = 0;
   out_6891031982408093260[17] = 0;
   out_6891031982408093260[18] = 0;
   out_6891031982408093260[19] = 0;
   out_6891031982408093260[20] = 0;
   out_6891031982408093260[21] = 0;
   out_6891031982408093260[22] = 0;
   out_6891031982408093260[23] = 0;
   out_6891031982408093260[24] = 0;
   out_6891031982408093260[25] = 1;
   out_6891031982408093260[26] = 0;
   out_6891031982408093260[27] = 0;
   out_6891031982408093260[28] = 0;
   out_6891031982408093260[29] = 0;
   out_6891031982408093260[30] = 0;
   out_6891031982408093260[31] = 0;
   out_6891031982408093260[32] = 0;
   out_6891031982408093260[33] = 0;
   out_6891031982408093260[34] = 0;
   out_6891031982408093260[35] = 0;
   out_6891031982408093260[36] = 0;
   out_6891031982408093260[37] = 0;
   out_6891031982408093260[38] = 0;
   out_6891031982408093260[39] = 0;
   out_6891031982408093260[40] = 0;
   out_6891031982408093260[41] = 0;
   out_6891031982408093260[42] = 0;
   out_6891031982408093260[43] = 0;
   out_6891031982408093260[44] = 1;
   out_6891031982408093260[45] = 0;
   out_6891031982408093260[46] = 0;
   out_6891031982408093260[47] = 0;
   out_6891031982408093260[48] = 0;
   out_6891031982408093260[49] = 0;
   out_6891031982408093260[50] = 0;
   out_6891031982408093260[51] = 0;
   out_6891031982408093260[52] = 0;
   out_6891031982408093260[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7958882747940958001) {
  err_fun(nom_x, delta_x, out_7958882747940958001);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4703319146697471116) {
  inv_err_fun(nom_x, true_x, out_4703319146697471116);
}
void pose_H_mod_fun(double *state, double *out_656327009382969529) {
  H_mod_fun(state, out_656327009382969529);
}
void pose_f_fun(double *state, double dt, double *out_1970546984054209494) {
  f_fun(state,  dt, out_1970546984054209494);
}
void pose_F_fun(double *state, double dt, double *out_2484970000761638635) {
  F_fun(state,  dt, out_2484970000761638635);
}
void pose_h_4(double *state, double *unused, double *out_5725974613387962710) {
  h_4(state, unused, out_5725974613387962710);
}
void pose_H_4(double *state, double *unused, double *out_3808243550112720964) {
  H_4(state, unused, out_3808243550112720964);
}
void pose_h_10(double *state, double *unused, double *out_6479738358501538001) {
  h_10(state, unused, out_6479738358501538001);
}
void pose_H_10(double *state, double *unused, double *out_2571832150125994618) {
  H_10(state, unused, out_2571832150125994618);
}
void pose_h_13(double *state, double *unused, double *out_2468597468972695670) {
  h_13(state, unused, out_2468597468972695670);
}
void pose_H_13(double *state, double *unused, double *out_595969724780388163) {
  H_13(state, unused, out_595969724780388163);
}
void pose_h_14(double *state, double *unused, double *out_7378190979403323616) {
  h_14(state, unused, out_7378190979403323616);
}
void pose_H_14(double *state, double *unused, double *out_6891031982408093260) {
  H_14(state, unused, out_6891031982408093260);
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
