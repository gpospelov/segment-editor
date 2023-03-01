/******************************************************************************
 *
 * Project       : QML playground
 *
 * Author        : Gennady Pospelov (IO)
 *
 *****************************************************************************/

#include "backend.h"

#include "utils.h"

namespace mvvm
{

Backend::Backend(QObject *parent) : QObject(parent) {}

QString Backend::helloWorldString() const
{
  return QString::fromStdString(::mvvm::GetHelloWorldString());
}

}  // namespace mvvm
