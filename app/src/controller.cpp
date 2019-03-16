#include "controller.h"

#include <iostream>

Controller::Controller(QObject *parent)
    : QObject(parent)
{}

void Controller::randomizeClicked(const QString &txt) {
    std::cout << txt.toStdString() << std::endl;
}