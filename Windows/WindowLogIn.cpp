#include "WindowLogIn.h"
#include "./ui_WindowLogIn.h"

WindowLogIn::WindowLogIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WindowLogIn)
{
    ui->setupUi(this);
}

WindowLogIn::~WindowLogIn()
{
    delete ui;
}

