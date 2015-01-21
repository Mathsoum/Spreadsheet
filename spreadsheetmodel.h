#ifndef _SPREAD_SHEET_MODEL_H
#define _SPREAD_SHEET_MODEL_H

#include <QAbstractItemModel>
#include <QtCore>

class SpreadSheetModel :public QAbstractItemModel {
    Q_OBJECT
    public:
        SpreadSheetModel(QObject* parent = 0);

        int columnCount(const QModelIndex& parent = QModelIndex()) const;
        int rowCount(const QModelIndex& parent = QModelIndex()) const;

        QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

        QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
        QModelIndex parent(const QModelIndex& index) const;

        static QString rowNameFromIndex(int row);
        static QString columnNameFromIndex(int column);
};

#endif // _SPREAAD_SHEET_MODEL_H
