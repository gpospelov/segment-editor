/******************************************************************************
 *
 * Project       : QML playground
 *
 * Author        : Gennady Pospelov (IO)
 *
 *****************************************************************************/

#ifndef SEGMENT_EDITOR_BACKEND_H_
#define SEGMENT_EDITOR_BACKEND_H_

#include <QObject>

namespace mvvm
{

class Backend : public QObject
{
  Q_OBJECT

public:
  explicit Backend(QObject* parent = nullptr);

  Q_INVOKABLE QString helloWorldString() const;
};

}  // namespace mvvm

#endif  // SEGMENT_EDITOR_BACKEND_H_
