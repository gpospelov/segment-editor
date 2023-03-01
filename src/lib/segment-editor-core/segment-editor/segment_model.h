/******************************************************************************
 *
 * Project       : QML playground
 *
 * Author        : Gennady Pospelov (IO)
 *
 *****************************************************************************/

#ifndef SEGMENT_EDITOR_SEGMENT_MODEL_H_
#define SEGMENT_EDITOR_SEGMENT_MODEL_H_

#include <QAbstractListModel>
#include <QString>
#include <QStringList>

#include <segment-editor/segment.h>

// See origin, Remy van Elst
// https://raymii.org/s/tutorials/Qml_Drag_and_Drop_example_including_reordering_the_Cpp_Model.html

namespace mvvm
{

//! The SegmentModel holds a collection of segments.

class SegmentModel : public QAbstractListModel
{
  Q_OBJECT
  Q_PROPERTY(QString contentAsString READ contentAsString NOTIFY contentChanged)

public:
  enum SegmentRoles
  {
    NameRole = Qt::UserRole + 1,
    ColorRole,
    IndexRole
  };

  SegmentModel(QObject *parent = nullptr);

  void addSegment(const Segment &segment);

  int rowCount(const QModelIndex &parent = QModelIndex()) const;

  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

  Q_INVOKABLE void move(int from, int to);

  Q_INVOKABLE QString contentAsString();

signals:
void contentChanged();

protected:
  QHash<int, QByteArray> roleNames() const;

private:
  QList<Segment> m_segments;
};

}  // namespace mvvm

#endif  // SEGMENT_EDITOR_SEGMENT_MODEL_H_
