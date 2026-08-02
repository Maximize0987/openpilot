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
void err_fun(double *nom_x, double *delta_x, double *out_2394949464519988932) {
   out_2394949464519988932[0] = delta_x[0] + nom_x[0];
   out_2394949464519988932[1] = delta_x[1] + nom_x[1];
   out_2394949464519988932[2] = delta_x[2] + nom_x[2];
   out_2394949464519988932[3] = delta_x[3] + nom_x[3];
   out_2394949464519988932[4] = delta_x[4] + nom_x[4];
   out_2394949464519988932[5] = delta_x[5] + nom_x[5];
   out_2394949464519988932[6] = delta_x[6] + nom_x[6];
   out_2394949464519988932[7] = delta_x[7] + nom_x[7];
   out_2394949464519988932[8] = delta_x[8] + nom_x[8];
   out_2394949464519988932[9] = delta_x[9] + nom_x[9];
   out_2394949464519988932[10] = delta_x[10] + nom_x[10];
   out_2394949464519988932[11] = delta_x[11] + nom_x[11];
   out_2394949464519988932[12] = delta_x[12] + nom_x[12];
   out_2394949464519988932[13] = delta_x[13] + nom_x[13];
   out_2394949464519988932[14] = delta_x[14] + nom_x[14];
   out_2394949464519988932[15] = delta_x[15] + nom_x[15];
   out_2394949464519988932[16] = delta_x[16] + nom_x[16];
   out_2394949464519988932[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6906452154256624155) {
   out_6906452154256624155[0] = -nom_x[0] + true_x[0];
   out_6906452154256624155[1] = -nom_x[1] + true_x[1];
   out_6906452154256624155[2] = -nom_x[2] + true_x[2];
   out_6906452154256624155[3] = -nom_x[3] + true_x[3];
   out_6906452154256624155[4] = -nom_x[4] + true_x[4];
   out_6906452154256624155[5] = -nom_x[5] + true_x[5];
   out_6906452154256624155[6] = -nom_x[6] + true_x[6];
   out_6906452154256624155[7] = -nom_x[7] + true_x[7];
   out_6906452154256624155[8] = -nom_x[8] + true_x[8];
   out_6906452154256624155[9] = -nom_x[9] + true_x[9];
   out_6906452154256624155[10] = -nom_x[10] + true_x[10];
   out_6906452154256624155[11] = -nom_x[11] + true_x[11];
   out_6906452154256624155[12] = -nom_x[12] + true_x[12];
   out_6906452154256624155[13] = -nom_x[13] + true_x[13];
   out_6906452154256624155[14] = -nom_x[14] + true_x[14];
   out_6906452154256624155[15] = -nom_x[15] + true_x[15];
   out_6906452154256624155[16] = -nom_x[16] + true_x[16];
   out_6906452154256624155[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4838410850925167920) {
   out_4838410850925167920[0] = 1.0;
   out_4838410850925167920[1] = 0.0;
   out_4838410850925167920[2] = 0.0;
   out_4838410850925167920[3] = 0.0;
   out_4838410850925167920[4] = 0.0;
   out_4838410850925167920[5] = 0.0;
   out_4838410850925167920[6] = 0.0;
   out_4838410850925167920[7] = 0.0;
   out_4838410850925167920[8] = 0.0;
   out_4838410850925167920[9] = 0.0;
   out_4838410850925167920[10] = 0.0;
   out_4838410850925167920[11] = 0.0;
   out_4838410850925167920[12] = 0.0;
   out_4838410850925167920[13] = 0.0;
   out_4838410850925167920[14] = 0.0;
   out_4838410850925167920[15] = 0.0;
   out_4838410850925167920[16] = 0.0;
   out_4838410850925167920[17] = 0.0;
   out_4838410850925167920[18] = 0.0;
   out_4838410850925167920[19] = 1.0;
   out_4838410850925167920[20] = 0.0;
   out_4838410850925167920[21] = 0.0;
   out_4838410850925167920[22] = 0.0;
   out_4838410850925167920[23] = 0.0;
   out_4838410850925167920[24] = 0.0;
   out_4838410850925167920[25] = 0.0;
   out_4838410850925167920[26] = 0.0;
   out_4838410850925167920[27] = 0.0;
   out_4838410850925167920[28] = 0.0;
   out_4838410850925167920[29] = 0.0;
   out_4838410850925167920[30] = 0.0;
   out_4838410850925167920[31] = 0.0;
   out_4838410850925167920[32] = 0.0;
   out_4838410850925167920[33] = 0.0;
   out_4838410850925167920[34] = 0.0;
   out_4838410850925167920[35] = 0.0;
   out_4838410850925167920[36] = 0.0;
   out_4838410850925167920[37] = 0.0;
   out_4838410850925167920[38] = 1.0;
   out_4838410850925167920[39] = 0.0;
   out_4838410850925167920[40] = 0.0;
   out_4838410850925167920[41] = 0.0;
   out_4838410850925167920[42] = 0.0;
   out_4838410850925167920[43] = 0.0;
   out_4838410850925167920[44] = 0.0;
   out_4838410850925167920[45] = 0.0;
   out_4838410850925167920[46] = 0.0;
   out_4838410850925167920[47] = 0.0;
   out_4838410850925167920[48] = 0.0;
   out_4838410850925167920[49] = 0.0;
   out_4838410850925167920[50] = 0.0;
   out_4838410850925167920[51] = 0.0;
   out_4838410850925167920[52] = 0.0;
   out_4838410850925167920[53] = 0.0;
   out_4838410850925167920[54] = 0.0;
   out_4838410850925167920[55] = 0.0;
   out_4838410850925167920[56] = 0.0;
   out_4838410850925167920[57] = 1.0;
   out_4838410850925167920[58] = 0.0;
   out_4838410850925167920[59] = 0.0;
   out_4838410850925167920[60] = 0.0;
   out_4838410850925167920[61] = 0.0;
   out_4838410850925167920[62] = 0.0;
   out_4838410850925167920[63] = 0.0;
   out_4838410850925167920[64] = 0.0;
   out_4838410850925167920[65] = 0.0;
   out_4838410850925167920[66] = 0.0;
   out_4838410850925167920[67] = 0.0;
   out_4838410850925167920[68] = 0.0;
   out_4838410850925167920[69] = 0.0;
   out_4838410850925167920[70] = 0.0;
   out_4838410850925167920[71] = 0.0;
   out_4838410850925167920[72] = 0.0;
   out_4838410850925167920[73] = 0.0;
   out_4838410850925167920[74] = 0.0;
   out_4838410850925167920[75] = 0.0;
   out_4838410850925167920[76] = 1.0;
   out_4838410850925167920[77] = 0.0;
   out_4838410850925167920[78] = 0.0;
   out_4838410850925167920[79] = 0.0;
   out_4838410850925167920[80] = 0.0;
   out_4838410850925167920[81] = 0.0;
   out_4838410850925167920[82] = 0.0;
   out_4838410850925167920[83] = 0.0;
   out_4838410850925167920[84] = 0.0;
   out_4838410850925167920[85] = 0.0;
   out_4838410850925167920[86] = 0.0;
   out_4838410850925167920[87] = 0.0;
   out_4838410850925167920[88] = 0.0;
   out_4838410850925167920[89] = 0.0;
   out_4838410850925167920[90] = 0.0;
   out_4838410850925167920[91] = 0.0;
   out_4838410850925167920[92] = 0.0;
   out_4838410850925167920[93] = 0.0;
   out_4838410850925167920[94] = 0.0;
   out_4838410850925167920[95] = 1.0;
   out_4838410850925167920[96] = 0.0;
   out_4838410850925167920[97] = 0.0;
   out_4838410850925167920[98] = 0.0;
   out_4838410850925167920[99] = 0.0;
   out_4838410850925167920[100] = 0.0;
   out_4838410850925167920[101] = 0.0;
   out_4838410850925167920[102] = 0.0;
   out_4838410850925167920[103] = 0.0;
   out_4838410850925167920[104] = 0.0;
   out_4838410850925167920[105] = 0.0;
   out_4838410850925167920[106] = 0.0;
   out_4838410850925167920[107] = 0.0;
   out_4838410850925167920[108] = 0.0;
   out_4838410850925167920[109] = 0.0;
   out_4838410850925167920[110] = 0.0;
   out_4838410850925167920[111] = 0.0;
   out_4838410850925167920[112] = 0.0;
   out_4838410850925167920[113] = 0.0;
   out_4838410850925167920[114] = 1.0;
   out_4838410850925167920[115] = 0.0;
   out_4838410850925167920[116] = 0.0;
   out_4838410850925167920[117] = 0.0;
   out_4838410850925167920[118] = 0.0;
   out_4838410850925167920[119] = 0.0;
   out_4838410850925167920[120] = 0.0;
   out_4838410850925167920[121] = 0.0;
   out_4838410850925167920[122] = 0.0;
   out_4838410850925167920[123] = 0.0;
   out_4838410850925167920[124] = 0.0;
   out_4838410850925167920[125] = 0.0;
   out_4838410850925167920[126] = 0.0;
   out_4838410850925167920[127] = 0.0;
   out_4838410850925167920[128] = 0.0;
   out_4838410850925167920[129] = 0.0;
   out_4838410850925167920[130] = 0.0;
   out_4838410850925167920[131] = 0.0;
   out_4838410850925167920[132] = 0.0;
   out_4838410850925167920[133] = 1.0;
   out_4838410850925167920[134] = 0.0;
   out_4838410850925167920[135] = 0.0;
   out_4838410850925167920[136] = 0.0;
   out_4838410850925167920[137] = 0.0;
   out_4838410850925167920[138] = 0.0;
   out_4838410850925167920[139] = 0.0;
   out_4838410850925167920[140] = 0.0;
   out_4838410850925167920[141] = 0.0;
   out_4838410850925167920[142] = 0.0;
   out_4838410850925167920[143] = 0.0;
   out_4838410850925167920[144] = 0.0;
   out_4838410850925167920[145] = 0.0;
   out_4838410850925167920[146] = 0.0;
   out_4838410850925167920[147] = 0.0;
   out_4838410850925167920[148] = 0.0;
   out_4838410850925167920[149] = 0.0;
   out_4838410850925167920[150] = 0.0;
   out_4838410850925167920[151] = 0.0;
   out_4838410850925167920[152] = 1.0;
   out_4838410850925167920[153] = 0.0;
   out_4838410850925167920[154] = 0.0;
   out_4838410850925167920[155] = 0.0;
   out_4838410850925167920[156] = 0.0;
   out_4838410850925167920[157] = 0.0;
   out_4838410850925167920[158] = 0.0;
   out_4838410850925167920[159] = 0.0;
   out_4838410850925167920[160] = 0.0;
   out_4838410850925167920[161] = 0.0;
   out_4838410850925167920[162] = 0.0;
   out_4838410850925167920[163] = 0.0;
   out_4838410850925167920[164] = 0.0;
   out_4838410850925167920[165] = 0.0;
   out_4838410850925167920[166] = 0.0;
   out_4838410850925167920[167] = 0.0;
   out_4838410850925167920[168] = 0.0;
   out_4838410850925167920[169] = 0.0;
   out_4838410850925167920[170] = 0.0;
   out_4838410850925167920[171] = 1.0;
   out_4838410850925167920[172] = 0.0;
   out_4838410850925167920[173] = 0.0;
   out_4838410850925167920[174] = 0.0;
   out_4838410850925167920[175] = 0.0;
   out_4838410850925167920[176] = 0.0;
   out_4838410850925167920[177] = 0.0;
   out_4838410850925167920[178] = 0.0;
   out_4838410850925167920[179] = 0.0;
   out_4838410850925167920[180] = 0.0;
   out_4838410850925167920[181] = 0.0;
   out_4838410850925167920[182] = 0.0;
   out_4838410850925167920[183] = 0.0;
   out_4838410850925167920[184] = 0.0;
   out_4838410850925167920[185] = 0.0;
   out_4838410850925167920[186] = 0.0;
   out_4838410850925167920[187] = 0.0;
   out_4838410850925167920[188] = 0.0;
   out_4838410850925167920[189] = 0.0;
   out_4838410850925167920[190] = 1.0;
   out_4838410850925167920[191] = 0.0;
   out_4838410850925167920[192] = 0.0;
   out_4838410850925167920[193] = 0.0;
   out_4838410850925167920[194] = 0.0;
   out_4838410850925167920[195] = 0.0;
   out_4838410850925167920[196] = 0.0;
   out_4838410850925167920[197] = 0.0;
   out_4838410850925167920[198] = 0.0;
   out_4838410850925167920[199] = 0.0;
   out_4838410850925167920[200] = 0.0;
   out_4838410850925167920[201] = 0.0;
   out_4838410850925167920[202] = 0.0;
   out_4838410850925167920[203] = 0.0;
   out_4838410850925167920[204] = 0.0;
   out_4838410850925167920[205] = 0.0;
   out_4838410850925167920[206] = 0.0;
   out_4838410850925167920[207] = 0.0;
   out_4838410850925167920[208] = 0.0;
   out_4838410850925167920[209] = 1.0;
   out_4838410850925167920[210] = 0.0;
   out_4838410850925167920[211] = 0.0;
   out_4838410850925167920[212] = 0.0;
   out_4838410850925167920[213] = 0.0;
   out_4838410850925167920[214] = 0.0;
   out_4838410850925167920[215] = 0.0;
   out_4838410850925167920[216] = 0.0;
   out_4838410850925167920[217] = 0.0;
   out_4838410850925167920[218] = 0.0;
   out_4838410850925167920[219] = 0.0;
   out_4838410850925167920[220] = 0.0;
   out_4838410850925167920[221] = 0.0;
   out_4838410850925167920[222] = 0.0;
   out_4838410850925167920[223] = 0.0;
   out_4838410850925167920[224] = 0.0;
   out_4838410850925167920[225] = 0.0;
   out_4838410850925167920[226] = 0.0;
   out_4838410850925167920[227] = 0.0;
   out_4838410850925167920[228] = 1.0;
   out_4838410850925167920[229] = 0.0;
   out_4838410850925167920[230] = 0.0;
   out_4838410850925167920[231] = 0.0;
   out_4838410850925167920[232] = 0.0;
   out_4838410850925167920[233] = 0.0;
   out_4838410850925167920[234] = 0.0;
   out_4838410850925167920[235] = 0.0;
   out_4838410850925167920[236] = 0.0;
   out_4838410850925167920[237] = 0.0;
   out_4838410850925167920[238] = 0.0;
   out_4838410850925167920[239] = 0.0;
   out_4838410850925167920[240] = 0.0;
   out_4838410850925167920[241] = 0.0;
   out_4838410850925167920[242] = 0.0;
   out_4838410850925167920[243] = 0.0;
   out_4838410850925167920[244] = 0.0;
   out_4838410850925167920[245] = 0.0;
   out_4838410850925167920[246] = 0.0;
   out_4838410850925167920[247] = 1.0;
   out_4838410850925167920[248] = 0.0;
   out_4838410850925167920[249] = 0.0;
   out_4838410850925167920[250] = 0.0;
   out_4838410850925167920[251] = 0.0;
   out_4838410850925167920[252] = 0.0;
   out_4838410850925167920[253] = 0.0;
   out_4838410850925167920[254] = 0.0;
   out_4838410850925167920[255] = 0.0;
   out_4838410850925167920[256] = 0.0;
   out_4838410850925167920[257] = 0.0;
   out_4838410850925167920[258] = 0.0;
   out_4838410850925167920[259] = 0.0;
   out_4838410850925167920[260] = 0.0;
   out_4838410850925167920[261] = 0.0;
   out_4838410850925167920[262] = 0.0;
   out_4838410850925167920[263] = 0.0;
   out_4838410850925167920[264] = 0.0;
   out_4838410850925167920[265] = 0.0;
   out_4838410850925167920[266] = 1.0;
   out_4838410850925167920[267] = 0.0;
   out_4838410850925167920[268] = 0.0;
   out_4838410850925167920[269] = 0.0;
   out_4838410850925167920[270] = 0.0;
   out_4838410850925167920[271] = 0.0;
   out_4838410850925167920[272] = 0.0;
   out_4838410850925167920[273] = 0.0;
   out_4838410850925167920[274] = 0.0;
   out_4838410850925167920[275] = 0.0;
   out_4838410850925167920[276] = 0.0;
   out_4838410850925167920[277] = 0.0;
   out_4838410850925167920[278] = 0.0;
   out_4838410850925167920[279] = 0.0;
   out_4838410850925167920[280] = 0.0;
   out_4838410850925167920[281] = 0.0;
   out_4838410850925167920[282] = 0.0;
   out_4838410850925167920[283] = 0.0;
   out_4838410850925167920[284] = 0.0;
   out_4838410850925167920[285] = 1.0;
   out_4838410850925167920[286] = 0.0;
   out_4838410850925167920[287] = 0.0;
   out_4838410850925167920[288] = 0.0;
   out_4838410850925167920[289] = 0.0;
   out_4838410850925167920[290] = 0.0;
   out_4838410850925167920[291] = 0.0;
   out_4838410850925167920[292] = 0.0;
   out_4838410850925167920[293] = 0.0;
   out_4838410850925167920[294] = 0.0;
   out_4838410850925167920[295] = 0.0;
   out_4838410850925167920[296] = 0.0;
   out_4838410850925167920[297] = 0.0;
   out_4838410850925167920[298] = 0.0;
   out_4838410850925167920[299] = 0.0;
   out_4838410850925167920[300] = 0.0;
   out_4838410850925167920[301] = 0.0;
   out_4838410850925167920[302] = 0.0;
   out_4838410850925167920[303] = 0.0;
   out_4838410850925167920[304] = 1.0;
   out_4838410850925167920[305] = 0.0;
   out_4838410850925167920[306] = 0.0;
   out_4838410850925167920[307] = 0.0;
   out_4838410850925167920[308] = 0.0;
   out_4838410850925167920[309] = 0.0;
   out_4838410850925167920[310] = 0.0;
   out_4838410850925167920[311] = 0.0;
   out_4838410850925167920[312] = 0.0;
   out_4838410850925167920[313] = 0.0;
   out_4838410850925167920[314] = 0.0;
   out_4838410850925167920[315] = 0.0;
   out_4838410850925167920[316] = 0.0;
   out_4838410850925167920[317] = 0.0;
   out_4838410850925167920[318] = 0.0;
   out_4838410850925167920[319] = 0.0;
   out_4838410850925167920[320] = 0.0;
   out_4838410850925167920[321] = 0.0;
   out_4838410850925167920[322] = 0.0;
   out_4838410850925167920[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8751525120696163789) {
   out_8751525120696163789[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8751525120696163789[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8751525120696163789[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8751525120696163789[3] = dt*state[12] + state[3];
   out_8751525120696163789[4] = dt*state[13] + state[4];
   out_8751525120696163789[5] = dt*state[14] + state[5];
   out_8751525120696163789[6] = state[6];
   out_8751525120696163789[7] = state[7];
   out_8751525120696163789[8] = state[8];
   out_8751525120696163789[9] = state[9];
   out_8751525120696163789[10] = state[10];
   out_8751525120696163789[11] = state[11];
   out_8751525120696163789[12] = state[12];
   out_8751525120696163789[13] = state[13];
   out_8751525120696163789[14] = state[14];
   out_8751525120696163789[15] = state[15];
   out_8751525120696163789[16] = state[16];
   out_8751525120696163789[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7175128552495691270) {
   out_7175128552495691270[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7175128552495691270[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7175128552495691270[2] = 0;
   out_7175128552495691270[3] = 0;
   out_7175128552495691270[4] = 0;
   out_7175128552495691270[5] = 0;
   out_7175128552495691270[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7175128552495691270[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7175128552495691270[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7175128552495691270[9] = 0;
   out_7175128552495691270[10] = 0;
   out_7175128552495691270[11] = 0;
   out_7175128552495691270[12] = 0;
   out_7175128552495691270[13] = 0;
   out_7175128552495691270[14] = 0;
   out_7175128552495691270[15] = 0;
   out_7175128552495691270[16] = 0;
   out_7175128552495691270[17] = 0;
   out_7175128552495691270[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7175128552495691270[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7175128552495691270[20] = 0;
   out_7175128552495691270[21] = 0;
   out_7175128552495691270[22] = 0;
   out_7175128552495691270[23] = 0;
   out_7175128552495691270[24] = 0;
   out_7175128552495691270[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7175128552495691270[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7175128552495691270[27] = 0;
   out_7175128552495691270[28] = 0;
   out_7175128552495691270[29] = 0;
   out_7175128552495691270[30] = 0;
   out_7175128552495691270[31] = 0;
   out_7175128552495691270[32] = 0;
   out_7175128552495691270[33] = 0;
   out_7175128552495691270[34] = 0;
   out_7175128552495691270[35] = 0;
   out_7175128552495691270[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7175128552495691270[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7175128552495691270[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7175128552495691270[39] = 0;
   out_7175128552495691270[40] = 0;
   out_7175128552495691270[41] = 0;
   out_7175128552495691270[42] = 0;
   out_7175128552495691270[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7175128552495691270[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7175128552495691270[45] = 0;
   out_7175128552495691270[46] = 0;
   out_7175128552495691270[47] = 0;
   out_7175128552495691270[48] = 0;
   out_7175128552495691270[49] = 0;
   out_7175128552495691270[50] = 0;
   out_7175128552495691270[51] = 0;
   out_7175128552495691270[52] = 0;
   out_7175128552495691270[53] = 0;
   out_7175128552495691270[54] = 0;
   out_7175128552495691270[55] = 0;
   out_7175128552495691270[56] = 0;
   out_7175128552495691270[57] = 1;
   out_7175128552495691270[58] = 0;
   out_7175128552495691270[59] = 0;
   out_7175128552495691270[60] = 0;
   out_7175128552495691270[61] = 0;
   out_7175128552495691270[62] = 0;
   out_7175128552495691270[63] = 0;
   out_7175128552495691270[64] = 0;
   out_7175128552495691270[65] = 0;
   out_7175128552495691270[66] = dt;
   out_7175128552495691270[67] = 0;
   out_7175128552495691270[68] = 0;
   out_7175128552495691270[69] = 0;
   out_7175128552495691270[70] = 0;
   out_7175128552495691270[71] = 0;
   out_7175128552495691270[72] = 0;
   out_7175128552495691270[73] = 0;
   out_7175128552495691270[74] = 0;
   out_7175128552495691270[75] = 0;
   out_7175128552495691270[76] = 1;
   out_7175128552495691270[77] = 0;
   out_7175128552495691270[78] = 0;
   out_7175128552495691270[79] = 0;
   out_7175128552495691270[80] = 0;
   out_7175128552495691270[81] = 0;
   out_7175128552495691270[82] = 0;
   out_7175128552495691270[83] = 0;
   out_7175128552495691270[84] = 0;
   out_7175128552495691270[85] = dt;
   out_7175128552495691270[86] = 0;
   out_7175128552495691270[87] = 0;
   out_7175128552495691270[88] = 0;
   out_7175128552495691270[89] = 0;
   out_7175128552495691270[90] = 0;
   out_7175128552495691270[91] = 0;
   out_7175128552495691270[92] = 0;
   out_7175128552495691270[93] = 0;
   out_7175128552495691270[94] = 0;
   out_7175128552495691270[95] = 1;
   out_7175128552495691270[96] = 0;
   out_7175128552495691270[97] = 0;
   out_7175128552495691270[98] = 0;
   out_7175128552495691270[99] = 0;
   out_7175128552495691270[100] = 0;
   out_7175128552495691270[101] = 0;
   out_7175128552495691270[102] = 0;
   out_7175128552495691270[103] = 0;
   out_7175128552495691270[104] = dt;
   out_7175128552495691270[105] = 0;
   out_7175128552495691270[106] = 0;
   out_7175128552495691270[107] = 0;
   out_7175128552495691270[108] = 0;
   out_7175128552495691270[109] = 0;
   out_7175128552495691270[110] = 0;
   out_7175128552495691270[111] = 0;
   out_7175128552495691270[112] = 0;
   out_7175128552495691270[113] = 0;
   out_7175128552495691270[114] = 1;
   out_7175128552495691270[115] = 0;
   out_7175128552495691270[116] = 0;
   out_7175128552495691270[117] = 0;
   out_7175128552495691270[118] = 0;
   out_7175128552495691270[119] = 0;
   out_7175128552495691270[120] = 0;
   out_7175128552495691270[121] = 0;
   out_7175128552495691270[122] = 0;
   out_7175128552495691270[123] = 0;
   out_7175128552495691270[124] = 0;
   out_7175128552495691270[125] = 0;
   out_7175128552495691270[126] = 0;
   out_7175128552495691270[127] = 0;
   out_7175128552495691270[128] = 0;
   out_7175128552495691270[129] = 0;
   out_7175128552495691270[130] = 0;
   out_7175128552495691270[131] = 0;
   out_7175128552495691270[132] = 0;
   out_7175128552495691270[133] = 1;
   out_7175128552495691270[134] = 0;
   out_7175128552495691270[135] = 0;
   out_7175128552495691270[136] = 0;
   out_7175128552495691270[137] = 0;
   out_7175128552495691270[138] = 0;
   out_7175128552495691270[139] = 0;
   out_7175128552495691270[140] = 0;
   out_7175128552495691270[141] = 0;
   out_7175128552495691270[142] = 0;
   out_7175128552495691270[143] = 0;
   out_7175128552495691270[144] = 0;
   out_7175128552495691270[145] = 0;
   out_7175128552495691270[146] = 0;
   out_7175128552495691270[147] = 0;
   out_7175128552495691270[148] = 0;
   out_7175128552495691270[149] = 0;
   out_7175128552495691270[150] = 0;
   out_7175128552495691270[151] = 0;
   out_7175128552495691270[152] = 1;
   out_7175128552495691270[153] = 0;
   out_7175128552495691270[154] = 0;
   out_7175128552495691270[155] = 0;
   out_7175128552495691270[156] = 0;
   out_7175128552495691270[157] = 0;
   out_7175128552495691270[158] = 0;
   out_7175128552495691270[159] = 0;
   out_7175128552495691270[160] = 0;
   out_7175128552495691270[161] = 0;
   out_7175128552495691270[162] = 0;
   out_7175128552495691270[163] = 0;
   out_7175128552495691270[164] = 0;
   out_7175128552495691270[165] = 0;
   out_7175128552495691270[166] = 0;
   out_7175128552495691270[167] = 0;
   out_7175128552495691270[168] = 0;
   out_7175128552495691270[169] = 0;
   out_7175128552495691270[170] = 0;
   out_7175128552495691270[171] = 1;
   out_7175128552495691270[172] = 0;
   out_7175128552495691270[173] = 0;
   out_7175128552495691270[174] = 0;
   out_7175128552495691270[175] = 0;
   out_7175128552495691270[176] = 0;
   out_7175128552495691270[177] = 0;
   out_7175128552495691270[178] = 0;
   out_7175128552495691270[179] = 0;
   out_7175128552495691270[180] = 0;
   out_7175128552495691270[181] = 0;
   out_7175128552495691270[182] = 0;
   out_7175128552495691270[183] = 0;
   out_7175128552495691270[184] = 0;
   out_7175128552495691270[185] = 0;
   out_7175128552495691270[186] = 0;
   out_7175128552495691270[187] = 0;
   out_7175128552495691270[188] = 0;
   out_7175128552495691270[189] = 0;
   out_7175128552495691270[190] = 1;
   out_7175128552495691270[191] = 0;
   out_7175128552495691270[192] = 0;
   out_7175128552495691270[193] = 0;
   out_7175128552495691270[194] = 0;
   out_7175128552495691270[195] = 0;
   out_7175128552495691270[196] = 0;
   out_7175128552495691270[197] = 0;
   out_7175128552495691270[198] = 0;
   out_7175128552495691270[199] = 0;
   out_7175128552495691270[200] = 0;
   out_7175128552495691270[201] = 0;
   out_7175128552495691270[202] = 0;
   out_7175128552495691270[203] = 0;
   out_7175128552495691270[204] = 0;
   out_7175128552495691270[205] = 0;
   out_7175128552495691270[206] = 0;
   out_7175128552495691270[207] = 0;
   out_7175128552495691270[208] = 0;
   out_7175128552495691270[209] = 1;
   out_7175128552495691270[210] = 0;
   out_7175128552495691270[211] = 0;
   out_7175128552495691270[212] = 0;
   out_7175128552495691270[213] = 0;
   out_7175128552495691270[214] = 0;
   out_7175128552495691270[215] = 0;
   out_7175128552495691270[216] = 0;
   out_7175128552495691270[217] = 0;
   out_7175128552495691270[218] = 0;
   out_7175128552495691270[219] = 0;
   out_7175128552495691270[220] = 0;
   out_7175128552495691270[221] = 0;
   out_7175128552495691270[222] = 0;
   out_7175128552495691270[223] = 0;
   out_7175128552495691270[224] = 0;
   out_7175128552495691270[225] = 0;
   out_7175128552495691270[226] = 0;
   out_7175128552495691270[227] = 0;
   out_7175128552495691270[228] = 1;
   out_7175128552495691270[229] = 0;
   out_7175128552495691270[230] = 0;
   out_7175128552495691270[231] = 0;
   out_7175128552495691270[232] = 0;
   out_7175128552495691270[233] = 0;
   out_7175128552495691270[234] = 0;
   out_7175128552495691270[235] = 0;
   out_7175128552495691270[236] = 0;
   out_7175128552495691270[237] = 0;
   out_7175128552495691270[238] = 0;
   out_7175128552495691270[239] = 0;
   out_7175128552495691270[240] = 0;
   out_7175128552495691270[241] = 0;
   out_7175128552495691270[242] = 0;
   out_7175128552495691270[243] = 0;
   out_7175128552495691270[244] = 0;
   out_7175128552495691270[245] = 0;
   out_7175128552495691270[246] = 0;
   out_7175128552495691270[247] = 1;
   out_7175128552495691270[248] = 0;
   out_7175128552495691270[249] = 0;
   out_7175128552495691270[250] = 0;
   out_7175128552495691270[251] = 0;
   out_7175128552495691270[252] = 0;
   out_7175128552495691270[253] = 0;
   out_7175128552495691270[254] = 0;
   out_7175128552495691270[255] = 0;
   out_7175128552495691270[256] = 0;
   out_7175128552495691270[257] = 0;
   out_7175128552495691270[258] = 0;
   out_7175128552495691270[259] = 0;
   out_7175128552495691270[260] = 0;
   out_7175128552495691270[261] = 0;
   out_7175128552495691270[262] = 0;
   out_7175128552495691270[263] = 0;
   out_7175128552495691270[264] = 0;
   out_7175128552495691270[265] = 0;
   out_7175128552495691270[266] = 1;
   out_7175128552495691270[267] = 0;
   out_7175128552495691270[268] = 0;
   out_7175128552495691270[269] = 0;
   out_7175128552495691270[270] = 0;
   out_7175128552495691270[271] = 0;
   out_7175128552495691270[272] = 0;
   out_7175128552495691270[273] = 0;
   out_7175128552495691270[274] = 0;
   out_7175128552495691270[275] = 0;
   out_7175128552495691270[276] = 0;
   out_7175128552495691270[277] = 0;
   out_7175128552495691270[278] = 0;
   out_7175128552495691270[279] = 0;
   out_7175128552495691270[280] = 0;
   out_7175128552495691270[281] = 0;
   out_7175128552495691270[282] = 0;
   out_7175128552495691270[283] = 0;
   out_7175128552495691270[284] = 0;
   out_7175128552495691270[285] = 1;
   out_7175128552495691270[286] = 0;
   out_7175128552495691270[287] = 0;
   out_7175128552495691270[288] = 0;
   out_7175128552495691270[289] = 0;
   out_7175128552495691270[290] = 0;
   out_7175128552495691270[291] = 0;
   out_7175128552495691270[292] = 0;
   out_7175128552495691270[293] = 0;
   out_7175128552495691270[294] = 0;
   out_7175128552495691270[295] = 0;
   out_7175128552495691270[296] = 0;
   out_7175128552495691270[297] = 0;
   out_7175128552495691270[298] = 0;
   out_7175128552495691270[299] = 0;
   out_7175128552495691270[300] = 0;
   out_7175128552495691270[301] = 0;
   out_7175128552495691270[302] = 0;
   out_7175128552495691270[303] = 0;
   out_7175128552495691270[304] = 1;
   out_7175128552495691270[305] = 0;
   out_7175128552495691270[306] = 0;
   out_7175128552495691270[307] = 0;
   out_7175128552495691270[308] = 0;
   out_7175128552495691270[309] = 0;
   out_7175128552495691270[310] = 0;
   out_7175128552495691270[311] = 0;
   out_7175128552495691270[312] = 0;
   out_7175128552495691270[313] = 0;
   out_7175128552495691270[314] = 0;
   out_7175128552495691270[315] = 0;
   out_7175128552495691270[316] = 0;
   out_7175128552495691270[317] = 0;
   out_7175128552495691270[318] = 0;
   out_7175128552495691270[319] = 0;
   out_7175128552495691270[320] = 0;
   out_7175128552495691270[321] = 0;
   out_7175128552495691270[322] = 0;
   out_7175128552495691270[323] = 1;
}
void h_4(double *state, double *unused, double *out_1724585592717515492) {
   out_1724585592717515492[0] = state[6] + state[9];
   out_1724585592717515492[1] = state[7] + state[10];
   out_1724585592717515492[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3018712125018871059) {
   out_3018712125018871059[0] = 0;
   out_3018712125018871059[1] = 0;
   out_3018712125018871059[2] = 0;
   out_3018712125018871059[3] = 0;
   out_3018712125018871059[4] = 0;
   out_3018712125018871059[5] = 0;
   out_3018712125018871059[6] = 1;
   out_3018712125018871059[7] = 0;
   out_3018712125018871059[8] = 0;
   out_3018712125018871059[9] = 1;
   out_3018712125018871059[10] = 0;
   out_3018712125018871059[11] = 0;
   out_3018712125018871059[12] = 0;
   out_3018712125018871059[13] = 0;
   out_3018712125018871059[14] = 0;
   out_3018712125018871059[15] = 0;
   out_3018712125018871059[16] = 0;
   out_3018712125018871059[17] = 0;
   out_3018712125018871059[18] = 0;
   out_3018712125018871059[19] = 0;
   out_3018712125018871059[20] = 0;
   out_3018712125018871059[21] = 0;
   out_3018712125018871059[22] = 0;
   out_3018712125018871059[23] = 0;
   out_3018712125018871059[24] = 0;
   out_3018712125018871059[25] = 1;
   out_3018712125018871059[26] = 0;
   out_3018712125018871059[27] = 0;
   out_3018712125018871059[28] = 1;
   out_3018712125018871059[29] = 0;
   out_3018712125018871059[30] = 0;
   out_3018712125018871059[31] = 0;
   out_3018712125018871059[32] = 0;
   out_3018712125018871059[33] = 0;
   out_3018712125018871059[34] = 0;
   out_3018712125018871059[35] = 0;
   out_3018712125018871059[36] = 0;
   out_3018712125018871059[37] = 0;
   out_3018712125018871059[38] = 0;
   out_3018712125018871059[39] = 0;
   out_3018712125018871059[40] = 0;
   out_3018712125018871059[41] = 0;
   out_3018712125018871059[42] = 0;
   out_3018712125018871059[43] = 0;
   out_3018712125018871059[44] = 1;
   out_3018712125018871059[45] = 0;
   out_3018712125018871059[46] = 0;
   out_3018712125018871059[47] = 1;
   out_3018712125018871059[48] = 0;
   out_3018712125018871059[49] = 0;
   out_3018712125018871059[50] = 0;
   out_3018712125018871059[51] = 0;
   out_3018712125018871059[52] = 0;
   out_3018712125018871059[53] = 0;
}
void h_10(double *state, double *unused, double *out_1452906161636095115) {
   out_1452906161636095115[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1452906161636095115[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1452906161636095115[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3099904708442444122) {
   out_3099904708442444122[0] = 0;
   out_3099904708442444122[1] = 9.8100000000000005*cos(state[1]);
   out_3099904708442444122[2] = 0;
   out_3099904708442444122[3] = 0;
   out_3099904708442444122[4] = -state[8];
   out_3099904708442444122[5] = state[7];
   out_3099904708442444122[6] = 0;
   out_3099904708442444122[7] = state[5];
   out_3099904708442444122[8] = -state[4];
   out_3099904708442444122[9] = 0;
   out_3099904708442444122[10] = 0;
   out_3099904708442444122[11] = 0;
   out_3099904708442444122[12] = 1;
   out_3099904708442444122[13] = 0;
   out_3099904708442444122[14] = 0;
   out_3099904708442444122[15] = 1;
   out_3099904708442444122[16] = 0;
   out_3099904708442444122[17] = 0;
   out_3099904708442444122[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3099904708442444122[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3099904708442444122[20] = 0;
   out_3099904708442444122[21] = state[8];
   out_3099904708442444122[22] = 0;
   out_3099904708442444122[23] = -state[6];
   out_3099904708442444122[24] = -state[5];
   out_3099904708442444122[25] = 0;
   out_3099904708442444122[26] = state[3];
   out_3099904708442444122[27] = 0;
   out_3099904708442444122[28] = 0;
   out_3099904708442444122[29] = 0;
   out_3099904708442444122[30] = 0;
   out_3099904708442444122[31] = 1;
   out_3099904708442444122[32] = 0;
   out_3099904708442444122[33] = 0;
   out_3099904708442444122[34] = 1;
   out_3099904708442444122[35] = 0;
   out_3099904708442444122[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3099904708442444122[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3099904708442444122[38] = 0;
   out_3099904708442444122[39] = -state[7];
   out_3099904708442444122[40] = state[6];
   out_3099904708442444122[41] = 0;
   out_3099904708442444122[42] = state[4];
   out_3099904708442444122[43] = -state[3];
   out_3099904708442444122[44] = 0;
   out_3099904708442444122[45] = 0;
   out_3099904708442444122[46] = 0;
   out_3099904708442444122[47] = 0;
   out_3099904708442444122[48] = 0;
   out_3099904708442444122[49] = 0;
   out_3099904708442444122[50] = 1;
   out_3099904708442444122[51] = 0;
   out_3099904708442444122[52] = 0;
   out_3099904708442444122[53] = 1;
}
void h_13(double *state, double *unused, double *out_7528264878139249656) {
   out_7528264878139249656[0] = state[3];
   out_7528264878139249656[1] = state[4];
   out_7528264878139249656[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3583314044700715163) {
   out_3583314044700715163[0] = 0;
   out_3583314044700715163[1] = 0;
   out_3583314044700715163[2] = 0;
   out_3583314044700715163[3] = 1;
   out_3583314044700715163[4] = 0;
   out_3583314044700715163[5] = 0;
   out_3583314044700715163[6] = 0;
   out_3583314044700715163[7] = 0;
   out_3583314044700715163[8] = 0;
   out_3583314044700715163[9] = 0;
   out_3583314044700715163[10] = 0;
   out_3583314044700715163[11] = 0;
   out_3583314044700715163[12] = 0;
   out_3583314044700715163[13] = 0;
   out_3583314044700715163[14] = 0;
   out_3583314044700715163[15] = 0;
   out_3583314044700715163[16] = 0;
   out_3583314044700715163[17] = 0;
   out_3583314044700715163[18] = 0;
   out_3583314044700715163[19] = 0;
   out_3583314044700715163[20] = 0;
   out_3583314044700715163[21] = 0;
   out_3583314044700715163[22] = 1;
   out_3583314044700715163[23] = 0;
   out_3583314044700715163[24] = 0;
   out_3583314044700715163[25] = 0;
   out_3583314044700715163[26] = 0;
   out_3583314044700715163[27] = 0;
   out_3583314044700715163[28] = 0;
   out_3583314044700715163[29] = 0;
   out_3583314044700715163[30] = 0;
   out_3583314044700715163[31] = 0;
   out_3583314044700715163[32] = 0;
   out_3583314044700715163[33] = 0;
   out_3583314044700715163[34] = 0;
   out_3583314044700715163[35] = 0;
   out_3583314044700715163[36] = 0;
   out_3583314044700715163[37] = 0;
   out_3583314044700715163[38] = 0;
   out_3583314044700715163[39] = 0;
   out_3583314044700715163[40] = 0;
   out_3583314044700715163[41] = 1;
   out_3583314044700715163[42] = 0;
   out_3583314044700715163[43] = 0;
   out_3583314044700715163[44] = 0;
   out_3583314044700715163[45] = 0;
   out_3583314044700715163[46] = 0;
   out_3583314044700715163[47] = 0;
   out_3583314044700715163[48] = 0;
   out_3583314044700715163[49] = 0;
   out_3583314044700715163[50] = 0;
   out_3583314044700715163[51] = 0;
   out_3583314044700715163[52] = 0;
   out_3583314044700715163[53] = 0;
}
void h_14(double *state, double *unused, double *out_4413124467477602634) {
   out_4413124467477602634[0] = state[6];
   out_4413124467477602634[1] = state[7];
   out_4413124467477602634[2] = state[8];
}
void H_14(double *state, double *unused, double *out_64076307276501237) {
   out_64076307276501237[0] = 0;
   out_64076307276501237[1] = 0;
   out_64076307276501237[2] = 0;
   out_64076307276501237[3] = 0;
   out_64076307276501237[4] = 0;
   out_64076307276501237[5] = 0;
   out_64076307276501237[6] = 1;
   out_64076307276501237[7] = 0;
   out_64076307276501237[8] = 0;
   out_64076307276501237[9] = 0;
   out_64076307276501237[10] = 0;
   out_64076307276501237[11] = 0;
   out_64076307276501237[12] = 0;
   out_64076307276501237[13] = 0;
   out_64076307276501237[14] = 0;
   out_64076307276501237[15] = 0;
   out_64076307276501237[16] = 0;
   out_64076307276501237[17] = 0;
   out_64076307276501237[18] = 0;
   out_64076307276501237[19] = 0;
   out_64076307276501237[20] = 0;
   out_64076307276501237[21] = 0;
   out_64076307276501237[22] = 0;
   out_64076307276501237[23] = 0;
   out_64076307276501237[24] = 0;
   out_64076307276501237[25] = 1;
   out_64076307276501237[26] = 0;
   out_64076307276501237[27] = 0;
   out_64076307276501237[28] = 0;
   out_64076307276501237[29] = 0;
   out_64076307276501237[30] = 0;
   out_64076307276501237[31] = 0;
   out_64076307276501237[32] = 0;
   out_64076307276501237[33] = 0;
   out_64076307276501237[34] = 0;
   out_64076307276501237[35] = 0;
   out_64076307276501237[36] = 0;
   out_64076307276501237[37] = 0;
   out_64076307276501237[38] = 0;
   out_64076307276501237[39] = 0;
   out_64076307276501237[40] = 0;
   out_64076307276501237[41] = 0;
   out_64076307276501237[42] = 0;
   out_64076307276501237[43] = 0;
   out_64076307276501237[44] = 1;
   out_64076307276501237[45] = 0;
   out_64076307276501237[46] = 0;
   out_64076307276501237[47] = 0;
   out_64076307276501237[48] = 0;
   out_64076307276501237[49] = 0;
   out_64076307276501237[50] = 0;
   out_64076307276501237[51] = 0;
   out_64076307276501237[52] = 0;
   out_64076307276501237[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2394949464519988932) {
  err_fun(nom_x, delta_x, out_2394949464519988932);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6906452154256624155) {
  inv_err_fun(nom_x, true_x, out_6906452154256624155);
}
void pose_H_mod_fun(double *state, double *out_4838410850925167920) {
  H_mod_fun(state, out_4838410850925167920);
}
void pose_f_fun(double *state, double dt, double *out_8751525120696163789) {
  f_fun(state,  dt, out_8751525120696163789);
}
void pose_F_fun(double *state, double dt, double *out_7175128552495691270) {
  F_fun(state,  dt, out_7175128552495691270);
}
void pose_h_4(double *state, double *unused, double *out_1724585592717515492) {
  h_4(state, unused, out_1724585592717515492);
}
void pose_H_4(double *state, double *unused, double *out_3018712125018871059) {
  H_4(state, unused, out_3018712125018871059);
}
void pose_h_10(double *state, double *unused, double *out_1452906161636095115) {
  h_10(state, unused, out_1452906161636095115);
}
void pose_H_10(double *state, double *unused, double *out_3099904708442444122) {
  H_10(state, unused, out_3099904708442444122);
}
void pose_h_13(double *state, double *unused, double *out_7528264878139249656) {
  h_13(state, unused, out_7528264878139249656);
}
void pose_H_13(double *state, double *unused, double *out_3583314044700715163) {
  H_13(state, unused, out_3583314044700715163);
}
void pose_h_14(double *state, double *unused, double *out_4413124467477602634) {
  h_14(state, unused, out_4413124467477602634);
}
void pose_H_14(double *state, double *unused, double *out_64076307276501237) {
  H_14(state, unused, out_64076307276501237);
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
