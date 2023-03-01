/******************************************************************************
 *
 * Project       : QML playground
 *
 * Author        : Gennady Pospelov (IO)
 *
 *****************************************************************************/

#include "segment.h"

namespace mvvm
{

Segment::Segment(const QString &name) : m_name(name) {}

QString Segment::GetName() const
{
  return m_name;
}

QColor Segment::GetColor() const
{
  return QColor("green");
}

}  // namespace mvvm
