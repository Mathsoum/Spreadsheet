#include <kdebug.h>
#include <KAboutData>
#include <klocalizedstring.h>
#include <KCmdLineArgs>
#include <QByteArray>
#include <KApplication>
#include <QWidget>
#include <spreadsheetmainwindow.h>

int main(int argc, char** argv) {
	KAboutData about("spreadsheet",
					 0,
					 ki18n("Spreadsheet"),
					 "1.0");
		
	KCmdLineArgs::init(argc, argv, &about);

	KApplication app;

	SpreadSheetMainWindow* mw = new SpreadSheetMainWindow();
	mw->show();

    return app.exec();
}

