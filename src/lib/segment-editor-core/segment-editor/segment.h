/******************************************************************************
 *
 * Project       : QML playground
 *
 * Author        : Gennady Pospelov (IO)
 *
 *****************************************************************************/

#ifndef SEGMENT_EDITOR_SEGMENT_H_
#define SEGMENT_EDITOR_SEGMENT_H_

#include <QString>
#include <QColor>

namespace mvvm
{

class Segment
{
public:
  explicit Segment(const QString &name);

  QString GetName() const;

  QColor GetColor() const;

private:
  QString m_name;
};

}  // namespace mvvm

#endif  // SEGMENT_EDITOR_SEGMENT_H_
