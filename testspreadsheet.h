#ifndef TESTS_H_
#define TESTS_H_

#include <QtTest/QtTest>

#include "spreadsheetmainwindow.h"

class TestSpreadSheet : public QObject {
	Q_OBJECT

	private slots:
		void locationFromIndex_data();
		void locationFromIndex();
};

#endif // TESTS_H_
