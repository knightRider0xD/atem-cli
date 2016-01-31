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

#ifndef CLIAPP_H
#define CLIAPP_H

#include <QtCore>
#include <QObject>
#include <QTextStream>
#include <QHostAddress>
#include "qatemtypes.h"
#include "qatemmixeffect.h"
#include "qatemconnection.h"

class QAtemConnection;

class CLIReader : public QThread
{
    Q_OBJECT
private:
    QTextStream * qin;
public:
    CLIReader(QObject * parent = 0, QTextStream * qin = 0 ): QThread(parent){this->qin = qin;}

    void run();

signals:
    void cmdReady(QStringList cmd);

};

class CLIApp : public QObject
{
    Q_OBJECT
private:
    bool reconnect = true;
    QTextStream qin;
    QTextStream qout;
    QHostAddress atem_address;
    QAtemMixEffect *m_mixEffect;
    QAtemConnection *m_atemConnection;
    CLIReader *reader;
    
    QList<quint16> aLvlUpdateList;
    
    void connectAtemEvents(); 
    void connectMixEffectEvents();
    
public:
    CLIApp(QObject *parent = 0, QString address = QString("192.168.10.240")) : QObject(parent), qin(stdin), qout(stdout){ if(!atem_address.setAddress(address)){emit finished();} }
    
    //void printStatus();
    
    void help();
    void helpVSrc();
    void helpASrc();
    void helpVFmt();
    
    void quit();
    void invalidCmd();
    
    void doCut();
    void doAutoTransition();
    
    void saveSettings();
    void clearSettings();
    
    void getAtemInfo();
    void getAudioChannelCount();
    void getAudioInBalance(quint16 channel);
    void getAudioInGain(quint16 channel);
    void getAudioInInfo(quint16 channel);
    void getAudioInState(quint16 channel);
    void getAudioLevels(QList<quint16> channels);
    void getAudioMasterGain();
    void getAudioMasterLevels();
    void getAuxSource(quint8 aux);
    void getColorGeneratorColor(quint8 generator);
    void getConnection();
    void getDebug();
    void getFadeToBlack();
    void getFadeToBlackFading();
    void getFadeToBlackFrames();
    void getFadeToBlackFramesLeft();
    //void getInputInfo(QStringList cmd);
    void getInputNameLong(quint16 input);
    void getInputNameShort(quint16 input);
    void getInputType(quint16 input);
    void getPreview();
    void getProgram();
    //void getTransitionCurrentKey(QStringList cmd);
    void getTransitionCurrentStyle();
    void getTransitionDipFrames();
    void getTransitionDipSource();
    //void getTransitionDVEEffect(QStringList cmd);
    //void getTransitionDVEFillSource(QStringList cmd);
    //void getTransitionDVEFrames(QStringList cmd);
    void getTransitionFrames();
    //void getTallyChannelCount(QStringList cmd);
    //void getTallyIndexCount(QStringList cmd);
    //void getTallyState(QStringList cmd);
    void getTransitionMixFrames();
    //void getTransitionNextBackground(QStringList cmd);
    //void getTransitionNextKey(QStringList cmd);
    void getTransitionNextStyle();
    void getTransitionPosition();
    void getTransitionPreview();
    void getVideoDownConvertType();
    void getVideoFormat();
    
