#include "testspreadsheetmodel.h"
#include <QtCore/qmath.h>
#include <QVariant>

void TestSpreadSheetModel::testModelInitialisation() {
    SpreadSheetModel model;

    QCOMPARE(model.columnCount(), (int)qPow(2, 16));
    QCOMPARE(model.rowCount(), (int)qPow(2, 16));

    /*
    for(int column = 0 ; column < model.columnCount() ; ++column) {
        for(int row = 0 ; row < model.rowCount() ; ++row) {
            QCOMPARE(model.data(model.index(row, column)), QVariant());
        }
    }
    // */
}

void TestSpreadSheetModel::testRowNameFromIndex_data() {
    QTest::addColumn<int>("input");
    QTest::addColumn<QString>("output");

    for(int i = -10; i < 0; ++i) {
        QTest::newRow("row") << i << "1";
    }

    for(int i = 0; i < 100; ++i) {
        QTest::newRow("row") << i << QString::number(i + 1);
    }
}

void TestSpreadSheetModel::testRowNameFromIndex() {
    QFETCH(int, input);
    QFETCH(QString, output);

    QCOMPARE(SpreadSheetModel::rowNameFromIndex(input), output);
}

void TestSpreadSheetModel::testColumnNameFromIndex_data() {
	QTest::addColumn<int>("input");
	QTest::addColumn<QString>("output");

	QTest::newRow("A") << 0 << "A";
	QTest::newRow("B") << 1 << "B";
	QTest::newRow("C") << 2 << "C";

	QTest::newRow("Z") << 25 << "Z";
	QTest::newRow("AA") << 26 << "AA";

	QTest::newRow("AZ") << 51 << "AZ";
	QTest::newRow("BA") << 52 << "BA";

	QTest::newRow("CV") << 99 << "CV";
	QTest::newRow("CW") << 100 << "CW";

	QTest::newRow("AAA") << 702 << "AAA";
	QTest::newRow("ZZ") << 701 << "ZZ";

	QTest::newRow("AAAA") << 18278 << "AAAA";
	QTest::newRow("ZZZ") << 18277 << "ZZZ";

	QTest::newRow("A") << -42 << "A";
	QTest::newRow("A") << -13 << "A";
}

void TestSpreadSheetModel::testColumnNameFromIndex() {
    QFETCH(int, input);
    QFETCH(QString, output);

    QCOMPARE(SpreadSheetModel::columnNameFromIndex(input), output);
}

void TestSpreadSheetModel::testHeaderHOrientation_data() {
    QTest::addColumn<int>("section");
    QTest::addColumn<QString>("output");

	for(int i = -10; i < 0; ++i) {
        QTest::newRow("rows") << i << "1";
    }

	for(int i = 0; i < 100; ++i) {
        QTest::newRow("rows") << i << QString::number(i+1);
    }
}

void TestSpreadSheetModel::testHeaderHOrientation() {
    SpreadSheetModel model;

    QFETCH(int, section);
    QFETCH(QString, output);

    QCOMPARE(model.headerData(section, Qt::Horizontal).toString(), output);
}

void TestSpreadSheetModel::testHeaderVOrientation_data() {
    QTest::addColumn<int>("section");
    QTest::addColumn<QString>("output");

	QTest::newRow("A") << 0 << "A";
	QTest::newRow("Z") << 25 << "Z";

	QTest::newRow("AA") << 26 << "AA";
	QTest::newRow("AZ") << 51 << "AZ";

	QTest::newRow("BA") << 52 << "BA";

	QTest::newRow("AAA") << 702 << "AAA";
	QTest::newRow("ZZ") << 701 << "ZZ";

	QTest::newRow("AAAA") << 18278 << "AAAA";
	QTest::newRow("ZZZ") << 18277 << "ZZZ";

	QTest::newRow("A") << -42 << "A";
	QTest::newRow("A") << -13 << "A";


}

void TestSpreadSheetModel::testHeaderVOrientation() {
    SpreadSheetModel model;

    QFETCH(int, section);
    QFETCH(QString, output);

    QCOMPARE(model.headerData(section, Qt::Vertical).toString(), output);
}

QTEST_MAIN(TestSpreadSheetModel)
