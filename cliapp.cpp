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
#include <QApplication>
#include <iostream>
#include <QObject>
#include <QTextStream>
#include <QHostAddress>

#include "cliapp.h"
#include "cmddict.h"
#include "qatemtypes.h"
#include "qatemmixeffect.h"
#include "qatemconnection.h"


void CLIReader::run(){
    
    QString line;
    
    while(true){
        
        line = qin->readLine();
        //qout << line << endl;
        emit cmdReady(line.split(" "));
        
    }
    
}


void CLIApp::run(){

    m_atemConnection = new QAtemConnection(this);
    
    connectAtemEvents();
    
    qout << atem_address.toString() << endl;
    
    m_atemConnection->connectToSwitcher(atem_address);
    
}

void CLIApp::processCmd(QStringList cmd){
    
    CmdDict cmdParser = CmdDict(this);
    
    cmdParser.parseCommand(cmd);
        
}


void CLIApp::help(){
    qout << "\n"
    "        ~ CLI for Blackmagic ATEM Switchers ~\n"
    "Commands:         {PREFIXES}              ARGUMENTS \n"
    "   ACHNLS         {GET|HELP}\n"                                     //done
    "   AINBAL         {GET|SET}               INDEX BALANCE\n"     //done
    "   AINGAIN        {GET|SET}               INDEX GAIN\n"        //done
    "   AININFO        {GET}                   INDEX\n"             //done
    "   AINPEAK        {RESET}                 ALL|[INDEX1,...]\n"  //done
    "   AINSTATE       {GET|SET}               INDEX STATE\n"       //done //0 = Off, 1 = On, 2 = AFV
    "   ALVLS          {ENABLE|DISABLE|GET}    ALL|[INDEX1,...]\n"  //done
    "   AMSTRGAIN      {GET|SET}               GAIN\n"              //done
    "   AMSTRLVL       {GET}\n"                                     //done
    "   AMSTRPEAK      {RESET}\n"                                   //done
    "   AUXSRC         {GET|SET|HELP}          AUXCHNL INDEX\n"     //done
    "   CLRGENC        {GET|SET}               GENERATOR R G B\n"   //done
    "   CONN           {START|STOP|GET}\n"                          //done
    "   CUT            {DO}\n"                                      //done
    "   DEBUG          {ENABLE|DISABLE|GET}\n"                      //done
    "   FTB            {DO|UNDO|TOGGLE|GET}\n"                      //done
    "   FTBFRAMES      {GET|SET}               INDEX\n"             //done
    "   FTBFRAMESLEFT  {GET}                   INDEX\n"             //done
    "   FTBLIVE        {GET}                   INDEX\n"             //done
    "   ININFO         {GET}                   INDEX\n"
    "   INNAMEL        {GET|SET}               INDEX NAME\n"        //done
    "   INNAMES        {GET|SET}               INDEX NAME\n"        //done
    "   INTYPE         {GET|SET}               INDEX TYPE\n"        //done
    "   PREV           {GET|SET|HELP}          INDEX\n"             //done
    "   PROG           {GET|SET|HELP}          INDEX\n"             //done
    "   SETTINGS       {SAVE|CLEAR}            YES\n"               //done
    "   TCURRKEY       {GET}                   ALL|INDEX\n"         //done
    "   TCURRSTYLE     {GET}\n"                                     //done //0 = Mix, 1 = Dip, 2 = Wipe, 3 = DVE and 4 = Stinger
    "   TDIPFRAMES     {GET|SET}               FRAMES\n"            //done
    "   TDIPSRC        {GET|SET}               SOURCE\n"            //done
    //"   TDVEEFFECT\n"
    //"   TDVEFILLSRC\n"
    //"   TDVEFRAMES\n"
    //"   TDVEKEY\n"
    //"   TDVEKEYSRC\n"
    "   TFRAMES        {GET}                   INDEX\n"             //done
    //"   TLYCHNLS\n"
    //"   TLYINDXS\n"
    //"   TLYSTATE\n"
    "   TMIXFRAMES     {GET|SET}               FRAMES\n"            //done
    //"   TNEXTBG        {GET|SET}               INDEX\n" // if off/on background disappears/appears next trans
    "   TNEXTKEY       {GET|SET}               ALL|INDEX STATE\n"  //done // if off/on key disappears/appears next trans. 0 = Background, 1 = Key1 ...
    "   TNEXTSTYLE     {GET|SET}               STYLE\n"             //done //0 = Mix, 1 = Dip, 2 = Wipe, 3 = DVE and 4 = Stinger
    "   TPOS           {GET|SET}               POSITION\n"          //done //goes from 0 to 9999 then flips to 0; must send 0 to end transition.
    "   TPREV          {ENABLE|DISABLE|GET}\n"                      //done
    "   TRANS          {DO}\n"                                      //done
    "   VDOWNCONTYPE   {GET|SET}               MODE\n"              //done
    "   VFMT           {GET|SET|HELP}          FORMAT" << endl;
}

void CLIApp::helpVSrc(){
    qout << "\n"
    "Video Source IDs: (Not All Available on all Models)\n"
    "   [0] =>         Black\n"
    "   [1] =>         Input 1\n"
    "   ...\n"
    "   [20]           Input 20\n"
    "   [1000]         Color Bars\n"
    "   [2001]         Color 1\n"
    "   [2002]         Color 2\n"
    "   [3010]         Media Player 1\n"
    "   [3011]         Media Player 1 Key\n"
    "   [3020]         Media Player 2\n"
    "   [3021]         Media Player 2 Key\n"
    "   [4010]         Key 1 Mask\n"
    "   [4020]         Key 2 Mask\n"
    "   [4030]         Key 3 Mask\n"
    "   [4040]         Key 4 Mask\n"
    "   [5010]         DSK 1 Mask\n"
    "   [5020]         DSK 2 Mask\n"
    "   [6000]         Super Source\n"
    "   [7001]         Clean Feed 1\n"
    "   [7002]         Clean Feed 2\n"
    "   [8001]         Auxilary 1\n"
    "   ...\n"
    "   [8006]         Auxilary 6\n"
    "   [10010]        ME 1 Prog\n"
    "   [10011]        ME 1 Prev\n"
    "   [10020]        ME 2 Prog\n"
    "   [10021]        ME 2 Prev" << endl;
}

void CLIApp::helpASrc(){
    qout << "\n"
    "Audio Source IDs: (Not All Available on all Models)\n"
    "   [1]            Input 1\n"
    "   ...\n"
    "   [20]           Input 20\n"
    "   [1001]         XLR\n"
    "   [1101]         AES/EBU\n"
    "   [1201]         RCA\n"
    "   [2001]         MP1\n"
    "   [2002]         MP2" << endl;
}

void CLIApp::helpVFmt(){
    qout << "\n"
    "Video Formats: (Not All Available on all Models)\n"
    " 	0:             525i59.94 NTSC"
    "   1:             625i50    PAL"
    "   2:             525i59.94 NTSC 16:9"
    "   3:             625i50    PAL 16:9"
    "   4:             720p50"
    "   5:             720p59.94"
    "   6:             1080i50"
    "   7:             1080i59.94"
    "   8:             1080p23.98"
    "   9:             1080p24"
    "   10:            1080p25"
    "   11:            1080p29.97"
    "   12:            1080p50"
    "   13:            1080p59.94"
    "   14:            2160p23.98"
    "   15:            2160p24"
    "   16:            2160p25"
    "   17:            2160p29.97" << endl;
}
    
