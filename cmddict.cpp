/*
Copyright 2015  Ian Knight <ian@knightly.xyz>

This file is part of atem-cli.

atem-cli is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with atem-cli.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtCore>
#include <QStringList>
#include <QApplication>
#include <iostream>

#include "cliapp.h"
#include "cmddict.h"

#define A0 NULL
#define B0 NULL
#define C0 NULL
#define D0 NULL
#define E0 NULL
#define F0 NULL
#define G0 NULL
#define H0 NULL
#define I0 NULL
#define J0 NULL
#define K0 NULL
#define L0 NULL
#define M0 NULL
#define N0 NULL
#define O0 NULL
#define P0 NULL
#define Q0 NULL
#define R0 NULL
#define S0 NULL
#define T0 NULL
#define U0 NULL
#define V0 NULL
#define W0 NULL
#define X0 NULL
#define Y0 NULL
#define Z0 NULL
 

/* Layer 20 */
/* Layer 19 */
/* Layer 18 */
/* Layer 17 */
/* Layer 16 */
/* Layer 15 */
/* Layer 14 */
/* Layer 13 */
struct CmdTrieNode cmdFTBFRAMESLEFT = {&CmdDict::preFadeToBlackFramesLeft,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer 12 */
struct CmdTrieNode cmdFTBFRAMESLEF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdFTBFRAMESLEFT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOWNCONTYPE = {&CmdDict::preVideoDownConvertType,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer 11 */
struct CmdTrieNode cmdFTBFRAMESLE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdFTBFRAMESLEF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFILLSRC = {&CmdDict::preTransitionDVEFillSource,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOWNCONTYP = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdVDOWNCONTYPE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer 10 */
struct CmdTrieNode cmdTCURRSTYLE = {&CmdDict::preTransitionCurrentStyle,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBFRAMESL = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdFTBFRAMESLE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPFRAMES = {&CmdDict::preTransitionDipFrames,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEEFFECT = {&CmdDict::preTransitionDVEEffect,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFILLSR = {&CmdDict::invalid,{A0, B0, &cmdTDVEFILLSRC, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFRAMES = {&CmdDict::preTransitionDVEFrames,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMIXFRAMES = {&CmdDict::preTransitionMixFrames,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXTSTYLE = {&CmdDict::preTransitionNextStyle,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOWNCONTY = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, &cmdVDOWNCONTYP, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer  9 */
struct CmdTrieNode cmdAMSTRGAIN = {&CmdDict::preAudioMasterGain,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRPEAK = {&CmdDict::preAudioMasterPeak,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBFRAMES = {&CmdDict::preFadeToBlackFrames,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdFTBFRAMESL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCURRSTYL = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTCURRSTYLE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPFRAME = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTDIPFRAMES, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEEFFEC = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdTDVEEFFECT, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFILLS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTDVEFILLSR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFRAME = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTDVEFRAMES, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMIXFRAME = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTMIXFRAMES, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXTSTYL = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTNEXTSTYLE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOWNCONT = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, &cmdVDOWNCONTY, Z0}};
/* Layer  8 */
struct CmdTrieNode cmdAINSTATE = {&CmdDict::preAudioInState,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRGAI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdAMSTRGAIN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRLVL = {&CmdDict::preAudioMasterLevels,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRPEA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, &cmdAMSTRPEAK, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBFRAME = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdFTBFRAMES, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdSETTINGS = {&CmdDict::preSettings,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCURRKEY = {&CmdDict::preTransitionCurrentKey,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCURRSTY = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdTCURRSTYL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPFRAM = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTDIPFRAME, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEEFFE = {&CmdDict::invalid,{A0, B0, &cmdTDVEEFFEC, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFILL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTDVEFILLS, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFRAM = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTDVEFRAME, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYCHNLS = {&CmdDict::preTallyChannelCount,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYINDXS = {&CmdDict::preTallyIndexCount,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYSTATE = {&CmdDict::preTallyState,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMIXFRAM = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTMIXFRAME, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXTKEY = {&CmdDict::preTransitionNextKey,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXTSTY = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdTNEXTSTYL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOWNCON = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdVDOWNCONT, U0, V0, W0, X0, Y0, Z0}};
/* Layer  7 */
struct CmdTrieNode cmdAINGAIN = {&CmdDict::preAudioInGain,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAININFO = {&CmdDict::preAudioInInfo,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINPEAK = {&CmdDict::preAudioInPeak,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINSTAT = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdAINSTATE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRGA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, &cmdAMSTRGAI, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRLV = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdAMSTRLVL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRPE = {&CmdDict::invalid,{&cmdAMSTRPEA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCLRGENC = {&CmdDict::preColorGeneratorColor,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBFRAM = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdFTBFRAME, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBLIVE = {&CmdDict::preFadeToBlackFading,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINNAMEL = {&CmdDict::preInputNameLong,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINNAMES = {&CmdDict::preInputNameShort,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdSETTING = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdSETTINGS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCURRKE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, &cmdTCURRKEY, Z0}};
struct CmdTrieNode cmdTCURRST = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, &cmdTCURRSTY, Z0}};
struct CmdTrieNode cmdTDIPFRA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, &cmdTDIPFRAM, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPSRC = {&CmdDict::preTransitionDipSource,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEEFF = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTDVEEFFE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFIL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdTDVEFILL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFRA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, &cmdTDVEFRAM, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTFRAMES = {&CmdDict::preTransitionFrames,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYCHNL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTLYCHNLS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYINDX = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTLYINDXS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYSTAT = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTLYSTATE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMIXFRA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, &cmdTMIXFRAM, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTNEXTBG = {&CmdDict::preTransitionNextBackground,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXTKE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, &cmdTNEXTKEY, Z0}};
struct CmdTrieNode cmdTNEXTST = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, &cmdTNEXTSTY, Z0}};
struct CmdTrieNode cmdVDOWNCO = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdVDOWNCON, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer  6 */
struct CmdTrieNode cmdACHNLS = {&CmdDict::preAudioChannelCount,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINBAL = {&CmdDict::preAudioInBalance,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINGAI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdAINGAIN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAININF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, &cmdAININFO, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINPEA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, &cmdAINPEAK, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINSTA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdAINSTAT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRG = {&CmdDict::invalid,{&cmdAMSTRGA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, &cmdAMSTRLV, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTRP = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdAMSTRPE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAUXSRC = {&CmdDict::preAuxSource,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCLRGEN = {&CmdDict::invalid,{A0, B0, &cmdCLRGENC, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBFRA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, &cmdFTBFRAM, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBLIV = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdFTBLIVE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdININFO = {&CmdDict::preInputInfo,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINNAME = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdINNAMEL, M0, N0, O0, P0, Q0, R0, &cmdINNAMES, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINTYPE = {&CmdDict::preInputType,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdSETTIN = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, &cmdSETTING, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCURRK = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTCURRKE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCURRS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdTCURRST, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPFR = {&CmdDict::invalid,{&cmdTDIPFRA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPSR = {&CmdDict::invalid,{A0, B0, &cmdTDIPSRC, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEEF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdTDVEEFF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdTDVEFIL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEFR = {&CmdDict::invalid,{&cmdTDVEFRA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTFRAME = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTFRAMES, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYCHN = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdTLYCHNL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYIND = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, &cmdTLYINDX, Y0, Z0}};
struct CmdTrieNode cmdTLYSTA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdTLYSTAT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMIXFR = {&CmdDict::invalid,{&cmdTMIXFRA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTNEXTB = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, &cmdTNEXTBG, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXTK = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTNEXTKE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXTS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdTNEXTST, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOWNC = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, &cmdVDOWNCO, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer  5 */
struct CmdTrieNode cmdACHNL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdACHNLS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINBA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdAINBAL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINGA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, &cmdAINGAI, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAININ = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdAININF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINPE = {&CmdDict::invalid,{&cmdAINPEA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINST = {&CmdDict::invalid,{&cmdAINSTA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdALVLS = {&CmdDict::preAudioLevels,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMSTR = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, &cmdAMSTRG, H0, I0, J0, K0, &cmdAMSTRL, M0, N0, O0, &cmdAMSTRP, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAUXSR = {&CmdDict::invalid,{A0, B0, &cmdAUXSRC, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCLRGE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdCLRGEN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdDEBUG = {&CmdDict::preDebug,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBFR = {&CmdDict::invalid,{&cmdFTBFRA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBLI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, &cmdFTBLIV, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdININF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, &cmdININFO, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINNAM = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdINNAME, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINTYP = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdINTYPE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdSETTI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdSETTIN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCURR = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, &cmdTCURRK, L0, M0, N0, O0, P0, Q0, R0, &cmdTCURRS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTDIPFR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIPS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTDIPSR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdTDVEEF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVEF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTDVEFR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTFRAM = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTFRAME, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYCH = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdTLYCHN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYIN = {&CmdDict::invalid,{A0, B0, C0, &cmdTLYIND, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYST = {&CmdDict::invalid,{&cmdTLYSTA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMIXF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTMIXFR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEXT = {&CmdDict::invalid,{A0, B0/*&cmdTNEXTB*/, C0, D0, E0, F0, G0, H0, I0, J0, &cmdTNEXTK, L0, M0, N0, O0, P0, Q0, R0, &cmdTNEXTS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTPREV = {&CmdDict::preTransitionPreview,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTRANS = {&CmdDict::preAutoTransition,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOWN = {&CmdDict::invalid,{A0, B0, &cmdVDOWNC, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer  4 */
struct CmdTrieNode cmdACHN = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdACHNL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINB = {&CmdDict::invalid,{&cmdAINBA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAING = {&CmdDict::invalid,{&cmdAINGA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdAININ, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINP = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdAINPE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAINS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdAINST, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdALVL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdALVLS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMST = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdAMSTR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAUXS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdAUXSR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCLRG = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdCLRGE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCONN = {&CmdDict::preConnection,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdDEBU = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, &cmdDEBUG, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdFTBFR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTBL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, &cmdFTBLI, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINFO = {&CmdDict::preInfo,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdININ = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdININF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINNA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, &cmdINNAM, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINTY = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, &cmdINTYP, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdPREV = {&CmdDict::prePreview,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdPROG = {&CmdDict::preProgram,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdSETT = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, &cmdSETTI, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCUR = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTCURR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDIP = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdTDIPF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTDIPS, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDVE = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTDVEE, &cmdTDVEF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTFRA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, &cmdTFRAM, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYC = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, &cmdTLYCH, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdTLYIN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLYS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdTLYST, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMIX = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdTMIXF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTNEX = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdTNEXT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTPOS = {&CmdDict::preTransitionPosition,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTPRE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, &cmdTPREV, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTRAN = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTRANS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDOW = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdVDOWN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVFMT = {&CmdDict::preVideoFormat,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer  3 */
struct CmdTrieNode cmdACH = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdACHN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAIN = {&CmdDict::invalid,{A0, &cmdAINB, C0, D0, E0, F0, &cmdAING, H0, &cmdAINI, J0, K0, L0, M0, N0, O0, &cmdAINP, Q0, R0, &cmdAINS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdALV = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdALVL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAMS = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdAMST, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAUX = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdAUXS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCLR = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, &cmdCLRG, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCON = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdCONN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCUT = {&CmdDict::preCut,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdDEB = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, &cmdDEBU, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFTB = {&CmdDict::preFadeToBlack,{A0, B0, C0, D0, E0, &cmdFTBF, G0, H0, I0, J0, K0, &cmdFTBL, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdININ, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, &cmdINFO, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINN = {&CmdDict::invalid,{&cmdINNA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdINT = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, &cmdINTY, Z0}};
struct CmdTrieNode cmdPRE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, &cmdPREV, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdPRO = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, &cmdPROG, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdSET = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdSETT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTCU = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTCUR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTDI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, &cmdTDIP, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdTDV = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTDVE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTFR = {&CmdDict::invalid,{&cmdTFRA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTLY = {&CmdDict::invalid,{A0, B0, &cmdTLYC, D0, E0, F0, G0, H0, &cmdTLYI, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTLYS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTMI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, &cmdTMIX, Y0, Z0}};
struct CmdTrieNode cmdTNE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, &cmdTNEX, Y0, Z0}};
struct CmdTrieNode cmdTPO = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdTPOS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTPR = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTPRE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTRA = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdTRAN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVDO = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, &cmdVDOW, X0, Y0, Z0}};
struct CmdTrieNode cmdVFM = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdVFMT, U0, V0, W0, X0, Y0, Z0}};
/* Layer  2 */
struct CmdTrieNode cmdAC = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, &cmdACH, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdAIN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, &cmdALV, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAM = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, &cmdAMS, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdAU = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, &cmdAUX, Y0, Z0}};
struct CmdTrieNode cmdCL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdCLR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCO = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdCON, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdCU = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdCUT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdDE = {&CmdDict::invalid,{A0, &cmdDEB, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdFT = {&CmdDict::invalid,{A0, &cmdFTB, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdIN = {&CmdDict::invalid,{A0, B0, C0, D0, E0, &cmdINF, G0, H0, &cmdINI, J0, K0, L0, M0, &cmdINN, O0, P0, Q0, R0, S0, &cmdINT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdPR = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdPRE, F0, G0, H0, I0, J0, K0, L0, M0, N0, &cmdPRO, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdSE = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdSET, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTC = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, &cmdTCU, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTD = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, &cmdTDI, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0/*&cmdTDV*/, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdTFR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTL = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, &cmdTLY, Z0}};
struct CmdTrieNode cmdTM = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, &cmdTMI, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTN = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdTNE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTP = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, &cmdTPO, P0, Q0, &cmdTPR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdTR = {&CmdDict::invalid,{&cmdTRA, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVD = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, &cmdVDO, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdVF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, &cmdVFM, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Layer  1 */
struct CmdTrieNode cmdA = {&CmdDict::invalid,{A0, B0, &cmdAC, D0, E0, F0, G0, H0, &cmdAI, J0, K0, &cmdAL, &cmdAM, N0, O0, P0, Q0, R0, S0, T0, &cmdAU, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdC = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, &cmdCL, M0, N0, &cmdCO, P0, Q0, R0, S0, T0, &cmdCU, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdD = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdDE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdF = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, &cmdFT, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdI = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, &cmdIN, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdP = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, &cmdPR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdS = {&CmdDict::invalid,{A0, B0, C0, D0, &cmdSE, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdT = {&CmdDict::invalid,{A0, B0, C0/*&cmdTC*/, &cmdTD, E0, &cmdTF, G0, H0, I0, J0, K0, &cmdTL, &cmdTM, N0, O0, &cmdTP, Q0, &cmdTR, S0, T0, U0, V0, W0, X0, Y0, Z0}};
struct CmdTrieNode cmdV = {&CmdDict::invalid,{A0, B0, C0, &cmdVD, E0, &cmdVF, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
//struct CmdTrieNode cmdX = {&CmdDict::invalid,{A0, B0, C0, D0, E0, F0, G0, H0, I0, J0, K0, L0, M0, N0, O0, P0, Q0, R0, S0, T0, U0, V0, W0, X0, Y0, Z0}};
/* Root Node */
struct CmdTrieNode cmdRoot = {&CmdDict::invalid,{&cmdA, B0, &cmdC, &cmdD, E0, &cmdF, G0, H0, &cmdI, J0, K0, L0, M0, N0, O0, &cmdP, Q0, R0, &cmdS, &cmdT, U0, &cmdV, W0, X0, Y0, Z0}};

struct CmdTrieNode * CmdDict::cmdTrieRoot = &cmdRoot;
CLIApp * CmdDict::app = NULL;

CmdDict::CmdDict(CLIApp * app){
    this->app = app;
}

/**
 * Parses Command 
 */
void CmdDict::parseCommand(QStringList cmd){
    
    if(cmd.size()<2){
        if(cmd.size()==1){
            if(cmd[0].toUpper()=="HELP"){
                preHelp(cmd);
            } else if(cmd[0].toUpper()=="QUIT"){
                preQuit(cmd);
            } else if(cmd[0].toUpper()=="EXIT"){
                preQuit(cmd);
            } else {
                invalid(cmd);
            }
        } else {
            invalid(cmd);
        }
        return;
    }
    
    QString key = cmd[1].toUpper(); //extract key that Trie traverses
    
    
    struct CmdTrieNode * node = cmdTrieRoot;
    for(int i = 0; i < key.size(); i++) {
        
        int charIndex = (int)(key.at(i).toLatin1())-(int)('A'); // Take character at current position and convert to a value from 0-25
        if(charIndex<0 || charIndex > 25){
            // If invalid character, run invalid function & return.
            invalid(cmd);
            return;
        }
        
        node = node->nextChar[charIndex]; // Get Node for character.
        if(node == NULL){
            // If no node for character, run invalid function & return.
            invalid(cmd);
            return;
        }

    }
    
    node->currentCmd(cmd);
    
}



void CmdDict::invalid(QStringList cmd){
    Q_UNUSED(cmd)
    app->invalidCmd();
}

void CmdDict::preHelp(QStringList cmd){
    Q_UNUSED(cmd)
    app->help();
}

void CmdDict::preQuit(QStringList cmd){
    Q_UNUSED(cmd)
    app->quit();
}

void CmdDict::preAudioChannelCount(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getAudioChannelCount();
        }
    } else if(cmd[0].toUpper()=="HELP"){
        app->helpASrc();
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioInBalance(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getAudioInBalance((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setAudioInBalance((quint16)cmd[2].toInt(),cmd[3].toFloat());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioInGain(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getAudioInGain((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setAudioInGain((quint16)cmd[2].toInt(),cmd[3].toFloat());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioInInfo(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getAudioInInfo((quint16)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioInPeak(QStringList cmd){
    if(cmd[0].toUpper()=="RESET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->resetAudioInPeak((quint16)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioInState(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getAudioInState((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setAudioInState((quint16)cmd[2].toInt(),(quint8)cmd[3].toInt()); //0 = Off, 1 = On, 2 = AFV
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioLevels(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()< 3){
            invalid(cmd);
        } else {
            QList<quint16> channels;
            if(cmd[2].toUpper()!="ALL"){ // populate channel list if not all
                for(int i=2; i<cmd.size(); i++){
                    channels.append((quint16)cmd[i].toInt());
                }
            }
            app->getAudioLevels(channels);
        }
    } else if(cmd[0].toUpper()=="ENABLE"){
        if(cmd.size()< 2){
            invalid(cmd);
        } else {
            QList<quint16> channels;
            for(int i=2; i<cmd.size(); i++){
                channels.append((quint16)cmd[i].toInt());
            }
            app->enableAudioLevels(true, channels);
        }
        
    } else if(cmd[0].toUpper()=="DISABLE"){
        if(cmd.size() != 2){
            invalid(cmd);
        } else {
            app->enableAudioLevels(false,QList<quint16>());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioMasterGain(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getAudioMasterGain();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setAudioMasterGain(cmd[2].toFloat());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioMasterLevels(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getAudioMasterLevels();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAudioMasterPeak(QStringList cmd){
    if(cmd[0].toUpper()=="RESET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->resetAudioMasterPeak();
        }
    } else {
        invalid(cmd);
    }
}

/* GET/SET AUXSRC AUXCHNL INPUT */
void CmdDict::preAuxSource(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getAuxSource((quint8)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setAuxSource((quint8)cmd[2].toInt(),(quint16)cmd[3].toInt());
        }
    } else if(cmd[0].toUpper()=="HELP"){
        app->helpVSrc();
    } else {
        invalid(cmd);
    }
}

void CmdDict::preColorGeneratorColor(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getColorGeneratorColor((quint8)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 6){
            invalid(cmd);
        } else {
            app->setColorGeneratorColor((quint8)cmd[2].toInt(),(quint8)cmd[3].toInt(),(quint8)cmd[4].toInt(),(quint8)cmd[5].toInt()); // RGB 0-255
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preConnection(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getConnection();
        }
    } else if(cmd[0].toUpper()=="START"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->setConnection(true);
        }
    } else if(cmd[0].toUpper()=="STOP"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->setConnection(false);
        }
    } else {
        invalid(cmd);
    }
}

/* DO CUT */
void CmdDict::preCut(QStringList cmd){
    if(cmd[0].toUpper()=="DO"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->doCut();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preDebug(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getConnection();
        }
    } else if(cmd[0].toUpper()=="ENABLE"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->setDebug(true);
        }
    } else if(cmd[0].toUpper()=="DISABLE"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->setDebug(false);
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preFadeToBlack(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getFadeToBlack();
        }
    } else if(cmd[0].toUpper()=="TOGGLE"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->toggleFadeToBlack();
        }
    } else if(cmd[0].toUpper()=="DO"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setFadeToBlack(true);
        }
    } else if(cmd[0].toUpper()=="UNDO"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setFadeToBlack(false);
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preFadeToBlackFrames(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getFadeToBlackFrames();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setFadeToBlackFrames((quint8)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preFadeToBlackFramesLeft(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getFadeToBlackFramesLeft();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preFadeToBlackFading(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getFadeToBlackFading();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preInfo(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getAtemInfo();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preInputInfo(QStringList cmd){
    Q_UNUSED(cmd)
}

void CmdDict::preInputNameLong(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getInputNameLong((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setInputNameLong((quint16)cmd[2].toInt(),cmd[3]);
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preInputNameShort(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getInputNameShort((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setInputNameShort((quint16)cmd[2].toInt(),cmd[3]);
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preInputType(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getInputType((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setInputType((quint16)cmd[2].toInt(),(quint8)cmd[3].toInt()); //0 = Off, 1 = On, 2 = AFV
        }
    } else {
        invalid(cmd);
    }
}

/* GET/SET PREV INPUT */
void CmdDict::prePreview(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getPreview();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setPreview((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="HELP"){
        app->helpVSrc();
    } else {
        invalid(cmd);
    }
}

/* GET/SET PROG INPUT */
void CmdDict::preProgram(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getProgram();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setProgram((quint16)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="HELP"){
        app->helpVSrc();
    } else {
        invalid(cmd);
    }
}

void CmdDict::preSettings(QStringList cmd){
    if(cmd[0].toUpper()=="SAVE"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->saveSettings();
        }
    } else if(cmd[0].toUpper()=="CLEAR"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            if(cmd[2].toUpper()=="YES"){
                app->clearSettings();
            } else {
                invalid(cmd);
            }
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTransitionCurrentKey(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            if(cmd[2].toUpper()=="ALL"){
                cmd[2] = "255";
            }
            app->getTransitionCurrentKey((quint8)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTransitionCurrentStyle(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getTransitionCurrentStyle();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTransitionDipFrames(QStringList cmd){
    Q_UNUSED(cmd)
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getTransitionDipFrames();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setTransitionDipFrames((quint8)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTransitionDipSource(QStringList cmd){
    Q_UNUSED(cmd)
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getTransitionDipSource();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setTransitionDipSource((quint16)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

/*
void CmdDict::preTransitionDVEEffect(QStringList cmd){
    Q_UNUSED(cmd)
}

void CmdDict::preTransitionDVEFillSource(QStringList cmd){
    Q_UNUSED(cmd)
}

void CmdDict::preTransitionDVEFrames(QStringList cmd){
    Q_UNUSED(cmd)
}
*/

void CmdDict::preTransitionFrames(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getTransitionFrames();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTallyChannelCount(QStringList cmd){
    Q_UNUSED(cmd)
}

void CmdDict::preTallyIndexCount(QStringList cmd){
    Q_UNUSED(cmd)
}

void CmdDict::preTallyState(QStringList cmd){
    Q_UNUSED(cmd)
}

void CmdDict::preTransitionMixFrames(QStringList cmd){
    Q_UNUSED(cmd)
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getTransitionMixFrames();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setTransitionMixFrames((quint8)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}


void CmdDict::preTransitionNextBackground(QStringList cmd){
    // This function is covered by preTransitionNextBackground with index 0
    Q_UNUSED(cmd)
}

void CmdDict::preTransitionNextKey(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            if(cmd[2].toUpper()=="ALL"){
                cmd[2] = "255";
            }
            app->getTransitionNextKey((quint8)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setTransitionNextKey((quint8)cmd[2].toInt(),(bool)cmd[3].toInt()); //0 = Off, 1 = On
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTransitionNextStyle(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getTransitionNextStyle();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setTransitionNextStyle((quint8)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTransitionPosition(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getTransitionPosition();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setTransitionPosition((quint16)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preTransitionPreview(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!=2){
            invalid(cmd);
        } else {
            app->getTransitionPreview();
        }
    } else if(cmd[0].toUpper()=="ENABLE"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->setTransitionPreview(true);
        }
        
    } else if(cmd[0].toUpper()=="DISABLE"){
        if(cmd.size() != 2){
            invalid(cmd);
        } else {
            app->setTransitionPreview(false);
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preAutoTransition(QStringList cmd){
     if(cmd[0].toUpper()=="DO"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->doAutoTransition();
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preVideoDownConvertType(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getVideoDownConvertType();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setVideoDownConvertType((quint8)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preVideoFormat(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 2){
            invalid(cmd);
        } else {
            app->getVideoFormat();
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->setVideoFormat((quint8)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="HELP"){
        app->helpVFmt();
    } else {
        invalid(cmd);
    }
}
