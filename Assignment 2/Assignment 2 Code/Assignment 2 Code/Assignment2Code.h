#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Assignment2Code.h"

class Assignment2Code : public QMainWindow {
	Q_OBJECT

public:
	Assignment2Code(QWidget *parent = Q_NULLPTR);

private:
	Ui::Assignment2CodeClass ui;
};
