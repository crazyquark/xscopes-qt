/***************************************************************************
**                                                                        **
**  XprotolabInterface                                                    **
**  Copyright (C) 2013 Gabotronics                                        **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Syed Adnan Kamili                                    **
**          Contact: adnan.kamili@gmail.com                               **
**             Date: 13.10.13                                             **
**          Version: 0.1-1                                                **
****************************************************************************/

#ifndef XPROTOLABINTERFACE_H
#define XPROTOLABINTERFACE_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QtEndian>
#include "qcustomplot.h"
#include "libusbdevice.h"
#include "fft.h"
#include "sniffer.h"

enum WindowFunction {
    Rectangular,
    Hamming,
    Hann,
    Blackman
};

enum Protocol {
    SPI,
    I2C,
    RS232
};

enum Mode {
    OSCILLOSCOPE,
    SNIFFER,
    METER,
    NONE
};

namespace Ui {
class XprotolabInterface;
}

class XprotolabInterface : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit XprotolabInterface(QWidget *parent = 0);
    ~XprotolabInterface();

private:
    void setupGrid(QCustomPlot *);
    void setupTracers(QCustomPlot *);
    void setupCursors(QCustomPlot *);
    void setupItemLabels(QCustomPlot *);
    void closeEvent(QCloseEvent *);
    void selectWaveForm(uint8_t);
    void readDeviceSettings();
    void updateSweepCursors();
    void parseCSV(QString, byte*);
    void sendCH1Controls();
    void sendCH2Controls();
    void sendCHDControls();
    void sendCHDBitControls();
    void sendTriggerControls();
    void sendCursorControls();
    void sendMFFTControls();
    void sendVerticalCursorA();
    void sendVerticalCursorB();
    void sendHorizontalCursorCH1A();
    void sendHorizontalCursorCH1B();
    void sendHorizontalCursorCH2A();
    void sendHorizontalCursorCH2B();
    void sendSweepControls();
    void sendSnifferSettings();
    void sendDisplayControls();
    void sendMStatusControls();
    void updateFrequency();
    void setupValues();
    void setFFTWindow(int);
    void setDecodeProtocol(int);
    void setTriggerLevel(byte);
    void setTriggerPost(unsigned short);
    void setTriggerLevelPosition();

    