void CLIApp::quit(){
    reconnect = false;
    m_atemConnection->disconnectFromSwitcher();
    emit finished();
}
    
void CLIApp::invalidCmd(){
    qout << "Invalid Command. Type \"HELP\" for details" << endl;
}

void CLIApp::doCut(){
    m_mixEffect->cut();
}

void CLIApp::doAutoTransition(){
    m_mixEffect->autoTransition();
}

void CLIApp::saveSettings(){
    m_atemConnection->saveSettings();
}

void CLIApp::clearSettings(){
    m_atemConnection->clearSettings();
}

void CLIApp::getAtemInfo(){
    qout << "INFO: [ " << m_atemConnection->majorVersion() << " " << m_atemConnection->minorVersion() << " ] " << m_atemConnection->productInformation() << endl;
}

void CLIApp::getAudioChannelCount(){
    qout << "ACHNLS: " << m_atemConnection->audioChannelCount() << endl;
}

void CLIApp::getAudioInBalance(quint16 channel){
    qout << "AINBAL: [ "<< channel <<" ] " << m_atemConnection->audioInput(channel).balance << endl;
}

void CLIApp::getAudioInGain(quint16 channel){
    qout << "AINGAIN: [ "<< channel <<" ] " << m_atemConnection->audioInput(channel).gain << endl;
}

void CLIApp::getAudioInInfo(quint16 channel){
    //quint8 type; // 0 = Video input, 1 = Media player, 2 = External
    //quint8 plugType; // 0 = Internal, 1 = SDI, 2 = HDMI, 3 = Component, 4 = Composite, 5 = SVideo, 32 = XLR, 64 = AES/EBU, 128 = RCA
    qout << "AININFO: [ "<< channel <<" ] " << m_atemConnection->audioInput(channel).type << " " << m_atemConnection->audioInput(channel).plugType << endl;
    
}

void CLIApp::getAudioInState(quint16 channel){
    //0 = Off, 1 = On, 2 = AFV
    qout << "AINSTATE: [ "<< channel <<" ] " << m_atemConnection->audioInput(channel).state << endl;
}

/* If channels empty, do all
 * ALVLX: LLVL RLVL ( LPEAK RPEAK )
 */
void CLIApp::getAudioLevels(QList<quint16> channels){
    if(channels.size() == 0){ // if empty, do all
        QHash<quint16, QAtem::AudioInput> ains = m_atemConnection->audioInputs();
        QHash<quint16, QAtem::AudioInput>::iterator i;
        for (i = ains.begin(); i != ains.end(); ++i) {
            QAtem::AudioLevel ainl = m_atemConnection->audioLevel(i.key());
            qout << "ALVL: [ "<<i.key()<<" ] " << ainl.left << " " << ainl.right << " ( " << ainl.peakLeft << " " << ainl.peakRight << " )" << endl;
        }
    } else {
        for(int i=0; i<channels.size(); i++){
            qout << "ALVL: [ "<<channels[i]<<" ] " << m_atemConnection->audioLevel(channels[i]).left << " " << m_atemConnection->audioLevel(channels[i]).right << " ( " << m_atemConnection->audioLevel(channels[i]).peakLeft << " " << m_atemConnection->audioLevel(channels[i]).peakRight << " )" << endl;
        }
    }
}

void CLIApp::getAudioMasterGain(){
    qout << "AMSTRGAIN: " << m_atemConnection->audioMasterOutputGain() << endl;
}

void CLIApp::getAudioMasterLevels(){
    qout << "AMSTRLVL: " << m_atemConnection->audioMasterOutputLevelLeft() << " " << m_atemConnection->audioMasterOutputLevelRight() << " ( " << m_atemConnection->audioMasterOutputPeakLeft() << " " << m_atemConnection->audioMasterOutputPeakRight() << " )" << endl;
}

void CLIApp::getAuxSource(quint8 aux){
    qout << "AUX: [ "<<aux<<" ] " << m_atemConnection->auxSource(aux) << endl;
}

void CLIApp::getColorGeneratorColor(quint8 generator){
    QColor cgc = m_atemConnection->colorGeneratorColor(generator);
    qout << "CLRGEN: [ "<<generator<<" ] " << cgc.red() << " " << cgc.green() << " " << cgc.blue() << endl;
}

void CLIApp::getConnection(){
    qout << "CONN: "<< m_atemConnection->isConnected() << endl;
}

void CLIApp::getDebug(){
    qout << "DEBUG: "<< m_atemConnection->debugEnabled() << endl;
}

void CLIApp::getFadeToBlack(){
    qout << "FTB: " << m_mixEffect->fadeToBlackEnabled() << endl;
}

void CLIApp::getFadeToBlackFading(){
    qout << "FTBLIVE: " << m_mixEffect->fadeToBlackFading() << endl;
}

void CLIApp::getFadeToBlackFrames(){
    qout << "FTBFRAMES: " << m_mixEffect->fadeToBlackFrames() << endl;
}

void CLIApp::getFadeToBlackFramesLeft(){
    qout << "FTBFRAMESLEFT: " << m_mixEffect->fadeToBlackFrameCount() << endl;
}

void CLIApp::getInputType(quint16 input){
    quint8 type = m_atemConnection->inputInfo(input).externalType;
    if(type!=0){
        qout << "INTYPE: [ " << input << " ] EXTERNAL " << type << endl;
    } else {
        type = m_atemConnection->inputInfo(input).internalType;
        qout << "INTYPE: [ " << input << " ] INTERNAL " << type << endl;
    }
}

void CLIApp::getInputNameLong(quint16 input){
    qout << "INNAMEL: [ " << input << " ] " << m_atemConnection->inputInfo(input).longText << endl;
}

void CLIApp::getInputNameShort(quint16 input){
    qout << "INNAMES: [ " << input << " ] " << m_atemConnection->inputInfo(input).shortText << endl;
}


void CLIApp::getPreview(){
    qout << "PREV: " << m_mixEffect->previewInput()  << endl;
}

void CLIApp::getProgram(){
    qout << "PROG: " << m_mixEffect->programInput() << endl;
}

void CLIApp::getTransitionCurrentKey(quint8 keyer){
    quint8 bitmap = m_mixEffect->keyersOnCurrentTransition(); //produces bitmap where lsb is keyer 0. Will right-shift to select bit and modulo for value
    if(keyer == 255){
        for(int i=0; i<5; i++){
            qout << "TCURRKEY " << i << ": " << ((bitmap >> i)%2) << endl;
        }
    } else {
        qout << "TCURRKEY " << keyer << ": " << ((bitmap >> keyer)%2) << endl;
    }
}

void CLIApp::getTransitionCurrentStyle(){
    qout << "TCURRSTYLE: " << m_mixEffect->currentTransitionStyle() << endl;
}

void CLIApp::getTransitionDipFrames(){
    qout << "TDIPFRAMES: " << m_mixEffect->dipFrames() << endl;
}

void CLIApp::getTransitionDipSource(){
    qout << "TDIPSRC: " << m_mixEffect->dipSource() << endl;
}

void CLIApp::getTransitionFrames(){
    qout << "TFRAMES: " << m_mixEffect->transitionFrameCount() << endl;
}

void CLIApp::getTransitionMixFrames(){
    qout << "TMIXFRAMES: " << m_mixEffect->mixFrames() << endl;
}

void CLIApp::getTransitionNextKey(quint8 keyer){
    quint8 bitmap = m_mixEffect->keyersOnNextTransition(); //produces bitmap where lsb is keyer 0. Will right-shift to select bit and modulo for value
    if(keyer == 255){
        for(int i=0; i<5; i++){
            qout << "TNEXTKEY " << i << ": " << ((bitmap >> i)%2) << endl;
        }
    } else {
        qout << "TNEXTKEY " << keyer << ": " << ((bitmap >> keyer)%2) << endl;
    }
}

