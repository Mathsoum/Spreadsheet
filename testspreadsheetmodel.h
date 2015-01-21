#ifndef _TEST_SPREAD_SHEET_MODEL_H
#define _TEST_SPREAD_SHEET_MODEL_H

#include <QtTest/QtTest>

#include "spreadsheetmodel.h"

class TestSpreadSheetModel : public QObject {
    Q_OBJECT

    private slots:
        void testModelInitialisation();
    
        void testRowNameFromIndex_data();
        void testRowNameFromIndex();

        void testColumnNameFromIndex_data();
        void testColumnNameFromIndex();

        void testHeaderHOrientation_data();
        void testHeaderHOrientation();

        void testHeaderVOrientation_data();
        void testHeaderVOrientation();
};


#endif // _TEST_SPREAD_SHEET_MODEL_H