private slots:
    void on_playButton_clicked();
    void plotData();
    void sniffProtocol();
    void moveCursor(QMouseEvent*);
    void on_autoButton_clicked();

    void on_connectButton_clicked();

    void xAxisChanged(QCPRange);

    void on_stopButton_clicked();

    void on_radioButtonExpo_clicked();

    void on_radioButtonTriangle_clicked();

    void on_radioButtonSquare_clicked();

    void on_radioButtonSine_clicked();

    void on_radioButtonNoise_clicked();

    void on_radioButtonCustom_clicked();

    void on_zoomSlider_valueChanged(int value);

    void on_samplingSlider_valueChanged(int value);

    void on_ch1PositionSlider_valueChanged(int value);

    void on_ch2PositionSlider_valueChanged(int value);

    void on_openCSVButton_clicked();

    void on_saveAWGButton_clicked();

    void on_checkBoxCH1Math_clicked();

    void on_checkBoxCH1Invert_clicked();

    void on_checkBoxCH1Trace_clicked();

    void on_checkBoxCH1Average_clicked();

    void on_checkBoxCH2Math_clicked();

    void on_checkBoxCH2Invert_clicked();

    void on_checkBoxCH2Trace_clicked();

    void on_checkBoxCH2Average_clicked();

    void on_radioButtonCH2Sub_clicked();

    void on_radioButtonCH1Sub_clicked();

    void on_checkBoxCHDTrace_clicked();

    void on_checkBoxCHDInvert_clicked();

    void on_checkBoxCHDThick0_clicked();

    void on_chdPullSlider_valueChanged(int value);

    void on_checkBoxASCII_clicked();

    void on_checkBoxCHD0_clicked();

    void on_checkBoxCHD1_clicked();

    void on_checkBoxCHD2_clicked();

    void on_checkBoxCHD3_clicked();

    void on_checkBoxCHD4_clicked();

    void on_checkBoxCHD5_clicked();

    void on_checkBoxCHD6_clicked();

    void on_checkBoxCHD7_clicked();

    void on_radioButtonRising_clicked();

    void on_radioButtonFalling_clicked();

    void on_radioButtonDual_clicked();

    void on_radioButtonPositive_clicked();

    void on_radioButtonNegative_clicked();

    void on_radioButtonWindow_clicked();

    void on_radioButtonFree_clicked();

    void on_radioButtonNormal_clicked();

    void on_radioButtonAuto_clicked();

    void on_radioButtonSingle_clicked();

    void on_checkBoxCircular_clicked();

    void on_rollMode_clicked();

    void on_checkBoxLogY_clicked();

    void on_checkBoxFFTTrace_clicked();

    void on_checkBoxIQFFT_clicked();

    void on_radioButtonRect_clicked();

    void on_radioButtonHamming_clicked();

    void on_radioButtonHann_clicked();

    void on_radioButtonBlackman_clicked();

    void on_xyMode_clicked();

    void on_checkBoxSweepFrequency_clicked();

    void on_checkBoxSweepAmplitude_clicked();

    void on_checkBoxSweepDutyCycle_clicked();

    void on_checkBoxSweepOffset_clicked();

    void on_checkBoxDirection_clicked();

    void on_checkBoxPingPong_clicked();

    void on_checkBoxAccelerate_clicked();

    void on_checkBoxAccelDirection_clicked();

    void on_radioButtonSniffNormal_clicked();

    void on_radioButtonSniffSingle_clicked();

    void on_comboBoxBaud_currentIndexChanged(int index);

    void on_comboBoxParity_currentIndexChanged(int index);

    void on_comboBoxStopBits_currentIndexChanged(int index);

    void on_comboBoxCPOL_currentIndexChanged(int index);

    void on_comboBoxCPHA_currentIndexChanged(int index);



    void on_forceButton_clicked();

    void on_ch1GainSlider_valueChanged(int value);

    void on_ch2GainSlider_valueChanged(int value);

    void on_horizontalScrollBar_sliderMoved(int position);

    void on_doubleSpinBoxTrigHold_valueChanged(double arg1);

    void on_comboBoxTrigSource_currentIndexChanged(int index);

    void on_doubleSpinBoxTrigAuto_valueChanged(double arg1);

    void on_chdPositionSlider_valueChanged(int value);

    void on_sweepStartFreqSlider_valueChanged(int value);

    void on_sweepEndFreqSlider_valueChanged(int value);

    void on_sweepSpeedSlider_valueChanged(int value);

    void on_doubleSpinBoxAmp_valueChanged(double arg1);

    void on_amplitudeSlider_valueChanged(int value);

    void on_doubleSpinBoxDuty_valueChanged(double arg1);

    void on_dutyCycleSlider_valueChanged(int value);

    void on_doubleSpinBoxOffset_valueChanged(double arg1);

    void on_offsetSlider_valueChanged(int value);

    void on_doubleSpinBoxDesiredFreq_valueChanged(double arg1);

    void on_frequencySlider_valueChanged(int value);

    void on_radioButton10_clicked();

    void on_radioButton100_clicked();

    void on_radioButton1K_clicked();

    void on_radioButton10K_clicked();

    void on_radioButton100K_clicked();

    void on_checkBoxInvert_clicked();

    void on_checkBoxShowSettings_clicked();

    void on_checkBoxFlip_clicked();

    void on_checkBoxPersistence_clicked();

    void on_checkBoxVectors_clicked();

    void on_comboBoxGrid_currentIndexChanged(int index);

    void on_elasticMode_clicked();


    void on_checkBoxCursorAuto_clicked();

    void on_checkBoxCursorTrack_clicked();

    void on_checkBoxCursorVertical_clicked();

    void on_radioButtonCursorCH1_clicked();

    void on_radioButtonCursorCH2_clicked();

    void on_radioButtonCursorNone_clicked();

    void on_startSnifferButton_clicked();

    void on_protocolTabWidget_currentChanged(int index);

    void on_ch2CaptureSlider_valueChanged(int value);

    void on_ch1CaptureSlider_valueChanged(int value);

    void on_chdCaptureSelector_valueChanged(int value);

private:
    Ui::XprotolabInterface *ui;
    QTimer dataTimer;
    LibUsbDevice usbDevice;
    Sniffer *sniffLogic;
    bool isScrolling;
    double rangeMax,fftWindow[256],hCursorAPos ,hCursorBPos ,vCursorAPos ,vCursorBPos;
    QStringList rateText,gainText;
    int freqValue[23],xmax,mode;
    bool bitChecked[8],itemIsSelected;
    QCPGraph *bars1,*bars2;
    QCPItemTracer *phaseTracerAA, *phaseTracerAB, *phaseTracerBA, *phaseTracerBB;
    QCPItemStraightLine *hCursorA, *hCursorB, *vCursorA, *vCursorB;
    QCPItemPixmap *hCursorAHead, *hCursorBHead;
    QCPItemPixmap *triggerPixmap, *vCursorAHead, *vCursorBHead;
    QCPItemText *textLabelBit[8], *textLabelDeltaTime, *textLabelDeltaVoltage, *textLabelVoltage, *textLabelFrequency;
    byte sniffBuffer[1289], triggerLevel;
    uint16_t triggerPost;
   // QLabel *ch1Label, *ch2Label, *timeLabel;

   // QCPLegend *legend;
   // double xtime;
};

#endif // XPROTOLABINTERFACE_H