void CLIApp::getTransitionNextStyle(){
    qout << "TNEXTSTYLE: " << m_mixEffect->nextTransitionStyle() << endl;
}

void CLIApp::getTransitionPosition(){
    qout << "TPOS: " << m_mixEffect->transitionPosition() << endl;
}

void CLIApp::getTransitionPreview(){
    qout << "TPREV: " << m_mixEffect->transitionPreviewEnabled() << endl;
}

void CLIApp::getVideoDownConvertType(){
    qout << "VDOWNCONTYPE: " << m_atemConnection->videoDownConvertType() << endl;
}

void CLIApp::getVideoFormat(){
    qout << "VFMT: " << m_atemConnection->videoFormat() << endl;
}

void CLIApp::setAudioInBalance(quint16 channel, float balance){
    m_atemConnection->setAudioInputBalance(channel, balance);
}

void CLIApp::setAudioInGain(quint16 channel, float gain){
    m_atemConnection->setAudioInputGain(channel, gain);
}

void CLIApp::resetAudioInPeak(quint16 channel){
    m_atemConnection->resetAudioInputPeaks(channel);
}

void CLIApp::setAudioInState(quint16 channel, quint8 state){
    m_atemConnection->setAudioInputState(channel, state);
}

void CLIApp::enableAudioLevels(bool enabled, QList<quint16> channels){
    m_atemConnection->setAudioLevelsEnabled(enabled);
    this->aLvlUpdateList.clear();
    if(enabled){        
        this->aLvlUpdateList.append(channels);
    }
}

void CLIApp::setAudioMasterGain(float gain){
    m_atemConnection->setAudioMasterOutputGain(gain);
}

void CLIApp::resetAudioMasterPeak(){
    m_atemConnection->resetAudioMasterOutputPeaks();
}

void CLIApp::setAuxSource(quint8 aux, quint16 index){
    m_atemConnection->setAuxSource(aux, index);
}

void CLIApp::setColorGeneratorColor(quint8 generator, quint8 red, quint8 green, quint8 blue){
    m_atemConnection->setColorGeneratorColor(generator, QColor((int)red, (int)green, (int)blue));
}

void CLIApp::setConnection(bool enable){
    reconnect = false;
    if(m_atemConnection->isConnected()!=enable){
        if(enable){
            m_atemConnection->connectToSwitcher(atem_address);
        } else {
            m_atemConnection->disconnectFromSwitcher();
        }
    }
}

void CLIApp::setDebug(bool enable){
    m_atemConnection->setDebugEnabled(enable);
}

void CLIApp::setFadeToBlack(bool ftb){
    if(ftb==m_mixEffect->fadeToBlackEnabled()){
        qout << "FTB: " << ftb << endl;
    } else {
        m_mixEffect->toggleFadeToBlack();
    }
}

void CLIApp::setFadeToBlackFrames(quint8 frames){
    m_mixEffect->setFadeToBlackFrameRate(frames);
}

void CLIApp::setInputNameLong(quint16 input, QString name){
    m_atemConnection->setInputLongName(input, name.left(20)); //20
}

void CLIApp::setInputNameShort(quint16 input, QString name){
    m_atemConnection->setInputShortName(input, name.left(4)); //4
}

void CLIApp::setInputType(quint16 input, quint8 type){
    m_atemConnection->setInputType(input, type);
}

void CLIApp::toggleFadeToBlack(){
    m_mixEffect->toggleFadeToBlack();
}

void CLIApp::setPreview(quint16 index){
    m_mixEffect->changePreviewInput(index);
}

void CLIApp::setProgram(quint16 index){
    m_mixEffect->changeProgramInput(index);
}

void CLIApp::setTransitionDipFrames(quint8 frames){
    m_mixEffect->setDipFrames(frames);
}

void CLIApp::setTransitionDipSource(quint16 source){
    m_mixEffect->setDipSource(source);
}

void CLIApp::setTransitionMixFrames(quint8 frames){
    m_mixEffect->setMixFrames(frames);
}

void CLIApp::setTransitionNextKey(quint8 keyer, bool state){
    // 0 for background
    m_mixEffect->setKeyOnNextTransition(keyer, state);
}

void CLIApp::setTransitionNextStyle(quint8 style){
    m_mixEffect->setTransitionType(style);
}

void CLIApp::setTransitionPosition(quint16 position){
    m_mixEffect->setTransitionPosition(position);
}

void CLIApp::setTransitionPreview(bool preview){
    m_mixEffect->setTransitionPreview(preview);
}

void CLIApp::setVideoDownConvertType(quint8 mode){
    m_atemConnection->setVideoDownConvertType(mode);
}

void CLIApp::setVideoFormat(quint8 format){
    m_atemConnection->setVideoFormat(format);
}

void CLIApp::onAtemConnected()
{
    reconnect = true;
    qout << "Connected" << endl;
    m_mixEffect = m_atemConnection->mixEffect(0);
    
    connectMixEffectEvents();
    
    reader = new CLIReader(this,&qin);
    connect(reader, SIGNAL(cmdReady(QStringList)), this, SLOT(processCmd(QStringList)));
    reader->start();
    
    qout << "Ready" << endl;
    
}

void CLIApp::onAtemDisconnected()
{
    
    reader->terminate();
    delete reader;
    
    if(!reconnect){
        qout << "Disconnected ... Exiting";
        return;
    }
    
    qout << "Disconnected ... Attempting Reconnect" << endl;
    m_atemConnection->connectToSwitcher(atem_address);
}

void CLIApp::onAtemSocketError(const QString& errorString){
    qout << errorString;
}

void CLIApp::onAtemSwitcherWarning(const QString &warningString){
    qout << warningString;
}

void CLIApp::onAtemTallyStatesChanged(){}

void CLIApp::onAtemDownstreamKeyOnChanged(quint8 keyer, bool state){
    Q_UNUSED(keyer)
    Q_UNUSED(state)
}
void CLIApp::onAtemDownstreamKeyTieChanged(quint8 keyer, bool state){
    Q_UNUSED(keyer)
    Q_UNUSED(state)
}
void CLIApp::onAtemDownstreamKeyFrameCountChanged(quint8 keyer, quint8 count){
    Q_UNUSED(keyer)
    Q_UNUSED(count)
}
void CLIApp::onAtemDownstreamKeyFramesChanged(quint8 keyer, quint8 frames){
    Q_UNUSED(keyer)
    Q_UNUSED(frames)
}
void CLIApp::onAtemDownstreamKeySourcesChanged(quint8 keyer, quint16 fill, quint16 key){
    Q_UNUSED(keyer)
    Q_UNUSED(fill)
    Q_UNUSED(key)
}
void CLIApp::onAtemDownstreamKeyInvertKeyChanged(quint8 keyer, bool invert){
    Q_UNUSED(keyer)
    Q_UNUSED(invert)
}
void CLIApp::onAtemDownstreamKeyPreMultipliedChanged(quint8 keyer, bool preMultiplied){
    Q_UNUSED(keyer)
    Q_UNUSED(preMultiplied)
}
void CLIApp::onAtemDownstreamKeyClipChanged(quint8 keyer, float clip){
    Q_UNUSED(keyer)
    Q_UNUSED(clip)
}
void CLIApp::onAtemDownstreamKeyGainChanged(quint8 keyer, float gain){
    Q_UNUSED(keyer)
    Q_UNUSED(gain)
}
void CLIApp::onAtemDownstreamKeyEnableMaskChanged(quint8 keyer, bool enable){
    Q_UNUSED(keyer)
    Q_UNUSED(enable)
}
void CLIApp::onAtemDownstreamKeyTopMaskChanged(quint8 keyer, float value){
    Q_UNUSED(keyer)
    Q_UNUSED(value)
}
void CLIApp::onAtemDownstreamKeyBottomMaskChanged(quint8 keyer, float value){
    Q_UNUSED(keyer)
    Q_UNUSED(value)
}
void CLIApp::onAtemDownstreamKeyLeftMaskChanged(quint8 keyer, float value){
    Q_UNUSED(keyer)
    Q_UNUSED(value)
}
void CLIApp::onAtemDownstreamKeyRightMaskChanged(quint8 keyer, float value){
    Q_UNUSED(keyer)
    Q_UNUSED(value)
}

