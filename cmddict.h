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

#ifndef CMDDICT_H
#define CMDDICT_H

#include "cliapp.h"

struct CmdTrieNode {
    void (*currentCmd)(QStringList);
    CmdTrieNode * nextChar[26];
};

class CmdDict {
    
public:
    CmdDict(CLIApp * app);
    static void parseCommand(QStringList cmd);
    
    static struct CmdTrieNode * cmdTrieRoot;
    static CLIApp * app;
    
    static void invalid(QStringList cmd);
    
    static void preHelp(QStringList cmd);
    static void preQuit(QStringList cmd);
    
    static void preAudioChannelCount(QStringList cmd);
    static void preAudioInBalance(QStringList cmd);
    static void preAudioInGain(QStringList cmd);
    static void preAudioInInfo(QStringList cmd);
    static void preAudioInPeak(QStringList cmd);
    static void preAudioInState(QStringList cmd);
    static void preAudioLevels(QStringList cmd);
    static void preAudioMasterGain(QStringList cmd);
    static void preAudioMasterLevels(QStringList cmd);
    static void preAudioMasterPeak(QStringList cmd);
    static void preAuxSource(QStringList cmd);
    static void preColorGeneratorColor(QStringList cmd);
    static void preConnection(QStringList cmd);
    static void preCut(QStringList cmd);
    static void preDebug(QStringList cmd);
    static void preFadeToBlack(QStringList cmd);
    static void preFadeToBlackFrames(QStringList cmd);
    static void preFadeToBlackFramesLeft(QStringList cmd);
    static void preFadeToBlackFading(QStringList cmd);
    static void preInfo(QStringList cmd);
    static void preInputInfo(QStringList cmd);
    static void preInputNameLong(QStringList cmd);
    static void preInputNameShort(QStringList cmd);
    static void preInputType(QStringList cmd);
    static void prePreview(QStringList cmd);
    static void preProgram(QStringList cmd);
    static void preSettings(QStringList cmd);
    static void preTransitionCurrentKey(QStringList cmd);
    static void preTransitionCurrentStyle(QStringList cmd);
    static void preTransitionDipFrames(QStringList cmd);
    static void preTransitionDipSource(QStringList cmd);
    /*static void preTransitionDVEEffect(QStringList cmd);
    static void preTransitionDVEFillSource(QStringList cmd);
    static void preTransitionDVEFrames(QStringList cmd);*/
    static void preTransitionFrames(QStringList cmd);
    static void preTallyChannelCount(QStringList cmd);
    static void preTallyIndexCount(QStringList cmd);
    static void preTallyState(QStringList cmd);
    static void preTransitionMixFrames(QStringList cmd);
    static void preTransitionNextBackground(QStringList cmd);
    static void preTransitionNextKey(QStringList cmd);
    static void preTransitionNextStyle(QStringList cmd);
    static void preTransitionPosition(QStringList cmd);
    static void preTransitionPreview(QStringList cmd);
    static void preAutoTransition(QStringList cmd);
    static void preVideoDownConvertType(QStringList cmd);
    static void preVideoFormat(QStringList cmd);

};

#endif // CMDDICT_H