    void setAudioInBalance(quint16 channel, float balance);
    void setAudioInGain(quint16 channel, float gain);
    void resetAudioInPeak(quint16 channel);
    void setAudioInState(quint16 channel, quint8 state);
    void enableAudioLevels(bool enabled, QList<quint16> channels);
    void setAudioMasterGain(float gain);
    void resetAudioMasterPeak();
    void setAuxSource(quint8 aux, quint16 index);
    void setColorGeneratorColor(quint8 generator, quint8 red, quint8 green, quint8 blue);
    void setConnection(bool enable);
    void setDebug(bool enable);
    void setFadeToBlack(bool ftb);
    void toggleFadeToBlack();
    void setFadeToBlackFrames(quint8 frames);
    void setInputNameLong(quint16 input, QString name);
    void setInputNameShort(quint16 input, QString name);
    void setInputType(quint16 input, quint8 type);
    void setPreview(quint16 index);
    void setProgram(quint16 index);
    //void setTransitionCurrentKey(QStringList cmd);
    //void setTransitionCurrentStyle(QStringList cmd);
    void setTransitionDipFrames(quint8 frames);
    void setTransitionDipSource(quint16 source);
    //void setTransitionDVEEffect(QStringList cmd);
    //void setTransitionDVEFillSource(QStringList cmd);
    //void setTransitionDVEFrames(QStringList cmd);
    //void setTallyChannelCount(QStringList cmd);
    //void setTallyIndexCount(QStringList cmd);
    //void setTallyState(QStringList cmd);
    void setTransitionMixFrames(quint8 frames);
    //void setTransitionNextBackground(QStringList cmd);
    //void setTransitionNextKey(QStringList cmd);
    void setTransitionNextStyle(quint8 style);
    void setTransitionPosition(quint16 position);
    void setTransitionPreview(bool preview);
    void setVideoDownConvertType(quint8 mode);
    void setVideoFormat(quint8 format);

public slots:
    void run();
    
    void processCmd(QStringList cmd);

    // ATEM Slots
    void onAtemConnected();
    void onAtemDisconnected();
    void onAtemSocketError(const QString& errorString);

    void onAtemSwitcherWarning(const QString &warningString);

    void onAtemTallyStatesChanged();

    void onAtemDownstreamKeyOnChanged(quint8 keyer, bool state);
    void onAtemDownstreamKeyTieChanged(quint8 keyer, bool state);
    void onAtemDownstreamKeyFrameCountChanged(quint8 keyer, quint8 count);
    void onAtemDownstreamKeyFramesChanged(quint8 keyer, quint8 frames);
    void onAtemDownstreamKeySourcesChanged(quint8 keyer, quint16 fill, quint16 key);
    void onAtemDownstreamKeyInvertKeyChanged(quint8 keyer, bool invert);
    void onAtemDownstreamKeyPreMultipliedChanged(quint8 keyer, bool preMultiplied);
    void onAtemDownstreamKeyClipChanged(quint8 keyer, float clip);
    void onAtemDownstreamKeyGainChanged(quint8 keyer, float gain);
    void onAtemDownstreamKeyEnableMaskChanged(quint8 keyer, bool enable);
    void onAtemDownstreamKeyTopMaskChanged(quint8 keyer, float value);
    void onAtemDownstreamKeyBottomMaskChanged(quint8 keyer, float value);
    void onAtemDownstreamKeyLeftMaskChanged(quint8 keyer, float value);
    void onAtemDownstreamKeyRightMaskChanged(quint8 keyer, float value);

    void onAtemColorGeneratorColorChanged(quint8 generator, const QColor& color);

    void onAtemMediaPlayerChanged(quint8 player, quint8 type, quint8 still, quint8 clip);
    void onAtemMediaPlayerStateChanged(quint8 player, const QAtem::MediaPlayerState& state);

    void onAtemAuxSourceChanged(quint8 aux, quint16 source);

    void onAtemInputInfoChanged(const QAtem::InputInfo& info);

    void onAtemMediaInfoChanged(const QAtem::MediaInfo& info);

    void onAtemProductInformationChanged(const QString& info);
    void onAtemVersionChanged(quint16 major, quint16 minor);

    void onAtemTimeChanged(quint32 time);

    void onAtemVideoFormatChanged(quint8 format);
    void onAtemVideoDownConvertTypeChanged(quint8 type);

    void onAtemMediaPoolClip1SizeChanged(quint16 size);
    void onAtemMediaPoolClip2SizeChanged(quint16 size);