void CLIApp::onAtemColorGeneratorColorChanged(quint8 generator, const QColor& color){
    qout << "CLRGEN: [ "<<generator<<" ] " << color.red() << " " << color.green() << " " << color.blue() << endl;
}

void CLIApp::onAtemMediaPlayerChanged(quint8 player, quint8 type, quint8 still, quint8 clip){}
void CLIApp::onAtemMediaPlayerStateChanged(quint8 player, const QAtem::MediaPlayerState& state){}

void CLIApp::onAtemAuxSourceChanged(quint8 aux, quint16 source){
    qout << "AUX: [ "<<aux<<" ] " << m_atemConnection->auxSource(aux) << endl;
}

void CLIApp::onAtemInputInfoChanged(const QAtem::InputInfo& info){
    Q_UNUSED(info)
}

void CLIApp::onAtemMediaInfoChanged(const QAtem::MediaInfo& info){
    Q_UNUSED(info)
}

void CLIApp::onAtemProductInformationChanged(const QString& info){
    Q_UNUSED(info)
}
void CLIApp::onAtemVersionChanged(quint16 major, quint16 minor){
    Q_UNUSED(major)
    Q_UNUSED(minor)
}

void CLIApp::onAtemTimeChanged(quint32 time){
    Q_UNUSED(time)
}

void CLIApp::onAtemVideoFormatChanged(quint8 format){
    Q_UNUSED(format)
}
void CLIApp::onAtemVideoDownConvertTypeChanged(quint8 type){
    Q_UNUSED(type)
}

void CLIApp::onAtemMediaPoolClip1SizeChanged(quint16 size){
    Q_UNUSED(size)
}
void CLIApp::onAtemMediaPoolClip2SizeChanged(quint16 size){
    Q_UNUSED(size)
}

void CLIApp::onAtemAudioInputChanged(quint8 index, const QAtem::AudioInput& input){
    Q_UNUSED(index)
    qout << "AINSTATE: [ "<< input.index <<" ] " << input.state << endl;
    qout << "AINBAL: [ "<< input.index <<" ] " << input.balance << endl;
    qout << "AINGAIN: [ "<< input.index <<" ] " << input.gain << endl;
}

void CLIApp::onAtemAudioMonitorEnabledChanged(bool enabled){
    Q_UNUSED(enabled)
}
void CLIApp::onAtemAudioMonitorGainChanged(float gain){
    Q_UNUSED(gain)
}
void CLIApp::onAtemAudioMonitorMutedChanged(bool muted){
    Q_UNUSED(muted)
}
void CLIApp::onAtemAudioMonitorDimmedChanged(bool dimmed){
    Q_UNUSED(dimmed)
}
void CLIApp::onAtemAudioMonitorSoloChanged(qint8 solo){
    Q_UNUSED(solo)
}

void CLIApp::onAtemAudioMasterOutputGainChanged(float gain){
    qout << "AMSTRGAIN: " << gain << endl;
}

/*
 * AMSTRLVL: LLVL RLVL ( LPEAK RPEAK )
 * ALVLX: LLVL RLVL ( LPEAK RPEAK )
 */
void CLIApp::onAtemAudioLevelsChanged(){
    qout << "AMSTRLVL: " << m_atemConnection->audioMasterOutputLevelLeft() << " " << m_atemConnection->audioMasterOutputLevelRight() << " ( " << m_atemConnection->audioMasterOutputPeakLeft() << " " << m_atemConnection->audioMasterOutputPeakRight() << " )" << endl;
    for(int i=0; i<this->aLvlUpdateList.size(); i++){
        qout << "ALVL: [ "<<this->aLvlUpdateList[i]<<" ] " << m_atemConnection->audioLevel(this->aLvlUpdateList[i]).left << " " << m_atemConnection->audioLevel(this->aLvlUpdateList[i]).right << " ( " << m_atemConnection->audioLevel(this->aLvlUpdateList[i]).peakLeft << " " << m_atemConnection->audioLevel(this->aLvlUpdateList[i]).peakRight << " )" << endl;
    }
}

void CLIApp::onAtemMediaLockStateChanged(quint8 id, bool state){}
void CLIApp::onAtemGetLockStateChanged(quint8 storeId, bool state){}

void CLIApp::onAtemDataTransferFinished(quint16 transferId){}

void CLIApp::onAtemTopologyChanged(const QAtem::Topology &topology){}

void CLIApp::onAtemPowerStatusChanged(quint8 status){}

void CLIApp::onAtemMultiViewLayoutChanged(quint8 multiView, quint8 layout){}
void CLIApp::onAtemMultiViewInputsChanged(quint8 multiView){}

void CLIApp::onAtemMacroInfoChanged(quint8 index, const QAtem::MacroInfo &info){}
void CLIApp::onAtemMacroRunningStateChanged(QAtem::MacroRunningState running, bool repeating, quint8 macroIndex){}
void CLIApp::onAtemMacroRecordingStateChanged(bool recording, quint8 macroIndex){}




void CLIApp::onMixEffectProgramInputChanged(quint8 me, quint16 oldIndex, quint16 newIndex){
    Q_UNUSED(me)
    Q_UNUSED(oldIndex)
    qout << "PROG: " << newIndex << endl;
    
}
void CLIApp::onMixEffectPreviewInputChanged(quint8 me, quint16 oldIndex, quint16 newIndex){
    Q_UNUSED(me)
    Q_UNUSED(oldIndex)
    qout << "PREV: " << newIndex << endl;
}

void CLIApp::onMixEffectTransitionPreviewChanged(quint8 me, bool state){
    Q_UNUSED(me)
    qout << "TPREV: " << state << endl;
}
void CLIApp::onMixEffectTransitionFrameCountChanged(quint8 me, quint8 count){
    Q_UNUSED(me)
    Q_UNUSED(count)
}
void CLIApp::onMixEffectTransitionPositionChanged(quint8 me, quint16 count){
    Q_UNUSED(me)
    qout << "TPOS: " << count << endl;
}
void CLIApp::onMixEffectNextTransitionStyleChanged(quint8 me, quint8 style){
    Q_UNUSED(me)
    qout << "TNEXTSTYLE: " << m_mixEffect->nextTransitionStyle() << endl;
}
void CLIApp::onMixEffectKeyersOnNextTransitionChanged(quint8 me, quint8 keyers){
    Q_UNUSED(me)
    for(int i=0; i<5; i++){
        qout << "TNEXTKEY " << i << ": " << ((keyers >> i)%2) << endl;
    }
    
}
void CLIApp::onMixEffectCurrentTransitionStyleChanged(quint8 me, quint8 style){
    Q_UNUSED(me)
    Q_UNUSED(style)
}
void CLIApp::onMixEffectKeyersOnCurrentTransitionChanged(quint8 me, quint8 keyers){
    Q_UNUSED(me)
    for(int i=0; i<5; i++){
        qout << "TCURRKEY " << i << ": " << ((keyers >> i)%2) << endl;
    }
}

