#ifndef SSMW_H_
#define SSMW_H_

#include <KXmlGuiWindow>
#include <KActionCollection>
#include <QTableView>
#include <KAction>
#include <KStatusBar>

class SpreadSheetMainWindow : public KXmlGuiWindow {
	Q_OBJECT
	public:
		SpreadSheetMainWindow(QWidget* parent = 0,
				Qt::WindowFlags f=KDE_DEFAULT_WINDOWFLAGS);

		virtual ~SpreadSheetMainWindow();

		static QString locationFromIndex(int column, int row);

	public slots:
		void newFile();
		void open();
		void save();
		void saveAs();
		void cut();
		void copy();
		void paste();

		void updateStatusBar(const QModelIndex& index);

	private:
		QTableView* _tableView;
		QAction* _copy;
		QAction* _cut;
		QAction* _paste;
		QMap<QPair<int,int>,QVariant> _copiedData;

};

#endif // SSMW_H_
