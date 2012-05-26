/**
 ******************************************************************************
 *
 * @file       generici2cwidget.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup GenericI2CPlugin
 * @{
 * @brief A place holder gadget plugin
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "generici2cwidget.h"
#include "generici2cfactory.h"
#include "vminstructionform.h"

#include <QDebug>
#include <QtGui/QWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>
#include <QScrollArea>
//#include "uavobjectwidgetutils/configtaskwidget.h"


GenericI2CWidget::GenericI2CWidget(QWidget *parent) : QLabel(parent)
{


    m_widget = new Ui_GenericI2CWidget();
    m_widget->setupUi(this);

//    addUAVObject("GenericI2CSensor");

//    addApplySaveButtons(m_widget->ApplyPushButton,m_widget->SavePushButton);

    m_widget->hexDexComboBox->addItem("Hexadecimal");
    m_widget->hexDexComboBox->addItem("Decimal");

//    instructionTypes << "None" << "Write" << "Read" << "Delay [ms]" << "Send UAVO";
//    m_widget->InstructionComboBox_0->addItems(instructionTypes);
//    m_widget->InstructionComboBox_0->setCurrentIndex(0);

    //Connect elements to callback functions
//    connect(m_widget->InstructionComboBox_0, SIGNAL(currentIndexChanged(QString)), this, SLOT(switchCompilerInst(QString)));
    connect(m_widget->AdditionalLinesPushButton, SIGNAL(clicked()), this, SLOT(addAdditionalCompilerLine()));

    //Add first programming line
    instrctIdx=0; // <--- *must* come beofre addAdditionalCompilerLine()
    addAdditionalCompilerLine();

    //Add scroll bar when necessary
//    QScrollArea *scroll = new QScrollArea;
//    scroll->setWidget(m_widget->frame);
//    m_widget->gridLayout->addWidget(scroll);

}

GenericI2CWidget::~GenericI2CWidget()
{
    // Do nothing
}

void GenericI2CWidget::addAdditionalCompilerLine(){
    qDebug()<<"Add compiler line";
    VMInstructionForm *form = new VMInstructionForm(instrctIdx, this);
//    connect(m_config->channelOutTest, SIGNAL(toggled(bool)),
//            form, SLOT(enableChannelTest(bool)));
//    connect(form, SIGNAL(channelChanged(int,int)),
//            this, SLOT(sendChannelTest(int,int)));
    m_widget->vmInstructionLayout->addWidget(form);

    instrctIdx++;
}

//void GenericI2CWidget::switchCompilerInst(QString instruction){
//    qDebug()<<"Switching compiler instruction.";
//}