void CLIApp::onMixEffectFadeToBlackChanged(quint8 me, bool fading, bool enabled){
    Q_UNUSED(me)
    if(!fading){
        qout << "FTB: " << enabled << endl;
    }
}
void CLIApp::onMixEffectFadeToBlackFrameCountChanged(quint8 me, quint8 count){
    Q_UNUSED(me)
    Q_UNUSED(count)
}
void CLIApp::onMixEffectFadeToBlackFramesChanged(quint8 me, quint8 frames){
    Q_UNUSED(me)
    qout << "FTBFRAMES: " << frames << endl;
}

void CLIApp::onMixEffectMixFramesChanged(quint8 me, quint8 frames){
    Q_UNUSED(me)
    qout << "TMIXFRAMES: " << frames << endl;
}

void CLIApp::onMixEffectDipFramesChanged(quint8 me, quint8 frames){
    Q_UNUSED(me)
    qout << "TDIPFRAMES: " << frames << endl;
}
void CLIApp::onMixEffectDipSourceChanged(quint8 me, quint16 source){
    Q_UNUSED(me)
    qout << "TDIPSRC: " << source << endl;
}

void CLIApp::onMixEffectWipeFramesChanged(quint8 me, quint8 frames){
    Q_UNUSED(me)
    Q_UNUSED(frames)
}
void CLIApp::onMixEffectWipeBorderWidthChanged(quint8 me, quint16 width){
    Q_UNUSED(me)
    Q_UNUSED(width)
}
void CLIApp::onMixEffectWipeBorderSoftnessChanged(quint8 me, quint16 softness){
    Q_UNUSED(me)
    Q_UNUSED(softness)
}
void CLIApp::onMixEffectWipeTypeChanged(quint8 me, quint8 type){
    Q_UNUSED(me)
    Q_UNUSED(type)
}
void CLIApp::onMixEffectWipeSymmetryChanged(quint8 me, quint16 value){
    Q_UNUSED(me)
    Q_UNUSED(value)
}
void CLIApp::onMixEffectWipeXPositionChanged(quint8 me, quint16 value){
    Q_UNUSED(me)
    Q_UNUSED(value)
}
void CLIApp::onMixEffectWipeYPositionChanged(quint8 me, quint16 value){
    Q_UNUSED(me)
    Q_UNUSED(value)
}
void CLIApp::onMixEffectWipeReverseDirectionChanged(quint8 me, bool reverse){
    Q_UNUSED(me)
    Q_UNUSED(reverse)
}
void CLIApp::onMixEffectWipeFlipFlopChanged(quint8 me, bool flipFlop){
    Q_UNUSED(me)
    Q_UNUSED(flipFlop)
}
void CLIApp::onMixEffectWipeBorderSourceChanged(quint8 me, quint16 index){
    Q_UNUSED(me)
    Q_UNUSED(index)
}

void CLIApp::onMixEffectDveRateChanged(quint8 me, quint16 frames){
    Q_UNUSED(me)
    Q_UNUSED(frames)
}
void CLIApp::onMixEffectDveEffectChanged(quint8 me, quint8 effect){
    Q_UNUSED(me)
    Q_UNUSED(effect)
}
void CLIApp::onMixEffectDveFillSourceChanged(quint8 me, quint16 source){
    Q_UNUSED(me)
    Q_UNUSED(source)
}
void CLIApp::onMixEffectDveKeySourceChanged(quint8 me, quint16 source){
    Q_UNUSED(me)
    Q_UNUSED(source)
}
void CLIApp::onMixEffectDveEnableKeyChanged(quint8 me, bool enabled){
    Q_UNUSED(me)
    Q_UNUSED(enabled)
}
void CLIApp::onMixEffectDveEnablePreMultipliedKeyChanged(quint8 me, bool enabled){
    Q_UNUSED(me)
    Q_UNUSED(enabled)
}
void CLIApp::onMixEffectDveKeyClipChanged(quint8 me, float clip){
    Q_UNUSED(me)
    Q_UNUSED(clip)
}
void CLIApp::onMixEffectDveKeyGainChanged(quint8 me, float gain){
    Q_UNUSED(me)
    Q_UNUSED(gain)
}
void CLIApp::onMixEffectDveEnableInvertKeyChanged(quint8 me, bool enabled){
    Q_UNUSED(me)
    Q_UNUSED(enabled)
}
void CLIApp::onMixEffectDveReverseDirectionChanged(quint8 me, bool reverse){
    Q_UNUSED(me)
    Q_UNUSED(reverse)
}
void CLIApp::onMixEffectDveFlipFlopDirectionChanged(quint8 me, bool flipFlop){
    Q_UNUSED(me)
    Q_UNUSED(flipFlop)
}

void CLIApp::onMixEffectStingerSourceChanged(quint8 me, quint8 source){
    Q_UNUSED(me)
    Q_UNUSED(source)
}
void CLIApp::onMixEffectStingerEnablePreMultipliedKeyChanged(quint8 me, bool enabled){
    Q_UNUSED(me)
    Q_UNUSED(enabled)
}
void CLIApp::onMixEffectStingerClipChanged(quint8 me, float percent){
    Q_UNUSED(me)
    Q_UNUSED(percent)
}
void CLIApp::onMixEffectStingerGainChanged(quint8 me, float percent){
    Q_UNUSED(me)
    Q_UNUSED(percent)
}
void CLIApp::onMixEffectStingerEnableInvertKeyChanged(quint8 me, bool enabled){
    Q_UNUSED(me)
    Q_UNUSED(enabled)
}
void CLIApp::onMixEffectStingerPreRollChanged(quint8 me, quint16 frames){
    Q_UNUSED(me)
    Q_UNUSED(frames)
}
void CLIApp::onMixEffectStingerClipDurationChanged(quint8 me, quint16 frames){
    Q_UNUSED(me)
    Q_UNUSED(frames)
}
void CLIApp::onMixEffectStingerTriggerPointChanged(quint8 me, quint16 frames){
    Q_UNUSED(me)
    Q_UNUSED(frames)
}
void CLIApp::onMixEffectStingerMixRateChanged(quint8 me, quint16 frames){
    Q_UNUSED(me)
    Q_UNUSED(frames)
}

