/*
Copyright 2017  Ian Knight <ian@knightly.xyz>

This file is part of atem-cli.

atem-cli is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

atem-cli is distributed in the hope that it will be useful,
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
 

/* Root Node */
struct CmdTrieNode cmdRoot = {};

struct CmdTrieNode * CmdDict::cmdTrieRoot = &cmdRoot;
CLIApp * CmdDict::app = NULL;

CmdDict::CmdDict(CLIApp * app){
    this->app = app;
    
    CmdDict::defineCommand("ACHNLS", &CmdDict::preAudioChannelCount);
    CmdDict::defineCommand("AINBAL", &CmdDict::preAudioInBalance);
    CmdDict::defineCommand("AINGAIN", &CmdDict::preAudioInGain);
    CmdDict::defineCommand("AININFO", &CmdDict::preAudioInInfo);
    CmdDict::defineCommand("AINPEAK", &CmdDict::preAudioInPeak);
    CmdDict::defineCommand("AINSTATE", &CmdDict::preAudioInState);
    CmdDict::defineCommand("ALVLS", &CmdDict::preAudioLevels);
    CmdDict::defineCommand("AMSTRGAIN", &CmdDict::preAudioMasterGain);
    CmdDict::defineCommand("AMSTRLVL", &CmdDict::preAudioMasterLevels);
    CmdDict::defineCommand("AMSTRPEAK", &CmdDict::preAudioMasterPeak);
    CmdDict::defineCommand("AUXSRC", &CmdDict::preAuxSource);
    CmdDict::defineCommand("CLRGENC", &CmdDict::preColorGeneratorColor);
    CmdDict::defineCommand("CONN", &CmdDict::preConnection);
    CmdDict::defineCommand("CUT", &CmdDict::preCut);
    CmdDict::defineCommand("DEBUG", &CmdDict::preDebug);
    CmdDict::defineCommand("DSKEY", &CmdDict::preDSKeyLive);
    CmdDict::defineCommand("DSKAUTO", &CmdDict::preDSKeyAuto);
    CmdDict::defineCommand("DSKARATE", &CmdDict::preDSKeyAutoFrameRate);
    CmdDict::defineCommand("DSKTIE", &CmdDict::preDSKeyTie);
    CmdDict::defineCommand("FTB", &CmdDict::preFadeToBlack);
    CmdDict::defineCommand("FTBFRAMES", &CmdDict::preFadeToBlackFrames);
    CmdDict::defineCommand("FTBFRAMESLEFT", &CmdDict::preFadeToBlackFramesLeft);
    CmdDict::defineCommand("FTBLIVE", &CmdDict::preFadeToBlackFading);
    CmdDict::defineCommand("INFO", &CmdDict::preInfo);
    CmdDict::defineCommand("ININFO", &CmdDict::preInputInfo);
    CmdDict::defineCommand("INNAMEL", &CmdDict::preInputNameLong);
    CmdDict::defineCommand("INNAMES", &CmdDict::preInputNameShort);
    CmdDict::defineCommand("INTYPE", &CmdDict::preInputType);
    CmdDict::defineCommand("PREV", &CmdDict::prePreview);
    CmdDict::defineCommand("PROG", &CmdDict::preProgram);
    CmdDict::defineCommand("SETTINGS", &CmdDict::preSettings);
    CmdDict::defineCommand("TCURRKEY", &CmdDict::preTransitionCurrentKey);
    CmdDict::defineCommand("TCURRSTYLE", &CmdDict::preTransitionCurrentStyle);
    CmdDict::defineCommand("TDIPFRAMES", &CmdDict::preTransitionDipFrames);
    CmdDict::defineCommand("TDIPSRC", &CmdDict::preTransitionDipSource);
    //CmdDict::defineCommand("TDVEFILLSRC", &CmdDict::preTransitionDVEFillSource);
    //CmdDict::defineCommand("TDVEEFFECT", &CmdDict::preTransitionDVEEffect);
    //CmdDict::defineCommand("TDVEFRAMES", &CmdDict::preTransitionDVEFrames);
    CmdDict::defineCommand("TFRAMES", &CmdDict::preTransitionFrames);
    CmdDict::defineCommand("TLYCHNLS", &CmdDict::preTallyChannelCount);
    CmdDict::defineCommand("TLYINDXS", &CmdDict::preTallyIndexCount);
    CmdDict::defineCommand("TLYSTATE", &CmdDict::preTallyState);
    CmdDict::defineCommand("TMIXFRAMES", &CmdDict::preTransitionMixFrames);
    //CmdDict::defineCommand("TNEXTBG", &CmdDict::preTransitionNextBackground);
    CmdDict::defineCommand("TNEXTKEY", &CmdDict::preTransitionNextKey);
    CmdDict::defineCommand("TNEXTSTYLE", &CmdDict::preTransitionNextStyle);
    CmdDict::defineCommand("TPOS", &CmdDict::preTransitionPosition);
    CmdDict::defineCommand("TPREV", &CmdDict::preTransitionPreview);
    CmdDict::defineCommand("TRANS", &CmdDict::preAutoTransition);
    CmdDict::defineCommand("VDOWNCONTYPE", &CmdDict::preVideoDownConvertType);
    CmdDict::defineCommand("VFMT", &CmdDict::preVideoFormat);
    
}


/**
 * Adds new command and corresponding handler to Trie 
 */
void CmdDict::defineCommand(QString cmd_name, void (*handler)(QStringList)){

    QString key = cmd_name.toUpper(); //extract key that Trie traverses
    
    
    struct CmdTrieNode * node = cmdTrieRoot;
    for(int i = 0; i < key.size(); i++) {
        
        int charIndex = (int)(key.at(i).toLatin1())-(int)('A'); // Take character at current position and convert to a value from 0-25
        if(charIndex<0 || charIndex > 25){
            // If invalid character return.
            return;
        }
        
        struct CmdTrieNode * next = node->nextChar[charIndex];
        if(next == NULL){
            // If no node exists for current position in trie, create new node and continue.
            next = new CmdTrieNode();
            node->nextChar[charIndex] = next;
        }
        node = next;

    }
    
    node->currentCmd = handler;
    
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


void CmdDict::preDSKeyLive(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            if(cmd[2].toUpper()=="ALL"){
                cmd[2] = "255";
            }
            app->getDSKeyLive((quint8)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setDSKeyLive((quint8)cmd[2].toInt(),(bool)cmd[3].toInt()); //0 = Off, 1 = On
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preDSKeyAuto(QStringList cmd){
    if(cmd[0].toUpper()=="DO"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->doDSKeyAuto((quint8)cmd[2].toInt());
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preDSKeyAutoFrameRate(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            app->getDSKeyAutoFrameRate((quint8)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setDSKeyAutoFrameRate((quint8)cmd[2].toInt(),(quint8)cmd[3].toInt()); //value 0-250
        }
    } else {
        invalid(cmd);
    }
}

void CmdDict::preDSKeyTie(QStringList cmd){
    if(cmd[0].toUpper()=="GET"){
        if(cmd.size()!= 3){
            invalid(cmd);
        } else {
            if(cmd[2].toUpper()=="ALL"){
                cmd[2] = "255";
            }
            app->getDSKeyTie((quint8)cmd[2].toInt());
        }
    } else if(cmd[0].toUpper()=="SET"){
        if(cmd.size()!= 4){
            invalid(cmd);
        } else {
            app->setDSKeyTie((quint8)cmd[2].toInt(),(bool)cmd[3].toInt()); //0 = Off, 1 = On
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