    void onAtemAudioInputChanged(quint8 index, const QAtem::AudioInput& input);
    void onAtemAudioMonitorEnabledChanged(bool enabled);
    void onAtemAudioMonitorGainChanged(float gain);
    void onAtemAudioMonitorMutedChanged(bool muted);
    void onAtemAudioMonitorDimmedChanged(bool dimmed);
    void onAtemAudioMonitorSoloChanged(qint8 solo);
    void onAtemAudioMasterOutputGainChanged(float gain);
    void onAtemAudioLevelsChanged();

    void onAtemMediaLockStateChanged(quint8 id, bool state);
    void onAtemGetLockStateChanged(quint8 storeId, bool state);

    void onAtemDataTransferFinished(quint16 transferId);

    void onAtemTopologyChanged(const QAtem::Topology &topology);

    void onAtemPowerStatusChanged(quint8 status);

    void onAtemMultiViewLayoutChanged(quint8 multiView, quint8 layout);
    void onAtemMultiViewInputsChanged(quint8 multiView);

    void onAtemMacroInfoChanged(quint8 index, const QAtem::MacroInfo &info);
    void onAtemMacroRunningStateChanged(QAtem::MacroRunningState running, bool repeating, quint8 macroIndex);
    void onAtemMacroRecordingStateChanged(bool recording, quint8 macroIndex);
    
    // Mix Effect Slots
    void onMixEffectProgramInputChanged(quint8 me, quint16 oldIndex, quint16 newIndex);
    void onMixEffectPreviewInputChanged(quint8 me, quint16 oldIndex, quint16 newIndex);

    void onMixEffectTransitionPreviewChanged(quint8 me, bool state);
    void onMixEffectTransitionFrameCountChanged(quint8 me, quint8 count);
    void onMixEffectTransitionPositionChanged(quint8 me, quint16 count);
    void onMixEffectNextTransitionStyleChanged(quint8 me, quint8 style);
    void onMixEffectKeyersOnNextTransitionChanged(quint8 me, quint8 keyers);
    void onMixEffectCurrentTransitionStyleChanged(quint8 me, quint8 style);
    void onMixEffectKeyersOnCurrentTransitionChanged(quint8 me, quint8 keyers);

    void onMixEffectFadeToBlackChanged(quint8 me, bool fading, bool enabled);
    void onMixEffectFadeToBlackFrameCountChanged(quint8 me, quint8 count);
    void onMixEffectFadeToBlackFramesChanged(quint8 me, quint8 frames);

    void onMixEffectMixFramesChanged(quint8 me, quint8 frames);

    void onMixEffectDipFramesChanged(quint8 me, quint8 frames);
    void onMixEffectDipSourceChanged(quint8 me, quint16 source);

    void onMixEffectWipeFramesChanged(quint8 me, quint8 frames);
    void onMixEffectWipeBorderWidthChanged(quint8 me, quint16 width);
    void onMixEffectWipeBorderSoftnessChanged(quint8 me, quint16 softness);
    void onMixEffectWipeTypeChanged(quint8 me, quint8 type);
    void onMixEffectWipeSymmetryChanged(quint8 me, quint16 value);
    void onMixEffectWipeXPositionChanged(quint8 me, quint16 value);
    void onMixEffectWipeYPositionChanged(quint8 me, quint16 value);
    void onMixEffectWipeReverseDirectionChanged(quint8 me, bool reverse);
    void onMixEffectWipeFlipFlopChanged(quint8 me, bool flipFlop);
    void onMixEffectWipeBorderSourceChanged(quint8 me, quint16 index);

