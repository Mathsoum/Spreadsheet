#include "spreadsheetmainwindow.h"
#include "spreadsheetmodel.h"
#include <iostream>
#include <KActionCollection>
#include <QTableWidget>
#include <QMenu>

#define COORDINATES_LABEL	13
#define FORMULA_LABEL		37

SpreadSheetMainWindow::SpreadSheetMainWindow(
		QWidget* parent,
		Qt::WindowFlags f) 
		: KXmlGuiWindow(parent, f) {

		KActionCollection* actions = actionCollection();
		actions->addAction(KStandardAction::New, this, SLOT(newFile()));
		actions->addAction(KStandardAction::Open, this, SLOT(open()));
		actions->addAction(KStandardAction::Save, this, SLOT(save()));
		actions->addAction(KStandardAction::SaveAs, this, SLOT(saveAs()));
		actions->addAction(KStandardAction::Quit, this, SLOT(close()));
		_cut = actions->addAction(KStandardAction::Cut, this, SLOT(cut()));
		_copy = actions->addAction(KStandardAction::Copy, this, SLOT(copy()));
		_paste = actions->addAction(KStandardAction::Paste, this, SLOT(paste()));

		_tableView = new QTableView;
		_tableView->setModel(new SpreadSheetModel);

		setCentralWidget(_tableView);
		_tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
		_tableView->addAction(_cut);
		_tableView->addAction(_copy);
		_tableView->addAction(_paste);

		QAbstractItemModel* model = _tableView->model();
		model->setData(model->index(0,0), "William");
		model->setData(model->index(0,1), "Adama");
		model->setData(model->index(0,2), "1947-02-24");

		model->setData(model->index(1,0), "Saul");
		model->setData(model->index(1,1), "Tigh");
		model->setData(model->index(1,2), "1949-03-22");

		model->setData(model->index(2,0), "Lee");
		model->setData(model->index(2,1), "Adama");
		model->setData(model->index(2,2), "1973-04-03");

		model->setData(model->index(3,0), "Kara");
		model->setData(model->index(3,1), "Thrace");
		model->setData(model->index(3,2), "1980-04-08");

		model->setData(model->index(4,0), "Laura");
		model->setData(model->index(4,1), "Roslin");
		model->setData(model->index(4,2), "1952-04-28");

		model->setData(model->index(5,0), "Gaius");
		model->setData(model->index(5,1), "Baltar");
		model->setData(model->index(5,2), "1971-06-04");

		statusBar()->insertPermanentItem(">>>>>WW<<<<<", COORDINATES_LABEL);
		statusBar()->insertPermanentItem("Formula", FORMULA_LABEL);
		_tableView->setSelectionMode(QAbstractItemView::ContiguousSelection);

		connect(_tableView->selectionModel(),
				SIGNAL(currentChanged(QModelIndex, QModelIndex)),
				this,
				SLOT(updateStatusBar(QModelIndex)));

		setupGUI();
}

SpreadSheetMainWindow::~SpreadSheetMainWindow() {}


void SpreadSheetMainWindow::newFile() {
	std::cout << "Suck it, bro!" << std::endl;
}

void SpreadSheetMainWindow::open() {

}

void SpreadSheetMainWindow::save() {

}

void SpreadSheetMainWindow::saveAs() {

}

void SpreadSheetMainWindow::cut() {
	copy();
	QModelIndexList list = _tableView->selectionModel()->selectedIndexes();
	foreach(const QModelIndex& idx, list) {
		_tableView->model()->setData(idx, QVariant());
	}
}

void SpreadSheetMainWindow::copy() {
	if(_tableView->selectionModel()->hasSelection()) {
		_copiedData.clear();
		QModelIndex source = _tableView->currentIndex();
		QModelIndexList list = _tableView->selectionModel()->selectedIndexes();
		for(int i=0; i<list.length(); ++i) {
			QModelIndex current = list[i];
			_copiedData.insert(QPair<int,int>(current.row() - source.row(),
							   current.column() - source.column()), current.data());
		}
	}
}

void SpreadSheetMainWindow::paste() {
	if(!_copiedData.isEmpty()) {
		QPair<int,int> current(_tableView->currentIndex().row(),
					   _tableView->currentIndex().column());
		for(QMap<QPair<int,int>,QVariant>::const_iterator it = _copiedData.constBegin() ;
				it != _copiedData.constEnd(); it++) {
			_tableView->model()->setData(
					_tableView->model()->index(
						current.first + it.key().first,
						current.second + it.key().second),
					it.value());
		}
	}
}

void SpreadSheetMainWindow::updateStatusBar(const QModelIndex& index) {
	if(statusBar()->hasItem(COORDINATES_LABEL)) {
		statusBar()->changeItem(locationFromIndex(index.column(), index.row()), COORDINATES_LABEL);
	} else {
		statusBar()->insertItem(locationFromIndex(index.column(), index.row()), COORDINATES_LABEL);
	}
}

QString SpreadSheetMainWindow::locationFromIndex(int column, int row) {
	return SpreadSheetModel::columnNameFromIndex(column) + SpreadSheetModel::rowNameFromIndex(row);
}