void CLIApp::onMixEffectUpstreamKeyOnAirChanged(quint8 me, quint8 keyer, bool state){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyTypeChanged(quint8 me, quint8 keyer, quint8 type){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyFillSourceChanged(quint8 me, quint8 keyer, quint16 source){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyKeySourceChanged(quint8 me, quint8 keyer, quint16 source){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyEnableMaskChanged(quint8 me, quint8 keyer, bool enable){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyTopMaskChanged(quint8 me, quint8 keyer, float value){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyBottomMaskChanged(quint8 me, quint8 keyer, float value){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyLeftMaskChanged(quint8 me, quint8 keyer, float value){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyRightMaskChanged(quint8 me, quint8 keyer, float value){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyLumaPreMultipliedKeyChanged(quint8 me, quint8 keyer, bool preMultiplied){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyLumaInvertKeyChanged(quint8 me, quint8 keyer, bool invert){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyLumaClipChanged(quint8 me, quint8 keyer, float clip){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyLumaGainChanged(quint8 me, quint8 keyer, float gain){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyChromaHueChanged(quint8 me, quint8 keyer, float hue){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyChromaGainChanged(quint8 me, quint8 keyer, float gain){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyChromaYSuppressChanged(quint8 me, quint8 keyer, float ySuppress){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyChromaLiftChanged(quint8 me, quint8 keyer, float lift){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyChromaNarrowRangeChanged(quint8 me, quint8 keyer, bool narrowRange){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyPatternPatternChanged(quint8 me, quint8 keyer, quint8 pattern){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyPatternInvertPatternChanged(quint8 me, quint8 keyer, bool invert){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyPatternSizeChanged(quint8 me, quint8 keyer, float size){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyPatternSymmetryChanged(quint8 me, quint8 keyer, float symmetry){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyPatternSoftnessChanged(quint8 me, quint8 keyer, float softness){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyPatternXPositionChanged(quint8 me, quint8 keyer, float xPosition){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyPatternYPositionChanged(quint8 me, quint8 keyer, float yPosition){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEXPositionChanged(quint8 me, quint8 keyer, float xPosition){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEYPositionChanged(quint8 me, quint8 keyer, float yPosition){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEXSizeChanged(quint8 me, quint8 keyer, float xSize){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEYSizeChanged(quint8 me, quint8 keyer, float ySize){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVERotationChanged(quint8 me, quint8 keyer, float rotation){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEEnableDropShadowChanged(quint8 me, quint8 keyer, bool enable){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVELighSourceDirectionChanged(quint8 me, quint8 keyer, float direction){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVELightSourceAltitudeChanged(quint8 me, quint8 keyer, quint8 altitude){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEEnableBorderChanged(quint8 me, quint8 keyer, bool enable){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderStyleChanged(quint8 me, quint8 keyer, quint8 style){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderColorChanged(quint8 me, quint8 keyer, QColor color){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderOutsideWidthChanged(quint8 me, quint8 keyer, float width){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderInsideWidthChanged(quint8 me, quint8 keyer, float width){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderOutsideSoftenChanged(quint8 me, quint8 keyer, quint8 soften){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderInsideSoftenChanged(quint8 me, quint8 keyer, quint8 soften){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderOpacityChanged(quint8 me, quint8 keyer, quint8 opacity){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderBevelPositionChanged(quint8 me, quint8 keyer, float position){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEBorderBevelSoftenChanged(quint8 me, quint8 keyer, float soften){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVERateChanged(quint8 me, quint8 keyer, quint8 rate){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEKeyFrameASetChanged(quint8 me, quint8 keyer, bool set){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEKeyFrameBSetChanged(quint8 me, quint8 keyer, bool set){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyEnableFlyChanged(quint8 me, quint8 keyer, bool enabled){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEKeyFrameChanged(quint8 me, quint8 keyer, quint8 frame){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEMaskEnabledChanged(quint8 me, quint8 keyer, bool enabled){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEMaskTopChanged(quint8 me, quint8 keyer, float top){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEMaskBottomChanged(quint8 me, quint8 keyer, float bottom){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEMaskLeftChanged(quint8 me, quint8 keyer, float left){Q_UNUSED(me)}
void CLIApp::onMixEffectUpstreamKeyDVEMaskRightChanged(quint8 me, quint8 keyer, float right){Q_UNUSED(me)}
    


void CLIApp::connectAtemEvents()
{
    //Setup ATEM event triggers
    connect(m_atemConnection, SIGNAL(connected()), this, SLOT(onAtemConnected()));
    connect(m_atemConnection, SIGNAL(disconnected()), this, SLOT(onAtemDisconnected()));
    connect(m_atemConnection, SIGNAL(socketError(const QString&)), this, SLOT(onAtemSocketError(const QString&)));
    connect(m_atemConnection, SIGNAL(switcherWarning(const QString&)), this, SLOT(onAtemSwitcherWarning(const QString&)));
    connect(m_atemConnection, SIGNAL(tallyStatesChanged()), this, SLOT(onAtemTallyStatesChanged()));
    connect(m_atemConnection, SIGNAL(downstreamKeyOnChanged(quint8, bool)), this, SLOT(onAtemDownstreamKeyOnChanged(quint8, bool)));
    connect(m_atemConnection, SIGNAL(downstreamKeyTieChanged(quint8, bool)), this, SLOT(onAtemDownstreamKeyTieChanged(quint8, bool)));
    connect(m_atemConnection, SIGNAL(downstreamKeyFrameCountChanged(quint8, quint8)), this, SLOT(onAtemDownstreamKeyFrameCountChanged(quint8, quint8)));
    connect(m_atemConnection, SIGNAL(downstreamKeyFramesChanged(quint8, quint8)), this, SLOT(onAtemDownstreamKeyFramesChanged(quint8, quint8)));
    connect(m_atemConnection, SIGNAL(downstreamKeySourcesChanged(quint8, quint16, quint16)), this, SLOT(onAtemDownstreamKeySourcesChanged(quint8, quint16, quint16)));
    connect(m_atemConnection, SIGNAL(downstreamKeyInvertKeyChanged(quint8, bool)), this, SLOT(onAtemDownstreamKeyInvertKeyChanged(quint8, bool)));
    connect(m_atemConnection, SIGNAL(downstreamKeyPreMultipliedChanged(quint8, bool)), this, SLOT(onAtemDownstreamKeyPreMultipliedChanged(quint8, bool)));
    connect(m_atemConnection, SIGNAL(downstreamKeyClipChanged(quint8, float)), this, SLOT(onAtemDownstreamKeyClipChanged(quint8, float)));
    connect(m_atemConnection, SIGNAL(downstreamKeyGainChanged(quint8, float)), this, SLOT(onAtemDownstreamKeyGainChanged(quint8, float)));
    connect(m_atemConnection, SIGNAL(downstreamKeyEnableMaskChanged(quint8, bool)), this, SLOT(onAtemDownstreamKeyEnableMaskChanged(quint8, bool)));
    connect(m_atemConnection, SIGNAL(downstreamKeyTopMaskChanged(quint8, float)), this, SLOT(onAtemDownstreamKeyTopMaskChanged(quint8, float)));
    connect(m_atemConnection, SIGNAL(downstreamKeyBottomMaskChanged(quint8, float)), this, SLOT(onAtemDownstreamKeyBottomMaskChanged(quint8, float)));
    connect(m_atemConnection, SIGNAL(downstreamKeyLeftMaskChanged(quint8, float)), this, SLOT(onAtemDownstreamKeyLeftMaskChanged(quint8, float)));
    connect(m_atemConnection, SIGNAL(downstreamKeyRightMaskChanged(quint8, float)), this, SLOT(onAtemDownstreamKeyRightMaskChanged(quint8, float)));
    connect(m_atemConnection, SIGNAL(colorGeneratorColorChanged(quint8,const QColor&)), this, SLOT(onAtemColorGeneratorColorChanged(quint8,const QColor&)));
    connect(m_atemConnection, SIGNAL(mediaPlayerChanged(quint8, quint8,quint8,quint8)), this, SLOT(onAtemMediaPlayerChanged(quint8, quint8,quint8,quint8)));
    connect(m_atemConnection, SIGNAL(mediaPlayerStateChanged(quint8, const QAtem::MediaPlayerState&)), this, SLOT(onAtemMediaPlayerStateChanged(quint8, const QAtem::MediaPlayerState&)));
    connect(m_atemConnection, SIGNAL(auxSourceChanged(quint8, quint16)), this, SLOT(onAtemAuxSourceChanged(quint8, quint16)));
    connect(m_atemConnection, SIGNAL(inputInfoChanged(const QAtem::InputInfo&)), this, SLOT(onAtemInputInfoChanged(const QAtem::InputInfo&)));
    connect(m_atemConnection, SIGNAL(mediaInfoChanged(const QAtem::MediaInfo&)), this, SLOT(onAtemMediaInfoChanged(const QAtem::MediaInfo&)));
    connect(m_atemConnection, SIGNAL(productInformationChanged(const QString&)), this, SLOT(onAtemProductInformationChanged(const QString&)));
    connect(m_atemConnection, SIGNAL(versionChanged(quint16, quint16)), this, SLOT(onAtemVersionChanged(quint16, quint16)));
    connect(m_atemConnection, SIGNAL(timeChanged(quint32)), this, SLOT(onAtemTimeChanged(quint32)));
    connect(m_atemConnection, SIGNAL(videoFormatChanged(quint8)), this, SLOT(onAtemVideoFormatChanged(quint8)));
    connect(m_atemConnection, SIGNAL(videoDownConvertTypeChanged(quint8)), this, SLOT(onAtemVideoDownConvertTypeChanged(quint8)));
    connect(m_atemConnection, SIGNAL(mediaPoolClip1SizeChanged(quint16)), this, SLOT(onAtemMediaPoolClip1SizeChanged(quint16)));
    connect(m_atemConnection, SIGNAL(mediaPoolClip2SizeChanged(quint16)), this, SLOT(onAtemMediaPoolClip2SizeChanged(quint16)));
    connect(m_atemConnection, SIGNAL(audioInputChanged(quint8,const QAtem::AudioInput&)), this, SLOT(onAtemAudioInputChanged(quint8,const QAtem::AudioInput&)));
    connect(m_atemConnection, SIGNAL(audioMonitorEnabledChanged(bool)), this, SLOT(onAtemAudioMonitorEnabledChanged(bool)));
    connect(m_atemConnection, SIGNAL(audioMonitorGainChanged(float)), this, SLOT(onAtemAudioMonitorGainChanged(float)));
    connect(m_atemConnection, SIGNAL(audioMonitorMutedChanged(bool)), this, SLOT(onAtemAudioMonitorMutedChanged(bool)));
    connect(m_atemConnection, SIGNAL(audioMonitorDimmedChanged(bool)), this, SLOT(onAtemAudioMonitorDimmedChanged(bool)));
    connect(m_atemConnection, SIGNAL(audioMonitorSoloChanged(qint8)), this, SLOT(onAtemAudioMonitorSoloChanged(qint8)));
    connect(m_atemConnection, SIGNAL(audioMasterOutputGainChanged(float)), this, SLOT(onAtemAudioMasterOutputGainChanged(float)));
    connect(m_atemConnection, SIGNAL(audioLevelsChanged()), this, SLOT(onAtemAudioLevelsChanged()));
    connect(m_atemConnection, SIGNAL(mediaLockStateChanged(quint8, bool)), this, SLOT(onAtemMediaLockStateChanged(quint8, bool)));
    connect(m_atemConnection, SIGNAL(getLockStateChanged(quint8, bool)), this, SLOT(onAtemGetLockStateChanged(quint8, bool)));
    connect(m_atemConnection, SIGNAL(dataTransferFinished(quint16)), this, SLOT(onAtemDataTransferFinished(quint16)));
    connect(m_atemConnection, SIGNAL(topologyChanged(const QAtem::Topology&)), this, SLOT(onAtemTopologyChanged(const QAtem::Topology&)));
    connect(m_atemConnection, SIGNAL(powerStatusChanged(quint8)), this, SLOT(onAtemPowerStatusChanged(quint8)));
    connect(m_atemConnection, SIGNAL(multiViewLayoutChanged(quint8, quint8)), this, SLOT(onAtemMultiViewLayoutChanged(quint8, quint8)));
    connect(m_atemConnection, SIGNAL(multiViewInputsChanged(quint8)), this, SLOT(onAtemMultiViewInputsChanged(quint8)));
    connect(m_atemConnection, SIGNAL(macroInfoChanged(quint8, const QAtem::MacroInfo&)), this, SLOT(onAtemMacroInfoChanged(quint8, const QAtem::MacroInfo&)));
    connect(m_atemConnection, SIGNAL(macroRunningStateChanged(QAtem::MacroRunningState, bool, quint8)), this, SLOT(onAtemMacroRunningStateChanged(QAtem::MacroRunningState, bool, quint8)));
    connect(m_atemConnection, SIGNAL(macroRecordingStateChanged(bool, quint8)), this, SLOT(onAtemMacroRecordingStateChanged(bool, quint8)));
    
    
    
}

void CLIApp::connectMixEffectEvents()
{
    //Setup MixEffect event triggers
    connect(m_mixEffect, SIGNAL(programInputChanged(quint8, quint16, quint16)), this, SLOT(onMixEffectProgramInputChanged(quint8, quint16, quint16)));
    connect(m_mixEffect, SIGNAL(previewInputChanged(quint8, quint16, quint16)), this, SLOT(onMixEffectPreviewInputChanged(quint8, quint16, quint16)));

    connect(m_mixEffect, SIGNAL(transitionPreviewChanged(quint8, bool)), this, SLOT(onMixEffectTransitionPreviewChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(transitionFrameCountChanged(quint8, quint8)), this, SLOT(onMixEffectTransitionFrameCountChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(transitionPositionChanged(quint8, quint16)), this, SLOT(onMixEffectTransitionPositionChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(nextTransitionStyleChanged(quint8, quint8)), this, SLOT(onMixEffectNextTransitionStyleChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(keyersOnNextTransitionChanged(quint8, quint8)), this, SLOT(onMixEffectKeyersOnNextTransitionChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(currentTransitionStyleChanged(quint8, quint8)), this, SLOT(onMixEffectCurrentTransitionStyleChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(keyersOnCurrentTransitionChanged(quint8, quint8)), this, SLOT(onMixEffectKeyersOnCurrentTransitionChanged(quint8, quint8)));

    connect(m_mixEffect, SIGNAL(fadeToBlackChanged(quint8, bool, bool)), this, SLOT(onMixEffectFadeToBlackChanged(quint8, bool, bool)));
    connect(m_mixEffect, SIGNAL(fadeToBlackFrameCountChanged(quint8, quint8)), this, SLOT(onMixEffectFadeToBlackFrameCountChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(fadeToBlackFramesChanged(quint8, quint8)), this, SLOT(onMixEffectFadeToBlackFramesChanged(quint8, quint8)));

    connect(m_mixEffect, SIGNAL(mixFramesChanged(quint8, quint8)), this, SLOT(onMixEffectMixFramesChanged(quint8, quint8)));

    connect(m_mixEffect, SIGNAL(dipFramesChanged(quint8, quint8)), this, SLOT(onMixEffectDipFramesChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(dipSourceChanged(quint8, quint16)), this, SLOT(onMixEffectDipSourceChanged(quint8, quint16)));

    connect(m_mixEffect, SIGNAL(wipeFramesChanged(quint8, quint8)), this, SLOT(onMixEffectWipeFramesChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(wipeBorderWidthChanged(quint8, quint16)), this, SLOT(onMixEffectWipeBorderWidthChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(wipeBorderSoftnessChanged(quint8, quint16)), this, SLOT(onMixEffectWipeBorderSoftnessChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(wipeTypeChanged(quint8, quint8)), this, SLOT(onMixEffectWipeTypeChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(wipeSymmetryChanged(quint8, quint16)), this, SLOT(onMixEffectWipeSymmetryChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(wipeXPositionChanged(quint8, quint16)), this, SLOT(onMixEffectWipeXPositionChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(wipeYPositionChanged(quint8, quint16)), this, SLOT(onMixEffectWipeYPositionChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(wipeReverseDirectionChanged(quint8, bool)), this, SLOT(onMixEffectWipeReverseDirectionChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(wipeFlipFlopChanged(quint8, bool)), this, SLOT(onMixEffectWipeFlipFlopChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(wipeBorderSourceChanged(quint8, quint16)), this, SLOT(onMixEffectWipeBorderSourceChanged(quint8, quint16)));

    connect(m_mixEffect, SIGNAL(dveRateChanged(quint8, quint16)), this, SLOT(onMixEffectDveRateChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(dveEffectChanged(quint8, quint8)), this, SLOT(onMixEffectDveEffectChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(dveFillSourceChanged(quint8, quint16)), this, SLOT(onMixEffectDveFillSourceChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(dveKeySourceChanged(quint8, quint16)), this, SLOT(onMixEffectDveKeySourceChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(dveEnableKeyChanged(quint8, bool)), this, SLOT(onMixEffectDveEnableKeyChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(dveEnablePreMultipliedKeyChanged(quint8, bool)), this, SLOT(onMixEffectDveEnablePreMultipliedKeyChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(dveKeyClipChanged(quint8, float)), this, SLOT(onMixEffectDveKeyClipChanged(quint8, float)));
    connect(m_mixEffect, SIGNAL(dveKeyGainChanged(quint8, float)), this, SLOT(onMixEffectDveKeyGainChanged(quint8, float)));
    connect(m_mixEffect, SIGNAL(dveEnableInvertKeyChanged(quint8, bool)), this, SLOT(onMixEffectDveEnableInvertKeyChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(dveReverseDirectionChanged(quint8, bool)), this, SLOT(onMixEffectDveReverseDirectionChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(dveFlipFlopDirectionChanged(quint8, bool)), this, SLOT(onMixEffectDveFlipFlopDirectionChanged(quint8, bool)));

    connect(m_mixEffect, SIGNAL(stingerSourceChanged(quint8, quint8)), this, SLOT(onMixEffectStingerSourceChanged(quint8, quint8)));
    connect(m_mixEffect, SIGNAL(stingerEnablePreMultipliedKeyChanged(quint8, bool)), this, SLOT(onMixEffectStingerEnablePreMultipliedKeyChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(stingerClipChanged(quint8, float)), this, SLOT(onMixEffectStingerClipChanged(quint8, float)));
    connect(m_mixEffect, SIGNAL(stingerGainChanged(quint8, float)), this, SLOT(onMixEffectStingerGainChanged(quint8, float)));
    connect(m_mixEffect, SIGNAL(stingerEnableInvertKeyChanged(quint8, bool)), this, SLOT(onMixEffectStingerEnableInvertKeyChanged(quint8, bool)));
    connect(m_mixEffect, SIGNAL(stingerPreRollChanged(quint8, quint16)), this, SLOT(onMixEffectStingerPreRollChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(stingerClipDurationChanged(quint8, quint16)), this, SLOT(onMixEffectStingerClipDurationChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(stingerTriggerPointChanged(quint8, quint16)), this, SLOT(onMixEffectStingerTriggerPointChanged(quint8, quint16)));
    connect(m_mixEffect, SIGNAL(stingerMixRateChanged(quint8, quint16)), this, SLOT(onMixEffectStingerMixRateChanged(quint8, quint16)));

    connect(m_mixEffect, SIGNAL(upstreamKeyOnAirChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyOnAirChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyTypeChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyTypeChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyFillSourceChanged(quint8, quint8, quint16)), this, SLOT(onMixEffectUpstreamKeyFillSourceChanged(quint8, quint8, quint16)));
    connect(m_mixEffect, SIGNAL(upstreamKeyKeySourceChanged(quint8, quint8, quint16)), this, SLOT(onMixEffectUpstreamKeyKeySourceChanged(quint8, quint8, quint16)));
    connect(m_mixEffect, SIGNAL(upstreamKeyEnableMaskChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyEnableMaskChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyTopMaskChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyTopMaskChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyBottomMaskChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyBottomMaskChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyLeftMaskChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyLeftMaskChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyRightMaskChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyRightMaskChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyLumaPreMultipliedKeyChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyLumaPreMultipliedKeyChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyLumaInvertKeyChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyLumaInvertKeyChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyLumaClipChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyLumaClipChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyLumaGainChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyLumaGainChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyChromaHueChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyChromaHueChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyChromaGainChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyChromaGainChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyChromaYSuppressChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyChromaYSuppressChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyChromaLiftChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyChromaLiftChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyChromaNarrowRangeChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyChromaNarrowRangeChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyPatternPatternChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyPatternPatternChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyPatternInvertPatternChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyPatternInvertPatternChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyPatternSizeChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyPatternSizeChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyPatternSymmetryChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyPatternSymmetryChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyPatternSoftnessChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyPatternSoftnessChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyPatternXPositionChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyPatternXPositionChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyPatternYPositionChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyPatternYPositionChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEXPositionChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEXPositionChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEYPositionChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEYPositionChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEXSizeChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEXSizeChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEYSizeChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEYSizeChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVERotationChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVERotationChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEEnableDropShadowChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyDVEEnableDropShadowChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVELighSourceDirectionChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVELighSourceDirectionChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVELightSourceAltitudeChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyDVELightSourceAltitudeChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEEnableBorderChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyDVEEnableBorderChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderStyleChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyDVEBorderStyleChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderColorChanged(quint8, quint8, QColor)), this, SLOT(onMixEffectUpstreamKeyDVEBorderColorChanged(quint8, quint8, QColor)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderOutsideWidthChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEBorderOutsideWidthChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderInsideWidthChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEBorderInsideWidthChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderOutsideSoftenChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyDVEBorderOutsideSoftenChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderInsideSoftenChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyDVEBorderInsideSoftenChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderOpacityChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyDVEBorderOpacityChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderBevelPositionChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEBorderBevelPositionChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEBorderBevelSoftenChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEBorderBevelSoftenChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVERateChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyDVERateChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEKeyFrameASetChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyDVEKeyFrameASetChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEKeyFrameBSetChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyDVEKeyFrameBSetChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyEnableFlyChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyEnableFlyChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEKeyFrameChanged(quint8, quint8, quint8)), this, SLOT(onMixEffectUpstreamKeyDVEKeyFrameChanged(quint8, quint8, quint8)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEMaskEnabledChanged(quint8, quint8, bool)), this, SLOT(onMixEffectUpstreamKeyDVEMaskEnabledChanged(quint8, quint8, bool)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEMaskTopChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEMaskTopChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEMaskBottomChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEMaskBottomChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEMaskLeftChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEMaskLeftChanged(quint8, quint8, float)));
    connect(m_mixEffect, SIGNAL(upstreamKeyDVEMaskRightChanged(quint8, quint8, float)), this, SLOT(onMixEffectUpstreamKeyDVEMaskRightChanged(quint8, quint8, float)));

   
}