    void onMixEffectDveRateChanged(quint8 me, quint16 frames);
    void onMixEffectDveEffectChanged(quint8 me, quint8 effect);
    void onMixEffectDveFillSourceChanged(quint8 me, quint16 source);
    void onMixEffectDveKeySourceChanged(quint8 me, quint16 source);
    void onMixEffectDveEnableKeyChanged(quint8 me, bool enabled);
    void onMixEffectDveEnablePreMultipliedKeyChanged(quint8 me, bool enabled);
    void onMixEffectDveKeyClipChanged(quint8 me, float clip);
    void onMixEffectDveKeyGainChanged(quint8 me, float gain);
    void onMixEffectDveEnableInvertKeyChanged(quint8 me, bool enabled);
    void onMixEffectDveReverseDirectionChanged(quint8 me, bool reverse);
    void onMixEffectDveFlipFlopDirectionChanged(quint8 me, bool flipFlop);

    void onMixEffectStingerSourceChanged(quint8 me, quint8 source);
    void onMixEffectStingerEnablePreMultipliedKeyChanged(quint8 me, bool enabled);
    void onMixEffectStingerClipChanged(quint8 me, float percent);
    void onMixEffectStingerGainChanged(quint8 me, float percent);
    void onMixEffectStingerEnableInvertKeyChanged(quint8 me, bool enabled);
    void onMixEffectStingerPreRollChanged(quint8 me, quint16 frames);
    void onMixEffectStingerClipDurationChanged(quint8 me, quint16 frames);
    void onMixEffectStingerTriggerPointChanged(quint8 me, quint16 frames);
    void onMixEffectStingerMixRateChanged(quint8 me, quint16 frames);

