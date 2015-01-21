#include "spreadsheetmodel.h"
#include <QtCore/qmath.h>

SpreadSheetModel::SpreadSheetModel(QObject* parent) : QAbstractItemModel(parent)
{
}

int SpreadSheetModel::columnCount(const QModelIndex& parent) const {
    return parent.isValid() ? 0 : qPow(2, 16);
}

int SpreadSheetModel::rowCount(const QModelIndex& parent) const {
    return parent.isValid() ? 0 : qPow(2, 16);
}

QVariant SpreadSheetModel::data(const QModelIndex& index, int role) const {
    return QVariant();
}

QModelIndex SpreadSheetModel::index(int row, int column, const QModelIndex& parent) const {
    return parent;
}

QModelIndex SpreadSheetModel::parent(const QModelIndex& index) const {
    return index;
}

QString SpreadSheetModel::rowNameFromIndex(int row) {
	int actualRow = row < 0 ? 0 : row;
    return QString::number(actualRow + 1);
}

QString SpreadSheetModel::columnNameFromIndex(int column) {
	int actualColumn = column < 0 ? 0 : column;

	QString columnLabel;

	for(int i = actualColumn/26; i > 0; i /= 26) {
		columnLabel.prepend('A' + ((i - 1) % 26));
		i--;
	}
	columnLabel.append('A' + (actualColumn % 26));

	return columnLabel;
}

QVariant SpreadSheetModel::headerData(int section, Qt::Orientation orientation, int role) const {
    switch(orientation) {
        case Qt::Horizontal:
            return QVariant(rowNameFromIndex(section));
        case Qt::Vertical:
            return QVariant(columnNameFromIndex(section));
    }

    return QVariant();
}
