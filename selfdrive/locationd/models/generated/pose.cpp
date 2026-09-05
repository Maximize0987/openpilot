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
void err_fun(double *nom_x, double *delta_x, double *out_4860250714300227404) {
   out_4860250714300227404[0] = delta_x[0] + nom_x[0];
   out_4860250714300227404[1] = delta_x[1] + nom_x[1];
   out_4860250714300227404[2] = delta_x[2] + nom_x[2];
   out_4860250714300227404[3] = delta_x[3] + nom_x[3];
   out_4860250714300227404[4] = delta_x[4] + nom_x[4];
   out_4860250714300227404[5] = delta_x[5] + nom_x[5];
   out_4860250714300227404[6] = delta_x[6] + nom_x[6];
   out_4860250714300227404[7] = delta_x[7] + nom_x[7];
   out_4860250714300227404[8] = delta_x[8] + nom_x[8];
   out_4860250714300227404[9] = delta_x[9] + nom_x[9];
   out_4860250714300227404[10] = delta_x[10] + nom_x[10];
   out_4860250714300227404[11] = delta_x[11] + nom_x[11];
   out_4860250714300227404[12] = delta_x[12] + nom_x[12];
   out_4860250714300227404[13] = delta_x[13] + nom_x[13];
   out_4860250714300227404[14] = delta_x[14] + nom_x[14];
   out_4860250714300227404[15] = delta_x[15] + nom_x[15];
   out_4860250714300227404[16] = delta_x[16] + nom_x[16];
   out_4860250714300227404[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6437944255548658708) {
   out_6437944255548658708[0] = -nom_x[0] + true_x[0];
   out_6437944255548658708[1] = -nom_x[1] + true_x[1];
   out_6437944255548658708[2] = -nom_x[2] + true_x[2];
   out_6437944255548658708[3] = -nom_x[3] + true_x[3];
   out_6437944255548658708[4] = -nom_x[4] + true_x[4];
   out_6437944255548658708[5] = -nom_x[5] + true_x[5];
   out_6437944255548658708[6] = -nom_x[6] + true_x[6];
   out_6437944255548658708[7] = -nom_x[7] + true_x[7];
   out_6437944255548658708[8] = -nom_x[8] + true_x[8];
   out_6437944255548658708[9] = -nom_x[9] + true_x[9];
   out_6437944255548658708[10] = -nom_x[10] + true_x[10];
   out_6437944255548658708[11] = -nom_x[11] + true_x[11];
   out_6437944255548658708[12] = -nom_x[12] + true_x[12];
   out_6437944255548658708[13] = -nom_x[13] + true_x[13];
   out_6437944255548658708[14] = -nom_x[14] + true_x[14];
   out_6437944255548658708[15] = -nom_x[15] + true_x[15];
   out_6437944255548658708[16] = -nom_x[16] + true_x[16];
   out_6437944255548658708[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_22797630451996970) {
   out_22797630451996970[0] = 1.0;
   out_22797630451996970[1] = 0.0;
   out_22797630451996970[2] = 0.0;
   out_22797630451996970[3] = 0.0;
   out_22797630451996970[4] = 0.0;
   out_22797630451996970[5] = 0.0;
   out_22797630451996970[6] = 0.0;
   out_22797630451996970[7] = 0.0;
   out_22797630451996970[8] = 0.0;
   out_22797630451996970[9] = 0.0;
   out_22797630451996970[10] = 0.0;
   out_22797630451996970[11] = 0.0;
   out_22797630451996970[12] = 0.0;
   out_22797630451996970[13] = 0.0;
   out_22797630451996970[14] = 0.0;
   out_22797630451996970[15] = 0.0;
   out_22797630451996970[16] = 0.0;
   out_22797630451996970[17] = 0.0;
   out_22797630451996970[18] = 0.0;
   out_22797630451996970[19] = 1.0;
   out_22797630451996970[20] = 0.0;
   out_22797630451996970[21] = 0.0;
   out_22797630451996970[22] = 0.0;
   out_22797630451996970[23] = 0.0;
   out_22797630451996970[24] = 0.0;
   out_22797630451996970[25] = 0.0;
   out_22797630451996970[26] = 0.0;
   out_22797630451996970[27] = 0.0;
   out_22797630451996970[28] = 0.0;
   out_22797630451996970[29] = 0.0;
   out_22797630451996970[30] = 0.0;
   out_22797630451996970[31] = 0.0;
   out_22797630451996970[32] = 0.0;
   out_22797630451996970[33] = 0.0;
   out_22797630451996970[34] = 0.0;
   out_22797630451996970[35] = 0.0;
   out_22797630451996970[36] = 0.0;
   out_22797630451996970[37] = 0.0;
   out_22797630451996970[38] = 1.0;
   out_22797630451996970[39] = 0.0;
   out_22797630451996970[40] = 0.0;
   out_22797630451996970[41] = 0.0;
   out_22797630451996970[42] = 0.0;
   out_22797630451996970[43] = 0.0;
   out_22797630451996970[44] = 0.0;
   out_22797630451996970[45] = 0.0;
   out_22797630451996970[46] = 0.0;
   out_22797630451996970[47] = 0.0;
   out_22797630451996970[48] = 0.0;
   out_22797630451996970[49] = 0.0;
   out_22797630451996970[50] = 0.0;
   out_22797630451996970[51] = 0.0;
   out_22797630451996970[52] = 0.0;
   out_22797630451996970[53] = 0.0;
   out_22797630451996970[54] = 0.0;
   out_22797630451996970[55] = 0.0;
   out_22797630451996970[56] = 0.0;
   out_22797630451996970[57] = 1.0;
   out_22797630451996970[58] = 0.0;
   out_22797630451996970[59] = 0.0;
   out_22797630451996970[60] = 0.0;
   out_22797630451996970[61] = 0.0;
   out_22797630451996970[62] = 0.0;
   out_22797630451996970[63] = 0.0;
   out_22797630451996970[64] = 0.0;
   out_22797630451996970[65] = 0.0;
   out_22797630451996970[66] = 0.0;
   out_22797630451996970[67] = 0.0;
   out_22797630451996970[68] = 0.0;
   out_22797630451996970[69] = 0.0;
   out_22797630451996970[70] = 0.0;
   out_22797630451996970[71] = 0.0;
   out_22797630451996970[72] = 0.0;
   out_22797630451996970[73] = 0.0;
   out_22797630451996970[74] = 0.0;
   out_22797630451996970[75] = 0.0;
   out_22797630451996970[76] = 1.0;
   out_22797630451996970[77] = 0.0;
   out_22797630451996970[78] = 0.0;
   out_22797630451996970[79] = 0.0;
   out_22797630451996970[80] = 0.0;
   out_22797630451996970[81] = 0.0;
   out_22797630451996970[82] = 0.0;
   out_22797630451996970[83] = 0.0;
   out_22797630451996970[84] = 0.0;
   out_22797630451996970[85] = 0.0;
   out_22797630451996970[86] = 0.0;
   out_22797630451996970[87] = 0.0;
   out_22797630451996970[88] = 0.0;
   out_22797630451996970[89] = 0.0;
   out_22797630451996970[90] = 0.0;
   out_22797630451996970[91] = 0.0;
   out_22797630451996970[92] = 0.0;
   out_22797630451996970[93] = 0.0;
   out_22797630451996970[94] = 0.0;
   out_22797630451996970[95] = 1.0;
   out_22797630451996970[96] = 0.0;
   out_22797630451996970[97] = 0.0;
   out_22797630451996970[98] = 0.0;
   out_22797630451996970[99] = 0.0;
   out_22797630451996970[100] = 0.0;
   out_22797630451996970[101] = 0.0;
   out_22797630451996970[102] = 0.0;
   out_22797630451996970[103] = 0.0;
   out_22797630451996970[104] = 0.0;
   out_22797630451996970[105] = 0.0;
   out_22797630451996970[106] = 0.0;
   out_22797630451996970[107] = 0.0;
   out_22797630451996970[108] = 0.0;
   out_22797630451996970[109] = 0.0;
   out_22797630451996970[110] = 0.0;
   out_22797630451996970[111] = 0.0;
   out_22797630451996970[112] = 0.0;
   out_22797630451996970[113] = 0.0;
   out_22797630451996970[114] = 1.0;
   out_22797630451996970[115] = 0.0;
   out_22797630451996970[116] = 0.0;
   out_22797630451996970[117] = 0.0;
   out_22797630451996970[118] = 0.0;
   out_22797630451996970[119] = 0.0;
   out_22797630451996970[120] = 0.0;
   out_22797630451996970[121] = 0.0;
   out_22797630451996970[122] = 0.0;
   out_22797630451996970[123] = 0.0;
   out_22797630451996970[124] = 0.0;
   out_22797630451996970[125] = 0.0;
   out_22797630451996970[126] = 0.0;
   out_22797630451996970[127] = 0.0;
   out_22797630451996970[128] = 0.0;
   out_22797630451996970[129] = 0.0;
   out_22797630451996970[130] = 0.0;
   out_22797630451996970[131] = 0.0;
   out_22797630451996970[132] = 0.0;
   out_22797630451996970[133] = 1.0;
   out_22797630451996970[134] = 0.0;
   out_22797630451996970[135] = 0.0;
   out_22797630451996970[136] = 0.0;
   out_22797630451996970[137] = 0.0;
   out_22797630451996970[138] = 0.0;
   out_22797630451996970[139] = 0.0;
   out_22797630451996970[140] = 0.0;
   out_22797630451996970[141] = 0.0;
   out_22797630451996970[142] = 0.0;
   out_22797630451996970[143] = 0.0;
   out_22797630451996970[144] = 0.0;
   out_22797630451996970[145] = 0.0;
   out_22797630451996970[146] = 0.0;
   out_22797630451996970[147] = 0.0;
   out_22797630451996970[148] = 0.0;
   out_22797630451996970[149] = 0.0;
   out_22797630451996970[150] = 0.0;
   out_22797630451996970[151] = 0.0;
   out_22797630451996970[152] = 1.0;
   out_22797630451996970[153] = 0.0;
   out_22797630451996970[154] = 0.0;
   out_22797630451996970[155] = 0.0;
   out_22797630451996970[156] = 0.0;
   out_22797630451996970[157] = 0.0;
   out_22797630451996970[158] = 0.0;
   out_22797630451996970[159] = 0.0;
   out_22797630451996970[160] = 0.0;
   out_22797630451996970[161] = 0.0;
   out_22797630451996970[162] = 0.0;
   out_22797630451996970[163] = 0.0;
   out_22797630451996970[164] = 0.0;
   out_22797630451996970[165] = 0.0;
   out_22797630451996970[166] = 0.0;
   out_22797630451996970[167] = 0.0;
   out_22797630451996970[168] = 0.0;
   out_22797630451996970[169] = 0.0;
   out_22797630451996970[170] = 0.0;
   out_22797630451996970[171] = 1.0;
   out_22797630451996970[172] = 0.0;
   out_22797630451996970[173] = 0.0;
   out_22797630451996970[174] = 0.0;
   out_22797630451996970[175] = 0.0;
   out_22797630451996970[176] = 0.0;
   out_22797630451996970[177] = 0.0;
   out_22797630451996970[178] = 0.0;
   out_22797630451996970[179] = 0.0;
   out_22797630451996970[180] = 0.0;
   out_22797630451996970[181] = 0.0;
   out_22797630451996970[182] = 0.0;
   out_22797630451996970[183] = 0.0;
   out_22797630451996970[184] = 0.0;
   out_22797630451996970[185] = 0.0;
   out_22797630451996970[186] = 0.0;
   out_22797630451996970[187] = 0.0;
   out_22797630451996970[188] = 0.0;
   out_22797630451996970[189] = 0.0;
   out_22797630451996970[190] = 1.0;
   out_22797630451996970[191] = 0.0;
   out_22797630451996970[192] = 0.0;
   out_22797630451996970[193] = 0.0;
   out_22797630451996970[194] = 0.0;
   out_22797630451996970[195] = 0.0;
   out_22797630451996970[196] = 0.0;
   out_22797630451996970[197] = 0.0;
   out_22797630451996970[198] = 0.0;
   out_22797630451996970[199] = 0.0;
   out_22797630451996970[200] = 0.0;
   out_22797630451996970[201] = 0.0;
   out_22797630451996970[202] = 0.0;
   out_22797630451996970[203] = 0.0;
   out_22797630451996970[204] = 0.0;
   out_22797630451996970[205] = 0.0;
   out_22797630451996970[206] = 0.0;
   out_22797630451996970[207] = 0.0;
   out_22797630451996970[208] = 0.0;
   out_22797630451996970[209] = 1.0;
   out_22797630451996970[210] = 0.0;
   out_22797630451996970[211] = 0.0;
   out_22797630451996970[212] = 0.0;
   out_22797630451996970[213] = 0.0;
   out_22797630451996970[214] = 0.0;
   out_22797630451996970[215] = 0.0;
   out_22797630451996970[216] = 0.0;
   out_22797630451996970[217] = 0.0;
   out_22797630451996970[218] = 0.0;
   out_22797630451996970[219] = 0.0;
   out_22797630451996970[220] = 0.0;
   out_22797630451996970[221] = 0.0;
   out_22797630451996970[222] = 0.0;
   out_22797630451996970[223] = 0.0;
   out_22797630451996970[224] = 0.0;
   out_22797630451996970[225] = 0.0;
   out_22797630451996970[226] = 0.0;
   out_22797630451996970[227] = 0.0;
   out_22797630451996970[228] = 1.0;
   out_22797630451996970[229] = 0.0;
   out_22797630451996970[230] = 0.0;
   out_22797630451996970[231] = 0.0;
   out_22797630451996970[232] = 0.0;
   out_22797630451996970[233] = 0.0;
   out_22797630451996970[234] = 0.0;
   out_22797630451996970[235] = 0.0;
   out_22797630451996970[236] = 0.0;
   out_22797630451996970[237] = 0.0;
   out_22797630451996970[238] = 0.0;
   out_22797630451996970[239] = 0.0;
   out_22797630451996970[240] = 0.0;
   out_22797630451996970[241] = 0.0;
   out_22797630451996970[242] = 0.0;
   out_22797630451996970[243] = 0.0;
   out_22797630451996970[244] = 0.0;
   out_22797630451996970[245] = 0.0;
   out_22797630451996970[246] = 0.0;
   out_22797630451996970[247] = 1.0;
   out_22797630451996970[248] = 0.0;
   out_22797630451996970[249] = 0.0;
   out_22797630451996970[250] = 0.0;
   out_22797630451996970[251] = 0.0;
   out_22797630451996970[252] = 0.0;
   out_22797630451996970[253] = 0.0;
   out_22797630451996970[254] = 0.0;
   out_22797630451996970[255] = 0.0;
   out_22797630451996970[256] = 0.0;
   out_22797630451996970[257] = 0.0;
   out_22797630451996970[258] = 0.0;
   out_22797630451996970[259] = 0.0;
   out_22797630451996970[260] = 0.0;
   out_22797630451996970[261] = 0.0;
   out_22797630451996970[262] = 0.0;
   out_22797630451996970[263] = 0.0;
   out_22797630451996970[264] = 0.0;
   out_22797630451996970[265] = 0.0;
   out_22797630451996970[266] = 1.0;
   out_22797630451996970[267] = 0.0;
   out_22797630451996970[268] = 0.0;
   out_22797630451996970[269] = 0.0;
   out_22797630451996970[270] = 0.0;
   out_22797630451996970[271] = 0.0;
   out_22797630451996970[272] = 0.0;
   out_22797630451996970[273] = 0.0;
   out_22797630451996970[274] = 0.0;
   out_22797630451996970[275] = 0.0;
   out_22797630451996970[276] = 0.0;
   out_22797630451996970[277] = 0.0;
   out_22797630451996970[278] = 0.0;
   out_22797630451996970[279] = 0.0;
   out_22797630451996970[280] = 0.0;
   out_22797630451996970[281] = 0.0;
   out_22797630451996970[282] = 0.0;
   out_22797630451996970[283] = 0.0;
   out_22797630451996970[284] = 0.0;
   out_22797630451996970[285] = 1.0;
   out_22797630451996970[286] = 0.0;
   out_22797630451996970[287] = 0.0;
   out_22797630451996970[288] = 0.0;
   out_22797630451996970[289] = 0.0;
   out_22797630451996970[290] = 0.0;
   out_22797630451996970[291] = 0.0;
   out_22797630451996970[292] = 0.0;
   out_22797630451996970[293] = 0.0;
   out_22797630451996970[294] = 0.0;
   out_22797630451996970[295] = 0.0;
   out_22797630451996970[296] = 0.0;
   out_22797630451996970[297] = 0.0;
   out_22797630451996970[298] = 0.0;
   out_22797630451996970[299] = 0.0;
   out_22797630451996970[300] = 0.0;
   out_22797630451996970[301] = 0.0;
   out_22797630451996970[302] = 0.0;
   out_22797630451996970[303] = 0.0;
   out_22797630451996970[304] = 1.0;
   out_22797630451996970[305] = 0.0;
   out_22797630451996970[306] = 0.0;
   out_22797630451996970[307] = 0.0;
   out_22797630451996970[308] = 0.0;
   out_22797630451996970[309] = 0.0;
   out_22797630451996970[310] = 0.0;
   out_22797630451996970[311] = 0.0;
   out_22797630451996970[312] = 0.0;
   out_22797630451996970[313] = 0.0;
   out_22797630451996970[314] = 0.0;
   out_22797630451996970[315] = 0.0;
   out_22797630451996970[316] = 0.0;
   out_22797630451996970[317] = 0.0;
   out_22797630451996970[318] = 0.0;
   out_22797630451996970[319] = 0.0;
   out_22797630451996970[320] = 0.0;
   out_22797630451996970[321] = 0.0;
   out_22797630451996970[322] = 0.0;
   out_22797630451996970[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2362837524605346595) {
   out_2362837524605346595[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2362837524605346595[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2362837524605346595[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2362837524605346595[3] = dt*state[12] + state[3];
   out_2362837524605346595[4] = dt*state[13] + state[4];
   out_2362837524605346595[5] = dt*state[14] + state[5];
   out_2362837524605346595[6] = state[6];
   out_2362837524605346595[7] = state[7];
   out_2362837524605346595[8] = state[8];
   out_2362837524605346595[9] = state[9];
   out_2362837524605346595[10] = state[10];
   out_2362837524605346595[11] = state[11];
   out_2362837524605346595[12] = state[12];
   out_2362837524605346595[13] = state[13];
   out_2362837524605346595[14] = state[14];
   out_2362837524605346595[15] = state[15];
   out_2362837524605346595[16] = state[16];
   out_2362837524605346595[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4166989473592392013) {
   out_4166989473592392013[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4166989473592392013[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4166989473592392013[2] = 0;
   out_4166989473592392013[3] = 0;
   out_4166989473592392013[4] = 0;
   out_4166989473592392013[5] = 0;
   out_4166989473592392013[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4166989473592392013[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4166989473592392013[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4166989473592392013[9] = 0;
   out_4166989473592392013[10] = 0;
   out_4166989473592392013[11] = 0;
   out_4166989473592392013[12] = 0;
   out_4166989473592392013[13] = 0;
   out_4166989473592392013[14] = 0;
   out_4166989473592392013[15] = 0;
   out_4166989473592392013[16] = 0;
   out_4166989473592392013[17] = 0;
   out_4166989473592392013[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4166989473592392013[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4166989473592392013[20] = 0;
   out_4166989473592392013[21] = 0;
   out_4166989473592392013[22] = 0;
   out_4166989473592392013[23] = 0;
   out_4166989473592392013[24] = 0;
   out_4166989473592392013[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4166989473592392013[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4166989473592392013[27] = 0;
   out_4166989473592392013[28] = 0;
   out_4166989473592392013[29] = 0;
   out_4166989473592392013[30] = 0;
   out_4166989473592392013[31] = 0;
   out_4166989473592392013[32] = 0;
   out_4166989473592392013[33] = 0;
   out_4166989473592392013[34] = 0;
   out_4166989473592392013[35] = 0;
   out_4166989473592392013[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4166989473592392013[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4166989473592392013[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4166989473592392013[39] = 0;
   out_4166989473592392013[40] = 0;
   out_4166989473592392013[41] = 0;
   out_4166989473592392013[42] = 0;
   out_4166989473592392013[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4166989473592392013[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4166989473592392013[45] = 0;
   out_4166989473592392013[46] = 0;
   out_4166989473592392013[47] = 0;
   out_4166989473592392013[48] = 0;
   out_4166989473592392013[49] = 0;
   out_4166989473592392013[50] = 0;
   out_4166989473592392013[51] = 0;
   out_4166989473592392013[52] = 0;
   out_4166989473592392013[53] = 0;
   out_4166989473592392013[54] = 0;
   out_4166989473592392013[55] = 0;
   out_4166989473592392013[56] = 0;
   out_4166989473592392013[57] = 1;
   out_4166989473592392013[58] = 0;
   out_4166989473592392013[59] = 0;
   out_4166989473592392013[60] = 0;
   out_4166989473592392013[61] = 0;
   out_4166989473592392013[62] = 0;
   out_4166989473592392013[63] = 0;
   out_4166989473592392013[64] = 0;
   out_4166989473592392013[65] = 0;
   out_4166989473592392013[66] = dt;
   out_4166989473592392013[67] = 0;
   out_4166989473592392013[68] = 0;
   out_4166989473592392013[69] = 0;
   out_4166989473592392013[70] = 0;
   out_4166989473592392013[71] = 0;
   out_4166989473592392013[72] = 0;
   out_4166989473592392013[73] = 0;
   out_4166989473592392013[74] = 0;
   out_4166989473592392013[75] = 0;
   out_4166989473592392013[76] = 1;
   out_4166989473592392013[77] = 0;
   out_4166989473592392013[78] = 0;
   out_4166989473592392013[79] = 0;
   out_4166989473592392013[80] = 0;
   out_4166989473592392013[81] = 0;
   out_4166989473592392013[82] = 0;
   out_4166989473592392013[83] = 0;
   out_4166989473592392013[84] = 0;
   out_4166989473592392013[85] = dt;
   out_4166989473592392013[86] = 0;
   out_4166989473592392013[87] = 0;
   out_4166989473592392013[88] = 0;
   out_4166989473592392013[89] = 0;
   out_4166989473592392013[90] = 0;
   out_4166989473592392013[91] = 0;
   out_4166989473592392013[92] = 0;
   out_4166989473592392013[93] = 0;
   out_4166989473592392013[94] = 0;
   out_4166989473592392013[95] = 1;
   out_4166989473592392013[96] = 0;
   out_4166989473592392013[97] = 0;
   out_4166989473592392013[98] = 0;
   out_4166989473592392013[99] = 0;
   out_4166989473592392013[100] = 0;
   out_4166989473592392013[101] = 0;
   out_4166989473592392013[102] = 0;
   out_4166989473592392013[103] = 0;
   out_4166989473592392013[104] = dt;
   out_4166989473592392013[105] = 0;
   out_4166989473592392013[106] = 0;
   out_4166989473592392013[107] = 0;
   out_4166989473592392013[108] = 0;
   out_4166989473592392013[109] = 0;
   out_4166989473592392013[110] = 0;
   out_4166989473592392013[111] = 0;
   out_4166989473592392013[112] = 0;
   out_4166989473592392013[113] = 0;
   out_4166989473592392013[114] = 1;
   out_4166989473592392013[115] = 0;
   out_4166989473592392013[116] = 0;
   out_4166989473592392013[117] = 0;
   out_4166989473592392013[118] = 0;
   out_4166989473592392013[119] = 0;
   out_4166989473592392013[120] = 0;
   out_4166989473592392013[121] = 0;
   out_4166989473592392013[122] = 0;
   out_4166989473592392013[123] = 0;
   out_4166989473592392013[124] = 0;
   out_4166989473592392013[125] = 0;
   out_4166989473592392013[126] = 0;
   out_4166989473592392013[127] = 0;
   out_4166989473592392013[128] = 0;
   out_4166989473592392013[129] = 0;
   out_4166989473592392013[130] = 0;
   out_4166989473592392013[131] = 0;
   out_4166989473592392013[132] = 0;
   out_4166989473592392013[133] = 1;
   out_4166989473592392013[134] = 0;
   out_4166989473592392013[135] = 0;
   out_4166989473592392013[136] = 0;
   out_4166989473592392013[137] = 0;
   out_4166989473592392013[138] = 0;
   out_4166989473592392013[139] = 0;
   out_4166989473592392013[140] = 0;
   out_4166989473592392013[141] = 0;
   out_4166989473592392013[142] = 0;
   out_4166989473592392013[143] = 0;
   out_4166989473592392013[144] = 0;
   out_4166989473592392013[145] = 0;
   out_4166989473592392013[146] = 0;
   out_4166989473592392013[147] = 0;
   out_4166989473592392013[148] = 0;
   out_4166989473592392013[149] = 0;
   out_4166989473592392013[150] = 0;
   out_4166989473592392013[151] = 0;
   out_4166989473592392013[152] = 1;
   out_4166989473592392013[153] = 0;
   out_4166989473592392013[154] = 0;
   out_4166989473592392013[155] = 0;
   out_4166989473592392013[156] = 0;
   out_4166989473592392013[157] = 0;
   out_4166989473592392013[158] = 0;
   out_4166989473592392013[159] = 0;
   out_4166989473592392013[160] = 0;
   out_4166989473592392013[161] = 0;
   out_4166989473592392013[162] = 0;
   out_4166989473592392013[163] = 0;
   out_4166989473592392013[164] = 0;
   out_4166989473592392013[165] = 0;
   out_4166989473592392013[166] = 0;
   out_4166989473592392013[167] = 0;
   out_4166989473592392013[168] = 0;
   out_4166989473592392013[169] = 0;
   out_4166989473592392013[170] = 0;
   out_4166989473592392013[171] = 1;
   out_4166989473592392013[172] = 0;
   out_4166989473592392013[173] = 0;
   out_4166989473592392013[174] = 0;
   out_4166989473592392013[175] = 0;
   out_4166989473592392013[176] = 0;
   out_4166989473592392013[177] = 0;
   out_4166989473592392013[178] = 0;
   out_4166989473592392013[179] = 0;
   out_4166989473592392013[180] = 0;
   out_4166989473592392013[181] = 0;
   out_4166989473592392013[182] = 0;
   out_4166989473592392013[183] = 0;
   out_4166989473592392013[184] = 0;
   out_4166989473592392013[185] = 0;
   out_4166989473592392013[186] = 0;
   out_4166989473592392013[187] = 0;
   out_4166989473592392013[188] = 0;
   out_4166989473592392013[189] = 0;
   out_4166989473592392013[190] = 1;
   out_4166989473592392013[191] = 0;
   out_4166989473592392013[192] = 0;
   out_4166989473592392013[193] = 0;
   out_4166989473592392013[194] = 0;
   out_4166989473592392013[195] = 0;
   out_4166989473592392013[196] = 0;
   out_4166989473592392013[197] = 0;
   out_4166989473592392013[198] = 0;
   out_4166989473592392013[199] = 0;
   out_4166989473592392013[200] = 0;
   out_4166989473592392013[201] = 0;
   out_4166989473592392013[202] = 0;
   out_4166989473592392013[203] = 0;
   out_4166989473592392013[204] = 0;
   out_4166989473592392013[205] = 0;
   out_4166989473592392013[206] = 0;
   out_4166989473592392013[207] = 0;
   out_4166989473592392013[208] = 0;
   out_4166989473592392013[209] = 1;
   out_4166989473592392013[210] = 0;
   out_4166989473592392013[211] = 0;
   out_4166989473592392013[212] = 0;
   out_4166989473592392013[213] = 0;
   out_4166989473592392013[214] = 0;
   out_4166989473592392013[215] = 0;
   out_4166989473592392013[216] = 0;
   out_4166989473592392013[217] = 0;
   out_4166989473592392013[218] = 0;
   out_4166989473592392013[219] = 0;
   out_4166989473592392013[220] = 0;
   out_4166989473592392013[221] = 0;
   out_4166989473592392013[222] = 0;
   out_4166989473592392013[223] = 0;
   out_4166989473592392013[224] = 0;
   out_4166989473592392013[225] = 0;
   out_4166989473592392013[226] = 0;
   out_4166989473592392013[227] = 0;
   out_4166989473592392013[228] = 1;
   out_4166989473592392013[229] = 0;
   out_4166989473592392013[230] = 0;
   out_4166989473592392013[231] = 0;
   out_4166989473592392013[232] = 0;
   out_4166989473592392013[233] = 0;
   out_4166989473592392013[234] = 0;
   out_4166989473592392013[235] = 0;
   out_4166989473592392013[236] = 0;
   out_4166989473592392013[237] = 0;
   out_4166989473592392013[238] = 0;
   out_4166989473592392013[239] = 0;
   out_4166989473592392013[240] = 0;
   out_4166989473592392013[241] = 0;
   out_4166989473592392013[242] = 0;
   out_4166989473592392013[243] = 0;
   out_4166989473592392013[244] = 0;
   out_4166989473592392013[245] = 0;
   out_4166989473592392013[246] = 0;
   out_4166989473592392013[247] = 1;
   out_4166989473592392013[248] = 0;
   out_4166989473592392013[249] = 0;
   out_4166989473592392013[250] = 0;
   out_4166989473592392013[251] = 0;
   out_4166989473592392013[252] = 0;
   out_4166989473592392013[253] = 0;
   out_4166989473592392013[254] = 0;
   out_4166989473592392013[255] = 0;
   out_4166989473592392013[256] = 0;
   out_4166989473592392013[257] = 0;
   out_4166989473592392013[258] = 0;
   out_4166989473592392013[259] = 0;
   out_4166989473592392013[260] = 0;
   out_4166989473592392013[261] = 0;
   out_4166989473592392013[262] = 0;
   out_4166989473592392013[263] = 0;
   out_4166989473592392013[264] = 0;
   out_4166989473592392013[265] = 0;
   out_4166989473592392013[266] = 1;
   out_4166989473592392013[267] = 0;
   out_4166989473592392013[268] = 0;
   out_4166989473592392013[269] = 0;
   out_4166989473592392013[270] = 0;
   out_4166989473592392013[271] = 0;
   out_4166989473592392013[272] = 0;
   out_4166989473592392013[273] = 0;
   out_4166989473592392013[274] = 0;
   out_4166989473592392013[275] = 0;
   out_4166989473592392013[276] = 0;
   out_4166989473592392013[277] = 0;
   out_4166989473592392013[278] = 0;
   out_4166989473592392013[279] = 0;
   out_4166989473592392013[280] = 0;
   out_4166989473592392013[281] = 0;
   out_4166989473592392013[282] = 0;
   out_4166989473592392013[283] = 0;
   out_4166989473592392013[284] = 0;
   out_4166989473592392013[285] = 1;
   out_4166989473592392013[286] = 0;
   out_4166989473592392013[287] = 0;
   out_4166989473592392013[288] = 0;
   out_4166989473592392013[289] = 0;
   out_4166989473592392013[290] = 0;
   out_4166989473592392013[291] = 0;
   out_4166989473592392013[292] = 0;
   out_4166989473592392013[293] = 0;
   out_4166989473592392013[294] = 0;
   out_4166989473592392013[295] = 0;
   out_4166989473592392013[296] = 0;
   out_4166989473592392013[297] = 0;
   out_4166989473592392013[298] = 0;
   out_4166989473592392013[299] = 0;
   out_4166989473592392013[300] = 0;
   out_4166989473592392013[301] = 0;
   out_4166989473592392013[302] = 0;
   out_4166989473592392013[303] = 0;
   out_4166989473592392013[304] = 1;
   out_4166989473592392013[305] = 0;
   out_4166989473592392013[306] = 0;
   out_4166989473592392013[307] = 0;
   out_4166989473592392013[308] = 0;
   out_4166989473592392013[309] = 0;
   out_4166989473592392013[310] = 0;
   out_4166989473592392013[311] = 0;
   out_4166989473592392013[312] = 0;
   out_4166989473592392013[313] = 0;
   out_4166989473592392013[314] = 0;
   out_4166989473592392013[315] = 0;
   out_4166989473592392013[316] = 0;
   out_4166989473592392013[317] = 0;
   out_4166989473592392013[318] = 0;
   out_4166989473592392013[319] = 0;
   out_4166989473592392013[320] = 0;
   out_4166989473592392013[321] = 0;
   out_4166989473592392013[322] = 0;
   out_4166989473592392013[323] = 1;
}
void h_4(double *state, double *unused, double *out_800785631088066019) {
   out_800785631088066019[0] = state[6] + state[9];
   out_800785631088066019[1] = state[7] + state[10];
   out_800785631088066019[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2555861026626074297) {
   out_2555861026626074297[0] = 0;
   out_2555861026626074297[1] = 0;
   out_2555861026626074297[2] = 0;
   out_2555861026626074297[3] = 0;
   out_2555861026626074297[4] = 0;
   out_2555861026626074297[5] = 0;
   out_2555861026626074297[6] = 1;
   out_2555861026626074297[7] = 0;
   out_2555861026626074297[8] = 0;
   out_2555861026626074297[9] = 1;
   out_2555861026626074297[10] = 0;
   out_2555861026626074297[11] = 0;
   out_2555861026626074297[12] = 0;
   out_2555861026626074297[13] = 0;
   out_2555861026626074297[14] = 0;
   out_2555861026626074297[15] = 0;
   out_2555861026626074297[16] = 0;
   out_2555861026626074297[17] = 0;
   out_2555861026626074297[18] = 0;
   out_2555861026626074297[19] = 0;
   out_2555861026626074297[20] = 0;
   out_2555861026626074297[21] = 0;
   out_2555861026626074297[22] = 0;
   out_2555861026626074297[23] = 0;
   out_2555861026626074297[24] = 0;
   out_2555861026626074297[25] = 1;
   out_2555861026626074297[26] = 0;
   out_2555861026626074297[27] = 0;
   out_2555861026626074297[28] = 1;
   out_2555861026626074297[29] = 0;
   out_2555861026626074297[30] = 0;
   out_2555861026626074297[31] = 0;
   out_2555861026626074297[32] = 0;
   out_2555861026626074297[33] = 0;
   out_2555861026626074297[34] = 0;
   out_2555861026626074297[35] = 0;
   out_2555861026626074297[36] = 0;
   out_2555861026626074297[37] = 0;
   out_2555861026626074297[38] = 0;
   out_2555861026626074297[39] = 0;
   out_2555861026626074297[40] = 0;
   out_2555861026626074297[41] = 0;
   out_2555861026626074297[42] = 0;
   out_2555861026626074297[43] = 0;
   out_2555861026626074297[44] = 1;
   out_2555861026626074297[45] = 0;
   out_2555861026626074297[46] = 0;
   out_2555861026626074297[47] = 1;
   out_2555861026626074297[48] = 0;
   out_2555861026626074297[49] = 0;
   out_2555861026626074297[50] = 0;
   out_2555861026626074297[51] = 0;
   out_2555861026626074297[52] = 0;
   out_2555861026626074297[53] = 0;
}
void h_10(double *state, double *unused, double *out_7585285090603906809) {
   out_7585285090603906809[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7585285090603906809[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7585285090603906809[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6341548427213940478) {
   out_6341548427213940478[0] = 0;
   out_6341548427213940478[1] = 9.8100000000000005*cos(state[1]);
   out_6341548427213940478[2] = 0;
   out_6341548427213940478[3] = 0;
   out_6341548427213940478[4] = -state[8];
   out_6341548427213940478[5] = state[7];
   out_6341548427213940478[6] = 0;
   out_6341548427213940478[7] = state[5];
   out_6341548427213940478[8] = -state[4];
   out_6341548427213940478[9] = 0;
   out_6341548427213940478[10] = 0;
   out_6341548427213940478[11] = 0;
   out_6341548427213940478[12] = 1;
   out_6341548427213940478[13] = 0;
   out_6341548427213940478[14] = 0;
   out_6341548427213940478[15] = 1;
   out_6341548427213940478[16] = 0;
   out_6341548427213940478[17] = 0;
   out_6341548427213940478[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6341548427213940478[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6341548427213940478[20] = 0;
   out_6341548427213940478[21] = state[8];
   out_6341548427213940478[22] = 0;
   out_6341548427213940478[23] = -state[6];
   out_6341548427213940478[24] = -state[5];
   out_6341548427213940478[25] = 0;
   out_6341548427213940478[26] = state[3];
   out_6341548427213940478[27] = 0;
   out_6341548427213940478[28] = 0;
   out_6341548427213940478[29] = 0;
   out_6341548427213940478[30] = 0;
   out_6341548427213940478[31] = 1;
   out_6341548427213940478[32] = 0;
   out_6341548427213940478[33] = 0;
   out_6341548427213940478[34] = 1;
   out_6341548427213940478[35] = 0;
   out_6341548427213940478[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6341548427213940478[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6341548427213940478[38] = 0;
   out_6341548427213940478[39] = -state[7];
   out_6341548427213940478[40] = state[6];
   out_6341548427213940478[41] = 0;
   out_6341548427213940478[42] = state[4];
   out_6341548427213940478[43] = -state[3];
   out_6341548427213940478[44] = 0;
   out_6341548427213940478[45] = 0;
   out_6341548427213940478[46] = 0;
   out_6341548427213940478[47] = 0;
   out_6341548427213940478[48] = 0;
   out_6341548427213940478[49] = 0;
   out_6341548427213940478[50] = 1;
   out_6341548427213940478[51] = 0;
   out_6341548427213940478[52] = 0;
   out_6341548427213940478[53] = 1;
}
void h_13(double *state, double *unused, double *out_7888682643875678910) {
   out_7888682643875678910[0] = state[3];
   out_7888682643875678910[1] = state[4];
   out_7888682643875678910[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5768134851958407098) {
   out_5768134851958407098[0] = 0;
   out_5768134851958407098[1] = 0;
   out_5768134851958407098[2] = 0;
   out_5768134851958407098[3] = 1;
   out_5768134851958407098[4] = 0;
   out_5768134851958407098[5] = 0;
   out_5768134851958407098[6] = 0;
   out_5768134851958407098[7] = 0;
   out_5768134851958407098[8] = 0;
   out_5768134851958407098[9] = 0;
   out_5768134851958407098[10] = 0;
   out_5768134851958407098[11] = 0;
   out_5768134851958407098[12] = 0;
   out_5768134851958407098[13] = 0;
   out_5768134851958407098[14] = 0;
   out_5768134851958407098[15] = 0;
   out_5768134851958407098[16] = 0;
   out_5768134851958407098[17] = 0;
   out_5768134851958407098[18] = 0;
   out_5768134851958407098[19] = 0;
   out_5768134851958407098[20] = 0;
   out_5768134851958407098[21] = 0;
   out_5768134851958407098[22] = 1;
   out_5768134851958407098[23] = 0;
   out_5768134851958407098[24] = 0;
   out_5768134851958407098[25] = 0;
   out_5768134851958407098[26] = 0;
   out_5768134851958407098[27] = 0;
   out_5768134851958407098[28] = 0;
   out_5768134851958407098[29] = 0;
   out_5768134851958407098[30] = 0;
   out_5768134851958407098[31] = 0;
   out_5768134851958407098[32] = 0;
   out_5768134851958407098[33] = 0;
   out_5768134851958407098[34] = 0;
   out_5768134851958407098[35] = 0;
   out_5768134851958407098[36] = 0;
   out_5768134851958407098[37] = 0;
   out_5768134851958407098[38] = 0;
   out_5768134851958407098[39] = 0;
   out_5768134851958407098[40] = 0;
   out_5768134851958407098[41] = 1;
   out_5768134851958407098[42] = 0;
   out_5768134851958407098[43] = 0;
   out_5768134851958407098[44] = 0;
   out_5768134851958407098[45] = 0;
   out_5768134851958407098[46] = 0;
   out_5768134851958407098[47] = 0;
   out_5768134851958407098[48] = 0;
   out_5768134851958407098[49] = 0;
   out_5768134851958407098[50] = 0;
   out_5768134851958407098[51] = 0;
   out_5768134851958407098[52] = 0;
   out_5768134851958407098[53] = 0;
}
void h_14(double *state, double *unused, double *out_3441729687180753414) {
   out_3441729687180753414[0] = state[6];
   out_3441729687180753414[1] = state[7];
   out_3441729687180753414[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4925284788653666127) {
   out_4925284788653666127[0] = 0;
   out_4925284788653666127[1] = 0;
   out_4925284788653666127[2] = 0;
   out_4925284788653666127[3] = 0;
   out_4925284788653666127[4] = 0;
   out_4925284788653666127[5] = 0;
   out_4925284788653666127[6] = 1;
   out_4925284788653666127[7] = 0;
   out_4925284788653666127[8] = 0;
   out_4925284788653666127[9] = 0;
   out_4925284788653666127[10] = 0;
   out_4925284788653666127[11] = 0;
   out_4925284788653666127[12] = 0;
   out_4925284788653666127[13] = 0;
   out_4925284788653666127[14] = 0;
   out_4925284788653666127[15] = 0;
   out_4925284788653666127[16] = 0;
   out_4925284788653666127[17] = 0;
   out_4925284788653666127[18] = 0;
   out_4925284788653666127[19] = 0;
   out_4925284788653666127[20] = 0;
   out_4925284788653666127[21] = 0;
   out_4925284788653666127[22] = 0;
   out_4925284788653666127[23] = 0;
   out_4925284788653666127[24] = 0;
   out_4925284788653666127[25] = 1;
   out_4925284788653666127[26] = 0;
   out_4925284788653666127[27] = 0;
   out_4925284788653666127[28] = 0;
   out_4925284788653666127[29] = 0;
   out_4925284788653666127[30] = 0;
   out_4925284788653666127[31] = 0;
   out_4925284788653666127[32] = 0;
   out_4925284788653666127[33] = 0;
   out_4925284788653666127[34] = 0;
   out_4925284788653666127[35] = 0;
   out_4925284788653666127[36] = 0;
   out_4925284788653666127[37] = 0;
   out_4925284788653666127[38] = 0;
   out_4925284788653666127[39] = 0;
   out_4925284788653666127[40] = 0;
   out_4925284788653666127[41] = 0;
   out_4925284788653666127[42] = 0;
   out_4925284788653666127[43] = 0;
   out_4925284788653666127[44] = 1;
   out_4925284788653666127[45] = 0;
   out_4925284788653666127[46] = 0;
   out_4925284788653666127[47] = 0;
   out_4925284788653666127[48] = 0;
   out_4925284788653666127[49] = 0;
   out_4925284788653666127[50] = 0;
   out_4925284788653666127[51] = 0;
   out_4925284788653666127[52] = 0;
   out_4925284788653666127[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4860250714300227404) {
  err_fun(nom_x, delta_x, out_4860250714300227404);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6437944255548658708) {
  inv_err_fun(nom_x, true_x, out_6437944255548658708);
}
void pose_H_mod_fun(double *state, double *out_22797630451996970) {
  H_mod_fun(state, out_22797630451996970);
}
void pose_f_fun(double *state, double dt, double *out_2362837524605346595) {
  f_fun(state,  dt, out_2362837524605346595);
}
void pose_F_fun(double *state, double dt, double *out_4166989473592392013) {
  F_fun(state,  dt, out_4166989473592392013);
}
void pose_h_4(double *state, double *unused, double *out_800785631088066019) {
  h_4(state, unused, out_800785631088066019);
}
void pose_H_4(double *state, double *unused, double *out_2555861026626074297) {
  H_4(state, unused, out_2555861026626074297);
}
void pose_h_10(double *state, double *unused, double *out_7585285090603906809) {
  h_10(state, unused, out_7585285090603906809);
}
void pose_H_10(double *state, double *unused, double *out_6341548427213940478) {
  H_10(state, unused, out_6341548427213940478);
}
void pose_h_13(double *state, double *unused, double *out_7888682643875678910) {
  h_13(state, unused, out_7888682643875678910);
}
void pose_H_13(double *state, double *unused, double *out_5768134851958407098) {
  H_13(state, unused, out_5768134851958407098);
}
void pose_h_14(double *state, double *unused, double *out_3441729687180753414) {
  h_14(state, unused, out_3441729687180753414);
}
void pose_H_14(double *state, double *unused, double *out_4925284788653666127) {
  H_14(state, unused, out_4925284788653666127);
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
