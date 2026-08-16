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
void err_fun(double *nom_x, double *delta_x, double *out_3576801538095390920) {
   out_3576801538095390920[0] = delta_x[0] + nom_x[0];
   out_3576801538095390920[1] = delta_x[1] + nom_x[1];
   out_3576801538095390920[2] = delta_x[2] + nom_x[2];
   out_3576801538095390920[3] = delta_x[3] + nom_x[3];
   out_3576801538095390920[4] = delta_x[4] + nom_x[4];
   out_3576801538095390920[5] = delta_x[5] + nom_x[5];
   out_3576801538095390920[6] = delta_x[6] + nom_x[6];
   out_3576801538095390920[7] = delta_x[7] + nom_x[7];
   out_3576801538095390920[8] = delta_x[8] + nom_x[8];
   out_3576801538095390920[9] = delta_x[9] + nom_x[9];
   out_3576801538095390920[10] = delta_x[10] + nom_x[10];
   out_3576801538095390920[11] = delta_x[11] + nom_x[11];
   out_3576801538095390920[12] = delta_x[12] + nom_x[12];
   out_3576801538095390920[13] = delta_x[13] + nom_x[13];
   out_3576801538095390920[14] = delta_x[14] + nom_x[14];
   out_3576801538095390920[15] = delta_x[15] + nom_x[15];
   out_3576801538095390920[16] = delta_x[16] + nom_x[16];
   out_3576801538095390920[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3629669491519681211) {
   out_3629669491519681211[0] = -nom_x[0] + true_x[0];
   out_3629669491519681211[1] = -nom_x[1] + true_x[1];
   out_3629669491519681211[2] = -nom_x[2] + true_x[2];
   out_3629669491519681211[3] = -nom_x[3] + true_x[3];
   out_3629669491519681211[4] = -nom_x[4] + true_x[4];
   out_3629669491519681211[5] = -nom_x[5] + true_x[5];
   out_3629669491519681211[6] = -nom_x[6] + true_x[6];
   out_3629669491519681211[7] = -nom_x[7] + true_x[7];
   out_3629669491519681211[8] = -nom_x[8] + true_x[8];
   out_3629669491519681211[9] = -nom_x[9] + true_x[9];
   out_3629669491519681211[10] = -nom_x[10] + true_x[10];
   out_3629669491519681211[11] = -nom_x[11] + true_x[11];
   out_3629669491519681211[12] = -nom_x[12] + true_x[12];
   out_3629669491519681211[13] = -nom_x[13] + true_x[13];
   out_3629669491519681211[14] = -nom_x[14] + true_x[14];
   out_3629669491519681211[15] = -nom_x[15] + true_x[15];
   out_3629669491519681211[16] = -nom_x[16] + true_x[16];
   out_3629669491519681211[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_128220774054724087) {
   out_128220774054724087[0] = 1.0;
   out_128220774054724087[1] = 0.0;
   out_128220774054724087[2] = 0.0;
   out_128220774054724087[3] = 0.0;
   out_128220774054724087[4] = 0.0;
   out_128220774054724087[5] = 0.0;
   out_128220774054724087[6] = 0.0;
   out_128220774054724087[7] = 0.0;
   out_128220774054724087[8] = 0.0;
   out_128220774054724087[9] = 0.0;
   out_128220774054724087[10] = 0.0;
   out_128220774054724087[11] = 0.0;
   out_128220774054724087[12] = 0.0;
   out_128220774054724087[13] = 0.0;
   out_128220774054724087[14] = 0.0;
   out_128220774054724087[15] = 0.0;
   out_128220774054724087[16] = 0.0;
   out_128220774054724087[17] = 0.0;
   out_128220774054724087[18] = 0.0;
   out_128220774054724087[19] = 1.0;
   out_128220774054724087[20] = 0.0;
   out_128220774054724087[21] = 0.0;
   out_128220774054724087[22] = 0.0;
   out_128220774054724087[23] = 0.0;
   out_128220774054724087[24] = 0.0;
   out_128220774054724087[25] = 0.0;
   out_128220774054724087[26] = 0.0;
   out_128220774054724087[27] = 0.0;
   out_128220774054724087[28] = 0.0;
   out_128220774054724087[29] = 0.0;
   out_128220774054724087[30] = 0.0;
   out_128220774054724087[31] = 0.0;
   out_128220774054724087[32] = 0.0;
   out_128220774054724087[33] = 0.0;
   out_128220774054724087[34] = 0.0;
   out_128220774054724087[35] = 0.0;
   out_128220774054724087[36] = 0.0;
   out_128220774054724087[37] = 0.0;
   out_128220774054724087[38] = 1.0;
   out_128220774054724087[39] = 0.0;
   out_128220774054724087[40] = 0.0;
   out_128220774054724087[41] = 0.0;
   out_128220774054724087[42] = 0.0;
   out_128220774054724087[43] = 0.0;
   out_128220774054724087[44] = 0.0;
   out_128220774054724087[45] = 0.0;
   out_128220774054724087[46] = 0.0;
   out_128220774054724087[47] = 0.0;
   out_128220774054724087[48] = 0.0;
   out_128220774054724087[49] = 0.0;
   out_128220774054724087[50] = 0.0;
   out_128220774054724087[51] = 0.0;
   out_128220774054724087[52] = 0.0;
   out_128220774054724087[53] = 0.0;
   out_128220774054724087[54] = 0.0;
   out_128220774054724087[55] = 0.0;
   out_128220774054724087[56] = 0.0;
   out_128220774054724087[57] = 1.0;
   out_128220774054724087[58] = 0.0;
   out_128220774054724087[59] = 0.0;
   out_128220774054724087[60] = 0.0;
   out_128220774054724087[61] = 0.0;
   out_128220774054724087[62] = 0.0;
   out_128220774054724087[63] = 0.0;
   out_128220774054724087[64] = 0.0;
   out_128220774054724087[65] = 0.0;
   out_128220774054724087[66] = 0.0;
   out_128220774054724087[67] = 0.0;
   out_128220774054724087[68] = 0.0;
   out_128220774054724087[69] = 0.0;
   out_128220774054724087[70] = 0.0;
   out_128220774054724087[71] = 0.0;
   out_128220774054724087[72] = 0.0;
   out_128220774054724087[73] = 0.0;
   out_128220774054724087[74] = 0.0;
   out_128220774054724087[75] = 0.0;
   out_128220774054724087[76] = 1.0;
   out_128220774054724087[77] = 0.0;
   out_128220774054724087[78] = 0.0;
   out_128220774054724087[79] = 0.0;
   out_128220774054724087[80] = 0.0;
   out_128220774054724087[81] = 0.0;
   out_128220774054724087[82] = 0.0;
   out_128220774054724087[83] = 0.0;
   out_128220774054724087[84] = 0.0;
   out_128220774054724087[85] = 0.0;
   out_128220774054724087[86] = 0.0;
   out_128220774054724087[87] = 0.0;
   out_128220774054724087[88] = 0.0;
   out_128220774054724087[89] = 0.0;
   out_128220774054724087[90] = 0.0;
   out_128220774054724087[91] = 0.0;
   out_128220774054724087[92] = 0.0;
   out_128220774054724087[93] = 0.0;
   out_128220774054724087[94] = 0.0;
   out_128220774054724087[95] = 1.0;
   out_128220774054724087[96] = 0.0;
   out_128220774054724087[97] = 0.0;
   out_128220774054724087[98] = 0.0;
   out_128220774054724087[99] = 0.0;
   out_128220774054724087[100] = 0.0;
   out_128220774054724087[101] = 0.0;
   out_128220774054724087[102] = 0.0;
   out_128220774054724087[103] = 0.0;
   out_128220774054724087[104] = 0.0;
   out_128220774054724087[105] = 0.0;
   out_128220774054724087[106] = 0.0;
   out_128220774054724087[107] = 0.0;
   out_128220774054724087[108] = 0.0;
   out_128220774054724087[109] = 0.0;
   out_128220774054724087[110] = 0.0;
   out_128220774054724087[111] = 0.0;
   out_128220774054724087[112] = 0.0;
   out_128220774054724087[113] = 0.0;
   out_128220774054724087[114] = 1.0;
   out_128220774054724087[115] = 0.0;
   out_128220774054724087[116] = 0.0;
   out_128220774054724087[117] = 0.0;
   out_128220774054724087[118] = 0.0;
   out_128220774054724087[119] = 0.0;
   out_128220774054724087[120] = 0.0;
   out_128220774054724087[121] = 0.0;
   out_128220774054724087[122] = 0.0;
   out_128220774054724087[123] = 0.0;
   out_128220774054724087[124] = 0.0;
   out_128220774054724087[125] = 0.0;
   out_128220774054724087[126] = 0.0;
   out_128220774054724087[127] = 0.0;
   out_128220774054724087[128] = 0.0;
   out_128220774054724087[129] = 0.0;
   out_128220774054724087[130] = 0.0;
   out_128220774054724087[131] = 0.0;
   out_128220774054724087[132] = 0.0;
   out_128220774054724087[133] = 1.0;
   out_128220774054724087[134] = 0.0;
   out_128220774054724087[135] = 0.0;
   out_128220774054724087[136] = 0.0;
   out_128220774054724087[137] = 0.0;
   out_128220774054724087[138] = 0.0;
   out_128220774054724087[139] = 0.0;
   out_128220774054724087[140] = 0.0;
   out_128220774054724087[141] = 0.0;
   out_128220774054724087[142] = 0.0;
   out_128220774054724087[143] = 0.0;
   out_128220774054724087[144] = 0.0;
   out_128220774054724087[145] = 0.0;
   out_128220774054724087[146] = 0.0;
   out_128220774054724087[147] = 0.0;
   out_128220774054724087[148] = 0.0;
   out_128220774054724087[149] = 0.0;
   out_128220774054724087[150] = 0.0;
   out_128220774054724087[151] = 0.0;
   out_128220774054724087[152] = 1.0;
   out_128220774054724087[153] = 0.0;
   out_128220774054724087[154] = 0.0;
   out_128220774054724087[155] = 0.0;
   out_128220774054724087[156] = 0.0;
   out_128220774054724087[157] = 0.0;
   out_128220774054724087[158] = 0.0;
   out_128220774054724087[159] = 0.0;
   out_128220774054724087[160] = 0.0;
   out_128220774054724087[161] = 0.0;
   out_128220774054724087[162] = 0.0;
   out_128220774054724087[163] = 0.0;
   out_128220774054724087[164] = 0.0;
   out_128220774054724087[165] = 0.0;
   out_128220774054724087[166] = 0.0;
   out_128220774054724087[167] = 0.0;
   out_128220774054724087[168] = 0.0;
   out_128220774054724087[169] = 0.0;
   out_128220774054724087[170] = 0.0;
   out_128220774054724087[171] = 1.0;
   out_128220774054724087[172] = 0.0;
   out_128220774054724087[173] = 0.0;
   out_128220774054724087[174] = 0.0;
   out_128220774054724087[175] = 0.0;
   out_128220774054724087[176] = 0.0;
   out_128220774054724087[177] = 0.0;
   out_128220774054724087[178] = 0.0;
   out_128220774054724087[179] = 0.0;
   out_128220774054724087[180] = 0.0;
   out_128220774054724087[181] = 0.0;
   out_128220774054724087[182] = 0.0;
   out_128220774054724087[183] = 0.0;
   out_128220774054724087[184] = 0.0;
   out_128220774054724087[185] = 0.0;
   out_128220774054724087[186] = 0.0;
   out_128220774054724087[187] = 0.0;
   out_128220774054724087[188] = 0.0;
   out_128220774054724087[189] = 0.0;
   out_128220774054724087[190] = 1.0;
   out_128220774054724087[191] = 0.0;
   out_128220774054724087[192] = 0.0;
   out_128220774054724087[193] = 0.0;
   out_128220774054724087[194] = 0.0;
   out_128220774054724087[195] = 0.0;
   out_128220774054724087[196] = 0.0;
   out_128220774054724087[197] = 0.0;
   out_128220774054724087[198] = 0.0;
   out_128220774054724087[199] = 0.0;
   out_128220774054724087[200] = 0.0;
   out_128220774054724087[201] = 0.0;
   out_128220774054724087[202] = 0.0;
   out_128220774054724087[203] = 0.0;
   out_128220774054724087[204] = 0.0;
   out_128220774054724087[205] = 0.0;
   out_128220774054724087[206] = 0.0;
   out_128220774054724087[207] = 0.0;
   out_128220774054724087[208] = 0.0;
   out_128220774054724087[209] = 1.0;
   out_128220774054724087[210] = 0.0;
   out_128220774054724087[211] = 0.0;
   out_128220774054724087[212] = 0.0;
   out_128220774054724087[213] = 0.0;
   out_128220774054724087[214] = 0.0;
   out_128220774054724087[215] = 0.0;
   out_128220774054724087[216] = 0.0;
   out_128220774054724087[217] = 0.0;
   out_128220774054724087[218] = 0.0;
   out_128220774054724087[219] = 0.0;
   out_128220774054724087[220] = 0.0;
   out_128220774054724087[221] = 0.0;
   out_128220774054724087[222] = 0.0;
   out_128220774054724087[223] = 0.0;
   out_128220774054724087[224] = 0.0;
   out_128220774054724087[225] = 0.0;
   out_128220774054724087[226] = 0.0;
   out_128220774054724087[227] = 0.0;
   out_128220774054724087[228] = 1.0;
   out_128220774054724087[229] = 0.0;
   out_128220774054724087[230] = 0.0;
   out_128220774054724087[231] = 0.0;
   out_128220774054724087[232] = 0.0;
   out_128220774054724087[233] = 0.0;
   out_128220774054724087[234] = 0.0;
   out_128220774054724087[235] = 0.0;
   out_128220774054724087[236] = 0.0;
   out_128220774054724087[237] = 0.0;
   out_128220774054724087[238] = 0.0;
   out_128220774054724087[239] = 0.0;
   out_128220774054724087[240] = 0.0;
   out_128220774054724087[241] = 0.0;
   out_128220774054724087[242] = 0.0;
   out_128220774054724087[243] = 0.0;
   out_128220774054724087[244] = 0.0;
   out_128220774054724087[245] = 0.0;
   out_128220774054724087[246] = 0.0;
   out_128220774054724087[247] = 1.0;
   out_128220774054724087[248] = 0.0;
   out_128220774054724087[249] = 0.0;
   out_128220774054724087[250] = 0.0;
   out_128220774054724087[251] = 0.0;
   out_128220774054724087[252] = 0.0;
   out_128220774054724087[253] = 0.0;
   out_128220774054724087[254] = 0.0;
   out_128220774054724087[255] = 0.0;
   out_128220774054724087[256] = 0.0;
   out_128220774054724087[257] = 0.0;
   out_128220774054724087[258] = 0.0;
   out_128220774054724087[259] = 0.0;
   out_128220774054724087[260] = 0.0;
   out_128220774054724087[261] = 0.0;
   out_128220774054724087[262] = 0.0;
   out_128220774054724087[263] = 0.0;
   out_128220774054724087[264] = 0.0;
   out_128220774054724087[265] = 0.0;
   out_128220774054724087[266] = 1.0;
   out_128220774054724087[267] = 0.0;
   out_128220774054724087[268] = 0.0;
   out_128220774054724087[269] = 0.0;
   out_128220774054724087[270] = 0.0;
   out_128220774054724087[271] = 0.0;
   out_128220774054724087[272] = 0.0;
   out_128220774054724087[273] = 0.0;
   out_128220774054724087[274] = 0.0;
   out_128220774054724087[275] = 0.0;
   out_128220774054724087[276] = 0.0;
   out_128220774054724087[277] = 0.0;
   out_128220774054724087[278] = 0.0;
   out_128220774054724087[279] = 0.0;
   out_128220774054724087[280] = 0.0;
   out_128220774054724087[281] = 0.0;
   out_128220774054724087[282] = 0.0;
   out_128220774054724087[283] = 0.0;
   out_128220774054724087[284] = 0.0;
   out_128220774054724087[285] = 1.0;
   out_128220774054724087[286] = 0.0;
   out_128220774054724087[287] = 0.0;
   out_128220774054724087[288] = 0.0;
   out_128220774054724087[289] = 0.0;
   out_128220774054724087[290] = 0.0;
   out_128220774054724087[291] = 0.0;
   out_128220774054724087[292] = 0.0;
   out_128220774054724087[293] = 0.0;
   out_128220774054724087[294] = 0.0;
   out_128220774054724087[295] = 0.0;
   out_128220774054724087[296] = 0.0;
   out_128220774054724087[297] = 0.0;
   out_128220774054724087[298] = 0.0;
   out_128220774054724087[299] = 0.0;
   out_128220774054724087[300] = 0.0;
   out_128220774054724087[301] = 0.0;
   out_128220774054724087[302] = 0.0;
   out_128220774054724087[303] = 0.0;
   out_128220774054724087[304] = 1.0;
   out_128220774054724087[305] = 0.0;
   out_128220774054724087[306] = 0.0;
   out_128220774054724087[307] = 0.0;
   out_128220774054724087[308] = 0.0;
   out_128220774054724087[309] = 0.0;
   out_128220774054724087[310] = 0.0;
   out_128220774054724087[311] = 0.0;
   out_128220774054724087[312] = 0.0;
   out_128220774054724087[313] = 0.0;
   out_128220774054724087[314] = 0.0;
   out_128220774054724087[315] = 0.0;
   out_128220774054724087[316] = 0.0;
   out_128220774054724087[317] = 0.0;
   out_128220774054724087[318] = 0.0;
   out_128220774054724087[319] = 0.0;
   out_128220774054724087[320] = 0.0;
   out_128220774054724087[321] = 0.0;
   out_128220774054724087[322] = 0.0;
   out_128220774054724087[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8022018128441912094) {
   out_8022018128441912094[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8022018128441912094[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8022018128441912094[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8022018128441912094[3] = dt*state[12] + state[3];
   out_8022018128441912094[4] = dt*state[13] + state[4];
   out_8022018128441912094[5] = dt*state[14] + state[5];
   out_8022018128441912094[6] = state[6];
   out_8022018128441912094[7] = state[7];
   out_8022018128441912094[8] = state[8];
   out_8022018128441912094[9] = state[9];
   out_8022018128441912094[10] = state[10];
   out_8022018128441912094[11] = state[11];
   out_8022018128441912094[12] = state[12];
   out_8022018128441912094[13] = state[13];
   out_8022018128441912094[14] = state[14];
   out_8022018128441912094[15] = state[15];
   out_8022018128441912094[16] = state[16];
   out_8022018128441912094[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4440336535941280195) {
   out_4440336535941280195[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4440336535941280195[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4440336535941280195[2] = 0;
   out_4440336535941280195[3] = 0;
   out_4440336535941280195[4] = 0;
   out_4440336535941280195[5] = 0;
   out_4440336535941280195[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4440336535941280195[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4440336535941280195[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4440336535941280195[9] = 0;
   out_4440336535941280195[10] = 0;
   out_4440336535941280195[11] = 0;
   out_4440336535941280195[12] = 0;
   out_4440336535941280195[13] = 0;
   out_4440336535941280195[14] = 0;
   out_4440336535941280195[15] = 0;
   out_4440336535941280195[16] = 0;
   out_4440336535941280195[17] = 0;
   out_4440336535941280195[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4440336535941280195[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4440336535941280195[20] = 0;
   out_4440336535941280195[21] = 0;
   out_4440336535941280195[22] = 0;
   out_4440336535941280195[23] = 0;
   out_4440336535941280195[24] = 0;
   out_4440336535941280195[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4440336535941280195[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4440336535941280195[27] = 0;
   out_4440336535941280195[28] = 0;
   out_4440336535941280195[29] = 0;
   out_4440336535941280195[30] = 0;
   out_4440336535941280195[31] = 0;
   out_4440336535941280195[32] = 0;
   out_4440336535941280195[33] = 0;
   out_4440336535941280195[34] = 0;
   out_4440336535941280195[35] = 0;
   out_4440336535941280195[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4440336535941280195[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4440336535941280195[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4440336535941280195[39] = 0;
   out_4440336535941280195[40] = 0;
   out_4440336535941280195[41] = 0;
   out_4440336535941280195[42] = 0;
   out_4440336535941280195[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4440336535941280195[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4440336535941280195[45] = 0;
   out_4440336535941280195[46] = 0;
   out_4440336535941280195[47] = 0;
   out_4440336535941280195[48] = 0;
   out_4440336535941280195[49] = 0;
   out_4440336535941280195[50] = 0;
   out_4440336535941280195[51] = 0;
   out_4440336535941280195[52] = 0;
   out_4440336535941280195[53] = 0;
   out_4440336535941280195[54] = 0;
   out_4440336535941280195[55] = 0;
   out_4440336535941280195[56] = 0;
   out_4440336535941280195[57] = 1;
   out_4440336535941280195[58] = 0;
   out_4440336535941280195[59] = 0;
   out_4440336535941280195[60] = 0;
   out_4440336535941280195[61] = 0;
   out_4440336535941280195[62] = 0;
   out_4440336535941280195[63] = 0;
   out_4440336535941280195[64] = 0;
   out_4440336535941280195[65] = 0;
   out_4440336535941280195[66] = dt;
   out_4440336535941280195[67] = 0;
   out_4440336535941280195[68] = 0;
   out_4440336535941280195[69] = 0;
   out_4440336535941280195[70] = 0;
   out_4440336535941280195[71] = 0;
   out_4440336535941280195[72] = 0;
   out_4440336535941280195[73] = 0;
   out_4440336535941280195[74] = 0;
   out_4440336535941280195[75] = 0;
   out_4440336535941280195[76] = 1;
   out_4440336535941280195[77] = 0;
   out_4440336535941280195[78] = 0;
   out_4440336535941280195[79] = 0;
   out_4440336535941280195[80] = 0;
   out_4440336535941280195[81] = 0;
   out_4440336535941280195[82] = 0;
   out_4440336535941280195[83] = 0;
   out_4440336535941280195[84] = 0;
   out_4440336535941280195[85] = dt;
   out_4440336535941280195[86] = 0;
   out_4440336535941280195[87] = 0;
   out_4440336535941280195[88] = 0;
   out_4440336535941280195[89] = 0;
   out_4440336535941280195[90] = 0;
   out_4440336535941280195[91] = 0;
   out_4440336535941280195[92] = 0;
   out_4440336535941280195[93] = 0;
   out_4440336535941280195[94] = 0;
   out_4440336535941280195[95] = 1;
   out_4440336535941280195[96] = 0;
   out_4440336535941280195[97] = 0;
   out_4440336535941280195[98] = 0;
   out_4440336535941280195[99] = 0;
   out_4440336535941280195[100] = 0;
   out_4440336535941280195[101] = 0;
   out_4440336535941280195[102] = 0;
   out_4440336535941280195[103] = 0;
   out_4440336535941280195[104] = dt;
   out_4440336535941280195[105] = 0;
   out_4440336535941280195[106] = 0;
   out_4440336535941280195[107] = 0;
   out_4440336535941280195[108] = 0;
   out_4440336535941280195[109] = 0;
   out_4440336535941280195[110] = 0;
   out_4440336535941280195[111] = 0;
   out_4440336535941280195[112] = 0;
   out_4440336535941280195[113] = 0;
   out_4440336535941280195[114] = 1;
   out_4440336535941280195[115] = 0;
   out_4440336535941280195[116] = 0;
   out_4440336535941280195[117] = 0;
   out_4440336535941280195[118] = 0;
   out_4440336535941280195[119] = 0;
   out_4440336535941280195[120] = 0;
   out_4440336535941280195[121] = 0;
   out_4440336535941280195[122] = 0;
   out_4440336535941280195[123] = 0;
   out_4440336535941280195[124] = 0;
   out_4440336535941280195[125] = 0;
   out_4440336535941280195[126] = 0;
   out_4440336535941280195[127] = 0;
   out_4440336535941280195[128] = 0;
   out_4440336535941280195[129] = 0;
   out_4440336535941280195[130] = 0;
   out_4440336535941280195[131] = 0;
   out_4440336535941280195[132] = 0;
   out_4440336535941280195[133] = 1;
   out_4440336535941280195[134] = 0;
   out_4440336535941280195[135] = 0;
   out_4440336535941280195[136] = 0;
   out_4440336535941280195[137] = 0;
   out_4440336535941280195[138] = 0;
   out_4440336535941280195[139] = 0;
   out_4440336535941280195[140] = 0;
   out_4440336535941280195[141] = 0;
   out_4440336535941280195[142] = 0;
   out_4440336535941280195[143] = 0;
   out_4440336535941280195[144] = 0;
   out_4440336535941280195[145] = 0;
   out_4440336535941280195[146] = 0;
   out_4440336535941280195[147] = 0;
   out_4440336535941280195[148] = 0;
   out_4440336535941280195[149] = 0;
   out_4440336535941280195[150] = 0;
   out_4440336535941280195[151] = 0;
   out_4440336535941280195[152] = 1;
   out_4440336535941280195[153] = 0;
   out_4440336535941280195[154] = 0;
   out_4440336535941280195[155] = 0;
   out_4440336535941280195[156] = 0;
   out_4440336535941280195[157] = 0;
   out_4440336535941280195[158] = 0;
   out_4440336535941280195[159] = 0;
   out_4440336535941280195[160] = 0;
   out_4440336535941280195[161] = 0;
   out_4440336535941280195[162] = 0;
   out_4440336535941280195[163] = 0;
   out_4440336535941280195[164] = 0;
   out_4440336535941280195[165] = 0;
   out_4440336535941280195[166] = 0;
   out_4440336535941280195[167] = 0;
   out_4440336535941280195[168] = 0;
   out_4440336535941280195[169] = 0;
   out_4440336535941280195[170] = 0;
   out_4440336535941280195[171] = 1;
   out_4440336535941280195[172] = 0;
   out_4440336535941280195[173] = 0;
   out_4440336535941280195[174] = 0;
   out_4440336535941280195[175] = 0;
   out_4440336535941280195[176] = 0;
   out_4440336535941280195[177] = 0;
   out_4440336535941280195[178] = 0;
   out_4440336535941280195[179] = 0;
   out_4440336535941280195[180] = 0;
   out_4440336535941280195[181] = 0;
   out_4440336535941280195[182] = 0;
   out_4440336535941280195[183] = 0;
   out_4440336535941280195[184] = 0;
   out_4440336535941280195[185] = 0;
   out_4440336535941280195[186] = 0;
   out_4440336535941280195[187] = 0;
   out_4440336535941280195[188] = 0;
   out_4440336535941280195[189] = 0;
   out_4440336535941280195[190] = 1;
   out_4440336535941280195[191] = 0;
   out_4440336535941280195[192] = 0;
   out_4440336535941280195[193] = 0;
   out_4440336535941280195[194] = 0;
   out_4440336535941280195[195] = 0;
   out_4440336535941280195[196] = 0;
   out_4440336535941280195[197] = 0;
   out_4440336535941280195[198] = 0;
   out_4440336535941280195[199] = 0;
   out_4440336535941280195[200] = 0;
   out_4440336535941280195[201] = 0;
   out_4440336535941280195[202] = 0;
   out_4440336535941280195[203] = 0;
   out_4440336535941280195[204] = 0;
   out_4440336535941280195[205] = 0;
   out_4440336535941280195[206] = 0;
   out_4440336535941280195[207] = 0;
   out_4440336535941280195[208] = 0;
   out_4440336535941280195[209] = 1;
   out_4440336535941280195[210] = 0;
   out_4440336535941280195[211] = 0;
   out_4440336535941280195[212] = 0;
   out_4440336535941280195[213] = 0;
   out_4440336535941280195[214] = 0;
   out_4440336535941280195[215] = 0;
   out_4440336535941280195[216] = 0;
   out_4440336535941280195[217] = 0;
   out_4440336535941280195[218] = 0;
   out_4440336535941280195[219] = 0;
   out_4440336535941280195[220] = 0;
   out_4440336535941280195[221] = 0;
   out_4440336535941280195[222] = 0;
   out_4440336535941280195[223] = 0;
   out_4440336535941280195[224] = 0;
   out_4440336535941280195[225] = 0;
   out_4440336535941280195[226] = 0;
   out_4440336535941280195[227] = 0;
   out_4440336535941280195[228] = 1;
   out_4440336535941280195[229] = 0;
   out_4440336535941280195[230] = 0;
   out_4440336535941280195[231] = 0;
   out_4440336535941280195[232] = 0;
   out_4440336535941280195[233] = 0;
   out_4440336535941280195[234] = 0;
   out_4440336535941280195[235] = 0;
   out_4440336535941280195[236] = 0;
   out_4440336535941280195[237] = 0;
   out_4440336535941280195[238] = 0;
   out_4440336535941280195[239] = 0;
   out_4440336535941280195[240] = 0;
   out_4440336535941280195[241] = 0;
   out_4440336535941280195[242] = 0;
   out_4440336535941280195[243] = 0;
   out_4440336535941280195[244] = 0;
   out_4440336535941280195[245] = 0;
   out_4440336535941280195[246] = 0;
   out_4440336535941280195[247] = 1;
   out_4440336535941280195[248] = 0;
   out_4440336535941280195[249] = 0;
   out_4440336535941280195[250] = 0;
   out_4440336535941280195[251] = 0;
   out_4440336535941280195[252] = 0;
   out_4440336535941280195[253] = 0;
   out_4440336535941280195[254] = 0;
   out_4440336535941280195[255] = 0;
   out_4440336535941280195[256] = 0;
   out_4440336535941280195[257] = 0;
   out_4440336535941280195[258] = 0;
   out_4440336535941280195[259] = 0;
   out_4440336535941280195[260] = 0;
   out_4440336535941280195[261] = 0;
   out_4440336535941280195[262] = 0;
   out_4440336535941280195[263] = 0;
   out_4440336535941280195[264] = 0;
   out_4440336535941280195[265] = 0;
   out_4440336535941280195[266] = 1;
   out_4440336535941280195[267] = 0;
   out_4440336535941280195[268] = 0;
   out_4440336535941280195[269] = 0;
   out_4440336535941280195[270] = 0;
   out_4440336535941280195[271] = 0;
   out_4440336535941280195[272] = 0;
   out_4440336535941280195[273] = 0;
   out_4440336535941280195[274] = 0;
   out_4440336535941280195[275] = 0;
   out_4440336535941280195[276] = 0;
   out_4440336535941280195[277] = 0;
   out_4440336535941280195[278] = 0;
   out_4440336535941280195[279] = 0;
   out_4440336535941280195[280] = 0;
   out_4440336535941280195[281] = 0;
   out_4440336535941280195[282] = 0;
   out_4440336535941280195[283] = 0;
   out_4440336535941280195[284] = 0;
   out_4440336535941280195[285] = 1;
   out_4440336535941280195[286] = 0;
   out_4440336535941280195[287] = 0;
   out_4440336535941280195[288] = 0;
   out_4440336535941280195[289] = 0;
   out_4440336535941280195[290] = 0;
   out_4440336535941280195[291] = 0;
   out_4440336535941280195[292] = 0;
   out_4440336535941280195[293] = 0;
   out_4440336535941280195[294] = 0;
   out_4440336535941280195[295] = 0;
   out_4440336535941280195[296] = 0;
   out_4440336535941280195[297] = 0;
   out_4440336535941280195[298] = 0;
   out_4440336535941280195[299] = 0;
   out_4440336535941280195[300] = 0;
   out_4440336535941280195[301] = 0;
   out_4440336535941280195[302] = 0;
   out_4440336535941280195[303] = 0;
   out_4440336535941280195[304] = 1;
   out_4440336535941280195[305] = 0;
   out_4440336535941280195[306] = 0;
   out_4440336535941280195[307] = 0;
   out_4440336535941280195[308] = 0;
   out_4440336535941280195[309] = 0;
   out_4440336535941280195[310] = 0;
   out_4440336535941280195[311] = 0;
   out_4440336535941280195[312] = 0;
   out_4440336535941280195[313] = 0;
   out_4440336535941280195[314] = 0;
   out_4440336535941280195[315] = 0;
   out_4440336535941280195[316] = 0;
   out_4440336535941280195[317] = 0;
   out_4440336535941280195[318] = 0;
   out_4440336535941280195[319] = 0;
   out_4440336535941280195[320] = 0;
   out_4440336535941280195[321] = 0;
   out_4440336535941280195[322] = 0;
   out_4440336535941280195[323] = 1;
}
void h_4(double *state, double *unused, double *out_1055205231970937411) {
   out_1055205231970937411[0] = state[6] + state[9];
   out_1055205231970937411[1] = state[7] + state[10];
   out_1055205231970937411[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5232245798722086233) {
   out_5232245798722086233[0] = 0;
   out_5232245798722086233[1] = 0;
   out_5232245798722086233[2] = 0;
   out_5232245798722086233[3] = 0;
   out_5232245798722086233[4] = 0;
   out_5232245798722086233[5] = 0;
   out_5232245798722086233[6] = 1;
   out_5232245798722086233[7] = 0;
   out_5232245798722086233[8] = 0;
   out_5232245798722086233[9] = 1;
   out_5232245798722086233[10] = 0;
   out_5232245798722086233[11] = 0;
   out_5232245798722086233[12] = 0;
   out_5232245798722086233[13] = 0;
   out_5232245798722086233[14] = 0;
   out_5232245798722086233[15] = 0;
   out_5232245798722086233[16] = 0;
   out_5232245798722086233[17] = 0;
   out_5232245798722086233[18] = 0;
   out_5232245798722086233[19] = 0;
   out_5232245798722086233[20] = 0;
   out_5232245798722086233[21] = 0;
   out_5232245798722086233[22] = 0;
   out_5232245798722086233[23] = 0;
   out_5232245798722086233[24] = 0;
   out_5232245798722086233[25] = 1;
   out_5232245798722086233[26] = 0;
   out_5232245798722086233[27] = 0;
   out_5232245798722086233[28] = 1;
   out_5232245798722086233[29] = 0;
   out_5232245798722086233[30] = 0;
   out_5232245798722086233[31] = 0;
   out_5232245798722086233[32] = 0;
   out_5232245798722086233[33] = 0;
   out_5232245798722086233[34] = 0;
   out_5232245798722086233[35] = 0;
   out_5232245798722086233[36] = 0;
   out_5232245798722086233[37] = 0;
   out_5232245798722086233[38] = 0;
   out_5232245798722086233[39] = 0;
   out_5232245798722086233[40] = 0;
   out_5232245798722086233[41] = 0;
   out_5232245798722086233[42] = 0;
   out_5232245798722086233[43] = 0;
   out_5232245798722086233[44] = 1;
   out_5232245798722086233[45] = 0;
   out_5232245798722086233[46] = 0;
   out_5232245798722086233[47] = 1;
   out_5232245798722086233[48] = 0;
   out_5232245798722086233[49] = 0;
   out_5232245798722086233[50] = 0;
   out_5232245798722086233[51] = 0;
   out_5232245798722086233[52] = 0;
   out_5232245798722086233[53] = 0;
}
void h_10(double *state, double *unused, double *out_4616527314461451432) {
   out_4616527314461451432[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4616527314461451432[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4616527314461451432[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5353452105284919759) {
   out_5353452105284919759[0] = 0;
   out_5353452105284919759[1] = 9.8100000000000005*cos(state[1]);
   out_5353452105284919759[2] = 0;
   out_5353452105284919759[3] = 0;
   out_5353452105284919759[4] = -state[8];
   out_5353452105284919759[5] = state[7];
   out_5353452105284919759[6] = 0;
   out_5353452105284919759[7] = state[5];
   out_5353452105284919759[8] = -state[4];
   out_5353452105284919759[9] = 0;
   out_5353452105284919759[10] = 0;
   out_5353452105284919759[11] = 0;
   out_5353452105284919759[12] = 1;
   out_5353452105284919759[13] = 0;
   out_5353452105284919759[14] = 0;
   out_5353452105284919759[15] = 1;
   out_5353452105284919759[16] = 0;
   out_5353452105284919759[17] = 0;
   out_5353452105284919759[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5353452105284919759[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5353452105284919759[20] = 0;
   out_5353452105284919759[21] = state[8];
   out_5353452105284919759[22] = 0;
   out_5353452105284919759[23] = -state[6];
   out_5353452105284919759[24] = -state[5];
   out_5353452105284919759[25] = 0;
   out_5353452105284919759[26] = state[3];
   out_5353452105284919759[27] = 0;
   out_5353452105284919759[28] = 0;
   out_5353452105284919759[29] = 0;
   out_5353452105284919759[30] = 0;
   out_5353452105284919759[31] = 1;
   out_5353452105284919759[32] = 0;
   out_5353452105284919759[33] = 0;
   out_5353452105284919759[34] = 1;
   out_5353452105284919759[35] = 0;
   out_5353452105284919759[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5353452105284919759[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5353452105284919759[38] = 0;
   out_5353452105284919759[39] = -state[7];
   out_5353452105284919759[40] = state[6];
   out_5353452105284919759[41] = 0;
   out_5353452105284919759[42] = state[4];
   out_5353452105284919759[43] = -state[3];
   out_5353452105284919759[44] = 0;
   out_5353452105284919759[45] = 0;
   out_5353452105284919759[46] = 0;
   out_5353452105284919759[47] = 0;
   out_5353452105284919759[48] = 0;
   out_5353452105284919759[49] = 0;
   out_5353452105284919759[50] = 1;
   out_5353452105284919759[51] = 0;
   out_5353452105284919759[52] = 0;
   out_5353452105284919759[53] = 1;
}
void h_13(double *state, double *unused, double *out_35896446347085605) {
   out_35896446347085605[0] = state[3];
   out_35896446347085605[1] = state[4];
   out_35896446347085605[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5603867066670764454) {
   out_5603867066670764454[0] = 0;
   out_5603867066670764454[1] = 0;
   out_5603867066670764454[2] = 0;
   out_5603867066670764454[3] = 1;
   out_5603867066670764454[4] = 0;
   out_5603867066670764454[5] = 0;
   out_5603867066670764454[6] = 0;
   out_5603867066670764454[7] = 0;
   out_5603867066670764454[8] = 0;
   out_5603867066670764454[9] = 0;
   out_5603867066670764454[10] = 0;
   out_5603867066670764454[11] = 0;
   out_5603867066670764454[12] = 0;
   out_5603867066670764454[13] = 0;
   out_5603867066670764454[14] = 0;
   out_5603867066670764454[15] = 0;
   out_5603867066670764454[16] = 0;
   out_5603867066670764454[17] = 0;
   out_5603867066670764454[18] = 0;
   out_5603867066670764454[19] = 0;
   out_5603867066670764454[20] = 0;
   out_5603867066670764454[21] = 0;
   out_5603867066670764454[22] = 1;
   out_5603867066670764454[23] = 0;
   out_5603867066670764454[24] = 0;
   out_5603867066670764454[25] = 0;
   out_5603867066670764454[26] = 0;
   out_5603867066670764454[27] = 0;
   out_5603867066670764454[28] = 0;
   out_5603867066670764454[29] = 0;
   out_5603867066670764454[30] = 0;
   out_5603867066670764454[31] = 0;
   out_5603867066670764454[32] = 0;
   out_5603867066670764454[33] = 0;
   out_5603867066670764454[34] = 0;
   out_5603867066670764454[35] = 0;
   out_5603867066670764454[36] = 0;
   out_5603867066670764454[37] = 0;
   out_5603867066670764454[38] = 0;
   out_5603867066670764454[39] = 0;
   out_5603867066670764454[40] = 0;
   out_5603867066670764454[41] = 1;
   out_5603867066670764454[42] = 0;
   out_5603867066670764454[43] = 0;
   out_5603867066670764454[44] = 0;
   out_5603867066670764454[45] = 0;
   out_5603867066670764454[46] = 0;
   out_5603867066670764454[47] = 0;
   out_5603867066670764454[48] = 0;
   out_5603867066670764454[49] = 0;
   out_5603867066670764454[50] = 0;
   out_5603867066670764454[51] = 0;
   out_5603867066670764454[52] = 0;
   out_5603867066670764454[53] = 0;
}
void h_14(double *state, double *unused, double *out_631141063206634270) {
   out_631141063206634270[0] = state[6];
   out_631141063206634270[1] = state[7];
   out_631141063206634270[2] = state[8];
}
void H_14(double *state, double *unused, double *out_9195486655061570762) {
   out_9195486655061570762[0] = 0;
   out_9195486655061570762[1] = 0;
   out_9195486655061570762[2] = 0;
   out_9195486655061570762[3] = 0;
   out_9195486655061570762[4] = 0;
   out_9195486655061570762[5] = 0;
   out_9195486655061570762[6] = 1;
   out_9195486655061570762[7] = 0;
   out_9195486655061570762[8] = 0;
   out_9195486655061570762[9] = 0;
   out_9195486655061570762[10] = 0;
   out_9195486655061570762[11] = 0;
   out_9195486655061570762[12] = 0;
   out_9195486655061570762[13] = 0;
   out_9195486655061570762[14] = 0;
   out_9195486655061570762[15] = 0;
   out_9195486655061570762[16] = 0;
   out_9195486655061570762[17] = 0;
   out_9195486655061570762[18] = 0;
   out_9195486655061570762[19] = 0;
   out_9195486655061570762[20] = 0;
   out_9195486655061570762[21] = 0;
   out_9195486655061570762[22] = 0;
   out_9195486655061570762[23] = 0;
   out_9195486655061570762[24] = 0;
   out_9195486655061570762[25] = 1;
   out_9195486655061570762[26] = 0;
   out_9195486655061570762[27] = 0;
   out_9195486655061570762[28] = 0;
   out_9195486655061570762[29] = 0;
   out_9195486655061570762[30] = 0;
   out_9195486655061570762[31] = 0;
   out_9195486655061570762[32] = 0;
   out_9195486655061570762[33] = 0;
   out_9195486655061570762[34] = 0;
   out_9195486655061570762[35] = 0;
   out_9195486655061570762[36] = 0;
   out_9195486655061570762[37] = 0;
   out_9195486655061570762[38] = 0;
   out_9195486655061570762[39] = 0;
   out_9195486655061570762[40] = 0;
   out_9195486655061570762[41] = 0;
   out_9195486655061570762[42] = 0;
   out_9195486655061570762[43] = 0;
   out_9195486655061570762[44] = 1;
   out_9195486655061570762[45] = 0;
   out_9195486655061570762[46] = 0;
   out_9195486655061570762[47] = 0;
   out_9195486655061570762[48] = 0;
   out_9195486655061570762[49] = 0;
   out_9195486655061570762[50] = 0;
   out_9195486655061570762[51] = 0;
   out_9195486655061570762[52] = 0;
   out_9195486655061570762[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_3576801538095390920) {
  err_fun(nom_x, delta_x, out_3576801538095390920);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3629669491519681211) {
  inv_err_fun(nom_x, true_x, out_3629669491519681211);
}
void pose_H_mod_fun(double *state, double *out_128220774054724087) {
  H_mod_fun(state, out_128220774054724087);
}
void pose_f_fun(double *state, double dt, double *out_8022018128441912094) {
  f_fun(state,  dt, out_8022018128441912094);
}
void pose_F_fun(double *state, double dt, double *out_4440336535941280195) {
  F_fun(state,  dt, out_4440336535941280195);
}
void pose_h_4(double *state, double *unused, double *out_1055205231970937411) {
  h_4(state, unused, out_1055205231970937411);
}
void pose_H_4(double *state, double *unused, double *out_5232245798722086233) {
  H_4(state, unused, out_5232245798722086233);
}
void pose_h_10(double *state, double *unused, double *out_4616527314461451432) {
  h_10(state, unused, out_4616527314461451432);
}
void pose_H_10(double *state, double *unused, double *out_5353452105284919759) {
  H_10(state, unused, out_5353452105284919759);
}
void pose_h_13(double *state, double *unused, double *out_35896446347085605) {
  h_13(state, unused, out_35896446347085605);
}
void pose_H_13(double *state, double *unused, double *out_5603867066670764454) {
  H_13(state, unused, out_5603867066670764454);
}
void pose_h_14(double *state, double *unused, double *out_631141063206634270) {
  h_14(state, unused, out_631141063206634270);
}
void pose_H_14(double *state, double *unused, double *out_9195486655061570762) {
  H_14(state, unused, out_9195486655061570762);
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
