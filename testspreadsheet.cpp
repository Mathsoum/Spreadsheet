#include "testspreadsheet.h"

void TestSpreadSheet::locationFromIndex_data() {
	QTest::addColumn<int>("line");
	QTest::addColumn<int>("column");
	QTest::addColumn<QString>("output");

	QTest::newRow("A1") << 0 << 0 << "A1";
	QTest::newRow("A2") << 0 << 1 << "A2";
	QTest::newRow("B3") << 1 << 2 << "B3";
	QTest::newRow("B4") << 1 << 3 << "B4";
	QTest::newRow("C5") << 2 << 4 << "C5";
	QTest::newRow("C6") << 2 << 5 << "C6";

	QTest::newRow("Z1") << 25 << 0 << "Z1";
	QTest::newRow("AA1") << 26 << 0 << "AA1";

	QTest::newRow("AZ100") << 51 << 99 << "AZ100";
	QTest::newRow("BA100") << 52 << 99 << "BA100";

	QTest::newRow("CV100") << 99 << 99 << "CV100";
	QTest::newRow("CW101") << 100 << 100 << "CW101";

	QTest::newRow("AAA101") << 702 << 100 << "AAA101";
	QTest::newRow("ZZ101") << 701 << 100 << "ZZ101";

	QTest::newRow("AAAA101") << 18278 << 100 << "AAAA101";
	QTest::newRow("ZZZ101") << 18277 << 100 << "ZZZ101";

	QTest::newRow("A38") << -42 << 37 << "A38";
	QTest::newRow("A1") << -13 << -37 << "A1";


}

void TestSpreadSheet::locationFromIndex() {
	QFETCH(int, line);
	QFETCH(int, column);
	QFETCH(QString, output);

	QCOMPARE(SpreadSheetMainWindow::locationFromIndex(line, column), output);
}

QTEST_MAIN(TestSpreadSheet)
