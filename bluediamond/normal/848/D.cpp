#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 

bool home = true;
using namespace std;
typedef long long ll;

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int dp[51][51];
  dp[1][1] = 0;
  dp[1][2] = 1;
  dp[2][1] = 0;
  dp[2][2] = 2;
  dp[2][3] = 1;
  dp[3][1] = 0;
  dp[3][2] = 6;
  dp[3][3] = 3;
  dp[3][4] = 1;
  dp[4][1] = 0;
  dp[4][2] = 20;
  dp[4][3] = 15;
  dp[4][4] = 3;
  dp[4][5] = 1;
  dp[5][1] = 0;
  dp[5][2] = 78;
  dp[5][3] = 60;
  dp[5][4] = 18;
  dp[5][5] = 3;
  dp[5][6] = 1;
  dp[6][1] = 0;
  dp[6][2] = 320;
  dp[6][3] = 269;
  dp[6][4] = 90;
  dp[6][5] = 19;
  dp[6][6] = 3;
  dp[6][7] = 1;
  dp[7][1] = 0;
  dp[7][2] = 1404;
  dp[7][3] = 1196;
  dp[7][4] = 452;
  dp[7][5] = 102;
  dp[7][6] = 19;
  dp[7][7] = 3;
  dp[7][8] = 1;
  dp[8][1] = 0;
  dp[8][2] = 6354;
  dp[8][3] = 5550;
  dp[8][4] = 2232;
  dp[8][5] = 566;
  dp[8][6] = 105;
  dp[8][7] = 19;
  dp[8][8] = 3;
  dp[8][9] = 1;
  dp[9][1] = 0;
  dp[9][2] = 29660;
  dp[9][3] = 26148;
  dp[9][4] = 11129;
  dp[9][5] = 3004;
  dp[9][6] = 608;
  dp[9][7] = 106;
  dp[9][8] = 19;
  dp[9][9] = 3;
  dp[9][10] = 1;
  dp[10][1] = 0;
  dp[10][2] = 141356;
  dp[10][3] = 125797;
  dp[10][4] = 55564;
  dp[10][5] = 15992;
  dp[10][6] = 3401;
  dp[10][7] = 621;
  dp[10][8] = 106;
  dp[10][9] = 19;
  dp[10][10] = 3;
  dp[10][11] = 1;
  dp[11][1] = 0;
  dp[11][2] = 685720;
  dp[11][3] = 613696;
  dp[11][4] = 279559;
  dp[11][5] = 84232;
  dp[11][6] = 18975;
  dp[11][7] = 3551;
  dp[11][8] = 624;
  dp[11][9] = 106;
  dp[11][10] = 19;
  dp[11][11] = 3;
  dp[11][12] = 1;
  dp[12][1] = 0;
  dp[12][2] = 3372972;
  dp[12][3] = 3033312;
  dp[12][4] = 1414754;
  dp[12][5] = 443388;
  dp[12][6] = 104533;
  dp[12][7] = 20372;
  dp[12][8] = 3596;
  dp[12][9] = 625;
  dp[12][10] = 106;
  dp[12][11] = 19;
  dp[12][12] = 3;
  dp[12][13] = 1;
  dp[13][1] = 0;
  dp[13][2] = 16787362;
  dp[13][3] = 15150580;
  dp[13][4] = 7205309;
  dp[13][5] = 2330591;
  dp[13][6] = 572601;
  dp[13][7] = 115463;
  dp[13][8] = 20879;
  dp[13][9] = 3609;
  dp[13][10] = 625;
  dp[13][11] = 106;
  dp[13][12] = 19;
  dp[13][13] = 3;
  dp[13][14] = 1;
  dp[14][1] = 0;
  dp[14][2] = 84374296;
  dp[14][3] = 76373402;
  dp[14][4] = 36905066;
  dp[14][5] = 12260498;
  dp[14][6] = 3118939;
  dp[14][7] = 651005;
  dp[14][8] = 120188;
  dp[14][9] = 21042;
  dp[14][10] = 3612;
  dp[14][11] = 625;
  dp[14][12] = 106;
  dp[14][13] = 19;
  dp[14][14] = 3;
  dp[14][15] = 1;
  dp[15][1] = 0;
  dp[15][2] = 427657604;
  dp[15][3] = 388029184;
  dp[15][4] = 190039924;
  dp[15][5] = 64569370;
  dp[15][6] = 16932666;
  dp[15][7] = 3645556;
  dp[15][8] = 689414;
  dp[15][9] = 121903;
  dp[15][10] = 21088;
  dp[15][11] = 3613;
  dp[15][12] = 625;
  dp[15][13] = 106;
  dp[15][14] = 19;
  dp[15][15] = 3;
  dp[15][16] = 1;
  dp[16][1] = 0;
  dp[16][2] = 183422138;
  dp[16][3] = 985084652;
  dp[16][4] = 983358608;
  dp[16][5] = 340626132;
  dp[16][6] = 91705041;
  dp[16][7] = 20316053;
  dp[16][8] = 3932165;
  dp[16][9] = 705215;
  dp[16][10] = 122449;
  dp[16][11] = 21101;
  dp[16][12] = 3613;
  dp[16][13] = 625;
  dp[16][14] = 106;
  dp[16][15] = 19;
  dp[16][16] = 3;
  dp[16][17] = 1;
  dp[17][1] = 0;
  dp[17][2] = 218595807;
  dp[17][3] = 216827574;
  dp[17][4] = 111123886;
  dp[17][5] = 800216575;
  dp[17][6] = 495958406;
  dp[17][7] = 112739002;
  dp[17][8] = 22325180;
  dp[17][9] = 4062841;
  dp[17][10] = 710843;
  dp[17][11] = 122615;
  dp[17][12] = 21104;
  dp[17][13] = 3613;
  dp[17][14] = 625;
  dp[17][15] = 106;
  dp[17][16] = 19;
  dp[17][17] = 3;
  dp[17][18] = 1;
  dp[18][1] = 0;
  dp[18][2] = 965416379;
  dp[18][3] = 866331606;
  dp[18][4] = 673968136;
  dp[18][5] = 532890011;
  dp[18][6] = 680029370;
  dp[18][7] = 623595485;
  dp[18][8] = 126193365;
  dp[18][9] = 23327903;
  dp[18][10] = 4114503;
  dp[18][11] = 712681;
  dp[18][12] = 122661;
  dp[18][13] = 21105;
  dp[18][14] = 3613;
  dp[18][15] = 625;
  dp[18][16] = 106;
  dp[18][17] = 19;
  dp[18][18] = 3;
  dp[18][19] = 1;
  dp[19][1] = 0;
  dp[19][2] = 993455088;
  dp[19][3] = 862080862;
  dp[19][4] = 725923843;
  dp[19][5] = 580538538;
  dp[19][6] = 477345228;
  dp[19][7] = 440384026;
  dp[19][8] = 710624473;
  dp[19][9] = 133452405;
  dp[19][10] = 23761056;
  dp[19][11] = 4132780;
  dp[19][12] = 713240;
  dp[19][13] = 122674;
  dp[19][14] = 21105;
  dp[19][15] = 3613;
  dp[19][16] = 625;
  dp[19][17] = 106;
  dp[19][18] = 19;
  dp[19][19] = 3;
  dp[19][20] = 1;
  dp[20][1] = 0;
  dp[20][2] = 905119307;
  dp[20][3] = 192776929;
  dp[20][4] = 427183902;
  dp[20][5] = 902740653;
  dp[20][6] = 205572806;
  dp[20][7] = 943087579;
  dp[20][8] = 988485039;
  dp[20][9] = 760890378;
  dp[20][10] = 136845231;
  dp[20][11] = 23927353;
  dp[20][12] = 4138765;
  dp[20][13] = 713407;
  dp[20][14] = 122677;
  dp[20][15] = 21105;
  dp[20][16] = 3613;
  dp[20][17] = 625;
  dp[20][18] = 106;
  dp[20][19] = 19;
  dp[20][20] = 3;
  dp[20][21] = 1;
  dp[21][1] = 0;
  dp[21][2] = 983258926;
  dp[21][3] = 856652574;
  dp[21][4] = 419294183;
  dp[21][5] = 314218472;
  dp[21][6] = 565633404;
  dp[21][7] = 144225184;
  dp[21][8] = 323294025;
  dp[21][9] = 324568580;
  dp[21][10] = 786075109;
  dp[21][11] = 138248537;
  dp[21][12] = 23985741;
  dp[21][13] = 4140643;
  dp[21][14] = 713453;
  dp[21][15] = 122678;
  dp[21][16] = 21105;
  dp[21][17] = 3613;
  dp[21][18] = 625;
  dp[21][19] = 106;
  dp[21][20] = 19;
  dp[21][21] = 3;
  dp[21][22] = 1;
  dp[22][1] = 0;
  dp[22][2] = 768913899;
  dp[22][3] = 874476794;
  dp[22][4] = 159058735;
  dp[22][5] = 376378817;
  dp[22][6] = 200939010;
  dp[22][7] = 909767346;
  dp[22][8] = 644939341;
  dp[22][9] = 508636359;
  dp[22][10] = 503698048;
  dp[22][11] = 797229154;
  dp[22][12] = 138775923;
  dp[22][13] = 24005038;
  dp[22][14] = 4141205;
  dp[22][15] = 713466;
  dp[22][16] = 122678;
  dp[22][17] = 21105;
  dp[22][18] = 3613;
  dp[22][19] = 625;
  dp[22][20] = 106;
  dp[22][21] = 19;
  dp[22][22] = 3;
  dp[22][23] = 1;
  dp[23][1] = 0;
  dp[23][2] = 823642493;
  dp[23][3] = 705094318;
  dp[23][4] = 65810807;
  dp[23][5] = 545788941;
  dp[23][6] = 142710068;
  dp[23][7] = 49894552;
  dp[23][8] = 580875908;
  dp[23][9] = 538421095;
  dp[23][10] = 739525857;
  dp[23][11] = 588102612;
  dp[23][12] = 801695573;
  dp[23][13] = 138960083;
  dp[23][14] = 24011149;
  dp[23][15] = 4141372;
  dp[23][16] = 713469;
  dp[23][17] = 122678;
  dp[23][18] = 21105;
  dp[23][19] = 3613;
  dp[23][20] = 625;
  dp[23][21] = 106;
  dp[23][22] = 19;
  dp[23][23] = 3;
  dp[23][24] = 1;
  dp[24][1] = 0;
  dp[24][2] = 499072817;
  dp[24][3] = 566780682;
  dp[24][4] = 543283862;
  dp[24][5] = 201724451;
  dp[24][6] = 58271802;
  dp[24][7] = 344858002;
  dp[24][8] = 63874460;
  dp[24][9] = 300408434;
  dp[24][10] = 761612286;
  dp[24][11] = 353031679;
  dp[24][12] = 623964235;
  dp[24][13] = 803344922;
  dp[24][14] = 139021264;
  dp[24][15] = 24013040;
  dp[24][16] = 4141418;
  dp[24][17] = 713470;
  dp[24][18] = 122678;
  dp[24][19] = 21105;
  dp[24][20] = 3613;
  dp[24][21] = 625;
  dp[24][22] = 106;
  dp[24][23] = 19;
  dp[24][24] = 3;
  dp[24][25] = 1;
  dp[25][1] = 0;
  dp[25][2] = 576529878;
  dp[25][3] = 241212759;
  dp[25][4] = 870406317;
  dp[25][5] = 516608637;
  dp[25][6] = 786808826;
  dp[25][7] = 170564828;
  dp[25][8] = 502043776;
  dp[25][9] = 190085463;
  dp[25][10] = 974194583;
  dp[25][11] = 74582715;
  dp[25][12] = 628375911;
  dp[25][13] = 637942018;
  dp[25][14] = 803919124;
  dp[25][15] = 139040931;
  dp[25][16] = 24013603;
  dp[25][17] = 4141431;
  dp[25][18] = 713470;
  dp[25][19] = 122678;
  dp[25][20] = 21105;
  dp[25][21] = 3613;
  dp[25][22] = 625;
  dp[25][23] = 106;
  dp[25][24] = 19;
  dp[25][25] = 3;
  dp[25][26] = 1;
  dp[26][1] = 0;
  dp[26][2] = 282664742;
  dp[26][3] = 137969620;
  dp[26][4] = 386494112;
  dp[26][5] = 872056910;
  dp[26][6] = 282992318;
  dp[26][7] = 176896609;
  dp[26][8] = 111724215;
  dp[26][9] = 824867747;
  dp[26][10] = 799878112;
  dp[26][11] = 461513992;
  dp[26][12] = 110630666;
  dp[26][13] = 741379513;
  dp[26][14] = 643041881;
  dp[26][15] = 804110861;
  dp[26][16] = 139047082;
  dp[26][17] = 24013770;
  dp[26][18] = 4141434;
  dp[26][19] = 713470;
  dp[26][20] = 122678;
  dp[26][21] = 21105;
  dp[26][22] = 3613;
  dp[26][23] = 625;
  dp[26][24] = 106;
  dp[26][25] = 19;
  dp[26][26] = 3;
  dp[26][27] = 1;
  dp[27][1] = 0;
  dp[27][2] = 608570317;
  dp[27][3] = 801652211;
  dp[27][4] = 274963061;
  dp[27][5] = 886518820;
  dp[27][6] = 90837790;
  dp[27][7] = 626361724;
  dp[27][8] = 699033037;
  dp[27][9] = 540982188;
  dp[27][10] = 987824503;
  dp[27][11] = 727135089;
  dp[27][12] = 45389606;
  dp[27][13] = 987874590;
  dp[27][14] = 784549175;
  dp[27][15] = 644812246;
  dp[27][16] = 804173102;
  dp[27][17] = 139048976;
  dp[27][18] = 24013816;
  dp[27][19] = 4141435;
  dp[27][20] = 713470;
  dp[27][21] = 122678;
  dp[27][22] = 21105;
  dp[27][23] = 3613;
  dp[27][24] = 625;
  dp[27][25] = 106;
  dp[27][26] = 19;
  dp[27][27] = 3;
  dp[27][28] = 1;
  dp[28][1] = 0;
  dp[28][2] = 357486479;
  dp[28][3] = 181089468;
  dp[28][4] = 969172260;
  dp[28][5] = 289931681;
  dp[28][6] = 772500290;
  dp[28][7] = 740282998;
  dp[28][8] = 829587032;
  dp[28][9] = 842625948;
  dp[28][10] = 138113736;
  dp[28][11] = 232645342;
  dp[28][12] = 395674948;
  dp[28][13] = 621904062;
  dp[28][14] = 338297429;
  dp[28][15] = 800139849;
  dp[28][16] = 645406477;
  dp[28][17] = 804192896;
  dp[28][18] = 139049539;
  dp[28][19] = 24013829;
  dp[28][20] = 4141435;
  dp[28][21] = 713470;
  dp[28][22] = 122678;
  dp[28][23] = 21105;
  dp[28][24] = 3613;
  dp[28][25] = 625;
  dp[28][26] = 106;
  dp[28][27] = 19;
  dp[28][28] = 3;
  dp[28][29] = 1;
  dp[29][1] = 0;
  dp[29][2] = 254234510;
  dp[29][3] = 292608126;
  dp[29][4] = 417414987;
  dp[29][5] = 111595904;
  dp[29][6] = 430339254;
  dp[29][7] = 77443136;
  dp[29][8] = 291720282;
  dp[29][9] = 257053540;
  dp[29][10] = 606934755;
  dp[29][11] = 335685102;
  dp[29][12] = 729928927;
  dp[29][13] = 235560375;
  dp[29][14] = 363847245;
  dp[29][15] = 469945923;
  dp[29][16] = 805548789;
  dp[29][17] = 645601127;
  dp[29][18] = 804199060;
  dp[29][19] = 139049706;
  dp[29][20] = 24013832;
  dp[29][21] = 4141435;
  dp[29][22] = 713470;
  dp[29][23] = 122678;
  dp[29][24] = 21105;
  dp[29][25] = 3613;
  dp[29][26] = 625;
  dp[29][27] = 106;
  dp[29][28] = 19;
  dp[29][29] = 3;
  dp[29][30] = 1;
  dp[30][1] = 0;
  dp[30][2] = 595455172;
  dp[30][3] = 310857698;
  dp[30][4] = 142929150;
  dp[30][5] = 451089427;
  dp[30][6] = 328175846;
  dp[30][7] = 775787438;
  dp[30][8] = 501396673;
  dp[30][9] = 447925018;
  dp[30][10] = 130822422;
  dp[30][11] = 58418115;
  dp[30][12] = 769951318;
  dp[30][13] = 773701088;
  dp[30][14] = 10940059;
  dp[30][15] = 434786651;
  dp[30][16] = 517174485;
  dp[30][17] = 807371391;
  dp[30][18] = 645663741;
  dp[30][19] = 804200955;
  dp[30][20] = 139049752;
  dp[30][21] = 24013833;
  dp[30][22] = 4141435;
  dp[30][23] = 713470;
  dp[30][24] = 122678;
  dp[30][25] = 21105;
  dp[30][26] = 3613;
  dp[30][27] = 625;
  dp[30][28] = 106;
  dp[30][29] = 19;
  dp[30][30] = 3;
  dp[30][31] = 1;
  dp[31][1] = 0;
  dp[31][2] = 349426455;
  dp[31][3] = 464387898;
  dp[31][4] = 431999991;
  dp[31][5] = 893280928;
  dp[31][6] = 77931049;
  dp[31][7] = 52569295;
  dp[31][8] = 64921457;
  dp[31][9] = 666455225;
  dp[31][10] = 189432628;
  dp[31][11] = 773839352;
  dp[31][12] = 165726163;
  dp[31][13] = 690284554;
  dp[31][14] = 801367433;
  dp[31][15] = 438034612;
  dp[31][16] = 832160214;
  dp[31][17] = 533545110;
  dp[31][18] = 807973529;
  dp[31][19] = 645683575;
  dp[31][20] = 804201518;
  dp[31][21] = 139049765;
  dp[31][22] = 24013833;
  dp[31][23] = 4141435;
  dp[31][24] = 713470;
  dp[31][25] = 122678;
  dp[31][26] = 21105;
  dp[31][27] = 3613;
  dp[31][28] = 625;
  dp[31][29] = 106;
  dp[31][30] = 19;
  dp[31][31] = 3;
  dp[31][32] = 1;
  dp[32][1] = 0;
  dp[32][2] = 702575145;
  dp[32][3] = 801280561;
  dp[32][4] = 442448096;
  dp[32][5] = 451076534;
  dp[32][6] = 362114194;
  dp[32][7] = 647176951;
  dp[32][8] = 12722649;
  dp[32][9] = 733600088;
  dp[32][10] = 928868484;
  dp[32][11] = 314273055;
  dp[32][12] = 676922181;
  dp[32][13] = 390832804;
  dp[32][14] = 195357510;
  dp[32][15] = 179246035;
  dp[32][16] = 671930508;
  dp[32][17] = 973917989;
  dp[32][18] = 539088258;
  dp[32][19] = 808169252;
  dp[32][20] = 645689742;
  dp[32][21] = 804201685;
  dp[32][22] = 139049768;
  dp[32][23] = 24013833;
  dp[32][24] = 4141435;
  dp[32][25] = 713470;
  dp[32][26] = 122678;
  dp[32][27] = 21105;
  dp[32][28] = 3613;
  dp[32][29] = 625;
  dp[32][30] = 106;
  dp[32][31] = 19;
  dp[32][32] = 3;
  dp[32][33] = 1;
  dp[33][1] = 0;
  dp[33][2] = 899116600;
  dp[33][3] = 365887165;
  dp[33][4] = 540851416;
  dp[33][5] = 477622706;
  dp[33][6] = 621209745;
  dp[33][7] = 41855534;
  dp[33][8] = 381872526;
  dp[33][9] = 568727969;
  dp[33][10] = 382270909;
  dp[33][11] = 755519068;
  dp[33][12] = 830377562;
  dp[33][13] = 327016443;
  dp[33][14] = 53743758;
  dp[33][15] = 200196957;
  dp[33][16] = 718037620;
  dp[33][17] = 859696293;
  dp[33][18] = 23095734;
  dp[33][19] = 540931780;
  dp[33][20] = 808231993;
  dp[33][21] = 645691637;
  dp[33][22] = 804201731;
  dp[33][23] = 139049769;
  dp[33][24] = 24013833;
  dp[33][25] = 4141435;
  dp[33][26] = 713470;
  dp[33][27] = 122678;
  dp[33][28] = 21105;
  dp[33][29] = 3613;
  dp[33][30] = 625;
  dp[33][31] = 106;
  dp[33][32] = 19;
  dp[33][33] = 3;
  dp[33][34] = 1;
  dp[34][1] = 0;
  dp[34][2] = 28443452;
  dp[34][3] = 454707299;
  dp[34][4] = 720701160;
  dp[34][5] = 419189620;
  dp[34][6] = 636769312;
  dp[34][7] = 212745640;
  dp[34][8] = 720255594;
  dp[34][9] = 47264013;
  dp[34][10] = 4353233;
  dp[34][11] = 571423322;
  dp[34][12] = 317657958;
  dp[34][13] = 770671406;
  dp[34][14] = 566775337;
  dp[34][15] = 229432738;
  dp[34][16] = 486965531;
  dp[34][17] = 377266778;
  dp[34][18] = 282006828;
  dp[34][19] = 39807033;
  dp[34][20] = 541536871;
  dp[34][21] = 808251840;
  dp[34][22] = 645692200;
  dp[34][23] = 804201744;
  dp[34][24] = 139049769;
  dp[34][25] = 24013833;
  dp[34][26] = 4141435;
  dp[34][27] = 713470;
  dp[34][28] = 122678;
  dp[34][29] = 21105;
  dp[34][30] = 3613;
  dp[34][31] = 625;
  dp[34][32] = 106;
  dp[34][33] = 19;
  dp[34][34] = 3;
  dp[34][35] = 1;
  dp[35][1] = 0;
  dp[35][2] = 708370999;
  dp[35][3] = 745748618;
  dp[35][4] = 582217318;
  dp[35][5] = 455319063;
  dp[35][6] = 603859790;
  dp[35][7] = 231341973;
  dp[35][8] = 348942460;
  dp[35][9] = 170184178;
  dp[35][10] = 689724591;
  dp[35][11] = 110508688;
  dp[35][12] = 857619861;
  dp[35][13] = 426992165;
  dp[35][14] = 588329004;
  dp[35][15] = 979260570;
  dp[35][16] = 343202258;
  dp[35][17] = 927818650;
  dp[35][18] = 898766596;
  dp[35][19] = 428587224;
  dp[35][20] = 45404704;
  dp[35][21] = 541732968;
  dp[35][22] = 808258008;
  dp[35][23] = 645692367;
  dp[35][24] = 804201747;
  dp[35][25] = 139049769;
  dp[35][26] = 24013833;
  dp[35][27] = 4141435;
  dp[35][28] = 713470;
  dp[35][29] = 122678;
  dp[35][30] = 21105;
  dp[35][31] = 3613;
  dp[35][32] = 625;
  dp[35][33] = 106;
  dp[35][34] = 19;
  dp[35][35] = 3;
  dp[35][36] = 1;
  dp[36][1] = 0;
  dp[36][2] = 220300732;
  dp[36][3] = 46609850;
  dp[36][4] = 375712662;
  dp[36][5] = 568586423;
  dp[36][6] = 941804380;
  dp[36][7] = 601855282;
  dp[36][8] = 597025225;
  dp[36][9] = 210361053;
  dp[36][10] = 58336959;
  dp[36][11] = 790143347;
  dp[36][12] = 618095230;
  dp[36][13] = 176358732;
  dp[36][14] = 30543080;
  dp[36][15] = 993842771;
  dp[36][16] = 937341158;
  dp[36][17] = 423396479;
  dp[36][18] = 514187911;
  dp[36][19] = 147490617;
  dp[36][20] = 478619188;
  dp[36][21] = 47256254;
  dp[36][22] = 541795749;
  dp[36][23] = 808259903;
  dp[36][24] = 645692413;
  dp[36][25] = 804201748;
  dp[36][26] = 139049769;
  dp[36][27] = 24013833;
  dp[36][28] = 4141435;
  dp[36][29] = 713470;
  dp[36][30] = 122678;
  dp[36][31] = 21105;
  dp[36][32] = 3613;
  dp[36][33] = 625;
  dp[36][34] = 106;
  dp[36][35] = 19;
  dp[36][36] = 3;
  dp[36][37] = 1;
  dp[37][1] = 0;
  dp[37][2] = 491767445;
  dp[37][3] = 782125933;
  dp[37][4] = 760844150;
  dp[37][5] = 771643255;
  dp[37][6] = 631272756;
  dp[37][7] = 200568934;
  dp[37][8] = 776727389;
  dp[37][9] = 125809805;
  dp[37][10] = 89178072;
  dp[37][11] = 942931662;
  dp[37][12] = 158053887;
  dp[37][13] = 262399651;
  dp[37][14] = 379208459;
  dp[37][15] = 503988395;
  dp[37][16] = 438193938;
  dp[37][17] = 774920020;
  dp[37][18] = 818726507;
  dp[37][19] = 874419280;
  dp[37][20] = 581626996;
  dp[37][21] = 495470440;
  dp[37][22] = 47862421;
  dp[37][23] = 541815599;
  dp[37][24] = 808260466;
  dp[37][25] = 645692426;
  dp[37][26] = 804201748;
  dp[37][27] = 139049769;
  dp[37][28] = 24013833;
  dp[37][29] = 4141435;
  dp[37][30] = 713470;
  dp[37][31] = 122678;
  dp[37][32] = 21105;
  dp[37][33] = 3613;
  dp[37][34] = 625;
  dp[37][35] = 106;
  dp[37][36] = 19;
  dp[37][37] = 3;
  dp[37][38] = 1;
  dp[38][1] = 0;
  dp[38][2] = 751552393;
  dp[38][3] = 507106191;
  dp[38][4] = 927020229;
  dp[38][5] = 340983299;
  dp[38][6] = 824935876;
  dp[38][7] = 982944264;
  dp[38][8] = 112403021;
  dp[38][9] = 736470034;
  dp[38][10] = 712046769;
  dp[38][11] = 464383985;
  dp[38][12] = 718862672;
  dp[38][13] = 472451638;
  dp[38][14] = 74303981;
  dp[38][15] = 410907563;
  dp[38][16] = 666832122;
  dp[38][17] = 904514562;
  dp[38][18] = 425593301;
  dp[38][19] = 712078493;
  dp[38][20] = 543662654;
  dp[38][21] = 730328807;
  dp[38][22] = 501089364;
  dp[38][23] = 48058645;
  dp[38][24] = 541821767;
  dp[38][25] = 808260633;
  dp[38][26] = 645692429;
  dp[38][27] = 804201748;
  dp[38][28] = 139049769;
  dp[38][29] = 24013833;
  dp[38][30] = 4141435;
  dp[38][31] = 713470;
  dp[38][32] = 122678;
  dp[38][33] = 21105;
  dp[38][34] = 3613;
  dp[38][35] = 625;
  dp[38][36] = 106;
  dp[38][37] = 19;
  dp[38][38] = 3;
  dp[38][39] = 1;
  dp[39][1] = 0;
  dp[39][2] = 73145977;
  dp[39][3] = 945393539;
  dp[39][4] = 491610692;
  dp[39][5] = 289456339;
  dp[39][6] = 427592987;
  dp[39][7] = 156456089;
  dp[39][8] = 856721546;
  dp[39][9] = 643411286;
  dp[39][10] = 438709919;
  dp[39][11] = 830334785;
  dp[39][12] = 521084183;
  dp[39][13] = 802961067;
  dp[39][14] = 577757709;
  dp[39][15] = 979743576;
  dp[39][16] = 751951426;
  dp[39][17] = 169028881;
  dp[39][18] = 473063432;
  dp[39][19] = 677653095;
  dp[39][20] = 991492477;
  dp[39][21] = 821146133;
  dp[39][22] = 780715488;
  dp[39][23] = 502943880;
  dp[39][24] = 48121439;
  dp[39][25] = 541823662;
  dp[39][26] = 808260679;
  dp[39][27] = 645692430;
  dp[39][28] = 804201748;
  dp[39][29] = 139049769;
  dp[39][30] = 24013833;
  dp[39][31] = 4141435;
  dp[39][32] = 713470;
  dp[39][33] = 122678;
  dp[39][34] = 21105;
  dp[39][35] = 3613;
  dp[39][36] = 625;
  dp[39][37] = 106;
  dp[39][38] = 19;
  dp[39][39] = 3;
  dp[39][40] = 1;
  dp[40][1] = 0;
  dp[40][2] = 437082018;
  dp[40][3] = 559756622;
  dp[40][4] = 712764202;
  dp[40][5] = 175256028;
  dp[40][6] = 39001965;
  dp[40][7] = 169118126;
  dp[40][8] = 961041841;
  dp[40][9] = 330531579;
  dp[40][10] = 726355685;
  dp[40][11] = 652058564;
  dp[40][12] = 184476311;
  dp[40][13] = 959023349;
  dp[40][14] = 36529059;
  dp[40][15] = 566693578;
  dp[40][16] = 286624497;
  dp[40][17] = 631545034;
  dp[40][18] = 213553699;
  dp[40][19] = 420454245;
  dp[40][20] = 108890823;
  dp[40][21] = 707021032;
  dp[40][22] = 260499053;
  dp[40][23] = 797622167;
  dp[40][24] = 503550421;
  dp[40][25] = 48141290;
  dp[40][26] = 541824225;
  dp[40][27] = 808260692;
  dp[40][28] = 645692430;
  dp[40][29] = 804201748;
  dp[40][30] = 139049769;
  dp[40][31] = 24013833;
  dp[40][32] = 4141435;
  dp[40][33] = 713470;
  dp[40][34] = 122678;
  dp[40][35] = 21105;
  dp[40][36] = 3613;
  dp[40][37] = 625;
  dp[40][38] = 106;
  dp[40][39] = 19;
  dp[40][40] = 3;
  dp[40][41] = 1;
  dp[41][1] = 0;
  dp[41][2] = 911273698;
  dp[41][3] = 461802381;
  dp[41][4] = 157547978;
  dp[41][5] = 651886959;
  dp[41][6] = 991079947;
  dp[41][7] = 904206440;
  dp[41][8] = 752012728;
  dp[41][9] = 91490856;
  dp[41][10] = 970456086;
  dp[41][11] = 827908805;
  dp[41][12] = 200404310;
  dp[41][13] = 46817164;
  dp[41][14] = 95037060;
  dp[41][15] = 872320139;
  dp[41][16] = 544155656;
  dp[41][17] = 866678032;
  dp[41][18] = 265740321;
  dp[41][19] = 62232640;
  dp[41][20] = 640825471;
  dp[41][21] = 56958810;
  dp[41][22] = 445660277;
  dp[41][23] = 410088790;
  dp[41][24] = 803249159;
  dp[41][25] = 503746685;
  dp[41][26] = 48147458;
  dp[41][27] = 541824392;
  dp[41][28] = 808260695;
  dp[41][29] = 645692430;
  dp[41][30] = 804201748;
  dp[41][31] = 139049769;
  dp[41][32] = 24013833;
  dp[41][33] = 4141435;
  dp[41][34] = 713470;
  dp[41][35] = 122678;
  dp[41][36] = 21105;
  dp[41][37] = 3613;
  dp[41][38] = 625;
  dp[41][39] = 106;
  dp[41][40] = 19;
  dp[41][41] = 3;
  dp[41][42] = 1;
  dp[42][1] = 0;
  dp[42][2] = 99547327;
  dp[42][3] = 792772093;
  dp[42][4] = 413279596;
  dp[42][5] = 39759631;
  dp[42][6] = 598831434;
  dp[42][7] = 274143461;
  dp[42][8] = 681931397;
  dp[42][9] = 242545472;
  dp[42][10] = 634618776;
  dp[42][11] = 733602547;
  dp[42][12] = 401821126;
  dp[42][13] = 689076310;
  dp[42][14] = 138792047;
  dp[42][15] = 867529343;
  dp[42][16] = 871445219;
  dp[42][17] = 80442445;
  dp[42][18] = 172358416;
  dp[42][19] = 884450832;
  dp[42][20] = 787463230;
  dp[42][21] = 130635330;
  dp[42][22] = 184459417;
  dp[42][23] = 735860525;
  dp[42][24] = 460617750;
  dp[42][25] = 805104752;
  dp[42][26] = 503809482;
  dp[42][27] = 48149353;
  dp[42][28] = 541824438;
  dp[42][29] = 808260696;
  dp[42][30] = 645692430;
  dp[42][31] = 804201748;
  dp[42][32] = 139049769;
  dp[42][33] = 24013833;
  dp[42][34] = 4141435;
  dp[42][35] = 713470;
  dp[42][36] = 122678;
  dp[42][37] = 21105;
  dp[42][38] = 3613;
  dp[42][39] = 625;
  dp[42][40] = 106;
  dp[42][41] = 19;
  dp[42][42] = 3;
  dp[42][43] = 1;
  dp[43][1] = 0;
  dp[43][2] = 482186350;
  dp[43][3] = 273967294;
  dp[43][4] = 649045886;
  dp[43][5] = 108980254;
  dp[43][6] = 570311699;
  dp[43][7] = 966889002;
  dp[43][8] = 666859727;
  dp[43][9] = 546817455;
  dp[43][10] = 689881573;
  dp[43][11] = 84630300;
  dp[43][12] = 893298736;
  dp[43][13] = 354835358;
  dp[43][14] = 214615309;
  dp[43][15] = 168750989;
  dp[43][16] = 158197112;
  dp[43][17] = 45797168;
  dp[43][18] = 168957735;
  dp[43][19] = 782446817;
  dp[43][20] = 163825770;
  dp[43][21] = 628696027;
  dp[43][22] = 196779450;
  dp[43][23] = 66205132;
  dp[43][24] = 177414259;
  dp[43][25] = 477545803;
  dp[43][26] = 805711420;
  dp[43][27] = 503829333;
  dp[43][28] = 48149916;
  dp[43][29] = 541824451;
  dp[43][30] = 808260696;
  dp[43][31] = 645692430;
  dp[43][32] = 804201748;
  dp[43][33] = 139049769;
  dp[43][34] = 24013833;
  dp[43][35] = 4141435;
  dp[43][36] = 713470;
  dp[43][37] = 122678;
  dp[43][38] = 21105;
  dp[43][39] = 3613;
  dp[43][40] = 625;
  dp[43][41] = 106;
  dp[43][42] = 19;
  dp[43][43] = 3;
  dp[43][44] = 1;
  dp[44][1] = 0;
  dp[44][2] = 725343523;
  dp[44][3] = 72904069;
  dp[44][4] = 317229993;
  dp[44][5] = 651086888;
  dp[44][6] = 760199404;
  dp[44][7] = 971917773;
  dp[44][8] = 359172971;
  dp[44][9] = 877096152;
  dp[44][10] = 866895001;
  dp[44][11] = 443077851;
  dp[44][12] = 620349470;
  dp[44][13] = 706453237;
  dp[44][14] = 575090255;
  dp[44][15] = 745511976;
  dp[44][16] = 849766738;
  dp[44][17] = 965850920;
  dp[44][18] = 588577451;
  dp[44][19] = 178627725;
  dp[44][20] = 235164813;
  dp[44][21] = 372125002;
  dp[44][22] = 603898412;
  dp[44][23] = 155168897;
  dp[44][24] = 835596754;
  dp[44][25] = 327364579;
  dp[44][26] = 483175764;
  dp[44][27] = 805907697;
  dp[44][28] = 503835501;
  dp[44][29] = 48150083;
  dp[44][30] = 541824454;
  dp[44][31] = 808260696;
  dp[44][32] = 645692430;
  dp[44][33] = 804201748;
  dp[44][34] = 139049769;
  dp[44][35] = 24013833;
  dp[44][36] = 4141435;
  dp[44][37] = 713470;
  dp[44][38] = 122678;
  dp[44][39] = 21105;
  dp[44][40] = 3613;
  dp[44][41] = 625;
  dp[44][42] = 106;
  dp[44][43] = 19;
  dp[44][44] = 3;
  dp[44][45] = 1;
  dp[45][1] = 0;
  dp[45][2] = 227169509;
  dp[45][3] = 545240090;
  dp[45][4] = 21373631;
  dp[45][5] = 4703558;
  dp[45][6] = 149454127;
  dp[45][7] = 906947250;
  dp[45][8] = 436226575;
  dp[45][9] = 231453773;
  dp[45][10] = 520829752;
  dp[45][11] = 657885509;
  dp[45][12] = 940170245;
  dp[45][13] = 816566317;
  dp[45][14] = 211196753;
  dp[45][15] = 118819980;
  dp[45][16] = 726741982;
  dp[45][17] = 596789649;
  dp[45][18] = 939963244;
  dp[45][19] = 486112971;
  dp[45][20] = 653096931;
  dp[45][21] = 608998341;
  dp[45][22] = 286609915;
  dp[45][23] = 821835078;
  dp[45][24] = 678102815;
  dp[45][25] = 131197840;
  dp[45][26] = 377949300;
  dp[45][27] = 485031731;
  dp[45][28] = 805970495;
  dp[45][29] = 503837396;
  dp[45][30] = 48150129;
  dp[45][31] = 541824455;
  dp[45][32] = 808260696;
  dp[45][33] = 645692430;
  dp[45][34] = 804201748;
  dp[45][35] = 139049769;
  dp[45][36] = 24013833;
  dp[45][37] = 4141435;
  dp[45][38] = 713470;
  dp[45][39] = 122678;
  dp[45][40] = 21105;
  dp[45][41] = 3613;
  dp[45][42] = 625;
  dp[45][43] = 106;
  dp[45][44] = 19;
  dp[45][45] = 3;
  dp[45][46] = 1;
  dp[46][1] = 0;
  dp[46][2] = 812941513;
  dp[46][3] = 632016277;
  dp[46][4] = 587752971;
  dp[46][5] = 907369437;
  dp[46][6] = 245365463;
  dp[46][7] = 237152744;
  dp[46][8] = 770806419;
  dp[46][9] = 254057260;
  dp[46][10] = 256931484;
  dp[46][11] = 657088179;
  dp[46][12] = 685991399;
  dp[46][13] = 165335468;
  dp[46][14] = 793178596;
  dp[46][15] = 943503554;
  dp[46][16] = 488208964;
  dp[46][17] = 862646224;
  dp[46][18] = 801219250;
  dp[46][19] = 113427800;
  dp[46][20] = 680954452;
  dp[46][21] = 973579312;
  dp[46][22] = 138931569;
  dp[46][23] = 370928377;
  dp[46][24] = 622393891;
  dp[46][25] = 633659803;
  dp[46][26] = 573653877;
  dp[46][27] = 394885434;
  dp[46][28] = 485638439;
  dp[46][29] = 805990346;
  dp[46][30] = 503837959;
  dp[46][31] = 48150142;
  dp[46][32] = 541824455;
  dp[46][33] = 808260696;
  dp[46][34] = 645692430;
  dp[46][35] = 804201748;
  dp[46][36] = 139049769;
  dp[46][37] = 24013833;
  dp[46][38] = 4141435;
  dp[46][39] = 713470;
  dp[46][40] = 122678;
  dp[46][41] = 21105;
  dp[46][42] = 3613;
  dp[46][43] = 625;
  dp[46][44] = 106;
  dp[46][45] = 19;
  dp[46][46] = 3;
  dp[46][47] = 1;
  dp[47][1] = 0;
  dp[47][2] = 831284912;
  dp[47][3] = 920930216;
  dp[47][4] = 121837637;
  dp[47][5] = 363197429;
  dp[47][6] = 615372675;
  dp[47][7] = 818973396;
  dp[47][8] = 465784421;
  dp[47][9] = 249654262;
  dp[47][10] = 962863505;
  dp[47][11] = 443733107;
  dp[47][12] = 862431829;
  dp[47][13] = 259718701;
  dp[47][14] = 674328903;
  dp[47][15] = 72003370;
  dp[47][16] = 27941538;
  dp[47][17] = 457774123;
  dp[47][18] = 769643354;
  dp[47][19] = 316096474;
  dp[47][20] = 198211169;
  dp[47][21] = 732391072;
  dp[47][22] = 973293491;
  dp[47][23] = 813065869;
  dp[47][24] = 598354179;
  dp[47][25] = 515441584;
  dp[47][26] = 416189909;
  dp[47][27] = 723747383;
  dp[47][28] = 400516472;
  dp[47][29] = 485834719;
  dp[47][30] = 805996514;
  dp[47][31] = 503838126;
  dp[47][32] = 48150145;
  dp[47][33] = 541824455;
  dp[47][34] = 808260696;
  dp[47][35] = 645692430;
  dp[47][36] = 804201748;
  dp[47][37] = 139049769;
  dp[47][38] = 24013833;
  dp[47][39] = 4141435;
  dp[47][40] = 713470;
  dp[47][41] = 122678;
  dp[47][42] = 21105;
  dp[47][43] = 3613;
  dp[47][44] = 625;
  dp[47][45] = 106;
  dp[47][46] = 19;
  dp[47][47] = 3;
  dp[47][48] = 1;
  dp[48][1] = 0;
  dp[48][2] = 833292674;
  dp[48][3] = 298848298;
  dp[48][4] = 168903770;
  dp[48][5] = 545074331;
  dp[48][6] = 52799215;
  dp[48][7] = 758871225;
  dp[48][8] = 252495511;
  dp[48][9] = 924121755;
  dp[48][10] = 374266136;
  dp[48][11] = 669478514;
  dp[48][12] = 60769576;
  dp[48][13] = 806058403;
  dp[48][14] = 907911655;
  dp[48][15] = 394903137;
  dp[48][16] = 121208854;
  dp[48][17] = 373718471;
  dp[48][18] = 645725760;
  dp[48][19] = 64527479;
  dp[48][20] = 804531912;
  dp[48][21] = 436447112;
  dp[48][22] = 588689529;
  dp[48][23] = 502994369;
  dp[48][24] = 593283887;
  dp[48][25] = 897804374;
  dp[48][26] = 214286791;
  dp[48][27] = 714026394;
  dp[48][28] = 774353518;
  dp[48][29] = 402372566;
  dp[48][30] = 485897517;
  dp[48][31] = 805998409;
  dp[48][32] = 503838172;
  dp[48][33] = 48150146;
  dp[48][34] = 541824455;
  dp[48][35] = 808260696;
  dp[48][36] = 645692430;
  dp[48][37] = 804201748;
  dp[48][38] = 139049769;
  dp[48][39] = 24013833;
  dp[48][40] = 4141435;
  dp[48][41] = 713470;
  dp[48][42] = 122678;
  dp[48][43] = 21105;
  dp[48][44] = 3613;
  dp[48][45] = 625;
  dp[48][46] = 106;
  dp[48][47] = 19;
  dp[48][48] = 3;
  dp[48][49] = 1;
  dp[49][1] = 0;
  dp[49][2] = 987390633;
  dp[49][3] = 352790884;
  dp[49][4] = 614135688;
  dp[49][5] = 73248057;
  dp[49][6] = 535068088;
  dp[49][7] = 778378333;
  dp[49][8] = 304699153;
  dp[49][9] = 787437186;
  dp[49][10] = 778598899;
  dp[49][11] = 436272891;
  dp[49][12] = 717326240;
  dp[49][13] = 327325089;
  dp[49][14] = 183229809;
  dp[49][15] = 956509573;
  dp[49][16] = 178816507;
  dp[49][17] = 780681714;
  dp[49][18] = 939063227;
  dp[49][19] = 78846995;
  dp[49][20] = 42468967;
  dp[49][21] = 482999731;
  dp[49][22] = 874463719;
  dp[49][23] = 105692341;
  dp[49][24] = 586003573;
  dp[49][25] = 658414122;
  dp[49][26] = 894144031;
  dp[49][27] = 201549678;
  dp[49][28] = 156845346;
  dp[49][29] = 791292622;
  dp[49][30] = 402979287;
  dp[49][31] = 485917368;
  dp[49][32] = 805998972;
  dp[49][33] = 503838185;
  dp[49][34] = 48150146;
  dp[49][35] = 541824455;
  dp[49][36] = 808260696;
  dp[49][37] = 645692430;
  dp[49][38] = 804201748;
  dp[49][39] = 139049769;
  dp[49][40] = 24013833;
  dp[49][41] = 4141435;
  dp[49][42] = 713470;
  dp[49][43] = 122678;
  dp[49][44] = 21105;
  dp[49][45] = 3613;
  dp[49][46] = 625;
  dp[49][47] = 106;
  dp[49][48] = 19;
  dp[49][49] = 3;
  dp[49][50] = 1;
  dp[50][1] = 0;
  dp[50][2] = 637245807;
  dp[50][3] = 499830334;
  dp[50][4] = 750632612;
  dp[50][5] = 151627894;
  dp[50][6] = 974119694;
  dp[50][7] = 567468624;
  dp[50][8] = 244879604;
  dp[50][9] = 269170082;
  dp[50][10] = 396392266;
  dp[50][11] = 280843475;
  dp[50][12] = 343181990;
  dp[50][13] = 746080370;
  dp[50][14] = 730888752;
  dp[50][15] = 810540922;
  dp[50][16] = 910735707;
  dp[50][17] = 103336517;
  dp[50][18] = 104943638;
  dp[50][19] = 266354616;
  dp[50][20] = 664188130;
  dp[50][21] = 338775312;
  dp[50][22] = 887579699;
  dp[50][23] = 740792318;
  dp[50][24] = 467888722;
  dp[50][25] = 667892662;
  dp[50][26] = 673680617;
  dp[50][27] = 203733589;
  dp[50][28] = 989562192;
  dp[50][29] = 306994734;
  dp[50][30] = 796924034;
  dp[50][31] = 403175568;
  dp[50][32] = 485923536;
  dp[50][33] = 805999139;
  dp[50][34] = 503838188;
  dp[50][35] = 48150146;
  dp[50][36] = 541824455;
  dp[50][37] = 808260696;
  dp[50][38] = 645692430;
  dp[50][39] = 804201748;
  dp[50][40] = 139049769;
  dp[50][41] = 24013833;
  dp[50][42] = 4141435;
  dp[50][43] = 713470;
  dp[50][44] = 122678;
  dp[50][45] = 21105;
  dp[50][46] = 3613;
  dp[50][47] = 625;
  dp[50][48] = 106;
  dp[50][49] = 19;
  dp[50][50] = 3;
  dp[50][51] = 1;
  int a, b;
  cin >> a >> b;
  cout << dp[a][b] << "\n";
}