    void onMixEffectUpstreamKeyOnAirChanged(quint8 me, quint8 keyer, bool state);
    void onMixEffectUpstreamKeyTypeChanged(quint8 me, quint8 keyer, quint8 type);
    void onMixEffectUpstreamKeyFillSourceChanged(quint8 me, quint8 keyer, quint16 source);
    void onMixEffectUpstreamKeyKeySourceChanged(quint8 me, quint8 keyer, quint16 source);
    void onMixEffectUpstreamKeyEnableMaskChanged(quint8 me, quint8 keyer, bool enable);
    void onMixEffectUpstreamKeyTopMaskChanged(quint8 me, quint8 keyer, float value);
    void onMixEffectUpstreamKeyBottomMaskChanged(quint8 me, quint8 keyer, float value);
    void onMixEffectUpstreamKeyLeftMaskChanged(quint8 me, quint8 keyer, float value);
    void onMixEffectUpstreamKeyRightMaskChanged(quint8 me, quint8 keyer, float value);
    void onMixEffectUpstreamKeyLumaPreMultipliedKeyChanged(quint8 me, quint8 keyer, bool preMultiplied);
    void onMixEffectUpstreamKeyLumaInvertKeyChanged(quint8 me, quint8 keyer, bool invert);
    void onMixEffectUpstreamKeyLumaClipChanged(quint8 me, quint8 keyer, float clip);
    void onMixEffectUpstreamKeyLumaGainChanged(quint8 me, quint8 keyer, float gain);
    void onMixEffectUpstreamKeyChromaHueChanged(quint8 me, quint8 keyer, float hue);
    void onMixEffectUpstreamKeyChromaGainChanged(quint8 me, quint8 keyer, float gain);
    void onMixEffectUpstreamKeyChromaYSuppressChanged(quint8 me, quint8 keyer, float ySuppress);
    void onMixEffectUpstreamKeyChromaLiftChanged(quint8 me, quint8 keyer, float lift);
    void onMixEffectUpstreamKeyChromaNarrowRangeChanged(quint8 me, quint8 keyer, bool narrowRange);
    void onMixEffectUpstreamKeyPatternPatternChanged(quint8 me, quint8 keyer, quint8 pattern);
    void onMixEffectUpstreamKeyPatternInvertPatternChanged(quint8 me, quint8 keyer, bool invert);
    void onMixEffectUpstreamKeyPatternSizeChanged(quint8 me, quint8 keyer, float size);
    void onMixEffectUpstreamKeyPatternSymmetryChanged(quint8 me, quint8 keyer, float symmetry);
    void onMixEffectUpstreamKeyPatternSoftnessChanged(quint8 me, quint8 keyer, float softness);
    void onMixEffectUpstreamKeyPatternXPositionChanged(quint8 me, quint8 keyer, float xPosition);
    void onMixEffectUpstreamKeyPatternYPositionChanged(quint8 me, quint8 keyer, float yPosition);
    void onMixEffectUpstreamKeyDVEXPositionChanged(quint8 me, quint8 keyer, float xPosition);
    void onMixEffectUpstreamKeyDVEYPositionChanged(quint8 me, quint8 keyer, float yPosition);
    void onMixEffectUpstreamKeyDVEXSizeChanged(quint8 me, quint8 keyer, float xSize);
    void onMixEffectUpstreamKeyDVEYSizeChanged(quint8 me, quint8 keyer, float ySize);
    void onMixEffectUpstreamKeyDVERotationChanged(quint8 me, quint8 keyer, float rotation);
    void onMixEffectUpstreamKeyDVEEnableDropShadowChanged(quint8 me, quint8 keyer, bool enable);
    void onMixEffectUpstreamKeyDVELighSourceDirectionChanged(quint8 me, quint8 keyer, float direction);
    void onMixEffectUpstreamKeyDVELightSourceAltitudeChanged(quint8 me, quint8 keyer, quint8 altitude);
    void onMixEffectUpstreamKeyDVEEnableBorderChanged(quint8 me, quint8 keyer, bool enable);
    void onMixEffectUpstreamKeyDVEBorderStyleChanged(quint8 me, quint8 keyer, quint8 style);
    void onMixEffectUpstreamKeyDVEBorderColorChanged(quint8 me, quint8 keyer, QColor color);
    void onMixEffectUpstreamKeyDVEBorderOutsideWidthChanged(quint8 me, quint8 keyer, float width);
    void onMixEffectUpstreamKeyDVEBorderInsideWidthChanged(quint8 me, quint8 keyer, float width);
    void onMixEffectUpstreamKeyDVEBorderOutsideSoftenChanged(quint8 me, quint8 keyer, quint8 soften);
    void onMixEffectUpstreamKeyDVEBorderInsideSoftenChanged(quint8 me, quint8 keyer, quint8 soften);
    void onMixEffectUpstreamKeyDVEBorderOpacityChanged(quint8 me, quint8 keyer, quint8 opacity);
    void onMixEffectUpstreamKeyDVEBorderBevelPositionChanged(quint8 me, quint8 keyer, float position);
    void onMixEffectUpstreamKeyDVEBorderBevelSoftenChanged(quint8 me, quint8 keyer, float soften);
    void onMixEffectUpstreamKeyDVERateChanged(quint8 me, quint8 keyer, quint8 rate);
    void onMixEffectUpstreamKeyDVEKeyFrameASetChanged(quint8 me, quint8 keyer, bool set);
    void onMixEffectUpstreamKeyDVEKeyFrameBSetChanged(quint8 me, quint8 keyer, bool set);
    void onMixEffectUpstreamKeyEnableFlyChanged(quint8 me, quint8 keyer, bool enabled);
    void onMixEffectUpstreamKeyDVEKeyFrameChanged(quint8 me, quint8 keyer, quint8 frame);
    void onMixEffectUpstreamKeyDVEMaskEnabledChanged(quint8 me, quint8 keyer, bool enabled);
    void onMixEffectUpstreamKeyDVEMaskTopChanged(quint8 me, quint8 keyer, float top);
    void onMixEffectUpstreamKeyDVEMaskBottomChanged(quint8 me, quint8 keyer, float bottom);
    void onMixEffectUpstreamKeyDVEMaskLeftChanged(quint8 me, quint8 keyer, float left);
    void onMixEffectUpstreamKeyDVEMaskRightChanged(quint8 me, quint8 keyer, float right);

signals:
    void finished();
};


#endif // CLIAPP_H