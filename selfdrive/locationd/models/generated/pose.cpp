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
void err_fun(double *nom_x, double *delta_x, double *out_7746602045410251207) {
   out_7746602045410251207[0] = delta_x[0] + nom_x[0];
   out_7746602045410251207[1] = delta_x[1] + nom_x[1];
   out_7746602045410251207[2] = delta_x[2] + nom_x[2];
   out_7746602045410251207[3] = delta_x[3] + nom_x[3];
   out_7746602045410251207[4] = delta_x[4] + nom_x[4];
   out_7746602045410251207[5] = delta_x[5] + nom_x[5];
   out_7746602045410251207[6] = delta_x[6] + nom_x[6];
   out_7746602045410251207[7] = delta_x[7] + nom_x[7];
   out_7746602045410251207[8] = delta_x[8] + nom_x[8];
   out_7746602045410251207[9] = delta_x[9] + nom_x[9];
   out_7746602045410251207[10] = delta_x[10] + nom_x[10];
   out_7746602045410251207[11] = delta_x[11] + nom_x[11];
   out_7746602045410251207[12] = delta_x[12] + nom_x[12];
   out_7746602045410251207[13] = delta_x[13] + nom_x[13];
   out_7746602045410251207[14] = delta_x[14] + nom_x[14];
   out_7746602045410251207[15] = delta_x[15] + nom_x[15];
   out_7746602045410251207[16] = delta_x[16] + nom_x[16];
   out_7746602045410251207[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7631524114608656485) {
   out_7631524114608656485[0] = -nom_x[0] + true_x[0];
   out_7631524114608656485[1] = -nom_x[1] + true_x[1];
   out_7631524114608656485[2] = -nom_x[2] + true_x[2];
   out_7631524114608656485[3] = -nom_x[3] + true_x[3];
   out_7631524114608656485[4] = -nom_x[4] + true_x[4];
   out_7631524114608656485[5] = -nom_x[5] + true_x[5];
   out_7631524114608656485[6] = -nom_x[6] + true_x[6];
   out_7631524114608656485[7] = -nom_x[7] + true_x[7];
   out_7631524114608656485[8] = -nom_x[8] + true_x[8];
   out_7631524114608656485[9] = -nom_x[9] + true_x[9];
   out_7631524114608656485[10] = -nom_x[10] + true_x[10];
   out_7631524114608656485[11] = -nom_x[11] + true_x[11];
   out_7631524114608656485[12] = -nom_x[12] + true_x[12];
   out_7631524114608656485[13] = -nom_x[13] + true_x[13];
   out_7631524114608656485[14] = -nom_x[14] + true_x[14];
   out_7631524114608656485[15] = -nom_x[15] + true_x[15];
   out_7631524114608656485[16] = -nom_x[16] + true_x[16];
   out_7631524114608656485[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_506241675272442753) {
   out_506241675272442753[0] = 1.0;
   out_506241675272442753[1] = 0.0;
   out_506241675272442753[2] = 0.0;
   out_506241675272442753[3] = 0.0;
   out_506241675272442753[4] = 0.0;
   out_506241675272442753[5] = 0.0;
   out_506241675272442753[6] = 0.0;
   out_506241675272442753[7] = 0.0;
   out_506241675272442753[8] = 0.0;
   out_506241675272442753[9] = 0.0;
   out_506241675272442753[10] = 0.0;
   out_506241675272442753[11] = 0.0;
   out_506241675272442753[12] = 0.0;
   out_506241675272442753[13] = 0.0;
   out_506241675272442753[14] = 0.0;
   out_506241675272442753[15] = 0.0;
   out_506241675272442753[16] = 0.0;
   out_506241675272442753[17] = 0.0;
   out_506241675272442753[18] = 0.0;
   out_506241675272442753[19] = 1.0;
   out_506241675272442753[20] = 0.0;
   out_506241675272442753[21] = 0.0;
   out_506241675272442753[22] = 0.0;
   out_506241675272442753[23] = 0.0;
   out_506241675272442753[24] = 0.0;
   out_506241675272442753[25] = 0.0;
   out_506241675272442753[26] = 0.0;
   out_506241675272442753[27] = 0.0;
   out_506241675272442753[28] = 0.0;
   out_506241675272442753[29] = 0.0;
   out_506241675272442753[30] = 0.0;
   out_506241675272442753[31] = 0.0;
   out_506241675272442753[32] = 0.0;
   out_506241675272442753[33] = 0.0;
   out_506241675272442753[34] = 0.0;
   out_506241675272442753[35] = 0.0;
   out_506241675272442753[36] = 0.0;
   out_506241675272442753[37] = 0.0;
   out_506241675272442753[38] = 1.0;
   out_506241675272442753[39] = 0.0;
   out_506241675272442753[40] = 0.0;
   out_506241675272442753[41] = 0.0;
   out_506241675272442753[42] = 0.0;
   out_506241675272442753[43] = 0.0;
   out_506241675272442753[44] = 0.0;
   out_506241675272442753[45] = 0.0;
   out_506241675272442753[46] = 0.0;
   out_506241675272442753[47] = 0.0;
   out_506241675272442753[48] = 0.0;
   out_506241675272442753[49] = 0.0;
   out_506241675272442753[50] = 0.0;
   out_506241675272442753[51] = 0.0;
   out_506241675272442753[52] = 0.0;
   out_506241675272442753[53] = 0.0;
   out_506241675272442753[54] = 0.0;
   out_506241675272442753[55] = 0.0;
   out_506241675272442753[56] = 0.0;
   out_506241675272442753[57] = 1.0;
   out_506241675272442753[58] = 0.0;
   out_506241675272442753[59] = 0.0;
   out_506241675272442753[60] = 0.0;
   out_506241675272442753[61] = 0.0;
   out_506241675272442753[62] = 0.0;
   out_506241675272442753[63] = 0.0;
   out_506241675272442753[64] = 0.0;
   out_506241675272442753[65] = 0.0;
   out_506241675272442753[66] = 0.0;
   out_506241675272442753[67] = 0.0;
   out_506241675272442753[68] = 0.0;
   out_506241675272442753[69] = 0.0;
   out_506241675272442753[70] = 0.0;
   out_506241675272442753[71] = 0.0;
   out_506241675272442753[72] = 0.0;
   out_506241675272442753[73] = 0.0;
   out_506241675272442753[74] = 0.0;
   out_506241675272442753[75] = 0.0;
   out_506241675272442753[76] = 1.0;
   out_506241675272442753[77] = 0.0;
   out_506241675272442753[78] = 0.0;
   out_506241675272442753[79] = 0.0;
   out_506241675272442753[80] = 0.0;
   out_506241675272442753[81] = 0.0;
   out_506241675272442753[82] = 0.0;
   out_506241675272442753[83] = 0.0;
   out_506241675272442753[84] = 0.0;
   out_506241675272442753[85] = 0.0;
   out_506241675272442753[86] = 0.0;
   out_506241675272442753[87] = 0.0;
   out_506241675272442753[88] = 0.0;
   out_506241675272442753[89] = 0.0;
   out_506241675272442753[90] = 0.0;
   out_506241675272442753[91] = 0.0;
   out_506241675272442753[92] = 0.0;
   out_506241675272442753[93] = 0.0;
   out_506241675272442753[94] = 0.0;
   out_506241675272442753[95] = 1.0;
   out_506241675272442753[96] = 0.0;
   out_506241675272442753[97] = 0.0;
   out_506241675272442753[98] = 0.0;
   out_506241675272442753[99] = 0.0;
   out_506241675272442753[100] = 0.0;
   out_506241675272442753[101] = 0.0;
   out_506241675272442753[102] = 0.0;
   out_506241675272442753[103] = 0.0;
   out_506241675272442753[104] = 0.0;
   out_506241675272442753[105] = 0.0;
   out_506241675272442753[106] = 0.0;
   out_506241675272442753[107] = 0.0;
   out_506241675272442753[108] = 0.0;
   out_506241675272442753[109] = 0.0;
   out_506241675272442753[110] = 0.0;
   out_506241675272442753[111] = 0.0;
   out_506241675272442753[112] = 0.0;
   out_506241675272442753[113] = 0.0;
   out_506241675272442753[114] = 1.0;
   out_506241675272442753[115] = 0.0;
   out_506241675272442753[116] = 0.0;
   out_506241675272442753[117] = 0.0;
   out_506241675272442753[118] = 0.0;
   out_506241675272442753[119] = 0.0;
   out_506241675272442753[120] = 0.0;
   out_506241675272442753[121] = 0.0;
   out_506241675272442753[122] = 0.0;
   out_506241675272442753[123] = 0.0;
   out_506241675272442753[124] = 0.0;
   out_506241675272442753[125] = 0.0;
   out_506241675272442753[126] = 0.0;
   out_506241675272442753[127] = 0.0;
   out_506241675272442753[128] = 0.0;
   out_506241675272442753[129] = 0.0;
   out_506241675272442753[130] = 0.0;
   out_506241675272442753[131] = 0.0;
   out_506241675272442753[132] = 0.0;
   out_506241675272442753[133] = 1.0;
   out_506241675272442753[134] = 0.0;
   out_506241675272442753[135] = 0.0;
   out_506241675272442753[136] = 0.0;
   out_506241675272442753[137] = 0.0;
   out_506241675272442753[138] = 0.0;
   out_506241675272442753[139] = 0.0;
   out_506241675272442753[140] = 0.0;
   out_506241675272442753[141] = 0.0;
   out_506241675272442753[142] = 0.0;
   out_506241675272442753[143] = 0.0;
   out_506241675272442753[144] = 0.0;
   out_506241675272442753[145] = 0.0;
   out_506241675272442753[146] = 0.0;
   out_506241675272442753[147] = 0.0;
   out_506241675272442753[148] = 0.0;
   out_506241675272442753[149] = 0.0;
   out_506241675272442753[150] = 0.0;
   out_506241675272442753[151] = 0.0;
   out_506241675272442753[152] = 1.0;
   out_506241675272442753[153] = 0.0;
   out_506241675272442753[154] = 0.0;
   out_506241675272442753[155] = 0.0;
   out_506241675272442753[156] = 0.0;
   out_506241675272442753[157] = 0.0;
   out_506241675272442753[158] = 0.0;
   out_506241675272442753[159] = 0.0;
   out_506241675272442753[160] = 0.0;
   out_506241675272442753[161] = 0.0;
   out_506241675272442753[162] = 0.0;
   out_506241675272442753[163] = 0.0;
   out_506241675272442753[164] = 0.0;
   out_506241675272442753[165] = 0.0;
   out_506241675272442753[166] = 0.0;
   out_506241675272442753[167] = 0.0;
   out_506241675272442753[168] = 0.0;
   out_506241675272442753[169] = 0.0;
   out_506241675272442753[170] = 0.0;
   out_506241675272442753[171] = 1.0;
   out_506241675272442753[172] = 0.0;
   out_506241675272442753[173] = 0.0;
   out_506241675272442753[174] = 0.0;
   out_506241675272442753[175] = 0.0;
   out_506241675272442753[176] = 0.0;
   out_506241675272442753[177] = 0.0;
   out_506241675272442753[178] = 0.0;
   out_506241675272442753[179] = 0.0;
   out_506241675272442753[180] = 0.0;
   out_506241675272442753[181] = 0.0;
   out_506241675272442753[182] = 0.0;
   out_506241675272442753[183] = 0.0;
   out_506241675272442753[184] = 0.0;
   out_506241675272442753[185] = 0.0;
   out_506241675272442753[186] = 0.0;
   out_506241675272442753[187] = 0.0;
   out_506241675272442753[188] = 0.0;
   out_506241675272442753[189] = 0.0;
   out_506241675272442753[190] = 1.0;
   out_506241675272442753[191] = 0.0;
   out_506241675272442753[192] = 0.0;
   out_506241675272442753[193] = 0.0;
   out_506241675272442753[194] = 0.0;
   out_506241675272442753[195] = 0.0;
   out_506241675272442753[196] = 0.0;
   out_506241675272442753[197] = 0.0;
   out_506241675272442753[198] = 0.0;
   out_506241675272442753[199] = 0.0;
   out_506241675272442753[200] = 0.0;
   out_506241675272442753[201] = 0.0;
   out_506241675272442753[202] = 0.0;
   out_506241675272442753[203] = 0.0;
   out_506241675272442753[204] = 0.0;
   out_506241675272442753[205] = 0.0;
   out_506241675272442753[206] = 0.0;
   out_506241675272442753[207] = 0.0;
   out_506241675272442753[208] = 0.0;
   out_506241675272442753[209] = 1.0;
   out_506241675272442753[210] = 0.0;
   out_506241675272442753[211] = 0.0;
   out_506241675272442753[212] = 0.0;
   out_506241675272442753[213] = 0.0;
   out_506241675272442753[214] = 0.0;
   out_506241675272442753[215] = 0.0;
   out_506241675272442753[216] = 0.0;
   out_506241675272442753[217] = 0.0;
   out_506241675272442753[218] = 0.0;
   out_506241675272442753[219] = 0.0;
   out_506241675272442753[220] = 0.0;
   out_506241675272442753[221] = 0.0;
   out_506241675272442753[222] = 0.0;
   out_506241675272442753[223] = 0.0;
   out_506241675272442753[224] = 0.0;
   out_506241675272442753[225] = 0.0;
   out_506241675272442753[226] = 0.0;
   out_506241675272442753[227] = 0.0;
   out_506241675272442753[228] = 1.0;
   out_506241675272442753[229] = 0.0;
   out_506241675272442753[230] = 0.0;
   out_506241675272442753[231] = 0.0;
   out_506241675272442753[232] = 0.0;
   out_506241675272442753[233] = 0.0;
   out_506241675272442753[234] = 0.0;
   out_506241675272442753[235] = 0.0;
   out_506241675272442753[236] = 0.0;
   out_506241675272442753[237] = 0.0;
   out_506241675272442753[238] = 0.0;
   out_506241675272442753[239] = 0.0;
   out_506241675272442753[240] = 0.0;
   out_506241675272442753[241] = 0.0;
   out_506241675272442753[242] = 0.0;
   out_506241675272442753[243] = 0.0;
   out_506241675272442753[244] = 0.0;
   out_506241675272442753[245] = 0.0;
   out_506241675272442753[246] = 0.0;
   out_506241675272442753[247] = 1.0;
   out_506241675272442753[248] = 0.0;
   out_506241675272442753[249] = 0.0;
   out_506241675272442753[250] = 0.0;
   out_506241675272442753[251] = 0.0;
   out_506241675272442753[252] = 0.0;
   out_506241675272442753[253] = 0.0;
   out_506241675272442753[254] = 0.0;
   out_506241675272442753[255] = 0.0;
   out_506241675272442753[256] = 0.0;
   out_506241675272442753[257] = 0.0;
   out_506241675272442753[258] = 0.0;
   out_506241675272442753[259] = 0.0;
   out_506241675272442753[260] = 0.0;
   out_506241675272442753[261] = 0.0;
   out_506241675272442753[262] = 0.0;
   out_506241675272442753[263] = 0.0;
   out_506241675272442753[264] = 0.0;
   out_506241675272442753[265] = 0.0;
   out_506241675272442753[266] = 1.0;
   out_506241675272442753[267] = 0.0;
   out_506241675272442753[268] = 0.0;
   out_506241675272442753[269] = 0.0;
   out_506241675272442753[270] = 0.0;
   out_506241675272442753[271] = 0.0;
   out_506241675272442753[272] = 0.0;
   out_506241675272442753[273] = 0.0;
   out_506241675272442753[274] = 0.0;
   out_506241675272442753[275] = 0.0;
   out_506241675272442753[276] = 0.0;
   out_506241675272442753[277] = 0.0;
   out_506241675272442753[278] = 0.0;
   out_506241675272442753[279] = 0.0;
   out_506241675272442753[280] = 0.0;
   out_506241675272442753[281] = 0.0;
   out_506241675272442753[282] = 0.0;
   out_506241675272442753[283] = 0.0;
   out_506241675272442753[284] = 0.0;
   out_506241675272442753[285] = 1.0;
   out_506241675272442753[286] = 0.0;
   out_506241675272442753[287] = 0.0;
   out_506241675272442753[288] = 0.0;
   out_506241675272442753[289] = 0.0;
   out_506241675272442753[290] = 0.0;
   out_506241675272442753[291] = 0.0;
   out_506241675272442753[292] = 0.0;
   out_506241675272442753[293] = 0.0;
   out_506241675272442753[294] = 0.0;
   out_506241675272442753[295] = 0.0;
   out_506241675272442753[296] = 0.0;
   out_506241675272442753[297] = 0.0;
   out_506241675272442753[298] = 0.0;
   out_506241675272442753[299] = 0.0;
   out_506241675272442753[300] = 0.0;
   out_506241675272442753[301] = 0.0;
   out_506241675272442753[302] = 0.0;
   out_506241675272442753[303] = 0.0;
   out_506241675272442753[304] = 1.0;
   out_506241675272442753[305] = 0.0;
   out_506241675272442753[306] = 0.0;
   out_506241675272442753[307] = 0.0;
   out_506241675272442753[308] = 0.0;
   out_506241675272442753[309] = 0.0;
   out_506241675272442753[310] = 0.0;
   out_506241675272442753[311] = 0.0;
   out_506241675272442753[312] = 0.0;
   out_506241675272442753[313] = 0.0;
   out_506241675272442753[314] = 0.0;
   out_506241675272442753[315] = 0.0;
   out_506241675272442753[316] = 0.0;
   out_506241675272442753[317] = 0.0;
   out_506241675272442753[318] = 0.0;
   out_506241675272442753[319] = 0.0;
   out_506241675272442753[320] = 0.0;
   out_506241675272442753[321] = 0.0;
   out_506241675272442753[322] = 0.0;
   out_506241675272442753[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4178544833437689493) {
   out_4178544833437689493[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4178544833437689493[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4178544833437689493[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4178544833437689493[3] = dt*state[12] + state[3];
   out_4178544833437689493[4] = dt*state[13] + state[4];
   out_4178544833437689493[5] = dt*state[14] + state[5];
   out_4178544833437689493[6] = state[6];
   out_4178544833437689493[7] = state[7];
   out_4178544833437689493[8] = state[8];
   out_4178544833437689493[9] = state[9];
   out_4178544833437689493[10] = state[10];
   out_4178544833437689493[11] = state[11];
   out_4178544833437689493[12] = state[12];
   out_4178544833437689493[13] = state[13];
   out_4178544833437689493[14] = state[14];
   out_4178544833437689493[15] = state[15];
   out_4178544833437689493[16] = state[16];
   out_4178544833437689493[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8152186578689356973) {
   out_8152186578689356973[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8152186578689356973[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8152186578689356973[2] = 0;
   out_8152186578689356973[3] = 0;
   out_8152186578689356973[4] = 0;
   out_8152186578689356973[5] = 0;
   out_8152186578689356973[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8152186578689356973[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8152186578689356973[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8152186578689356973[9] = 0;
   out_8152186578689356973[10] = 0;
   out_8152186578689356973[11] = 0;
   out_8152186578689356973[12] = 0;
   out_8152186578689356973[13] = 0;
   out_8152186578689356973[14] = 0;
   out_8152186578689356973[15] = 0;
   out_8152186578689356973[16] = 0;
   out_8152186578689356973[17] = 0;
   out_8152186578689356973[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8152186578689356973[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8152186578689356973[20] = 0;
   out_8152186578689356973[21] = 0;
   out_8152186578689356973[22] = 0;
   out_8152186578689356973[23] = 0;
   out_8152186578689356973[24] = 0;
   out_8152186578689356973[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8152186578689356973[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8152186578689356973[27] = 0;
   out_8152186578689356973[28] = 0;
   out_8152186578689356973[29] = 0;
   out_8152186578689356973[30] = 0;
   out_8152186578689356973[31] = 0;
   out_8152186578689356973[32] = 0;
   out_8152186578689356973[33] = 0;
   out_8152186578689356973[34] = 0;
   out_8152186578689356973[35] = 0;
   out_8152186578689356973[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8152186578689356973[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8152186578689356973[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8152186578689356973[39] = 0;
   out_8152186578689356973[40] = 0;
   out_8152186578689356973[41] = 0;
   out_8152186578689356973[42] = 0;
   out_8152186578689356973[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8152186578689356973[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8152186578689356973[45] = 0;
   out_8152186578689356973[46] = 0;
   out_8152186578689356973[47] = 0;
   out_8152186578689356973[48] = 0;
   out_8152186578689356973[49] = 0;
   out_8152186578689356973[50] = 0;
   out_8152186578689356973[51] = 0;
   out_8152186578689356973[52] = 0;
   out_8152186578689356973[53] = 0;
   out_8152186578689356973[54] = 0;
   out_8152186578689356973[55] = 0;
   out_8152186578689356973[56] = 0;
   out_8152186578689356973[57] = 1;
   out_8152186578689356973[58] = 0;
   out_8152186578689356973[59] = 0;
   out_8152186578689356973[60] = 0;
   out_8152186578689356973[61] = 0;
   out_8152186578689356973[62] = 0;
   out_8152186578689356973[63] = 0;
   out_8152186578689356973[64] = 0;
   out_8152186578689356973[65] = 0;
   out_8152186578689356973[66] = dt;
   out_8152186578689356973[67] = 0;
   out_8152186578689356973[68] = 0;
   out_8152186578689356973[69] = 0;
   out_8152186578689356973[70] = 0;
   out_8152186578689356973[71] = 0;
   out_8152186578689356973[72] = 0;
   out_8152186578689356973[73] = 0;
   out_8152186578689356973[74] = 0;
   out_8152186578689356973[75] = 0;
   out_8152186578689356973[76] = 1;
   out_8152186578689356973[77] = 0;
   out_8152186578689356973[78] = 0;
   out_8152186578689356973[79] = 0;
   out_8152186578689356973[80] = 0;
   out_8152186578689356973[81] = 0;
   out_8152186578689356973[82] = 0;
   out_8152186578689356973[83] = 0;
   out_8152186578689356973[84] = 0;
   out_8152186578689356973[85] = dt;
   out_8152186578689356973[86] = 0;
   out_8152186578689356973[87] = 0;
   out_8152186578689356973[88] = 0;
   out_8152186578689356973[89] = 0;
   out_8152186578689356973[90] = 0;
   out_8152186578689356973[91] = 0;
   out_8152186578689356973[92] = 0;
   out_8152186578689356973[93] = 0;
   out_8152186578689356973[94] = 0;
   out_8152186578689356973[95] = 1;
   out_8152186578689356973[96] = 0;
   out_8152186578689356973[97] = 0;
   out_8152186578689356973[98] = 0;
   out_8152186578689356973[99] = 0;
   out_8152186578689356973[100] = 0;
   out_8152186578689356973[101] = 0;
   out_8152186578689356973[102] = 0;
   out_8152186578689356973[103] = 0;
   out_8152186578689356973[104] = dt;
   out_8152186578689356973[105] = 0;
   out_8152186578689356973[106] = 0;
   out_8152186578689356973[107] = 0;
   out_8152186578689356973[108] = 0;
   out_8152186578689356973[109] = 0;
   out_8152186578689356973[110] = 0;
   out_8152186578689356973[111] = 0;
   out_8152186578689356973[112] = 0;
   out_8152186578689356973[113] = 0;
   out_8152186578689356973[114] = 1;
   out_8152186578689356973[115] = 0;
   out_8152186578689356973[116] = 0;
   out_8152186578689356973[117] = 0;
   out_8152186578689356973[118] = 0;
   out_8152186578689356973[119] = 0;
   out_8152186578689356973[120] = 0;
   out_8152186578689356973[121] = 0;
   out_8152186578689356973[122] = 0;
   out_8152186578689356973[123] = 0;
   out_8152186578689356973[124] = 0;
   out_8152186578689356973[125] = 0;
   out_8152186578689356973[126] = 0;
   out_8152186578689356973[127] = 0;
   out_8152186578689356973[128] = 0;
   out_8152186578689356973[129] = 0;
   out_8152186578689356973[130] = 0;
   out_8152186578689356973[131] = 0;
   out_8152186578689356973[132] = 0;
   out_8152186578689356973[133] = 1;
   out_8152186578689356973[134] = 0;
   out_8152186578689356973[135] = 0;
   out_8152186578689356973[136] = 0;
   out_8152186578689356973[137] = 0;
   out_8152186578689356973[138] = 0;
   out_8152186578689356973[139] = 0;
   out_8152186578689356973[140] = 0;
   out_8152186578689356973[141] = 0;
   out_8152186578689356973[142] = 0;
   out_8152186578689356973[143] = 0;
   out_8152186578689356973[144] = 0;
   out_8152186578689356973[145] = 0;
   out_8152186578689356973[146] = 0;
   out_8152186578689356973[147] = 0;
   out_8152186578689356973[148] = 0;
   out_8152186578689356973[149] = 0;
   out_8152186578689356973[150] = 0;
   out_8152186578689356973[151] = 0;
   out_8152186578689356973[152] = 1;
   out_8152186578689356973[153] = 0;
   out_8152186578689356973[154] = 0;
   out_8152186578689356973[155] = 0;
   out_8152186578689356973[156] = 0;
   out_8152186578689356973[157] = 0;
   out_8152186578689356973[158] = 0;
   out_8152186578689356973[159] = 0;
   out_8152186578689356973[160] = 0;
   out_8152186578689356973[161] = 0;
   out_8152186578689356973[162] = 0;
   out_8152186578689356973[163] = 0;
   out_8152186578689356973[164] = 0;
   out_8152186578689356973[165] = 0;
   out_8152186578689356973[166] = 0;
   out_8152186578689356973[167] = 0;
   out_8152186578689356973[168] = 0;
   out_8152186578689356973[169] = 0;
   out_8152186578689356973[170] = 0;
   out_8152186578689356973[171] = 1;
   out_8152186578689356973[172] = 0;
   out_8152186578689356973[173] = 0;
   out_8152186578689356973[174] = 0;
   out_8152186578689356973[175] = 0;
   out_8152186578689356973[176] = 0;
   out_8152186578689356973[177] = 0;
   out_8152186578689356973[178] = 0;
   out_8152186578689356973[179] = 0;
   out_8152186578689356973[180] = 0;
   out_8152186578689356973[181] = 0;
   out_8152186578689356973[182] = 0;
   out_8152186578689356973[183] = 0;
   out_8152186578689356973[184] = 0;
   out_8152186578689356973[185] = 0;
   out_8152186578689356973[186] = 0;
   out_8152186578689356973[187] = 0;
   out_8152186578689356973[188] = 0;
   out_8152186578689356973[189] = 0;
   out_8152186578689356973[190] = 1;
   out_8152186578689356973[191] = 0;
   out_8152186578689356973[192] = 0;
   out_8152186578689356973[193] = 0;
   out_8152186578689356973[194] = 0;
   out_8152186578689356973[195] = 0;
   out_8152186578689356973[196] = 0;
   out_8152186578689356973[197] = 0;
   out_8152186578689356973[198] = 0;
   out_8152186578689356973[199] = 0;
   out_8152186578689356973[200] = 0;
   out_8152186578689356973[201] = 0;
   out_8152186578689356973[202] = 0;
   out_8152186578689356973[203] = 0;
   out_8152186578689356973[204] = 0;
   out_8152186578689356973[205] = 0;
   out_8152186578689356973[206] = 0;
   out_8152186578689356973[207] = 0;
   out_8152186578689356973[208] = 0;
   out_8152186578689356973[209] = 1;
   out_8152186578689356973[210] = 0;
   out_8152186578689356973[211] = 0;
   out_8152186578689356973[212] = 0;
   out_8152186578689356973[213] = 0;
   out_8152186578689356973[214] = 0;
   out_8152186578689356973[215] = 0;
   out_8152186578689356973[216] = 0;
   out_8152186578689356973[217] = 0;
   out_8152186578689356973[218] = 0;
   out_8152186578689356973[219] = 0;
   out_8152186578689356973[220] = 0;
   out_8152186578689356973[221] = 0;
   out_8152186578689356973[222] = 0;
   out_8152186578689356973[223] = 0;
   out_8152186578689356973[224] = 0;
   out_8152186578689356973[225] = 0;
   out_8152186578689356973[226] = 0;
   out_8152186578689356973[227] = 0;
   out_8152186578689356973[228] = 1;
   out_8152186578689356973[229] = 0;
   out_8152186578689356973[230] = 0;
   out_8152186578689356973[231] = 0;
   out_8152186578689356973[232] = 0;
   out_8152186578689356973[233] = 0;
   out_8152186578689356973[234] = 0;
   out_8152186578689356973[235] = 0;
   out_8152186578689356973[236] = 0;
   out_8152186578689356973[237] = 0;
   out_8152186578689356973[238] = 0;
   out_8152186578689356973[239] = 0;
   out_8152186578689356973[240] = 0;
   out_8152186578689356973[241] = 0;
   out_8152186578689356973[242] = 0;
   out_8152186578689356973[243] = 0;
   out_8152186578689356973[244] = 0;
   out_8152186578689356973[245] = 0;
   out_8152186578689356973[246] = 0;
   out_8152186578689356973[247] = 1;
   out_8152186578689356973[248] = 0;
   out_8152186578689356973[249] = 0;
   out_8152186578689356973[250] = 0;
   out_8152186578689356973[251] = 0;
   out_8152186578689356973[252] = 0;
   out_8152186578689356973[253] = 0;
   out_8152186578689356973[254] = 0;
   out_8152186578689356973[255] = 0;
   out_8152186578689356973[256] = 0;
   out_8152186578689356973[257] = 0;
   out_8152186578689356973[258] = 0;
   out_8152186578689356973[259] = 0;
   out_8152186578689356973[260] = 0;
   out_8152186578689356973[261] = 0;
   out_8152186578689356973[262] = 0;
   out_8152186578689356973[263] = 0;
   out_8152186578689356973[264] = 0;
   out_8152186578689356973[265] = 0;
   out_8152186578689356973[266] = 1;
   out_8152186578689356973[267] = 0;
   out_8152186578689356973[268] = 0;
   out_8152186578689356973[269] = 0;
   out_8152186578689356973[270] = 0;
   out_8152186578689356973[271] = 0;
   out_8152186578689356973[272] = 0;
   out_8152186578689356973[273] = 0;
   out_8152186578689356973[274] = 0;
   out_8152186578689356973[275] = 0;
   out_8152186578689356973[276] = 0;
   out_8152186578689356973[277] = 0;
   out_8152186578689356973[278] = 0;
   out_8152186578689356973[279] = 0;
   out_8152186578689356973[280] = 0;
   out_8152186578689356973[281] = 0;
   out_8152186578689356973[282] = 0;
   out_8152186578689356973[283] = 0;
   out_8152186578689356973[284] = 0;
   out_8152186578689356973[285] = 1;
   out_8152186578689356973[286] = 0;
   out_8152186578689356973[287] = 0;
   out_8152186578689356973[288] = 0;
   out_8152186578689356973[289] = 0;
   out_8152186578689356973[290] = 0;
   out_8152186578689356973[291] = 0;
   out_8152186578689356973[292] = 0;
   out_8152186578689356973[293] = 0;
   out_8152186578689356973[294] = 0;
   out_8152186578689356973[295] = 0;
   out_8152186578689356973[296] = 0;
   out_8152186578689356973[297] = 0;
   out_8152186578689356973[298] = 0;
   out_8152186578689356973[299] = 0;
   out_8152186578689356973[300] = 0;
   out_8152186578689356973[301] = 0;
   out_8152186578689356973[302] = 0;
   out_8152186578689356973[303] = 0;
   out_8152186578689356973[304] = 1;
   out_8152186578689356973[305] = 0;
   out_8152186578689356973[306] = 0;
   out_8152186578689356973[307] = 0;
   out_8152186578689356973[308] = 0;
   out_8152186578689356973[309] = 0;
   out_8152186578689356973[310] = 0;
   out_8152186578689356973[311] = 0;
   out_8152186578689356973[312] = 0;
   out_8152186578689356973[313] = 0;
   out_8152186578689356973[314] = 0;
   out_8152186578689356973[315] = 0;
   out_8152186578689356973[316] = 0;
   out_8152186578689356973[317] = 0;
   out_8152186578689356973[318] = 0;
   out_8152186578689356973[319] = 0;
   out_8152186578689356973[320] = 0;
   out_8152186578689356973[321] = 0;
   out_8152186578689356973[322] = 0;
   out_8152186578689356973[323] = 1;
}
void h_4(double *state, double *unused, double *out_6179676342109340429) {
   out_6179676342109340429[0] = state[6] + state[9];
   out_6179676342109340429[1] = state[7] + state[10];
   out_6179676342109340429[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1260402677327155360) {
   out_1260402677327155360[0] = 0;
   out_1260402677327155360[1] = 0;
   out_1260402677327155360[2] = 0;
   out_1260402677327155360[3] = 0;
   out_1260402677327155360[4] = 0;
   out_1260402677327155360[5] = 0;
   out_1260402677327155360[6] = 1;
   out_1260402677327155360[7] = 0;
   out_1260402677327155360[8] = 0;
   out_1260402677327155360[9] = 1;
   out_1260402677327155360[10] = 0;
   out_1260402677327155360[11] = 0;
   out_1260402677327155360[12] = 0;
   out_1260402677327155360[13] = 0;
   out_1260402677327155360[14] = 0;
   out_1260402677327155360[15] = 0;
   out_1260402677327155360[16] = 0;
   out_1260402677327155360[17] = 0;
   out_1260402677327155360[18] = 0;
   out_1260402677327155360[19] = 0;
   out_1260402677327155360[20] = 0;
   out_1260402677327155360[21] = 0;
   out_1260402677327155360[22] = 0;
   out_1260402677327155360[23] = 0;
   out_1260402677327155360[24] = 0;
   out_1260402677327155360[25] = 1;
   out_1260402677327155360[26] = 0;
   out_1260402677327155360[27] = 0;
   out_1260402677327155360[28] = 1;
   out_1260402677327155360[29] = 0;
   out_1260402677327155360[30] = 0;
   out_1260402677327155360[31] = 0;
   out_1260402677327155360[32] = 0;
   out_1260402677327155360[33] = 0;
   out_1260402677327155360[34] = 0;
   out_1260402677327155360[35] = 0;
   out_1260402677327155360[36] = 0;
   out_1260402677327155360[37] = 0;
   out_1260402677327155360[38] = 0;
   out_1260402677327155360[39] = 0;
   out_1260402677327155360[40] = 0;
   out_1260402677327155360[41] = 0;
   out_1260402677327155360[42] = 0;
   out_1260402677327155360[43] = 0;
   out_1260402677327155360[44] = 1;
   out_1260402677327155360[45] = 0;
   out_1260402677327155360[46] = 0;
   out_1260402677327155360[47] = 1;
   out_1260402677327155360[48] = 0;
   out_1260402677327155360[49] = 0;
   out_1260402677327155360[50] = 0;
   out_1260402677327155360[51] = 0;
   out_1260402677327155360[52] = 0;
   out_1260402677327155360[53] = 0;
}
void h_10(double *state, double *unused, double *out_9202982941819295536) {
   out_9202982941819295536[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_9202982941819295536[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_9202982941819295536[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6171075050568888644) {
   out_6171075050568888644[0] = 0;
   out_6171075050568888644[1] = 9.8100000000000005*cos(state[1]);
   out_6171075050568888644[2] = 0;
   out_6171075050568888644[3] = 0;
   out_6171075050568888644[4] = -state[8];
   out_6171075050568888644[5] = state[7];
   out_6171075050568888644[6] = 0;
   out_6171075050568888644[7] = state[5];
   out_6171075050568888644[8] = -state[4];
   out_6171075050568888644[9] = 0;
   out_6171075050568888644[10] = 0;
   out_6171075050568888644[11] = 0;
   out_6171075050568888644[12] = 1;
   out_6171075050568888644[13] = 0;
   out_6171075050568888644[14] = 0;
   out_6171075050568888644[15] = 1;
   out_6171075050568888644[16] = 0;
   out_6171075050568888644[17] = 0;
   out_6171075050568888644[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6171075050568888644[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6171075050568888644[20] = 0;
   out_6171075050568888644[21] = state[8];
   out_6171075050568888644[22] = 0;
   out_6171075050568888644[23] = -state[6];
   out_6171075050568888644[24] = -state[5];
   out_6171075050568888644[25] = 0;
   out_6171075050568888644[26] = state[3];
   out_6171075050568888644[27] = 0;
   out_6171075050568888644[28] = 0;
   out_6171075050568888644[29] = 0;
   out_6171075050568888644[30] = 0;
   out_6171075050568888644[31] = 1;
   out_6171075050568888644[32] = 0;
   out_6171075050568888644[33] = 0;
   out_6171075050568888644[34] = 1;
   out_6171075050568888644[35] = 0;
   out_6171075050568888644[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6171075050568888644[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6171075050568888644[38] = 0;
   out_6171075050568888644[39] = -state[7];
   out_6171075050568888644[40] = state[6];
   out_6171075050568888644[41] = 0;
   out_6171075050568888644[42] = state[4];
   out_6171075050568888644[43] = -state[3];
   out_6171075050568888644[44] = 0;
   out_6171075050568888644[45] = 0;
   out_6171075050568888644[46] = 0;
   out_6171075050568888644[47] = 0;
   out_6171075050568888644[48] = 0;
   out_6171075050568888644[49] = 0;
   out_6171075050568888644[50] = 1;
   out_6171075050568888644[51] = 0;
   out_6171075050568888644[52] = 0;
   out_6171075050568888644[53] = 1;
}
void h_13(double *state, double *unused, double *out_5137979176045158123) {
   out_5137979176045158123[0] = state[3];
   out_5137979176045158123[1] = state[4];
   out_5137979176045158123[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4472676502659488161) {
   out_4472676502659488161[0] = 0;
   out_4472676502659488161[1] = 0;
   out_4472676502659488161[2] = 0;
   out_4472676502659488161[3] = 1;
   out_4472676502659488161[4] = 0;
   out_4472676502659488161[5] = 0;
   out_4472676502659488161[6] = 0;
   out_4472676502659488161[7] = 0;
   out_4472676502659488161[8] = 0;
   out_4472676502659488161[9] = 0;
   out_4472676502659488161[10] = 0;
   out_4472676502659488161[11] = 0;
   out_4472676502659488161[12] = 0;
   out_4472676502659488161[13] = 0;
   out_4472676502659488161[14] = 0;
   out_4472676502659488161[15] = 0;
   out_4472676502659488161[16] = 0;
   out_4472676502659488161[17] = 0;
   out_4472676502659488161[18] = 0;
   out_4472676502659488161[19] = 0;
   out_4472676502659488161[20] = 0;
   out_4472676502659488161[21] = 0;
   out_4472676502659488161[22] = 1;
   out_4472676502659488161[23] = 0;
   out_4472676502659488161[24] = 0;
   out_4472676502659488161[25] = 0;
   out_4472676502659488161[26] = 0;
   out_4472676502659488161[27] = 0;
   out_4472676502659488161[28] = 0;
   out_4472676502659488161[29] = 0;
   out_4472676502659488161[30] = 0;
   out_4472676502659488161[31] = 0;
   out_4472676502659488161[32] = 0;
   out_4472676502659488161[33] = 0;
   out_4472676502659488161[34] = 0;
   out_4472676502659488161[35] = 0;
   out_4472676502659488161[36] = 0;
   out_4472676502659488161[37] = 0;
   out_4472676502659488161[38] = 0;
   out_4472676502659488161[39] = 0;
   out_4472676502659488161[40] = 0;
   out_4472676502659488161[41] = 1;
   out_4472676502659488161[42] = 0;
   out_4472676502659488161[43] = 0;
   out_4472676502659488161[44] = 0;
   out_4472676502659488161[45] = 0;
   out_4472676502659488161[46] = 0;
   out_4472676502659488161[47] = 0;
   out_4472676502659488161[48] = 0;
   out_4472676502659488161[49] = 0;
   out_4472676502659488161[50] = 0;
   out_4472676502659488161[51] = 0;
   out_4472676502659488161[52] = 0;
   out_4472676502659488161[53] = 0;
}
void h_14(double *state, double *unused, double *out_7033934925710428047) {
   out_7033934925710428047[0] = state[6];
   out_7033934925710428047[1] = state[7];
   out_7033934925710428047[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1822385754968216936) {
   out_1822385754968216936[0] = 0;
   out_1822385754968216936[1] = 0;
   out_1822385754968216936[2] = 0;
   out_1822385754968216936[3] = 0;
   out_1822385754968216936[4] = 0;
   out_1822385754968216936[5] = 0;
   out_1822385754968216936[6] = 1;
   out_1822385754968216936[7] = 0;
   out_1822385754968216936[8] = 0;
   out_1822385754968216936[9] = 0;
   out_1822385754968216936[10] = 0;
   out_1822385754968216936[11] = 0;
   out_1822385754968216936[12] = 0;
   out_1822385754968216936[13] = 0;
   out_1822385754968216936[14] = 0;
   out_1822385754968216936[15] = 0;
   out_1822385754968216936[16] = 0;
   out_1822385754968216936[17] = 0;
   out_1822385754968216936[18] = 0;
   out_1822385754968216936[19] = 0;
   out_1822385754968216936[20] = 0;
   out_1822385754968216936[21] = 0;
   out_1822385754968216936[22] = 0;
   out_1822385754968216936[23] = 0;
   out_1822385754968216936[24] = 0;
   out_1822385754968216936[25] = 1;
   out_1822385754968216936[26] = 0;
   out_1822385754968216936[27] = 0;
   out_1822385754968216936[28] = 0;
   out_1822385754968216936[29] = 0;
   out_1822385754968216936[30] = 0;
   out_1822385754968216936[31] = 0;
   out_1822385754968216936[32] = 0;
   out_1822385754968216936[33] = 0;
   out_1822385754968216936[34] = 0;
   out_1822385754968216936[35] = 0;
   out_1822385754968216936[36] = 0;
   out_1822385754968216936[37] = 0;
   out_1822385754968216936[38] = 0;
   out_1822385754968216936[39] = 0;
   out_1822385754968216936[40] = 0;
   out_1822385754968216936[41] = 0;
   out_1822385754968216936[42] = 0;
   out_1822385754968216936[43] = 0;
   out_1822385754968216936[44] = 1;
   out_1822385754968216936[45] = 0;
   out_1822385754968216936[46] = 0;
   out_1822385754968216936[47] = 0;
   out_1822385754968216936[48] = 0;
   out_1822385754968216936[49] = 0;
   out_1822385754968216936[50] = 0;
   out_1822385754968216936[51] = 0;
   out_1822385754968216936[52] = 0;
   out_1822385754968216936[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7746602045410251207) {
  err_fun(nom_x, delta_x, out_7746602045410251207);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7631524114608656485) {
  inv_err_fun(nom_x, true_x, out_7631524114608656485);
}
void pose_H_mod_fun(double *state, double *out_506241675272442753) {
  H_mod_fun(state, out_506241675272442753);
}
void pose_f_fun(double *state, double dt, double *out_4178544833437689493) {
  f_fun(state,  dt, out_4178544833437689493);
}
void pose_F_fun(double *state, double dt, double *out_8152186578689356973) {
  F_fun(state,  dt, out_8152186578689356973);
}
void pose_h_4(double *state, double *unused, double *out_6179676342109340429) {
  h_4(state, unused, out_6179676342109340429);
}
void pose_H_4(double *state, double *unused, double *out_1260402677327155360) {
  H_4(state, unused, out_1260402677327155360);
}
void pose_h_10(double *state, double *unused, double *out_9202982941819295536) {
  h_10(state, unused, out_9202982941819295536);
}
void pose_H_10(double *state, double *unused, double *out_6171075050568888644) {
  H_10(state, unused, out_6171075050568888644);
}
void pose_h_13(double *state, double *unused, double *out_5137979176045158123) {
  h_13(state, unused, out_5137979176045158123);
}
void pose_H_13(double *state, double *unused, double *out_4472676502659488161) {
  H_13(state, unused, out_4472676502659488161);
}
void pose_h_14(double *state, double *unused, double *out_7033934925710428047) {
  h_14(state, unused, out_7033934925710428047);
}
void pose_H_14(double *state, double *unused, double *out_1822385754968216936) {
  H_14(state, unused, out_1822385754968216936);
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
