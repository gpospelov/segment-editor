/******************************************************************************
 *
 * Project       : QML playground
 *
 * Author        : Gennady Pospelov (IO)
 *
 *****************************************************************************/

#include "segment_model.h"

#include <QDebug>

namespace mvvm
{

SegmentModel::SegmentModel(QObject *parent) : QAbstractListModel(parent) {}

void SegmentModel::addSegment(const Segment &segment)
{
  beginInsertRows(QModelIndex(), rowCount(), rowCount());
  m_segments << segment;
  endInsertRows();
}

int SegmentModel::rowCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);
  return m_segments.count();
}

QVariant SegmentModel::data(const QModelIndex &index, int role) const
{
  if (index.row() < 0 || index.row() >= m_segments.count())
    return QVariant();

  const Segment &segment = m_segments[index.row()];
  if (role == NameRole)
  {
    return segment.GetName();
  }
  else if (role == ColorRole)
  {
    return segment.GetColor();
  }
  else if (role == IndexRole)
  {
    return index.row();
  }

  return QVariant();
}

void SegmentModel::move(int from, int to)
{
  const bool is_valid_from = (from >= 0 && from < rowCount());
  const bool is_valid_to = (to >= 0 && to < rowCount());
  if (is_valid_from && is_valid_to && from != to)
  {
    beginResetModel();
    m_segments.move(from, to);
    endResetModel();
  }
  qDebug() << contentAsString();
  emit contentChanged();
}

QString SegmentModel::contentAsString()
{
  QString result;
  for (const auto &segment : m_segments)
  {
    result.append(segment.GetName());
    result.append("; ");
  }
  return result;
}

QHash<int, QByteArray> SegmentModel::roleNames() const
{
  QHash<int, QByteArray> roles;
  roles[NameRole] = "name";
  roles[ColorRole] = "color";
  roles[IndexRole] = "modelIndex";
  return roles;
}

}  // namespace mvvm
