#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include "camera_custom_nvram.h"
#include "camera_custom_lens.h"
const NVRAM_LENS_PARA_STRUCT DW9714AF_OV8858_LENS_PARA_DEFAULT_VALUE = 
{1, // Version

rFocusRange: {0, // i4InfPos
1023, // i4MacroPos
},

rAFNVRAM: {
sAF_Coef: {
sTABLE: {70, // i4Offset
14, // i4NormalNum
14, // i4MacroNum
0, // i4InfIdxOffset
0, // i4MacroIdxOffset
{0, 20, 56, 114, 145, 171, 215, 268, 293, 335, 385, 435, 505, 585, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4Pos
},
15, // i4THRES_MAIN
10, // i4THRES_SUB
1, // i4AFC_FAIL_CNT
0, // i4FAIL_POS
4, // i4INIT_WAIT
{500, 500, 500, 500, 500, },// i4FRAME_WAIT
0, // i4DONE_WAIT
},

sVAFC_Coef: {
sTABLE: {70, // i4Offset
14, // i4NormalNum
14, // i4MacroNum
0, // i4InfIdxOffset
0, // i4MacroIdxOffset
{0, 20, 56, 114, 145, 171, 215, 268, 293, 335, 385, 435, 505, 585, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4Pos
},
15, // i4THRES_MAIN
10, // i4THRES_SUB
1, // i4AFC_FAIL_CNT
-1, // i4FAIL_POS
4, // i4INIT_WAIT
{0, 0, 100, 500, 500, },// i4FRAME_WAIT
0, // i4DONE_WAIT
},

sAF_TH: {8, // i4ISONum
{100, 150, 200, 300, 400, 600, 800, 1600, },// i4ISO
{21, 21, 21, 20, 20, 19, 19, 18, 30, 30, 30, 30, 29, 29, 28, 27, 44, 44, 43, 43, 
43, 42, 42, 40, 63, 62, 62, 62, 62, 61, 61, 60, 89, 89, 89, 89, 88, 88, 88, 87, 
124, 126, 121, 116, 111, 113, 112, 111, 178, 180, 177, 174, 171, 172, 171, 171, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, },// i4MIN_TH
{2, 2, 2, 2, 3, 3, 4, 4, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{2, 2, 2, 2, 3, 3, 4, 4, },// i4HW_TH2
},

sZSD_AF_TH: {8, // i4ISONum
{100, 150, 200, 300, 400, 600, 800, 1600, },// i4ISO
{20, 19, 19, 18, 18, 17, 16, 14, 29, 29, 28, 28, 27, 26, 25, 23, 43, 42, 42, 41, 
40, 40, 39, 36, 62, 61, 61, 60, 60, 59, 58, 56, 88, 88, 88, 87, 87, 86, 85, 83, 
126, 126, 126, 125, 125, 124, 124, 122, 180, 180, 180, 179, 179, 179, 179, 177, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{2000, 2000, 2000, 1000, 1000, 1000, 1000, 1000, },// i4MIN_TH
{2, 2, 2, 2, 3, 3, 4, 4, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{2, 2, 2, 2, 3, 3, 4, 4, },// i4HW_TH2
},

sVID_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sVID1_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sVID2_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sIHDR_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sREV1_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sREV2_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sREV3_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sREV4_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},

sREV5_AF_TH: {0, // i4ISONum
{0, 0, 0, 0, 0, 0, 0, 0, },// i4ISO
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4GMR
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH
{0, 0, 0, 0, 0, 0, 0, 0, },// i4FV_DC2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4MIN_TH2
{0, 0, 0, 0, 0, 0, 0, 0, },// i4HW_TH2
},
0, // i4ReadOTP
3, // i4StatGain
0, // i4LV_THRES
170, // i4InfPos
33, // i4FRAME_TIME
{0, 100, 200, 350, 500, },// i4BackJump
500, // i4BackJumpPos
20, // i4AFC_STEP_SIZE
18, // i4SPOT_PERCENT_W
24, // i4SPOT_PERCENT_H
0, // i4CHANGE_CNT_DELTA
1, // i4AFS_STEP_MIN_ENABLE
4, // i4AFS_STEP_MIN_NORMAL
4, // i4AFS_STEP_MIN_MACRO
5, // i4FIRST_FV_WAIT
12, // i4FV_1ST_STABLE_THRES
10000, // i4FV_1ST_STABLE_OFFSET
6, // i4FV_1ST_STABLE_NUM
6, // i4FV_1ST_STABLE_CNT
50, // i4FV_SHOCK_THRES
30000, // i4FV_SHOCK_OFFSET
5, // i4FV_VALID_CNT
20, // i4FV_SHOCK_FRM_CNT
5, // i4FV_SHOCK_CNT
90, // i4FDWinPercent
40, // i4FDSizeDiff
10, // i4FD_DETECT_CNT
5, // i4FD_NONE_CNT
1, // i4LeftSearchEnable
0, // i4LeftJumpStep
0, // i4Curve5ptFit
0, // i4AfDoneDelay
0, // i4VdoAfDoneDelay
0, // i4ZoomInWinChg
1, // i4SensorEnable
70, // i4PostureComp
3, // i4SceneMonitorLevel
1, // i4VdoSceneMonitorLevel

sFV: {1, // i4Enable
0, // i4ChgType
100000, // i4ChgOffset
{20, 20, 10, },// i4ChgThr
{10, 5, 5, },// i4ChgCnt
1, // i4StbType
50000, // i4StbOffset
{25, 25, 25, },// i4StbThr
{10, 7, 5, },// i4StbCnt
},

sGS: {1, // i4Enable
0, // i4ChgType
15, // i4ChgOffset
{20, 20, 15, },// i4ChgThr
{15, 10, 10, },// i4ChgCnt
1, // i4StbType
5, // i4StbOffset
{5, 10, 10, },// i4StbThr
{10, 7, 5, },// i4StbCnt
},

sAEB: {1, // i4Enable
0, // i4ChgType
15, // i4ChgOffset
{30, 30, 25, },// i4ChgThr
{33, 30, 30, },// i4ChgCnt
1, // i4StbType
5, // i4StbOffset
{10, 10, 10, },// i4StbThr
{10, 7, 5, },// i4StbCnt
},

sGYRO: {1, // i4Enable
0, // i4ChgType
0, // i4ChgOffset
{40, 40, 20, },// i4ChgThr
{5, 3, 3, },// i4ChgCnt
1, // i4StbType
0, // i4StbOffset
{10, 10, 10, },// i4StbThr
{10, 7, 5, },// i4StbCnt
},

sACCE: {1, // i4Enable
0, // i4ChgType
0, // i4ChgOffset
{80, 80, 60, },// i4ChgThr
{15, 12, 12, },// i4ChgCnt
1, // i4StbType
0, // i4StbOffset
{50, 50, 50, },// i4StbThr
{10, 7, 5, },// i4StbCnt
},

sVdoFV: {1, // i4Enable
0, // i4ChgType
100000, // i4ChgOffset
{40, 40, 30, },// i4ChgThr
{20, 15, 15, },// i4ChgCnt
1, // i4StbType
50000, // i4StbOffset
{20, 20, 20, },// i4StbThr
{20, 15, 10, },// i4StbCnt
},

sVdoGS: {1, // i4Enable
0, // i4ChgType
15, // i4ChgOffset
{20, 20, 15, },// i4ChgThr
{28, 25, 25, },// i4ChgCnt
1, // i4StbType
5, // i4StbOffset
{5, 5, 5, },// i4StbThr
{15, 13, 10, },// i4StbCnt
},

sVdoAEB: {1, // i4Enable
0, // i4ChgType
15, // i4ChgOffset
{30, 30, 25, },// i4ChgThr
{33, 30, 30, },// i4ChgCnt
1, // i4StbType
5, // i4StbOffset
{10, 10, 10, },// i4StbThr
{15, 13, 10, },// i4StbCnt
},

sVdoGYRO: {1, // i4Enable
0, // i4ChgType
0, // i4ChgOffset
{40, 40, 20, },// i4ChgThr
{7, 5, 5, },// i4ChgCnt
1, // i4StbType
0, // i4StbOffset
{10, 10, 10, },// i4StbThr
{15, 13, 10, },// i4StbCnt
},

sVdoACCE: {1, // i4Enable
0, // i4ChgType
0, // i4ChgOffset
{80, 80, 60, },// i4ChgThr
{15, 12, 12, },// i4ChgCnt
1, // i4StbType
0, // i4StbOffset
{50, 50, 50, },// i4StbThr
{13, 13, 10, },// i4StbCnt
},
1, // i4FvExtractEnable
40, // i4FvExtractThr
1, // i4DampingCompEnable
{7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 0, 0, 0, 0, 0, },// i4DampingStep
{-2, -4, -4, -6, -5, -5, -13, -8, -10, -20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4DampingRdirComp
{2, 4, 4, 6, 5, 5, 13, 8, 10, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4DampingLdirComp
1, // i4DirSelectEnable
-1, // i4InfDir
-1, // i4MidDir
-1, // i4MacDir
40, // i4RatioInf
70, // i4RatioMac
1, // i4StartBoundEnable
3, // i4StartCamCAF
3, // i4StartCamTAF
0, // i4StartVdoCAF
0, // i4StartVdoTAF
1, // i4FpsRemapTblEnable
{10, 12, },// i4FpsThres
{0, 0, },// i4TableClipPt
{80, 90, },// i4TableRemapPt
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
},// i4EasyTuning
{12, 120, 10, 30, 70, 100, 1, 100, 100, 100, 0, 0, 0, 0, -1, -2, 0, -7, -1, 0, 
0, 0, 0, 2, 1, 2, 2, 1, 0, 3, 2, 100, 100, 100, 0, 0, 0, 0, -1, -2, 
0, -7, -1, 0, 0, 0, 0, 2, 1, 2, 2, 1, 0, 3, 3, 100, 100, 100, -2, -5, 
-8, -9, -13, -15, -12, -33, -27, -16, 2, 4, 6, 11, 14, 18, 16, 16, 20, 48, 4, 100, 
100, 100, -3, -7, -12, -12, -19, -21, -29, -40, -52, -26, 3, 7, 9, 17, 20, 25, 29, 23, 
28, 60, 5, 80, 80, 80, -3, -7, -12, -12, -19, -21, -29, -40, -52, -26, 3, 7, 9, 17, 
20, 25, 29, 23, 28, 60, 6, 66, 66, 66, -3, -7, -12, -12, -19, -21, -29, -40, -52, -26, 
3, 7, 9, 17, 20, 25, 29, 23, 28, 60, 7, 57, 57, 57, -3, -7, -12, -12, -19, -21, 
-29, -40, -52, -26, 3, 7, 9, 17, 20, 25, 29, 23, 28, 60, 8, 50, 50, 50, -3, -7, 
-12, -12, -19, -21, -29, -40, -52, -26, 3, 7, 9, 17, 20, 25, 29, 23, 28, 60, 9, 44, 
44, 44, -3, -7, -12, -12, -19, -21, -29, -40, -52, -26, 3, 7, 9, 17, 20, 25, 29, 23, 
28, 60, 10, 40, 40, 40, -3, -7, -12, -12, -19, -21, -29, -40, -52, -26, 3, 7, 9, 17, 
20, 25, 29, 23, 28, 60, 11, 36, 36, 36, -3, -7, -12, -12, -19, -21, -29, -40, -52, -26, 
3, 7, 9, 17, 20, 25, 29, 23, 28, 60, 12, 33, 33, 33, -3, -7, -12, -12, -19, -21, 
-29, -40, -52, -26, 3, 7, 9, 17, 20, 25, 29, 23, 28, 60, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
},// i4DepthAF
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 10, 40, 5, 100, 50, 150, 10, 0, 
0, 1, 30, 50, 5, 100, 50, 150, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 30, 100, 90, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
},// i4Coefs
},

rPDNVRAM: {
rCaliData: {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, },// uData
0, // i4Size
},

rTuningData: {0, // i4FocusPDSizeX
0, // i4FocusPDSizeY
{0, 0, 0, 0, 0, },// i4ConfIdx1
{0, 0, 0, 0, 0, },// i4ConfIdx2
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },// i4ConfTbl
0, // i4SaturateLevel
0, // i4SaturateThr
0, // i4ConfThr
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
},// i4Reserved
},
},
};

UINT32 DW9714AF_OV8858_getDefaultData(VOID *pDataBuf, UINT32 size)
{
    UINT32 dataSize = sizeof(NVRAM_LENS_PARA_STRUCT);

    if ((pDataBuf == NULL) || (size < dataSize))
    {
        return 1;
    }

    // copy from Buff to global struct
    memcpy(pDataBuf, &DW9714AF_OV8858_LENS_PARA_DEFAULT_VALUE, dataSize);

    return 0;
}

PFUNC_GETLENSDEFAULT pDW9714AF_OV8858_getDefaultData = DW9714AF_OV8858_getDefaultData;

